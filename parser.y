%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <bits/stdc++.h>

#include "tabla_simbolos.h"
#include "tabla_tipos.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
void error(char *s);

string codigo = "";
void gen(string);

//variables globales
PilaTablaSimbolos STS;
PilaTablaTipos STT;
int dir;
int typeGBL;
vector<int> SDir;


//nulls
TablaSimbolos null_TS;

//salida
string codigo_intermedio;
%}

%union {

    struct {
        vector<int> lista;
        int num;
    }lista;

    struct {
        int type;
        string dir;
    }tipo;

    struct {
        int type;
        bool estructura;
        string des;
        Tabla tabla;
        bool code_est;
    }estructura;

    struct {
        bool code_est;
        string dir;
        int type;
        int base;
        string des;
    } variable;

    struct {
        int base;
    } base;

    struct {
        vector<string> truelist;
        vector<string> falselist;
    } lista_rel;

    struct {
        vector<string> nexlist;
        vector<string> prueba;
    } lista_indices;

    struct {
        vector<string> truelist;
        vector<string> falselist;
        vector<string> nexlist;
    } sentencia;
    
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
%type<estructura> dato_est_sim variable_comp
%type<variable> variable
%type<base> base
%type<lista_rel> relacional_op e_bool
%type<lista_indices> predeterminado casos
%type<sentencia> sentencia sentencias funciones

%start programa

%%

programa: {
            STS.push(PilaTablaSimbolos());
            TablaTipos global;
            global.agregar(Tipo(-1, "sin", 0, -1, null_TS));
            global.agregar(Tipo(0, "ent", 4, -1, null_TS));
            global.agregar(Tipo(1, "car", 1, -1, null_TS));
            global.agregar(Tipo(2, "real", 4, -1, null_TS));
            global.agregar(Tipo(3, "dreal", 8, -1, null_TS));
            STT.push(global);
            dir = 0;
            }
            declaraciones funciones{
            //$$.codigo = $3.codigo;
            };

declaraciones: tipo{typeGBL = $1.type;} lista_var PUNTO_Y_COMA declaraciones
             | tipo_registro {typeGBL= $1.type;} lista_var PUNTO_Y_COMA declaraciones
             | {};

//creacion del tipo revisar
//getTam mala llamada
//id esta mal
tipo_registro: ESTRUCTURA INICIO{  STS.push(PilaTablaSimbolos());
                                   STT.push(PilaTablaTipos());
                                   SDir.push_back(dir);
                                   dir = 0;
                                   } declaraciones{TablaSimbolos SymTab = STS.pop();
                                                    //SymTab.tt = STT.pop();
                                                    //int tam = SymTab.get_tamano();

                                                    dir = SDir.back();
                                                    SDir.pop_back();
                                                    
                                                    int id = STT.nuevo_indice();
                                                    Tipo nuevo(id, "struct", tam, -1, SymTab);
                                                    STT.get_cima().agregar(nuevo);
                                                    } FIN {
                                                        $$.type = id;
                                                    };

tipo: base{baseGBL = $1.base} tipo_arreglo{$$.type = $3.type};

//Definir los tipos en global
base: ENT{$$.base = STT.get_global().get_id("ent");}
    | REAL{$$.base = STT.get_global().get_id("real");}
    | DREAL{$$.base = STT.get_global().get_id("dreal");}
    | CAR{$$.base = STT.get_global().get_id("car");}
    | SIN{$$.base = STT.get_global().get_id("sin");};

//Poner type, dir de num 
//Poner type de tipo arreglo
//creacion de tipo es posible que este mal
tipo_arreglo: CORCH_ABRE NUM CORCH_CIERRA{if($2.type != STT.get_global().get_id("ent")){
                                        error("El indice debe ser tipo entero");
                                    }} tipo_arreglo{
                                                    if($2.dir > 0){ //dir debe ser entero
                                                        int id = STT.nuevo_indice();
                                                        Tipo nuevo(id, "array", $2.dir, $2.tipo);
                                                        STT.get_cima().agregar(nuevo);
                                                        $$.type = id;
                                                    }else{
                                                        error("El indice debe ser mayor a cero");
                                                    }}
            | {$$.type=baseGBL};


//ID se puede usar asi?
//tabla simbolos debe tener existe
//
lista_var: lista_var COMA ID {if(STS.get_cima().existe($3)){
                            Simbolo s()($3, typeGBL, dir, "var", null, null );
                            STS.get_cima().agregar(s);
                            dir = dir + STT.get_cima().get_tamano(typeGBL);
                        }else{
                                error("La variable no ha sido declarada");
                        }
                        }
            | ID {if(STS.get_cima().existe($1)) {
                 Simbolo s()($1, typeGBL, dir, "var", null, null );
                 STS.get_cima().agregar(s);
                 dir = dir + STT.get_cima().get_tamano(typeGBL);
            }else{
                error("El id no existe");
            }
            };

//ListaRet no existe
//sdir no existe
//cmpRet
funciones: DEF tipo ID{if(!STS.get_global().existe($3)){
                            STS.push(PilaTablaSimbolos());
                            STT.push(PilaTablaTipos());
                            SDir.push_back(dir);
                            dir = 0;
                            listaRET = newListRet();
                        }else{
                            error("Ya existe una funcion declarada con ese identificador");
                        }
                        }PAR_ABRE argumentos PAR_CIERRA INICIO declaraciones sentencias{if(cmpRet(lista_retorno, $2.type)){
                                                                                            L = nueva_etiqueta();
                                                                                            backpatch($10.nextlist, L);
                                                                                            gen(L);
                                                                                            STS.pop();
                                                                                            STT.pop();
                                                                                        }else{
                                                                                            error("...");
                                                                                        }
                                                                                        } FIN funciones
            | {};

//argumentos tiene num, list
//lista_arg tiene lista, num
argumentos: lista_arg{$$.lista = $1.lista
                      $$.num = $1.num}
            |SIN {$$.lista = NULO
                  $$.num = 0};

//lista_arg posee lista, num
//arg tiene type
//newList no esta definido
lista_arg: lista_arg COMA arg { $$.lista = $1.lista
                                $$.lista.push_back($3.type)
                                $$.num = $1.num + 1};
         | arg{ $$.lista = newList()
                $$.lista.push_back($1.type)
                $$.num = 1};

arg: tipo_arg ID{if(!STS.get_cima().existe(id)){
                    STS.get_cima().agregar(id, tipo.type, dir, "arg", NULO, NULO);
                    dir = dir + STT.get_cima().get_tamano(tipo.type);
                    $$.type = tipo.type;
                }else{
                    error("Ya existe una variable con ese nombre");
                }
                };

//esta esta mal
//base tiene pase, param
//tipo.type ????
tipo_arg: base{baseGBL = $1.base;} param_arr{tipo.type = $3.base;};

param_arr: CORCH_ABRE CORCH_CIERRA param_arr{Tipo nuevo("array"), 0, param_arr1.tipo);
                                            param_arr.type = STT.get_cima().insert(nuevo);};
         | {$$.type = baseGBL};


