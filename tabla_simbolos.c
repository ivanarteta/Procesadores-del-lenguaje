#include "tabla_simbolos.h"
#include "definiciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROJO "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET "\x1b[0m"

void TS_nuevaLista(TS_lista *elemento){
    elemento->inicio = NULL;
	elemento->final = NULL;
}

/* En nuestro caso queremos ir añadiendo siempre al final */
void TS_insertar(TS_lista *lista, char *nombre){
    TS_celda *celda;
    celda = (TS_celda*)malloc(sizeof(TS_celda));
    /* Le damos los valores a la celda */
    celda->nombre = nombre;
    celda->tipo = -1;
    if(TS_esVacio(lista)){
        celda->siguiente = NULL;
        lista->inicio = celda;
        lista->final = celda;
    }else{
        if(!TS_buscar(lista, nombre)){
            celda->siguiente = NULL;
            TS_celda *aux = lista->inicio;
            while(aux->siguiente != NULL){
                aux = aux->siguiente;
            }
            aux->siguiente = celda;
            lista->final = celda;
        }
    }
    TS_imprimir(lista);
}

void TS_modificar_tipo(TS_lista *lista, int tipo){
    printf("tipo: %d \n", tipo);
    TS_celda *aux;
    aux = lista->inicio; 
    while (aux->siguiente != NULL){
        printf("%d \n", aux->tipo);
        if(aux->tipo == -1){
           aux->tipo = tipo; 
        }
        aux = aux->siguiente;
    }
    if(aux->tipo == -1){
        aux->tipo = tipo; 
    }
}

bool TS_buscar(TS_lista *lista, char * nombre){ 
    TS_celda *aux;
    aux = lista->inicio;
    while(aux->siguiente != NULL){
        if(aux->nombre == nombre || !strcmp(aux->nombre, nombre)){
            return true;
        }
        aux = aux->siguiente;  
    }
    return (aux->nombre == nombre || !strcmp(aux->nombre, nombre)) ? true : false;
}

bool TS_esVacio(TS_lista *lista){
    return (lista->inicio == NULL && lista->final == NULL);
}

void TS_imprimir(TS_lista *lista){
	printf("\n\n______________ Contenido de la tabla de simbolos _____________\n");
	printf("%5s %10s %25s\n", "ID", "NOMBRE", "TIPO");
    /* Recorremos todos los elementos de la tabla */
    TS_celda *aux;
    aux = lista->inicio; 
    while (aux->siguiente != NULL){
        printf("%s %d \n", aux->nombre, aux->tipo);
        aux = aux->siguiente;
    }
    printf("%s %d \n", aux->nombre, aux->tipo);
}