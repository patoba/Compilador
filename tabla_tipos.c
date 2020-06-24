#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "data.h"
#include "tabla_tipos.h"

int append_type(TYPTAB *tt, TYP *t){
    if(tt->num == 0){
        tt -> head = t;
        (*tt).tail = t;
        (*tt).num = 1;
        return 1;
    }
    TYP *temp = (*tt).head;
    while((*temp).next != NULL){
        temp = (*temp).next;
    }
    (*temp).next = t;
    (*tt).num = (*tt).num + 1; 
    tt->tail = t;
    return 1;
}

void clear_type_tab(TYPTAB *tt){
    TYP *temp = (*tt).head;
    while((*temp).next != NULL){
        temp = (*temp).next;
        if((*temp).next == NULL){
            finish_type(temp);
            temp = (*tt).head;
        }
    }
    (*tt).next =NULL;
    (*tt).head = NULL;
    (*tt).tail = NULL;
    (*tt).num = 0;
}


TYPTAB *pop_tt(TSTACK *s){
    if((*s).top == NULL){
        printf("Se hizo pop de una pila vacia\n");
        return NULL;
    }
    TYPTAB *temp = (*s).top;
    while((*temp).next->next != NULL){
        temp = (*temp).next;
    }
    TYPTAB *ret = (*temp).next;
    (*temp).next = NULL;
    (*s).tail = temp;
    return ret;
}

void push_tt(TSTACK *s, TYPTAB *tt){
    if(s->top == NULL && s->tail == NULL){
        s -> top = tt;
        s->tail = tt;
    }
    TYPTAB *temp = (*s).top;
    while((*temp).next != NULL){
        temp = (*temp).next;
    }
    (*temp).next = tt;
    s->tail = tt;
}

TB *init_tipo_base(){
    TB *tipo=(TB *)malloc(sizeof(TB));
    tipo->is_est = -1;
    return tipo;
}

TYP *init_type(){
    TYP *tipo=(TYP *)malloc(sizeof(TYP));
    tipo->id = 0;
    strcpy(tipo->nombre, "");
    tipo->tb = init_tipo_base();
    tipo->tam = 0;
    tipo->next = NULL;
    return tipo;
}

TYP *crear_typ(char *nombre, int tam, TB *tb){
    static int id = -1;
    TYP *tipo = init_type();
    tipo->id = ++id;
    strcpy(tipo->nombre, nombre);
    tipo->tb = tb;
    tipo->tam = tam;
    return tipo;
}

TYPTAB *init_tabla_tipo(){
    TYPTAB *tabla_tipos=(TYPTAB*)malloc(sizeof(TYPTAB));
    tabla_tipos->head = NULL;
    tabla_tipos->tail = NULL;
    tabla_tipos->num = 0;
    tabla_tipos->next = NULL;
}

TSTACK *init_type_tab_stack(){
    TSTACK *pila_tabla_simbolos=(TSTACK *)malloc(sizeof(TSTACK));
    pila_tabla_simbolos->top = NULL;
    pila_tabla_simbolos->tail = NULL;
    return pila_tabla_simbolos;
}

TYP *search_type(TYPTAB *tt, int id){
    if(tt->num == 0)
        return NULL;
    TYP *temp = (*tt).head;
    while((*temp).next != NULL)
        if(temp->id != id)
            return temp;
    return NULL;
}

int getTam(TYPTAB *t , int id){
    return search_type(t, id)->tam;
}

TB *getTipoBase(TYPTAB *t , int id){
    return search_type(t, id)->tb;
}

char *getNombre( TYPTAB *t , int id ){
    return search_type(t, id)->nombre;
}

TYPTAB *getTopType(TSTACK *pila){
    return pila->top;
}

TYPTAB *getGlobal(TSTACK *pila){
    return pila->tail;
}

void finish_type_tab_stack(TSTACK *s){
    finish_type_tab(s->top);
    finish_type_tab(s->tail);
    free(s);
}

void finish_type_tab(TYPTAB *st){
    finish_type(st->head);
    finish_type(st->tail);
    free(st->next);
    free(st);
}

void finish_type(TYP *s){
    free(s->next);
    free(s->tb);
    free(s);
}

TYPTAB *init_type_tab_global(){
    TYPTAB *global = init_tabla_tipo();
    append_type(global, crear_typ("sin", 0, NULL));
    append_type(global, crear_typ("ent", 4, NULL));
    append_type(global, crear_typ("car", 1, NULL));
    append_type(global, crear_typ("real", 4, NULL));
    append_type(global, crear_typ("dreal", 8, NULL));   
    return global;
}

TB *crear_estructura(SYMTAB *est){
    TB *tipobase = init_tipo_base();
    tipobase->is_est=1;
    tipobase->tipo.est=est;
    return tipobase;
}

TB *crear_tipo_basado(int tipo){
    TB *tipobase = init_tipo_base();
    tipobase->is_est=0;
    tipobase->tipo.tipo=tipo;
    return tipobase;
}

//IMPRIMIR

void print_tipo_base(TB *tb){
    if(tb->is_est==1){//estructura
        printf("\n");
    }else if(tb->is_est==0){//tipo simple
        printf("%d\n", tb->tipo.tipo);
    }else{//no tiene tipo base
        printf("\n");
    }
}

void print_type(TYP *t ){
    printf("%d\t%s\t%d\n", t->id, t->nombre, t->tam );
}

void print_tab_type(TYPTAB *tt ){
    if(tt->num == 0)
        return;
    printf("id\tnombre\ttam\n");
    TYP *temp = (*tt).head;
    while((*temp).next != NULL){
        print_type(temp);
        temp = (*temp).next;
    }
        
}

void print_stack_tab_type(TSTACK *s ){
    if(s->top == NULL && s->tail == NULL)
        return;
    TYPTAB *temp = (*s).top;
    while((*temp).next != NULL){
        print_tab_type(temp);
        temp = (*temp).next;
    }
}

