//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHSESSIONCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHSESSIONCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_SessionCollection_CS.h"

typedef RedfishSessionCollection_SessionCollection_CS EFI_REDFISH_SESSIONCOLLECTION_CS;

RedfishCS_status
Json_SessionCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_SESSIONCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_SessionCollection_JSON (EFI_REDFISH_SESSIONCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroySessionCollection_CS (EFI_REDFISH_SESSIONCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroySessionCollection_Json (RedfishCS_char *JsonText);

#endif
