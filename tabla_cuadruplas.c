#include "tabla_cuadruplas.h"
#include <stdio.h>
#include <stdlib.h>

void nuevaTabla(TC_tabla_cuadrupla *elemento){
    elemento->siguiente = NULL;
	elemento->cuadrupla = NULL;
}