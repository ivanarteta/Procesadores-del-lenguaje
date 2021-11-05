#include "tc.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



void inicializar_TC(struct TC* tabla_cuadruplas) {
    tabla_cuadruplas->nextquad = 0;
}

void insertar_cuadrupla(struct TC* tabla_cuadruplas, enum enum_operador op, int* op1, int* op2, int* resultado) {
    
    int pos;
    int* op1_tc;
    int* op2_tc;
    int* resultado_tc;
    op1_tc = (int*)malloc(sizeof(int));
    op2_tc = (int*)malloc(sizeof(int));
    resultado_tc = (int*)malloc(sizeof(int));
    if (op1 == NULL) {
        op1_tc = NULL;
    } else {
        *op1_tc = *op1;
    }
    if (op2 == NULL) {
        op2_tc = NULL;
    } else {
        *op2_tc = *op2;
    }
    if (resultado == NULL) {
        resultado_tc = NULL;
    } else {
        *resultado_tc = *resultado;
    }
    
    pos = tabla_cuadruplas->nextquad;
    // Inserto los atributos de la cuadrupla
    ((tabla_cuadruplas->cuadruplas)[pos].operador) = op;
    (tabla_cuadruplas->cuadruplas)[pos].operando1= op1_tc;
    (tabla_cuadruplas->cuadruplas)[pos].operando2 = op2_tc;
    (tabla_cuadruplas->cuadruplas)[pos].resultado = resultado_tc;
    // Aumento la posición en uno
    tabla_cuadruplas->nextquad = pos + 1;
    
}

void backpatch(struct TRUE_FALSE lista, int idCuadrupla, struct TC* tabla_cuadruplas){
    while (lista.cabeza != NULL ) {
        
        //(((*tabla_cuadruplas).cuadruplas[(lista.cabeza)->idCuadrupla]).operando1) = &idCuadrupla;
        int* x;
        x = (int*)malloc(sizeof(int));
        *x = idCuadrupla;
        if((lista.cabeza)->idCuadrupla != -1){
           ((tabla_cuadruplas->cuadruplas[(lista.cabeza)->idCuadrupla]).resultado) = x; 
        }
        
        lista.cabeza  = lista.cabeza->p;
    }
    
}

