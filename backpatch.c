#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "backpatch.h"

INDEX *init_index() {
    static int indices = 0;
    char final[6];
    INDEX *index = (INDEX*)malloc(sizeof(INDEX));

    sprintf(final, "i%d", indices++);
    index->indice =  final; // Tenemos un problema
    index->next = NULL;

    return index;
}

void finish_index(INDEX *index) {
    free(index);
}

LINDEX *init_list_index(INDEX *index) {
    LINDEX *list_index = (LINDEX*)malloc(sizeof(LINDEX));

    if (index != NULL) {
        list_index->head = NULL;
        list_index->tail = NULL;
        append_index(list_index, index);
    }
    else {
        exit(EXIT_FAILURE);
    }

    return list_index;
}

void finish_list_index(LINDEX *lista) {
    free(lista);
}

void append_index(LINDEX *list, INDEX *index) {
    if (list->tail == NULL && list->head == NULL) {
        list->head = index;
        list->tail = index;
    }
    else {
        list->tail->next = index;
        list->tail = index;
    }

    list->tail->next = NULL;
}

LINDEX *combinar(LINDEX *list1, LINDEX *list2) {
    LINDEX *new_list = (LINDEX*)malloc(sizeof(LINDEX));

    list1->tail->next = list2->head;

    new_list->head = list1->head;
    new_list->tail = list2->tail;

    finish_list_index(list1);
    finish_list_index(list2);

    return new_list;
}

void backpatch(CODE *code, LINDEX *list, char *label) {
    CUAD  *temp_quad = code->head;
    INDEX *temp_index;
    
    while(temp_quad->next != NULL) {
        temp_index = list->head;
        while(temp_index != NULL) {
            if (strcmp(temp_index->indice, temp_quad->res) == 0) {
                strcpy(temp_quad->res, label);
            }
            temp_index = temp_index->next;
        }
        temp_quad = temp_quad->next;
    }
}

char *new_temporal() {
    static int temp = 0;
    char *final = (char *)malloc(sizeof(char) * 6);

    sprintf(final, "t%d", temp++);

    return final;
}