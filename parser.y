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
#include "codigo_intermedio.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
void yyerror(char *s);

//funciones acciones EdT
void agregar_sym_var(char *id, char *nombre);
int crear_arreglo(int tipo, int val, int arreglo);
char *entero_a_string(int i);

//variables globales
TSTACK *STT;
SSTACK *STS;
int dir;
int typeGBL, baseGBL;
SDir *SDIR;
CODE *code;
char *IDGBL;
//vector<int> SDir;
%}

%union {

    struct {
        struct args *lista;
        int num;
    } lista;

    struct {
        int type;
        int estructura;
        int des;
        struct sym_tab *tabla;
        int code_est;
    } estructura;

    struct {
        int type;
        char dir[50];
    } tipo;

    struct {
        int code_est;
        char dir[50];
        int type;
        int base;
        int des;
    } variable;

    struct {
        int base;
    } base;

    struct {
        struct list_index *truelist;
        struct list_index *falselist;
        struct list_index *nextlist;
        struct list_index *prueba;
    } lista_indices;
}

//PALABRAS RESERVADAS
%token ESTRUCTURA INICIO FIN DEF SI ENTONCES MIENTRAS HACER SEGUN ESCRIBIR LEER DEVOLVER TERMINAR CASO PRED

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
%type<estructura> dato_est_sim variable_comp
%type<variable> variable
%type<base> base
%type<lista_indices> predeterminado casos relacional_op e_bool sentencia sentencias 

%nonassoc SIT
%nonassoc SINO

%start programa

%%

