#include <stdbool.h>

typedef int tipoElementoMinMonticulo;

typedef struct tMM{
	tipoElementoMinMonticulo *array;
	int pos; //posicion en la que esta el ultimo elem
	int numEl; //cantidad total de elems
}tipoMinMonticulo;

void nuevoMinMonticulo(tipoMinMonticulo*, int);

void errorMinMonticulo(char s[]);

void insertarMinMonticulo(tipoMinMonticulo *, tipoElementoMinMonticulo);

void eliminarElemento(tipoMinMonticulo *, tipoElementoMinMonticulo);

tipoElementoMinMonticulo devolverRaiz(tipoMinMonticulo);

void mostrarAnchura(tipoMinMonticulo);

bool esVacio(tipoMinMonticulo);

bool estaLleno(tipoMinMonticulo);