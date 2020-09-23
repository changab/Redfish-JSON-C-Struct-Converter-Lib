//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHACCOUNTSERVICE_V1_0_5_CSTRUCT_H_
#define _EFI_REDFISHACCOUNTSERVICE_V1_0_5_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_AccountService_v1_0_5_CS.h"

typedef RedfishAccountService_V1_0_5_AccountService_CS EFI_REDFISH_ACCOUNTSERVICE_V1_0_5_CS;

RedfishCS_status
Json_AccountService_V1_0_5_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_ACCOUNTSERVICE_V1_0_5_CS **ReturnedCs);

RedfishCS_status
CS_To_AccountService_V1_0_5_JSON (EFI_REDFISH_ACCOUNTSERVICE_V1_0_5_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyAccountService_V1_0_5_CS (EFI_REDFISH_ACCOUNTSERVICE_V1_0_5_CS *CSPtr);

RedfishCS_status
DestroyAccountService_V1_0_5_Json (RedfishCS_char *JsonText);

#endif
