//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHEVENTSERVICE_V1_2_0_CSTRUCT_H_
#define _EFI_REDFISHEVENTSERVICE_V1_2_0_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_EventService_v1_2_0_CS.h"

typedef RedfishEventService_V1_2_0_EventService_CS EFI_REDFISH_EVENTSERVICE_V1_2_0_CS;

RedfishCS_status
Json_EventService_V1_2_0_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_EVENTSERVICE_V1_2_0_CS **ReturnedCs);

RedfishCS_status
CS_To_EventService_V1_2_0_JSON (EFI_REDFISH_EVENTSERVICE_V1_2_0_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyEventService_V1_2_0_CS (EFI_REDFISH_EVENTSERVICE_V1_2_0_CS *CSPtr);

RedfishCS_status
DestroyEventService_V1_2_0_Json (RedfishCS_char *JsonText);

#endif
