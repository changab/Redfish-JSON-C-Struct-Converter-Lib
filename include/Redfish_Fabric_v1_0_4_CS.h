//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishFabric_V1_0_4_CSTRUCT_H_
#define _RedfishFabric_V1_0_4_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishFabric_V1_0_4_Actions_CS RedfishFabric_V1_0_4_Actions_CS;
typedef struct _RedfishFabric_V1_0_4_Fabric_CS RedfishFabric_V1_0_4_Fabric_CS;
typedef struct _RedfishFabric_V1_0_4_Links_CS RedfishFabric_V1_0_4_Links_CS;
typedef struct _RedfishFabric_V1_0_4_OemActions_CS RedfishFabric_V1_0_4_OemActions_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishFabric_V1_0_4_Actions_CS {
    RedfishFabric_V1_0_4_OemActions_CS    *Oem;    // This property contains the
                                                  // available OEM specific actions
                                                  // for this resource.
} RedfishFabric_V1_0_4_Actions_CS;

//
// Contains references to other resources that are related to this resource.
//
typedef struct _RedfishFabric_V1_0_4_Links_CS {
    RedfishResource_Oem_CS    *Oem;    // Oem extension object.
} RedfishFabric_V1_0_4_Links_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishFabric_V1_0_4_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishFabric_V1_0_4_OemActions_CS;

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
// The Fabric schema represents a simple fabric consisting of one or more
// switches, zero or more endpoints, and zero or more zones.
//
typedef struct _RedfishFabric_V1_0_4_Fabric_CS {
    RedfishCS_Header                   Header;
    RedfishCS_char                     *odata_context;
    RedfishCS_char                     *odata_etag;  
    RedfishCS_char                     *odata_id;    
    RedfishCS_char                     *odata_type;  
    RedfishFabric_V1_0_4_Actions_CS    *Actions;         // The available actions for this
                                                         // resource.
    RedfishCS_char                     *Description; 
    RedfishCS_Link                     Endpoints;        // A collection of references to
                                                         // the endpoints contained in
                                                         // this fabric.
    RedfishCS_char                     *FabricType;      // The protocol being sent over
                                                         // this fabric.
    RedfishCS_char                     *Id;          
    RedfishFabric_V1_0_4_Links_CS      *Links;           // Contains references to other
                                                         // resources that are related to
                                                         // this resource.
    RedfishCS_int64                    *MaxZones;        // The value of this property
                                                         // shall contain the maximum
                                                         // number of zones the switch can
                                                         // currently configure.
    RedfishCS_char                     *Name;        
    RedfishResource_Oem_CS             *Oem;             // This is the
                                                         // manufacturer/provider specific
                                                         // extension moniker used to
                                                         // divide the Oem object into
                                                         // sections.
    RedfishResource_Status_CS          *Status;          // This property describes the
                                                         // status and health of the
                                                         // resource and its children.
    RedfishCS_Link                     Switches;         // A collection of references to
                                                         // the switches contained in this
                                                         // fabric.
    RedfishCS_Link                     Zones;            // A collection of references to
                                                         // the zones contained in this
                                                         // fabric.
} RedfishFabric_V1_0_4_Fabric_CS;

RedfishCS_status
Json_Fabric_V1_0_4_To_CS (char *JsonRawText, RedfishFabric_V1_0_4_Fabric_CS **ReturnedCS);

RedfishCS_status
CS_To_Fabric_V1_0_4_JSON (RedfishFabric_V1_0_4_Fabric_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyFabric_V1_0_4_CS (RedfishFabric_V1_0_4_Fabric_CS *CSPtr);

RedfishCS_status
DestroyFabric_V1_0_4_Json (RedfishCS_char *JsonText);

#endif
