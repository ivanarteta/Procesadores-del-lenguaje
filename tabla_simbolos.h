#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#include <stdbool.h>

/* Es la tabla que construimos en los parsers, más o menos */
/* Es una lista de celdas o casillas */
/* Por cada fila tenemos X casillas */
typedef struct dato{
    /* Nombre */
    /* Tipo => Dato (TABLA, TUPLA, PUNTERO, ENTERO, REAL, BOOLEANO, CARACTER O STRING) o Simbolo (VAR, TIPO, CTE, FUNCION, ACCION) */
    /* Id */
}TS_dato;


typedef struct ts_celda{
    /* Nombre */
    /* Tipo => Dato (TABLA, TUPLA, PUNTERO, ENTERO, REAL, BOOLEANO, CARACTER O STRING) o Simbolo (VAR, TIPO, CTE, FUNCION, ACCION) */
    /* Id */
    TS_dato elemento;
    /* Puntero al elemento anterior y al siguiente */
    struct ts_celda *siguiente, *anterior;
}TS_celda;

typedef struct ts_fila{
    /* Puntero a la primera celda, y a la última celda */
    TS_celda *inicio, *final;
}TS_fila;


/* La estructura de datos que se utiliza es un union sobre un struct de un tipo */
typedef struct TS_tipo{
    union{

    };
};

/* La tabla de simbolos contiene informacion sobre los simbolos que se utilizan en la programacion. 
Por ejemplo: 
    nombres de variables: nombre, tipo, ámbito de validez
    nombres de constantes: nombre, tipo, valor, ámbito de validez
    nombres de acciones: nombre, lista de parámetros (tipo, nombre, tipo de peso?)
    nombres de funciones: nombre, lista de parámetros (tipo, nombre, tipo de peso?), devolución
    nombres de tipos
*/

/* Funciones */
void TS_nueva_fila(TS_fila *);
void TS_insertar_celda(TS_fila *, TS_dato);
bool TS_esta_elemento(TS_fila, TS_dato);
bool TS_es_nula_fila(TS_fila);
void TS_concatenar_fila (TS_fila *, TS_fila *);
void TS_imprimir_fila (TS_fila);

#endif