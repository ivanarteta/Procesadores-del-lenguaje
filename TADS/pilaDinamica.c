#include "pilaDinamica.h"

void errorPila(char s[]){
	printf("Error en el modulo pilas \n");
}

void nuevaPila(tipoPila *p){
	*p = NULL;
}

void apilar(tipoPila *p, tipoElementoPila elemento){
	celdaPila *nuevo;
	nuevo = (celdaPila*)malloc(sizeof(celdaPila));
	nuevo->elem = elemento;
	nuevo->sig = *p;
	*p = nuevo;
}

/*ESTA MAL*/ /* REPASAR */
void desapilar(tipoPila *p){
	celdaPila *nuevo;
	//nuevo = (celdaPila*)malloc(sizeof(celdaPila));
	nuevo = *p;
	//nuevo = nuevo->sig;
	//*p = nuevo;
	*p = (*p)->sig;
	free(aux);
}

tipoElementoPila cima(tipoPila p){
	return p->elem;
}

bool esNulaPila(tipoPila p){
	return p == NULL;
}