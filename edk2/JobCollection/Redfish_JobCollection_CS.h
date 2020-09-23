//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHJOBCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHJOBCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_JobCollection_CS.h"

typedef RedfishJobCollection_JobCollection_CS EFI_REDFISH_JOBCOLLECTION_CS;

RedfishCS_status
Json_JobCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_JOBCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_JobCollection_JSON (EFI_REDFISH_JOBCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyJobCollection_CS (EFI_REDFISH_JOBCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyJobCollection_Json (RedfishCS_char *JsonText);

#endif
