//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHUPDATESERVICE_V1_1_0_CSTRUCT_H_
#define _EFI_REDFISHUPDATESERVICE_V1_1_0_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_UpdateService_v1_1_0_CS.h"

typedef RedfishUpdateService_V1_1_0_UpdateService_CS EFI_REDFISH_UPDATESERVICE_V1_1_0_CS;

RedfishCS_status
Json_UpdateService_V1_1_0_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_UPDATESERVICE_V1_1_0_CS **ReturnedCs);

RedfishCS_status
CS_To_UpdateService_V1_1_0_JSON (EFI_REDFISH_UPDATESERVICE_V1_1_0_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyUpdateService_V1_1_0_CS (EFI_REDFISH_UPDATESERVICE_V1_1_0_CS *CSPtr);

RedfishCS_status
DestroyUpdateService_V1_1_0_Json (RedfishCS_char *JsonText);

#endif
