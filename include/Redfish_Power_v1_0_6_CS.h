//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishPower_V1_0_6_CSTRUCT_H_
#define _RedfishPower_V1_0_6_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __Redfishodata_V4_0_1_idRef_Array_CS__
typedef struct _Redfishodata_V4_0_1_idRef_Array_CS Redfishodata_V4_0_1_idRef_Array_CS;
#endif
typedef struct _RedfishPower_V1_0_6_PowerControl_Array_CS RedfishPower_V1_0_6_PowerControl_Array_CS;
typedef struct _RedfishPower_V1_0_6_PowerSupply_Array_CS RedfishPower_V1_0_6_PowerSupply_Array_CS;
typedef struct _RedfishPower_V1_0_6_Voltage_Array_CS RedfishPower_V1_0_6_Voltage_Array_CS;
typedef struct _RedfishPower_V1_0_6_Power_CS RedfishPower_V1_0_6_Power_CS;
typedef struct _RedfishPower_V1_0_6_PowerControl_CS RedfishPower_V1_0_6_PowerControl_CS;
typedef struct _RedfishPower_V1_0_6_PowerLimit_CS RedfishPower_V1_0_6_PowerLimit_CS;
typedef struct _RedfishPower_V1_0_6_PowerMetric_CS RedfishPower_V1_0_6_PowerMetric_CS;
typedef struct _RedfishPower_V1_0_6_PowerSupply_CS RedfishPower_V1_0_6_PowerSupply_CS;
typedef struct _RedfishPower_V1_0_6_Voltage_CS RedfishPower_V1_0_6_Voltage_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

#ifndef __Redfishodata_V4_0_1_idRef_CS__
typedef struct _Redfishodata_V4_0_1_idRef_CS Redfishodata_V4_0_1_idRef_CS;
#endif

typedef struct _RedfishPower_V1_0_6_PowerControl_CS {
    RedfishCS_char                        *MemberId;                 // This is the identifier for the
                                                                     // member within the collection.
    RedfishCS_char                        *Name;                     // Power Control Function name.
    RedfishResource_Oem_CS                *Oem;                      // This is the
                                                                     // manufacturer/provider specific
                                                                     // extension moniker used to
                                                                     // divide the Oem object into
                                                                     // sections.
    RedfishCS_int64                       *PowerAllocatedWatts;      // The total amount of power that
                                                                     // has been allocated (or
                                                                     // budegeted)to  chassis
                                                                     // resources.
    RedfishCS_int64                       *PowerAvailableWatts;      // The amount of power not
                                                                     // already budgeted and therefore
                                                                     // available for additional
                                                                     // allocation. (powerCapacity -
                                                                     // powerAllocated).  This
                                                                     // indicates how much reserve
                                                                     // power capacity is left.
    RedfishCS_int64                       *PowerCapacityWatts;       // The total amount of power
                                                                     // available to the chassis for
                                                                     // allocation. This may the power
                                                                     // supply capacity, or power
                                                                     // budget assigned to the chassis
                                                                     // from an up-stream chassis.
    RedfishCS_int64                       *PowerConsumedWatts;       // The actual power being
                                                                     // consumed by the chassis.
    RedfishPower_V1_0_6_PowerLimit_CS     *PowerLimit;               // Power limit status and
                                                                     // configuration information for
                                                                     // this chassis.
    RedfishPower_V1_0_6_PowerMetric_CS    *PowerMetrics;             // Power readings for this
                                                                     // chassis.
    RedfishCS_int64                       *PowerRequestedWatts;      // The potential power that the
                                                                     // chassis resources are
                                                                     // requesting which may be higher
                                                                     // than the current level being
                                                                     // consumed since requested power
                                                                     // includes budget that the
                                                                     // chassis resource wants for
                                                                     // future use.
    Redfishodata_V4_0_1_idRef_Array_CS    *RelatedItem;              // The ID(s) of the resources
                                                                     // associated with this Power
                                                                     // Limit.
    RedfishCS_int64                       *RelatedItemodata_count;
    RedfishResource_Status_CS             *Status;               
} RedfishPower_V1_0_6_PowerControl_CS;

//
// This object contains power limit status and configuration information for the
// chassis.
//
typedef struct _RedfishPower_V1_0_6_PowerLimit_CS {
    RedfishCS_int64    *CorrectionInMs;    // The time required for the
                                          // limiting process to reduce
                                          // power consumption to below the
                                          // limit.
    RedfishCS_char     *LimitException;    // The action that is taken if
                                          // the power cannot be maintained
                                          // below the LimitInWatts.
    RedfishCS_int64    *LimitInWatts;     // The Power limit in watts. Set
                                          // to null to disable power
                                          // capping.
} RedfishPower_V1_0_6_PowerLimit_CS;

