//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHSERVICEROOT_V1_0_6_CSTRUCT_H_
#define _EFI_REDFISHSERVICEROOT_V1_0_6_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_ServiceRoot_v1_0_6_CS.h"

typedef RedfishServiceRoot_V1_0_6_ServiceRoot_CS EFI_REDFISH_SERVICEROOT_V1_0_6_CS;

RedfishCS_status
Json_ServiceRoot_V1_0_6_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_SERVICEROOT_V1_0_6_CS **ReturnedCs);

RedfishCS_status
CS_To_ServiceRoot_V1_0_6_JSON (EFI_REDFISH_SERVICEROOT_V1_0_6_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyServiceRoot_V1_0_6_CS (EFI_REDFISH_SERVICEROOT_V1_0_6_CS *CSPtr);

RedfishCS_status
DestroyServiceRoot_V1_0_6_Json (RedfishCS_char *JsonText);

#endif
