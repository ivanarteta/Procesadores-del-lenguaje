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
/*
%type <itype> 
%type <ftype> 
%type <exp_type> */

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
                    $$.sitio = $1.sitio;
                    $$.tipo = $1.tipo;
                    $$.TRUE = $1.TRUE;
                    $$.FALSE = $1.FALSE;
                    /*printf(ROJO"Cola $$.TRUE: \n"RESET);
                    imprimirCola(&$$.TRUE);
                    printf(ROJO"Cola $$.FALSE: \n"RESET);
                    imprimirCola(&$$.FALSE);*/
                }
            | expresion_booleana 
                {
                    $$.sitio = $1.sitio; 
                    $$.TRUE = $1.TRUE;
                    $$.FALSE = $1.FALSE;
                    $$.tipo = TIPO_BOOLEANO;
                    /*printf(ROJO"Cola $$.TRUE: \n"RESET);
                    imprimirCola(&$$.TRUE);
                    printf(ROJO"Cola $$.FALSE: \n"RESET);
                    imprimirCola(&$$.FALSE);*/
                }
            | llamada_funcion {}
            ;

/* FALTAN POR COMPROBAR CASOS */
expresion_aritmetica:   expresion_aritmetica TK_SUMA expresion_aritmetica 
                            {
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
                                }else if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_LITERAL_ENTERO)){
                                    int nueva2 = TS_newtempt(&simbolos);
                                    TS_modificar_tipo(&simbolos, nueva2, TIPO_LITERAL_ENTERO, TS_VAR);
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_ENTERO, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_ASIGNACION_ENTERO, nueva2, -1, $3.sitio));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_SUMA, $1.sitio, nueva2 , nueva));
                                    $$.tipo = TIPO_ENTERO;
                                }
                                $$.sitio = nueva;
                            }
                        | expresion_aritmetica TK_RESTA expresion_aritmetica 
                            {
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
                                }else if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_LITERAL_ENTERO)){
                                    int nueva2 = TS_newtempt(&simbolos);
                                    TS_modificar_tipo(&simbolos, nueva2, TIPO_LITERAL_ENTERO, TS_VAR);
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_ENTERO, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_ASIGNACION_ENTERO, nueva2, -1, $3.sitio));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_RESTA, $1.sitio, nueva2 , nueva));
                                    $$.tipo = TIPO_ENTERO;
                                }
                                $$.sitio = nueva;
                            }
                        | expresion_aritmetica TK_DIVISION expresion_aritmetica 
                            {
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
                            }
                        | expresion_aritmetica TK_DIV expresion_aritmetica 
                            {
                                int nueva = TS_newtempt(&simbolos);
                                if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_ENTERO, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_DIV, $1.sitio, $3.sitio, nueva));
                                    $$.tipo = TIPO_ENTERO;
                                    $$.sitio = nueva;
                                }else{
                                    printf(ROJO"ENTRO AQUI\n"RESET);
                                }
                            }
                        | expresion_aritmetica TK_MOD expresion_aritmetica 
                            {
                                int nueva = TS_newtempt(&simbolos);
                                if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_ENTERO, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_MOD, $1.sitio, $3.sitio, nueva));
                                    $$.tipo = TIPO_ENTERO;
                                    $$.sitio = nueva;
                                }else{
                                    printf(ROJO"ENTRO AQUI\n"RESET);
                                }
                            }
                        | expresion_aritmetica TK_MULTIPLICACION expresion_aritmetica 
                            {
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
                            }
                        | TK_INICIO_PARENTESIS expresion_aritmetica TK_FIN_PARENTESIS 
                            {
                                $$.tipo = $2.tipo;
                                $$.sitio = $2.sitio;
                            }
                        | operando 
                            {
                                $$.sitio = $1.sitio; 
                                $$.tipo = $1.tipo;
                            }
                        | TK_RESTA expresion_aritmetica %prec UMINUS 
                            {
                                int nueva = TS_newtempt(&simbolos);
                                TS_modificar_tipo(&simbolos, nueva, $2.tipo, TS_VAR);
                                if($2.tipo == TIPO_ENTERO){
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_RESTA_UNARIA_ENTERO, $2.sitio, -1, nueva));
                                }else if($2.tipo == TIPO_REAL){
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_RESTA_UNARIA_REAL, $2.sitio, -1, nueva));
                                }
                                $$.sitio = nueva;
                                $$.tipo = $2.tipo;
                            }
                        | TK_LITERAL_ENTERO 
                            {
                                $$.tipo = TIPO_LITERAL_ENTERO;
                                $$.sitio = $1;
                            }
                        | TK_LITERAL_REAL 
                            {
                                $$.tipo = TIPO_LITERAL_REAL;
                                $$.sitio = $1;
                            }
                        ;

