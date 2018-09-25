//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishHostinterface_V1_1_0_CSTRUCT_H_
#define _RedfishHostinterface_V1_1_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishHostInterface_V1_1_0_HostInterface_CS RedfishHostInterface_V1_1_0_HostInterface_CS;
typedef struct _RedfishHostInterface_V1_1_0_HostInterface_Actions_CS RedfishHostInterface_V1_1_0_HostInterface_Actions_CS;
typedef struct _RedfishHostInterface_V1_1_0_HostInterface_Actions_Oem_CS RedfishHostInterface_V1_1_0_HostInterface_Actions_Oem_CS;
typedef struct _RedfishHostInterface_V1_1_0_HostInterface_Links_CS RedfishHostInterface_V1_1_0_HostInterface_Links_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishHostInterface_V1_1_0_HostInterface_Actions_CS {
    RedfishHostInterface_V1_1_0_HostInterface_Actions_Oem_CS    *Oem;    // The available OEM specific
                                                                        // actions for this resource.
} RedfishHostInterface_V1_1_0_HostInterface_Actions_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishHostInterface_V1_1_0_HostInterface_Actions_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishHostInterface_V1_1_0_HostInterface_Actions_Oem_CS;

//
// Contains references to other resources that are related to this resource.
//
typedef struct _RedfishHostInterface_V1_1_0_HostInterface_Links_CS {
    RedfishCS_Link            ComputerSystems;                        // An array of references to the
                                                                      // Computer Systems connected to
                                                                      // this Host Interface.
    RedfishCS_int64           *ComputerSystemsodata_count;        
    RedfishCS_char            *ComputerSystemsodata_navigationLink;
    RedfishCS_Link            FirmwareAuthRole;                       // A reference to the Role object
                                                                      // defining Privileges for this
                                                                      // Host Interface when using
                                                                      // firmware authentication.
    RedfishCS_Link            KernelAuthRole;                         // A reference to the Role object
                                                                      // defining Privileges for this
                                                                      // Host Interface when using
                                                                      // kernel authentication.
    RedfishResource_Oem_CS    *Oem;                                   // Oem extension object.
} RedfishHostInterface_V1_1_0_HostInterface_Links_CS;

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
// This schema defines a Host Interface resource.
//
typedef struct _RedfishHostInterface_V1_1_0_HostInterface_CS {
    RedfishCS_Header                                        Header;
    RedfishCS_char                                          *odata_context;         
    RedfishCS_char                                          *odata_id;              
    RedfishCS_char                                          *odata_type;            
    RedfishHostInterface_V1_1_0_HostInterface_Actions_CS    *Actions;                   // The available actions for this
                                                                                        // resource.
    RedfishCS_char_Array                                    *AuthenticationModes;       // This indicates the
                                                                                        // authentication modes available
                                                                                        // on this interface.
    RedfishCS_char                                          *Description;           
    RedfishCS_bool                                          *ExternallyAccessible;      // This indicates whether this
                                                                                        // interface is accessible by
                                                                                        // external entities.
    RedfishCS_bool                                          *FirmwareAuthEnabled;       // This indicates whether this
                                                                                        // firmware authentication is
                                                                                        // enabled for this interface.
    RedfishCS_char                                          *FirmwareAuthRoleId;        // This property contains the
                                                                                        // Role for firmware
                                                                                        // authentication on this
                                                                                        // interface.
    RedfishCS_Link                                          HostEthernetInterfaces;     // This is a reference to a
                                                                                        // collection of NICs that
                                                                                        // Computer Systems use for
                                                                                        // network communication with
                                                                                        // this Host Interface.
    RedfishCS_char                                          *HostInterfaceType;         // This indicates the Host
                                                                                        // Interface type for this
                                                                                        // interface.
    RedfishCS_char                                          *Id;                    
    RedfishCS_bool                                          *InterfaceEnabled;          // This indicates whether this
                                                                                        // interface is enabled.
    RedfishCS_bool                                          *KernelAuthEnabled;         // This indicates whether this
                                                                                        // kernel authentication is
                                                                                        // enabled for this interface.
    RedfishCS_char                                          *KernelAuthRoleId;          // This property contains the
                                                                                        // Role for kernel authentication
                                                                                        // on this interface.
    RedfishHostInterface_V1_1_0_HostInterface_Links_CS      *Links;                     // Contains references to other
                                                                                        // resources that are related to
                                                                                        // this resource.
    RedfishCS_Link                                          ManagerEthernetInterface;    // This is a reference to a
                                                                                        // single NIC that this Manager
                                                                                        // uses for network communication
                                                                                        // with this Host Interface.
    RedfishCS_char                                          *Name;                  
    RedfishCS_Link                                          NetworkProtocol;            // This is a reference to the
                                                                                        // network services and their
                                                                                        // settings that the Manager
                                                                                        // controls.  It is here that
                                                                                        // clients will find network
                                                                                        // configuration options as well
                                                                                        // as network services.
    RedfishResource_Oem_CS                                  *Oem;                       // This is the
                                                                                        // manufacturer/provider specific
                                                                                        // extension moniker used to
                                                                                        // divide the Oem object into
                                                                                        // sections.
    RedfishResource_Status_CS                               *Status;                
} RedfishHostInterface_V1_1_0_HostInterface_CS;

RedfishCS_status
Json_HostInterface_V1_1_0_To_CS (char *JsonRawText, RedfishHostInterface_V1_1_0_HostInterface_CS **ReturnedCS);

RedfishCS_status
CS_To_HostInterface_V1_1_0_JSON (RedfishHostInterface_V1_1_0_HostInterface_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyHostInterface_V1_1_0_CS (RedfishHostInterface_V1_1_0_HostInterface_CS *CSPtr);

RedfishCS_status
DestroyHostInterface_V1_1_0_Json (RedfishCS_char *JsonText);

#endif
