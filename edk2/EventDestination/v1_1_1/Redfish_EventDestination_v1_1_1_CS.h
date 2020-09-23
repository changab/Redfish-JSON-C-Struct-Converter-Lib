//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHEVENTDESTINATION_V1_1_1_CSTRUCT_H_
#define _EFI_REDFISHEVENTDESTINATION_V1_1_1_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_EventDestination_v1_1_1_CS.h"

typedef RedfishEventDestination_V1_1_1_EventDestination_CS EFI_REDFISH_EVENTDESTINATION_V1_1_1_CS;

RedfishCS_status
Json_EventDestination_V1_1_1_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_EVENTDESTINATION_V1_1_1_CS **ReturnedCs);

RedfishCS_status
CS_To_EventDestination_V1_1_1_JSON (EFI_REDFISH_EVENTDESTINATION_V1_1_1_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyEventDestination_V1_1_1_CS (EFI_REDFISH_EVENTDESTINATION_V1_1_1_CS *CSPtr);

RedfishCS_status
DestroyEventDestination_V1_1_1_Json (RedfishCS_char *JsonText);

#endif
