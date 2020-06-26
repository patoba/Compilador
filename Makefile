 
all: 
	flex lexer.l
	yacc -d parser.y
	gcc codigo_intermedio.c lex.yy.c y.tab.c tabla_simbolos.c tabla_tipos.c tipos.c cuadruplas.c backpatch.c pila_dir.c main.c -ggdb -o main.out
clean:
	rm -f *.yy.c
	rm -f *.tab.h
	rm -f *.tab.c
