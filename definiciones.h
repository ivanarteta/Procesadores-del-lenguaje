#ifndef DEFINICIONES
#define DEFINICIONES

enum enum_literales{
    LITERAL_ENTERO = 1, 
    LITERAL_REAL,
    LITERAL_CARACTER,
    LITERAL_CADENA,
    LITERAL_VERDADERO,
    LITERAL_FALSO
};

enum enum_tipo_celda{
    TS_VAR = 1, 
    TS_CONSTANTE,
    TS_ACCION,
    TS_FUNCION,
    TS_TIPO, 
    TIPO_ENTERO,
    TIPO_LITERAL_ENTERO,
    TIPO_REAL, //O LITERAL_REAL
    TIPO_BOOLEANO, //O LITERAL_BOOLEANO
    TIPO_CADENA, //O LITERAL_CADENA
    TIPO_CARACTER //O LITERAL_CARACTER
};

enum enum_operadores{

    /* Input y output */
    OP_INPUT = 1,
    OP_OUTPUT,

    /* Asignación */
    OP_ASIGNACION,
    OP_ASIGNACION_TRUE,
    OP_ASIGNACION_FALSE,
    OP_ASIGNACION_ENTERO,
    /*OP_ASIGNACION_ENTERO,
    OP_ASIGNACION_REAL,

    OP_ASIGNACION_CARACTER,
    OP_ASIGNACION_CADENA*/
    OP_SUMA,
    OP_RESTA,
    OP_MULTIPLICACION,
    OP_DIVISION,
    OP_MOD,
    OP_DIV,
    OP_IGUAL,
    OP_OPERADORES_RELACIONALES,

    /* Operadores logicos */
    OP_NO,
    OP_Y,
    OP_O,

    /* Para conversiones */
    OP_INT_TO_REAL,
    OP_REAL_TO_INT,

    /* Resta unaria */
    OP_RESTA_UNARIA_ENTERO,
    OP_RESTA_UNARIA_REAL,

    /* Para los GOTO */
    OP_GOTO,
    OP_GOTO_IGUAL,
    OP_GOTO_DISTINTO,
    OP_GOTO_MENOR,
    OP_GOTO_MAYOR,
    OP_GOTO_MENOR_O_IGUAL,
    OP_GOTO_MAYOR_O_IGUAL
};


#endif