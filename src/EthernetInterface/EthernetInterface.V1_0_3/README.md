# Definition of EthernetInterface.V1_0_3 and functions<br><br>

## IPv6AddressPolicyEntry
    typedef struct _RedfishEthernetInterface_V1_0_3_IPv6AddressPolicyEntry_CS {
        RedfishCS_int64 *Label;
        RedfishCS_int64 *Precedence;
        RedfishCS_char *Prefix;
    } RedfishEthernetInterface_V1_0_3_IPv6AddressPolicyEntry_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Label**|RedfishCS_int64| 64-bit long long interger pointer to **Label** property.| No| No
|**Precedence**|RedfishCS_int64| 64-bit long long interger pointer to **Precedence** property.| No| No
|**Prefix**|RedfishCS_char| String pointer to **Prefix** property.| No| No


## IPv4Address
    typedef struct _RedfishIPAddresses_V1_0_0_IPv4Address_CS {
        RedfishCS_char *Origin;
        RedfishCS_char *Address;
        RedfishCS_char *AddressOrigin;
        RedfishCS_char *Gateway;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *SubnetMask;
    } RedfishIPAddresses_V1_0_0_IPv4Address_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Origin**|RedfishCS_char| String pointer to **AddressOrigin** property.| No| Yes
|**Address**|RedfishCS_char| String pointer to **Address** property.| No| No
|**AddressOrigin**|RedfishCS_char| String pointer to **AddressOrigin** property.| No| Yes
|**Gateway**|RedfishCS_char| String pointer to **Gateway** property.| No| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**SubnetMask**|RedfishCS_char| String pointer to **SubnetMask** property.| No| No


## IPv6Address
    typedef struct _RedfishIPAddresses_V1_0_0_IPv6Address_CS {
        RedfishCS_char *Origin;
        RedfishCS_char *Address;
        RedfishCS_char *AddressOrigin;
        RedfishCS_char *AddressState;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_int64 *PrefixLength;
    } RedfishIPAddresses_V1_0_0_IPv6Address_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Origin**|RedfishCS_char| String pointer to **AddressOrigin** property.| No| Yes
|**Address**|RedfishCS_char| String pointer to **Address** property.| No| No
|**AddressOrigin**|RedfishCS_char| String pointer to **AddressOrigin** property.| No| Yes
|**AddressState**|RedfishCS_char| String pointer to **AddressState** property.| No| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PrefixLength**|RedfishCS_int64| 64-bit long long interger pointer to **PrefixLength** property.| No| Yes


## IPv6StaticAddress
    typedef struct _RedfishIPAddresses_V1_0_0_IPv6StaticAddress_CS {
        RedfishCS_char *Address;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_int64 *PrefixLength;
    } RedfishIPAddresses_V1_0_0_IPv6StaticAddress_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Address**|RedfishCS_char| String pointer to **Address** property.| No| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PrefixLength**|RedfishCS_int64| 64-bit long long interger pointer to **PrefixLength** property.| No| Yes


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


## VLAN
    typedef struct _RedfishVLanNetworkInterface_V1_0_0_VLAN_CS {
        RedfishCS_int64 *Id;
        RedfishCS_bool *VLANEnable;
        RedfishCS_int64 *VLANId;
    } RedfishVLanNetworkInterface_V1_0_0_VLAN_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Id**|RedfishCS_int64| 64-bit long long interger pointer to **VLANId** property.| No| No
|**VLANEnable**|RedfishCS_bool| Boolean pointer to **VLANEnable** property.| No| No
|**VLANId**|RedfishCS_int64| 64-bit long long interger pointer to **VLANId** property.| No| No


