//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHSWITCHCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHSWITCHCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_SwitchCollection_CS.h"

typedef RedfishSwitchCollection_SwitchCollection_CS EFI_REDFISH_SWITCHCOLLECTION_CS;

RedfishCS_status
Json_SwitchCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_SWITCHCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_SwitchCollection_JSON (EFI_REDFISH_SWITCHCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroySwitchCollection_CS (EFI_REDFISH_SWITCHCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroySwitchCollection_Json (RedfishCS_char *JsonText);

#endif
