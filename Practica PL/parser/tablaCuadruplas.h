#ifndef DPIS_TC_H
#define DPIS_TC_H

//Defines de las operaciones
#define OP_SUMA_E 1
#define OP_SUMA_R 2
#define OP_RESTA_E 3
#define OP_RESTA_R 4
#define OP_MULTI_E 5
#define OP_MULTI_R 6
#define OP_DIV_E 7
#define OP_DIV_R 8
#define OP_MOD 9
#define OP_MAYOR_IGUAL 10
#define OP_MENOR_IGUAL 11
#define OP_MENOR 12
#define OP_MAYOR 13
#define OP_ASIGNACION 14
#define OP_DISTINTO 15
#define OP_CREACION_TIPO 16
#define OP_ENTONCES 17
#define OP_ACCESO 18
#define OP_SUBRANGO 19
#define OP_INTTOREAL 20

typedef struct tC{
    int nextquad;
    int cuadruplas[100][4];
}tC;

void iniciarTC(tC *t);
void gen(int opr, int op1 ,int op2 ,int sol, tC *t);
void imprimirTablaCuadruplas(tC t);

#endif
