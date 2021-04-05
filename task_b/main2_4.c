#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK_SIZE 10000
char child_stack[STACK_SIZE+1];
    
    
int main1(void *params)
{
    char *args1[2] = {"./main2_1", NULL};
    execv(args1[0], args1);
    printf("main2_1 thread");
    return 0;
}
int main2(void *params)
{
    char *args2[2] = {"./main2_2", NULL};
    execv(args2[0], args2);
    printf("main2_2 thread");
    return 0;
}
int main3(void *params)
{
    char *args3[2] = {"./main2_3", NULL};
    execv(args3[0], args3);
    printf("main2_3 thread");
    return 0;
}

int main(){
    int res1 = clone(main1,child_stack+STACK_SIZE,0,0);
    sleep(1);
    int res2 = clone(main2,child_stack+STACK_SIZE,0,0);
    sleep(2);
    int res3 = clone(main3,child_stack+STACK_SIZE,0,0);
    sleep(3);
    
    return 0;
}