#ifndef BACKPATCH_H
#define BACKPATCH_H

#include "cuadruplas.h"

typedef struct index INDEX;

struct index {
    char *indice;
    INDEX *next;
};

typedef struct list_index {
    INDEX *head;
    INDEX *tail;
}LINDEX;

INDEX *init_index(); // Reserva memoria para un nodo índice
void finish_index(INDEX *index); // Libera memoria de un nodo índice

LINDEX *init_list_index(INDEX *index); // Reserva memoria para la lista de índices
void finish_list_index(LINDEX *lista); // Libera la memoria de la lista y de todos los nodos dentro

void append_index(LINDEX *list, INDEX *index); // Agrega un nodo índice al final de la lista

LINDEX *combinar(LINDEX *list1, LINDEX *list2); // Retorna una lista ligada de la concateción de l1 y l2

void backpatch(CODE *code, LINDEX *list, char *label); // Remplaza label en cada aparición de un índice en la cuádruplas del código C

char *new_temporal();
char *nueva_etiqueta();

#endif