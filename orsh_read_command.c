#include "orsh_read_command.h"

char *orsh_read_command(void)
{
	char *command = strdup(""), *current_line = NULL;
	size_t n = 0, number_of_characters = 0;

readline:
	free(current_line);
	getline(&current_line, &n, stdin);
	if(ferror(stdin)){
		fprintf(stderr, "Orsh : getline() failed!\n");
		exit(EXIT_FAILURE);
	}
	if(feof(stdin)){
		free(command);
		free(current_line);
		return strdup("exit");
	}
	
	// Remove tailing newline character
	n = strlen(current_line);
	if(current_line[n-1] == '\n') current_line[--n] = '\0';
	number_of_characters += n;

	// Allocate enough memory for "command" and add current_line to the end of it
	command = realloc(command, number_of_characters);
	if(command == NULL){
		fprintf(stderr, "Orsh : memory allocation problem, quit and try again!\n");
		exit(EXIT_FAILURE);
	}
	strcat(command, current_line);

	// if the line ends with a backslash, read a new line
	if(command[n-1] == '\\') {
		command[n-1] = '\0';
		goto readline;
	}

	free(current_line);
	return command;
}
