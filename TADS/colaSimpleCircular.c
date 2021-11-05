#include "cola.h"
#include <stdio.h>
#include <stdlib.h> 

void errorCola(char s[]){
	printf("\n\n\nERROR en el modulo colas:  %s\n", s);
}

void nuevaCola(tipoCola *c){
	c->ini = NULL;
	c->fin= NULL;
}

void encolar(tipoCola *c, tipoElementoCola elemento){
	celdaCola *nuevo;
	nuevo=(celdaCola*)malloc(sizeof(celdaCola));
	nuevo->elem = elemento;
	nuevo->sig = nuevo;
	if(!esNulaCola(*c)){
		nuevo->sig = (*c)->sig;
		(*c)->sig = nuevo;
	}
	*c = nuevo;
}

bool esNulaCola(tipoCola c){
	return (c.ini == NULL);
}

void desencolar(tipoCola *c){	
	if (esNulaCola(*c)){
		errorCola("avanzando en cola nula");
	}else{
		celdaCola *aux;
		aux = (*c)->sig;
		if(aux == (*c)){
			(*c) = NULL;
		}else{
			(*c)->sig = aux->sig;
		}
		free(aux);
	}
	
}

tipoElementoCola frente(tipoCola c){
	if (esNulaCola(c))
		errorCola("primero en cola nula");
	return c.ini->elem;
}