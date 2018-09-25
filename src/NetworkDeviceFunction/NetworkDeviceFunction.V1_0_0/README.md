# Definition of NetworkDeviceFunction.V1_0_0 and functions<br><br>

## BootTargets
    typedef struct _RedfishNetworkDeviceFunction_V1_0_0_BootTargets_CS {
        RedfishCS_int64 *BootPriority;
        RedfishCS_char *LUNID;
        RedfishCS_char *WWPN;
    } RedfishNetworkDeviceFunction_V1_0_0_BootTargets_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**BootPriority**|RedfishCS_int64| 64-bit long long interger pointer to **BootPriority** property.| No| No
|**LUNID**|RedfishCS_char| String pointer to **LUNID** property.| No| No
|**WWPN**|RedfishCS_char| String pointer to **WWPN** property.| No| No


## Ethernet
    typedef struct _RedfishNetworkDeviceFunction_V1_0_0_Ethernet_CS {
        RedfishCS_char *MACAddress;
        RedfishCS_int64 *MTUSize;
        RedfishCS_char *PermanentMACAddress;
    } RedfishNetworkDeviceFunction_V1_0_0_Ethernet_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**MACAddress**|RedfishCS_char| String pointer to **MACAddress** property.| No| No
|**MTUSize**|RedfishCS_int64| 64-bit long long interger pointer to **MTUSize** property.| No| No
|**PermanentMACAddress**|RedfishCS_char| String pointer to **PermanentMACAddress** property.| No| Yes


## FibreChannel
    typedef struct _RedfishNetworkDeviceFunction_V1_0_0_FibreChannel_CS {
        RedfishCS_bool *AllowFIPVLANDiscovery;
        RedfishNetworkDeviceFunction_V1_0_0_BootTargets_Array_CS *BootTargets;
        RedfishCS_int64 *FCoEActiveVLANId;
        RedfishCS_int64 *FCoELocalVLANId;
        RedfishCS_char *PermanentWWNN;
        RedfishCS_char *PermanentWWPN;
        RedfishCS_char *WWNN;
        RedfishCS_char *WWNSource;
        RedfishCS_char *WWPN;
    } RedfishNetworkDeviceFunction_V1_0_0_FibreChannel_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**AllowFIPVLANDiscovery**|RedfishCS_bool| Boolean pointer to **AllowFIPVLANDiscovery** property.| No| No
|**BootTargets**|RedfishNetworkDeviceFunction_V1_0_0_BootTargets_Array_CS| Structure array points to one or more than one **RedfishNetworkDeviceFunction_V1_0_0_BootTargets_Array_CS** structures for property **BootTargets**.| No| No
|**FCoEActiveVLANId**|RedfishCS_int64| 64-bit long long interger pointer to **FCoEActiveVLANId** property.| No| Yes
|**FCoELocalVLANId**|RedfishCS_int64| 64-bit long long interger pointer to **FCoELocalVLANId** property.| No| No
|**PermanentWWNN**|RedfishCS_char| String pointer to **PermanentWWNN** property.| No| Yes
|**PermanentWWPN**|RedfishCS_char| String pointer to **PermanentWWPN** property.| No| Yes
|**WWNN**|RedfishCS_char| String pointer to **WWNN** property.| No| No
|**WWNSource**|RedfishCS_char| String pointer to **WWNSource** property.| No| No
|**WWPN**|RedfishCS_char| String pointer to **WWPN** property.| No| No


## Links
    typedef struct _RedfishNetworkDeviceFunction_V1_0_0_Links_CS {
        RedfishCS_Link PCIeFunction;
    } RedfishNetworkDeviceFunction_V1_0_0_Links_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**PCIeFunction**|RedfishCS_Link| Structure link list to **PCIeFunction** property.| No| Yes


