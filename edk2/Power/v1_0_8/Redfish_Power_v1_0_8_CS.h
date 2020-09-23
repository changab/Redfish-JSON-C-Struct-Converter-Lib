//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHPOWER_V1_0_8_CSTRUCT_H_
#define _EFI_REDFISHPOWER_V1_0_8_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_Power_v1_0_8_CS.h"

typedef RedfishPower_V1_0_8_Power_CS EFI_REDFISH_POWER_V1_0_8_CS;

RedfishCS_status
Json_Power_V1_0_8_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_POWER_V1_0_8_CS **ReturnedCs);

RedfishCS_status
CS_To_Power_V1_0_8_JSON (EFI_REDFISH_POWER_V1_0_8_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyPower_V1_0_8_CS (EFI_REDFISH_POWER_V1_0_8_CS *CSPtr);

RedfishCS_status
DestroyPower_V1_0_8_Json (RedfishCS_char *JsonText);

#endif
