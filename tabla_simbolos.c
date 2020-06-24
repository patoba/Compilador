#ifndef SYMTAB_H
#define SYMTAB_H
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tabla_simbolos.h"
#include "data.h"

//Agrega un nuevo argumento
void append_arg(ARGS* args, int arg){       
    //Crea un nuevo argumento
    ARG* nuevoArg = (ARG*)malloc(sizeof(ARG));
    nuevoArg -> arg = arg;
    nuevoArg -> next = NULL;

    if(args -> num > 0){
        ARG* argumentoTemp = args -> head;
        //Recorre la lista y añade el argumento
        for(int i=0; i< args->num; i++)
            argumentoTemp = argumentoTemp -> next;
        argumentoTemp -> next = nuevoArg;
    }else //Es el primer argumento
        args->head = nuevoArg;
    //Mueve el apuntador del final al nuevo elemento    
    args->tail = nuevoArg;
    //Aumenta el número de argumentos
    args->num++;
}


//Compara dos listas y devuelve 1 si son iguales, 0 si son diferentes
int compare_args(ARGS *a1, ARGS *a2){
    if(a1->num == a2->num){
        ARG* apL1 = a1->head;
        ARG* apL2 = a2->head;
        
        for(int i=0; i < a1->num; i++){
            if(apL1->arg != apL2->arg)
                return 0;
            else
            {
                apL1 = apL1 -> next;
                apL1 = apL1 -> next;
            }
        }
        return 1;
    }else
        return 0;
    
}




SYM *search_SYM(SYMTAB *T, char *id){
    SYM *simbol=T->head;
    while(simbol!=NULL){
        if (strcmp(simbol->id,id)==0)
            return simbol;
        simbol = simbol->next;
    }
    return NULL;
}

//Agrega al final de la tabla un nuevo simbolo, devuelve 1 cuando se inserta y 0 cuando no
int append_sym(SYMTAB *t,SYM *s){
    //Si la tabla de símbolos está vacía...
    if(t->head == NULL){
        t->head = s;
        t->tail = s;
        t->num++;
        return 1;
    }
    //Verifica que el símbolo no este en la tabla...
    else if(search_SYM(t, s->id) != NULL){
        SYM* simbTemp = t-> head;
        //Recorre la tabla...
        for(int i=0; i < t->num; i++)
            simbTemp = simbTemp -> next;
        simbTemp -> next = s;
        t->tail = s;
        t->num ++;
        return 1;
    }else
        return 0;
} 

// Vacia la tabla
/* void clear_sym_tab(SYMTAB *t){
    
}*/

// Ejecuta un pop sobre la pila de tablas de simbolos y retorna la tabla eliminada
// Checar
SYMTAB *pop_st(SSTACK *s){
    SYMTAB* temp;
    temp = s->top;
    s->top = temp->next;
    return temp;

} 

// Ingresa una tabla a la pila de tablas de simbolos
// Checar
void push_st(SSTACK *s,SYMTAB *st){
    st->next = s->top;
    s->top = st;
} 

//Retorna el apuntador a un tipo ARGS
ARGS *init_args(){
    ARGS* nuevaL;
    nuevaL = (ARGS*)malloc(sizeof(ARGS));
    nuevaL->head = NULL;
    nuevaL->num = 0;
    nuevaL->tail=NULL;
    return nuevaL;
}
// Reserva memoria para la pila
SSTACK *init_sym_tab_stack(){
    SSTACK* nuevaPila = (SSTACK*)malloc(sizeof(SSTACK));
    nuevaPila->tail = NULL;
    nuevaPila->top = NULL;
    return nuevaPila;
} 

