//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishEndpoint_V1_0_1_CSTRUCT_H_
#define _RedfishEndpoint_V1_0_1_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_V1_1_0_Identifier_Array_CS__
typedef struct _RedfishResource_V1_1_0_Identifier_Array_CS RedfishResource_V1_1_0_Identifier_Array_CS;
#endif
typedef struct _RedfishEndpoint_V1_0_1_ConnectedEntity_Array_CS RedfishEndpoint_V1_0_1_ConnectedEntity_Array_CS;
typedef struct _RedfishEndpoint_V1_0_1_ConnectedEntity_CS RedfishEndpoint_V1_0_1_ConnectedEntity_CS;
typedef struct _RedfishEndpoint_V1_0_1_Endpoint_CS RedfishEndpoint_V1_0_1_Endpoint_CS;
typedef struct _RedfishEndpoint_V1_0_1_Endpoint_Actions_CS RedfishEndpoint_V1_0_1_Endpoint_Actions_CS;
typedef struct _RedfishEndpoint_V1_0_1_Endpoint_Links_CS RedfishEndpoint_V1_0_1_Endpoint_Links_CS;
typedef struct _RedfishEndpoint_V1_0_1_PciId_CS RedfishEndpoint_V1_0_1_PciId_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

#ifndef __RedfishResource_V1_1_0_Identifier_CS__
typedef struct _RedfishResource_V1_1_0_Identifier_CS RedfishResource_V1_1_0_Identifier_CS;
#endif

//
// Represents a remote resource that is connected to the network accessible to
// this endpoint.
//
typedef struct _RedfishEndpoint_V1_0_1_ConnectedEntity_CS {
    RedfishCS_Link                                EntityLink;           // A link to the associated
                                                                        // entity.
    RedfishEndpoint_V1_0_1_PciId_CS               *EntityPciId;         // The PCI ID of the connected
                                                                        // entity.
    RedfishCS_char                                *EntityRole;          // The role of the connected
                                                                        // entity.
    RedfishCS_char                                *EntityType;          // The type of the connected
                                                                        // entity.
    RedfishResource_V1_1_0_Identifier_Array_CS    *Identifiers;         // Identifiers for the remote
                                                                        // entity.
    RedfishResource_Oem_CS                        *Oem;             
    RedfishCS_char                                *PciClassCode;        // The Class Code and Subclass
                                                                        // code of this PCIe function.
    RedfishCS_int64                               *PciFunctionNumber;    // The PCI ID of the connected
                                                                        // entity.
} RedfishEndpoint_V1_0_1_ConnectedEntity_CS;

//
// The Actions object contains the available custom actions on this resource.
//
typedef struct _RedfishEndpoint_V1_0_1_Endpoint_Actions_CS {
    RedfishCS_Link    Oem;
} RedfishEndpoint_V1_0_1_Endpoint_Actions_CS;

//
// The links object contains the links to other resources that are related to this
// resource.
//
typedef struct _RedfishEndpoint_V1_0_1_Endpoint_Links_CS {
    RedfishCS_Link            MutuallyExclusiveEndpoints;                        // An array of references to the
                                                                                 // endpoints that may not be used
                                                                                 // in zones if this endpoint is
                                                                                 // used in a zone.
    RedfishCS_int64           *MutuallyExclusiveEndpointsodata_count;        
    RedfishCS_char            *MutuallyExclusiveEndpointsodata_navigationLink;
    RedfishResource_Oem_CS    *Oem;                                              // Oem extension object.
    RedfishCS_Link            Ports;                                             // An array of references to the
                                                                                 // the physical ports associated
                                                                                 // with this endpoint.
    RedfishCS_int64           *Portsodata_count;                             
    RedfishCS_char            *Portsodata_navigationLink;                    
} RedfishEndpoint_V1_0_1_Endpoint_Links_CS;

typedef struct _RedfishEndpoint_V1_0_1_PciId_CS {
    RedfishCS_char    *DeviceId;            // The Device ID of this PCIe
                                            // function.
    RedfishCS_char    *SubsystemId;         // The Subsystem ID of this PCIe
                                            // function.
    RedfishCS_char    *SubsystemVendorId;    // The Subsystem Vendor ID of
                                            // this PCIe function.
    RedfishCS_char    *VendorId;            // The Vendor ID of this PCIe
                                            // function.
} RedfishEndpoint_V1_0_1_PciId_CS;

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

