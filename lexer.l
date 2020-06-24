%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    #include "y.tab.h"

    extern void yyerror(char *);

%}

%option yylineno
%option noyywrap
%s COMENTARIO
%x COMENTARIO2

op_rel_igual "=="
op_rel_diferente "<>"
digito [0-9]
entero ({digito})+
exp [Ee][+-]?{entero}
real (({digito})*.({digito})+|({digito})+"."({digito}})*)({exp}?)|({entero}{exp})
flotante ({real}{exp}?|{entero}{exp})[Ff]
num {entero}
id [a-zA-Z_][a-zA-Z_0-9]*
caracter "'"[c\c]"'"
cadena "\""[c\c]*"\""

%%
<INITIAL>ent {
    return ENT;
}
<INITIAL>real {
    return REAL;
}
<INITIAL>dreal {
    return DREAL;
}
<INITIAL>car {
    return CAR;
}                             
<INITIAL>sin {
    return SIN;
}      
<INITIAL>estructura {
    return ESTRUCTURA;
}  
<INITIAL>inicio {
    return INICIO;
}
<INITIAL>fin {
    return FIN;
}
<INITIAL>def {
    return DEF;
}
<INITIAL>si {
    return SI;
}
<INITIAL>entonces {
    return ENTONCES;
}
<INITIAL>sino {
    return SINO;
}
<INITIAL>mientras {
    return MIENTRAS;
}
<INITIAL>hacer {
    return HACER;
}
<INITIAL>segun {
    return SEGUN;
}
<INITIAL>escribir {
    return ESCRIBIR;
}
<INITIAL>leer {
    return LEER;
}
<INITIAL>devolver {
    return DEVOLVER;
}
<INITIAL>terminar {
    return TERMINAR;
}
<INITIAL>caso {
    return CASO;
}
<INITIAL>pred {
    return PRED;
}
<INITIAL>"," {
    return COMA;
}
<INITIAL>":=" {
    return ASIG;
}
<INITIAL>"o" {
    return O;
}
<INITIAL>"y" {
    return Y;
}
<INITIAL>"no" {
    return NO;
}
<INITIAL>{op_rel_igual} {
    return IGUAL;
}
<INITIAL>{op_rel_diferente} {
    return DIFER;
}
<INITIAL>">" {
    return MAYOR_QUE;
}
<INITIAL>">=" {
    return MAYOR_IGUAL_QUE;
}
<INITIAL>"<" {
    return MENOR_QUE;
}
<INITIAL>"<=" {
    return MENOR_IGUAL_QUE;
}
<INITIAL>"+" {
    return SUMA;
}
<INITIAL>"-" {
    return RESTA;
}
<INITIAL>"*" {
    return MULT;
}
<INITIAL>"/" {
    return DIV;
}
<INITIAL>"%" {
    return MOD;
}
<INITIAL>{num} {
    return NUM;
}
<INITIAL>{cadena} {
    return CADENA;
}
<INITIAL>{caracter} {
    return CARACTER;
}
<INITIAL>"verdadero" {
    return VERDADERO;
}
<INITIAL>"falso" {
    return FALSO;
}
<INITIAL>"." {
    return PUNTO;
}
<INITIAL>";" {
    return PUNTO_Y_COMA;
}
<INITIAL>"(" {
    return PAR_ABRE;
}
<INITIAL>")" {
    return PAR_CIERRA;
}
<INITIAL>{id} {
    return ID;
}
<INITIAL>"[" {
    return CORCH_ABRE;
}
<INITIAL>"]" {
    return CORCH_CIERRA;
}
<INITIAL>[ \t\n\r]+ {/*Ignora espacios en blaco*/}
<INITIAL>"/*"       {BEGIN(COMENTARIO);}
<INITIAL>.          {yyerror(yytext);}
<COMENTARIO>[^*/]*  {/*Ignorar comentarios*/}
<COMENTARIO>[*/]    {/*Ignorar comentarios*/}
<COMENTARIO>"*/"    {BEGIN(INITIAL);}
%%
