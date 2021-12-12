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
    TIPO_REAL,
    TIPO_BOOLEANO,
    TIPO_EXPRESION_BOOLEANA,
    TIPO_CADENA,
    TIPO_CARACTER
};

enum enum_operadores{

    /* Input y output */
    OP_INPUT = 1,
    OP_OUTPUT,

    /* Asignación */
    OP_ASIGNACION,
    OP_ASIGNACION_TRUE,
    OP_ASIGNACION_FALSE,
    OP_SUMA,
    OP_RESTA,
    OP_MULTIPLICACION,
    OP_DIVISION,
    OP_MOD,
    OP_DIV,

    /* Para conversiones */
    OP_INT_TO_REAL,

    /* Resta unaria */
    OP_RESTA_UNARIA,

    /* Para los GOTOS */
    OP_GOTO,
    OP_GOTO_IGUAL,
    OP_GOTO_DISTINTO,
    OP_GOTO_MENOR,
    OP_GOTO_MAYOR,
    OP_GOTO_MENOR_O_IGUAL,
    OP_GOTO_MAYOR_O_IGUAL
};

enum enum_errores{
    ERROR_TIPO, // Para cuando intentamos hacer una operación con tipos no compatibles
    ERROR_OPERADOR, //Para cuando intentamos hacer una operación con un operador no compatible
    ERROR_SIMBOLO, //Para cuando intentamos hacer una operación con un símbolo no compatible
    ERROR_OPERANDO //Para cuando intentamos hacer una operación con un operando no compatibles
};

#endif