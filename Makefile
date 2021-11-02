all:
	bison -v -d parser.y
	flex scanner.l
	gcc lex.yy.c
	gcc parser.tab.c lex.yy.o -lfl -lm
	
clean:
	rm lex.yy.c a.out lex.yy.o parser.output parser.tab.c parser.tab.h