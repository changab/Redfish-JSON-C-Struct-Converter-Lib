# Definition of EventService.V1_1_1 and functions<br><br>

## Actions
    typedef struct _RedfishEventService_V1_1_1_Actions_CS {
        RedfishEventService_V1_1_1_SubmitTestEvent_CS *EventService_SubmitTestEvent;
        RedfishEventService_V1_1_1_OemActions_CS *Oem;
    } RedfishEventService_V1_1_1_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**EventService_SubmitTestEvent**|RedfishEventService_V1_1_1_SubmitTestEvent_CS| Structure points to **#EventService.SubmitTestEvent** property.| No| No
|**Oem**|RedfishEventService_V1_1_1_OemActions_CS| Structure points to **Oem** property.| No| No


## OemActions
    typedef struct _RedfishEventService_V1_1_1_OemActions_CS {
        RedfishCS_Link Prop;
    } RedfishEventService_V1_1_1_OemActions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## SubmitTestEvent
    typedef struct _RedfishEventService_V1_1_1_SubmitTestEvent_CS {
        RedfishCS_char *target;
        RedfishCS_char *title;
    } RedfishEventService_V1_1_1_SubmitTestEvent_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**target**|RedfishCS_char| String pointer to **target** property.| No| No
|**title**|RedfishCS_char| String pointer to **title** property.| No| No


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


## EventService
    typedef struct _RedfishEventService_V1_1_1_EventService_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_etag;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishEventService_V1_1_1_Actions_CS *Actions;
        RedfishCS_int64 *DeliveryRetryAttempts;
        RedfishCS_int64 *DeliveryRetryIntervalSeconds;
        RedfishCS_char *Description;
        RedfishCS_char *EventTypesForSubscription;
        RedfishCS_char *Id;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *ServerSentEventUri;
        RedfishCS_bool *ServiceEnabled;
        RedfishResource_Status_CS *Status;
        RedfishCS_Link Subscriptions;
    } RedfishEventService_V1_1_1_EventService_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_etag**|RedfishCS_char| String pointer to **@odata.etag** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| Yes| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| Yes| No
|**Actions**|RedfishEventService_V1_1_1_Actions_CS| Structure points to **Actions** property.| No| No
|**DeliveryRetryAttempts**|RedfishCS_int64| 64-bit long long interger pointer to **DeliveryRetryAttempts** property.| No| No
|**DeliveryRetryIntervalSeconds**|RedfishCS_int64| 64-bit long long interger pointer to **DeliveryRetryIntervalSeconds** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**EventTypesForSubscription**|RedfishCS_char| String pointer to **EventTypesForSubscription** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**ServerSentEventUri**|RedfishCS_char| String pointer to **ServerSentEventUri** property.| No| Yes
|**ServiceEnabled**|RedfishCS_bool| Boolean pointer to **ServiceEnabled** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**Subscriptions**|RedfishCS_Link| Structure link list to **Subscriptions** property.| No| Yes
## Redfish EventService V1_1_1 to C Structure Function
    RedfishCS_status
    Json_EventService_V1_1_1_To_CS (RedfishCS_char *JsonRawText, RedfishEventService_V1_1_1_EventService_CS **ReturnedCS);

## C Structure to Redfish EventService V1_1_1 JSON Function
    RedfishCS_status
    CS_To_EventService_V1_1_1_JSON (RedfishEventService_V1_1_1_EventService_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish EventService V1_1_1 C Structure Function
    RedfishCS_status
    DestroyEventService_V1_1_1_CS (RedfishEventService_V1_1_1_EventService_CS *CSPtr);

