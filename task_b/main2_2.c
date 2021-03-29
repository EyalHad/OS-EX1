#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10000
#define CYCLES 10
char child_stack[STACK_SIZE + 1];

void print(const char *txt)
{

    int i;
    for (i = 0; i < CYCLES; i++)
    {
        printf("Hello from %s\n", txt);
        usleep(1000000);
    }
}

int child(void *params)
{
    print("child thread");
}

int main()
{

    int res = clone(child, child_stack + STACK_SIZE, CLONE_PARENT, 0);
    printf("clone res = %d\n", res);

    print("parent");

    return 0;
}