expresion_booleana:     expresion_booleana TK_Y M expresion_booleana 
                            {
                                printf(MAGENTA"Expresion booleana -> 1\n"RESET);
                                printf("Valor de M %d \n", $3);
                                $$.tipo = TIPO_BOOLEANO;
                                TC_imprimir(&cuadrupla);
                                backpatch(&cuadrupla, &$1.TRUE, $3);
                                $$.FALSE = merge($1.FALSE, $4.FALSE);
                                $$.TRUE = $4.TRUE;
                                //TC_imprimir(&cuadrupla);
                                /*printf(ROJO"Cola $$.TRUE: \n"RESET);
                                imprimirCola(&$$.TRUE);
                                printf(ROJO"Cola $$.FALSE: \n"RESET);
                                imprimirCola(&$$.FALSE);*/

                            }
                        | expresion_booleana TK_O M expresion_booleana
                            {
                                /*Hay que añadirle antes de la segunda expresión booleana una M */
                                printf(MAGENTA"Expresion booleana -> 2\n"RESET);
                                printf("Valor de M %d \n", $3);
                                $$.tipo = TIPO_BOOLEANO;
                                backpatch(&cuadrupla, &$1.FALSE, $3);
                                $$.TRUE = merge($1.TRUE, $4.TRUE);
                                $$.FALSE = $4.FALSE;  

                                /*printf(ROJO"Cola $$.TRUE: \n"RESET);
                                imprimirCola(&$$.TRUE);
                                printf(ROJO"Cola $$.FALSE: \n"RESET);
                                imprimirCola(&$$.FALSE);*/
                            }
                        | TK_NO expresion_booleana
                            {
                                printf(MAGENTA"Expresion booleana -> 3\n"RESET);
                                $$.tipo = TIPO_BOOLEANO;
                                $$.TRUE = $2.FALSE;
                                $$.FALSE = $2.TRUE;
                                /*printf(ROJO"Cola $$.TRUE: \n"RESET);
                                imprimirCola(&$$.TRUE);
                                printf(ROJO"Cola $$.FALSE: \n"RESET);
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
                                printf(MAGENTA"Expresion booleana -> 6\n"RESET);
                                $$.tipo = TIPO_BOOLEANO;
                                int nextquad = TC_elemento_siguiente(&cuadrupla);
                                printf("nextquad %d", nextquad);
                                /*nuevaCola(&$$.TRUE);
                                nuevaCola(&$$.FALSE);  */
                                pideTurnoCola(&$$.TRUE, nextquad);
                                pideTurnoCola(&$$.FALSE, nextquad+1);
                                if(strcmp($2, "<") == 0){
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO_MENOR, $1.sitio, $3.sitio, -1));
                                }else if(strcmp($2, "<=") == 0){
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO_MENOR_O_IGUAL, $1.sitio, $3.sitio, -1));
                                }else if(strcmp($2, ">") == 0){
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO_MAYOR, $1.sitio, $3.sitio, -1));
                                }else if(strcmp($2, "=>") == 0){
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO_MAYOR_O_IGUAL, $1.sitio, $3.sitio, -1));
                                }else if(strcmp($2, "<>") == 0){
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO_DISTINTO, $1.sitio, $3.sitio, -1));
                                }
                                /* Aquí tiene que ir el resultado al output (2) */

                                /* POSIBLEMENTE ESTO ESTÉ MAL */
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO, -1, -1, -1));
                                
                            }
                        | expresion_aritmetica TK_IGUAL expresion_aritmetica 
                            {
                                printf(MAGENTA"Expresion booleana -> 7\n"RESET);
                                /* AQUI NO COGE BIEN EL SITIO, NO SE PORQUE */
                                $$.tipo = TIPO_BOOLEANO;
                                int nextquad = TC_elemento_siguiente(&cuadrupla);
                                pideTurnoCola(&$$.TRUE, nextquad);
                                pideTurnoCola(&$$.FALSE, nextquad+1);
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO_IGUAL, $1.sitio, $3.sitio, -1));
                                /* POSIBLEMENTE ESTO ESTÉ MAL */
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO, -1, -1, -1));
                            }
                        | TK_INICIO_PARENTESIS expresion_booleana TK_FIN_PARENTESIS 
                            {
                                printf(MAGENTA"Expresion booleana -> 8\n"RESET);
                                $$ = $2;
                                TC_imprimir(&cuadrupla);
                            }
                        ;

