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

Constante* TS_crear_constante(char *nombre, int tipo, Constante_valor valor){
    Constante *celda;
    celda = (Constante*)malloc(sizeof(Constante));
    celda->nombre = nombre;
    celda->tipo = tipo;
    switch (tipo){
        case 0:
        case 4:
        case 5:
            celda->valor.entero = valor.entero;
            break;
        case 1:
            celda->valor.real = valor.real;
            break;
        case 2:
        case 3:
            strcpy(celda->valor.caracteres,valor.caracteres);
        default:
            break;
    }
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

void TS_insertar_constante(TS_lista *lista, Constante *constante, int tipo){
    TS_celda *celda;
    celda = (TS_celda*)malloc(sizeof(TS_celda));
    celda->tipo = tipo;
    celda->constante = constante;
    if(TS_esVacio(lista)){
        celda->siguiente = NULL;
        lista->inicio = celda;
        lista->final = celda;
    }else{
        if(!TS_buscar(lista, constante->nombre)){
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

bool TS_buscar(TS_lista *lista, char * nombre){ 
    TS_celda *aux;
    aux = lista->inicio;
    while(aux->siguiente != NULL){
        if(comprobarTipo(aux,nombre)){
            return true;
        }
        aux = aux->siguiente;  
    }
    comprobarTipo(aux,nombre);
    return comprobarTipo(aux, nombre);
}

bool comprobarTipo(TS_celda *celda, char* nombre){
    switch (celda->tipo){
        case 0:
            if(celda->variable->nombre == nombre || !strcmp(celda->variable->nombre, nombre)){
                return true;
            }
            break;
        case 1:
            if(celda->constante->nombre == nombre || !strcmp(celda->constante->nombre, nombre)){
                return true;
            }
            break;
        default:
            break;
    }
    return false;
}

bool TS_esVacio(TS_lista *lista){
    return (lista->inicio == NULL && lista->final == NULL);
}

void TS_imprimir_comun(TS_celda *celda){
    switch (celda->tipo){
        case 0:
            printf("%10s %25d \t\t\t VAR \n", celda->variable->nombre, celda->variable->tipo);
            break;
        case 1:
            printf("%10s %25d \t\t\t CONST \n", celda->constante->nombre, celda->constante->tipo);
            break;
        default:
            break;
    }
}

void TS_imprimir(TS_lista *lista){
	printf("\n\n______________ Contenido de la tabla de simbolos _____________\n");
	printf("%10s %25s %25s \n", "NOMBRE", "TIPO", "OTRO TIPO");
    /* Recorremos todos los elementos de la tabla */
    TS_celda *aux;
    aux = lista->inicio; 
    while (aux->siguiente != NULL){
        TS_imprimir_comun(aux);
        aux = aux->siguiente;
    }
    TS_imprimir_comun(aux);
}

int TS_consulta_tipo(TS_lista *lista, char *nombre){
    TS_celda *aux;
    aux = lista->inicio;
    while(aux->siguiente != NULL){
        if(aux->variable->nombre == nombre || !strcmp(aux->variable->nombre, nombre)){
            return aux->variable->tipo;
        }
        aux = aux->siguiente;  
    }
    if(aux->variable->nombre == nombre || !strcmp(aux->variable->nombre, nombre)){
        return aux->variable->tipo;
    }
    return -1;
}