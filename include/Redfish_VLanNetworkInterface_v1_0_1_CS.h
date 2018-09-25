//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishVlannetworkinterface_V1_0_1_CSTRUCT_H_
#define _RedfishVlannetworkinterface_V1_0_1_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

typedef struct _RedfishVLanNetworkInterface_V1_0_1_VLAN_CS RedfishVLanNetworkInterface_V1_0_1_VLAN_CS;
typedef struct _RedfishVLanNetworkInterface_V1_0_1_VLanNetworkInterface_CS RedfishVLanNetworkInterface_V1_0_1_VLanNetworkInterface_CS;
//
// Oem extension object.
//
#ifndef __RedfishResource_Oem_CS__
#define __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishResource_Oem_CS;
#endif

typedef struct _RedfishVLanNetworkInterface_V1_0_1_VLAN_CS {
    RedfishCS_bool     *VLANEnable;    // This indicates if this VLAN is
                                      // enabled.
    RedfishCS_int64    *VLANId;       // This indicates the VLAN
                                      // identifier for this VLAN.
} RedfishVLanNetworkInterface_V1_0_1_VLAN_CS;

//
// This resource contains information for a Virtual LAN (VLAN) network instance
// available on a manager, system or other device.
//
typedef struct _RedfishVLanNetworkInterface_V1_0_1_VLanNetworkInterface_CS {
    RedfishCS_Header          Header;
    RedfishCS_char            *odata_context;
    RedfishCS_char            *odata_id;    
    RedfishCS_char            *odata_type;  
    RedfishCS_char            *Description; 
    RedfishCS_char            *Id;          
    RedfishCS_char            *Name;        
    RedfishResource_Oem_CS    *Oem;             // This is the
                                                // manufacturer/provider specific
                                                // extension moniker used to
                                                // divide the Oem object into
                                                // sections.
    RedfishCS_bool            *VLANEnable;      // This indicates if this VLAN is
                                                // enabled.
    RedfishCS_int64           *VLANId;          // This indicates the VLAN
                                                // identifier for this VLAN.
} RedfishVLanNetworkInterface_V1_0_1_VLanNetworkInterface_CS;

RedfishCS_status
Json_VLanNetworkInterface_V1_0_1_To_CS (char *JsonRawText, RedfishVLanNetworkInterface_V1_0_1_VLanNetworkInterface_CS **ReturnedCS);

RedfishCS_status
CS_To_VLanNetworkInterface_V1_0_1_JSON (RedfishVLanNetworkInterface_V1_0_1_VLanNetworkInterface_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyVLanNetworkInterface_V1_0_1_CS (RedfishVLanNetworkInterface_V1_0_1_VLanNetworkInterface_CS *CSPtr);

RedfishCS_status
DestroyVLanNetworkInterface_V1_0_1_Json (RedfishCS_char *JsonText);

#endif
