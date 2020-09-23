//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHDRIVE_V1_0_6_CSTRUCT_H_
#define _EFI_REDFISHDRIVE_V1_0_6_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_Drive_v1_0_6_CS.h"

typedef RedfishDrive_V1_0_6_Drive_CS EFI_REDFISH_DRIVE_V1_0_6_CS;

RedfishCS_status
Json_Drive_V1_0_6_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_DRIVE_V1_0_6_CS **ReturnedCs);

RedfishCS_status
CS_To_Drive_V1_0_6_JSON (EFI_REDFISH_DRIVE_V1_0_6_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyDrive_V1_0_6_CS (EFI_REDFISH_DRIVE_V1_0_6_CS *CSPtr);

RedfishCS_status
DestroyDrive_V1_0_6_Json (RedfishCS_char *JsonText);

#endif