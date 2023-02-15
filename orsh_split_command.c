#include "orsh_split_command.h"


char ** orsh_split_command(char *command)
{
    int buffSize = ORSH_TOK_BUFSIZE;
    int position = 0;
    char **tokens = (char **) malloc(sizeof(char * ) * buffSize);
    char * token;

    if(tokens == NULL)
    {
        fprintf(stderr,"ORSH: memory allocation problem , exit and try again !\n");
        exit(EXIT_FAILURE);   
    }

    token = strtok(command,ORSH_TOK_DELIM);
    while(token != NULL)
    {
        tokens[position] = token;
        position++;

        if(position >= buffSize)
        {
            buffSize*=2;
            tokens = realloc(tokens,buffSize);
            if(tokens == NULL)
            {
                fprintf(stderr,"ORSH: reallocation problem");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL,ORSH_TOK_DELIM); 

        /* The strtok function maintains the state of the string being tokenized using an internal static pointer.
         This means that subsequent calls to strtok with a NULL pointer 
         as the first argument will continue tokenizing the original string, 
         rather than starting over from the beginning */

         tokens[position] = NULL; // we null terminate the tokens lists 
         return tokens;
    } 
}