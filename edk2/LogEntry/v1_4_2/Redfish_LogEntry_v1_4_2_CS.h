//
// Auto-generated file by Redfish Schema C Structure Generator.
// https://github.com/DMTF/Redfish-Schema-C-Struct-Generator.
//
//  (C) Copyright 2019 Hewlett Packard Enterprise Development LP<BR>
//
//  SPDX-License-Identifier: BSD-2-Clause-Patent
//

#ifndef _EFI_REDFISHLOGENTRY_V1_4_2_CSTRUCT_H_
#define _EFI_REDFISHLOGENTRY_V1_4_2_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_LogEntry_v1_4_2_CS.h"

typedef RedfishLogEntry_V1_4_2_LogEntry_CS EFI_REDFISH_LOGENTRY_V1_4_2_CS;

RedfishCS_status
Json_LogEntry_V1_4_2_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_LOGENTRY_V1_4_2_CS **ReturnedCs);

RedfishCS_status
CS_To_LogEntry_V1_4_2_JSON (EFI_REDFISH_LOGENTRY_V1_4_2_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyLogEntry_V1_4_2_CS (EFI_REDFISH_LOGENTRY_V1_4_2_CS *CSPtr);

RedfishCS_status
DestroyLogEntry_V1_4_2_Json (RedfishCS_char *JsonText);

#endif
