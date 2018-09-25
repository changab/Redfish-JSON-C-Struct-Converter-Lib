# Definition of Thermal.V1_1_3 and functions<br><br>

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


## Fan
    typedef struct _RedfishThermal_V1_1_3_Fan_CS {
        RedfishCS_char *FanName;
        RedfishCS_int64 *LowerThresholdCritical;
        RedfishCS_int64 *LowerThresholdFatal;
        RedfishCS_int64 *LowerThresholdNonCritical;
        RedfishCS_int64 *MaxReadingRange;
        RedfishCS_char *MemberId;
        RedfishCS_int64 *MinReadingRange;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_Link PhysicalContext;
        RedfishCS_int64 *Reading;
        RedfishCS_char *ReadingUnits;
        RedfishCS_Link Redundancy;
        RedfishCS_int64 *Redundancyodata_count;
        RedfishCS_char *Redundancyodata_navigationLink;
        Redfishodata_V4_0_0_idRef_Array_CS *RelatedItem;
        RedfishCS_int64 *RelatedItemodata_count;
        RedfishCS_char *RelatedItemodata_navigationLink;
        RedfishResource_Status_CS *Status;
        RedfishCS_int64 *UpperThresholdCritical;
        RedfishCS_int64 *UpperThresholdFatal;
        RedfishCS_int64 *UpperThresholdNonCritical;
    } RedfishThermal_V1_1_3_Fan_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**FanName**|RedfishCS_char| String pointer to **FanName** property.| No| Yes
|**LowerThresholdCritical**|RedfishCS_int64| 64-bit long long interger pointer to **LowerThresholdCritical** property.| No| Yes
|**LowerThresholdFatal**|RedfishCS_int64| 64-bit long long interger pointer to **LowerThresholdFatal** property.| No| Yes
|**LowerThresholdNonCritical**|RedfishCS_int64| 64-bit long long interger pointer to **LowerThresholdNonCritical** property.| No| Yes
|**MaxReadingRange**|RedfishCS_int64| 64-bit long long interger pointer to **MaxReadingRange** property.| No| Yes
|**MemberId**|RedfishCS_char| String pointer to **MemberId** property.| No| Yes
|**MinReadingRange**|RedfishCS_int64| 64-bit long long interger pointer to **MinReadingRange** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PhysicalContext**|RedfishCS_Link| Structure link list to **PhysicalContext** property.| No| Yes
|**Reading**|RedfishCS_int64| 64-bit long long interger pointer to **Reading** property.| No| Yes
|**ReadingUnits**|RedfishCS_char| String pointer to **ReadingUnits** property.| No| Yes
|**Redundancy**|RedfishCS_Link| Structure link list to **Redundancy** property.| No| No
|**Redundancyodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Redundancy@odata.count** property.| No| No
|**Redundancyodata_navigationLink**|RedfishCS_char| String pointer to **Redundancy@odata.navigationLink** property.| No| No
|**RelatedItem**|Redfishodata_V4_0_0_idRef_Array_CS| Structure array points to one or more than one **Redfishodata_V4_0_0_idRef_Array_CS** structures for property **RelatedItem**.| No| Yes
|**RelatedItemodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **RelatedItem@odata.count** property.| No| No
|**RelatedItemodata_navigationLink**|RedfishCS_char| String pointer to **RelatedItem@odata.navigationLink** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**UpperThresholdCritical**|RedfishCS_int64| 64-bit long long interger pointer to **UpperThresholdCritical** property.| No| Yes
|**UpperThresholdFatal**|RedfishCS_int64| 64-bit long long interger pointer to **UpperThresholdFatal** property.| No| Yes
|**UpperThresholdNonCritical**|RedfishCS_int64| 64-bit long long interger pointer to **UpperThresholdNonCritical** property.| No| Yes


## Temperature
    typedef struct _RedfishThermal_V1_1_3_Temperature_CS {
        RedfishCS_int64 *LowerThresholdCritical;
        RedfishCS_int64 *LowerThresholdFatal;
        RedfishCS_int64 *LowerThresholdNonCritical;
        RedfishCS_int64 *MaxReadingRangeTemp;
        RedfishCS_char *MemberId;
        RedfishCS_int64 *MinReadingRangeTemp;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_Link PhysicalContext;
        RedfishCS_int64 *ReadingCelsius;
        Redfishodata_V4_0_0_idRef_Array_CS *RelatedItem;
        RedfishCS_int64 *RelatedItemodata_count;
        RedfishCS_char *RelatedItemodata_navigationLink;
        RedfishCS_int64 *SensorNumber;
        RedfishResource_Status_CS *Status;
        RedfishCS_int64 *UpperThresholdCritical;
        RedfishCS_int64 *UpperThresholdFatal;
        RedfishCS_int64 *UpperThresholdNonCritical;
    } RedfishThermal_V1_1_3_Temperature_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**LowerThresholdCritical**|RedfishCS_int64| 64-bit long long interger pointer to **LowerThresholdCritical** property.| No| Yes
