#ifndef DEFINICIONES
#define DEFINICIONES

/*#define OP_SUMA 1
#define OP_RESTA 2
#define OP_MULTIPLICACION 3
#define OP_DIVISION 4
#define OP_MOD 5
#define OP_DIV 6 
#define OP_OPERADORES_RELACIONALES 7*/

enum enum_operador{
    OP_SUMA,
    OP_RESTA,
    OP_MULTIPLICACION,
    OP_DIVISION,
    OP_MOD,
    OP_DIV,
    OP_OPERADORES_RELACIONALES
};

enum enum_tipo{
    TIPO_ENTERO,
    TIPO_REAL,
    TIPO_BOOLEANO,
    TIPO_CADENA,
    TIPO_CARACTER
};

enum enum_literales{
    LITERAL_ENTERO, 
    LITERAL_REAL,
    LITERAL_CARACTER,
    LITERAL_CADENA,
    LITERAL_VERDADERO,
    LITERAL_FALSO
};

enum enum_tipo_celda{
    TS_VAR, 
    TS_CONSTANTE,
    TS_ACCION,
    TS_FUNCION,
    TS_TIPO
};

#endif