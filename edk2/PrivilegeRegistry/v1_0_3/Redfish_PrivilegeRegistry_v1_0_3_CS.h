//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHPRIVILEGEREGISTRY_V1_0_3_CSTRUCT_H_
#define _EFI_REDFISHPRIVILEGEREGISTRY_V1_0_3_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_PrivilegeRegistry_v1_0_3_CS.h"

typedef RedfishPrivilegeRegistry_V1_0_3_PrivilegeRegistry_CS EFI_REDFISH_PRIVILEGEREGISTRY_V1_0_3_CS;

RedfishCS_status
Json_PrivilegeRegistry_V1_0_3_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_PRIVILEGEREGISTRY_V1_0_3_CS **ReturnedCs);

RedfishCS_status
CS_To_PrivilegeRegistry_V1_0_3_JSON (EFI_REDFISH_PRIVILEGEREGISTRY_V1_0_3_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyPrivilegeRegistry_V1_0_3_CS (EFI_REDFISH_PRIVILEGEREGISTRY_V1_0_3_CS *CSPtr);

RedfishCS_status
DestroyPrivilegeRegistry_V1_0_3_Json (RedfishCS_char *JsonText);

#endif
