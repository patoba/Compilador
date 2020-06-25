%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "data.h"
#include "tabla_simbolos.h"
#include "tabla_tipos.h"
#include "cuadruplas.h"
#include "backpatch.h"
#include "tipos.h"
#include "pila_dir.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
void yyerror(char *s);

//funciones acciones EdT
void agregar_sym_var(char *id, char *nombre);
int crear_arreglo(int tipo, int val, int arreglo);

//variables globales
TSTACK *STT;
SSTACK *STS;
int dir;
int typeGBL, baseGBL;
SDir *SDIR;
//vector<int> SDir;
%}

%union {

    struct {
        struct args *lista;
        int num;
    } lista;

    struct {
        int type;
        char dir[50];
    } tipo;

    struct {
        int code_est;
        char dir[50];
        int type;
        int base;
        char des[50];
    } variable;

    struct {
        int base;
    } base;

    struct {
        struct list_index *truelist;
        struct list_index *falselist;
        struct list_index *nexlist;
        struct list_index *prueba;
    } lista_indices;
}

//PALABRAS RESERVADAS
%token ESTRUCTURA INICIO FIN DEF SI ENTONCES SINO MIENTRAS HACER SEGUN ESCRIBIR LEER DEVOLVER TERMINAR CASO PRED

//TIPOS DE DATOS
%token ENT REAL DREAL CAR SIN

//Constantes
%token VERDADERO FALSO

//DEFINIDOS POR NOSOTROS
%token<tipo> NUM
%token<tipo> ID
%token<tipo> CARACTER
%token<tipo> CADENA

//JERARQUIA
%token COMA
%right ASIG
%left O
%left Y
%left IGUAL DIFER
%left MAYOR_QUE MAYOR_IGUAL_QUE MENOR_QUE MENOR_IGUAL_QUE
%left SUMA RESTA
%left MULT DIV MOD
%left NO

//Caracteres especiales
%token PUNTO DOS_PUNTOS
%nonassoc PAR_ABRE PAR_CIERRA
%nonassoc CORCH_ABRE CORCH_CIERRA   
%token PUNTO_Y_COMA

%type<lista> lista_arg lista_param parametros argumentos
%type<tipo> expresion arreglo param_arr arg tipo_arreglo tipo_arg
%type<tipo> tipo_registro declaraciones relacional tipo 
//%type<estructura> dato_est_sim variable_comp
%type<variable> variable
%type<base> base
%type<lista_indices> predeterminado casos relacional_op e_bool sentencia sentencias 

%start programa

%%

programa: { 
            
            STS = init_sym_tab_stack();
            STT = init_type_tab_stack();
            
            TYPTAB *global = init_type_tab_global();
            push_tt(STT, global);

            SYMTAB *primera = init_sym_tab();
            push_st(STS, primera);

            dir = 0;
            SDIR = create_s_dir();
          } declaraciones funciones{
                                    //$$.codigo = $3.codigo;
                                    //print_stack_tab_type(STT);
                                    //printf("aqui");
                                    //printf("%d\n", STT->top.);
                                    //print_stack_tab_sym(STS);
                                    };

declaraciones: tipo{typeGBL = $1.type;} lista_var PUNTO_Y_COMA declaraciones
             | tipo_registro{typeGBL= $1.type;} lista_var PUNTO_Y_COMA declaraciones
             | {};

//creacion del tipo revisar
//getTam mala llamada
//id esta mal
tipo_registro: ESTRUCTURA INICIO{  
                                   push_tt(STT, init_tabla_tipo());
                                   push_st(STS, init_sym_tab());
                                   
                                   pushSDir(SDIR, dir);
                                   dir = 0;
                                   } declaraciones FIN {
                                                        SYMTAB *SymTab = pop_st(STS);
                                                        int tam = tamano_tabla_tipos(SymTab, STT);
                                                        SymTab->tt_asoc = pop_tt(STT);
                                                        

                                                        dir = popSDir(SDIR);
                                                        
                                                        TB *tb = crear_estructura(SymTab); //falla implementacion
                                                        TYP *nuevo = crear_type("struct", tam, tb);
                                                        append_type(getTopType(STT), nuevo);
                                                        $$.type = nuevo->id;
                                                    };

tipo: base{baseGBL = $1.base;} tipo_arreglo{$$.type = $3.type;};

//Definir los tipos en global
base: ENT{$$.base = getId(getGlobal(STT), "ent");}
    | REAL{$$.base = getId(getGlobal(STT), "real");}
    | DREAL{$$.base = getId(getGlobal(STT), "dreal");}
    | CAR{$$.base = getId(getGlobal(STT), "car");}
    | SIN{$$.base = getId(getGlobal(STT), "sin");};

