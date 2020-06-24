#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipos.h"
#include "cuadruplas.h"
#include "tabla_tipos.h"
extern TSTACK *STT;

/*
 * Recibe dos tipos, cada uno es su índice hacia la tabla de tipos en la cima de la pila
 * Si el primero es más chico que el segundo, genera la cuádrupla
 * para realizar la ampliación del tipo.
 * Retorna la nueva dirección generada por la ampliación
 * o la dirección original en caso de que no se realice
 */
char *ampliar (char *dir, int t1, int t2, CODE *code) {
    int tipo_min = min(t1, t2);
    
    if (t1 == t2 || t2 == tipo_min) return dir;
    else {
        TYPTAB *top = getTopType(STT);
        TYP *tipo = search_type(top, tipo_min);
        char *LPAR = "(";
        char *RPAR = ")";

        CUAD *new_quad = init_quad();
        char *new_dir = new_temporal();

        add_data_quad(new_quad, "=", strcat(LPAR, strcat(tipo->nombre, RPAR)), dir, new_dir);
        append_quad(code, new_quad);

        return new_dir;
    }
}

/*
 * Recibe dos tipos, cada uno es su índice hacia la tabla de tipos en la cima de la pila
 * Si el primero es más grande que el segundo, genera la cuádrupla
 * para realizar la reducción del tipo.
 * Retorna la nueva dirección generada por la reducción
 * o la dirección original en caso de que no se realice
 */
char *reducir(char *dir, int t1, int t2, CODE *code) {
    int tipo_max = max(t1, t2);

    if (t1 == t2 || t1 == tipo_max) return dir;
    else {
        TYPTAB *top = getTopType(STT);
        TYP *tipo = search_type(top, tipo_max);
        char *LPAR = "(";
        char *RPAR = ")";

        CUAD *new_quad = init_quad();
        char *new_dir = new_temporal();

        add_data_quad(new_quad, "=", strcat(LPAR, strcat(tipo->nombre, RPAR)), dir, new_dir);
        append_quad(code, new_quad);

        return new_dir;
    }
}

/*
 * Recibe dos tipos, cada uno es índice hacia la tabla de tipos en la cima de la pila
 * retorna el índice de mayor dimensión
 */
int max(int t1, int t2) {
    if (t1 == t2) return t1;

    TYPTAB *top = getTopType(STT);

    TYP *tipo1 = search_type(top, t1);
    TYP *tipo2 = search_type(top, t2);

    if (tipo1->tam < tipo2->tam) {
        return t2;
    } else {
        return t1;
    }
}

/*
 * Recibe dos tipos, cada uno es índice hacia la tabla de tipos en la cima de la pila
 * retorna el índice de menor dimensión
 */
int min(int t1, int t2) {
    if (t1 == t2) return t1;

    TYPTAB *top = getTopType(STT);

    TYP *tipo1 = search_type(top, t1);
    TYP *tipo2 = search_type(top, t2);

    if (tipo1->tam > tipo2->tam) {
        return t2;
    } else {
        return t1;
    }
}

