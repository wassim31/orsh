#include "orsh_read_command.h"

char *orsh_read_command(void)
{
    int buffSize = orsh_command_bufferSize;
    int position = 0;
    char* buffer = (char *) malloc(sizeof(char) * buffSize);
    int character;

    if(buffer == NULL)
    {
        fprintf(stderr,"Orsh : memory allocation problem, quit and try again !\n");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        character = getchar();
        if(character == EOF || character == '\n')
        {
            buffer[position] = '\0'; // put the last character of the string to null to indicate the end of the string
            return buffer;
        }
        else
        {
            buffer[position] = character;
        }
        position++;

        // in case the user exceded the maximum buffer size we allocated , we reallocate again 
        if(position >= buffSize)
        {
            buffSize*=2; // we double the size of the buffer
            buffer = realloc(buffer,buffSize); 
            if(buffer == NULL)
            {
                fprintf(stderr,"Orsh : Reallocation error , quit and try again!\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}