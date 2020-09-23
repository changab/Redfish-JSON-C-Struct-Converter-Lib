//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHFABRIC_V1_0_1_CSTRUCT_H_
#define _EFI_REDFISHFABRIC_V1_0_1_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_Fabric_v1_0_1_CS.h"

typedef RedfishFabric_V1_0_1_Fabric_CS EFI_REDFISH_FABRIC_V1_0_1_CS;

RedfishCS_status
Json_Fabric_V1_0_1_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_FABRIC_V1_0_1_CS **ReturnedCs);

RedfishCS_status
CS_To_Fabric_V1_0_1_JSON (EFI_REDFISH_FABRIC_V1_0_1_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyFabric_V1_0_1_CS (EFI_REDFISH_FABRIC_V1_0_1_CS *CSPtr);

RedfishCS_status
DestroyFabric_V1_0_1_Json (RedfishCS_char *JsonText);

#endif