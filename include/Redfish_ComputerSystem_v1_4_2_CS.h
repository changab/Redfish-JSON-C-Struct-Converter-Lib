//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishComputersystem_V1_4_2_CSTRUCT_H_
#define _RedfishComputersystem_V1_4_2_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __Redfishodata_V4_0_1_idRef_Array_CS__
typedef struct _Redfishodata_V4_0_1_idRef_Array_CS Redfishodata_V4_0_1_idRef_Array_CS;
#endif
typedef struct _RedfishComputerSystem_V1_4_2_TrustedModules_Array_CS RedfishComputerSystem_V1_4_2_TrustedModules_Array_CS;
typedef struct _RedfishComputerSystem_V1_4_2_Actions_CS RedfishComputerSystem_V1_4_2_Actions_CS;
typedef struct _RedfishComputerSystem_V1_4_2_Boot_CS RedfishComputerSystem_V1_4_2_Boot_CS;
typedef struct _RedfishComputerSystem_V1_4_2_ComputerSystem_CS RedfishComputerSystem_V1_4_2_ComputerSystem_CS;
typedef struct _RedfishComputerSystem_V1_4_2_HostedServices_CS RedfishComputerSystem_V1_4_2_HostedServices_CS;
typedef struct _RedfishComputerSystem_V1_4_2_Links_CS RedfishComputerSystem_V1_4_2_Links_CS;
typedef struct _RedfishComputerSystem_V1_4_2_MemorySummary_CS RedfishComputerSystem_V1_4_2_MemorySummary_CS;
typedef struct _RedfishComputerSystem_V1_4_2_OemActions_CS RedfishComputerSystem_V1_4_2_OemActions_CS;
typedef struct _RedfishComputerSystem_V1_4_2_ProcessorSummary_CS RedfishComputerSystem_V1_4_2_ProcessorSummary_CS;
typedef struct _RedfishComputerSystem_V1_4_2_Reset_CS RedfishComputerSystem_V1_4_2_Reset_CS;
typedef struct _RedfishComputerSystem_V1_4_2_SetDefaultBootOrder_CS RedfishComputerSystem_V1_4_2_SetDefaultBootOrder_CS;
typedef struct _RedfishComputerSystem_V1_4_2_TrustedModules_CS RedfishComputerSystem_V1_4_2_TrustedModules_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

#ifndef __Redfishodata_V4_0_1_idRef_CS__
typedef struct _Redfishodata_V4_0_1_idRef_CS Redfishodata_V4_0_1_idRef_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishComputerSystem_V1_4_2_Actions_CS {
    RedfishComputerSystem_V1_4_2_Reset_CS                  *ComputerSystem_Reset;             
    RedfishComputerSystem_V1_4_2_SetDefaultBootOrder_CS    *ComputerSystem_SetDefaultBootOrder;
    RedfishComputerSystem_V1_4_2_OemActions_CS             *Oem;                              
} RedfishComputerSystem_V1_4_2_Actions_CS;

//
// This object contains the boot information for the current resource.
//
typedef struct _RedfishComputerSystem_V1_4_2_Boot_CS {
    RedfishCS_char    *BootSourceOverrideEnabled;      // Describes the state of the
                                                       // Boot Source Override feature.
    RedfishCS_char    *BootSourceOverrideMode;         // The BIOS Boot Mode (either
                                                       // Legacy or UEFI) to be used
                                                       // when BootSourceOverrideTarget
                                                       // boot source is booted from.
    RedfishCS_char    *BootSourceOverrideTarget;       // The current boot source to be
                                                       // used at next boot instead of
                                                       // the normal boot device, if
                                                       // BootSourceOverrideEnabled is
                                                       // true.
    RedfishCS_char    *UefiTargetBootSourceOverride;    // This property is the UEFI
                                                       // Device Path of the device to
                                                       // boot from when
                                                       // BootSourceOverrideTarget is
                                                       // UefiTarget.
} RedfishComputerSystem_V1_4_2_Boot_CS;

