// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif

void* my_gballoc_malloc(size_t t)
{
    return malloc(t);
}

void my_gballoc_free(void * t)
{
    free(t);
}


#ifdef _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif


#ifdef __cplusplus
#include <cstddef>
#include <cstdint>
#include <cinttypes>
#else
#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>
#endif

#define STRING_new real_STRING_new
#define STRING_clone real_STRING_clone
#define STRING_construct real_STRING_construct
#define STRING_construct_n real_STRING_construct_n
#define STRING_new_with_memory real_STRING_new_with_memory
#define STRING_new_quoted real_STRING_new_quoted
#define STRING_new_JSON real_STRING_new_JSON
#define STRING_from_byte_array real_STRING_from_byte_array
#define STRING_delete real_STRING_delete
#define STRING_concat real_STRING_concat
#define STRING_concat_with_STRING real_STRING_concat_with_STRING
#define STRING_quote real_STRING_quote
#define STRING_copy real_STRING_copy
#define STRING_copy_n real_STRING_copy_n
#define STRING_c_str real_STRING_c_str
#define STRING_empty real_STRING_empty
#define STRING_length real_STRING_length
#define STRING_compare real_STRING_compare
#include "strings.c"
#undef STRINGS_H
#undef STRING_new 
#undef STRING_clone 
#undef STRING_construct 
#undef STRING_construct_n 
#undef STRING_new_with_memory 
#undef STRING_new_quoted 
#undef STRING_new_JSON 
#undef STRING_from_byte_array 
#undef STRING_delete 
#undef STRING_concat 
#undef STRING_concat_with_STRING 
#undef STRING_quote 
#undef STRING_copy 
#undef STRING_copy_n 
#undef STRING_c_str 
#undef STRING_empty 
#undef STRING_length 
#undef STRING_compare 


#include "umock_c.h"
#include "umocktypes_charptr.h"
#include "umocktypes_bool.h"
#include "umocktypes_stdint.h"
#include "umock_c_negative_tests.h"

#define ENABLE_MOCKS
#include "agenttypesystem.h"
#include "schema.h"
#include "iotdevice.h"
#include "azure_c_shared_utility/strings.h"
#undef ENABLE_MOCKS

#include "testrunnerswitcher.h"
#include "codefirst.h"
#include "macro_utils.h"
#include "c_bool_size.h"
#include "serializer.h"

TEST_DEFINE_ENUM_TYPE(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_RESULT_VALUES);
IMPLEMENT_UMOCK_C_ENUM_TYPE(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_RESULT_VALUES);
//TEST_DEFINE_ENUM_TYPE(AGENT_DATA_TYPES_RESULT, AGENT_DATA_TYPES_RESULT_VALUES);
IMPLEMENT_UMOCK_C_ENUM_TYPE(AGENT_DATA_TYPES_RESULT, AGENT_DATA_TYPES_RESULT_VALUES);
//TEST_DEFINE_ENUM_TYPE(SCHEMA_RESULT, SCHEMA_RESULT_VALUES);
IMPLEMENT_UMOCK_C_ENUM_TYPE(SCHEMA_RESULT, SCHEMA_RESULT_VALUES);

DEFINE_ENUM_STRINGS(UMOCK_C_ERROR_CODE, UMOCK_C_ERROR_CODE_VALUES)

BEGIN_NAMESPACE(DummyDataProvider)

DECLARE_MODEL(TruckType,

/*Tests_SRS_SERIALIZER_99_004:[ The propertyType can be any of the following data types: double]*/
WITH_DATA(double, this_is_double),

/*Tests_SRS_SERIALIZER_99_005:[ int], */
WITH_DATA(int, this_is_int),

/*Tests_SRS_SERIALIZER_99_006:[ float]*/
WITH_DATA(float, this_is_float),

/*Tests_SRS_SERIALIZER_99_007:[ long]*/
WITH_DATA(long, this_is_long),

/*Tests_SRS_SERIALIZER_99_008:[ int8_t]*/
WITH_DATA(int8_t, this_is_sint8_t),

/*Tests_SRS_SERIALIZER_99_009:[ uint8_t]*/
WITH_DATA(uint8_t, this_is_uint8_t),

/*Tests_SRS_SERIALIZER_99_010:[ int16_t]*/
WITH_DATA(int16_t, this_is_int16_t),

/*Tests_SRS_SERIALIZER_99_011:[ int32_t]*/
WITH_DATA(int32_t, this_is_int32_t),

/*Tests_SRS_SERIALIZER_99_012:[ int64_t]*/
WITH_DATA(int64_t, this_is_int64_t),

/*Tests_SRS_SERIALIZER_99_013:[ bool]*/
WITH_DATA(bool, this_is_bool),

/*Tests_SRS_SERIALIZER_99_014:[ ascii_char_ptr]*/
WITH_DATA(ascii_char_ptr, this_is_ascii_char_ptr),

/* Tests SRS_SERIALIZER_01_001: [ascii_char_ptr_no_quotes, ] */
WITH_DATA(ascii_char_ptr_no_quotes, this_is_ascii_char_ptr_no_quotes),

/*Tests_SRS_SERIALIZER_99_051:[ EDM_DATE_TIME_OFFSET]*/
WITH_DATA(EDM_DATE_TIME_OFFSET, this_is_EdmDateTimeOffset),

/*Tests_SRS_SERIALIZER_99_072:[ EDM_GUID]*/
WITH_DATA(EDM_GUID, this_is_EdmGuid),

/*Tests_SRS_SERIALIZER_99_074:[ EDM_BINARY]*/
WITH_DATA(EDM_BINARY, this_is_EdmBinary),

WITH_ACTION(reset),
WITH_ACTION(setSpeed, double, theSpeed),
WITH_ACTION(test1, double, P1, int, P2, float, P3, long, P4, int8_t, P5, uint8_t, P6, int16_t, P7, int32_t, P8, int64_t, P9, bool, P10, ascii_char_ptr, P11, EDM_DATE_TIME_OFFSET, P12, EDM_GUID, P13, EDM_BINARY, P14, ascii_char_ptr_no_quotes, P15),

WITH_REPORTED_PROPERTY(double, reported_this_is_double),
WITH_REPORTED_PROPERTY(int, reported_this_is_int),
WITH_REPORTED_PROPERTY(float, reported_this_is_float),
WITH_REPORTED_PROPERTY(long, reported_this_is_long),
WITH_REPORTED_PROPERTY(int8_t, reported_this_is_int8_t),
WITH_REPORTED_PROPERTY(uint8_t, reported_this_is_uint8_t),
WITH_REPORTED_PROPERTY(int16_t, reported_this_is_int16_t),
WITH_REPORTED_PROPERTY(int32_t, reported_this_is_int32_t),
WITH_REPORTED_PROPERTY(int64_t, reported_this_is_int64_t),
WITH_REPORTED_PROPERTY(bool, reported_this_is_bool),
WITH_REPORTED_PROPERTY(ascii_char_ptr, reported_this_is_ascii_char_ptr),
WITH_REPORTED_PROPERTY(ascii_char_ptr_no_quotes, reported_this_is_ascii_char_ptr_no_quotes),
WITH_REPORTED_PROPERTY(EDM_DATE_TIME_OFFSET, reported_this_is_EdmDateTimeOffset),
WITH_REPORTED_PROPERTY(EDM_GUID, reported_this_is_EdmGuid),
WITH_REPORTED_PROPERTY(EDM_BINARY, reported_this_is_EdmBinary)
);

END_NAMESPACE(DummyDataProvider)

static const char TEST_MODEL_NAME[] = "SimpleDevice";

bool DummyDataProvider_reset_wasCalled;
EXECUTE_COMMAND_RESULT reset(TruckType* device)
{
    (void)device;
    DummyDataProvider_reset_wasCalled = true;
    return EXECUTE_COMMAND_SUCCESS;
}

bool DummyDataProvider_setSpeed_wasCalled;
double DummyDataProvider_setSpeed_theSpeed;
EXECUTE_COMMAND_RESULT setSpeed(TruckType* device, double theSpeed)
{
    (void)device;
    DummyDataProvider_setSpeed_wasCalled = true;
    DummyDataProvider_setSpeed_theSpeed = theSpeed;
    return EXECUTE_COMMAND_SUCCESS;
}

bool                    DummyDataProvider_test1_wasCalled;
double                  DummyDataProvider_test1_P1;
int                     DummyDataProvider_test1_P2;
float                   DummyDataProvider_test1_P3;
long                    DummyDataProvider_test1_P4;
int8_t                  DummyDataProvider_test1_P5;
uint8_t                 DummyDataProvider_test1_P6;
int16_t                 DummyDataProvider_test1_P7;
int32_t                 DummyDataProvider_test1_P8;
int64_t                 DummyDataProvider_test1_P9;
bool                    DummyDataProvider_test1_P10;
#define                 P11_MAX_SIZE 100
char                    DummyDataProvider_test1_P11[P11_MAX_SIZE];
EDM_DATE_TIME_OFFSET    DummyDataProvider_test1_P12;
EDM_GUID                DummyDataProvider_test1_P13;
EDM_BINARY              DummyDataProvider_test1_P14 = { 0, NULL };
#define                 P15_MAX_SIZE 100
char                    DummyDataProvider_test1_P15[P15_MAX_SIZE];

EXECUTE_COMMAND_RESULT test1(TruckType* device, double P1, int P2, float P3, long P4, int8_t P5, uint8_t P6, int16_t P7, int32_t P8, int64_t P9, bool P10, ascii_char_ptr P11, EDM_DATE_TIME_OFFSET P12, EDM_GUID P13, EDM_BINARY P14, ascii_char_ptr_no_quotes P15)
{
    (void)device;
    DummyDataProvider_test1_wasCalled = true;
    DummyDataProvider_test1_P1 = P1;
    DummyDataProvider_test1_P2 = P2;
    DummyDataProvider_test1_P3 = P3;
    DummyDataProvider_test1_P4 = P4;
    DummyDataProvider_test1_P5 = P5;
    DummyDataProvider_test1_P6 = P6;
    DummyDataProvider_test1_P7 = P7;
    DummyDataProvider_test1_P8 = P8;
    DummyDataProvider_test1_P9 = P9;
    DummyDataProvider_test1_P10 = P10;
    strcpy(DummyDataProvider_test1_P11,  P11);
    DummyDataProvider_test1_P12 = P12;
    DummyDataProvider_test1_P13 = P13;
    DummyDataProvider_test1_P14.size = P14.size;
    DummyDataProvider_test1_P14.data = (unsigned char*)malloc(P14.size);
    memcpy(DummyDataProvider_test1_P14.data, P14.data, P14.size);
    strcpy(DummyDataProvider_test1_P15, P15);
    return EXECUTE_COMMAND_SUCCESS;
}

#define TEST_DEFAULT_SCHEMA_NAMESPACE   ("Test.TruckDemo")
#define TEST_DEFAULT_MODEL_NAME         ("TruckType")

static const SCHEMA_HANDLE TEST_SCHEMA_HANDLE = (SCHEMA_HANDLE)0x4242;
static const SCHEMA_MODEL_TYPE_HANDLE TEST_MODEL_HANDLE = (SCHEMA_MODEL_TYPE_HANDLE)0x4243;
static const SCHEMA_MODEL_TYPE_HANDLE TEST_TRUCKTYPE_MODEL_HANDLE = (SCHEMA_MODEL_TYPE_HANDLE)0x4244;
static const DEVICE_HANDLE TEST_DEVICE_HANDLE = (DEVICE_HANDLE)0x4848;

static const SCHEMA_ACTION_HANDLE TEST1_ACTION_HANDLE = (SCHEMA_ACTION_HANDLE)0x5201;
static const SCHEMA_ACTION_HANDLE SETSPEED_ACTION_HANDLE = (SCHEMA_ACTION_HANDLE)0x5202;
static const SCHEMA_ACTION_HANDLE RESET_ACTION_HANDLE = (SCHEMA_ACTION_HANDLE)0x5202;
static const SCHEMA_STRUCT_TYPE_HANDLE TEST_STRUCT_TYPE_HANDLE = (SCHEMA_STRUCT_TYPE_HANDLE)0x6202;

#define MAX_NAME_LENGTH 100
typedef char someName[MAX_NAME_LENGTH];
#define MAX_RECORDINGS 100

static  AGENT_DATA_TYPE* Create_EDM_BOOLEAN_from_int_agentData = NULL;
static  AGENT_DATA_TYPE* Create_AGENT_DATA_TYPE_from_UINT8_agentData = NULL;
static  AGENT_DATA_TYPE* Create_AGENT_DATA_TYPE_from_DOUBLE_agentData = NULL;
static  AGENT_DATA_TYPE* Create_AGENT_DATA_TYPE_from_SINT16_agentData = NULL;
static  AGENT_DATA_TYPE* Create_AGENT_DATA_TYPE_from_SINT32_agentData = NULL;
static  AGENT_DATA_TYPE* Create_AGENT_DATA_TYPE_from_SINT64_agentData = NULL;
static  AGENT_DATA_TYPE* Create_AGENT_DATA_TYPE_from_SINT8_agentData = NULL;
static  AGENT_DATA_TYPE* Create_AGENT_DATA_TYPE_from_FLOAT_agentData = NULL;
static  AGENT_DATA_TYPE* Create_AGENT_DATA_TYPE_from_charz_agentData = NULL;
static  AGENT_DATA_TYPE* Create_AGENT_DATA_TYPE_from_charz_no_quotes_agentData = NULL;
static AGENT_DATA_TYPE* Create_AGENT_DATA_TYPE_from_Members_agentData = NULL;
static someName Create_AGENT_DATA_TYPE_from_Members_names[MAX_RECORDINGS];
static const AGENT_DATA_TYPE* Create_AGENT_DATA_TYPE_from_Members_values[MAX_RECORDINGS];
static  AGENT_DATA_TYPE* Create_AGENT_DATA_TYPE_from_EDM_DATE_TIME_OFFSET_agentData = NULL;
static  AGENT_DATA_TYPE* Create_AGENT_DATA_TYPE_from_EDM_GUID_agentData = NULL;
static  AGENT_DATA_TYPE* Create_AGENT_DATA_TYPE_from_EDM_BINARY_agentData = NULL;
static const AGENT_DATA_TYPE* Device_Publish_agentData = NULL;
static const AGENT_DATA_TYPE* Device_PublishTransacted_agentData = NULL;
static  AGENT_DATA_TYPE* Destroy_AGENT_DATA_TYPE_agentData = NULL;

#define TEST_CALLBACK_CONTEXT   ((void*)0x4247)
#define TEST_COMMAND "this be some command"

static char* umockvalue_stringify_EDM_DATE_TIME_OFFSET(const EDM_DATE_TIME_OFFSET* dateTimeOffset)
{
    size_t needed = snprintf(NULL, 0, "struct tm = ( %d-%d-%d %d:%d:%d ) %" PRIu8 " %" PRIu64 " %" PRIu8 " %" PRIu8 " %" PRIu8,
        dateTimeOffset->dateTime.tm_year,
        dateTimeOffset->dateTime.tm_mon,
        dateTimeOffset->dateTime.tm_mday,
        dateTimeOffset->dateTime.tm_hour,
        dateTimeOffset->dateTime.tm_min,
        dateTimeOffset->dateTime.tm_sec,
        dateTimeOffset->hasFractionalSecond,
        dateTimeOffset->fractionalSecond,
        dateTimeOffset->hasTimeZone,
        dateTimeOffset->timeZoneHour,
        dateTimeOffset->timeZoneMinute);
    char* result = (char*)my_gballoc_malloc(needed + 1);
    if (result == NULL)
    {
        ASSERT_FAIL("failed to malloc");
    }
    else
    {
        (void)snprintf(result, needed+1, "struct tm = ( %d-%d-%d %d:%d:%d ) %" PRIu8 " %" PRIu64 " %" PRIu8 " %" PRIu8 " %" PRIu8,
            dateTimeOffset->dateTime.tm_year,
            dateTimeOffset->dateTime.tm_mon,
            dateTimeOffset->dateTime.tm_mday,
            dateTimeOffset->dateTime.tm_hour,
            dateTimeOffset->dateTime.tm_min,
            dateTimeOffset->dateTime.tm_sec,
            dateTimeOffset->hasFractionalSecond,
            dateTimeOffset->fractionalSecond,
            dateTimeOffset->hasTimeZone,
            dateTimeOffset->timeZoneHour,
            dateTimeOffset->timeZoneMinute);
    }
    return result;
}


static int umockvalue_are_equal_EDM_DATE_TIME_OFFSET(const EDM_DATE_TIME_OFFSET *left, const EDM_DATE_TIME_OFFSET*right)
{
    return (memcmp(&left, &right, sizeof(left)) == 0);
}

static int umockvalue_copy_EDM_DATE_TIME_OFFSET(EDM_DATE_TIME_OFFSET*destination, const EDM_DATE_TIME_OFFSET*source)
{
    memcpy(destination, source, sizeof(EDM_DATE_TIME_OFFSET));
    return 0;
}

static void umockvalue_free_EDM_DATE_TIME_OFFSET(EDM_DATE_TIME_OFFSET*value)
{
    my_gballoc_free(value);
}

static int umockvalue_are_equal_EDM_GUID(const EDM_GUID *left, const EDM_GUID*right)
{
    return (memcmp(&left, &right, sizeof(left)) == 0);
}

static char* umockvalue_stringify_EDM_BINARY(const EDM_BINARY* b)
{   
    char* result = (char*)malloc(b->size * 5 + 1);/*every byte is "0xDD " plus 1 '\0' at the end of the string*/
    if (result == NULL)
    {
        ASSERT_FAIL("cannot malloc");
    }
    else
    {
        size_t i;
        for (i = 0;i < b->size;i++)
        {
            unsigned char hn = b->data[i] >> 4; /*hn = high nibble*/
            unsigned char ln = b->data[i] & 0x0F;

            result[i + 0] = '0';
            result[i + 1] = 'x';
            result[i + 2] = (hn) >= 10 ? ('A' - 10 + hn) : ('0' + hn);
            result[i + 3] = (ln) >= 10 ? ('A' - 10 + ln) : ('0' + ln);
            result[i + 4] = ' ';
        }
        result[b->size * 5] = '\0';
    }
    return result;
}

