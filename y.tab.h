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
extern YYSTYPE yylval;
