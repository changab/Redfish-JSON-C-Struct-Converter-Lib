//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHPOWER_V1_2_1_CSTRUCT_H_
#define _EFI_REDFISHPOWER_V1_2_1_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_Power_v1_2_1_CS.h"

typedef RedfishPower_V1_2_1_Power_CS EFI_REDFISH_POWER_V1_2_1_CS;

RedfishCS_status
Json_Power_V1_2_1_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_POWER_V1_2_1_CS **ReturnedCs);

RedfishCS_status
CS_To_Power_V1_2_1_JSON (EFI_REDFISH_POWER_V1_2_1_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyPower_V1_2_1_CS (EFI_REDFISH_POWER_V1_2_1_CS *CSPtr);

RedfishCS_status
DestroyPower_V1_2_1_Json (RedfishCS_char *JsonText);

#endif
