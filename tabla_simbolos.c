#include "tabla_simbolos.h"
#include <stdio.h>
#include <stdlib.h>

void nuevaLista(TS_lista *elemento){
    elemento->inicio = NULL;
	elemento->final = NULL;
}