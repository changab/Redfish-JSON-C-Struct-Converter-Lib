# Definition of NetworkAdapter.V1_0_1 and functions<br><br>

## ControllerCapabilities
    typedef struct _RedfishNetworkAdapter_V1_0_1_ControllerCapabilities_CS {
        RedfishNetworkAdapter_V1_0_1_DataCenterBridging_CS *DataCenterBridging;
        RedfishNetworkAdapter_V1_0_1_NPIV_CS *NPIV;
        RedfishCS_int64 *NetworkDeviceFunctionCount;
        RedfishCS_int64 *NetworkPortCount;
        RedfishNetworkAdapter_V1_0_1_VirtualizationOffload_CS *VirtualizationOffload;
    } RedfishNetworkAdapter_V1_0_1_ControllerCapabilities_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**DataCenterBridging**|RedfishNetworkAdapter_V1_0_1_DataCenterBridging_CS| Structure points to **DataCenterBridging** property.| No| No
|**NPIV**|RedfishNetworkAdapter_V1_0_1_NPIV_CS| Structure points to **NPIV** property.| No| No
|**NetworkDeviceFunctionCount**|RedfishCS_int64| 64-bit long long interger pointer to **NetworkDeviceFunctionCount** property.| No| Yes
|**NetworkPortCount**|RedfishCS_int64| 64-bit long long interger pointer to **NetworkPortCount** property.| No| Yes
|**VirtualizationOffload**|RedfishNetworkAdapter_V1_0_1_VirtualizationOffload_CS| Structure points to **VirtualizationOffload** property.| No| No


## Controllers
    typedef struct _RedfishNetworkAdapter_V1_0_1_Controllers_CS {
        RedfishNetworkAdapter_V1_0_1_ControllerCapabilities_CS *ControllerCapabilities;
        RedfishCS_char *FirmwarePackageVersion;
        RedfishNetworkAdapter_V1_0_1_Controllers_Links_CS *Links;
    } RedfishNetworkAdapter_V1_0_1_Controllers_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**ControllerCapabilities**|RedfishNetworkAdapter_V1_0_1_ControllerCapabilities_CS| Structure points to **ControllerCapabilities** property.| No| No
|**FirmwarePackageVersion**|RedfishCS_char| String pointer to **FirmwarePackageVersion** property.| No| Yes
|**Links**|RedfishNetworkAdapter_V1_0_1_Controllers_Links_CS| Structure points to **Links** property.| No| No


## Controllers_Links
    typedef struct _RedfishNetworkAdapter_V1_0_1_Controllers_Links_CS {
        RedfishCS_Link NetworkDeviceFunctions;
        RedfishCS_int64 *NetworkDeviceFunctionsodata_count;
        RedfishCS_char *NetworkDeviceFunctionsodata_navigationLink;
        RedfishCS_Link NetworkPorts;
        RedfishCS_int64 *NetworkPortsodata_count;
        RedfishCS_char *NetworkPortsodata_navigationLink;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_Link PCIeDevices;
        RedfishCS_int64 *PCIeDevicesodata_count;
        RedfishCS_char *PCIeDevicesodata_navigationLink;
    } RedfishNetworkAdapter_V1_0_1_Controllers_Links_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**NetworkDeviceFunctions**|RedfishCS_Link| Structure link list to **NetworkDeviceFunctions** property.| No| Yes
|**NetworkDeviceFunctionsodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **NetworkDeviceFunctions@odata.count** property.| No| No
|**NetworkDeviceFunctionsodata_navigationLink**|RedfishCS_char| String pointer to **NetworkDeviceFunctions@odata.navigationLink** property.| No| No
|**NetworkPorts**|RedfishCS_Link| Structure link list to **NetworkPorts** property.| No| Yes
|**NetworkPortsodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **NetworkPorts@odata.count** property.| No| No
|**NetworkPortsodata_navigationLink**|RedfishCS_char| String pointer to **NetworkPorts@odata.navigationLink** property.| No| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PCIeDevices**|RedfishCS_Link| Structure link list to **PCIeDevices** property.| No| Yes
|**PCIeDevicesodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **PCIeDevices@odata.count** property.| No| No
|**PCIeDevicesodata_navigationLink**|RedfishCS_char| String pointer to **PCIeDevices@odata.navigationLink** property.| No| No


## DataCenterBridging
    typedef struct _RedfishNetworkAdapter_V1_0_1_DataCenterBridging_CS {
        RedfishCS_bool *Capable;
    } RedfishNetworkAdapter_V1_0_1_DataCenterBridging_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Capable**|RedfishCS_bool| Boolean pointer to **Capable** property.| No| Yes


## NPIV
    typedef struct _RedfishNetworkAdapter_V1_0_1_NPIV_CS {
        RedfishCS_int64 *MaxDeviceLogins;
        RedfishCS_int64 *MaxPortLogins;
    } RedfishNetworkAdapter_V1_0_1_NPIV_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**MaxDeviceLogins**|RedfishCS_int64| 64-bit long long interger pointer to **MaxDeviceLogins** property.| No| Yes
|**MaxPortLogins**|RedfishCS_int64| 64-bit long long interger pointer to **MaxPortLogins** property.| No| Yes


