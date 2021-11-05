#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

/* Es la tabla que construimos en los parsers, más o menos */
/* Es una lista de celdas o casillas */
/* Por cada fila tenemos X casillas */
typedef struct TS_celda{
    /* Nombre */
    /* Tipo => Dato (TABLA, TUPLA, PUNTERO, ENTERO, REAL, BOOLEANO, CARACTER O STRING) o Simbolo (VAR, TIPO, CTE, FUNCION, ACCION) */
    /* Id */
    /* Puntero al elemento anterior y al siguiente */
};

typedef struct TS_fila{
    /* Puntero a la primera celda, y a la última celda */
};

/* Este realmente no se si haría falta, ya que creo que se puede ir haciendo de fila en fila, por lo que
creo que no haría falta construirla */
typedef struct TS_lista{
    
};

#endif