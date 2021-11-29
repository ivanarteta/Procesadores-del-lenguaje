%{

#include "pila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tabla_cuadruplas.h"
#include "tabla_simbolos.h"
#include "codigo_tres_direcciones.h"


#define YYDEBUG 1
int yyerror(char *s);
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
%type <itype> lista_id def_tipo M
%type <celda> tipo_base
%type <literales_type> tipo_literal
%type <exp_type> operando expresion expresion_aritmetica expresion_booleana
%type <inst_type> it_cota_fija it_cota_variable instrucciones alternativa iteracion instruccion asignacion
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
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_INPUT, cima(pila), NULL, NULL));
                                desapilar(&pila);
                            }
                        }
                    ;
definicion_salida:  TK_SAL lista_definiciones_var 
                        {
                            while(!esNulaPila(pila)){
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_OUTPUT, cima(pila), NULL, NULL));
                                desapilar(&pila);
                            }
                        }
                    ;    

/* EXPRESIONES */
expresion:  expresion_aritmetica 
                {
                    $$.sitio = $1.sitio; 

                    $$.tipo = TS_consulta_tipo(&simbolos, $1.sitio);
                    $$.TRUE = $1.TRUE;
                    $$.FALSE = $1.FALSE;
                    //printf(GREEN"sitio2: %d\n"RESET, $$.sitio);
                    //printf(GREEN"sitio: %s"RESET, $$.sitio);
                }
            | expresion_booleana 
                {
                    $$.sitio = $1.sitio; 
                    $$.TRUE = $1.TRUE;
                    $$.FALSE = $1.FALSE;
                    $$.tipo = TIPO_BOOLEANO;
                    //printf(GREEN"sitio3: %s\n"RESET, $$.sitio);
                }
            | llamada_funcion {}
            ;

expresion_aritmetica:   expresion_aritmetica TK_SUMA expresion_aritmetica 
                            {
                                int nueva = TS_newtempt(&simbolos);
                                if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_ENTERO, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_SUMA, $1.sitio, $3.sitio, nueva));
                                    $$.tipo = TIPO_ENTERO;
                                }else if(($1.tipo == TIPO_REAL) && ($3.tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, $3.sitio, NULL, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_SUMA, nueva, $1.sitio, nueva));
                                    $$.tipo = TIPO_REAL;
                                }else if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, $1.sitio, NULL, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_SUMA, nueva, $3.sitio, nueva));
                                    $$.tipo = TIPO_REAL;
                                }else if(($1.tipo == TIPO_REAL) && ($3.tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_SUMA, $1.sitio, $3.sitio, nueva));
                                    $$.tipo = TIPO_REAL;
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
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, $3.sitio, NULL, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_RESTA, nueva, $1.sitio, nueva));
                                    $$.tipo = TIPO_REAL;
                                }else if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, $1.sitio, NULL, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_RESTA, nueva, $3.sitio, nueva));
                                    $$.tipo = TIPO_REAL;
                                }else if(($1.tipo == TIPO_REAL) && ($3.tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_RESTA, $1.sitio, $3.sitio, nueva));
                                    $$.tipo = TIPO_REAL;
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
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, $1.sitio, NULL, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, $3.sitio, NULL, nueva2));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_DIVISION, nueva, nueva2, nueva));
                                }else if(($1.tipo == TIPO_REAL) && ($3.tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, $3.sitio, NULL, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_DIVISION, nueva, $1.sitio, nueva));
                                }else if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, $1.sitio, NULL, nueva));
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
                                /* Esta es la division entera */
                                int nueva = TS_newtempt(&simbolos);
                                if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_ENTERO, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_DIV, $1.sitio, $3.sitio, nueva));
                                    $$.tipo = TIPO_ENTERO;
                                    $$.sitio = nueva;
                                }else{
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
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, $3.sitio, NULL, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_MULTIPLICACION, nueva, $1.sitio, nueva));
                                    $$.tipo = TIPO_REAL;
                                }else if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, $1.sitio, NULL, nueva));
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
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_RESTA_UNARIA_ENTERO, $2.sitio, NULL, nueva));
                                }else if($2.tipo == TIPO_REAL){
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_RESTA_UNARIA_REAL, $2.sitio, NULL, nueva));
                                }
                                $$.sitio = nueva;
                                $$.tipo = $2.tipo;
                            }
                        | TK_LITERAL_ENTERO 
                            {
                                //int nueva = TS_newtempt(&simbolos);
                                $$.tipo = TIPO_ENTERO;
                                $$.sitio = $1;
                                printf(CYAN"Entro aqui %d %d \n",$$.tipo, $$.sitio);
                                //TS_modificar_tipo(&simbolos, nueva, TIPO_ENTERO, TS_VAR);
                            }
                        | TK_LITERAL_REAL 
                            {
                                int nueva = TS_newtempt(&simbolos);
                                $$.tipo = TIPO_REAL;
                                $$.sitio = nueva;
                                TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                            }
                        ;

