/** @file
   
  The implementation of EFI Redfish Interpreter DXE driver for below
  Redfish schema.
   - ComputerSystem.v1_5_0 

  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
  This software contains information confidential and proprietary to
  Hewlett Packard Enterprise. It shall not be reproduced in whole or in part,
  or transferred to other documents, or disclosed to third parties, or used
  for any purpose other than that for which it was obtained without the prior
  written consent of Hewlett Packard Enterprise.

**/
#include <Uefi.h>
#include <Library/BaseLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiDriverEntryPoint.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>

#include <Protocol/RestResourceInterpreter.h>

#include <Library/HpStringUtilLib.h>
#include <jansson.h>
//
// EFI Redfish Resource Type IDentifier.
//
#include <RedfishInterpreter/ComputerSystem/v1_5_0/EfiComputerSystemV1_5_0.h>
CHAR8 mResourceTypeStr [] = "#ComputerSystem";
BOOLEAN IsRevisonController = TRUE;

// Support ComputerSystem V1_5_0 
EFI_REST_RESOURCE_INTERP_SUPPORTED ResourceInterP [] = {
  {
    {
      (LIST_ENTRY *)&ResourceInterP[0], (LIST_ENTRY *)&ResourceInterP[0]
    },
    {
      {
        "ComputerSystem",
        "1",
        "5",
        "0"
      },
      "ComputerSystem"
    }
  }
};

EFI_REST_RESOURCE_INTERPRETER_PROTOCOL *mRestRsrcInterpProt = NULL;
EFI_HANDLE mInterpHandle = NULL;

/**
  This function gets the string of revision number.
  
  @param[in]    Str             Odata.type string.
  @param[in]    StrIndex        Current string index. 
  @param[in]    OdataTypeStrLen Odata.type string length
   
  @retval != 0 Number found.
  @retval 0    Number not found.

**/
UINTN
GetOdataTypeVersionNum (CHAR8 *Str, UINTN *StrIndex, UINTN OdataTypeStrLen)
{
  UINTN NumIndex;
  UINTN Index;

  Index = *StrIndex;
  while (Str[Index] < 0x30 || Str[Index] > 0x39) {
    Index ++;
    if (OdataTypeStrLen < Index) {
      return 0;
    }
  };
  NumIndex = Index;
  while (Str [Index] != '.' && Str [Index] != '_') {
    Index ++;
    if (OdataTypeStrLen < Index) {
      return 0;
    }
  };
  Str [Index] = 0;
  *StrIndex = Index;
  return NumIndex;
}

/**
  This function checks if the given JSON property supported by this 
  Redfish JSON to C structure convertor.
  
  @param[in]    ResoruceRaw      Given JSON property.
   
  @retval EFI_SUCCESS
  @retval Others

**/
BOOLEAN
CheckSupportedSchema (IN CHAR8 *ResoruceRaw)
{
  json_t *TempJsonObj;
  json_t *JsonObjReturned;
  CHAR8 *TempChar;
  UINTN StrIndex;
  EFI_STATUS Status;
  UINTN StrMajorIndex;
  UINTN StrMinorIndex;
  UINTN StrErrataIndex;
  UINTN OdataTypeStrLen;

  Status = EFI_SUCCESS;
  JsonObjReturned = json_loads(ResoruceRaw, 0, NULL);
  TempJsonObj = json_object_get(JsonObjReturned, "@odata.type");
  if (TempJsonObj == NULL) {
    goto Error;
  }
  TempChar = (CHAR8 *)json_string_value(TempJsonObj);
  OdataTypeStrLen = AsciiStrLen(TempChar);
  //
  // Validate odata.type
  //
  if (OdataTypeStrLen < AsciiStrLen(mResourceTypeStr)) {
    goto Error;
  }
 
  if (CompareMem ((VOID *)TempChar, (VOID *)mResourceTypeStr, AsciiStrLen(mResourceTypeStr)) != 0) {
    goto Error;
  }
  StrIndex = AsciiStrLen(mResourceTypeStr);
  if (TempChar [StrIndex] != '.' ) {
    goto Error;
  }
  StrIndex ++;
  if (OdataTypeStrLen < StrIndex) {
    goto Error;
  }
  if (!IsRevisonController) {
    //
    // No revision controllerd.
    //
    return TRUE;
  }
  
  //
  // Check major revision.
  //
  StrMajorIndex = GetOdataTypeVersionNum (TempChar, &StrIndex, OdataTypeStrLen);
  if (StrMajorIndex == 0) {
    goto Error;
  }

  //
  // Check minor revision.
  //
  StrMinorIndex = GetOdataTypeVersionNum (TempChar, &StrIndex, OdataTypeStrLen);
  if (StrMajorIndex == 0) {
    goto Error;
  }
  //
  // Check errata revision.
  //
  StrErrataIndex = GetOdataTypeVersionNum (TempChar, &StrIndex, OdataTypeStrLen);
  if (StrMajorIndex == 0) {
    goto Error;
  }
  if ((AsciiStrCmp(TempChar + StrMajorIndex, ResourceInterP[0].RestResourceInterp.NameSpace.MajorVersion) == 0) && 
      (AsciiStrCmp(TempChar + StrMinorIndex, ResourceInterP[0].RestResourceInterp.NameSpace.MinorVersion) == 0) &&
      (AsciiStrCmp(TempChar + StrErrataIndex, ResourceInterP[0].RestResourceInterp.NameSpace.ErrataVersion) == 0)) {
    json_decref(JsonObjReturned);
    return TRUE;
  }
Error:;
  json_decref(JsonObjReturned);
  return FALSE;
}

