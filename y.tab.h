/* A Bison parser, made by GNU Bison 3.6.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ESTRUCTURA = 258,              /* ESTRUCTURA  */
    INICIO = 259,                  /* INICIO  */
    FIN = 260,                     /* FIN  */
    DEF = 261,                     /* DEF  */
    SI = 262,                      /* SI  */
    ENTONCES = 263,                /* ENTONCES  */
    SINO = 264,                    /* SINO  */
    MIENTRAS = 265,                /* MIENTRAS  */
    HACER = 266,                   /* HACER  */
    SEGUN = 267,                   /* SEGUN  */
    ESCRIBIR = 268,                /* ESCRIBIR  */
    LEER = 269,                    /* LEER  */
    DEVOLVER = 270,                /* DEVOLVER  */
    TERMINAR = 271,                /* TERMINAR  */
    CASO = 272,                    /* CASO  */
    PRED = 273,                    /* PRED  */
    ENT = 274,                     /* ENT  */
    REAL = 275,                    /* REAL  */
    DREAL = 276,                   /* DREAL  */
    CAR = 277,                     /* CAR  */
    SIN = 278,                     /* SIN  */
    VERDADERO = 279,               /* VERDADERO  */
    FALSO = 280,                   /* FALSO  */
    NUM = 281,                     /* NUM  */
    ID = 282,                      /* ID  */
    CARACTER = 283,                /* CARACTER  */
    CADENA = 284,                  /* CADENA  */
    COMA = 285,                    /* COMA  */
    ASIG = 286,                    /* ASIG  */
    O = 287,                       /* O  */
    Y = 288,                       /* Y  */
    IGUAL = 289,                   /* IGUAL  */
    DIFER = 290,                   /* DIFER  */
    MAYOR_QUE = 291,               /* MAYOR_QUE  */
    MAYOR_IGUAL_QUE = 292,         /* MAYOR_IGUAL_QUE  */
    MENOR_QUE = 293,               /* MENOR_QUE  */
    MENOR_IGUAL_QUE = 294,         /* MENOR_IGUAL_QUE  */
    SUMA = 295,                    /* SUMA  */
    RESTA = 296,                   /* RESTA  */
    MULT = 297,                    /* MULT  */
    DIV = 298,                     /* DIV  */
    MOD = 299,                     /* MOD  */
    NO = 300,                      /* NO  */
    PUNTO = 301,                   /* PUNTO  */
    DOS_PUNTOS = 302,              /* DOS_PUNTOS  */
    PAR_ABRE = 303,                /* PAR_ABRE  */
    PAR_CIERRA = 304,              /* PAR_CIERRA  */
    CORCH_ABRE = 305,              /* CORCH_ABRE  */
    CORCH_CIERRA = 306,            /* CORCH_CIERRA  */
    PUNTO_Y_COMA = 307             /* PUNTO_Y_COMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ESTRUCTURA 258
#define INICIO 259
#define FIN 260
#define DEF 261
#define SI 262
#define ENTONCES 263
#define SINO 264
#define MIENTRAS 265
#define HACER 266
#define SEGUN 267
#define ESCRIBIR 268
#define LEER 269
#define DEVOLVER 270
#define TERMINAR 271
#define CASO 272
#define PRED 273
#define ENT 274
#define REAL 275
#define DREAL 276
#define CAR 277
#define SIN 278
#define VERDADERO 279
#define FALSO 280
#define NUM 281
#define ID 282
#define CARACTER 283
#define CADENA 284
#define COMA 285
#define ASIG 286
#define O 287
#define Y 288
#define IGUAL 289
#define DIFER 290
#define MAYOR_QUE 291
#define MAYOR_IGUAL_QUE 292
#define MENOR_QUE 293
#define MENOR_IGUAL_QUE 294
#define SUMA 295
#define RESTA 296
#define MULT 297
#define DIV 298
#define MOD 299
#define NO 300
#define PUNTO 301
#define DOS_PUNTOS 302
#define PAR_ABRE 303
#define PAR_CIERRA 304
#define CORCH_ABRE 305
#define CORCH_CIERRA 306
#define PUNTO_Y_COMA 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "parser.y"


    struct {
        ARGS *lista;
        int num;
    } lista;

    struct {
        int type;
        char dir[50];
    } tipo;

    struct {
        bool code_est;
        char dir[50];
        int type;
        int base;
        char des[50];
    } variable;

    struct {
        int base;
    } base;

    struct {
        LINDEX *truelist;
        LINDEX *falselist;
        LINDEX *nexlist;
        LINDEX *prueba;
    } lista_indices;

#line 202 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