// Reserva memoria para una tabla de simbolos vacia
SYMTAB *init_sym_tab(){
    SYMTAB* TablaS = (SYMTAB*)malloc(sizeof(SYMTAB));
    TablaS->head = NULL;
    TablaS->next = NULL;
    TablaS->num = 0;
    TablaS->tail = NULL;
    TablaS->tt_asoc = NULL;
    return TablaS;
} 
// libera memoria para un simbolo vacio
void finish_sym(SYMTAB *T,SYM *s){
    SYM* simbolo = search_SYM(T,s->id);
    free(simbolo);

} 
// Libera memoria para una tabla de simbolos
void finish_sym_tab(SYMTAB *st){
    finish_sym(st,st->head);
    finish_sym(st,st->tail);
    free(st->next);
    free(st);
}

// Reserva memoria para un simbolo vacio
SYM *init_sym(){
    SYM *nuevoSYM = (SYM *)malloc(sizeof(SYM));
    nuevoSYM->next = NULL;
    return nuevoSYM;
}

// Libera la memoria para la pila
void finish_sym_tab_stack(SSTACK *s){
    finish_sym_tab(s->top);
    finish_sym_tab(s->tail);
    free(s);
} 



//Libera memoria para un arg
void finish_arg(ARG *s){
    free(s);
} 

//Libera memoria para una lista ARGS
void finish_args(ARGS *s){
    free(s->head);
    free(s->tail);
    free(s);
}

// Imprime en pantalla la tabla de simbolos
void print_tab_sym(SYMTAB *t){
    SYM *simbol;
    simbol=t->head;
    printf("\n---------------------------------------- ---------------------------------\n");
    printf("         |                   TABLA DE SIMBOLOS                  |\n");
    printf("-------------------------------------------------------------------------\n");
    printf("         |  DIR  |  TIPO  |     ID     |  ARGS  |  NUM  |  VAR  |\n");
    printf("-------------------------------------------------------------------------\n");
    while(simbol!=NULL){
        if(simbol->args == NULL){
            printf("         |%i\t |%i\t  |%s\t       | xxxxxx |%i\t|%s\t|\n",simbol->dir,simbol->tipo,simbol->id,simbol->num,simbol->var);
        }else if(simbol->args != NULL){
            printf("         |%i\t |%i\t  |%s\t     |%i\t  |%i\t|%s\t|\n",simbol->dir,simbol->tipo,simbol->id,simbol->args->num,simbol->num,simbol->var);
        }
        simbol=simbol->next;
    }
    printf("-------------------------------------------------------------------------\n");



} 

/* int getDir(SYMTAB *T , char *id){


}
int getTipo(SYMTAB *T , char *id);
char *getVar(SYMTAB *T , char *id);
ARGS* getArgs(SYMTAB *T , char *id);
int getNumArgs(SYMTAB *T, char *id);*/
// Es posible obtener los atributos a partir de esta función
SYM* getSimbolo(SYMTAB *T, char *id){
    SYM* simbolo = search_SYM(T,id);
    return simbolo;
}

//int search_id_symbol(SYMTAB *T, char *id){

// Se puede sacar de search_SYM, devuelve dir

//}

SYM *search_Prev_SYM(SYMTAB *T, char *id){
    SYM *simbolAux;
    SYM *anterior = NULL;
    int existeTS = 0;
    simbolAux = T->head;
    while(simbolAux!=NULL){
        if (strcmp(simbolAux->id,id)==0){
            existeTS = 1;
            return anterior;
        }
        anterior = simbolAux;
        simbolAux = simbolAux->next;
    }
    return NULL;
}





//Checar
SYM *set_sym(SYM *s, char *id, int dir, int tipo, char *var, ARGS *args, SYMTAB *ts, TYPTAB *tt){
    strcpy(s->id,id);
    s->dir = dir;
    s->tipo = tipo;
    ts->tt_asoc = tt;
    if (var != NULL )
        strcpy(s->var, var);
    else
        strcpy(s->var, "var");
    
    if(args != NULL)
        s->args = args;
    return s;
}

SYMTAB *getTopSym(SSTACK *pilaTS){
    return pilaTS->top;
}
#endif