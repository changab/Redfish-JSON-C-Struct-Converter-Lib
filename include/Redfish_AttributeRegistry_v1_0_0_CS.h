//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishAttributeregistry_V1_0_0_CSTRUCT_H_
#define _RedfishAttributeregistry_V1_0_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishAttributeRegistry_V1_0_0_Dependencies_Array_CS RedfishAttributeRegistry_V1_0_0_Dependencies_Array_CS;
typedef struct _RedfishAttributeRegistry_V1_0_0_Menus_Array_CS RedfishAttributeRegistry_V1_0_0_Menus_Array_CS;
typedef struct _RedfishAttributeRegistry_V1_0_0_Attributes_Array_CS RedfishAttributeRegistry_V1_0_0_Attributes_Array_CS;
typedef struct _RedfishAttributeRegistry_V1_0_0_MapFrom_Array_CS RedfishAttributeRegistry_V1_0_0_MapFrom_Array_CS;
typedef struct _RedfishAttributeRegistry_V1_0_0_AttributeValue_Array_CS RedfishAttributeRegistry_V1_0_0_AttributeValue_Array_CS;
typedef struct _RedfishAttributeRegistry_V1_0_0_SupportedSystems_Array_CS RedfishAttributeRegistry_V1_0_0_SupportedSystems_Array_CS;
typedef struct _RedfishAttributeRegistry_V1_0_0_AttributeRegistry_CS RedfishAttributeRegistry_V1_0_0_AttributeRegistry_CS;
typedef struct _RedfishAttributeRegistry_V1_0_0_AttributeValue_CS RedfishAttributeRegistry_V1_0_0_AttributeValue_CS;
typedef struct _RedfishAttributeRegistry_V1_0_0_Attributes_CS RedfishAttributeRegistry_V1_0_0_Attributes_CS;
typedef struct _RedfishAttributeRegistry_V1_0_0_Dependencies_CS RedfishAttributeRegistry_V1_0_0_Dependencies_CS;
typedef struct _RedfishAttributeRegistry_V1_0_0_Dependency_CS RedfishAttributeRegistry_V1_0_0_Dependency_CS;
typedef struct _RedfishAttributeRegistry_V1_0_0_MapFrom_CS RedfishAttributeRegistry_V1_0_0_MapFrom_CS;
typedef struct _RedfishAttributeRegistry_V1_0_0_Menus_CS RedfishAttributeRegistry_V1_0_0_Menus_CS;
typedef struct _RedfishAttributeRegistry_V1_0_0_RegistryEntries_CS RedfishAttributeRegistry_V1_0_0_RegistryEntries_CS;
typedef struct _RedfishAttributeRegistry_V1_0_0_SupportedSystems_CS RedfishAttributeRegistry_V1_0_0_SupportedSystems_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

typedef struct _RedfishAttributeRegistry_V1_0_0_AttributeValue_CS {
    RedfishCS_char    *ValueDisplayName;    // A user-readable display string
                                           // of the value of the attribute
                                           // in the defined 'Language'.
    RedfishCS_char    *ValueName;          // The value name of the
                                           // attribute.
} RedfishAttributeRegistry_V1_0_0_AttributeValue_CS;

