//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHMANAGERACCOUNTCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHMANAGERACCOUNTCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_ManagerAccountCollection_CS.h"

typedef RedfishManagerAccountCollection_ManagerAccountCollection_CS EFI_REDFISH_MANAGERACCOUNTCOLLECTION_CS;

RedfishCS_status
Json_ManagerAccountCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_MANAGERACCOUNTCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_ManagerAccountCollection_JSON (EFI_REDFISH_MANAGERACCOUNTCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyManagerAccountCollection_CS (EFI_REDFISH_MANAGERACCOUNTCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyManagerAccountCollection_Json (RedfishCS_char *JsonText);

#endif
