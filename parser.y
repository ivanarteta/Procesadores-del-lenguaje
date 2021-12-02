%{
#include "pila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tabla_cuadruplas.h"
#include "tabla_simbolos.h"
#include "codigo_tres_direcciones.h"

#define YYDEBUG 1
void yyerror(char *s);
int yylex(void);
int yyparse(void);
int separar_cadena(char *);
extern FILE * yyin;

#define ROJO "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET "\x1b[0m"
#define RESET_COLOR    "\x1b[0m"
#define NEGRO_T        "\x1b[30m"
#define NEGRO_F        "\x1b[40m"
#define ROJO_T     "\x1b[31m"
#define ROJO_F     "\x1b[41m"
#define VERDE_T        "\x1b[32m"
#define VERDE_F        "\x1b[42m"
#define AMARILLO_T "\x1b[33m"
#define    AMARILLO_F  "\x1b[43m"
#define AZUL_T     "\x1b[34m"
#define    AZUL_F      "\x1b[44m"
#define MAGENTA_T  "\x1b[35m"
#define MAGENTA_F  "\x1b[45m"
#define CYAN_T     "\x1b[36m"
#define CYAN_F     "\x1b[46m"
#define BLANCO_T   "\x1b[37m"
#define BLANCO_F   "\x1b[47m"

TS_lista simbolos;
TC_tabla_cuadrupla cuadrupla;
tipoPila pila;

/* Falta algo para las expresiones que tenga un campo para el tipo (real, entero, booleano, ...)
    y para un apuntador a la tabla de simbolos.*/
%}

%code requires{
    #include "cola.h"
    #include "definiciones.h"
    #include "tabla_simbolos.h"
}

%union{
    char* ctype; /* Para las cadenas de caracteres (id, string, ...) */
    int itype; /* Para los números enteros y los booleanos */
    float ftype; /* Para los números reales */   
    /* Para las expresiones */
    //enum enum_tipo tipo;
    enum enum_tipo_celda celda;
    enum enum_literales literales;
    struct exp_type{
        int tipo;
        int sitio;
        union{
            struct{
                    //TRUE: Lista de posiciones de cuadruplas con gotos incompletos que tienen que ir
                   // a lo que se haga si es cierto.
                    //FALSE: Lista de posiciones de cuadruplas con gotos incompletos que tienen que ir
                   // a lo que se haga si es falso.
                Cola TRUE, FALSE;
            };
        };
    }exp_type;
    struct inst_type{
        Cola siguiente;
    }inst_type;
    struct literales_type{
        int tipo;
        Constante_valor valor;
    }literales_type;
};

%token <ctype> TK_LITERAL_CADENA
%token <ctype> TK_LITERAL_CARACTER
%token <itype> TK_LITERAL_ENTERO
%token <ftype> TK_LITERAL_REAL
%token <ctype> TK_IDENTIFICADOR

%token TK_ACCION
%token TK_ALGORITMO
%token TK_BOOLEANO
%token TK_CADENA
%token TK_CARACTER
%token TK_CONST
%token TK_CONTINUAR
%token TK_DE 
%token TK_DEV
%token TK_ENT
%token TK_ENTERO
%token TK_ENT_SAL
%token TK_FACCION
%token TK_FALGORITMO
%token <itype>TK_FALSO
%token TK_FCONST
%token TK_FFUNCION
%token TK_FMIENTRAS
%token TK_FPARA
%token TK_FSI 
%token TK_FTIPO
%token TK_FTUPLA
%token TK_FUNCION 
%token TK_FVAR
%token TK_HACER
%token TK_HASTA
%token TK_MIENTRAS 
%token TK_PARA 
%token TK_REAL
%token TK_SAL 
%token TK_SI 
%token TK_TABLA
%token TK_TIPO 
%token TK_TUPLA 
%token TK_VAR 
%token <itype>TK_VERDADERO
%token TK_REF
%token TK_COMENTARIO

%token TK_ASIGNACION
%token TK_COMPOSICION_SECUENCIAL
%token TK_SEPARADOR
%token TK_SUBRANGO
%token TK_DEF_TIPO
%token TK_ENTONCES
%token TK_SI_NO_SI
%token TK_FIN_ARRAY
%token TK_INICIO_PARENTESIS
%token TK_FIN_PARENTESIS
%token <ctype> TK_OPERADOR_RELACIONAL

/* Prioridades */
/* Operadores de referencia */
%left TK_REFERENCIA
%left TK_INICIO_ARRAY
%left TK_REF

/* Operadores lógicos */
%left TK_O
%left TK_Y
%left TK_NO

 /* Operadores comparativos */
%left TK_OPERADOR_RELACIONAL TK_IGUAL

 /* Operadores aritmeticos */
%left TK_SUMA TK_RESTA
%left TK_MOD
%left TK_DIV
%left TK_MULTIPLICACION TK_DIVISION
%left UMINUS

 /* TYPE */
%type <itype> lista_id def_tipo M N
%type <celda> tipo_base
%type <literales_type> tipo_literal
%type <exp_type> operando expresion expresion_aritmetica expresion_booleana
%type <inst_type> it_cota_fija it_cota_variable instrucciones alternativa iteracion instruccion asignacion lista_opciones

%%
descripcion_algoritmo:  TK_ALGORITMO TK_IDENTIFICADOR TK_COMPOSICION_SECUENCIAL cabecera_algoritmo bloque_algoritmo TK_FALGORITMO
                        ;
cabecera_algoritmo: definiciones_globales definiciones_acciones_funciones definiciones_variables_interaccion TK_COMENTARIO
                    ;
