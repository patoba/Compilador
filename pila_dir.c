#include <stdio.h>
#include <stdlib.h>

#include "pila_dir.h"

DIR *create_dir(int valor) {
    DIR *direccion = (DIR*)malloc(sizeof(DIR));

    direccion->valor = valor;
    direccion->down = NULL;

    return direccion;
}

SDir *create_s_dir() {
    SDir *s_dir = (SDir*)malloc(sizeof(SDir));

    s_dir->top = NULL;

    return s_dir;
}

void free_s_dir(SDir *sDir) {
    DIR *actual_dir;

    while(sDir->top != NULL) {
        actual_dir = sDir->top;
        sDir->top = actual_dir->down;
        free(actual_dir);
    }

    free(sDir);
}

void pushSDir(SDir *sDir, int dir) {
    DIR *new_dir = create_dir(dir);
    if(sDir->top == NULL) {
        new_dir->down = NULL;
    }
    else {
        new_dir->down = sDir->top;
    }
    sDir->top = new_dir;
}

int popSDir(SDir *sDir) {
    DIR *temp_dir = sDir->top;
    sDir->top = temp_dir->down;
    
    int valor = temp_dir->valor;
    free(temp_dir);

    return valor;
}

void print_s_dir(SDir *sDir) {
    DIR *actual_dir = sDir->top;

    while(actual_dir != NULL) {
        printf("%d\n", actual_dir->valor);
        actual_dir = actual_dir->down;
    }
}
