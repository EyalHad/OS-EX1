#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void print(const char *txt)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%s\n", txt);
        usleep(1000000);
    } 
}

int main()
{
    pid_t pid = fork(); //Create a child process

    if (pid == 0)
    { //Success in making a child process

        pid_t pid = fork(); //Create a grand child process

        if (pid == 0)
        { //Success in making a grand child process
            print("grand child");

            char *args[2] = {"./Subtask2.1", NULL}; //File name and arguments
            execvp(args[0], args);                  //The exec type system calls allow a process to run any program files
        }
        else
        {
            print("child"); //Done with grand child, now we in child process
        }
    }
    else
        print("parent"); //Done with child, now we in parent process

    return 0;
}