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

typedef struct ts_celda{
    int tipo; //Tipo será entero, real, booleano, caracter o cadena
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

/* FUNCIONES */
void TS_nuevaLista(TS_lista *); //Para generar la lista vacía
int TS_insertar(TS_lista *, char*);
void TS_modificar_tipo(TS_lista *, int , int, int); //Nombre, tipo (entero, real,...) y tipo de simbolo (var, cte, ...)
int TS_consulta_tipo(TS_lista *, int);
int TS_consulta_tipo_simbolo(TS_lista *, int);
int TS_buscar_id(TS_lista *, char *);
int TS_newtempt(TS_lista *);
void TS_modificar_valor_cte(TS_lista *, char *, Constante_valor);
bool TS_buscar(TS_lista *, char *); //Busca si existe un nombre en la tabla o no
bool comprobarTipo(TS_celda *, char *);
bool TS_esVacio(TS_lista *); //Para comprobar si está vacía la lista
void TS_imprimir(TS_lista *); //Para mostrar la tabla de símbolos
char* TS_buscar_nombre(TS_lista *, int);

#endif