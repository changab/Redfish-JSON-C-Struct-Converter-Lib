# Definition of Chassis.V1_3_5 and functions<br><br>

## Actions
    typedef struct _RedfishChassis_V1_3_5_Actions_CS {
        RedfishChassis_V1_3_5_Reset_CS *Chassis_Reset;
        RedfishChassis_V1_3_5_OemActions_CS *Oem;
    } RedfishChassis_V1_3_5_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Chassis_Reset**|RedfishChassis_V1_3_5_Reset_CS| Structure points to **#Chassis.Reset** property.| No| No
|**Oem**|RedfishChassis_V1_3_5_OemActions_CS| Structure points to **Oem** property.| No| No


## Links
    typedef struct _RedfishChassis_V1_3_5_Links_CS {
        RedfishCS_Link ComputerSystems;
        RedfishCS_int64 *ComputerSystemsodata_count;
        RedfishCS_Link ContainedBy;
        RedfishCS_Link Contains;
        RedfishCS_int64 *Containsodata_count;
        Redfishodata_V4_0_3_idRef_Array_CS *CooledBy;
        RedfishCS_int64 *CooledByodata_count;
        RedfishCS_Link Drives;
        RedfishCS_int64 *Drivesodata_count;
        RedfishCS_Link ManagedBy;
        RedfishCS_int64 *ManagedByodata_count;
        RedfishCS_Link ManagersInChassis;
        RedfishCS_int64 *ManagersInChassisodata_count;
        RedfishResource_Oem_CS *Oem;
        Redfishodata_V4_0_3_idRef_Array_CS *PoweredBy;
        RedfishCS_int64 *PoweredByodata_count;
        RedfishCS_Link Storage;
        RedfishCS_int64 *Storageodata_count;
    } RedfishChassis_V1_3_5_Links_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**ComputerSystems**|RedfishCS_Link| Structure link list to **ComputerSystems** property.| No| Yes
|**ComputerSystemsodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **ComputerSystems@odata.count** property.| No| No
|**ContainedBy**|RedfishCS_Link| Structure link list to **ContainedBy** property.| No| Yes
|**Contains**|RedfishCS_Link| Structure link list to **Contains** property.| No| Yes
|**Containsodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Contains@odata.count** property.| No| No
|**CooledBy**|Redfishodata_V4_0_3_idRef_Array_CS| Structure array points to one or more than one **Redfishodata_V4_0_3_idRef_Array_CS** structures for property **CooledBy**.| No| Yes
|**CooledByodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **CooledBy@odata.count** property.| No| No
|**Drives**|RedfishCS_Link| Structure link list to **Drives** property.| No| Yes
|**Drivesodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Drives@odata.count** property.| No| No
|**ManagedBy**|RedfishCS_Link| Structure link list to **ManagedBy** property.| No| Yes
|**ManagedByodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **ManagedBy@odata.count** property.| No| No
|**ManagersInChassis**|RedfishCS_Link| Structure link list to **ManagersInChassis** property.| No| Yes
|**ManagersInChassisodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **ManagersInChassis@odata.count** property.| No| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PoweredBy**|Redfishodata_V4_0_3_idRef_Array_CS| Structure array points to one or more than one **Redfishodata_V4_0_3_idRef_Array_CS** structures for property **PoweredBy**.| No| Yes
|**PoweredByodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **PoweredBy@odata.count** property.| No| No
|**Storage**|RedfishCS_Link| Structure link list to **Storage** property.| No| Yes
|**Storageodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Storage@odata.count** property.| No| No


## OemActions
    typedef struct _RedfishChassis_V1_3_5_OemActions_CS {
        RedfishCS_Link Prop;
    } RedfishChassis_V1_3_5_OemActions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## PhysicalSecurity
    typedef struct _RedfishChassis_V1_3_5_PhysicalSecurity_CS {
        RedfishCS_char *IntrusionSensor;
        RedfishCS_int64 *IntrusionSensorNumber;
        RedfishCS_char *IntrusionSensorReArm;
    } RedfishChassis_V1_3_5_PhysicalSecurity_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**IntrusionSensor**|RedfishCS_char| String pointer to **IntrusionSensor** property.| No| No
