p = 1
all: clean compilar run
clean:
	rm -f Resultados/salida.txt
	rm -f Resultados/CTD.txt
	rm -f Resultados/TS.txt
	rm -f Resultados/TC.txt
	rm -f a.out
	rm -f eaux.o
	rm -f lex.yy.c
	rm -f lex.yy.o
	rm -f parser.output
	rm -f parser.tab.c
	rm -f parser.tab.h
	rm -f tc.o
	rm -f ts.o
compilar:
	bison -v -d parser.y
	flex -i scanner.l
	gcc -c lex.yy.c
	gcc -c ts.c
	gcc -c tc.c
	gcc -c eaux.c
	gcc parser.tab.c lex.yy.o ts.o tc.o eaux.o -ll -lm
runconsole:
	./a.out
run:
	./a.out Programas/programa$(p).alg > Resultados/salida.txt
allconsole: clean compilar runconsole
