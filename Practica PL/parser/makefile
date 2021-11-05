all:
	bison -v  -d parser.y
	flex scanner.l
	gcc -c lex.yy.c 
	gcc  -c tablaSimbolos.c tablaSimbolos.h
	gcc -c tablaCuadruplas.c tablaCuadruplas.h
	gcc parser.tab.c lex.yy.o tablaSimbolos.o tablaCuadruplas.o -lfl -lm
clean:
	rm tablaCuadruplas.o tablaCuadruplas.h.gch tablaSimbolos.o tablaSimbolos.h.gch lex.yy.c paser.tab.h parser.tab.c a.out parser.output

