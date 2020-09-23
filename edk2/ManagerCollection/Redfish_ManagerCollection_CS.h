//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHMANAGERCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHMANAGERCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_ManagerCollection_CS.h"

typedef RedfishManagerCollection_ManagerCollection_CS EFI_REDFISH_MANAGERCOLLECTION_CS;

RedfishCS_status
Json_ManagerCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_MANAGERCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_ManagerCollection_JSON (EFI_REDFISH_MANAGERCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyManagerCollection_CS (EFI_REDFISH_MANAGERCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyManagerCollection_Json (RedfishCS_char *JsonText);

#endif
