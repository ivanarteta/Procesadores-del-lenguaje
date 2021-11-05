#include "colaDinamica.h"

void nuevaCola(tipoCola *c){
	c->ini = NULL;
	c->fin = NULL;
}


void encolar(tipoCola *c, tipoElementoCola elemento){
	celdaCola *nuevo;
	nuevo = (celdaCola*)malloc(sizeof(celdaCola));
	nuevo->elem = elemento;
	if(esNulaCola(*c)){
		nuevo->sig = NULL;
		c->ini = nuevo;
		c->fin = nuevo;
		*c = nuevo;
	}else{

	}
}