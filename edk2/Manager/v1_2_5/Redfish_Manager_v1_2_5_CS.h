//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHMANAGER_V1_2_5_CSTRUCT_H_
#define _EFI_REDFISHMANAGER_V1_2_5_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_Manager_v1_2_5_CS.h"

typedef RedfishManager_V1_2_5_Manager_CS EFI_REDFISH_MANAGER_V1_2_5_CS;

RedfishCS_status
Json_Manager_V1_2_5_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_MANAGER_V1_2_5_CS **ReturnedCs);

RedfishCS_status
CS_To_Manager_V1_2_5_JSON (EFI_REDFISH_MANAGER_V1_2_5_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyManager_V1_2_5_CS (EFI_REDFISH_MANAGER_V1_2_5_CS *CSPtr);

RedfishCS_status
DestroyManager_V1_2_5_Json (RedfishCS_char *JsonText);

#endif
