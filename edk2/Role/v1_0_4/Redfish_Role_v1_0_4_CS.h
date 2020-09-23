//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHROLE_V1_0_4_CSTRUCT_H_
#define _EFI_REDFISHROLE_V1_0_4_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_Role_v1_0_4_CS.h"

typedef RedfishRole_V1_0_4_Role_CS EFI_REDFISH_ROLE_V1_0_4_CS;

RedfishCS_status
Json_Role_V1_0_4_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_ROLE_V1_0_4_CS **ReturnedCs);

RedfishCS_status
CS_To_Role_V1_0_4_JSON (EFI_REDFISH_ROLE_V1_0_4_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyRole_V1_0_4_CS (EFI_REDFISH_ROLE_V1_0_4_CS *CSPtr);

RedfishCS_status
DestroyRole_V1_0_4_Json (RedfishCS_char *JsonText);

#endif
