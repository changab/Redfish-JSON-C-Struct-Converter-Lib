# Definition of CompositionService.V1_0_1 and functions<br><br>

## Actions
    typedef struct _RedfishCompositionService_V1_0_1_Actions_CS {
        RedfishCompositionService_V1_0_1_OemActions_CS *Oem;
    } RedfishCompositionService_V1_0_1_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Oem**|RedfishCompositionService_V1_0_1_OemActions_CS| Structure points to **Oem** property.| No| No


## OemActions
    typedef struct _RedfishCompositionService_V1_0_1_OemActions_CS {
        RedfishCS_Link Prop;
    } RedfishCompositionService_V1_0_1_OemActions_CS;

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


## CompositionService
    typedef struct _RedfishCompositionService_V1_0_1_CompositionService_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishCompositionService_V1_0_1_Actions_CS *Actions;
        RedfishCS_char *Description;
        RedfishCS_char *Id;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_Link ResourceBlocks;
        RedfishCS_Link ResourceZones;
        RedfishCS_bool *ServiceEnabled;
        RedfishResource_Status_CS *Status;
    } RedfishCompositionService_V1_0_1_CompositionService_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Actions**|RedfishCompositionService_V1_0_1_Actions_CS| Structure points to **Actions** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**ResourceBlocks**|RedfishCS_Link| Structure link list to **ResourceBlocks** property.| No| Yes
|**ResourceZones**|RedfishCS_Link| Structure link list to **ResourceZones** property.| No| Yes
|**ServiceEnabled**|RedfishCS_bool| Boolean pointer to **ServiceEnabled** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
## Redfish CompositionService V1_0_1 to C Structure Function
    RedfishCS_status
    Json_CompositionService_V1_0_1_To_CS (RedfishCS_char *JsonRawText, RedfishCompositionService_V1_0_1_CompositionService_CS **ReturnedCS);

## C Structure to Redfish CompositionService V1_0_1 JSON Function
    RedfishCS_status
    CS_To_CompositionService_V1_0_1_JSON (RedfishCompositionService_V1_0_1_CompositionService_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish CompositionService V1_0_1 C Structure Function
    RedfishCS_status
    DestroyCompositionService_V1_0_1_CS (RedfishCompositionService_V1_0_1_CompositionService_CS *CSPtr);

