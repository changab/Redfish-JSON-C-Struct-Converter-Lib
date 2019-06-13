//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishMemory_V1_0_0_CSTRUCT_H_
#define _RedfishMemory_V1_0_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishMemory_V1_0_0_RegionSet_Array_CS RedfishMemory_V1_0_0_RegionSet_Array_CS;
typedef struct _RedfishMemory_V1_0_0_DisablePassphrase_CS RedfishMemory_V1_0_0_DisablePassphrase_CS;
typedef struct _RedfishMemory_V1_0_0_Memory_CS RedfishMemory_V1_0_0_Memory_CS;
typedef struct _RedfishMemory_V1_0_0_MemoryLocation_CS RedfishMemory_V1_0_0_MemoryLocation_CS;
typedef struct _RedfishMemory_V1_0_0_Memory_Actions_CS RedfishMemory_V1_0_0_Memory_Actions_CS;
typedef struct _RedfishMemory_V1_0_0_Memory_Actions_Oem_CS RedfishMemory_V1_0_0_Memory_Actions_Oem_CS;
typedef struct _RedfishMemory_V1_0_0_PowerManagementPolicy_CS RedfishMemory_V1_0_0_PowerManagementPolicy_CS;
typedef struct _RedfishMemory_V1_0_0_RegionSet_CS RedfishMemory_V1_0_0_RegionSet_CS;
typedef struct _RedfishMemory_V1_0_0_SecureEraseUnit_CS RedfishMemory_V1_0_0_SecureEraseUnit_CS;
typedef struct _RedfishMemory_V1_0_0_SecurityCapabilities_CS RedfishMemory_V1_0_0_SecurityCapabilities_CS;
typedef struct _RedfishMemory_V1_0_0_SetPassphrase_CS RedfishMemory_V1_0_0_SetPassphrase_CS;
typedef struct _RedfishMemory_V1_0_0_UnlockUnit_CS RedfishMemory_V1_0_0_UnlockUnit_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

//
// Disable passphrase for given regions
//
typedef struct _RedfishMemory_V1_0_0_DisablePassphrase_CS {
    RedfishCS_char    *target;    // Link to invoke action
    RedfishCS_char    *title;    // Friendly action name
} RedfishMemory_V1_0_0_DisablePassphrase_CS;

//
// .
//
typedef struct _RedfishMemory_V1_0_0_MemoryLocation_CS {
    RedfishCS_int64    *Channel;            // Channel number in which Memory
                                            // is connected
    RedfishCS_int64    *MemoryController;    // Memory controller number in
                                            // which Memory is connected
    RedfishCS_int64    *Slot;               // Slot number in which Memory is
                                            // connected
    RedfishCS_int64    *Socket;             // Socket number in which Memory
                                            // is connected
} RedfishMemory_V1_0_0_MemoryLocation_CS;

//
// The available actions for this resource.
//
typedef struct _RedfishMemory_V1_0_0_Memory_Actions_CS {
    RedfishMemory_V1_0_0_DisablePassphrase_CS     *Memory_DisablePassphrase;
    RedfishMemory_V1_0_0_SecureEraseUnit_CS       *Memory_SecureEraseUnit; 
    RedfishMemory_V1_0_0_SetPassphrase_CS         *Memory_SetPassphrase;   
    RedfishMemory_V1_0_0_UnlockUnit_CS            *Memory_UnlockUnit;      
    RedfishMemory_V1_0_0_Memory_Actions_Oem_CS    *Oem;                    
} RedfishMemory_V1_0_0_Memory_Actions_CS;

typedef struct _RedfishMemory_V1_0_0_Memory_Actions_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishMemory_V1_0_0_Memory_Actions_Oem_CS;

