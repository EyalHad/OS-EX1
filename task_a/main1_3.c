#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>


int main() {


    void *handle = dlopen("./libHello.so", RTLD_LAZY);
    if(handle == NULL) {
        printf("Library not found!\n");
        return -1;
    }
    void (*fnc)() = (void *)dlsym(handle, "hello_ariel");
    if(fnc == NULL) {
        printf("Function not found!\n");
        return -1;
    }

    fnc();

    return 0;
}