#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>

void (*hello_ariel)();

bool init_libarary(){
    void *hdl = dlopen("./libHello.so",RTLD_LAZY);
    if ( NULL == hdl){return false;}
    return true;
}
int main() {
    if (init_libarary())
    {
        hello_ariel();
    } else {
        printf("Failed to load library\n");
    }
    return 0;
}