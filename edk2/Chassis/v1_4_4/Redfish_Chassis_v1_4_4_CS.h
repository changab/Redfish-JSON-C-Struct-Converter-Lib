//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHCHASSIS_V1_4_4_CSTRUCT_H_
#define _EFI_REDFISHCHASSIS_V1_4_4_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_Chassis_v1_4_4_CS.h"

typedef RedfishChassis_V1_4_4_Chassis_CS EFI_REDFISH_CHASSIS_V1_4_4_CS;

RedfishCS_status
Json_Chassis_V1_4_4_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_CHASSIS_V1_4_4_CS **ReturnedCs);

RedfishCS_status
CS_To_Chassis_V1_4_4_JSON (EFI_REDFISH_CHASSIS_V1_4_4_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyChassis_V1_4_4_CS (EFI_REDFISH_CHASSIS_V1_4_4_CS *CSPtr);

RedfishCS_status
DestroyChassis_V1_4_4_Json (RedfishCS_char *JsonText);

#endif
