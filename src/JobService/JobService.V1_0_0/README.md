# Definition of JobService.V1_0_0 and functions<br><br>

## Actions
    typedef struct _RedfishJobService_V1_0_0_Actions_CS {
        RedfishJobService_V1_0_0_OemActions_CS *Oem;
    } RedfishJobService_V1_0_0_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Oem**|RedfishJobService_V1_0_0_OemActions_CS| Structure points to **Oem** property.| No| No


## JobServiceCapabilities
    typedef struct _RedfishJobService_V1_0_0_JobServiceCapabilities_CS {
        RedfishCS_int64 *MaxJobs;
        RedfishCS_int64 *MaxSteps;
        RedfishCS_bool *Scheduling;
    } RedfishJobService_V1_0_0_JobServiceCapabilities_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**MaxJobs**|RedfishCS_int64| 64-bit long long interger pointer to **MaxJobs** property.| No| Yes
|**MaxSteps**|RedfishCS_int64| 64-bit long long interger pointer to **MaxSteps** property.| No| Yes
|**Scheduling**|RedfishCS_bool| Boolean pointer to **Scheduling** property.| No| Yes


## OemActions
    typedef struct _RedfishJobService_V1_0_0_OemActions_CS {
        RedfishCS_Link Prop;
    } RedfishJobService_V1_0_0_OemActions_CS;

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


## JobService
    typedef struct _RedfishJobService_V1_0_0_JobService_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_etag;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishJobService_V1_0_0_Actions_CS *Actions;
        RedfishCS_char *DateTime;
        RedfishCS_char *Description;
        RedfishCS_char *Id;
        RedfishCS_Link Jobs;
        RedfishCS_Link Log;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishJobService_V1_0_0_JobServiceCapabilities_CS *ServiceCapabilities;
        RedfishCS_bool *ServiceEnabled;
        RedfishResource_Status_CS *Status;
    } RedfishJobService_V1_0_0_JobService_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_etag**|RedfishCS_char| String pointer to **@odata.etag** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| Yes| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| Yes| No
|**Actions**|RedfishJobService_V1_0_0_Actions_CS| Structure points to **Actions** property.| No| No
|**DateTime**|RedfishCS_char| String pointer to **DateTime** property.| No| Yes
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**Jobs**|RedfishCS_Link| Structure link list to **Jobs** property.| No| Yes
|**Log**|RedfishCS_Link| Structure link list to **Log** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**ServiceCapabilities**|RedfishJobService_V1_0_0_JobServiceCapabilities_CS| Structure points to **ServiceCapabilities** property.| No| No
|**ServiceEnabled**|RedfishCS_bool| Boolean pointer to **ServiceEnabled** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
## Redfish JobService V1_0_0 to C Structure Function
    RedfishCS_status
    Json_JobService_V1_0_0_To_CS (RedfishCS_char *JsonRawText, RedfishJobService_V1_0_0_JobService_CS **ReturnedCS);

## C Structure to Redfish JobService V1_0_0 JSON Function
    RedfishCS_status
    CS_To_JobService_V1_0_0_JSON (RedfishJobService_V1_0_0_JobService_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish JobService V1_0_0 C Structure Function
    RedfishCS_status
    DestroyJobService_V1_0_0_CS (RedfishJobService_V1_0_0_JobService_CS *CSPtr);

