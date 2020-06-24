#include <stdio.h>
#include <stdlib.h>
#include "cuadruplas.h"

int main(int argc, char **argv) {
    CODE *code = init_code();

    CUAD *quad1 = init_quad();
    CUAD *quad2 = init_quad();
    CUAD *quad3 = init_quad();

    add_data_quad(quad1, "+", "x", "y", "goto L1");
    add_data_quad(quad2, "*", "a", "b", "goto L2");
    add_data_quad(quad3, ">", "e", "p", "goto L4");

    append_quad(code, quad1);
    append_quad(code, quad2);
    append_quad(code, quad3);

    print_code(code);

    return 0;
}