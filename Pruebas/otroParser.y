/**
 * @file
 * 	\brief Este fichero es la implementación de un parser en bison. 
 * Puedes compilarlo con la utilidad bison. Usa la opción -d para generar
 * la cabecera parser.tab.h que flex necesita
 * @author Silvia Popa y Víctor Ruiz Gómez
 */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yyerror(char *s);
    int yylex(void);
    int yyparse(void);
    extern FILE * yyin;

%}

/* Asociamos identificadores de tokens de bison a campos de yystype */
%token T_literal_entero
%token T_literal_real
%token T_literal_booleano
%token T_literal_caracter
%token T_literal_string

%token T_id

%token T_asignacion
%token T_comp_secuencial
%token T_separador
%token T_subrango
%token T_def_tipo_variable
%token T_entonces
%token T_si_no_si
%token T_creacion_tipo
%token T_inic_array
%token T_fin_array

%token T_suma

%token T_resta
%token T_div
%token T_mult
%token T_mod
%token T_inic_parentesis
%token T_fin_parentesis
%token T_oprel
%token T_referencia

%token T_accion
%token T_ref
%token T_de
%token T_algoritmo
%token T_const
%token T_continuar
%token T_dev 
%token T_ent
%token T_es
%token T_faccion 
%token T_falgoritmo
%token T_fconst
%token T_ffuncion
%token T_fmientras
%token T_fpara
%token T_fsi
%token T_ftipo
%token T_ftupla 
%token T_funcion 
%token T_fvar
%token T_hacer
%token T_hasta
%token T_mientras
%token T_no
%token T_o
%token T_para 
%token T_sal
%token T_si
%token T_tabla
%token T_tipo
%token T_tupla
%token T_var
%token T_y
%token T_div_entera
%token T_comentario

%token T_tipo_base

/* Asociamos no terminales a campos de la unión */

/* Indicamos la asociatividad y prioridad de los operadores */

// Asociatividad en op. de referencia 
%left T_referencia
%left T_inic_array
%left T_ref

// Prioridad en op. booleanos
%left T_y
%left T_o
%left T_no

// Prioridad en op. aritméticos. 
%left T_suma T_resta
%left T_mult T_div T_div_entera
%left T_mod


%%
	/* Zona de declaración de producciones de la gramática */
axioma:
	desc_algoritmo;
desc_algoritmo:
	T_algoritmo T_id cabecera_alg bloque_alg T_falgoritmo;
cabecera_alg:
	decl_globales decl_a_f decl_ent_sal T_comentario;
bloque_alg:
	bloque T_comentario;

decl_globales:
	decl_globales declaracion_tipo
	|decl_globales declaracion_cte
	| /*vacío */
    ;

decl_a_f:
	decl_a_f accion_d
	|decl_a_f funcion_d
	| /*vacío */
    ;

bloque:
	declaraciones instrucciones;
	
declaraciones:
	declaraciones declaracion_tipo
	| declaraciones declaracion_cte
	| declaraciones declaracion_var
	| /*vacío */
    ;
	
	
/* Declaraciones para expresiones */
expresion: 
	exp_a  
	| exp_b
    ;
	
// Expresiones aritméticas
exp_a:
	exp_a T_suma exp_a 
    | exp_a T_resta exp_a 
	| exp_a T_mult exp_a 
	| exp_a T_div_entera exp_a 
	| exp_a T_div exp_a 
	| T_inic_parentesis exp_a T_fin_parentesis
	| T_literal_entero
    | T_literal_real 
    | T_resta exp_a 
    | exp_a T_mod exp_a 
    ;

//Expresiones booleanas
exp_b:
	exp_b T_y exp_b 
    | exp_b T_o exp_b 
    | T_no exp_b 
    | T_literal_booleano 
    | exp_b T_oprel exp_b 
    | T_inic_parentesis exp_b T_fin_parentesis
    ;
	
operando:
	T_id
	| operando T_referencia operando 
	| operando T_inic_array expresion T_fin_array 
	| operando T_ref
	| funcion_ll
    ;

/* Declaración para instrucciones */
instrucciones:
	instrucciones T_comp_secuencial instruccion 
	| instruccion 
	| instrucciones T_comp_secuencial error 
	| error 
    ;

