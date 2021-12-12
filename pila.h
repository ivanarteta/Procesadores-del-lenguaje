#include <stdbool.h>

// tElem es el tipo de elemento que se va a guardar en la cola
typedef int tElem;

// Estructura para las celdas de la pila
typedef struct celdaP{
	tElem elem;
	struct celdaP *sig;
} celdaPila;

// Estructura de la pila (puntero a celda)
typedef celdaPila* tipoPila;

// Crear una nueva pila
void nuevaPila(tipoPila *);

// Añadir un elemento nuevo a la pila
void apilar(tipoPila *, tElem);

// Eliminar el elemento de la cima de la pila
void desapilar(tipoPila *);

// Ver el primer elemento de la pila
tElem cima(tipoPila);

// Comprobar si la pila está vacía
bool esNulaPila(tipoPila);

// Vaciar la pila
void vaciarPila(tipoPila *);