#include "eaux.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct TRUE_FALSE makelist(){
    struct TRUE_FALSE nuevaEstructura;
    //nuevaEstructura =  (struct TRUE_FALSE)  malloc(sizeof(struct TRUE_FALSE));
    nuevaEstructura.cabeza = (struct elementoLista*) malloc(sizeof(struct elementoLista));
    nuevaEstructura.cola = (struct elementoLista*) malloc(sizeof(struct elementoLista));
    nuevaEstructura.cabeza ->idCuadrupla = -1;
    nuevaEstructura.cabeza ->p = NULL;
    nuevaEstructura.cola = nuevaEstructura.cabeza;
    return nuevaEstructura;
}

void insert_list(struct TRUE_FALSE* lista, int id){
    if((*lista).cabeza->idCuadrupla == -1){
        (*lista).cabeza->idCuadrupla = id;
    }else{
        struct elementoLista* nueva;
        nueva = (struct elementoLista*) malloc(sizeof(struct elementoLista));
        nueva->idCuadrupla = id;
        nueva->p = NULL;
        (*lista).cola->p = nueva;
        (*lista).cola = nueva;  
        
    }
    
}

struct TRUE_FALSE merge(struct TRUE_FALSE lista1, struct TRUE_FALSE lista2){
    struct TRUE_FALSE nueva;
    //nueva = (struct TRUE_FALSE) malloc(sizeof(struct TRUE_FALSE));
    // Esto se puede hacer??? NO se estña pasando por referencia lista1 y lista2...
    lista1.cola->p = lista2.cabeza;
    nueva = lista1;
    return nueva;
}

int empty(struct TRUE_FALSE lista){
    if (lista.cabeza == NULL){
        return 1;
    }else{
        return 0;
    }
}


int esOpGoto(int op) {
    if (op >= OPERADOR_GOTO && op <= OPERADOR_GOTO_MEOI_REAL) {
        return 1;
    } else {
        return 0;
    }
}