sentencias: sentencias sentencia {string L = nueva_etiqueta();
                                backpatch($1.nextlist, L);
                                gen(L);};


sentencia:  SI e_bool ENTONCES sentencia FIN{string L = nueva_etiqueta();
                                            backpatch($2.truelist, L)
                                            $$.nextlist = combinar($2.falselist, $4.nextlist);
                                            gen(L);}
          |  SI e_bool ENTONCES
            sentencia SINO sentencia FIN{string L1 = nueva_etiqueta();
                                         string L2 = nueva_etiqueta();
                                        backpatch($2.truelist, L1);
                                        backpatch($2.falselist, L2);
                                        $$.nextlist = combinar($4.nextlist, $6.nextlist);
                                        gen(L1);
                                        gen("goto " + $4.nextlist[0]);
                                        gen(L2);}
          | MIENTRAS e_bool HACER sentencia FIN{string L1 = nueva_etiqueta();
                                                string L2 = nueva_etiqueta();
                                                backpatch($4.nextlist, L1);
                                                backpatch($2.truelist, L2);
                                                $$.nextlist = $2.falselist;
                                                gen(L1);
                                                gen(L2);
                                                gen("goto " + $4.nextlist[0]);}
          | HACER sentencia MIENTRAS e_bool PUNTO_Y_COMA{string L = nueva_etiqueta();
                                                        gen(L);
                                                        batckbatch($2.nextlist, L);}
          | SEGUN PAR_ABRE variable PAR_CIERRA HACER casos predeterminado FIN{
                                                                        string L1 = nueva_etiqueta();
                                                                        lista prueba = combinar($6.prueba, $7.prueba);
                                                                        backpatch($6.nextlist, L2);
                                                                        sustituir(”??”, $3.dir, prueba);
                                                                        }
          | variable ASIG expresion PUNTO_Y_COMA{dir = reducir($3.dir, $3.type, $1.type);
                                    if($1.code_est){
                                        gen($1.base + "[" + $1.des + "]" + "=" + dir);
                                    }else{
                                        gen($1.dir + "=" + dir);
                                    }} 

          | ESCRIBIR expresion PUNTO_Y_COMA{gen("write " + $2.dir);}
          | LEER variable PUNTO_Y_COMA{gen("read" + $2.dir);}
          | DEVOLVER expresion PUNTO_Y_COMA{gen("return" + $2.dir);}
          | DEVOLVER PUNTO_Y_COMA{gen("return"); }
          | TERMINAR PUNTO_Y_COMA{index = nuevo_indice();
                                    $$.nextlist = nueva_lista_indice(index);
                                    gen("goto" + index);}
          | INICIO sentencia FIN{$$.nextlist = $2.nextlist};

