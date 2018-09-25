# Definition of ComputerSystem.V1_1_1 and functions<br><br>

## Boot
    typedef struct _RedfishComputerSystem_V1_1_1_Boot_CS {
        RedfishCS_char *BootSourceOverrideEnabled;
        RedfishCS_char *BootSourceOverrideMode;
        RedfishCS_char *BootSourceOverrideTarget;
        RedfishCS_char *UefiTargetBootSourceOverride;
    } RedfishComputerSystem_V1_1_1_Boot_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**BootSourceOverrideEnabled**|RedfishCS_char| String pointer to **BootSourceOverrideEnabled** property.| No| No
|**BootSourceOverrideMode**|RedfishCS_char| String pointer to **BootSourceOverrideMode** property.| No| No
|**BootSourceOverrideTarget**|RedfishCS_char| String pointer to **BootSourceOverrideTarget** property.| No| No
|**UefiTargetBootSourceOverride**|RedfishCS_char| String pointer to **UefiTargetBootSourceOverride** property.| No| No


## ComputerSystem_Actions
    typedef struct _RedfishComputerSystem_V1_1_1_ComputerSystem_Actions_CS {
        RedfishComputerSystem_V1_1_1_Reset_CS *ComputerSystem_Reset;
        RedfishComputerSystem_V1_1_1_ComputerSystem_Actions_Oem_CS *Oem;
    } RedfishComputerSystem_V1_1_1_ComputerSystem_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**ComputerSystem_Reset**|RedfishComputerSystem_V1_1_1_Reset_CS| Structure points to **#ComputerSystem.Reset** property.| No| No
|**Oem**|RedfishComputerSystem_V1_1_1_ComputerSystem_Actions_Oem_CS| Structure points to **Oem** property.| No| No


## ComputerSystem_Actions_Oem
    typedef struct _RedfishComputerSystem_V1_1_1_ComputerSystem_Actions_Oem_CS {
        RedfishCS_Link Prop;
    } RedfishComputerSystem_V1_1_1_ComputerSystem_Actions_Oem_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## ComputerSystem_Links
    typedef struct _RedfishComputerSystem_V1_1_1_ComputerSystem_Links_CS {
        RedfishCS_Link Chassis;
        RedfishCS_int64 *Chassisodata_count;
        RedfishCS_char *Chassisodata_navigationLink;
        Redfishodata_V4_0_0_idRef_CS *CooledBy;
        RedfishCS_int64 *CooledByodata_count;
        RedfishCS_char *CooledByodata_navigationLink;
        RedfishCS_Link ManagedBy;
        RedfishCS_int64 *ManagedByodata_count;
        RedfishCS_char *ManagedByodata_navigationLink;
        RedfishResource_Oem_CS *Oem;
        Redfishodata_V4_0_0_idRef_CS *PoweredBy;
        RedfishCS_int64 *PoweredByodata_count;
        RedfishCS_char *PoweredByodata_navigationLink;
    } RedfishComputerSystem_V1_1_1_ComputerSystem_Links_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Chassis**|RedfishCS_Link| Structure link list to **Chassis** property.| No| Yes
|**Chassisodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Chassis@odata.count** property.| No| No
|**Chassisodata_navigationLink**|RedfishCS_char| String pointer to **Chassis@odata.navigationLink** property.| No| No
|**CooledBy**|Redfishodata_V4_0_0_idRef_CS| Structure points to **CooledBy** property.| No| Yes
|**CooledByodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **CooledBy@odata.count** property.| No| No
|**CooledByodata_navigationLink**|RedfishCS_char| String pointer to **CooledBy@odata.navigationLink** property.| No| No
|**ManagedBy**|RedfishCS_Link| Structure link list to **ManagedBy** property.| No| Yes
|**ManagedByodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **ManagedBy@odata.count** property.| No| No
|**ManagedByodata_navigationLink**|RedfishCS_char| String pointer to **ManagedBy@odata.navigationLink** property.| No| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PoweredBy**|Redfishodata_V4_0_0_idRef_CS| Structure points to **PoweredBy** property.| No| Yes
|**PoweredByodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **PoweredBy@odata.count** property.| No| No
|**PoweredByodata_navigationLink**|RedfishCS_char| String pointer to **PoweredBy@odata.navigationLink** property.| No| No