void guardar_TC(char* ruta, struct TC tabla_cuadruplas, int errorFlag) {
    FILE* f = fopen(ruta, "w");
    if (errorFlag == 1) {
        fprintf(f, "Se ha producido un error en la compilación, por lo que la tabla de cuádruplas puede no haberse generado correctamente.\n");
        fprintf(f, "Consulte la salida para obtener más información sobre el error.\n\n");
    }
    fprintf(f, "Id\t\tOperador\t\tOperando1\t\tOperando2\t\tResultado\tNombre operador\n\n");
    for (int i = 0; i<tabla_cuadruplas.nextquad; i++){
        fprintf(f, "%d\t\t%d\t\t\t", i, tabla_cuadruplas.cuadruplas[i].operador);
        if ((tabla_cuadruplas.cuadruplas)[i].operando1 == NULL) {
            fprintf(f, "-\t\t\t");
        } else {
            fprintf(f, "%d\t\t\t", *((tabla_cuadruplas.cuadruplas)[i].operando1));
        }
        if (tabla_cuadruplas.cuadruplas[i].operando2 == NULL) {
            fprintf(f, "-\t\t\t");
        } else {
            fprintf(f, "%d\t\t\t", *((tabla_cuadruplas.cuadruplas)[i].operando2));
        }
        if ((tabla_cuadruplas.cuadruplas)[i].resultado == NULL) {
            fprintf(f, "-\t\t");
        } else {
            fprintf(f, "%d\t\t", *((tabla_cuadruplas.cuadruplas)[i].resultado));
        }
        switch (tabla_cuadruplas.cuadruplas[i].operador) {
            case OPERADOR_ERROR:
                fprintf(f, "Operador inválido\n");
                break;
            case OPERADOR_RESTA_UNITARIA_ENTERO:
                fprintf(f, "Negativo entero\n");
                break;
            case OPERADOR_RESTA_UNITARIA_REAL:
                fprintf(f, "Negativo real\n");
                break;
            case OPERADOR_MULTIPLICACION_ENTERO:
                fprintf(f, "Multiplicación entero\n");
                break;
            case OPERADOR_MULTIPLICACION_REAL:
                fprintf(f, "Multiplicación real\n");
                break;
            case OPERADOR_INT2REAL:
                fprintf(f, "Entero a real\n");
                break;
            case OPERADOR_REAL2INT:
                fprintf(f, "Real a entero\n");
                break;
            case OPERADOR_SUMA_ENTERO:
                fprintf(f, "Suma entero\n");
                break;
            case OPERADOR_SUMA_REAL:
                fprintf(f, "Suma real\n");
                break;
            case OPERADOR_RESTA_ENTERO:
                fprintf(f, "Resta entero\n");
                break;
            case OPERADOR_RESTA_REAL:
                fprintf(f, "Resta real\n");
                break;
            case OPERADOR_DIVISION_ENTERO:
                fprintf(f, "División entre enteros\n");
                break;
            case OPERADOR_DIVISION_REAL:
                fprintf(f, "División entre reales\n");
                break;
            case OPERADOR_MOD_ENTERO:
                fprintf(f, "Mod entero\n");
                break;
            case OPERADOR_MOD_REAL:
                fprintf(f, "Mod real\n");
                break;
            case OPERADOR_DIVENT:
                fprintf(f, "Div entera\n");
                break;
            case OPERADOR_ASIGNACION_ENTERO:
                fprintf(f, "Asignación entero\n");
                break;
            case OPERADOR_ASIGNACION_REAL:
                fprintf(f, "Asignación real\n");
                break;
            case OPERADOR_ASIGNACION_CARACTER:
                fprintf(f, "Asignación caracter\n");
                break;
            case OPERADOR_ASIGNACION_CADENA:
                fprintf(f, "Asignación cadena\n");
                break;
            case OPERADOR_INPUT:
                fprintf(f, "Input\n");
                break;
            case OPERADOR_OUTPUT:
                fprintf(f, "Output\n");
                break;
            case OPERADOR_B_Y:
                fprintf(f, "Y lógico\n");
                break;
            case OPERADOR_B_O:
                fprintf(f, "O lógico\n");
                break;
            case OPERADOR_B_NO:
                fprintf(f, "No lógico\n");
                break;
            case OPERADOR_GOTO:
                fprintf(f, "Goto\n");
                break;
            case OPERADOR_GOTO_IGUAL_ENTERO:
                fprintf(f, "Goto igual enteros\n");
                break;
            case OPERADOR_GOTO_IGUAL_REAL:
                fprintf(f, "Goto igual reales\n");
                break;
            case OPERADOR_GOTO_IGUAL_BOOLEANO:
                fprintf(f, "Goto igual booleanos\n");
                break;
            case OPERADOR_GOTO_DISTINTO_ENTERO:
                fprintf(f, "Goto distinto enteros\n");
                break;
            case OPERADOR_GOTO_DISTINTO_REAL:
                fprintf(f, "Goto distinto reales\n");
                break;
            case OPERADOR_GOTO_DISTINTO_BOOLEANO:
                fprintf(f, "Goto distinto booleanos\n");
                break;
            case OPERADOR_GOTO_MENOR_ENTERO:
                fprintf(f, "Goto menor enteros\n");
                break;
            case OPERADOR_GOTO_MENOR_REAL:
                fprintf(f, "Goto menor reales\n");
                break;
            case OPERADOR_GOTO_MAYOR_ENTERO:
                fprintf(f, "Goto mayor enteros\n");
                break;
            case OPERADOR_GOTO_MAYOR_REAL:
                fprintf(f, "Goto mayor reales\n");
                break;
            case OPERADOR_GOTO_MAOI_ENTERO:
                fprintf(f, "Goto mayor o igual enteros\n");
                break;
            case OPERADOR_GOTO_MAOI_REAL:
                fprintf(f, "Goto mayor o igual reales\n");
                break;
            case OPERADOR_GOTO_MEOI_ENTERO:
                fprintf(f, "Goto menor o igual enteros\n");
                break;
            case OPERADOR_GOTO_MEOI_REAL:
                fprintf(f, "Goto menor o igual reales\n");
                break;
            case OPERADOR_ASIGNACION_BOOLEANO_FALSE:
                fprintf(f, "Asignación booleano false\n");
                break;
            case OPERADOR_GOTO_VERDADERO:
                fprintf(f, "Goto verdadero\n");
                break;
            case OPERADOR_ASIGNACION_BOOLEANO_TRUE:
                fprintf(f, "Asignación booleano true\n");
                break; 
        }
    }
    fclose(f);
}


