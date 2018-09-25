//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishEthernetinterface_V1_4_0_CSTRUCT_H_
#define _RedfishEthernetinterface_V1_4_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishEthernetInterface_V1_4_0_IPv6AddressPolicyEntry_Array_CS RedfishEthernetInterface_V1_4_0_IPv6AddressPolicyEntry_Array_CS;
typedef struct _RedfishEthernetInterface_V1_4_0_Actions_CS RedfishEthernetInterface_V1_4_0_Actions_CS;
typedef struct _RedfishEthernetInterface_V1_4_0_DHCPv4Configuration_CS RedfishEthernetInterface_V1_4_0_DHCPv4Configuration_CS;
typedef struct _RedfishEthernetInterface_V1_4_0_DHCPv6Configuration_CS RedfishEthernetInterface_V1_4_0_DHCPv6Configuration_CS;
typedef struct _RedfishEthernetInterface_V1_4_0_EthernetInterface_CS RedfishEthernetInterface_V1_4_0_EthernetInterface_CS;
typedef struct _RedfishEthernetInterface_V1_4_0_IPv6AddressPolicyEntry_CS RedfishEthernetInterface_V1_4_0_IPv6AddressPolicyEntry_CS;
typedef struct _RedfishEthernetInterface_V1_4_0_Links_CS RedfishEthernetInterface_V1_4_0_Links_CS;
typedef struct _RedfishEthernetInterface_V1_4_0_OemActions_CS RedfishEthernetInterface_V1_4_0_OemActions_CS;
typedef struct _RedfishEthernetInterface_V1_4_0_StatelessAddressAutoConfiguration_CS RedfishEthernetInterface_V1_4_0_StatelessAddressAutoConfiguration_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishEthernetInterface_V1_4_0_Actions_CS {
    RedfishEthernetInterface_V1_4_0_OemActions_CS    *Oem;
} RedfishEthernetInterface_V1_4_0_Actions_CS;

//
// DHCPv4 configuration for this interface.
//
typedef struct _RedfishEthernetInterface_V1_4_0_DHCPv4Configuration_CS {
    RedfishCS_bool    *DHCPEnabled;       // Determines whether DHCPv4 is
                                          // enabled on this interface.
    RedfishCS_bool    *UseDNSServers;     // Determines whether to use
                                          // DHCPv4-supplied DNS servers.
    RedfishCS_bool    *UseDomainName;     // Determines whether to use a
                                          // DHCPv4-supplied domain name.
    RedfishCS_bool    *UseGateway;        // Determines whether to use a
                                          // DHCPv4-supplied gateway.
    RedfishCS_bool    *UseNTPServers;     // Determines whether to use
                                          // DHCPv4-supplied NTP servers.
    RedfishCS_bool    *UseStaticRoutes;    // Determines whether to use
                                          // DHCPv4-supplied static routes.
} RedfishEthernetInterface_V1_4_0_DHCPv4Configuration_CS;

//
// DHCPv6 configuration for this interface.
//
typedef struct _RedfishEthernetInterface_V1_4_0_DHCPv6Configuration_CS {
    RedfishCS_char    *OperatingMode;    // Determines the DHCPv6
                                         // operating mode for this
                                         // interface.
    RedfishCS_bool    *UseDNSServers;    // When enabled, DNS server
                                         // addresses supplied through
                                         // DHCPv6 stateless mode will be
                                         // used.
    RedfishCS_bool    *UseDomainName;    // When enabled, the domain name
                                         // supplied through DHCPv6
                                         // stateless mode will be used.
    RedfishCS_bool    *UseNTPServers;    // When enabled, NTP server
                                         // addresses supplied through
                                         // DHCPv6 stateless mode will be
                                         // used.
    RedfishCS_bool    *UseRapidCommit;    // Determines whether to use
                                         // DHCPv6 rapid commit mode for
                                         // stateful mode address
                                         // assignments. Do not enable in
                                         // networks where more than one
                                         // DHCPv6 server is configured to
                                         // provide address assignments.
} RedfishEthernetInterface_V1_4_0_DHCPv6Configuration_CS;

