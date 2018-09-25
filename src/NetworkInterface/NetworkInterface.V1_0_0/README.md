# Definition of NetworkInterface.V1_0_0 and functions<br><br>

## NetworkInterface_Links
    typedef struct _RedfishNetworkInterface_V1_0_0_NetworkInterface_Links_CS {
        RedfishCS_Link NetworkAdapter;
        RedfishResource_Oem_CS *Oem;
    } RedfishNetworkInterface_V1_0_0_NetworkInterface_Links_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**NetworkAdapter**|RedfishCS_Link| Structure link list to **NetworkAdapter** property.| No| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No


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
    typedef struct _RedfishNetworkInterface_V1_0_0_NetworkInterface_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishCS_char *Description;
        RedfishCS_char *Id;
        RedfishNetworkInterface_V1_0_0_NetworkInterface_Links_CS *Links;
        RedfishCS_char *Name;
        RedfishCS_Link NetworkDeviceFunctions;
        RedfishCS_Link NetworkPorts;
        RedfishResource_Oem_CS *Oem;
        RedfishResource_Status_CS *Status;
    } RedfishNetworkInterface_V1_0_0_NetworkInterface_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**Links**|RedfishNetworkInterface_V1_0_0_NetworkInterface_Links_CS| Structure points to **Links** property.| No| No
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**NetworkDeviceFunctions**|RedfishCS_Link| Structure link list to **NetworkDeviceFunctions** property.| No| Yes
|**NetworkPorts**|RedfishCS_Link| Structure link list to **NetworkPorts** property.| No| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
## Redfish NetworkInterface V1_0_0 to C Structure Function
    RedfishCS_status
    Json_NetworkInterface_V1_0_0_To_CS (RedfishCS_char *JsonRawText, RedfishNetworkInterface_V1_0_0_NetworkInterface_CS **ReturnedCS);

## C Structure to Redfish NetworkInterface V1_0_0 JSON Function
    RedfishCS_status
    CS_To_NetworkInterface_V1_0_0_JSON (RedfishNetworkInterface_V1_0_0_NetworkInterface_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish NetworkInterface V1_0_0 C Structure Function
    RedfishCS_status
    DestroyNetworkInterface_V1_0_0_CS (RedfishNetworkInterface_V1_0_0_NetworkInterface_CS *CSPtr);

