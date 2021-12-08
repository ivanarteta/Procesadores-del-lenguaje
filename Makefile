all:
	bison -v -d -t parser.y
	flex scanner.l
	gcc -c lex.yy.c 
	gcc -c tabla_simbolos.c tabla_simbolos.h -Wall
	gcc -c tabla_cuadruplas.c tabla_cuadruplas.h -Wall
	gcc -c codigo_tres_direcciones.c codigo_tres_direcciones.h -Wall
	gcc -c cola.c cola.h -Wall
	gcc -c pila.c pila.h -Wall
	gcc cola.o pila.o parser.tab.c lex.yy.o tabla_simbolos.o tabla_cuadruplas.o codigo_tres_direcciones.o -lfl -lm -Wall
	
clean:
	rm lex.yy.c a.out lex.yy.o parser.output parser.tab.c parser.tab.h 
	rm tabla_simbolos.h.gch tabla_simbolos.o cola.h.gch cola.o tabla_cuadruplas.h.gch 
	rm tabla_cuadruplas.o pila.o pila.h.gch codigo_tres_direcciones.o codigo_tres_direcciones.h.gch