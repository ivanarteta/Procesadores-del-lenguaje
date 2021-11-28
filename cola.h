#ifndef FFF_COLA_DE_TELEMS_H
#define FFF_COLA_DE_TELEMS_H
#include <stdbool.h> 
#include "definiciones.h"

/*typedef int tElem;

typedef struct nodoDeCola{
	tElem e;
	struct nodoDeCola *s;
}NodoDeCola;

typedef struct cola{
	NodoDeCola *i;
	NodoDeCola *f;
}Cola;*/

void nuevaCola(Cola *);
void pideTurnoCola(Cola *, tElem);
void avanceCola(Cola *);
tElem primeroCola(Cola);
bool esNulaCola(Cola);
#endif