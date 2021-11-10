all:
	bison -v -d -t parser.y
	flex scanner.l
	gcc -c lex.yy.c 
	gcc parser.tab.c lex.yy.o -lfl -lm
	
clean:
	rm lex.yy.c a.out lex.yy.o parser.output parser.tab.c parser.tab.h