//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHSERVICEROOT_V1_0_7_CSTRUCT_H_
#define _EFI_REDFISHSERVICEROOT_V1_0_7_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_ServiceRoot_v1_0_7_CS.h"

typedef RedfishServiceRoot_V1_0_7_ServiceRoot_CS EFI_REDFISH_SERVICEROOT_V1_0_7_CS;

RedfishCS_status
Json_ServiceRoot_V1_0_7_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_SERVICEROOT_V1_0_7_CS **ReturnedCs);

RedfishCS_status
CS_To_ServiceRoot_V1_0_7_JSON (EFI_REDFISH_SERVICEROOT_V1_0_7_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyServiceRoot_V1_0_7_CS (EFI_REDFISH_SERVICEROOT_V1_0_7_CS *CSPtr);

RedfishCS_status
DestroyServiceRoot_V1_0_7_Json (RedfishCS_char *JsonText);

#endif
