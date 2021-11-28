#ifndef DEFINICIONES
#define DEFINICIONES

/* Esto para la cola de $$.true y $$.false */
typedef int tElem;

typedef struct nodoDeCola{
	tElem e;
	struct nodoDeCola *s;
}NodoDeCola;

typedef struct cola{
	NodoDeCola *i;
	NodoDeCola *f;
}Cola;


typedef struct constante_valor{
    union{
        int entero; //Para enteros y booleanos
        float real;
        char* caracteres; //Para char y cadenas
    };
}Constante_valor;

/*enum enum_operador{
    OP_SUMA,
    OP_RESTA,
    OP_MULTIPLICACION,
    OP_DIVISION,
    OP_MOD,
    OP_DIV,
    OP_OPERADORES_RELACIONALES
};*/

/*enum enum_tipo{
    TIPO_ENTERO, //O LITERAL_ENTERO
    TIPO_REAL, //O LITERAL_REAL
    TIPO_BOOLEANO, //O LITERAL_BOOLEANO
    TIPO_CADENA, //O LITERAL_CADENA
    TIPO_CARACTER //O LITERAL_CARACTER
};*/

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
    TS_TIPO, 
    TIPO_ENTERO, //O LITERAL_ENTERO
    TIPO_REAL, //O LITERAL_REAL
    TIPO_BOOLEANO, //O LITERAL_BOOLEANO
    TIPO_CADENA, //O LITERAL_CADENA
    TIPO_CARACTER //O LITERAL_CARACTER
};

enum enum_operadores{

    /* Input y output */
    OP_INPUT,
    OP_OUTPUT,

    /* Asignación */
    OP_ASIGNACION,
    OP_ASIGNACION_TRUE,
    OP_ASIGNACION_FALSE,
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

    /* Para conversiones */
    OP_INT_TO_REAL,

    /* Resta unaria */
    OP_RESTA_UNARIA_ENTERO,
    OP_RESTA_UNARIA_REAL,

    /* Para los GOTO */
    OP_GOTO
};


#endif