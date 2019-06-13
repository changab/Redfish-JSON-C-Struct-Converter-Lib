//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishNetworkadapter_V1_2_0_CSTRUCT_H_
#define _RedfishNetworkadapter_V1_2_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishNetworkAdapter_V1_2_0_Controllers_Array_CS RedfishNetworkAdapter_V1_2_0_Controllers_Array_CS;
typedef struct _RedfishNetworkAdapter_V1_2_0_Actions_CS RedfishNetworkAdapter_V1_2_0_Actions_CS;
typedef struct _RedfishNetworkAdapter_V1_2_0_ControllerCapabilities_CS RedfishNetworkAdapter_V1_2_0_ControllerCapabilities_CS;
typedef struct _RedfishNetworkAdapter_V1_2_0_ControllerLinks_CS RedfishNetworkAdapter_V1_2_0_ControllerLinks_CS;
typedef struct _RedfishNetworkAdapter_V1_2_0_Controllers_CS RedfishNetworkAdapter_V1_2_0_Controllers_CS;
typedef struct _RedfishNetworkAdapter_V1_2_0_DataCenterBridging_CS RedfishNetworkAdapter_V1_2_0_DataCenterBridging_CS;
typedef struct _RedfishNetworkAdapter_V1_2_0_NPIV_CS RedfishNetworkAdapter_V1_2_0_NPIV_CS;
typedef struct _RedfishNetworkAdapter_V1_2_0_NetworkAdapter_CS RedfishNetworkAdapter_V1_2_0_NetworkAdapter_CS;
typedef struct _RedfishNetworkAdapter_V1_2_0_NicPartitioning_CS RedfishNetworkAdapter_V1_2_0_NicPartitioning_CS;
typedef struct _RedfishNetworkAdapter_V1_2_0_OemActions_CS RedfishNetworkAdapter_V1_2_0_OemActions_CS;
typedef struct _RedfishNetworkAdapter_V1_2_0_ResetSettingsToDefault_CS RedfishNetworkAdapter_V1_2_0_ResetSettingsToDefault_CS;
typedef struct _RedfishNetworkAdapter_V1_2_0_SRIOV_CS RedfishNetworkAdapter_V1_2_0_SRIOV_CS;
typedef struct _RedfishNetworkAdapter_V1_2_0_VirtualFunction_CS RedfishNetworkAdapter_V1_2_0_VirtualFunction_CS;
typedef struct _RedfishNetworkAdapter_V1_2_0_VirtualizationOffload_CS RedfishNetworkAdapter_V1_2_0_VirtualizationOffload_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishNetworkAdapter_V1_2_0_Actions_CS {
    RedfishNetworkAdapter_V1_2_0_ResetSettingsToDefault_CS    *NetworkAdapter_ResetSettingsToDefault;
    RedfishNetworkAdapter_V1_2_0_OemActions_CS                *Oem;                                     // This property contains the
                                                                                                        // available OEM specific actions
                                                                                                        // for this resource.
} RedfishNetworkAdapter_V1_2_0_Actions_CS;

//
// The capabilities of a controller.
//
typedef struct _RedfishNetworkAdapter_V1_2_0_ControllerCapabilities_CS {
    RedfishNetworkAdapter_V1_2_0_DataCenterBridging_CS       *DataCenterBridging;           // Data Center Bridging (DCB) for
                                                                                            // this controller.
    RedfishNetworkAdapter_V1_2_0_NicPartitioning_CS          *NPAR;                         // NIC Partitioning (NPAR)
                                                                                            // capabilities for this
                                                                                            // controller.
    RedfishNetworkAdapter_V1_2_0_NPIV_CS                     *NPIV;                         // N_Port ID Virtualization
                                                                                            // (NPIV) capabilties for this
                                                                                            // controller.
    RedfishCS_int64                                          *NetworkDeviceFunctionCount;    // The maximum number of physical
                                                                                            // functions available on this
                                                                                            // controller.
    RedfishCS_int64                                          *NetworkPortCount;             // The number of physical ports
                                                                                            // on this controller.
    RedfishNetworkAdapter_V1_2_0_VirtualizationOffload_CS    *VirtualizationOffload;        // Virtualization offload for
                                                                                            // this controller.
} RedfishNetworkAdapter_V1_2_0_ControllerCapabilities_CS;