expresion_booleana:     expresion_booleana TK_Y M expresion_booleana 
                            {
                                /*Hay que añadirle antes de la segunda expresión booleana una M */
                                printf(MAGENTA"Expresion booleana -> 1\n"RESET);
                                $$.tipo = TIPO_BOOLEANO;
                                backpatch(&cuadrupla, &$1.TRUE, $3);
                                $$.FALSE = merge($1.FALSE, $4.FALSE);
                                $$.TRUE = $4.TRUE;
                            }
                        | expresion_booleana TK_O M expresion_booleana
                            {
                                /*Hay que añadirle antes de la segunda expresión booleana una M */
                                printf(MAGENTA"Expresion booleana -> 2\n"RESET);
                                $$.tipo = TIPO_BOOLEANO;
                                backpatch(&cuadrupla, &$1.FALSE, $3);
                                $$.TRUE = merge($1.TRUE, $4.TRUE);
                                $$.FALSE = $4.FALSE;  
                            }
                        | TK_NO expresion_booleana
                            {
                                printf(MAGENTA"Expresion booleana -> 3\n"RESET);
                                $$.tipo = TIPO_BOOLEANO;
                                $$.TRUE = $2.FALSE;
                                $$.FALSE = $2.TRUE;
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
                                //TC_imprimir(&cuadrupla);
                                $$.tipo = TIPO_BOOLEANO;
                                int nextquad = TC_elemento_siguiente(&cuadrupla);
                                pideTurnoCola(&$$.TRUE, nextquad);
                                pideTurnoCola(&$$.FALSE, nextquad+1);
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_IGUAL, $1.sitio, $3.sitio, NULL));
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO, NULL, NULL, NULL));
                            }
                        | expresion_aritmetica TK_IGUAL expresion_aritmetica 
                            {
                                printf(MAGENTA"Expresion booleana -> 7\n"RESET);
                                /* AQUI NO COGE BIEN EL SITIO, NO SE PORQUE */
                                $$.tipo = TIPO_BOOLEANO;
                                int nextquad = TC_elemento_siguiente(&cuadrupla);
                                pideTurnoCola(&$$.TRUE, nextquad);
                                pideTurnoCola(&$$.FALSE, nextquad+1);
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_IGUAL, $1.sitio, $3.sitio, NULL));
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO, NULL, NULL, NULL));
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

