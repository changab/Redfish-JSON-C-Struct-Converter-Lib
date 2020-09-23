//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHLOGSERVICECOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHLOGSERVICECOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_LogServiceCollection_CS.h"

typedef RedfishLogServiceCollection_LogServiceCollection_CS EFI_REDFISH_LOGSERVICECOLLECTION_CS;

RedfishCS_status
Json_LogServiceCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_LOGSERVICECOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_LogServiceCollection_JSON (EFI_REDFISH_LOGSERVICECOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyLogServiceCollection_CS (EFI_REDFISH_LOGSERVICECOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyLogServiceCollection_Json (RedfishCS_char *JsonText);

#endif
