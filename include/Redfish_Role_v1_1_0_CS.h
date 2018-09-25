//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishRole_V1_1_0_CSTRUCT_H_
#define _RedfishRole_V1_1_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

typedef struct _RedfishRole_V1_1_0_Role_CS RedfishRole_V1_1_0_Role_CS;
typedef struct _RedfishRole_V1_1_0_Role_Actions_CS RedfishRole_V1_1_0_Role_Actions_CS;
typedef struct _RedfishRole_V1_1_0_Role_Actions_Oem_CS RedfishRole_V1_1_0_Role_Actions_Oem_CS;
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
// The available actions for this resource.
//
typedef struct _RedfishRole_V1_1_0_Role_Actions_CS {
    RedfishRole_V1_1_0_Role_Actions_Oem_CS    *Oem;    // The available OEM specific
                                                      // actions for this resource.
} RedfishRole_V1_1_0_Role_Actions_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishRole_V1_1_0_Role_Actions_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishRole_V1_1_0_Role_Actions_Oem_CS;

//
// This resource defines a user role to be used in conjunction with a Manager
// Account.
//
typedef struct _RedfishRole_V1_1_0_Role_CS {
    RedfishCS_Header                      Header;
    RedfishCS_char                        *odata_context;    
    RedfishCS_char                        *odata_id;         
    RedfishCS_char                        *odata_type;       
    RedfishRole_V1_1_0_Role_Actions_CS    *Actions;              // The available actions for this
                                                                 // resource.
    RedfishCS_char_Array                  *AssignedPrivileges;    // The redfish privileges that
                                                                 // this role includes.
    RedfishCS_char                        *Description;      
    RedfishCS_char                        *Id;               
    RedfishCS_bool                        *IsPredefined;         // This property is used to
                                                                 // indicate if the Role is one of
                                                                 // the Redfish Predefined Roles
                                                                 // vs a Custom role.
    RedfishCS_char                        *Name;             
    RedfishResource_Oem_CS                *Oem;                  // This is the
                                                                 // manufacturer/provider specific
                                                                 // extension moniker used to
                                                                 // divide the Oem object into
                                                                 // sections.
    RedfishCS_char_Array                  *OemPrivileges;        // The OEM privileges that this
                                                                 // role includes.
} RedfishRole_V1_1_0_Role_CS;

RedfishCS_status
Json_Role_V1_1_0_To_CS (char *JsonRawText, RedfishRole_V1_1_0_Role_CS **ReturnedCS);

RedfishCS_status
CS_To_Role_V1_1_0_JSON (RedfishRole_V1_1_0_Role_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyRole_V1_1_0_CS (RedfishRole_V1_1_0_Role_CS *CSPtr);

RedfishCS_status
DestroyRole_V1_1_0_Json (RedfishCS_char *JsonText);

#endif
