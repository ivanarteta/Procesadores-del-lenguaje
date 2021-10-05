all:
	flex scanner.l
	gcc lex.yy.c -lfl
	./a.out programa1.alg
	./a.out programa2.alg
	./a.out programa3.alg

clean:
	rm lex.yy.c a.out