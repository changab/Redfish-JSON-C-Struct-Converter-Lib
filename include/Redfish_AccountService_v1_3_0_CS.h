//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishAccountservice_V1_3_0_CSTRUCT_H_
#define _RedfishAccountservice_V1_3_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishAccountService_V1_3_0_RoleMapping_Array_CS RedfishAccountService_V1_3_0_RoleMapping_Array_CS;
typedef struct _RedfishAccountService_V1_3_0_AccountService_CS RedfishAccountService_V1_3_0_AccountService_CS;
typedef struct _RedfishAccountService_V1_3_0_Actions_CS RedfishAccountService_V1_3_0_Actions_CS;
typedef struct _RedfishAccountService_V1_3_0_Authentication_CS RedfishAccountService_V1_3_0_Authentication_CS;
typedef struct _RedfishAccountService_V1_3_0_ExternalAccountProvider_CS RedfishAccountService_V1_3_0_ExternalAccountProvider_CS;
typedef struct _RedfishAccountService_V1_3_0_LDAPSearchSettings_CS RedfishAccountService_V1_3_0_LDAPSearchSettings_CS;
typedef struct _RedfishAccountService_V1_3_0_LDAPService_CS RedfishAccountService_V1_3_0_LDAPService_CS;
typedef struct _RedfishAccountService_V1_3_0_OemActions_CS RedfishAccountService_V1_3_0_OemActions_CS;
typedef struct _RedfishAccountService_V1_3_0_RoleMapping_CS RedfishAccountService_V1_3_0_RoleMapping_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishAccountService_V1_3_0_Actions_CS {
    RedfishAccountService_V1_3_0_OemActions_CS    *Oem;
} RedfishAccountService_V1_3_0_Actions_CS;

//
// Contains the authentication information for the external service.
//
typedef struct _RedfishAccountService_V1_3_0_Authentication_CS {
    RedfishCS_char            *AuthenticationType;    // This property contains the
                                                     // type of authentication used to
                                                     // connect to the external
                                                     // account provider.
    RedfishCS_char            *KerberosKeytab;       // This property is used with a
                                                     // PATCH or PUT to write a base64
                                                     // encoded version of the
                                                     // kerberos keytab for the
                                                     // account.  This property is
                                                     // null on a GET.
    RedfishResource_Oem_CS    *Oem;              
    RedfishCS_char            *Password;             // This property is used with a
                                                     // PATCH or PUT to write the
                                                     // password for the account
                                                     // service.  This property is
                                                     // null on a GET.
    RedfishCS_char            *Token;                // This property is used with a
                                                     // PATCH or PUT to write the
                                                     // token for the account.  This
                                                     // property is null on a GET.
    RedfishCS_char            *Username;             // This property contains the
                                                     // user name for the account
                                                     // service.
} RedfishAccountService_V1_3_0_Authentication_CS;

//
// A remote service that can provide accounts for this manager to utilize for
// authentication.
//
typedef struct _RedfishAccountService_V1_3_0_ExternalAccountProvider_CS {
    RedfishCS_char                                       *AccountProviderType;    // This property contains the
                                                                                 // type of external account
                                                                                 // provider this resource
                                                                                 // references.
    RedfishAccountService_V1_3_0_Authentication_CS       *Authentication;        // This property contains the
                                                                                 // authentication information for
                                                                                 // the external account provider.
    RedfishAccountService_V1_3_0_LDAPService_CS          *LDAPService;           // This property contains
                                                                                 // additional mapping information
                                                                                 // needed to parse a generic LDAP
                                                                                 // service.
    RedfishAccountService_V1_3_0_RoleMapping_Array_CS    *RemoteRoleMapping;     // This property contains a
                                                                                 // collection of the mapping
                                                                                 // rules to convert the external
                                                                                 // account providers account
                                                                                 // information to the local
                                                                                 // Redfish Role.
    RedfishCS_char_Array                                 *ServiceAddresses;      // This property contains the
                                                                                 // addresses of the user account
                                                                                 // providers this resource
                                                                                 // references. The format of this
                                                                                 // field depends on the Type.
    RedfishCS_bool                                       *ServiceEnabled;        // This indicates whether this
                                                                                 // service is enabled.
} RedfishAccountService_V1_3_0_ExternalAccountProvider_CS;

