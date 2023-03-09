#include "orsh_read_command.h"

char *orsh_read_command(void)
{
   char *buffer;
   size_t n;
   getline(&buffer, &n, stdin);
   return buffer;
}