typedef struct _RedfishAttributeRegistry_V1_0_0_Attributes_CS {
    RedfishCS_char                                             *AttributeName;            // The unique name of the
                                                                                          // attribute.
    RedfishCS_Vague                                            *CurrentValue;             // Placeholder of the current
                                                                                          // value of the attribute.
    RedfishCS_Vague                                            *DefaultValue;             // The default current value of
                                                                                          // the attribute.
    RedfishCS_char                                             *DisplayName;              // The user-readable display
                                                                                          // string of the attribute in the
                                                                                          // defined 'Language'.
    RedfishCS_int64                                            *DisplayOrder;             // The numeric value describing
                                                                                          // the ascending order that the
                                                                                          // attribute is displayed
                                                                                          // relative to other attributes.
    RedfishCS_bool                                             *GrayOut;                  // The gray-out state of this
                                                                                          // attribute.
    RedfishCS_char                                             *HelpText;                 // The help text for the
                                                                                          // attribute.
    RedfishCS_bool                                             *Hidden;                   // The hidden state of this
                                                                                          // attribute.
    RedfishCS_bool                                             *Immutable;                // Defines whether this attribute
                                                                                          // is immutable or not.
    RedfishCS_bool                                             *IsSystemUniqueProperty;    // Defines whether this attribute
                                                                                          // is unique for this system and
                                                                                          // should not be replicated.
    RedfishCS_int64                                            *LowerBound;               // The lower limit of the value
                                                                                          // of an attribute of type
                                                                                          // 'Integer'.
    RedfishCS_int64                                            *MaxLength;                // The maximum character length
                                                                                          // of the value of an attribute
                                                                                          // of type 'String'.
    RedfishCS_char                                             *MenuPath;                 // A path that describes the menu
                                                                                          // hierarchy of this attribute.
    RedfishCS_int64                                            *MinLength;                // The minimum character length
                                                                                          // of the value of an attribute
                                                                                          // of type 'String'.
    RedfishCS_bool                                             *ReadOnly;                 // The read-only state of this
                                                                                          // attribute.
    RedfishCS_int64                                            *ScalarIncrement;          // The amount to increment or
                                                                                          // decrement the value of an
                                                                                          // attribute of type 'Integer'
                                                                                          // each time a user requests a
                                                                                          // value change.
    RedfishCS_char                                             *Type;                     // The type of the attribute.
    RedfishCS_int64                                            *UpperBound;               // The upper limit of the value
                                                                                          // of an attribute of type
                                                                                          // 'Integer'.
    RedfishAttributeRegistry_V1_0_0_AttributeValue_Array_CS    *Value;                    // The array containing possible
                                                                                          // values for attributes of type
                                                                                          // 'Enumeration'.
    RedfishCS_char                                             *ValueExpression;          // A regular expression that is
                                                                                          // used to validate the value of
                                                                                          // the attribute. This is only
                                                                                          // applicable to attributes of
                                                                                          // type 'String' or 'Integer'.
    RedfishCS_char                                             *WarningText;              // The warning text for changing
                                                                                          // the attribute.
    RedfishCS_bool                                             *WriteOnly;                // Defines whether this attribute
                                                                                          // is write-only. Such attributes
                                                                                          // revert back to their initial
                                                                                          // value after settings are
                                                                                          // applied.
} RedfishAttributeRegistry_V1_0_0_Attributes_CS;

typedef struct _RedfishAttributeRegistry_V1_0_0_Dependencies_CS {
    RedfishAttributeRegistry_V1_0_0_Dependency_CS    *Dependency;  
    RedfishCS_char                                   *DependencyFor;    // The AttributeName of the
                                                                       // attribute whose change
                                                                       // triggers the evaluation of
                                                                       // this dependency expression.
    RedfishCS_char                                   *Type;            // The type of the dependency
                                                                       // structure.
} RedfishAttributeRegistry_V1_0_0_Dependencies_CS;

typedef struct _RedfishAttributeRegistry_V1_0_0_Dependency_CS {
    RedfishAttributeRegistry_V1_0_0_MapFrom_Array_CS    *MapFrom;          // Array of the map-from
                                                                           // conditions for mapping
                                                                           // dependency.
    RedfishCS_char                                      *MapToAttribute;    // The Name of the attribute that
                                                                           // is affected by this dependency
                                                                           // expression.
    RedfishCS_char                                      *MapToProperty;    // The meta-data property of the
                                                                           // attribute specified in
                                                                           // MapFromAttribute that is used
                                                                           // to evaluate this dependency
                                                                           // expression.
    RedfishCS_Vague                                     *MapToValue;       // The value that MapToProperty
                                                                           // is changed to if the
                                                                           // dependency expression
                                                                           // evaluates to true.
} RedfishAttributeRegistry_V1_0_0_Dependency_CS;