|**LowerThresholdFatal**|RedfishCS_int64| 64-bit long long interger pointer to **LowerThresholdFatal** property.| No| Yes
|**LowerThresholdNonCritical**|RedfishCS_int64| 64-bit long long interger pointer to **LowerThresholdNonCritical** property.| No| Yes
|**MaxReadingRangeTemp**|RedfishCS_int64| 64-bit long long interger pointer to **MaxReadingRangeTemp** property.| No| Yes
|**MemberId**|RedfishCS_char| String pointer to **MemberId** property.| No| Yes
|**MinReadingRangeTemp**|RedfishCS_int64| 64-bit long long interger pointer to **MinReadingRangeTemp** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PhysicalContext**|RedfishCS_Link| Structure link list to **PhysicalContext** property.| No| Yes
|**ReadingCelsius**|RedfishCS_int64| 64-bit long long interger pointer to **ReadingCelsius** property.| No| Yes
|**RelatedItem**|Redfishodata_V4_0_0_idRef_Array_CS| Structure array points to one or more than one **Redfishodata_V4_0_0_idRef_Array_CS** structures for property **RelatedItem**.| No| Yes
|**RelatedItemodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **RelatedItem@odata.count** property.| No| No
|**RelatedItemodata_navigationLink**|RedfishCS_char| String pointer to **RelatedItem@odata.navigationLink** property.| No| No
|**SensorNumber**|RedfishCS_int64| 64-bit long long interger pointer to **SensorNumber** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**UpperThresholdCritical**|RedfishCS_int64| 64-bit long long interger pointer to **UpperThresholdCritical** property.| No| Yes
|**UpperThresholdFatal**|RedfishCS_int64| 64-bit long long interger pointer to **UpperThresholdFatal** property.| No| Yes
|**UpperThresholdNonCritical**|RedfishCS_int64| 64-bit long long interger pointer to **UpperThresholdNonCritical** property.| No| Yes


## idRef
    typedef struct _Redfishodata_V4_0_0_idRef_CS {
        RedfishCS_char *odata_id;
    } Redfishodata_V4_0_0_idRef_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No


## Redfishodata_V4_0_0_idRef_Array_CS
    typedef struct _Redfishodata_V4_0_0_idRef_Array_CS  {
        RedfishCS_Link *Next;
        Redfishodata_V4_0_0_idRef_CS *ArrayValue;
    } Redfishodata_V4_0_0_idRef_Array_CS;



## Thermal
    typedef struct _RedfishThermal_V1_1_3_Thermal_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishCS_char *Description;
        RedfishThermal_V1_1_3_Fan_CS *Fans;
        RedfishCS_int64 *Fansodata_count;
        RedfishCS_char *Fansodata_navigationLink;
        RedfishCS_char *Id;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_Link Redundancy;
        RedfishCS_int64 *Redundancyodata_count;
        RedfishCS_char *Redundancyodata_navigationLink;
        RedfishResource_Status_CS *Status;
        RedfishThermal_V1_1_3_Temperature_CS *Temperatures;
        RedfishCS_int64 *Temperaturesodata_count;
        RedfishCS_char *Temperaturesodata_navigationLink;
    } RedfishThermal_V1_1_3_Thermal_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Fans**|RedfishThermal_V1_1_3_Fan_CS| Structure points to **Fans** property.| No| No
|**Fansodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Fans@odata.count** property.| No| No
|**Fansodata_navigationLink**|RedfishCS_char| String pointer to **Fans@odata.navigationLink** property.| No| No
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**Redundancy**|RedfishCS_Link| Structure link list to **Redundancy** property.| No| No
|**Redundancyodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Redundancy@odata.count** property.| No| No
|**Redundancyodata_navigationLink**|RedfishCS_char| String pointer to **Redundancy@odata.navigationLink** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**Temperatures**|RedfishThermal_V1_1_3_Temperature_CS| Structure points to **Temperatures** property.| No| No
|**Temperaturesodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Temperatures@odata.count** property.| No| No
|**Temperaturesodata_navigationLink**|RedfishCS_char| String pointer to **Temperatures@odata.navigationLink** property.| No| No
## Redfish Thermal V1_1_3 to C Structure Function
    RedfishCS_status
    Json_Thermal_V1_1_3_To_CS (RedfishCS_char *JsonRawText, RedfishThermal_V1_1_3_Thermal_CS **ReturnedCS);

## C Structure to Redfish Thermal V1_1_3 JSON Function
    RedfishCS_status
    CS_To_Thermal_V1_1_3_JSON (RedfishThermal_V1_1_3_Thermal_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish Thermal V1_1_3 C Structure Function
    RedfishCS_status
    DestroyThermal_V1_1_3_CS (RedfishThermal_V1_1_3_Thermal_CS *CSPtr);

