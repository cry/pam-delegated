#include <iostream>

// This module only handles authentication
#define PAM_SM_AUTH

#include <security/pam_modules.h>
#include <curl/curl.h>

// todo(cry): implement
int pam_sm_authenticate(pam_handle_t* pamh, int flags, int argc, const char** argv) {
    return 1;
}
