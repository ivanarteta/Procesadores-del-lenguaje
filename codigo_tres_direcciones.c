#include "codigo_tres_direcciones.h"
#include <stdio.h>

void CTD_imprimir(TC_tabla_cuadrupla cuadrupla, TS_lista simbolos){
	int pos = -1;
	int nOut = 0;
	int cont = 0;
    int numOutputs = 0;
    printf("\n\n______________ Codigo en tres direcciones _____________\n");
    for(int i=0; i < cuadrupla.siguiente; i++){
        switch (cuadrupla.cuadruplas[i].operador){
            case OP_INPUT:
                printf("%d input %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1));
                break;
            case OP_OUTPUT:
				if(pos == -1){
					pos = i;
				}
				nOut = nOut + 1;
				cont = cont - 1;
                numOutputs++;
                break;
            case OP_ASIGNACION:
                if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].resultado) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].resultado);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO){
                        printf("%d %s := %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.entero);
                    }else if(celda->tipo == TIPO_BOOLEANO){
                        printf("%d %s := %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), (cte->valor.entero == 1) ? "verdadero" : "falso");
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d %s := %f \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.real);
                    }else if(celda->tipo == TIPO_CADENA || celda->tipo == TIPO_CARACTER){
                        printf("%d %s := %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.caracteres);
                    }
                }else{
                    printf("%d %s := %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado));
                }                   
                break;
            case OP_ASIGNACION_TRUE:
                printf("%d %s := TRUE \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado));
                break;
            case OP_ASIGNACION_FALSE:
                printf("%d %s := FALSE \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado));
                break;
            case OP_SUMA:
                if((TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE) &&
                    (TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE)){
                    TS_celda* celda1 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte1 = (Constante*)celda1->otros;
                    TS_celda* celda2 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte2 = (Constante*)celda2->otros;
                    if((celda1->tipo == TIPO_ENTERO) && (celda2->tipo == TIPO_ENTERO)){
                        printf("%d %s := %d + %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte1->valor.entero, cte2->valor.entero);
                    }else if((celda1->tipo == TIPO_REAL) && (celda2->tipo == TIPO_REAL)){
                        printf("%d %s := %f + %f \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte1->valor.real, cte2->valor.real);
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO){
                        printf("%d %s := %d + %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte->valor.entero, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1));
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d %s := %f + %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte->valor.real, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1));
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO){
                        printf("%d %s := %s + %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.entero);
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d %s := %s + %f \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.real);
                    }
                }else{
                    printf("%d %s := %s + %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2));
                }
                break;
            case OP_RESTA:
                if((TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE) &&
                    (TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE)){
                    TS_celda* celda1 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte1 = (Constante*)celda1->otros;
                    TS_celda* celda2 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte2 = (Constante*)celda2->otros;
                    if((celda1->tipo == TIPO_ENTERO) && (celda2->tipo == TIPO_ENTERO)){
                        printf("%d %s := %d - %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte1->valor.entero, cte2->valor.entero);
                    }else if((celda1->tipo == TIPO_REAL) && (celda2->tipo == TIPO_REAL)){
                        printf("%d %s := %f - %f \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte1->valor.real, cte2->valor.real);
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO){
                        printf("%d %s := %d - %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte->valor.entero, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1));
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d %s := %f - %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte->valor.real, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1));
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO){
                        printf("%d %s := %s - %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.entero);
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d %s := %s - %f \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.real);
                    }
                }else{
                    printf("%d %s := %s - %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2));
                }
                break;
            case OP_MULTIPLICACION:
                if((TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE) &&
                    (TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE)){
                    TS_celda* celda1 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte1 = (Constante*)celda1->otros;
                    TS_celda* celda2 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte2 = (Constante*)celda2->otros;
                    if((celda1->tipo == TIPO_ENTERO) && (celda2->tipo == TIPO_ENTERO)){
                        printf("%d %s := %d * %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte1->valor.entero, cte2->valor.entero);
                    }else if((celda1->tipo == TIPO_REAL) && (celda2->tipo == TIPO_REAL)){
                        printf("%d %s := %f * %f \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte1->valor.real, cte2->valor.real);
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO){
                        printf("%d %s := %d * %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte->valor.entero, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1));
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d %s := %f * %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte->valor.real, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1));
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO){
                        printf("%d %s := %s * %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.entero);
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d %s := %s * %f \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.real);
                    }
                }else{
                    printf("%d %s := %s * %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2));
                }
                break;
            case OP_DIVISION:
                if((TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE) &&
                    (TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE)){
                    TS_celda* celda1 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte1 = (Constante*)celda1->otros;
                    TS_celda* celda2 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte2 = (Constante*)celda2->otros;
                    if((celda1->tipo == TIPO_ENTERO) && (celda2->tipo == TIPO_ENTERO)){
                        printf("%d %s := %d / %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte1->valor.entero, cte2->valor.entero);
                    }else if((celda1->tipo == TIPO_REAL) && (celda2->tipo == TIPO_REAL)){
                        printf("%d %s := %f / %f \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte1->valor.real, cte2->valor.real);
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO){
                        printf("%d %s := %d / %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte->valor.entero, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1));
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d %s := %f / %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte->valor.real, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1));
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO){
                        printf("%d %s := %s / %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.entero);
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d %s := %s / %f \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.real);
                    }
                }else{
                    printf("%d %s := %s / %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2));
                }
                break;
            case OP_MOD:
                if((TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE) &&
                    (TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE)){
                    TS_celda* celda1 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte1 = (Constante*)celda1->otros;
                    TS_celda* celda2 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte2 = (Constante*)celda2->otros;
                    if((celda1->tipo == TIPO_ENTERO) && (celda2->tipo == TIPO_ENTERO)){
                        printf("%d %s := %d mod %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte1->valor.entero, cte2->valor.entero);
                    }else if((celda1->tipo == TIPO_REAL) && (celda2->tipo == TIPO_REAL)){
                        printf("%d %s := %f mod %f \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte1->valor.real, cte2->valor.real);
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO){
                        printf("%d %s := %d mod %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte->valor.entero, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1));
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d %s := %f mod %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte->valor.real, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1));
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO){
                        printf("%d %s := %s mod %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.entero);
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d %s := %s mod %f \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.real);
                    }
                }else{
                    printf("%d %s := %s mod %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2));
                }
                break;
            case OP_DIV:
                if((TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE) &&
                    (TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE)){
                    TS_celda* celda1 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte1 = (Constante*)celda1->otros;
                    TS_celda* celda2 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte2 = (Constante*)celda2->otros;
                    if((celda1->tipo == TIPO_ENTERO) && (celda2->tipo == TIPO_ENTERO)){
                        printf("%d %s := %d div %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte1->valor.entero, cte2->valor.entero);
                    }else if((celda1->tipo == TIPO_REAL) && (celda2->tipo == TIPO_REAL)){
                        printf("%d %s := %f div %f \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte1->valor.real, cte2->valor.real);
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO){
                        printf("%d %s := %d div %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte->valor.entero, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1));
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d %s := %f div %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte->valor.real, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1));
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO){
                        printf("%d %s := %s div %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.entero);
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d %s := %s div %f \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.real);
                    }
                }else{
                    printf("%d %s := %s div %s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2));
                }
                break;
            case OP_INT_TO_REAL:
                if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO){
                        printf("%d %s := int_to_real %d \n", cont,TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte->valor.entero);
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d %s := int_to_real %f \n", cont,TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte->valor.real);
                    }
                }else{
                    printf("%d %s := int_to_real %s \n", cont,TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1));
                }
                
                break;
            case OP_RESTA_UNARIA:
                if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO){
                        printf("%d %s := -%d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte->valor.entero);
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d %s := -%f  \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), cte->valor.real);
                    }
                }else{
                    printf("%d %s := -%s \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].resultado), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1));
                }
                break;
            case OP_GOTO:
                printf("%d goto %d \n", cont, cuadrupla.cuadruplas[i].resultado - numOutputs);
                break;
            case OP_GOTO_IGUAL:
                if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE &&
                    TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE){
                    TS_celda* celda1 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte1 = (Constante*)celda1->otros;
                    TS_celda* celda2 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte2 = (Constante*)celda2->otros;
                    if(celda1->tipo == TIPO_ENTERO && celda2->tipo == TIPO_ENTERO){
                        printf("%d if %d = %d goto %d \n", cont, cte1->valor.entero, cte2->valor.entero, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }else if(celda1->tipo == TIPO_REAL && celda2->tipo == TIPO_REAL){
                        printf("%d if %f = %f goto %d \n", cont, cte1->valor.real, cte2->valor.real, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO ){
                        printf("%d if %d = %s goto %d \n", cont, cte->valor.entero, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2), cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d if %f = %s goto %d \n", cont, cte->valor.real, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2), cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO ){
                        printf("%d if %s = %d goto %d \n", cont,TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.entero, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d if %s = %f goto %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.real, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }
                }else{
                    printf("%d if %s = %s goto %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2), cuadrupla.cuadruplas[i].resultado - numOutputs);
                }
                break;
            case OP_GOTO_DISTINTO:
                if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE &&
                    TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE){
                    TS_celda* celda1 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte1 = (Constante*)celda1->otros;
                    TS_celda* celda2 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte2 = (Constante*)celda2->otros;
                    if(celda1->tipo == TIPO_ENTERO && celda2->tipo == TIPO_ENTERO){
                        printf("%d if %d <> %d goto %d \n", cont, cte1->valor.entero, cte2->valor.entero, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }else if(celda1->tipo == TIPO_REAL && celda2->tipo == TIPO_REAL){
                        printf("%d if %f <> %f goto %d \n", cont, cte1->valor.real, cte2->valor.real, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO ){
                        printf("%d if %d <> %s goto %d \n", cont, cte->valor.entero, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2), cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d if %f <> %s goto %d \n", cont, cte->valor.real, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2), cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO ){
                        printf("%d if %s <> %d goto %d \n", cont,TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.entero, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d if %s <> %f goto %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.real, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }
                }else{
                    printf("%d if %s <> %s goto %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2), cuadrupla.cuadruplas[i].resultado - numOutputs);
                }
                break;
            case OP_GOTO_MENOR:
                if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE &&
                    TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE){
                    TS_celda* celda1 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte1 = (Constante*)celda1->otros;
                    TS_celda* celda2 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte2 = (Constante*)celda2->otros;
                    if(celda1->tipo == TIPO_ENTERO && celda2->tipo == TIPO_ENTERO){
                        printf("%d if %d < %d goto %d \n", cont, cte1->valor.entero, cte2->valor.entero, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }else if(celda1->tipo == TIPO_REAL && celda2->tipo == TIPO_REAL){
                        printf("%d if %f < %f goto %d \n", cont, cte1->valor.real, cte2->valor.real, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO ){
                        printf("%d if %d < %s goto %d \n", cont, cte->valor.entero, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2), cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d if %f < %s goto %d \n", cont, cte->valor.real, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2), cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO ){
                        printf("%d if %s < %d goto %d \n", cont,TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.entero, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d if %s < %f goto %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.real, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }
                }else{
                    printf("%d if %s < %s goto %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2), cuadrupla.cuadruplas[i].resultado - numOutputs);
                }
                break;
            case OP_GOTO_MAYOR:
                if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE &&
                    TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE){
                    TS_celda* celda1 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte1 = (Constante*)celda1->otros;
                    TS_celda* celda2 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte2 = (Constante*)celda2->otros;
                    if(celda1->tipo == TIPO_ENTERO && celda2->tipo == TIPO_ENTERO){
                        printf("%d if %d > %d goto %d \n", cont, cte1->valor.entero, cte2->valor.entero, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }else if(celda1->tipo == TIPO_REAL && celda2->tipo == TIPO_REAL){
                        printf("%d if %f > %f goto %d \n", cont, cte1->valor.real, cte2->valor.real, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO ){
                        printf("%d if %d > %s goto %d \n", cont, cte->valor.entero, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2), cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d if %f > %s goto %d \n", cont, cte->valor.real, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2), cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO ){
                        printf("%d if %s > %d goto %d \n", cont,TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.entero, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d if %s > %f goto %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.real, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }
                }else{
                    printf("%d if %s > %s goto %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2), cuadrupla.cuadruplas[i].resultado - numOutputs);
                }
                break;
            case OP_GOTO_MENOR_O_IGUAL:
                if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE &&
                    TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE){
                    TS_celda* celda1 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte1 = (Constante*)celda1->otros;
                    TS_celda* celda2 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte2 = (Constante*)celda2->otros;
                    if(celda1->tipo == TIPO_ENTERO && celda2->tipo == TIPO_ENTERO){
                        printf("%d if %d <= %d goto %d \n", cont, cte1->valor.entero, cte2->valor.entero, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }else if(celda1->tipo == TIPO_REAL && celda2->tipo == TIPO_REAL){
                        printf("%d if %f <= %f goto %d \n", cont, cte1->valor.real, cte2->valor.real, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO ){
                        printf("%d if %d <= %s goto %d \n", cont, cte->valor.entero, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2), cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d if %f <= %s goto %d \n", cont, cte->valor.real, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2), cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO ){
                        printf("%d if %s <= %d goto %d \n", cont,TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.entero, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d if %s <= %f goto %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.real, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }
                }else{
                    printf("%d if %s <= %s goto %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2), cuadrupla.cuadruplas[i].resultado - numOutputs);
                }
                break;
            case OP_GOTO_MAYOR_O_IGUAL:
                if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE &&
                    TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE){
                    TS_celda* celda1 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte1 = (Constante*)celda1->otros;
                    TS_celda* celda2 = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte2 = (Constante*)celda2->otros;
                    if(celda1->tipo == TIPO_ENTERO && celda2->tipo == TIPO_ENTERO){
                        printf("%d if %d >= %d goto %d \n", cont, cte1->valor.entero, cte2->valor.entero, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }else if(celda1->tipo == TIPO_REAL && celda2->tipo == TIPO_REAL){
                        printf("%d if %f >= %f goto %d \n", cont, cte1->valor.real, cte2->valor.real, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando1) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando1);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO ){
                        printf("%d if %d >= %s goto %d \n", cont, cte->valor.entero, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2), cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d if %f >= %s goto %d \n", cont, cte->valor.real, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2), cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }
                }else if(TS_consulta_tipo_simbolo(simbolos, cuadrupla.cuadruplas[i].operando2) == TS_CONSTANTE){
                    TS_celda* celda = TS_devolver_celda(simbolos, cuadrupla.cuadruplas[i].operando2);
                    Constante* cte = (Constante*)celda->otros;
                    if(celda->tipo == TIPO_ENTERO ){
                        printf("%d if %s >= %d goto %d \n", cont,TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.entero, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }else if(celda->tipo == TIPO_REAL){
                        printf("%d if %s >= %f goto %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), cte->valor.real, cuadrupla.cuadruplas[i].resultado - numOutputs);
                    }
                }else{
                    printf("%d if %s >= %s goto %d \n", cont, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando1), TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[i].operando2), cuadrupla.cuadruplas[i].resultado - numOutputs);
                }
                break;
            default:
                printf("Entro en default\n");
                break;
        }
        cont = cont + 1;
    }

    // Bucle para imprimir el output al final
    for(int i=0; i < nOut; i++){
		printf("%d output %s \n", cont + i, TS_buscar_nombre(simbolos, cuadrupla.cuadruplas[pos + i].operando1));
	}
}
