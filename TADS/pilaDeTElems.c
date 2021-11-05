#include "pilaDeTElems.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * ACCION: nuevaPilaDeTElems
 * ENTRADA: una pila de tElems
 * REQUISITOS: la pila no esta inicializada
 * SALIDA: Inicializa la pila como una pila de tElems sin elementos
 */
void nuevaPilaDeTElems(PilaDeTElems *p){
	p->cima=-1;
}
/**
 * ACCION: error
 * REQUISITOS:
 * SALIDA: Para la ejecucion tras informar de un error
 */
void errorPilaDeTElems(char s[]){
	printf("\n\n\nERROR en el modulo pilas: %s \n", s);
	while (true)
		exit(-1);
}
/**
 * ACCION: llena
 * REQUISITOS:
 * SALIDA: Devuelve verdadero si la pila esta llena
 */
bool llenaPilaDeTElems(PilaDeTElems p){
	return (p.cima == TAMANIO_PILA_DE_TELEMS -1);
}
/**
 * ACCION: apilarPilaDeTElems
 * ENTRADA: una pila de tElems y un tElem
 * REQUISITOS: la pila esta inicializada y no esta llena
 * MODIFICA: Añade el tElem como la cima de la pila
 */
void apilarPilaDeTElems(PilaDeTElems *p, tElem x){
	if (llenaPilaDeTElems(*p))
		errorPilaDeTElems("Apilando en una pila de tElems llena.");
	p->cima++;
	p->valores[p->cima]=x;
}
/**
 * ACCION: desapilarPilaDeTElems
 * ENTRADA: una pila de tElems
 * REQUISITOS: la pila esta inicializada y no esta vacia
 * MODIFICA: Elimina el elemento mas nuevo de la pila
 */
void desapilarPilaDeTElems(PilaDeTElems *p){
	if (esNulaPilaDeTElems(*p))
		errorPilaDeTElems("Desapilando en una pila de tElems vacia.");
	p->cima--;
}
/**
 * ACCION: cimaPilaDeTElems
 * ENTRADA: una pila de tElems y un tElem
 * REQUISITOS: la pila esta inicializada y no esta vacia
 * MODIFICA: Copia en el tElem el elemento mas nuevo de la pila
 */
void cimaPilaDeTElems (PilaDeTElems p, tElem *x){
	if (esNulaPilaDeTElems(p))
		errorPilaDeTElems("Cima en una pila de tElems vacia.");
	*x = p.valores[p.cima];
}
/**
 * ACCION: esNulaPilaDeTElems
 * ENTRADA: una pila de tElems
 * REQUISITOS: la pila esta inicializada
 * SALIDA: Devuelve true si la pila esta vacia
 */
bool esNulaPilaDeTElems (PilaDeTElems p){
	return (p.cima == -1);
}
