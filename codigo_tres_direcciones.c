#include "codigo_tres_direcciones.h"
#include <stdio.h>

void CTD_imprimir(TC_tabla_cuadrupla *cuadrupla, TS_lista *simbolos){
	int pos = -1;
	int nOut = 0;
	int cont = 0;
    printf("\n\n______________ Codigo en tres direcciones _____________\n");
    for(int i=0; i < cuadrupla->siguiente; i++){
        switch (cuadrupla->cuadruplas[i].operador){
            case OP_INPUT:
                printf("%d input %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1));
                break;
            case OP_OUTPUT:
				if(pos == -1){
					pos = i;
				}
				nOut = nOut + 1;
				cont = cont - 1;
                //printf("%d output %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1));
                break;
            case OP_ASIGNACION:
                printf("%d %s := %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].resultado));            
                break;
            case OP_ASIGNACION_TRUE:
                printf("%d %s := TRUE \n", cont, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].resultado));
                break;
            case OP_ASIGNACION_FALSE:
                printf("%d %s := FALSE \n", cont, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].resultado));
                break;
            case OP_ASIGNACION_ENTERO:
                printf("%d %s := %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1), cuadrupla->cuadruplas[i].resultado);
                break;
            case OP_SUMA:
                printf("%d %s := %s + %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando2));
                break;
            case OP_RESTA:
                printf("%d %s := %s - %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando2));
                break;
            case OP_MULTIPLICACION:
                printf("%d %s := %s * %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando2));
                break;
            case OP_DIVISION:
                printf("%d %s := %s / %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando2));
                break;
            case OP_MOD:
                printf("%d %s := %s mod %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando2));
                break;
            case OP_DIV:
                printf("%d %s := %s / %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando2));
                break;
            case OP_IGUAL:
                printf("Entro en OP_IGUAL\n");
                //printf("%d %s := %s * %s \n", cont+1, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando2));
                break;
            /*case OP_OPERADORES_RELACIONALES:
                printf("Entro en OP_OPERADORES_RELACIONALES\n");
                break;*/
            case OP_NO:
                printf("Entro en OP_NO\n");
                break;
            case OP_Y:
                printf("Entro en OP_Y\n");
                break;
            case OP_O:
                printf("Entro en OP_O\n");
                break;
            case OP_INT_TO_REAL:
                printf("Entro en OP_INT_TO_REAL\n");
                break;
            case OP_REAL_TO_INT:
                printf("Entro en OP_REAL_TO_INT\n");
                break;
            case OP_RESTA_UNARIA_ENTERO:
                printf("Entro en OP_RESTA_UNARIA_ENTERO\n");
                break;
            case OP_RESTA_UNARIA_REAL:
                printf("Entro en OP_RESTA_UNARIA_REAL\n");
                break;
            case OP_GOTO:
                printf("%d goto %d \n", cont, cuadrupla->cuadruplas[i].resultado);
                break;
            case OP_GOTO_IGUAL:
                printf("%d if %s = %s goto %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando2), cuadrupla->cuadruplas[i].resultado);
                break;
            case OP_GOTO_DISTINTO:
                printf("%d if %s <> %s goto %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando2), cuadrupla->cuadruplas[i].resultado);
                break;
            case OP_GOTO_MENOR:
                printf("%d if %s < %s goto %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando2), cuadrupla->cuadruplas[i].resultado);
                break;
            case OP_GOTO_MAYOR:
                printf("%d if %s > %s goto %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando2), cuadrupla->cuadruplas[i].resultado);
                break;
            case OP_GOTO_MENOR_O_IGUAL:
                printf("%d if %s <= %s goto %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando2), cuadrupla->cuadruplas[i].resultado);
                break;
            case OP_GOTO_MAYOR_O_IGUAL:
                printf("%d if %s >= %s goto %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[i].operando2), cuadrupla->cuadruplas[i].resultado);
                break;
            default:
                printf("Entro en default\n");
                break;
        }
        cont = cont + 1;
    }
    for(int i=0; i < nOut; i++){
		printf("%d output %s \n", cont + i, TS_buscar_nombre(simbolos, cuadrupla->cuadruplas[pos + i].operando1));
	}
}
