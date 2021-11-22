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

Variable* TS_crear_variable(char *nombre, int tipo){
    Variable *celda;
    celda = (Variable*)malloc(sizeof(Variable));
    celda->nombre = nombre;
    celda->tipo = tipo;
    return celda;
}

void TS_insertar_variable(TS_lista *lista, Variable *variable, int tipo){
    TS_celda *celda;
    celda = (TS_celda*)malloc(sizeof(TS_celda));
    celda->tipo = tipo;
    celda->variable = variable;
    if(TS_esVacio(lista)){
        celda->siguiente = NULL;
        lista->inicio = celda;
        lista->final = celda;
    }else{
        if(!TS_buscar(lista, variable->nombre)){
            celda->siguiente = NULL;
            TS_celda *aux = lista->inicio;
            while(aux->siguiente != NULL){
                aux = aux->siguiente;
            }
            aux->siguiente = celda;
            lista->final = celda;
        }
    }

}


/* En nuestro caso queremos ir añadiendo siempre al final */
void TS_insertar(TS_lista *lista, char *nombre, int tipo){
    /*TS_celda *celda;
    celda = (TS_celda*)malloc(sizeof(TS_celda));
    celda->tipo = tipo;
    
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
    }*/
}

void TS_modificar_tipo(TS_lista *lista, int tipo){
    TS_celda *aux;
    aux = lista->inicio; 
    while (aux->siguiente != NULL){
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
        comprobarTipo(aux,nombre);
        /*switch (aux->tipo){
            case 0:
                if(aux->variable->nombre == nombre || !strcmp(aux->variable->nombre, nombre)){
                    return true;
                }
                break;
            default:
                break;
        }*/

        /*if(aux->variable->nombre == nombre || !strcmp(aux->variable->nombre, nombre)){
            return true;
        }*/
        aux = aux->siguiente;  
    }
    comprobarTipo(aux,nombre);

    /*switch (aux->tipo){
        case 0:
            if(aux->variable->nombre == nombre || !strcmp(aux->variable->nombre, nombre)){
                return true;
            }
            break;
        default:
            break;
    }*/

    return false;

    //return (aux->variable->nombre == nombre || !strcmp(aux->variable->nombre, nombre)) ? true : false;
}

void comprobarTipo(TS_celda *celda, char* nombre){
    switch (celda->tipo){
            case 0:
                if(celda->variable->nombre == nombre || !strcmp(celda->variable->nombre, nombre)){
                    return true;
                }
                break;
            default:
                break;
        }
}

bool TS_esVacio(TS_lista *lista){
    return (lista->inicio == NULL && lista->final == NULL);
}

void TS_imprimir(TS_lista *lista){
	printf("\n\n______________ Contenido de la tabla de simbolos _____________\n");
	printf("%10s %25s\n", "NOMBRE", "TIPO");
    /* Recorremos todos los elementos de la tabla */
    TS_celda *aux;
    aux = lista->inicio; 
    while (aux->siguiente != NULL){
        printf("%10s %25d \n", aux->variable->nombre, aux->variable->tipo);
        aux = aux->siguiente;
    }
    printf("%10s %25d \n", aux->variable->nombre, aux->variable->tipo);
}