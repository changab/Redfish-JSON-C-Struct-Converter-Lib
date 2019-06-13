# Definition of NetworkInterface.V1_1_1 and functions<br><br>

## Actions
    typedef struct _RedfishNetworkInterface_V1_1_1_Actions_CS {
        RedfishNetworkInterface_V1_1_1_OemActions_CS *Oem;
    } RedfishNetworkInterface_V1_1_1_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Oem**|RedfishNetworkInterface_V1_1_1_OemActions_CS| Structure points to **Oem** property.| No| No


## Links
    typedef struct _RedfishNetworkInterface_V1_1_1_Links_CS {
        RedfishCS_Link NetworkAdapter;
        RedfishResource_Oem_CS *Oem;
    } RedfishNetworkInterface_V1_1_1_Links_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**NetworkAdapter**|RedfishCS_Link| Structure link list to **NetworkAdapter** property.| No| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No


## OemActions
    typedef struct _RedfishNetworkInterface_V1_1_1_OemActions_CS {
        RedfishCS_Link Prop;
    } RedfishNetworkInterface_V1_1_1_OemActions_CS;

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


## NetworkInterface
    typedef struct _RedfishNetworkInterface_V1_1_1_NetworkInterface_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_etag;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishNetworkInterface_V1_1_1_Actions_CS *Actions;
        RedfishCS_char *Description;
        RedfishCS_char *Id;
        RedfishNetworkInterface_V1_1_1_Links_CS *Links;
        RedfishCS_char *Name;
        RedfishCS_Link NetworkDeviceFunctions;
        RedfishCS_Link NetworkPorts;
        RedfishResource_Oem_CS *Oem;
        RedfishResource_Status_CS *Status;
    } RedfishNetworkInterface_V1_1_1_NetworkInterface_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_etag**|RedfishCS_char| String pointer to **@odata.etag** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| Yes| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| Yes| No
|**Actions**|RedfishNetworkInterface_V1_1_1_Actions_CS| Structure points to **Actions** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**Links**|RedfishNetworkInterface_V1_1_1_Links_CS| Structure points to **Links** property.| No| No
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**NetworkDeviceFunctions**|RedfishCS_Link| Structure link list to **NetworkDeviceFunctions** property.| No| Yes
|**NetworkPorts**|RedfishCS_Link| Structure link list to **NetworkPorts** property.| No| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
## Redfish NetworkInterface V1_1_1 to C Structure Function
    RedfishCS_status
    Json_NetworkInterface_V1_1_1_To_CS (RedfishCS_char *JsonRawText, RedfishNetworkInterface_V1_1_1_NetworkInterface_CS **ReturnedCS);

## C Structure to Redfish NetworkInterface V1_1_1 JSON Function
    RedfishCS_status
    CS_To_NetworkInterface_V1_1_1_JSON (RedfishNetworkInterface_V1_1_1_NetworkInterface_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish NetworkInterface V1_1_1 C Structure Function
    RedfishCS_status
    DestroyNetworkInterface_V1_1_1_CS (RedfishNetworkInterface_V1_1_1_NetworkInterface_CS *CSPtr);

