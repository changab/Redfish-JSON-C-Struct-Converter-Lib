# Definition of LogService.V1_0_4 and functions<br><br>

## ClearLog
    typedef struct _RedfishLogService_V1_0_4_ClearLog_CS {
        RedfishCS_char *target;
        RedfishCS_char *title;
    } RedfishLogService_V1_0_4_ClearLog_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**target**|RedfishCS_char| String pointer to **target** property.| No| No
|**title**|RedfishCS_char| String pointer to **title** property.| No| No


## LogService_Actions
    typedef struct _RedfishLogService_V1_0_4_LogService_Actions_CS {
        RedfishLogService_V1_0_4_ClearLog_CS *LogService_ClearLog;
        RedfishLogService_V1_0_4_LogService_Actions_Oem_CS *Oem;
    } RedfishLogService_V1_0_4_LogService_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**LogService_ClearLog**|RedfishLogService_V1_0_4_ClearLog_CS| Structure points to **#LogService.ClearLog** property.| No| No
|**Oem**|RedfishLogService_V1_0_4_LogService_Actions_Oem_CS| Structure points to **Oem** property.| No| No


## LogService_Actions_Oem
    typedef struct _RedfishLogService_V1_0_4_LogService_Actions_Oem_CS {
        RedfishCS_Link Prop;
    } RedfishLogService_V1_0_4_LogService_Actions_Oem_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## Oem
    typedef struct _RedfishResource_Oem_CS {
        RedfishCS_Link Prop;
    } RedfishResource_Oem_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## Status
    typedef struct _RedfishResource_Status_CS {
        RedfishCS_char *Health;
        RedfishCS_char *HealthRollup;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *State;
    } RedfishResource_Status_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Health**|RedfishCS_char| String pointer to **Health** property.| No| Yes
|**HealthRollup**|RedfishCS_char| String pointer to **HealthRollup** property.| No| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**State**|RedfishCS_char| String pointer to **State** property.| No| Yes


## LogService
    typedef struct _RedfishLogService_V1_0_4_LogService_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishLogService_V1_0_4_LogService_Actions_CS *Actions;
        RedfishCS_char *DateTime;
        RedfishCS_char *DateTimeLocalOffset;
        RedfishCS_char *Description;
        RedfishCS_Link Entries;
        RedfishCS_char *Id;
        RedfishCS_int64 *MaxNumberOfRecords;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *OverWritePolicy;
        RedfishCS_bool *ServiceEnabled;
        RedfishResource_Status_CS *Status;
    } RedfishLogService_V1_0_4_LogService_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Actions**|RedfishLogService_V1_0_4_LogService_Actions_CS| Structure points to **Actions** property.| No| No
|**DateTime**|RedfishCS_char| String pointer to **DateTime** property.| No| No
|**DateTimeLocalOffset**|RedfishCS_char| String pointer to **DateTimeLocalOffset** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Entries**|RedfishCS_Link| Structure link list to **Entries** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**MaxNumberOfRecords**|RedfishCS_int64| 64-bit long long interger pointer to **MaxNumberOfRecords** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**OverWritePolicy**|RedfishCS_char| String pointer to **OverWritePolicy** property.| No| Yes
|**ServiceEnabled**|RedfishCS_bool| Boolean pointer to **ServiceEnabled** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
## Redfish LogService V1_0_4 to C Structure Function
    RedfishCS_status
    Json_LogService_V1_0_4_To_CS (RedfishCS_char *JsonRawText, RedfishLogService_V1_0_4_LogService_CS **ReturnedCS);

## C Structure to Redfish LogService V1_0_4 JSON Function
    RedfishCS_status
    CS_To_LogService_V1_0_4_JSON (RedfishLogService_V1_0_4_LogService_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish LogService V1_0_4 C Structure Function
    RedfishCS_status
    DestroyLogService_V1_0_4_CS (RedfishLogService_V1_0_4_LogService_CS *CSPtr);

