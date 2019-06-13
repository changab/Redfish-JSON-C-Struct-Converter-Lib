//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishNetworkport_V1_2_0_CSTRUCT_H_
#define _RedfishNetworkport_V1_2_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishNetworkPort_V1_2_0_NetDevFuncMaxBWAlloc_Array_CS RedfishNetworkPort_V1_2_0_NetDevFuncMaxBWAlloc_Array_CS;
typedef struct _RedfishNetworkPort_V1_2_0_NetDevFuncMinBWAlloc_Array_CS RedfishNetworkPort_V1_2_0_NetDevFuncMinBWAlloc_Array_CS;
typedef struct _RedfishNetworkPort_V1_2_0_SupportedLinkCapabilities_Array_CS RedfishNetworkPort_V1_2_0_SupportedLinkCapabilities_Array_CS;
typedef struct _RedfishNetworkPort_V1_2_0_Actions_CS RedfishNetworkPort_V1_2_0_Actions_CS;
typedef struct _RedfishNetworkPort_V1_2_0_NetDevFuncMaxBWAlloc_CS RedfishNetworkPort_V1_2_0_NetDevFuncMaxBWAlloc_CS;
typedef struct _RedfishNetworkPort_V1_2_0_NetDevFuncMinBWAlloc_CS RedfishNetworkPort_V1_2_0_NetDevFuncMinBWAlloc_CS;
typedef struct _RedfishNetworkPort_V1_2_0_NetworkPort_CS RedfishNetworkPort_V1_2_0_NetworkPort_CS;
typedef struct _RedfishNetworkPort_V1_2_0_OemActions_CS RedfishNetworkPort_V1_2_0_OemActions_CS;
typedef struct _RedfishNetworkPort_V1_2_0_SupportedLinkCapabilities_CS RedfishNetworkPort_V1_2_0_SupportedLinkCapabilities_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishNetworkPort_V1_2_0_Actions_CS {
    RedfishNetworkPort_V1_2_0_OemActions_CS    *Oem;    // This property contains the
                                                       // available OEM specific actions
                                                       // for this resource.
} RedfishNetworkPort_V1_2_0_Actions_CS;

//
// A maximum bandwidth allocation percentage for a Network Device Functions
// associated a port.
//
typedef struct _RedfishNetworkPort_V1_2_0_NetDevFuncMaxBWAlloc_CS {
    RedfishCS_int64    *MaxBWAllocPercent;      // The maximum bandwidth
                                                // allocation percentage
                                                // allocated to the corresponding
                                                // network device function
                                                // instance.
    RedfishCS_Link     NetworkDeviceFunction;    // A reference to the
                                                // NetworkDeviceFunction
                                                // associated with this bandwidth
                                                // setting of this Network Port.
} RedfishNetworkPort_V1_2_0_NetDevFuncMaxBWAlloc_CS;

//
// A minimum bandwidth allocation percentage for a Network Device Functions
// associated a port.
//
typedef struct _RedfishNetworkPort_V1_2_0_NetDevFuncMinBWAlloc_CS {
    RedfishCS_int64    *MinBWAllocPercent;      // The minimum bandwidth
                                                // allocation percentage
                                                // allocated to the corresponding
                                                // network device function
                                                // instance.
    RedfishCS_Link     NetworkDeviceFunction;    // A reference to the
                                                // NetworkDeviceFunction
                                                // associated with this bandwidth
                                                // setting of this Network Port.
} RedfishNetworkPort_V1_2_0_NetDevFuncMinBWAlloc_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishNetworkPort_V1_2_0_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishNetworkPort_V1_2_0_OemActions_CS;

