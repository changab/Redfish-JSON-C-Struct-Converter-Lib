//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHTASK_V1_2_0_CSTRUCT_H_
#define _EFI_REDFISHTASK_V1_2_0_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_Task_v1_2_0_CS.h"

typedef RedfishTask_V1_2_0_Task_CS EFI_REDFISH_TASK_V1_2_0_CS;

RedfishCS_status
Json_Task_V1_2_0_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_TASK_V1_2_0_CS **ReturnedCs);

RedfishCS_status
CS_To_Task_V1_2_0_JSON (EFI_REDFISH_TASK_V1_2_0_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyTask_V1_2_0_CS (EFI_REDFISH_TASK_V1_2_0_CS *CSPtr);

RedfishCS_status
DestroyTask_V1_2_0_Json (RedfishCS_char *JsonText);

#endif
