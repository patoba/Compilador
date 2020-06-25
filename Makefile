 
all: 
	flex lexer.l
	yacc -d parser.y
	gcc lex.yy.c y.tab.c tabla_simbolos.c tabla_tipos.c tipos.c cuadruplas.c backpatch.c pila_dir.c main.c -o main.out
clean:
	rm -f *.yy.c
	rm -f *.tab.h
	rm -f *.tab.c