//
// The self-described link capabilities of an assocaited port.
//
typedef struct _RedfishNetworkPort_V1_2_0_SupportedLinkCapabilities_CS {
    RedfishCS_bool           *AutoSpeedNegotiation;    // Indicates whether the port has
                                                       // the capability to auto
                                                       // negotiate speed.
    RedfishCS_int64_Array    *CapableLinkSpeedMbps;    // The self-described link
                                                       // network speed capabilities of
                                                       // this port. Note: Should this
                                                       // be a new enumerated type of
                                                       // link speeds?.
    RedfishCS_char           *LinkNetworkTechnology;    // The self-described link
                                                       // network technology
                                                       // capabilities of this port.
    RedfishCS_int64          *LinkSpeedMbps;           // The speed of the link in Mbps
                                                       // when this link network
                                                       // technology is active.
} RedfishNetworkPort_V1_2_0_SupportedLinkCapabilities_CS;

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
// A Network Port represents a discrete physical port capable of connecting to a
// network.
//
typedef struct _RedfishNetworkPort_V1_2_0_NetworkPort_CS {
    RedfishCS_Header                                                Header;
    RedfishCS_char                                                  *odata_context;               
    RedfishCS_char                                                  *odata_etag;                  
    RedfishCS_char                                                  *odata_id;                    
    RedfishCS_char                                                  *odata_type;                  
    RedfishNetworkPort_V1_2_0_Actions_CS                            *Actions;                         // The available actions for this
                                                                                                      // resource.
    RedfishCS_char                                                  *ActiveLinkTechnology;            // Network Port Active Link
                                                                                                      // Technology.
    RedfishCS_char_Array                                            *AssociatedNetworkAddresses;      // The array of configured
                                                                                                      // network addresses (MAC or WWN)
                                                                                                      // that are associated with this
                                                                                                      // Network Port, including the
                                                                                                      // programmed address of the
                                                                                                      // lowest numbered Network Device
                                                                                                      // Function, the configured but
                                                                                                      // not active address if
                                                                                                      // applicable, the address for
                                                                                                      // hardware port teaming, or
                                                                                                      // other network addresses.
    RedfishCS_int64                                                 *CurrentLinkSpeedMbps;            // Network Port Current Link
                                                                                                      // Speed.
    RedfishCS_char                                                  *Description;                 
    RedfishCS_bool                                                  *EEEEnabled;                      // Whether IEEE 802.3az Energy
                                                                                                      // Efficient Ethernet (EEE) is
                                                                                                      // enabled for this network port.
    RedfishCS_char                                                  *FCFabricName;                    // The FC Fabric Name provided by
                                                                                                      // the switch.
    RedfishCS_char                                                  *FCPortConnectionType;            // This is the connection type of
                                                                                                      // this port.
    RedfishCS_char                                                  *FlowControlConfiguration;        // The locally configured 802.3x
                                                                                                      // flow control setting for this
                                                                                                      // network port.
    RedfishCS_char                                                  *FlowControlStatus;               // The 802.3x flow control
                                                                                                      // behavior negotiated with the
                                                                                                      // link partner for this network
                                                                                                      // port (Ethernet-only).
    RedfishCS_char                                                  *Id;                          
    RedfishCS_char                                                  *LinkStatus;                      // The status of the link between
                                                                                                      // this port and its link
                                                                                                      // partner.
    RedfishCS_int64                                                 *MaxFrameSize;                    // The maximum frame size
                                                                                                      // supported by the port.
    RedfishCS_char                                                  *Name;                        
    RedfishNetworkPort_V1_2_0_NetDevFuncMaxBWAlloc_Array_CS         *NetDevFuncMaxBWAlloc;            // The array of maximum bandwidth
                                                                                                      // allocation percentages for the
                                                                                                      // Network Device Functions
                                                                                                      // associated with this port.
    RedfishNetworkPort_V1_2_0_NetDevFuncMinBWAlloc_Array_CS         *NetDevFuncMinBWAlloc;            // The array of minimum bandwidth
                                                                                                      // allocation percentages for the
                                                                                                      // Network Device Functions
                                                                                                      // associated with this port.
    RedfishCS_int64                                                 *NumberDiscoveredRemotePorts;     // The number of ports not on
                                                                                                      // this adapter that this port
                                                                                                      // has discovered.
    RedfishResource_Oem_CS                                          *Oem;                             // This is the
                                                                                                      // manufacturer/provider specific
                                                                                                      // extension moniker used to
                                                                                                      // divide the Oem object into
                                                                                                      // sections.
    RedfishCS_char                                                  *PhysicalPortNumber;              // The physical port number label
                                                                                                      // for this port.
    RedfishCS_int64                                                 *PortMaximumMTU;                  // The largest maximum
                                                                                                      // transmission unit (MTU) that
                                                                                                      // can be configured for this
                                                                                                      // network port.
    RedfishCS_bool                                                  *SignalDetected;                  // Whether or not the port has
                                                                                                      // detected enough signal on
                                                                                                      // enough lanes to establish
                                                                                                      // link.
    RedfishResource_Status_CS                                       *Status;                          // This property describes the
                                                                                                      // status and health of the
                                                                                                      // resource and its children.
    RedfishCS_char_Array                                            *SupportedEthernetCapabilities;    // The set of Ethernet
                                                                                                      // capabilities that this port
                                                                                                      // supports.
    RedfishNetworkPort_V1_2_0_SupportedLinkCapabilities_Array_CS    *SupportedLinkCapabilities;       // The self-described link
                                                                                                      // capabilities of this port.
    RedfishCS_char                                                  *VendorId;                        // The Vendor Identification for
                                                                                                      // this port.
    RedfishCS_bool                                                  *WakeOnLANEnabled;                // Whether Wake on LAN (WoL) is
                                                                                                      // enabled for this network port.
} RedfishNetworkPort_V1_2_0_NetworkPort_CS;

typedef struct _RedfishNetworkPort_V1_2_0_NetDevFuncMaxBWAlloc_Array_CS  {
    RedfishNetworkPort_V1_2_0_NetDevFuncMaxBWAlloc_Array_CS    *Next;
    RedfishNetworkPort_V1_2_0_NetDevFuncMaxBWAlloc_CS    *ArrayValue;
} RedfishNetworkPort_V1_2_0_NetDevFuncMaxBWAlloc_Array_CS;

typedef struct _RedfishNetworkPort_V1_2_0_NetDevFuncMinBWAlloc_Array_CS  {
    RedfishNetworkPort_V1_2_0_NetDevFuncMinBWAlloc_Array_CS    *Next;
    RedfishNetworkPort_V1_2_0_NetDevFuncMinBWAlloc_CS    *ArrayValue;
} RedfishNetworkPort_V1_2_0_NetDevFuncMinBWAlloc_Array_CS;

typedef struct _RedfishNetworkPort_V1_2_0_SupportedLinkCapabilities_Array_CS  {
    RedfishNetworkPort_V1_2_0_SupportedLinkCapabilities_Array_CS    *Next;
    RedfishNetworkPort_V1_2_0_SupportedLinkCapabilities_CS    *ArrayValue;
} RedfishNetworkPort_V1_2_0_SupportedLinkCapabilities_Array_CS;

RedfishCS_status
Json_NetworkPort_V1_2_0_To_CS (char *JsonRawText, RedfishNetworkPort_V1_2_0_NetworkPort_CS **ReturnedCS);

RedfishCS_status
CS_To_NetworkPort_V1_2_0_JSON (RedfishNetworkPort_V1_2_0_NetworkPort_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyNetworkPort_V1_2_0_CS (RedfishNetworkPort_V1_2_0_NetworkPort_CS *CSPtr);

RedfishCS_status
DestroyNetworkPort_V1_2_0_Json (RedfishCS_char *JsonText);

#endif
