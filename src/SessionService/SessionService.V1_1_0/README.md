# Definition of SessionService.V1_1_0 and functions<br><br>

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


## SessionService_Actions
    typedef struct _RedfishSessionService_V1_1_0_SessionService_Actions_CS {
        RedfishCS_Link Oem;
    } RedfishSessionService_V1_1_0_SessionService_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Oem**|RedfishCS_Link| Structure link list to **Oem** property.| No| No


## SessionService
    typedef struct _RedfishSessionService_V1_1_0_SessionService_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishSessionService_V1_1_0_SessionService_Actions_CS *Actions;
        RedfishCS_char *Description;
        RedfishCS_char *Id;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_bool *ServiceEnabled;
        RedfishCS_int64 *SessionTimeout;
        RedfishCS_Link Sessions;
        RedfishResource_Status_CS *Status;
    } RedfishSessionService_V1_1_0_SessionService_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Actions**|RedfishSessionService_V1_1_0_SessionService_Actions_CS| Structure points to **Actions** property.| No| Yes
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| No
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| No
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**ServiceEnabled**|RedfishCS_bool| Boolean pointer to **ServiceEnabled** property.| No| No
|**SessionTimeout**|RedfishCS_int64| 64-bit long long interger pointer to **SessionTimeout** property.| No| No
|**Sessions**|RedfishCS_Link| Structure link list to **Sessions** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
## Redfish SessionService V1_1_0 to C Structure Function
    RedfishCS_status
    Json_SessionService_V1_1_0_To_CS (RedfishCS_char *JsonRawText, RedfishSessionService_V1_1_0_SessionService_CS **ReturnedCS);

## C Structure to Redfish SessionService V1_1_0 JSON Function
    RedfishCS_status
    CS_To_SessionService_V1_1_0_JSON (RedfishSessionService_V1_1_0_SessionService_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish SessionService V1_1_0 C Structure Function
    RedfishCS_status
    DestroySessionService_V1_1_0_CS (RedfishSessionService_V1_1_0_SessionService_CS *CSPtr);

