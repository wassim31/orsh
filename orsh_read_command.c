#include "orsh_read_command.h"

char *orsh_read_command(void)
{
   char *buffer;
   size_t n;
   getline(&buffer, &n, stdin);
   if(ferror(stdin)) {
	   fprintf(stderr, "Orsh : getline() failed!\n");
	   exit(EXIT_FAILURE);
   }
   if(feof(stdin)) buffer = strdup("exit");
   return buffer;
}
