//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHTHERMAL_V1_2_4_CSTRUCT_H_
#define _EFI_REDFISHTHERMAL_V1_2_4_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_Thermal_v1_2_4_CS.h"

typedef RedfishThermal_V1_2_4_Thermal_CS EFI_REDFISH_THERMAL_V1_2_4_CS;

RedfishCS_status
Json_Thermal_V1_2_4_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_THERMAL_V1_2_4_CS **ReturnedCs);

RedfishCS_status
CS_To_Thermal_V1_2_4_JSON (EFI_REDFISH_THERMAL_V1_2_4_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyThermal_V1_2_4_CS (EFI_REDFISH_THERMAL_V1_2_4_CS *CSPtr);

RedfishCS_status
DestroyThermal_V1_2_4_Json (RedfishCS_char *JsonText);

#endif
