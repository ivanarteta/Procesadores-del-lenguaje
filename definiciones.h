#ifndef DEFINICIONES
#define DEFINICIONES

/*#define OP_SUMA 1
#define OP_RESTA 2
#define OP_MULTIPLICACION 3
#define OP_DIVISION 4
#define OP_MOD 5
#define OP_DIV 6 
#define OP_OPERADORES_RELACIONALES 7*/
typedef struct constante_valor{
    union{
        int entero; //Para enteros y booleanos
        float real;
        char* caracteres; //Para char y cadenas
    };
}Constante_valor;

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
    TS_TIPO,
};

enum enum_operadores{

    /* Input y output */
    OP_INPUT,
    OP_OUTPUT,

    /* Asignación */
    OP_ASIGNACION,
    /*OP_ASIGNACION_ENTERO,
    OP_ASIGNACION_REAL,
    OP_ASIGNACION_BOOLEANO_TRUE,
    OP_ASIGNACION_BOOLEANO_FALSE,
    OP_ASIGNACION_CARACTER,
    OP_ASIGNACION_CADENA*/

};


#endif