static void EDM_BINARY_ToString(char* s, size_t t, EDM_BINARY e)
{
    (void)t;
    strcpy(s, umockvalue_stringify_EDM_BINARY(&e));
}

static int umockvalue_are_equal_EDM_BINARY(const EDM_BINARY *left, const EDM_BINARY*right)
{
    return (memcmp(&left, &right, sizeof(left)) == 0);
}

static int EDM_BINARY_Compare(EDM_BINARY e, EDM_BINARY fe)
{
    return umockvalue_are_equal_EDM_BINARY(&e, &fe);
}

static AGENT_DATA_TYPES_RESULT my_Create_AGENT_DATA_TYPE_from_DOUBLE(AGENT_DATA_TYPE* agentData, double v)
{
    (void)v;
    Create_AGENT_DATA_TYPE_from_DOUBLE_agentData = agentData;
    return AGENT_DATA_TYPES_OK;
}

static DEVICE_RESULT my_Device_PublishTransacted(TRANSACTION_HANDLE transactionHandle, const char* propertyName, const AGENT_DATA_TYPE* data)
{
    (void)transactionHandle;
    if (
        (
        (strcmp(propertyName, "this_is_double") == 0) &&
            (data != Create_AGENT_DATA_TYPE_from_DOUBLE_agentData)
            )
        /*the below cannot be checked easily because there are 2 types (int, int32_t) setting the same CReate_AGET_DATA_TYPE_from_SINT32_agentData*/
        /*same goes for long and sint64_t*/
        /*(
        (strcmp(propertyName, "this_is_int") == 0) &&
        (data != Create_AGENT_DATA_TYPE_from_DOUBLE_agentData)
        )*/
        ||
        (
        (strcmp(propertyName, "this_is_float") == 0) &&
            (data != Create_AGENT_DATA_TYPE_from_FLOAT_agentData)
            )
        ||
        (
        (strcmp(propertyName, "this_is_sint8_t") == 0) &&
            (data != Create_AGENT_DATA_TYPE_from_SINT8_agentData)
            )
        ||
        (
        (strcmp(propertyName, "this_is_uint8_t") == 0) &&
            (data != Create_AGENT_DATA_TYPE_from_UINT8_agentData)
            )
        ||
        (
        (strcmp(propertyName, "this_is_int16_t") == 0) &&
            (data != Create_AGENT_DATA_TYPE_from_SINT16_agentData)
            )
        ||
        (
        (strcmp(propertyName, "this_is_bool") == 0) &&
            (data != Create_EDM_BOOLEAN_from_int_agentData)
            )
        ||
        (
        (strcmp(propertyName, "this_is_ascii_char_ptr") == 0) &&
            (data != Create_AGENT_DATA_TYPE_from_charz_agentData)
            )
        ||
        (
        (strcmp(propertyName, "this_is_ascii_char_ptr_no_quotes") == 0) &&
            (data != Create_AGENT_DATA_TYPE_from_charz_no_quotes_agentData)
            )
        ||
        (
        (strcmp(propertyName, "this_is_EdmDateTimeOffset") == 0) &&
            (data != Create_AGENT_DATA_TYPE_from_EDM_DATE_TIME_OFFSET_agentData)
            )
        )
    {
        ASSERT_FAIL("where did you get that AGENT_DATA_TYPE?");
    }
    Device_PublishTransacted_agentData = data;
    return DEVICE_OK;
}

static void my_Destroy_AGENT_DATA_TYPE(AGENT_DATA_TYPE* agentData)
{
    Destroy_AGENT_DATA_TYPE_agentData = agentData;
}

static AGENT_DATA_TYPES_RESULT my_Create_AGENT_DATA_TYPE_from_SINT32(AGENT_DATA_TYPE* agentData, int32_t v)
{
    (void)(v);
    Create_AGENT_DATA_TYPE_from_SINT32_agentData = agentData;
    return AGENT_DATA_TYPES_OK;
}

static void* toBeCleaned = NULL; /*this variable exists because bad semantics in _CancelTransaction/EndTransaction.*/
static TRANSACTION_HANDLE my_Device_StartTransaction(DEVICE_HANDLE deviceHandle)
{
    (void)(deviceHandle);
    return (TRANSACTION_HANDLE)(toBeCleaned=my_gballoc_malloc(1));
}

static DEVICE_RESULT my_Device_EndTransaction(TRANSACTION_HANDLE transactionHandle, unsigned char** destination, size_t* destinationSize)
{
    (void)(destination, destinationSize);
    ASSERT_ARE_EQUAL(void_ptr, transactionHandle, toBeCleaned);
    my_gballoc_free((void*)transactionHandle);
    toBeCleaned = NULL;
    return DEVICE_OK;
}

static DEVICE_RESULT my_Device_CancelTransaction(TRANSACTION_HANDLE transactionHandle)
{
    ASSERT_ARE_EQUAL(void_ptr, transactionHandle, toBeCleaned);
    my_gballoc_free((void*)transactionHandle);
    toBeCleaned = NULL;
    return DEVICE_OK;
}

TEST_DEFINE_ENUM_TYPE(CODEFIRST_RESULT, CODEFIRST_RESULT_VALUES);
IMPLEMENT_UMOCK_C_ENUM_TYPE(CODEFIRST_RESULT, CODEFIRST_RESULT_VALUES);
TEST_DEFINE_ENUM_TYPE(DEVICE_RESULT, DEVICE_RESULT_VALUES);
IMPLEMENT_UMOCK_C_ENUM_TYPE(DEVICE_RESULT, DEVICE_RESULT_VALUES);

static TEST_MUTEX_HANDLE g_testByTest;
static TEST_MUTEX_HANDLE g_dllByDll;

static char someChars[] = { "someChars" };
static char someMoreChars[] = { "someMoreChars" };
static AGENT_DATA_TYPE someDouble;
static AGENT_DATA_TYPE someInt32;
static AGENT_DATA_TYPE arrayOfAgentDataType[15];

static EDM_DATE_TIME_OFFSET someEdmDateTimeOffset;
static EDM_GUID someEdmGuid;
static EDM_BINARY someEdmBinary;
static void* g_InvokeActionCallbackArgument;

typedef struct SimpleDevice_TAG
{
    unsigned char __SimpleDevice_begin;
    int reported_this_is_int;
    double reported_this_is_double;
    double this_is_double;
    int this_is_int;
} SimpleDevice;

static const WRAPPER_ARGUMENT setSpeedArguments[] = { { "double", "theSpeed" } };
/*                                                                      type                                 * next                             reportedProperty                                                                                                                                                                            structure                       field                                                       property                                                                                                                                                    action                                                          model*/
static const REFLECTED_SOMETHING reported_this_is_int               = { REFLECTION_REPORTED_PROPERTY_TYPE,  NULL,                               {   { "reported_this_is_int", "int", Create_AGENT_DATA_TYPE_From_Ptr_reported_this_is_int, offsetof(SimpleDevice, reported_this_is_int), sizeof(int), "SimpleDevice" },                     { 0 },                          { 0 },                                                      { 0 },                                                                                                                                                      { 0 },                                                          { 0 } } };
static const REFLECTED_SOMETHING reported_this_is_double            = { REFLECTION_REPORTED_PROPERTY_TYPE,  &reported_this_is_int,              {   { "reported_this_is_double", "double", Create_AGENT_DATA_TYPE_From_Ptr_reported_this_is_double, offsetof(SimpleDevice, reported_this_is_double), sizeof(double), "SimpleDevice" },      { 0 },                          { 0 },                                                      { 0 },                                                                                                                                                      { 0 },                                                          { 0 } } };
static const REFLECTED_SOMETHING this_is_double_Property            = { REFLECTION_PROPERTY_TYPE,           &reported_this_is_double,           {   { 0 },                                                                                                                                                                                  { 0 },                          { 0 },                                                      { "this_is_double", "double", Create_AGENT_DATA_TYPE_From_Ptr_this_is_double, offsetof(SimpleDevice, this_is_double), sizeof(double), "SimpleDevice"},      { 0 },                                                          { 0 } } };
static const REFLECTED_SOMETHING this_is_int_Property               = { REFLECTION_PROPERTY_TYPE,           &this_is_double_Property,           {   { 0 },                                                                                                                                                                                  { 0 },                          { 0 },                                                      { "this_is_int", "int", Create_AGENT_DATA_TYPE_From_Ptr_this_is_int, offsetof(SimpleDevice, this_is_int), sizeof(int), "SimpleDevice"},                     { 0 },                                                          { 0 } } };
static const REFLECTED_SOMETHING SimpleDevice_Model                 = { REFLECTION_MODEL_TYPE,              &this_is_int_Property,              {   { 0 },                                                                                                                                                                                  { 0 },                          { 0 },                                                      { 0 },                                                                                                                                                      { 0 },                                                          { "SimpleDevice"} } };
static const REFLECTED_SOMETHING whereIsMyDevice_Struct             = { REFLECTION_STRUCT_TYPE,             &SimpleDevice_Model,                {   { 0 },                                                                                                                                                                                  { "GeoLocation" },              { 0 },                                                      { 0 },                                                                                                                                                      { 0 },                                                          { 0 } } };
static const REFLECTED_SOMETHING Lat_Field                          = { REFLECTION_FIELD_TYPE,              &whereIsMyDevice_Struct,            {   { 0 },                                                                                                                                                                                  { 0 },                          { "Lat", "double", "GeoLocation" },                         { 0 },                                                                                                                                                      { 0 },                                                          { 0 } } };
static const REFLECTED_SOMETHING Long_Field                         = { REFLECTION_FIELD_TYPE,              &Lat_Field,                         {   { 0 },                                                                                                                                                                                  { 0 },                          { "Long", "double", "GeoLocation" },                        { 0 },                                                                                                                                                      { 0 },                                                          { 0 } } };
static const REFLECTED_SOMETHING theCarIsBehindTheVan_Struct        = { REFLECTION_STRUCT_TYPE,             &Long_Field,                        {   { 0 },                                                                                                                                                                                  { "theCarIsBehindTheVan" },     { 0 },                                                      { 0 },                                                                                                                                                      { 0 },                                                          { 0 } } };
static const REFLECTED_SOMETHING Alt_Field                          = { REFLECTION_FIELD_TYPE,              &theCarIsBehindTheVan_Struct,       {   { 0 },                                                                                                                                                                                  { 0 },                          { "Alt", "int", "theCarIsBehindTheVan" },                   { 0 },                                                                                                                                                      { 0 },                                                          { 0 } } };
static const REFLECTED_SOMETHING whereIsMyCar_Field                 = { REFLECTION_FIELD_TYPE,              &Alt_Field,                         {   { 0 },                                                                                                                                                                                  { 0 },                          { "whereIsMyCar", "GeoLocation", "theCarIsBehindTheVan" },  { 0 },                                                                                                                                                      { 0 },                                                          { 0 } } };
static const REFLECTED_SOMETHING setSpeed_Action                    = { REFLECTION_ACTION_TYPE,             &whereIsMyCar_Field,                {   { 0 },                                                                                                                                                                                  { 0 },                          { 0 },                                                      { 0 },                                                                                                                                                      { "setSpeed", 1, setSpeedArguments, NULL, "TruckType" },        { 0 } } };
static const REFLECTED_SOMETHING reset_Action                       = { REFLECTION_ACTION_TYPE,             &setSpeed_Action,                   {   { 0 },                                                                                                                                                                                  { 0 },                          { 0 },                                                      { 0 },                                                                                                                                                      { "reset", 0, NULL, NULL, "TruckType" },                        { 0 } } };
static const REFLECTED_SOMETHING truckType_Model                    = { REFLECTION_MODEL_TYPE,              &reset_Action,                      {   { 0 },                                                                                                                                                                                  { 0 },                          { 0 },                                                      { 0 },                                                                                                                                                      { 0 },                                                          { "TruckType"} } };
static const REFLECTED_DATA_FROM_DATAPROVIDER testReflectedData     = { &truckType_Model };


typedef struct InnerType_TAG
{
    unsigned char __InnerType_begin;
    double this_is_double;
    int this_is_reported_int_Property_2;
    int this_is_int;
} InnerType;

typedef struct OuterType_TAG
{
    unsigned char __OuterType_begin;
    InnerType Inner;
    int this_is_int;
} OuterType;

void* OuterType_reset_device;
EXECUTE_COMMAND_RESULT OuterType_reset(void* device, size_t ParameterCount, const AGENT_DATA_TYPE* values)
{
    (void)ParameterCount;
    (void)values;
    OuterType_reset_device = device;
    return EXECUTE_COMMAND_SUCCESS;
}

void* InnerType_reset_device;
EXECUTE_COMMAND_RESULT InnerType_reset(void* device, size_t ParameterCount, const AGENT_DATA_TYPE* values)
{
    (void)ParameterCount;
    (void)values;
    InnerType_reset_device = device;
    return EXECUTE_COMMAND_SUCCESS;
}

static const SCHEMA_MODEL_TYPE_HANDLE TEST_INNERTYPE_MODEL_HANDLE = (SCHEMA_MODEL_TYPE_HANDLE)0x5555;
static const SCHEMA_MODEL_TYPE_HANDLE TEST_OUTERTYPE_MODEL_HANDLE = (SCHEMA_MODEL_TYPE_HANDLE)0x5556;

/*                                                                      type                                 * next                             reportedProperty                                                                                                                                                                            structure                       field                                                       property                                                                                                                                                    action                                                          model*/
static const REFLECTED_SOMETHING OuterType_reset_Action             = { REFLECTION_ACTION_TYPE,             NULL,                               {   { 0 },                                                                                                                                                                                  { 0 },                          { 0 },                                                      { 0 },                                                                                                                                                      { "reset", 0, NULL, OuterType_reset, "OuterType" },             { 0 } } };
static const REFLECTED_SOMETHING InnerType_reset_Action             = { REFLECTION_ACTION_TYPE,             &OuterType_reset_Action,            {   { 0 },                                                                                                                                                                                  { 0 },                          { 0 },                                                      { 0 },                                                                                                                                                      { "reset", 0, NULL, InnerType_reset, "InnerType" },             { 0 } } };
static const REFLECTED_SOMETHING this_is_int_Property_2             = { REFLECTION_PROPERTY_TYPE,           &InnerType_reset_Action,            {   { 0 },                                                                                                                                                                                  { 0 },                          { 0 },                                                      { "this_is_int", "int", Create_AGENT_DATA_TYPE_From_Ptr_this_is_int, offsetof(InnerType, this_is_int), sizeof(int), "InnerType" },                          { 0 },                                                          { 0 } } };
static const REFLECTED_SOMETHING this_is_reported_int_Property_2    = { REFLECTION_REPORTED_PROPERTY_TYPE,  &this_is_int_Property_2,            {   { "this_is_reported_int_Property_2", "int", Create_AGENT_DATA_TYPE_From_Ptr_this_is_int, offsetof(InnerType, this_is_reported_int_Property_2), sizeof(int), "InnerType" },              { 0 },                          { 0 },                                                      { 0 },                                                                                                                                                      { 0 },                                                          { 0 } } };
static const REFLECTED_SOMETHING this_is_double_Property_2          = { REFLECTION_PROPERTY_TYPE,           &this_is_reported_int_Property_2,   {   { 0 },                                                                                                                                                                                  { 0 },                          { 0 },                                                      { "this_is_double", "double", Create_AGENT_DATA_TYPE_From_Ptr_this_is_double, offsetof(InnerType, this_is_double), sizeof(double), "InnerType"},            { 0 },                                                          { 0 } } };
static const REFLECTED_SOMETHING InnerType_Model                    = { REFLECTION_MODEL_TYPE,              &this_is_double_Property_2,         {   { 0 },                                                                                                                                                                                  { 0 },                          { 0 },                                                      { 0 },                                                                                                                                                      { 0 },                                                          { "InnerType"} } };
static const REFLECTED_SOMETHING Inner_Property                     = { REFLECTION_PROPERTY_TYPE,           &InnerType_Model,                   {   { 0 },                                                                                                                                                                                  { 0 },                          { 0 },                                                      { "Inner", "InnerType", Create_AGENT_DATA_TYPE_From_Ptr_this_is_double, offsetof(OuterType, Inner), sizeof(InnerType), "OuterType"},                        { 0 },                                                          { 0 } } };
static const REFLECTED_SOMETHING OuterType_Model                    = { REFLECTION_MODEL_TYPE,              &Inner_Property,                    {   { 0 },                                                                                                                                                                                  { 0 },                          { 0 },                                                      { 0 },                                                                                                                                                      { 0 },                                                          { "OuterType"} } };
const REFLECTED_DATA_FROM_DATAPROVIDER testModelInModelReflected    = { &OuterType_Model };


static unsigned char edmBinarySource[] = { 1, 42, 43, 44, 1 };

static void on_umock_c_error(UMOCK_C_ERROR_CODE error_code)
{
    char temp_str[256];
    (void)snprintf(temp_str, sizeof(temp_str), "umock_c reported error :%s", ENUM_TO_STRING(UMOCK_C_ERROR_CODE, error_code));
    ASSERT_FAIL(temp_str);
}

static DEVICE_RESULT my_Device_Create(SCHEMA_MODEL_TYPE_HANDLE modelHandle, pfDeviceActionCallback deviceActionCallback, void* callbackUserContext, bool includePropertyPath, DEVICE_HANDLE* deviceHandle)
{
    (void)(includePropertyPath, deviceActionCallback, modelHandle);
    *deviceHandle = TEST_DEVICE_HANDLE;
    g_InvokeActionCallbackArgument = callbackUserContext;
    return DEVICE_OK;
}

