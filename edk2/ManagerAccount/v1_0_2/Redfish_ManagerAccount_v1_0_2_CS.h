//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHMANAGERACCOUNT_V1_0_2_CSTRUCT_H_
#define _EFI_REDFISHMANAGERACCOUNT_V1_0_2_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_ManagerAccount_v1_0_2_CS.h"

typedef RedfishManagerAccount_V1_0_2_ManagerAccount_CS EFI_REDFISH_MANAGERACCOUNT_V1_0_2_CS;

RedfishCS_status
Json_ManagerAccount_V1_0_2_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_MANAGERACCOUNT_V1_0_2_CS **ReturnedCs);

RedfishCS_status
CS_To_ManagerAccount_V1_0_2_JSON (EFI_REDFISH_MANAGERACCOUNT_V1_0_2_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyManagerAccount_V1_0_2_CS (EFI_REDFISH_MANAGERACCOUNT_V1_0_2_CS *CSPtr);

RedfishCS_status
DestroyManagerAccount_V1_0_2_Json (RedfishCS_char *JsonText);

#endif
