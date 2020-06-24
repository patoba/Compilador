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

extern int yylex();
extern int yylineno;
extern char* yytext;
void yyerror(char *s);

//variables globales
TSTACK *STT;
SSTACK *STS;
int dir;
int typeGBL, baseGBL;
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
%type<tipo> expresion arreglo param_arr arg tipo_arreglo 
%type<tipo> tipo_registro declaraciones relacional tipo 
//%type<estructura> dato_est_sim variable_comp
%type<variable> variable
%type<base> base
%type<lista_indices> predeterminado casos relacional_op e_bool sentencia sentencias 

%start programa

%%

programa: { STS = init_sym_tab_stack();
            STT = init_type_tab_stack();
            TYPTAB *global = init_type_tab_global();
            push_tt(STT, global);
            dir = 0;
          } declaraciones funciones{
                                    //$$.codigo = $3.codigo;
                                    print_stack_tab_type(STT);
                                    };

declaraciones: tipo{typeGBL = $1.type;} lista_var PUNTO_Y_COMA declaraciones
             | tipo_registro {typeGBL= $1.type;} lista_var PUNTO_Y_COMA declaraciones
             | {};

//creacion del tipo revisar
//getTam mala llamada
//id esta mal
tipo_registro: ESTRUCTURA INICIO{  
                                   } declaraciones{
                                                    } FIN {
                                                        
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
                                                        if($2.type == getId(getGlobal(STT), "ent")){
                                                            int temp_dir = atoi($2.dir);
                                                            if(temp_dir > 0){ //dir debe ser entero
                                                                TB* tipo_base = crear_tipo_basado($4.type);
                                                                TYP *nuevo = crear_type("array", $2.type, tipo_base);
                                                                append_type(getTopType(STT), nuevo);
                                                                $$.type = nuevo->id;
                                                            }else{
                                                                yyerror("El indice debe ser mayor a cero");
                                                            }
                                                        }else{
                                                            yyerror("El indice debe ser tipo entero\n");
                                                        }
                                                      }
            | {$$.type=baseGBL;};


//ID se puede usar asi?
//tabla simbolos debe tener existe
//
lista_var: lista_var COMA ID {  
                                char *id = $3.dir;
                                if(search_SYM(getTopSym(STS), id) == NULL){
                                    Simbolo s = crear_sym(id, dir, typeGBL, "var", NULL, NULL, NULL);
                                    append_sym(getTopSym(STS), s);//prueba
                                    dir = dir + getTam(getGlobal(STT), typeGBL);
                                }else{
                                    char s[80] = "Ya existe una variable llamada ";
                                    strcat(s, id);
                                    yyerror(s);
                                }
                             }
            | ID {
                    char *id = $3.dir;
                    if(search_SYM(getTopSym(STS), id) == NULL){
                        Simbolo s = crear_sym(id, dir, typeGBL, "var", NULL, NULL, NULL);
                        append_sym(getTopSym(STS), s);//prueba
                        dir = dir + getTam(getGlobal(STT), typeGBL);
                    }else{
                        char s[80] = "Ya existe una variable llamada ";
                        strcat(s, id);
                        yyerror(s);
                    }
                 };

//ListaRet no existe
//sdir no existe
//cmpRet
funciones: DEF tipo ID{
                        }PAR_ABRE argumentos PAR_CIERRA INICIO declaraciones sentencias{
                                                                                        } FIN funciones
            | {};

//argumentos tiene num, list
//lista_arg tiene lista, num
argumentos: lista_arg{}
            |SIN {};

//lista_arg posee lista, num
//arg tiene type
//newList no esta definido
lista_arg: lista_arg COMA arg { };
         | arg{ };

arg: tipo_arg ID{
                };

//esta esta mal
//base tiene pase, param
//tipo.type ????
tipo_arg: base{baseGBL = $1.base;} param_arr{};

param_arr: CORCH_ABRE CORCH_CIERRA param_arr{};
         | {};


sentencias: sentencias sentencia {};


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

