//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishZone_V1_0_3_CSTRUCT_H_
#define _RedfishZone_V1_0_3_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

typedef struct _RedfishZone_V1_0_3_Links_CS RedfishZone_V1_0_3_Links_CS;
typedef struct _RedfishZone_V1_0_3_Zone_CS RedfishZone_V1_0_3_Zone_CS;
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
// Contains references to other resources that are related to this resource.
//
typedef struct _RedfishZone_V1_0_3_Links_CS {
    RedfishCS_Link            Endpoints;                      // Represents an array of
                                                              // references to the endpoints
                                                              // that are contained in this
                                                              // zone.
    RedfishCS_int64           *Endpointsodata_count;      
    RedfishCS_Link            InvolvedSwitches;               // Represents an array of
                                                              // references to the switches in
                                                              // this zone.
    RedfishCS_int64           *InvolvedSwitchesodata_count;
    RedfishResource_Oem_CS    *Oem;                           // Oem extension object.
} RedfishZone_V1_0_3_Links_CS;

//
// The Zone schema represents a fabric zone.
//
typedef struct _RedfishZone_V1_0_3_Zone_CS {
    RedfishCS_Header               Header;
    RedfishCS_char                 *odata_context;
    RedfishCS_char                 *odata_etag;  
    RedfishCS_char                 *odata_id;    
    RedfishCS_char                 *odata_type;  
    RedfishCS_char                 *Description; 
    RedfishCS_char                 *Id;          
    RedfishZone_V1_0_3_Links_CS    *Links;           // Contains references to other
                                                     // resources that are related to
                                                     // this resource.
    RedfishCS_char                 *Name;        
    RedfishResource_Oem_CS         *Oem;             // This is the
                                                     // manufacturer/provider specific
                                                     // extension moniker used to
                                                     // divide the Oem object into
                                                     // sections.
    RedfishResource_Status_CS      *Status;          // This property describes the
                                                     // status and health of the
                                                     // resource and its children.
} RedfishZone_V1_0_3_Zone_CS;

RedfishCS_status
Json_Zone_V1_0_3_To_CS (char *JsonRawText, RedfishZone_V1_0_3_Zone_CS **ReturnedCS);

RedfishCS_status
CS_To_Zone_V1_0_3_JSON (RedfishZone_V1_0_3_Zone_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyZone_V1_0_3_CS (RedfishZone_V1_0_3_Zone_CS *CSPtr);

RedfishCS_status
DestroyZone_V1_0_3_Json (RedfishCS_char *JsonText);

#endif
