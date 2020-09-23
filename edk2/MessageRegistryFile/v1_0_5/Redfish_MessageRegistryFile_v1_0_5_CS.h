//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHMESSAGEREGISTRYFILE_V1_0_5_CSTRUCT_H_
#define _EFI_REDFISHMESSAGEREGISTRYFILE_V1_0_5_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_MessageRegistryFile_v1_0_5_CS.h"

typedef RedfishMessageRegistryFile_V1_0_5_MessageRegistryFile_CS EFI_REDFISH_MESSAGEREGISTRYFILE_V1_0_5_CS;

RedfishCS_status
Json_MessageRegistryFile_V1_0_5_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_MESSAGEREGISTRYFILE_V1_0_5_CS **ReturnedCs);

RedfishCS_status
CS_To_MessageRegistryFile_V1_0_5_JSON (EFI_REDFISH_MESSAGEREGISTRYFILE_V1_0_5_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyMessageRegistryFile_V1_0_5_CS (EFI_REDFISH_MESSAGEREGISTRYFILE_V1_0_5_CS *CSPtr);

RedfishCS_status
DestroyMessageRegistryFile_V1_0_5_Json (RedfishCS_char *JsonText);

#endif