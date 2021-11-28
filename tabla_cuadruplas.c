#include "tabla_cuadruplas.h"
#include "definiciones.h"
#include "cola.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void TC_nuevaLista(TC_tabla_cuadrupla *elemento){
    elemento->siguiente = 0;
}

TC_cuadrupla* TC_crear_cuadrupla(int operador, char *op1, char *op2, char *resultado){
    TC_cuadrupla *cuadrupla;
    cuadrupla = (TC_cuadrupla*)malloc(sizeof(TC_cuadrupla));
    cuadrupla->operador = operador;
    cuadrupla->operando1 = op1;
    cuadrupla->operando2 = op2;
    cuadrupla->resultado = (resultado == NULL) ? resultado : strdup(resultado);
    return cuadrupla;
}

void TC_insertar(TC_tabla_cuadrupla *tabla, TC_cuadrupla *cuadrupla){
    tabla->cuadruplas[tabla->siguiente] = *cuadrupla;
    tabla->siguiente++;
}

char* mostrar_operador(int operador){
    switch (operador){
        case OP_INPUT:
            return "Input";
        case OP_OUTPUT:
            return "Output";
        case OP_ASIGNACION:
            return ":=";
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
        case OP_IGUAL:
            return "=";
        case OP_OPERADORES_RELACIONALES:
            return "Oprel";
        case OP_INT_TO_REAL:
            return "IntToReal";
        case OP_RESTA_UNARIA_ENTERO:
            return "-ent";
        case OP_RESTA_UNARIA_REAL:
            return "-real";
        case OP_ASIGNACION_FALSE:
            return ":= false";
        case OP_ASIGNACION_TRUE:
            return ":= true";
        case OP_GOTO:
            return "goto";
        default:
            break;
    }
}

void TC_imprimir(TC_tabla_cuadrupla *tabla){
    printf("\n\n______________ Contenido de la tabla de cuadruplas _____________\n");
	printf("%5s %25s %25s %25s %25s \n", "ID", "OPERADOR", "OPERANDO1", "OPERANDO2", "RESULTADO");
    /* Recorremos todos los elementos de la tabla */
    for(int i=0; i < tabla->siguiente; i++){
        printf("%5d %25s %25s %25s %25s \n", i, mostrar_operador(tabla->cuadruplas[i].operador), tabla->cuadruplas[i].operando1, tabla->cuadruplas[i].operando2, tabla->cuadruplas[i].resultado);
    }
}

void TC_imprimir_C3D(TC_tabla_cuadrupla *tabla){
    printf("\n\n______________ Codigo en tres direcciones _____________\n");
    for(int i=0; i < tabla->siguiente; i++){
        switch (tabla->cuadruplas[i].operador){
            case OP_INPUT:
                printf("%d input %s \n", i+1, tabla->cuadruplas[i].operando1);
                break;
            case OP_OUTPUT:
                printf("%d output %s \n", i+1, tabla->cuadruplas[i].operando1);
                break;
            case OP_ASIGNACION:
                printf("%d %s := %s \n", i+1, tabla->cuadruplas[i].operando1, tabla->cuadruplas[i].resultado);
                break;
            default:
                break;
        }
    }
    

    

}

int TC_elemento_siguiente(TC_tabla_cuadrupla *tabla){
    return tabla->siguiente;
}

void backpatch(TC_tabla_cuadrupla *tabla, Cola *cola, char* quad){
    while(!esNulaCola(*cola)){
        printf("BACKPACH %d \n", primeroCola(*cola));
        tabla->cuadruplas[primeroCola(*cola)].resultado = quad;
        avanceCola(cola);
    }
}

Cola* TC_crear_lista(int quad){
    /*Cola *cola;
    nuevaCola(cola);
    pideTurnoCola(cola, quad);
    return cola;*/
}

Cola* merge(Cola *cola1, Cola *cola2){
    /*Cola *aux;
    TC_insertar_otra_lista(aux, *cola1);
    TC_insertar_otra_lista(aux, *cola2);
    return aux;*/
}

void TC_insertar_otra_lista(Cola *final, Cola cola){
    /*while(!esNulaCola(cola)){
        pideTurnoCola(final, primeroCola(cola));
        avanceCola(&cola);
    }*/
}