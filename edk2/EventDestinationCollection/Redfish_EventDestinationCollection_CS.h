//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHEVENTDESTINATIONCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHEVENTDESTINATIONCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_EventDestinationCollection_CS.h"

typedef RedfishEventDestinationCollection_EventDestinationCollection_CS EFI_REDFISH_EVENTDESTINATIONCOLLECTION_CS;

RedfishCS_status
Json_EventDestinationCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_EVENTDESTINATIONCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_EventDestinationCollection_JSON (EFI_REDFISH_EVENTDESTINATIONCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyEventDestinationCollection_CS (EFI_REDFISH_EVENTDESTINATIONCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyEventDestinationCollection_Json (RedfishCS_char *JsonText);

#endif