bloque_algoritmo:   bloque TK_COMENTARIO
                    ;
definiciones_globales:  definicion_tipo definiciones_globales
                        | definicion_const definiciones_globales
                        | /* vacio */
                        ;
definiciones_acciones_funciones:    definicion_accion definiciones_acciones_funciones 
                                    | definicion_funcion definiciones_acciones_funciones
                                    | /* vacio */
                                    ;
bloque: declaraciones instrucciones
        ;      
declaraciones:  definicion_tipo declaraciones
                | definicion_const declaraciones 
                | definicion_var declaraciones
                | /* vacio */
                ;                             
/* DEFINICIONES */
definicion_tipo:    TK_TIPO lista_definiciones_tipo TK_FTIPO
                    ;
definicion_const:   TK_CONST lista_definiciones_const TK_FCONST
                    ;
definicion_var: TK_VAR lista_definiciones_var TK_FVAR
                ;
/* DEFINICIONES DE TIPOS */
lista_definiciones_tipo:    TK_IDENTIFICADOR TK_IGUAL def_tipo TK_COMPOSICION_SECUENCIAL lista_definiciones_tipo
                            | /* vacio */ 
                            ;
def_tipo:   TK_TUPLA lista_campos TK_FTUPLA {}
            | TK_TABLA TK_INICIO_ARRAY expresion_tabla TK_SUBRANGO expresion_tabla TK_FIN_ARRAY TK_DE def_tipo {}
            | TK_IDENTIFICADOR {}
            | expresion_tabla TK_SUBRANGO expresion_tabla {}
            | TK_REF def_tipo {}
            | tipo_base {}
            ;
tipo_base:  TK_ENTERO {$$ = TIPO_ENTERO;}
            | TK_BOOLEANO {$$ = TIPO_BOOLEANO;}
            | TK_CARACTER {$$ = TIPO_CARACTER;}
            | TK_REAL {$$ = TIPO_REAL;}
            | TK_CADENA {$$ = TIPO_CADENA;}
            ;
expresion_tabla:    TK_LITERAL_ENTERO 
                    | TK_LITERAL_CARACTER
                    ;
lista_campos:   TK_IDENTIFICADOR TK_DEF_TIPO def_tipo TK_COMPOSICION_SECUENCIAL lista_campos
                | /* vacio */ 
                ;  
/* DECLARACION DE CONSTANTES Y VARIABLES */
lista_definiciones_const:   TK_IDENTIFICADOR TK_IGUAL tipo_literal TK_COMPOSICION_SECUENCIAL lista_definiciones_const 
                                {   
                                    //TS_insertar(&simbolos, $1);   
                                    //TS_modificar_tipo(&simbolos, $1, $3.tipo, TS_CONSTANTE);
                                    //TS_modificar_valor_cte(&simbolos, $1, $3.valor);
                                }
                            | /* vacio */ 
                            ;
tipo_literal:   TK_LITERAL_CADENA {$$.tipo = TIPO_CADENA; $$.valor.caracteres = $1;}
                | TK_LITERAL_CARACTER {$$.tipo = TIPO_CARACTER; $$.valor.caracteres = $1;}
                | TK_LITERAL_ENTERO {$$.tipo = TIPO_ENTERO; $$.valor.entero = $1;}
                | TK_LITERAL_REAL {$$.tipo = TIPO_REAL; $$.valor.real = $1;}
                | TK_VERDADERO {}
                | TK_FALSO {}
                ;

lista_definiciones_var:     lista_id TK_COMPOSICION_SECUENCIAL lista_definiciones_var
                            | /* vacio */
                            ;
lista_id:   TK_IDENTIFICADOR TK_SEPARADOR lista_id 
                {  
                    int id = TS_insertar(&simbolos, $1);
                    TS_modificar_tipo(&simbolos, id, $3, TS_VAR);
                    apilar(&pila, id);
                    $$=$3;
                }
            | TK_IDENTIFICADOR TK_DEF_TIPO def_tipo 
                {
                    int id = TS_insertar(&simbolos, $1);
                    TS_modificar_tipo(&simbolos, id, $3, TS_VAR);
                    apilar(&pila, id);
                    $$ = $3;
                }
            /*| vacio */
            ;
definiciones_variables_interaccion: definicion_entrada
                                    | definicion_entrada definicion_salida
                                    | definicion_salida
                                    ;
definicion_entrada: TK_ENT lista_definiciones_var 
                        {
                            while(!esNulaPila(pila)){
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_INPUT, cima(pila), -1, -1));
                                desapilar(&pila);
                            }
                        }
                    ;
definicion_salida:  TK_SAL lista_definiciones_var 
                        {
                            while(!esNulaPila(pila)){
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_OUTPUT, cima(pila), -1, -1));
                                desapilar(&pila);
                            }
                        }
                    ;    