|**IntrusionSensorNumber**|RedfishCS_int64| 64-bit long long interger pointer to **IntrusionSensorNumber** property.| No| Yes
|**IntrusionSensorReArm**|RedfishCS_char| String pointer to **IntrusionSensorReArm** property.| No| Yes


## Reset
    typedef struct _RedfishChassis_V1_3_5_Reset_CS {
        RedfishCS_char *target;
        RedfishCS_char *title;
    } RedfishChassis_V1_3_5_Reset_CS;

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
    typedef struct _Redfishodata_V4_0_3_idRef_CS {
        RedfishCS_char *odata_id;
    } Redfishodata_V4_0_3_idRef_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| Yes| No


## Redfishodata_V4_0_3_idRef_Array_CS
    typedef struct _Redfishodata_V4_0_3_idRef_Array_CS  {
        RedfishCS_Link *Next;
        Redfishodata_V4_0_3_idRef_CS *ArrayValue;
    } Redfishodata_V4_0_3_idRef_Array_CS;



## Chassis
    typedef struct _RedfishChassis_V1_3_5_Chassis_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_etag;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishChassis_V1_3_5_Actions_CS *Actions;
        RedfishCS_char *AssetTag;
        RedfishCS_char *ChassisType;
        RedfishCS_char *Description;
        RedfishCS_char *Id;
        RedfishCS_char *IndicatorLED;
        RedfishChassis_V1_3_5_Links_CS *Links;
        RedfishCS_Link Location;
        RedfishCS_Link LogServices;
        RedfishCS_char *Manufacturer;
        RedfishCS_char *Model;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *PartNumber;
        RedfishChassis_V1_3_5_PhysicalSecurity_CS *PhysicalSecurity;
        RedfishCS_Link Power;
        RedfishCS_char *PowerState;
        RedfishCS_char *SKU;
        RedfishCS_char *SerialNumber;
        RedfishResource_Status_CS *Status;
        RedfishCS_Link Thermal;
    } RedfishChassis_V1_3_5_Chassis_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_etag**|RedfishCS_char| String pointer to **@odata.etag** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| Yes| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| Yes| No
|**Actions**|RedfishChassis_V1_3_5_Actions_CS| Structure points to **Actions** property.| No| No
|**AssetTag**|RedfishCS_char| String pointer to **AssetTag** property.| No| No
|**ChassisType**|RedfishCS_char| String pointer to **ChassisType** property.| Yes| Yes
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**IndicatorLED**|RedfishCS_char| String pointer to **IndicatorLED** property.| No| No
|**Links**|RedfishChassis_V1_3_5_Links_CS| Structure points to **Links** property.| No| No
|**Location**|RedfishCS_Link| Structure link list to **Location** property.| No| No
|**LogServices**|RedfishCS_Link| Structure link list to **LogServices** property.| No| Yes
|**Manufacturer**|RedfishCS_char| String pointer to **Manufacturer** property.| No| Yes
|**Model**|RedfishCS_char| String pointer to **Model** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PartNumber**|RedfishCS_char| String pointer to **PartNumber** property.| No| Yes
|**PhysicalSecurity**|RedfishChassis_V1_3_5_PhysicalSecurity_CS| Structure points to **PhysicalSecurity** property.| No| No
|**Power**|RedfishCS_Link| Structure link list to **Power** property.| No| Yes
|**PowerState**|RedfishCS_char| String pointer to **PowerState** property.| No| Yes
|**SKU**|RedfishCS_char| String pointer to **SKU** property.| No| Yes
|**SerialNumber**|RedfishCS_char| String pointer to **SerialNumber** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**Thermal**|RedfishCS_Link| Structure link list to **Thermal** property.| No| Yes
## Redfish Chassis V1_3_5 to C Structure Function
    RedfishCS_status
    Json_Chassis_V1_3_5_To_CS (RedfishCS_char *JsonRawText, RedfishChassis_V1_3_5_Chassis_CS **ReturnedCS);

## C Structure to Redfish Chassis V1_3_5 JSON Function
    RedfishCS_status
    CS_To_Chassis_V1_3_5_JSON (RedfishChassis_V1_3_5_Chassis_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish Chassis V1_3_5 C Structure Function
    RedfishCS_status
    DestroyChassis_V1_3_5_CS (RedfishChassis_V1_3_5_Chassis_CS *CSPtr);

