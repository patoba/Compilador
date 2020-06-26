#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cuadruplas.h"

CUAD *init_quad() {
    CUAD *new_quad = (CUAD*)malloc(sizeof(CUAD));
    new_quad->op   = NULL;
    new_quad->next = NULL;

    return new_quad;
}

void add_data_quad(CUAD *quad, char *op, char *arg1, char *arg2, char *res) {
    quad->op = op;
    strcpy(quad->arg1, arg1);
    strcpy(quad->arg2, arg2);
    strcpy(quad->res, res);
}

CUAD *crear_cuadrupla(char *op, char *arg1, char *arg2, char *res) {
    CUAD *new_quad = init_quad();
    add_data_quad(new_quad, op, arg1, arg2, res);
    return new_quad;
}

void finish_quad(CUAD *quad){
    free(quad);
}

CODE *init_code() {
    CODE *new_code = (CODE*)malloc(sizeof(CODE));
    new_code->head = NULL;
    new_code->tail = NULL;

    return new_code;
}

void finish_code(CODE *code) {
    free(code);
}

void append_quad(CODE* code, CUAD *quad) {
    if (code->tail == NULL && code->head == NULL) {
        code->head = quad;
        code->tail = quad;
    }
    else {
        code->tail->next = quad;
        code->tail = quad;
    }

    code->tail->next = NULL;
}

void print_code(CODE *code) {
    printf("OP\tARG1\tARG2\tRES\n");
    print_content_code(code->head);
}

void print_content_code(CUAD *head) {
    if (head != NULL) {
        printf("%s\t%s\t%s\t%s\n", head->op, head->arg1, head->arg2, head->res);
        print_content_code(head->next);
    }
}