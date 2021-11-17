#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#include <stdbool.h>

/* Es la tabla que construimos en los parsers, más o menos */
/* Es una lista de celdas o casillas */
/* Por cada fila tenemos X casillas */

/* DE MOMENTO SOLO VARIABLES*/
enum TS_tipo{
    variable,
    accion, 
    funcion,
    tipo, 
    constante
};

//Empezamos con las variables
typedef struct ts_celda{
    /* Nombre */
    char *nombre;
    /* Ámbito de validez */
    int ambito;
    /* Tipo */
    enum TS_tipo elemento;
    /* Puntero al elemento anterior y al siguiente */
    struct ts_celda *siguiente/*,anterior*/;
}TS_celda;

typedef struct ts_lista{
    /* Puntero a la primera celda, y a la última celda */
    TS_celda *inicio, *final;
}TS_lista;


/* La estructura de datos que se utiliza es un union sobre un struct de un tipo */
/* La tabla de simbolos contiene informacion sobre los simbolos que se utilizan en la programacion. 
Por ejemplo: 
    nombres de variables: nombre, tipo, ámbito de validez
    nombres de constantes: nombre, tipo, valor, ámbito de validez
    nombres de acciones: nombre, lista de parámetros (tipo, nombre, tipo de paso)
    nombres de funciones: nombre, lista de parámetros (tipo, nombre, tipo de paso), devolución
    nombres de tipos
*/

void nuevaLista(TS_lista *);


#endif