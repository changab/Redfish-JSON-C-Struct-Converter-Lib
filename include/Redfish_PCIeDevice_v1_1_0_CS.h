//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishPciedevice_V1_1_0_CSTRUCT_H_
#define _RedfishPciedevice_V1_1_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishPCIeDevice_V1_1_0_PCIeDevice_CS RedfishPCIeDevice_V1_1_0_PCIeDevice_CS;
typedef struct _RedfishPCIeDevice_V1_1_0_PCIeDevice_Actions_CS RedfishPCIeDevice_V1_1_0_PCIeDevice_Actions_CS;
typedef struct _RedfishPCIeDevice_V1_1_0_PCIeDevice_Actions_Oem_CS RedfishPCIeDevice_V1_1_0_PCIeDevice_Actions_Oem_CS;
typedef struct _RedfishPCIeDevice_V1_1_0_PCIeDevice_Links_CS RedfishPCIeDevice_V1_1_0_PCIeDevice_Links_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishPCIeDevice_V1_1_0_PCIeDevice_Actions_CS {
    RedfishPCIeDevice_V1_1_0_PCIeDevice_Actions_Oem_CS    *Oem;    // The available OEM specific
                                                                  // actions for this resource.
} RedfishPCIeDevice_V1_1_0_PCIeDevice_Actions_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishPCIeDevice_V1_1_0_PCIeDevice_Actions_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishPCIeDevice_V1_1_0_PCIeDevice_Actions_Oem_CS;

//
// The links object contains the links to other resources that are related to this
// resource.
//
typedef struct _RedfishPCIeDevice_V1_1_0_PCIeDevice_Links_CS {
    RedfishCS_Link            Chassis;                              // An array of references to the
                                                                    // chassis in which the PCIe
                                                                    // device is contained.
    RedfishCS_int64           *Chassisodata_count;              
    RedfishCS_char            *Chassisodata_navigationLink;     
    RedfishResource_Oem_CS    *Oem;                                 // Oem extension object.
    RedfishCS_Link            PCIeFunctions;                        // An array of references to
                                                                    // PCIeFunctions exposed by this
                                                                    // device.
    RedfishCS_int64           *PCIeFunctionsodata_count;        
    RedfishCS_char            *PCIeFunctionsodata_navigationLink;
} RedfishPCIeDevice_V1_1_0_PCIeDevice_Links_CS;

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
// This is the schema definition for the PCIeDevice resource.  It represents the
// properties of a PCIeDevice attached to a System.
//
typedef struct _RedfishPCIeDevice_V1_1_0_PCIeDevice_CS {
    RedfishCS_Header                                  Header;
    RedfishCS_char                                    *odata_context; 
    RedfishCS_char                                    *odata_id;      
    RedfishCS_char                                    *odata_type;    
    RedfishPCIeDevice_V1_1_0_PCIeDevice_Actions_CS    *Actions;           // The available actions for this
                                                                          // resource.
    RedfishCS_char                                    *AssetTag;          // The user assigned asset tag
                                                                          // for this PCIe device.
    RedfishCS_char                                    *Description;   
    RedfishCS_char                                    *DeviceType;        // The device type for this PCIe
                                                                          // device.
    RedfishCS_char                                    *FirmwareVersion;    // The version of firmware for
                                                                          // this PCIe device.
    RedfishCS_char                                    *Id;            
    RedfishPCIeDevice_V1_1_0_PCIeDevice_Links_CS      *Links;             // The links object contains the
                                                                          // links to other resources that
                                                                          // are related to this resource.
    RedfishCS_char                                    *Manufacturer;      // This is the manufacturer of
                                                                          // this PCIe device.
    RedfishCS_char                                    *Model;             // This is the model number for
                                                                          // the PCIe device.
    RedfishCS_char                                    *Name;          
    RedfishResource_Oem_CS                            *Oem;               // This is the
                                                                          // manufacturer/provider specific
                                                                          // extension moniker used to
                                                                          // divide the Oem object into
                                                                          // sections.
    RedfishCS_char                                    *PartNumber;        // The part number for this PCIe
                                                                          // device.
    RedfishCS_char                                    *SKU;               // This is the SKU for this PCIe
                                                                          // device.
    RedfishCS_char                                    *SerialNumber;      // The serial number for this
                                                                          // PCIe device.
    RedfishResource_Status_CS                         *Status;        
} RedfishPCIeDevice_V1_1_0_PCIeDevice_CS;

RedfishCS_status
Json_PCIeDevice_V1_1_0_To_CS (char *JsonRawText, RedfishPCIeDevice_V1_1_0_PCIeDevice_CS **ReturnedCS);

RedfishCS_status
CS_To_PCIeDevice_V1_1_0_JSON (RedfishPCIeDevice_V1_1_0_PCIeDevice_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyPCIeDevice_V1_1_0_CS (RedfishPCIeDevice_V1_1_0_PCIeDevice_CS *CSPtr);

RedfishCS_status
DestroyPCIeDevice_V1_1_0_Json (RedfishCS_char *JsonText);

#endif
