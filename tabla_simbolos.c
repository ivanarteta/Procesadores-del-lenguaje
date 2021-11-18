#include "tabla_simbolos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void TS_nuevaLista(TS_lista *elemento){
    elemento->inicio = NULL;
	elemento->final = NULL;
}

void TS_insertar(TS_lista *lista, TS_celda *elemento){

    if(TS_esVacio(lista)){
        lista->inicio = elemento;
        lista->final = elemento;
    }else{
        elemento->siguiente = NULL;
        lista->final = elemento;
    }
}

void TS_buscar(TS_lista *lista, char elem[]){

}

/**
 * @brief Función que comprueba si la tabla de símbolos está vacía o no
 * 
 * @param lista 
 * @return true Si la lista está vacía
 * @return false Si hay algún elemento en la lista
 */
bool TS_esVacio(TS_lista *lista){
    return (lista->inicio == NULL && lista->final == NULL);
}
