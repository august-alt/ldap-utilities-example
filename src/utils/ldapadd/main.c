#include <stdio.h>
#include <ldap.h>

const char* LDAP_CONNECTION_STRING = "ldaps://localhost:389";

int main(int argc, char ** argv)
{
    LDAP* ld = NULL;

    int return_code = ldap_initialize(&ld, LDAP_CONNECTION_STRING);
    if (return_code != LDAP_SUCCESS)
    {
        fprintf(stderr, "Unable to connect to ldap service %s\n", ldap_err2string(return_code));
        return return_code;
    }

    return 0;
}
