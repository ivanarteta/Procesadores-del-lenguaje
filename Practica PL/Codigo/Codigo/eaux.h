#ifndef eaux_H
#define eaux_H

enum enum_tipo{
    TIPO_ERROR,
    TIPO_ENTERO,
    TIPO_REAL,
    TIPO_BOOLEANO,
    TIPO_CARACTER,
    TIPO_CADENA/*,
    TIPO_USUARIO,
    TIPO_ARRAY ??? */
} enum_tipo;

enum enum_modo {
    MODO_ENTRADA,
    MODO_SALIDA,
    MODO_ENTRADA_SALIDA,
    MODO_LOCAL
} enum_modo;

enum enum_operador{
    OPERADOR_ERROR,
    OPERADOR_INPUT,
    OPERADOR_OUTPUT,
    OPERADOR_RESTA_UNITARIA_ENTERO,
    OPERADOR_RESTA_UNITARIA_REAL,
    OPERADOR_MULTIPLICACION_ENTERO,
    OPERADOR_MULTIPLICACION_REAL,
    OPERADOR_INT2REAL,
    OPERADOR_REAL2INT,
    OPERADOR_SUMA_ENTERO,
    OPERADOR_SUMA_REAL,
    OPERADOR_RESTA_ENTERO,
    OPERADOR_RESTA_REAL,
    OPERADOR_DIVISION_ENTERO,
    OPERADOR_DIVISION_REAL,
    OPERADOR_MOD_ENTERO,
    OPERADOR_MOD_REAL,
    OPERADOR_DIVENT,
    
    OPERADOR_B_Y,
    OPERADOR_B_O,
    OPERADOR_B_NO,
    
    OPERADOR_GOTO,
    OPERADOR_GOTO_IGUAL_ENTERO,
    OPERADOR_GOTO_IGUAL_REAL,
    OPERADOR_GOTO_IGUAL_BOOLEANO,
    OPERADOR_GOTO_DISTINTO_ENTERO,
    OPERADOR_GOTO_DISTINTO_REAL,
    OPERADOR_GOTO_DISTINTO_BOOLEANO,
    OPERADOR_GOTO_MENOR_ENTERO,
    OPERADOR_GOTO_MENOR_REAL,
    OPERADOR_GOTO_MAYOR_ENTERO,
    OPERADOR_GOTO_MAYOR_REAL,
    OPERADOR_GOTO_MAOI_ENTERO,
    OPERADOR_GOTO_MAOI_REAL,
    OPERADOR_GOTO_MEOI_ENTERO,
    OPERADOR_GOTO_VERDADERO,
    OPERADOR_GOTO_MEOI_REAL,
    
    
    OPERADOR_ASIGNACION_ENTERO,
    OPERADOR_ASIGNACION_REAL,
    OPERADOR_ASIGNACION_BOOLEANO_TRUE,
    OPERADOR_ASIGNACION_BOOLEANO_FALSE,
    OPERADOR_ASIGNACION_CARACTER,
    OPERADOR_ASIGNACION_CADENA
} enum_operador;

struct elementoLista{
    int                     idCuadrupla;
    struct elementoLista*   p;
}elementoLista;

struct TRUE_FALSE{
    struct elementoLista* cabeza;
    struct elementoLista* cola;
    
}TRUE_FALSE;

struct TRUE_FALSE makelist();
void insert_list(struct TRUE_FALSE* lista, int id);
struct TRUE_FALSE merge(struct TRUE_FALSE lista1, struct TRUE_FALSE lista2);
int empty(struct TRUE_FALSE lista);
int esOpGoto(int op);

#endif