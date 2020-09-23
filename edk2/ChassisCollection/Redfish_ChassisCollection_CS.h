//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHCHASSISCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHCHASSISCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_ChassisCollection_CS.h"

typedef RedfishChassisCollection_ChassisCollection_CS EFI_REDFISH_CHASSISCOLLECTION_CS;

RedfishCS_status
Json_ChassisCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_CHASSISCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_ChassisCollection_JSON (EFI_REDFISH_CHASSISCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyChassisCollection_CS (EFI_REDFISH_CHASSISCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyChassisCollection_Json (RedfishCS_char *JsonText);

#endif
