//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishAccountservice_V1_2_0_CSTRUCT_H_
#define _RedfishAccountservice_V1_2_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishAccountService_V1_2_0_AccountService_CS RedfishAccountService_V1_2_0_AccountService_CS;
typedef struct _RedfishAccountService_V1_2_0_AccountService_Actions_CS RedfishAccountService_V1_2_0_AccountService_Actions_CS;
typedef struct _RedfishAccountService_V1_2_0_AccountService_Actions_Oem_CS RedfishAccountService_V1_2_0_AccountService_Actions_Oem_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishAccountService_V1_2_0_AccountService_Actions_CS {
    RedfishAccountService_V1_2_0_AccountService_Actions_Oem_CS    *Oem;    // The available OEM specific
                                                                          // actions for this resource.
} RedfishAccountService_V1_2_0_AccountService_Actions_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishAccountService_V1_2_0_AccountService_Actions_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishAccountService_V1_2_0_AccountService_Actions_Oem_CS;

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

//
// Account Service contains properties common to all user accounts, such as
// password requirements, and control features such as account lockout.  It also
// contains links to the collections of Manager Accounts and Roles.
//
typedef struct _RedfishAccountService_V1_2_0_AccountService_CS {
    RedfishCS_Header                                          Header;
    RedfishCS_char                                            *odata_context;                 
    RedfishCS_char                                            *odata_id;                      
    RedfishCS_char                                            *odata_type;                    
    RedfishCS_int64                                           *AccountLockoutCounterResetAfter;    // The interval of time in
                                                                                                  // seconds since the last failed
                                                                                                  // login attempt at which point
                                                                                                  // the lockout threshold counter
                                                                                                  // for the account is reset to
                                                                                                  // zero. Must be less than or
                                                                                                  // equal to
                                                                                                  // AccountLockoutDuration.
    RedfishCS_int64                                           *AccountLockoutDuration;            // The time in seconds an account
                                                                                                  // is locked after the account
                                                                                                  // lockout threshold is met. Must
                                                                                                  // be >=
                                                                                                  // AccountLockoutResetAfter. If
                                                                                                  // set to 0, no lockout will
                                                                                                  // occur.
    RedfishCS_int64                                           *AccountLockoutThreshold;           // The number of failed login
                                                                                                  // attempts before a user account
                                                                                                  // is locked for a specified
                                                                                                  // duration (0=never locked).
    RedfishCS_Link                                            Accounts;                           // Link to a collection of
                                                                                                  // Manager Accounts.
    RedfishAccountService_V1_2_0_AccountService_Actions_CS    *Actions;                           // The available actions for this
                                                                                                  // resource.
    RedfishCS_int64                                           *AuthFailureLoggingThreshold;       // This is the number of
                                                                                                  // authorization failures that
                                                                                                  // need to occur before the
                                                                                                  // failure attempt is logged to
                                                                                                  // the manager log.
    RedfishCS_char                                            *Description;                   
    RedfishCS_char                                            *Id;                            
    RedfishCS_int64                                           *MaxPasswordLength;                 // This is the maximum password
                                                                                                  // length for this service.
    RedfishCS_int64                                           *MinPasswordLength;                 // This is the minimum password
                                                                                                  // length for this service.
    RedfishCS_char                                            *Name;                          
    RedfishResource_Oem_CS                                    *Oem;                               // This is the
                                                                                                  // manufacturer/provider specific
                                                                                                  // extension moniker used to
                                                                                                  // divide the Oem object into
                                                                                                  // sections.
    RedfishCS_Link                                            PrivilegeMap;                       // A reference to the Privilege
                                                                                                  // mapping defining the
                                                                                                  // privileges needed to perform a
                                                                                                  // requested operation on a URI
                                                                                                  // associated with this service.
    RedfishCS_Link                                            Roles;                              // Link to a collection of Roles.
    RedfishCS_bool                                            *ServiceEnabled;                    // This indicates whether this
                                                                                                  // service is enabled.
    RedfishResource_Status_CS                                 *Status;                        
} RedfishAccountService_V1_2_0_AccountService_CS;

RedfishCS_status
Json_AccountService_V1_2_0_To_CS (char *JsonRawText, RedfishAccountService_V1_2_0_AccountService_CS **ReturnedCS);

RedfishCS_status
CS_To_AccountService_V1_2_0_JSON (RedfishAccountService_V1_2_0_AccountService_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyAccountService_V1_2_0_CS (RedfishAccountService_V1_2_0_AccountService_CS *CSPtr);

RedfishCS_status
DestroyAccountService_V1_2_0_Json (RedfishCS_char *JsonText);

#endif