## MemorySummary
    typedef struct _RedfishComputerSystem_V1_1_1_MemorySummary_CS {
        RedfishCS_char *MemoryMirroring;
        RedfishResource_Status_CS *Status;
        RedfishCS_int64 *TotalSystemMemoryGiB;
    } RedfishComputerSystem_V1_1_1_MemorySummary_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**MemoryMirroring**|RedfishCS_char| String pointer to **MemoryMirroring** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**TotalSystemMemoryGiB**|RedfishCS_int64| 64-bit long long interger pointer to **TotalSystemMemoryGiB** property.| No| Yes


## ProcessorSummary
    typedef struct _RedfishComputerSystem_V1_1_1_ProcessorSummary_CS {
        RedfishCS_int64 *Count;
        RedfishCS_char *Model;
        RedfishResource_Status_CS *Status;
    } RedfishComputerSystem_V1_1_1_ProcessorSummary_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Count**|RedfishCS_int64| 64-bit long long interger pointer to **Count** property.| No| Yes
|**Model**|RedfishCS_char| String pointer to **Model** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No


## Reset
    typedef struct _RedfishComputerSystem_V1_1_1_Reset_CS {
        RedfishCS_char *target;
        RedfishCS_char *title;
    } RedfishComputerSystem_V1_1_1_Reset_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**target**|RedfishCS_char| String pointer to **target** property.| No| No
|**title**|RedfishCS_char| String pointer to **title** property.| No| No


## TrustedModules
    typedef struct _RedfishComputerSystem_V1_1_1_TrustedModules_CS {
        RedfishCS_char *FirmwareVersion;
        RedfishCS_char *InterfaceType;
        RedfishResource_Oem_CS *Oem;
        RedfishResource_Status_CS *Status;
    } RedfishComputerSystem_V1_1_1_TrustedModules_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**FirmwareVersion**|RedfishCS_char| String pointer to **FirmwareVersion** property.| No| Yes
|**InterfaceType**|RedfishCS_char| String pointer to **InterfaceType** property.| No| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No


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


## idRef
    typedef struct _Redfishodata_V4_0_0_idRef_CS {
        RedfishCS_char *odata_id;
    } Redfishodata_V4_0_0_idRef_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No


## ComputerSystem
    typedef struct _RedfishComputerSystem_V1_1_1_ComputerSystem_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishComputerSystem_V1_1_1_ComputerSystem_Actions_CS *Actions;
        RedfishCS_char *AssetTag;
        RedfishCS_Link Bios;
        RedfishCS_char *BiosVersion;
        RedfishComputerSystem_V1_1_1_Boot_CS *Boot;
        RedfishCS_char *Description;
        RedfishCS_Link EthernetInterfaces;
        RedfishCS_char *HostName;
        RedfishCS_char *Id;
        RedfishCS_char *IndicatorLED;
        RedfishComputerSystem_V1_1_1_ComputerSystem_Links_CS *Links;
        RedfishCS_Link LogServices;
        RedfishCS_char *Manufacturer;
        RedfishCS_Link Memory;
        RedfishComputerSystem_V1_1_1_MemorySummary_CS *MemorySummary;
        RedfishCS_char *Model;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *PartNumber;
        RedfishCS_char *PowerState;
        RedfishComputerSystem_V1_1_1_ProcessorSummary_CS *ProcessorSummary;
        RedfishCS_Link Processors;
        RedfishCS_char *SKU;
        RedfishCS_Link SecureBoot;
        RedfishCS_char *SerialNumber;
        RedfishCS_Link SimpleStorage;
        RedfishResource_Status_CS *Status;
        RedfishCS_Link Storage;
        RedfishCS_char *SystemType;
        RedfishComputerSystem_V1_1_1_TrustedModules_CS *TrustedModules;
        RedfishCS_char *UUID;
    } RedfishComputerSystem_V1_1_1_ComputerSystem_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Actions**|RedfishComputerSystem_V1_1_1_ComputerSystem_Actions_CS| Structure points to **Actions** property.| No| Yes
