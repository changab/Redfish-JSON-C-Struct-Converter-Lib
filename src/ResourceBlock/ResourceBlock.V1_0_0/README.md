# Definition of ResourceBlock.V1_0_0 and functions<br><br>

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


## CompositionStatus
    typedef struct _RedfishResourceBlock_V1_0_0_CompositionStatus_CS {
        RedfishCS_char *CompositionState;
        RedfishCS_bool *Reserved;
    } RedfishResourceBlock_V1_0_0_CompositionStatus_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**CompositionState**|RedfishCS_char| String pointer to **CompositionState** property.| No| Yes
|**Reserved**|RedfishCS_bool| Boolean pointer to **Reserved** property.| No| No


## ResourceBlock_Actions
    typedef struct _RedfishResourceBlock_V1_0_0_ResourceBlock_Actions_CS {
        RedfishResourceBlock_V1_0_0_ResourceBlock_Actions_Oem_CS *Oem;
    } RedfishResourceBlock_V1_0_0_ResourceBlock_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Oem**|RedfishResourceBlock_V1_0_0_ResourceBlock_Actions_Oem_CS| Structure points to **Oem** property.| No| No


## ResourceBlock_Actions_Oem
    typedef struct _RedfishResourceBlock_V1_0_0_ResourceBlock_Actions_Oem_CS {
        RedfishCS_Link Prop;
    } RedfishResourceBlock_V1_0_0_ResourceBlock_Actions_Oem_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## ResourceBlock_Links
    typedef struct _RedfishResourceBlock_V1_0_0_ResourceBlock_Links_CS {
        RedfishCS_Link Chassis;
        RedfishCS_int64 *Chassisodata_count;
        RedfishCS_char *Chassisodata_navigationLink;
        RedfishCS_Link ComputerSystems;
        RedfishCS_int64 *ComputerSystemsodata_count;
        RedfishCS_char *ComputerSystemsodata_navigationLink;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_Link Zones;
        RedfishCS_int64 *Zonesodata_count;
        RedfishCS_char *Zonesodata_navigationLink;
    } RedfishResourceBlock_V1_0_0_ResourceBlock_Links_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Chassis**|RedfishCS_Link| Structure link list to **Chassis** property.| No| Yes
|**Chassisodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Chassis@odata.count** property.| No| No
|**Chassisodata_navigationLink**|RedfishCS_char| String pointer to **Chassis@odata.navigationLink** property.| No| No
|**ComputerSystems**|RedfishCS_Link| Structure link list to **ComputerSystems** property.| No| Yes
|**ComputerSystemsodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **ComputerSystems@odata.count** property.| No| No
|**ComputerSystemsodata_navigationLink**|RedfishCS_char| String pointer to **ComputerSystems@odata.navigationLink** property.| No| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**Zones**|RedfishCS_Link| Structure link list to **Zones** property.| No| Yes
|**Zonesodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Zones@odata.count** property.| No| No
|**Zonesodata_navigationLink**|RedfishCS_char| String pointer to **Zones@odata.navigationLink** property.| No| No


## ResourceBlock
    typedef struct _RedfishResourceBlock_V1_0_0_ResourceBlock_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishResourceBlock_V1_0_0_ResourceBlock_Actions_CS *Actions;
        RedfishResourceBlock_V1_0_0_CompositionStatus_CS *CompositionStatus;
        RedfishCS_Link ComputerSystems;
        RedfishCS_int64 *ComputerSystemsodata_count;
        RedfishCS_char *ComputerSystemsodata_navigationLink;
        RedfishCS_char *Description;
        RedfishCS_Link EthernetInterfaces;
        RedfishCS_int64 *EthernetInterfacesodata_count;
        RedfishCS_char *EthernetInterfacesodata_navigationLink;
        RedfishCS_char *Id;
        RedfishResourceBlock_V1_0_0_ResourceBlock_Links_CS *Links;
        RedfishCS_Link Memory;
        RedfishCS_int64 *Memoryodata_count;
        RedfishCS_char *Memoryodata_navigationLink;
        RedfishCS_char *Name;
        RedfishCS_Link NetworkInterfaces;
        RedfishCS_int64 *NetworkInterfacesodata_count;
        RedfishCS_char *NetworkInterfacesodata_navigationLink;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_Link Processors;
        RedfishCS_int64 *Processorsodata_count;
        RedfishCS_char *Processorsodata_navigationLink;
        RedfishCS_char *ResourceBlockType;
        RedfishCS_Link SimpleStorage;
        RedfishCS_int64 *SimpleStorageodata_count;
        RedfishCS_char *SimpleStorageodata_navigationLink;
        RedfishResource_Status_CS *Status;
        RedfishCS_Link Storage;
        RedfishCS_int64 *Storageodata_count;
        RedfishCS_char *Storageodata_navigationLink;
    } RedfishResourceBlock_V1_0_0_ResourceBlock_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Actions**|RedfishResourceBlock_V1_0_0_ResourceBlock_Actions_CS| Structure points to **Actions** property.| No| No
