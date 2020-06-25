#include <stdio.h>
#include <stdlib.h>
#include "tabla_simbolos.h"

//Ya no se permiten duplicados en la tabla!!!
int main(){
    //Crea el símbolo x
    SYM* sim1 = init_sym();
    print_sym(sim1);
    sim1 = crear_sym("x",0,0,"var",NULL);    
    //Crea el símbolo y
    SYM* sim2 = init_sym();
    sim2 = crear_sym("y",1,0,"var",NULL);
    //Crea un símbolo con id repetido
    SYM* sim3 = init_sym();
    sim3 = crear_sym("x",0,0,"var",NULL);
    //Crea la lista de argumentos para una función
    ARGS* listaArg = init_args();
    //Crea otra lista de argumentos
    ARGS* listaAr = init_args();
    //Agrega los argumentos
    append_arg(listaArg,1);
    //print_args(listaArg);
    append_arg(listaArg,2);
    //print_args(listaArg);
    append_arg(listaArg,3);

    //finish_arg(listaArg->tail);
    print_args(listaArg);
    //Crea una nueva función
    SYM* sim4 = init_sym();
    sim4 = crear_sym("x",0,0,"func",listaArg);
    //Crea la tabla de símbolos
    SYMTAB* tablaSimb = init_sym_tab();
    //print_tab_sym(tablaSimb);
    //Agrega los símbolos
    append_sym(tablaSimb,sim1);
    append_sym(tablaSimb,sim2);
    append_sym(tablaSimb,sim3);
    append_sym(tablaSimb,sim4);
    //Muestra la tabla
    //print_tab_sym(tablaSimb);
    //Busca un elemento por su id
    //SYM* simbF = search_SYM(tablaSimb,"x");
    //Imprime el elemento
    //printf("Símbolo encontrado:");
    //print_sym(simbF);


    //Encuentra el anterior símbolo
    //print_tab_sym(tablaSimb);
    SYM *ejem = search_Prev_SYM(tablaSimb,"y");
    //Imprime el elemento
    append_sym(tablaSimb,ejem);
    printf("Símbolo encontrado:");
    //if(ejem)
    print_sym(ejem);

    //finish_sym(tablaSimb,ejem);
    printf("Simbolo elim");
    print_sym(ejem);


    //Elimina la tabla de símbolos
    //finish_sym_tab(tablaSimb);
    //Checa si se eliminaron las referencias de los símbolos
    //print_sym(sim4); //No se eliminan las referencias a los símbolos!!!
    //Comparar 2 listas de argumentos
    //printf("%d",compare_args(listaArg,listaAr));



    //---------------------------------------------Prueba pila tabla de símbolos
    SYMTAB *tabla2 = init_sym_tab();
    append_sym(tabla2,sim3);
    SYMTAB *tabla3 = init_sym_tab();
    append_sym(tabla3,sim4);

    SSTACK *pila = init_sym_tab_stack();
    
    push_st(pila,tablaSimb);
    push_st(pila,tabla2);
    
    pop_st(pila);
    push_st(pila,tabla3);
    //print_stack_tab_sym(pila);
    print_tab_sym(getTopSym(pila));

    finish_sym_tab_stack(pila);
    //print_stack_tab_sym(pila);
    // Liberar memoria
    //ARGS *prueba;
    //print_args(listaArg);
    /* finish_args(listaArg);
    finish_sym_tab(tablaSimb);
    //print_args(listaArg);
    SYMTAB *tabla3 = init_sym_tab();
    append_sym(tabla3,sim4);
    finish_sym_tab(tabla3);
    print_tab_sym(tabla3);
    print_sym(sim4);*/

}