//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHROLECOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHROLECOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_RoleCollection_CS.h"

typedef RedfishRoleCollection_RoleCollection_CS EFI_REDFISH_ROLECOLLECTION_CS;

RedfishCS_status
Json_RoleCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_ROLECOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_RoleCollection_JSON (EFI_REDFISH_ROLECOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyRoleCollection_CS (EFI_REDFISH_ROLECOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyRoleCollection_Json (RedfishCS_char *JsonText);

#endif