//
// This object describes services that may be running or installed on the system.
//
typedef struct _RedfishComputerSystem_V1_4_2_HostedServices_CS {
    RedfishResource_Oem_CS    *Oem;          
    RedfishCS_Link            StorageServices;    // A reference to a collection of
                                                 // storage services supported by
                                                 // this computer system.
} RedfishComputerSystem_V1_4_2_HostedServices_CS;

//
// Contains references to other resources that are related to this resource.
//
typedef struct _RedfishComputerSystem_V1_4_2_Links_CS {
    RedfishCS_Link                        Chassis;                      // An array of references to the
                                                                        // chassis in which this system
                                                                        // is contained.
    RedfishCS_int64                       *Chassisodata_count;      
    Redfishodata_V4_0_1_idRef_Array_CS    *CooledBy;                    // An array of ID[s] of resources
                                                                        // that cool this computer
                                                                        // system. Normally the ID will
                                                                        // be a chassis or a specific set
                                                                        // of fans.
    RedfishCS_int64                       *CooledByodata_count;     
    RedfishCS_Link                        Endpoints;                    // An array of references to the
                                                                        // endpoints that connect to this
                                                                        // system.
    RedfishCS_int64                       *Endpointsodata_count;    
    RedfishCS_Link                        ManagedBy;                    // An array of references to the
                                                                        // Managers responsible for this
                                                                        // system.
    RedfishCS_int64                       *ManagedByodata_count;    
    RedfishResource_Oem_CS                *Oem;                         // Oem extension object.
    Redfishodata_V4_0_1_idRef_Array_CS    *PoweredBy;                   // An array of ID[s] of resources
                                                                        // that power this computer
                                                                        // system. Normally the ID will
                                                                        // be a chassis or a specific set
                                                                        // of Power Supplies.
    RedfishCS_int64                       *PoweredByodata_count;    
    RedfishCS_Link                        ResourceBlocks;               // An array of references to the
                                                                        // Resource Blocks that are used
                                                                        // in this Computer System.
    RedfishCS_int64                       *ResourceBlocksodata_count;
} RedfishComputerSystem_V1_4_2_Links_CS;

//
// This object describes the memory of the system in general detail.
//
typedef struct _RedfishComputerSystem_V1_4_2_MemorySummary_CS {
    RedfishCS_char               *MemoryMirroring;                  // The ability and type of memory
                                                                    // mirroring supported by this
                                                                    // system.
    RedfishResource_Status_CS    *Status;                       
    RedfishCS_int64              *TotalSystemMemoryGiB;             // The total configured operating
                                                                    // system-accessible memory
                                                                    // (RAM), measured in GiB.
    RedfishCS_int64              *TotalSystemPersistentMemoryGiB;    // The total configured, system-
                                                                    // accessible persistent memory,
                                                                    // measured in GiB.
} RedfishComputerSystem_V1_4_2_MemorySummary_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishComputerSystem_V1_4_2_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishComputerSystem_V1_4_2_OemActions_CS;

//
// This object describes the central processors of the system in general detail.
//
typedef struct _RedfishComputerSystem_V1_4_2_ProcessorSummary_CS {
    RedfishCS_int64              *Count;    // The number of physical
                                            // processors in the system.
    RedfishCS_char               *Model;    // The processor model for the
                                            // primary or majority of
                                            // processors in this system.
    RedfishResource_Status_CS    *Status;
} RedfishComputerSystem_V1_4_2_ProcessorSummary_CS;

//
// This action is used to reset the system.
//
typedef struct _RedfishComputerSystem_V1_4_2_Reset_CS {
    RedfishCS_char    *target;    // Link to invoke action
    RedfishCS_char    *title;    // Friendly action name
} RedfishComputerSystem_V1_4_2_Reset_CS;

//
// This action is used to set the Boot Order to the default settings.
//
typedef struct _RedfishComputerSystem_V1_4_2_SetDefaultBootOrder_CS {
    RedfishCS_char    *target;    // Link to invoke action
    RedfishCS_char    *title;    // Friendly action name
} RedfishComputerSystem_V1_4_2_SetDefaultBootOrder_CS;