/* EXPRESIONES */
expresion:  expresion_aritmetica 
                {
                    printf(MAGENTA_F"Expresion -> aritmética entrada"RESET" \n");
                    printf("Datos de la expresión: \n");
                    printf("Tipo: %d Sitio: %d \n", $1.tipo, $1.sitio);
                    printf("Cola true:\n");
                    imprimirCola(&$1.TRUE);
                    printf("Cola false:\n");
                    imprimirCola(&$1.FALSE);

                    $$.sitio = $1.sitio;
                    $$.tipo = $1.tipo;
                    $$.TRUE = $1.TRUE;
                    $$.FALSE = $1.FALSE;

                    printf(MAGENTA_F"Expresion -> aritmética salida, no produce ninguna"RESET" \n");

                }
            | expresion_booleana 
                {
                    printf(MAGENTA_F"Expresion -> booleana entrada"RESET" \n");
                    printf("Datos de la expresión: \n");
                    printf("Tipo: %d Sitio: %d \n", $1.tipo, $1.sitio);
                    printf("Cola true:\n");
                    imprimirCola(&$1.TRUE);
                    printf("Cola false:\n");
                    imprimirCola(&$1.FALSE);

                    /*if(!esNulaCola($1.TRUE)){
                        int nextquad = TC_elemento_siguiente(&cuadrupla);
                        backpatch(&cuadrupla, &$1.TRUE, nextquad);
                    }*/

                    //Desde aqui no se puede hacer backpatch para añadir los resultados de los goto,
                    //porque no tenemos los datos.

                    $$.sitio = $1.sitio; 
                    $$.TRUE = $1.TRUE;
                    $$.FALSE = $1.FALSE;
                    $$.tipo = TIPO_BOOLEANO;

                    TC_imprimir(&cuadrupla);

                    printf(MAGENTA_F"Expresion -> booleana salida, no produce ninguna"RESET" \n");
                }
            | llamada_funcion {}
            ;

