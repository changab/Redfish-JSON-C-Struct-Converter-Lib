# Definition of Fabric.V1_0_3 and functions<br><br>

## Actions
    typedef struct _RedfishFabric_V1_0_3_Actions_CS {
        RedfishFabric_V1_0_3_OemActions_CS *Oem;
    } RedfishFabric_V1_0_3_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Oem**|RedfishFabric_V1_0_3_OemActions_CS| Structure points to **Oem** property.| No| No


## Links
    typedef struct _RedfishFabric_V1_0_3_Links_CS {
        RedfishResource_Oem_CS *Oem;
    } RedfishFabric_V1_0_3_Links_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No


## OemActions
    typedef struct _RedfishFabric_V1_0_3_OemActions_CS {
        RedfishCS_Link Prop;
    } RedfishFabric_V1_0_3_OemActions_CS;

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


## Fabric
    typedef struct _RedfishFabric_V1_0_3_Fabric_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishFabric_V1_0_3_Actions_CS *Actions;
        RedfishCS_char *Description;
        RedfishCS_Link Endpoints;
        RedfishCS_char *FabricType;
        RedfishCS_char *Id;
        RedfishFabric_V1_0_3_Links_CS *Links;
        RedfishCS_int64 *MaxZones;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishResource_Status_CS *Status;
        RedfishCS_Link Switches;
        RedfishCS_Link Zones;
    } RedfishFabric_V1_0_3_Fabric_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Actions**|RedfishFabric_V1_0_3_Actions_CS| Structure points to **Actions** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Endpoints**|RedfishCS_Link| Structure link list to **Endpoints** property.| No| Yes
|**FabricType**|RedfishCS_char| String pointer to **FabricType** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**Links**|RedfishFabric_V1_0_3_Links_CS| Structure points to **Links** property.| No| No
|**MaxZones**|RedfishCS_int64| 64-bit long long interger pointer to **MaxZones** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**Switches**|RedfishCS_Link| Structure link list to **Switches** property.| No| Yes
|**Zones**|RedfishCS_Link| Structure link list to **Zones** property.| No| Yes
## Redfish Fabric V1_0_3 to C Structure Function
    RedfishCS_status
    Json_Fabric_V1_0_3_To_CS (RedfishCS_char *JsonRawText, RedfishFabric_V1_0_3_Fabric_CS **ReturnedCS);

## C Structure to Redfish Fabric V1_0_3 JSON Function
    RedfishCS_status
    CS_To_Fabric_V1_0_3_JSON (RedfishFabric_V1_0_3_Fabric_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish Fabric V1_0_3 C Structure Function
    RedfishCS_status
    DestroyFabric_V1_0_3_CS (RedfishFabric_V1_0_3_Fabric_CS *CSPtr);

