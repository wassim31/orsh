#include <stdlib.h>
#include <stdio.h>
#define numberOfBuiltinCommands 3
#include <string.h>
#include <unistd.h>
#include "orsh_launch.c"
int orsh_cd(char **arguments);
int orsh_help(char **arguments);
int orsh_exit(char **arguments);