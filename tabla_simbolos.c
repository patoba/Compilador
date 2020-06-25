#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tabla_simbolos.h"
#include "data.h"

void append_arg(ARGS* args, int num){
    ARG *arg = crear_arg(num);
    if(args->num == 0){
        args -> head = arg;
        (*args).tail = arg;
        (*args).num = 1;
        return;
    }
    args->tail->next = arg;
    args->tail = arg;
    (*args).num = (*args).num + 1; 
    return;
}


//Compara dos listas y devuelve 1 si son iguales, 0 si son diferentes
int compare_args(ARGS *a1, ARGS *a2){
    if(a1 == NULL || a2 == NULL && !(a1 == NULL && a2 == NULL))
        return 0;
    if(a1->num != a2->num)
        return 0;
    ARG *temp1 = a1->head;
    ARG *temp2 = a2->head;
    for(int i = 0; i < a1->num; i++){
        if(temp1->arg != temp2->arg)
            return 0;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return 1;
}

SYM *search_SYM(SYMTAB *T, char *id){
    if(T==NULL)
        return NULL;
    SYM *simbol=T->head;
    while(simbol!=NULL){
        if (strcmp(simbol->id, id)==0)
            return simbol;
        simbol = simbol->next;
    }
    return NULL;
}

//Agrega al final de la tabla un nuevo simbolo, devuelve 1 cuando se inserta y 0 cuando no
int append_sym(SYMTAB *t, SYM *s){
    if(t->head == NULL){
        t->head = s;
        t->tail = s;
        t->num = 1;
        return 1;
    }
    t->tail->next = s;
    t->tail = s;
    t->num = t->num + 1;
    return 1;
} 


// Ejecuta un pop sobre la pila de tablas de simbolos y retorna la tabla eliminada
// Checar
SYMTAB *pop_st(SSTACK *s){
    if((*s).top == NULL){
        printf("Se hizo pop de una pila vacia\n");
        return NULL;
    }
    SYMTAB *temp = (*s).top;
    while((*temp).next->next != NULL){
        temp = (*temp).next;
    }
    SYMTAB *ret = (*temp).next;
    (*temp).next = NULL;
    (*s).tail = temp;
    return ret;
} 

// Ingresa una tabla a la pila de tablas de simbolos
// Checar
void push_st(SSTACK *s,SYMTAB *st){
    if(s->top == NULL && s->tail == NULL){
        s->top = st;
        s->tail = st;
        return;
    }
    s->tail->next = st;
    s->tail = st;
} 

ARG *init_arg(){
    ARG *nuevo = (ARG*) malloc(sizeof(ARG));
    return nuevo;
}

ARG *crear_arg(int arg){
    ARG *nuevo = init_arg();
    nuevo->arg = arg;
    return nuevo;
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

void print_args(ARGS *args){
    printf("(%d, ", args->num);
    ARG *temp = args->head;
    while(temp->next != NULL){
        printf("%d, ", temp->arg);
        temp = temp->next;
    }
    printf("%d)", temp->arg);
}

void print_sym(SYM *s){    
    printf("%s\t%d\t%d\t%s\t", s->id, s->tipo, s->dir, s->var);
    if(s->args != NULL){
       print_args(s->args);
    }else
    {
        printf("N/A");
    }
    
    printf("\n");
}

// Imprime en pantalla la tabla de simbolos
void print_tab_sym(SYMTAB *t){
    printf("id\ttipo\tdir\tvar\targs\n");
    if(t==NULL||t->head==NULL)
        return;
    SYM *temp = t->head;
     while(temp->next != NULL){
        print_sym(temp);
        temp = temp->next;
    }
    print_sym(temp);
} 

void print_stack_tab_sym(SSTACK *s){
    if(s->top == NULL && s->tail == NULL)
        return;
    SYMTAB *temp = s->top;
     while(temp->next != NULL){
        print_tab_sym(temp);
        printf("\n");
        temp = temp->next;
    }
    print_tab_sym(temp);
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
SYM *crear_sym(char *id, int dir, int tipo, char *var, ARGS *args){
    SYM *s = init_sym();
    strcpy(s->id, id);
    s->dir = dir;
    s->tipo = tipo;
    if (var != NULL )
        strcpy(s->var, var);
    else
        strcpy(s->var, "var");
    
    if(args != NULL)
        s->args = args;
    return s;
}

SYMTAB *getTopSym(SSTACK *pilaTS){
    return pilaTS->tail;
}

