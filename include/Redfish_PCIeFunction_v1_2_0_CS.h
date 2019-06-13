//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishPciefunction_V1_2_0_CSTRUCT_H_
#define _RedfishPciefunction_V1_2_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishPCIeFunction_V1_2_0_Actions_CS RedfishPCIeFunction_V1_2_0_Actions_CS;
typedef struct _RedfishPCIeFunction_V1_2_0_Links_CS RedfishPCIeFunction_V1_2_0_Links_CS;
typedef struct _RedfishPCIeFunction_V1_2_0_OemActions_CS RedfishPCIeFunction_V1_2_0_OemActions_CS;
typedef struct _RedfishPCIeFunction_V1_2_0_PCIeFunction_CS RedfishPCIeFunction_V1_2_0_PCIeFunction_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishPCIeFunction_V1_2_0_Actions_CS {
    RedfishPCIeFunction_V1_2_0_OemActions_CS    *Oem;
} RedfishPCIeFunction_V1_2_0_Actions_CS;

//
// Contains references to other resources that are related to this resource.
//
typedef struct _RedfishPCIeFunction_V1_2_0_Links_CS {
    RedfishCS_Link            Drives;                               // An array of references to the
                                                                    // drives which the PCIe device
                                                                    // produces.
    RedfishCS_int64           *Drivesodata_count;               
    RedfishCS_Link            EthernetInterfaces;                   // An array of references to the
                                                                    // ethernet interfaces which the
                                                                    // PCIe device produces.
    RedfishCS_int64           *EthernetInterfacesodata_count;   
    RedfishCS_Link            NetworkDeviceFunctions;               // An array of references to the
                                                                    // Network Device Functions which
                                                                    // the PCIe device produces.
    RedfishCS_int64           *NetworkDeviceFunctionsodata_count;
    RedfishResource_Oem_CS    *Oem;                                 // Oem extension object.
    RedfishCS_Link            PCIeDevice;                           // A reference to the PCIeDevice
                                                                    // on which this function
                                                                    // resides.
    RedfishCS_Link            StorageControllers;                   // An array of references to the
                                                                    // storage controllers which the
                                                                    // PCIe device produces.
    RedfishCS_int64           *StorageControllersodata_count;   
} RedfishPCIeFunction_V1_2_0_Links_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishPCIeFunction_V1_2_0_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishPCIeFunction_V1_2_0_OemActions_CS;

//
// Oem extension object.
//
#ifndef __RedfishResource_Oem_CS__
#define __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishResource_Oem_CS;
#endif

//
// This type describes the status and health of a resource and its children.
//
#ifndef __RedfishResource_Status_CS__
#define __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS {
    RedfishCS_char            *Health;         // This represents the health
                                               // state of this resource in the
                                               // absence of its dependent
                                               // resources.
    RedfishCS_char            *HealthRollup;    // This represents the overall
                                               // health state from the view of
                                               // this resource.
    RedfishResource_Oem_CS    *Oem;            // Oem extension object.
    RedfishCS_char            *State;          // This indicates the known state
                                               // of the resource, such as if it
                                               // is enabled.
} RedfishResource_Status_CS;
#endif

//
// This is the schema definition for the PCIeFunction resource.  It represents the
// properties of a PCIeFunction attached to a System.
//
typedef struct _RedfishPCIeFunction_V1_2_0_PCIeFunction_CS {
    RedfishCS_Header                         Header;
    RedfishCS_char                           *odata_context;   
    RedfishCS_char                           *odata_etag;      
    RedfishCS_char                           *odata_id;        
    RedfishCS_char                           *odata_type;      
    RedfishPCIeFunction_V1_2_0_Actions_CS    *Actions;             // The available actions for this
                                                                   // resource.
    RedfishCS_char                           *ClassCode;           // The Class Code of this PCIe
                                                                   // function.
    RedfishCS_char                           *Description;     
    RedfishCS_char                           *DeviceClass;         // The class for this PCIe
                                                                   // Function.
    RedfishCS_char                           *DeviceId;            // The Device ID of this PCIe
                                                                   // function.
    RedfishCS_int64                          *FunctionId;          // The the PCIe Function
                                                                   // identifier.
    RedfishCS_char                           *FunctionType;        // The type of the PCIe Function.
    RedfishCS_char                           *Id;              
    RedfishPCIeFunction_V1_2_0_Links_CS      *Links;               // The links object contains the
                                                                   // links to other resources that
                                                                   // are related to this resource.
    RedfishCS_char                           *Name;            
    RedfishResource_Oem_CS                   *Oem;                 // This is the
                                                                   // manufacturer/provider specific
                                                                   // extension moniker used to
                                                                   // divide the Oem object into
                                                                   // sections.
    RedfishCS_char                           *RevisionId;          // The Revision ID of this PCIe
                                                                   // function.
    RedfishResource_Status_CS                *Status;          
    RedfishCS_char                           *SubsystemId;         // The Subsystem ID of this PCIe
                                                                   // function.
    RedfishCS_char                           *SubsystemVendorId;    // The Subsystem Vendor ID of
                                                                   // this PCIe function.
    RedfishCS_char                           *VendorId;            // The Vendor ID of this PCIe
                                                                   // function.
} RedfishPCIeFunction_V1_2_0_PCIeFunction_CS;

RedfishCS_status
Json_PCIeFunction_V1_2_0_To_CS (char *JsonRawText, RedfishPCIeFunction_V1_2_0_PCIeFunction_CS **ReturnedCS);

RedfishCS_status
CS_To_PCIeFunction_V1_2_0_JSON (RedfishPCIeFunction_V1_2_0_PCIeFunction_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyPCIeFunction_V1_2_0_CS (RedfishPCIeFunction_V1_2_0_PCIeFunction_CS *CSPtr);

RedfishCS_status
DestroyPCIeFunction_V1_2_0_Json (RedfishCS_char *JsonText);

#endif
