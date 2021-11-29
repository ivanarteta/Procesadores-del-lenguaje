#include "cola.h"
#include <stdio.h>
#include <stdlib.h> 

void errorCola(char s[]){
	printf("\n\n\nERROR en el modulo colas:  %s\n", s);
	while (true)
		exit(-1);
}

void nuevaCola(Cola *c){
	c->i = NULL;
	c->f= NULL;
}

void pideTurnoCola(Cola *c, tElem x){
	NodoDeCola * q;
	if ((q=malloc(sizeof(NodoDeCola)))==NULL)
		errorCola("no hay memoria para pideTurno");
	q->e = x;
	q->s = NULL;
	if (c->f == NULL)
		c->i = q;
	else
		c->f->s=q;
	c->f=q;
}

bool esNulaCola(Cola c){
	return (c.i == NULL);
}

void avanceCola(Cola *c){
	NodoDeCola * q;
	if (esNulaCola(*c))
		errorCola("avanzando en cola nula");
	q= c->i;
	c->i = c->i->s;
	if (c->i == NULL)
		c->f = NULL;
	free(q);
}

tElem primeroCola(Cola c){
	if (esNulaCola(c))
		errorCola("primero en cola nula");
	return c.i->e;
}

void imprimirCola(Cola *cola){
	if (!esNulaCola(*cola)){
		NodoDeCola *aux;
		aux = cola->i;
		while(aux->s != NULL){
			printf("%d \n", aux->e);
			aux = aux->s;
		}
		printf("%d \n", aux->e);
	}
}