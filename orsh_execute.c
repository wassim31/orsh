#include "orsh_execute.h"

char *builtin_str[] = {
  "cd",
  "help",
  "exit"
};

int (*builtin_func[]) (char **) = {
  &orsh_cd,
  &orsh_help,
  &orsh_exit
};



int orsh_cd(char **arguments)
{
    if(arguments[1] == NULL)
    {
        fprintf(stderr,"ORSH: cd expect a specific destination\n");
    }
    if (chdir(arguments[1]) != 0) {
      perror("ORSH : Error\n");
    }
    return 1;
}

int orsh_help(char **args)
{
  int i;
  printf("Boussebha Wassim's Shell called ORSH : Oranios shell , a shell from Oran :)\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < numberOfBuiltinCommands ; i++) {
    printf("  %s\n", builtin_str[i]);
  }

  printf("Use the man command for information on other programs.\n");
  return 1;
}

int orsh_exit(char **args)
{
  return 0;
}

int orsh_execute(char **args)
{
  int i;

  if (args == NULL || args[0] == NULL) {
    // An empty command was entered.
    return 1;
  }

  for (i = 0; i < numberOfBuiltinCommands ; i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  return orsh_launch(args);
}
