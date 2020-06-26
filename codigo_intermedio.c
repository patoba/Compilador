#include <stdio.h>
#include <string.h>

#include "codigo_intermedio.h"
#include "cuadruplas.h"

FILE *archivo_destino;

int igual_cad(char* s1, char* s2){
    return strcmp(s1, s2) == 0;
}

void ver_codigo_intermedio(CODE *cuadruplas){
    archivo_destino =stdout;
    CUAD *actual = cuadruplas->head;
    fprintf(archivo_destino, "Codigo Intermedio:\n");
    while(actual!=NULL){
        char* op = actual->op;
        fprintf(archivo_destino, "\t");
        if(igual_cad(op, "+") || igual_cad(op, "-") //falla por ser operador unario
           || igual_cad(op, "*") || igual_cad(op, "/") || igual_cad(op, "%"))
            ci_op_aritmetico(actual);
        else if(igual_cad(op, "+") || igual_cad(op, "-"))
            ci_signo(actual);
        else if(igual_cad(op, ">") || igual_cad(op, "<") || igual_cad(op, ">=") ||
                igual_cad(op, "<=") || igual_cad(op, "==") || igual_cad(op, "<>"))
            ci_salto_condicional(actual);
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
            fprintf(archivo_destino, "error regla no definida");
        fprintf(archivo_destino, "\n");
        actual = actual->next;
    }
    
}

void ci_op_aritmetico(CUAD *op_arit){
    /*
    x = y op z
    (op, y, z, x)
    */
    fprintf(archivo_destino, "%s = %s %s %s", op_arit->res, op_arit->arg1, op_arit->op, op_arit->arg2);
}

void ci_signo(CUAD *signo){
    /*
    Instruccion de asignacion: x = op y     op=+,-
    (op, y, NULL, x)    
    */
   fprintf(archivo_destino, "%s = %s %s/n", signo->res, signo->op, signo->arg1);
}

void ci_goto(CUAD *op_goto){
    /*
    Salto Condicional: goto L
    (goto, NULL, NULL, L)
    */
    fprintf(archivo_destino, "goto %s", op_goto->res);
}

void ci_salto_condicional(CUAD *salto){
    /*
    Salto condicinal if x relop y goto L      relop es un operador relacional
    (relop, x, y, L)
    */
    fprintf(archivo_destino, "if %s %s %s goto %s", salto->arg1, salto->op, salto->arg2, salto->res);
}

void ci_asignacion(CUAD *igual){//no esta definida bien
    if(igual_cad(igual->arg2, "")){
        fprintf(archivo_destino, "%s = %s", igual->res, igual->arg1);
    }else{//cast
        fprintf(archivo_destino, "%s = %s %s", igual->res, igual->arg1, igual->arg2);
    }
    
}

void ci_etiqueta(CUAD *etiqueta){
    /*etiqueta t:
    (etiq, "", "", L)
    */
    fprintf(archivo_destino, "\n%s:", etiqueta->res);
}

void ci_acceder_corch(CUAD *corch){
    /*
        Copia Indexada: x=y[i]
        ([], y, i, x)
    */
   fprintf(archivo_destino, "%s = %s[%s]", corch->res, corch->arg1, corch->arg2);
}
        
void ci_igual_corch(CUAD *corch){
    /*
        Copia Indexada: x[i]=y
        ([]=, i, y, x)
    */
   fprintf(archivo_destino, "%s[%s] = %s", corch->res, corch->arg1, corch->arg2);
}