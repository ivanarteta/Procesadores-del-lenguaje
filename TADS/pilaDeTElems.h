#ifndef FFF_PILA_DE_TELEMS_H
#define FFF_PILA_DE_TELEMS_H
#include <stdbool.h>
//Dimensión maxima del array
#define TAMANIO_PILA_DE_TELEMS 100
typedef int tElem;
//Definicion del tipo PilaDeTElems
typedef struct pilaDeTElems{
	tElem cima; // Desplazamiento para alcanzar el elemento de la cima
	tElem valores[TAMANIO_PILA_DE_TELEMS];
} PilaDeTElems;
	// Prototipos de la funcionalidad exportada

/**
 * ACCION: nuevaPilaDeTElems
 * ENTRADA: una pila de tElems
 * REQUISITOS: la pila no esta inicializada
 * SALIDA: Inicializa la pila como una pila de tElems sin elementos
 */
void nuevaPilaDeTElems(PilaDeTElems *);
/**
 * ACCION: apilarPilaDeTElems
 * ENTRADA: una pila de tElems y un tElem
 * REQUISITOS: la pila esta inicializada y no esta llena
 * MODIFICA: Añade el tElem como la cima de la pila
 */
void apilarPilaDeTElems(PilaDeTElems *, tElem);
/**
 * ACCION: desapilarPilaDeTElems
 * ENTRADA: una pila de tElems
 * REQUISITOS: la pila esta inicializada y no esta vacia
 * MODIFICA: Elimina el elemento mas nuevo de la pila
 */
void desapilarPilaDeTElems(PilaDeTElems *);
/**
 * ACCION: cimaPilaDeTElems
 * ENTRADA: una pila de tElems y un tElem
 * REQUISITOS: la pila esta inicializada y no esta vacia
 * MODIFICA: Copia en el tElem el elemento mas nuevo de la pila
 */
void cimaPilaDeTElems(PilaDeTElems, tElem *);
/**
 * ACCION: esNulaPilaDeTElems
 * ENTRADA: una pila de tElems
 * REQUISITOS: la pila esta inicializada
 * SALIDA: Devuelve true si la pila esta vacia
 */
bool esNulaPilaDeTElems(PilaDeTElems);
#endif 