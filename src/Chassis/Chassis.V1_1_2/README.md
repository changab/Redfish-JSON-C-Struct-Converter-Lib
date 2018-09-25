# Definition of Chassis.V1_1_2 and functions<br><br>

## Chassis_Actions
    typedef struct _RedfishChassis_V1_1_2_Chassis_Actions_CS {
        RedfishChassis_V1_1_2_Reset_CS *Chassis_Reset;
        RedfishChassis_V1_1_2_Chassis_Actions_Oem_CS *Oem;
    } RedfishChassis_V1_1_2_Chassis_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Chassis_Reset**|RedfishChassis_V1_1_2_Reset_CS| Structure points to **#Chassis.Reset** property.| No| No
|**Oem**|RedfishChassis_V1_1_2_Chassis_Actions_Oem_CS| Structure points to **Oem** property.| No| No


## Chassis_Actions_Oem
    typedef struct _RedfishChassis_V1_1_2_Chassis_Actions_Oem_CS {
        RedfishCS_Link Prop;
    } RedfishChassis_V1_1_2_Chassis_Actions_Oem_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## Chassis_Links
    typedef struct _RedfishChassis_V1_1_2_Chassis_Links_CS {
        RedfishCS_Link ComputerSystems;
        RedfishCS_int64 *ComputerSystemsodata_count;
        RedfishCS_char *ComputerSystemsodata_navigationLink;
        RedfishCS_Link ContainedBy;
        RedfishCS_Link Contains;
        RedfishCS_int64 *Containsodata_count;
        RedfishCS_char *Containsodata_navigationLink;
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
    } RedfishChassis_V1_1_2_Chassis_Links_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**ComputerSystems**|RedfishCS_Link| Structure link list to **ComputerSystems** property.| No| Yes
|**ComputerSystemsodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **ComputerSystems@odata.count** property.| No| No
|**ComputerSystemsodata_navigationLink**|RedfishCS_char| String pointer to **ComputerSystems@odata.navigationLink** property.| No| No
|**ContainedBy**|RedfishCS_Link| Structure link list to **ContainedBy** property.| No| Yes
|**Contains**|RedfishCS_Link| Structure link list to **Contains** property.| No| Yes
|**Containsodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Contains@odata.count** property.| No| No
|**Containsodata_navigationLink**|RedfishCS_char| String pointer to **Contains@odata.navigationLink** property.| No| No
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


## PhysicalSecurity
    typedef struct _RedfishChassis_V1_1_2_PhysicalSecurity_CS {
        RedfishCS_char *IntrusionSensor;
        RedfishCS_int64 *IntrusionSensorNumber;
        RedfishCS_char *IntrusionSensorReArm;
    } RedfishChassis_V1_1_2_PhysicalSecurity_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**IntrusionSensor**|RedfishCS_char| String pointer to **IntrusionSensor** property.| No| No
|**IntrusionSensorNumber**|RedfishCS_int64| 64-bit long long interger pointer to **IntrusionSensorNumber** property.| No| Yes
|**IntrusionSensorReArm**|RedfishCS_char| String pointer to **IntrusionSensorReArm** property.| No| Yes


## Reset
    typedef struct _RedfishChassis_V1_1_2_Reset_CS {
        RedfishCS_char *target;
        RedfishCS_char *title;
    } RedfishChassis_V1_1_2_Reset_CS;

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


## idRef
    typedef struct _Redfishodata_V4_0_0_idRef_CS {
        RedfishCS_char *odata_id;
    } Redfishodata_V4_0_0_idRef_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No


## Chassis
    typedef struct _RedfishChassis_V1_1_2_Chassis_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishChassis_V1_1_2_Chassis_Actions_CS *Actions;
        RedfishCS_char *AssetTag;
        RedfishCS_char *ChassisType;
        RedfishCS_char *Description;
        RedfishCS_char *Id;
        RedfishCS_char *IndicatorLED;
        RedfishChassis_V1_1_2_Chassis_Links_CS *Links;
        RedfishCS_Link LogServices;
        RedfishCS_char *Manufacturer;
        RedfishCS_char *Model;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *PartNumber;
        RedfishChassis_V1_1_2_PhysicalSecurity_CS *PhysicalSecurity;
        RedfishCS_Link Power;
        RedfishCS_char *PowerState;
        RedfishCS_char *SKU;
        RedfishCS_char *SerialNumber;
        RedfishResource_Status_CS *Status;
        RedfishCS_Link Thermal;
    } RedfishChassis_V1_1_2_Chassis_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Actions**|RedfishChassis_V1_1_2_Chassis_Actions_CS| Structure points to **Actions** property.| No| Yes
|**AssetTag**|RedfishCS_char| String pointer to **AssetTag** property.| No| No
|**ChassisType**|RedfishCS_char| String pointer to **ChassisType** property.| Yes| Yes
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| No
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| No
|**IndicatorLED**|RedfishCS_char| String pointer to **IndicatorLED** property.| No| No
|**Links**|RedfishChassis_V1_1_2_Chassis_Links_CS| Structure points to **Links** property.| No| Yes
|**LogServices**|RedfishCS_Link| Structure link list to **LogServices** property.| No| Yes
|**Manufacturer**|RedfishCS_char| String pointer to **Manufacturer** property.| No| Yes
|**Model**|RedfishCS_char| String pointer to **Model** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PartNumber**|RedfishCS_char| String pointer to **PartNumber** property.| No| Yes
|**PhysicalSecurity**|RedfishChassis_V1_1_2_PhysicalSecurity_CS| Structure points to **PhysicalSecurity** property.| No| No
|**Power**|RedfishCS_Link| Structure link list to **Power** property.| No| Yes
|**PowerState**|RedfishCS_char| String pointer to **PowerState** property.| No| Yes
|**SKU**|RedfishCS_char| String pointer to **SKU** property.| No| Yes
|**SerialNumber**|RedfishCS_char| String pointer to **SerialNumber** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**Thermal**|RedfishCS_Link| Structure link list to **Thermal** property.| No| Yes
## Redfish Chassis V1_1_2 to C Structure Function
    RedfishCS_status
    Json_Chassis_V1_1_2_To_CS (RedfishCS_char *JsonRawText, RedfishChassis_V1_1_2_Chassis_CS **ReturnedCS);

## C Structure to Redfish Chassis V1_1_2 JSON Function
    RedfishCS_status
    CS_To_Chassis_V1_1_2_JSON (RedfishChassis_V1_1_2_Chassis_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish Chassis V1_1_2 C Structure Function
    RedfishCS_status
    DestroyChassis_V1_1_2_CS (RedfishChassis_V1_1_2_Chassis_CS *CSPtr);

