//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHHOSTINTERFACE_V1_1_3_CSTRUCT_H_
#define _EFI_REDFISHHOSTINTERFACE_V1_1_3_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_HostInterface_v1_1_3_CS.h"

typedef RedfishHostInterface_V1_1_3_HostInterface_CS EFI_REDFISH_HOSTINTERFACE_V1_1_3_CS;

RedfishCS_status
Json_HostInterface_V1_1_3_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_HOSTINTERFACE_V1_1_3_CS **ReturnedCs);

RedfishCS_status
CS_To_HostInterface_V1_1_3_JSON (EFI_REDFISH_HOSTINTERFACE_V1_1_3_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyHostInterface_V1_1_3_CS (EFI_REDFISH_HOSTINTERFACE_V1_1_3_CS *CSPtr);

RedfishCS_status
DestroyHostInterface_V1_1_3_Json (RedfishCS_char *JsonText);

#endif