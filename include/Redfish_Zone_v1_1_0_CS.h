//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishZone_V1_1_0_CSTRUCT_H_
#define _RedfishZone_V1_1_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

typedef struct _RedfishZone_V1_1_0_Zone_CS RedfishZone_V1_1_0_Zone_CS;
typedef struct _RedfishZone_V1_1_0_Zone_Actions_CS RedfishZone_V1_1_0_Zone_Actions_CS;
typedef struct _RedfishZone_V1_1_0_Zone_Actions_Oem_CS RedfishZone_V1_1_0_Zone_Actions_Oem_CS;
typedef struct _RedfishZone_V1_1_0_Zone_Links_CS RedfishZone_V1_1_0_Zone_Links_CS;
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
typedef struct _RedfishZone_V1_1_0_Zone_Actions_CS {
    RedfishZone_V1_1_0_Zone_Actions_Oem_CS    *Oem;    // The available OEM specific
                                                      // actions for this resource.
} RedfishZone_V1_1_0_Zone_Actions_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishZone_V1_1_0_Zone_Actions_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishZone_V1_1_0_Zone_Actions_Oem_CS;

//
// Contains references to other resources that are related to this resource.
//
typedef struct _RedfishZone_V1_1_0_Zone_Links_CS {
    RedfishCS_Link            Endpoints;                               // An array of references to the
                                                                       // endpoints that are contained
                                                                       // in this zone.
    RedfishCS_int64           *Endpointsodata_count;               
    RedfishCS_char            *Endpointsodata_navigationLink;      
    RedfishCS_Link            InvolvedSwitches;                        // An array of references to the
                                                                       // switchs that are utilized in
                                                                       // this zone.
    RedfishCS_int64           *InvolvedSwitchesodata_count;        
    RedfishCS_char            *InvolvedSwitchesodata_navigationLink;
    RedfishResource_Oem_CS    *Oem;                                    // Oem extension object.
    RedfishCS_Link            ResourceBlocks;                          // An array of references to the
                                                                       // Resource Blocks that are used
                                                                       // in this Zone.
    RedfishCS_int64           *ResourceBlocksodata_count;          
    RedfishCS_char            *ResourceBlocksodata_navigationLink; 
} RedfishZone_V1_1_0_Zone_Links_CS;

//
// Switch contains properties describing a simple fabric zone.
//
typedef struct _RedfishZone_V1_1_0_Zone_CS {
    RedfishCS_Header                      Header;
    RedfishCS_char                        *odata_context;
    RedfishCS_char                        *odata_id;    
    RedfishCS_char                        *odata_type;  
    RedfishZone_V1_1_0_Zone_Actions_CS    *Actions;         // The available actions for this
                                                            // resource.
    RedfishCS_char                        *Description; 
    RedfishCS_char                        *Id;          
    RedfishZone_V1_1_0_Zone_Links_CS      *Links;           // Contains references to other
                                                            // resources that are related to
                                                            // this resource.
    RedfishCS_char                        *Name;        
    RedfishResource_Oem_CS                *Oem;             // This is the
                                                            // manufacturer/provider specific
                                                            // extension moniker used to
                                                            // divide the Oem object into
                                                            // sections.
    RedfishResource_Status_CS             *Status;      
} RedfishZone_V1_1_0_Zone_CS;

RedfishCS_status
Json_Zone_V1_1_0_To_CS (char *JsonRawText, RedfishZone_V1_1_0_Zone_CS **ReturnedCS);

RedfishCS_status
CS_To_Zone_V1_1_0_JSON (RedfishZone_V1_1_0_Zone_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyZone_V1_1_0_CS (RedfishZone_V1_1_0_Zone_CS *CSPtr);

RedfishCS_status
DestroyZone_V1_1_0_Json (RedfishCS_char *JsonText);

#endif
