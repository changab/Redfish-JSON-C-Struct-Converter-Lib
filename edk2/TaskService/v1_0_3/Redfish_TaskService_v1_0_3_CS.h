//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHTASKSERVICE_V1_0_3_CSTRUCT_H_
#define _EFI_REDFISHTASKSERVICE_V1_0_3_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_TaskService_v1_0_3_CS.h"

typedef RedfishTaskService_V1_0_3_TaskService_CS EFI_REDFISH_TASKSERVICE_V1_0_3_CS;

RedfishCS_status
Json_TaskService_V1_0_3_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_TASKSERVICE_V1_0_3_CS **ReturnedCs);

RedfishCS_status
CS_To_TaskService_V1_0_3_JSON (EFI_REDFISH_TASKSERVICE_V1_0_3_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyTaskService_V1_0_3_CS (EFI_REDFISH_TASKSERVICE_V1_0_3_CS *CSPtr);

RedfishCS_status
DestroyTaskService_V1_0_3_Json (RedfishCS_char *JsonText);

#endif