instruccion:
	asignacion
	| alternativa
	| iteracion
    | T_continuar
    | accion_ll
    ;

asignacion:
	operando T_asignacion expresion 
    | operando T_asignacion operando 
    ;
		
/* este no terminal representa una condición */
condicion:
	expresion 
	| operando 
    ;
	
alternativa:
	T_si condicion T_entonces instrucciones lista_opciones T_fsi 
	| T_si condicion T_entonces instrucciones T_fsi 
    ;

lista_opciones:
	T_si_no_si condicion T_entonces instrucciones lista_opciones 
	| T_si_no_si condicion T_entonces instrucciones 
    ;
iteracion:
	it_cota_fija
	| it_cota_exp
    ;

it_cota_exp:
	T_mientras expresion T_hacer instrucciones T_fmientras;
	
expresion_f:
	expresion 
	| operando
    ;
	
it_cota_fija_c:
	T_para T_id T_asignacion expresion_f T_hasta expresion_f T_hacer;
it_cota_fija:
	it_cota_fija_c instrucciones T_fpara;

/* Declaraciones */
declaracion_tipo:
	T_tipo lista_de_tipo T_ftipo T_comp_secuencial;
declaracion_cte:
	T_const lista_de_cte T_fconst T_comp_secuencial;
declaracion_var:
	T_var lista_de_var T_fvar T_comp_secuencial;

/* Declaraciones de tipos */	
lista_de_tipo:
	T_id T_creacion_tipo d_tipo T_comp_secuencial lista_de_tipo ;

d_tipo:
	T_id
	| dd_tipo
    ;

dd_tipo:
	T_tupla lista_campos T_ftupla
    |T_subrango expresion_t T_fin_array T_de d_tipo 
	|  expresion_t T_subrango expresion_t
	| T_ref d_tipo 
	| T_tipo_base
    ;

expresion_t:
	expresion 
	| T_literal_caracter
    ;
lista_campos:
	T_id T_def_tipo_variable d_tipo T_comp_secuencial lista_campos
	| /*vacio*/
    ;


/* Declaración de constantes y variables */
lista_de_cte:
	T_id T_creacion_tipo constante T_comp_secuencial lista_de_cte 
    | /*vacio*/
    ;

constante:
	literal 
	| T_literal_booleano
    ;
literal:
	T_literal_entero
	| T_literal_real
	| T_literal_caracter
	| T_literal_string
    ;

lista_de_var:
	lista_id T_def_tipo_variable T_id T_comp_secuencial lista_de_var
    | lista_id T_def_tipo_variable dd_tipo T_comp_secuencial lista_de_var 
    | /*vacio */
    ;
lista_id:
	T_id T_separador lista_id
	| T_id
    ;

decl_ent_sal: 
	decl_ent
	| decl_ent decl_sal 
	| decl_sal 
	| /*vacio*/
    ;
decl_ent: 
	T_ent lista_de_var;
decl_sal:
	T_sal lista_de_var;


/* Acciones y funciones */
accion_d:
	T_accion a_cabecera bloque T_faccion;

funcion_d:
	T_funcion f_cabecera bloque T_dev expresion T_ffuncion;

a_cabecera:
	T_id T_inic_parentesis d_par_form T_fin_parentesis T_comp_secuencial; 

f_cabecera:
	T_id T_inic_parentesis lista_de_var T_fin_parentesis T_dev d_tipo T_comp_secuencial;

d_par_form:
	d_p_form T_comp_secuencial d_par_form
	| d_p_form 
	| /*vacio*/
    ;
d_p_form:
	T_ent lista_id T_def_tipo_variable d_tipo
	| T_sal lista_id T_def_tipo_variable d_tipo
	| T_es lista_id T_def_tipo_variable d_tipo
    ;

accion_ll:
	T_id T_inic_parentesis l_ll T_fin_parentesis;
	
funcion_ll:
	T_id T_inic_parentesis l_ll T_fin_parentesis;

l_ll:
	expresion T_separador expresion
	| expresion
	| /*vacio*/
    ;

%%
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
    yydebug = 1;
    yyparse();


}