//
// This type describe the power metrics for a resource.
//
typedef struct _RedfishPower_V1_0_6_PowerMetric_CS {
    RedfishCS_int64    *AverageConsumedWatts;    // The average power level over
                                                // the measurement window (the
                                                // last IntervalInMin minutes).
    RedfishCS_int64    *IntervalInMin;          // The time interval (or window)
                                                // in which the PowerMetrics are
                                                // measured over.
    RedfishCS_int64    *MaxConsumedWatts;       // The highest power consumption
                                                // level that has occured over
                                                // the measurement window (the
                                                // last IntervalInMin minutes).
    RedfishCS_int64    *MinConsumedWatts;       // The lowest power consumption
                                                // level over the measurement
                                                // window (the last IntervalInMin
                                                // minutes).
} RedfishPower_V1_0_6_PowerMetric_CS;

//
// Details of a power supplies associated with this system or device.
//
typedef struct _RedfishPower_V1_0_6_PowerSupply_CS {
    RedfishCS_char                        *FirmwareVersion;          // The firmware version for this
                                                                     // Power Supply.
    RedfishCS_int64                       *LastPowerOutputWatts;     // The average power output of
                                                                     // this Power Supply.
    RedfishCS_int64                       *LineInputVoltage;         // The line input voltage at
                                                                     // which the Power Supply is
                                                                     // operating.
    RedfishCS_char                        *LineInputVoltageType;     // The line voltage type
                                                                     // supported as an input to this
                                                                     // Power Supply.
    RedfishCS_char                        *MemberId;                 // This is the identifier for the
                                                                     // member within the collection.
    RedfishCS_char                        *Model;                    // The model number for this
                                                                     // Power Supply.
    RedfishCS_char                        *Name;                     // The name of the Power Supply.
    RedfishResource_Oem_CS                *Oem;                      // This is the
                                                                     // manufacturer/provider specific
                                                                     // extension moniker used to
                                                                     // divide the Oem object into
                                                                     // sections.
    RedfishCS_char                        *PartNumber;               // The part number for this Power
                                                                     // Supply.
    RedfishCS_int64                       *PowerCapacityWatts;       // The maximum capacity of this
                                                                     // Power Supply.
    RedfishCS_char                        *PowerSupplyType;          // The Power Supply type (AC or
                                                                     // DC).
    RedfishCS_Link                        Redundancy;                // This structure is used to show
                                                                     // redundancy for power supplies.
                                                                     // The Component ids will
                                                                     // reference the members of the
                                                                     // redundancy groups.
    RedfishCS_int64                       *Redundancyodata_count;
    Redfishodata_V4_0_1_idRef_Array_CS    *RelatedItem;              // The ID(s) of the resources
                                                                     // associated with this Power
                                                                     // Limit.
    RedfishCS_int64                       *RelatedItemodata_count;
    RedfishCS_char                        *SerialNumber;             // The serial number for this
                                                                     // Power Supply.
    RedfishCS_char                        *SparePartNumber;          // The spare part number for this
                                                                     // Power Supply.
    RedfishResource_Status_CS             *Status;               
} RedfishPower_V1_0_6_PowerSupply_CS;

typedef struct _RedfishPower_V1_0_6_Voltage_CS {
    RedfishCS_int64                       *LowerThresholdCritical;      // Below normal range but not yet
                                                                        // fatal.
    RedfishCS_int64                       *LowerThresholdFatal;         // Below normal range and is
                                                                        // fatal.
    RedfishCS_int64                       *LowerThresholdNonCritical;    // Below normal range.
    RedfishCS_int64                       *MaxReadingRange;             // Maximum value for this Voltage
                                                                        // sensor.
    RedfishCS_char                        *MemberId;                    // This is the identifier for the
                                                                        // member within the collection.
    RedfishCS_int64                       *MinReadingRange;             // Minimum value for this Voltage
                                                                        // sensor.
    RedfishCS_char                        *Name;                        // Voltage sensor name.
    RedfishResource_Oem_CS                *Oem;                         // This is the
                                                                        // manufacturer/provider specific
                                                                        // extension moniker used to
                                                                        // divide the Oem object into
                                                                        // sections.
    RedfishCS_char                        *PhysicalContext;             // Describes the area or device
                                                                        // to which this voltage
                                                                        // measurement applies.
    RedfishCS_int64                       *ReadingVolts;                // The present reading of the
                                                                        // voltage sensor.
    Redfishodata_V4_0_1_idRef_Array_CS    *RelatedItem;                 // Describes the areas or devices
                                                                        // to which this voltage
                                                                        // measurement applies.
    RedfishCS_int64                       *RelatedItemodata_count;  
    RedfishCS_int64                       *SensorNumber;                // A numerical identifier to
                                                                        // represent the voltage sensor.
    RedfishResource_Status_CS             *Status;                  
    RedfishCS_int64                       *UpperThresholdCritical;      // Above normal range but not yet
                                                                        // fatal.
    RedfishCS_int64                       *UpperThresholdFatal;         // Above normal range and is
                                                                        // fatal.
    RedfishCS_int64                       *UpperThresholdNonCritical;    // Above normal range.
} RedfishPower_V1_0_6_Voltage_CS;

