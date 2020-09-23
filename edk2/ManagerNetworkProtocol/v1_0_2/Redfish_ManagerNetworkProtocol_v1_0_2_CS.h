//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHMANAGERNETWORKPROTOCOL_V1_0_2_CSTRUCT_H_
#define _EFI_REDFISHMANAGERNETWORKPROTOCOL_V1_0_2_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_ManagerNetworkProtocol_v1_0_2_CS.h"

typedef RedfishManagerNetworkProtocol_V1_0_2_ManagerNetworkProtocol_CS EFI_REDFISH_MANAGERNETWORKPROTOCOL_V1_0_2_CS;

RedfishCS_status
Json_ManagerNetworkProtocol_V1_0_2_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_MANAGERNETWORKPROTOCOL_V1_0_2_CS **ReturnedCs);

RedfishCS_status
CS_To_ManagerNetworkProtocol_V1_0_2_JSON (EFI_REDFISH_MANAGERNETWORKPROTOCOL_V1_0_2_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyManagerNetworkProtocol_V1_0_2_CS (EFI_REDFISH_MANAGERNETWORKPROTOCOL_V1_0_2_CS *CSPtr);

RedfishCS_status
DestroyManagerNetworkProtocol_V1_0_2_Json (RedfishCS_char *JsonText);

#endif
