#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#include <stdbool.h>
#include "definiciones.h"

// Estructura para almacenar el valor de las constantes
typedef struct constante_valor{
    union{
        int entero; // Para enteros y booleanos
        float real; // Para reales
        char* caracteres; // Para caracteres y cadenas
    };
}Constante_valor;

// Estructura para las constantes
typedef struct constante{
    Constante_valor valor;
}Constante;

// Estructura para los parametros de acciones/funciones
typedef struct params{
    int id;
    int tipoPaso; // 1 Para entrada, 2 para salida, 3 para entrada/salida  y 4 para dev en funciones
}Params;

// Estructura para las acciones/funciones
typedef struct accion_funcion{
    Params params[10];
    int contador; // Para saber cuantos hay añadidos
}AccionFuncion;

// Estructura para la celda de la tabla
typedef struct ts_celda{
    int tipo; // Tipo será entero, real, booleano, caracter o cadena
    int ambito; // El ambito que tiene la celda
    int id; // Para la posición en la tabla
    int tipo_simbolo; // Tipo del símbolo, que será var, const, accion, función, ...
    char* nombre; // Nombre del elemento
    void* otros; // Al ser void se le asignarán de otro tipo de estructuras los datos.
    struct ts_celda *siguiente; /* Puntero al elemento anterior y al siguiente */
}TS_celda;

// Estructura para la tabla
typedef struct ts_lista{
    int contador; // Para el nombre de las variables temporales
    TS_celda *inicio , *final;
}TS_lista;

// Devuelve la fila de la tabla en la posición indicada
TS_celda* TS_devolver_celda(TS_lista, int);

// Genera una lista vacía
void TS_nuevaLista(TS_lista *);

// Crea un simbolo nuevo
int TS_new(TS_lista *, TS_celda *, int);

// Inserta un simbolo a la TS
int TS_insertar(TS_lista *, char*, int);

// Modifica el tipo de la fila indicada
void TS_modificar_tipo(TS_lista *, int , int, int); //Nombre, tipo (entero, real,...) y tipo de simbolo (var, cte, ...)

// Combrueba si la lista está vacía
bool TS_esVacio(TS_lista);

// Devuelve el nombre de una fila
char* TS_buscar_nombre(TS_lista, int);

// Devuelve el tipo de una fila
int TS_consulta_tipo(TS_lista, int);

// Devuelve el tipo de simbolo de una fila
int TS_consulta_tipo_simbolo(TS_lista, int);

// Comprueba si existe una fila con ese nombre en la tabla
bool TS_buscar(TS_lista, char *, int);

// Devuelve el id de de la fila con el mismo nombre y ámbito
int TS_buscar_id(TS_lista, char *, int);

// Imprime la tabla de símbolos
void TS_imprimir(TS_lista);

// Inserta un parámetro en la TS
void TS_insertar_param(TS_lista *, int, int , int , int );

// Vacia la tabla
void TS_vaciar(TS_lista *);

/* Funciones para las variables */
// Crear nueva variable temporal
int TS_newtempt(TS_lista *, int);

/* Funciones para las constantes */
// Crear nueva constante
int TS_newConst(TS_lista *, int);

// Modifica el valor de una constante
void TS_modificar_valor_cte(TS_lista *, int, Constante_valor);

// Imprime una constante
void TS_imprimir_cte(TS_celda);

int TS_buscar_const(TS_lista, int, int, int, Constante_valor);

#endif