## NetworkAdapter_Actions
    typedef struct _RedfishNetworkAdapter_V1_0_1_NetworkAdapter_Actions_CS {
        RedfishNetworkAdapter_V1_0_1_ResetSettingsToDefault_CS *NetworkAdapter_ResetSettingsToDefault;
        RedfishNetworkAdapter_V1_0_1_NetworkAdapter_Actions_Oem_CS *Oem;
    } RedfishNetworkAdapter_V1_0_1_NetworkAdapter_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**NetworkAdapter_ResetSettingsToDefault**|RedfishNetworkAdapter_V1_0_1_ResetSettingsToDefault_CS| Structure points to **#NetworkAdapter.ResetSettingsToDefault** property.| No| No
|**Oem**|RedfishNetworkAdapter_V1_0_1_NetworkAdapter_Actions_Oem_CS| Structure points to **Oem** property.| No| No


## NetworkAdapter_Actions_Oem
    typedef struct _RedfishNetworkAdapter_V1_0_1_NetworkAdapter_Actions_Oem_CS {
        RedfishCS_Link Prop;
    } RedfishNetworkAdapter_V1_0_1_NetworkAdapter_Actions_Oem_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## ResetSettingsToDefault
    typedef struct _RedfishNetworkAdapter_V1_0_1_ResetSettingsToDefault_CS {
        RedfishCS_char *target;
        RedfishCS_char *title;
    } RedfishNetworkAdapter_V1_0_1_ResetSettingsToDefault_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**target**|RedfishCS_char| String pointer to **target** property.| No| No
|**title**|RedfishCS_char| String pointer to **title** property.| No| No


## SRIOV
    typedef struct _RedfishNetworkAdapter_V1_0_1_SRIOV_CS {
        RedfishCS_bool *SRIOVVEPACapable;
    } RedfishNetworkAdapter_V1_0_1_SRIOV_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**SRIOVVEPACapable**|RedfishCS_bool| Boolean pointer to **SRIOVVEPACapable** property.| No| Yes


## VirtualFunction
    typedef struct _RedfishNetworkAdapter_V1_0_1_VirtualFunction_CS {
        RedfishCS_int64 *DeviceMaxCount;
        RedfishCS_int64 *MinAssignmentGroupSize;
        RedfishCS_int64 *NetworkPortMaxCount;
    } RedfishNetworkAdapter_V1_0_1_VirtualFunction_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**DeviceMaxCount**|RedfishCS_int64| 64-bit long long interger pointer to **DeviceMaxCount** property.| No| Yes
|**MinAssignmentGroupSize**|RedfishCS_int64| 64-bit long long interger pointer to **MinAssignmentGroupSize** property.| No| Yes
|**NetworkPortMaxCount**|RedfishCS_int64| 64-bit long long interger pointer to **NetworkPortMaxCount** property.| No| Yes


## VirtualizationOffload
    typedef struct _RedfishNetworkAdapter_V1_0_1_VirtualizationOffload_CS {
        RedfishNetworkAdapter_V1_0_1_SRIOV_CS *SRIOV;
        RedfishNetworkAdapter_V1_0_1_VirtualFunction_CS *VirtualFunction;
    } RedfishNetworkAdapter_V1_0_1_VirtualizationOffload_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**SRIOV**|RedfishNetworkAdapter_V1_0_1_SRIOV_CS| Structure points to **SRIOV** property.| No| No
|**VirtualFunction**|RedfishNetworkAdapter_V1_0_1_VirtualFunction_CS| Structure points to **VirtualFunction** property.| No| No


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


## NetworkAdapter
    typedef struct _RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishNetworkAdapter_V1_0_1_NetworkAdapter_Actions_CS *Actions;
        RedfishNetworkAdapter_V1_0_1_Controllers_CS *Controllers;
        RedfishCS_char *Description;
        RedfishCS_char *Id;
        RedfishCS_char *Manufacturer;
        RedfishCS_char *Model;
        RedfishCS_char *Name;
        RedfishCS_Link NetworkDeviceFunctions;
        RedfishCS_Link NetworkPorts;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *PartNumber;
        RedfishCS_char *SKU;
        RedfishCS_char *SerialNumber;
        RedfishResource_Status_CS *Status;
    } RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Actions**|RedfishNetworkAdapter_V1_0_1_NetworkAdapter_Actions_CS| Structure points to **Actions** property.| No| No
|**Controllers**|RedfishNetworkAdapter_V1_0_1_Controllers_CS| Structure points to **Controllers** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**Manufacturer**|RedfishCS_char| String pointer to **Manufacturer** property.| No| Yes
|**Model**|RedfishCS_char| String pointer to **Model** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**NetworkDeviceFunctions**|RedfishCS_Link| Structure link list to **NetworkDeviceFunctions** property.| No| Yes
|**NetworkPorts**|RedfishCS_Link| Structure link list to **NetworkPorts** property.| No| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PartNumber**|RedfishCS_char| String pointer to **PartNumber** property.| No| Yes
|**SKU**|RedfishCS_char| String pointer to **SKU** property.| No| Yes
|**SerialNumber**|RedfishCS_char| String pointer to **SerialNumber** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
## Redfish NetworkAdapter V1_0_1 to C Structure Function
    RedfishCS_status
    Json_NetworkAdapter_V1_0_1_To_CS (RedfishCS_char *JsonRawText, RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS **ReturnedCS);

## C Structure to Redfish NetworkAdapter V1_0_1 JSON Function
    RedfishCS_status
    CS_To_NetworkAdapter_V1_0_1_JSON (RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish NetworkAdapter V1_0_1 C Structure Function
    RedfishCS_status
    DestroyNetworkAdapter_V1_0_1_CS (RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS *CSPtr);

