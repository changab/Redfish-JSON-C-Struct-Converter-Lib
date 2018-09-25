//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishThermal_V1_0_3_CSTRUCT_H_
#define _RedfishThermal_V1_0_3_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
#ifndef __Redfishodata_V4_0_0_idRef_Array_CS__
typedef struct _Redfishodata_V4_0_0_idRef_Array_CS Redfishodata_V4_0_0_idRef_Array_CS;
#endif
typedef struct _RedfishThermal_V1_0_3_Fan_Array_CS RedfishThermal_V1_0_3_Fan_Array_CS;
typedef struct _RedfishThermal_V1_0_3_Temperature_Array_CS RedfishThermal_V1_0_3_Temperature_Array_CS;
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

typedef struct _RedfishThermal_V1_0_3_Fan_CS RedfishThermal_V1_0_3_Fan_CS;
typedef struct _RedfishThermal_V1_0_3_Temperature_CS RedfishThermal_V1_0_3_Temperature_CS;
typedef struct _RedfishThermal_V1_0_3_Thermal_CS RedfishThermal_V1_0_3_Thermal_CS;
#ifndef __Redfishodata_V4_0_0_idRef_CS__
typedef struct _Redfishodata_V4_0_0_idRef_CS Redfishodata_V4_0_0_idRef_CS;
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
    RedfishResource_Oem_CS    *Oem;        
    RedfishCS_char            *State;          // This indicates the known state
                                               // of the resource, such as if it
                                               // is enabled.
} RedfishResource_Status_CS;
#endif

//
// This is the base type for addressable members of an array.
//
typedef struct _RedfishThermal_V1_0_3_Fan_CS {
    RedfishCS_char                        *FanName;                           // Name of the fan.
    RedfishCS_int64                       *LowerThresholdCritical;            // Below normal range but not yet
                                                                              // fatal.
    RedfishCS_int64                       *LowerThresholdFatal;               // Below normal range and is
                                                                              // fatal.
    RedfishCS_int64                       *LowerThresholdNonCritical;         // Below normal range.
    RedfishCS_int64                       *MaxReadingRange;                   // Maximum value for Reading.
    RedfishCS_char                        *MemberId;                          // This is the identifier for the
                                                                              // member within the collection.
    RedfishCS_int64                       *MinReadingRange;                   // Minimum value for Reading.
    RedfishResource_Oem_CS                *Oem;                               // This is the
                                                                              // manufacturer/provider specific
                                                                              // extension moniker used to
                                                                              // divide the Oem object into
                                                                              // sections.
    RedfishCS_Link                        PhysicalContext;                    // Describes the area or device
                                                                              // associated with this fan.
    RedfishCS_int64                       *Reading;                           // Current fan speed.
    RedfishCS_char                        *ReadingUnits;                      // Units in which the reading and
                                                                              // thresholds are measured.
    RedfishCS_Link                        Redundancy;                         // This structure is used to show
                                                                              // redundancy for fans.  The
                                                                              // Component ids will reference
                                                                              // the members of the redundancy
                                                                              // groups.
    RedfishCS_int64                       *Redundancyodata_count;         
    RedfishCS_char                        *Redundancyodata_navigationLink;
    Redfishodata_V4_0_0_idRef_Array_CS    *RelatedItem;                       // The ID(s) of the resources
                                                                              // serviced with this fan.
    RedfishCS_int64                       *RelatedItemodata_count;        
    RedfishCS_char                        *RelatedItemodata_navigationLink;
    RedfishResource_Status_CS             *Status;                        
    RedfishCS_int64                       *UpperThresholdCritical;            // Above normal range but not yet
                                                                              // fatal.
    RedfishCS_int64                       *UpperThresholdFatal;               // Above normal range and is
                                                                              // fatal.
    RedfishCS_int64                       *UpperThresholdNonCritical;         // Above normal range.
} RedfishThermal_V1_0_3_Fan_CS;