## EthernetInterface
    typedef struct _RedfishEthernetInterface_V1_0_3_EthernetInterface_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishCS_bool *AutoNeg;
        RedfishCS_char *Description;
        RedfishCS_char *FQDN;
        RedfishCS_bool *FullDuplex;
        RedfishCS_char *HostName;
        RedfishIPAddresses_V1_0_0_IPv4Address_CS *IPv4Addresses;
        RedfishEthernetInterface_V1_0_3_IPv6AddressPolicyEntry_CS *IPv6AddressPolicyTable;
        RedfishIPAddresses_V1_0_0_IPv6Address_CS *IPv6Addresses;
        RedfishCS_char *IPv6DefaultGateway;
        RedfishIPAddresses_V1_0_0_IPv6StaticAddress_CS *IPv6StaticAddresses;
        RedfishCS_char *Id;
        RedfishCS_bool *InterfaceEnabled;
        RedfishCS_char *MACAddress;
        RedfishCS_int64 *MTUSize;
        RedfishCS_int64 *MaxIPv6StaticAddresses;
        RedfishCS_char *Name;
        RedfishCS_char *NameServers;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *PermanentMACAddress;
        RedfishCS_int64 *SpeedMbps;
        RedfishResource_Status_CS *Status;
        RedfishCS_char *UefiDevicePath;
        RedfishVLanNetworkInterface_V1_0_0_VLAN_CS *VLAN;
        RedfishCS_Link VLANs;
    } RedfishEthernetInterface_V1_0_3_EthernetInterface_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**AutoNeg**|RedfishCS_bool| Boolean pointer to **AutoNeg** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**FQDN**|RedfishCS_char| String pointer to **FQDN** property.| No| No
|**FullDuplex**|RedfishCS_bool| Boolean pointer to **FullDuplex** property.| No| No
|**HostName**|RedfishCS_char| String pointer to **HostName** property.| No| No
|**IPv4Addresses**|RedfishIPAddresses_V1_0_0_IPv4Address_CS| Structure points to **IPv4Addresses** property.| No| No
|**IPv6AddressPolicyTable**|RedfishEthernetInterface_V1_0_3_IPv6AddressPolicyEntry_CS| Structure points to **IPv6AddressPolicyTable** property.| No| No
|**IPv6Addresses**|RedfishIPAddresses_V1_0_0_IPv6Address_CS| Structure points to **IPv6Addresses** property.| No| No
|**IPv6DefaultGateway**|RedfishCS_char| String pointer to **IPv6DefaultGateway** property.| No| Yes
|**IPv6StaticAddresses**|RedfishIPAddresses_V1_0_0_IPv6StaticAddress_CS| Structure points to **IPv6StaticAddresses** property.| No| No
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**InterfaceEnabled**|RedfishCS_bool| Boolean pointer to **InterfaceEnabled** property.| No| No
|**MACAddress**|RedfishCS_char| String pointer to **MACAddress** property.| No| No
|**MTUSize**|RedfishCS_int64| 64-bit long long interger pointer to **MTUSize** property.| No| No
|**MaxIPv6StaticAddresses**|RedfishCS_int64| 64-bit long long interger pointer to **MaxIPv6StaticAddresses** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**NameServers**|RedfishCS_char| String pointer to **NameServers** property.| No| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PermanentMACAddress**|RedfishCS_char| String pointer to **PermanentMACAddress** property.| No| Yes
|**SpeedMbps**|RedfishCS_int64| 64-bit long long interger pointer to **SpeedMbps** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**UefiDevicePath**|RedfishCS_char| String pointer to **UefiDevicePath** property.| No| Yes
|**VLAN**|RedfishVLanNetworkInterface_V1_0_0_VLAN_CS| Structure points to **VLAN** property.| No| No
|**VLANs**|RedfishCS_Link| Structure link list to **VLANs** property.| No| Yes
## Redfish EthernetInterface V1_0_3 to C Structure Function
    RedfishCS_status
    Json_EthernetInterface_V1_0_3_To_CS (RedfishCS_char *JsonRawText, RedfishEthernetInterface_V1_0_3_EthernetInterface_CS **ReturnedCS);

## C Structure to Redfish EthernetInterface V1_0_3 JSON Function
    RedfishCS_status
    CS_To_EthernetInterface_V1_0_3_JSON (RedfishEthernetInterface_V1_0_3_EthernetInterface_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish EthernetInterface V1_0_3 C Structure Function
    RedfishCS_status
    DestroyEthernetInterface_V1_0_3_CS (RedfishEthernetInterface_V1_0_3_EthernetInterface_CS *CSPtr);