void guardar_CTD(char* ruta, struct TC tabla_cuadruplas, struct FILA_TS* cabeza_TS, int errorFlag) {
    FILE* f = fopen(ruta, "w");
    int resGoto;
    char* res;
    char* op1;
    char* op2;
    if (errorFlag == 1) {
        fprintf(f, "Se ha producido un error en la compilación, por lo que el código de tres direcciones puede no haberse generado correctamente.\n");
        fprintf(f, "Consulte la salida para más información sobre el error.\n\n");
    }
    for (int i=0; i<tabla_cuadruplas.nextquad; i++) {
        if (tabla_cuadruplas.cuadruplas[i].resultado != NULL) {
            if (esOpGoto(tabla_cuadruplas.cuadruplas[i].operador) == 0) {
                res = TS_consultar_nombre(*tabla_cuadruplas.cuadruplas[i].resultado, cabeza_TS);
            } else {
                resGoto = *tabla_cuadruplas.cuadruplas[i].resultado;
            }
        }
        if (tabla_cuadruplas.cuadruplas[i].operando1 != NULL) {
            op1 = TS_consultar_nombre(*tabla_cuadruplas.cuadruplas[i].operando1, cabeza_TS);
        }
        if (tabla_cuadruplas.cuadruplas[i].operando2 != NULL) {
            op2 = TS_consultar_nombre(*tabla_cuadruplas.cuadruplas[i].operando2, cabeza_TS);
        }
        switch (tabla_cuadruplas.cuadruplas[i].operador) {
            case OPERADOR_ERROR:
                fprintf(f, "%d\tOperador inválido\n", i);
                break;
            case OPERADOR_RESTA_UNITARIA_ENTERO:
                fprintf(f, "%d\t%s := - %s\n", i, res, op1);
                break;
            case OPERADOR_RESTA_UNITARIA_REAL:
                fprintf(f, "%d\t%s := - %s\n", i, res, op1);
                break;
            case OPERADOR_MULTIPLICACION_ENTERO:
                fprintf(f, "%d\t%s := %s * %s\n", i, res, op1, op2);
                break;
            case OPERADOR_MULTIPLICACION_REAL:
                fprintf(f, "%d\t%s := %s * %s\n", i, res, op1, op2);
                break;
            case OPERADOR_INT2REAL:
                fprintf(f, "%d\t%s := (real) %s\n", i, res, op1);
                break;
            case OPERADOR_REAL2INT:
                fprintf(f, "%d\t%s := (entero) %s\n", i, res, op1);
                break;
            case OPERADOR_SUMA_ENTERO:
                fprintf(f, "%d\t%s := %s + %s\n", i, res, op1, op2);
                break;
            case OPERADOR_SUMA_REAL:
                fprintf(f, "%d\t%s := %s + %s\n", i, res, op1, op2);
                break;
            case OPERADOR_RESTA_ENTERO:
                fprintf(f, "%d\t%s := %s - %s\n", i, res, op1, op2);
                break;
            case OPERADOR_RESTA_REAL:
                fprintf(f, "%d\t%s := %s - %s\n", i, res, op1, op2);
                break;
            case OPERADOR_DIVISION_ENTERO:
                fprintf(f, "%d\t%s := %s / %s\n", i, res, op1, op2);
                break;
            case OPERADOR_DIVISION_REAL:
                fprintf(f, "%d\t%s := %s / %s\n", i, res, op1, op2);
                break;
            case OPERADOR_MOD_ENTERO:
                fprintf(f, "%d\t%s := %s mod %s\n", i, res, op1, op2);
                break;
            case OPERADOR_MOD_REAL:
                fprintf(f, "%d\t%s := %s mod %s\n", i, res, op1, op2);
                break;
            case OPERADOR_DIVENT:
                fprintf(f, "%d\t%s := %s div %s\n", i, res, op1, op2);
                break;
            case OPERADOR_ASIGNACION_ENTERO:
                fprintf(f, "%d\t%s := %s\n", i, res, op1);
                break;
            case OPERADOR_ASIGNACION_REAL:
                fprintf(f, "%d\t%s := %s\n", i, res, op1);
                break;
            case OPERADOR_ASIGNACION_CARACTER:
                fprintf(f, "%d\t%s := %s\n", i, res, op1);
                break;
            case OPERADOR_ASIGNACION_CADENA:
                fprintf(f, "%d\t%s := %s\n", i, res, op1);
                break;
            case OPERADOR_INPUT:
                fprintf(f, "%d\tINPUT %s\n", i, op1);
                break;
            case OPERADOR_OUTPUT:
                fprintf(f, "%d\tOUTPUT %s\n", i, op1);
                break;
            case OPERADOR_B_Y:
                fprintf(f, "%d\t%s := %s Y %s\n", i, res, op1, op2);
                break;
            case OPERADOR_B_O:
                fprintf(f, "%d\t%s := %s O %s\n", i, res, op1, op2);
                break;
            case OPERADOR_B_NO:
                fprintf(f, "%d\t%s := NO %s\n", i, res, op1);
                break;
            case OPERADOR_GOTO:
                fprintf(f, "%d\tGOTO %d\n", i, resGoto);
                break;
            case OPERADOR_GOTO_IGUAL_ENTERO:
                fprintf(f, "%d\tIF %s = %s GOTO %d\n", i, op1, op2, resGoto);
                break;
            case OPERADOR_GOTO_IGUAL_REAL:
                fprintf(f, "%d\tIF %s = %s GOTO %d\n", i, op1, op2, resGoto);
                break;
            case OPERADOR_GOTO_IGUAL_BOOLEANO:
                fprintf(f, "%d\tIF %s = %s GOTO %d\n", i, op1, op2, resGoto);
                break;
            case OPERADOR_GOTO_DISTINTO_ENTERO:
                fprintf(f, "%d\tIF %s != %s GOTO %d\n", i, op1, op2, resGoto);
                break;
            case OPERADOR_GOTO_DISTINTO_REAL:
                fprintf(f, "%d\tIF %s != %s GOTO %d\n", i, op1, op2, resGoto);
                break;
            case OPERADOR_GOTO_DISTINTO_BOOLEANO:
                fprintf(f, "%d\tIF %s != %s GOTO %d\n", i, op1, op2, resGoto);
                break;
            case OPERADOR_GOTO_MENOR_ENTERO:
                fprintf(f, "%d\tIF %s < %s GOTO %d\n", i, op1, op2, resGoto);
                break;
            case OPERADOR_GOTO_MENOR_REAL:
                fprintf(f, "%d\tIF %s < %s GOTO %d\n", i, op1, op2, resGoto);
                break;
            case OPERADOR_GOTO_MAYOR_ENTERO:
                fprintf(f, "%d\tIF %s > %s GOTO %d\n", i, op1, op2, resGoto);
                break;
            case OPERADOR_GOTO_MAYOR_REAL:
                fprintf(f, "%d\tIF %s > %s GOTO %d\n", i, op1, op2, resGoto);
                break;
            case OPERADOR_GOTO_MAOI_ENTERO:
                fprintf(f, "%d\tIF %s >= %s GOTO %d\n", i, op1, op2, resGoto);
                break;
            case OPERADOR_GOTO_MAOI_REAL:
                fprintf(f, "%d\tIF %s >= %s GOTO %d\n", i, op1, op2, resGoto);
                break;
            case OPERADOR_GOTO_MEOI_ENTERO:
                fprintf(f, "%d\tIF %s <= %s GOTO %d\n", i, op1, op2, resGoto);;
                break;
            case OPERADOR_GOTO_MEOI_REAL:
                fprintf(f, "%d\tIF %s <= %s GOTO %d\n", i, op1, op2, resGoto);
                break;
            case OPERADOR_ASIGNACION_BOOLEANO_FALSE:
                fprintf(f, "%d\t%s := FALSE\n", i, res);
                break;
            case OPERADOR_GOTO_VERDADERO:
                fprintf(f, "%d\tIF %s GOTO %d\n", i, op1, resGoto);
                break;
            case OPERADOR_ASIGNACION_BOOLEANO_TRUE:
                fprintf(f, "%d\t%s := TRUE\n", i, res);
                break; 
        }
    }
    fprintf(f, "%d\tEXIT", tabla_cuadruplas.nextquad);
    fclose(f);
}