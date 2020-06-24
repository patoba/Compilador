#ifndef BACKPATCH_H
#define BACKPATCH_H

#include "cuadruplas.h"

typedef struct index {
    char  *indice;
    INDEX *next;
} INDEX;

typedef struct list_index {
    INDEX *head;
    INDEX *tail;
} LINDEX;

INDEX *init_index(); // Reserva memoria para un nodo índice
void finish_index(INDEX *i); // Libera memoria de un nodo índice

LINDEX *init_list_index(INDEX *i); // Reserva memoria para la lista de índices
void finish_list_index(CODE *c); // Libera la memoria de la lista y de todos los nodos dentro

void append_index(LINDEX *l, INDEX *i); // Agrega un nodo índice al final de la lista

LINDEX *combinar(LINDEX l1, LINDEX l2); // Retorna una lista ligada de la concateción de l1 y l2

void backpatch(CODE *c, LINDEX *l, char *label); // Remplaza label en cada aparición de in índice en la cuádruplas del código C

#endif