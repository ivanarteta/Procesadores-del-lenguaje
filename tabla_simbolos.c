#include "tabla_simbolos.h"
#include <stdio.h>
#include <stdlib.h>

void TS_error_fila(char s[]){
	printf("\n\n\nERROR en el modulo filas:  %s\n", s);
}

void TS_nueva_fila(TS_fila *fila){
	fila->inicio = NULL;
	fila->final = NULL;
}

void TS_insertar_celda(TS_fila *fila, TS_dato elem){ 
	TS_celda *celda;
	celda = (TS_celda*)malloc(sizeof(TS_celda));
	/* AÑADIMOS EL ELEMENTO */
	celda->elemento = elem; 
	/* Puede ser un elemento así o bien, los valores sueltos*/
	/* Lo he puesto asi de momento por comodidad */
	if (esNulaLista(*fila)){
        celda->siguiente = NULL;
        celda->anterior = NULL;
        fila->inicio = celda;
        fila->final = celda;
    }else{
        celda->siguiente = NULL;
		celda->anterior = fila->final;
		celda->anterior->siguiente = celda;
		fila->final = celda;
    }
}

bool TS_es_nula_fila(TS_fila fila){
	return ((fila.inicio == NULL) & (fila.final ==NULL));
}

void TS_imprimir_fila (TS_fila fila){
	TS_celda *aux;
	aux = fila.inicio;
	while(aux->anterior){
		aux = aux->anterior;
	}
	while(aux){
		printf("%d ",aux->elemento);
		aux = aux->siguiente;
	}
	printf("\n");
}

bool TS_esta_elemento(TS_fila, TS_dato);
void TS_concatenar_fila (TS_fila *, TS_fila *);
void TS_borrar_celda();