programa: { 
            
            STS = init_sym_tab_stack();
            STT = init_type_tab_stack();
            code = init_code();
            
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
                      } PAR_ABRE argumentos{//print_stack_tab_sym(STS);
                                            //print_stack_tab_type(STT);
                                            } PAR_CIERRA INICIO declaraciones sentencias{
                                                                                        
                                                                                        pop_st(STS);
                                                                                        pop_tt(STT);
                                                                                        //print_code(code);
                                                                                        ver_codigo_intermedio(code);
                                                        
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


sentencias: sentencias sentencia{
                                    //no se
                                    //char *L = nueva_etiqueta();
                                    //backpatch(code, $1.nextlist, L);
                                    //CUAD *etiqueta = crear_cuadrupla("etiq", "", "", L);
                                    //append_quad(code, etiqueta);

                                    //la de abajo no va
                                    $$.nextlist = $2.nextlist;
                                }
            | sentencia{//$$.nextlist = init_code();
                        $$.nextlist = $1.nextlist;
                        //sentencias.code = sentencia.code
                        };

sentencia:  SI e_bool ENTONCES sentencia %prec SIT FIN{ 
                                                char *L = nueva_etiqueta();
                                                backpatch(code, $2.truelist, L);
                                                $$.nextlist = combinar($2.falselist, $4.nextlist);
                                                CUAD *etiqueta = crear_cuadrupla("etiq", "", "", L);
                                                append_quad(code, etiqueta);
                                            } 
          |  SI e_bool ENTONCES sentencia SINO sentencia FIN{
                                                                char *L1 = nueva_etiqueta();
                                                                char *L2 = nueva_etiqueta();
                                                                backpatch(code, $2.truelist, L1);
                                                                backpatch(code, $2.falselist, L2);
                                                                $$.nextlist = combinar($4.nextlist, $6.nextlist);
                                                                CUAD *etiqueta1 = crear_cuadrupla("etiq", "", "", L1);
                                                                CUAD *gotoo = crear_cuadrupla("goto", "", "", $4.nextlist->head->indice);
                                                                CUAD *etiqueta2 = crear_cuadrupla("etiq", "", "", L2);
                                                                append_quad(code, etiqueta1);
                                                                append_quad(code, gotoo);
                                                                append_quad(code, etiqueta2);
                                                            }

          | MIENTRAS e_bool HACER sentencia FIN{}
          | HACER sentencia MIENTRAS e_bool PUNTO_Y_COMA{}
          | SEGUN PAR_ABRE variable PAR_CIERRA HACER casos predeterminado FIN{
                                                                        
                                                                        }
          | variable ASIG expresion PUNTO_Y_COMA{
                                                    if (es_compatible($1.type, $3.type)){  //corregir
                                                        
                                                        char *dir = reducir($3.dir, $1.type, $3.type, code);
                                                        
                                                        if($1.code_est){
                                                            //char *new_temp = new_temporal();
                                                            char *temp = entero_a_string($1.des);//posible falla segmnet faul
                                                            CUAD *acceder = crear_cuadrupla("[]=", temp, dir, entero_a_string($1.base));
                                                            append_quad(code, acceder);
                                                            //gen($1.base + "[" + $1.des + "]" + "=" + dir);
                                                        }else{
                                                            //gen($1.dir + "=" + dir);
                                                            CUAD *igualar = crear_cuadrupla(":=", dir, "", $1.dir);
                                                            append_quad(code, igualar);
                                                        }
                                                    }else{
                                                        yyerror("No se puede realizar el cast");
                                                    }
                                                } 

          | ESCRIBIR expresion PUNTO_Y_COMA{}
          | LEER variable PUNTO_Y_COMA{}
          | DEVOLVER expresion PUNTO_Y_COMA{}
          | DEVOLVER PUNTO_Y_COMA{}
          | TERMINAR PUNTO_Y_COMA{}
          | INICIO sentencias FIN{ $$.nextlist = $2.nextlist; };

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
//relacional.truelist = lista_indices
//relacional.falselist = lista
e_bool: e_bool O e_bool{
                            char *L = nueva_etiqueta();
                            backpatch(code, $1.falselist, L);
                            $$.truelist = combinar($1.truelist, $3.truelist);
                            $$.falselist = $3.falselist;
                            CUAD *etiqueta = crear_cuadrupla("etiq", "", "", L);
                            append_quad(code, etiqueta);
                       }

        | e_bool Y e_bool {
                            char *L = nueva_etiqueta();
                            backpatch(code, $1.truelist, L);
                            $$.truelist = $3.truelist;
                            $$.falselist = combinar($1.falselist, $3.falselist);
                            CUAD *etiqueta = crear_cuadrupla("etiq", "", "", L);
                            append_quad(code, etiqueta);
                          }

        | NO e_bool {
                        $$.truelist =$2.falselist;
                        $$.falselist = $2.truelist;
                    }

        |relacional_op{
                        $$.truelist = $1.truelist;
                        $$.falselist = $1.falselist;
                    }

        | VERDADERO {
                        INDEX *i0 = init_index();
                        $$.truelist = init_list_index(i0);
                        CUAD *cuad = crear_cuadrupla("goto", "", "", i0->indice);
                        append_quad(code, cuad);
                    }
        | FALSO {
                    INDEX *i0 = init_index();
                    $$.falselist = init_list_index(i0);
                    CUAD *cuad = crear_cuadrupla("goto", "", "", i0->indice);
                    append_quad(code, cuad);
                };

//relacional.truelist=nueva_lista_indice(t0)
//relacional.falselist=nueva_lista_indice(t1)
//relacional.code
relacional_op: relacional MAYOR_QUE relacional{ 
                                                INDEX *i0 = init_index(); 
                                                INDEX *i1 = init_index();
                                                $$.truelist=init_list_index(i0);
                                                $$.falselist=init_list_index(i1);
                                                CUAD *si = crear_cuadrupla(">", $1.dir, $3.dir, i0->indice);
                                                CUAD *gotoo = crear_cuadrupla("goto", "", "", i1->indice);
                                                append_quad(code, si);
                                                append_quad(code, gotoo);
                                              }

            | relacional MENOR_QUE relacional{
                                                INDEX *i0 = init_index(); 
                                                INDEX *i1 = init_index();
                                                $$.truelist=init_list_index(i0);
                                                $$.falselist=init_list_index(i1);
                                                CUAD *si = crear_cuadrupla("<", $1.dir, $3.dir, i0->indice);
                                                CUAD *gotoo = crear_cuadrupla("goto", "", "", i1->indice);
                                                append_quad(code, si);
                                                append_quad(code, gotoo);
                                             }

            | relacional MENOR_IGUAL_QUE relacional{
                                                    INDEX *i0 = init_index(); 
                                                    INDEX *i1 = init_index();
                                                    $$.truelist=init_list_index(i0);
                                                    $$.falselist=init_list_index(i1);
                                                    CUAD *si = crear_cuadrupla("<=", $1.dir, $3.dir, i0->indice);
                                                    CUAD *gotoo = crear_cuadrupla("goto", "", "", i1->indice);
                                                    append_quad(code, si);
                                                    append_quad(code, gotoo);
                                                  }

            | relacional MAYOR_IGUAL_QUE relacional{
                                                    INDEX *i0 = init_index(); 
                                                    INDEX *i1 = init_index();
                                                    $$.truelist=init_list_index(i0);
                                                    $$.falselist=init_list_index(i1);
                                                    CUAD *si = crear_cuadrupla(">=", $1.dir, $3.dir, i0->indice);
                                                    CUAD *gotoo = crear_cuadrupla("goto", "", "", i1->indice);
                                                    append_quad(code, si);
                                                    append_quad(code, gotoo);
                                                  }

            | relacional DIFER relacional{
                                            INDEX *i0 = init_index(); 
                                            INDEX *i1 = init_index();
                                            $$.truelist=init_list_index(i0);
                                            $$.falselist=init_list_index(i1);
                                            CUAD *si = crear_cuadrupla("<>", $1.dir, $3.dir, i0->indice);
                                            CUAD *gotoo = crear_cuadrupla("goto", "", "", i1->indice);
                                            append_quad(code, si);
                                            append_quad(code, gotoo);
                                         }

            | relacional IGUAL relacional{
                                            INDEX *i0 = init_index(); 
                                            INDEX *i1 = init_index();
                                            $$.truelist=init_list_index(i0);
                                            $$.falselist=init_list_index(i1);
                                            CUAD *si = crear_cuadrupla("==", $1.dir, $3.dir, i0->indice);
                                            CUAD *gotoo = crear_cuadrupla("goto", "", "", i1->indice);
                                            append_quad(code, si);
                                            append_quad(code, gotoo);
                                        };

relacional: expresion{
                        $$.type = $1.type;
                        strcpy($$.dir, $1.dir);
                     };

// EXPRESION.TYPE == ENTERO 
// EXPRESION.DIR == STRING
expresion: expresion SUMA expresion {
                                        if(es_compatible($1.type, $3.type)) {
                                            $$.type = min($1.type, $3.type);
                                            strcpy($$.dir, new_temporal());
                                            char *dir1 = ampliar($1.dir, $1.type, $$.type, code);
                                            char *dir2 = ampliar($3.dir, $3.type, $$.type, code);
                                            CUAD *operacion = crear_cuadrupla("+", dir1, dir2, $$.dir);
                                            append_quad(code, operacion);
                                        }
                                        else {
                                            yyerror("No se puede realizar la operación entre diferentes tipos de datos");
                                        }
                                    }

         | expresion RESTA expresion {
                                        if(es_compatible($1.type, $3.type)) {
                                            $$.type = min($1.type, $3.type);
                                            strcpy($$.dir, new_temporal());
                                            char *dir1 = ampliar($1.dir, $1.type, $$.type, code);
                                            char *dir2 = ampliar($3.dir, $3.type, $$.type, code);
                                            CUAD *operacion = crear_cuadrupla("-", dir1, dir2, $$.dir);
                                            append_quad(code, operacion);
                                        }
                                        else {
                                            yyerror("No se puede realizar la operación entre diferentes tipos de datos");
                                        }
                                     }

         | expresion MULT expresion {
                                        if(es_compatible($1.type, $3.type)) {
                                            $$.type = min($1.type, $3.type);
                                            strcpy($$.dir, new_temporal());
                                            char *dir1 = ampliar($1.dir, $1.type, $$.type, code);
                                            char *dir2 = ampliar($3.dir, $3.type, $$.type, code);
                                            CUAD *operacion = crear_cuadrupla("*", dir1, dir2, $$.dir);
                                            append_quad(code, operacion);
                                        }
                                        else {
                                            yyerror("No se puede realizar la operación entre diferentes tipos de datos");
                                        }
                                    }

         | expresion DIV expresion {
                                        if(es_compatible($1.type, $3.type)) {
                                            $$.type = min($1.type, $3.type);
                                            strcpy($$.dir, new_temporal());
                                            char *dir1 = ampliar($1.dir, $1.type, $$.type, code);
                                            char *dir2 = ampliar($3.dir, $3.type, $$.type, code);
                                            CUAD *operacion = crear_cuadrupla("/", dir1, dir2, $$.dir);
                                            append_quad(code, operacion);
                                        }
                                        else {
                                            yyerror("No se puede realizar la operación entre diferentes tipos de datos");
                                        }
                                   }

         | expresion MOD expresion {
                                        if($1.type == 1 && $3.type == 1) {
                                            $$.type = max($1.type, $3.type);
                                            strcpy($$.dir, new_temporal());
                                            char *dir1 = ampliar($1.dir, $1.type, $$.type, code);
                                            char *dir2 = ampliar($3.dir, $3.type, $$.type, code);
                                            CUAD *operacion = crear_cuadrupla("%", dir1, dir2, $$.dir);
                                            append_quad(code, operacion);
                                        }
                                        else {
                                            yyerror("El módulo solo puede operar con números enteros");
                                        }
                                   }

         | PAR_ABRE expresion PAR_CIERRA {  
                                            $$.type = $2.type; 
                                            strcpy($$.dir, $2.dir);
                                         }

         | variable { 
                      $$.type = $1.type; 
                      strcpy($$.dir, $1.dir);
                    }

         | NUM { 
                    $$.type = $1.type; 
                    strcpy($$.dir, $1.dir); 
               }

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
variable: ID {  
                if(buscar_en_pila_sym(STS, $1.dir) != NULL) //posible falle el compilador si la variable no existe
                    IDGBL = $1.dir;
                else 
                    yyerror("El identificador no existe");
             } variable_comp  { 
                                if ($3.code_est) {  //peligroso
                                    strcpy($$.dir, new_temporal());
                                    $$.type = $3.type;   
                                    char *temp = entero_a_string($3.des);//posible falla segmnet fault
                                    CUAD *acceder = crear_cuadrupla("[]", $1.dir, temp, $$.dir);
                                    append_quad(code, acceder);
                                    //gen($$.dir + "=" + $1 + "[" + $3.des + "]");
                                    $$.base = atoi($1.dir); // ??? ENTERO = STRING
                                    $$.code_est = 1;
                                    $$.des = $3.des;
                                }else {
                                    strcpy($$.dir, $1.dir); // ???
                                    $$.type = buscar_en_pila_sym(STS, $1.dir)->tipo;
                                    $$.code_est = 0;
                                }
                             };

// VARIABLE_COMP.TYPE == ENTERO 
// VARIABLE_COMP.CODE_EST == BOOL
variable_comp: dato_est_sim { 
                              $$.type = $1.type; 
                              $$.des = $1.des;
                              $$.code_est = $1.code_est;
                            }

             | arreglo { 
                         $$.type = $1.type;
                         $$.des = atoi($1.dir);
                         $$.code_est = 1;
                       }

             | PAR_ABRE parametros PAR_CIERRA { 

                                              };

// DATO_EST_SIM.ESTRUCTURA == BOOL
// DATO_EST_SIM.TYPE == ENTERO 
// DATO_EST_SIM.DES == STRING
// DATO_EST_SIM.TABLA == TABLA

// DE DONDE SALE ID SI ES UNA PRODUCCION VACIA
dato_est_sim: dato_est_sim PUNTO ID {  //muy PELIGROSO
                                        if ($1.estructura) {
                                            SYM *s = search_SYM($1.tabla, $3.dir);//hay que copiar todos
                                            if(s != NULL) {
                                                $$.des = $1.des + s->dir; //??? tabla_1 $1 o $$
                                                int typeTemp = s->tipo;
                                                TYP *estTemp = search_type($1.tabla->tt_asoc, typeTemp); //aqui truena, por no copiar todo
                                                if(estTemp == NULL)
                                                    estTemp = search_type(getGlobal(STT), typeTemp);   
                                                if (es_estructura(estTemp)) { 
                                                    $$.estructura = 1;
                                                    //dato est sim.tabla.tablaTipos.getTipoBase(typeTemp).tabla
                                                    $$.tabla = search_type($$.tabla->tt_asoc, typeTemp)->tb->tipo.est; 
                                                }else   {
                                                    $$.estructura = 0;
                                                    $$.tabla = NULL;
                                                    $$.type = s->tipo;
                                                }
                                                $$.code_est = 1;
                                            }else            {
                                                yyerror("No existe la variable en la tabla de tipos asociada a la estructura");
                                            }
                                        }else                                     {
                                            yyerror("La variable no pertenece a un tipo estructura");
                                        }  
                                    }
            | { 
                SYM *symTemp = buscar_en_pila_sym(STS, IDGBL); 
                TYP *tipo_asoc = buscar_en_pila(STT, symTemp->tipo);
                if (es_estructura(tipo_asoc)) { 
                    $$.estructura = 1;//int
                    $$.tabla = tipo_asoc->tb->tipo.est; //TablaSimbolos
                    $$.des = 0;   //direccion (entero)
                }
                else {
                    $$.estructura = 0;
                    $$.type = tipo_asoc->id; 
                }
                $$.code_est = 0;
            };

// ARREGLO.TYPE == ENTERO 
// ARREGLO.DIR == STRING
arreglo: CORCH_ABRE expresion CORCH_CIERRA {
                                                TYP *temp_type = buscar_en_pila(STT, buscar_en_pila_sym(STS, IDGBL)->tipo);
                                                
                                                if (es_arreglo(temp_type)) { 
                                                    if($2.type == getId(getGlobal(STT), "ent")) {
                                                        if(atoi($2.dir) > 0){  //Posible falla por $2.dir es string
                                                            int tipo_basado = temp_type->tb->tipo.tipo;
                                                            $$.type = tipo_basado;
                                                            int tam = buscar_en_pila(STT, tipo_basado)->tam;
                                                            strcpy($$.dir, new_temporal());
                                                            char *tamano_en_cadena = entero_a_string(tam);  //posible segment faul
                                                            CUAD *mult =crear_cuadrupla("*", $2.dir, tamano_en_cadena, $$.dir);
                                                            append_quad(code, mult);
                                                        }else{
                                                            yyerror("El indice debe ser positivo");
                                                        }
                                                    } else {
                                                        yyerror("El indice debe ser un entero");
                                                    }
                                                } else {
                                                    yyerror("No se ha declarado el arreglo");
                                                }  
                                            }
       | arreglo CORCH_ABRE expresion CORCH_CIERRA {  
                                                        TYP *temp_type = buscar_en_pila(STT, $1.type);
                                                        //$$.type = temp_type->id;
                                                        if (es_arreglo(temp_type)) {
                                                            if ($3.type == getId(getGlobal(STT), "ent")){
                                                                if(atoi($3.dir) > 0){
                                                                    int typeTemp = temp_type->tb->tipo.tipo;
                                                                    $$.type = typeTemp;
                                                                    int tam = buscar_en_pila(STT, typeTemp)->tam;
                                                                    char *dirTemp = new_temporal();
                                                                    strcpy($$.dir, new_temporal());
                                                                    char *tamano_en_cadena = entero_a_string(tam);  //posible segment fault
                                                                    CUAD *mult =crear_cuadrupla("*", $3.dir, tamano_en_cadena, dirTemp);
                                                                    append_quad(code, mult);
                                                                    CUAD *suma =crear_cuadrupla("+", $1.dir, dirTemp, $$.dir);
                                                                    append_quad(code, suma);
                                                                }else{
                                                                    yyerror("El indice debe ser mayor a cero");
                                                                }
                                                            }
                                                            else {
                                                                yyerror("El índice del arreglo debe ser entero");
                                                            }
                                                        }
                                                        else {
                                                            yyerror("La variable no es un arreglo"); // ???
                                                        }
                                                  };

// PARAMETROS.LISTA = LISTA
// PARAMETROS.NUM = ENTERO
parametros: lista_param {   
                            $$.lista = $1.lista;
                            $$.num = $1.num;
                        }
          | { 
              $$.lista = NULL;
              $$.num = 0;
            };

// LISTA_PARAM.LISTA == LISTA 
// LISTA_PARAM.NUM == ENTERO
lista_param: lista_param COMA expresion {   
                                            $$.lista = $1.lista;   
                                            append_arg($$.lista, $3.type);
                                            $$.num = $1.num + 1;
                                        }
           | expresion { 
                            $$.lista = init_args();
                            append_arg($$.lista, $1.type);
                            $$.num = 1;
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

char *entero_a_string(int i) {
    char *s = (char*)malloc(sizeof(char)*10);
    sprintf(s, "%d", i);
    return s;
}