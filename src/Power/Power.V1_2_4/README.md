# Definition of Power.V1_2_4 and functions<br><br>

## InputRange
    typedef struct _RedfishPower_V1_2_4_InputRange_CS {
        RedfishCS_char *InputType;
        RedfishCS_int64 *MaximumFrequencyHz;
        RedfishCS_int64 *MaximumVoltage;
        RedfishCS_int64 *MinimumFrequencyHz;
        RedfishCS_int64 *MinimumVoltage;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_int64 *OutputWattage;
    } RedfishPower_V1_2_4_InputRange_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**InputType**|RedfishCS_char| String pointer to **InputType** property.| No| Yes
|**MaximumFrequencyHz**|RedfishCS_int64| 64-bit long long interger pointer to **MaximumFrequencyHz** property.| No| Yes
|**MaximumVoltage**|RedfishCS_int64| 64-bit long long interger pointer to **MaximumVoltage** property.| No| Yes
|**MinimumFrequencyHz**|RedfishCS_int64| 64-bit long long interger pointer to **MinimumFrequencyHz** property.| No| Yes
|**MinimumVoltage**|RedfishCS_int64| 64-bit long long interger pointer to **MinimumVoltage** property.| No| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**OutputWattage**|RedfishCS_int64| 64-bit long long interger pointer to **OutputWattage** property.| No| Yes


## PowerControl
    typedef struct _RedfishPower_V1_2_4_PowerControl_CS {
        RedfishCS_char *MemberId;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_int64 *PowerAllocatedWatts;
        RedfishCS_int64 *PowerAvailableWatts;
        RedfishCS_int64 *PowerCapacityWatts;
        RedfishCS_int64 *PowerConsumedWatts;
        RedfishPower_V1_2_4_PowerLimit_CS *PowerLimit;
        RedfishPower_V1_2_4_PowerMetric_CS *PowerMetrics;
        RedfishCS_int64 *PowerRequestedWatts;
        Redfishodata_V4_0_1_idRef_Array_CS *RelatedItem;
        RedfishCS_int64 *RelatedItemodata_count;
        RedfishResource_Status_CS *Status;
    } RedfishPower_V1_2_4_PowerControl_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**MemberId**|RedfishCS_char| String pointer to **MemberId** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PowerAllocatedWatts**|RedfishCS_int64| 64-bit long long interger pointer to **PowerAllocatedWatts** property.| No| Yes
|**PowerAvailableWatts**|RedfishCS_int64| 64-bit long long interger pointer to **PowerAvailableWatts** property.| No| Yes
|**PowerCapacityWatts**|RedfishCS_int64| 64-bit long long interger pointer to **PowerCapacityWatts** property.| No| Yes
|**PowerConsumedWatts**|RedfishCS_int64| 64-bit long long interger pointer to **PowerConsumedWatts** property.| No| Yes
|**PowerLimit**|RedfishPower_V1_2_4_PowerLimit_CS| Structure points to **PowerLimit** property.| No| No
|**PowerMetrics**|RedfishPower_V1_2_4_PowerMetric_CS| Structure points to **PowerMetrics** property.| No| No
|**PowerRequestedWatts**|RedfishCS_int64| 64-bit long long interger pointer to **PowerRequestedWatts** property.| No| Yes
|**RelatedItem**|Redfishodata_V4_0_1_idRef_Array_CS| Structure array points to one or more than one **Redfishodata_V4_0_1_idRef_Array_CS** structures for property **RelatedItem**.| No| Yes
|**RelatedItemodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **RelatedItem@odata.count** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No


## PowerLimit
    typedef struct _RedfishPower_V1_2_4_PowerLimit_CS {
        RedfishCS_int64 *CorrectionInMs;
        RedfishCS_char *LimitException;
        RedfishCS_int64 *LimitInWatts;
    } RedfishPower_V1_2_4_PowerLimit_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**CorrectionInMs**|RedfishCS_int64| 64-bit long long interger pointer to **CorrectionInMs** property.| No| No
|**LimitException**|RedfishCS_char| String pointer to **LimitException** property.| No| No
|**LimitInWatts**|RedfishCS_int64| 64-bit long long interger pointer to **LimitInWatts** property.| No| No


## PowerMetric
    typedef struct _RedfishPower_V1_2_4_PowerMetric_CS {
        RedfishCS_int64 *AverageConsumedWatts;
        RedfishCS_int64 *IntervalInMin;
        RedfishCS_int64 *MaxConsumedWatts;
        RedfishCS_int64 *MinConsumedWatts;
    } RedfishPower_V1_2_4_PowerMetric_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**AverageConsumedWatts**|RedfishCS_int64| 64-bit long long interger pointer to **AverageConsumedWatts** property.| No| Yes
