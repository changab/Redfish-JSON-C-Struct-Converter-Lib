//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHBOOTOPTION_V1_0_0_CSTRUCT_H_
#define _EFI_REDFISHBOOTOPTION_V1_0_0_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_BootOption_v1_0_0_CS.h"

typedef RedfishBootOption_V1_0_0_BootOption_CS EFI_REDFISH_BOOTOPTION_V1_0_0_CS;

RedfishCS_status
Json_BootOption_V1_0_0_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_BOOTOPTION_V1_0_0_CS **ReturnedCs);

RedfishCS_status
CS_To_BootOption_V1_0_0_JSON (EFI_REDFISH_BOOTOPTION_V1_0_0_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyBootOption_V1_0_0_CS (EFI_REDFISH_BOOTOPTION_V1_0_0_CS *CSPtr);

RedfishCS_status
DestroyBootOption_V1_0_0_Json (RedfishCS_char *JsonText);

#endif
