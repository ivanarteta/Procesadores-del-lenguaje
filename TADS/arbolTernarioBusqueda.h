#include <stdbool.h>

typedef int tipoElementoArbolBusqueda;
typedef struct celdaATB{
	tipoElementoArbolBusqueda elem;
	struct celdaATB *izda;
	struct celdaATB *centro;
	struct celdaATB *dcha;
}celdaArbolBusqueda; 
typedef celdaArbolBusqueda *tipoArbolTB;

void nuevoArbolTB(tipoArbolTB *);

void errorArbolTB(char s[]);

void insertar(tipoArbolTB *, tipoElementoArbolBusqueda);

void borrar(tipoArbolTB *, tipoElementoArbolBusqueda);

void mostrarEnFormaRara(tipoArbolTB);

bool esVacio(tipoArbolTB);