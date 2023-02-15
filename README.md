# orsh
Orsh : stands for Oranios shell , which is a simple shell written in C .

## What Oranios means ?
 Oranios means that this shell is from Oran , since Oran is my lovely city , you should visit it :)


### How it works ?

I used the REPL way in this shell : that means Read , Execute , Parse , Loop .

orsh_loop() function will be in a constant loop as it name tells , it will read a string by the function orsh_read_command

orsh_read_command : it will read from the standard input (keyboard stdin ) character by character , until it reaches the EOF or back to the line flags, so it ends the string with null character.

orsh_split_command : this command will uses strtok() function provided by the standard C library , it will tokenize the string into a bunch of tokens by specifiyng the delimiter as a reference to split (that can be a space or back to the line character , check orsh_split_command.h , it contains a macro called ORSH_TOK_DELIM)
#### Remark : 

The strtok function maintains the state of the string being tokenized using an internal static pointer. This means that subsequent calls to strtok with a NULL pointer as the first argument will continue tokenizing the original string, rather than starting over from the beginning.

orsh_launch() : it fork() our C program (shell process) , that means the creation of a new process with a duplicate copy of the  memory pages(data , code) , file discriptors , registers and stack pointer and other common proprities... , but it has a unique proprieties too such as the process id (PID) , and then it calls the exec() syscall via the function execvp() , we pass the first args[0] and the string (the other options to that command) , where we'll use that string as a program name such as ps or pstree ....


#### important remark related to orsh_launch()

there are some commands such as cd that uses chdir() syscall , but it will change the directory of the current process right ? (in the PCB data structure we find a variable that contains the current directory the process is currently working in) not the the parent process which is our shell which is concerned by that . we can't modify the state of the parent process discriptors . the same thing for exit() syscall that send a SIGINT to the process , but the exit command process not the shell .

for this problem , we will define some static commands , which are help , cd and exit, we do that in orsh_execute function

orsh_execute() : 