|**IntervalInMin**|RedfishCS_int64| 64-bit long long interger pointer to **IntervalInMin** property.| No| Yes
|**MaxConsumedWatts**|RedfishCS_int64| 64-bit long long interger pointer to **MaxConsumedWatts** property.| No| Yes
|**MinConsumedWatts**|RedfishCS_int64| 64-bit long long interger pointer to **MinConsumedWatts** property.| No| Yes


## PowerSupply
    typedef struct _RedfishPower_V1_2_4_PowerSupply_CS {
        RedfishCS_char *FirmwareVersion;
        RedfishCS_char *IndicatorLED;
        RedfishPower_V1_2_4_InputRange_Array_CS *InputRanges;
        RedfishCS_int64 *LastPowerOutputWatts;
        RedfishCS_int64 *LineInputVoltage;
        RedfishCS_char *LineInputVoltageType;
        RedfishCS_char *Manufacturer;
        RedfishCS_char *MemberId;
        RedfishCS_char *Model;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *PartNumber;
        RedfishCS_int64 *PowerCapacityWatts;
        RedfishCS_char *PowerSupplyType;
        RedfishCS_Link Redundancy;
        RedfishCS_int64 *Redundancyodata_count;
        Redfishodata_V4_0_1_idRef_Array_CS *RelatedItem;
        RedfishCS_int64 *RelatedItemodata_count;
        RedfishCS_char *SerialNumber;
        RedfishCS_char *SparePartNumber;
        RedfishResource_Status_CS *Status;
    } RedfishPower_V1_2_4_PowerSupply_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**FirmwareVersion**|RedfishCS_char| String pointer to **FirmwareVersion** property.| No| Yes
|**IndicatorLED**|RedfishCS_char| String pointer to **IndicatorLED** property.| No| No
|**InputRanges**|RedfishPower_V1_2_4_InputRange_Array_CS| Structure array points to one or more than one **RedfishPower_V1_2_4_InputRange_Array_CS** structures for property **InputRanges**.| No| No
|**LastPowerOutputWatts**|RedfishCS_int64| 64-bit long long interger pointer to **LastPowerOutputWatts** property.| No| Yes
|**LineInputVoltage**|RedfishCS_int64| 64-bit long long interger pointer to **LineInputVoltage** property.| No| Yes
|**LineInputVoltageType**|RedfishCS_char| String pointer to **LineInputVoltageType** property.| No| Yes
|**Manufacturer**|RedfishCS_char| String pointer to **Manufacturer** property.| No| Yes
|**MemberId**|RedfishCS_char| String pointer to **MemberId** property.| No| Yes
|**Model**|RedfishCS_char| String pointer to **Model** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PartNumber**|RedfishCS_char| String pointer to **PartNumber** property.| No| Yes
|**PowerCapacityWatts**|RedfishCS_int64| 64-bit long long interger pointer to **PowerCapacityWatts** property.| No| Yes
|**PowerSupplyType**|RedfishCS_char| String pointer to **PowerSupplyType** property.| No| Yes
|**Redundancy**|RedfishCS_Link| Structure link list to **Redundancy** property.| No| No
|**Redundancyodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Redundancy@odata.count** property.| No| No
|**RelatedItem**|Redfishodata_V4_0_1_idRef_Array_CS| Structure array points to one or more than one **Redfishodata_V4_0_1_idRef_Array_CS** structures for property **RelatedItem**.| No| No
|**RelatedItemodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **RelatedItem@odata.count** property.| No| No
|**SerialNumber**|RedfishCS_char| String pointer to **SerialNumber** property.| No| Yes
|**SparePartNumber**|RedfishCS_char| String pointer to **SparePartNumber** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No


## Voltage
    typedef struct _RedfishPower_V1_2_4_Voltage_CS {
        RedfishCS_int64 *LowerThresholdCritical;
        RedfishCS_int64 *LowerThresholdFatal;
        RedfishCS_int64 *LowerThresholdNonCritical;
        RedfishCS_int64 *MaxReadingRange;
        RedfishCS_char *MemberId;
        RedfishCS_int64 *MinReadingRange;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *PhysicalContext;
        RedfishCS_int64 *ReadingVolts;
        Redfishodata_V4_0_1_idRef_Array_CS *RelatedItem;
        RedfishCS_int64 *RelatedItemodata_count;
        RedfishCS_int64 *SensorNumber;
        RedfishResource_Status_CS *Status;
        RedfishCS_int64 *UpperThresholdCritical;
        RedfishCS_int64 *UpperThresholdFatal;
        RedfishCS_int64 *UpperThresholdNonCritical;
    } RedfishPower_V1_2_4_Voltage_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**LowerThresholdCritical**|RedfishCS_int64| 64-bit long long interger pointer to **LowerThresholdCritical** property.| No| Yes
