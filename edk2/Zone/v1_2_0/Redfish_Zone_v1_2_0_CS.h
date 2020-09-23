//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHZONE_V1_2_0_CSTRUCT_H_
#define _EFI_REDFISHZONE_V1_2_0_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_Zone_v1_2_0_CS.h"

typedef RedfishZone_V1_2_0_Zone_CS EFI_REDFISH_ZONE_V1_2_0_CS;

RedfishCS_status
Json_Zone_V1_2_0_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_ZONE_V1_2_0_CS **ReturnedCs);

RedfishCS_status
CS_To_Zone_V1_2_0_JSON (EFI_REDFISH_ZONE_V1_2_0_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyZone_V1_2_0_CS (EFI_REDFISH_ZONE_V1_2_0_CS *CSPtr);

RedfishCS_status
DestroyZone_V1_2_0_Json (RedfishCS_char *JsonText);

#endif
