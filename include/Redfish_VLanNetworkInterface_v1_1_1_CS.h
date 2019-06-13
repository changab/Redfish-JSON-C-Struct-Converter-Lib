//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishVlannetworkinterface_V1_1_1_CSTRUCT_H_
#define _RedfishVlannetworkinterface_V1_1_1_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

typedef struct _RedfishVLanNetworkInterface_V1_1_1_Actions_CS RedfishVLanNetworkInterface_V1_1_1_Actions_CS;
typedef struct _RedfishVLanNetworkInterface_V1_1_1_OemActions_CS RedfishVLanNetworkInterface_V1_1_1_OemActions_CS;
typedef struct _RedfishVLanNetworkInterface_V1_1_1_VLAN_CS RedfishVLanNetworkInterface_V1_1_1_VLAN_CS;
typedef struct _RedfishVLanNetworkInterface_V1_1_1_VLanNetworkInterface_CS RedfishVLanNetworkInterface_V1_1_1_VLanNetworkInterface_CS;
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
// The available actions for this resource.
//
typedef struct _RedfishVLanNetworkInterface_V1_1_1_Actions_CS {
    RedfishVLanNetworkInterface_V1_1_1_OemActions_CS    *Oem;
} RedfishVLanNetworkInterface_V1_1_1_Actions_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishVLanNetworkInterface_V1_1_1_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishVLanNetworkInterface_V1_1_1_OemActions_CS;

//
// This type describes the attributes of a Virtual LAN.
//
typedef struct _RedfishVLanNetworkInterface_V1_1_1_VLAN_CS {
    RedfishCS_bool     *VLANEnable;    // This indicates if this VLAN is
                                      // enabled.
    RedfishCS_int64    *VLANId;       // This indicates the VLAN
                                      // identifier for this VLAN.
} RedfishVLanNetworkInterface_V1_1_1_VLAN_CS;

//
// This resource describes the attributes of a Virtual LAN.
//
typedef struct _RedfishVLanNetworkInterface_V1_1_1_VLanNetworkInterface_CS {
    RedfishCS_Header                                 Header;
    RedfishCS_char                                   *odata_context;
    RedfishCS_char                                   *odata_id;    
    RedfishCS_char                                   *odata_type;  
    RedfishVLanNetworkInterface_V1_1_1_Actions_CS    *Actions;         // The available actions for this
                                                                       // resource.
    RedfishCS_char                                   *Description; 
    RedfishCS_char                                   *Id;          
    RedfishCS_char                                   *Name;        
    RedfishResource_Oem_CS                           *Oem;             // This is the
                                                                       // manufacturer/provider specific
                                                                       // extension moniker used to
                                                                       // divide the Oem object into
                                                                       // sections.
    RedfishCS_bool                                   *VLANEnable;      // This indicates if this VLAN is
                                                                       // enabled.
    RedfishCS_int64                                  *VLANId;          // This indicates the VLAN
                                                                       // identifier for this VLAN.
} RedfishVLanNetworkInterface_V1_1_1_VLanNetworkInterface_CS;

RedfishCS_status
Json_VLanNetworkInterface_V1_1_1_To_CS (char *JsonRawText, RedfishVLanNetworkInterface_V1_1_1_VLanNetworkInterface_CS **ReturnedCS);

RedfishCS_status
CS_To_VLanNetworkInterface_V1_1_1_JSON (RedfishVLanNetworkInterface_V1_1_1_VLanNetworkInterface_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyVLanNetworkInterface_V1_1_1_CS (RedfishVLanNetworkInterface_V1_1_1_VLanNetworkInterface_CS *CSPtr);

RedfishCS_status
DestroyVLanNetworkInterface_V1_1_1_Json (RedfishCS_char *JsonText);

#endif
