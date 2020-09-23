/** @file
  Auto-generated file by Redfish Schema C Structure Generator.
  https://github.com/DMTF/Redfish-Schema-C-Struct-Generator
  
  This file defines the EFI Redfish C Structure Interpreter for LogEntry v1_4_2

  (C) Copyright 2019 Hewlett Packard Enterprise Development LP<BR>
  
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __EFI_REDFISH_INTERP_LOGENTRY_V1_4_2_H__
#define __EFI_REDFISH_INTERP_LOGENTRY_V1_4_2_H__

#include <Uefi.h>
#include <Protocol/RestJsonStructure.h>
#include "Library/RedfishCSLib/edk2/LogEntry/v1_4_2/Redfish_LogEntry_v1_4_2_CS.h"
//
// EFI structure of Redfish LogEntry v1_4_2
//
typedef struct _EFI_REDFISH_LOGENTRY_V1_4_2 {
  EFI_REST_JSON_STRUCTURE_HEADER Header;
  EFI_REDFISH_LOGENTRY_V1_4_2_CS *LogEntry;
} EFI_REDFISH_LOGENTRY_V1_4_2;

#endif