/* INSTRUCCIONES */
instrucciones:  instruccion TK_COMPOSICION_SECUENCIAL M instrucciones 
                    {
                        /* Faltaria un backpatch con $1.siguiente y $3? */
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
                        /* Solo se puede modificar el tipo de las variables */
                        if(TS_consulta_tipo_simbolo(&simbolos, $1.sitio) == TS_VAR){
                            /* Se puede modificar*/
                            if($1.tipo == $3.tipo){  
                                if($1.tipo == TIPO_BOOLEANO){
                                    int nextquad = TC_elemento_siguiente(&cuadrupla);
                                    backpatch(&cuadrupla, &$3.FALSE, nextquad+1);
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_ASIGNACION_FALSE, NULL, NULL, $1.sitio));
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO, NULL, NULL, nextquad+2));
                                    backpatch(&cuadrupla, &$3.TRUE, nextquad);
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_ASIGNACION_TRUE, NULL, NULL, $1.sitio));
                                    /*backpatch(&cuadrupla, &$3.TRUE, nextquad);
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_ASIGNACION_TRUE, NULL, NULL, $1.sitio));
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO, NULL, NULL, nextquad+2));
                                    backpatch(&cuadrupla, &$3.FALSE,  nextquad+1);
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_ASIGNACION_FALSE, NULL, NULL, $1.sitio));*/
                                }else{
                                    printf(GREEN"Entro aqui con $1.sitio %d \n"RESET, $1.sitio);
                                    printf(GREEN"Entro aqui con $3.sitio %d \n"RESET, $3.sitio);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_ASIGNACION, $1.sitio, NULL, $3.sitio));
                                }
                            }else if(($1.tipo == TIPO_REAL) && ($3.tipo == TIPO_ENTERO)){
                                TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_ASIGNACION, $1.sitio, NULL, $3.sitio));
                            }else if(($1.tipo == TIPO_ENTERO) && ($3.tipo == TIPO_REAL)){
                                //error;
                            }
                        }

                        nuevaCola(&$$.siguiente);
                    }
                ;

alternativa:    TK_SI expresion_booleana TK_ENTONCES M instrucciones N lista_opciones TK_FSI
                {
                    //Esta seria la expresion 2 de los apuntes de sentencias estructuradas
                    int nextquad = TC_elemento_siguiente(&cuadrupla);
                    char numero[10];
                    sprintf(numero, "%d", nextquad);
                    backpatch(&cuadrupla,&$2.true, numero);
                    //backpatch(&cuadrupla,&$2.false, numero);
                    if(!empty($7.next)){
                        $5.next = merge(/*$6.next,*/ &$2.next,$7.next);
                    }else{
                        $5.next = merge(/*$6.next,*/ &$2.false,TC_crear_lista(nextquad));
                        TC_insertar(OP_GOTO,NULL,NULL,NULL);
                    }
                }   
                ;
lista_opciones: TK_SI_NO_SI expresion_booleana TK_ENTONCES M instrucciones lista_opciones
                {
                    //Esta seria la expresion 1 de los apuntes de sentencias estructuradas
                    int nextquad = TC_elemento_siguiente(&cuadrupla);
                    char numero[10];
                    sprintf(numero, "%d", nextquad);
                    backpatch(&cuadrupla,&$2.true, numero);
                    if(!empty($5.next)){
                        $5.next = merge(&$2.false,$5.next);
                    }else{
                        $5.next = merge(&$2.false,TC_crear_lista(nextquad));
                        TC_insertar(OP_GOTO,NULL,NULL,NULL);
                    }
                    //Habria que guardar los datos de M y de S para mandarlos a la otra sentencia??

                }
                | /* vacio */ {}
>>>>>>> 5bd61a8dcaa7119583ab70e87365471b37474c49
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
it_cota_variable:   TK_MIENTRAS M expresion TK_HACER M instrucciones TK_FMIENTRAS
                        {
                            printf(ROJO"Holaaaa \n"RESET);
                            backpatch(&cuadrupla, &$3.TRUE, $5);
                            printf(ROJO"Adiossss \n"RESET);
                            if(!esNulaCola($6.siguiente)){
                                printf(ROJO"Holaaaa22 \n"RESET);
                                backpatch(&cuadrupla, &$6.siguiente, $2);
                                printf(ROJO"Adiossss22 \n"RESET);
                            }else{
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO, NULL, NULL, $2)); 
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
    //TC_imprimir_C3D(&cuadrupla);
}
	
int yyerror(char* s){
    printf(ROJO"PARSER ERROR: %s\n" RESET,s);
}