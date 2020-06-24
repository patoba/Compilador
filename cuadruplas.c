#include <stdio.h>
#include <stdlib.h>

#include "cuadruplas.h"

CUAD *init_quad() {
    CUAD *new_quad = (CUAD*)malloc(sizeof(CUAD));
    new_quad->op   = NULL;
    new_quad->arg1 = NULL;
    new_quad->arg2 = NULL;
    new_quad->next = NULL;
    new_quad->res  = NULL;

    return new_quad;
}

void add_data_quad(CUAD *quad, char *op, char *arg1, char *arg2, char *res) {
    quad->op = op;
    quad->arg1 = arg1;
    quad->arg2 = arg2;
    quad->res = res;
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