# Definition of TaskService.V1_1_2 and functions<br><br>

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


## Actions
    typedef struct _RedfishTaskService_V1_1_2_Actions_CS {
        RedfishTaskService_V1_1_2_OemActions_CS *Oem;
    } RedfishTaskService_V1_1_2_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Oem**|RedfishTaskService_V1_1_2_OemActions_CS| Structure points to **Oem** property.| No| No


## OemActions
    typedef struct _RedfishTaskService_V1_1_2_OemActions_CS {
        RedfishCS_Link Prop;
    } RedfishTaskService_V1_1_2_OemActions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## TaskService
    typedef struct _RedfishTaskService_V1_1_2_TaskService_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_etag;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishTaskService_V1_1_2_Actions_CS *Actions;
        RedfishCS_char *CompletedTaskOverWritePolicy;
        RedfishCS_char *DateTime;
        RedfishCS_char *Description;
        RedfishCS_char *Id;
        RedfishCS_bool *LifeCycleEventOnTaskStateChange;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_bool *ServiceEnabled;
        RedfishResource_Status_CS *Status;
        RedfishCS_Link Tasks;
    } RedfishTaskService_V1_1_2_TaskService_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_etag**|RedfishCS_char| String pointer to **@odata.etag** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| Yes| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| Yes| No
|**Actions**|RedfishTaskService_V1_1_2_Actions_CS| Structure points to **Actions** property.| No| No
|**CompletedTaskOverWritePolicy**|RedfishCS_char| String pointer to **CompletedTaskOverWritePolicy** property.| No| Yes
|**DateTime**|RedfishCS_char| String pointer to **DateTime** property.| No| Yes
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**LifeCycleEventOnTaskStateChange**|RedfishCS_bool| Boolean pointer to **LifeCycleEventOnTaskStateChange** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**ServiceEnabled**|RedfishCS_bool| Boolean pointer to **ServiceEnabled** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**Tasks**|RedfishCS_Link| Structure link list to **Tasks** property.| No| Yes
## Redfish TaskService V1_1_2 to C Structure Function
    RedfishCS_status
    Json_TaskService_V1_1_2_To_CS (RedfishCS_char *JsonRawText, RedfishTaskService_V1_1_2_TaskService_CS **ReturnedCS);

## C Structure to Redfish TaskService V1_1_2 JSON Function
    RedfishCS_status
    CS_To_TaskService_V1_1_2_JSON (RedfishTaskService_V1_1_2_TaskService_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish TaskService V1_1_2 C Structure Function
    RedfishCS_status
    DestroyTaskService_V1_1_2_CS (RedfishTaskService_V1_1_2_TaskService_CS *CSPtr);

