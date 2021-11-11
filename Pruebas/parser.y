%{
    /*#Declaraciones en C
    #Con union definimos indirectamente una union con un campo
    #para cada valor semantico, por ejemplo char* cadena e int numero*/
    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>
    #include <math.h>
	#include <stdlib.h>

    int yyerror(char *s);
    int yylex(void);
    int yyparse(void);
    extern FILE * yyin;
    extern int yydebug;

    #define YYDEBUG 1

%}
    /*Declaraciones Yacc/Bison*/
%union{
    int itype;
    float ftype;
    char* stype;
    char ctype;
}/* YYSTYPE */

%token TK_LITERAL_CADENA
%token TK_LITERAL_CARACTER
%token TK_LITERAL_ENTERO
%token TK_LITERAL_REAL
%token TK_IDENTIFICADOR
 /* Aquí quitamos el TK_LITERAL_BOOLEANO */

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
%token TK_FALSO
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
%token TK_VERDADERO

%token TK_COMENTARIO

%token TK_ASIGNACION
%token TK_COMPOSICION_SECUENCIAL
%token TK_SEPARADOR /* NUEVO */
%token TK_SUBRANGO
%token TK_DEF_TIPO
%token TK_ENTONCES
%token TK_SI_NO_SI
%token TK_FIN_ARRAY

 /* NUEVOSSS */
%token TK_INICIO_PARENTESIS
%token TK_FIN_PARENTESIS
%token TK_IGUAL
%token TK_OPERADOR_RELACIONAL

/* Prioridades */
 //Operadores de referencia
%left TK_REFERENCIA TK_Y TK_SUMA TK_RESTA
%left TK_INICIO_ARRAY TK_O TK_MULTIPLICACION TK_DIVISION TK_DIV
%left TK_REF TK_NO TK_MOD
%left UMINUS


%%
/* Reglas de la gramatica */
descripcion_algoritmo: TK_ALGORITMO TK_IDENTIFICADOR TK_COMPOSICION_SECUENCIAL cabecera_algoritmo bloque_algoritmo TK_FALGORITMO;
cabecera_algoritmo: definiciones_globales definiciones_acciones_funciones definiciones_variables_interaccion TK_COMENTARIO;
bloque_algoritmo: bloque TK_COMENTARIO;
definiciones_globales:  definicion_tipo definiciones_globales
                        | definicion_const definiciones_globales
                        | /* vacio */
                        ;
definiciones_acciones_funciones:    definicion_accion definiciones_acciones_funciones
                                    | definicion_funcion definiciones_acciones_funciones
                                    | /* vacio */
                                    ;
bloque: declaraciones instrucciones;
declaraciones:  definicion_tipo declaraciones
                | definicion_const declaraciones 
                | definicion_var declaraciones
                | /* vacio */
                ;

/* DEFINICIONES */
definicion_tipo: TK_TIPO lista_definiciones_tipo TK_FTIPO;
definicion_const: TK_CONST lista_definiciones_const TK_FCONST;
definicion_var: TK_VAR lista_definiciones_var TK_FVAR;

/* DEFINICIONES DE TIPOS */
lista_definiciones_tipo:    TK_IDENTIFICADOR TK_IGUAL def_tipo TK_COMPOSICION_SECUENCIAL lista_definiciones_tipo
                            | /* vacio */
                            ;
def_tipo:    TK_TUPLA lista_campos TK_FTUPLA
                    | TK_TABLA TK_INICIO_ARRAY expresion_tabla TK_SUBRANGO expresion_tabla TK_FIN_ARRAY TK_DE def_tipo
                    | TK_IDENTIFICADOR
                    | expresion_tabla TK_SUBRANGO expresion_tabla
                    | TK_REF def_tipo
                    | tipo_base
                    ;
tipo_base:  TK_ENTERO 
            | TK_BOOLEANO 
            | TK_CARACTER 
            | TK_REAL 
            | TK_CADENA 
            ;

expresion_tabla:    expresion 
                    | TK_LITERAL_CARACTER
                    ;
lista_campos:   TK_IDENTIFICADOR TK_DEF_TIPO def_tipo TK_COMPOSICION_SECUENCIAL lista_campos
                | /* vacio */
                ;

/* DECLARACION DE CONSTANTES Y VARIABLES */
lista_definiciones_const:   TK_IDENTIFICADOR TK_IGUAL TK_LITERAL_CADENA TK_COMPOSICION_SECUENCIAL lista_definiciones_const
                            | TK_IDENTIFICADOR TK_IGUAL TK_LITERAL_CARACTER TK_COMPOSICION_SECUENCIAL lista_definiciones_const
                            | TK_IDENTIFICADOR TK_IGUAL TK_LITERAL_ENTERO TK_COMPOSICION_SECUENCIAL lista_definiciones_const
                            | TK_IDENTIFICADOR TK_IGUAL TK_LITERAL_REAL TK_COMPOSICION_SECUENCIAL lista_definiciones_const
                            | TK_IDENTIFICADOR TK_IGUAL TK_VERDADERO TK_COMPOSICION_SECUENCIAL lista_definiciones_const
                            | TK_IDENTIFICADOR TK_IGUAL TK_FALSO TK_COMPOSICION_SECUENCIAL lista_definiciones_const
                            | /* vacio */
                            ;

