#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <unistd.h>
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

    int res1 = clone(child, child_stack + STACK_SIZE, CLONE_PARENT, 0);
    int res2 = clone(child, child_stack + STACK_SIZE, CLONE_PARENT, 0);
    printf("clone res = %d\n", res1);
    printf("clone res = %d\n", res2);

    print("parent");

    return 0;
}