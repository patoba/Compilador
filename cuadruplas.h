#ifndef CUADRUPLAS_H
#define CUADRUPLAS_H

typedef struct cuad CUAD;

struct cuad{
	char *op;
	char arg1[50];
	char arg2[50];
	char res[50];
	CUAD *next;
};

typedef struct code{
	CUAD *head;
	CUAD *tail;
} CODE;

CUAD *init_quad(); // Reserva memoria para una cuádrupla
CUAD *crear_cuadrupla(char *op, char *arg1, char *arg2, char *res);

void add_data_quad(CUAD *quad, char *op, char *arg1, char *arg2, char *res); // Llena el quad
void finish_quad(CUAD *quad); // Libera la memoria de una cuádrupla

CODE *init_code(); // Reserva memoria para el código
void finish_code(CODE *code); // Libera la memoria de la lista ligada del código

void append_quad(CODE* code, CUAD *quad); // Agrega una cuádrupla al final de la lista

void print_code(CODE *code);
void print_content_code(CUAD *code);

#endif
