#include "tabla_cuadruplas.h"
#include "definiciones.h"
#include <stdio.h>
#include <stdlib.h>

void TC_nuevaLista(TC_tabla_cuadrupla *elemento){
    elemento->siguiente = NULL;
	//elemento->cuadrupla = NULL;
    elemento->contador = 1;
}

TC_cuadrupla* TC_crear_cuadrupla(int operador, int *op1, int *op2, int *resultado){
    TC_cuadrupla *cuadrupla;
    cuadrupla = (TC_cuadrupla*)malloc(sizeof(TC_cuadrupla));
    cuadrupla->operador = operador;
    cuadrupla->operando1 = op1;
    cuadrupla->operando2 = op2;
    cuadrupla->resultado = resultado;
    return cuadrupla;
}

void TC_insertar(TC_tabla_cuadrupla *tabla, TC_cuadrupla *cuadrupla){
    TC_tabla_cuadrupla *aux;
    aux = (TC_tabla_cuadrupla*)malloc(sizeof(TC_tabla_cuadrupla));
    aux->cuadrupla = cuadrupla;
    aux->siguiente = NULL;

    


}