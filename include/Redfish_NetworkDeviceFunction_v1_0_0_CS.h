//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishNetworkdevicefunction_V1_0_0_CSTRUCT_H_
#define _RedfishNetworkdevicefunction_V1_0_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishNetworkDeviceFunction_V1_0_0_BootTargets_Array_CS RedfishNetworkDeviceFunction_V1_0_0_BootTargets_Array_CS;
typedef struct _RedfishNetworkDeviceFunction_V1_0_0_BootTargets_CS RedfishNetworkDeviceFunction_V1_0_0_BootTargets_CS;
typedef struct _RedfishNetworkDeviceFunction_V1_0_0_Ethernet_CS RedfishNetworkDeviceFunction_V1_0_0_Ethernet_CS;
typedef struct _RedfishNetworkDeviceFunction_V1_0_0_FibreChannel_CS RedfishNetworkDeviceFunction_V1_0_0_FibreChannel_CS;
typedef struct _RedfishNetworkDeviceFunction_V1_0_0_Links_CS RedfishNetworkDeviceFunction_V1_0_0_Links_CS;
typedef struct _RedfishNetworkDeviceFunction_V1_0_0_NetworkDeviceFunction_CS RedfishNetworkDeviceFunction_V1_0_0_NetworkDeviceFunction_CS;
typedef struct _RedfishNetworkDeviceFunction_V1_0_0_iSCSIBoot_CS RedfishNetworkDeviceFunction_V1_0_0_iSCSIBoot_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

typedef struct _RedfishNetworkDeviceFunction_V1_0_0_BootTargets_CS {
    RedfishCS_int64    *BootPriority;    // The relative priority for this
                                        // entry in the boot targets
                                        // array.
    RedfishCS_char     *LUNID;          // The Logical Unit Number (LUN)
                                        // ID to boot from on the device
                                        // referred to by the
                                        // corresponding WWPN.
    RedfishCS_char     *WWPN;           // The World-Wide Port Name to
                                        // boot from.
} RedfishNetworkDeviceFunction_V1_0_0_BootTargets_CS;

typedef struct _RedfishNetworkDeviceFunction_V1_0_0_Ethernet_CS {
    RedfishCS_char     *MACAddress;            // This is the currently
                                               // configured MAC address of the
                                               // (logical port) network device
                                               // function.
    RedfishCS_int64    *MTUSize;               // The Maximum Transmission Unit
                                               // (MTU) configured for this
                                               // network device function.
    RedfishCS_char     *PermanentMACAddress;    // This is the permanent MAC
                                               // address assigned to this
                                               // network device function
                                               // (physical function).
} RedfishNetworkDeviceFunction_V1_0_0_Ethernet_CS;

typedef struct _RedfishNetworkDeviceFunction_V1_0_0_FibreChannel_CS {
    RedfishCS_bool                                              *AllowFIPVLANDiscovery;    // Whether the FCoE
                                                                                          // Initialization Protocol (FIP)
                                                                                          // is used for populating the
                                                                                          // FCoE VLAN Id.
    RedfishNetworkDeviceFunction_V1_0_0_BootTargets_Array_CS    *BootTargets;             // An array of Fibre Channel boot
                                                                                          // targets configured for this
                                                                                          // network device function.
    RedfishCS_int64                                             *FCoEActiveVLANId;        // The active FCoE VLAN ID.
    RedfishCS_int64                                             *FCoELocalVLANId;         // The locally configured FCoE
                                                                                          // VLAN ID.
    RedfishCS_char                                              *PermanentWWNN;           // This is the permanent WWNN
                                                                                          // address assigned to this
                                                                                          // network device function
                                                                                          // (physical function).
    RedfishCS_char                                              *PermanentWWPN;           // This is the permanent WWPN
                                                                                          // address assigned to this
                                                                                          // network device function
                                                                                          // (physical function).
    RedfishCS_char                                              *WWNN;                    // This is the currently
                                                                                          // configured WWNN address of the
                                                                                          // network device function
                                                                                          // (physical function).
    RedfishCS_char                                              *WWNSource;               // The configuration source of
                                                                                          // the WWNs for this connection
                                                                                          // (WWPN and WWNN).
    RedfishCS_char                                              *WWPN;                    // This is the currently
                                                                                          // configured WWPN address of the
                                                                                          // network device function
                                                                                          // (physical function).
} RedfishNetworkDeviceFunction_V1_0_0_FibreChannel_CS;