//
// This is the base type for addressable members of an array.
//
typedef struct _RedfishThermal_V1_0_3_Temperature_CS {
    RedfishCS_int64                       *LowerThresholdCritical;            // Below normal range but not yet
                                                                              // fatal.
    RedfishCS_int64                       *LowerThresholdFatal;               // Below normal range and is
                                                                              // fatal.
    RedfishCS_int64                       *LowerThresholdNonCritical;         // Below normal range.
    RedfishCS_int64                       *MaxReadingRangeTemp;               // Maximum value for
                                                                              // ReadingCelsius.
    RedfishCS_char                        *MemberId;                          // This is the identifier for the
                                                                              // member within the collection.
    RedfishCS_int64                       *MinReadingRangeTemp;               // Minimum value for
                                                                              // ReadingCelsius.
    RedfishCS_char                        *Name;                              // Temperature sensor name.
    RedfishResource_Oem_CS                *Oem;                               // This is the
                                                                              // manufacturer/provider specific
                                                                              // extension moniker used to
                                                                              // divide the Oem object into
                                                                              // sections.
    RedfishCS_Link                        PhysicalContext;                    // Describes the area or device
                                                                              // to which this temperature
                                                                              // measurement applies.
    RedfishCS_int64                       *ReadingCelsius;                    // Temperature.
    Redfishodata_V4_0_0_idRef_Array_CS    *RelatedItem;                       // Describes the areas or devices
                                                                              // to which this temperature
                                                                              // measurement applies.
    RedfishCS_int64                       *RelatedItemodata_count;        
    RedfishCS_char                        *RelatedItemodata_navigationLink;
    RedfishCS_int64                       *SensorNumber;                      // A numerical identifier to
                                                                              // represent the temperature
                                                                              // sensor.
    RedfishResource_Status_CS             *Status;                        
    RedfishCS_int64                       *UpperThresholdCritical;            // Above normal range but not yet
                                                                              // fatal.
    RedfishCS_int64                       *UpperThresholdFatal;               // Above normal range and is
                                                                              // fatal.
    RedfishCS_int64                       *UpperThresholdNonCritical;         // Above normal range.
} RedfishThermal_V1_0_3_Temperature_CS;

//
// A reference to a resource.
//
#ifndef __Redfishodata_V4_0_0_idRef_CS__
#define __Redfishodata_V4_0_0_idRef_CS__
typedef struct _Redfishodata_V4_0_0_idRef_CS {
    RedfishCS_char    *odata_id;
} Redfishodata_V4_0_0_idRef_CS;
#endif

//
// This is the schema definition for the Thermal properties.  It represents the
// properties for Temperature and Cooling.
//
typedef struct _RedfishThermal_V1_0_3_Thermal_CS {
    RedfishCS_Header                              Header;
    RedfishCS_char                                *odata_context;                  
    RedfishCS_char                                *odata_id;                       
    RedfishCS_char                                *odata_type;                     
    RedfishCS_char                                *Description;                    
    RedfishThermal_V1_0_3_Fan_Array_CS            *Fans;                               // This is the definition for
                                                                                       // fans.
    RedfishCS_int64                               *Fansodata_count;                
    RedfishCS_char                                *Fansodata_navigationLink;       
    RedfishCS_char                                *Id;                             
    RedfishCS_char                                *Name;                           
    RedfishResource_Oem_CS                        *Oem;                                // This is the
                                                                                       // manufacturer/provider specific
                                                                                       // extension moniker used to
                                                                                       // divide the Oem object into
                                                                                       // sections.
    RedfishCS_Link                                Redundancy;                          // This structure is used to show
                                                                                       // redundancy for fans.  The
                                                                                       // Component ids will reference
                                                                                       // the members of the redundancy
                                                                                       // groups.
    RedfishCS_int64                               *Redundancyodata_count;          
    RedfishCS_char                                *Redundancyodata_navigationLink; 
    RedfishResource_Status_CS                     *Status;                         
    RedfishThermal_V1_0_3_Temperature_Array_CS    *Temperatures;                       // This is the definition for
                                                                                       // temperature sensors.
    RedfishCS_int64                               *Temperaturesodata_count;        
    RedfishCS_char                                *Temperaturesodata_navigationLink;
} RedfishThermal_V1_0_3_Thermal_CS;

#ifndef __Redfishodata_V4_0_0_idRef_Array_CS__
#define __Redfishodata_V4_0_0_idRef_Array_CS__
typedef struct _Redfishodata_V4_0_0_idRef_Array_CS  {
    Redfishodata_V4_0_0_idRef_Array_CS    *Next;
    Redfishodata_V4_0_0_idRef_CS    *ArrayValue;
} Redfishodata_V4_0_0_idRef_Array_CS;
#endif

typedef struct _RedfishThermal_V1_0_3_Fan_Array_CS  {
    RedfishThermal_V1_0_3_Fan_Array_CS    *Next;
    RedfishThermal_V1_0_3_Fan_CS    *ArrayValue;
} RedfishThermal_V1_0_3_Fan_Array_CS;

typedef struct _RedfishThermal_V1_0_3_Temperature_Array_CS  {
    RedfishThermal_V1_0_3_Temperature_Array_CS    *Next;
    RedfishThermal_V1_0_3_Temperature_CS    *ArrayValue;
} RedfishThermal_V1_0_3_Temperature_Array_CS;

RedfishCS_status
Json_Thermal_V1_0_3_To_CS (char *JsonRawText, RedfishThermal_V1_0_3_Thermal_CS **ReturnedCS);

RedfishCS_status
CS_To_Thermal_V1_0_3_JSON (RedfishThermal_V1_0_3_Thermal_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyThermal_V1_0_3_CS (RedfishThermal_V1_0_3_Thermal_CS *CSPtr);

RedfishCS_status
DestroyThermal_V1_0_3_Json (RedfishCS_char *JsonText);

#endif
