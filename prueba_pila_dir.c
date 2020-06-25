#include <stdio.h>
#include <stdlib.h>

#include "pila_dir.h"

int main(int argc, char const *argv[]) {
    
    SDir *s_dir = create_s_dir();

    pushSDir(s_dir, 2);
    pushSDir(s_dir, 4);
    pushSDir(s_dir, 6);

    print_s_dir(s_dir);

    int dir = popSDir(s_dir);

    printf("Elemento sacado de pila: %d\n", dir);

    printf("Pila: \n");
    print_s_dir(s_dir);

    free_s_dir(s_dir);

    return 0;
}
