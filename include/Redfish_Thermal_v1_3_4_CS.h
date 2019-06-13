//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishThermal_V1_3_4_CSTRUCT_H_
#define _RedfishThermal_V1_3_4_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
#ifndef __Redfishodata_V4_0_3_idRef_Array_CS__
typedef struct _Redfishodata_V4_0_3_idRef_Array_CS Redfishodata_V4_0_3_idRef_Array_CS;
#endif
typedef struct _RedfishThermal_V1_3_4_Fan_Array_CS RedfishThermal_V1_3_4_Fan_Array_CS;
typedef struct _RedfishThermal_V1_3_4_Temperature_Array_CS RedfishThermal_V1_3_4_Temperature_Array_CS;
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

typedef struct _RedfishThermal_V1_3_4_Fan_CS RedfishThermal_V1_3_4_Fan_CS;
typedef struct _RedfishThermal_V1_3_4_FanActions_CS RedfishThermal_V1_3_4_FanActions_CS;
typedef struct _RedfishThermal_V1_3_4_FanOemActions_CS RedfishThermal_V1_3_4_FanOemActions_CS;
typedef struct _RedfishThermal_V1_3_4_Temperature_CS RedfishThermal_V1_3_4_Temperature_CS;
typedef struct _RedfishThermal_V1_3_4_TemperatureActions_CS RedfishThermal_V1_3_4_TemperatureActions_CS;
typedef struct _RedfishThermal_V1_3_4_TemperatureOemActions_CS RedfishThermal_V1_3_4_TemperatureOemActions_CS;
typedef struct _RedfishThermal_V1_3_4_Thermal_CS RedfishThermal_V1_3_4_Thermal_CS;
typedef struct _RedfishThermal_V1_3_4_ThermalActions_CS RedfishThermal_V1_3_4_ThermalActions_CS;
typedef struct _RedfishThermal_V1_3_4_ThermalOemActions_CS RedfishThermal_V1_3_4_ThermalOemActions_CS;
#ifndef __Redfishodata_V4_0_3_idRef_CS__
typedef struct _Redfishodata_V4_0_3_idRef_CS Redfishodata_V4_0_3_idRef_CS;
#endif

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

typedef struct _RedfishThermal_V1_3_4_Fan_CS {
    RedfishCS_char                         *odata_id;                
    RedfishThermal_V1_3_4_FanActions_CS    *Actions;                     // The available actions for this
                                                                         // resource.
    RedfishCS_char                         *FanName;                     // Name of the fan.
    RedfishCS_char                         *IndicatorLED;                // The state of the indicator
                                                                         // LED, used to identify this
                                                                         // Fan.
    RedfishCS_int64                        *LowerThresholdCritical;      // Below normal range but not yet
                                                                         // fatal.
    RedfishCS_int64                        *LowerThresholdFatal;         // Below normal range and is
                                                                         // fatal.
    RedfishCS_int64                        *LowerThresholdNonCritical;    // Below normal range.
    RedfishCS_char                         *Manufacturer;                // This is the manufacturer of
                                                                         // this Fan.
    RedfishCS_int64                        *MaxReadingRange;             // Maximum value for Reading.
    RedfishCS_char                         *MemberId;                    // This is the identifier for the
                                                                         // member within the collection.
    RedfishCS_int64                        *MinReadingRange;             // Minimum value for Reading.
    RedfishCS_char                         *Model;                       // The model number for this Fan.
    RedfishCS_char                         *Name;                        // Name of the fan.
    RedfishResource_Oem_CS                 *Oem;                         // This is the
                                                                         // manufacturer/provider specific
                                                                         // extension moniker used to
                                                                         // divide the Oem object into
                                                                         // sections.
    RedfishCS_char                         *PartNumber;                  // The part number for this Fan.
    RedfishCS_char                         *PhysicalContext;             // Describes the area or device
                                                                         // associated with this fan.
    RedfishCS_int64                        *Reading;                     // Current fan speed.
    RedfishCS_char                         *ReadingUnits;                // Units in which the reading and
                                                                         // thresholds are measured.
    RedfishCS_Link                         Redundancy;                   // This structure is used to show
                                                                         // redundancy for fans.  The
                                                                         // Component ids will reference
                                                                         // the members of the redundancy
                                                                         // groups.
    RedfishCS_int64                        *Redundancyodata_count;   
    Redfishodata_V4_0_3_idRef_Array_CS     *RelatedItem;                 // The ID(s) of the resources
                                                                         // serviced with this fan.
    RedfishCS_int64                        *RelatedItemodata_count;  
    RedfishCS_char                         *SerialNumber;                // The serial number for this
                                                                         // Fan.
    RedfishCS_char                         *SparePartNumber;             // The spare part number for this
                                                                         // Fan.
    RedfishResource_Status_CS              *Status;                      // This property describes the
                                                                         // status and health of the
                                                                         // resource and its children.
    RedfishCS_int64                        *UpperThresholdCritical;      // Above normal range but not yet
                                                                         // fatal.
    RedfishCS_int64                        *UpperThresholdFatal;         // Above normal range and is
                                                                         // fatal.
    RedfishCS_int64                        *UpperThresholdNonCritical;    // Above normal range.
} RedfishThermal_V1_3_4_Fan_CS;