#ifndef __RedfishResource_V1_1_0_Identifier_CS__
#define __RedfishResource_V1_1_0_Identifier_CS__
typedef struct _RedfishResource_V1_1_0_Identifier_CS {
    RedfishCS_char    *DurableName;         // This indicates the world wide,
                                            // persistent name of the
                                            // resource.
    RedfishCS_char    *DurableNameFormat;    // This represents the format of
                                            // the DurableName property.
} RedfishResource_V1_1_0_Identifier_CS;
#endif

//
// This is the schema definition for the Endpoint resource. It represents the
// properties of an entity that sends or receives protocol defined messages over a
// transport.
//
typedef struct _RedfishEndpoint_V1_0_1_Endpoint_CS {
    RedfishCS_Header                                   Header;
    RedfishCS_char                                     *odata_context;                
    RedfishCS_char                                     *odata_id;                     
    RedfishCS_char                                     *odata_type;                   
    RedfishEndpoint_V1_0_1_Endpoint_Actions_CS         *Actions;                          // The Actions object contains
                                                                                          // the available custom actions
                                                                                          // on this resource.
    RedfishEndpoint_V1_0_1_ConnectedEntity_Array_CS    *ConnectedEntities;                // All the entities connected to
                                                                                          // this endpoint.
    RedfishCS_char                                     *Description;                  
    RedfishCS_char                                     *EndpointProtocol;                 // The protocol supported by this
                                                                                          // endpoint.
    RedfishCS_int64                                    *HostReservationMemoryBytes;       // The amount of memory in Bytes
                                                                                          // that the Host should allocate
                                                                                          // to connect to this endpoint.
    RedfishCS_char                                     *Id;                           
    RedfishResource_V1_1_0_Identifier_Array_CS         *Identifiers;                      // Identifiers for this endpoint.
    RedfishEndpoint_V1_0_1_Endpoint_Links_CS           *Links;                            // The links object contains the
                                                                                          // links to other resources that
                                                                                          // are related to this resource.
    RedfishCS_char                                     *Name;                         
    RedfishResource_Oem_CS                             *Oem;                              // This is the
                                                                                          // manufacturer/provider specific
                                                                                          // extension moniker used to
                                                                                          // divide the Oem object into
                                                                                          // sections.
    RedfishEndpoint_V1_0_1_PciId_CS                    *PciId;                            // The PCI ID of the endpoint.
    RedfishCS_Link                                     Redundancy;                        // Redundancy information for the
                                                                                          // lower level endpoints
                                                                                          // supporting this endpoint.
    RedfishCS_int64                                    *Redundancyodata_count;        
    RedfishCS_char                                     *Redundancyodata_navigationLink;
    RedfishResource_Status_CS                          *Status;                       
} RedfishEndpoint_V1_0_1_Endpoint_CS;

#ifndef __RedfishResource_V1_1_0_Identifier_Array_CS__
#define __RedfishResource_V1_1_0_Identifier_Array_CS__
typedef struct _RedfishResource_V1_1_0_Identifier_Array_CS  {
    RedfishResource_V1_1_0_Identifier_Array_CS    *Next;
    RedfishResource_V1_1_0_Identifier_CS    *ArrayValue;
} RedfishResource_V1_1_0_Identifier_Array_CS;
#endif

typedef struct _RedfishEndpoint_V1_0_1_ConnectedEntity_Array_CS  {
    RedfishEndpoint_V1_0_1_ConnectedEntity_Array_CS    *Next;
    RedfishEndpoint_V1_0_1_ConnectedEntity_CS    *ArrayValue;
} RedfishEndpoint_V1_0_1_ConnectedEntity_Array_CS;

RedfishCS_status
Json_Endpoint_V1_0_1_To_CS (char *JsonRawText, RedfishEndpoint_V1_0_1_Endpoint_CS **ReturnedCS);

RedfishCS_status
CS_To_Endpoint_V1_0_1_JSON (RedfishEndpoint_V1_0_1_Endpoint_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyEndpoint_V1_0_1_CS (RedfishEndpoint_V1_0_1_Endpoint_CS *CSPtr);

RedfishCS_status
DestroyEndpoint_V1_0_1_Json (RedfishCS_char *JsonText);

#endif
