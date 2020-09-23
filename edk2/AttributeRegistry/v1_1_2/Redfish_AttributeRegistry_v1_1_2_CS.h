//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHATTRIBUTEREGISTRY_V1_1_2_CSTRUCT_H_
#define _EFI_REDFISHATTRIBUTEREGISTRY_V1_1_2_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_AttributeRegistry_v1_1_2_CS.h"

typedef RedfishAttributeRegistry_V1_1_2_AttributeRegistry_CS EFI_REDFISH_ATTRIBUTEREGISTRY_V1_1_2_CS;

RedfishCS_status
Json_AttributeRegistry_V1_1_2_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_ATTRIBUTEREGISTRY_V1_1_2_CS **ReturnedCs);

RedfishCS_status
CS_To_AttributeRegistry_V1_1_2_JSON (EFI_REDFISH_ATTRIBUTEREGISTRY_V1_1_2_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyAttributeRegistry_V1_1_2_CS (EFI_REDFISH_ATTRIBUTEREGISTRY_V1_1_2_CS *CSPtr);

RedfishCS_status
DestroyAttributeRegistry_V1_1_2_Json (RedfishCS_char *JsonText);

#endif