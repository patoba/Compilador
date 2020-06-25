/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "parser.y"

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

/*funciones acciones EdT*/
void agregar_sym_var(char *id);


/*variables globales*/
TSTACK *STT;
SSTACK *STS;
int dir;
int typeGBL, baseGBL;
/*vector<int> SDir;*/
#line 31 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {

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
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 89 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ESTRUCTURA 257
#define INICIO 258
#define FIN 259
#define DEF 260
#define SI 261
#define ENTONCES 262
#define SINO 263
#define MIENTRAS 264
#define HACER 265
#define SEGUN 266
#define ESCRIBIR 267
#define LEER 268
#define DEVOLVER 269
#define TERMINAR 270
#define CASO 271
#define PRED 272
#define ENT 273
#define REAL 274
#define DREAL 275
#define CAR 276
#define SIN 277
#define VERDADERO 278
#define FALSO 279
#define NUM 280
#define ID 281
#define CARACTER 282
#define CADENA 283
#define COMA 284
#define ASIG 285
#define O 286
#define Y 287
#define IGUAL 288
#define DIFER 289
#define MAYOR_QUE 290
#define MAYOR_IGUAL_QUE 291
#define MENOR_QUE 292
#define MENOR_IGUAL_QUE 293
#define SUMA 294
#define RESTA 295
#define MULT 296
#define DIV 297
#define MOD 298
#define NO 299
#define PUNTO 300
#define DOS_PUNTOS 301
#define PAR_ABRE 302
#define PAR_CIERRA 303
#define CORCH_ABRE 304
#define CORCH_CIERRA 305
#define PUNTO_Y_COMA 306
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
   22,    0,   25,   11,   26,   11,   11,   27,   28,   10,
   29,   13,   15,   15,   15,   15,   15,    9,    9,   24,
   24,   30,   31,   23,   23,    4,    4,    1,    1,    8,
   33,   32,    7,    7,   21,   20,   20,   20,   20,   20,
   20,   20,   20,   20,   20,   20,   20,   17,   17,   16,
   16,   19,   19,   19,   19,   19,   19,   18,   18,   18,
   18,   18,   18,   12,    5,    5,    5,    5,    5,    5,
    5,    5,    5,    5,   35,   14,   34,   34,   34,   36,
   36,    6,    6,    3,    3,    2,    2,
};
static const YYINT yylen[] = {                            2,
    0,    3,    0,    5,    0,    5,    0,    0,    0,    6,
    0,    3,    1,    1,    1,    1,    1,    4,    0,    3,
    1,    0,    0,   13,    0,    1,    1,    3,    1,    2,
    0,    3,    3,    0,    2,    5,    7,    5,    5,    8,
    4,    3,    3,    3,    2,    2,    3,    5,    4,    3,
    0,    3,    3,    2,    1,    1,    1,    3,    3,    3,
    3,    3,    3,    1,    3,    3,    3,    3,    3,    3,
    1,    1,    1,    1,    0,    3,    1,    1,    3,    3,
    0,    3,    4,    1,    0,    3,    1,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    0,   13,   14,   15,   16,   17,    5,    0,
    3,   11,    8,    0,    0,    2,    0,    0,    0,   21,
    0,    0,    0,    0,   12,    9,    0,    0,   22,    0,
    0,    0,   20,    6,    0,    4,    0,   10,    0,   18,
    0,    0,    0,   29,   31,    0,    0,    0,    0,   30,
   28,    0,    0,   32,    0,    0,    0,   33,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   75,    0,   35,
    0,    0,   56,   57,   72,   74,   73,    0,    0,    0,
    0,   71,   55,    0,    0,    0,    0,    0,    0,   45,
    0,   46,    0,    0,    0,   47,   54,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   42,   43,   44,    0,    0,
    0,   76,    0,    0,   24,   70,    0,    0,   67,   68,
   69,   63,   62,   58,   61,   59,   60,    0,    0,   53,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   41,
   36,    0,   38,   39,    0,    0,   79,   82,    0,   80,
    0,    0,    0,    0,   83,   37,    0,    0,    0,    0,
    0,    0,    0,   40,   49,    0,   50,   48,
};
static const YYINT yydgoto[] = {                          1,
   42,  144,  145,   43,   80,  121,   54,   44,   25,    9,
   10,   81,   11,   82,   12,  170,  163,   83,   84,   70,
   57,    2,   16,   21,   17,   14,   19,   32,   18,   35,
   71,   46,   49,  122,   93,  123,
};
static const YYINT yysindex[] = {                         0,
    0,  -80, -249,    0,    0,    0,    0,    0,    0, -228,
    0,    0,    0, -259,  -10,    0, -259, -265,  -80,    0,
 -268, -237, -266, -218,    0,    0, -187,  -80,    0,  -80,
 -229, -146,    0,    0, -188,    0, -265,    0,   51,    0,
    0, -169, -183,    0,    0, -140,  -10, -114, -144,    0,
    0,  -80, -127,    0,    0, -144, -158,    0, -158,  -51,
  -51, -158, -121, -203,  -91, -211, -148,    0,  -94,    0,
  -67,  -45,    0,    0,    0,    0,    0,  -51, -203,   35,
 -136,    0,    0, -262, -250,  -46,  -91, -147,  -72,    0,
  -73,    0, -212, -203, -228,    0,    0,   20, -203, -203,
 -203, -203, -203, -203, -203, -203, -203, -203, -203, -158,
  -51,  -51, -158,  -51,  -88,    0,    0,    0, -203, -203,
  -78,    0,  -64,  -13,    0,    0, -223, -223,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -170,  -38,    0,
   -7, -252,  -12,  -29,  -44,   35,    3, -203,  -23,    0,
    0, -158,    0,    0,   -3, -203,    0,    0,    8,    0,
   11,    6, -219,   35,    0,    0,  -14,    9,   -6,   33,
 -158,   -5, -158,    0,    0, -158,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    2,    0,    0,    0,    0,    0,    0,    0,  294,
    0,    0,    0,    0,    0,    0,    0,   26,   50,    0,
    0,    0,    0,    0,    0,    0,    0,    1,    0,    1,
    0,    0,    0,    0,    0,    0,   26,    0,    0,    0,
 -275,    7,    0,    0,    0,    0,    0,    0,   30,    0,
    0,    0,    0,    0,    0,   30,   53,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -205,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -160,    0,  294,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   16,    0,
 -123,    0,  -86,    0,    0,    0,  -49,  -15,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -245,    0,
    0,    0,    0,   17,    0, -258,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   62, -238,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,    0,  -52,    0,  266,  287,  298,    0,
   -9,   80,  321,  -54,  -16,    0,    0,    0,  -48,  -55,
    0,    0,  242,  322,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 339
static const YYINT yytable[] = {                        110,
    7,    7,   69,   72,   69,   17,   86,   69,   13,   26,
   89,   88,   85,   91,  113,   27,   52,   27,   34,   52,
   36,   20,   45,  111,  112,   87,   98,   27,   17,   97,
   45,   15,  115,  111,  112,  111,  112,   28,   24,   30,
   52,  124,   55,   29,   87,   86,  127,  128,  129,  130,
  131,  168,  169,  154,  138,   69,   64,  141,   69,   64,
   52,   31,  139,  140,   86,  142,  146,  147,   75,   68,
   76,   77,  101,  102,  103,   37,   75,   68,   76,   77,
   64,   64,   64,   64,   64,   64,   64,   64,  151,  119,
   79,  120,  152,   33,   90,  159,  161,   69,   79,   59,
   64,   81,   60,  164,   81,   61,   62,   63,   64,   65,
   66,   67,   38,   39,   47,  175,   69,  177,   69,   48,
  178,   69,   68,   81,   81,   81,   81,   81,   81,   81,
   81,   81,   81,   81,   81,   81,   81,   81,   78,   81,
   50,   78,   81,   52,   81,   81,   99,  100,  101,  102,
  103,  104,  105,  106,  107,  108,  109,   92,  116,   53,
   78,   78,   78,   78,   78,   78,   78,   78,   78,   78,
   78,   78,   78,   78,   78,   77,    3,   56,   77,   78,
   87,   78,   78,  132,  133,  134,  135,  136,  137,   68,
   94,   95,    4,    5,    6,    7,    8,   77,   77,   77,
   77,   77,   77,   77,   77,   77,   77,   77,   77,   77,
   77,   77,   65,   96,  143,   65,   77,  114,   77,   77,
   99,  100,  101,  102,  103,  148,   73,   74,   75,   68,
   76,   77,  118,  117,   65,  149,   65,   65,   65,   65,
   65,   65,   65,   65,   65,   65,   66,   78,  112,   66,
   79,  153,  155,   65,  156,   65,   65,  160,  157,    7,
    7,    7,    4,    5,    6,    7,    8,  162,   66,  166,
   66,   66,   66,   66,   66,   66,   66,   66,   66,   66,
   99,  100,  101,  102,  103,  167,  171,   66,  172,   66,
   66,  174,  150,   25,  173,  176,   99,  100,  101,  102,
  103,   99,  100,  101,  102,  103,   19,  158,    7,   26,
   34,   23,  165,   99,  100,  101,  102,  103,   85,   84,
   51,   58,  126,    4,    5,    6,    7,   41,   99,  100,
  101,  102,  103,   51,   40,   22,  125,    0,   23,
};
static const YYINT yycheck[] = {                        262,
    0,    0,   57,   59,   59,  281,   62,   62,  258,   19,
   65,   64,   61,   66,  265,  284,  262,  284,   28,  265,
   30,  281,   39,  286,  287,  284,   79,  303,  304,   78,
   47,  260,   87,  286,  287,  286,  287,  306,  304,  306,
  286,   94,   52,  281,  303,  284,   99,  100,  101,  102,
  103,  271,  272,  306,  110,  110,  262,  113,  113,  265,
  306,  280,  111,  112,  303,  114,  119,  120,  280,  281,
  282,  283,  296,  297,  298,  305,  280,  281,  282,  283,
  286,  287,  288,  289,  290,  291,  292,  293,  259,  302,
  302,  304,  263,  281,  306,  148,  152,  152,  302,  258,
  306,  262,  261,  156,  265,  264,  265,  266,  267,  268,
  269,  270,  259,  302,  284,  171,  171,  173,  173,  303,
  176,  176,  281,  284,  285,  286,  287,  288,  289,  290,
  291,  292,  293,  294,  295,  296,  297,  298,  262,  300,
  281,  265,  303,  258,  305,  306,  294,  295,  296,  297,
  298,  288,  289,  290,  291,  292,  293,  306,  306,  304,
  284,  285,  286,  287,  288,  289,  290,  291,  292,  293,
  294,  295,  296,  297,  298,  262,  257,  305,  265,  303,
  302,  305,  306,  104,  105,  106,  107,  108,  109,  281,
  285,  259,  273,  274,  275,  276,  277,  284,  285,  286,
  287,  288,  289,  290,  291,  292,  293,  294,  295,  296,
  297,  298,  262,  259,  303,  265,  303,  264,  305,  306,
  294,  295,  296,  297,  298,  304,  278,  279,  280,  281,
  282,  283,  306,  306,  284,  300,  286,  287,  288,  289,
  290,  291,  292,  293,  294,  295,  262,  299,  287,  265,
  302,  259,  265,  303,  284,  305,  306,  281,  303,  259,
  260,  260,  273,  274,  275,  276,  277,  271,  284,  259,
  286,  287,  288,  289,  290,  291,  292,  293,  294,  295,
  294,  295,  296,  297,  298,  280,  301,  303,  280,  305,
  306,  259,  306,    0,  301,  301,  294,  295,  296,  297,
  298,  294,  295,  296,  297,  298,  281,  305,  259,  303,
  281,  259,  305,  294,  295,  296,  297,  298,  303,  303,
  259,   56,  303,  273,  274,  275,  276,  277,  294,  295,
  296,  297,  298,   47,   37,   15,   95,   -1,   17,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 306
#define YYUNDFTOKEN 345
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ESTRUCTURA","INICIO","FIN","DEF",
"SI","ENTONCES","SINO","MIENTRAS","HACER","SEGUN","ESCRIBIR","LEER","DEVOLVER",
"TERMINAR","CASO","PRED","ENT","REAL","DREAL","CAR","SIN","VERDADERO","FALSO",
"NUM","ID","CARACTER","CADENA","COMA","ASIG","O","Y","IGUAL","DIFER",
"MAYOR_QUE","MAYOR_IGUAL_QUE","MENOR_QUE","MENOR_IGUAL_QUE","SUMA","RESTA",
"MULT","DIV","MOD","NO","PUNTO","DOS_PUNTOS","PAR_ABRE","PAR_CIERRA",
"CORCH_ABRE","CORCH_CIERRA","PUNTO_Y_COMA",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programa",
"$$1 :",
"programa : $$1 declaraciones funciones",
"$$2 :",
"declaraciones : tipo $$2 lista_var PUNTO_Y_COMA declaraciones",
"$$3 :",
"declaraciones : tipo_registro $$3 lista_var PUNTO_Y_COMA declaraciones",
"declaraciones :",
"$$4 :",
"$$5 :",
"tipo_registro : ESTRUCTURA INICIO $$4 declaraciones $$5 FIN",
"$$6 :",
"tipo : base $$6 tipo_arreglo",
"base : ENT",
"base : REAL",
"base : DREAL",
"base : CAR",
"base : SIN",
"tipo_arreglo : CORCH_ABRE NUM CORCH_CIERRA tipo_arreglo",
"tipo_arreglo :",
"lista_var : lista_var COMA ID",
"lista_var : ID",
"$$7 :",
"$$8 :",
"funciones : DEF tipo ID $$7 PAR_ABRE argumentos PAR_CIERRA INICIO declaraciones sentencias $$8 FIN funciones",
"funciones :",
"argumentos : lista_arg",
"argumentos : SIN",
"lista_arg : lista_arg COMA arg",
"lista_arg : arg",
"arg : tipo_arg ID",
"$$9 :",
"tipo_arg : base $$9 param_arr",
"param_arr : CORCH_ABRE CORCH_CIERRA param_arr",
"param_arr :",
"sentencias : sentencias sentencia",
"sentencia : SI e_bool ENTONCES sentencia FIN",
"sentencia : SI e_bool ENTONCES sentencia SINO sentencia FIN",
"sentencia : MIENTRAS e_bool HACER sentencia FIN",
"sentencia : HACER sentencia MIENTRAS e_bool PUNTO_Y_COMA",
"sentencia : SEGUN PAR_ABRE variable PAR_CIERRA HACER casos predeterminado FIN",
"sentencia : variable ASIG expresion PUNTO_Y_COMA",
"sentencia : ESCRIBIR expresion PUNTO_Y_COMA",
"sentencia : LEER variable PUNTO_Y_COMA",
"sentencia : DEVOLVER expresion PUNTO_Y_COMA",
"sentencia : DEVOLVER PUNTO_Y_COMA",
"sentencia : TERMINAR PUNTO_Y_COMA",
"sentencia : INICIO sentencia FIN",
"casos : casos CASO NUM DOS_PUNTOS sentencia",
"casos : CASO NUM DOS_PUNTOS sentencia",
"predeterminado : PRED DOS_PUNTOS sentencia",
"predeterminado :",
"e_bool : e_bool O e_bool",
"e_bool : e_bool Y e_bool",
"e_bool : NO e_bool",
"e_bool : relacional_op",
"e_bool : VERDADERO",
"e_bool : FALSO",
"relacional_op : relacional MAYOR_QUE relacional",
"relacional_op : relacional MENOR_QUE relacional",
"relacional_op : relacional MENOR_IGUAL_QUE relacional",
"relacional_op : relacional MAYOR_IGUAL_QUE relacional",
"relacional_op : relacional DIFER relacional",
"relacional_op : relacional IGUAL relacional",
"relacional : expresion",
"expresion : expresion SUMA expresion",
"expresion : expresion RESTA expresion",
"expresion : expresion MULT expresion",
"expresion : expresion DIV expresion",
"expresion : expresion MOD expresion",
"expresion : PAR_ABRE expresion PAR_CIERRA",
"expresion : variable",
"expresion : NUM",
"expresion : CADENA",
"expresion : CARACTER",
"$$10 :",
"variable : ID $$10 variable_comp",
"variable_comp : dato_est_sim",
"variable_comp : arreglo",
"variable_comp : PAR_ABRE parametros PAR_CIERRA",
"dato_est_sim : dato_est_sim PUNTO ID",
"dato_est_sim :",
"arreglo : CORCH_ABRE expresion CORCH_CIERRA",
"arreglo : arreglo CORCH_ABRE expresion CORCH_CIERRA",
"parametros : lista_param",
"parametros :",
"lista_param : lista_param COMA expresion",
"lista_param : expresion",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 371 "parser.y"

void yyerror(char *s){
    printf("%s, linea: %d, token: %s\n",s, yylineno, yytext);
}

void agregar_sym_var(char *id){
    if(search_SYM(getTopSym(STS), id) == NULL){
        SYM *s = crear_sym(id, dir, typeGBL, "var", NULL);
        append_sym(getTopSym(STS), s);//prueba
        dir = dir + getTam(getGlobal(STT), typeGBL);
    }else{
        char s[80] = "Ya existe una variable llamada ";
        strcat(s, id);
        yyerror(s);
    }
}
#line 509 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 107 "parser.y"
	{ 
            
            STS = init_sym_tab_stack();
            STT = init_type_tab_stack();
            
            TYPTAB *global = init_type_tab_global();
            push_tt(STT, global);

            SYMTAB *primera = init_sym_tab();
            push_st(STS, primera);

            dir = 0;
          }
break;
case 2:
#line 119 "parser.y"
	{
                                    /*$$.codigo = $3.codigo;*/
                                    print_stack_tab_type(STT);
                                    /*printf("aqui");*/
                                    /*printf("%d\n", STT->top.);*/
                                    print_stack_tab_sym(STS);
                                    }
break;
case 3:
#line 127 "parser.y"
	{typeGBL = yystack.l_mark[0].tipo.type;}
break;
case 5:
#line 128 "parser.y"
	{typeGBL= yystack.l_mark[0].tipo.type;}
break;
case 7:
#line 129 "parser.y"
	{}
break;
case 8:
#line 134 "parser.y"
	{  
                                   }
break;
case 9:
#line 135 "parser.y"
	{
                                                    }
break;
case 10:
#line 136 "parser.y"
	{
                                                        
                                                    }
break;
case 11:
#line 140 "parser.y"
	{baseGBL = yystack.l_mark[0].base.base;}
break;
case 12:
#line 140 "parser.y"
	{yyval.tipo.type = yystack.l_mark[0].tipo.type;}
break;
case 13:
#line 143 "parser.y"
	{yyval.base.base = getId(getGlobal(STT), "ent");}
break;
case 14:
#line 144 "parser.y"
	{yyval.base.base = getId(getGlobal(STT), "real");}
break;
case 15:
#line 145 "parser.y"
	{yyval.base.base = getId(getGlobal(STT), "dreal");}
break;
case 16:
#line 146 "parser.y"
	{yyval.base.base = getId(getGlobal(STT), "car");}
break;
case 17:
#line 147 "parser.y"
	{yyval.base.base = getId(getGlobal(STT), "sin");}
break;
case 18:
#line 152 "parser.y"
	{
                                                        if(yystack.l_mark[-2].tipo.type == getId(getGlobal(STT), "ent")){
                                                            int temp_dir = atoi(yystack.l_mark[-2].tipo.dir);
                                                            if(temp_dir > 0){ /*dir debe ser entero*/
                                                                TB* tipo_base = crear_tipo_basado(yystack.l_mark[0].tipo.type);
                                                                TYP *nuevo = crear_type("array", atoi(yystack.l_mark[-2].tipo.dir) * getTam(getGlobal(STT), yystack.l_mark[0].tipo.type), tipo_base);
                                                                append_type(getTopType(STT), nuevo);
                                                                yyval.tipo.type = nuevo->id;
                                                            }else{
                                                                yyerror("El indice debe ser mayor a cero");
                                                            }
                                                        }else{
                                                            yyerror("El indice debe ser tipo entero\n");
                                                        }
                                                      }
break;
case 19:
#line 167 "parser.y"
	{yyval.tipo.type=baseGBL;}
break;
case 20:
#line 173 "parser.y"
	{  
                                agregar_sym_var(yystack.l_mark[0].tipo.dir);
                             }
break;
case 21:
#line 176 "parser.y"
	{
                    agregar_sym_var(yystack.l_mark[0].tipo.dir);
                 }
break;
case 22:
#line 183 "parser.y"
	{
                        }
break;
case 23:
#line 184 "parser.y"
	{
                                                                                        }
break;
case 25:
#line 186 "parser.y"
	{}
break;
case 26:
#line 190 "parser.y"
	{}
break;
case 27:
#line 191 "parser.y"
	{}
break;
case 28:
#line 196 "parser.y"
	{ }
break;
case 29:
#line 197 "parser.y"
	{ }
break;
case 30:
#line 199 "parser.y"
	{
                }
break;
case 31:
#line 205 "parser.y"
	{baseGBL = yystack.l_mark[0].base.base;}
break;
case 32:
#line 205 "parser.y"
	{}
break;
case 33:
#line 207 "parser.y"
	{}
break;
case 34:
#line 208 "parser.y"
	{}
break;
case 35:
#line 211 "parser.y"
	{}
break;
case 36:
#line 214 "parser.y"
	{}
break;
case 37:
#line 216 "parser.y"
	{}
break;
case 38:
#line 217 "parser.y"
	{}
break;
case 39:
#line 218 "parser.y"
	{}
break;
case 40:
#line 219 "parser.y"
	{
                                                                        
                                                                        }
break;
case 41:
#line 222 "parser.y"
	{
                                    }
break;
case 42:
#line 225 "parser.y"
	{}
break;
case 43:
#line 226 "parser.y"
	{}
break;
case 44:
#line 227 "parser.y"
	{}
break;
case 45:
#line 228 "parser.y"
	{}
break;
case 46:
#line 229 "parser.y"
	{}
break;
case 47:
#line 230 "parser.y"
	{}
break;
case 48:
#line 234 "parser.y"
	{}
break;
case 49:
#line 235 "parser.y"
	{}
break;
case 50:
#line 238 "parser.y"
	{}
break;
case 51:
#line 239 "parser.y"
	{}
break;
case 52:
#line 246 "parser.y"
	{
                            }
break;
case 53:
#line 248 "parser.y"
	{
                            }
break;
case 54:
#line 250 "parser.y"
	{
                    }
break;
case 55:
#line 252 "parser.y"
	{
                    }
break;
case 56:
#line 254 "parser.y"
	{
                    }
break;
case 57:
#line 256 "parser.y"
	{
                }
break;
case 58:
#line 262 "parser.y"
	{ 
                                                }
break;
case 59:
#line 265 "parser.y"
	{
                                        }
break;
case 60:
#line 268 "parser.y"
	{
                                        
                                        }
break;
case 61:
#line 272 "parser.y"
	{
                                        }
break;
case 62:
#line 275 "parser.y"
	{
                                        }
break;
case 63:
#line 278 "parser.y"
	{
                                        }
break;
case 64:
#line 281 "parser.y"
	{
                    }
break;
case 65:
#line 288 "parser.y"
	{
                                    }
break;
case 66:
#line 291 "parser.y"
	{
                                      }
break;
case 67:
#line 294 "parser.y"
	{
                                    }
break;
case 68:
#line 297 "parser.y"
	{
                                    }
break;
case 69:
#line 300 "parser.y"
	{ 
                                    }
break;
case 70:
#line 303 "parser.y"
	{  }
break;
case 71:
#line 305 "parser.y"
	{}
break;
case 72:
#line 307 "parser.y"
	{ }
break;
case 73:
#line 308 "parser.y"
	{ 
                  }
break;
case 74:
#line 311 "parser.y"
	{
                    }
break;
case 75:
#line 321 "parser.y"
	{  
             }
break;
case 76:
#line 322 "parser.y"
	{ 
                             }
break;
case 77:
#line 328 "parser.y"
	{ 
                            }
break;
case 78:
#line 331 "parser.y"
	{ 
                       }
break;
case 79:
#line 334 "parser.y"
	{ 

                                              }
break;
case 80:
#line 344 "parser.y"
	{   
                                    }
break;
case 81:
#line 347 "parser.y"
	{ 
            }
break;
case 82:
#line 352 "parser.y"
	{  
                                }
break;
case 83:
#line 354 "parser.y"
	{  
                                     }
break;
case 84:
#line 359 "parser.y"
	{   
                        }
break;
case 85:
#line 361 "parser.y"
	{ 
            }
break;
case 86:
#line 366 "parser.y"
	{   
                                        }
break;
case 87:
#line 368 "parser.y"
	{ 
                       }
break;
#line 1128 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
