//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishMessageregistryfile_V1_0_0_CSTRUCT_H_
#define _RedfishMessageregistryfile_V1_0_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishMessageRegistryFile_V1_0_0_Location_Array_CS RedfishMessageRegistryFile_V1_0_0_Location_Array_CS;
typedef struct _RedfishMessageRegistryFile_V1_0_0_Location_CS RedfishMessageRegistryFile_V1_0_0_Location_CS;
typedef struct _RedfishMessageRegistryFile_V1_0_0_MessageRegistryFile_CS RedfishMessageRegistryFile_V1_0_0_MessageRegistryFile_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

typedef struct _RedfishMessageRegistryFile_V1_0_0_Location_CS {
    RedfishCS_char    *ArchiveFile;      // If the schema is hosted on the
                                         // service in an archive file,
                                         // this is the name of the file
                                         // within the archive.
    RedfishCS_char    *ArchiveUri;       // If the schema is hosted on the
                                         // service in an archive file,
                                         // this is the link to the
                                         // archive file.
    RedfishCS_char    *Language;         // The language code for the file
                                         // the schema is in.
    RedfishCS_char    *PublicationUri;    // Link to publicly available
                                         // (canonical) URI for schema.
    RedfishCS_char    *Uri;              // Link to locally available URI
                                         // for schema.
} RedfishMessageRegistryFile_V1_0_0_Location_CS;

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
// This is the schema definition for the Schema File locator resource.
//
typedef struct _RedfishMessageRegistryFile_V1_0_0_MessageRegistryFile_CS {
    RedfishCS_Header                                       Header;
    RedfishCS_char                                         *odata_context;
    RedfishCS_char                                         *odata_id;    
    RedfishCS_char                                         *odata_type;  
    RedfishCS_char                                         *Description; 
    RedfishCS_char                                         *Id;          
    RedfishCS_char_Array                                   *Languages;       // Language codes for the schemas
                                                                             // available.
    RedfishMessageRegistryFile_V1_0_0_Location_Array_CS    *Location;        // Location information for this
                                                                             // schema file.
    RedfishCS_char                                         *Name;        
    RedfishResource_Oem_CS                                 *Oem;             // This is the
                                                                             // manufacturer/provider specific
                                                                             // extension moniker used to
                                                                             // divide the Oem object into
                                                                             // sections.
    RedfishCS_char                                         *Registry;        // The Registry Name, Major and
                                                                             // Minor version used in
                                                                             // MessageID construction.
} RedfishMessageRegistryFile_V1_0_0_MessageRegistryFile_CS;

typedef struct _RedfishMessageRegistryFile_V1_0_0_Location_Array_CS  {
    RedfishMessageRegistryFile_V1_0_0_Location_Array_CS    *Next;
    RedfishMessageRegistryFile_V1_0_0_Location_CS    *ArrayValue;
} RedfishMessageRegistryFile_V1_0_0_Location_Array_CS;

RedfishCS_status
Json_MessageRegistryFile_V1_0_0_To_CS (char *JsonRawText, RedfishMessageRegistryFile_V1_0_0_MessageRegistryFile_CS **ReturnedCS);

RedfishCS_status
CS_To_MessageRegistryFile_V1_0_0_JSON (RedfishMessageRegistryFile_V1_0_0_MessageRegistryFile_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyMessageRegistryFile_V1_0_0_CS (RedfishMessageRegistryFile_V1_0_0_MessageRegistryFile_CS *CSPtr);

RedfishCS_status
DestroyMessageRegistryFile_V1_0_0_Json (RedfishCS_char *JsonText);

#endif
