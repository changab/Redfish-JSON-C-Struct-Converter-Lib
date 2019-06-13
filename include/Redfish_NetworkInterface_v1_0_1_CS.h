//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishNetworkinterface_V1_0_1_CSTRUCT_H_
#define _RedfishNetworkinterface_V1_0_1_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishNetworkInterface_V1_0_1_NetworkInterface_CS RedfishNetworkInterface_V1_0_1_NetworkInterface_CS;
typedef struct _RedfishNetworkInterface_V1_0_1_NetworkInterface_Links_CS RedfishNetworkInterface_V1_0_1_NetworkInterface_Links_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

//
// Links.
//
typedef struct _RedfishNetworkInterface_V1_0_1_NetworkInterface_Links_CS {
    RedfishCS_Link            NetworkAdapter;    // Contains the members of this
                                                // collection.
    RedfishResource_Oem_CS    *Oem;             // Oem extension object.
} RedfishNetworkInterface_V1_0_1_NetworkInterface_Links_CS;

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
// A NetworkInterface contains references linking NetworkAdapter, NetworkPort, and
// NetworkDeviceFunction resources and represents the functionality available to
// the containing system.
//
typedef struct _RedfishNetworkInterface_V1_0_1_NetworkInterface_CS {
    RedfishCS_Header                                            Header;
    RedfishCS_char                                              *odata_context;       
    RedfishCS_char                                              *odata_id;            
    RedfishCS_char                                              *odata_type;          
    RedfishCS_char                                              *Description;         
    RedfishCS_char                                              *Id;                  
    RedfishNetworkInterface_V1_0_1_NetworkInterface_Links_CS    *Links;                   // Links.
    RedfishCS_char                                              *Name;                
    RedfishCS_Link                                              NetworkDeviceFunctions;    // Contains the members of this
                                                                                          // collection.
    RedfishCS_Link                                              NetworkPorts;             // Contains the members of this
                                                                                          // collection.
    RedfishResource_Oem_CS                                      *Oem;                     // This is the
                                                                                          // manufacturer/provider specific
                                                                                          // extension moniker used to
                                                                                          // divide the Oem object into
                                                                                          // sections.
    RedfishResource_Status_CS                                   *Status;              
} RedfishNetworkInterface_V1_0_1_NetworkInterface_CS;

RedfishCS_status
Json_NetworkInterface_V1_0_1_To_CS (char *JsonRawText, RedfishNetworkInterface_V1_0_1_NetworkInterface_CS **ReturnedCS);

RedfishCS_status
CS_To_NetworkInterface_V1_0_1_JSON (RedfishNetworkInterface_V1_0_1_NetworkInterface_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyNetworkInterface_V1_0_1_CS (RedfishNetworkInterface_V1_0_1_NetworkInterface_CS *CSPtr);

RedfishCS_status
DestroyNetworkInterface_V1_0_1_Json (RedfishCS_char *JsonText);

#endif