//
// This object describes the inventory of a Trusted Modules installed in the
// system.
//
typedef struct _RedfishComputerSystem_V1_4_2_TrustedModules_CS {
    RedfishCS_char               *FirmwareVersion;          // The firmware version of this
                                                            // Trusted Module.
    RedfishCS_char               *FirmwareVersion2;         // The 2nd firmware version of
                                                            // this Trusted Module, if
                                                            // applicable.
    RedfishCS_char               *InterfaceType;            // This property indicates the
                                                            // interface type of the Trusted
                                                            // Module.
    RedfishCS_char               *InterfaceTypeSelection;    // The Interface Type selection
                                                            // supported by this Trusted
                                                            // Module.
    RedfishResource_Oem_CS       *Oem;                  
    RedfishResource_Status_CS    *Status;               
} RedfishComputerSystem_V1_4_2_TrustedModules_CS;

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
// A reference to a resource.
//
#ifndef __Redfishodata_V4_0_1_idRef_CS__
#define __Redfishodata_V4_0_1_idRef_CS__
typedef struct _Redfishodata_V4_0_1_idRef_CS {
    RedfishCS_char    *odata_id;
} Redfishodata_V4_0_1_idRef_CS;
#endif

//
// This schema defines a computer system and its respective properties.  A
// computer system represents a machine (physical or virtual) and the local
// resources such as memory, cpu and other devices that can be accessed from that
// machine.
//
typedef struct _RedfishComputerSystem_V1_4_2_ComputerSystem_CS {
    RedfishCS_Header                                        Header;
    RedfishCS_char                                          *odata_context;          
    RedfishCS_char                                          *odata_id;               
    RedfishCS_char                                          *odata_type;             
    RedfishComputerSystem_V1_4_2_Actions_CS                 *Actions;                    // The available actions for this
                                                                                         // resource.
    RedfishCS_char                                          *AssetTag;                   // The user definable tag that
                                                                                         // can be used to track this
                                                                                         // computer system for inventory
                                                                                         // or other client purposes.
    RedfishCS_Link                                          Bios;                        // A reference to the BIOS
                                                                                         // settings associated with this
                                                                                         // system.
    RedfishCS_char                                          *BiosVersion;                // The version of the system BIOS
                                                                                         // or primary system firmware.
    RedfishComputerSystem_V1_4_2_Boot_CS                    *Boot;                       // Information about the boot
                                                                                         // settings for this system.
    RedfishCS_char                                          *Description;            
    RedfishCS_Link                                          EthernetInterfaces;          // A reference to the collection
                                                                                         // of Ethernet interfaces
                                                                                         // associated with this system.
    RedfishCS_char                                          *HostName;                   // The DNS Host Name, without any
                                                                                         // domain information.
    RedfishComputerSystem_V1_4_2_HostedServices_CS          *HostedServices;             // The services that this
                                                                                         // computer system supports.
    RedfishCS_char_Array                                    *HostingRoles;               // The hosing roles that this
                                                                                         // computer system supports.
    RedfishCS_char                                          *Id;                     
    RedfishCS_char                                          *IndicatorLED;               // The state of the indicator
                                                                                         // LED, used to identify the
                                                                                         // system.
    RedfishComputerSystem_V1_4_2_Links_CS                   *Links;                      // Contains references to other
                                                                                         // resources that are related to
                                                                                         // this resource.
    RedfishCS_Link                                          LogServices;                 // A reference to the collection
                                                                                         // of Log Services associated
                                                                                         // with this system.
    RedfishCS_char                                          *Manufacturer;               // The manufacturer or OEM of
                                                                                         // this system.
    RedfishCS_Link                                          Memory;                      // A reference to the collection
                                                                                         // of Memory associated with this
                                                                                         // system.
    RedfishCS_Link                                          MemoryDomains;               // A reference to the collection
                                                                                         // of Memory Domains associated
                                                                                         // with this system.
    RedfishComputerSystem_V1_4_2_MemorySummary_CS           *MemorySummary;              // This object describes the
                                                                                         // central memory of the system
                                                                                         // in general detail.
    RedfishCS_char                                          *Model;                      // The product name for this
                                                                                         // system, without the
                                                                                         // manufacturer name.
    RedfishCS_char                                          *Name;                   
    RedfishCS_Link                                          NetworkInterfaces;           // A reference to the collection
                                                                                         // of Network Interfaces
                                                                                         // associated with this system.
    RedfishResource_Oem_CS                                  *Oem;                        // This is the
                                                                                         // manufacturer/provider specific
                                                                                         // extension moniker used to
                                                                                         // divide the Oem object into
                                                                                         // sections.
    RedfishCS_Link                                          PCIeDevices;                 // A reference to a collection of
                                                                                         // PCIe Devices used by this
                                                                                         // computer system.
    RedfishCS_int64                                         *PCIeDevicesodata_count; 
    RedfishCS_Link                                          PCIeFunctions;               // A reference to a collection of
                                                                                         // PCIe Functions used by this
                                                                                         // computer system.
    RedfishCS_int64                                         *PCIeFunctionsodata_count;
    RedfishCS_char                                          *PartNumber;                 // The part number for this
                                                                                         // system.
    RedfishCS_char                                          *PowerState;                 // This is the current power
                                                                                         // state of the system.
    RedfishComputerSystem_V1_4_2_ProcessorSummary_CS        *ProcessorSummary;           // This object describes the
                                                                                         // central processors of the
                                                                                         // system in general detail.
    RedfishCS_Link                                          Processors;                  // A reference to the collection
                                                                                         // of Processors associated with
                                                                                         // this system.
    RedfishCS_char                                          *SKU;                        // The manufacturer SKU for this
                                                                                         // system.
    RedfishCS_Link                                          SecureBoot;                  // A reference to the UEFI
                                                                                         // SecureBoot resource associated
                                                                                         // with this system.
    RedfishCS_char                                          *SerialNumber;               // The serial number for this
                                                                                         // system.
    RedfishCS_Link                                          SimpleStorage;               // A reference to the collection
                                                                                         // of storage devices associated
                                                                                         // with this system.
    RedfishResource_Status_CS                               *Status;                 
    RedfishCS_Link                                          Storage;                     // A reference to the collection
                                                                                         // of storage devices associated
                                                                                         // with this system.
    RedfishCS_char                                          *SystemType;                 // The type of computer system
                                                                                         // represented by this resource.
    RedfishComputerSystem_V1_4_2_TrustedModules_Array_CS    *TrustedModules;             // This object describes the
                                                                                         // array of Trusted Modules in
                                                                                         // the system.
    RedfishCS_char                                          *UUID;                       // The universal unique
                                                                                         // identifier (UUID) for this
                                                                                         // system.
} RedfishComputerSystem_V1_4_2_ComputerSystem_CS;

