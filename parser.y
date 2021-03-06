%{
#include "definiciones.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tabla_cuadruplas.h"
#include "tabla_simbolos.h"
#include "cola.h"

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
Cola cola;

/* Falta algo para las expresiones que tenga un campo para el tipo (real, entero, booleano, ...)
    y para un apuntador a la tabla de simbolos.*/
%}

%union{
    char* ctype; /* Para las cadenas de caracteres (id, string, ...) */
    int itype; /* Para los números enteros y los booleanos */
    float ftype; /* Para los números reales */   
    /* Para las expresiones */
    enum enum_tipo tipo;
    enum enum_tipo_celda celda;
    enum enum_literales literales;
    struct exp_type{
        int tipo;
        char* sitio; //Apuntador para la tabla de simbolos
    }exp_type;
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
%type <ctype> lista_id 
%type <itype> def_tipo
%type <tipo> tipo_base
%type <literales_type> tipo_literal
%type <exp_type> asignacion operando expresion expresion_aritmetica
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
                                    TS_insertar_constante(&simbolos, TS_crear_constante($1,$3.tipo,$3.valor), TS_CONSTANTE);
                                }
                            | /* vacio */ 
                            ;
tipo_literal:   TK_LITERAL_CADENA {$$.tipo = LITERAL_CADENA; $$.valor.caracteres = $1;}
                | TK_LITERAL_CARACTER {$$.tipo = LITERAL_CARACTER; $$.valor.caracteres = $1;}
                | TK_LITERAL_ENTERO {$$.tipo = LITERAL_ENTERO; $$.valor.entero = $1;}
                | TK_LITERAL_REAL {$$.tipo = LITERAL_REAL; $$.valor.real = $1;}
                | TK_VERDADERO {$$.tipo = LITERAL_VERDADERO; $$.valor.entero = $1;}
                | TK_FALSO {$$.tipo = LITERAL_FALSO; $$.valor.entero = $1;}
                ;

lista_definiciones_var:     lista_id TK_COMPOSICION_SECUENCIAL lista_definiciones_var
                            | /* vacio */
                            ;
lista_id:   TK_IDENTIFICADOR TK_SEPARADOR lista_id 
                {
                    pideTurnoCola(&cola, $1);
                    TS_insertar_variable(&simbolos, TS_crear_variable($1, $3), TS_VAR);
                    $$=$3;
                }
            | TK_IDENTIFICADOR TK_DEF_TIPO def_tipo 
                {
                    pideTurnoCola(&cola, $1);
                    TS_insertar_variable(&simbolos, TS_crear_variable($1, $3), TS_VAR); 
                    $$=$3;
                }
            /*| vacio */
            ;
definiciones_variables_interaccion: definicion_entrada
                                    | definicion_entrada definicion_salida
                                    | definicion_salida
                                    ;
definicion_entrada: TK_ENT lista_definiciones_var 
                        {
                            while(!esNulaCola(cola)){
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_INPUT, primeroCola(cola), NULL, NULL));
                                 avanceCola(&cola);
                            }
                        }
                    ;
definicion_salida:  TK_SAL lista_definiciones_var 
                        {
                            while(!esNulaCola(cola)){
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_OUTPUT, primeroCola(cola), NULL, NULL));
                                 avanceCola(&cola);
                            }
                        }
                    ;    

/* EXPRESIONES */
expresion:  expresion_aritmetica {$$.sitio = $1.sitio;}
            | expresion_booleana {}
            | llamada_funcion {}
            ;

expresion_aritmetica:   expresion_aritmetica TK_SUMA expresion_aritmetica {}
                        | expresion_aritmetica TK_RESTA expresion_aritmetica {}
                        | expresion_aritmetica TK_DIVISION expresion_aritmetica {}
                        | expresion_aritmetica TK_DIV expresion_aritmetica {}
                        | expresion_aritmetica TK_MOD expresion_aritmetica {}
                        | expresion_aritmetica TK_MULTIPLICACION expresion_aritmetica {}
                        | TK_INICIO_PARENTESIS expresion_aritmetica TK_FIN_PARENTESIS {}
                        | operando {$$.sitio = $1.sitio;}
                        | TK_RESTA expresion_aritmetica %prec UMINUS {}
                        | TK_LITERAL_ENTERO {$$.tipo = TIPO_ENTERO;
                                            char cont[5];
                                            sprintf(cont, "%d", TS_get_contador(&simbolos));
                                            char nombre[6];
                                            strcpy(nombre, "t");
                                            strcat(nombre, cont);
                                            $$.sitio = strdup(nombre);
                                            TS_insertar_variable(&simbolos, TS_crear_variable(nombre, TIPO_ENTERO), TS_VAR);}
                        | TK_LITERAL_REAL {$$.tipo = TIPO_REAL;
                                            char cont[5];
                                            sprintf(cont, "%d", TS_get_contador(&simbolos));
                                            char nombre[6];
                                            strcpy(nombre, "t");
                                            strcat(nombre, cont);
                                            $$.sitio = strdup(nombre);
                                            TS_insertar_variable(&simbolos, TS_crear_variable(nombre, TIPO_REAL), TS_VAR);}
                        ;

