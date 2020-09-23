/** @file
  This file defines the EFI Redfish C Structure Interpreter for Drive v1_1_5

  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
  This software contains information confidential and proprietary to
  Hewlett Packard Enterprise. It shall not be reproduced in whole or in part,
  or transferred to other documents, or disclosed to third parties, or used
  for any purpose other than that for which it was obtained without the prior
  written consent of Hewlett Packard Enterprise.

**/

#ifndef __EFI_REDFISH_INTERP_DRIVE_V1_1_5_H__
#define __EFI_REDFISH_INTERP_DRIVE_V1_1_5_H__

#include <Uefi.h>
#include <Protocol/RestResourceInterpreter.h>
#include "Library/RfishCS/edk2/Drive/v1_1_5/Redfish_Drive_v1_1_5_CS.h"
//
// EFI structure of Redfish Drive v1_1_5
//
typedef struct _EFI_REDFISH_DRIVE_V1_1_5 {
  EFI_REST_RESOURCE_INTERPED_PROPERTY_HEADER Header;
  EFI_REDFISH_DRIVE_V1_1_5_CS *Drive;
} EFI_REDFISH_DRIVE_V1_1_5;

#endif
