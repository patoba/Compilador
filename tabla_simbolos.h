/*Fecha: 22/mayo/2020
*Autor: Adrián Ulises Mercado Martı́nez
*Descripción: Se definen las funciones para manipular una tabla de simbolos
*/


#include "data.h"

#pragma once

void append_arg(ARGS* args, int arg);//Agrega un argumento al final
int compare_args(ARGS *a1, ARGS *a2);//Compara dos listas y devuelve 1 si son iguales, 0 si son diferentes
int append_sym(SYMTAB *t,SYM *s) ; //Agrega al final de la tabla un nuevo simbolo
//void clear_sym_tab(SYMTAB *t) ; // Deja vacia la tabla

SYMTAB *pop_st(SSTACK *s) ; // Ejecuta un pop sobre la pila de tablas de simbolos
void push_st(SSTACK *s,SYMTAB *st) ; // Ingresa una tabla a la pila de tablas de simbolos

ARGS *init_args(); // Retorna el apuntador a un tipo ARGS
ARG *init_arg(int dato); //Reserva memoria para un tipo ARG y retrona el apuntador
SSTACK *init_sym_tab_stack(); // Reserva memoria para la pila
SYMTAB *init_sym_tab(); // Reserva memoria para una tabla de simbolos vacia
SYM *init_sym(); // Reserva memoria para un simbolo vacio

void finish_sym_tab_stack(SSTACK *s); // Libera la memoria para la pila
void finish_sym_tab(SYMTAB *st); // Libera memoria para una tabla de simbolos
void finish_sym(SYMTAB *T,SYM *s); // libera memoria para un simbolo vacio
void finish_arg(ARG *s); //libera memoria para un arg
void finish_args(ARGS *s);// libera memoria para una lista ARGS

void print_tab_sym(SYMTAB *t); // Imprime en pantalla la tabla de simbolos

int existe_id_en_tabla_sym(SYMTAB* tabla_sim, char* nombre);

/*int getDir(SYMTAB *T , char *id);
int getTipo(SYMTAB *T , char *id);
char *getVar(SYMTAB *T , char *id);
ARGS* getArgs(SYMTAB *T , char *id);
int getNumArgs(SYMTAB *T, char *id);*/

//int search_id_symbol(SYMTAB *T, char *id);
SYM *search_Prev_SYM(SYMTAB *T, char *id);
SYM *search_SYM(SYMTAB *T, char *id);
SYM *crear_sym(char *id, int dir, int tipo, char *var, ARGS *args);
SYMTAB *getTopSym(SSTACK *pilaTS);