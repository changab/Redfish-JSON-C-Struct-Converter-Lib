//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishChassis_V1_3_1_CSTRUCT_H_
#define _RedfishChassis_V1_3_1_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __Redfishodata_V4_0_0_idRef_Array_CS__
typedef struct _Redfishodata_V4_0_0_idRef_Array_CS Redfishodata_V4_0_0_idRef_Array_CS;
#endif
typedef struct _RedfishChassis_V1_3_1_Chassis_CS RedfishChassis_V1_3_1_Chassis_CS;
typedef struct _RedfishChassis_V1_3_1_Chassis_Actions_CS RedfishChassis_V1_3_1_Chassis_Actions_CS;
typedef struct _RedfishChassis_V1_3_1_Chassis_Actions_Oem_CS RedfishChassis_V1_3_1_Chassis_Actions_Oem_CS;
typedef struct _RedfishChassis_V1_3_1_Chassis_Links_CS RedfishChassis_V1_3_1_Chassis_Links_CS;
typedef struct _RedfishChassis_V1_3_1_PhysicalSecurity_CS RedfishChassis_V1_3_1_PhysicalSecurity_CS;
typedef struct _RedfishChassis_V1_3_1_Reset_CS RedfishChassis_V1_3_1_Reset_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

#ifndef __RedfishResource_V1_1_0_Location_CS__
typedef struct _RedfishResource_V1_1_0_Location_CS RedfishResource_V1_1_0_Location_CS;
#endif

#ifndef __Redfishodata_V4_0_0_idRef_CS__
typedef struct _Redfishodata_V4_0_0_idRef_CS Redfishodata_V4_0_0_idRef_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishChassis_V1_3_1_Chassis_Actions_CS {
    RedfishChassis_V1_3_1_Reset_CS                  *Chassis_Reset;
    RedfishChassis_V1_3_1_Chassis_Actions_Oem_CS    *Oem;         
} RedfishChassis_V1_3_1_Chassis_Actions_CS;

typedef struct _RedfishChassis_V1_3_1_Chassis_Actions_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishChassis_V1_3_1_Chassis_Actions_Oem_CS;

//
// Contains references to other resources that are related to this resource.
//
typedef struct _RedfishChassis_V1_3_1_Chassis_Links_CS {
    RedfishCS_Link                        ComputerSystems;                          // An array of references to the
                                                                                    // computer systems contained in
                                                                                    // this chassis.  This will only
                                                                                    // reference ComputerSystems that
                                                                                    // are directly and wholly
                                                                                    // contained in this chassis.
    RedfishCS_int64                       *ComputerSystemsodata_count;          
    RedfishCS_char                        *ComputerSystemsodata_navigationLink; 
    RedfishCS_Link                        ContainedBy;                              // A reference to the chassis
                                                                                    // that this chassis is contained
                                                                                    // by.
    RedfishCS_Link                        Contains;                                 // An array of references to any
                                                                                    // other chassis that this
                                                                                    // chassis has in it.
    RedfishCS_int64                       *Containsodata_count;                 
    RedfishCS_char                        *Containsodata_navigationLink;        
    Redfishodata_V4_0_0_idRef_Array_CS    *CooledBy;                                // An array of ID[s] of resources
                                                                                    // that cool this chassis.
                                                                                    // Normally the ID will be a
                                                                                    // chassis or a specific set of
                                                                                    // fans.
    RedfishCS_int64                       *CooledByodata_count;                 
    RedfishCS_char                        *CooledByodata_navigationLink;        
    RedfishCS_Link                        Drives;                                   // An array of references to the
                                                                                    // disk drives located in this
                                                                                    // Chassis.
    RedfishCS_int64                       *Drivesodata_count;                   
    RedfishCS_char                        *Drivesodata_navigationLink;          
    RedfishCS_Link                        ManagedBy;                                // An array of references to the
                                                                                    // Managers responsible for
                                                                                    // managing this chassis.
    RedfishCS_int64                       *ManagedByodata_count;                
    RedfishCS_char                        *ManagedByodata_navigationLink;       
    RedfishCS_Link                        ManagersInChassis;                        // An array of references to the
                                                                                    // managers located in this
                                                                                    // Chassis.
    RedfishCS_int64                       *ManagersInChassisodata_count;        
    RedfishCS_char                        *ManagersInChassisodata_navigationLink;
    RedfishResource_Oem_CS                *Oem;                                     // Oem extension object.
    Redfishodata_V4_0_0_idRef_Array_CS    *PoweredBy;                               // An array of ID[s] of resources
                                                                                    // that power this chassis.
                                                                                    // Normally the ID will be a
                                                                                    // chassis or a specific set of
                                                                                    // Power Supplies.
    RedfishCS_int64                       *PoweredByodata_count;                
    RedfishCS_char                        *PoweredByodata_navigationLink;       
    RedfishCS_Link                        Storage;                                  // An array of references to the
                                                                                    // storage subsystems connected
                                                                                    // to or inside this Chassis.
    RedfishCS_int64                       *Storageodata_count;                  
    RedfishCS_char                        *Storageodata_navigationLink;         
} RedfishChassis_V1_3_1_Chassis_Links_CS;

