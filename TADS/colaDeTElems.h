#ifndef FFF_COLA_DE_TELEMS_H
#define FFF_COLA_DE_TELEMS_H
#include <stdbool.h> 
typedef int tElem;
typedef struct nodoDeColaDeTElems{
	tElem e;
	struct nodoDeColaDeTElems *s;
}NodoDeColaDeTElems;

typedef struct colaDeEnteros{
	NodoDeColaDeTElems *i;
	NodoDeColaDeTElems *f;
}ColaDeTElems;

/**
 * ACCION: nuevaColaDeTElems
 * ENTRADA: una cola de tElems
 * REQUISITOS: la cola no esta inicializada
 * SALIDA: Inicializa la cola como una cola de tElems sin elementos
 */
void nuevaColaDeTElems(ColaDeTElems *);
/**
 * ACCION: pideTurnoColaDeTElems
 * ENTRADA: una cola de tElems y un tElem
 * REQUISITOS: la cola esta inicializada y no esta llena
 * MODIFICA: Añade el tElem como el ultimo valor de la cola
 */
void pideTurnoColaDeTElems(ColaDeTElems *, tElem);
/**
 * ACCION: avanceColaDeTElems
 * ENTRADA: una cola de tElems
 * REQUISITOS: la cola esta inicializada y no esta vacia
 * MODIFICA: Elimina el elemento mas antiguo de la cola
 */
void avanceColaDeTElems(ColaDeTElems *);
/**
 * ACCION: primeroColaDeTElems
 * ENTRADA: una cola de tElems y un tElem
 * REQUISITOS: la cola esta inicializada y no esta vacia
 * MODIFICA: Copia en el tElem el elemento mas antiguo de la cola
 */
void primeroColaDeTElems(ColaDeTElems, tElem *);
/**
 * ACCION: esNulaColaDeTElems
 * ENTRADA: una cola de tElems
 * REQUISITOS: la cola esta inicializada
 * SALIDA: Devuelve true si la cola esta vacia
 */
bool esNulaColaDeTElems(ColaDeTElems);
#endif