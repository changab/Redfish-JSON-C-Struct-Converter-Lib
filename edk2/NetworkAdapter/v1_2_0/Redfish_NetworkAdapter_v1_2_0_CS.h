//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHNETWORKADAPTER_V1_2_0_CSTRUCT_H_
#define _EFI_REDFISHNETWORKADAPTER_V1_2_0_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_NetworkAdapter_v1_2_0_CS.h"

typedef RedfishNetworkAdapter_V1_2_0_NetworkAdapter_CS EFI_REDFISH_NETWORKADAPTER_V1_2_0_CS;

RedfishCS_status
Json_NetworkAdapter_V1_2_0_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_NETWORKADAPTER_V1_2_0_CS **ReturnedCs);

RedfishCS_status
CS_To_NetworkAdapter_V1_2_0_JSON (EFI_REDFISH_NETWORKADAPTER_V1_2_0_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyNetworkAdapter_V1_2_0_CS (EFI_REDFISH_NETWORKADAPTER_V1_2_0_CS *CSPtr);

RedfishCS_status
DestroyNetworkAdapter_V1_2_0_Json (RedfishCS_char *JsonText);

#endif