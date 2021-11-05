#ifndef TABLA_CUADRUPLAS_H
#define TABLA_CUADRUPLAS_H

/* Podemos crear una lista con defines para todos los posibles operadores de las cuádruplas */
/* O bien definir un enum con los valores de los posibles operadores */


/* Lo que tiene una cuadrupla es un campo para el operador, un campo para cada operando y una para el resultado*/
typedef struct TC_cuadrupla{
    /* Operador */
    /* Argumento 1 o primer operando */
    /* Argumento 2 o segundo operando */
    /* Resultado */
};

/* Definición de la tabla cuadrupla */
typedef struct TC_tabla_cuadrupla{
    /* Puntero al siguiente elemento vacío donde se puede insertar la cuádrupla */
    /* Referencia a la cuádrupla */
};

/* Se puede hacer así o bien todo en un struct: CONSULTAR CON EL EQUIPO COMO QUIEREN HACERLO */

#endif