//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHSOFTWAREINVENTORY_V1_0_3_CSTRUCT_H_
#define _EFI_REDFISHSOFTWAREINVENTORY_V1_0_3_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_SoftwareInventory_v1_0_3_CS.h"

typedef RedfishSoftwareInventory_V1_0_3_SoftwareInventory_CS EFI_REDFISH_SOFTWAREINVENTORY_V1_0_3_CS;

RedfishCS_status
Json_SoftwareInventory_V1_0_3_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_SOFTWAREINVENTORY_V1_0_3_CS **ReturnedCs);

RedfishCS_status
CS_To_SoftwareInventory_V1_0_3_JSON (EFI_REDFISH_SOFTWAREINVENTORY_V1_0_3_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroySoftwareInventory_V1_0_3_CS (EFI_REDFISH_SOFTWAREINVENTORY_V1_0_3_CS *CSPtr);

RedfishCS_status
DestroySoftwareInventory_V1_0_3_Json (RedfishCS_char *JsonText);

#endif
