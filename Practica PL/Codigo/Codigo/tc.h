#ifndef TC_H
#define TC_H
#include "eaux.h"
#include "ts.h"


struct cuadrupla {
    enum enum_operador   operador;
    int*                 operando1;
    int*                 operando2;
    int*                 resultado;
};
struct TC{
    int                 nextquad;                 // Para saber donde insertar la siguiente cuadrupla. La siguiente posición libre.
    struct cuadrupla    cuadruplas[200];        // Array con todas las cuadruplas
};

void inicializar_TC(struct TC* tabla_cuadruplas);
void insertar_cuadrupla(struct TC* tabla_cuadruplas, enum enum_operador op, int* op1, int* op2, int* resultado);
void backpatch(struct TRUE_FALSE lista, int idCuadrupla, struct TC* tabla_cuadruplas);
void guardar_TC(char* ruta, struct TC tabla_cuadruplas, int errorFlag);
void guardar_CTD(char* ruta, struct TC tabla_cuadruplas, struct FILA_TS* cabeza_TS, int errorFlag);


#endif
