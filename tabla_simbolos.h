#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#include <stdbool.h>
#include "definiciones.h" //Solo si en el struct hacemos referencia al enum_tipo

typedef struct constante_valor{
    union{
        int entero; //Para enteros y booleanos
        float real;
        char* caracteres; //Para char y cadenas
    };
}Constante_valor;

typedef struct constante{
    Constante_valor valor;
}Constante;

typedef struct params{
    int id;
    int tipoPaso; //1 Para entrada, 2 para salida, 3 para entrada salida  y 4 para dev en funciones
}Params;

typedef struct accion_funcion{
    Params params[10];
    int contador; //Para saber cuantos hay añadidos
}AccionFuncion;

typedef struct ts_celda{
    int tipo; //Tipo será entero, real, booleano, caracter o cadena
    int ambito;
    int id; //Para la posición
    int tipo_simbolo; //Tipo del símbolo, que será var, const, accion, función, ...
    char* nombre;
    void* otros; //Al ser void se le asignarán de otro tipo de estructuras los datos.
    struct ts_celda *siguiente; /* Puntero al elemento anterior y al siguiente */
}TS_celda;

typedef struct ts_lista{
    int contador; //Para cuando hagamos las variables temporales saber por cual vamos
    TS_celda *inicio , *final;
}TS_lista;

/* Funciones para todo */
TS_celda* TS_devolver_celda(TS_lista, int);
void TS_nuevaLista(TS_lista *); //Para generar la lista vacía
int TS_new(TS_lista *, TS_celda *, int); //Funcion con codigo común para crear cualquier tipo de simbolo
int TS_insertar(TS_lista *, char*, int); // Para insertar cualquier tipo de simbolo a la TS
void TS_modificar_tipo(TS_lista *, int , int, int); //Nombre, tipo (entero, real,...) y tipo de simbolo (var, cte, ...)
bool TS_esVacio(TS_lista); //Para comprobar si está vacía la lista
char* TS_buscar_nombre(TS_lista, int);
int TS_consulta_tipo(TS_lista, int);
int TS_consulta_tipo_simbolo(TS_lista, int);
bool TS_buscar(TS_lista, char *, int); //Busca si existe un nombre en la tabla o no
int TS_buscar_id(TS_lista, char *, int);
bool comprobarTipo(TS_celda *, char *);
void TS_imprimir(TS_lista); //Para mostrar la tabla de símbolos
void TS_insertar_param(TS_lista *, int, int , int , int );

/* Funciones para las variables */
int TS_newtempt(TS_lista *, int);

/* Funciones para las constantes */
int TS_newConst(TS_lista *, int);
void TS_modificar_valor_cte(TS_lista *, int, Constante_valor);
void TS_imprimir_cte(TS_celda);

#endif