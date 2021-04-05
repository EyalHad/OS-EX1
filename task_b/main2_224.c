#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

void print(const char *txt, pid_t pid)
{
    int i;
    for (i = 0; i < 2; i++)
    {
        printf("%s %d\n", txt, getpid());
        usleep(1000000);
    } 
}

int main() {

    char *args1[2] = {"./main2_1", NULL};
    char *args2[2] = {"./main2_2", NULL};
    char *args3[2] = {"./main2_3", NULL};

    pid_t p1 = fork();
    
    if (p1 == 0) {
        // Child process
        print("\nTask: 1 , PID = ", p1);
        execv(args1[0], args1);
    } else {
        // Back to main process
        
        pid_t p2 = fork();

        if(p2 == 0) {
            // Another child process
            print("\nTask: 2 , PID = ", p2);
            execv(args2[0], args2);

        } else {
            
            pid_t p3 = fork();

            if(p3 == 0) {
                print("\nTask: 3 , PID = ", p3);
                execv(args3[0], args3);
            }
        }
    }
    
    return 0;
}