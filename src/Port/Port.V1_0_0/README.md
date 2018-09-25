# Definition of Port.V1_0_0 and functions<br><br>

## Port_Actions
    typedef struct _RedfishPort_V1_0_0_Port_Actions_CS {
        RedfishPort_V1_0_0_Reset_CS *Port_Reset;
        RedfishPort_V1_0_0_Port_Actions_Oem_CS *Oem;
    } RedfishPort_V1_0_0_Port_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Port_Reset**|RedfishPort_V1_0_0_Reset_CS| Structure points to **#Port.Reset** property.| No| No
|**Oem**|RedfishPort_V1_0_0_Port_Actions_Oem_CS| Structure points to **Oem** property.| No| No


## Port_Actions_Oem
    typedef struct _RedfishPort_V1_0_0_Port_Actions_Oem_CS {
        RedfishCS_Link Prop;
    } RedfishPort_V1_0_0_Port_Actions_Oem_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## Port_Links
    typedef struct _RedfishPort_V1_0_0_Port_Links_CS {
        RedfishCS_Link AssociatedEndpoints;
        RedfishCS_int64 *AssociatedEndpointsodata_count;
        RedfishCS_char *AssociatedEndpointsodata_navigationLink;
        RedfishCS_Link ConnectedSwitchPorts;
        RedfishCS_int64 *ConnectedSwitchPortsodata_count;
        RedfishCS_char *ConnectedSwitchPortsodata_navigationLink;
        RedfishCS_Link ConnectedSwitches;
        RedfishCS_int64 *ConnectedSwitchesodata_count;
        RedfishCS_char *ConnectedSwitchesodata_navigationLink;
        RedfishResource_Oem_CS *Oem;
    } RedfishPort_V1_0_0_Port_Links_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**AssociatedEndpoints**|RedfishCS_Link| Structure link list to **AssociatedEndpoints** property.| No| Yes
|**AssociatedEndpointsodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **AssociatedEndpoints@odata.count** property.| No| No
|**AssociatedEndpointsodata_navigationLink**|RedfishCS_char| String pointer to **AssociatedEndpoints@odata.navigationLink** property.| No| No
|**ConnectedSwitchPorts**|RedfishCS_Link| Structure link list to **ConnectedSwitchPorts** property.| No| Yes
|**ConnectedSwitchPortsodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **ConnectedSwitchPorts@odata.count** property.| No| No
|**ConnectedSwitchPortsodata_navigationLink**|RedfishCS_char| String pointer to **ConnectedSwitchPorts@odata.navigationLink** property.| No| No
|**ConnectedSwitches**|RedfishCS_Link| Structure link list to **ConnectedSwitches** property.| No| Yes
|**ConnectedSwitchesodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **ConnectedSwitches@odata.count** property.| No| No
|**ConnectedSwitchesodata_navigationLink**|RedfishCS_char| String pointer to **ConnectedSwitches@odata.navigationLink** property.| No| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No


## Reset
    typedef struct _RedfishPort_V1_0_0_Reset_CS {
        RedfishCS_char *target;
        RedfishCS_char *title;
    } RedfishPort_V1_0_0_Reset_CS;

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


## Port
    typedef struct _RedfishPort_V1_0_0_Port_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishPort_V1_0_0_Port_Actions_CS *Actions;
        RedfishCS_int64 *CurrentSpeedGbps;
        RedfishCS_char *Description;
        RedfishCS_char *Id;
        RedfishPort_V1_0_0_Port_Links_CS *Links;
        RedfishCS_int64 *MaxSpeedGbps;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *PortId;
        RedfishCS_char *PortProtocol;
        RedfishCS_char *PortType;
        RedfishResource_Status_CS *Status;
        RedfishCS_int64 *Width;
    } RedfishPort_V1_0_0_Port_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Actions**|RedfishPort_V1_0_0_Port_Actions_CS| Structure points to **Actions** property.| No| Yes
|**CurrentSpeedGbps**|RedfishCS_int64| 64-bit long long interger pointer to **CurrentSpeedGbps** property.| No| Yes
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| No
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| No
|**Links**|RedfishPort_V1_0_0_Port_Links_CS| Structure points to **Links** property.| No| Yes
|**MaxSpeedGbps**|RedfishCS_int64| 64-bit long long interger pointer to **MaxSpeedGbps** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PortId**|RedfishCS_char| String pointer to **PortId** property.| No| Yes
|**PortProtocol**|RedfishCS_char| String pointer to **PortProtocol** property.| No| No
|**PortType**|RedfishCS_char| String pointer to **PortType** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**Width**|RedfishCS_int64| 64-bit long long interger pointer to **Width** property.| No| Yes
## Redfish Port V1_0_0 to C Structure Function
    RedfishCS_status
    Json_Port_V1_0_0_To_CS (RedfishCS_char *JsonRawText, RedfishPort_V1_0_0_Port_CS **ReturnedCS);

## C Structure to Redfish Port V1_0_0 JSON Function
    RedfishCS_status
    CS_To_Port_V1_0_0_JSON (RedfishPort_V1_0_0_Port_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish Port V1_0_0 C Structure Function
    RedfishCS_status
    DestroyPort_V1_0_0_CS (RedfishPort_V1_0_0_Port_CS *CSPtr);