//
// Contains references to other resources that are related to this resource.
//
typedef struct _RedfishNetworkAdapter_V1_2_0_ControllerLinks_CS {
    RedfishCS_Link            NetworkDeviceFunctions;               // An array of references to the
                                                                    // NetworkDeviceFunctions
                                                                    // associated with this Network
                                                                    // Controller.
    RedfishCS_int64           *NetworkDeviceFunctionsodata_count;
    RedfishCS_Link            NetworkPorts;                         // An array of references to the
                                                                    // NetworkPorts associated with
                                                                    // this Network Controller.
    RedfishCS_int64           *NetworkPortsodata_count;         
    RedfishResource_Oem_CS    *Oem;                                 // Oem extension object.
    RedfishCS_Link            PCIeDevices;                          // An array of references to the
                                                                    // PCIeDevices associated with
                                                                    // this Network Controller.
    RedfishCS_int64           *PCIeDevicesodata_count;          
} RedfishNetworkAdapter_V1_2_0_ControllerLinks_CS;

//
// A network controller ASIC that makes up part of a NetworkAdapter.
//
typedef struct _RedfishNetworkAdapter_V1_2_0_Controllers_CS {
    RedfishNetworkAdapter_V1_2_0_ControllerCapabilities_CS    *ControllerCapabilities;    // The capabilities of this
                                                                                         // controller.
    RedfishCS_char                                            *FirmwarePackageVersion;    // The version of the user-facing
                                                                                         // firmware package.
    RedfishNetworkAdapter_V1_2_0_ControllerLinks_CS           *Links;                    // Links.
    RedfishCS_Link                                            Location;                  // The Location of the network
                                                                                         // adapter controller.
    RedfishCS_Link                                            PCIeInterface;             // The PCIe interface details for
                                                                                         // this controller.
} RedfishNetworkAdapter_V1_2_0_Controllers_CS;

//
// Data Center Bridging (DCB) for capabilities of a controller.
//
typedef struct _RedfishNetworkAdapter_V1_2_0_DataCenterBridging_CS {
    RedfishCS_bool    *Capable;    // Whether this controller is
                                  // capable of Data Center
                                  // Bridging (DCB).
} RedfishNetworkAdapter_V1_2_0_DataCenterBridging_CS;

//
// N_Port ID Virtualization (NPIV) capabilties for a controller.
//
typedef struct _RedfishNetworkAdapter_V1_2_0_NPIV_CS {
    RedfishCS_int64    *MaxDeviceLogins;    // The maximum number of N_Port
                                           // ID Virtualization (NPIV)
                                           // logins allowed simultaneously
                                           // from all ports on this
                                           // controller.
    RedfishCS_int64    *MaxPortLogins;     // The maximum number of N_Port
                                           // ID Virtualization (NPIV)
                                           // logins allowed per physical
                                           // port on this controller.
} RedfishNetworkAdapter_V1_2_0_NPIV_CS;

//
// NIC Partitioning capability, status, and configuration for a controller.
//
typedef struct _RedfishNetworkAdapter_V1_2_0_NicPartitioning_CS {
    RedfishCS_bool    *NparCapable;    // Indicates whether or not NIC
                                      // function partitioning is
                                      // supported by a controller.
    RedfishCS_bool    *NparEnabled;    // When true, NIC function
                                      // partitioning is active on this
                                      // controller.
} RedfishNetworkAdapter_V1_2_0_NicPartitioning_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishNetworkAdapter_V1_2_0_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishNetworkAdapter_V1_2_0_OemActions_CS;

//
// This action is to clear the settings back to factory defaults.
//
typedef struct _RedfishNetworkAdapter_V1_2_0_ResetSettingsToDefault_CS {
    RedfishCS_char    *target;    // Link to invoke action
    RedfishCS_char    *title;    // Friendly action name
} RedfishNetworkAdapter_V1_2_0_ResetSettingsToDefault_CS;

//
// Single-Root Input/Output Virtualization (SR-IOV) capabilities.
//
typedef struct _RedfishNetworkAdapter_V1_2_0_SRIOV_CS {
    RedfishCS_bool    *SRIOVVEPACapable;    // Whether this controller
                                           // supports Single Root
                                           // Input/Output Virtualization
                                           // (SR-IOV) in Virtual Ethernet
                                           // Port Aggregator (VEPA) mode.
} RedfishNetworkAdapter_V1_2_0_SRIOV_CS;

