%{
    /*#Declaraciones en C
    #Con union definimos indirectamente una union con un campo
    #para cada valor semantico, por ejemplo char* cadena e int numero*/
    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>
    #include <math.h>
	#include <stdlib.h>
%}
    /*Declaraciones Yacc/Bison
    #%token <campo_union> NOMBRE_TOKEN
    #Los TOKEN SIEMPRE MAYÚSCULAS
    #por ejemplo:
    #%token IF
    #%token <cadena> ID*/
    %union{
        int itype;
        double dtype;
        float ftype;
        char* stype;
        char ctype;
    }


    %token <stype> TK_LITERAL_CADENA
    %token <ctype> TK_LITERAL_CARACTER
    %token <itype> TK_LITERAL_ENTERO
    %token <ftype> TK_LITERAL_REAL

    %token TK_ACCION
    %token TK_ALGORITMO
    %token TK_BOOLEANO
    %token TK_CADENA
    %token TK_CARACTER
    %token TK_CONST
    %token TK_CONTINUAR
    %token TK_DE 
    %token TK_DEV
    %token TK_DIV
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
    %token TK_MOD
    %token TK_NO 
    %token TK_O 
    %token TK_PARA 
    %token TK_REAL
    %token TK_REF
    %token TK_SAL 
    %token TK_SI 
    %token TK_TABLA
    %token TK_TIPO 
    %token TK_TUPLA 
    %token TK_VAR 
    %token TK_VERDADERO
    %token TK_Y
    
    %token TK_ASIGNACION
    %token TK_COMPOSICION_SECUENCIAL
    %token TK_SEPARADOR
    %token TK_SUBRANGO
    %token TK_DEF_TIPO
    %token TK_ENTONCES
    %token TK_SI_NO_SI
    %token TK_CREACION_TIPO
    %token TK_INICIO_ARRAY
    %token TK_FIN_ARRAY
    %token TK_IGUAL_QUE
    %token TK_MAYOR_QUE
    %token TK_MENOR_QUE
    %token TK_DISTINTO_QUE
    %token TK_MAYOR_O_IGUAL
    %token TK_MENOR_O_IGUAL

%%
    /* Reglas de la gramatica */

    descripcion_algoritmo: TK_ALGORITMO TK_IDENTIFICADOR TK_COMPOSICION_SECUENCIAL cabecera_algoritmo bloque_algoritmo TK_FALGORITMO;
    cabecera_algoritmo: definiciones_globales definiciones_acciones_funciones definiciones_variables_interaccion TK_COMENTARIO;
    bloque_algoritmo: bloque TK_COMENTARIO;
    definiciones_globales:  definicion_tipo definiciones_globales
                            | definicion_const definiciones_globales
                            | /* vacio */
                            ;
    definiciones_acciones_funciones:    (definicion_accion | definicion_funcion) definiciones_acciones_funciones
                                        | /* vacio */
                                        ;
    bloque: declaraciones instrucciones;
    declaraciones:  (definicion_tipo | definicion_const | definicion_var) declaraciones
                    | /* vacio */
                    ;

    /* DEFINICIONES */
    definicion_tipo: TK_TIPO lista_definiciones_tipo TK_FTIPO;
    definicion_const: TK_CONST lista_definiciones_const TK_FCONST;
    definicion_var: TK_VAR lista_definiciones_var TK_FVAR;

    /* DEFINICIONES DE TIPOS */
    lista_definiciones_tipo:    TK_IDENTIFICADOR TK_CREACION_TIPO definicion_tipo TK_COMPOSICION_SECUENCIAL lista_definiciones_tipo
                                | /* vacio */
                                ;
    definicion_tipo:    TK_TUPLA lista_campos TK_FTUPLA
                        | TK_TABLA TK_INICIO_ARRAY expresionT TK_SUBRANGO expresionT TK_FIN_ARRAY TK_DE definicion_tipo
                        | TK_IDENTIFICADOR
                        | expresionT TK_SUBRANGO expresionT
                        | TK_REF definicion_tipo
                        | TK_TIPO_BASE /*WTF*/
                        ;
    expresionT: TK_LITERAL_ENTERO 
                | TK_LITERAL_CARACTER
                ;
    lista_campos:   TK_IDENTIFICADOR TK_DEF_TIPO definicion_tipo TK_COMPOSICION_SECUENCIAL lista_campos
                    | /* vacio */
                    ;

    /* DECLARACION DE CONSTANTES Y VARIABLES */
    lista_definiciones_const:   TK_IDENTIFICADOR TK_ASIGNACION TK_LITERAL_CADENA TK_COMPOSICION_SECUENCIAL lista_definiciones_const
                                | TK_IDENTIFICADOR TK_ASIGNACION TK_LITERAL_CARACTER TK_COMPOSICION_SECUENCIAL lista_definiciones_const
                                | TK_IDENTIFICADOR TK_ASIGNACION TK_LITERAL_ENTERO TK_COMPOSICION_SECUENCIAL lista_definiciones_const
                                | TK_IDENTIFICADOR TK_ASIGNACION TK_LITERAL_REAL TK_COMPOSICION_SECUENCIAL lista_definiciones_const
                                | /* vacio */
                                ;
    lista_definiciones_var:     lista_id TK_DEF_TIPO definicion_tipo TK_COMPOSICION_SECUENCIAL lista_definiciones_var
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

%%
    /* Código C */