//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishSecureboot_V1_0_1_CSTRUCT_H_
#define _RedfishSecureboot_V1_0_1_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

typedef struct _RedfishSecureBoot_V1_0_1_ResetKeys_CS RedfishSecureBoot_V1_0_1_ResetKeys_CS;
typedef struct _RedfishSecureBoot_V1_0_1_SecureBoot_CS RedfishSecureBoot_V1_0_1_SecureBoot_CS;
typedef struct _RedfishSecureBoot_V1_0_1_SecureBoot_Actions_CS RedfishSecureBoot_V1_0_1_SecureBoot_Actions_CS;
typedef struct _RedfishSecureBoot_V1_0_1_SecureBoot_Actions_Oem_CS RedfishSecureBoot_V1_0_1_SecureBoot_Actions_Oem_CS;
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
// This action is used to reset the Secure Boot keys.
//
typedef struct _RedfishSecureBoot_V1_0_1_ResetKeys_CS {
    RedfishCS_char    *target;    // Link to invoke action
    RedfishCS_char    *title;    // Friendly action name
} RedfishSecureBoot_V1_0_1_ResetKeys_CS;

//
// The available actions for this resource.
//
typedef struct _RedfishSecureBoot_V1_0_1_SecureBoot_Actions_CS {
    RedfishSecureBoot_V1_0_1_ResetKeys_CS                 *SecureBoot_ResetKeys;
    RedfishSecureBoot_V1_0_1_SecureBoot_Actions_Oem_CS    *Oem;                
} RedfishSecureBoot_V1_0_1_SecureBoot_Actions_CS;

typedef struct _RedfishSecureBoot_V1_0_1_SecureBoot_Actions_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishSecureBoot_V1_0_1_SecureBoot_Actions_Oem_CS;

//
// This resource contains UEFI Secure Boot information. It represents properties
// for managing the UEFI Secure Boot functionality of a system.
//
typedef struct _RedfishSecureBoot_V1_0_1_SecureBoot_CS {
    RedfishCS_Header                                  Header;
    RedfishCS_char                                    *odata_context;       
    RedfishCS_char                                    *odata_id;            
    RedfishCS_char                                    *odata_type;          
    RedfishSecureBoot_V1_0_1_SecureBoot_Actions_CS    *Actions;                 // The available actions for this
                                                                                // resource.
    RedfishCS_char                                    *Description;         
    RedfishCS_char                                    *Id;                  
    RedfishCS_char                                    *Name;                
    RedfishResource_Oem_CS                            *Oem;                     // This is the
                                                                                // manufacturer/provider specific
                                                                                // extension moniker used to
                                                                                // divide the Oem object into
                                                                                // sections.
    RedfishCS_char                                    *SecureBootCurrentBoot;    // Secure Boot state during the
                                                                                // current boot cycle.
    RedfishCS_bool                                    *SecureBootEnable;        // Enable or disable UEFI Secure
                                                                                // Boot (takes effect on next
                                                                                // boot).
    RedfishCS_char                                    *SecureBootMode;          // Current Secure Boot Mode.
} RedfishSecureBoot_V1_0_1_SecureBoot_CS;

RedfishCS_status
Json_SecureBoot_V1_0_1_To_CS (char *JsonRawText, RedfishSecureBoot_V1_0_1_SecureBoot_CS **ReturnedCS);

RedfishCS_status
CS_To_SecureBoot_V1_0_1_JSON (RedfishSecureBoot_V1_0_1_SecureBoot_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroySecureBoot_V1_0_1_CS (RedfishSecureBoot_V1_0_1_SecureBoot_CS *CSPtr);

RedfishCS_status
DestroySecureBoot_V1_0_1_Json (RedfishCS_char *JsonText);

#endif
