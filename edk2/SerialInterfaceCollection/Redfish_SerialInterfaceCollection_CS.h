//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHSERIALINTERFACECOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHSERIALINTERFACECOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_SerialInterfaceCollection_CS.h"

typedef RedfishSerialInterfaceCollection_SerialInterfaceCollection_CS EFI_REDFISH_SERIALINTERFACECOLLECTION_CS;

RedfishCS_status
Json_SerialInterfaceCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_SERIALINTERFACECOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_SerialInterfaceCollection_JSON (EFI_REDFISH_SERIALINTERFACECOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroySerialInterfaceCollection_CS (EFI_REDFISH_SERIALINTERFACECOLLECTION_CS *CSPtr);

RedfishCS_status
DestroySerialInterfaceCollection_Json (RedfishCS_char *JsonText);

#endif
