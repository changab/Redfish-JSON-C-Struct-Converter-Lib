//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishMessageregistry_V1_2_0_CSTRUCT_H_
#define _RedfishMessageregistry_V1_2_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishMessageRegistry_V1_2_0_Actions_CS RedfishMessageRegistry_V1_2_0_Actions_CS;
typedef struct _RedfishMessageRegistry_V1_2_0_ClearingLogic_CS RedfishMessageRegistry_V1_2_0_ClearingLogic_CS;
typedef struct _RedfishMessageRegistry_V1_2_0_Message_CS RedfishMessageRegistry_V1_2_0_Message_CS;
typedef struct _RedfishMessageRegistry_V1_2_0_MessageProperty_CS RedfishMessageRegistry_V1_2_0_MessageProperty_CS;
typedef struct _RedfishMessageRegistry_V1_2_0_MessageRegistry_CS RedfishMessageRegistry_V1_2_0_MessageRegistry_CS;
typedef struct _RedfishMessageRegistry_V1_2_0_OemActions_CS RedfishMessageRegistry_V1_2_0_OemActions_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishMessageRegistry_V1_2_0_Actions_CS {
    RedfishMessageRegistry_V1_2_0_OemActions_CS    *Oem;    // This property contains the
                                                           // available OEM specific actions
                                                           // for this resource.
} RedfishMessageRegistry_V1_2_0_Actions_CS;

//
// The clearing logic associated with this message.  The properties within
// indicate that what messages are cleared by this message as well as under what
// conditions.
//
typedef struct _RedfishMessageRegistry_V1_2_0_ClearingLogic_CS {
    RedfishCS_bool          *ClearsAll;       // This property indicates that
                                              // all prior conditions and
                                              // messages are cleared provided
                                              // the ClearsIf condition is met.
    RedfishCS_char          *ClearsIf;        // This property contains the
                                              // available OEM specific actions
                                              // for this resource.
    RedfishCS_char_Array    *ClearsMessage;    // This property contains the
                                              // array of Message Ids that are
                                              // cleared by this message,
                                              // provided the other conditions
                                              // are met.
} RedfishMessageRegistry_V1_2_0_ClearingLogic_CS;

//
// This type shall reprensent how a message is defined within the registry.
//
typedef struct _RedfishMessageRegistry_V1_2_0_Message_CS {
    RedfishMessageRegistry_V1_2_0_ClearingLogic_CS    *ClearingLogic;    // The clearing logic associated
                                                                        // with this message.  The
                                                                        // properties within indicate
                                                                        // that what messages are cleared
                                                                        // by this message as well as
                                                                        // under what conditions.
    RedfishCS_char                                    *Description;     // This is a short description of
                                                                        // how and when this message is
                                                                        // to be used.
    RedfishCS_char                                    *Message;         // The actual message.
    RedfishCS_int64                                   *NumberOfArgs;    // The number of arguments to be
                                                                        // expected to be passed in as
                                                                        // MessageArgs for this message.
    RedfishResource_Oem_CS                            *Oem;             // Oem extension object.
    RedfishCS_char_Array                              *ParamTypes;      // The MessageArg types, in
                                                                        // order, for the message.
    RedfishCS_char                                    *Resolution;      // Used to provide suggestions on
                                                                        // how to resolve the situation
                                                                        // that caused the error.
    RedfishCS_char                                    *Severity;        // This is the severity of the
                                                                        // message.
} RedfishMessageRegistry_V1_2_0_Message_CS;

//
// The pattern type indicates that a free-form string is the unique identifier for
// the message within the registry.
//
typedef struct _RedfishMessageRegistry_V1_2_0_MessageProperty_CS {
    RedfishCS_Link    Prop;
} RedfishMessageRegistry_V1_2_0_MessageProperty_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishMessageRegistry_V1_2_0_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishMessageRegistry_V1_2_0_OemActions_CS;

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
// This is the schema definition for all Message Registries.  It represents the
// properties for the registries themselves.  The MessageId is formed per the
// Redfish specification.  It consists of the RegistryPrefix concatenated with the
// version concatenated with the unique identifier for the message registry entry.
//
typedef struct _RedfishMessageRegistry_V1_2_0_MessageRegistry_CS {
    RedfishCS_Header                                    Header;
    RedfishCS_char                                      *odata_context; 
    RedfishCS_char                                      *odata_etag;    
    RedfishCS_char                                      *odata_id;      
    RedfishCS_char                                      *odata_type;    
    RedfishMessageRegistry_V1_2_0_Actions_CS            *Actions;           // The available actions for this
                                                                            // resource.
    RedfishCS_char                                      *Description;   
    RedfishCS_char                                      *Id;            
    RedfishCS_char                                      *Language;          // This is the RFC 5646 compliant
                                                                            // language code for the
                                                                            // registry.
    RedfishMessageRegistry_V1_2_0_MessageProperty_CS    *Messages;          // The pattern property indicates
                                                                            // that a free-form string is the
                                                                            // unique identifier for the
                                                                            // message within the registry.
    RedfishCS_char                                      *Name;          
    RedfishResource_Oem_CS                              *Oem;               // This is the
                                                                            // manufacturer/provider specific
                                                                            // extension moniker used to
                                                                            // divide the Oem object into
                                                                            // sections.
    RedfishCS_char                                      *OwningEntity;      // This is the organization or
                                                                            // company that publishes this
                                                                            // registry.
    RedfishCS_char                                      *RegistryPrefix;    // This is the single word prefix
                                                                            // used to form a messageID
                                                                            // structure.
    RedfishCS_char                                      *RegistryVersion;    // This is the message registry
                                                                            // version which is used in the
                                                                            // middle portion of a messageID.
} RedfishMessageRegistry_V1_2_0_MessageRegistry_CS;

RedfishCS_status
Json_MessageRegistry_V1_2_0_To_CS (char *JsonRawText, RedfishMessageRegistry_V1_2_0_MessageRegistry_CS **ReturnedCS);

RedfishCS_status
CS_To_MessageRegistry_V1_2_0_JSON (RedfishMessageRegistry_V1_2_0_MessageRegistry_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyMessageRegistry_V1_2_0_CS (RedfishMessageRegistry_V1_2_0_MessageRegistry_CS *CSPtr);

RedfishCS_status
DestroyMessageRegistry_V1_2_0_Json (RedfishCS_char *JsonText);

#endif
