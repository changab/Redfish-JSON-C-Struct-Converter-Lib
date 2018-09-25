//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishVolume_V1_0_3_CSTRUCT_H_
#define _RedfishVolume_V1_0_3_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

#ifndef __RedfishResource_V1_1_0_Identifier_CS__
typedef struct _RedfishResource_V1_1_0_Identifier_CS RedfishResource_V1_1_0_Identifier_CS;
#endif

typedef struct _RedfishVolume_V1_0_3_Initialize_CS RedfishVolume_V1_0_3_Initialize_CS;
typedef struct _RedfishVolume_V1_0_3_Operations_CS RedfishVolume_V1_0_3_Operations_CS;
typedef struct _RedfishVolume_V1_0_3_Volume_CS RedfishVolume_V1_0_3_Volume_CS;
typedef struct _RedfishVolume_V1_0_3_Volume_Actions_CS RedfishVolume_V1_0_3_Volume_Actions_CS;
typedef struct _RedfishVolume_V1_0_3_Volume_Actions_Oem_CS RedfishVolume_V1_0_3_Volume_Actions_Oem_CS;
typedef struct _RedfishVolume_V1_0_3_Volume_Links_CS RedfishVolume_V1_0_3_Volume_Links_CS;
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

#ifndef __RedfishResource_V1_1_0_Identifier_CS__
#define __RedfishResource_V1_1_0_Identifier_CS__
typedef struct _RedfishResource_V1_1_0_Identifier_CS {
    RedfishCS_char    *DurableName;         // This indicates the world wide,
                                            // persistent name of the
                                            // resource.
    RedfishCS_char    *DurableNameFormat;    // This represents the format of
                                            // the DurableName property.
} RedfishResource_V1_1_0_Identifier_CS;
#endif

//
// This action is used to prepare the contents of the volume for use by the
// system.
//
typedef struct _RedfishVolume_V1_0_3_Initialize_CS {
    RedfishCS_char    *target;    // Link to invoke action
    RedfishCS_char    *title;    // Friendly action name
} RedfishVolume_V1_0_3_Initialize_CS;

//
// An operation currently running on this resource.
//
typedef struct _RedfishVolume_V1_0_3_Operations_CS {
    RedfishCS_Link     AssociatedTask;        // A reference to the task
                                              // associated with the operation
                                              // if any.
    RedfishCS_char     *OperationName;        // The name of the operation.
    RedfishCS_int64    *PercentageComplete;    // The percentage of the
                                              // operation that has been
                                              // completed.
} RedfishVolume_V1_0_3_Operations_CS;

//
// The available actions for this resource.
//
typedef struct _RedfishVolume_V1_0_3_Volume_Actions_CS {
    RedfishVolume_V1_0_3_Initialize_CS            *Volume_Initialize;
    RedfishVolume_V1_0_3_Volume_Actions_Oem_CS    *Oem;                 // The available OEM specific
                                                                        // actions for this resource.
} RedfishVolume_V1_0_3_Volume_Actions_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishVolume_V1_0_3_Volume_Actions_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishVolume_V1_0_3_Volume_Actions_Oem_CS;

//
// Contains references to other resources that are related to this resource.
//
typedef struct _RedfishVolume_V1_0_3_Volume_Links_CS {
    RedfishCS_Link            Drives;                        // An array of references to the
                                                             // drives which contain this
                                                             // volume. This will reference
                                                             // Drives that either wholly or
                                                             // only partly contain this
                                                             // volume.
    RedfishCS_int64           *Drivesodata_count;        
    RedfishCS_char            *Drivesodata_navigationLink;
    RedfishResource_Oem_CS    *Oem;                          // Oem extension object.
} RedfishVolume_V1_0_3_Volume_Links_CS;

//
// Volume contains properties used to describe a volume, virtual disk, LUN, or
// other logical storage entity for any system.
//
typedef struct _RedfishVolume_V1_0_3_Volume_CS {
    RedfishCS_Header                          Header;
    RedfishCS_char                            *odata_context;    
    RedfishCS_char                            *odata_id;         
    RedfishCS_char                            *odata_type;       
    RedfishVolume_V1_0_3_Volume_Actions_CS    *Actions;              // The available actions for this
                                                                     // resource.
    RedfishCS_int64                           *BlockSizeBytes;       // The size of the smallest
                                                                     // addressible unit (Block) of
                                                                     // this volume in bytes.
    RedfishCS_int64                           *CapacityBytes;        // The size in bytes of this
                                                                     // Volume.
    RedfishCS_char                            *Description;      
    RedfishCS_bool                            *Encrypted;            // Is this Volume encrypted.
    RedfishCS_char                            *EncryptionTypes;      // The types of encryption used
                                                                     // by this Volume.
    RedfishCS_char                            *Id;               
    RedfishResource_V1_1_0_Identifier_CS      *Identifiers;          // The Durable names for the
                                                                     // volume.
    RedfishVolume_V1_0_3_Volume_Links_CS      *Links;                // Contains references to other
                                                                     // resources that are related to
                                                                     // this resource.
    RedfishCS_char                            *Name;             
    RedfishResource_Oem_CS                    *Oem;                  // This is the
                                                                     // manufacturer/provider specific
                                                                     // extension moniker used to
                                                                     // divide the Oem object into
                                                                     // sections.
    RedfishVolume_V1_0_3_Operations_CS        *Operations;           // The operations currently
                                                                     // running on the Volume.
    RedfishCS_int64                           *OptimumIOSizeBytes;    // The size in bytes of this
                                                                     // Volume's optimum IO size.
    RedfishResource_Status_CS                 *Status;           
    RedfishCS_char                            *VolumeType;           // The type of this volume.
} RedfishVolume_V1_0_3_Volume_CS;

RedfishCS_status
Json_Volume_V1_0_3_To_CS (char *JsonRawText, RedfishVolume_V1_0_3_Volume_CS **ReturnedCS);

RedfishCS_status
CS_To_Volume_V1_0_3_JSON (RedfishVolume_V1_0_3_Volume_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyVolume_V1_0_3_CS (RedfishVolume_V1_0_3_Volume_CS *CSPtr);

RedfishCS_status
DestroyVolume_V1_0_3_Json (RedfishCS_char *JsonText);

#endif