typedef struct _RedfishChassis_V1_3_1_PhysicalSecurity_CS {
    RedfishCS_char     *IntrusionSensor;         // This indicates the known state
                                                 // of the physical security
                                                 // sensor, such as if it is
                                                 // hardware intrusion detected.
    RedfishCS_int64    *IntrusionSensorNumber;    // A numerical identifier to
                                                 // represent the physical
                                                 // security sensor.
    RedfishCS_char     *IntrusionSensorReArm;    // This indicates how the Normal
                                                 // state to be restored.
} RedfishChassis_V1_3_1_PhysicalSecurity_CS;

//
// This action is used to reset the chassis. This action resets the chassis, not
// Systems or other contained resources, although side effects may occur which
// affect those resources.
//
typedef struct _RedfishChassis_V1_3_1_Reset_CS {
    RedfishCS_char    *target;    // Link to invoke action
    RedfishCS_char    *title;    // Friendly action name
} RedfishChassis_V1_3_1_Reset_CS;

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

#ifndef __RedfishResource_V1_1_0_Location_CS__
#define __RedfishResource_V1_1_0_Location_CS__
typedef struct _RedfishResource_V1_1_0_Location_CS {
    RedfishCS_char            *Info;         // This indicates the location of
                                             // the resource.
    RedfishCS_char            *InfoFormat;    // This represents the format of
                                             // the Info property.
    RedfishResource_Oem_CS    *Oem;      
} RedfishResource_V1_1_0_Location_CS;
#endif

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
// A Chassis represents the physical components for any system.  This resource
// represents the sheet-metal confined spaces and logical zones like racks,
// enclosures, chassis and all other containers. Subsystems (like sensors), which
// operate outside of a system's data plane (meaning the resources are not
// accessible to software running on the system) are linked either directly or
// indirectly through this resource.
//
typedef struct _RedfishChassis_V1_3_1_Chassis_CS {
    RedfishCS_Header                             Header;
    RedfishCS_char                               *odata_context;  
    RedfishCS_char                               *odata_id;       
    RedfishCS_char                               *odata_type;     
    RedfishChassis_V1_3_1_Chassis_Actions_CS     *Actions;            // The available actions for this
                                                                      // resource.
    RedfishCS_char                               *AssetTag;           // The user assigned asset tag
                                                                      // for this chassis.
    RedfishCS_char                               *ChassisType;        // This property indicates the
                                                                      // type of physical form factor
                                                                      // of this resource.
    RedfishCS_char                               *Description;    
    RedfishCS_char                               *Id;             
    RedfishCS_char                               *IndicatorLED;       // The state of the indicator
                                                                      // LED, used to identify the
                                                                      // chassis.
    RedfishChassis_V1_3_1_Chassis_Links_CS       *Links;              // Contains references to other
                                                                      // resources that are related to
                                                                      // this resource.
    RedfishResource_V1_1_0_Location_CS           *Location;       
    RedfishCS_Link                               LogServices;         // A reference to the logs for
                                                                      // this chassis.
    RedfishCS_char                               *Manufacturer;       // This is the manufacturer of
                                                                      // this chassis.
    RedfishCS_char                               *Model;              // This is the model number for
                                                                      // the chassis.
    RedfishCS_char                               *Name;           
    RedfishResource_Oem_CS                       *Oem;                // This is the
                                                                      // manufacturer/provider specific
                                                                      // extension moniker used to
                                                                      // divide the Oem object into
                                                                      // sections.
    RedfishCS_char                               *PartNumber;         // The part number for this
                                                                      // chassis.
    RedfishChassis_V1_3_1_PhysicalSecurity_CS    *PhysicalSecurity;    // The state of the physical
                                                                      // security sensor.
    RedfishCS_Link                               Power;               // A reference to the power
                                                                      // properties (power supplies,
                                                                      // power policies, sensors) for
                                                                      // this chassis.
    RedfishCS_char                               *PowerState;         // This is the current power
                                                                      // state of the chassis.
    RedfishCS_char                               *SKU;                // This is the SKU for this
                                                                      // chassis.
    RedfishCS_char                               *SerialNumber;       // The serial number for this
                                                                      // chassis.
    RedfishResource_Status_CS                    *Status;         
    RedfishCS_Link                               Thermal;             // A reference to the thermal
                                                                      // properties (fans, cooling,
                                                                      // sensors) for this chassis.
} RedfishChassis_V1_3_1_Chassis_CS;

#ifndef __Redfishodata_V4_0_0_idRef_Array_CS__
#define __Redfishodata_V4_0_0_idRef_Array_CS__
typedef struct _Redfishodata_V4_0_0_idRef_Array_CS  {
    Redfishodata_V4_0_0_idRef_Array_CS    *Next;
    Redfishodata_V4_0_0_idRef_CS    *ArrayValue;
} Redfishodata_V4_0_0_idRef_Array_CS;
#endif

RedfishCS_status
Json_Chassis_V1_3_1_To_CS (char *JsonRawText, RedfishChassis_V1_3_1_Chassis_CS **ReturnedCS);

RedfishCS_status
CS_To_Chassis_V1_3_1_JSON (RedfishChassis_V1_3_1_Chassis_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyChassis_V1_3_1_CS (RedfishChassis_V1_3_1_Chassis_CS *CSPtr);

RedfishCS_status
DestroyChassis_V1_3_1_Json (RedfishCS_char *JsonText);

#endif
