#include "cuadruplas.h"

int igual_cad(char* s1, char* s2);

void ver_codigo_intermedio(CODE *cuadruplas);

void ci_op_aritmetico(CUAD *op_arit);

void ci_signo(CUAD *signo);

void ci_goto(CUAD *op_goto);
void ci_salto_condicional(CUAD *salto);

void ci_asignacion(CUAD *igual);

void ci_etiqueta(CUAD *etiqueta);

void ci_acceder_corch(CUAD *);
        
void ci_igual_corch(CUAD *);