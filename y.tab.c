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
#include "pila_dir.h"

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
SDir *SDIR;
/*vector<int> SDir;*/
#line 33 "parser.y"
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
#line 91 "y.tab.c"

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
   22,    0,   25,   11,   26,   11,   11,   27,   10,   28,
   13,   15,   15,   15,   15,   15,    9,    9,   24,   24,
   29,   30,   23,   23,    4,    4,    1,    1,    8,   32,
   31,    7,    7,   21,   20,   20,   20,   20,   20,   20,
   20,   20,   20,   20,   20,   20,   17,   17,   16,   16,
   19,   19,   19,   19,   19,   19,   18,   18,   18,   18,
   18,   18,   12,    5,    5,    5,    5,    5,    5,    5,
    5,    5,    5,   34,   14,   33,   33,   33,   35,   35,
    6,    6,    3,    3,    2,    2,
};
static const YYINT yylen[] = {                            2,
    0,    3,    0,    5,    0,    5,    0,    0,    5,    0,
    3,    1,    1,    1,    1,    1,    4,    0,    3,    1,
    0,    0,   13,    0,    1,    1,    3,    1,    2,    0,
    3,    3,    0,    2,    5,    7,    5,    5,    8,    4,
    3,    3,    3,    2,    2,    3,    5,    4,    3,    0,
    3,    3,    2,    1,    1,    1,    3,    3,    3,    3,
    3,    3,    1,    3,    3,    3,    3,    3,    3,    1,
    1,    1,    1,    0,    3,    1,    1,    3,    3,    0,
    3,    4,    1,    0,    3,    1,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    0,   12,   13,   14,   15,   16,    5,    0,
    3,   10,    8,    0,    0,    2,    0,    0,    0,   20,
    0,    0,    0,    0,   11,    0,    0,    0,   21,    0,
    0,    9,   19,    6,    0,    4,    0,    0,   17,    0,
    0,    0,   28,   30,    0,    0,    0,    0,   29,   27,
    0,    0,   31,    0,    0,    0,   32,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   74,    0,   34,    0,
    0,   55,   56,   71,   73,   72,    0,    0,    0,    0,
   70,   54,    0,    0,    0,    0,    0,    0,   44,    0,
   45,    0,    0,    0,   46,   53,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   41,   42,   43,    0,    0,    0,
   75,    0,    0,   23,   69,    0,    0,   66,   67,   68,
   62,   61,   57,   60,   58,   59,    0,    0,   52,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   40,   35,
    0,   37,   38,    0,    0,   78,   81,    0,   79,    0,
    0,    0,    0,   82,   36,    0,    0,    0,    0,    0,
    0,    0,   39,   48,    0,   49,   47,
};
static const YYINT yydgoto[] = {                          1,
   41,  143,  144,   42,   79,  120,   53,   43,   25,    9,
   10,   80,   11,   81,   12,  169,  162,   82,   83,   69,
   56,    2,   16,   21,   17,   14,   19,   18,   35,   70,
   45,   48,  121,   92,  122,
};
static const YYINT yysindex[] = {                         0,
    0,  -80, -249,    0,    0,    0,    0,    0,    0, -238,
    0,    0,    0, -242,  -10,    0, -242, -260,  -80,    0,
 -269, -219, -268, -207,    0, -170, -191,  -80,    0,  -80,
 -192,    0,    0,    0, -188,    0, -260,   51,    0,    0,
 -169, -183,    0,    0, -140,  -10, -114, -146,    0,    0,
  -80, -145,    0,    0, -146, -158,    0, -158,  -50,  -50,
 -158, -124, -203, -100, -211, -116,    0,  -94,    0,  -67,
  -45,    0,    0,    0,    0,    0,  -50, -203,   35, -136,
    0,    0, -262, -255,  -46, -100, -147,  -91,    0,  -72,
    0, -228, -203, -238,    0,    0,   20, -203, -203, -203,
 -203, -203, -203, -203, -203, -203, -203, -203, -158,  -50,
  -50, -158,  -50,  -82,    0,    0,    0, -203, -203,  -77,
    0,  -64,  -13,    0,    0, -204, -204,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -240,  -39,    0,   -8,
 -241,  -12,  -29,  -44,   35,    3, -203,  -23,    0,    0,
 -158,    0,    0,   -3, -203,    0,    0,    8,    0,   11,
    6, -236,   35,    0,    0,  -14,    9,   -9,   36, -158,
   -7, -158,    0,    0, -158,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    2,    0,    0,    0,    0,    0,    0,    0,  296,
    0,    0,    0,    0,    0,    0,    0,   26,   50,    0,
    0,    0,    0,    0,    0,    0,    0,    1,    0,    1,
    0,    0,    0,    0,    0,    0,   26,    0,    0, -275,
    7,    0,    0,    0,    0,    0,    0, -191,    0,    0,
    0,    0,    0,    0, -191,   52,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -205,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -160,    0,  296,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   16,    0, -123,
    0,  -86,    0,    0,    0,  -49,  -15,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -245,    0,    0,
    0,    0,   17,    0, -263,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   53, -250,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,    0,  -51,    0,  266,  276,  297,    0,
   24,   81,  320,  -53,  -20,    0,    0,    0,  -47,  -54,
    0,    0,  242,  321,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 338
static const YYINT yytable[] = {                        109,
    7,    7,   68,   71,   68,   16,   85,   68,   13,  112,
   88,   87,   84,   90,   27,   27,   51,   44,  150,   51,
   86,   15,  151,  110,  111,   44,   97,   26,   16,   96,
  110,  111,  114,   85,  167,  168,   28,   30,   20,   86,
   51,  123,   26,   24,  110,  111,  126,  127,  128,  129,
  130,   34,   85,   36,  137,   68,   63,  140,   68,   63,
   51,   29,  138,  139,  153,  141,  145,  146,   74,   67,
   75,   76,   31,  118,   54,  119,   74,   67,   75,   76,
   63,   63,   63,   63,   63,   63,   63,   63,   32,   33,
   78,  100,  101,  102,   89,  158,  160,   68,   78,   58,
   63,   80,   59,  163,   80,   60,   61,   62,   63,   64,
   65,   66,   37,   38,   46,  174,   68,  176,   68,   47,
  177,   68,   67,   80,   80,   80,   80,   80,   80,   80,
   80,   80,   80,   80,   80,   80,   80,   80,   77,   80,
   49,   77,   80,   51,   80,   80,   98,   99,  100,  101,
  102,  103,  104,  105,  106,  107,  108,   52,  115,   55,
   77,   77,   77,   77,   77,   77,   77,   77,   77,   77,
   77,   77,   77,   77,   77,   76,    3,   86,   76,   77,
   67,   77,   77,  131,  132,  133,  134,  135,  136,   91,
   93,   94,    4,    5,    6,    7,    8,   76,   76,   76,
   76,   76,   76,   76,   76,   76,   76,   76,   76,   76,
   76,   76,   64,   95,  116,   64,   76,  113,   76,   76,
  142,   98,   99,  100,  101,  102,  147,   72,   73,   74,
   67,   75,   76,  117,   64,  148,   64,   64,   64,   64,
   64,   64,   64,   64,   64,   64,   65,  111,   77,   65,
  152,   78,  154,   64,  155,   64,   64,  159,  156,    7,
    7,    7,    4,    5,    6,    7,    8,  161,   65,  165,
   65,   65,   65,   65,   65,   65,   65,   65,   65,   65,
   98,   99,  100,  101,  102,  166,  170,   65,  171,   65,
   65,  172,  149,  175,  173,   24,   98,   99,  100,  101,
  102,   98,   99,  100,  101,  102,   18,  157,    7,   25,
   22,   50,  164,   98,   99,  100,  101,  102,   84,   83,
   57,   50,  125,    4,    5,    6,    7,   40,   98,   99,
  100,  101,  102,   39,   22,  124,    0,   23,
};
static const YYINT yycheck[] = {                        262,
    0,    0,   56,   58,   58,  281,   61,   61,  258,  265,
   64,   63,   60,   65,  284,  284,  262,   38,  259,  265,
  284,  260,  263,  286,  287,   46,   78,  303,  304,   77,
  286,  287,   86,  284,  271,  272,  306,  306,  281,  303,
  286,   93,   19,  304,  286,  287,   98,   99,  100,  101,
  102,   28,  303,   30,  109,  109,  262,  112,  112,  265,
  306,  281,  110,  111,  306,  113,  118,  119,  280,  281,
  282,  283,  280,  302,   51,  304,  280,  281,  282,  283,
  286,  287,  288,  289,  290,  291,  292,  293,  259,  281,
  302,  296,  297,  298,  306,  147,  151,  151,  302,  258,
  306,  262,  261,  155,  265,  264,  265,  266,  267,  268,
  269,  270,  305,  302,  284,  170,  170,  172,  172,  303,
  175,  175,  281,  284,  285,  286,  287,  288,  289,  290,
  291,  292,  293,  294,  295,  296,  297,  298,  262,  300,
  281,  265,  303,  258,  305,  306,  294,  295,  296,  297,
  298,  288,  289,  290,  291,  292,  293,  304,  306,  305,
  284,  285,  286,  287,  288,  289,  290,  291,  292,  293,
  294,  295,  296,  297,  298,  262,  257,  302,  265,  303,
  281,  305,  306,  103,  104,  105,  106,  107,  108,  306,
  285,  259,  273,  274,  275,  276,  277,  284,  285,  286,
  287,  288,  289,  290,  291,  292,  293,  294,  295,  296,
  297,  298,  262,  259,  306,  265,  303,  264,  305,  306,
  303,  294,  295,  296,  297,  298,  304,  278,  279,  280,
  281,  282,  283,  306,  284,  300,  286,  287,  288,  289,
  290,  291,  292,  293,  294,  295,  262,  287,  299,  265,
  259,  302,  265,  303,  284,  305,  306,  281,  303,  259,
  260,  260,  273,  274,  275,  276,  277,  271,  284,  259,
  286,  287,  288,  289,  290,  291,  292,  293,  294,  295,
  294,  295,  296,  297,  298,  280,  301,  303,  280,  305,
  306,  301,  306,  301,  259,    0,  294,  295,  296,  297,
  298,  294,  295,  296,  297,  298,  281,  305,  259,  303,
  259,  259,  305,  294,  295,  296,  297,  298,  303,  303,
   55,   46,  303,  273,  274,  275,  276,  277,  294,  295,
  296,  297,  298,   37,   15,   94,   -1,   17,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 306
#define YYUNDFTOKEN 344
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"tipo_registro : ESTRUCTURA INICIO $$4 declaraciones FIN",
"$$5 :",
"tipo : base $$5 tipo_arreglo",
"base : ENT",
"base : REAL",
"base : DREAL",
"base : CAR",
"base : SIN",
"tipo_arreglo : CORCH_ABRE NUM CORCH_CIERRA tipo_arreglo",
"tipo_arreglo :",
"lista_var : lista_var COMA ID",
"lista_var : ID",
"$$6 :",
"$$7 :",
"funciones : DEF tipo ID $$6 PAR_ABRE argumentos PAR_CIERRA INICIO declaraciones sentencias $$7 FIN funciones",
"funciones :",
"argumentos : lista_arg",
"argumentos : SIN",
"lista_arg : lista_arg COMA arg",
"lista_arg : arg",
"arg : tipo_arg ID",
"$$8 :",
"tipo_arg : base $$8 param_arr",
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
"$$9 :",
"variable : ID $$9 variable_comp",
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
#line 389 "parser.y"

void yyerror(char *s){
    printf("%s, linea: %d, token: %s\n",s, yylineno, yytext);
}

void agregar_sym_var(char *id){
    if(search_SYM(getTopSym(STS), id) == NULL){
        SYM *s = crear_sym(id, dir, typeGBL, "var", NULL);
        append_sym(getTopSym(STS), s);//prueba
        dir = dir + buscar_en_pila(STT, typeGBL)->tam;
    }else{
        char s[80] = "Ya existe una variable llamada ";
        strcat(s, id);
        yyerror(s);
    }
}
#line 510 "y.tab.c"

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
#line 109 "parser.y"
	{ 
            
            STS = init_sym_tab_stack();
            STT = init_type_tab_stack();
            
            TYPTAB *global = init_type_tab_global();
            push_tt(STT, global);

            SYMTAB *primera = init_sym_tab();
            push_st(STS, primera);

            dir = 0;
            SDIR = create_s_dir();
          }
break;
case 2:
#line 122 "parser.y"
	{
                                    /*$$.codigo = $3.codigo;*/
                                    print_stack_tab_type(STT);
                                    /*printf("aqui");*/
                                    /*printf("%d\n", STT->top.);*/
                                    print_stack_tab_sym(STS);
                                    }
break;
case 3:
#line 130 "parser.y"
	{typeGBL = yystack.l_mark[0].tipo.type;}
break;
case 5:
#line 131 "parser.y"
	{typeGBL= yystack.l_mark[0].tipo.type;}
break;
case 7:
#line 132 "parser.y"
	{}
break;
case 8:
#line 137 "parser.y"
	{  
                                   push_tt(STT, init_tabla_tipo());
                                   push_st(STS, init_sym_tab());
                                   
                                   pushSDir(SDIR, dir);
                                   dir = 0;
                                   }
break;
case 9:
#line 143 "parser.y"
	{
                                                        SYMTAB *SymTab = pop_st(STS);
                                                        int tam = tamano_tabla_tipos(SymTab, STT);
                                                        SymTab->tt_asoc = pop_tt(STT);
                                                        

                                                        dir = popSDir(SDIR);
                                                        
                                                        TB *tb = crear_estructura(SymTab); /*falla implementacion*/
                                                        TYP *nuevo = crear_type("struct", tam, tb);
                                                        append_type(getTopType(STT), nuevo);
                                                        yyval.tipo.type = nuevo->id;
                                                    }
break;
case 10:
#line 157 "parser.y"
	{baseGBL = yystack.l_mark[0].base.base;}
break;
case 11:
#line 157 "parser.y"
	{yyval.tipo.type = yystack.l_mark[0].tipo.type;}
break;
case 12:
#line 160 "parser.y"
	{yyval.base.base = getId(getGlobal(STT), "ent");}
break;
case 13:
#line 161 "parser.y"
	{yyval.base.base = getId(getGlobal(STT), "real");}
break;
case 14:
#line 162 "parser.y"
	{yyval.base.base = getId(getGlobal(STT), "dreal");}
break;
case 15:
#line 163 "parser.y"
	{yyval.base.base = getId(getGlobal(STT), "car");}
break;
case 16:
#line 164 "parser.y"
	{yyval.base.base = getId(getGlobal(STT), "sin");}
break;
case 17:
#line 169 "parser.y"
	{
                                                        if(yystack.l_mark[-2].tipo.type == getId(getGlobal(STT), "ent")){
                                                            int temp_dir = atoi(yystack.l_mark[-2].tipo.dir);
                                                            if(temp_dir > 0){ /*dir debe ser entero*/
                                                                TB* tipo_base = crear_tipo_basado(yystack.l_mark[0].tipo.type);
                                                                int tam_anterior = buscar_en_pila(STT, yystack.l_mark[0].tipo.type)->tam;
                                                                TYP *nuevo = crear_type("array", atoi(yystack.l_mark[-2].tipo.dir) * tam_anterior, tipo_base);
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
case 18:
#line 185 "parser.y"
	{yyval.tipo.type=baseGBL;}
break;
case 19:
#line 191 "parser.y"
	{  
                                agregar_sym_var(yystack.l_mark[0].tipo.dir);
                             }
break;
case 20:
#line 194 "parser.y"
	{
                    agregar_sym_var(yystack.l_mark[0].tipo.dir);
                 }
break;
case 21:
#line 201 "parser.y"
	{
                        }
break;
case 22:
#line 202 "parser.y"
	{
                                                                                        }
break;
case 24:
#line 204 "parser.y"
	{}
break;
case 25:
#line 208 "parser.y"
	{}
break;
case 26:
#line 209 "parser.y"
	{}
break;
case 27:
#line 214 "parser.y"
	{ }
break;
case 28:
#line 215 "parser.y"
	{ }
break;
case 29:
#line 217 "parser.y"
	{
                }
break;
case 30:
#line 223 "parser.y"
	{baseGBL = yystack.l_mark[0].base.base;}
break;
case 31:
#line 223 "parser.y"
	{}
break;
case 32:
#line 225 "parser.y"
	{}
break;
case 33:
#line 226 "parser.y"
	{}
break;
case 34:
#line 229 "parser.y"
	{}
break;
case 35:
#line 232 "parser.y"
	{}
break;
case 36:
#line 234 "parser.y"
	{}
break;
case 37:
#line 235 "parser.y"
	{}
break;
case 38:
#line 236 "parser.y"
	{}
break;
case 39:
#line 237 "parser.y"
	{
                                                                        
                                                                        }
break;
case 40:
#line 240 "parser.y"
	{
                                    }
break;
case 41:
#line 243 "parser.y"
	{}
break;
case 42:
#line 244 "parser.y"
	{}
break;
case 43:
#line 245 "parser.y"
	{}
break;
case 44:
#line 246 "parser.y"
	{}
break;
case 45:
#line 247 "parser.y"
	{}
break;
case 46:
#line 248 "parser.y"
	{}
break;
case 47:
#line 252 "parser.y"
	{}
break;
case 48:
#line 253 "parser.y"
	{}
break;
case 49:
#line 256 "parser.y"
	{}
break;
case 50:
#line 257 "parser.y"
	{}
break;
case 51:
#line 264 "parser.y"
	{
                            }
break;
case 52:
#line 266 "parser.y"
	{
                            }
break;
case 53:
#line 268 "parser.y"
	{
                    }
break;
case 54:
#line 270 "parser.y"
	{
                    }
break;
case 55:
#line 272 "parser.y"
	{
                    }
break;
case 56:
#line 274 "parser.y"
	{
                }
break;
case 57:
#line 280 "parser.y"
	{ 
                                                }
break;
case 58:
#line 283 "parser.y"
	{
                                        }
break;
case 59:
#line 286 "parser.y"
	{
                                        
                                        }
break;
case 60:
#line 290 "parser.y"
	{
                                        }
break;
case 61:
#line 293 "parser.y"
	{
                                        }
break;
case 62:
#line 296 "parser.y"
	{
                                        }
break;
case 63:
#line 299 "parser.y"
	{
                    }
break;
case 64:
#line 306 "parser.y"
	{
                                    }
break;
case 65:
#line 309 "parser.y"
	{
                                      }
break;
case 66:
#line 312 "parser.y"
	{
                                    }
break;
case 67:
#line 315 "parser.y"
	{
                                    }
break;
case 68:
#line 318 "parser.y"
	{ 
                                    }
break;
case 69:
#line 321 "parser.y"
	{  }
break;
case 70:
#line 323 "parser.y"
	{}
break;
case 71:
#line 325 "parser.y"
	{ }
break;
case 72:
#line 326 "parser.y"
	{ 
                  }
break;
case 73:
#line 329 "parser.y"
	{
                    }
break;
case 74:
#line 339 "parser.y"
	{  
             }
break;
case 75:
#line 340 "parser.y"
	{ 
                             }
break;
case 76:
#line 346 "parser.y"
	{ 
                            }
break;
case 77:
#line 349 "parser.y"
	{ 
                       }
break;
case 78:
#line 352 "parser.y"
	{ 

                                              }
break;
case 79:
#line 362 "parser.y"
	{   
                                    }
break;
case 80:
#line 365 "parser.y"
	{ 
            }
break;
case 81:
#line 370 "parser.y"
	{  
                                }
break;
case 82:
#line 372 "parser.y"
	{  
                                     }
break;
case 83:
#line 377 "parser.y"
	{   
                        }
break;
case 84:
#line 379 "parser.y"
	{ 
            }
break;
case 85:
#line 384 "parser.y"
	{   
                                        }
break;
case 86:
#line 386 "parser.y"
	{ 
                       }
break;
#line 1141 "y.tab.c"
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