/* FALTAN POR COMPROBAR CASOS */
expresion_aritmetica:   expresion_aritmetica TK_SUMA expresion_aritmetica 
                            {
                                /*printf(CYAN_F"Expresion aritmetica 1 entrada"RESET" \n");
                                printf("Datos de la primera expresión aritmética: \n");
                                printf("Tipo: %d Sitio: %d \n", $1.tipo, $1.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$1.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$1.FALSE);
                                printf("Datos de la segunda expresión aritmética: \n");
                                printf("Tipo: %d Sitio: %d \n", $3.tipo, $3.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$3.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$3.FALSE);*/
    
                                int nueva = TS_newtempt(&simbolos);
                                if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_ENTERO, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_SUMA, $1.sitio, $3.sitio, nueva));
                                    $$.tipo = TIPO_ENTERO;
                                }else if(($1.tipo == TIPO_REAL) && ($3.tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, $3.sitio, -1, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_SUMA, nueva, $1.sitio, nueva));
                                    $$.tipo = TIPO_REAL;
                                }else if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, $1.sitio, -1, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_SUMA, nueva, $3.sitio, nueva));
                                    $$.tipo = TIPO_REAL;
                                }else if(($1.tipo == TIPO_REAL) && ($3.tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_SUMA, $1.sitio, $3.sitio, nueva));
                                    $$.tipo = TIPO_REAL;
                                }
                                $$.sitio = nueva;

                                /*printf(CYAN_F"Expresion aritmetica 1 salida "RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", $$.tipo, $$.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$$.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$$.FALSE);*/
                            }
                        | expresion_aritmetica TK_RESTA expresion_aritmetica 
                            {
                                /*printf(CYAN_F"Expresion aritmetica 2 entrada "RESET" \n");
                                printf("Datos de la primera expresión aritmética: \n");
                                printf("Tipo: %d Sitio: %d \n", $1.tipo, $1.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$1.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$1.FALSE);
                                printf("Datos de la segunda expresión aritmética: \n");
                                printf("Tipo: %d Sitio: %d \n", $3.tipo, $3.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$3.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$3.FALSE);*/
                                
                                int nueva = TS_newtempt(&simbolos);
                                if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_ENTERO, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_RESTA, $1.sitio, $3.sitio, nueva));
                                    $$.tipo = TIPO_ENTERO;
                                }else if(($1.tipo == TIPO_REAL) && ($3.tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, $3.sitio, -1, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_RESTA, nueva, $1.sitio, nueva));
                                    $$.tipo = TIPO_REAL;
                                }else if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, $1.sitio, -1, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_RESTA, nueva, $3.sitio, nueva));
                                    $$.tipo = TIPO_REAL;
                                }else if(($1.tipo == TIPO_REAL) && ($3.tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_RESTA, $1.sitio, $3.sitio, nueva));
                                    $$.tipo = TIPO_REAL;
                                }
                                $$.sitio = nueva;

                                /*printf(CYAN_F"Expresion aritmetica 2 salida"RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", $$.tipo, $$.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$$.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$$.FALSE);*/
                            }
                        | expresion_aritmetica TK_DIVISION expresion_aritmetica 
                            {
                                /*printf(CYAN_F"Expresion aritmetica 3 entrada "RESET" \n");
                                printf("Datos de la primera expresión aritmética: \n");
                                printf("Tipo: %d Sitio: %d \n", $1.tipo, $1.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$1.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$1.FALSE);
                                printf("Datos de la segunda expresión aritmética: \n");
                                printf("Tipo: %d Sitio: %d \n", $3.tipo, $3.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$3.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$3.FALSE);*/
                                
                                int nueva = TS_newtempt(&simbolos);
                                if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_ENTERO)){
                                    int nueva2 = TS_newtempt(&simbolos);
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TS_modificar_tipo(&simbolos, nueva2, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, $1.sitio, -1, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, $3.sitio, -1, nueva2));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_DIVISION, nueva, nueva2, nueva));
                                }else if(($1.tipo == TIPO_REAL) && ($3.tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, $3.sitio, -1, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_DIVISION, nueva, $1.sitio, nueva));
                                }else if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, $1.sitio, -1, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_DIVISION, nueva, $3.sitio, nueva));
                                }else if(($1.tipo == TIPO_REAL) && ($3.tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_DIVISION, $1.sitio, $3.sitio, nueva));
                                }
                                $$.tipo = TIPO_REAL;
                                $$.sitio = nueva;

                                /*printf(CYAN_F"Expresion aritmetica 3 salida "RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", $$.tipo, $$.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$$.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$$.FALSE);*/
                            }
                        | expresion_aritmetica TK_DIV expresion_aritmetica 
                            {
                                /*printf(CYAN_F"Expresion aritmetica 4 entrada "RESET" \n");
                                printf("Datos de la primera expresión aritmética: \n");
                                printf("Tipo: %d Sitio: %d \n", $1.tipo, $1.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$1.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$1.FALSE);
                                printf("Datos de la segunda expresión aritmética: \n");
                                printf("Tipo: %d Sitio: %d \n", $3.tipo, $3.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$3.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$3.FALSE);*/

                                int nueva = TS_newtempt(&simbolos);
                                if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_ENTERO, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_DIV, $1.sitio, $3.sitio, nueva));
                                    $$.tipo = TIPO_ENTERO;
                                    $$.sitio = nueva;
                                }else{
                                    printf(ROJO"ENTRO AQUI\n"RESET);
                                }

                                /*printf(CYAN_F"Expresion aritmetica 4 salida "RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", $$.tipo, $$.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$$.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$$.FALSE);*/
                            }
                        | expresion_aritmetica TK_MOD expresion_aritmetica 
                            {
                                /*printf(CYAN_F"Expresion aritmetica 5 entrada "RESET" \n");
                                printf("Datos de la primera expresión aritmética: \n");
                                printf("Tipo: %d Sitio: %d \n", $1.tipo, $1.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$1.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$1.FALSE);
                                printf("Datos de la segunda expresión aritmética: \n");
                                printf("Tipo: %d Sitio: %d \n", $3.tipo, $3.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$3.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$3.FALSE);*/

                                int nueva = TS_newtempt(&simbolos);
                                if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_ENTERO, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_MOD, $1.sitio, $3.sitio, nueva));
                                    $$.tipo = TIPO_ENTERO;
                                    $$.sitio = nueva;
                                }else{
                                    printf(ROJO"ENTRO AQUI\n"RESET);
                                }

                                /*printf(CYAN_F"Expresion aritmetica 5 salida "RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", $$.tipo, $$.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$$.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$$.FALSE);*/
                            }
                        | expresion_aritmetica TK_MULTIPLICACION expresion_aritmetica 
                            {
                                /*printf(CYAN_F"Expresion aritmetica 6 entrada "RESET" \n");
                                printf("Datos de la primera expresión aritmética: \n");
                                printf("Tipo: %d Sitio: %d \n", $1.tipo, $1.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$1.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$1.FALSE);
                                printf("Datos de la segunda expresión aritmética: \n");
                                printf("Tipo: %d Sitio: %d \n", $3.tipo, $3.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$3.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$3.FALSE);*/
                                
                                int nueva = TS_newtempt(&simbolos);
                                if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_ENTERO, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_MULTIPLICACION, $1.sitio, $3.sitio, nueva));
                                    $$.tipo = TIPO_ENTERO;
                                }else if(($1.tipo == TIPO_REAL) && ($3.tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, $3.sitio, -1, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_MULTIPLICACION, nueva, $1.sitio, nueva));
                                    $$.tipo = TIPO_REAL;
                                }else if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, $1.sitio, -1, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_MULTIPLICACION, nueva, $3.sitio, nueva));
                                    $$.tipo = TIPO_REAL;
                                }else if(($1.tipo == TIPO_REAL) && ($3.tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_MULTIPLICACION, $1.sitio, $3.sitio, nueva));
                                    $$.tipo = TIPO_REAL;
                                }
                                $$.sitio = nueva;

                                /*printf(CYAN_F"Expresion aritmetica 6 salida "RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", $$.tipo, $$.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$$.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$$.FALSE);*/
                            }
                        | TK_INICIO_PARENTESIS expresion_aritmetica TK_FIN_PARENTESIS 
                            {
                                /*printf(CYAN_F"Expresion aritmetica 7 entrada "RESET" \n");
                                printf("Datos de la expresión aritmética: \n");
                                printf("Tipo: %d Sitio: %d \n", $2.tipo, $2.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$2.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$2.FALSE);*/
                                
                                $$.tipo = $2.tipo;
                                $$.sitio = $2.sitio;

                                /*printf(CYAN_F"Expresion aritmetica 7 salida "RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", $$.tipo, $$.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$$.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$$.FALSE);*/
                            }
                        | operando 
                            {
                                /*printf(CYAN_F"Expresion aritmetica 8 entrada "RESET" \n");
                                printf("Datos de la expresión aritmética: \n");
                                printf("Tipo: %d Sitio: %d \n", $1.tipo, $1.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$1.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$1.FALSE);*/

                                $$.sitio = $1.sitio; 
                                $$.tipo = $1.tipo;

                                /*printf(CYAN_F"Expresion aritmetica 8 salida"RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", $$.tipo, $$.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$$.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$$.FALSE);*/
                            }
                        | TK_RESTA expresion_aritmetica %prec UMINUS 
                            {
                                /*printf(CYAN_F"Expresion aritmetica 9 entrada"RESET" \n");
                                printf("Datos de la expresión aritmética: \n");
                                printf("Tipo: %d Sitio: %d \n", $2.tipo, $2.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$2.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$2.FALSE);*/
                                
                                int nueva = TS_newtempt(&simbolos);
                                TS_modificar_tipo(&simbolos, nueva, $2.tipo, TS_VAR);
                                if($2.tipo == TIPO_ENTERO){
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_RESTA_UNARIA_ENTERO, $2.sitio, -1, nueva));
                                }else if($2.tipo == TIPO_REAL){
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_RESTA_UNARIA_REAL, $2.sitio, -1, nueva));
                                }
                                $$.sitio = nueva;
                                $$.tipo = $2.tipo;

                                /*printf(CYAN_F"Expresion aritmetica 9 salida"RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", $$.tipo, $$.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$$.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$$.FALSE);*/
                            }
                        | TK_LITERAL_ENTERO 
                            {
                                /*printf(CYAN_F"Expresion aritmetica 10 entrada \n"RESET);
                                printf("Datos de la expresión aritmética: \n");
                                printf("Tipo: %d Sitio: %d \n", $1.tipo, $1.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$1.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$1.FALSE);*/

                                //Cuando leemos un literal directamente lo metemos en la TS y en la TC */
                                int nueva = TS_newtempt(&simbolos);
                                TS_modificar_tipo(&simbolos, nueva, TIPO_LITERAL_ENTERO, TS_VAR);
                                TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_ASIGNACION_ENTERO, nueva, -1, $1));

                                /* Así los datos que tiene al final son */
                                $$.tipo = TIPO_ENTERO;
                                $$.sitio = nueva;

                                /*printf(CYAN_F"Expresion aritmetica 10 salida"RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", $$.tipo, $$.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$$.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$$.FALSE);*/
                            }
                        | TK_LITERAL_REAL 
                            {
                                /*printf(CYAN_F"Expresion aritmetica 11 entrada \n"RESET);
                                printf("Datos de la expresión aritmética: \n");
                                printf("Tipo: %d Sitio: %d \n", $1.tipo, $1.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$1.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$1.FALSE);*/
                                
                                $$.tipo = TIPO_LITERAL_REAL;
                                $$.sitio = $1;

                                /*printf(CYAN_F"Expresion aritmetica 11 salida "RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", $$.tipo, $$.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$$.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$$.FALSE);*/
                            }
                        ;