/**
  This function sets the structure of givin JSON resource in text format through
  supported Redfish schema interpreter.
  
  @param[in]    This              EFI_REST_RESOURCE_INTERPRETER_PROTOCOL instance. 
  @param[in]    RestEx            EFI REST EX protocol.
  @param[in]    RsrcTypeIdentifier  Resource type identifier.
  @param[in]    ResoruceRaw       Given Restful resource.
  @param[in]    PropertyName      Name of property defined in the data type to retrieve.
  @param[out]   InterpProp        Property interpreted from given ResoruceRaw.
   
  @retval EFI_SUCCESS
  @retval Others

**/
EFI_STATUS
EFIAPI
ComputerSystemToEfiStruct (
  IN EFI_REST_RESOURCE_INTERPRETER_PROTOCOL   *This,
  IN EFI_REST_EX_PROTOCOL                     *RestEx OPTIONAL,
  IN EFI_REST_RESOURCE_TYPE_IDENTIFIER        *RsrcIdentifier OPTIONAL,
  IN CHAR8                                    *ResoruceRaw,
  IN CHAR8                                    *PropertyName,
  OUT EFI_REST_RESOURCE_INTERPED_PROPERTY_HEADER  **InterpProp
)
{
  EFI_REDFISH_COMPUTERSYSTEM_V1_5_0 *ComputerSystemV1_5_0;
  EFI_REDFISH_COMPUTERSYSTEM_V1_5_0_CS *ComputerSystemV1_5_0Cs;
  EFI_REST_RESOURCE_INTERPED_PROPERTY_HEADER *RestIntrpHeader;
  CHAR8 *ResourceTypeMajorVersion;
  CHAR8 *ResourceTypeMinorVersion;
  CHAR8 *ResourceTypeErrataVersion;
  UINTN Length;
  EFI_STATUS Status;

  if (ResoruceRaw == NULL || (RsrcIdentifier != NULL && RsrcIdentifier->NameSpace.ResourceTypeName == NULL)) {
    return EFI_INVALID_PARAMETER;
  }
  if (RsrcIdentifier == NULL ||
      (RsrcIdentifier != NULL && 
      (RsrcIdentifier->NameSpace.MajorVersion == NULL ||
       RsrcIdentifier->NameSpace.MinorVersion == NULL ||
       RsrcIdentifier->NameSpace.ErrataVersion == NULL))
       ) {
    //
    // Support revision determination.
    //
    if (!CheckSupportedSchema (ResoruceRaw)) {
      return EFI_UNSUPPORTED;
    }
  } else if ((AsciiStrCmp (RsrcIdentifier->NameSpace.MajorVersion, "1") != 0) ||
             (AsciiStrCmp (RsrcIdentifier->NameSpace.MinorVersion, "5") != 0) ||
             (AsciiStrCmp (RsrcIdentifier->NameSpace.ErrataVersion, "0") != 0) ||
             (AsciiStrCmp (RsrcIdentifier->NameSpace.ResourceTypeName, "ComputerSystem") != 0)) {
    return EFI_UNSUPPORTED;
  }

  Status = Json_ComputerSystem_V1_5_0_To_CS (ResoruceRaw, &ComputerSystemV1_5_0Cs);
  if (EFI_ERROR (Status)){
    return Status;
  }
  ComputerSystemV1_5_0 = (EFI_REDFISH_COMPUTERSYSTEM_V1_5_0 *)AllocateZeroPool (
                        sizeof (EFI_REDFISH_COMPUTERSYSTEM_V1_5_0));
  if (ComputerSystemV1_5_0 == NULL){
    return EFI_OUT_OF_RESOURCES;
  }
  RestIntrpHeader = (EFI_REST_RESOURCE_INTERPED_PROPERTY_HEADER *)ComputerSystemV1_5_0;
  ComputerSystemV1_5_0->ComputerSystem = ComputerSystemV1_5_0Cs;
  ResourceTypeMajorVersion = "1";
  ResourceTypeMinorVersion = "5";
  ResourceTypeErrataVersion = "0";
  Length = sizeof (EFI_REDFISH_COMPUTERSYSTEM_V1_5_0_CS);
  //
  // Set header.
  //
  RestIntrpHeader->Signature = REST_RESOURCE_INTERP_SIGNATURE; 
  RestIntrpHeader->Length = Length;
  RestIntrpHeader->RsrcIdentifier.NameSpace.ResourceTypeName = (CHAR8 *)AllocatePool (AsciiStrSize ("ComputerSystem"));
  AsciiStrCpy (RestIntrpHeader->RsrcIdentifier.NameSpace.ResourceTypeName, "ComputerSystem");
  RestIntrpHeader->RsrcIdentifier.NameSpace.MajorVersion = (CHAR8 *)AllocatePool (AsciiStrSize (ResourceTypeMajorVersion));
  AsciiStrCpy (RestIntrpHeader->RsrcIdentifier.NameSpace.MajorVersion, ResourceTypeMajorVersion);
  RestIntrpHeader->RsrcIdentifier.NameSpace.MinorVersion = (CHAR8 *)AllocatePool (AsciiStrSize (ResourceTypeMinorVersion));
  AsciiStrCpy (RestIntrpHeader->RsrcIdentifier.NameSpace.MinorVersion, ResourceTypeMinorVersion);
  RestIntrpHeader->RsrcIdentifier.NameSpace.ErrataVersion = (CHAR8 *)AllocatePool (AsciiStrSize (ResourceTypeErrataVersion));
  AsciiStrCpy (RestIntrpHeader->RsrcIdentifier.NameSpace.ErrataVersion, ResourceTypeErrataVersion);
  RestIntrpHeader->RsrcIdentifier.DataType = (CHAR8 *)AllocatePool (AsciiStrSize ("ComputerSystem"));
  AsciiStrCpy (RestIntrpHeader->RsrcIdentifier.DataType, "ComputerSystem");
  *InterpProp = RestIntrpHeader;
  return EFI_SUCCESS;
}

