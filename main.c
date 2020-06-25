#include <stdio.h>

extern int yyparse();
extern FILE *yyin;

int main(int argc, char const *argv[])
{
    FILE *f;
    if(argc < 2){
        printf("Indique el nombre del archivo a compilar\n");
        return -1;        
    }
    f = fopen(argv[1], "r");
    if(!f){
        printf("El archivo no se puede abrir\n");
        return -1;
    }
    yyin = f;
    yyparse();
    fclose(yyin);
    return 0;
}