//casos.nextlist = lista
//casos.prueba = lista
casos: casos CASO NUM DOS_PUNTOS sentencia {$$.nextlist = combinar($$.nextlist, $5.nextlist);
                                            string L = nueva_etiqueta();
                                            gen(L);
                                            $$.prueba = $1.prueba;
                                            $$.prueba.append("if ?? == " + to_string($3.dir) + " goto " + L );}
    |CASO NUM DOS_PUNTOS sentencia {$$.prueba = nuevo_codigo();
                        string L = nueva_etiqueta();
                        gen(L);
                        $$.prueba.append("if ?? == " + to_string(num.dir) + " goto " + L);
                        $$.nextlist = $4.nextlist;};

//predeterminado.prueba = lista
predeterminado: PRED DOS_PUNTOS sentencia{$$.prueba = nuevo_codigo();
                                            string L = nueva_etiqueta();
                                            gen(L);
                                            $$.prueba.append("goto " + L );}
              | {$$.prueba = NULL;};

//e_bool.truelist = lista
//e_bool.falselist = lista
//e_bool.code = string
//relacional.truelist = lista
//relacional.falselist = lista
e_bool: e_bool O e_bool{string L = nueva_etiqueta();
                            backpatch($1.falselist, L);
                            $$.truelist = combinar($1.truelist, $3.truelist);
                            $$.falselist = $3.falselist;
                            gen(L);
                            }
        |e_bool Y e_bool{string L = nueva_etiqueta();
                            backpatch($1.truelist, L);
                            $$.truelist = $3.truelist;
                            $$.falselist = combinar($1.falselist, $3.falselist);
                            gen(L);
                            }
        |NO e_bool{$$.truelist =$2.falselist;
                    $$.falselist = $2.truelist;
                    }
        |relacional_op{$$.truelist = $1.truelist;
                    $$.falselist = $1.falselist;
                    }
        |VERDADERO{t0 = nuevo_indice();
                    $$.truelist = nueva_lista_indice(t0);
                    gen("goto " + t0 );
                    }
        |FALSO{t0 = nuevo_indice();
                $$.falselist = nueva_lista_indice(t0);
                gen("goto " + t0 );
                };

