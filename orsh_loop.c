#include <stdlib.h>
#include <stdio.h>
#include "orsh_read_command.c"
#include "orsh_split_command.c"
#include "orsh_execute.c"


void orsh_loop(void)
{
    char *command;
    char **arguments;
    int status;

    do {
        printf("orsh> ");
        command = orsh_read_command();
        arguments = orsh_split_command(command);
        status = orsh_execute(arguments);
        free(command);
        free(arguments);

    } while (status);
}
