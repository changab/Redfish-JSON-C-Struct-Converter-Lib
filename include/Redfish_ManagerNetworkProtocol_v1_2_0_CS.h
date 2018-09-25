//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishManagernetworkprotocol_V1_2_0_CSTRUCT_H_
#define _RedfishManagernetworkprotocol_V1_2_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishManagerNetworkProtocol_V1_2_0_ManagerNetworkProtocol_CS RedfishManagerNetworkProtocol_V1_2_0_ManagerNetworkProtocol_CS;
typedef struct _RedfishManagerNetworkProtocol_V1_2_0_ManagerNetworkProtocol_Actions_CS RedfishManagerNetworkProtocol_V1_2_0_ManagerNetworkProtocol_Actions_CS;
typedef struct _RedfishManagerNetworkProtocol_V1_2_0_ManagerNetworkProtocol_Actions_Oem_CS RedfishManagerNetworkProtocol_V1_2_0_ManagerNetworkProtocol_Actions_Oem_CS;
typedef struct _RedfishManagerNetworkProtocol_V1_2_0_NTPProtocol_CS RedfishManagerNetworkProtocol_V1_2_0_NTPProtocol_CS;
typedef struct _RedfishManagerNetworkProtocol_V1_2_0_Protocol_CS RedfishManagerNetworkProtocol_V1_2_0_Protocol_CS;
typedef struct _RedfishManagerNetworkProtocol_V1_2_0_SSDProtocol_CS RedfishManagerNetworkProtocol_V1_2_0_SSDProtocol_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishManagerNetworkProtocol_V1_2_0_ManagerNetworkProtocol_Actions_CS {
    RedfishManagerNetworkProtocol_V1_2_0_ManagerNetworkProtocol_Actions_Oem_CS    *Oem;    // The available OEM specific
                                                                                          // actions for this resource.
} RedfishManagerNetworkProtocol_V1_2_0_ManagerNetworkProtocol_Actions_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishManagerNetworkProtocol_V1_2_0_ManagerNetworkProtocol_Actions_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishManagerNetworkProtocol_V1_2_0_ManagerNetworkProtocol_Actions_Oem_CS;

//
// Settings for a network protocol associated with a manager.
//
typedef struct _RedfishManagerNetworkProtocol_V1_2_0_NTPProtocol_CS {
    RedfishCS_char_Array    *NTPServers;        // Indicates to which NTP servers
                                                // this manager is subscribed.
    RedfishCS_int64         *Port;              // Indicates the protocol port.
    RedfishCS_bool          *ProtocolEnabled;    // Indicates if the protocol is
                                                // enabled or disabled.
} RedfishManagerNetworkProtocol_V1_2_0_NTPProtocol_CS;

//
// Settings for a network protocol associated with a manager.
//
typedef struct _RedfishManagerNetworkProtocol_V1_2_0_Protocol_CS {
    RedfishCS_int64    *Port;              // Indicates the protocol port.
    RedfishCS_bool     *ProtocolEnabled;    // Indicates if the protocol is
                                           // enabled or disabled.
} RedfishManagerNetworkProtocol_V1_2_0_Protocol_CS;

//
// Settings for a network protocol associated with a manager.
//
typedef struct _RedfishManagerNetworkProtocol_V1_2_0_SSDProtocol_CS {
    RedfishCS_char     *NotifyIPv6Scope;                  // Indicates the scope for the
                                                          // IPv6 Notify messages for SSDP.
    RedfishCS_int64    *NotifyMulticastIntervalSeconds;    // Indicates how often the
                                                          // Multicast is done from this
                                                          // service for SSDP.
    RedfishCS_int64    *NotifyTTL;                        // Indicates the time to live hop
                                                          // count for SSDPs Notify
                                                          // messages.
    RedfishCS_int64    *Port;                             // Indicates the protocol port.
    RedfishCS_bool     *ProtocolEnabled;                  // Indicates if the protocol is
                                                          // enabled or disabled.
} RedfishManagerNetworkProtocol_V1_2_0_SSDProtocol_CS;

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
    RedfishResource_Oem_CS    *Oem;        
    RedfishCS_char            *State;          // This indicates the known state
                                               // of the resource, such as if it
                                               // is enabled.
} RedfishResource_Status_CS;
#endif