//
// Contains settings for searching a generic LDAP service.
//
typedef struct _RedfishAccountService_V1_3_0_LDAPSearchSettings_CS {
    RedfishCS_char_Array    *BaseDistinguishedNames;    // The base distinguished names
                                                       // to use when searching the LDAP
                                                       // service.
    RedfishCS_char          *GroupNameAttribute;       // The attribute name that
                                                       // contains the name of the
                                                       // Group.
    RedfishCS_char          *GroupsAttribute;          // The attribute name that
                                                       // contains the Groups for a
                                                       // user.
    RedfishCS_char          *UsernameAttribute;        // The attribute name that
                                                       // contains the Username.
} RedfishAccountService_V1_3_0_LDAPSearchSettings_CS;

//
// Contains settings for parsing a generic LDAP service.
//
typedef struct _RedfishAccountService_V1_3_0_LDAPService_CS {
    RedfishResource_Oem_CS                                *Oem;          
    RedfishAccountService_V1_3_0_LDAPSearchSettings_CS    *SearchSettings;    // This property contains the
                                                                             // settings needed to search an
                                                                             // external LDAP service.
} RedfishAccountService_V1_3_0_LDAPService_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishAccountService_V1_3_0_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishAccountService_V1_3_0_OemActions_CS;

//
// Contains mapping rules to convert the external account providers account
// information to the local Redfish Role.
//
typedef struct _RedfishAccountService_V1_3_0_RoleMapping_CS {
    RedfishCS_char            *LocalRole;     // The name of the local role in
                                              // which to map the remote user
                                              // or group.
    RedfishResource_Oem_CS    *Oem;       
    RedfishCS_char            *RemoteGroup;    // This property is the name of
                                              // the remote group (or in the
                                              // case of a Redfish Service,
                                              // remote role) that will be
                                              // mapped to the local role
                                              // referenced by this entity.
    RedfishCS_char            *RemoteUser;    // This property is the name of
                                              // the remote user that will be
                                              // mapped to the local role
                                              // referenced by this entity.
} RedfishAccountService_V1_3_0_RoleMapping_CS;

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
    RedfishResource_Oem_CS    *Oem;            // Oem extension object.
    RedfishCS_char            *State;          // This indicates the known state
                                               // of the resource, such as if it
                                               // is enabled.
} RedfishResource_Status_CS;
#endif

