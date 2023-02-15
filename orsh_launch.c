#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>


int orsh_launch(char **arguments)
{
    pid_t pid, wpid;
    int status;
    pid = fork();

    if(pid == 0)
    {
        // child process , the fork() will return 0
        if(execvp(arguments[0], arguments) == -1)
        {
            perror("ORSH : Error , can't launch this command\n");
        }
        exit(EXIT_FAILURE);
    }
    else if(pid < 0) // error forking
        perror("ORSH : Error , can't launch this command\n");
    else
    {
        do
        {
            wpid = waitpid(pid,&status,WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        
    }
    return 1;
}