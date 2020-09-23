//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHSESSIONSERVICE_V1_0_2_CSTRUCT_H_
#define _EFI_REDFISHSESSIONSERVICE_V1_0_2_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_SessionService_v1_0_2_CS.h"

typedef RedfishSessionService_V1_0_2_SessionService_CS EFI_REDFISH_SESSIONSERVICE_V1_0_2_CS;

RedfishCS_status
Json_SessionService_V1_0_2_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_SESSIONSERVICE_V1_0_2_CS **ReturnedCs);

RedfishCS_status
CS_To_SessionService_V1_0_2_JSON (EFI_REDFISH_SESSIONSERVICE_V1_0_2_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroySessionService_V1_0_2_CS (EFI_REDFISH_SESSIONSERVICE_V1_0_2_CS *CSPtr);

RedfishCS_status
DestroySessionService_V1_0_2_Json (RedfishCS_char *JsonText);

#endif
