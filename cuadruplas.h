#ifndef CUADRUPLAS_H
#define CUADRUPLAS_H

typedef struct cuad CUAD;

struct cuad{
	char *op;
	char *arg1;
	char *arg2;
	char *res;
	CUAD *next;
};

typedef struct code{
	CUAD *head;
	CUAD *tail;
}CODE;

CUAD *init_quad(); // Reserva memoria para una cuádrupla
void finish_quad(CUAD *c); // Libera la memoria de una cuádrupla

CODE *init_code(); // Reserva memoria para el código
void finish_code(CODE *c); // Libera la memoria de la lista ligada del código

void append_quad(CODE* c, CUAD *cd); // Agrega una cuádrupla al final de la lista

#endif
