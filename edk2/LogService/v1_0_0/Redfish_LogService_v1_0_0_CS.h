//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHLOGSERVICE_V1_0_0_CSTRUCT_H_
#define _EFI_REDFISHLOGSERVICE_V1_0_0_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_LogService_v1_0_0_CS.h"

typedef RedfishLogService_V1_0_0_LogService_CS EFI_REDFISH_LOGSERVICE_V1_0_0_CS;

RedfishCS_status
Json_LogService_V1_0_0_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_LOGSERVICE_V1_0_0_CS **ReturnedCs);

RedfishCS_status
CS_To_LogService_V1_0_0_JSON (EFI_REDFISH_LOGSERVICE_V1_0_0_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyLogService_V1_0_0_CS (EFI_REDFISH_LOGSERVICE_V1_0_0_CS *CSPtr);

RedfishCS_status
DestroyLogService_V1_0_0_Json (RedfishCS_char *JsonText);

#endif