expresion_booleana:     expresion_booleana TK_Y M expresion_booleana 
                            {
                                /*printf(VERDE_F"Expresion booleana entrada 1"RESET" \n");
                                printf("Datos de la primera expresión: \n");
                                printf("Tipo: %d Sitio: %d \n", $1.tipo, $1.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$1.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$1.FALSE);
                                printf("Dato de M: %d \n", $3);
                                printf("Datos de la segunda expresión: \n");
                                printf("Tipo: %d Sitio: %d \n", $4.tipo, $4.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$4.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$4.FALSE);*/

                                //TC_imprimir(&cuadrupla);

                                $$.tipo = TIPO_BOOLEANO;
                                backpatch(&cuadrupla, &$1.TRUE, $3);
                                $$.FALSE = merge($1.FALSE, $4.FALSE);
                                $$.TRUE = $4.TRUE;

                                //TC_imprimir(&cuadrupla);

                                /*printf(VERDE_F"Expresion booleana salida 1"RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", $$.tipo, $$.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$$.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$$.FALSE);*/

                            }
                        | expresion_booleana TK_O M expresion_booleana
                            {
                                /*printf(VERDE_F"Expresion booleana entrada 2"RESET" \n");
                                printf("Datos de la primera expresión: \n");
                                printf("Tipo: %d Sitio: %d \n", $1.tipo, $1.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$1.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$1.FALSE);
                                printf("Dato de M: %d \n", $3);
                                printf("Datos de la segunda expresión: \n");
                                printf("Tipo: %d Sitio: %d \n", $4.tipo, $4.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$4.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$4.FALSE);*/

                                $$.tipo = TIPO_BOOLEANO;
                                backpatch(&cuadrupla, &$1.FALSE, $3);
                                $$.TRUE = merge($1.TRUE, $4.TRUE);
                                $$.FALSE = $4.FALSE;  

                                /*printf(VERDE_F"Expresion booleana salida 2"RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", $$.tipo, $$.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$$.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$$.FALSE);*/
                            }
                        | TK_NO expresion_booleana
                            {
                                /*printf(VERDE_F"Expresion booleana entrada 3"RESET" \n");
                                printf("Datos de la expresión: \n");
                                printf("Tipo: %d Sitio: %d \n", $2.tipo, $2.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$2.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$2.FALSE);*/
                               
                                $$.tipo = TIPO_BOOLEANO;
                                $$.TRUE = $2.FALSE;
                                $$.FALSE = $2.TRUE;
                                
                                /*printf(VERDE_F"Expresion booleana salida 3"RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", $$.tipo, $$.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$$.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$$.FALSE);*/
                            }
                        | TK_VERDADERO 
                            {
                                printf(MAGENTA"Expresion booleana -> 4\n"RESET);
                            }
                        | TK_FALSO 
                            {
                                printf(MAGENTA"Expresion booleana -> 5\n"RESET);
                            }
                        | expresion_aritmetica TK_OPERADOR_RELACIONAL expresion_aritmetica 
                            {
                                /*printf(VERDE_F"Expresion booleana entrada 6"RESET" \n");
                                printf("Datos de la primera expresión: \n");
                                printf("Tipo: %d Sitio: %d \n", $1.tipo, $1.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$1.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$1.FALSE);
                                printf("Datos de la segunda expresión: \n");
                                printf("Tipo: %d Sitio: %d \n", $3.tipo, $3.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$3.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$3.FALSE);*/

                                //TC_imprimir(&cuadrupla);

                                $$.tipo = TIPO_BOOLEANO;
                                int nextquad = TC_elemento_siguiente(&cuadrupla);
                                nuevaCola(&$$.TRUE);
                                nuevaCola(&$$.FALSE);
                                pideTurnoCola(&$$.TRUE, nextquad);
                                pideTurnoCola(&$$.FALSE, nextquad+1);
                                if(strcmp($2, "<") == 0){
                                    printf("<\n");
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO_MENOR, $1.sitio, $3.sitio, -1));
                                }else if(strcmp($2, "<=") == 0){
                                    printf("<=\n");
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO_MENOR_O_IGUAL, $1.sitio, $3.sitio, -1));
                                }else if(strcmp($2, ">") == 0){
                                    printf(">\n");
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO_MAYOR, $1.sitio, $3.sitio, -1));
                                }else if(strcmp($2, ">=") == 0){
                                    printf("=>\n");
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO_MAYOR_O_IGUAL, $1.sitio, $3.sitio, -1));
                                }else if(strcmp($2, "<>") == 0){
                                    printf("<>\n");
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO_DISTINTO, $1.sitio, $3.sitio, -1));
                                }else{
                                    printf("ENTROOO \n");
                                }
                                /* Aquí tiene que ir el resultado al output (2) */
                                //TC_imprimir(&cuadrupla);
                                /* POSIBLEMENTE ESTO ESTÉ MAL */
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO, -1, -1, -1));

                                /*TC_imprimir(&cuadrupla);
                                
                                printf(VERDE_F"Expresion booleana salida 6"RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", $$.tipo, $$.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$$.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$$.FALSE);*/

                            }
                        | expresion_aritmetica TK_IGUAL expresion_aritmetica 
                            {
                                /*printf(VERDE_F"Expresion booleana entrada 7"RESET" \n");
                                printf("Datos de la primera expresión: \n");
                                printf("Tipo: %d Sitio: %d \n", $1.tipo, $1.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$1.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$1.FALSE);
                                printf("Datos de la segunda expresión: \n");
                                printf("Tipo: %d Sitio: %d \n", $3.tipo, $3.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$3.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$3.FALSE);*/

                                //TC_imprimir(&cuadrupla);
                                
                                if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_LITERAL_ENTERO)){
                                    int nueva = TS_newtempt(&simbolos);
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_LITERAL_ENTERO, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_ASIGNACION_ENTERO, nueva, -1, $3.sitio));
                                    int nextquad = TC_elemento_siguiente(&cuadrupla);
                                    pideTurnoCola(&$$.TRUE, nextquad);
                                    pideTurnoCola(&$$.FALSE, nextquad+1);
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO_IGUAL, $1.sitio, nueva, -1));
                                }else{
                                    
                                    int nextquad = TC_elemento_siguiente(&cuadrupla);
                                    pideTurnoCola(&$$.TRUE, nextquad);
                                    pideTurnoCola(&$$.FALSE, nextquad+1);
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO_IGUAL, $1.sitio, $3.sitio, -1));
                                }
                                $$.tipo = TIPO_BOOLEANO;
                                
                                
                                /* AQUI NO COGE BIEN EL SITIO, NO SE PORQUE */
                                /*$$.tipo = TIPO_BOOLEANO;
                                int nextquad = TC_elemento_siguiente(&cuadrupla);
                                pideTurnoCola(&$$.TRUE, nextquad);
                                pideTurnoCola(&$$.FALSE, nextquad+1);
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO_IGUAL, $1.sitio, $3.sitio, -1));*/
                                /* POSIBLEMENTE ESTO ESTÉ MAL */
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO, -1, -1, -1));


                                /*printf(VERDE_F"Expresion booleana salida 7"RESET" \n");
                                TC_imprimir(&cuadrupla);
                                printf("Tipo: %d Sitio: %d \n", $$.tipo, $$.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$$.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$$.FALSE);*/
                            }
                        | TK_INICIO_PARENTESIS expresion_booleana TK_FIN_PARENTESIS 
                            {
                                /*printf(VERDE_F"Expresion booleana entrada 8"RESET" \n");
                                printf("Datos de la expresión: \n");
                                printf("Tipo: %d Sitio: %d \n", $2.tipo, $2.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$2.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$2.FALSE);*/

                                $$ = $2;
                                
                                /*printf(VERDE_F"Expresion booleana salida 8"RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", $$.tipo, $$.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$$.TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&$$.FALSE);*/
                            }
                        ;