//
// The AccountService schema contains properties for managing user accounts. The
// properties are common to all user accounts, such as password requirements, and
// control features such as account lockout. The schema also contains links to the
// collections of Manager Accounts and Roles.
//
typedef struct _RedfishAccountService_V1_3_0_AccountService_CS {
    RedfishCS_Header                                           Header;
    RedfishCS_char                                             *odata_context;                   
    RedfishCS_char                                             *odata_etag;                      
    RedfishCS_char                                             *odata_id;                        
    RedfishCS_char                                             *odata_type;                      
    RedfishCS_int64                                            *AccountLockoutCounterResetAfter;     // The interval of time in
                                                                                                     // seconds between the last
                                                                                                     // failed login attempt and reset
                                                                                                     // of the lockout threshold
                                                                                                     // counter. This value must be
                                                                                                     // less than or equal to
                                                                                                     // AccountLockoutDuration. Reset
                                                                                                     // sets the counter to zero.
    RedfishCS_int64                                            *AccountLockoutDuration;              // The time in seconds an account
                                                                                                     // is locked out. The value must
                                                                                                     // be greater than or equal to
                                                                                                     // the value of the AccountLockou
                                                                                                     // tCounterResetAfter property.
                                                                                                     // If set to 0, no lockout
                                                                                                     // occurs.
    RedfishCS_int64                                            *AccountLockoutThreshold;             // The number of failed login
                                                                                                     // attempts allowed before a user
                                                                                                     // account is locked for a
                                                                                                     // specified duration. A value of
                                                                                                     // 0 means it is never locked.
    RedfishCS_Link                                             Accounts;                             // A link to a collection of
                                                                                                     // Manager Accounts.
    RedfishAccountService_V1_3_0_Actions_CS                    *Actions;                             // The available actions for this
                                                                                                     // resource.
    RedfishAccountService_V1_3_0_ExternalAccountProvider_CS    *ActiveDirectory;                     // The first ActiveDirectory
                                                                                                     // external account provider this
                                                                                                     // AccountService supports.
    RedfishCS_Link                                             AdditionalExternalAccountProviders;    // The additional external
                                                                                                     // account providers this
                                                                                                     // AccountService is using.
    RedfishCS_int64                                            *AuthFailureLoggingThreshold;         // The number of authorization
                                                                                                     // failures allowed before the
                                                                                                     // failure attempt is logged to
                                                                                                     // the manager log.
    RedfishCS_char                                             *Description;                     
    RedfishCS_char                                             *Id;                              
    RedfishAccountService_V1_3_0_ExternalAccountProvider_CS    *LDAP;                                // The first LDAP external
                                                                                                     // account provider this
                                                                                                     // AccountService supports.
    RedfishCS_char                                             *LocalAccountAuth;                    // Controls when this service
                                                                                                     // will use the accounts defined
                                                                                                     // withing this AccountService as
                                                                                                     // part of authentication.
    RedfishCS_int64                                            *MaxPasswordLength;                   // The maximum password length
                                                                                                     // for this service.
    RedfishCS_int64                                            *MinPasswordLength;                   // The minimum password length
                                                                                                     // for this service.
    RedfishCS_char                                             *Name;                            
    RedfishResource_Oem_CS                                     *Oem;                                 // This is the
                                                                                                     // manufacturer/provider specific
                                                                                                     // extension moniker used to
                                                                                                     // divide the Oem object into
                                                                                                     // sections.
    RedfishCS_Link                                             PrivilegeMap;                         // A reference to the Privilege
                                                                                                     // mapping that defines the
                                                                                                     // privileges needed to perform a
                                                                                                     // requested operation on a URI
                                                                                                     // associated with this service.
    RedfishCS_Link                                             Roles;                                // A link to a collection of
                                                                                                     // Roles.
    RedfishCS_bool                                             *ServiceEnabled;                      // Indicates whether this service
                                                                                                     // is enabled.  If set to false,
                                                                                                     // the AccountService is
                                                                                                     // disabled.  This means no users
                                                                                                     // can be created, deleted or
                                                                                                     // modified.  Any service
                                                                                                     // attempting to access the
                                                                                                     // AccountService resource (for
                                                                                                     // example, the Session Service)
                                                                                                     // will fail.  New sessions
                                                                                                     // cannot be started when the
                                                                                                     // service is disabled. However,
                                                                                                     // established sessions may still
                                                                                                     // continue operating. This does
                                                                                                     // not affect Basic AUTH
                                                                                                     // connections.
    RedfishResource_Status_CS                                  *Status;                          
} RedfishAccountService_V1_3_0_AccountService_CS;

typedef struct _RedfishAccountService_V1_3_0_RoleMapping_Array_CS  {
    RedfishAccountService_V1_3_0_RoleMapping_Array_CS    *Next;
    RedfishAccountService_V1_3_0_RoleMapping_CS    *ArrayValue;
} RedfishAccountService_V1_3_0_RoleMapping_Array_CS;

RedfishCS_status
Json_AccountService_V1_3_0_To_CS (char *JsonRawText, RedfishAccountService_V1_3_0_AccountService_CS **ReturnedCS);

RedfishCS_status
CS_To_AccountService_V1_3_0_JSON (RedfishAccountService_V1_3_0_AccountService_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyAccountService_V1_3_0_CS (RedfishAccountService_V1_3_0_AccountService_CS *CSPtr);

RedfishCS_status
DestroyAccountService_V1_3_0_Json (RedfishCS_char *JsonText);

#endif