|**AssetTag**|RedfishCS_char| String pointer to **AssetTag** property.| No| No
|**Bios**|RedfishCS_Link| Structure link list to **Bios** property.| No| Yes
|**BiosVersion**|RedfishCS_char| String pointer to **BiosVersion** property.| No| No
|**Boot**|RedfishComputerSystem_V1_1_1_Boot_CS| Structure points to **Boot** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| No
|**EthernetInterfaces**|RedfishCS_Link| Structure link list to **EthernetInterfaces** property.| No| Yes
|**HostName**|RedfishCS_char| String pointer to **HostName** property.| No| No
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| No
|**IndicatorLED**|RedfishCS_char| String pointer to **IndicatorLED** property.| No| No
|**Links**|RedfishComputerSystem_V1_1_1_ComputerSystem_Links_CS| Structure points to **Links** property.| No| Yes
|**LogServices**|RedfishCS_Link| Structure link list to **LogServices** property.| No| Yes
|**Manufacturer**|RedfishCS_char| String pointer to **Manufacturer** property.| No| Yes
|**Memory**|RedfishCS_Link| Structure link list to **Memory** property.| No| Yes
|**MemorySummary**|RedfishComputerSystem_V1_1_1_MemorySummary_CS| Structure points to **MemorySummary** property.| No| No
|**Model**|RedfishCS_char| String pointer to **Model** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PartNumber**|RedfishCS_char| String pointer to **PartNumber** property.| No| Yes
|**PowerState**|RedfishCS_char| String pointer to **PowerState** property.| No| Yes
|**ProcessorSummary**|RedfishComputerSystem_V1_1_1_ProcessorSummary_CS| Structure points to **ProcessorSummary** property.| No| No
|**Processors**|RedfishCS_Link| Structure link list to **Processors** property.| No| Yes
|**SKU**|RedfishCS_char| String pointer to **SKU** property.| No| Yes
|**SecureBoot**|RedfishCS_Link| Structure link list to **SecureBoot** property.| No| Yes
|**SerialNumber**|RedfishCS_char| String pointer to **SerialNumber** property.| No| Yes
|**SimpleStorage**|RedfishCS_Link| Structure link list to **SimpleStorage** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**Storage**|RedfishCS_Link| Structure link list to **Storage** property.| No| Yes
|**SystemType**|RedfishCS_char| String pointer to **SystemType** property.| No| Yes
|**TrustedModules**|RedfishComputerSystem_V1_1_1_TrustedModules_CS| Structure points to **TrustedModules** property.| No| No
|**UUID**|RedfishCS_char| String pointer to **UUID** property.| No| Yes
## Redfish ComputerSystem V1_1_1 to C Structure Function
    RedfishCS_status
    Json_ComputerSystem_V1_1_1_To_CS (RedfishCS_char *JsonRawText, RedfishComputerSystem_V1_1_1_ComputerSystem_CS **ReturnedCS);

## C Structure to Redfish ComputerSystem V1_1_1 JSON Function
    RedfishCS_status
    CS_To_ComputerSystem_V1_1_1_JSON (RedfishComputerSystem_V1_1_1_ComputerSystem_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish ComputerSystem V1_1_1 C Structure Function
    RedfishCS_status
    DestroyComputerSystem_V1_1_1_CS (RedfishComputerSystem_V1_1_1_ComputerSystem_CS *CSPtr);