lista_definiciones_var:     lista_id TK_DEF_TIPO def_tipo TK_COMPOSICION_SECUENCIAL lista_definiciones_var
                            | /* vacio */
                            ;

lista_id:   TK_IDENTIFICADOR TK_SEPARADOR lista_id
            | TK_IDENTIFICADOR
            ;
definiciones_variables_interaccion: definicion_entrada
                                    | definicion_entrada definicion_salida
                                    | definicion_salida
                                    ;
definicion_entrada: TK_ENT lista_definiciones_var;
definicion_salida:  TK_SAL lista_definiciones_var;

/* EXPRESIONES */
expresion:  expresion_aritmetica
            | expresion_booleana
            | llamada_funcion
            ;
expresion_aritmetica:   expresion_aritmetica TK_SUMA expresion_aritmetica
                        | expresion_aritmetica TK_RESTA expresion_aritmetica
                        | expresion_aritmetica TK_DIVISION expresion_aritmetica
                        | expresion_aritmetica TK_DIV expresion_aritmetica
                        | expresion_aritmetica TK_MOD expresion_aritmetica
                        | expresion_aritmetica TK_MULTIPLICACION expresion_aritmetica
                        | TK_INICIO_PARENTESIS expresion_aritmetica TK_FIN_PARENTESIS
                        | operando
                        | TK_RESTA expresion_aritmetica %prec UMINUS
                        | TK_LITERAL_ENTERO 
                        | TK_LITERAL_REAL 
                        ;
    /* FALTA POR MIRAR */
expresion_booleana:     expresion_booleana TK_Y expresion_booleana
                        | expresion_booleana TK_O expresion_booleana
                        | TK_NO expresion_booleana
                        | TK_VERDADERO
                        | TK_FALSO
                        | expresion_booleana TK_OPERADOR_RELACIONAL expresion_booleana
                        | expresion_booleana TK_IGUAL expresion_booleana
                        | TK_INICIO_PARENTESIS expresion_booleana TK_FIN_PARENTESIS
                        ;
operando:   TK_IDENTIFICADOR
            | operando TK_REFERENCIA operando
            | operando TK_INICIO_ARRAY expresion TK_FIN_ARRAY
            | operando TK_REF
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
asignacion:     operando TK_ASIGNACION expresion;
alternativa:    TK_SI expresion TK_ENTONCES instrucciones lista_opciones TK_FSI;
lista_opciones: TK_SI_NO_SI expresion TK_ENTONCES instrucciones lista_opciones
                | /* vacio */
                ;
iteracion:  it_cota_fija
            | it_cota_variable
            ;
it_cota_variable: TK_MIENTRAS expresion TK_HACER instrucciones TK_FMIENTRAS;
it_cota_fija:   TK_PARA TK_IDENTIFICADOR TK_ASIGNACION expresion TK_HASTA expresion TK_HACER instrucciones TK_FPARA;

/* ACCIONES Y FUNCIONES */
definicion_accion: TK_ACCION cabecera_accion bloque TK_FACCION;
definicion_funcion: TK_FUNCION cabecera_funcion bloque TK_DEV expresion TK_FFUNCION;
cabecera_accion:    TK_IDENTIFICADOR TK_INICIO_PARENTESIS defParForm TK_FIN_PARENTESIS TK_COMPOSICION_SECUENCIAL;
cabecera_funcion:   TK_IDENTIFICADOR TK_INICIO_PARENTESIS lista_definiciones_var TK_FIN_PARENTESIS TK_DEV definicion_tipo TK_COMPOSICION_SECUENCIAL;
defParForm:     dParForm TK_COMPOSICION_SECUENCIAL defParForm
                | /* vacio */
                ;

dParForm:       TK_ENT lista_id TK_DEF_TIPO def_tipo
                | TK_SAL lista_id TK_DEF_TIPO def_tipo
                | TK_ENT_SAL lista_id TK_DEF_TIPO def_tipo
                ;

llamada_funcion: TK_IDENTIFICADOR TK_INICIO_PARENTESIS parametros_reales TK_FIN_PARENTESIS;
llamada_accion:  TK_IDENTIFICADOR TK_INICIO_PARENTESIS parametros_reales TK_FIN_PARENTESIS;

parametros_reales:  expresion TK_SEPARADOR parametros_reales
                    | expresion
                    | /*vacio */
                    ;
%%
    /* Código C */
int yyerror(char *s){
    printf("Error: %s\n", s);
}

/*int main(int argc,char ** argv){
    yydebug = 2;
    return 0;
}*/

int main(int argc, char **argv){  
    /*++argv, --argc;*/ /* skip over program name */
    /*if (argc > 0)
        yyin = fopen( argv[0], "r" );
    else
        yyin = stdin;

    yydebug = 1;
    yyparse();*/


    if (argc > 1) {
        yyin = fopen(argv[1],"r");
    }

    yyparse();


}