//Poner type, dir de num 
//Poner type de tipo arreglo
//creacion de tipo es posible que este mal
tipo_arreglo: CORCH_ABRE NUM CORCH_CIERRA tipo_arreglo{
                                                        $$.type = crear_arreglo($2.type, atoi($2.dir), $4.type);
                                                      }
            | {$$.type=baseGBL;};


//ID se puede usar asi?
//tabla simbolos debe tener existe
//
lista_var: lista_var COMA ID {  
                                agregar_sym_var($3.dir, "var");
                             }
            | ID {
                    agregar_sym_var($1.dir, "var");
                 };

//ListaRet no existe
//sdir no existe
//cmpRet
funciones: DEF tipo ID{ 
                        if(search_SYM(STS->top, $3.dir) == 0) {
                            push_tt(STT, init_tabla_tipo());
                            push_st(STS, init_sym_tab());
                            pushSDir(SDIR, dir);
                            dir = 0;
                            //listaRET = newListRet();
                        }else{
                            yyerror("Ya existe una funcion declarada con ese identificador");
                        }
                      } PAR_ABRE argumentos{print_stack_tab_sym(STS);
                                            print_stack_tab_type(STT);} PAR_CIERRA INICIO declaraciones sentencias{
                                                                                        pop_st(STS);
                                                                                        pop_tt(STT);
                                                        
                                                                                        // if(cmpRet(lista_retorno, $2.type)){
                                                                                        //     L = nueva_etiqueta();
                                                                                        //     backpatch($10.nextlist, L);
                                                                                        //     gen(L);
                                                                                        //     STS.pop();
                                                                                        //     STT.pop();
                                                                                        // }else{
                                                                                        //     error("...");
                                                                                        // }
                                                                                        } FIN funciones
            | {};

//argumentos tiene num, list
//lista_arg tiene lista, num
argumentos: lista_arg {
                        $$.lista = $1.lista;
                        $$.num = $1.num;
                      }
            | SIN {
                    $$.lista = NULL;
                    $$.num = 0;
                 };

//lista_arg posee lista, num
//arg tiene type
//newList no esta definido
lista_arg: lista_arg COMA arg { 
                                $$.lista = $1.lista;
                                append_arg($$.lista, $3.type);
                                $$.num = $1.num + 1;
                              };
         | arg { 
                $$.lista = init_args();
                append_arg($$.lista, $1.type);
                $$.num = 1;
               };

arg: tipo_arg ID{
                    // if(existe_id_en_tabla_sym(STS->top, $2.dir) == 0){
                    //     SYM s = crear_sym($2.dir, dir, baseGBL, "arg", NULL);
                    //     append_sym(getTopSym(STS), s);
                    //     dir = dir + buscar_en_pila(STT, baseGBL)->tam;
                    //     $$.type = baseGBL;
                    // } else{
                    //     yyerror("Ya existe una variable con ese nombre");
                    // }
                    typeGBL = $1.type;
                    agregar_sym_var($2.dir, "arg");
                };

//esta esta mal
//base tiene pase, param
//tipo.type ????
tipo_arg: base { baseGBL = $1.base; } param_arr { $$.type = $3.type; };

param_arr: CORCH_ABRE CORCH_CIERRA param_arr{
                                                TB *tipo_base = crear_tipo_basado($3.type);
                                                TYP *nuevo = crear_type("array", 0, tipo_base);
                                                append_type(getTopType(STT), nuevo);
                                                $$.type = nuevo->id;
                                            };
         | { $$.type = baseGBL; };


sentencias: sentencias sentencia
            | {};


sentencia:  SI e_bool ENTONCES sentencia FIN{}
          |  SI e_bool ENTONCES
            sentencia SINO sentencia FIN{}
          | MIENTRAS e_bool HACER sentencia FIN{}
          | HACER sentencia MIENTRAS e_bool PUNTO_Y_COMA{}
          | SEGUN PAR_ABRE variable PAR_CIERRA HACER casos predeterminado FIN{
                                                                        
                                                                        }
          | variable ASIG expresion PUNTO_Y_COMA{
                                    } 

          | ESCRIBIR expresion PUNTO_Y_COMA{}
          | LEER variable PUNTO_Y_COMA{}
          | DEVOLVER expresion PUNTO_Y_COMA{}
          | DEVOLVER PUNTO_Y_COMA{}
          | TERMINAR PUNTO_Y_COMA{}
          | INICIO sentencia FIN{};

