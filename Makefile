all:
	bison -v -d -t parser.y
	flex scanner.l
	gcc -c lex.yy.c 
	gcc -c tabla_simbolos.c tabla_simbolos.h
	gcc parser.tab.c lex.yy.o tabla_simbolos.o -lfl -lm
	
clean:
	rm lex.yy.c a.out lex.yy.o parser.output parser.tab.c parser.tab.h tabla_simbolos.h.gch tabla_simbolos.o 