# Definition of NetworkPort.V1_0_0 and functions<br><br>

## NetDevFuncMaxBWAlloc
    typedef struct _RedfishNetworkPort_V1_0_0_NetDevFuncMaxBWAlloc_CS {
        RedfishCS_int64 *MaxBWAllocPercent;
        RedfishCS_Link NetworkDeviceFunction;
    } RedfishNetworkPort_V1_0_0_NetDevFuncMaxBWAlloc_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**MaxBWAllocPercent**|RedfishCS_int64| 64-bit long long interger pointer to **MaxBWAllocPercent** property.| No| No
|**NetworkDeviceFunction**|RedfishCS_Link| Structure link list to **NetworkDeviceFunction** property.| No| Yes


## NetDevFuncMinBWAlloc
    typedef struct _RedfishNetworkPort_V1_0_0_NetDevFuncMinBWAlloc_CS {
        RedfishCS_int64 *MinBWAllocPercent;
        RedfishCS_Link NetworkDeviceFunction;
    } RedfishNetworkPort_V1_0_0_NetDevFuncMinBWAlloc_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**MinBWAllocPercent**|RedfishCS_int64| 64-bit long long interger pointer to **MinBWAllocPercent** property.| No| No
|**NetworkDeviceFunction**|RedfishCS_Link| Structure link list to **NetworkDeviceFunction** property.| No| Yes


## SupportedLinkCapabilities
    typedef struct _RedfishNetworkPort_V1_0_0_SupportedLinkCapabilities_CS {
        RedfishCS_char *LinkNetworkTechnology;
        RedfishCS_int64 *LinkSpeedMbps;
    } RedfishNetworkPort_V1_0_0_SupportedLinkCapabilities_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**LinkNetworkTechnology**|RedfishCS_char| String pointer to **LinkNetworkTechnology** property.| No| Yes
|**LinkSpeedMbps**|RedfishCS_int64| 64-bit long long interger pointer to **LinkSpeedMbps** property.| No| Yes


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


## NetworkPort
    typedef struct _RedfishNetworkPort_V1_0_0_NetworkPort_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishCS_char *ActiveLinkTechnology;
        RedfishCS_char *AssociatedNetworkAddresses;
        RedfishCS_char *Description;
        RedfishCS_bool *EEEEnabled;
        RedfishCS_char *FlowControlConfiguration;
        RedfishCS_char *FlowControlStatus;
        RedfishCS_char *Id;
        RedfishCS_char *LinkStatus;
        RedfishCS_char *Name;
        RedfishNetworkPort_V1_0_0_NetDevFuncMaxBWAlloc_CS *NetDevFuncMaxBWAlloc;
        RedfishNetworkPort_V1_0_0_NetDevFuncMinBWAlloc_CS *NetDevFuncMinBWAlloc;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *PhysicalPortNumber;
        RedfishCS_int64 *PortMaximumMTU;
        RedfishCS_bool *SignalDetected;
        RedfishResource_Status_CS *Status;
        RedfishCS_char *SupportedEthernetCapabilities;
        RedfishNetworkPort_V1_0_0_SupportedLinkCapabilities_CS *SupportedLinkCapabilities;
        RedfishCS_bool *WakeOnLANEnabled;
    } RedfishNetworkPort_V1_0_0_NetworkPort_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**ActiveLinkTechnology**|RedfishCS_char| String pointer to **ActiveLinkTechnology** property.| No| No
|**AssociatedNetworkAddresses**|RedfishCS_char| String pointer to **AssociatedNetworkAddresses** property.| No| Yes
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**EEEEnabled**|RedfishCS_bool| Boolean pointer to **EEEEnabled** property.| No| No
|**FlowControlConfiguration**|RedfishCS_char| String pointer to **FlowControlConfiguration** property.| No| No
|**FlowControlStatus**|RedfishCS_char| String pointer to **FlowControlStatus** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**LinkStatus**|RedfishCS_char| String pointer to **LinkStatus** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**NetDevFuncMaxBWAlloc**|RedfishNetworkPort_V1_0_0_NetDevFuncMaxBWAlloc_CS| Structure points to **NetDevFuncMaxBWAlloc** property.| No| No
|**NetDevFuncMinBWAlloc**|RedfishNetworkPort_V1_0_0_NetDevFuncMinBWAlloc_CS| Structure points to **NetDevFuncMinBWAlloc** property.| No| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PhysicalPortNumber**|RedfishCS_char| String pointer to **PhysicalPortNumber** property.| No| Yes
|**PortMaximumMTU**|RedfishCS_int64| 64-bit long long interger pointer to **PortMaximumMTU** property.| No| Yes
|**SignalDetected**|RedfishCS_bool| Boolean pointer to **SignalDetected** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**SupportedEthernetCapabilities**|RedfishCS_char| String pointer to **SupportedEthernetCapabilities** property.| No| Yes
|**SupportedLinkCapabilities**|RedfishNetworkPort_V1_0_0_SupportedLinkCapabilities_CS| Structure points to **SupportedLinkCapabilities** property.| No| No
|**WakeOnLANEnabled**|RedfishCS_bool| Boolean pointer to **WakeOnLANEnabled** property.| No| No
## Redfish NetworkPort V1_0_0 to C Structure Function
    RedfishCS_status
    Json_NetworkPort_V1_0_0_To_CS (RedfishCS_char *JsonRawText, RedfishNetworkPort_V1_0_0_NetworkPort_CS **ReturnedCS);

## C Structure to Redfish NetworkPort V1_0_0 JSON Function
    RedfishCS_status
    CS_To_NetworkPort_V1_0_0_JSON (RedfishNetworkPort_V1_0_0_NetworkPort_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish NetworkPort V1_0_0 C Structure Function
    RedfishCS_status
    DestroyNetworkPort_V1_0_0_CS (RedfishNetworkPort_V1_0_0_NetworkPort_CS *CSPtr);

