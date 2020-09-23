//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHTASKCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHTASKCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_TaskCollection_CS.h"

typedef RedfishTaskCollection_TaskCollection_CS EFI_REDFISH_TASKCOLLECTION_CS;

RedfishCS_status
Json_TaskCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_TASKCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_TaskCollection_JSON (EFI_REDFISH_TASKCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyTaskCollection_CS (EFI_REDFISH_TASKCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyTaskCollection_Json (RedfishCS_char *JsonText);

#endif
