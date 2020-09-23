//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHZONECOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHZONECOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_ZoneCollection_CS.h"

typedef RedfishZoneCollection_ZoneCollection_CS EFI_REDFISH_ZONECOLLECTION_CS;

RedfishCS_status
Json_ZoneCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_ZONECOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_ZoneCollection_JSON (EFI_REDFISH_ZONECOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyZoneCollection_CS (EFI_REDFISH_ZONECOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyZoneCollection_Json (RedfishCS_char *JsonText);

#endif
