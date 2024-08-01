#include "philosophers.h"

void    handle_argm_error(char **argv)
{
    if (*argv[1] == '0' || *argv[2] == '0' || *argv[3] == '0' || *argv[4] == '0')
        print_error("Argument value is invalid !");
    printf("correct!\n");
}