//
// .
//
typedef struct _RedfishMemory_V1_0_0_PowerManagementPolicy_CS {
    RedfishCS_int64    *AveragePowerBudgetMilliWatts;    // Average power budget in milli
                                                        // watts
    RedfishCS_int64    *MaxTDPMilliWatts;               // Maximum TDP in milli watts
    RedfishCS_int64    *PeakPowerBudgetMilliWatts;      // Peak power budget in milli
                                                        // watts
    RedfishCS_bool     *PolicyEnabled;                  // Power management policy
                                                        // enabled status
} RedfishMemory_V1_0_0_PowerManagementPolicy_CS;

//
// Memory memory region information.
//
typedef struct _RedfishMemory_V1_0_0_RegionSet_CS {
    RedfishCS_char     *MemoryClassification;    // Classification of memory
                                                // occupied by the given memory
                                                // region
    RedfishCS_int64    *OffsetMiB;              // Offset with in the Memory that
                                                // corresponds to the starting of
                                                // this memory region in MiB
    RedfishCS_bool     *PassphraseState;        // State of the passphrase for
                                                // this region
    RedfishCS_char     *RegionId;               // Unique region ID representing
                                                // a specific region within the
                                                // Memory
    RedfishCS_int64    *SizeMiB;                // Size of this memory region in
                                                // MiB
} RedfishMemory_V1_0_0_RegionSet_CS;

//
// This defines the action for securely erasing given regions.
//
typedef struct _RedfishMemory_V1_0_0_SecureEraseUnit_CS {
    RedfishCS_char    *target;    // Link to invoke action
    RedfishCS_char    *title;    // Friendly action name
} RedfishMemory_V1_0_0_SecureEraseUnit_CS;

typedef struct _RedfishMemory_V1_0_0_SecurityCapabilities_CS {
    RedfishCS_int64         *MaxPassphraseCount;    // Maximum number of passphrases
                                                   // supported for this Memory
    RedfishCS_bool          *PassphraseCapable;    // Memory passphrase set
                                                   // capability
    RedfishCS_char_Array    *SecurityStates;       // Security states supported by
                                                   // the Memory
} RedfishMemory_V1_0_0_SecurityCapabilities_CS;

//
// Set passphrase for the given regions
//
typedef struct _RedfishMemory_V1_0_0_SetPassphrase_CS {
    RedfishCS_char    *target;    // Link to invoke action
    RedfishCS_char    *title;    // Friendly action name
} RedfishMemory_V1_0_0_SetPassphrase_CS;