//relacional.truelist=nueva_lista_indice(t0)
//relacional.falselist=nueva_lista_indice(t1)
//relacional.code
relacional_op: relacional MAYOR_QUE relacional{ t0 = nuevo_indice(); 
                                                t1 = nuevo_indice();
                                                $$.truelist=nueva_lista_indice(t0);
                                                $$.falselist=nueva_lista_indice(t1);
                                                gen("if " + $1.dir +  " > " + $3.dir + " goto " + t0 );
                                                gen("goto "  + t1 );
                                                }

            | relacional MENOR_QUE relacional{t0 = nuevo_indice();
                                        t1 = nuevo_indice();
                                        $$.truelist=nueva_lista_indice(t0);
                                        $$.falselist=nueva_lista_indice(t1);
                                        gen("if " + $1.dir + " < " + $3.dir  + " goto " +  t0 );
                                        gen("goto " + t1 );
                                        }

            |relacional MENOR_IGUAL_QUE relacional{
                                        t0 = nuevo_indice();
                                        t1 = nuevo_indice();
                                        $$.truelist=nueva_lista_indice(t0);
                                        $$.falselist=nueva_lista_indice(t1);
                                        gen("if " + $1.dir + " <= " + $3.dir + " goto " + t0 );
                                        gen("goto " + t1 );
                                        }

            |relacional MAYOR_IGUAL_QUE relacional{t0 = nuevo_indice(); 
                                        t1 = nuevo_indice();
                                        $$.truelist=nueva_lista_indice(t0);
                                        $$.falselist=nueva_lista_indice(t1);
                                        gen("if " + $1.dir + " >= " + $3.dir + " goto " + t0 );
                                        gen("goto " + t1 );
                                        }

            | relacional DIFER relacional{t0 = nuevo_indice();
                                        t1 = nuevo_indice();
                                        $$.truelist=nueva_lista_indice(t0);
                                        $$.falselist=nueva_lista_indice(t1);
                                        gen("if " + $1.dir + " <> "  + $3.dir " + goto + " t0 );
                                        gen("goto " + t1 ); 
                                        }

            |relacional IGUAL relacional{t0 = nuevo_indice(); 
                                        t1 = nuevo_indice();
                                        $$.truelist=nueva_lista_indice(t0);
                                        $$.falselist=nueva_lista_indice(t1);
                                        gen("if " + $1.dir + " = " + $3.dir + " goto " + t0 );
                                        gen("goto " + t1 ); 
                                        };

relacional: expresion{
                        $$.dir = $1.dir
                        $$.tipo = $1.tipo
                    };



