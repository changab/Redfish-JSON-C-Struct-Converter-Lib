//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHTHERMAL_V1_3_0_CSTRUCT_H_
#define _EFI_REDFISHTHERMAL_V1_3_0_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_Thermal_v1_3_0_CS.h"

typedef RedfishThermal_V1_3_0_Thermal_CS EFI_REDFISH_THERMAL_V1_3_0_CS;

RedfishCS_status
Json_Thermal_V1_3_0_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_THERMAL_V1_3_0_CS **ReturnedCs);

RedfishCS_status
CS_To_Thermal_V1_3_0_JSON (EFI_REDFISH_THERMAL_V1_3_0_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyThermal_V1_3_0_CS (EFI_REDFISH_THERMAL_V1_3_0_CS *CSPtr);

RedfishCS_status
DestroyThermal_V1_3_0_Json (RedfishCS_char *JsonText);

#endif
