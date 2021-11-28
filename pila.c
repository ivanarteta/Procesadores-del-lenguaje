#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void errorPila(char s[]){
	printf("Error en el modulo pilas \n");
}

void nuevaPila(tipoPila *pila){
	*pila = NULL;
}

void apilar(tipoPila *pila, tipoElementoPila elemento){
	celdaPila *nuevo;
	nuevo = (celdaPila*)malloc(sizeof(celdaPila));
	nuevo->elem = elemento;
	nuevo->sig = *pila;
	*pila = nuevo;
}

void desapilar(tipoPila *pila){
	if(!esNulaPila(*pila)){
		celdaPila *aux;
		aux = *pila;
		*pila = (*pila)->sig;
		free(aux);
	}
}

tipoElementoPila cima(tipoPila pila){
	if (!esNulaPila(pila))
		return (pila->elem);
	else
		return NULL;
}

bool esNulaPila(tipoPila pila){
	return pila == NULL;
}