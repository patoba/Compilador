/* A Bison parser, made by GNU Bison 3.6.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
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

//funciones acciones EdT
void agregar_sym_var(char *id);


//variables globales
TSTACK *STT;
SSTACK *STS;
int dir;
int typeGBL, baseGBL;
//vector<int> SDir;

#line 101 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 31 "parser.y"


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

#line 289 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ESTRUCTURA = 3,                 /* ESTRUCTURA  */
  YYSYMBOL_INICIO = 4,                     /* INICIO  */
  YYSYMBOL_FIN = 5,                        /* FIN  */
  YYSYMBOL_DEF = 6,                        /* DEF  */
  YYSYMBOL_SI = 7,                         /* SI  */
  YYSYMBOL_ENTONCES = 8,                   /* ENTONCES  */
  YYSYMBOL_SINO = 9,                       /* SINO  */
  YYSYMBOL_MIENTRAS = 10,                  /* MIENTRAS  */
  YYSYMBOL_HACER = 11,                     /* HACER  */
  YYSYMBOL_SEGUN = 12,                     /* SEGUN  */
  YYSYMBOL_ESCRIBIR = 13,                  /* ESCRIBIR  */
  YYSYMBOL_LEER = 14,                      /* LEER  */
  YYSYMBOL_DEVOLVER = 15,                  /* DEVOLVER  */
  YYSYMBOL_TERMINAR = 16,                  /* TERMINAR  */
  YYSYMBOL_CASO = 17,                      /* CASO  */
  YYSYMBOL_PRED = 18,                      /* PRED  */
  YYSYMBOL_ENT = 19,                       /* ENT  */
  YYSYMBOL_REAL = 20,                      /* REAL  */
  YYSYMBOL_DREAL = 21,                     /* DREAL  */
  YYSYMBOL_CAR = 22,                       /* CAR  */
  YYSYMBOL_SIN = 23,                       /* SIN  */
  YYSYMBOL_VERDADERO = 24,                 /* VERDADERO  */
  YYSYMBOL_FALSO = 25,                     /* FALSO  */
  YYSYMBOL_NUM = 26,                       /* NUM  */
  YYSYMBOL_ID = 27,                        /* ID  */
  YYSYMBOL_CARACTER = 28,                  /* CARACTER  */
  YYSYMBOL_CADENA = 29,                    /* CADENA  */
  YYSYMBOL_COMA = 30,                      /* COMA  */
  YYSYMBOL_ASIG = 31,                      /* ASIG  */
  YYSYMBOL_O = 32,                         /* O  */
  YYSYMBOL_Y = 33,                         /* Y  */
  YYSYMBOL_IGUAL = 34,                     /* IGUAL  */
  YYSYMBOL_DIFER = 35,                     /* DIFER  */
  YYSYMBOL_MAYOR_QUE = 36,                 /* MAYOR_QUE  */
  YYSYMBOL_MAYOR_IGUAL_QUE = 37,           /* MAYOR_IGUAL_QUE  */
  YYSYMBOL_MENOR_QUE = 38,                 /* MENOR_QUE  */
  YYSYMBOL_MENOR_IGUAL_QUE = 39,           /* MENOR_IGUAL_QUE  */
  YYSYMBOL_SUMA = 40,                      /* SUMA  */
  YYSYMBOL_RESTA = 41,                     /* RESTA  */
  YYSYMBOL_MULT = 42,                      /* MULT  */
  YYSYMBOL_DIV = 43,                       /* DIV  */
  YYSYMBOL_MOD = 44,                       /* MOD  */
  YYSYMBOL_NO = 45,                        /* NO  */
  YYSYMBOL_PUNTO = 46,                     /* PUNTO  */
  YYSYMBOL_DOS_PUNTOS = 47,                /* DOS_PUNTOS  */
  YYSYMBOL_PAR_ABRE = 48,                  /* PAR_ABRE  */
  YYSYMBOL_PAR_CIERRA = 49,                /* PAR_CIERRA  */
  YYSYMBOL_CORCH_ABRE = 50,                /* CORCH_ABRE  */
  YYSYMBOL_CORCH_CIERRA = 51,              /* CORCH_CIERRA  */
  YYSYMBOL_PUNTO_Y_COMA = 52,              /* PUNTO_Y_COMA  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_programa = 54,                  /* programa  */
  YYSYMBOL_55_1 = 55,                      /* $@1  */
  YYSYMBOL_declaraciones = 56,             /* declaraciones  */
  YYSYMBOL_57_2 = 57,                      /* $@2  */
  YYSYMBOL_58_3 = 58,                      /* $@3  */
  YYSYMBOL_tipo_registro = 59,             /* tipo_registro  */
  YYSYMBOL_60_4 = 60,                      /* $@4  */
  YYSYMBOL_61_5 = 61,                      /* $@5  */
  YYSYMBOL_tipo = 62,                      /* tipo  */
  YYSYMBOL_63_6 = 63,                      /* $@6  */
  YYSYMBOL_base = 64,                      /* base  */
  YYSYMBOL_tipo_arreglo = 65,              /* tipo_arreglo  */
  YYSYMBOL_lista_var = 66,                 /* lista_var  */
  YYSYMBOL_funciones = 67                  /* funciones  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   28

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  23
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  37

#define YYMAXUTOK   307


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   107,   107,   107,   127,   127,   128,   128,   129,   134,
     135,   134,   140,   140,   143,   144,   145,   146,   147,   152,
     167,   173,   177,   188
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ESTRUCTURA", "INICIO",
  "FIN", "DEF", "SI", "ENTONCES", "SINO", "MIENTRAS", "HACER", "SEGUN",
  "ESCRIBIR", "LEER", "DEVOLVER", "TERMINAR", "CASO", "PRED", "ENT",
  "REAL", "DREAL", "CAR", "SIN", "VERDADERO", "FALSO", "NUM", "ID",
  "CARACTER", "CADENA", "COMA", "ASIG", "O", "Y", "IGUAL", "DIFER",
  "MAYOR_QUE", "MAYOR_IGUAL_QUE", "MENOR_QUE", "MENOR_IGUAL_QUE", "SUMA",
  "RESTA", "MULT", "DIV", "MOD", "NO", "PUNTO", "DOS_PUNTOS", "PAR_ABRE",
  "PAR_CIERRA", "CORCH_ABRE", "CORCH_CIERRA", "PUNTO_Y_COMA", "$accept",
  "programa", "$@1", "declaraciones", "$@2", "$@3", "tipo_registro", "$@4",
  "$@5", "tipo", "$@6", "base", "tipo_arreglo", "lista_var", "funciones", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
#endif

#define YYPACT_NINF (-45)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -45,     3,     5,   -45,     0,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,   -45,   -22,   -22,   -44,     5,
     -45,   -30,   -29,   -19,   -45,   -45,   -18,     5,     5,   -39,
       8,   -45,   -45,   -45,   -44,   -45,   -45
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     8,     1,     0,    14,    15,    16,    17,    18,
      23,     6,     4,    12,     9,     3,     0,     0,    20,     8,
      22,     0,     0,     0,    13,    10,     0,     8,     8,     0,
       0,    21,     7,     5,    20,    11,    19
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -45,   -45,   -45,   -17,   -45,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,   -20,    -2,   -45
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    10,    17,    16,    11,    19,    30,    12,
      18,    13,    24,    21,    15
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      26,    26,    25,     3,    14,    20,    23,    29,     4,    31,
      32,    33,    34,    35,    36,    22,     0,     0,     0,     0,
       0,     0,    27,    28,     5,     6,     7,     8,     9
};

static const yytype_int8 yycheck[] =
{
      30,    30,    19,     0,     4,    27,    50,    26,     3,    27,
      27,    28,    51,     5,    34,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    52,    19,    20,    21,    22,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    54,    55,     0,     3,    19,    20,    21,    22,    23,
      56,    59,    62,    64,     4,    67,    58,    57,    63,    60,
      27,    66,    66,    50,    65,    56,    30,    52,    52,    26,
      61,    27,    56,    56,    51,     5,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    55,    54,    57,    56,    58,    56,    56,    60,
      61,    59,    63,    62,    64,    64,    64,    64,    64,    65,
      65,    66,    66,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     0,     5,     0,     5,     0,     0,
       0,     6,     0,     3,     1,     1,     1,     1,     1,     4,
       0,     3,     1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

<<<<<<< HEAD
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
=======
#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)
>>>>>>> fc0fbcf9f8d87e33440c95385c232a0b8922c840

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;


  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
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
#line 1377 "y.tab.c"
    break;

  case 3:
#line 119 "parser.y"
                                   {
                                    //$$.codigo = $3.codigo;
                                    print_stack_tab_type(STT);
                                    //printf("aqui");
                                    //printf("%d\n", STT->top.);
                                    print_stack_tab_sym(STS);
                                    }
#line 1389 "y.tab.c"
    break;

  case 4:
#line 127 "parser.y"
                   {typeGBL = (yyvsp[0].tipo).type;}
#line 1395 "y.tab.c"
    break;

  case 6:
#line 128 "parser.y"
                            {typeGBL= (yyvsp[0].tipo).type;}
#line 1401 "y.tab.c"
    break;

  case 8:
#line 129 "parser.y"
               {}
#line 1407 "y.tab.c"
    break;

  case 9:
#line 134 "parser.y"
                                {  
                                   }
#line 1414 "y.tab.c"
    break;

  case 10:
#line 135 "parser.y"
                                                  {
                                                    }
#line 1421 "y.tab.c"
    break;

  case 11:
#line 136 "parser.y"
                                                          {
                                                        
                                                    }
#line 1429 "y.tab.c"
    break;

  case 12:
#line 140 "parser.y"
          {baseGBL = (yyvsp[0].base).base;}
#line 1435 "y.tab.c"
    break;

  case 13:
#line 140 "parser.y"
                                           {(yyval.tipo).type = (yyvsp[0].tipo).type;}
#line 1441 "y.tab.c"
    break;

  case 14:
#line 143 "parser.y"
         {(yyval.base).base = getId(getGlobal(STT), "ent");}
#line 1447 "y.tab.c"
    break;

  case 15:
#line 144 "parser.y"
          {(yyval.base).base = getId(getGlobal(STT), "real");}
#line 1453 "y.tab.c"
    break;

  case 16:
#line 145 "parser.y"
           {(yyval.base).base = getId(getGlobal(STT), "dreal");}
#line 1459 "y.tab.c"
    break;

  case 17:
#line 146 "parser.y"
         {(yyval.base).base = getId(getGlobal(STT), "car");}
#line 1465 "y.tab.c"
    break;

  case 18:
#line 147 "parser.y"
         {(yyval.base).base = getId(getGlobal(STT), "sin");}
#line 1471 "y.tab.c"
    break;

  case 19:
#line 152 "parser.y"
<<<<<<< HEAD
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
=======
                                                      {
                                                        if((yyvsp[-2].tipo).type == getId(getGlobal(STT), "ent")){
                                                            int temp_dir = atoi((yyvsp[-2].tipo).dir);
                                                            if(temp_dir > 0){ //dir debe ser entero
                                                                TB* tipo_base = crear_tipo_basado((yyvsp[0].tipo).type);
                                                                TYP *nuevo = crear_type("array", (yyvsp[-2].tipo).type, tipo_base);
                                                                append_type(getTopType(STT), nuevo);
                                                                (yyval.tipo).type = nuevo->id;
                                                            }else{
                                                                yyerror("El indice debe ser mayor a cero");
                                                            }
                                                        }else{
                                                            yyerror("El indice debe ser tipo entero\n");
                                                        }
>>>>>>> fc0fbcf9f8d87e33440c95385c232a0b8922c840
                                                      }
#line 1491 "y.tab.c"
    break;

  case 20:
#line 167 "parser.y"
              {(yyval.tipo).type=baseGBL;}
#line 1497 "y.tab.c"
    break;

  case 21:
#line 173 "parser.y"
<<<<<<< HEAD
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
=======
                             {  
                                //printf("%s", $3.dir);
                                agregar_sym_var((yyvsp[0].tipo).dir);
                             }
#line 1506 "y.tab.c"
    break;

  case 22:
#line 177 "parser.y"
                 {
                    //char *id = $1.dir;
                    agregar_sym_var((yyvsp[0].tipo).dir);
                 }
#line 1515 "y.tab.c"
    break;

  case 23:
#line 188 "parser.y"
              {}
#line 1521 "y.tab.c"
    break;


#line 1525 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
>>>>>>> fc0fbcf9f8d87e33440c95385c232a0b8922c840
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 373 "parser.y"

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
