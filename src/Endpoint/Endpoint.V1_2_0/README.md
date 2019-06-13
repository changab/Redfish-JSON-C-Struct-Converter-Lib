# Definition of Endpoint.V1_2_0 and functions<br><br>

## Actions
    typedef struct _RedfishEndpoint_V1_2_0_Actions_CS {
        RedfishEndpoint_V1_2_0_OemActions_CS *Oem;
    } RedfishEndpoint_V1_2_0_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Oem**|RedfishEndpoint_V1_2_0_OemActions_CS| Structure points to **Oem** property.| No| No


## ConnectedEntity
    typedef struct _RedfishEndpoint_V1_2_0_ConnectedEntity_CS {
        RedfishCS_Link EntityLink;
        RedfishEndpoint_V1_2_0_PciId_CS *EntityPciId;
        RedfishCS_char *EntityRole;
        RedfishCS_char *EntityType;
        RedfishCS_Link Identifiers;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *PciClassCode;
        RedfishCS_int64 *PciFunctionNumber;
    } RedfishEndpoint_V1_2_0_ConnectedEntity_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**EntityLink**|RedfishCS_Link| Structure link list to **EntityLink** property.| No| Yes
|**EntityPciId**|RedfishEndpoint_V1_2_0_PciId_CS| Structure points to **EntityPciId** property.| No| No
|**EntityRole**|RedfishCS_char| String pointer to **EntityRole** property.| No| Yes
|**EntityType**|RedfishCS_char| String pointer to **EntityType** property.| No| Yes
|**Identifiers**|RedfishCS_Link| Structure link list to **Identifiers** property.| No| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PciClassCode**|RedfishCS_char| String pointer to **PciClassCode** property.| No| Yes
|**PciFunctionNumber**|RedfishCS_int64| 64-bit long long interger pointer to **PciFunctionNumber** property.| No| Yes


## IPTransportDetails
    typedef struct _RedfishEndpoint_V1_2_0_IPTransportDetails_CS {
        RedfishCS_Link IPv4Address;
        RedfishCS_Link IPv6Address;
        RedfishCS_int64 *Port;
        RedfishCS_char *TransportProtocol;
    } RedfishEndpoint_V1_2_0_IPTransportDetails_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**IPv4Address**|RedfishCS_Link| Structure link list to **IPv4Address** property.| No| No
|**IPv6Address**|RedfishCS_Link| Structure link list to **IPv6Address** property.| No| No
|**Port**|RedfishCS_int64| 64-bit long long interger pointer to **Port** property.| No| Yes
|**TransportProtocol**|RedfishCS_char| String pointer to **TransportProtocol** property.| No| Yes


## Links
    typedef struct _RedfishEndpoint_V1_2_0_Links_CS {
        RedfishCS_Link MutuallyExclusiveEndpoints;
        RedfishCS_int64 *MutuallyExclusiveEndpointsodata_count;
        RedfishCS_Link NetworkDeviceFunction;
        RedfishCS_int64 *NetworkDeviceFunctionodata_count;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_Link Ports;
        RedfishCS_int64 *Portsodata_count;
    } RedfishEndpoint_V1_2_0_Links_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**MutuallyExclusiveEndpoints**|RedfishCS_Link| Structure link list to **MutuallyExclusiveEndpoints** property.| No| Yes
|**MutuallyExclusiveEndpointsodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **MutuallyExclusiveEndpoints@odata.count** property.| No| No
|**NetworkDeviceFunction**|RedfishCS_Link| Structure link list to **NetworkDeviceFunction** property.| No| Yes
|**NetworkDeviceFunctionodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **NetworkDeviceFunction@odata.count** property.| No| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**Ports**|RedfishCS_Link| Structure link list to **Ports** property.| No| Yes
|**Portsodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Ports@odata.count** property.| No| No


