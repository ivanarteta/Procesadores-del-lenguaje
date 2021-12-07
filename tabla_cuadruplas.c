#include "tabla_cuadruplas.h"
#include "definiciones.h"
#include "cola.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ROJO "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET "\x1b[0m"

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
    //printf(ROJO"%d %d %d %d \n"RESET, cuadrupla->operador, cuadrupla->operando1, cuadrupla->operando2, cuadrupla->resultado);
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

int TC_elemento_siguiente(TC_tabla_cuadrupla *tabla){
    return tabla->siguiente;
}

void backpatch(TC_tabla_cuadrupla *tabla, Cola *cola, int quad){
    
    while(!esNulaCola(*cola)){
        printf(CYAN"Modificar registro %d asignandole %d \n"RESET, primeroCola(*cola), quad);
        /*if(tabla->cuadruplas[primeroCola(*cola)].operador == OP_GOTO
            || tabla->cuadruplas[primeroCola(*cola)].operador == OP_GOTO_MAYOR_O_IGUAL 
            || tabla->cuadruplas[primeroCola(*cola)].operador == OP_GOTO_MENOR
            || tabla->cuadruplas[primeroCola(*cola)].operador == OP_GOTO_MENOR_O_IGUAL
            || tabla->cuadruplas[primeroCola(*cola)].operador == OP_GOTO_MAYOR
            || tabla->cuadruplas[primeroCola(*cola)].operador == OP_GOTO_DISTINTO
            || tabla->cuadruplas[primeroCola(*cola)].operador == OP_GOTO_IGUAL){*/
            tabla->cuadruplas[primeroCola(*cola)].resultado = quad;
        //}
        //if(primeroCola(*cola) <= tabla->siguiente){
            
        //}
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
        //case OP_ASIGNACION_ENTERO:
          //  return ":= (entero)";
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
        //case OP_IGUAL:
        //    return "=";
        //case OP_NO:
          //  return "no";
        //case OP_Y:
         //   return "y";
        //case OP_O:
         //   return "o";
        case OP_INT_TO_REAL:
            return "IntToReal";
        //case OP_RESTA_UNARIA_ENTERO:
          //  return "-ent";
        //case OP_RESTA_UNARIA_REAL:
          //  return "-real";
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

void TC_imprimir(TC_tabla_cuadrupla *tabla){
    printf("\n\n______________ Contenido de la tabla de cuadruplas _____________\n");
	printf("%5s %25s %25s %25s %25s \n", "ID", "OPERADOR", "OPERANDO1", "OPERANDO2", "RESULTADO");
    /* Recorremos todos los elementos de la tabla */
    for(int i=0; i < tabla->siguiente; i++){
        /*if((strcmp(mostrar_operador(tabla->cuadruplas[i].operador),"goto")==0) && (tabla->cuadruplas[i].resultado == -1)){
            tabla->cuadruplas[i].resultado = TC_elemento_siguiente(tabla);
        }*/
        //printf("%5d %25s %25d %25d %25d \n", i, mostrar_operador(tabla->cuadruplas[i].operador), tabla->cuadruplas[i].operando1, tabla->cuadruplas[i].operando2, tabla->cuadruplas[i].resultado);
        printf("%5d %25s %25s %25s %25s \n", i, mostrar_operador(tabla->cuadruplas[i].operador), parse(tabla->cuadruplas[i].operando1), parse(tabla->cuadruplas[i].operando2), parse(tabla->cuadruplas[i].resultado));
    }
}