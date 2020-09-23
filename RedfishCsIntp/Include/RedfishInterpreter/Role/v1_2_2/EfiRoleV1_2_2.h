/** @file
  This file defines the EFI Redfish C Structure Interpreter for Role v1_2_2

  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
  This software contains information confidential and proprietary to
  Hewlett Packard Enterprise. It shall not be reproduced in whole or in part,
  or transferred to other documents, or disclosed to third parties, or used
  for any purpose other than that for which it was obtained without the prior
  written consent of Hewlett Packard Enterprise.

**/

#ifndef __EFI_REDFISH_INTERP_ROLE_V1_2_2_H__
#define __EFI_REDFISH_INTERP_ROLE_V1_2_2_H__

#include <Uefi.h>
#include <Protocol/RestResourceInterpreter.h>
#include "Library/RfishCS/edk2/Role/v1_2_2/Redfish_Role_v1_2_2_CS.h"
//
// EFI structure of Redfish Role v1_2_2
//
typedef struct _EFI_REDFISH_ROLE_V1_2_2 {
  EFI_REST_RESOURCE_INTERPED_PROPERTY_HEADER Header;
  EFI_REDFISH_ROLE_V1_2_2_CS *Role;
} EFI_REDFISH_ROLE_V1_2_2;

#endif