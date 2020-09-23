//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHVIRTUALMEDIA_V1_2_1_CSTRUCT_H_
#define _EFI_REDFISHVIRTUALMEDIA_V1_2_1_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_VirtualMedia_v1_2_1_CS.h"

typedef RedfishVirtualMedia_V1_2_1_VirtualMedia_CS EFI_REDFISH_VIRTUALMEDIA_V1_2_1_CS;

RedfishCS_status
Json_VirtualMedia_V1_2_1_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_VIRTUALMEDIA_V1_2_1_CS **ReturnedCs);

RedfishCS_status
CS_To_VirtualMedia_V1_2_1_JSON (EFI_REDFISH_VIRTUALMEDIA_V1_2_1_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyVirtualMedia_V1_2_1_CS (EFI_REDFISH_VIRTUALMEDIA_V1_2_1_CS *CSPtr);

RedfishCS_status
DestroyVirtualMedia_V1_2_1_Json (RedfishCS_char *JsonText);

#endif
