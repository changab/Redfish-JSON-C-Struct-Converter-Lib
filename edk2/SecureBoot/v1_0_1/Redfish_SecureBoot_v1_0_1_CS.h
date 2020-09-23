//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHSECUREBOOT_V1_0_1_CSTRUCT_H_
#define _EFI_REDFISHSECUREBOOT_V1_0_1_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_SecureBoot_v1_0_1_CS.h"

typedef RedfishSecureBoot_V1_0_1_SecureBoot_CS EFI_REDFISH_SECUREBOOT_V1_0_1_CS;

RedfishCS_status
Json_SecureBoot_V1_0_1_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_SECUREBOOT_V1_0_1_CS **ReturnedCs);

RedfishCS_status
CS_To_SecureBoot_V1_0_1_JSON (EFI_REDFISH_SECUREBOOT_V1_0_1_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroySecureBoot_V1_0_1_CS (EFI_REDFISH_SECUREBOOT_V1_0_1_CS *CSPtr);

RedfishCS_status
DestroySecureBoot_V1_0_1_Json (RedfishCS_char *JsonText);

#endif