operando:   TK_IDENTIFICADOR 
                {
                    $$.sitio = TS_buscar_id(&simbolos,$1); 
                    $$.tipo = TS_consulta_tipo(&simbolos, $$.sitio);
                    nuevaCola(&$$.TRUE);
                    nuevaCola(&$$.FALSE);  
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
                        /* Faltaria un backpatch con $1.siguiente y $3? */
                        printf("Valor de M %d \n", $3);
                        backpatch(&cuadrupla, &$1.siguiente, $3);
                        $$ = $1;
                    }
                | instruccion 
                    {
                        $$ = $1;
                    }
                ;

instruccion:    TK_CONTINUAR {}
                | asignacion {$$ = $1;}
                | alternativa {$$ = $1;}
                | iteracion {$$ = $1;}
                | llamada_accion {}
                ;
asignacion:     operando TK_ASIGNACION expresion
                    {
                        //printf(GREEN"Entro aqui con $1.sitio %d $1.tipo %d \n"RESET, $1.sitio, $1.tipo);
                        //printf(GREEN"Entro aqui con $3.sitio %d $3.tipo %d \n"RESET, $3.sitio, $3.tipo);
                        /* Solo se puede modificar el tipo de las variables */
                        if(TS_consulta_tipo_simbolo(&simbolos, $1.sitio) == TS_VAR){
                            /* Se puede modificar*/
                            if($1.tipo == $3.tipo){  
                                if($1.tipo == TIPO_BOOLEANO){
                                    int nextquad = TC_elemento_siguiente(&cuadrupla);
                                    backpatch(&cuadrupla, &$3.FALSE, nextquad+1);
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_ASIGNACION_FALSE, -1, -1, $1.sitio));
                                    /* PUEDE QUE ESTO ESTÉ MAL */
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO, -1, -1, nextquad+2));
                                    backpatch(&cuadrupla, &$3.TRUE, nextquad);
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
                                printf(ROJO"ENTRO AQUI\n"RESET);
                            }
                        }else{
                            //printf("Entro en el else\n");
                            printf(ROJO"ENTRO AQUI\n"RESET);
                        }

                        nuevaCola(&$$.siguiente);
                    }
                ;

