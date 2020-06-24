#include <stdio.h>
#include "tabla_tipos.h"

int main(int argc, char const *argv[])
{
    TYPTAB *global = init_type_tab_global();
    print_tab_type(global);  
    return 0;
}