typedef struct _RedfishAttributeRegistry_V1_0_0_MapFrom_CS {
    RedfishCS_char     *MapFromAttribute;    // The attribute that is used to
                                            // evaluate this dependency
                                            // expression.
    RedfishCS_char     *MapFromCondition;    // The condition that is used to
                                            // evaluate this dependency
                                            // expression.
    RedfishCS_char     *MapFromProperty;    // The meta-data property of the
                                            // attribute specified in
                                            // MapFromAttribute that is used
                                            // to evaluate this dependency
                                            // expression.
    RedfishCS_Vague    *MapFromValue;       // The value that the is used
                                            // property specified in
                                            // MapFromProperty that is used
                                            // to evaluate this dependency
                                            // expression.
    RedfishCS_char     *MapTerms;           // The logical term used to
                                            // combine two or more MapFrom
                                            // conditions in this dependency
                                            // expression.
} RedfishAttributeRegistry_V1_0_0_MapFrom_CS;

typedef struct _RedfishAttributeRegistry_V1_0_0_Menus_CS {
    RedfishCS_char     *DisplayName;    // The user-readable display
                                        // string of this menu in the
                                        // defined 'Language'.
    RedfishCS_int64    *DisplayOrder;    // The numeric value describing
                                        // the ascending order in which
                                        // this menu is displayed
                                        // relative to other menus.
    RedfishCS_bool     *GrayOut;        // The gray-out state of this
                                        // menu. A grayed-only menu is
                                        // not accessible in user
                                        // interfaces.
    RedfishCS_char     *MenuName;       // The unique name string of this
                                        // menu.
    RedfishCS_char     *MenuPath;       // A path that describes this
                                        // menu hierarchy relative to
                                        // other menus.
    RedfishCS_bool     *ReadOnly;       // The read-only state of this
                                        // menu.
} RedfishAttributeRegistry_V1_0_0_Menus_CS;

typedef struct _RedfishAttributeRegistry_V1_0_0_RegistryEntries_CS {
    RedfishAttributeRegistry_V1_0_0_Attributes_Array_CS      *Attributes;     // The array containing the
                                                                              // attributes and their possible
                                                                              // values.
    RedfishAttributeRegistry_V1_0_0_Dependencies_Array_CS    *Dependencies;    // The array containing a list of
                                                                              // dependencies of attributes on
                                                                              // this component.
    RedfishAttributeRegistry_V1_0_0_Menus_Array_CS           *Menus;          // The array containing the
                                                                              // attributes menus and their
                                                                              // hierarchy.
} RedfishAttributeRegistry_V1_0_0_RegistryEntries_CS;

typedef struct _RedfishAttributeRegistry_V1_0_0_SupportedSystems_CS {
    RedfishCS_char    *ProductName;    // Firmware version.
    RedfishCS_char    *SystemId;      // The system ID of the system.
} RedfishAttributeRegistry_V1_0_0_SupportedSystems_CS;

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
// An Attribute Registry is a set of key-value pairs which are specific to a
// particular implementation or product, such that creating standardized property
// names would be impractical.  This schema describes the structure of a Registry,
// and also includes mechanisms for building user interfaces (menus) allowing
// consistent navigation of the contents.
//
typedef struct _RedfishAttributeRegistry_V1_0_0_AttributeRegistry_CS {
    RedfishCS_Header                                             Header;
    RedfishCS_char                                               *odata_context;  
    RedfishCS_char                                               *odata_id;       
    RedfishCS_char                                               *odata_type;     
    RedfishCS_char                                               *Description;    
    RedfishCS_char                                               *Id;             
    RedfishCS_char                                               *Language;           // This is the RFC 5646 compliant
                                                                                      // language code for the
                                                                                      // registry.
    RedfishCS_char                                               *Name;           
    RedfishResource_Oem_CS                                       *Oem;                // This is the
                                                                                      // manufacturer/provider specific
                                                                                      // extension moniker used to
                                                                                      // divide the Oem object into
                                                                                      // sections.
    RedfishCS_char                                               *OwningEntity;       // This is the organization or
                                                                                      // company that publishes this
                                                                                      // registry.
    RedfishAttributeRegistry_V1_0_0_RegistryEntries_CS           *RegistryEntries;    // List of all attributes and
                                                                                      // their metadata for this
                                                                                      // component.
    RedfishCS_char                                               *RegistryVersion;    // This is the attribute registry
                                                                                      // version which is used in the
                                                                                      // middle portion of a
                                                                                      // AttributeRegistry.
    RedfishAttributeRegistry_V1_0_0_SupportedSystems_Array_CS    *SupportedSystems;    // Array of systems supported by
                                                                                      // this attribute registry.
} RedfishAttributeRegistry_V1_0_0_AttributeRegistry_CS;

