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

int contadorTemp = 1;

void TS_nuevaLista(TS_lista *elemento){
    elemento->inicio = NULL;
	elemento->final = NULL;
    elemento->contador = 1;
}

int TS_insertar(TS_lista *lista, char* nombre){
    TS_celda *celda;
    celda = (TS_celda*)malloc(sizeof(TS_celda));
    celda->nombre = nombre;
    if(TS_esVacio(lista)){
        celda->siguiente = NULL;
        lista->inicio = celda;
        lista->final = celda;
        celda->id = lista->contador;
        lista->contador++;
    }else{
        if(!TS_buscar(lista, nombre)){
            celda->siguiente = NULL;
            celda->id = lista->contador;
            lista->contador++;
            TS_celda *aux = lista->inicio;
            while(aux->siguiente != NULL){
                aux = aux->siguiente;
            }
            aux->siguiente = celda;
            lista->final = celda;       
        }else{
            return TS_buscar_id(lista, nombre);
        }
    }
    return celda->id;
}

int TS_buscar_id(TS_lista *lista, char * nombre){ 
    TS_celda *aux;
    aux = lista->inicio;
    while(aux->siguiente != NULL){
        if((aux->nombre == nombre) || !strcmp(aux->nombre, nombre)){
            return aux->id;
        }
        aux = aux->siguiente;  
    }
    return aux->id;
}

//Lista, nombre, tipo, tipo_simbolo
//Aquí en vez del nombre se le pasa la posicion
void TS_modificar_tipo(TS_lista *lista, int id, int tipo, int tipoSimbolo){
    TS_celda *aux;
    aux = lista->inicio;
    while(aux->siguiente != NULL && aux->id != id){
        aux = aux->siguiente;  
    }
    /* Puede ser porque o bien es el último elemento o bien porque es el correcto */
    if(aux->id == id){
        aux->tipo = tipo;
        aux->tipo_simbolo = tipoSimbolo;
    }
}


/*void TS_modificar_tipo(TS_lista *lista, char* nombre, int tipo, int tipoSimbolo){
    TS_celda *aux;
    aux = lista->inicio;
    while(aux->siguiente != NULL && aux->nombre != nombre){
        aux = aux->siguiente;  
    }
    if(aux->nombre == nombre){
        aux->tipo = tipo;
        aux->tipo_simbolo = tipoSimbolo;
    }
}*/



/*void TS_modificar_valor_cte(TS_lista *lista, char *nombre, Constante_valor valor){
    TS_celda *aux;
    aux = lista->inicio;
    while(aux->siguiente != NULL && (aux->nombre != nombre)){
        aux = aux->siguiente;  
    }
    //Comprobar si es el nombre
    if(aux->nombre == nombre && aux->tipo_simbolo == TS_CONSTANTE){
        aux->otros = (Constante*)malloc(sizeof(Constante));
        Constante *constante = aux->otros;
        switch (aux->tipo){
            case TIPO_ENTERO:
                constante->valor.entero = valor.entero;
                break;
            default:
                break;
        }
    }
}*/

int TS_newtempt(TS_lista *lista){
    TS_celda *celda;
    celda = (TS_celda*)malloc(sizeof(TS_celda));
    char nombre[10];
    sprintf(nombre, "t%d", contadorTemp);
    celda->nombre =strdup(nombre);
    contadorTemp++;
    if(TS_esVacio(lista)){
        celda->siguiente = NULL;
        lista->inicio = celda;
        lista->final = celda;
    }else{
        if(!TS_buscar(lista, celda->nombre)){
            celda->siguiente = NULL;
            celda->id = lista->contador;
            lista->contador++;
            TS_celda *aux = lista->inicio;
            while(aux->siguiente != NULL){
                aux = aux->siguiente;
            }
            aux->siguiente = celda;
            lista->final = celda;
        }
    }
    return celda->id;
}

bool TS_buscar(TS_lista *lista, char * nombre){ 
    TS_celda *aux;
    aux = lista->inicio;
    while(aux->siguiente != NULL){
        if((aux->nombre == nombre) || !strcmp(aux->nombre, nombre)){
            return true;
        }
        aux = aux->siguiente;  
    }
    return ((aux->nombre == nombre) || !strcmp(aux->nombre, nombre)) ? true : false;
}

bool TS_esVacio(TS_lista *lista){
    return (lista->inicio == NULL && lista->final == NULL);
}

char* mostrar_tipo(int tipo){
    switch (tipo){
        case TS_VAR:
            return "Var";
        case TS_CONSTANTE:
            return "Const";
        case TS_ACCION:
            return "Acción";
        case TS_FUNCION:
            return "Función";
        case TS_TIPO:
            return "Tipo";
        case TIPO_ENTERO:
            return "Entero";
        case TIPO_REAL:
            return "Real";
        case TIPO_BOOLEANO:
            return "Booleano";
        case TIPO_CADENA:
            return "Cadena";
        case TIPO_CARACTER:
            return "Caracter";
        case TIPO_LITERAL_ENTERO:
            return "Literal entero";
        default:
            return "-";
    }
}

void TS_imprimir(TS_lista *lista){
	printf("\n\n______________ Contenido de la tabla de simbolos _____________\n");
	printf("%5s %10s %25s %25s \n", "ID",  "NOMBRE", "TIPO", "TIPO SIMBOLO");
    /* Recorremos todos los elementos de la tabla */
    TS_celda *aux;
    aux = lista->inicio; 
    while (aux->siguiente != NULL){
        printf("%5d %10s %25s %25s \n",aux->id, aux->nombre, mostrar_tipo(aux->tipo), mostrar_tipo(aux->tipo_simbolo));
        aux = aux->siguiente;
    }
    printf("%5d %10s %25s %25s \n",aux->id, aux->nombre, mostrar_tipo(aux->tipo), mostrar_tipo(aux->tipo_simbolo));
}

int TS_consulta_tipo_simbolo(TS_lista *lista, int id){
    TS_celda *aux;
    aux = lista->inicio;
    while(aux->siguiente != NULL){
        if(aux->id == id){
            return aux->tipo_simbolo;
        }
        aux = aux->siguiente;  
    }
    if(aux->id == id){
        return aux->tipo_simbolo;
    }
    return -1;
}

int TS_consulta_tipo(TS_lista *lista, int id){
    TS_celda *aux;
    aux = lista->inicio;
    while(aux->siguiente != NULL){
        if(aux->id == id){
            return aux->tipo;
        }
        aux = aux->siguiente;  
    }
    if(aux->id == id){
        return aux->tipo;
    }
    return -1;
}

char* TS_buscar_nombre(TS_lista *lista, int id){
    TS_celda *aux;
    aux = lista->inicio;
    while(aux->siguiente != NULL){
        if(aux->id == id){
            return aux->nombre;
        }
        aux = aux->siguiente;  
    }
    if(aux->id == id){
        return aux->nombre;
    }
    return NULL;
}