operando:   TK_IDENTIFICADOR 
                {
                    $$.sitio = TS_buscar_id(&simbolos,$1); 
                    $$.tipo = TS_consulta_tipo(&simbolos, $$.sitio);
                    //nuevaCola(&$$.TRUE);
                    //nuevaCola(&$$.FALSE);  
                }
            | operando TK_REFERENCIA operando {}
            | operando TK_INICIO_ARRAY expresion TK_FIN_ARRAY {}
            | operando TK_REF {}
            ;   

M:  /* Vacío */ {$$ = TC_elemento_siguiente(&cuadrupla);};    

N: /* Vacío */ {$$ = TC_elemento_siguiente(&cuadrupla);};

/* INSTRUCCIONES */
instrucciones:  instruccion TK_COMPOSICION_SECUENCIAL M instrucciones 
                    {
                        printf(ROJO"Instrucciones 1 entrada\n"RESET);
                        printf("Datos de la instruccion: \n");
                        printf("Cola siguiente: \n");
                        imprimirCola(&$1.siguiente);
                        printf("Dato de M: %d \n", $3);
                        printf("Datos de las instrucciones: \n");
                        printf("Cola siguiente: \n");
                        imprimirCola(&$4.siguiente);

                        backpatch(&cuadrupla, &$1.siguiente, $3);
                        $$ = $1;

                        printf(ROJO"Instrucciones 1 salida\n"RESET);
                        printf("Cola siguiente: \n");
                        imprimirCola(&$$.siguiente);

                    }
                | instruccion 
                    {
                        printf(ROJO"Instrucciones 2 entrada\n"RESET);
                        printf("Datos de la instruccion: \n");
                        printf("Cola siguiente: \n");
                        imprimirCola(&$1.siguiente);
                        
                        $$ = $1;

                        printf(ROJO"Instrucciones 2 salida\n"RESET);
                        printf("Cola siguiente: \n");
                        imprimirCola(&$$.siguiente);
                        //int nextquad = TC_elemento_siguiente(&cuadrupla);
                        //backpatch(&cuadrupla, &$1.siguiente, nextquad-1);
                    }
                ;

