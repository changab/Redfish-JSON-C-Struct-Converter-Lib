# Definition of Processor.V1_1_1 and functions<br><br>

## Actions
    typedef struct _RedfishProcessor_V1_1_1_Actions_CS {
        RedfishProcessor_V1_1_1_OemActions_CS *Oem;
    } RedfishProcessor_V1_1_1_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Oem**|RedfishProcessor_V1_1_1_OemActions_CS| Structure points to **Oem** property.| No| No


## Links
    typedef struct _RedfishProcessor_V1_1_1_Links_CS {
        RedfishCS_Link Chassis;
        RedfishResource_Oem_CS *Oem;
    } RedfishProcessor_V1_1_1_Links_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Chassis**|RedfishCS_Link| Structure link list to **Chassis** property.| No| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No


## OemActions
    typedef struct _RedfishProcessor_V1_1_1_OemActions_CS {
        RedfishCS_Link Prop;
    } RedfishProcessor_V1_1_1_OemActions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## ProcessorId
    typedef struct _RedfishProcessor_V1_1_1_ProcessorId_CS {
        RedfishCS_char *EffectiveFamily;
        RedfishCS_char *EffectiveModel;
        RedfishCS_char *IdentificationRegisters;
        RedfishCS_char *MicrocodeInfo;
        RedfishCS_char *Step;
        RedfishCS_char *VendorId;
    } RedfishProcessor_V1_1_1_ProcessorId_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**EffectiveFamily**|RedfishCS_char| String pointer to **EffectiveFamily** property.| No| Yes
|**EffectiveModel**|RedfishCS_char| String pointer to **EffectiveModel** property.| No| Yes
|**IdentificationRegisters**|RedfishCS_char| String pointer to **IdentificationRegisters** property.| No| Yes
|**MicrocodeInfo**|RedfishCS_char| String pointer to **MicrocodeInfo** property.| No| Yes
|**Step**|RedfishCS_char| String pointer to **Step** property.| No| Yes
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


## Processor
    typedef struct _RedfishProcessor_V1_1_1_Processor_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_etag;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishProcessor_V1_1_1_Actions_CS *Actions;
        RedfishCS_char *Description;
        RedfishCS_char *Id;
        RedfishCS_char *InstructionSet;
        RedfishProcessor_V1_1_1_Links_CS *Links;
        RedfishCS_char *Manufacturer;
        RedfishCS_int64 *MaxSpeedMHz;
        RedfishCS_char *Model;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *ProcessorArchitecture;
        RedfishProcessor_V1_1_1_ProcessorId_CS *ProcessorId;
        RedfishCS_char *ProcessorType;
        RedfishCS_char *Socket;
        RedfishResource_Status_CS *Status;
        RedfishCS_int64 *TotalCores;
        RedfishCS_int64 *TotalThreads;
    } RedfishProcessor_V1_1_1_Processor_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_etag**|RedfishCS_char| String pointer to **@odata.etag** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| Yes| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| Yes| No
|**Actions**|RedfishProcessor_V1_1_1_Actions_CS| Structure points to **Actions** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**InstructionSet**|RedfishCS_char| String pointer to **InstructionSet** property.| No| Yes
|**Links**|RedfishProcessor_V1_1_1_Links_CS| Structure points to **Links** property.| No| No
|**Manufacturer**|RedfishCS_char| String pointer to **Manufacturer** property.| No| Yes
|**MaxSpeedMHz**|RedfishCS_int64| 64-bit long long interger pointer to **MaxSpeedMHz** property.| No| Yes
|**Model**|RedfishCS_char| String pointer to **Model** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**ProcessorArchitecture**|RedfishCS_char| String pointer to **ProcessorArchitecture** property.| No| Yes
|**ProcessorId**|RedfishProcessor_V1_1_1_ProcessorId_CS| Structure points to **ProcessorId** property.| No| No
|**ProcessorType**|RedfishCS_char| String pointer to **ProcessorType** property.| No| Yes
|**Socket**|RedfishCS_char| String pointer to **Socket** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**TotalCores**|RedfishCS_int64| 64-bit long long interger pointer to **TotalCores** property.| No| Yes
|**TotalThreads**|RedfishCS_int64| 64-bit long long interger pointer to **TotalThreads** property.| No| Yes
## Redfish Processor V1_1_1 to C Structure Function
    RedfishCS_status
    Json_Processor_V1_1_1_To_CS (RedfishCS_char *JsonRawText, RedfishProcessor_V1_1_1_Processor_CS **ReturnedCS);

## C Structure to Redfish Processor V1_1_1 JSON Function
    RedfishCS_status
    CS_To_Processor_V1_1_1_JSON (RedfishProcessor_V1_1_1_Processor_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish Processor V1_1_1 C Structure Function
    RedfishCS_status
    DestroyProcessor_V1_1_1_CS (RedfishProcessor_V1_1_1_Processor_CS *CSPtr);