alternativa:    TK_SI expresion_booleana TK_ENTONCES M instrucciones N lista_opciones TK_FSI
                {
                    printf(CYAN"Entro en alternativa \n"RESET);
                    printf("Valor de M %d \n", $4);
                    printf("Valor de N %d \n", $6);
                    //if E then M S N else M S
                    /* Otra */
                    //backpatch(&cuadrupla, &$2.TRUE, $4);
                    //backpatch(&cuadrupla, &$2.FALSE, $6);
                    //$$.siguiente = merge(&$5.siguiente, merge(&$6.siguiente, &$8.siguiente));
                    //printf(CYAN"Entro en alternativa \n"RESET);
                    //Esta seria la expresion 2 de los apuntes de sentencias estructuradas
                    int nextquad = TC_elemento_siguiente(&cuadrupla);
                    printf(CYAN"nextquad = %d \n"RESET, nextquad);
                    printf(CYAN"Cola true: \n"RESET);
                    imprimirCola(&$2.TRUE);
                    printf(CYAN"Cola false: \n"RESET);
                    imprimirCola(&$2.FALSE);
                    printf(CYAN"Cola 5 siguiente: \n"RESET);
                    imprimirCola(&$5.siguiente);
                    printf(CYAN"Cola 7 siguiente: \n"RESET);
                    imprimirCola(&$7.siguiente);
                    backpatch(&cuadrupla, &$2.TRUE, $4);
                    backpatch(&cuadrupla, &$2.FALSE, $6);
                    printf(CYAN"He terminado los backpatch\n"RESET);
                    if(!esNulaCola($7.siguiente)){
                        //$5.siguiente = merge($6.siguiente, merge($2.siguiente, $7.siguiente));
                        printf(CYAN"Entro en el if \n"RESET);
                        Cola aux;
                        nuevaCola(&aux);
                        pideTurnoCola(&aux, $6);
                        printf("Vamos a hacer el merge \n");
                        $$.siguiente = merge(aux, merge($5.siguiente, $7.siguiente));
                        printf(CYAN"Cola siguiente: \n"RESET);
                        imprimirCola(&$$.siguiente);
                    }else{ 
                        printf(CYAN"Entro en el else \n"RESET);
                        Cola aux, aux2;
                        nuevaCola(&aux);
                        nuevaCola(&aux2);
                        pideTurnoCola(&aux, $6);
                        pideTurnoCola(&aux2, nextquad);
                        $5.siguiente = merge(aux, merge($2.FALSE, aux2));
                        printf(CYAN"Cola 5 siguiente: \n"RESET);
                        imprimirCola(&$5.siguiente);
                        /* PUEDE QUE ESTO ESTÉ MAL */
                        TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_GOTO, -1, -1, -1));
                    }
                }   
                ;
lista_opciones: TK_SI_NO_SI expresion_booleana TK_ENTONCES M instrucciones N lista_opciones
                {
                    //Esta seria la expresion 1 de los apuntes de sentencias estructuradas
                    printf(CYAN"Entro en lista opciones \n"RESET);
                    printf("Valor de M %d \n", $4);
                    printf("Valor de N %d \n", $6);
                    //int nextquad = TC_elemento_siguiente(&cuadrupla);
                    printf(CYAN"nextquad = %d \n"RESET, $4);
                    printf(CYAN"Cola true: \n"RESET);
                    imprimirCola(&$2.TRUE);
                    printf(CYAN"Cola false: \n"RESET);
                    imprimirCola(&$2.FALSE);
                    printf(CYAN"Cola siguiente: \n"RESET);
                    imprimirCola(&$5.siguiente);
                    backpatch(&cuadrupla, &$2.TRUE, $6);
                    printf(CYAN"He terminado los backpatch\n"RESET);
                    if(!esNulaCola($5.siguiente)){
                        printf(CYAN"Entro en el if \n"RESET);
                        $5.siguiente = merge($2.FALSE, $5.siguiente);
                        printf(CYAN"Cola siguiente: \n"RESET);
                        imprimirCola(&$5.siguiente);
                    }else{
                        printf(CYAN"Entro en el else \n"RESET);
                        Cola aux;
                        nuevaCola(&aux);
                        pideTurnoCola(&aux, $4);
                        $5.siguiente = merge($2.FALSE, aux);
                        printf(CYAN"Cola siguiente: \n"RESET);
                        imprimirCola(&$5.siguiente);
                        /* PUEDE QUE ESTO ESTE MAL */
                        TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_GOTO, -1, -1, -1));
                    }
                    $$.siguiente = $5.siguiente;
                    //Habria que guardar los datos de M y de S para mandarlos a la otra sentencia??
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
it_cota_variable:   TK_MIENTRAS M expresion TK_HACER N instrucciones TK_FMIENTRAS
                        {
                            printf("Valor de M %d \n", $2);
                            printf("Valor de N %d \n", $5);
                            backpatch(&cuadrupla, &$3.TRUE, $5);
                            if(!esNulaCola($6.siguiente)){
                                backpatch(&cuadrupla, &$6.siguiente, $2);
                            }else{
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO, -1, -1, $5)); 
                            }    
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
    yydebug = 1;
    yyparse(); 
    TS_imprimir(&simbolos);
    TC_imprimir(&cuadrupla);
    CTD_imprimir(&cuadrupla, &simbolos);
}
	
void yyerror(char* s){
    printf(ROJO"PARSER ERROR: %s\n" RESET,s);
}