// EXPRESION.TYPE == ENTERO 
// EXPRESION.DIR == STRING
expresion: expresion SUMA expresion {$$.type = max($1.type, $3.type);
                                    $$.dir = nueva_temporal();
                                    string dir1 = ampliar($1.dir, $1.type, $$.type);
                                    string dir2 = ampliar($3.dir, $3.type, $$.type);
                                    gen($$.dir + "=" + dir1 + "+" + dir2); 
                                    }

         | expresion RESTA expresion {$$.type = max($1.type, $3.type);
                                      $$.dir = nueva_temporal();
                                      string dir1 = ampliar($1.dir, $1.type, $$.type);
                                      string dir2 = ampliar($3.dir, $3.type, $$.type);
                                      gen($$.dir + "=" + dir1 + "-" + dir2); 
                                      }

         | expresion MULT expresion {$$.type = max($1.type, $3.type);
                                    $$.dir = nueva_temporal();
                                    string dir1 = ampliar($1.dir, $1.type, $$.type);
                                    string dir2 = ampliar($3.dir, $3.type, $$.type);
                                    gen($$.dir + "=" + dir1 + "*" + dir2); 
                                    }

         | expresion DIV expresion {$$.type = max($1.type, $3.type);
                                    $$.dir = nueva_temporal();
                                    string dir1 = ampliar($1.dir, $1.type, $$.type);
                                    string dir2 = ampliar($3.dir, $3.type, $$.type);
                                    gen($$.dir + "=" + dir1 + "/" + dir2); 
                                    }

         | expresion MOD expresion { if ($1.type == ENT && $3.type == ENT){
                                        $$.type = max($1.type, $3.type);
                                        $$.dir = nueva_temporal();
                                        string dir1 = ampliar($1.dir, $1.type, $$.type);
                                        string dir2 = ampliar($3.dir, $3.type, $$.type);
                                        gen($$.dir + "=" + dir1 + "%" + dir2);
                                     }
                                     else {
                                        error("EL operador "%" solo opera con números enteros");
                                     } 
                                    }

         | PAR_ABRE expresion PAR_CIERRA { $$.type = $2.type; 
                                           $$.dir = $2.dir; }

         | variable { $$.type = $1.type; 
                      $$.dir = $1.dir; }

         | NUM { $$.type = $1.type; 
                 $$.dir = $1.dir; }

         | CADENA { $$.type = "string"; // ???
                    if (TablaCadenas.existe($1)) {
                        $$.dir = TablaCadenas.getIndexStr($1);
                    }
                    else {
                        $$.dir = TablaCadenas.insert($1);
                    }
                  }

         | CARACTER {$$.type = STT.get_global().get_id("car"); // ???
                     if (TablaCadenas.existe($1)) {
                        $$.dir = TablaCadenas.getIndexStr($1);
                     }
                     else {
                        $$.dir = TablaCadenas.insert($1);
                     }
                    };

// VARIABLE.CODE_EST == BOOL
// VARIABLE.DIR = STRING / ENTERO
// VARIABLE.TYPE = ENTERO
// VARIABLE.BASE = ENTERO
// VARIABLE.DES = STRING 

// HAY QUE REVISAR EL ATRIBUTO BASE Y DIR
variable: ID{  if(STS.get_cima().existe($1)) 
                    IDGBL = $1;
                else 
                    error("El identificador no existe");
             }variable_comp  { if ($3.code_est) {
                                    $$.dir = nueva_temporal();
                                    $$.type = $3.type;
                                    gen($$.dir + "=" + $1 + "(" + $3.des + ")");
                                    $$.base = $1.dir; // ??? ENTERO = STRING
                                    $$.code_est = true;
                                    $$.des = $3.des;
                                }
                                else {
                                    $$.dir = $1; // ???
                                    $$.type = STS.get_cima().get_tipo($1);
                                    $$.code_est = false;
                                }
                             };

// VARIABLE_COMP.TYPE == ENTERO 
// VARIABLE_COMP.DES == STRING
// VARIABLE_COMP.CODE_EST == BOOL
variable_comp: dato_est_sim { $$.type = $1.type; 
                              $$.des = $1.des;
                              $$.code_est = $1.code_est;
                            }

             | arreglo { $$.type = $1.type;
                         $$.des = $1.dir;
                         $$.code_est = true;
                       }

             | PAR_ABRE parametros PAR_CIERRA { if (STS.ver_global().get_var(IDGBL).es_funcion()) { // ??? FUNC
                                                    lista = STS.ver_global().getListArgs(IDGBL); // ??? getListArgs
                                                    num = STS.ver_global(); // ??? Falta codigo 
                                                }

                                              };

// DATO_EST_SIM.ESTRUCTURA == BOOL
// DATO_EST_SIM.TYPE == ENTERO 
// DATO_EST_SIM.DES == STRING
// DATO_EST_SIM.TABLA == TABLA