expresion_booleana:     expresion_booleana TK_Y expresion_booleana
                        | expresion_booleana TK_O expresion_booleana
                        | TK_NO expresion_booleana
                        | TK_VERDADERO
                        | TK_FALSO
                        | expresion_aritmetica TK_OPERADOR_RELACIONAL expresion_aritmetica
                        | expresion_aritmetica TK_IGUAL expresion_aritmetica
                        | TK_INICIO_PARENTESIS expresion_booleana TK_FIN_PARENTESIS
                        ;
operando:   TK_IDENTIFICADOR {$$.sitio = $1;}
            | operando TK_REFERENCIA operando {}
            | operando TK_INICIO_ARRAY expresion TK_FIN_ARRAY {}
            | operando TK_REF {}
            ;                      

/* INSTRUCCIONES */
instrucciones:  instruccion TK_COMPOSICION_SECUENCIAL instrucciones
                | instruccion
                ;
instruccion:    TK_CONTINUAR
                | asignacion 
                | alternativa
                | iteracion 
                | llamada_accion
                ;
asignacion:     operando TK_ASIGNACION expresion
                    {
                        printf(ROJO"$1 %s \n"RESET, $1.sitio);
                        printf(ROJO"$3 %s \n"RESET, $3.sitio);

                        int tipo = TS_consulta_tipo(&simbolos, $1.sitio);
                        printf(ROJO"tipo %d \n"RESET, tipo);            

                        /* HAY QUE TENER EN CUENTA QUE A LA HORA DE LA ASIGNACION A UNA VARIABLE P.E. BOOLEANA
                        NO SE LE PUEDE ASIGNAR UN ENTERO */
                        if(TS_consulta_tipo(&simbolos, $1.sitio) == TS_consulta_tipo(&simbolos,$3.sitio)){   
                            TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_ASIGNACION, $1.sitio, NULL, $3.sitio));
                            printf(GREEN"SITIO %s \n"RESET, $3.sitio); 
                        }else if((TS_consulta_tipo(&simbolos,$1.sitio) == TIPO_REAL) && (TS_consulta_tipo(&simbolos,$3.sitio) == TIPO_ENTERO)){
                            TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_ASIGNACION, $1.sitio, NULL, $3.sitio));
                            printf("Entro 2\n");
                        }else if((TS_consulta_tipo(&simbolos,$1.sitio) == TIPO_ENTERO) && (TS_consulta_tipo(&simbolos,$3.sitio) == TIPO_REAL)){
                            printf("Entro 3\n");
                            //error;
                        }
                    }
                ;
alternativa:    TK_SI expresion TK_ENTONCES instrucciones lista_opciones TK_FSI
                ;
lista_opciones: TK_SI_NO_SI expresion TK_ENTONCES instrucciones lista_opciones
                | /* vacio */
                ;
iteracion:  it_cota_fija
            | it_cota_variable
            ;               
it_cota_variable:   TK_MIENTRAS expresion TK_HACER instrucciones TK_FMIENTRAS
                    ;
it_cota_fija:   TK_PARA TK_IDENTIFICADOR TK_ASIGNACION expresion TK_HASTA expresion TK_HACER instrucciones TK_FPARA
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
    nuevaCola(&cola);
    TS_nuevaLista(&simbolos);
    TC_nuevaLista(&cuadrupla);
    yydebug = 1;
    yyparse();
    TS_imprimir(&simbolos);
    TC_imprimir(&cuadrupla);
    TC_imprimir_C3D(&cuadrupla);
}
	
int yyerror(char* s){
    printf(ROJO"PARSER ERROR: %s\n" RESET,s);
}