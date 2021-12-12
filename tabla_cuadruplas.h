#ifndef TABLA_CUADRUPLAS_H
#define TABLA_CUADRUPLAS_H

#include "definiciones.h"
#include "cola.h"
#include <stdbool.h>

/* Podemos crear una lista con defines para todos los posibles operadores de las cuádruplas */
/* O bien definir un enum con los valores de los posibles operadores */

/* Lo que tiene una cuadrupla es un campo para el operador, un campo para cada operando y una para el resultado*/
typedef struct TC_cuadrupla{
    /* Operador */
    int operador;
    /* Argumento 1 o primer operando */
    int operando1;
    /* Argumento 2 o segundo operando */
    int operando2;
    /* Resultado */
    int resultado;
}TC_cuadrupla;

/* Definición de la tabla cuadrupla */
typedef struct TC_tabla_cuadrupla{
    int siguiente;
    struct TC_cuadrupla cuadruplas[256];
}TC_tabla_cuadrupla;

// Crear nueva lista
void TC_nuevaLista(TC_tabla_cuadrupla *);

// Crear cuadrupla con los parámetros que se le pasan
TC_cuadrupla* TC_crear_cuadrupla(int, int, int, int);

// Insertar fila en la tabla (funcion gen())
void TC_insertar(TC_tabla_cuadrupla *, TC_cuadrupla *);

// Imprimir la tabla
void TC_imprimir(TC_tabla_cuadrupla);

// Devuelve la posicion de la siguiente cuádrupla que se va a insertar (nextquad)
int TC_elemento_siguiente(TC_tabla_cuadrupla);

// Añade el destino a los saltos de la cola
void backpatch(TC_tabla_cuadrupla *, Cola *, int);

// Une dos colas
Cola merge(Cola , Cola);

// Como esta tabla es estática, no hace falta liberarla

#endif