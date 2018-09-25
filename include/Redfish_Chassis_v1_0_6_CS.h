//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishChassis_V1_0_6_CSTRUCT_H_
#define _RedfishChassis_V1_0_6_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __Redfishodata_V4_0_1_idRef_Array_CS__
typedef struct _Redfishodata_V4_0_1_idRef_Array_CS Redfishodata_V4_0_1_idRef_Array_CS;
#endif
typedef struct _RedfishChassis_V1_0_6_Actions_CS RedfishChassis_V1_0_6_Actions_CS;
typedef struct _RedfishChassis_V1_0_6_Chassis_CS RedfishChassis_V1_0_6_Chassis_CS;
typedef struct _RedfishChassis_V1_0_6_Links_CS RedfishChassis_V1_0_6_Links_CS;
typedef struct _RedfishChassis_V1_0_6_OemActions_CS RedfishChassis_V1_0_6_OemActions_CS;
typedef struct _RedfishChassis_V1_0_6_Reset_CS RedfishChassis_V1_0_6_Reset_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

#ifndef __Redfishodata_V4_0_1_idRef_CS__
typedef struct _Redfishodata_V4_0_1_idRef_CS Redfishodata_V4_0_1_idRef_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishChassis_V1_0_6_Actions_CS {
    RedfishChassis_V1_0_6_Reset_CS         *Chassis_Reset;
    RedfishChassis_V1_0_6_OemActions_CS    *Oem;         
} RedfishChassis_V1_0_6_Actions_CS;

//
// Contains references to other resources that are related to this resource.
//
typedef struct _RedfishChassis_V1_0_6_Links_CS {
    RedfishCS_Link                        ComputerSystems;               // An array of references to the
                                                                         // computer systems contained in
                                                                         // this chassis.  This will only
                                                                         // reference ComputerSystems that
                                                                         // are directly and wholly
                                                                         // contained in this chassis.
    RedfishCS_int64                       *ComputerSystemsodata_count;
    RedfishCS_Link                        ContainedBy;                   // A reference to the chassis
                                                                         // that this chassis is contained
                                                                         // by.
    RedfishCS_Link                        Contains;                      // An array of references to any
                                                                         // other chassis that this
                                                                         // chassis has in it.
    RedfishCS_int64                       *Containsodata_count;      
    Redfishodata_V4_0_1_idRef_Array_CS    *CooledBy;                     // An array of ID[s] of resources
                                                                         // that cool this chassis.
                                                                         // Normally the ID will be a
                                                                         // chassis or a specific set of
                                                                         // fans.
    RedfishCS_int64                       *CooledByodata_count;      
    RedfishCS_Link                        ManagedBy;                     // An array of references to the
                                                                         // Managers responsible for
                                                                         // managing this chassis.
    RedfishCS_int64                       *ManagedByodata_count;     
    RedfishResource_Oem_CS                *Oem;                          // Oem extension object.
    Redfishodata_V4_0_1_idRef_Array_CS    *PoweredBy;                    // An array of ID[s] of resources
                                                                         // that power this chassis.
                                                                         // Normally the ID will be a
                                                                         // chassis or a specific set of
                                                                         // Power Supplies.
    RedfishCS_int64                       *PoweredByodata_count;     
} RedfishChassis_V1_0_6_Links_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishChassis_V1_0_6_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishChassis_V1_0_6_OemActions_CS;

//
// This action is used to reset the chassis. This action resets the chassis, not
// Systems or other contained resources, although side effects may occur which
// affect those resources.
//
typedef struct _RedfishChassis_V1_0_6_Reset_CS {
    RedfishCS_char    *target;    // Link to invoke action
    RedfishCS_char    *title;    // Friendly action name
} RedfishChassis_V1_0_6_Reset_CS;

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
// A reference to a resource.
//
#ifndef __Redfishodata_V4_0_1_idRef_CS__
#define __Redfishodata_V4_0_1_idRef_CS__
typedef struct _Redfishodata_V4_0_1_idRef_CS {
    RedfishCS_char    *odata_id;
} Redfishodata_V4_0_1_idRef_CS;
#endif

//
// The Chassis schema represents the physical components of a system.  This
// resource represents the sheet-metal confined spaces and logical zones such as
// racks, enclosures, chassis and all other containers. Subsystems (like sensors)
// that operate outside of a system's data plane (meaning the resources are not
// accessible to software running on the system) are linked either directly or
// indirectly through this resource.
//
typedef struct _RedfishChassis_V1_0_6_Chassis_CS {
    RedfishCS_Header                    Header;
    RedfishCS_char                      *odata_context;
    RedfishCS_char                      *odata_id;    
    RedfishCS_char                      *odata_type;  
    RedfishChassis_V1_0_6_Actions_CS    *Actions;         // The available actions for this
                                                          // resource.
    RedfishCS_char                      *AssetTag;        // The user assigned asset tag of
                                                          // this chassis.
    RedfishCS_char                      *ChassisType;     // The type of physical form
                                                          // factor of the chassis.
    RedfishCS_char                      *Description; 
    RedfishCS_char                      *Id;          
    RedfishCS_char                      *IndicatorLED;    // The state of the indicator
                                                          // LED, used to identify the
                                                          // chassis.
    RedfishChassis_V1_0_6_Links_CS      *Links;           // Contains references to other
                                                          // resources that are related to
                                                          // this resource.
    RedfishCS_Link                      LogServices;      // A reference to the logs for
                                                          // this chassis.
    RedfishCS_char                      *Manufacturer;    // The manufacturer of this
                                                          // chassis.
    RedfishCS_char                      *Model;           // The model number of the
                                                          // chassis.
    RedfishCS_char                      *Name;        
    RedfishResource_Oem_CS              *Oem;             // This is the
                                                          // manufacturer/provider specific
                                                          // extension moniker used to
                                                          // divide the Oem object into
                                                          // sections.
    RedfishCS_char                      *PartNumber;      // The part number of the
                                                          // chassis.
    RedfishCS_Link                      Power;            // A reference to the power
                                                          // properties (power supplies,
                                                          // power policies, sensors) of
                                                          // this chassis.
    RedfishCS_char                      *PowerState;      // The current power state of the
                                                          // chassis.
    RedfishCS_char                      *SKU;             // The SKU of the chassis.
    RedfishCS_char                      *SerialNumber;    // The serial number of the
                                                          // chassis.
    RedfishResource_Status_CS           *Status;      
    RedfishCS_Link                      Thermal;          // A reference to the thermal
                                                          // properties (fans, cooling,
                                                          // sensors) of this chassis.
} RedfishChassis_V1_0_6_Chassis_CS;

#ifndef __Redfishodata_V4_0_1_idRef_Array_CS__
#define __Redfishodata_V4_0_1_idRef_Array_CS__
typedef struct _Redfishodata_V4_0_1_idRef_Array_CS  {
    Redfishodata_V4_0_1_idRef_Array_CS    *Next;
    Redfishodata_V4_0_1_idRef_CS    *ArrayValue;
} Redfishodata_V4_0_1_idRef_Array_CS;
#endif

RedfishCS_status
Json_Chassis_V1_0_6_To_CS (char *JsonRawText, RedfishChassis_V1_0_6_Chassis_CS **ReturnedCS);

RedfishCS_status
CS_To_Chassis_V1_0_6_JSON (RedfishChassis_V1_0_6_Chassis_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyChassis_V1_0_6_CS (RedfishChassis_V1_0_6_Chassis_CS *CSPtr);

RedfishCS_status
DestroyChassis_V1_0_6_Json (RedfishCS_char *JsonText);

#endif