typedef struct _RedfishAttributeRegistry_V1_0_0_Dependencies_Array_CS  {
    RedfishAttributeRegistry_V1_0_0_Dependencies_Array_CS    *Next;
    RedfishAttributeRegistry_V1_0_0_Dependencies_CS    *ArrayValue;
} RedfishAttributeRegistry_V1_0_0_Dependencies_Array_CS;

typedef struct _RedfishAttributeRegistry_V1_0_0_Menus_Array_CS  {
    RedfishAttributeRegistry_V1_0_0_Menus_Array_CS    *Next;
    RedfishAttributeRegistry_V1_0_0_Menus_CS    *ArrayValue;
} RedfishAttributeRegistry_V1_0_0_Menus_Array_CS;

typedef struct _RedfishAttributeRegistry_V1_0_0_Attributes_Array_CS  {
    RedfishAttributeRegistry_V1_0_0_Attributes_Array_CS    *Next;
    RedfishAttributeRegistry_V1_0_0_Attributes_CS    *ArrayValue;
} RedfishAttributeRegistry_V1_0_0_Attributes_Array_CS;

typedef struct _RedfishAttributeRegistry_V1_0_0_MapFrom_Array_CS  {
    RedfishAttributeRegistry_V1_0_0_MapFrom_Array_CS    *Next;
    RedfishAttributeRegistry_V1_0_0_MapFrom_CS    *ArrayValue;
} RedfishAttributeRegistry_V1_0_0_MapFrom_Array_CS;

typedef struct _RedfishAttributeRegistry_V1_0_0_AttributeValue_Array_CS  {
    RedfishAttributeRegistry_V1_0_0_AttributeValue_Array_CS    *Next;
    RedfishAttributeRegistry_V1_0_0_AttributeValue_CS    *ArrayValue;
} RedfishAttributeRegistry_V1_0_0_AttributeValue_Array_CS;

typedef struct _RedfishAttributeRegistry_V1_0_0_SupportedSystems_Array_CS  {
    RedfishAttributeRegistry_V1_0_0_SupportedSystems_Array_CS    *Next;
    RedfishAttributeRegistry_V1_0_0_SupportedSystems_CS    *ArrayValue;
} RedfishAttributeRegistry_V1_0_0_SupportedSystems_Array_CS;

RedfishCS_status
Json_AttributeRegistry_V1_0_0_To_CS (char *JsonRawText, RedfishAttributeRegistry_V1_0_0_AttributeRegistry_CS **ReturnedCS);

RedfishCS_status
CS_To_AttributeRegistry_V1_0_0_JSON (RedfishAttributeRegistry_V1_0_0_AttributeRegistry_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyAttributeRegistry_V1_0_0_CS (RedfishAttributeRegistry_V1_0_0_AttributeRegistry_CS *CSPtr);

RedfishCS_status
DestroyAttributeRegistry_V1_0_0_Json (RedfishCS_char *JsonText);

#endif