## iSCSIBoot
    typedef struct _RedfishNetworkDeviceFunction_V1_0_0_iSCSIBoot_CS {
        RedfishCS_char *AuthenticationMethod;
        RedfishCS_char *CHAPSecret;
        RedfishCS_char *CHAPUsername;
        RedfishCS_char *IPAddressType;
        RedfishCS_bool *IPMaskDNSViaDHCP;
        RedfishCS_char *InitiatorDefaultGateway;
        RedfishCS_char *InitiatorIPAddress;
        RedfishCS_char *InitiatorName;
        RedfishCS_char *InitiatorNetmask;
        RedfishCS_char *MutualCHAPSecret;
        RedfishCS_char *MutualCHAPUsername;
        RedfishCS_char *PrimaryDNS;
        RedfishCS_int64 *PrimaryLUN;
        RedfishCS_char *PrimaryTargetIPAddress;
        RedfishCS_char *PrimaryTargetName;
        RedfishCS_int64 *PrimaryTargetTCPPort;
        RedfishCS_bool *PrimaryVLANEnable;
        RedfishCS_int64 *PrimaryVLANId;
        RedfishCS_bool *RouterAdvertisementEnabled;
        RedfishCS_char *SecondaryDNS;
        RedfishCS_int64 *SecondaryLUN;
        RedfishCS_char *SecondaryTargetIPAddress;
        RedfishCS_char *SecondaryTargetName;
        RedfishCS_int64 *SecondaryTargetTCPPort;
        RedfishCS_bool *SecondaryVLANEnable;
        RedfishCS_int64 *SecondaryVLANId;
        RedfishCS_bool *TargetInfoViaDHCP;
    } RedfishNetworkDeviceFunction_V1_0_0_iSCSIBoot_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**AuthenticationMethod**|RedfishCS_char| String pointer to **AuthenticationMethod** property.| No| No
|**CHAPSecret**|RedfishCS_char| String pointer to **CHAPSecret** property.| No| No
|**CHAPUsername**|RedfishCS_char| String pointer to **CHAPUsername** property.| No| No
|**IPAddressType**|RedfishCS_char| String pointer to **IPAddressType** property.| No| No
|**IPMaskDNSViaDHCP**|RedfishCS_bool| Boolean pointer to **IPMaskDNSViaDHCP** property.| No| No
|**InitiatorDefaultGateway**|RedfishCS_char| String pointer to **InitiatorDefaultGateway** property.| No| No
|**InitiatorIPAddress**|RedfishCS_char| String pointer to **InitiatorIPAddress** property.| No| No
|**InitiatorName**|RedfishCS_char| String pointer to **InitiatorName** property.| No| No
|**InitiatorNetmask**|RedfishCS_char| String pointer to **InitiatorNetmask** property.| No| No
|**MutualCHAPSecret**|RedfishCS_char| String pointer to **MutualCHAPSecret** property.| No| No
|**MutualCHAPUsername**|RedfishCS_char| String pointer to **MutualCHAPUsername** property.| No| No
|**PrimaryDNS**|RedfishCS_char| String pointer to **PrimaryDNS** property.| No| No
|**PrimaryLUN**|RedfishCS_int64| 64-bit long long interger pointer to **PrimaryLUN** property.| No| No
|**PrimaryTargetIPAddress**|RedfishCS_char| String pointer to **PrimaryTargetIPAddress** property.| No| No
|**PrimaryTargetName**|RedfishCS_char| String pointer to **PrimaryTargetName** property.| No| No
|**PrimaryTargetTCPPort**|RedfishCS_int64| 64-bit long long interger pointer to **PrimaryTargetTCPPort** property.| No| No
|**PrimaryVLANEnable**|RedfishCS_bool| Boolean pointer to **PrimaryVLANEnable** property.| No| No
|**PrimaryVLANId**|RedfishCS_int64| 64-bit long long interger pointer to **PrimaryVLANId** property.| No| No
|**RouterAdvertisementEnabled**|RedfishCS_bool| Boolean pointer to **RouterAdvertisementEnabled** property.| No| No
|**SecondaryDNS**|RedfishCS_char| String pointer to **SecondaryDNS** property.| No| No
|**SecondaryLUN**|RedfishCS_int64| 64-bit long long interger pointer to **SecondaryLUN** property.| No| No
|**SecondaryTargetIPAddress**|RedfishCS_char| String pointer to **SecondaryTargetIPAddress** property.| No| No
|**SecondaryTargetName**|RedfishCS_char| String pointer to **SecondaryTargetName** property.| No| No
|**SecondaryTargetTCPPort**|RedfishCS_int64| 64-bit long long interger pointer to **SecondaryTargetTCPPort** property.| No| No
|**SecondaryVLANEnable**|RedfishCS_bool| Boolean pointer to **SecondaryVLANEnable** property.| No| No
|**SecondaryVLANId**|RedfishCS_int64| 64-bit long long interger pointer to **SecondaryVLANId** property.| No| No
|**TargetInfoViaDHCP**|RedfishCS_bool| Boolean pointer to **TargetInfoViaDHCP** property.| No| No


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