typedef struct _RedfishNetworkDeviceFunction_V1_0_0_Links_CS {
    RedfishCS_Link    PCIeFunction;    // Contains the members of this
                                      // collection.
} RedfishNetworkDeviceFunction_V1_0_0_Links_CS;

typedef struct _RedfishNetworkDeviceFunction_V1_0_0_iSCSIBoot_CS {
    RedfishCS_char     *AuthenticationMethod;         // The iSCSI boot authentication
                                                      // method for this network device
                                                      // function.
    RedfishCS_char     *CHAPSecret;                   // The shared secret for CHAP
                                                      // authentication.
    RedfishCS_char     *CHAPUsername;                 // The username for CHAP
                                                      // authentication.
    RedfishCS_char     *IPAddressType;                // The type of IP address (IPv6
                                                      // or IPv4) being populated in
                                                      // the iSCSIBoot IP address
                                                      // fields.
    RedfishCS_bool     *IPMaskDNSViaDHCP;             // Whether the iSCSI boot
                                                      // initiator uses DHCP to obtain
                                                      // the iniator name, IP address,
                                                      // and netmask.
    RedfishCS_char     *InitiatorDefaultGateway;      // The IPv6 or IPv4 iSCSI boot
                                                      // default gateway.
    RedfishCS_char     *InitiatorIPAddress;           // The IPv6 or IPv4 address of
                                                      // the iSCSI initiator.
    RedfishCS_char     *InitiatorName;                // The iSCSI initiator name.
    RedfishCS_char     *InitiatorNetmask;             // The IPv6 or IPv4 netmask of
                                                      // the iSCSI boot initiator.
    RedfishCS_char     *MutualCHAPSecret;             // The CHAP Secret for 2-way CHAP
                                                      // authentication.
    RedfishCS_char     *MutualCHAPUsername;           // The CHAP Username for 2-way
                                                      // CHAP authentication.
    RedfishCS_char     *PrimaryDNS;                   // The IPv6 or IPv4 address of
                                                      // the primary DNS server for the
                                                      // iSCSI boot initiator.
    RedfishCS_int64    *PrimaryLUN;                   // The logical unit number (LUN)
                                                      // for the primary iSCSI boot
                                                      // target.
    RedfishCS_char     *PrimaryTargetIPAddress;       // The IP address (IPv6 or IPv4)
                                                      // for the primary iSCSI boot
                                                      // target.
    RedfishCS_char     *PrimaryTargetName;            // The name of the iSCSI primary
                                                      // boot target.
    RedfishCS_int64    *PrimaryTargetTCPPort;         // The TCP port for the primary
                                                      // iSCSI boot target.
    RedfishCS_bool     *PrimaryVLANEnable;            // This indicates if the primary
                                                      // VLAN is enabled.
    RedfishCS_int64    *PrimaryVLANId;                // The 802.1q VLAN ID to use for
                                                      // iSCSI boot from the primary
                                                      // target.
    RedfishCS_bool     *RouterAdvertisementEnabled;    // Whether IPv6 router
                                                      // advertisement is enabled for
                                                      // the iSCSI boot target.
    RedfishCS_char     *SecondaryDNS;                 // The IPv6 or IPv4 address of
                                                      // the secondary DNS server for
                                                      // the iSCSI boot initiator.
    RedfishCS_int64    *SecondaryLUN;                 // The logical unit number (LUN)
                                                      // for the secondary iSCSI boot
                                                      // target.
    RedfishCS_char     *SecondaryTargetIPAddress;     // The IP address (IPv6 or IPv4)
                                                      // for the secondary iSCSI boot
                                                      // target.
    RedfishCS_char     *SecondaryTargetName;          // The name of the iSCSI
                                                      // secondary boot target.
    RedfishCS_int64    *SecondaryTargetTCPPort;       // The TCP port for the secondary
                                                      // iSCSI boot target.
    RedfishCS_bool     *SecondaryVLANEnable;          // This indicates if the
                                                      // secondary VLAN is enabled.
    RedfishCS_int64    *SecondaryVLANId;              // The 802.1q VLAN ID to use for
                                                      // iSCSI boot from the secondary
                                                      // target.
    RedfishCS_bool     *TargetInfoViaDHCP;            // Whether the iSCSI boot target
                                                      // name, LUN, IP address, and
                                                      // netmask should be obtained
                                                      // from DHCP.
} RedfishNetworkDeviceFunction_V1_0_0_iSCSIBoot_CS;

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
// A Network Device Function represents a logical interface exposed by the network
// adapter.
//
typedef struct _RedfishNetworkDeviceFunction_V1_0_0_NetworkDeviceFunction_CS {
    RedfishCS_Header                                       Header;
    RedfishCS_char                                         *odata_context;                             
    RedfishCS_char                                         *odata_id;                                  
    RedfishCS_char                                         *odata_type;                                
    RedfishCS_Link                                         AssignablePhysicalPorts;                        // Contains the members of this
                                                                                                           // collection.
    RedfishCS_int64                                        *AssignablePhysicalPortsodata_count;        
    RedfishCS_char                                         *AssignablePhysicalPortsodata_navigationLink;
    RedfishCS_char                                         *BootMode;                                      // The boot mode configured for
                                                                                                           // this network device function.
    RedfishCS_char                                         *Description;                               
    RedfishCS_bool                                         *DeviceEnabled;                                 // Whether the network device
                                                                                                           // function is enabled.
    RedfishNetworkDeviceFunction_V1_0_0_Ethernet_CS        *Ethernet;                                      // Ethernet.
    RedfishNetworkDeviceFunction_V1_0_0_FibreChannel_CS    *FibreChannel;                                  // Fibre Channel.
    RedfishCS_char                                         *Id;                                        
    RedfishNetworkDeviceFunction_V1_0_0_Links_CS           *Links;                                         // Links.
    RedfishCS_int64                                        *MaxVirtualFunctions;                           // The number of virtual
                                                                                                           // functions (VFs) that are
                                                                                                           // available for this Network
                                                                                                           // Device Function.
    RedfishCS_char                                         *Name;                                      
    RedfishCS_char_Array                                   *NetDevFuncCapabilities;                        // Capabilities of this network
                                                                                                           // device function.
    RedfishCS_char                                         *NetDevFuncType;                                // The configured capability of
                                                                                                           // this network device function.
    RedfishResource_Oem_CS                                 *Oem;                                           // This is the
                                                                                                           // manufacturer/provider specific
                                                                                                           // extension moniker used to
                                                                                                           // divide the Oem object into
                                                                                                           // sections.
    RedfishCS_Link                                         PhysicalPortAssignment;                         // Contains the members of this
                                                                                                           // collection.
    RedfishResource_Status_CS                              *Status;                                    
    RedfishCS_bool                                         *VirtualFunctionsEnabled;                       // Whether Single Root I/O
                                                                                                           // Virtualization (SR-IOV) Virual
                                                                                                           // Functions (VFs) are enabled
                                                                                                           // for this Network Device
                                                                                                           // Function.
    RedfishNetworkDeviceFunction_V1_0_0_iSCSIBoot_CS       *iSCSIBoot;                                     // iSCSI Boot.
} RedfishNetworkDeviceFunction_V1_0_0_NetworkDeviceFunction_CS;

typedef struct _RedfishNetworkDeviceFunction_V1_0_0_BootTargets_Array_CS  {
    RedfishNetworkDeviceFunction_V1_0_0_BootTargets_Array_CS    *Next;
    RedfishNetworkDeviceFunction_V1_0_0_BootTargets_CS    *ArrayValue;
} RedfishNetworkDeviceFunction_V1_0_0_BootTargets_Array_CS;

RedfishCS_status
Json_NetworkDeviceFunction_V1_0_0_To_CS (char *JsonRawText, RedfishNetworkDeviceFunction_V1_0_0_NetworkDeviceFunction_CS **ReturnedCS);

RedfishCS_status
CS_To_NetworkDeviceFunction_V1_0_0_JSON (RedfishNetworkDeviceFunction_V1_0_0_NetworkDeviceFunction_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyNetworkDeviceFunction_V1_0_0_CS (RedfishNetworkDeviceFunction_V1_0_0_NetworkDeviceFunction_CS *CSPtr);

RedfishCS_status
DestroyNetworkDeviceFunction_V1_0_0_Json (RedfishCS_char *JsonText);

#endif