instruccion:    TK_CONTINUAR {}
                | asignacion 
                    {
                        $$ = $1; 
                        printf(MAGENTA"Instrucción -> Asignación \n"RESET);
                        printf("Mostramos los datos de la cola: \n");
                        imprimirCola(&$1.siguiente);
                    }
                | alternativa 
                    {
                        $$ = $1; 
                        printf(MAGENTA"Instrucción -> Alternativa \n"RESET);
                        printf("Mostramos los datos de la cola: \n");
                        imprimirCola(&$1.siguiente);
                    }
                | iteracion 
                    {
                        $$ = $1; 
                        printf(MAGENTA"Instrucción -> Iteración \n"RESET);
                        printf("Mostramos los datos de la cola: \n");
                        imprimirCola(&$1.siguiente);
                    }
                | llamada_accion {}
                ;
asignacion:     operando TK_ASIGNACION expresion
                    {
                        printf(YELLOW"Asignación entrada \n"RESET);
                        printf("Datos del operando: \n");
                        printf("Tipo: %d Sitio: %d \n", $1.tipo, $1.sitio);
                        printf("Cola true: \n");
                        imprimirCola(&$1.TRUE);
                        printf("Cola false: \n");
                        imprimirCola(&$1.FALSE);
                        printf("Datos de la expresion: \n");
                        printf("Tipo: %d Sitio: %d \n", $3.tipo, $3.sitio);
                        printf("Cola true: \n");
                        imprimirCola(&$3.TRUE);
                        printf("Cola false: \n");
                        imprimirCola(&$3.FALSE);
                        
                        //printf(GREEN"Entro aqui con $1.sitio %d $1.tipo %d \n"RESET, $1.sitio, $1.tipo);
                        //printf(GREEN"Entro aqui con $3.sitio %d $3.tipo %d \n"RESET, $3.sitio, $3.tipo);
                        /* Solo se puede modificar el tipo de las variables */
                        if(TS_consulta_tipo_simbolo(&simbolos, $1.sitio) == TS_VAR){
                            /* Se puede modificar*/
                            if($1.tipo == $3.tipo){  
                                if($1.tipo == TIPO_BOOLEANO){
                                    int nextquad = TC_elemento_siguiente(&cuadrupla);
                                    //printf(MAGENTA"ASIGNACION %d \n"RESET, nextquad);
                                    //backpatch(&cuadrupla, &$3.FALSE, nextquad+1);
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_ASIGNACION_FALSE, -1, -1, $1.sitio));
                                    /* PUEDE QUE ESTO ESTÉ MAL */
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO, -1, -1, nextquad+2));
                                    //backpatch(&cuadrupla, &$3.TRUE, nextquad);
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_ASIGNACION_TRUE, -1, -1, $1.sitio));
                                }else{
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_ASIGNACION, $1.sitio, -1, $3.sitio));
                                }
                            }else if(($1.tipo == TIPO_REAL) && ($3.tipo == TIPO_ENTERO)){
                                TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_ASIGNACION, $1.sitio, -1, $3.sitio));
                            }else if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_LITERAL_ENTERO)){
                                TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_ASIGNACION_ENTERO, $1.sitio, -1, $3.sitio));
                            }else if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_REAL)){
                                //error;
                                printf("ENTRO AQUI\n");
                            }
                        }else{
                            //printf("Entro en el else\n");
                            printf("ENTRO AQUI\n");
                        }

                        nuevaCola(&$$.siguiente);
                        printf(YELLOW"Asignación no produce ninguna salida \n"RESET);
                    }
                ;

alternativa:    TK_SI expresion TK_ENTONCES M instrucciones N lista_opciones TK_FSI
                {
                    /*printf(GREEN"Alternativa entrada\n"RESET);
                    printf("Datos de expresión: \n");
                    printf("tipo: %d sitio: %d \n", $2.tipo, $2.sitio);
                    printf("Cola true: \n");
                    imprimirCola(&$2.TRUE);
                    printf("Cola false: \n");
                    imprimirCola(&$2.FALSE);
                    printf("Datos de M: %d \n", $4);
                    printf("Datos de instrucciones: \n");
                    printf("Cola siguiente: \n");
                    imprimirCola(&$5.siguiente);
                    printf("Datos de N: %d \n", $6);
                    printf("Datos de lista opciones: \n");
                    printf("Cola siguiente: \n");
                    imprimirCola(&$7.siguiente);

                    TC_imprimir(&cuadrupla);*/

                    //if E then M S N else M S
                    //printf(CYAN"Entro en alternativa \n"RESET);
                    //Esta seria la expresion 2 de los apuntes de sentencias estructuradas
                    //int nextquad = TC_elemento_siguiente(&cuadrupla);
                    //backpatch(&cuadrupla, &$2.TRUE, $4);
                    //backpatch(&cuadrupla, &$2.FALSE, $6);
                    /*if(!esNulaCola($7.siguiente)){
                        Cola aux;
                        nuevaCola(&aux);
                        pideTurnoCola(&aux, $6);
                        if(!esNulaCola($5.siguiente)){
                            //$$.siguiente = merge(aux, merge($5.siguiente, $7.siguiente));
                        }else{
                            //$$.siguiente = merge(aux, $7.siguiente);
                        }*/
                    /*}else{ 
                        Cola aux, aux2;
                        nuevaCola(&aux);
                        nuevaCola(&aux2);
                        pideTurnoCola(&aux, $6);
                        pideTurnoCola(&aux2, nextquad);
                        if(!esNulaCola($2.FALSE)){
                            //$5.siguiente = merge(aux, merge($2.FALSE, aux2));
                        }else{
                            //$5.siguiente = merge(aux, aux2);
                        }            
                        //TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_GOTO, -1, -1, -1));

                        $$.siguiente = $5.siguiente; //Esto añadido, no se si está bien o me lo he inventado
                    }*/


                    $$.siguiente = $5.siguiente;
                    backpatch(&cuadrupla, &$2.TRUE, $4);
                    backpatch(&cuadrupla, &$2.FALSE, $6);

                    /*printf(GREEN"Alternativa salida \n"RESET);
                    printf("Cola siguiente: \n");
                    imprimirCola(&$$.siguiente);

                    TC_imprimir(&cuadrupla);*/
                }   
                ;
