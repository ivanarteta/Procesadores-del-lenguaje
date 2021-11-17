#include "colaDoble.h"
#include <stdlib.h>
#include <stdio.h>
void errorCola(char s[]){
	printf("\n\n\nERROR en el modulo colas:  %s\n", s);
	while (true)
		exit(-1);
}

void nuevaColaDoble(tipoColaDoble *cola){
	cola->ini = NULL;
	cola->fin = NULL;
}

/*NO se si está bien*/
void encolarPrimero(tipoColaDoble *cola, tipoElementoColaDoble elem){
	celdaColaDoble *aux;
	aux = (celdaColaDoble*)malloc(sizeof(celdaColaDoble));
	aux->elem = elem;
	if(esNulaColaDoble(*c)){
		//aux->sig = aux;
		//aux->ant = aux;
		aux->sig = aux;
		cola->ini = aux;
		cola->fin = aux;
	}else{
		cola->ini->ant = aux;
		aux->sig = cola;
		cola->ini = aux;
		cola->fin->sig = aux;
		//aux->sig = cola->ini;
		//aux->ant = cola->fin;
		//aux->ant->sig = aux;
		//celda->ant->sig = celda
		//l->fin = celda
		//cola->fin->sig = aux;
	}
	//cola->fin = aux;
	aux->ant = cola->fin;
}
/*NO se si está bien*/
void encolarUltimo(tipoColaDoble *cola, tipoElementoColaDoble elem){
	celdaColaDoble *aux;
	if((aux = malloc(sizeof(celdaColaDoble)))==NULL)
		errorCola("no hay memoria para pideTurno");
	aux->elem = elem;
	if(esNulaColaDoble(*c)){
		aux->sig = aux;
		aux->ant = aux;
		cola->ini = aux;
		cola->fin = aux;
	}else{
		aux->ant = cola->fin;
		aux->sig = cola->ini;
	}
	cola->fin = aux;
}

void desencolarPrimero(tipoColaDoble *cola){
	celdaColaDoble *aux;
	if(esNulaColaDoble(*cola))
		errorCola("avanzando en cola nula");
	aux = cola->ini;
	cola->ini = cola->ini->sig;
	if(cola->ini ==NULL)
		cola->fin = NULL;
	free(aux);
}

void desencolarUltimo(tipoColaDoble *cola){
	celdaColaDoble *aux;
	if(esNulaColaDoble(*cola))
		errorCola("avanzando en cola nula");
	aux = cola->fin;
	cola->fin = cola->fin->ant;
	if(cola->fin == NULL)
		cola->ini = NULL;
	free(aux);
}

tipoElementoColaDoble elemPrimero(tipoColaDoble cola){
	return (cola.ini->elem);
}

tipoElementoColaDoble elemUltimo(tipoColaDoble cola){
	return (cola.fin->elem);
}

bool esNulaColaDoble(tipoColaDoble cola){
	return (cola.ini == NULL && cola.fin ==NULL);
}