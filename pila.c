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

void apilar(tipoPila *pila, tElem elemento){
	celdaPila *nuevo;
	if((nuevo = (celdaPila*)malloc(sizeof(celdaPila))) == NULL){
		errorPila("No hay memoria para apilar");
	}
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
	}else{
		errorPila("Desapilar en pila vacia");
	}
}

tElem cima(tipoPila pila){
	if (!esNulaPila(pila)){
		return (pila->elem);
	}else{
		errorPila("Primero en pila vacia");
		return -1;
	}
}

bool esNulaPila(tipoPila pila){
	return pila == NULL;
}

void vaciarPila(tipoPila *pila){
	while(!esNulaPila(*pila)){
		desapilar(pila);
	}
	free(pila);
}