//
// Oem extension object.
//
#ifndef __RedfishResource_Oem_CS__
#define __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishResource_Oem_CS;
#endif

//
// This type describes the status and health of a resource and its children.
//
#ifndef __RedfishResource_Status_CS__
#define __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS {
    RedfishCS_char            *Health;         // This represents the health
                                               // state of this resource in the
                                               // absence of its dependent
                                               // resources.
    RedfishCS_char            *HealthRollup;    // This represents the overall
                                               // health state from the view of
                                               // this resource.
    RedfishResource_Oem_CS    *Oem;            // Oem extension object.
    RedfishCS_char            *State;          // This indicates the known state
                                               // of the resource, such as if it
                                               // is enabled.
} RedfishResource_Status_CS;
#endif

//
// A reference to a resource.
//
#ifndef __Redfishodata_V4_0_1_idRef_CS__
#define __Redfishodata_V4_0_1_idRef_CS__
typedef struct _Redfishodata_V4_0_1_idRef_CS {
    RedfishCS_char    *odata_id;
} Redfishodata_V4_0_1_idRef_CS;
#endif

//
// This is the schema definition for the Power Metrics.  It represents the
// properties for Power Consumption and Power Limiting.
//
typedef struct _RedfishPower_V1_0_6_Power_CS {
    RedfishCS_Header                             Header;
    RedfishCS_char                               *odata_context;          
    RedfishCS_char                               *odata_id;               
    RedfishCS_char                               *odata_type;             
    RedfishCS_char                               *Description;            
    RedfishCS_char                               *Id;                     
    RedfishCS_char                               *Name;                   
    RedfishResource_Oem_CS                       *Oem;                        // This is the
                                                                              // manufacturer/provider specific
                                                                              // extension moniker used to
                                                                              // divide the Oem object into
                                                                              // sections.
    RedfishPower_V1_0_6_PowerControl_Array_CS    *PowerControl;               // This is the definition for
                                                                              // power control function (power
                                                                              // reading/limiting).
    RedfishCS_int64                              *PowerControlodata_count;
    RedfishPower_V1_0_6_PowerSupply_Array_CS     *PowerSupplies;              // Details of the power supplies
                                                                              // associated with this system or
                                                                              // device.
    RedfishCS_int64                              *PowerSuppliesodata_count;
    RedfishCS_Link                               Redundancy;                  // Redundancy information for the
                                                                              // power subsystem of this system
                                                                              // or device.
    RedfishCS_int64                              *Redundancyodata_count;  
    RedfishPower_V1_0_6_Voltage_Array_CS         *Voltages;                   // This is the definition for
                                                                              // voltage sensors.
    RedfishCS_int64                              *Voltagesodata_count;    
} RedfishPower_V1_0_6_Power_CS;

#ifndef __Redfishodata_V4_0_1_idRef_Array_CS__
#define __Redfishodata_V4_0_1_idRef_Array_CS__
typedef struct _Redfishodata_V4_0_1_idRef_Array_CS  {
    Redfishodata_V4_0_1_idRef_Array_CS    *Next;
    Redfishodata_V4_0_1_idRef_CS    *ArrayValue;
} Redfishodata_V4_0_1_idRef_Array_CS;
#endif

typedef struct _RedfishPower_V1_0_6_PowerControl_Array_CS  {
    RedfishPower_V1_0_6_PowerControl_Array_CS    *Next;
    RedfishPower_V1_0_6_PowerControl_CS    *ArrayValue;
} RedfishPower_V1_0_6_PowerControl_Array_CS;

typedef struct _RedfishPower_V1_0_6_PowerSupply_Array_CS  {
    RedfishPower_V1_0_6_PowerSupply_Array_CS    *Next;
    RedfishPower_V1_0_6_PowerSupply_CS    *ArrayValue;
} RedfishPower_V1_0_6_PowerSupply_Array_CS;

typedef struct _RedfishPower_V1_0_6_Voltage_Array_CS  {
    RedfishPower_V1_0_6_Voltage_Array_CS    *Next;
    RedfishPower_V1_0_6_Voltage_CS    *ArrayValue;
} RedfishPower_V1_0_6_Voltage_Array_CS;

RedfishCS_status
Json_Power_V1_0_6_To_CS (char *JsonRawText, RedfishPower_V1_0_6_Power_CS **ReturnedCS);

RedfishCS_status
CS_To_Power_V1_0_6_JSON (RedfishPower_V1_0_6_Power_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyPower_V1_0_6_CS (RedfishPower_V1_0_6_Power_CS *CSPtr);

RedfishCS_status
DestroyPower_V1_0_6_Json (RedfishCS_char *JsonText);

#endif
