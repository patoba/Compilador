#ifndef PILA_DIR_H
#define PILA_DIR_H

typedef struct dir DIR;

struct dir {
    int valor;
    DIR *down;
};

typedef struct stack_dir {
    DIR *top;
} SDir;

DIR *create_dir(int valor);

SDir *create_s_dir();

void free_s_dir(SDir *sDir);

void pushSDir(SDir *sDir, int dir);

int popSDir(SDir *sDir);

void print_s_dir(SDir *sDir);

#endif