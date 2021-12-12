#include "tabla_cuadruplas.h"
#include "definiciones.h"
#include "cola.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void TC_nuevaLista(TC_tabla_cuadrupla *elemento){
    elemento->siguiente = 0;
}

TC_cuadrupla* TC_crear_cuadrupla(int operador, int op1, int op2, int resultado){
    TC_cuadrupla *cuadrupla;
    cuadrupla = (TC_cuadrupla*)malloc(sizeof(TC_cuadrupla));
    cuadrupla->operador = operador;
    cuadrupla->operando1 =  op1;
    cuadrupla->operando2 =  op2;
    cuadrupla->resultado = resultado;
    return cuadrupla;
}

void TC_insertar(TC_tabla_cuadrupla *tabla, TC_cuadrupla *cuadrupla){
    tabla->cuadruplas[tabla->siguiente] = *cuadrupla;
    tabla->siguiente++;
}

char *parse(int elemento){
    char aux[10];
    if(elemento == -1){
        strcpy(aux, "(null)");
    }else{
        sprintf(aux, "%d", elemento);
    }
    return strdup(aux);
}

int TC_elemento_siguiente(TC_tabla_cuadrupla tabla){
    return tabla.siguiente;
}

void backpatch(TC_tabla_cuadrupla *tabla, Cola *cola, int quad){
    while(!esNulaCola(*cola)){
        tabla->cuadruplas[primeroCola(*cola)].resultado = quad;
        avanceCola(cola);
    }
}

Cola merge(Cola cola1, Cola cola2){
    Cola aux;
    cola1.f->s = cola2.i;
    aux = cola1;
    return aux;
}

char* mostrar_operador(int operador){
    switch (operador){
        case OP_INPUT:
            return "Input";
        case OP_OUTPUT:
            return "Output";
        case OP_ASIGNACION:
            return ":=";
        case OP_ASIGNACION_FALSE:
            return ":= false";
        case OP_ASIGNACION_TRUE:
            return ":= true";
        case OP_SUMA:
            return "+";
        case OP_RESTA:
            return "-";
        case OP_MULTIPLICACION:
            return "*";
        case OP_DIVISION:
            return "/";
        case OP_MOD:
            return "mod";
        case OP_DIV:
            return "div";
        case OP_INT_TO_REAL:
            return "IntToReal";
        case OP_GOTO:
            return "goto";
        case OP_GOTO_IGUAL:
            return "=";
        case OP_GOTO_DISTINTO:
            return "<>";
        case OP_GOTO_MENOR:
            return "<";
        case OP_GOTO_MAYOR:
            return ">";
        case OP_GOTO_MENOR_O_IGUAL:
            return "<=";
        case OP_GOTO_MAYOR_O_IGUAL:
            return ">=";
        default:
            return NULL;
    }
}

void TC_imprimir(TC_tabla_cuadrupla tabla){
    printf("\n\n______________ Contenido de la tabla de cuadruplas _____________\n");
	printf("%5s %25s %25s %25s %25s \n", "ID", "OPERADOR", "OPERANDO1", "OPERANDO2", "RESULTADO");
    /* Recorremos todos los elementos de la tabla */
    for(int i=0; i < tabla.siguiente; i++){
        printf("%5d %25s %25s %25s %25s \n", i, mostrar_operador(tabla.cuadruplas[i].operador), parse(tabla.cuadruplas[i].operando1), parse(tabla.cuadruplas[i].operando2), parse(tabla.cuadruplas[i].resultado));
    }
}