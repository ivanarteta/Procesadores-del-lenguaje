#include <stdbool.h>

typedef int tipoElementoLista;
typedef struct celdaL{
	tipoElementoLista elem;
	struct celdaL *sig;
	struct celdaL *ant;
}celdaLista; 
typedef struct tipoL{
	celdaLista *ini;
	celdaLista *fin;
}tipoLista;

void nuevaLista(tipoLista *);

void insertar(tipoLista *, tipoElementoLista);

bool estaElemento(tipoLista, tipoElementoLista);

bool esNulaLista(tipoLista);

void concatenar (tipoLista *, tipoLista *);

void imprimirLista (tipoLista);