#include "data.h"

//--------------------------------------------------------------------Para los argumentos

void append_arg(ARGS* args, int arg);       // Agrega un argumento al final
int compare_args(ARGS *a1, ARGS *a2);       // Compara dos listas y devuelve 1 si son iguales, 0 si son diferentes
ARGS *init_args();                          // Retorna el apuntador a un tipo ARGS
ARG *init_arg();                            // Reserva memoria para un tipo ARG y retorna el apuntador
ARG *crear_arg(int dato);                   // Crea un argumento a partir del dato

//---------------------------------------------------------------------------------------

//----------------------------------------------------------------------Para los símbolos

int append_sym(SYMTAB *t,SYM *s) ;          //Agrega al final de la tabla un nuevo simbolo
SYM *init_sym();                            // Reserva memoria para un simbolo vacio
SYM *crear_sym(char *id, int dir, int tipo, char *var, ARGS *args);     //Crea un nuevo símbolo a partir de los datos
SYMTAB *init_sym_tab();                     // Reserva memoria para una tabla de simbolos vacia

//---------------------------------------------------------------------------------------

//-----------------------------------------------------Para la pila de tablas de símbolos

SSTACK *init_sym_tab_stack();               // Reserva memoria para la pila
SYMTAB *pop_st(SSTACK *s) ;                 // Ejecuta un pop sobre la pila de tablas de simbolos
void push_st(SSTACK *s,SYMTAB *st) ;        // Ingresa una tabla a la pila de tablas de simbolos
SYMTAB *getTopSym(SSTACK *pilaTS);          // Obtiene el último elemento de la pila

//---------------------------------------------------------------------------------------

//-----------------------------------------------------------------------Liberar memoria

void finish_sym_tab_stack(SSTACK *s);       // Libera la memoria para la pila
void finish_sym_tab(SYMTAB *st);            // Libera memoria para una tabla de simbolos
void finish_sym(SYM *s);          // Libera memoria para un simbolo vacio
void finish_arg(ARG *s);                    // Libera memoria para un arg
void finish_args(ARGS *s);                  // Libera memoria para una lista ARGS

//--------------------------------------------------------------------------------------

//-------------------------------------------------------------------Imprime en pantalla

void print_tab_sym(SYMTAB *t);              // Imprime en pantalla la tabla de simbolos
void print_args(ARGS *args);                // Imprime una lista de argumentos
void print_sym(SYM *s);                     // Imprime un símbolo
void print_stack_tab_sym(SSTACK *s);        // Imprime una pila de tablas de símbolos

//--------------------------------------------------------------------------------------

//--------------------------------------------------------------Para encontrar elementos

//int existe_id_en_tabla_sym(SYMTAB* tabla_sim, char* nombre);
SYM *search_Prev_SYM(SYMTAB *T, char *id);
SYM *search_SYM(SYMTAB *T, char *id);

//--------------------------------------------------------------------------------------




/*int getDir(SYMTAB *T , char *id);
int getTipo(SYMTAB *T , char *id);
char *getVar(SYMTAB *T , char *id);
ARGS* getArgs(SYMTAB *T , char *id);
int getNumArgs(SYMTAB *T, char *id);*/

//int search_id_symbol(SYMTAB *T, char *id);

