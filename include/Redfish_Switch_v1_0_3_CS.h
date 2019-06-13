//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishSwitch_V1_0_3_CSTRUCT_H_
#define _RedfishSwitch_V1_0_3_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

typedef struct _RedfishSwitch_V1_0_3_Actions_CS RedfishSwitch_V1_0_3_Actions_CS;
typedef struct _RedfishSwitch_V1_0_3_Links_CS RedfishSwitch_V1_0_3_Links_CS;
typedef struct _RedfishSwitch_V1_0_3_OemActions_CS RedfishSwitch_V1_0_3_OemActions_CS;
typedef struct _RedfishSwitch_V1_0_3_Reset_CS RedfishSwitch_V1_0_3_Reset_CS;
typedef struct _RedfishSwitch_V1_0_3_Switch_CS RedfishSwitch_V1_0_3_Switch_CS;
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
// The available actions for this resource.
//
typedef struct _RedfishSwitch_V1_0_3_Actions_CS {
    RedfishSwitch_V1_0_3_Reset_CS         *Switch_Reset;
    RedfishSwitch_V1_0_3_OemActions_CS    *Oem;        
} RedfishSwitch_V1_0_3_Actions_CS;

//
// Contains references to other resources that are related to this resource.
//
typedef struct _RedfishSwitch_V1_0_3_Links_CS {
    RedfishCS_Link            Chassis;                 // A reference to the chassis
                                                       // which contains this switch.
    RedfishCS_Link            ManagedBy;               // An array of references to the
                                                       // managers that manage this
                                                       // switch.
    RedfishCS_int64           *ManagedByodata_count;
    RedfishResource_Oem_CS    *Oem;                    // Oem extension object.
} RedfishSwitch_V1_0_3_Links_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishSwitch_V1_0_3_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishSwitch_V1_0_3_OemActions_CS;

//
// This action is used to reset this switch.
//
typedef struct _RedfishSwitch_V1_0_3_Reset_CS {
    RedfishCS_char    *target;    // Link to invoke action
    RedfishCS_char    *title;    // Friendly action name
} RedfishSwitch_V1_0_3_Reset_CS;

//
// Switch contains properties describing a simple fabric switch.
//
typedef struct _RedfishSwitch_V1_0_3_Switch_CS {
    RedfishCS_Header                   Header;
    RedfishCS_char                     *odata_context;       
    RedfishCS_char                     *odata_id;            
    RedfishCS_char                     *odata_type;          
    RedfishSwitch_V1_0_3_Actions_CS    *Actions;                 // The available actions for this
                                                                 // resource.
    RedfishCS_char                     *AssetTag;                // The user assigned asset tag
                                                                 // for this switch.
    RedfishCS_char                     *Description;         
    RedfishCS_int64                    *DomainID;                // The Domain ID for this switch.
    RedfishCS_char                     *Id;                  
    RedfishCS_char                     *IndicatorLED;            // The state of the indicator
                                                                 // LED, used to identify the
                                                                 // switch.
    RedfishCS_bool                     *IsManaged;               // This indicates whether the
                                                                 // switch is in a managed or
                                                                 // unmanaged state.
    RedfishSwitch_V1_0_3_Links_CS      *Links;                   // Contains references to other
                                                                 // resources that are related to
                                                                 // this resource.
    RedfishCS_Link                     LogServices;              // A reference to the collection
                                                                 // of Log Services associated
                                                                 // with this system.
    RedfishCS_char                     *Manufacturer;            // This is the manufacturer of
                                                                 // this switch.
    RedfishCS_char                     *Model;                   // The product model number of
                                                                 // this switch.
    RedfishCS_char                     *Name;                
    RedfishResource_Oem_CS             *Oem;                     // This is the
                                                                 // manufacturer/provider specific
                                                                 // extension moniker used to
                                                                 // divide the Oem object into
                                                                 // sections.
    RedfishCS_char                     *PartNumber;              // The part number for this
                                                                 // switch.
    RedfishCS_Link                     Ports;                    // A collection of references to
                                                                 // the ports for this switch.
    RedfishCS_char                     *PowerState;              // This is the current power
                                                                 // state of the switch.
    RedfishCS_Link                     Redundancy;               // Redundancy information for the
                                                                 // switches.
    RedfishCS_int64                    *Redundancyodata_count;
    RedfishCS_char                     *SKU;                     // This is the SKU for this
                                                                 // switch.
    RedfishCS_char                     *SerialNumber;            // The serial number for this
                                                                 // switch.
    RedfishResource_Status_CS          *Status;              
    RedfishCS_char                     *SwitchType;              // The protocol being sent over
                                                                 // this switch.
    RedfishCS_int64                    *TotalSwitchWidth;        // The total number of lanes,
                                                                 // phys, or other physical
                                                                 // transport links that this
                                                                 // switch contains.
} RedfishSwitch_V1_0_3_Switch_CS;

RedfishCS_status
Json_Switch_V1_0_3_To_CS (char *JsonRawText, RedfishSwitch_V1_0_3_Switch_CS **ReturnedCS);

RedfishCS_status
CS_To_Switch_V1_0_3_JSON (RedfishSwitch_V1_0_3_Switch_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroySwitch_V1_0_3_CS (RedfishSwitch_V1_0_3_Switch_CS *CSPtr);

RedfishCS_status
DestroySwitch_V1_0_3_Json (RedfishCS_char *JsonText);

#endif