## RedfishNetworkDeviceFunction_V1_0_0_BootTargets_Array_CS
    typedef struct _RedfishNetworkDeviceFunction_V1_0_0_BootTargets_Array_CS  {
        RedfishCS_Link *Next;
        RedfishNetworkDeviceFunction_V1_0_0_BootTargets_CS *ArrayValue;
    } RedfishNetworkDeviceFunction_V1_0_0_BootTargets_Array_CS;



## NetworkDeviceFunction
    typedef struct _RedfishNetworkDeviceFunction_V1_0_0_NetworkDeviceFunction_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishCS_Link AssignablePhysicalPorts;
        RedfishCS_int64 *AssignablePhysicalPortsodata_count;
        RedfishCS_char *AssignablePhysicalPortsodata_navigationLink;
        RedfishCS_char *BootMode;
        RedfishCS_char *Description;
        RedfishCS_bool *DeviceEnabled;
        RedfishNetworkDeviceFunction_V1_0_0_Ethernet_CS *Ethernet;
        RedfishNetworkDeviceFunction_V1_0_0_FibreChannel_CS *FibreChannel;
        RedfishCS_char *Id;
        RedfishNetworkDeviceFunction_V1_0_0_Links_CS *Links;
        RedfishCS_int64 *MaxVirtualFunctions;
        RedfishCS_char *Name;
        RedfishCS_char *NetDevFuncCapabilities;
        RedfishCS_char *NetDevFuncType;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_Link PhysicalPortAssignment;
        RedfishResource_Status_CS *Status;
        RedfishCS_bool *VirtualFunctionsEnabled;
        RedfishNetworkDeviceFunction_V1_0_0_iSCSIBoot_CS *iSCSIBoot;
    } RedfishNetworkDeviceFunction_V1_0_0_NetworkDeviceFunction_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**AssignablePhysicalPorts**|RedfishCS_Link| Structure link list to **AssignablePhysicalPorts** property.| No| Yes
|**AssignablePhysicalPortsodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **AssignablePhysicalPorts@odata.count** property.| No| No
|**AssignablePhysicalPortsodata_navigationLink**|RedfishCS_char| String pointer to **AssignablePhysicalPorts@odata.navigationLink** property.| No| No
|**BootMode**|RedfishCS_char| String pointer to **BootMode** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**DeviceEnabled**|RedfishCS_bool| Boolean pointer to **DeviceEnabled** property.| No| No
|**Ethernet**|RedfishNetworkDeviceFunction_V1_0_0_Ethernet_CS| Structure points to **Ethernet** property.| No| No
|**FibreChannel**|RedfishNetworkDeviceFunction_V1_0_0_FibreChannel_CS| Structure points to **FibreChannel** property.| No| No
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**Links**|RedfishNetworkDeviceFunction_V1_0_0_Links_CS| Structure points to **Links** property.| No| No
|**MaxVirtualFunctions**|RedfishCS_int64| 64-bit long long interger pointer to **MaxVirtualFunctions** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**NetDevFuncCapabilities**|RedfishCS_char| String pointer to **NetDevFuncCapabilities** property.| No| Yes
|**NetDevFuncType**|RedfishCS_char| String pointer to **NetDevFuncType** property.| No| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PhysicalPortAssignment**|RedfishCS_Link| Structure link list to **PhysicalPortAssignment** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**VirtualFunctionsEnabled**|RedfishCS_bool| Boolean pointer to **VirtualFunctionsEnabled** property.| No| Yes
|**iSCSIBoot**|RedfishNetworkDeviceFunction_V1_0_0_iSCSIBoot_CS| Structure points to **iSCSIBoot** property.| No| No
## Redfish NetworkDeviceFunction V1_0_0 to C Structure Function
    RedfishCS_status
    Json_NetworkDeviceFunction_V1_0_0_To_CS (RedfishCS_char *JsonRawText, RedfishNetworkDeviceFunction_V1_0_0_NetworkDeviceFunction_CS **ReturnedCS);

## C Structure to Redfish NetworkDeviceFunction V1_0_0 JSON Function
    RedfishCS_status
    CS_To_NetworkDeviceFunction_V1_0_0_JSON (RedfishNetworkDeviceFunction_V1_0_0_NetworkDeviceFunction_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish NetworkDeviceFunction V1_0_0 C Structure Function
    RedfishCS_status
    DestroyNetworkDeviceFunction_V1_0_0_CS (RedfishNetworkDeviceFunction_V1_0_0_NetworkDeviceFunction_CS *CSPtr);

