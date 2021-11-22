#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#include <stdbool.h>
#include "definiciones.h" //Solo si en el struct hacemos referencia al enum_tipo

typedef struct variable{
    int tipo; //Tipo será enum_tipo
    char* nombre;
    //int ambito; 
}Variable;

typedef struct constante{
    int tipo; //Tipo será enum_tipo_literal
    char* nombre;
    Constante_valor valor;
    //int ambito;
}Constante;

typedef struct ts_celda{
    //int id; /* La dirección en la que está */
    //char *nombre; /* Nombre */
    /*int ambito;*/ /* Ámbito de validez */ /* Creemos que no hace falta porque no se pueden declarar variables dentro de ningun bucle */
    //int tipo;
    //enum enum_tipo tipo; /* Tipo */
    int tipo; //Tipo de enum_tipo_celda
    //void* campos; //Va al struct con los campos especificos para ese tipo
    Variable *variable;
    Constante *constante;
    struct ts_celda *siguiente; /* Puntero al elemento anterior y al siguiente */
}TS_celda;

typedef struct ts_lista{
    TS_celda *inicio , *final;
}TS_lista;


/* FUNCIONES */
void TS_nuevaLista(TS_lista *); //Para generar la lista vacía
void TS_insertar_variable(TS_lista *, Variable *, int);
void TS_insertar_constante(TS_lista *, Constante *, int);
Variable* TS_crear_variable(char *, int);
Constante* TS_crear_constante(char *, int, Constante_valor);

bool TS_buscar(TS_lista *, char *); //Busca si existe un nombre en la tabla o no
bool comprobarTipo(TS_celda *, char *);
bool TS_esVacio(TS_lista *); //Para comprobar si está vacía la lista
void TS_imprimir(TS_lista *); //Para mostrar la tabla de símbolos
void TS_imprimir_comun(TS_celda *);

#endif