//casos.nextlist = lista
//casos.prueba = lista
casos: casos CASO NUM DOS_PUNTOS sentencia {}
    |CASO NUM DOS_PUNTOS sentencia {};

//predeterminado.prueba = lista
predeterminado: PRED DOS_PUNTOS sentencia{}
              | {};

//e_bool.truelist = lista
//e_bool.falselist = lista
//e_bool.code = string
//relacional.truelist = lista
//relacional.falselist = lista
e_bool: e_bool O e_bool{
                            }
        |e_bool Y e_bool{
                            }
        |NO e_bool{
                    }
        |relacional_op{
                    }
        |VERDADERO{
                    }
        |FALSO{
                };

//relacional.truelist=nueva_lista_indice(t0)
//relacional.falselist=nueva_lista_indice(t1)
//relacional.code
relacional_op: relacional MAYOR_QUE relacional{ 
                                                }

            | relacional MENOR_QUE relacional{
                                        }

            |relacional MENOR_IGUAL_QUE relacional{
                                        
                                        }

            |relacional MAYOR_IGUAL_QUE relacional{
                                        }

            | relacional DIFER relacional{
                                        }

            |relacional IGUAL relacional{
                                        };

relacional: expresion{
                    };



// EXPRESION.TYPE == ENTERO 
// EXPRESION.DIR == STRING
expresion: expresion SUMA expresion {
                                    }

         | expresion RESTA expresion {
                                      }

         | expresion MULT expresion {
                                    }

         | expresion DIV expresion {
                                    }

         | expresion MOD expresion { 
                                    }

         | PAR_ABRE expresion PAR_CIERRA {  }

         | variable {}

         | NUM { }
         | CADENA { 
                  }

         | CARACTER {
                    };

// VARIABLE.CODE_EST == BOOL
// VARIABLE.DIR = STRING / ENTERO
// VARIABLE.TYPE = ENTERO
// VARIABLE.BASE = ENTERO
// VARIABLE.DES = STRING 

// HAY QUE REVISAR EL ATRIBUTO BASE Y DIR
variable: ID{  
             }variable_comp  { 
                             };

// VARIABLE_COMP.TYPE == ENTERO 
// VARIABLE_COMP.DES == STRING
// VARIABLE_COMP.CODE_EST == BOOL
variable_comp: dato_est_sim { 
                            }

             | arreglo { 
                       }

             | PAR_ABRE parametros PAR_CIERRA { 

                                              };

// DATO_EST_SIM.ESTRUCTURA == BOOL
// DATO_EST_SIM.TYPE == ENTERO 
// DATO_EST_SIM.DES == STRING
// DATO_EST_SIM.TABLA == TABLA

// DE DONDE SALE ID SI ES UNA PRODUCCION VACIA
dato_est_sim: dato_est_sim PUNTO ID {   
                                    }
                                
            | { 
            };

// ARREGLO.TYPE == ENTERO 
// ARREGLO.DIR == STRING
arreglo: CORCH_ABRE expresion CORCH_CIERRA {  
                                }
       | arreglo CORCH_ABRE expresion CORCH_CIERRA {  
                                     };

// PARAMETROS.LISTA = LISTA
// PARAMETROS.NUM = ENTERO
parametros: lista_param {   
                        }
          | { 
            };

// LISTA_PARAM.LISTA == LISTA 
// LISTA_PARAM.NUM == ENTERO
lista_param: lista_param COMA expresion {   
                                        }
           | expresion { 
                       };

%%
void yyerror(char *s){
    printf("%s, linea: %d, token: %s\n",s, yylineno, yytext);
}

void agregar_sym_var(char *id, char *nombre){
    if(search_SYM(getTopSym(STS), id) == NULL){
        SYM *s = crear_sym(id, dir, typeGBL, nombre, NULL);
        append_sym(getTopSym(STS), s);//prueba
        dir = dir + buscar_en_pila(STT, typeGBL)->tam;
    }else{
        char s[80] = "Ya existe una variable llamada ";
        strcat(s, id);
        yyerror(s);
    }
}

int crear_arreglo(int tipo, int val, int arreglo) {
    if(tipo == getId(getGlobal(STT), "ent")){
        if(val > 0){ 
            TB* tipo_base = crear_tipo_basado(arreglo);
            int tam_anterior = buscar_en_pila(STT, arreglo)->tam;
            TYP *nuevo = crear_type("array", val * tam_anterior, tipo_base);
            append_type(getTopType(STT), nuevo);
            return nuevo->id;
        }else{
            yyerror("El indice debe ser mayor a cero");
        }
    }else{
        yyerror("El indice debe ser tipo entero\n");
    }
}