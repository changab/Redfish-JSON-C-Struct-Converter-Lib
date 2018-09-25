//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishHostinterface_V1_0_2_CSTRUCT_H_
#define _RedfishHostinterface_V1_0_2_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishHostInterface_V1_0_2_HostInterface_CS RedfishHostInterface_V1_0_2_HostInterface_CS;
typedef struct _RedfishHostInterface_V1_0_2_Links_CS RedfishHostInterface_V1_0_2_Links_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

//
// References to other resources that are related to this resource.
//
typedef struct _RedfishHostInterface_V1_0_2_Links_CS {
    RedfishCS_Link            ComputerSystems;               // An array of references to the
                                                             // Computer Systems connected to
                                                             // this Host Interface.
    RedfishCS_int64           *ComputerSystemsodata_count;
    RedfishCS_Link            FirmwareAuthRole;              // A reference to the Role that
                                                             // has firmware authentication
                                                             // privileges on this Host
                                                             // Interface.
    RedfishCS_Link            KernelAuthRole;                // A reference to the Role object
                                                             // defining Privileges for this
                                                             // Host Interface when using
                                                             // kernel authentication.
    RedfishResource_Oem_CS    *Oem;                          // Oem extension object.
} RedfishHostInterface_V1_0_2_Links_CS;

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
// This schema defines a single Host Interface resource.
//
typedef struct _RedfishHostInterface_V1_0_2_HostInterface_CS {
    RedfishCS_Header                        Header;
    RedfishCS_char                          *odata_context;         
    RedfishCS_char                          *odata_etag;            
    RedfishCS_char                          *odata_id;              
    RedfishCS_char                          *odata_type;            
    RedfishCS_char_Array                    *AuthenticationModes;       // Indicates the authentication
                                                                        // modes available on this
                                                                        // interface.
    RedfishCS_char                          *Description;           
    RedfishCS_bool                          *ExternallyAccessible;      // Indicates whether this
                                                                        // interface is accessible by
                                                                        // external entities.
    RedfishCS_bool                          *FirmwareAuthEnabled;       // Indicates whether this
                                                                        // firmware authentication is
                                                                        // enabled for this interface.
    RedfishCS_char                          *FirmwareAuthRoleId;        // The Role used for firmware
                                                                        // authentication on this
                                                                        // interface.
    RedfishCS_Link                          HostEthernetInterfaces;     // The Redfish link to the
                                                                        // collection of network
                                                                        // interface controllers or cards
                                                                        // (NICs) that a Computer System
                                                                        // uses to communicate with this
                                                                        // Host Interface.
    RedfishCS_char                          *HostInterfaceType;         // Indicates the Host Interface
                                                                        // type for this interface.
    RedfishCS_char                          *Id;                    
    RedfishCS_bool                          *InterfaceEnabled;          // Indicates whether this
                                                                        // interface is enabled.
    RedfishCS_bool                          *KernelAuthEnabled;         // Indicates whether this kernel
                                                                        // authentication is enabled for
                                                                        // this interface.
    RedfishCS_char                          *KernelAuthRoleId;          // The Role used for kernel
                                                                        // authentication on this
                                                                        // interface.
    RedfishHostInterface_V1_0_2_Links_CS    *Links;                     // Contains references to other
                                                                        // resources that are related to
                                                                        // this resource.
    RedfishCS_Link                          ManagerEthernetInterface;    // The Redfish link to a single
                                                                        // network interface controllers
                                                                        // or cards (NIC) that this
                                                                        // Manager uses for network
                                                                        // communication with this Host
                                                                        // Interface.
    RedfishCS_char                          *Name;                  
    RedfishCS_Link                          NetworkProtocol;            // The Redfish link to the
                                                                        // network services and their
                                                                        // settings that the Manager
                                                                        // controls.  It is here that
                                                                        // clients will find network
                                                                        // configuration options as well
                                                                        // as network services.
    RedfishResource_Oem_CS                  *Oem;                       // This is the
                                                                        // manufacturer/provider specific
                                                                        // extension moniker used to
                                                                        // divide the Oem object into
                                                                        // sections.
    RedfishResource_Status_CS               *Status;                
} RedfishHostInterface_V1_0_2_HostInterface_CS;

RedfishCS_status
Json_HostInterface_V1_0_2_To_CS (char *JsonRawText, RedfishHostInterface_V1_0_2_HostInterface_CS **ReturnedCS);

RedfishCS_status
CS_To_HostInterface_V1_0_2_JSON (RedfishHostInterface_V1_0_2_HostInterface_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyHostInterface_V1_0_2_CS (RedfishHostInterface_V1_0_2_HostInterface_CS *CSPtr);

RedfishCS_status
DestroyHostInterface_V1_0_2_Json (RedfishCS_char *JsonText);

#endif
