//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishJsonschemafile_V1_1_0_CSTRUCT_H_
#define _RedfishJsonschemafile_V1_1_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishJsonSchemaFile_V1_1_0_Location_Array_CS RedfishJsonSchemaFile_V1_1_0_Location_Array_CS;
typedef struct _RedfishJsonSchemaFile_V1_1_0_JsonSchemaFile_CS RedfishJsonSchemaFile_V1_1_0_JsonSchemaFile_CS;
typedef struct _RedfishJsonSchemaFile_V1_1_0_JsonSchemaFile_Actions_CS RedfishJsonSchemaFile_V1_1_0_JsonSchemaFile_Actions_CS;
typedef struct _RedfishJsonSchemaFile_V1_1_0_JsonSchemaFile_Actions_Oem_CS RedfishJsonSchemaFile_V1_1_0_JsonSchemaFile_Actions_Oem_CS;
typedef struct _RedfishJsonSchemaFile_V1_1_0_Location_CS RedfishJsonSchemaFile_V1_1_0_Location_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishJsonSchemaFile_V1_1_0_JsonSchemaFile_Actions_CS {
    RedfishJsonSchemaFile_V1_1_0_JsonSchemaFile_Actions_Oem_CS    *Oem;    // The available OEM specific
                                                                          // actions for this resource.
} RedfishJsonSchemaFile_V1_1_0_JsonSchemaFile_Actions_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishJsonSchemaFile_V1_1_0_JsonSchemaFile_Actions_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishJsonSchemaFile_V1_1_0_JsonSchemaFile_Actions_Oem_CS;

//
// Location information for a schema file.
//
typedef struct _RedfishJsonSchemaFile_V1_1_0_Location_CS {
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
} RedfishJsonSchemaFile_V1_1_0_Location_CS;

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
typedef struct _RedfishJsonSchemaFile_V1_1_0_JsonSchemaFile_CS {
    RedfishCS_Header                                          Header;
    RedfishCS_char                                            *odata_context;
    RedfishCS_char                                            *odata_id;    
    RedfishCS_char                                            *odata_type;  
    RedfishJsonSchemaFile_V1_1_0_JsonSchemaFile_Actions_CS    *Actions;         // The available actions for this
                                                                                // resource.
    RedfishCS_char                                            *Description; 
    RedfishCS_char                                            *Id;          
    RedfishCS_char_Array                                      *Languages;       // Language codes for the schemas
                                                                                // available.
    RedfishJsonSchemaFile_V1_1_0_Location_Array_CS            *Location;        // Location information for this
                                                                                // schema file.
    RedfishCS_char                                            *Name;        
    RedfishResource_Oem_CS                                    *Oem;             // This is the
                                                                                // manufacturer/provider specific
                                                                                // extension moniker used to
                                                                                // divide the Oem object into
                                                                                // sections.
    RedfishCS_char                                            *Schema;          // The @odata.type name this
                                                                                // schema describes.
} RedfishJsonSchemaFile_V1_1_0_JsonSchemaFile_CS;

typedef struct _RedfishJsonSchemaFile_V1_1_0_Location_Array_CS  {
    RedfishJsonSchemaFile_V1_1_0_Location_Array_CS    *Next;
    RedfishJsonSchemaFile_V1_1_0_Location_CS    *ArrayValue;
} RedfishJsonSchemaFile_V1_1_0_Location_Array_CS;

RedfishCS_status
Json_JsonSchemaFile_V1_1_0_To_CS (char *JsonRawText, RedfishJsonSchemaFile_V1_1_0_JsonSchemaFile_CS **ReturnedCS);

RedfishCS_status
CS_To_JsonSchemaFile_V1_1_0_JSON (RedfishJsonSchemaFile_V1_1_0_JsonSchemaFile_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyJsonSchemaFile_V1_1_0_CS (RedfishJsonSchemaFile_V1_1_0_JsonSchemaFile_CS *CSPtr);

RedfishCS_status
DestroyJsonSchemaFile_V1_1_0_Json (RedfishCS_char *JsonText);

#endif