## OemActions
    typedef struct _RedfishEndpoint_V1_2_0_OemActions_CS {
        RedfishCS_Link Prop;
    } RedfishEndpoint_V1_2_0_OemActions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## PciId
    typedef struct _RedfishEndpoint_V1_2_0_PciId_CS {
        RedfishCS_char *ClassCode;
        RedfishCS_char *DeviceId;
        RedfishCS_int64 *FunctionNumber;
        RedfishCS_char *SubsystemId;
        RedfishCS_char *SubsystemVendorId;
        RedfishCS_char *VendorId;
    } RedfishEndpoint_V1_2_0_PciId_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**ClassCode**|RedfishCS_char| String pointer to **ClassCode** property.| No| Yes
|**DeviceId**|RedfishCS_char| String pointer to **DeviceId** property.| No| Yes
|**FunctionNumber**|RedfishCS_int64| 64-bit long long interger pointer to **FunctionNumber** property.| No| Yes
|**SubsystemId**|RedfishCS_char| String pointer to **SubsystemId** property.| No| Yes
|**SubsystemVendorId**|RedfishCS_char| String pointer to **SubsystemVendorId** property.| No| Yes
|**VendorId**|RedfishCS_char| String pointer to **VendorId** property.| No| Yes


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


## Endpoint
    typedef struct _RedfishEndpoint_V1_2_0_Endpoint_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_etag;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishEndpoint_V1_2_0_Actions_CS *Actions;
        RedfishEndpoint_V1_2_0_ConnectedEntity_CS *ConnectedEntities;
        RedfishCS_char *Description;
        RedfishCS_char *EndpointProtocol;
        RedfishCS_int64 *HostReservationMemoryBytes;
        RedfishEndpoint_V1_2_0_IPTransportDetails_CS *IPTransportDetails;
        RedfishCS_char *Id;
        RedfishCS_Link Identifiers;
        RedfishEndpoint_V1_2_0_Links_CS *Links;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishEndpoint_V1_2_0_PciId_CS *PciId;
        RedfishCS_Link Redundancy;
        RedfishCS_int64 *Redundancyodata_count;
        RedfishResource_Status_CS *Status;
    } RedfishEndpoint_V1_2_0_Endpoint_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_etag**|RedfishCS_char| String pointer to **@odata.etag** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| Yes| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| Yes| No
|**Actions**|RedfishEndpoint_V1_2_0_Actions_CS| Structure points to **Actions** property.| No| No
|**ConnectedEntities**|RedfishEndpoint_V1_2_0_ConnectedEntity_CS| Structure points to **ConnectedEntities** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**EndpointProtocol**|RedfishCS_char| String pointer to **EndpointProtocol** property.| No| Yes
|**HostReservationMemoryBytes**|RedfishCS_int64| 64-bit long long interger pointer to **HostReservationMemoryBytes** property.| No| Yes
|**IPTransportDetails**|RedfishEndpoint_V1_2_0_IPTransportDetails_CS| Structure points to **IPTransportDetails** property.| No| No
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**Identifiers**|RedfishCS_Link| Structure link list to **Identifiers** property.| No| No
|**Links**|RedfishEndpoint_V1_2_0_Links_CS| Structure points to **Links** property.| No| No
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PciId**|RedfishEndpoint_V1_2_0_PciId_CS| Structure points to **PciId** property.| No| No
|**Redundancy**|RedfishCS_Link| Structure link list to **Redundancy** property.| No| No
|**Redundancyodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Redundancy@odata.count** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
## Redfish Endpoint V1_2_0 to C Structure Function
    RedfishCS_status
    Json_Endpoint_V1_2_0_To_CS (RedfishCS_char *JsonRawText, RedfishEndpoint_V1_2_0_Endpoint_CS **ReturnedCS);

## C Structure to Redfish Endpoint V1_2_0 JSON Function
    RedfishCS_status
    CS_To_Endpoint_V1_2_0_JSON (RedfishEndpoint_V1_2_0_Endpoint_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish Endpoint V1_2_0 C Structure Function
    RedfishCS_status
    DestroyEndpoint_V1_2_0_CS (RedfishEndpoint_V1_2_0_Endpoint_CS *CSPtr);