BEGIN_TEST_SUITE(CodeFirst_ut_Dummy_Data_Provider)

    TEST_SUITE_INITIALIZE(TestClassInitialize)
    {
        TEST_INITIALIZE_MEMORY_DEBUG(g_dllByDll);

        g_testByTest = TEST_MUTEX_CREATE();
        ASSERT_IS_NOT_NULL(g_testByTest);

        (void)umock_c_init(on_umock_c_error);
        
        (void)umocktypes_bool_register_types();
        (void)umocktypes_charptr_register_types();
        (void)umocktypes_stdint_register_types();

        REGISTER_GLOBAL_MOCK_HOOK(Device_Create, my_Device_Create);
        REGISTER_UMOCK_ALIAS_TYPE(SCHEMA_MODEL_TYPE_HANDLE, void*);
        REGISTER_UMOCK_ALIAS_TYPE(pfDeviceActionCallback, void*);
        REGISTER_UMOCK_ALIAS_TYPE(DEVICE_HANDLE, void*);
        REGISTER_UMOCK_ALIAS_TYPE(TRANSACTION_HANDLE, void*);
        REGISTER_UMOCK_ALIAS_TYPE(SCHEMA_HANDLE, void*);
        REGISTER_UMOCK_ALIAS_TYPE(SCHEMA_STRUCT_TYPE_HANDLE, void*);
        REGISTER_UMOCK_ALIAS_TYPE(SCHEMA_ACTION_HANDLE, void*);
        REGISTER_UMOCK_ALIAS_TYPE(STRING_HANDLE, void*);
        
        
        REGISTER_GLOBAL_MOCK_RETURN(Schema_GetModelName, TEST_MODEL_NAME);
        REGISTER_GLOBAL_MOCK_HOOK(Create_AGENT_DATA_TYPE_from_DOUBLE, my_Create_AGENT_DATA_TYPE_from_DOUBLE);
        REGISTER_GLOBAL_MOCK_FAIL_RETURN(Create_AGENT_DATA_TYPE_from_DOUBLE, AGENT_DATA_TYPES_JSON_ENCODER_ERRROR);


        REGISTER_UMOCK_VALUE_TYPE(EDM_DATE_TIME_OFFSET,
            umockvalue_stringify_EDM_DATE_TIME_OFFSET,
            umockvalue_are_equal_EDM_DATE_TIME_OFFSET,
            umockvalue_copy_EDM_DATE_TIME_OFFSET, 
            umockvalue_free_EDM_DATE_TIME_OFFSET
        );
        
        REGISTER_TYPE(DEVICE_RESULT, DEVICE_RESULT);
        REGISTER_TYPE(CODEFIRST_RESULT, CODEFIRST_RESULT);
        REGISTER_TYPE(AGENT_DATA_TYPES_RESULT, AGENT_DATA_TYPES_RESULT);
        REGISTER_TYPE(SCHEMA_RESULT, SCHEMA_RESULT);
        REGISTER_TYPE(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_RESULT);
        
        REGISTER_GLOBAL_MOCK_HOOK(Device_PublishTransacted, my_Device_PublishTransacted);
        REGISTER_GLOBAL_MOCK_FAIL_RETURN(Device_PublishTransacted, DEVICE_ERROR);
        REGISTER_GLOBAL_MOCK_HOOK(Destroy_AGENT_DATA_TYPE, my_Destroy_AGENT_DATA_TYPE);
        
        REGISTER_GLOBAL_MOCK_HOOK(Device_EndTransaction, my_Device_EndTransaction);
        REGISTER_GLOBAL_MOCK_FAIL_RETURN(Device_EndTransaction, DEVICE_ERROR);

        REGISTER_GLOBAL_MOCK_HOOK(Device_StartTransaction, my_Device_StartTransaction);
        REGISTER_GLOBAL_MOCK_FAIL_RETURN(Device_StartTransaction, NULL);

        REGISTER_GLOBAL_MOCK_HOOK(Device_CancelTransaction, my_Device_CancelTransaction);
        REGISTER_GLOBAL_MOCK_HOOK(Create_AGENT_DATA_TYPE_from_SINT32, my_Create_AGENT_DATA_TYPE_from_SINT32);
        REGISTER_GLOBAL_MOCK_FAIL_RETURN(Create_AGENT_DATA_TYPE_from_SINT32, AGENT_DATA_TYPES_JSON_ENCODER_ERRROR);

        REGISTER_GLOBAL_MOCK_RETURN(Schema_Create, TEST_SCHEMA_HANDLE);
        REGISTER_GLOBAL_MOCK_FAIL_RETURN(Schema_Create, NULL);

        REGISTER_GLOBAL_MOCK_RETURN(Schema_CreateStructType, TEST_STRUCT_TYPE_HANDLE);
        REGISTER_GLOBAL_MOCK_RETURN(Schema_AddStructTypeProperty, SCHEMA_OK);
        REGISTER_GLOBAL_MOCK_RETURN(Schema_CreateModelType, TEST_MODEL_HANDLE);
        REGISTER_GLOBAL_MOCK_RETURN(Schema_GetModelByName, (SCHEMA_MODEL_TYPE_HANDLE)NULL);
        REGISTER_GLOBAL_MOCK_RETURN(Schema_AddModelProperty, SCHEMA_OK);
        REGISTER_GLOBAL_MOCK_RETURN(Schema_CreateModelAction, TEST1_ACTION_HANDLE);
        REGISTER_GLOBAL_MOCK_RETURN(Schema_AddModelModel, SCHEMA_OK);

        REGISTER_GLOBAL_MOCK_HOOK(STRING_new, real_STRING_new);
        REGISTER_GLOBAL_MOCK_HOOK(STRING_clone, real_STRING_clone);
        REGISTER_GLOBAL_MOCK_HOOK(STRING_construct, real_STRING_construct);
        REGISTER_GLOBAL_MOCK_HOOK(STRING_construct_n, real_STRING_construct_n);
        REGISTER_GLOBAL_MOCK_HOOK(STRING_new_with_memory, real_STRING_new_with_memory);
        REGISTER_GLOBAL_MOCK_HOOK(STRING_new_quoted, real_STRING_new_quoted);
        REGISTER_GLOBAL_MOCK_HOOK(STRING_new_JSON, real_STRING_new_JSON);
        REGISTER_GLOBAL_MOCK_HOOK(STRING_from_byte_array, real_STRING_from_byte_array);
        REGISTER_GLOBAL_MOCK_HOOK(STRING_delete, real_STRING_delete);
        REGISTER_GLOBAL_MOCK_HOOK(STRING_concat, real_STRING_concat);
        REGISTER_GLOBAL_MOCK_FAIL_RETURN(STRING_concat, __LINE__);

        REGISTER_GLOBAL_MOCK_HOOK(STRING_concat_with_STRING, real_STRING_concat_with_STRING);
        REGISTER_GLOBAL_MOCK_HOOK(STRING_quote, real_STRING_quote);
        REGISTER_GLOBAL_MOCK_HOOK(STRING_copy, real_STRING_copy);
        REGISTER_GLOBAL_MOCK_HOOK(STRING_copy_n, real_STRING_copy_n);
        REGISTER_GLOBAL_MOCK_HOOK(STRING_c_str, real_STRING_c_str);
        REGISTER_GLOBAL_MOCK_HOOK(STRING_empty, real_STRING_empty);
        REGISTER_GLOBAL_MOCK_HOOK(STRING_length, real_STRING_length);
        REGISTER_GLOBAL_MOCK_HOOK(STRING_compare, real_STRING_compare);

    }


    TEST_SUITE_CLEANUP(TestClassCleanup)
    {
        umock_c_deinit();

        TEST_MUTEX_DESTROY(g_testByTest);
        TEST_DEINITIALIZE_MEMORY_DEBUG(g_dllByDll);
    }

    TEST_FUNCTION_INITIALIZE(TestMethodInitialize)
    {
        if (TEST_MUTEX_ACQUIRE(g_testByTest))
        {
            ASSERT_FAIL("our mutex is ABANDONED. Failure in test framework");
        }

        umock_c_reset_all_calls();


        someEdmDateTimeOffset.dateTime.tm_year = 2014 - 1900;
        someEdmDateTimeOffset.dateTime.tm_mon = 1 - 1;
        someEdmDateTimeOffset.dateTime.tm_mday = 2;
        someEdmDateTimeOffset.dateTime.tm_hour = 3;
        someEdmDateTimeOffset.dateTime.tm_min = 4;
        someEdmDateTimeOffset.dateTime.tm_sec = 5;
        someEdmDateTimeOffset.hasFractionalSecond = 1;
        someEdmDateTimeOffset.fractionalSecond = 666666666666;
        someEdmDateTimeOffset.hasTimeZone = 1;
        someEdmDateTimeOffset.timeZoneHour = 7;
        someEdmDateTimeOffset.timeZoneMinute = 8;

        const EDM_GUID source= { { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 } };
        memcpy(someEdmGuid.GUID, source.GUID, 16);

        
        someEdmBinary.size = 5;
        someEdmBinary.data = edmBinarySource;

        someDouble.type = EDM_DOUBLE_TYPE;
        someDouble.value.edmDouble.value = 0.42;

        someInt32.type = EDM_INT32_TYPE;
        someInt32.value.edmInt32.value = -34;

        InnerType_reset_device = NULL;
        OuterType_reset_device = NULL;

        DummyDataProvider_reset_wasCalled = false;

        DummyDataProvider_setSpeed_wasCalled = false;
        DummyDataProvider_setSpeed_theSpeed = -1.0;

        DummyDataProvider_test1_wasCalled = false;
        DummyDataProvider_test1_P1 = -1.0;
        DummyDataProvider_test1_P2 = -1;
        DummyDataProvider_test1_P3 = -1.0f;
        DummyDataProvider_test1_P4 = -1;
        DummyDataProvider_test1_P5 = -1;
        DummyDataProvider_test1_P6 = 255;
        DummyDataProvider_test1_P7 = -1;
        DummyDataProvider_test1_P8 = -1;
        DummyDataProvider_test1_P9 = -1;
        memset(DummyDataProvider_test1_P11, 0, P11_MAX_SIZE);
        DummyDataProvider_test1_P10 = false;
        free(DummyDataProvider_test1_P14.data);
        DummyDataProvider_test1_P14.data = NULL;
        DummyDataProvider_test1_P14.size= 0;

        arrayOfAgentDataType[0].type = EDM_DOUBLE_TYPE;
        arrayOfAgentDataType[0].value.edmDouble.value = 42.0;
        arrayOfAgentDataType[1].type = EDM_INT32_TYPE;
        arrayOfAgentDataType[1].value.edmInt32.value = 4;
        arrayOfAgentDataType[2].type = EDM_SINGLE_TYPE;
        arrayOfAgentDataType[2].value.edmSingle.value = 24.0f;
        arrayOfAgentDataType[3].type = EDM_INT64_TYPE;
        arrayOfAgentDataType[3].value.edmInt32.value = 2;
        arrayOfAgentDataType[4].type = EDM_SBYTE_TYPE;
        arrayOfAgentDataType[4].value.edmSbyte.value = 3;
        arrayOfAgentDataType[5].type = EDM_BYTE_TYPE;
        arrayOfAgentDataType[5].value.edmByte.value = 4;
        arrayOfAgentDataType[6].type = EDM_INT16_TYPE;
        arrayOfAgentDataType[6].value.edmInt16.value = 5;
        arrayOfAgentDataType[7].type = EDM_INT32_TYPE;
        arrayOfAgentDataType[7].value.edmInt32.value = 6;
        arrayOfAgentDataType[8].type = EDM_INT64_TYPE;
        arrayOfAgentDataType[8].value.edmInt64.value = 7;
        arrayOfAgentDataType[9].type = EDM_BOOLEAN_TYPE;
        arrayOfAgentDataType[9].value.edmBoolean.value = EDM_TRUE;
        arrayOfAgentDataType[10].type = EDM_STRING_TYPE;
        arrayOfAgentDataType[10].value.edmString.chars = someChars;
        arrayOfAgentDataType[14].value.edmString.length = strlen(someChars);
        arrayOfAgentDataType[11].type = EDM_DATE_TIME_OFFSET_TYPE;
        arrayOfAgentDataType[11].value.edmDateTimeOffset = someEdmDateTimeOffset;
        arrayOfAgentDataType[12].type = EDM_GUID_TYPE;
        arrayOfAgentDataType[12].value.edmGuid = someEdmGuid;
        arrayOfAgentDataType[13].type = EDM_BINARY_TYPE;
        arrayOfAgentDataType[13].value.edmBinary = someEdmBinary;
        arrayOfAgentDataType[14].type = EDM_STRING_NO_QUOTES_TYPE;
        arrayOfAgentDataType[14].value.edmStringNoQuotes.chars = someMoreChars;
        arrayOfAgentDataType[14].value.edmStringNoQuotes.length = strlen(someMoreChars);

        toBeCleaned = NULL;

        (void)CodeFirst_Init(NULL);

    }

    TEST_FUNCTION_CLEANUP(TestMethodCleanup)
    {
        if (toBeCleaned != NULL)
        {
            free(toBeCleaned);
            toBeCleaned = NULL;
        }

        free(DummyDataProvider_test1_P14.data);
        DummyDataProvider_test1_P14.data = NULL;
        DummyDataProvider_test1_P14.size = 0;

        CodeFirst_Deinit();
        TEST_MUTEX_RELEASE(g_testByTest);
    }

    TEST_FUNCTION(C_CPLUSPLUS_SANITY_CHECKS)
    {
        ///arrange

        ///act
        size_t C_has_sizeof_bool = sizeof_bool();

        ///assert
        ASSERT_ARE_EQUAL(size_t, sizeof(bool), C_has_sizeof_bool);
    }

    /*Tests_CODEFIRST_002:[ CodeFirst_RegisterSchema shall create the schema information and give it to the Schema module for one schema, identified by the metadata argument. On success, it shall return a handle to the model.]*/
    TEST_FUNCTION(CodeFirst_Init_succeds)
    {
        

        ///arrange
        CODEFIRST_RESULT result;
        CodeFirst_Deinit();
        umock_c_reset_all_calls();

        ///act
        result = CodeFirst_Init(NULL);

        ///assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_OK, result);
    }

    /*Tests_SRS_CODEFIRST_99_003:[ If the module is already initialized, the initialization shall fail and the return value shall be CODEFIRST_ALREADY_INIT.]*/
    TEST_FUNCTION(CodeFirst_Init_after_Init_fails)
    {
        ///arrange
        CODEFIRST_RESULT result;
        (void)CodeFirst_Init(NULL);

        umock_c_reset_all_calls();

        ///act
        result = CodeFirst_Init(NULL);

        ///assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_ALREADY_INIT, result);
    }

    /* CodeFirst_InvokeAction */

    /*Tests_SRS_CODEFIRST_99_066:[ If actionName, relativeActionPath or deviceHandle is NULL then EXECUTE_COMMAND_ERROR shall be returned*/
    TEST_FUNCTION(CodeFirst_InvokeAction_with_NULL_action_fails)
    {
        ///arrange
        (void)CodeFirst_Init(NULL);
        umock_c_reset_all_calls();

        ///act
        EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, NULL, "",  NULL, 1, &someDouble);

        ///assert
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
    }


    /*Tests_SRS_CODEFIRST_99_066:[ If actionName, relativeActionPath or deviceHandle is NULL then EXECUTE_COMMAND_ERROR shall be returned*/
    TEST_FUNCTION(CodeFirst_InvokeAction_with_NULL_DeviceHandle_fails)
    {
        ///arrange
        (void)CodeFirst_Init(NULL);
            

        ///act
        EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(NULL, NULL, "", "reset", 1, &someDouble);

        ///assert
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
    }

    /*Tests_SRS_CODEFIRST_99_066:[ If actionName, relativeActionPath or deviceHandle is NULL then EXECUTE_COMMAND_ERROR shall be returned*/
    TEST_FUNCTION(CodeFirst_InvokeAction_With_NULL_Relative_Path_Fails)
    {
        ///arrange
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        ///act
        EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, NULL, "reset", 0, NULL);

        ///assert
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_CODEFIRST_99_068:[ If the function is called before CodeFirst is initialized then EXECUTE_COMMAND_ERROR shall be returned.] */
    TEST_FUNCTION(CodeFirst_InvokeAction_When_Not_Initialized_Fails)
    {
        ///arrange
        CodeFirst_Deinit();
        umock_c_reset_all_calls();

        ///act
        EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, NULL, "", "reset", 1, &someDouble);

        ///assert
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
    }

    /*Tests_SRS_CODEFIRST_99_067:[ If parameterCount is greater than zero and parameterValues is NULL then EXECUTE_COMMAND_ERROR shall be returned.]*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_with_NULL_parameterValues_and_positive_count_fails)
    {
        ///arrange
        (void)CodeFirst_Init(NULL);
        umock_c_reset_all_calls();

        ///act
        EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, NULL, "", "reset", 1, NULL);

        ///assert
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
    }

    /*Tests_SRS_CODEFIRST_99_078:[If such a function is not found then the function shall return EXECUTE_COMMAND_ERROR.]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_with_unknown_actions_fails)
    {
        ///arrange
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("TruckType");

        ///act
        EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "asjnhfaslk", 1, &someDouble);

        ///assert
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_CODEFIRST_99_063:[ If the function is found, then CodeFirst shall call the wrapper of the found function inside the data provider. The wrapper is linked in the reflected data to the function name. The wrapper shall be called with the same arguments as CodeFirst_InvokeAction has been called.]*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    /*Tests_SRS_SERIALIZER_99_040:[ In addition to declaring the function, DECLARE_IOT_METHOD shall provide a definition for a wrapper that takes as parameters a size_t parameterCount and const AGENT_DATA_TYPE*.] */
    /*Tests_SRS_SERIALIZER_99_041:[ This wrapper shall convert all the arguments to predefined types and then call the function written by the data provider developer.]*/
    /*Tests_SRS_SERIALIZER_99_043:[ It is valid for a method not to have any parameters.]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calls_reset_action_succeeds)
    {
        ///arrange
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("TruckType");

        ///act
        EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "reset", 0, NULL);

        ///assert
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_SUCCESS, result);
        ASSERT_IS_TRUE(DummyDataProvider_reset_wasCalled);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_CODEFIRST_99_063:[ If the function is found, then CodeFirst shall call the wrapper of the found function inside the data provider. The wrapper is linked in the reflected data to the function name. The wrapper shall be called with the same arguments as CodeFirst_InvokeAction has been called.]*/
    /*Tests_SRS_SERIALIZER_99_045:[ If the number of passed parameters doesn't match the number of declared parameters, wrapper execution shall fail and return DATA_PROVIDER_INVALID_ARG;]*/
    /*Tests_SRS_CODEFIRST_99_065:[ For all the other return values CODEFIRST_ACTION_EXECUTION_ERROR shall be returned.]*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calling_setSpeed_action_with_insuficcient_parameters_fails)
    {
        ///arrange
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("TruckType");

        ///act
        EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "setSpeed", 0, NULL);

        ///assert
        ASSERT_IS_FALSE(DummyDataProvider_setSpeed_wasCalled);
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_CODEFIRST_99_063:[ If the function is found, then CodeFirst shall call the wrapper of the found function inside the data provider. The wrapper is linked in the reflected data to the function name. The wrapper shall be called with the same arguments as CodeFirst_InvokeAction has been called.]*/
    /*Tests_SRS_SERIALIZER_99_045:[ If the number of passed parameters doesn't match the number of declared parameters, wrapper execution shall fail and return DATA_PROVIDER_INVALID_ARG;]*/
    /*Tests_SRS_CODEFIRST_99_065:[ For all the other return values CODEFIRST_ACTION_EXECUTION_ERROR shall be returned.]*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calling_setSpeed_action_with_NULL_ParameterValues_fails)
    {
        ///arrange
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "setSpeed", 1, NULL);

        ///assert
        ASSERT_IS_FALSE(DummyDataProvider_setSpeed_wasCalled);
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_CODEFIRST_99_063:[ If the function is found, then CodeFirst shall call the wrapper of the found function inside the data provider. The wrapper is linked in the reflected data to the function name. The wrapper shall be called with the same arguments as CodeFirst_InvokeAction has been called.]*/
    /*Tests_SRS_SERIALIZER_99_045:[ If the number of passed parameters doesn't match the number of declared parameters, wrapper execution shall fail and return DATA_PROVIDER_INVALID_ARG;]*/
    /*Tests_SRS_CODEFIRST_99_065:[ For all the other return values CODEFIRST_ACTION_EXECUTION_ERROR shall be returned.]*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calling_setSpeed_action_with_too_many_parameters_fails)
    {
        ///arrange
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("TruckType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "setSpeed", 2, arrayOfAgentDataType);

        ///assert
        ASSERT_IS_FALSE(DummyDataProvider_setSpeed_wasCalled);
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_CODEFIRST_99_063:[ If the function is found, then CodeFirst shall call the wrapper of the found function inside the data provider. The wrapper is linked in the reflected data to the function name. The wrapper shall be called with the same arguments as CodeFirst_InvokeAction has been called.]*/
    /*Tests_SRS_SERIALIZER_99_045:[ If the number of passed parameters doesn't match the number of declared parameters, wrapper execution shall fail and return DATA_PROVIDER_INVALID_ARG;]*/
    /*Tests_SRS_CODEFIRST_99_065:[ For all the other return values CODEFIRST_ACTION_EXECUTION_ERROR shall be returned.]*/
    /*Tests_SRS_SERIALIZER_99_046:[ If the types of the parameters do not match the declared types, DATAPROVIDER_INVALID_ARG shall be returned.]*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calling_setSpeed_with_invalid_type_for_Parameter1_fails)
    {
        ///arrange
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("TruckType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "setSpeed", 1, &someInt32);

        ///assert
        ASSERT_IS_FALSE(DummyDataProvider_setSpeed_wasCalled);
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_CODEFIRST_99_063:[ If the function is found, then CodeFirst shall call the wrapper of the found function inside the data provider. The wrapper is linked in the reflected data to the function name. The wrapper shall be called with the same arguments as CodeFirst_InvokeAction has been called.]*/
    /*Tests_SRS_SERIALIZER_99_045:[ If the number of passed parameters doesn't match the number of declared parameters, wrapper execution shall fail and return DATA_PROVIDER_INVALID_ARG;]*/
    /*Tests_SRS_CODEFIRST_99_065:[ For all the other return values CODEFIRST_ACTION_EXECUTION_ERROR shall be returned.]*/
    /*Tests_SRS_CODEFIRST_99_064:[ If the wrapper call succeeds then CODEFIRST_OK shall be returned. ]*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    /*Tests_SRS_SERIALIZER_99_040:[ In addition to declaring the function, DECLARE_IOT_METHOD shall provide a definition for a wrapper that takes as parameters a size_t parameterCount and const AGENT_DATA_TYPE*.] */
    /*Tests_SRS_SERIALIZER_99_041:[ This wrapper shall convert all the arguments to predefined types and then call the function written by the data provider developer.]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calling_setSpeed_succeeds)
    {
        ///arrange
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("TruckType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "setSpeed", 1, &someDouble);

        ///assert
        ASSERT_IS_TRUE(DummyDataProvider_setSpeed_wasCalled);
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_SUCCESS, result);
        ASSERT_ARE_EQUAL(double, 0.42, DummyDataProvider_setSpeed_theSpeed);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*from here on there are tests for "test1"*/
    /*Tests_SRS_SERIALIZER_99_042:[The parameter types are either predefined parameter types(specs SRS_SERIALIZER_99_004 - SRS_SERIALIZER_99_014)*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calling_test1_with_insufficient_parameters_fails)
    {
        ///arrange
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("TruckType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "test1", 13, arrayOfAgentDataType);

        ///assert
        ASSERT_IS_FALSE(DummyDataProvider_test1_wasCalled);
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_SERIALIZER_99_042:[The parameter types are either predefined parameter types(specs SRS_SERIALIZER_99_004 - SRS_SERIALIZER_99_014)*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calling_test1_with_too_many_parameters_fails)
    {
        ///arrange
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("TruckType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "test1", 16, arrayOfAgentDataType);

        ///assert
        ASSERT_IS_FALSE(DummyDataProvider_test1_wasCalled);
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_SERIALIZER_99_042:[The parameter types are either predefined parameter types(specs SRS_SERIALIZER_99_004 - SRS_SERIALIZER_99_014)*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calling_test1_with_NULL_parameterValues_fails)
    {
        ///arrange
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "test1", 11, NULL);

        ///assert
        ASSERT_IS_FALSE(DummyDataProvider_test1_wasCalled);
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_SERIALIZER_99_042:[The parameter types are either predefined parameter types(specs SRS_SERIALIZER_99_004 - SRS_SERIALIZER_99_014)*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calling_test1_with_parameter_1_of_wrong_type_fails)
    {
        ///arrange
        arrayOfAgentDataType[0].type = EDM_INT32_TYPE;
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("TruckType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "test1", 12, arrayOfAgentDataType);

        ///assert
        ASSERT_IS_FALSE(DummyDataProvider_test1_wasCalled);
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_SERIALIZER_99_042:[The parameter types are either predefined parameter types(specs SRS_SERIALIZER_99_004 - SRS_SERIALIZER_99_014)*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calling_test1_with_parameter_2_of_wrong_type_fails)
    {
        ///arrange
        arrayOfAgentDataType[1].type = EDM_DOUBLE_TYPE;
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("TruckType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "test1", 12, arrayOfAgentDataType);

        ///assert
        ASSERT_IS_FALSE(DummyDataProvider_test1_wasCalled);
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_SERIALIZER_99_042:[The parameter types are either predefined parameter types(specs SRS_SERIALIZER_99_004 - SRS_SERIALIZER_99_014)*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calling_test1_with_parameter_3_of_wrong_type_fails)
    {
        ///arrange
        arrayOfAgentDataType[2].type = EDM_DOUBLE_TYPE;
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE,  &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("TruckType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "test1", 12, arrayOfAgentDataType);

        ///assert
        ASSERT_IS_FALSE(DummyDataProvider_test1_wasCalled);
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_SERIALIZER_99_042:[The parameter types are either predefined parameter types(specs SRS_SERIALIZER_99_004 - SRS_SERIALIZER_99_014)*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calling_test1_with_parameter_4_of_wrong_type_fails)
    {
        ///arrange
        arrayOfAgentDataType[3].type = EDM_DOUBLE_TYPE;
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE,  &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("TruckType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "test1", 12, arrayOfAgentDataType);

        ///assert
        ASSERT_IS_FALSE(DummyDataProvider_test1_wasCalled);
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_SERIALIZER_99_042:[The parameter types are either predefined parameter types(specs SRS_SERIALIZER_99_004 - SRS_SERIALIZER_99_014)*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calling_test1_with_parameter_5_of_wrong_type_fails)
    {
        ///arrange
        arrayOfAgentDataType[4].type = EDM_DOUBLE_TYPE;
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE,  &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("TruckType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "test1", 12, arrayOfAgentDataType);

        ///assert
        ASSERT_IS_FALSE(DummyDataProvider_test1_wasCalled);
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_SERIALIZER_99_042:[The parameter types are either predefined parameter types(specs SRS_SERIALIZER_99_004 - SRS_SERIALIZER_99_014)*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calling_test1_with_parameter_6_of_wrong_type_fails)
    {
        ///arrange
        arrayOfAgentDataType[5].type = EDM_DOUBLE_TYPE;
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE,  &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("TruckType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "test1", 12, arrayOfAgentDataType);

        ///assert
        ASSERT_IS_FALSE(DummyDataProvider_test1_wasCalled);
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_SERIALIZER_99_042:[The parameter types are either predefined parameter types(specs SRS_SERIALIZER_99_004 - SRS_SERIALIZER_99_014)*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calling_test1_with_parameter_7_of_wrong_type_fails)
    {
        ///arrange
        arrayOfAgentDataType[6].type = EDM_DOUBLE_TYPE;
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE,  &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("TruckType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "test1", 12, arrayOfAgentDataType);

        ///assert
        ASSERT_IS_FALSE(DummyDataProvider_test1_wasCalled);
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_SERIALIZER_99_042:[The parameter types are either predefined parameter types(specs SRS_SERIALIZER_99_004 - SRS_SERIALIZER_99_014)*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calling_test1_with_parameter_8_of_wrong_type_fails)
    {
        ///arrange
        arrayOfAgentDataType[7].type = EDM_DOUBLE_TYPE;
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE,  &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("TruckType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "test1", 12, arrayOfAgentDataType);

        ///assert
        ASSERT_IS_FALSE(DummyDataProvider_test1_wasCalled);
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_SERIALIZER_99_042:[The parameter types are either predefined parameter types(specs SRS_SERIALIZER_99_004 - SRS_SERIALIZER_99_014)*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calling_test1_with_parameter_9_of_wrong_type_fails)
    {
        ///arrange
        arrayOfAgentDataType[8].type = EDM_DOUBLE_TYPE;
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE,  &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("TruckType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "test1", 12, arrayOfAgentDataType);

        ///assert
        ASSERT_IS_FALSE(DummyDataProvider_test1_wasCalled);
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_SERIALIZER_99_042:[The parameter types are either predefined parameter types(specs SRS_SERIALIZER_99_004 - SRS_SERIALIZER_99_014)*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calling_test1_with_parameter_10_of_wrong_type_fails)
    {
        ///arrange
        arrayOfAgentDataType[9].type = EDM_DOUBLE_TYPE;
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE,  &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("TruckType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "test1", 12, arrayOfAgentDataType);

        ///assert
        ASSERT_IS_FALSE(DummyDataProvider_test1_wasCalled);
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_SERIALIZER_99_042:[The parameter types are either predefined parameter types(specs SRS_SERIALIZER_99_004 - SRS_SERIALIZER_99_014)*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calling_test1_with_parameter_11_of_wrong_type_fails)
    {
        ///arrange
        arrayOfAgentDataType[10].type = EDM_DOUBLE_TYPE;
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE,  &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("TruckType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "test1", 12, arrayOfAgentDataType);

        ///assert
        ASSERT_IS_FALSE(DummyDataProvider_test1_wasCalled);
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_SERIALIZER_99_042:[The parameter types are either predefined parameter types(specs SRS_SERIALIZER_99_004 - SRS_SERIALIZER_99_014)*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calling_test1_with_parameter_12_of_wrong_type_fails)
    {
        ///arrange
        arrayOfAgentDataType[11].type = EDM_DOUBLE_TYPE;
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE,  &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("TruckType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "test1", 12, arrayOfAgentDataType);

        ///assert
        ASSERT_IS_FALSE(DummyDataProvider_test1_wasCalled);
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_SERIALIZER_99_042:[The parameter types are either predefined parameter types(specs SRS_SERIALIZER_99_004 - SRS_SERIALIZER_99_014)*/
    /*Tests_SRS_SERIALIZER_99_039:[ WITH_ACTION shall declare an action of the current data provider called as the first macro parameter (name) and having the first parameter called parameter1Name of type parameter1Type, the second parameter named parameter2Name having the type parameter2Type and so on. ]*/
    /*Tests_SRS_SERIALIZER_99_040:[ In addition to declaring the function, DECLARE_IOT_METHOD shall provide a definition for a wrapper that takes as parameters a size_t parameterCount and const AGENT_DATA_TYPE*.] */
    /*Tests_SRS_SERIALIZER_99_041:[ This wrapper shall convert all the arguments to predefined types and then call the function written by the data provider developer.]*/
    TEST_FUNCTION(CodeFirst_InvokeAction_calling_test1_succeeds)
    {
        ///arrange
        (void)CodeFirst_Init(NULL);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE,  &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("TruckType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "test1", 15, arrayOfAgentDataType);

        ///assert
        ASSERT_IS_TRUE(DummyDataProvider_test1_wasCalled);
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_SUCCESS, result);
        ASSERT_ARE_EQUAL(double, 42.0, DummyDataProvider_test1_P1);
        ASSERT_ARE_EQUAL(int, 4, DummyDataProvider_test1_P2);
        ASSERT_ARE_EQUAL(float, 24.0f, DummyDataProvider_test1_P3);
        ASSERT_ARE_EQUAL(int, 2, DummyDataProvider_test1_P4);
        ASSERT_ARE_EQUAL(int, 3, DummyDataProvider_test1_P5);
        ASSERT_ARE_EQUAL(int, 4, DummyDataProvider_test1_P6);
        ASSERT_ARE_EQUAL(int, 5, DummyDataProvider_test1_P7);
        ASSERT_ARE_EQUAL(int, 6, DummyDataProvider_test1_P8);
        ASSERT_ARE_EQUAL(int, 7, (int)DummyDataProvider_test1_P9);
        ASSERT_IS_TRUE(DummyDataProvider_test1_P10);
        ASSERT_ARE_EQUAL(char_ptr, "someChars", DummyDataProvider_test1_P11);
        ASSERT_IS_TRUE(umockvalue_are_equal_EDM_DATE_TIME_OFFSET(&someEdmDateTimeOffset, &DummyDataProvider_test1_P12)==0);
        ASSERT_IS_TRUE(umockvalue_are_equal_EDM_GUID(&someEdmGuid, &DummyDataProvider_test1_P13)==0);
        ASSERT_IS_TRUE(umockvalue_are_equal_EDM_BINARY(&someEdmBinary, &DummyDataProvider_test1_P14)==0);
        ASSERT_ARE_EQUAL(char_ptr, "someMoreChars", DummyDataProvider_test1_P15);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_140:[CodeFirst_InvokeAction shall pass to the action wrapper that it calls a pointer to the model where the action is defined.] */
    /* Tests_SRS_CODEFIRST_99_139:[If the relativeActionPath is empty then the action shall be looked up in the device model.] */
    /* Tests_SRS_CODEFIRST_99_138:[The relativeActionPath argument shall be used by CodeFirst_InvokeAction to find the child model where the action is declared.] */
    /* Tests_SRS_CODEFIRST_99_142:[The relativeActionPath argument shall be in the format "childModel1/childModel2/.../childModelN".] */
    TEST_FUNCTION(CodeFirst_InvokeAction_For_A_Child_Model_Passes_The_OuterType_Instance_To_The_Callback)
    {
        ///arrange
        (void)CodeFirst_Init(NULL);
        OuterType* device = (OuterType*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testModelInModelReflected, sizeof(OuterType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("OuterType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "", "reset", 0, NULL);

        ///assert
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_SUCCESS, result);
        ASSERT_ARE_EQUAL(void_ptr, device, OuterType_reset_device);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_140:[CodeFirst_InvokeAction shall pass to the action wrapper that it calls a pointer to the model where the action is defined.] */
    /* Tests_SRS_CODEFIRST_99_139:[If the relativeActionPath is empty then the action shall be looked up in the device model.] */
    /* Tests_SRS_CODEFIRST_99_138:[The relativeActionPath argument shall be used by CodeFirst_InvokeAction to find the child model where the action is declared.] */
    /* Tests_SRS_CODEFIRST_99_142:[The relativeActionPath argument shall be in the format "childModel1/childModel2/.../childModelN".] */
    TEST_FUNCTION(CodeFirst_InvokeAction_For_A_Child_Model_Passes_The_InnerType_Instance_To_The_Callback)
    {
        ///arrange
        (void)CodeFirst_Init(NULL);
        OuterType* device = (OuterType*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testModelInModelReflected, sizeof(OuterType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("OuterType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "Inner", "reset", 0, NULL);



        ///assert
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_SUCCESS, result);
        ASSERT_ARE_EQUAL(void_ptr, &device->Inner, InnerType_reset_device);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_141:[If a child model specified in the relativeActionPath argument cannot be found by CodeFirst_InvokeAction, it shall return EXECUTE_COMMAND_ERROR.] */
    TEST_FUNCTION(CodeFirst_InvokeAction_For_A_Child_Model_And_The_Model_Is_Not_Found_Fails)
    {
        ///arrange
        (void)CodeFirst_Init(NULL);
        OuterType* device = (OuterType*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testModelInModelReflected, sizeof(OuterType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("OuterType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "Inne", "reset", 0, NULL);

        ///assert
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_141:[If a child model specified in the relativeActionPath argument cannot be found by CodeFirst_InvokeAction, it shall return EXECUTE_COMMAND_ERROR.] */
    TEST_FUNCTION(CodeFirst_InvokeAction_For_A_Child_Model_And_The_Model_Is_Not_Found_Because_Path_Too_Deep_Fails)
    {
        ///arrange
        (void)CodeFirst_Init(NULL);
        OuterType* device = (OuterType*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testModelInModelReflected, sizeof(OuterType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("OuterType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "Inner/FakeInner", "reset", 0, NULL);

        ///assert
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_141:[If a child model specified in the relativeActionPath argument cannot be found by CodeFirst_InvokeAction, it shall return EXECUTE_COMMAND_ERROR.] */
    TEST_FUNCTION(CodeFirst_InvokeAction_For_A_Child_Model_And_The_Action_Is_Not_Found_Fails)
    {
        ///arrange
        (void)CodeFirst_Init(NULL);
        OuterType* device = (OuterType*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testModelInModelReflected, sizeof(OuterType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE)).SetReturn("OuterType");

        ///act
       EXECUTE_COMMAND_RESULT result = CodeFirst_InvokeAction(TEST_DEVICE_HANDLE, g_InvokeActionCallbackArgument, "Inner", "rst", 0, NULL);

        ///assert
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* CodeFirst_CreateDevice */

    /* Tests_SRS_CODEFIRST_99_080:[If CodeFirst_CreateDevice is invoked with a NULL iotHubClientHandle or model, it shall return NULL.] */
    TEST_FUNCTION(CodeFirst_CreateDevice_With_NULL_Model_Fails)
    {
        // arrange

        // act
        void* result = CodeFirst_CreateDevice(NULL, &DummyDataProvider_allReflected, 1, false);

        // assert
        ASSERT_IS_NULL(result);
    }

    /* Tests_SRS_CODEFIRST_99_079:[CodeFirst_CreateDevice shall create a device and allocate a memory block that should hold the device data.] */
    /* Tests_SRS_CODEFIRST_99_081:[CodeFirst_CreateDevice shall use Device_Create to create a device handle.] */
    /* Tests_SRS_CODEFIRST_99_082:[CodeFirst_CreateDevice shall pass to Device_Create the function CodeFirst_InvokeAction as action callback argument.] */
    /* Tests_SRS_CODEFIRST_99_101:[On success, CodeFirst_CreateDevice shall return a non NULL pointer to the device data.] */
    /* Tests_SRS_CODEFIRST_01_001: [CodeFirst_CreateDevice shall pass the includePropertyPath argument to Device_Create.] */
    TEST_FUNCTION(CodeFirst_CreateDevice_With_Valid_Arguments_and_includePropertyPath_false_Succeeds_1)
    {
        // arrange

        STRICT_EXPECTED_CALL(Device_Create(TEST_MODEL_HANDLE, CodeFirst_InvokeAction, TEST_CALLBACK_CONTEXT, false, IGNORED_PTR_ARG))
            .IgnoreArgument(3).IgnoreArgument(5);
        STRICT_EXPECTED_CALL(Schema_AddDeviceRef(IGNORED_PTR_ARG))
            .IgnoreArgument(1);

        // act
        void* result = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, 1, false);

        // assert
        ASSERT_IS_NOT_NULL(result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(result);
    }

    TEST_FUNCTION(CodeFirst_CreateDevice_With_Valid_Arguments_and_includePropertyPath_false_Succeeds_2)
    {
        // arrange

        STRICT_EXPECTED_CALL(Device_Create(TEST_MODEL_HANDLE, CodeFirst_InvokeAction, TEST_CALLBACK_CONTEXT, false, IGNORED_PTR_ARG))
            .IgnoreArgument(3).IgnoreArgument(5);
        STRICT_EXPECTED_CALL(Schema_AddDeviceRef(IGNORED_PTR_ARG))
            .IgnoreArgument(1);

        // act
        void* result = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, 1, false);

        // assert
        ASSERT_IS_NOT_NULL(result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(result);
    }

    /* Tests_SRS_CODEFIRST_01_001: [CodeFirst_CreateDevice shall pass the includePropertyPath argument to Device_Create.] */
    TEST_FUNCTION(CodeFirst_CreateDevice_With_Valid_Arguments_and_includePropertyPath_true_Succeeds)
    {
        // arrange

        STRICT_EXPECTED_CALL(Device_Create(TEST_MODEL_HANDLE, CodeFirst_InvokeAction, TEST_CALLBACK_CONTEXT, true, IGNORED_PTR_ARG))
            .IgnoreArgument(3).IgnoreArgument(5);
        STRICT_EXPECTED_CALL(Schema_AddDeviceRef(IGNORED_PTR_ARG))
            .IgnoreArgument(1);

        // act
        void* result = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, 1, true);

        // assert
        ASSERT_IS_NOT_NULL(result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(result);
    }

    /* Tests_SRS_CODEFIRST_99_084:[If Device_Create fails, CodeFirst_CreateDevice shall return NULL.] */
    TEST_FUNCTION(When_Device_Create_Fails_Then_CodeFirst_CreateDevice_Fails)
    {
        // arrange

        STRICT_EXPECTED_CALL(Device_Create(TEST_MODEL_HANDLE, CodeFirst_InvokeAction, TEST_CALLBACK_CONTEXT, false, IGNORED_PTR_ARG))
            .IgnoreArgument(3).IgnoreArgument(5).SetReturn(DEVICE_ERROR);

        // act
        void* result = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, 1, false);

        // assert
        ASSERT_IS_NULL(result);
    }

    /* Tests_SRS_CODEFIRST_99_106:[If CodeFirst_CreateDevice is called when the modules is not initialized is shall return NULL.] */
    TEST_FUNCTION(CodeFirst_CreateDevice_When_The_Module_Is_Not_Initialized_Fails)
    {
        // arrange
        CodeFirst_Deinit();
        umock_c_reset_all_calls();

        // act
        void* result = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, 1, false);

        // assert
        ASSERT_IS_NULL(result);
    }

    /* CodeFirst_DestroyDevice */

    /* Tests_SRS_CODEFIRST_99_086:[If the argument is NULL, CodeFirst_DestroyDevice shall do nothing.] */
    TEST_FUNCTION(CodeFirst_DestroyDevice_With_NULL_Argument_Does_Nothing)
    {
        // arrange

        // act
        CodeFirst_DestroyDevice(NULL);

        // assert
        // no explicit assert, uMock checks the calls
    }

    /* Tests_SRS_CODEFIRST_99_085:[CodeFirst_DestroyDevice shall free all resources associated with a device.] */
    /* Tests_SRS_CODEFIRST_99_087:[In order to release the device handle, CodeFirst_DestroyDevice shall call Device_Destroy.] */
    TEST_FUNCTION(CodeFirst_DestroyDevice_With_Valid_Argument_Destroys_The_Device)
    {
        // arrange

        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, 1, false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_Destroy(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(Schema_ReleaseDeviceRef(IGNORED_PTR_ARG))
            .IgnoreArgument(1);
        STRICT_EXPECTED_CALL(Schema_DestroyIfUnused(IGNORED_PTR_ARG))
            .IgnoreArgument(1);

        // act
        CodeFirst_DestroyDevice(device);

        // assert
        // no explicit assert, uMock checks the calls
    }

    /* CodeFirst_SendAsync */

    /* Tests_SRS_CODEFIRST_99_103:[If CodeFirst_SendAsync is called with numProperties being zero, CODEFIRST_INVALID_ARG shall be returned.] */
    TEST_FUNCTION(CodeFirst_SendAsync_With_0_NumProperties_Fails)
    {
        // arrange
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, 1, false);
        unsigned char* destination;
        size_t destinationSize;
        umock_c_reset_all_calls();

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 0, device);

        // assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_INVALID_ARG, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_088:[CodeFirst_SendAsync shall send to the Device module a set of properties.] */
    /* Tests_SRS_CODEFIRST_99_105:[The properties are passed as pointers to the memory locations where the data exists in the device block allocated by CodeFirst_CreateDevice.] */
    /* Tests_SRS_CODEFIRST_99_089:[The numProperties argument shall indicate how many properties are to be sent.] */
    /* Tests_SRS_CODEFIRST_99_090:[All the properties shall be sent together by using the transacted APIs of the device.] */
    /* Tests_SRS_CODEFIRST_99_091:[CodeFirst_SendAsync shall start a transaction by calling Device_StartTransaction.] */
    /* Tests_SRS_CODEFIRST_99_092:[CodeFirst shall publish each value by using Device_PublishTransacted.] */
    /* Tests_SRS_CODEFIRST_99_093:[After all values have been published, Device_EndTransaction shall be called.] */
    /* Tests_SRS_CODEFIRST_99_095:[For each value passed to it, CodeFirst_SendAsync shall look up to which device the value belongs.] */
    /* Tests_SRS_CODEFIRST_99_097:[For each value marshalling to AGENT_DATA_TYPE shall be performed.] */
    /* Tests_SRS_CODEFIRST_99_098:[The marshalling shall be done by calling the Create_AGENT_DATA_TYPE_from_Ptr function associated with the property.] */
    /* Tests_SRS_CODEFIRST_99_117:[On success, CodeFirst_SendAsync shall return CODEFIRST_OK.] */
    TEST_FUNCTION(CodeFirst_SendAsync_With_One_Property_Succeeds)
    {
        // arrange
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        unsigned char* destination;
        size_t destinationSize;
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(STRING_new());
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_DOUBLE(IGNORED_PTR_ARG, 0.0));
        STRICT_EXPECTED_CALL(STRING_c_str(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "this_is_double", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3);
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));
        STRICT_EXPECTED_CALL(Device_EndTransaction(IGNORED_PTR_ARG, IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(2)
            .IgnoreArgument(3);
        device->this_is_double = 42.0;

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 1, &device->this_is_double);

        // assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_OK, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_088:[CodeFirst_SendAsync shall send to the Device module a set of properties.] */
    /* Tests_SRS_CODEFIRST_99_105:[The properties are passed as pointers to the memory locations where the data exists in the device block allocated by CodeFirst_CreateDevice.] */
    /* Tests_SRS_CODEFIRST_99_089:[The numProperties argument shall indicate how many properties are to be sent.] */
    /* Tests_SRS_CODEFIRST_99_090:[All the properties shall be sent together by using the transacted APIs of the device.] */
    /* Tests_SRS_CODEFIRST_99_091:[CodeFirst_SendAsync shall start a transaction by calling Device_StartTransaction.] */
    /* Tests_SRS_CODEFIRST_99_092:[CodeFirst shall publish each value by using Device_PublishTransacted.] */
    /* Tests_SRS_CODEFIRST_99_093:[After all values have been published, Device_EndTransaction shall be called.] */
    /* Tests_SRS_CODEFIRST_99_095:[For each value passed to it, CodeFirst_SendAsync shall look up to which device the value belongs.] */
    /* Tests_SRS_CODEFIRST_99_097:[For each value marshalling to AGENT_DATA_TYPE shall be performed.] */
    /* Tests_SRS_CODEFIRST_99_098:[The marshalling shall be done by calling the Create_AGENT_DATA_TYPE_from_Ptr function associated with the property] */
    /* Tests_SRS_CODEFIRST_99_117:[On success, CodeFirst_SendAsync shall return CODEFIRST_OK.] */
    TEST_FUNCTION(CodeFirst_SendAsync_2_Properties_Succeeds)
    {
        // arrange
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(STRING_new());
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_DOUBLE(IGNORED_PTR_ARG, 0.0));
        STRICT_EXPECTED_CALL(STRING_c_str(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "this_is_double", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3);
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));
        STRICT_EXPECTED_CALL(STRING_new());
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_SINT32(IGNORED_PTR_ARG, 0));
        STRICT_EXPECTED_CALL(STRING_c_str(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "this_is_int", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3);
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));
        STRICT_EXPECTED_CALL(Device_EndTransaction(IGNORED_PTR_ARG, IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(2)
            .IgnoreArgument(3);
        device->this_is_double = 42.0;
        device->this_is_int = 1;
        unsigned char* destination;
        size_t destinationSize;

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 2, &device->this_is_double, &device->this_is_int);

        // assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_OK, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_094:[If any Device API fail, CodeFirst_SendAsync shall return CODEFIRST_DEVICE_PUBLISH_FAILED.] */
    TEST_FUNCTION(When_StartTransaction_Fails_CodeFirst_SendAsync_Fails)
    {
        // arrange
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE))
            .SetReturn((TRANSACTION_HANDLE)NULL);
        device->this_is_double = 42.0;
        unsigned char* destination;
        size_t destinationSize;

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 1, device);

        // assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_DEVICE_PUBLISH_FAILED, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_094:[If any Device API fail, CodeFirst_SendAsync shall return CODEFIRST_DEVICE_PUBLISH_FAILED.] */
    TEST_FUNCTION(When_PublishTransacted_Fails_CodeFirst_SendAsync_Fails)
    {
        // arrange
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(STRING_new());
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_DOUBLE(IGNORED_PTR_ARG, 0.0));
        STRICT_EXPECTED_CALL(STRING_c_str(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "this_is_double", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3).SetReturn(DEVICE_ERROR);
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_CancelTransaction(IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle();
        device->this_is_double = 42.0;
        unsigned char* destination;
        size_t destinationSize;

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 1, &device->this_is_double);

        // assert
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_DEVICE_PUBLISH_FAILED, result);
        

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_094:[If any Device API fail, CodeFirst_SendAsync shall return CODEFIRST_DEVICE_PUBLISH_FAILED.] */
    TEST_FUNCTION(When_PublishTransacted_Fails_For_The_2nd_Property_CodeFirst_SendAsync_Fails)
    {
        // arrange
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(STRING_new());
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_DOUBLE(IGNORED_PTR_ARG, 0.0));
        STRICT_EXPECTED_CALL(STRING_c_str(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "this_is_double", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3);
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));
        STRICT_EXPECTED_CALL(STRING_new());
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_SINT32(IGNORED_PTR_ARG, 0));
        STRICT_EXPECTED_CALL(STRING_c_str(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "this_is_int", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3).SetReturn(DEVICE_ERROR);
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_CancelTransaction(IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle();
        device->this_is_double = 42.0;
        device->this_is_int = 1;
        unsigned char* destination;
        size_t destinationSize;

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 2, &device->this_is_double, &device->this_is_int);

        // assert
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_DEVICE_PUBLISH_FAILED, result);
        

        // cleanup
        CodeFirst_DestroyDevice(device);
    }
    
    /* Tests_SRS_CODEFIRST_99_094:[If any Device API fail, CodeFirst_SendAsync shall return CODEFIRST_DEVICE_PUBLISH_FAILED.] */
    TEST_FUNCTION(When_EndTransacted_Fails_CodeFirst_SendAsync_Fails)
    {
        // arrange
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(STRING_new());
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_DOUBLE(IGNORED_PTR_ARG, 0.0));
        STRICT_EXPECTED_CALL(STRING_c_str(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "this_is_double", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3);
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));
        STRICT_EXPECTED_CALL(Device_EndTransaction(IGNORED_PTR_ARG, IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(2)
            .IgnoreArgument(3)
            .SetReturn(DEVICE_ERROR);
        device->this_is_double = 42.0;
        unsigned char* destination;
        size_t destinationSize;

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 1, &device->this_is_double);

        // assert
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_DEVICE_PUBLISH_FAILED, result);
        
        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_104:[If a property cannot be associated with a device, CodeFirst_SendAsync shall return CODEFIRST_INVALID_ARG.] */
    TEST_FUNCTION(When_An_Invalid_Pointer_Is_Passed_CodeFirst_SendAsync_Fails)
    {
        // arrange
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        umock_c_reset_all_calls();

        device->this_is_double = 42.0;
        unsigned char* destination;
        size_t destinationSize;

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 1, device - 1);

        // assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_INVALID_ARG, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_104:[If a property cannot be associated with a device, CodeFirst_SendAsync shall return CODEFIRST_INVALID_ARG.] */
    TEST_FUNCTION(When_A_Pointer_Within_The_Device_Block_But_Mismatched_Is_Passed_CodeFirst_SendAsync_Fails)
    {
        // arrange
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(STRING_new());
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_CancelTransaction(IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle();
        device->this_is_double = 42.0;
        unsigned char* destination;
        size_t destinationSize;

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 1, (unsigned char*)device + 1);

        // assert
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_INVALID_ARG, result);
      

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_099:[If Create_AGENT_DATA_TYPE_from_Ptr fails, CodeFirst_SendAsync shall return CODEFIRST_AGENT_DATA_TYPE_ERROR.] */
    TEST_FUNCTION(When_Creating_The_Agent_Data_Type_Fails_Then_CodeFirst_SendAsync_Fails)
    {
        // arrange
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(STRING_new());
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_DOUBLE(IGNORED_PTR_ARG, 0.0))
            .SetReturn(AGENT_DATA_TYPES_ERROR);
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_CancelTransaction(IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle();
        device->this_is_double = 42.0;
        unsigned char* destination;
        size_t destinationSize;

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 1, &device->this_is_double);

        // assert
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_AGENT_DATA_TYPE_ERROR, result);
        

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_099:[If Create_AGENT_DATA_TYPE_from_Ptr fails, CodeFirst_SendAsync shall return CODEFIRST_AGENT_DATA_TYPE_ERROR.] */
    TEST_FUNCTION(When_Creating_The_Agent_Data_Type_Fails_For_The_2nd_Property_Then_CodeFirst_SendAsync_Fails)
    {
        // arrange
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(STRING_new());
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_DOUBLE(IGNORED_PTR_ARG, 0.0));
        STRICT_EXPECTED_CALL(STRING_c_str(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "this_is_double", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3);
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));
        STRICT_EXPECTED_CALL(STRING_new());
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_SINT32(IGNORED_PTR_ARG, 0))
            .SetReturn(AGENT_DATA_TYPES_ERROR);
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_CancelTransaction(IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle();
        device->this_is_double = 42.0;
        unsigned char* destination;
        size_t destinationSize;

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 2, &device->this_is_double, &device->this_is_int);

        // assert
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_AGENT_DATA_TYPE_ERROR, result);
        
        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_096:[All values have to belong to the same device, otherwise CodeFirst_SendAsync shall return CODEFIRST_VALUES_FROM_DIFFERENT_DEVICES_ERROR.] */
    TEST_FUNCTION(Properties_From_2_Different_Devices_Make_CodeFirst_SendAsync_Fail)
    {
        // arrange
        SimpleDevice* device1 = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        SimpleDevice* device2 = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(STRING_new());
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_DOUBLE(IGNORED_PTR_ARG, 0.0));
        STRICT_EXPECTED_CALL(STRING_c_str(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "this_is_double", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3);
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));
        STRICT_EXPECTED_CALL(Device_CancelTransaction(IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle();
        device1->this_is_double = 42.0;
        device2->this_is_double = 42.0;
        unsigned char* destination;
        size_t destinationSize;

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 2, &device1->this_is_double, &device2->this_is_double);

        // assert
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_VALUES_FROM_DIFFERENT_DEVICES_ERROR, result);
        
        // cleanup
        CodeFirst_DestroyDevice(device1);
        CodeFirst_DestroyDevice(device2);
    }

    /* Tests_SRS_CODEFIRST_99_088:[CodeFirst_SendAsync shall send to the Device module a set of properties.] */
    /* Tests_SRS_CODEFIRST_99_105:[The properties are passed as pointers to the memory locations where the data exists in the device block allocated by CodeFirst_CreateDevice.] */
    /* Tests_SRS_CODEFIRST_99_089:[The numProperties argument shall indicate how many properties are to be sent.] */
    /* Tests_SRS_CODEFIRST_99_090:[All the properties shall be sent together by using the transacted APIs of the device.] */
    /* Tests_SRS_CODEFIRST_99_091:[CodeFirst_SendAsync shall start a transaction by calling Device_StartTransaction.] */
    /* Tests_SRS_CODEFIRST_99_092:[CodeFirst shall publish each value by using Device_PublishTransacted.] */
    /* Tests_SRS_CODEFIRST_99_093:[After all values have been published, Device_EndTransaction shall be called.] */
    /* Tests_SRS_CODEFIRST_99_095:[For each value passed to it, CodeFirst_SendAsync shall look up to which device the value belongs.] */
    /* Tests_SRS_CODEFIRST_99_097:[For each value marshalling to AGENT_DATA_TYPE shall be performed.] */
    /* Tests_SRS_CODEFIRST_99_098:[The marshalling shall be done by calling the Create_AGENT_DATA_TYPE_from_Ptr function associated with the property.] */
    /* Tests_SRS_CODEFIRST_99_117:[On success, CodeFirst_SendAsync shall return CODEFIRST_OK.] */
    TEST_FUNCTION(CodeFirst_SendAsync_With_One_Property_Succeeds_2)
    {
        // arrange
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(STRING_new());

        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_DOUBLE(IGNORED_PTR_ARG, IGNORED_NUM_ARG));
        STRICT_EXPECTED_CALL(STRING_c_str(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "this_is_double", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3);
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));
        STRICT_EXPECTED_CALL(Device_EndTransaction(IGNORED_PTR_ARG, IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(2)
            .IgnoreArgument(3);
        device->this_is_double = 42.0;
        unsigned char* destination;
        size_t destinationSize;

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 1, &device->this_is_double);

        // assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_OK, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_088:[CodeFirst_SendAsync shall send to the Device module a set of properties.] */
    /* Tests_SRS_CODEFIRST_99_105:[The properties are passed as pointers to the memory locations where the data exists in the device block allocated by CodeFirst_CreateDevice.] */
    /* Tests_SRS_CODEFIRST_99_089:[The numProperties argument shall indicate how many properties are to be sent.] */
    /* Tests_SRS_CODEFIRST_99_090:[All the properties shall be sent together by using the transacted APIs of the device.] */
    /* Tests_SRS_CODEFIRST_99_091:[CodeFirst_SendAsync shall start a transaction by calling Device_StartTransaction.] */
    /* Tests_SRS_CODEFIRST_99_092:[CodeFirst shall publish each value by using Device_PublishTransacted.] */
    /* Tests_SRS_CODEFIRST_99_093:[After all values have been published, Device_EndTransaction shall be called.] */
    /* Tests_SRS_CODEFIRST_99_095:[For each value passed to it, CodeFirst_SendAsync shall look up to which device the value belongs.] */
    /* Tests_SRS_CODEFIRST_99_097:[For each value marshalling to AGENT_DATA_TYPE shall be performed.] */
    /* Tests_SRS_CODEFIRST_99_098:[The marshalling shall be done by calling the Create_AGENT_DATA_TYPE_from_Ptr function associated with the property.] */
    /* Tests_SRS_CODEFIRST_99_117:[On success, CodeFirst_SendAsync shall return CODEFIRST_OK.] */
    TEST_FUNCTION(CodeFirst_SendAsync_2_Properties_Succeeds_2)
    {
        // arrange
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(STRING_new());
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_DOUBLE(IGNORED_PTR_ARG, (double)(IGNORED_NUM_ARG)));
        STRICT_EXPECTED_CALL(STRING_c_str(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "this_is_double", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3);
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));
        STRICT_EXPECTED_CALL(STRING_new());
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_SINT32(IGNORED_PTR_ARG, (int32_t)(IGNORED_NUM_ARG)));
        STRICT_EXPECTED_CALL(STRING_c_str(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "this_is_int", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3);
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));
        STRICT_EXPECTED_CALL(Device_EndTransaction(IGNORED_PTR_ARG, IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(2)
            .IgnoreArgument(3);
        device->this_is_double = 42.0;
        device->this_is_int = 1;
        unsigned char* destination;
        size_t destinationSize;

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 2, &device->this_is_double, &device->this_is_int);

        // assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_OK, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_130:[If a pointer to the beginning of a device block is passed to CodeFirst_SendAsync instead of a pointer to a property, CodeFirst_SendAsync shall send all the properties that belong to that device.] */
    /* Tests_SRS_CODEFIRST_99_131:[The properties shall be given to Device as one transaction, as if they were all passed as individual arguments to Code_First.] */
    TEST_FUNCTION(CodeFirst_SendAsync_The_Entire_Device_State)
    {
        // arrange
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_SINT32(IGNORED_PTR_ARG, (int32_t)(IGNORED_NUM_ARG)));
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "this_is_int", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3);
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_DOUBLE(IGNORED_PTR_ARG, (double)(IGNORED_NUM_ARG)));
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "this_is_double", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3);
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));

        STRICT_EXPECTED_CALL(Device_EndTransaction(IGNORED_PTR_ARG, IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(2)
            .IgnoreArgument(3);
        device->this_is_double = 42.0;
        device->this_is_int = 1;
        unsigned char* destination;
        size_t destinationSize;

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 1, device);

        // assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_OK, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_099:[If Create_AGENT_DATA_TYPE_from_Ptr fails, CodeFirst_SendAsync shall return CODEFIRST_AGENT_DATA_TYPE_ERROR.] */
    TEST_FUNCTION(CodeFirst_When_Create_Agent_Data_Type_For_The_First_Property_Fails_Send_The_Entire_Device_State_Fails)
    {
        // arrange
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));

        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_SINT32(IGNORED_PTR_ARG, (int32_t)(IGNORED_NUM_ARG)))
            .SetReturn(AGENT_DATA_TYPES_ERROR);
        STRICT_EXPECTED_CALL(Device_CancelTransaction(IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle();
        device->this_is_double = 42.0;
        device->this_is_int = 1;
        unsigned char* destination;
        size_t destinationSize;

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 1, device);

        // assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_AGENT_DATA_TYPE_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_094:[If any Device API fail, CodeFirst_SendAsync shall return CODEFIRST_DEVICE_PUBLISH_FAILED.] */
    TEST_FUNCTION(CodeFirst_When_Publish_For_The_First_Property_Fails_Send_The_Entire_Device_State_Fails)
    {
        // arrange
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));
        
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_SINT32(IGNORED_PTR_ARG, (int32_t)(IGNORED_NUM_ARG)));
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "this_is_int", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3)
            .SetReturn(DEVICE_ERROR);
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));
        STRICT_EXPECTED_CALL(Device_CancelTransaction(IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle();
        device->this_is_double = 42.0;
        device->this_is_int = 1;
        unsigned char* destination;
        size_t destinationSize;

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 1, device);

        // assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_DEVICE_PUBLISH_FAILED, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_099:[If Create_AGENT_DATA_TYPE_from_Ptr fails, CodeFirst_SendAsync shall return CODEFIRST_AGENT_DATA_TYPE_ERROR.] */
    TEST_FUNCTION(CodeFirst_When_Create_Agent_Data_Type_For_The_Second_Property_Fails_Send_The_Entire_Device_State_Fails)
    {
        // arrange
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_SINT32(IGNORED_PTR_ARG, (int32_t)(IGNORED_NUM_ARG)));
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "this_is_int", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3);
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_DOUBLE(IGNORED_PTR_ARG, (double)(IGNORED_NUM_ARG)))
            .SetReturn(AGENT_DATA_TYPES_ERROR);
        STRICT_EXPECTED_CALL(Device_CancelTransaction(IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle();
        device->this_is_double = 42.0;
        device->this_is_int = 1;
        unsigned char* destination;
        size_t destinationSize;

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 1, device);

        // assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_AGENT_DATA_TYPE_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_094:[If any Device API fail, CodeFirst_SendAsync shall return CODEFIRST_DEVICE_PUBLISH_FAILED.] */
    TEST_FUNCTION(CodeFirst_When_Publish_For_The_Second_Property_Fails_Send_The_Entire_Device_State_Fails)
    {
        // arrange
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_SINT32(IGNORED_PTR_ARG, (int32_t)(IGNORED_NUM_ARG)));
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "this_is_int", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3);
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_DOUBLE(IGNORED_PTR_ARG, (double)(IGNORED_NUM_ARG)));
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "this_is_double", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3)
            .SetReturn(DEVICE_ERROR);
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));
        STRICT_EXPECTED_CALL(Device_CancelTransaction(IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle();
        device->this_is_double = 42.0;
        device->this_is_int = 1;
        unsigned char* destination;
        size_t destinationSize;

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 1, device);

        // assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_DEVICE_PUBLISH_FAILED, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_133:[CodeFirst_SendAsync shall allow sending of properties that are part of a child model.] */
    /* Tests_SRS_CODEFIRST_99_136:[CodeFirst_SendAsync shall build the full path for each property and then pass it to Device_PublishTransacted.] */
    TEST_FUNCTION(CodeFirst_SendAsync_Can_Send_A_Property_From_A_Child_Model)
    {
        // arrange
        OuterType* device = (OuterType*)CodeFirst_CreateDevice(TEST_OUTERTYPE_MODEL_HANDLE, &testModelInModelReflected, sizeof(OuterType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(STRING_new());
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_OUTERTYPE_MODEL_HANDLE)).SetReturn("OuterType");
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_DOUBLE(IGNORED_PTR_ARG, (double)(IGNORED_NUM_ARG)));
        STRICT_EXPECTED_CALL(STRING_c_str(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "Inner/this_is_double", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3);
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));
        STRICT_EXPECTED_CALL(Device_EndTransaction(IGNORED_PTR_ARG, IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(2)
            .IgnoreArgument(3);
        device->Inner.this_is_double = 42.0;
        unsigned char* destination;
        size_t destinationSize;

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 1, &device->Inner.this_is_double);

        // assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_OK, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_99_133:[CodeFirst_SendAsync shall allow sending of properties that are part of a child model.] */
    /* Tests_SRS_CODEFIRST_99_136:[CodeFirst_SendAsync shall build the full path for each property and then pass it to Device_PublishTransacted.] */
    TEST_FUNCTION(CodeFirst_SendAsync_Can_Send_The_Last_Property_From_A_Child_Model_With_2_Properties)
    {
        // arrange
        OuterType* device = (OuterType*)CodeFirst_CreateDevice(TEST_OUTERTYPE_MODEL_HANDLE, &testModelInModelReflected, sizeof(OuterType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(STRING_new());
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_OUTERTYPE_MODEL_HANDLE)).SetReturn("OuterType");
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_SINT32(IGNORED_PTR_ARG, (int32_t)(IGNORED_NUM_ARG)));
        STRICT_EXPECTED_CALL(STRING_c_str(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "Inner/this_is_int", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3);
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));
        STRICT_EXPECTED_CALL(Device_EndTransaction(IGNORED_PTR_ARG, IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(2)
            .IgnoreArgument(3);
        device->Inner.this_is_int = 1;
        unsigned char* destination;
        size_t destinationSize;

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 1, &device->Inner.this_is_int);

        // assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_OK, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }


    /* Tests_SRS_CODEFIRST_04_002: [If CodeFirst_SendAsync receives destination or destinationSize NULL, CodeFirst_SendAsync shall return Invalid Argument.]*/
    TEST_FUNCTION(CodeFirst_SendAsync_With_NULL_destination_and_NonNulldestinationSize_Fails)
    {
        // arrange
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        size_t destinationSize;
        umock_c_reset_all_calls();

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(NULL, &destinationSize, 1, &device->this_is_double);

        // assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_INVALID_ARG, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* Tests_SRS_CODEFIRST_04_002: [If CodeFirst_SendAsync receives destination or destinationSize NULL, CodeFirst_SendAsync shall return Invalid Argument.]*/
    TEST_FUNCTION(CodeFirst_SendAsync_With_nonNULL_destination_and_NulldestinationSize_Fails)
    {
        // arrange
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        unsigned char* destination;
        umock_c_reset_all_calls();

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, NULL, 1, &device->this_is_double);

        // assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_INVALID_ARG, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_CODEFIRST_99_088:[CodeFirst_SendAsync shall send to the Device module a set of properties, a destination and a destinationSize.] */
    TEST_FUNCTION(CodeFirst_SendAsync_With_One_Property_CallBackAndUserContext_Succeeds)
    {
        // arrange
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(STRING_new());
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_DOUBLE(IGNORED_PTR_ARG, 0.0));
        STRICT_EXPECTED_CALL(STRING_c_str(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "this_is_double", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3);
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));
        unsigned char* destination;
        size_t destinationSize;
        STRICT_EXPECTED_CALL(Device_EndTransaction(IGNORED_PTR_ARG, &destination, &destinationSize))
            .IgnoreArgument_transactionHandle();
        device->this_is_double = 42.0;


        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 1, &device->this_is_double);

        // assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_OK, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
    }

    /* CodeFirst_RegisterSchema */
    /* Tests_SRS_CODEFIRST_99_002:[ CodeFirst_RegisterSchema shall create the schema information and give it to the Schema module for one schema, identified by the metadata argument. On success, it shall return a handle to the model.] */
    TEST_FUNCTION(CodeFirst_RegisterSchema_succeeds)
    {
        static const SCHEMA_STRUCT_TYPE_HANDLE TEST_CAR_BEHIND_VAN_HANDLE = (SCHEMA_STRUCT_TYPE_HANDLE)0x7001;

        ///arrange
        STRICT_EXPECTED_CALL(Schema_GetSchemaByNamespace("TestSchema"));
        STRICT_EXPECTED_CALL(Schema_Create("TestSchema"));
        STRICT_EXPECTED_CALL(Schema_CreateStructType(TEST_SCHEMA_HANDLE, "theCarIsBehindTheVan"))
            .SetReturn(TEST_CAR_BEHIND_VAN_HANDLE);
        STRICT_EXPECTED_CALL(Schema_AddStructTypeProperty(TEST_CAR_BEHIND_VAN_HANDLE, "whereIsMyCar", "GeoLocation"));
        STRICT_EXPECTED_CALL(Schema_AddStructTypeProperty(TEST_CAR_BEHIND_VAN_HANDLE, "Alt", "int"));
        STRICT_EXPECTED_CALL(Schema_CreateStructType(TEST_SCHEMA_HANDLE, "GeoLocation"));
        STRICT_EXPECTED_CALL(Schema_AddStructTypeProperty(TEST_STRUCT_TYPE_HANDLE, "Long", "double"));
        STRICT_EXPECTED_CALL(Schema_AddStructTypeProperty(TEST_STRUCT_TYPE_HANDLE, "Lat", "double"));
        STRICT_EXPECTED_CALL(Schema_CreateModelType(TEST_SCHEMA_HANDLE, "TruckType"))
            .SetReturn(TEST_TRUCKTYPE_MODEL_HANDLE);
        STRICT_EXPECTED_CALL(Schema_CreateModelType(TEST_SCHEMA_HANDLE, "SimpleDevice"));
        STRICT_EXPECTED_CALL(Schema_GetModelByName(TEST_SCHEMA_HANDLE, "TruckType")).SetReturn(TEST_TRUCKTYPE_MODEL_HANDLE);
        STRICT_EXPECTED_CALL(Schema_CreateModelAction(TEST_TRUCKTYPE_MODEL_HANDLE, "reset"))
            .SetReturn(RESET_ACTION_HANDLE);
        
        STRICT_EXPECTED_CALL(Schema_CreateModelAction(TEST_TRUCKTYPE_MODEL_HANDLE, "setSpeed"))
            .SetReturn(SETSPEED_ACTION_HANDLE);
        STRICT_EXPECTED_CALL(Schema_AddModelActionArgument(SETSPEED_ACTION_HANDLE, "theSpeed", "double"));
        STRICT_EXPECTED_CALL(Schema_GetModelByName(TEST_SCHEMA_HANDLE, "SimpleDevice")).SetReturn(TEST_MODEL_HANDLE);
        STRICT_EXPECTED_CALL(Schema_GetModelByName(TEST_SCHEMA_HANDLE, "int")).SetReturn((SCHEMA_MODEL_TYPE_HANDLE)NULL);
        STRICT_EXPECTED_CALL(Schema_AddModelProperty(TEST_MODEL_HANDLE, "this_is_int", "int"));
        STRICT_EXPECTED_CALL(Schema_GetModelByName(TEST_SCHEMA_HANDLE, "double")).SetReturn((SCHEMA_MODEL_TYPE_HANDLE)NULL);
        STRICT_EXPECTED_CALL(Schema_AddModelProperty(TEST_MODEL_HANDLE, "this_is_double", "double"));

        ///act
        SCHEMA_HANDLE result = CodeFirst_RegisterSchema("TestSchema", &testReflectedData);

        ///assert
        
        ASSERT_ARE_EQUAL(void_ptr, TEST_SCHEMA_HANDLE, result);
    }

    /* Tests_SRS_CODEFIRST_99_002:[ CodeFirst_RegisterSchema shall create the schema information and give it to the Schema module for one schema, identified by the metadata argument. On success, it shall return a handle to the model.] */
    TEST_FUNCTION(CodeFirst_RegisterSchema_With_Model_In_Model_succeeds)
    {
        static const SCHEMA_STRUCT_TYPE_HANDLE TEST_CAR_BEHIND_VAN_HANDLE = (SCHEMA_STRUCT_TYPE_HANDLE)0x7001;

        ///arrange
        STRICT_EXPECTED_CALL(Schema_GetSchemaByNamespace("TestSchema"));
        STRICT_EXPECTED_CALL(Schema_Create("TestSchema"));
        STRICT_EXPECTED_CALL(Schema_CreateModelType(TEST_SCHEMA_HANDLE, "OuterType"))
            .SetReturn(TEST_OUTERTYPE_MODEL_HANDLE);
        STRICT_EXPECTED_CALL(Schema_CreateModelType(TEST_SCHEMA_HANDLE, "InnerType"))
            .SetReturn(TEST_INNERTYPE_MODEL_HANDLE);
        STRICT_EXPECTED_CALL(Schema_GetModelByName(TEST_SCHEMA_HANDLE, "OuterType"))
            .SetReturn(TEST_OUTERTYPE_MODEL_HANDLE);
        STRICT_EXPECTED_CALL(Schema_GetModelByName(TEST_SCHEMA_HANDLE, "InnerType"))
            .SetReturn(TEST_INNERTYPE_MODEL_HANDLE);
        STRICT_EXPECTED_CALL(Schema_AddModelModel(TEST_OUTERTYPE_MODEL_HANDLE, "Inner", TEST_INNERTYPE_MODEL_HANDLE));
        STRICT_EXPECTED_CALL(Schema_CreateModelAction(TEST_OUTERTYPE_MODEL_HANDLE, "reset"));
        STRICT_EXPECTED_CALL(Schema_GetModelByName(TEST_SCHEMA_HANDLE, "InnerType"))
            .SetReturn(TEST_INNERTYPE_MODEL_HANDLE);
        STRICT_EXPECTED_CALL(Schema_GetModelByName(TEST_SCHEMA_HANDLE, "double"));
        STRICT_EXPECTED_CALL(Schema_AddModelProperty(TEST_INNERTYPE_MODEL_HANDLE, "this_is_double", "double"));
        STRICT_EXPECTED_CALL(Schema_GetModelByName(TEST_SCHEMA_HANDLE, "int"));
        STRICT_EXPECTED_CALL(Schema_AddModelProperty(TEST_INNERTYPE_MODEL_HANDLE, "this_is_int", "int"));
        STRICT_EXPECTED_CALL(Schema_CreateModelAction(TEST_INNERTYPE_MODEL_HANDLE, "reset"));
        
        ///act
        SCHEMA_HANDLE result = CodeFirst_RegisterSchema("TestSchema", &testModelInModelReflected);

        ///assert
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());
        ASSERT_ARE_EQUAL(void_ptr, TEST_SCHEMA_HANDLE, result);
    }

    /* Tests_SRS_CODEFIRST_99_076:[If any Schema APIs fail, CodeFirst_RegisterSchema shall return NULL.] */
    TEST_FUNCTION(When_Schema_Create_Fails_Then_CodeFirst_RegisterSchema_Fails)
    {

        ///arrange
        STRICT_EXPECTED_CALL(Schema_GetSchemaByNamespace("TestSchema"));
        STRICT_EXPECTED_CALL(Schema_Create("TestSchema"))
            .SetReturn((SCHEMA_HANDLE)NULL);

        ///act
        SCHEMA_HANDLE result = CodeFirst_RegisterSchema("TestSchema", &testReflectedData);

        ///assert
        ASSERT_IS_NULL(result);
    }

    /* Tests_SRS_CODEFIRST_99_076:[If any Schema APIs fail, CodeFirst_RegisterSchema shall return NULL.] */
    TEST_FUNCTION(When_Schema_CreateModelType_Fails_Then_CodeFirst_RegisterSchema_Fails)
    {
        ///arrange
        STRICT_EXPECTED_CALL(Schema_Create("TestSchema"));
        STRICT_EXPECTED_CALL(Schema_CreateModelType(TEST_SCHEMA_HANDLE, TEST_DEFAULT_MODEL_NAME))
            .SetReturn((SCHEMA_MODEL_TYPE_HANDLE)NULL);
        STRICT_EXPECTED_CALL(Schema_Destroy(TEST_SCHEMA_HANDLE));

        ///act
        SCHEMA_HANDLE result = CodeFirst_RegisterSchema("TestSchema", &testReflectedData);

        ///assert
        ASSERT_IS_NULL(result);
    }

    /* Tests_SRS_CODEFIRST_99_076:[If any Schema APIs fail, CodeFirst_RegisterSchema shall return NULL.] */
    TEST_FUNCTION(When_Schema_AddModelProperty_Fails_Then_CodeFirst_RegisterSchema_Fails)
    {
        ///arrange
        STRICT_EXPECTED_CALL(Schema_GetModelByName(TEST_SCHEMA_HANDLE, "TruckType")).SetReturn(TEST_MODEL_HANDLE);
        STRICT_EXPECTED_CALL(Schema_GetModelByName(TEST_SCHEMA_HANDLE, "SimpleDevice")).SetReturn(TEST_MODEL_HANDLE);
        STRICT_EXPECTED_CALL(Schema_AddModelProperty(TEST_MODEL_HANDLE, "this_is_int", "int"))
            .SetReturn(SCHEMA_ERROR);
        STRICT_EXPECTED_CALL(Schema_Destroy(TEST_SCHEMA_HANDLE));

        ///act
        SCHEMA_HANDLE result = CodeFirst_RegisterSchema("TestSchema", &testReflectedData);

        ///assert
        ASSERT_IS_NULL(result);
    }

    /* Tests_SRS_CODEFIRST_99_076:[If any Schema APIs fail, CodeFirst_RegisterSchema shall return NULL.] */
    TEST_FUNCTION(When_Schema_CreateModelAction_Fails_Then_CodeFirst_RegisterSchema_Fails)
    {
        ///arrange
        STRICT_EXPECTED_CALL(Schema_GetModelByName(TEST_SCHEMA_HANDLE, "TruckType")).SetReturn(TEST_MODEL_HANDLE);
        STRICT_EXPECTED_CALL(Schema_CreateModelAction(TEST_MODEL_HANDLE, "setSpeed"))
            .SetReturn((SCHEMA_ACTION_HANDLE)NULL);
        STRICT_EXPECTED_CALL(Schema_Destroy(TEST_SCHEMA_HANDLE));

        ///act
        SCHEMA_HANDLE result = CodeFirst_RegisterSchema("TestSchema", &testReflectedData);

        ///assert
        ASSERT_IS_NULL(result);
    }

    /* Tests_SRS_CODEFIRST_99_076:[If any Schema APIs fail, CodeFirst_RegisterSchema shall return NULL.] */
    TEST_FUNCTION(When_Schema_AddModelActionArgument_Fails_Then_CodeFirst_RegisterSchema_Fails)
    {
        ///arrange
        STRICT_EXPECTED_CALL(Schema_GetModelByName(TEST_SCHEMA_HANDLE, "TruckType")).SetReturn(TEST_MODEL_HANDLE);
        STRICT_EXPECTED_CALL(Schema_CreateModelAction(TEST_MODEL_HANDLE, "setSpeed"))
            .SetReturn(SETSPEED_ACTION_HANDLE);
        STRICT_EXPECTED_CALL(Schema_AddModelActionArgument(SETSPEED_ACTION_HANDLE, "theSpeed", "double"))
            .SetReturn(SCHEMA_ERROR);
        STRICT_EXPECTED_CALL(Schema_Destroy(TEST_SCHEMA_HANDLE));

        ///act
        SCHEMA_HANDLE result = CodeFirst_RegisterSchema("TestSchema", &testReflectedData);

        ///assert
        ASSERT_IS_NULL(result);
    }

    /* Tests_SRS_CODEFIRST_99_076:[If any Schema APIs fail, CodeFirst_RegisterSchema shall return NULL.] */
    TEST_FUNCTION(When_Schema_CreateStructType_Fails_Then_CodeFirst_RegisterSchema_Fails)
    {
        ///arrange
        STRICT_EXPECTED_CALL(Schema_Create("TestSchema"));
        STRICT_EXPECTED_CALL(Schema_CreateStructType(TEST_SCHEMA_HANDLE, "GeoLocation"))
            .SetReturn((SCHEMA_STRUCT_TYPE_HANDLE)NULL);
        STRICT_EXPECTED_CALL(Schema_Destroy(TEST_SCHEMA_HANDLE));

        ///act
        SCHEMA_HANDLE result = CodeFirst_RegisterSchema("TestSchema", &testReflectedData);

        ///assert
        ASSERT_IS_NULL(result);
    }

    /* Tests_SRS_CODEFIRST_99_076:[If any Schema APIs fail, CodeFirst_RegisterSchema shall return NULL.] */
    TEST_FUNCTION(When_Schema_AddStructTypeProperty_Fails_Then_CodeFirst_RegisterSchema_Fails)
    {
        ///arrange
        STRICT_EXPECTED_CALL(Schema_Create("TestSchema"));
        STRICT_EXPECTED_CALL(Schema_AddStructTypeProperty(TEST_STRUCT_TYPE_HANDLE, "Lat", "double"))
            .SetReturn(SCHEMA_ERROR);
        STRICT_EXPECTED_CALL(Schema_Destroy(TEST_SCHEMA_HANDLE));

        ///act
        SCHEMA_HANDLE result = CodeFirst_RegisterSchema("TestSchema", &testReflectedData);

        ///assert
        ASSERT_IS_NULL(result);
    }

    /* Tests_SRS_CODEFIRST_99_076:[If any Schema APIs fail, CodeFirst_RegisterSchema shall return NULL.] */
    TEST_FUNCTION(When_Schema_GetModelByName_Returns_NULL_RegisterSchema_Fails)
    {
        ///arrange
        STRICT_EXPECTED_CALL(Schema_GetModelByName(TEST_SCHEMA_HANDLE, "TruckType"))
            .SetReturn((SCHEMA_MODEL_TYPE_HANDLE)NULL);
        STRICT_EXPECTED_CALL(Schema_Destroy(TEST_SCHEMA_HANDLE));

        ///act
        SCHEMA_HANDLE result = CodeFirst_RegisterSchema("TestSchema", &testReflectedData);

        ///assert
        ASSERT_IS_NULL(result);
    }

    /* Tests_SRS_CODEFIRST_99_121:[If the schema has already been registered, CodeFirst_RegisterSchema shall return its handle.] */
    TEST_FUNCTION(When_Schema_Was_Already_Registered_CodeFirst_Returns_Its_Handle)
    {

        ///arrange
        STRICT_EXPECTED_CALL(Schema_GetSchemaByNamespace("TestSchema"))
            .SetReturn((SCHEMA_HANDLE)TEST_SCHEMA_HANDLE);

        ///act
        SCHEMA_HANDLE result = CodeFirst_RegisterSchema("TestSchema", &testReflectedData);

        ///assert
        ASSERT_ARE_EQUAL(void_ptr, TEST_SCHEMA_HANDLE, result);
    }

    /*Tests_SRS_CODEFIRST_02_014: [If parameter device or command is NULL then CodeFirst_ExecuteCommand shall return EXECUTE_COMMAND_ERROR.] */
    TEST_FUNCTION(CodeFirst_ExecuteCommand_With_NULL_device_fails)
    {
        ///arrange

        ///act
        EXECUTE_COMMAND_RESULT result = CodeFirst_ExecuteCommand(NULL, TEST_COMMAND);

        ///assert
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);

        ///cleanup
    }

    /*Tests_SRS_CODEFIRST_02_014: [If parameter device or command is NULL then CodeFirst_ExecuteCommand shall return EXECUTE_COMMAND_ERROR.] */
    TEST_FUNCTION(CodeFirst_ExecuteCommand_With_NULL_command_fails)
    {
        ///arrange
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        ///act
        EXECUTE_COMMAND_RESULT result = CodeFirst_ExecuteCommand(device, NULL);

        ///assert
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        ///cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_CODEFIRST_02_015: [CodeFirst_ExecuteCommand shall find the device.]*/
    /*Tests_SRS_CODEFIRST_02_016: [If finding the device fails, then CodeFirst_ExecuteCommand shall return EXECUTE_COMMAND_ERROR.] */
    TEST_FUNCTION(CodeFirst_ExecuteCommand_fails_when_it_does_not_find_the_device)
    {
        ///arrange
        umock_c_reset_all_calls();

        ///act
        EXECUTE_COMMAND_RESULT result = CodeFirst_ExecuteCommand((unsigned char*)NULL +1, TEST_COMMAND);

        ///assert
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        ///cleanup
    }

    /*Tests_SRS_CODEFIRST_02_017: [Otherwise CodeFirst_ExecuteCommand shall call Device_ExecuteCommand and return what Device_ExecuteCommand is returning.] */
    TEST_FUNCTION(CodeFirst_ExecuteCommand_calls_Device_ExecuteCommand)
    {
        ///arrange
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_ExecuteCommand(IGNORED_PTR_ARG, TEST_COMMAND))
            .IgnoreArgument(1);

        ///act
        EXECUTE_COMMAND_RESULT result = CodeFirst_ExecuteCommand(device, TEST_COMMAND);

        ///assert
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_SUCCESS, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        ///cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_CODEFIRST_02_017: [Otherwise CodeFirst_ExecuteCommand shall call Device_ExecuteCommand and return what Device_ExecuteCommand is returning.] */
    TEST_FUNCTION(CodeFirst_ExecuteCommand_calls_Device_ExecuteCommand_can_returns_EXECUTE_COMMAND_FAILED)
    {
        ///arrange
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_ExecuteCommand(IGNORED_PTR_ARG, TEST_COMMAND))
            .IgnoreArgument(1)
            .SetReturn(EXECUTE_COMMAND_FAILED);

        ///act
        EXECUTE_COMMAND_RESULT result = CodeFirst_ExecuteCommand(device, TEST_COMMAND);

        ///assert
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_FAILED, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        ///cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_CODEFIRST_02_017: [Otherwise CodeFirst_ExecuteCommand shall call Device_ExecuteCommand and return what Device_ExecuteCommand is returning.] */
    TEST_FUNCTION(CodeFirst_ExecuteCommand_calls_Device_ExecuteCommand_can_returns_EXECUTE_COMMAND_ERROR)
    {
        ///arrange
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_ExecuteCommand(IGNORED_PTR_ARG, TEST_COMMAND))
            .IgnoreArgument(1)
            .SetReturn(EXECUTE_COMMAND_ERROR);

        ///act
        EXECUTE_COMMAND_RESULT result = CodeFirst_ExecuteCommand(device, TEST_COMMAND);

        ///assert
        ASSERT_ARE_EQUAL(EXECUTE_COMMAND_RESULT, EXECUTE_COMMAND_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        ///cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_CODEFIRST_02_018: [ If parameter destination, destinationSize or any of the values passed through va_args is NULL then CodeFirst_SendAsyncReported shall fail and return CODEFIRST_INVALID_ARG. ]*/
    TEST_FUNCTION(CodeFirst_SendAsyncReported_with_NULL_destination_fails)
    {
        ///arrange
        size_t destinationSize = 10;
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        ///act
        CODEFIRST_RESULT result = CodeFirst_SendAsyncReported(NULL, &destinationSize, 1, (void*)1);

        ///assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_INVALID_ARG, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        ///cleanup
        CodeFirst_DestroyDevice(device);
    }

    /*Tests_SRS_CODEFIRST_02_018: [ If parameter destination, destinationSize or any of the values passed through va_args is NULL then CodeFirst_SendAsyncReported shall fail and return CODEFIRST_INVALID_ARG. ]*/
    TEST_FUNCTION(CodeFirst_SendAsyncReported_with_NULL_destinationSize_fails)
    {
        ///arrange
        unsigned char *destination = (unsigned char*)my_gballoc_malloc(10);
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        ///act
        CODEFIRST_RESULT result = CodeFirst_SendAsyncReported(&destination, NULL, 1, (void*)1);

        ///assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_INVALID_ARG, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        ///cleanup
        CodeFirst_DestroyDevice(device);
        my_gballoc_free(destination);
    }

    /*Tests_SRS_CODEFIRST_02_018: [ If parameter destination, destinationSize or any of the values passed through va_args is NULL then CodeFirst_SendAsyncReported shall fail and return CODEFIRST_INVALID_ARG. ]*/
    TEST_FUNCTION(CodeFirst_SendAsyncReported_with_zero_reportedProperties_fails)
    {
        ///arrange
        unsigned char *destination = (unsigned char*)my_gballoc_malloc(10);
        size_t destinationSize = 10;
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        ///act
        CODEFIRST_RESULT result = CodeFirst_SendAsyncReported(&destination, &destinationSize, 0);

        ///assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_INVALID_ARG, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        ///cleanup
        CodeFirst_DestroyDevice(device);
        my_gballoc_free(destination);
    }

    /*Tests_SRS_CODEFIRST_02_018: [ If parameter destination, destinationSize or any of the values passed through va_args is NULL then CodeFirst_SendAsyncReported shall fail and return CODEFIRST_INVALID_ARG. ]*/
    TEST_FUNCTION(CodeFirst_SendAsyncReported_with_one_NULL_reportedProperties_fails)
    {
        ///arrange
        unsigned char *destination = (unsigned char*)my_gballoc_malloc(10);
        size_t destinationSize = 10;
        void* device = CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        umock_c_reset_all_calls();

        ///act
        CODEFIRST_RESULT result = CodeFirst_SendAsyncReported(&destination, &destinationSize, 1, NULL);

        ///assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_INVALID_ARG, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        ///cleanup
        CodeFirst_DestroyDevice(device);
        my_gballoc_free(destination);
    }

    /*Tests_SRS_CODEFIRST_02_019: [ If values passed through va_args do not belong to the same device then CodeFirst_SendAsyncReported shall fail and return CODEFIRST_VALUES_FROM_DIFFERENT_DEVICES_ERROR. ]*/
    TEST_FUNCTION(CodeFirst_SendAsyncReported_with_reportedProperties_from_different_devices_fails)
    {
        ///arrange
        size_t destinationSize = 1000;
        unsigned char *destination = (unsigned char*)my_gballoc_malloc(destinationSize);
        
        TruckType* device1 = (TruckType*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        TruckType* device2 = (TruckType*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        device1->reported_this_is_int = 1;
        device2->reported_this_is_int = 2;
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(IGNORED_PTR_ARG))
            .IgnoreArgument_deviceHandle();
        STRICT_EXPECTED_CALL(STRING_new());
        STRICT_EXPECTED_CALL(Schema_GetModelName(IGNORED_PTR_ARG))
            .IgnoreArgument_modelTypeHandle()
            .SetReturn("TruckType");
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, "reported_this_is_int"))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_SINT32(IGNORED_PTR_ARG, IGNORED_NUM_ARG))
            .IgnoreArgument_agentData()
            .IgnoreArgument_v();
        STRICT_EXPECTED_CALL(STRING_c_str(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "reported_this_is_int", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument_data();
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG))
            .IgnoreArgument_agentData();
        STRICT_EXPECTED_CALL(Device_CancelTransaction(IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle();

        ///act
        CODEFIRST_RESULT result = CodeFirst_SendAsyncReported(&destination, &destinationSize, 2, &device1->reported_this_is_int, &device2->reported_this_is_int);

        ///assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_VALUES_FROM_DIFFERENT_DEVICES_ERROR, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        ///cleanup
        CodeFirst_DestroyDevice(device2);
        CodeFirst_DestroyDevice(device1);
        my_gballoc_free(destination);
    }

    /*Tests_SRS_CODEFIRST_02_020: [ If values passed through va_args are not all of type REFLECTED_REPORTED_PROPERTY then CodeFirst_SendAsyncReported shall fail and return CODEFIRST_INVALID_ARG. ]*/
    TEST_FUNCTION(CodeFirst_SendAsyncReported_WITH_DATA_fails)
    {
        ///arrange
        size_t destinationSize = 1000;
        unsigned char *destination = (unsigned char*)my_gballoc_malloc(destinationSize);
        TruckType* device = (TruckType*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        device->reported_this_is_int = 3;
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(IGNORED_PTR_ARG))
            .IgnoreArgument_deviceHandle();
        STRICT_EXPECTED_CALL(STRING_new());
        STRICT_EXPECTED_CALL(Schema_GetModelName(IGNORED_PTR_ARG))
            .IgnoreArgument_modelTypeHandle();
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_CancelTransaction(IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle();

        ///act
        CODEFIRST_RESULT result = CodeFirst_SendAsyncReported(&destination, &destinationSize, 1, &device->this_is_int); /*note: this_is_int is defined with WITH_DATA*/

        ///assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_INVALID_ARG, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        ///cleanup
        CodeFirst_DestroyDevice(device);
        my_gballoc_free(destination);
    }

    /*Tests_SRS_CODEFIRST_02_020: [ If values passed through va_args are not all of type REFLECTED_REPORTED_PROPERTY then CodeFirst_SendAsyncReported shall fail and return CODEFIRST_INVALID_ARG. ]*/
    TEST_FUNCTION(CodeFirst_SendAsyncReported_with_reportedProperty_outside_any_device_fails)
    {
        ///arrange
        size_t destinationSize = 1000;
        unsigned char *destination = (unsigned char*)my_gballoc_malloc(destinationSize);
        TruckType* device = (TruckType*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &DummyDataProvider_allReflected, sizeof(TruckType), false);
        device->reported_this_is_int = 3;
        umock_c_reset_all_calls();

        ///act
        CODEFIRST_RESULT result = CodeFirst_SendAsyncReported(&destination, &destinationSize, 1, &(device+1)->reported_this_is_int); /*note: this is out of the memory of the device*/

        ///assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_INVALID_ARG, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        ///cleanup
        CodeFirst_DestroyDevice(device);
        my_gballoc_free(destination);
    }

    static void CodeFirst_SendReportedAsync_all_inert_path(void)
    {
        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));

        STRICT_EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_DOUBLE(IGNORED_PTR_ARG, 5.5))
            .IgnoreArgument_agentData();
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "reported_this_is_double", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument_data();
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));

        STRICT_EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_SINT32(IGNORED_PTR_ARG, -5))
            .IgnoreArgument_agentData();
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "reported_this_is_int", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument_data();
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));

        STRICT_EXPECTED_CALL(Device_EndTransaction(IGNORED_PTR_ARG, IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(2)
            .IgnoreArgument(3);
    }

    /*Tests_SRS_CODEFIRST_02_021: [ If the value passed through va_args is a complete model instance, then CodeFirst_SendAsyncReported shall send all the reported properties of that device. ]*/
    /*Tests_SRS_CODEFIRST_02_022: [ CodeFirst_SendAsyncReported shall start a transaction by calling Device_StartTransaction. ]*/
    /*Tests_SRS_CODEFIRST_02_023: [ CodeFirst_SendAsyncReported shall convert all REPORTED_PROPERTY model components to AGENT_DATA_TYPE. ]*/
    /*Tests_SRS_CODEFIRST_02_024: [ CodeFirst_SendAsyncReported shall call Device_PublishTransacted for every AGENT_DATA_TYPE converted from REPORTED_PROPERTY. ]*/
    /*Tests_SRS_CODEFIRST_02_026: [ CodeFirst_SendAsyncReported shall call Device_EndTransaction to end the transaction. ]*/
    /*Tests_SRS_CODEFIRST_02_028: [ CodeFirst_SendAsyncReported shall return CODEFIRST_OK when it succeeds. ]*/
    TEST_FUNCTION(CodeFirst_SendReportedAsync_all_happy_path)
    {
        /// arrange
        size_t destinationSize = 1000;
        unsigned char *destination = (unsigned char*)my_gballoc_malloc(destinationSize);
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        umock_c_reset_all_calls();

        device->reported_this_is_double = 5.5; /*the only reported properties*/
        device->reported_this_is_int = -5; /*the only reported properties*/

        CodeFirst_SendReportedAsync_all_inert_path();

        /// act
        CODEFIRST_RESULT result = CodeFirst_SendAsyncReported(&destination, &destinationSize, 1, device);

        /// assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_OK, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        /// cleanup
        CodeFirst_DestroyDevice(device);
        my_gballoc_free(destination);
    }

    /*Tests_SRS_CODEFIRST_02_027: [ If any error occurs, CodeFirst_SendAsyncReported shall fail, cancelling the transaction by calling Device_CancelTransaction, returning CODEFIRST_DEVICE_FAILED if the error pertains to usage of Device APIs or returning CODEFIRST_ERROR in all other cases ]*/
    TEST_FUNCTION(CodeFirst_SendReportedAsync_all_unahppy_path)
    {
        ///arrange
        size_t destinationSize = 1000;
        unsigned char *destination = (unsigned char*)my_gballoc_malloc(destinationSize);
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        (void)umock_c_negative_tests_init();
        umock_c_reset_all_calls();

        device->reported_this_is_double = 5.5; /*the only reported properties*/
        device->reported_this_is_int = -5; /*the only reported properties*/

        CodeFirst_SendReportedAsync_all_inert_path();

        umock_c_negative_tests_snapshot();

        size_t calls_that_cannot_fail[] =
        {
            1,/*Schema_GetModelName*/
            4,/*Destroy_AGENT_DATA_TYPE*/
            7,/*Destroy_AGENT_DATA_TYPE*/
        };

        for (size_t i = 0; i < umock_c_negative_tests_call_count(); i++)
        {
            size_t j;
            for (j = 0;j < sizeof(calls_that_cannot_fail) / sizeof(calls_that_cannot_fail[0]);j++) /*not running the tests that cannot fail*/
            {
                if (calls_that_cannot_fail[j] == i)
                    break;
            }

            if (j == sizeof(calls_that_cannot_fail) / sizeof(calls_that_cannot_fail[0]))
            {
                umock_c_negative_tests_reset();
                umock_c_negative_tests_fail_call(i);
                char temp_str[128];
                sprintf(temp_str, "On failed call %zu", i);
                ///act
                CODEFIRST_RESULT result = CodeFirst_SendAsyncReported(&destination, &destinationSize, 1, device);

                ///assert
                ASSERT_ARE_NOT_EQUAL_WITH_MSG(CODEFIRST_RESULT, CODEFIRST_OK, result, temp_str);
            }
        }

        ///cleanup
        CodeFirst_DestroyDevice(device);
        umock_c_negative_tests_deinit();
        my_gballoc_free(destination);
    }

    static void CodeFirst_SendReportedAsync_one_inert_path(void)
    {

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(STRING_new());
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_MODEL_HANDLE));
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, "reported_this_is_double"))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_DOUBLE(IGNORED_PTR_ARG, 5.5))
            .IgnoreArgument_agentData();
        STRICT_EXPECTED_CALL(STRING_c_str(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "reported_this_is_double", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument_data();
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG))
            .IgnoreArgument_agentData();
        STRICT_EXPECTED_CALL(Device_EndTransaction(IGNORED_PTR_ARG, IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(2)
            .IgnoreArgument(3);
    }

    /*Tests_SRS_CODEFIRST_02_022: [ CodeFirst_SendAsyncReported shall start a transaction by calling Device_StartTransaction. ]*/
    /*Tests_SRS_CODEFIRST_02_023: [ CodeFirst_SendAsyncReported shall convert all REPORTED_PROPERTY model components to AGENT_DATA_TYPE. ]*/
    /*Tests_SRS_CODEFIRST_02_024: [ CodeFirst_SendAsyncReported shall call Device_PublishTransacted for every AGENT_DATA_TYPE converted from REPORTED_PROPERTY. ]*/
    /*Tests_SRS_CODEFIRST_02_025: [ CodeFirst_SendAsyncReported shall compute for every AGENT_DATA_TYPE the valuePath. ]*/
    /*Tests_SRS_CODEFIRST_02_026: [ CodeFirst_SendAsyncReported shall call Device_EndTransaction to end the transaction. ]*/
    TEST_FUNCTION(CodeFirst_SendReportedAsync_one_reportedProperty_happy_path)
    {
        /// arrange
        size_t destinationSize = 1000;
        unsigned char *destination = (unsigned char*)my_gballoc_malloc(destinationSize);
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        umock_c_reset_all_calls();

        device->reported_this_is_double = 5.5; /*the only reported properties*/
        device->reported_this_is_int = -5; /*the only reported properties*/

        CodeFirst_SendReportedAsync_one_inert_path();

        /// act
        CODEFIRST_RESULT result = CodeFirst_SendAsyncReported(&destination, &destinationSize, 1, &(device->reported_this_is_double));

        /// assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_OK, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        /// cleanup
        CodeFirst_DestroyDevice(device);
        my_gballoc_free(destination);
    }

    /*Tests_SRS_CODEFIRST_02_027: [ If any error occurs, CodeFirst_SendAsyncReported shall fail, cancelling the transaction by calling Device_CancelTransaction, returning CODEFIRST_DEVICE_FAILED if the error pertains to usage of Device APIs or returning CODEFIRST_ERROR in all other cases ]*/
    TEST_FUNCTION(CodeFirst_SendReportedAsync_one_reportedProperty_unhappy_path)
    {
        /// arrange
        size_t destinationSize = 1000;
        unsigned char *destination = (unsigned char*)my_gballoc_malloc(destinationSize);
        SimpleDevice* device = (SimpleDevice*)CodeFirst_CreateDevice(TEST_MODEL_HANDLE, &testReflectedData, sizeof(SimpleDevice), false);
        (void)umock_c_negative_tests_init();
        umock_c_reset_all_calls();

        device->reported_this_is_double = 5.5; /*the only reported properties*/
        device->reported_this_is_int = -5; /*the only reported properties*/

        CodeFirst_SendReportedAsync_one_inert_path();
        umock_c_negative_tests_snapshot();

        size_t calls_that_cannot_fail[] =
        {
            2,/*Schema_GetModelName*/
            5,/*STRING_c_str*/
            7,/*STRING_delete*/
            8,/*Destroy_AGENT_DATA_TYPE*/
        };

        for (size_t i = 0; i < umock_c_negative_tests_call_count(); i++)
        {
            size_t j;
            for (j = 0;j < sizeof(calls_that_cannot_fail) / sizeof(calls_that_cannot_fail[0]);j++) /*not running the tests that cannot fail*/
            {
                if (calls_that_cannot_fail[j] == i)
                    break;
            }

            if (j == sizeof(calls_that_cannot_fail) / sizeof(calls_that_cannot_fail[0]))
            {
                umock_c_negative_tests_reset();
                umock_c_negative_tests_fail_call(i);
                char temp_str[128];
                sprintf(temp_str, "On failed call %zu", i);

                ///act
                CODEFIRST_RESULT result = CodeFirst_SendAsyncReported(&destination, &destinationSize, 1, &(device->reported_this_is_double));

                ///assert
                ASSERT_ARE_NOT_EQUAL_WITH_MSG(CODEFIRST_RESULT, CODEFIRST_OK, result, temp_str);
            }
        }

        ///cleanup
        CodeFirst_DestroyDevice(device);
        umock_c_negative_tests_deinit();
        my_gballoc_free(destination);
    }

    TEST_FUNCTION(CodeFirst_SendAsyncReported_Can_Send_The_Last_reportedProperty_From_A_Child_Model)
    {
        /// arrange
        size_t destinationSize = 1000;
        unsigned char *destination = (unsigned char*)my_gballoc_malloc(destinationSize);
        OuterType* device = (OuterType*)CodeFirst_CreateDevice(TEST_OUTERTYPE_MODEL_HANDLE, &testModelInModelReflected, sizeof(OuterType), false);
        umock_c_reset_all_calls();

        STRICT_EXPECTED_CALL(Device_StartTransaction(TEST_DEVICE_HANDLE));
        STRICT_EXPECTED_CALL(STRING_new());
        STRICT_EXPECTED_CALL(Schema_GetModelName(TEST_OUTERTYPE_MODEL_HANDLE)).SetReturn("OuterType");
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        STRICT_EXPECTED_CALL(STRING_concat(IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_handle()
            .IgnoreArgument_s2();
        EXPECTED_CALL(Create_AGENT_DATA_TYPE_from_SINT32(IGNORED_PTR_ARG, (int32_t)(IGNORED_NUM_ARG)));
        STRICT_EXPECTED_CALL(STRING_c_str(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        STRICT_EXPECTED_CALL(Device_PublishTransacted(IGNORED_PTR_ARG, "Inner/this_is_int", IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(3);
        STRICT_EXPECTED_CALL(STRING_delete(IGNORED_PTR_ARG))
            .IgnoreArgument_handle();
        EXPECTED_CALL(Destroy_AGENT_DATA_TYPE(IGNORED_PTR_ARG));
        STRICT_EXPECTED_CALL(Device_EndTransaction(IGNORED_PTR_ARG, IGNORED_PTR_ARG, IGNORED_PTR_ARG))
            .IgnoreArgument_transactionHandle()
            .IgnoreArgument(2)
            .IgnoreArgument(3);
        device->Inner.this_is_int = 1;

        // act
        CODEFIRST_RESULT result = CodeFirst_SendAsync(&destination, &destinationSize, 1, &device->Inner.this_is_int);

        // assert
        ASSERT_ARE_EQUAL(CODEFIRST_RESULT, CODEFIRST_OK, result);
        ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());

        // cleanup
        CodeFirst_DestroyDevice(device);
        my_gballoc_free(destination);
    }


END_TEST_SUITE(CodeFirst_ut_Dummy_Data_Provider);