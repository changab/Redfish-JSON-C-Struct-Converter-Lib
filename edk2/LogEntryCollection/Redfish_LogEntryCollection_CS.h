//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHLOGENTRYCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHLOGENTRYCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_LogEntryCollection_CS.h"

typedef RedfishLogEntryCollection_LogEntryCollection_CS EFI_REDFISH_LOGENTRYCOLLECTION_CS;

RedfishCS_status
Json_LogEntryCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_LOGENTRYCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_LogEntryCollection_JSON (EFI_REDFISH_LOGENTRYCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyLogEntryCollection_CS (EFI_REDFISH_LOGENTRYCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyLogEntryCollection_Json (RedfishCS_char *JsonText);

#endif