//
// A entry in the RFC 6724 Address Selection Policy Table.
//
typedef struct _RedfishEthernetInterface_V1_4_0_IPv6AddressPolicyEntry_CS {
    RedfishCS_int64    *Label;        // The IPv6 Label (as defined in
                                      // RFC 6724 section 2.1).
    RedfishCS_int64    *Precedence;    // The IPv6 Precedence (as
                                      // defined in RFC 6724 section
                                      // 2.1.
    RedfishCS_char     *Prefix;       // The IPv6 Address Prefix (as
                                      // defined in RFC 6724 section
                                      // 2.1).
} RedfishEthernetInterface_V1_4_0_IPv6AddressPolicyEntry_CS;

//
// Contains references to other resources that are related to this resource.
//
typedef struct _RedfishEthernetInterface_V1_4_0_Links_CS {
    RedfishCS_Link            Chassis;                 // A reference to the Chassis
                                                       // which contains this Ethernet
                                                       // Interface.
    RedfishCS_Link            Endpoints;               // An array of references to the
                                                       // endpoints that connect to this
                                                       // ethernet interface.
    RedfishCS_int64           *Endpointsodata_count;
    RedfishCS_Link            HostInterface;           // This is a reference to a Host
                                                       // Interface that is associated
                                                       // with this Ethernet Interface.
    RedfishResource_Oem_CS    *Oem;                    // Oem extension object.
} RedfishEthernetInterface_V1_4_0_Links_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishEthernetInterface_V1_4_0_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishEthernetInterface_V1_4_0_OemActions_CS;

