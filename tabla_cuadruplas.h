#ifndef TABLA_CUADRUPLAS_H
#define TABLA_CUADRUPLAS_H

#include "definiciones.h"

/* Podemos crear una lista con defines para todos los posibles operadores de las cuádruplas */
/* O bien definir un enum con los valores de los posibles operadores */

/* Lo que tiene una cuadrupla es un campo para el operador, un campo para cada operando y una para el resultado*/
typedef struct TC_cuadrupla{
    /* Operador */
    int operador; //ASIGNACION POR EJEMPLO
    /* Argumento 1 o primer operando */
    int* operando1;
    /* Argumento 2 o segundo operando */
    int* operando2;
    /* Resultado */
    int* resultado;
}TC_cuadrupla;

/* Definición de la tabla cuadrupla */
typedef struct TC_tabla_cuadrupla{
    int siguiente;
    struct TC_cuadrupla cuadruplas[256];
}TC_tabla_cuadrupla;

void TC_nuevaLista(TC_tabla_cuadrupla *);

void TC_insertar(TC_tabla_cuadrupla *, TC_cuadrupla *); //Es la función gen
TC_cuadrupla* TC_crear_cuadrupla(int, int *, int *, int *);

void TC_imprimir(TC_tabla_cuadrupla *);

void TC_imprimir_C3D(TC_tabla_cuadrupla *);

//void backpatch();

//void merge();


#endif