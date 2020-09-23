//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHBIOS_V1_0_0_CSTRUCT_H_
#define _EFI_REDFISHBIOS_V1_0_0_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_Bios_v1_0_0_CS.h"

typedef RedfishBios_V1_0_0_Bios_CS EFI_REDFISH_BIOS_V1_0_0_CS;

RedfishCS_status
Json_Bios_V1_0_0_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_BIOS_V1_0_0_CS **ReturnedCs);

RedfishCS_status
CS_To_Bios_V1_0_0_JSON (EFI_REDFISH_BIOS_V1_0_0_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyBios_V1_0_0_CS (EFI_REDFISH_BIOS_V1_0_0_CS *CSPtr);

RedfishCS_status
DestroyBios_V1_0_0_Json (RedfishCS_char *JsonText);

#endif
