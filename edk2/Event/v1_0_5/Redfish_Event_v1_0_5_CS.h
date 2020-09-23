//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHEVENT_V1_0_5_CSTRUCT_H_
#define _EFI_REDFISHEVENT_V1_0_5_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_Event_v1_0_5_CS.h"

typedef RedfishEvent_V1_0_5_Event_CS EFI_REDFISH_EVENT_V1_0_5_CS;

RedfishCS_status
Json_Event_V1_0_5_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_EVENT_V1_0_5_CS **ReturnedCs);

RedfishCS_status
CS_To_Event_V1_0_5_JSON (EFI_REDFISH_EVENT_V1_0_5_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyEvent_V1_0_5_CS (EFI_REDFISH_EVENT_V1_0_5_CS *CSPtr);

RedfishCS_status
DestroyEvent_V1_0_5_Json (RedfishCS_char *JsonText);

#endif