|**CompositionStatus**|RedfishResourceBlock_V1_0_0_CompositionStatus_CS| Structure points to **CompositionStatus** property.| Yes| No
|**ComputerSystems**|RedfishCS_Link| Structure link list to **ComputerSystems** property.| No| Yes
|**ComputerSystemsodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **ComputerSystems@odata.count** property.| No| No
|**ComputerSystemsodata_navigationLink**|RedfishCS_char| String pointer to **ComputerSystems@odata.navigationLink** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**EthernetInterfaces**|RedfishCS_Link| Structure link list to **EthernetInterfaces** property.| No| Yes
|**EthernetInterfacesodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **EthernetInterfaces@odata.count** property.| No| No
|**EthernetInterfacesodata_navigationLink**|RedfishCS_char| String pointer to **EthernetInterfaces@odata.navigationLink** property.| No| No
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**Links**|RedfishResourceBlock_V1_0_0_ResourceBlock_Links_CS| Structure points to **Links** property.| No| No
|**Memory**|RedfishCS_Link| Structure link list to **Memory** property.| No| Yes
|**Memoryodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Memory@odata.count** property.| No| No
|**Memoryodata_navigationLink**|RedfishCS_char| String pointer to **Memory@odata.navigationLink** property.| No| No
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**NetworkInterfaces**|RedfishCS_Link| Structure link list to **NetworkInterfaces** property.| No| Yes
|**NetworkInterfacesodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **NetworkInterfaces@odata.count** property.| No| No
|**NetworkInterfacesodata_navigationLink**|RedfishCS_char| String pointer to **NetworkInterfaces@odata.navigationLink** property.| No| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**Processors**|RedfishCS_Link| Structure link list to **Processors** property.| No| Yes
|**Processorsodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Processors@odata.count** property.| No| No
|**Processorsodata_navigationLink**|RedfishCS_char| String pointer to **Processors@odata.navigationLink** property.| No| No
|**ResourceBlockType**|RedfishCS_char| String pointer to **ResourceBlockType** property.| Yes| Yes
|**SimpleStorage**|RedfishCS_Link| Structure link list to **SimpleStorage** property.| No| Yes
|**SimpleStorageodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **SimpleStorage@odata.count** property.| No| No
|**SimpleStorageodata_navigationLink**|RedfishCS_char| String pointer to **SimpleStorage@odata.navigationLink** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**Storage**|RedfishCS_Link| Structure link list to **Storage** property.| No| Yes
|**Storageodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Storage@odata.count** property.| No| No
|**Storageodata_navigationLink**|RedfishCS_char| String pointer to **Storage@odata.navigationLink** property.| No| No
## Redfish ResourceBlock V1_0_0 to C Structure Function
    RedfishCS_status
    Json_ResourceBlock_V1_0_0_To_CS (RedfishCS_char *JsonRawText, RedfishResourceBlock_V1_0_0_ResourceBlock_CS **ReturnedCS);

## C Structure to Redfish ResourceBlock V1_0_0 JSON Function
    RedfishCS_status
    CS_To_ResourceBlock_V1_0_0_JSON (RedfishResourceBlock_V1_0_0_ResourceBlock_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish ResourceBlock V1_0_0 C Structure Function
    RedfishCS_status
    DestroyResourceBlock_V1_0_0_CS (RedfishResourceBlock_V1_0_0_ResourceBlock_CS *CSPtr);

