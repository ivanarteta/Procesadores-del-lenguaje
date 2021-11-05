#include <stdbool.h>

typedef int tipoElementoMaxMonticulo;

typedef struct tMM{
	tipoElementoMaxMonticulo *array;
	int pos;
	int numEl;
}tipoMaxMonticulo;

void nuevoMaxMonticulo(tipoMaxMonticulo*,int);
void errorMaxMonticulo(char s[]);
void insertarMaxMonticulo(tipoMaxMonticulo *, tipoElementoMaxMonticulo);

void eliminarElemento(tipoMaxMonticulo *, tipoElementoMaxMonticulo);

tipoElementoMaxMonticulo devolverRaiz(tipoMaxMonticulo);

void mostrarAnchura(tipoMaxMonticulo);

bool esVacio(tipoMaxMonticulo);

bool estaLleno(tipoMaxMonticulo);