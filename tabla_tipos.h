#include "data.h"

int append_type(TYPTAB *tt,TYP *t); //*Agrega a l final de la tabla un nuevo tipo
void clear_type_tab(TYPTAB *tt); //*Deja vacia la tabla

TYPTAB *pop_tt(TSTACK *s); //*Ejecuta un pop sobre la pila de tablas de tipos
void push_tt(TSTACK *s,TYPTAB *tt); //* Ingresa una tabla a la pila de tablas de tipos

TSTACK *init_type_tab_stack(); //*Reserva memoria para la pila
TYPTAB *init_type_tab_global(); //*Reserva memoria para una tabla de tipos e inserta los tipos nativos
TYP *init_type(); // Reserva memoria para un tipo

TYPTAB *init_tabla_tipo();
TB *init_tipo_base();
TB *crear_estructura(SYMTAB *est);
TB *crear_tipo_basado(int tipo);

TYP  *search_type(TYPTAB *tabTipos, int id);

void finish_type_tab_stack(TSTACK *s); //*Libera la memoria para la pila
void finish_type_tab(TYPTAB *st); //*Libera memoria para una tabla de tipos
void finish_type(TYP *s); //*libera memoria para un tipo

int getTam(TYPTAB *t , int id);//*Retorna el tam de un tipo
TB *getTipoBase(TYPTAB *t , int id); //*retorna el tipo base
char *getNombre( TYPTAB *t , int id ) ; //*retorna el nombre de un tipo tambien lo puede cambiar por un entero

TYPTAB *getTopType(TSTACK *pilaTT);//Retorna el tope de la pila de tipos
TYPTAB *getGlobal(TSTACK *pilaTT);//Retorna la tabla de tipos global

TYP *crear_typ(char *nombre, int tam, TB *tb);

void print_tipo_base(TB *tb);//imprime un tipo base 
void print_type(TYP *t );//Imprime un tipo
void print_tab_type(TYPTAB *t ); //*Imprime en pantalla la tabla de tipos
void print_stack_tab_type(TSTACK *s );//Imprime stack de tablas de simbolos