/**
  This function returns JSON property in text format for the given structure through
  supported Restful data interpreter.
  
  @param[in]    This            EFI_REST_RESOURCE_INTERPRETER_PROTOCOL instance. 
  @param[in]    RestEx          EFI REST EX protocol.
  @param[in]    InterpProp      Given Restful resource.
  @param[out]   ResoruceRaw     Resource in RESTfuls service oriented property interpreted from given ResoruceRaw.
                                Caller has to release the memory allocated for ResoruceRaw using DestoryJson function.

  @retval EFI_SUCCESS
  @retval Others

**/
EFI_STATUS
EFIAPI
ComputerSystemFromEfiStruct(
  IN EFI_REST_RESOURCE_INTERPRETER_PROTOCOL *This,
  IN EFI_REST_EX_PROTOCOL                   *RestEx,
  IN EFI_REST_RESOURCE_INTERPED_PROPERTY_HEADER *InterpProp,
  OUT CHAR8 **ResoruceRaw
)
{
  if (InterpProp == NULL || ResoruceRaw == NULL) {
    return EFI_INVALID_PARAMETER;
  }
  return CS_To_ComputerSystem_V1_5_0_JSON (*((EFI_REDFISH_COMPUTERSYSTEM_V1_5_0_CS **)((UINT8 *)InterpProp + sizeof (EFI_REST_RESOURCE_INTERPED_PROPERTY_HEADER))), ResoruceRaw);  
}

