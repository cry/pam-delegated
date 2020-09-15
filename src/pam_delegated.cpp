// This module only handles authentication
#define PAM_SM_AUTH

#include <iostream>
#include <curl/curl.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>

#include "config.hpp"

// todo(cry): implement
int pam_sm_authenticate(pam_handle_t* pamh, int flags, int argc, const char** argv) {
    return 1;
}