//
// This resource is used to obtain or modify the network services managed by a
// given manager.
//
typedef struct _RedfishManagerNetworkProtocol_V1_2_0_ManagerNetworkProtocol_CS {
    RedfishCS_Header                                                          Header;
    RedfishCS_char                                                            *odata_context;
    RedfishCS_char                                                            *odata_id;    
    RedfishCS_char                                                            *odata_type;  
    RedfishManagerNetworkProtocol_V1_2_0_ManagerNetworkProtocol_Actions_CS    *Actions;         // The available actions for this
                                                                                                // resource.
    RedfishManagerNetworkProtocol_V1_2_0_Protocol_CS                          *DHCP;            // Settings for this Manager's
                                                                                                // DHCP protocol support.
    RedfishCS_char                                                            *Description; 
    RedfishCS_char                                                            *FQDN;            // This is the fully qualified
                                                                                                // domain name for the manager
                                                                                                // obtained by DNS including the
                                                                                                // host name and top-level domain
                                                                                                // name.
    RedfishManagerNetworkProtocol_V1_2_0_Protocol_CS                          *HTTP;            // Settings for this Manager's
                                                                                                // HTTP protocol support.
    RedfishManagerNetworkProtocol_V1_2_0_Protocol_CS                          *HTTPS;           // Settings for this Manager's
                                                                                                // HTTPS protocol support.
    RedfishCS_char                                                            *HostName;        // The DNS Host Name of this
                                                                                                // manager, without any domain
                                                                                                // information.
    RedfishManagerNetworkProtocol_V1_2_0_Protocol_CS                          *IPMI;            // Settings for this Manager's
                                                                                                // IPMI-over-LAN protocol
                                                                                                // support.
    RedfishCS_char                                                            *Id;          
    RedfishManagerNetworkProtocol_V1_2_0_Protocol_CS                          *KVMIP;           // Settings for this Manager's
                                                                                                // KVM-IP protocol support.
    RedfishManagerNetworkProtocol_V1_2_0_NTPProtocol_CS                       *NTP;             // Settings for this Manager's
                                                                                                // NTP protocol support.
    RedfishCS_char                                                            *Name;        
    RedfishResource_Oem_CS                                                    *Oem;             // This is the
                                                                                                // manufacturer/provider specific
                                                                                                // extension moniker used to
                                                                                                // divide the Oem object into
                                                                                                // sections.
    RedfishManagerNetworkProtocol_V1_2_0_Protocol_CS                          *SNMP;            // Settings for this Manager's
                                                                                                // SNMP support.
    RedfishManagerNetworkProtocol_V1_2_0_SSDProtocol_CS                       *SSDP;            // Settings for this Manager's
                                                                                                // SSDP support.
    RedfishManagerNetworkProtocol_V1_2_0_Protocol_CS                          *SSH;             // Settings for this Manager's
                                                                                                // SSH (Secure Shell) protocol
                                                                                                // support.
    RedfishResource_Status_CS                                                 *Status;      
    RedfishManagerNetworkProtocol_V1_2_0_Protocol_CS                          *Telnet;          // Settings for this Manager's
                                                                                                // Telnet protocol support.
    RedfishManagerNetworkProtocol_V1_2_0_Protocol_CS                          *VirtualMedia;    // Settings for this Manager's
                                                                                                // Virtual Media support.
} RedfishManagerNetworkProtocol_V1_2_0_ManagerNetworkProtocol_CS;

RedfishCS_status
Json_ManagerNetworkProtocol_V1_2_0_To_CS (char *JsonRawText, RedfishManagerNetworkProtocol_V1_2_0_ManagerNetworkProtocol_CS **ReturnedCS);

RedfishCS_status
CS_To_ManagerNetworkProtocol_V1_2_0_JSON (RedfishManagerNetworkProtocol_V1_2_0_ManagerNetworkProtocol_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyManagerNetworkProtocol_V1_2_0_CS (RedfishManagerNetworkProtocol_V1_2_0_ManagerNetworkProtocol_CS *CSPtr);

RedfishCS_status
DestroyManagerNetworkProtocol_V1_2_0_Json (RedfishCS_char *JsonText);

#endif
