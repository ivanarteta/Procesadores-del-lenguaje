#include "codigo_tres_direcciones.h"
#include <stdio.h>

void CTD_imprimir(TC_tabla_cuadrupla *cuadrupla, TS_lista *simbolos){
    printf("\n\n______________ Codigo en tres direcciones _____________\n");
    for(int i=0; i < cuadrupla->siguiente; i++){
        switch (cuadrupla->cuadruplas[i].operador){
            case OP_INPUT:
                printf("%d input %s \n", i+1, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1));
                break;
            case OP_OUTPUT:
                printf("%d output %s \n", i+1, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1));
                break;
            case OP_ASIGNACION:
                printf("%d %s := %s \n", i+1, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].resultado));
                break;
            case OP_ASIGNACION_TRUE:
                break;
            case OP_ASIGNACION_FALSE:
                break;
            case OP_SUMA:
                break;
            case OP_RESTA:
                printf("%d %s := %s - %s \n", i+1, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando2));
                break;
            case OP_MULTIPLICACION:
                printf("%d %s := %s * %s \n", i+1, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando2));
                break;
            case OP_DIVISION:
                break;
            case OP_MOD:
                break;
            case OP_DIV:
                break;
            case OP_IGUAL:
                break;
            case OP_OPERADORES_RELACIONALES:
                break;
            case OP_NO:
                break;
            case OP_Y:
                break;
            case OP_O:
                break;
            case OP_INT_TO_REAL:
                break;
            case OP_REAL_TO_INT:
                break;
            case OP_RESTA_UNARIA_ENTERO:
                break;
            case OP_RESTA_UNARIA_REAL:
                break;
            case OP_GOTO:
                printf("%d goto %d \n", i+1, cuadrupla->cuadruplas[i].resultado);
                break;
            case OP_GOTO_IGUAL:
                break;
            case OP_GOTO_DISTINTO:
                break;
            case OP_GOTO_MENOR:
                break;
            case OP_GOTO_MAYOR:
                break;
            case OP_GOTO_MENOR_O_IGUAL:
                break;
            case OP_GOTO_MAYOR_O_IGUAL:
                break;
            
            default:
                break;
        }
    }
}