lista_opciones: TK_SI_NO_SI expresion TK_ENTONCES M instrucciones N lista_opciones
                {
                    /*printf(CYAN"Lista opciones entrada\n"RESET);
                    printf("Datos de expresión booleana: \n");
                    printf("tipo: %d sitio: %d \n", $2.tipo, $2.sitio);
                    printf("Cola true: \n");
                    imprimirCola(&$2.TRUE);
                    printf("Cola false: \n");
                    imprimirCola(&$2.FALSE);
                    printf("Datos de M: %d \n", $4);
                    printf("Datos de instrucciones: \n");
                    printf("Cola siguiente: \n");
                    imprimirCola(&$5.siguiente);
                    printf("Datos de N: %d \n", $6);
                    TS_imprimir(&simbolos);
                    TC_imprimir(&cuadrupla);*/
                    backpatch(&cuadrupla, &$2.TRUE, $4);
                    backpatch(&cuadrupla, &$2.FALSE, $6);
                    $$.siguiente = $5.siguiente;

                    /*printf(CYAN"Lista opciones salida \n"RESET);
                    printf("Cola siguiente: \n");
                    imprimirCola(&$$.siguiente);
                    TS_imprimir(&simbolos);
                    TC_imprimir(&cuadrupla);*/
                }
                | /* vacio */ {nuevaCola(&$$.siguiente);}
                ;
iteracion:  it_cota_fija
                {
                    $$ = $1;
                }
            | it_cota_variable
                {
                    $$ = $1;
                }
            ;               
it_cota_variable:   TK_MIENTRAS M expresion_booleana TK_HACER N instrucciones TK_FMIENTRAS
                        {
                            backpatch(&cuadrupla, &$3.TRUE, $5);
                            if(!esNulaCola($6.siguiente)){
                                backpatch(&cuadrupla, &$6.siguiente, $2);
                            }else{
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO, -1, -1, $5)); 
                            }    
                            int nextquad = TC_elemento_siguiente(&cuadrupla);
                            backpatch(&cuadrupla, &$3.FALSE, nextquad);
                            $$.siguiente = $3.FALSE;
                        }
                    ;
it_cota_fija:   TK_PARA TK_IDENTIFICADOR TK_ASIGNACION expresion TK_HASTA expresion TK_HACER instrucciones TK_FPARA
                    {

                    }
                ;

/* ACCIONES Y FUNCIONES */
definicion_accion:  TK_ACCION cabecera_accion bloque TK_FACCION
                    ;
definicion_funcion: TK_FUNCION cabecera_funcion bloque TK_DEV expresion TK_FFUNCION
                    ;
cabecera_accion:    TK_IDENTIFICADOR TK_INICIO_PARENTESIS defParForm TK_FIN_PARENTESIS TK_COMPOSICION_SECUENCIAL
                    ;
cabecera_funcion:   TK_IDENTIFICADOR TK_INICIO_PARENTESIS lista_definiciones_var TK_FIN_PARENTESIS TK_DEV definicion_tipo TK_COMPOSICION_SECUENCIAL
                    ;
defParForm:     dParForm TK_COMPOSICION_SECUENCIAL defParForm
                | /* vacio */
                ;

dParForm:       TK_ENT lista_id TK_DEF_TIPO def_tipo
                | TK_SAL lista_id TK_DEF_TIPO def_tipo
                | TK_ENT_SAL lista_id TK_DEF_TIPO def_tipo
                ;
llamada_funcion:    TK_IDENTIFICADOR TK_INICIO_PARENTESIS parametros_reales TK_FIN_PARENTESIS
                    ;
llamada_accion:     TK_IDENTIFICADOR TK_INICIO_PARENTESIS parametros_reales TK_FIN_PARENTESIS
                    ;
parametros_reales:  expresion TK_SEPARADOR parametros_reales
                    | expresion
                    | /*vacio */
                    ;

%%

int main(int argc, char **argv){  
    if (argc > 1) {
        yyin = fopen(argv[1],"r");
    }
    nuevaPila(&pila);
    TS_nuevaLista(&simbolos);
    TC_nuevaLista(&cuadrupla);
    //yydebug = 1;
    yyparse(); 
    TS_imprimir(&simbolos);
    TC_imprimir(&cuadrupla);
    CTD_imprimir(&cuadrupla, &simbolos);
}
	
void yyerror(char* s){
    printf(ROJO"PARSER ERROR: %s\n" RESET,s);
}