//
// A virtual function of a controller.
//
typedef struct _RedfishNetworkAdapter_V1_2_0_VirtualFunction_CS {
    RedfishCS_int64    *DeviceMaxCount;           // The maximum number of Virtual
                                                  // Functions (VFs) supported by
                                                  // this controller.
    RedfishCS_int64    *MinAssignmentGroupSize;    // The minimum number of Virtual
                                                  // Functions (VFs) that can be
                                                  // allocated or moved between
                                                  // physical functions for this
                                                  // controller.
    RedfishCS_int64    *NetworkPortMaxCount;      // The maximum number of Virtual
                                                  // Functions (VFs) supported per
                                                  // network port for this
                                                  // controller.
} RedfishNetworkAdapter_V1_2_0_VirtualFunction_CS;

//
// A Virtualization offload capability of a controller.
//
typedef struct _RedfishNetworkAdapter_V1_2_0_VirtualizationOffload_CS {
    RedfishNetworkAdapter_V1_2_0_SRIOV_CS              *SRIOV;             // Single-Root Input/Output
                                                                           // Virtualization (SR-IOV)
                                                                           // capabilities.
    RedfishNetworkAdapter_V1_2_0_VirtualFunction_CS    *VirtualFunction;    // The virtual function of the
                                                                           // controller.
} RedfishNetworkAdapter_V1_2_0_VirtualizationOffload_CS;

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
// A NetworkAdapter represents the physical network adapter capable of connecting
// to a computer network.  Examples include but are not limited to Ethernet, Fibre
// Channel, and converged network adapters.
//
typedef struct _RedfishNetworkAdapter_V1_2_0_NetworkAdapter_CS {
    RedfishCS_Header                                     Header;
    RedfishCS_char                                       *odata_context;       
    RedfishCS_char                                       *odata_etag;          
    RedfishCS_char                                       *odata_id;            
    RedfishCS_char                                       *odata_type;          
    RedfishNetworkAdapter_V1_2_0_Actions_CS              *Actions;                 // The available actions for this
                                                                                   // resource.
    RedfishCS_Link                                       Assembly;                 // A reference to the Assembly
                                                                                   // resource associated with this
                                                                                   // adapter.
    RedfishNetworkAdapter_V1_2_0_Controllers_Array_CS    *Controllers;             // The set of network controllers
                                                                                   // ASICs that make up this
                                                                                   // NetworkAdapter.
    RedfishCS_char                                       *Description;         
    RedfishCS_char                                       *Id;                  
    RedfishCS_char                                       *Manufacturer;            // The manufacturer or OEM of
                                                                                   // this network adapter.
    RedfishCS_char                                       *Model;                   // The model string for this
                                                                                   // network adapter.
    RedfishCS_char                                       *Name;                
    RedfishCS_Link                                       NetworkDeviceFunctions;    // A reference to the collection
                                                                                   // of NetworkDeviceFunctions
                                                                                   // associated with this
                                                                                   // NetworkAdapter.
    RedfishCS_Link                                       NetworkPorts;             // A reference to the collection
                                                                                   // of NetworkPorts associated
                                                                                   // with this NetworkAdapter.
    RedfishResource_Oem_CS                               *Oem;                     // This is the
                                                                                   // manufacturer/provider specific
                                                                                   // extension moniker used to
                                                                                   // divide the Oem object into
                                                                                   // sections.
    RedfishCS_char                                       *PartNumber;              // Part number for this network
                                                                                   // adapter.
    RedfishCS_char                                       *SKU;                     // The manufacturer SKU for this
                                                                                   // network adapter.
    RedfishCS_char                                       *SerialNumber;            // The serial number for this
                                                                                   // network adapter.
    RedfishResource_Status_CS                            *Status;                  // This property describes the
                                                                                   // status and health of the
                                                                                   // resource and its children.
} RedfishNetworkAdapter_V1_2_0_NetworkAdapter_CS;

typedef struct _RedfishNetworkAdapter_V1_2_0_Controllers_Array_CS  {
    RedfishNetworkAdapter_V1_2_0_Controllers_Array_CS    *Next;
    RedfishNetworkAdapter_V1_2_0_Controllers_CS    *ArrayValue;
} RedfishNetworkAdapter_V1_2_0_Controllers_Array_CS;

RedfishCS_status
Json_NetworkAdapter_V1_2_0_To_CS (char *JsonRawText, RedfishNetworkAdapter_V1_2_0_NetworkAdapter_CS **ReturnedCS);

RedfishCS_status
CS_To_NetworkAdapter_V1_2_0_JSON (RedfishNetworkAdapter_V1_2_0_NetworkAdapter_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyNetworkAdapter_V1_2_0_CS (RedfishNetworkAdapter_V1_2_0_NetworkAdapter_CS *CSPtr);

RedfishCS_status
DestroyNetworkAdapter_V1_2_0_Json (RedfishCS_char *JsonText);

#endif
