#include "colaDeTElems.h"
#include <stdio.h>
#include <stdlib.h> 
/**
 * ACCION: error
 * REQUISITOS:
 * SALIDA: Para la ejecucion tras informar de un error
 */
void errorColaDeTElems(char s[]){
	printf("\n\n\nERROR en el modulo colas:  %s\n", s);
	while (true)
		exit(-1);
}
/**
 * ACCION: nuevaColaDeTElems
 * ENTRADA: una cola de tElems
 * REQUISITOS: la cola no esta inicializada
 * SALIDA: Inicializa la cola como una cola de tElems sin elementos
 */
void nuevaColaDeTElems(ColaDeTElems *c){
	c->i = NULL;
	c->f= NULL;
}
/**
 * ACCION: pideTurnoColaDeTElems
 * ENTRADA: una cola de tElems y un tElem
 * REQUISITOS: la cola esta inicializada y no esta llena
 * MODIFICA: Añade el tElem como el ultimo valor de la cola
 */
void pideTurnoColaDeTElems(ColaDeTElems *c, tElem x){
	NodoDeColaDeTElems * q;
	if ((q=malloc(sizeof(NodoDeColaDeTElems)))==NULL)
		errorColaDeTElems("no hay memoria para pideTurno");
	q->e = x;
	q->s = NULL;
	if (c->f == NULL)
		c->i = q;
	else
		c->f->s=q;
	c->f=q;
}
/**
 * ACCION: esNulaColaDeTElems
 * ENTRADA: una cola de tElems
 * REQUISITOS: la cola esta inicializada
 * SALIDA: Devuelve true si la cola esta vacia
 */
bool esNulaColaDeTElems(ColaDeTElems c){
	return (c.i == NULL);
}
/**
 * ACCION: avanceColaDeTElems
 * ENTRADA: una cola de tElems
 * REQUISITOS: la cola esta inicializada y no esta vacia
 * MODIFICA: Elimina el elemento mas antiguo de la cola
 */
void avanceColaDeTElems(ColaDeTElems *c){
	NodoDeColaDeTElems * q;
	if (esNulaColaDeTElems(*c))
		errorColaDeTElems("avanzando en cola nula");
	q= c->i;
	c->i = c->i->s;
	if (c->i == NULL)
		c->f = NULL;
	free(q);
}
/**
 * ACCION: primeroColaDeTElems
 * ENTRADA: una cola de tElems y un tElem
 * REQUISITOS: la cola esta inicializada y no esta vacia
 * MODIFICA: Copia en el tElem el elemento mas antiguo de la cola
 */
void primeroColaDeTElems(ColaDeTElems c, tElem *x){
	if (esNulaColaDeTElems(c))
		errorColaDeTElems("primero en cola nula");
	*x = c.i->e;
}