// DE DONDE SALE ID SI ES UNA PRODUCCION VACIA
dato_est_sim: dato_est_sim PUNTO ID {   if ($1.estructura == true) {
                                            if $1.tabla.existe($3) {
                                                $$.des = $1.des + $1.tabla.get_dir($3); //??? tabla_1 $1 o $$
                                                int typeTemp = $1.tabla.get_tipo($3);
                                                string estTemp = $1.tabla.tablaTipos.get_nombre(typeTemp);
                                                if (estTemp == ESTRUCTURA) { // ??? ESTRUCTURA
                                                    $$.estructura = true;
                                                    $$.tabla = $$.tabla.tablaTipos.get_tipo_base(typeTemp).tabla;
                                                }
                                                else {
                                                    $$.estructura = false;
                                                    $$.tabla = NULO;
                                                    $$.type = $1.tabla.get_tipo($3);
                                                }
                                                $$.code_est = true;
                                            }
                                            else {
                                                error("La estructura se ha declarado anteriormente");
                                            }
                                        }
                                        else {
                                            error("No se que error poner aquí");
                                        } 
                                    }
                                
            | { int typeTemp = STS.get_cima().get_tipo(id); // ??? de donde sale id
                if (STT.get_cima().get_nombre(typeTemp) == ESTRUCTURA) { // ??? ESTRUCTURA
                    $$.estructura = true;
                    $$.tabla = STT.get_cima().get_tipo_base(typeTemp).tabla;
                    $$.des = 0;   
                }
                else {
                    $$.estructura = false;
                    $$.type = STT.get_top().get_tipo(id) // ??? otravez id
                }
                $$.code_est = false;
            };

// ARREGLO.TYPE == ENTERO 
// ARREGLO.DIR == STRING
arreglo: CORCH_ABRE expresion CORCH_CIERRA {  $$.type = STS.get_cima().get_tipo(IDGBL);
                                if (STS.get_cima().get_nombre($$.type) == "array") { // ??? array
                                    if ($2.type == ENT) {
                                        int typeTemp = STT.get_cima().get_tipo_base($$.type);
                                        int tam = STT.get_cima().get_tamano(typeTemp);
                                        $$.dir = nueva_temporal();
                                        gen($$.dir + "=" + $2.dir + "*" + tam);
                                    }
                                    else {
                                        error("La variable a la que se intenta acceder no es un arreglo");
                                    }
                                }
                                else {
                                    error("No se ha declarado el arreglo");
                                }
                             }
       | arreglo CORCH_ABRE expresion CORCH_CIERRA {  $$.type = STS.get_cima().get_tipo($1.type);
                                        if (STT.get_cima().get_nombre($$.type) == "array") {
                                            if ($3.type == ENT){
                                                int typeTemp = STT.get_cima().get_tipo_base($$.type);
                                                int tam = STT.get_cima().get_tamano(typeTemp);
                                                string dirTemp = nueva_temporal();
                                                $$.dir = nueva_temporal();
                                                gen(dirTemp + "="  + $3.dir + "*" + to_string(tam));
                                                gen($$.dir + "=" + $1.dir "+" + dirTemp);
                                            }
                                            else {
                                                error("El índice del arreglo debe ser entero");
                                            }
                                        }
                                        else {
                                            error("La variable no es un arreglo"); // ???
                                        }
                                     };

// PARAMETROS.LISTA = LISTA
// PARAMETROS.NUM = ENTERO
parametros: lista_param {   $$.lista = $1.lista;
                            $$.num = $1.num;
                        }
          | { $$.lista = null;
              $$.num = 0;
            };

// LISTA_PARAM.LISTA == LISTA 
// LISTA_PARAM.NUM == ENTERO
lista_param: lista_param COMA expresion {   $$.lista = $1.lista;   
                                            $$.lista.push_back($3.type);
                                            $$.num = $1.num + 1;
                                        }
           | expresion { $$.lista = nueva_lista();
                         $$.lista.push_back($1.type);
                         $$.num = 1;
                       };

%%
void error(char *s){
    printf("%s, linea: %d, token: %s\n",s, yylineno, yytext);
    exit(-1);
}

void gen(string s){
    codigo = codigo + s + "\n";
}

