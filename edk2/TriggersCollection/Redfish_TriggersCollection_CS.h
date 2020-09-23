//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHTRIGGERSCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHTRIGGERSCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_TriggersCollection_CS.h"

typedef RedfishTriggersCollection_TriggersCollection_CS EFI_REDFISH_TRIGGERSCOLLECTION_CS;

RedfishCS_status
Json_TriggersCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_TRIGGERSCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_TriggersCollection_JSON (EFI_REDFISH_TRIGGERSCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyTriggersCollection_CS (EFI_REDFISH_TRIGGERSCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyTriggersCollection_Json (RedfishCS_char *JsonText);

#endif
