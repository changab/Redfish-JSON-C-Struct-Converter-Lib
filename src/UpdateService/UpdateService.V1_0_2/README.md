# Definition of UpdateService.V1_0_2 and functions<br><br>

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


## SimpleUpdate
    typedef struct _RedfishUpdateService_V1_0_2_SimpleUpdate_CS {
        RedfishCS_char *target;
        RedfishCS_char *title;
    } RedfishUpdateService_V1_0_2_SimpleUpdate_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**target**|RedfishCS_char| String pointer to **target** property.| No| No
|**title**|RedfishCS_char| String pointer to **title** property.| No| No


## UpdateService_Actions
    typedef struct _RedfishUpdateService_V1_0_2_UpdateService_Actions_CS {
        RedfishUpdateService_V1_0_2_SimpleUpdate_CS *UpdateService_SimpleUpdate;
        RedfishUpdateService_V1_0_2_UpdateService_Actions_Oem_CS *Oem;
    } RedfishUpdateService_V1_0_2_UpdateService_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**UpdateService_SimpleUpdate**|RedfishUpdateService_V1_0_2_SimpleUpdate_CS| Structure points to **#UpdateService.SimpleUpdate** property.| No| No
|**Oem**|RedfishUpdateService_V1_0_2_UpdateService_Actions_Oem_CS| Structure points to **Oem** property.| No| No


## UpdateService_Actions_Oem
    typedef struct _RedfishUpdateService_V1_0_2_UpdateService_Actions_Oem_CS {
        RedfishCS_Link Prop;
    } RedfishUpdateService_V1_0_2_UpdateService_Actions_Oem_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## UpdateService
    typedef struct _RedfishUpdateService_V1_0_2_UpdateService_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishUpdateService_V1_0_2_UpdateService_Actions_CS *Actions;
        RedfishCS_char *Description;
        RedfishCS_Link FirmwareInventory;
        RedfishCS_char *Id;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_bool *ServiceEnabled;
        RedfishCS_Link SoftwareInventory;
        RedfishResource_Status_CS *Status;
    } RedfishUpdateService_V1_0_2_UpdateService_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Actions**|RedfishUpdateService_V1_0_2_UpdateService_Actions_CS| Structure points to **Actions** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**FirmwareInventory**|RedfishCS_Link| Structure link list to **FirmwareInventory** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**ServiceEnabled**|RedfishCS_bool| Boolean pointer to **ServiceEnabled** property.| No| No
|**SoftwareInventory**|RedfishCS_Link| Structure link list to **SoftwareInventory** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
## Redfish UpdateService V1_0_2 to C Structure Function
    RedfishCS_status
    Json_UpdateService_V1_0_2_To_CS (RedfishCS_char *JsonRawText, RedfishUpdateService_V1_0_2_UpdateService_CS **ReturnedCS);

## C Structure to Redfish UpdateService V1_0_2 JSON Function
    RedfishCS_status
    CS_To_UpdateService_V1_0_2_JSON (RedfishUpdateService_V1_0_2_UpdateService_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish UpdateService V1_0_2 C Structure Function
    RedfishCS_status
    DestroyUpdateService_V1_0_2_CS (RedfishUpdateService_V1_0_2_UpdateService_CS *CSPtr);

