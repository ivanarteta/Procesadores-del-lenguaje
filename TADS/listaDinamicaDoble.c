#include "listaDinamicaDoble.h"
#include <stdlib.h>
#include <stdio.h>
void errorLista(char s[]){
	printf("\n\n\nERROR en el modulo listas:  %s\n", s);
}

//FUnciona bien
void nuevaLista(tipoLista *l){
	l->ini = NULL;
	l->fin = NULL;
}

void insertar(tipoLista *l, tipoElementoLista e){ 
	celdaLista *celda;
	celda = (celdaLista*)malloc(sizeof(celdaLista));
    celda->elem = e;
	if (esNulaLista(*l)){
        celda->sig = NULL;
        celda->ant = NULL;
        l->ini = celda;
        l->fin = celda;
    }else{
        celda->sig = NULL;
		celda->ant = l->fin;
		celda->ant->sig = celda;
		l->fin = celda;
    }
}

void borrar(){
	if(esNulaLista(*l)){
		//error
	}else{
		
	}
}

bool esNulaLista(tipoLista l){
	return ((l.ini == NULL) & (l.fin ==NULL));
}

void imprimirLista (tipoLista l){
	celdaLista *aux;
	aux = l.ini;
	while(aux->ant){
		aux = aux->ant;
	}
	while(aux){
		printf("%d ",aux->elem );
		aux = aux->sig;
	}
	printf("\n");
}