//
// Stateless Address Automatic Configuration (SLAAC) parameters for this
// interface.
//
typedef struct _RedfishEthernetInterface_V1_4_0_StatelessAddressAutoConfiguration_CS {
    RedfishCS_bool    *IPv4AutoConfigEnabled;    // Indicates whether IPv4 SLAAC
                                                // is enabled for this interface.
    RedfishCS_bool    *IPv6AutoConfigEnabled;    // Indicates whether IPv6 SLAAC
                                                // is enabled for this interface.
} RedfishEthernetInterface_V1_4_0_StatelessAddressAutoConfiguration_CS;

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
// The EthernetInterface schema represents a single, logical ethernet interface or
// network interface controller (NIC).
//
typedef struct _RedfishEthernetInterface_V1_4_0_EthernetInterface_CS {
    RedfishCS_Header                                                        Header;
    RedfishCS_char                                                          *odata_context;            
    RedfishCS_char                                                          *odata_id;                 
    RedfishCS_char                                                          *odata_type;               
    RedfishEthernetInterface_V1_4_0_Actions_CS                              *Actions;                      // The available actions for this
                                                                                                           // resource.
    RedfishCS_bool                                                          *AutoNeg;                      // This indicates if the speed
                                                                                                           // and duplex are automatically
                                                                                                           // negotiated and configured on
                                                                                                           // this interface.
    RedfishEthernetInterface_V1_4_0_DHCPv4Configuration_CS                  *DHCPv4;                       // DHCPv4 configuration for this
                                                                                                           // interface.
    RedfishEthernetInterface_V1_4_0_DHCPv6Configuration_CS                  *DHCPv6;                       // DHCPv6 configuration for this
                                                                                                           // interface.
    RedfishCS_char                                                          *Description;              
    RedfishCS_char                                                          *FQDN;                         // This is the complete, fully
                                                                                                           // qualified domain name obtained
                                                                                                           // by DNS for this interface.
    RedfishCS_bool                                                          *FullDuplex;                   // This indicates if the
                                                                                                           // interface is in Full Duplex
                                                                                                           // mode or not.
    RedfishCS_char                                                          *HostName;                     // The DNS Host Name, without any
                                                                                                           // domain information.
    RedfishCS_Link                                                          IPv4Addresses;                 // The IPv4 addresses currently
                                                                                                           // assigned to this interface.
    RedfishCS_Link                                                          IPv4StaticAddresses;           // The IPv4 static addresses
                                                                                                           // assigned to this interface.
    RedfishEthernetInterface_V1_4_0_IPv6AddressPolicyEntry_Array_CS         *IPv6AddressPolicyTable;       // An array representing the RFC
                                                                                                           // 6724 Address Selection Policy
                                                                                                           // Table.
    RedfishCS_Link                                                          IPv6Addresses;                 // Enumerates in an array all of
                                                                                                           // the currently assigned IPv6
                                                                                                           // addresses on this interface.
    RedfishCS_char                                                          *IPv6DefaultGateway;           // This is the IPv6 default
                                                                                                           // gateway address that is
                                                                                                           // currently in use on this
                                                                                                           // interface.
    RedfishCS_Link                                                          IPv6StaticAddresses;           // Represents in an array all of
                                                                                                           // the IPv6 static addresses to
                                                                                                           // be assigned on this interface.
    RedfishCS_Link                                                          IPv6StaticDefaultGateways;     // The IPv6 static default
                                                                                                           // gateways for this interface.
    RedfishCS_char                                                          *Id;                       
    RedfishCS_bool                                                          *InterfaceEnabled;             // This indicates whether this
                                                                                                           // interface is enabled.
    RedfishCS_char                                                          *LinkStatus;                   // The link status of this
                                                                                                           // interface (port).
    RedfishEthernetInterface_V1_4_0_Links_CS                                *Links;                        // Contains references to other
                                                                                                           // resources that are related to
                                                                                                           // this resource.
    RedfishCS_char                                                          *MACAddress;                   // This is the currently
                                                                                                           // configured MAC address of the
                                                                                                           // (logical port) interface.
    RedfishCS_int64                                                         *MTUSize;                      // This is the currently
                                                                                                           // configured Maximum
                                                                                                           // Transmission Unit (MTU) in
                                                                                                           // bytes on this interface.
    RedfishCS_int64                                                         *MaxIPv6StaticAddresses;       // This indicates the maximum
                                                                                                           // number of Static IPv6
                                                                                                           // addresses that can be
                                                                                                           // configured on this interface.
    RedfishCS_char                                                          *Name;                     
    RedfishCS_char_Array                                                    *NameServers;                  // This represents DNS name
                                                                                                           // servers that are currently in
                                                                                                           // use on this interface.
    RedfishResource_Oem_CS                                                  *Oem;                          // This is the
                                                                                                           // manufacturer/provider specific
                                                                                                           // extension moniker used to
                                                                                                           // divide the Oem object into
                                                                                                           // sections.
    RedfishCS_char                                                          *PermanentMACAddress;          // This is the permanent MAC
                                                                                                           // address assigned to this
                                                                                                           // interface (port).
    RedfishCS_int64                                                         *SpeedMbps;                    // This is the current speed in
                                                                                                           // Mbps of this interface.
    RedfishEthernetInterface_V1_4_0_StatelessAddressAutoConfiguration_CS    *StatelessAddressAutoConfig;    // Stateless Address Automatic
                                                                                                           // Configuration (SLAAC)
                                                                                                           // parameters for this interface.
    RedfishCS_char_Array                                                    *StaticNameServers;            // A statically defined set of
                                                                                                           // DNS server IP addresses (both
                                                                                                           // IPv4 and IPv6).
    RedfishResource_Status_CS                                               *Status;                   
    RedfishCS_char                                                          *UefiDevicePath;               // The UEFI device path for this
                                                                                                           // interface.
    RedfishCS_Link                                                          VLAN;                          // If this Network Interface
                                                                                                           // supports more than one VLAN,
                                                                                                           // this property is not present.
                                                                                                           // VLANs collections appear in
                                                                                                           // the Link section of this
                                                                                                           // resource.
    RedfishCS_Link                                                          VLANs;                         // This is a reference to a
                                                                                                           // collection of VLANs and is
                                                                                                           // only used if the interface
                                                                                                           // supports more than one VLANs.
} RedfishEthernetInterface_V1_4_0_EthernetInterface_CS;

typedef struct _RedfishEthernetInterface_V1_4_0_IPv6AddressPolicyEntry_Array_CS  {
    RedfishEthernetInterface_V1_4_0_IPv6AddressPolicyEntry_Array_CS    *Next;
    RedfishEthernetInterface_V1_4_0_IPv6AddressPolicyEntry_CS    *ArrayValue;
} RedfishEthernetInterface_V1_4_0_IPv6AddressPolicyEntry_Array_CS;

RedfishCS_status
Json_EthernetInterface_V1_4_0_To_CS (char *JsonRawText, RedfishEthernetInterface_V1_4_0_EthernetInterface_CS **ReturnedCS);

RedfishCS_status
CS_To_EthernetInterface_V1_4_0_JSON (RedfishEthernetInterface_V1_4_0_EthernetInterface_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyEthernetInterface_V1_4_0_CS (RedfishEthernetInterface_V1_4_0_EthernetInterface_CS *CSPtr);

RedfishCS_status
DestroyEthernetInterface_V1_4_0_Json (RedfishCS_char *JsonText);

#endif