//
// This defines the action for unlocking given regions.
//
typedef struct _RedfishMemory_V1_0_0_UnlockUnit_CS {
    RedfishCS_char    *target;    // Link to invoke action
    RedfishCS_char    *title;    // Friendly action name
} RedfishMemory_V1_0_0_UnlockUnit_CS;

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
// This is the schema definition for definition of a Memory and its configuration
//
typedef struct _RedfishMemory_V1_0_0_Memory_CS {
    RedfishCS_Header                                 Header;
    RedfishCS_char                                   *odata_context;              
    RedfishCS_char                                   *odata_id;                   
    RedfishCS_char                                   *odata_type;                 
    RedfishMemory_V1_0_0_Memory_Actions_CS           *Actions;                        // The available actions for this
                                                                                      // resource.
    RedfishCS_int64_Array                            *AllowedSpeedsMHz;               // Speed bins supported by this
                                                                                      // Memory
    RedfishCS_char                                   *BaseModuleType;                 // The base module type of Memory
    RedfishCS_int64                                  *BusWidthBits;                   // Bus Width in bits.
    RedfishCS_int64                                  *CapacityMiB;                    // Memory Capacity in MiB.
    RedfishCS_int64                                  *DataWidthBits;                  // Data Width in bits.
    RedfishCS_char                                   *Description;                
    RedfishCS_char                                   *DeviceID;                       // Device ID
    RedfishCS_char                                   *DeviceLocator;                  // Location of the Memory in the
                                                                                      // platform
    RedfishCS_char                                   *ErrorCorrection;                // Error correction scheme
                                                                                      // supported for this memory
    RedfishCS_char                                   *FirmwareApiVersion;             // Version of API supported by
                                                                                      // the firmware
    RedfishCS_char                                   *FirmwareRevision;               // Revision of firmware on the
                                                                                      // Memory controller
    RedfishCS_char_Array                             *FunctionClasses;                // Function Classes by the Memory
    RedfishCS_char                                   *Id;                         
    RedfishCS_bool                                   *IsRankSpareEnabled;             // Rank spare enabled status
    RedfishCS_bool                                   *IsSpareDeviceEnabled;           // Spare device enabled status
    RedfishCS_char                                   *Manufacturer;                   // The Memory manufacturer
    RedfishCS_int64_Array                            *MaxTDPMilliWatts;               // Maximum TDPs in milli Watts
    RedfishCS_char                                   *MemoryDeviceType;               // Type details of the Memory
    RedfishMemory_V1_0_0_MemoryLocation_CS           *MemoryLocation;                 // Memory connection information
                                                                                      // to sockets and memory
                                                                                      // controllers.
    RedfishCS_char_Array                             *MemoryMedia;                    // Media  of this Memory
    RedfishCS_char                                   *MemoryType;                     // The type of Memory
    RedfishCS_Link                                   Metrics;                         // A reference to the Metrics
                                                                                      // associated with this Memory
    RedfishCS_char                                   *Name;                       
    RedfishResource_Oem_CS                           *Oem;                            // This is the
                                                                                      // manufacturer/provider specific
                                                                                      // extension moniker used to
                                                                                      // divide the Oem object into
                                                                                      // sections.
    RedfishCS_char_Array                             *OperatingMemoryModes;           // Memory modes supported by the
                                                                                      // Memory
    RedfishCS_int64                                  *OperatingSpeedMhz;              // Operating speed of Memory in
                                                                                      // MHz
    RedfishCS_char                                   *PartNumber;                     // The product part number of
                                                                                      // this device
    RedfishCS_int64                                  *PersistentRegionSizeLimitMiB;    // Total size of persistent
                                                                                      // regions in MiB
    RedfishMemory_V1_0_0_PowerManagementPolicy_CS    *PowerManagementPolicy;          // Power management policy
                                                                                      // information.
    RedfishCS_int64                                  *RankCount;                      // Number of ranks available in
                                                                                      // the Memory
    RedfishMemory_V1_0_0_RegionSet_Array_CS          *Regions;                        // Memory regions information
                                                                                      // within the Memory
    RedfishMemory_V1_0_0_SecurityCapabilities_CS     *SecurityCapabilities;           // This object contains security
                                                                                      // capabilities of the Memory.
    RedfishCS_char                                   *SerialNumber;                   // The product serial number of
                                                                                      // this device
    RedfishCS_int64                                  *SpareDeviceCount;               // Number of unused spare devices
                                                                                      // available in the Memory
    RedfishCS_char                                   *SubsystemDeviceID;              // Subsystem Device ID
    RedfishCS_char                                   *SubsystemVendorID;              // SubSystem Vendor ID
    RedfishCS_char                                   *VendorID;                       // Vendor ID
    RedfishCS_int64                                  *VolatileRegionSizeLimitMiB;     // Total size of volatile regions
                                                                                      // in MiB
} RedfishMemory_V1_0_0_Memory_CS;

typedef struct _RedfishMemory_V1_0_0_RegionSet_Array_CS  {
    RedfishMemory_V1_0_0_RegionSet_Array_CS    *Next;
    RedfishMemory_V1_0_0_RegionSet_CS    *ArrayValue;
} RedfishMemory_V1_0_0_RegionSet_Array_CS;

RedfishCS_status
Json_Memory_V1_0_0_To_CS (char *JsonRawText, RedfishMemory_V1_0_0_Memory_CS **ReturnedCS);

RedfishCS_status
CS_To_Memory_V1_0_0_JSON (RedfishMemory_V1_0_0_Memory_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyMemory_V1_0_0_CS (RedfishMemory_V1_0_0_Memory_CS *CSPtr);

RedfishCS_status
DestroyMemory_V1_0_0_Json (RedfishCS_char *JsonText);

#endif