//
// The available actions for this resource.
//
typedef struct _RedfishThermal_V1_3_4_FanActions_CS {
    RedfishThermal_V1_3_4_FanOemActions_CS    *Oem;    // This property contains the
                                                      // available OEM specific actions
                                                      // for this resource.
} RedfishThermal_V1_3_4_FanActions_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishThermal_V1_3_4_FanOemActions_CS {
    RedfishCS_Link    Prop;
} RedfishThermal_V1_3_4_FanOemActions_CS;

typedef struct _RedfishThermal_V1_3_4_Temperature_CS {
    RedfishCS_char                                 *odata_id;                
    RedfishThermal_V1_3_4_TemperatureActions_CS    *Actions;                     // The available actions for this
                                                                                 // resource.
    RedfishCS_int64                                *LowerThresholdCritical;      // Below normal range but not yet
                                                                                 // fatal.
    RedfishCS_int64                                *LowerThresholdFatal;         // Below normal range and is
                                                                                 // fatal.
    RedfishCS_int64                                *LowerThresholdNonCritical;    // Below normal range.
    RedfishCS_int64                                *MaxReadingRangeTemp;         // Maximum value for
                                                                                 // ReadingCelsius.
    RedfishCS_char                                 *MemberId;                    // This is the identifier for the
                                                                                 // member within the collection.
    RedfishCS_int64                                *MinReadingRangeTemp;         // Minimum value for
                                                                                 // ReadingCelsius.
    RedfishCS_char                                 *Name;                        // Temperature sensor name.
    RedfishResource_Oem_CS                         *Oem;                         // This is the
                                                                                 // manufacturer/provider specific
                                                                                 // extension moniker used to
                                                                                 // divide the Oem object into
                                                                                 // sections.
    RedfishCS_char                                 *PhysicalContext;             // Describes the area or device
                                                                                 // to which this temperature
                                                                                 // measurement applies.
    RedfishCS_int64                                *ReadingCelsius;              // Temperature.
    Redfishodata_V4_0_3_idRef_Array_CS             *RelatedItem;                 // Describes the areas or devices
                                                                                 // to which this temperature
                                                                                 // measurement applies.
    RedfishCS_int64                                *RelatedItemodata_count;  
    RedfishCS_int64                                *SensorNumber;                // A numerical identifier to
                                                                                 // represent the temperature
                                                                                 // sensor.
    RedfishResource_Status_CS                      *Status;                      // This property describes the
                                                                                 // status and health of the
                                                                                 // resource and its children.
    RedfishCS_int64                                *UpperThresholdCritical;      // Above normal range but not yet
                                                                                 // fatal.
    RedfishCS_int64                                *UpperThresholdFatal;         // Above normal range and is
                                                                                 // fatal.
    RedfishCS_int64                                *UpperThresholdNonCritical;    // Above normal range.
} RedfishThermal_V1_3_4_Temperature_CS;

//
// The available actions for this resource.
//
typedef struct _RedfishThermal_V1_3_4_TemperatureActions_CS {
    RedfishThermal_V1_3_4_TemperatureOemActions_CS    *Oem;    // This property contains the
                                                              // available OEM specific actions
                                                              // for this resource.
} RedfishThermal_V1_3_4_TemperatureActions_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishThermal_V1_3_4_TemperatureOemActions_CS {
    RedfishCS_Link    Prop;
} RedfishThermal_V1_3_4_TemperatureOemActions_CS;

