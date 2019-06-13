//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishVirtualmedia_V1_0_3_CSTRUCT_H_
#define _RedfishVirtualmedia_V1_0_3_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

typedef struct _RedfishVirtualMedia_V1_0_3_VirtualMedia_CS RedfishVirtualMedia_V1_0_3_VirtualMedia_CS;
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
// This resource allows monitoring and control of an instance of virtual media
// (e.g. a remote CD, DVD, or USB device) functionality provided by a Manager for
// a system or device.
//
typedef struct _RedfishVirtualMedia_V1_0_3_VirtualMedia_CS {
    RedfishCS_Header          Header;
    RedfishCS_char            *odata_context;
    RedfishCS_char            *odata_id;     
    RedfishCS_char            *odata_type;   
    RedfishCS_char            *ConnectedVia;     // Current virtual media
                                                 // connection methods.
    RedfishCS_char            *Description;  
    RedfishCS_char            *Id;           
    RedfishCS_char            *Image;            // A URI providing the location
                                                 // of the selected image.
    RedfishCS_char            *ImageName;        // The current image name.
    RedfishCS_bool            *Inserted;         // Indicates if virtual media is
                                                 // inserted in the virtual
                                                 // device.
    RedfishCS_char            *MediaTypes;       // This is the media types
                                                 // supported as virtual media.
    RedfishCS_char            *Name;         
    RedfishResource_Oem_CS    *Oem;              // This is the
                                                 // manufacturer/provider specific
                                                 // extension moniker used to
                                                 // divide the Oem object into
                                                 // sections.
    RedfishCS_bool            *WriteProtected;    // Indicates the media is write
                                                 // protected.
} RedfishVirtualMedia_V1_0_3_VirtualMedia_CS;

RedfishCS_status
Json_VirtualMedia_V1_0_3_To_CS (char *JsonRawText, RedfishVirtualMedia_V1_0_3_VirtualMedia_CS **ReturnedCS);

RedfishCS_status
CS_To_VirtualMedia_V1_0_3_JSON (RedfishVirtualMedia_V1_0_3_VirtualMedia_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyVirtualMedia_V1_0_3_CS (RedfishVirtualMedia_V1_0_3_VirtualMedia_CS *CSPtr);

RedfishCS_status
DestroyVirtualMedia_V1_0_3_Json (RedfishCS_char *JsonText);

#endif
