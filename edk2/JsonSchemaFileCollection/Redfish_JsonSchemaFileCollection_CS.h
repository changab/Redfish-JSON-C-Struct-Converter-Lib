//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHJSONSCHEMAFILECOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHJSONSCHEMAFILECOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_JsonSchemaFileCollection_CS.h"

typedef RedfishJsonSchemaFileCollection_JsonSchemaFileCollection_CS EFI_REDFISH_JSONSCHEMAFILECOLLECTION_CS;

RedfishCS_status
Json_JsonSchemaFileCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_JSONSCHEMAFILECOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_JsonSchemaFileCollection_JSON (EFI_REDFISH_JSONSCHEMAFILECOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyJsonSchemaFileCollection_CS (EFI_REDFISH_JSONSCHEMAFILECOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyJsonSchemaFileCollection_Json (RedfishCS_char *JsonText);

#endif
