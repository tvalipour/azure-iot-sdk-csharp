// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

using System;
using System.Globalization;
using System.Threading.Tasks;
using Microsoft.Azure.Amqp;
using Microsoft.Azure.Amqp.Encoding;
using Microsoft.Azure.Amqp.Framing;

namespace Microsoft.Azure.Devices.Provisioning.Client.Transport.Amqp
{
    internal class AmqpClientLink
    {
        private readonly AmqpClientSession _amqpSession;

        public AmqpClientLink(AmqpClientSession amqpClientSession)
        {
            _amqpSession = amqpClientSession;

            AmqpLinkSettings = new AmqpLinkSettings
            {
                LinkName = Guid.NewGuid().ToString("N", CultureInfo.InvariantCulture),
                TotalLinkCredit = AmqpConstants.DefaultLinkCredit,
                AutoSendFlow = true,
                Source = new Source(),
                Target = new Target(),
                SettleType = SettleMode.SettleOnDispose
            };
        }

        private bool _isLinkClosed;

        internal AmqpLink AmqpLink { get; private set; }

        public AmqpLinkSettings AmqpLinkSettings { get; private set; }

        public bool IsLinkClosed => _isLinkClosed;

        public async Task OpenAsync(TimeSpan timeout)
        {
            if (Extensions.IsReceiver(AmqpLinkSettings))
            {
                AmqpLink = new ReceivingAmqpLink(_amqpSession.AmqpSession, AmqpLinkSettings);
            }
            else
            {
                AmqpLink = new SendingAmqpLink(_amqpSession.AmqpSession, AmqpLinkSettings);
            }

            AmqpLink.SafeAddClosed(OnLinkClosed);
            await AmqpLink.OpenAsync(timeout).ConfigureAwait(false);
            _isLinkClosed = false;
        }

        void AddProperty(AmqpSymbol symbol, object value)
        {
            Extensions.AddProperty((Attach)AmqpLinkSettings, symbol, value);
        }

        public void AddApiVersion(string apiVersion)
        {
            AddProperty(AmqpConstants.Vendor + ":" + ClientApiVersionHelper.ApiVersionName, apiVersion);
        }

        public void AddClientVersion(string clientVersion)
        {
            AddProperty(AmqpConstants.Vendor + ":" + ClientApiVersionHelper.ClientVersionName, clientVersion);
        }

        public async Task<Outcome> SendMessageAsync(
            AmqpMessage message,
            ArraySegment<byte> deliveryTag,
            TimeSpan timeout)
        {
            var sendLink = AmqpLink as SendingAmqpLink;
            if (sendLink == null)
            {
                throw new InvalidOperationException("Link does not support sending.");
            }

            return await sendLink.SendMessageAsync(message,
                deliveryTag,
                AmqpConstants.NullBinary,
                timeout).ConfigureAwait(false);
        }

        public async Task<AmqpMessage> ReceiveMessageAsync(TimeSpan timeout)
        {
            var receiveLink = AmqpLink as ReceivingAmqpLink;
            if (receiveLink == null)
            {
                throw new InvalidOperationException("Link does not support receiving.");
            }

            return await receiveLink.ReceiveMessageAsync(timeout).ConfigureAwait(false);
        }

        public void AcceptMessage(AmqpMessage amqpMessage)
        {
            var receiveLink = AmqpLink as ReceivingAmqpLink;
            if (receiveLink == null)
            {
                throw new InvalidOperationException("Link does not support receiving.");
            }
            receiveLink.AcceptMessage(amqpMessage, false);
        }

        void OnLinkClosed(object o, EventArgs args)
        {
            _isLinkClosed = true;
        }
    }
}
