#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tabla_simbolos.h"
#include "data.h"


//--------------------------------------------------------------------Para los argumentos
/* Agrega un nuevo argumento a la lista de argumentos */
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

/* Inicia una nueva lista de argumentos y retorna el apuntador */
ARGS *init_args(){
    ARGS* nuevaL;
    nuevaL = (ARGS*)malloc(sizeof(ARGS));
    nuevaL->head = NULL;
    nuevaL->num = 0;
    nuevaL->tail=NULL;
    return nuevaL;
}

/* Reserva el espacio en memoria para un nuevo argumento */
ARG *init_arg(){
    ARG *nuevo = (ARG*) malloc(sizeof(ARG));
    return nuevo;
}

/* Crea un nuevo argumento */
ARG *crear_arg(int arg){
    ARG *nuevo = init_arg();
    nuevo->arg = arg;
    return nuevo;
}

/* Compara dos listas de argumentos y devuelve 1 si son iguales, 0 si son diferentes */
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
//---------------------------------------------------------------------------------------

//----------------------------------------------------------------------Para los símbolos
/* Agrega al final de la tabla un nuevo simbolo, devuelve 1 cuando se inserta y 0 cuando no */
int append_sym(SYMTAB *t, SYM *s){
    //Revisa que el id no exista en la tabla
    if(search_SYM(t, s->id) == NULL){
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
    }else
        return 0;
    
} 

/* Reserva memoria para una tabla de simbolos vacia */
SYMTAB *init_sym_tab(){
    SYMTAB* TablaS = (SYMTAB*)malloc(sizeof(SYMTAB));
    TablaS->head = NULL;
    TablaS->next = NULL;
    TablaS->num = 0;
    TablaS->tail = NULL;
    TablaS->tt_asoc = NULL;
    return TablaS;
} 

/* Crea un nuevo símbolo */
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

/* Reserva memoria para un simbolo vacio */
SYM *init_sym(){
    SYM *nuevoSYM = (SYM *)malloc(sizeof(SYM));
    nuevoSYM->next = NULL;
    return nuevoSYM;
}
//---------------------------------------------------------------------------------------

//--------------------------------------------------------------------Imprime en pantalla

/* Imprime una lista de argumentos */
void print_args(ARGS *args){
    //Para prevenir una violación de segmento
    if(args->num != 0){
        //printf("Num args: %d", args->num);
        ARG *temp = args->head;
        printf("(");
        while(temp->next != NULL){
            printf("%d, ", temp->arg);
            temp = temp->next;
        }   
        printf("%d)", temp->arg);
    }else
    {
        printf("La lista de argumentos esta vacía\n");
    }
}

/* Imprime un símbolo */
void print_sym(SYM *s){    
    if(s != NULL){
        printf("%s\t%d\t%d\t%s\t", s->id, s->tipo, s->dir, s->var);
        if(s->args != NULL){
            print_args(s->args);
        }else
        {
            printf("N/A");
        }
    
        printf("\n");
    }else
    {
        printf("El símbolo no se encuentra definido");
    }
    
}

/* Imprime en pantalla la tabla de simbolos */
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

/* Muestra la pila de tabla de símbolos */
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

//---------------------------------------------------------------------------------------

//---------------------------------------------------------------Para encontrar elementos
/* Busca un símbolo en la tabla a través de su id */
 SYM *search_SYM(SYMTAB *T, char *id){
    if(T==NULL)
        return NULL;
    SYM *simbol=T->head;

    while(simbol!=NULL){
        if (strcmp(simbol->id, id) ==0)
            return simbol;
        simbol = simbol->next;
    }
    return NULL;
}
SYM *search_Prev_SYM(SYMTAB *T, char *id){
    SYM *simbolAux;
    SYM *anterior = NULL;
    int existeTS = 0;    

    if(T->num == 0)
        return NULL;
    else if (T->head->id == id)
        return NULL;
    else{
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
}

//---------------------------------------------------------------------------------------

//-----------------------------------------------------Para la pila de tablas de símbolos
/* Ejecuta un pop sobre la pila de tablas de simbolos y retorna la tabla eliminada */
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

/* Ingresa una tabla a la pila de tablas de simbolos */
void push_st(SSTACK *s,SYMTAB *st){
    if(s->top == NULL && s->tail == NULL){
        s->top = st;
        s->tail = st;
        return;
    }
    s->tail->next = st;
    s->tail = st;
} 

/* Reserva memoria para la pila */
SSTACK *init_sym_tab_stack(){
    SSTACK* nuevaPila = (SSTACK*)malloc(sizeof(SSTACK));
    nuevaPila->tail = NULL;
    nuevaPila->top = NULL;
    return nuevaPila;
} 

/* Obtiene el último elemento de la pila */
SYMTAB *getTopSym(SSTACK *pilaTS){
    return pilaTS->tail;
}
//---------------------------------------------------------------------------------------

//------------------------------------------------------------------------Liberar memoria

/* Libera memoria de un arg */
void finish_arg(ARG *s){
    free(s);
} 

/* Libera memoria de una lista ARGS */
void finish_args(ARGS *s){
    int i;
    ARG* temp;
    ARG* temp1;
    if(s->num > 1){
        temp = s->head;
        temp1 = s->head;
        while(temp != NULL){
            free(temp1);
            temp = temp -> next;
            temp1 = temp;
            //i++;
        }
    }else if (s->num == 1){
        free(s->head);
    }
    // Si falla es porque se paso un dato del tipo ARGS* ejemplo; sin llamar a malloc
    free(s);  
}

/* Libera la memoria de un simbolo */
void finish_sym(SYM *s){
    free(s);
}


/* Libera memoria para una tabla de simbolos */
void finish_sym_tab(SYMTAB *st){
    int i;
    SYM* temp;
    SYM* temp1;
    if(st->num > 1){
        temp = st->head;
        temp1 = st->head;
        while(temp != NULL){
            free(temp1);
            temp = temp -> next;
            temp1 = temp;
            //i++;
        }
    }else if (st->num == 1){
        free(st->head);
    }
    // Si falla es porque se paso un dato del tipo SYMTAB* ejemplo; sin llamar a malloc
    free(st);
}

// Libera la memoria para la pila
void finish_sym_tab_stack(SSTACK *st){
    //finish_sym_tab(s->top);
    //finish_sym_tab(s->tail);
    //free(s);
    int i;
    SYMTAB* temp;
    SYMTAB* temp1;
    if(st->tail != st->top){
        temp = st->tail;
        temp1 = st->tail;
        while(temp != NULL){
            free(temp1);
            temp = temp -> next;
            temp1 = temp;
            //i++;
        }
    }else{
        free(st->tail);
    }
    // Si falla es porque se paso un dato del tipo SSTACK* ejemplo; sin llamar a malloc o cuando ya se libero la memoria
    free(st);
}
//---------------------------------------------------------------------------------------

/* int getDir(SYMTAB *T , char *id){


}
int getTipo(SYMTAB *T , char *id);
char *getVar(SYMTAB *T , char *id);
ARGS* getArgs(SYMTAB *T , char *id);
int getNumArgs(SYMTAB *T, char *id);*/
// Es posible obtener los atributos a partir de esta función
/* SYM* getSimbolo(SYMTAB *T, char *id){
    SYM* simbolo = search_SYM(T,id);
    return simbolo;
}*/

//int search_id_symbol(SYMTAB *T, char *id){

// Se puede sacar de search_SYM, devuelve dir

//}