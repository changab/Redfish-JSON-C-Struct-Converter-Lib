//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHSESSION_V1_0_3_CSTRUCT_H_
#define _EFI_REDFISHSESSION_V1_0_3_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_Session_v1_0_3_CS.h"

typedef RedfishSession_V1_0_3_Session_CS EFI_REDFISH_SESSION_V1_0_3_CS;

RedfishCS_status
Json_Session_V1_0_3_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_SESSION_V1_0_3_CS **ReturnedCs);

RedfishCS_status
CS_To_Session_V1_0_3_JSON (EFI_REDFISH_SESSION_V1_0_3_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroySession_V1_0_3_CS (EFI_REDFISH_SESSION_V1_0_3_CS *CSPtr);

RedfishCS_status
DestroySession_V1_0_3_Json (RedfishCS_char *JsonText);

#endif
