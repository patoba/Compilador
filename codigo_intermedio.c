#include <stdio.h>
#include <string.h>

#include "codigo_intermedio.h"
#include "cuadruplas.h"

int igual_cad(char* s1, char* s2){
    return strcmp(s1, s2) == 0;
}

void codigo_intermedio(CODE *cuadruplas){
    CUAD *actual = cuadruplas->head;
    while(actual!=NULL){
        char* op = actual->op;
        sprintf(stdout, "\t");
        if(igual_cad(op, "+") || igual_cad(op, "-") //falla por ser operador unario
           || igual_cad(op, "*") || igual_cad(op, "/") || igual_cad(op, "%"))
            ci_op_aritmetico(actual);
        else if(igual_cad(op, "+") || igual_cad(op, "-"))
            ci_signo(actual);
        else if(igual_cad(op, "goto"))
            ci_goto(actual);
        else if(igual_cad(op, ":="))
            ci_asignacion(actual);
        else if(igual_cad(op, "etiq"))
            ci_etiqueta(actual);
        else if(igual_cad(op, "[]"))
            ci_acceder_corch(actual);
        else if(igual_cad(op, "[]="))
            ci_igual_corch(actual);
        else 
            sprintf(stdout, "error regla no definida");
        sprintf(stdout, "\n");
        actual = actual->next;
    }
    
}

void ci_op_aritmetico(CUAD *op_arit){
    /*
    x = y op z
    (op, y, z, x)
    */
    sprintf(stdout, "%s %s %s %s", op_arit->res, op_arit->arg1, op_arit->op, op_arit->arg2);
}

void ci_signo(CUAD *signo){
    /*
    Instruccion de asignacion: x = op y     op=+,-
    (op, y, NULL, x)    
    */
   sprintf(stdout, "%s %s %s/n", signo->res, signo->op, signo->arg1);
}

void ci_goto(CUAD *op_goto){
    /*
    Salto Condicional: goto L
    (goto, NULL, NULL, L)
    */
    sprintf(stdout, "goto %s", op_goto->res);
}

void ci_salto_condicional(CUAD *salto){
    /*
    Salto condicinal if x relop y goto L      relop es un operador relacional
    (relop, x, y, L)
    */
    sprintf(stdout, "if %s %s %s goto %s", salto->arg1, salto->op, salto->arg2, salto->res);
}

void ci_asignacion(CUAD *igual){//no esta definida bien
    if(igual_cad(igual->arg2, "")){
        sprintf(stdout, "%s = %s", igual->res, igual->arg1);
    }else{//cast
        sprintf(stdout, "%s = %s %s", igual->res, igual->arg1, igual->arg2);
    }
    
}

void ci_etiqueta(CUAD *etiqueta){
    /*etiqueta t:
    (etiq, "", "", L)
    */
    sprintf(stdout, "\n%s:", etiqueta->res);
}

void ci_acceder_corch(CUAD *corch){
    /*
        Copia Indexada: x=y[i]
        ([], y, i, x)
    */
   sprintf(stdout, "%s = %s[%s]", corch->res, corch->arg1, corch->arg2);
}
        
void ci_igual_corch(CUAD *corch){
    /*
        Copia Indexada: x[i]=y
        ([]=, i, y, x)
    */
   sprintf(stdout, "%s[%s] = %s", corch->res, corch->arg1, corch->arg2);
}