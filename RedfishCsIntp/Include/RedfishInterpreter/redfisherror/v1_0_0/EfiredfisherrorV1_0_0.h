/** @file
  Auto-generated file by Redfish Schema C Structure Generator.
  https://github.com/DMTF/Redfish-Schema-C-Struct-Generator
  
  This file defines the EFI Redfish C Structure Interpreter for redfisherror v1_0_0

  (C) Copyright 2019 Hewlett Packard Enterprise Development LP<BR>
  
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __EFI_REDFISH_INTERP_REDFISHERROR_V1_0_0_H__
#define __EFI_REDFISH_INTERP_REDFISHERROR_V1_0_0_H__

#include <Uefi.h>
#include <Protocol/RestJsonStructure.h>
#include "Library/RedfishCSLib/edk2/redfisherror/v1_0_0/Redfish_redfisherror_v1_0_0_CS.h"
//
// EFI structure of Redfish redfisherror v1_0_0
//
typedef struct _EFI_REDFISH_REDFISHERROR_V1_0_0 {
  EFI_REST_JSON_STRUCTURE_HEADER Header;
  EFI_REDFISH_REDFISHERROR_V1_0_0_CS *redfisherror;
} EFI_REDFISH_REDFISHERROR_V1_0_0;

#endif