#ifndef __Redfishodata_V4_0_1_idRef_Array_CS__
#define __Redfishodata_V4_0_1_idRef_Array_CS__
typedef struct _Redfishodata_V4_0_1_idRef_Array_CS  {
    Redfishodata_V4_0_1_idRef_Array_CS    *Next;
    Redfishodata_V4_0_1_idRef_CS    *ArrayValue;
} Redfishodata_V4_0_1_idRef_Array_CS;
#endif

typedef struct _RedfishComputerSystem_V1_4_2_TrustedModules_Array_CS  {
    RedfishComputerSystem_V1_4_2_TrustedModules_Array_CS    *Next;
    RedfishComputerSystem_V1_4_2_TrustedModules_CS    *ArrayValue;
} RedfishComputerSystem_V1_4_2_TrustedModules_Array_CS;

RedfishCS_status
Json_ComputerSystem_V1_4_2_To_CS (char *JsonRawText, RedfishComputerSystem_V1_4_2_ComputerSystem_CS **ReturnedCS);

RedfishCS_status
CS_To_ComputerSystem_V1_4_2_JSON (RedfishComputerSystem_V1_4_2_ComputerSystem_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyComputerSystem_V1_4_2_CS (RedfishComputerSystem_V1_4_2_ComputerSystem_CS *CSPtr);

RedfishCS_status
DestroyComputerSystem_V1_4_2_Json (RedfishCS_char *JsonText);

#endif
