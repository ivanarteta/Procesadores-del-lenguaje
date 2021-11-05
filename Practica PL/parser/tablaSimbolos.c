#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tablaSimbolos.h"

void iniciarTabla(lista *l){
	l->primero = NULL;
	l->ultimo = NULL;
    l->cont = 1;
}


bool vacia(lista l){
	if (l.primero == NULL){
		return true;
	}else{
		return false;
	}
}


int insertarElemento(lista *l, celda* nuevo){
	if (vacia(*l)){
		l->primero = nuevo;
		l->ultimo = nuevo;
		return 0;
	}else{
		nuevo->ant = l->ultimo;
		l->ultimo->sig = nuevo;
		l->ultimo = nuevo;
		return 0;
	}
}


celda* buscarElemento(lista l, int idE){
	if (!vacia(l)){
		if ((l.primero)->id == idE){
			return l.primero;
		}else if ((l.ultimo)->id == idE){
			return l.ultimo;
		}else{
			lista aux;
			aux = l;
            if (l.primero->sig != NULL && l.ultimo->ant != NULL){
                while ((((aux.primero)->sig)->id != idE) && (((aux.ultimo)->ant)->id != idE)){
                    aux.primero = aux.primero->sig;
                    aux.ultimo = aux.ultimo->ant;
					if (aux.primero->sig == aux.ultimo->ant || aux.primero->sig == aux.ultimo){
						break;
					}
                }
                if (((aux.primero)->sig)->id == idE){
                    return (aux.primero)->sig;
                }else if (((aux.ultimo)->ant)->id == idE){
                    return (aux.ultimo)->ant;
                }else{
                    return NULL;
                }
            }
		}
	}else{
		return NULL;	
	}
}

celda* buscarT(lista l, char* nombre) {
	if (!vacia(l)) {
		lista aux = l;
		while ((strcmp(aux.primero->nombre, nombre) != false) && (aux.primero->sig != NULL)) {
			aux.primero = aux.primero->sig;
		}
		if (strcmp(aux.primero->nombre, nombre) == false) {
			return (aux.primero);
		}
		else {
			return NULL;
		}
	}
	else {
		return NULL;
	}
}



void modifica_tipo_TS(lista* l, int id, int tipo) {
	celda* aux = buscarElemento(*l, id);
	aux->type = tipo;
}


void imprimirTablaSimbolos(lista l){
		celda *aux;
		aux = l.primero;
		while (aux->sig != NULL){
			printf("ID: %d , Nombre: %s , Type: %d \n",aux->id, aux->nombre, aux->type);
			aux = aux->sig;
		}
		printf("ID: %d , Nombre: %s  , Type: %d \n", aux->id, aux->nombre, aux->type);
}



int newTemp(lista* l, char* nombre) {
	celda* newT = (celda*)malloc(sizeof(celda));
	newT->sig = NULL;
	newT->ant = NULL;
	newT->id = l->cont++;
	if (nombre != NULL) {
		char* temp = (char*)malloc(sizeof(strlen(nombre)));
		strcpy(temp, nombre);
		newT->nombre = temp;
	}
	else {
		char temp[7];
		sprintf(temp, "temp_%d", l->cont);
		newT->nombre = strdup(temp);
	}
	insertarElemento(l, newT);
	return newT->id;
}
