//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHCOMPUTERSYSTEMCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHCOMPUTERSYSTEMCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_ComputerSystemCollection_CS.h"

typedef RedfishComputerSystemCollection_ComputerSystemCollection_CS EFI_REDFISH_COMPUTERSYSTEMCOLLECTION_CS;

RedfishCS_status
Json_ComputerSystemCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_COMPUTERSYSTEMCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_ComputerSystemCollection_JSON (EFI_REDFISH_COMPUTERSYSTEMCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyComputerSystemCollection_CS (EFI_REDFISH_COMPUTERSYSTEMCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyComputerSystemCollection_Json (RedfishCS_char *JsonText);

#endif
