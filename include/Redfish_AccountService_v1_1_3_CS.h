//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishAccountservice_V1_1_3_CSTRUCT_H_
#define _RedfishAccountservice_V1_1_3_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishAccountService_V1_1_3_AccountService_CS RedfishAccountService_V1_1_3_AccountService_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

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
typedef struct _RedfishAccountService_V1_1_3_AccountService_CS {
    RedfishCS_Header             Header;
    RedfishCS_char               *odata_context;                 
    RedfishCS_char               *odata_etag;                    
    RedfishCS_char               *odata_id;                      
    RedfishCS_char               *odata_type;                    
    RedfishCS_int64              *AccountLockoutCounterResetAfter;    // The interval of time in
                                                                     // seconds between the last
                                                                     // failed login attempt and reset
                                                                     // of the lockout threshold
                                                                     // counter. This value must be
                                                                     // less than or equal to
                                                                     // AccountLockoutDuration. Reset
                                                                     // sets the counter to zero.
    RedfishCS_int64              *AccountLockoutDuration;            // The time in seconds an account
                                                                     // is locked out. The value must
                                                                     // be greater than or equal to
                                                                     // the value of the AccountLockou
                                                                     // tCounterResetAfter property.
                                                                     // If set to 0, no lockout
                                                                     // occurs.
    RedfishCS_int64              *AccountLockoutThreshold;           // The number of failed login
                                                                     // attempts allowed before a user
                                                                     // account is locked for a
                                                                     // specified duration. A value of
                                                                     // 0 means it is never locked.
    RedfishCS_Link               Accounts;                           // A link to a collection of
                                                                     // Manager Accounts.
    RedfishCS_int64              *AuthFailureLoggingThreshold;       // The number of authorization
                                                                     // failures allowed before the
                                                                     // failure attempt is logged to
                                                                     // the manager log.
    RedfishCS_char               *Description;                   
    RedfishCS_char               *Id;                            
    RedfishCS_int64              *MaxPasswordLength;                 // The maximum password length
                                                                     // for this service.
    RedfishCS_int64              *MinPasswordLength;                 // The minimum password length
                                                                     // for this service.
    RedfishCS_char               *Name;                          
    RedfishResource_Oem_CS       *Oem;                               // This is the
                                                                     // manufacturer/provider specific
                                                                     // extension moniker used to
                                                                     // divide the Oem object into
                                                                     // sections.
    RedfishCS_Link               PrivilegeMap;                       // A reference to the Privilege
                                                                     // mapping that defines the
                                                                     // privileges needed to perform a
                                                                     // requested operation on a URI
                                                                     // associated with this service.
    RedfishCS_Link               Roles;                              // A link to a collection of
                                                                     // Roles.
    RedfishCS_bool               *ServiceEnabled;                    // Indicates whether this service
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
    RedfishResource_Status_CS    *Status;                            // This property describes the
                                                                     // status and health of the
                                                                     // resource and its children.
} RedfishAccountService_V1_1_3_AccountService_CS;

RedfishCS_status
Json_AccountService_V1_1_3_To_CS (char *JsonRawText, RedfishAccountService_V1_1_3_AccountService_CS **ReturnedCS);

RedfishCS_status
CS_To_AccountService_V1_1_3_JSON (RedfishAccountService_V1_1_3_AccountService_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyAccountService_V1_1_3_CS (RedfishAccountService_V1_1_3_AccountService_CS *CSPtr);

RedfishCS_status
DestroyAccountService_V1_1_3_Json (RedfishCS_char *JsonText);

#endif