//
// The available actions for this resource.
//
typedef struct _RedfishThermal_V1_3_4_ThermalActions_CS {
    RedfishThermal_V1_3_4_ThermalOemActions_CS    *Oem;    // This property contains the
                                                          // available OEM specific actions
                                                          // for this resource.
} RedfishThermal_V1_3_4_ThermalActions_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishThermal_V1_3_4_ThermalOemActions_CS {
    RedfishCS_Link    Prop;
} RedfishThermal_V1_3_4_ThermalOemActions_CS;

//
// A reference to a resource.
//
#ifndef __Redfishodata_V4_0_3_idRef_CS__
#define __Redfishodata_V4_0_3_idRef_CS__
typedef struct _Redfishodata_V4_0_3_idRef_CS {
    RedfishCS_char    *odata_id;
} Redfishodata_V4_0_3_idRef_CS;
#endif

//
// This is the schema definition for the Thermal properties.  It represents the
// properties for Temperature and Cooling.
//
typedef struct _RedfishThermal_V1_3_4_Thermal_CS {
    RedfishCS_Header                              Header;
    RedfishCS_char                                *odata_context;         
    RedfishCS_char                                *odata_etag;            
    RedfishCS_char                                *odata_id;              
    RedfishCS_char                                *odata_type;            
    RedfishThermal_V1_3_4_ThermalActions_CS       *Actions;                   // The available actions for this
                                                                              // resource.
    RedfishCS_char                                *Description;           
    RedfishThermal_V1_3_4_Fan_Array_CS            *Fans;                      // This is the definition for
                                                                              // fans.
    RedfishCS_int64                               *Fansodata_count;       
    RedfishCS_char                                *Id;                    
    RedfishCS_char                                *Name;                  
    RedfishResource_Oem_CS                        *Oem;                       // This is the
                                                                              // manufacturer/provider specific
                                                                              // extension moniker used to
                                                                              // divide the Oem object into
                                                                              // sections.
    RedfishCS_Link                                Redundancy;                 // This structure is used to show
                                                                              // redundancy for fans.  The
                                                                              // Component ids will reference
                                                                              // the members of the redundancy
                                                                              // groups.
    RedfishCS_int64                               *Redundancyodata_count; 
    RedfishResource_Status_CS                     *Status;                    // This property describes the
                                                                              // status and health of the
                                                                              // resource and its children.
    RedfishThermal_V1_3_4_Temperature_Array_CS    *Temperatures;              // This is the definition for
                                                                              // temperature sensors.
    RedfishCS_int64                               *Temperaturesodata_count;
} RedfishThermal_V1_3_4_Thermal_CS;

#ifndef __Redfishodata_V4_0_3_idRef_Array_CS__
#define __Redfishodata_V4_0_3_idRef_Array_CS__
typedef struct _Redfishodata_V4_0_3_idRef_Array_CS  {
    Redfishodata_V4_0_3_idRef_Array_CS    *Next;
    Redfishodata_V4_0_3_idRef_CS    *ArrayValue;
} Redfishodata_V4_0_3_idRef_Array_CS;
#endif

typedef struct _RedfishThermal_V1_3_4_Fan_Array_CS  {
    RedfishThermal_V1_3_4_Fan_Array_CS    *Next;
    RedfishThermal_V1_3_4_Fan_CS    *ArrayValue;
} RedfishThermal_V1_3_4_Fan_Array_CS;

typedef struct _RedfishThermal_V1_3_4_Temperature_Array_CS  {
    RedfishThermal_V1_3_4_Temperature_Array_CS    *Next;
    RedfishThermal_V1_3_4_Temperature_CS    *ArrayValue;
} RedfishThermal_V1_3_4_Temperature_Array_CS;

RedfishCS_status
Json_Thermal_V1_3_4_To_CS (char *JsonRawText, RedfishThermal_V1_3_4_Thermal_CS **ReturnedCS);

RedfishCS_status
CS_To_Thermal_V1_3_4_JSON (RedfishThermal_V1_3_4_Thermal_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyThermal_V1_3_4_CS (RedfishThermal_V1_3_4_Thermal_CS *CSPtr);

RedfishCS_status
DestroyThermal_V1_3_4_Json (RedfishCS_char *JsonText);

#endif
