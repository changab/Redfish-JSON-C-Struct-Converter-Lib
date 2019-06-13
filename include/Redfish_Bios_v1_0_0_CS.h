//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishBios_V1_0_0_CSTRUCT_H_
#define _RedfishBios_V1_0_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishBios_V1_0_0_Attributes_CS RedfishBios_V1_0_0_Attributes_CS;
typedef struct _RedfishBios_V1_0_0_Bios_CS RedfishBios_V1_0_0_Bios_CS;
typedef struct _RedfishBios_V1_0_0_Bios_Actions_CS RedfishBios_V1_0_0_Bios_Actions_CS;
typedef struct _RedfishBios_V1_0_0_Bios_Actions_Oem_CS RedfishBios_V1_0_0_Bios_Actions_Oem_CS;
typedef struct _RedfishBios_V1_0_0_ChangePassword_CS RedfishBios_V1_0_0_ChangePassword_CS;
typedef struct _RedfishBios_V1_0_0_ResetBios_CS RedfishBios_V1_0_0_ResetBios_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

typedef struct _RedfishBios_V1_0_0_Attributes_CS {
    RedfishCS_Link    Prop;
} RedfishBios_V1_0_0_Attributes_CS;

//
// The available actions for this resource.
//
typedef struct _RedfishBios_V1_0_0_Bios_Actions_CS {
    RedfishBios_V1_0_0_ChangePassword_CS      *Bios_ChangePassword;
    RedfishBios_V1_0_0_ResetBios_CS           *Bios_ResetBios;    
    RedfishBios_V1_0_0_Bios_Actions_Oem_CS    *Oem;               
} RedfishBios_V1_0_0_Bios_Actions_CS;

typedef struct _RedfishBios_V1_0_0_Bios_Actions_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishBios_V1_0_0_Bios_Actions_Oem_CS;

//
// This action is used to change the BIOS passwords.
//
typedef struct _RedfishBios_V1_0_0_ChangePassword_CS {
    RedfishCS_char    *target;    // Link to invoke action
    RedfishCS_char    *title;    // Friendly action name
} RedfishBios_V1_0_0_ChangePassword_CS;

//
// This action is used to reset the BIOS attributes to default.
//
typedef struct _RedfishBios_V1_0_0_ResetBios_CS {
    RedfishCS_char    *target;    // Link to invoke action
    RedfishCS_char    *title;    // Friendly action name
} RedfishBios_V1_0_0_ResetBios_CS;

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
// Bios contains properties surrounding a BIOS Attribute Registry (where the
// system-specific BIOS attributes are described) and the Actions needed to
// perform changes to BIOS settings, which typically require a system reset to
// apply.
//
typedef struct _RedfishBios_V1_0_0_Bios_CS {
    RedfishCS_Header                      Header;
    RedfishCS_char                        *odata_context;   
    RedfishCS_char                        *odata_id;        
    RedfishCS_char                        *odata_type;      
    RedfishBios_V1_0_0_Bios_Actions_CS    *Actions;             // The available actions for this
                                                                // resource.
    RedfishCS_char                        *AttributeRegistry;    // The Resource ID of the
                                                                // Attribute Registry for the
                                                                // BIOS Attributes resource.
    RedfishBios_V1_0_0_Attributes_CS      *Attributes;          // This is the
                                                                // manufacturer/provider specific
                                                                // list of BIOS attributes.
    RedfishCS_char                        *Description;     
    RedfishCS_char                        *Id;              
    RedfishCS_char                        *Name;            
    RedfishResource_Oem_CS                *Oem;                 // This is the
                                                                // manufacturer/provider specific
                                                                // extension moniker used to
                                                                // divide the Oem object into
                                                                // sections.
} RedfishBios_V1_0_0_Bios_CS;

RedfishCS_status
Json_Bios_V1_0_0_To_CS (char *JsonRawText, RedfishBios_V1_0_0_Bios_CS **ReturnedCS);

RedfishCS_status
CS_To_Bios_V1_0_0_JSON (RedfishBios_V1_0_0_Bios_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyBios_V1_0_0_CS (RedfishBios_V1_0_0_Bios_CS *CSPtr);

RedfishCS_status
DestroyBios_V1_0_0_Json (RedfishCS_char *JsonText);

#endif
