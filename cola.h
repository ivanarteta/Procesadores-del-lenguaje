#ifndef FFF_COLA_DE_TELEMS_H
#define FFF_COLA_DE_TELEMS_H
#include <stdbool.h> 
#include "definiciones.h"

// tElem es el tipo de elemento que se va a guardar en la cola
typedef int tElem;

// Estructura para los nodos de la cola
typedef struct nodoDeCola{
	tElem e;
	struct nodoDeCola *s;
}NodoDeCola;

// Estructura para la cola
typedef struct cola{
	NodoDeCola *i;
	NodoDeCola *f;
}Cola;

// Crear una cola nueva
void nuevaCola(Cola *);

// Añadir un elemento a la cola
void pideTurnoCola(Cola *, tElem);

// Eliminar el primer elemento de la cola
void avanceCola(Cola *);

// Ver el primer elemento de la cola
tElem primeroCola(Cola);

// Comprobar si la cola está vacía
bool esNulaCola(Cola);

// Imprimir el contenido de la cola
void imprimirCola(Cola);

// Vaciar la cola
void vaciarCola(Cola *);

#endif