|**LowerThresholdFatal**|RedfishCS_int64| 64-bit long long interger pointer to **LowerThresholdFatal** property.| No| Yes
|**LowerThresholdNonCritical**|RedfishCS_int64| 64-bit long long interger pointer to **LowerThresholdNonCritical** property.| No| Yes
|**MaxReadingRange**|RedfishCS_int64| 64-bit long long interger pointer to **MaxReadingRange** property.| No| Yes
|**MemberId**|RedfishCS_char| String pointer to **MemberId** property.| No| Yes
|**MinReadingRange**|RedfishCS_int64| 64-bit long long interger pointer to **MinReadingRange** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PhysicalContext**|RedfishCS_char| String pointer to **PhysicalContext** property.| No| Yes
|**ReadingVolts**|RedfishCS_int64| 64-bit long long interger pointer to **ReadingVolts** property.| No| Yes
|**RelatedItem**|Redfishodata_V4_0_1_idRef_Array_CS| Structure array points to one or more than one **Redfishodata_V4_0_1_idRef_Array_CS** structures for property **RelatedItem**.| No| Yes
|**RelatedItemodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **RelatedItem@odata.count** property.| No| No
|**SensorNumber**|RedfishCS_int64| 64-bit long long interger pointer to **SensorNumber** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**UpperThresholdCritical**|RedfishCS_int64| 64-bit long long interger pointer to **UpperThresholdCritical** property.| No| Yes
|**UpperThresholdFatal**|RedfishCS_int64| 64-bit long long interger pointer to **UpperThresholdFatal** property.| No| Yes
|**UpperThresholdNonCritical**|RedfishCS_int64| 64-bit long long interger pointer to **UpperThresholdNonCritical** property.| No| Yes


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
    typedef struct _Redfishodata_V4_0_1_idRef_CS {
        RedfishCS_char *odata_id;
    } Redfishodata_V4_0_1_idRef_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No


## Redfishodata_V4_0_1_idRef_Array_CS
    typedef struct _Redfishodata_V4_0_1_idRef_Array_CS  {
        RedfishCS_Link *Next;
        Redfishodata_V4_0_1_idRef_CS *ArrayValue;
    } Redfishodata_V4_0_1_idRef_Array_CS;



## RedfishPower_V1_2_4_InputRange_Array_CS
    typedef struct _RedfishPower_V1_2_4_InputRange_Array_CS  {
        RedfishCS_Link *Next;
        RedfishPower_V1_2_4_InputRange_CS *ArrayValue;
    } RedfishPower_V1_2_4_InputRange_Array_CS;



## Power
    typedef struct _RedfishPower_V1_2_4_Power_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishCS_char *Description;
        RedfishCS_char *Id;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishPower_V1_2_4_PowerControl_CS *PowerControl;
        RedfishCS_int64 *PowerControlodata_count;
        RedfishPower_V1_2_4_PowerSupply_CS *PowerSupplies;
        RedfishCS_int64 *PowerSuppliesodata_count;
        RedfishCS_Link Redundancy;
        RedfishCS_int64 *Redundancyodata_count;
        RedfishPower_V1_2_4_Voltage_CS *Voltages;
        RedfishCS_int64 *Voltagesodata_count;
    } RedfishPower_V1_2_4_Power_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PowerControl**|RedfishPower_V1_2_4_PowerControl_CS| Structure points to **PowerControl** property.| No| No
|**PowerControlodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **PowerControl@odata.count** property.| No| No
|**PowerSupplies**|RedfishPower_V1_2_4_PowerSupply_CS| Structure points to **PowerSupplies** property.| No| No
|**PowerSuppliesodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **PowerSupplies@odata.count** property.| No| No
|**Redundancy**|RedfishCS_Link| Structure link list to **Redundancy** property.| No| No
|**Redundancyodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Redundancy@odata.count** property.| No| No
|**Voltages**|RedfishPower_V1_2_4_Voltage_CS| Structure points to **Voltages** property.| No| No
|**Voltagesodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Voltages@odata.count** property.| No| No
## Redfish Power V1_2_4 to C Structure Function
    RedfishCS_status
    Json_Power_V1_2_4_To_CS (RedfishCS_char *JsonRawText, RedfishPower_V1_2_4_Power_CS **ReturnedCS);

## C Structure to Redfish Power V1_2_4 JSON Function
    RedfishCS_status
    CS_To_Power_V1_2_4_JSON (RedfishPower_V1_2_4_Power_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish Power V1_2_4 C Structure Function
    RedfishCS_status
    DestroyPower_V1_2_4_CS (RedfishPower_V1_2_4_Power_CS *CSPtr);