/**
  This function destory structure retunred in ComputerSystemToStruct.
  
  @param[in]    This                EFI_REST_RESOURCE_INTERPRETER_PROTOCOL instance. 
  @param[in]    RsrcTypeIdentifier  Resource type identifier.
  @param[in]    InterpProp          Given Restful resource.

  @retval EFI_SUCCESS
  @retval Others

**/
EFI_STATUS
EFIAPI
ComputerSystemDestoryEfiStruct(
  IN EFI_REST_RESOURCE_INTERPRETER_PROTOCOL   *This,
  IN EFI_REST_RESOURCE_TYPE_IDENTIFIER        *RsrcIdentifier,
  IN EFI_REST_RESOURCE_INTERPED_PROPERTY_HEADER  *InterpProp
)
{
  EFI_REDFISH_COMPUTERSYSTEM_V1_5_0 *ComputerSystemV1_5_0;
  
  ComputerSystemV1_5_0 = (EFI_REDFISH_COMPUTERSYSTEM_V1_5_0 *)InterpProp;
  DestroyComputerSystem_V1_5_0_CS (ComputerSystemV1_5_0->ComputerSystem); 
  return EFI_SUCCESS;
}

/**
  This function destory JSON raw text returned from ComputerSystemFromEfiStruct
  
  @param[in]    This                EFI_REST_RESOURCE_INTERPRETER_PROTOCOL instance. 
  @param[in]    RsrcTypeIdentifier  Resource type identifier.  
  @param[in]    ResoruceRaw         JSON raw text.

  @retval EFI_SUCCESS
  @retval Others

**/
EFI_STATUS
EFIAPI
ComputerSystemDestoryJson(
  IN EFI_REST_RESOURCE_INTERPRETER_PROTOCOL *This,
  IN EFI_REST_RESOURCE_TYPE_IDENTIFIER *RsrcIdentifier,  
  IN CHAR8 *ResoruceRaw
)
{
  if (ResoruceRaw == NULL) {
    return EFI_INVALID_PARAMETER;
  }
  return DestroyComputerSystem_V1_5_0_Json (ResoruceRaw);
}

/**
  This is the declaration of an EFI image entry point.

  @param  ImageHandle           The firmware allocated handle for the UEFI image.
  @param  SystemTable           A pointer to the EFI System Table.

  @retval EFI_SUCCESS           The operation completed successfully.
  @retval Others                An unexpected error occurred.
**/
EFI_STATUS
EFIAPI
RedfishComputerSystem_V1_5_0EntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS Status;
                      
  if (mRestRsrcInterpProt == NULL) {
    Status = gBS->LocateProtocol(&gEfiRestResourceInterpreterProtocolGuid, NULL, (VOID **)&mRestRsrcInterpProt);
    if ((EFI_ERROR (Status))) {
      return Status;
    }
  }
  Status = mRestRsrcInterpProt->Register (
              mRestRsrcInterpProt,
              ResourceInterP,
              ComputerSystemToEfiStruct,
              ComputerSystemFromEfiStruct,
              ComputerSystemDestoryEfiStruct,
              ComputerSystemDestoryJson,
              &mInterpHandle
              );
  return Status;
}

/**
  This is the unload handle for Redfish discover module.

  Disconnect the driver specified by ImageHandle from all the devices in the handle database.
  Uninstall all the protocols installed in the driver entry point.

  @param[in] ImageHandle           The drivers' driver image.

  @retval    EFI_SUCCESS           The image is unloaded.
  @retval    Others                Failed to unload the image.

**/
EFI_STATUS
EFIAPI
RedfishComputerSystem_V1_5_0Unload (
  IN EFI_HANDLE ImageHandle
  )
{
  if (mRestRsrcInterpProt != NULL && mInterpHandle != NULL) {
    mRestRsrcInterpProt->Unregister (mRestRsrcInterpProt, mInterpHandle);
  }
  return EFI_SUCCESS;
}
