#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <syslog.h>

int main()
{
    pid_t pid = fork();//this fork creats a child process that will be daemon

    if (pid == 0)
    {
        //move to root dir. used to not block the file system
        chdir("/");

        //move it to a new session, so the parent maybe will closed
        setsid();

        printf("starting my daemon\n");

        //close I/O
        close(stdout);
        close(stdin);
        close(stderr);

        //open log
        openlog("myDaemon\n", LOG_PID, LOG_DAEMON);
        syslog(LOG_NOTICE, "Daemon started\n");
        usleep(3000000);
        syslog(LOG_NOTICE, "Daemon working...\n");
        usleep(3000000);
        syslog(LOG_NOTICE, "Daemon finished\n");
    }
    else
    {
        printf("Daemon PID %d\n", pid);
    }

    return 0;
}