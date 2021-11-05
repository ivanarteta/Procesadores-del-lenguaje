/*Seccion de definiciones*/
%{
	/*delimitador de código C */
	#include <stdio.h>
	#include <math.h>
	#include <stdlib.h>
	#include "tablaSimbolos.h"
	#include "tablaCuadruplas.h"
	#define NULO -99
	
	extern FILE *yyin;
	extern int yylex();
	extern int yyparse();
	
	void yyerror(char const *);
	
	//Creamos las estructuras 
	lista tabla_s;
	tC tc;
	


%}
%union YYSTYPE{
	char* sval;
	int ival;
	float fval;
	struct E{
		int place;
		int type;
	}E;
}

%token <ival>TK_LITERAL_ENTERO
%token <fval>TK_LITERAL_REAL
%token <sval>TK_LITERAL_BOOLEANO 

%token TK_ACCION
%token TK_ALGORITMO 
%token TK_CONST
%token TK_CONTINUAR
%token TK_DE
%token TK_DEV
%token TK_ENT
%token TK_FACCION
%token TK_FALGORITMO 
%token TK_FCONST 
%token TK_FFUNCION 
%token TK_MIENTRAS 
%token TK_FMIENTRAS
%token <ival>TK_ENTERO
%token TK_FPARA 
%token TK_FSI
%token TK_FTIPO
%token TK_FTUPLA 
%token TK_FUNCION
%token TK_FVAR 
%token TK_HACER
%token TK_HASTA 
%left TK_O 
%left TK_Y 
%nonassoc TK_NO 
%token TK_PARA 
%token <ival>TK_BOOLEANO
%token <ival>TK_REAL
%token <ival>TK_CADENA
%token <ival>TK_CARACTER
%right <ival>TK_REF 
%token TK_SAL
%token TK_SI 
%token TK_TABLA 
%token TK_TIPO
%token TK_TUPLA 
%token TK_VAR 
%token TK_LIT_CADENA
%token TK_COMENTARIO

%token TK_LITERAL_CARACTER 
%token <sval>TK_IDENTIFICADOR 

%left TK_SUMA TK_RESTA
%left TK_MULTI TK_DIVI TK_MOD TK_DIV

%nonassoc TK_COMPARADOR_MENOR
%nonassoc TK_COMPARADOR_MAYOR
%left TK_ABRIR_PARENTESIS 
%token TK_CERRAR_PARENTESIS
%token TK_ASIGNACION
%left TK_COMP_SEC
%token TK_SEPARADOR
%token <sval>TK_SUBRANGO
%token TK_DEF_VARIABLE
%token TK_CREACION_TIPO
%right TK_INICIO_ARRAY
%token TK_FIN_ARRAY
%right TK_ACCESO TK_ENTONCES
%left TK_DISTINTO TK_MAYOR_IGUAL TK_MENOR_IGUAL 
%token TK_ELSE


%type <ival> d_tipo
%type <ival> lista_id
%type <E> exp
%type <E> expresion
%type <E> asignacion
%type <E> operando


%%

/*Seccion de Reglas*/
desc_algoritmo:
	TK_ALGORITMO TK_IDENTIFICADOR TK_COMP_SEC cabecera_alg bloque_alg TK_FALGORITMO {printf("desc_algoritmo\n");}
	; 
cabecera_alg:
	decl_globales decl_a_f decl_ent_sal TK_COMENTARIO {printf("cabecera_alg\n");}
	;
bloque_alg:
	bloque TK_COMENTARIO {printf("bloque_alg\n");}
	;
decl_globales:
	declaracion_tipo decl_globales {printf("decl_globales\n");}
	| declaracion_cte decl_globales {printf("decl_globales\n");}
	| /* vacio */ {printf("decl_globales\n");}
	;
decl_a_f:
	accion_d decl_a_f {printf("decl_a_f\n");}
	| funcion_d decl_a_f {printf("decl_a_f\n");}
	| /* vacio */ {printf("decl_a_f\n");}
	;
bloque:
	declaraciones instrucciones {printf("bloque\n");}
	;
declaraciones:
	declaracion_tipo declaraciones {printf("declaraciones\n");}
	| declaracion_cte declaraciones {printf("declaraciones\n");}
	| declaracion_var declaraciones {printf("declaraciones\n");}
	|/* vacio */ {printf("declaraciones\n");}
	;


/*Declaraciones*/	
declaracion_tipo:
	TK_TIPO lista_d_tipo TK_FTIPO {printf("declaracion_tipo\n");}
	;
declaracion_cte:
	TK_CONST lista_d_cte TK_FCONST {printf("declaracion_cte\n");}
	;
declaracion_var:
	TK_VAR lista_d_var TK_FVAR {printf("declaracion_var\n");}
	;

	
/*Declaración de tipos*/
lista_d_tipo:
	TK_IDENTIFICADOR TK_ASIGNACION d_tipo TK_COMP_SEC /*lista_d_tipo*/ {printf("lista_d_tipo\n");} 
	| /* vacio */ {printf("lista_d_tipo\n");}
	;
d_tipo:
	TK_TUPLA lista_campos TK_FTUPLA {printf("d_tipo\n");}
	| TK_TABLA TK_INICIO_ARRAY expresion_t TK_SUBRANGO expresion_t TK_FIN_ARRAY TK_DE d_tipo {printf("d_tipo\n");}
	| TK_IDENTIFICADOR {printf("TK_IDENTIFICADOR");}
	| expresion_t TK_SUBRANGO expresion_t {printf("d_tipo");}
	| TK_REF d_tipo {printf("TK_REF");}
	| TK_ENTERO {printf("d_tipo %d \n",TENTERO);
				$$ = TENTERO;}
	| TK_BOOLEANO {$$ = TBOOLEANO;}
	| TK_CARACTER {$$ = TCARACTER;}
	| TK_REAL {printf("d_tipo %d \n",TREAL);
				$$ = TREAL;}
	| TK_CADENA {$$ = TCADENA;}
	; 
expresion_t:
	expresion {printf("expresion_t0\n");}
	| TK_LITERAL_CARACTER {printf("expresion_t1\n");}
	;
lista_campos:
	TK_IDENTIFICADOR TK_DEF_VARIABLE d_tipo TK_COMP_SEC lista_campos {printf("lista_campos\n");}
	| /* vacio */ {printf("lista_campos\n");}
	;


/*decalaracion de contantes y variables*/
lista_d_cte: 
	TK_IDENTIFICADOR TK_CREACION_TIPO TK_LITERAL_CARACTER TK_COMP_SEC lista_d_cte {printf("lista_d_cte\n");}
	| TK_IDENTIFICADOR TK_CREACION_TIPO TK_LITERAL_ENTERO TK_COMP_SEC lista_d_cte {printf("lista_d_cte\n");}
	| TK_IDENTIFICADOR TK_CREACION_TIPO TK_LITERAL_REAL TK_COMP_SEC lista_d_cte {printf("lista_d_cte\n");}
	| TK_IDENTIFICADOR TK_CREACION_TIPO TK_LITERAL_BOOLEANO TK_COMP_SEC lista_d_cte {printf("lista_d_cte\n");}
	| TK_IDENTIFICADOR TK_CREACION_TIPO TK_LIT_CADENA TK_COMP_SEC lista_d_cte {printf("lista_d_cte\n");}
	| /* vacio */ {printf("lista_d_cte\n");}
	;

lista_d_var: lista_id TK_COMP_SEC lista_d_var {printf("lista_d_var 1\n");}
	| /* vacio */ {printf("lista_d_var 2\n");}
	;
	
lista_id:
	TK_IDENTIFICADOR TK_SEPARADOR lista_id {printf("lista_id0\n");
											if (((celda*)buscarT(tabla_s,$1)) == NULL){
												modifica_tipo_TS(&tabla_s,newTemp(&tabla_s,$1),$3);
												$$ = $3;
											}else{
												printf("Error lista id");
											}
	}
	| TK_IDENTIFICADOR TK_DEF_VARIABLE d_tipo {printf("lista_id1\n");
											if (((celda*)buscarT(tabla_s,$1)) == NULL){
												modifica_tipo_TS(&tabla_s,newTemp(&tabla_s,$1),$3);
												$$ = $3;
											}else{
												printf("Error lista id");
											}}
	;
decl_ent_sal:
	decl_ent {printf("decl_ent_sal\n");}
	| decl_ent decl_sal {printf("decl_ent_sal\n");}
	| decl_sal {printf("decl_ent_sal\n");}
	;
decl_ent:
	TK_ENT lista_d_var {printf("decl_ent\n");}
	;
decl_sal:
	TK_SAL lista_d_var {printf("decl_sal\n");}
	;


/*epresiones*/
expresion:
	exp {printf("expresion0\n");
				$$.place = $1.place;
                $$.type = $1.type;
	}
	| funcion_ll {printf("expresion1\n");}
	;
exp:
	exp TK_SUMA exp {printf("expsum\n");
					int T = newTemp(&tabla_s,NULL);
					$$.place = T;
					if($1.type == TENTERO && $3.type == TENTERO){
						modifica_tipo_TS(&tabla_s,T, TENTERO);
						gen(OP_SUMA_E,$1.place,$3.place,$$.place,&tc);
						$$.type = TENTERO;
					}else if($1.type == TENTERO && $3.type == TREAL){
						modifica_tipo_TS(&tabla_s,T, TREAL);
						gen(OP_SUMA_R,$1.place,$3.place,$$.place,&tc);
						$$.type = TREAL;
					}else if($1.type == TREAL && $3.type == TENTERO){
						modifica_tipo_TS(&tabla_s,T, TREAL);
						gen(OP_SUMA_R,$1.place,$3.place,$$.place,&tc);
						$$.type = TREAL;
					}else if($1.type == TREAL && $3.type == TREAL){
						modifica_tipo_TS(&tabla_s,T, TREAL);
						gen(OP_SUMA_R,$1.place,$3.place,$$.place,&tc);
						$$.type = TREAL;
					}
	}
	| exp TK_RESTA exp {printf("expresta\n");
						int T = newTemp(&tabla_s,NULL);
						$$.place = T;
						if($1.type == TENTERO && $3.type == TENTERO){
							modifica_tipo_TS(&tabla_s,T, TENTERO);
							gen(OP_RESTA_E,$1.place,$3.place,$$.place,&tc);
							$$.type = TENTERO;
						}else if($1.type == TENTERO && $3.type == TREAL){
							modifica_tipo_TS(&tabla_s,T, TREAL);
							gen(OP_RESTA_R,$1.place,$3.place,$$.place,&tc);
							$$.type = TREAL;
						}else if($1.type == TREAL && $3.type == TENTERO){
							modifica_tipo_TS(&tabla_s,T, TREAL);
							gen(OP_RESTA_R,$1.place,$3.place,$$.place,&tc);
							$$.type = TREAL;
						}else if($1.type == TREAL && $3.type == TREAL){
							modifica_tipo_TS(&tabla_s,T, TREAL);
							gen(OP_RESTA_R,$1.place,$3.place,$$.place,&tc);
							$$.type = TREAL;
						}
	}
	| exp TK_MULTI exp {printf("expmulti\n");
						int T = newTemp(&tabla_s,NULL);
						$$.place = T;
						if($1.type == TENTERO && $3.type == TENTERO){
							modifica_tipo_TS(&tabla_s,T, TENTERO);
							gen(OP_MULTI_E,$1.place,$3.place,$$.place,&tc);
							$$.type = TENTERO;
						}else if($1.type == TENTERO && $3.type == TREAL){
							modifica_tipo_TS(&tabla_s,T, TREAL);
							gen(OP_MULTI_R,$1.place,$3.place,$$.place,&tc);
							$$.type = TREAL;
						}else if($1.type == TREAL && $3.type == TENTERO){
							modifica_tipo_TS(&tabla_s,T, TREAL);
							gen(OP_MULTI_R,$1.place,$3.place,$$.place,&tc);
							$$.type = TREAL;
						}else if($1.type == TREAL && $3.type == TREAL){
							modifica_tipo_TS(&tabla_s,T, TREAL);
							gen(OP_MULTI_R,$1.place,$3.place,$$.place,&tc);
							$$.type = TREAL;
						}
	}
	| exp TK_DIVI exp {printf("expdivi\n");
						int T = newTemp(&tabla_s,NULL);
						$$.place = T;
						if($1.type == TENTERO && $3.type == TREAL){
							modifica_tipo_TS(&tabla_s,T, TREAL);
							gen(OP_DIV_R,$1.place,$3.place,$$.place,&tc);
							$$.type = TREAL;
						}else if($1.type == TREAL && $3.type == TENTERO){
							modifica_tipo_TS(&tabla_s,T, TREAL);
							gen(OP_DIV_R,$1.place,$3.place,$$.place,&tc);
							$$.type = TREAL;
						}else if($1.type == TREAL && $3.type == TREAL){
							modifica_tipo_TS(&tabla_s,T, TREAL);
							gen(OP_DIV_R,$1.place,$3.place,$$.place,&tc);
							$$.type = TREAL;
						}
	}
	| exp TK_MOD exp {printf("expmod\n");
						int T = newTemp(&tabla_s,NULL);
						$$.place = T;
						if($1.type == TENTERO && $3.type == TENTERO){
							modifica_tipo_TS(&tabla_s,T, TENTERO);
							gen(OP_MOD,$1.place,$3.place,$$.place,&tc);
							$$.type = TENTERO;
						}
	}
	| exp TK_DIV exp {printf("expdiv\n");
						int T = newTemp(&tabla_s,NULL);
						$$.place = T;
						if($1.type == TENTERO && $3.type == TENTERO){
							modifica_tipo_TS(&tabla_s,T, TENTERO);
							gen(OP_DIV_E,$1.place,$3.place,$$.place,&tc);
							$$.type = TENTERO;
						}
	}
	| TK_ABRIR_PARENTESIS exp TK_CERRAR_PARENTESIS {printf("expparen\n");
													$$.place = $2.place;
													$$.type = $2.type;
	}
	| operando {printf("expoper\n");}
	| TK_LITERAL_ENTERO {printf("explitent\n");
						int T = newTemp(&tabla_s,NULL);
						modifica_tipo_TS(&tabla_s,T,TENTERO);
						$$.place = T;
						$$.type = TENTERO;
	}
	| TK_LITERAL_REAL {printf("explitreal\n");
						int T = newTemp(&tabla_s,NULL);
						modifica_tipo_TS(&tabla_s,T,TREAL);
						$$.place = T;
						$$.type = TREAL;
	}
	| TK_RESTA exp {printf("expneg\n");
					modifica_tipo_TS(&tabla_s,$$.place, $2.type);
					$$.place = newTemp(&tabla_s,NULL);
					if($2.type == TENTERO){
						gen(OP_RESTA_E,NULO,$2.place,$$.place,&tc); 
					}else if($2.type == TREAL){
						gen(OP_RESTA_R,NULO,$2.place,$$.place,&tc);
					}
	}
	| exp TK_Y exp {printf("expy\n");}
	| exp TK_O exp {printf("expo\n");}
	| TK_NO exp {printf("expno\n");}
	| TK_BOOLEANO {printf("expbool\n");}
	| expresion TK_COMPARADOR_MENOR expresion {printf("expcompmen\n");}
	| expresion TK_COMPARADOR_MAYOR expresion {printf("expcompma\n");}
	| expresion TK_ASIGNACION expresion {printf("expasig\n");}
	| expresion TK_DISTINTO expresion {printf("expdist\n");}
	| expresion TK_MAYOR_IGUAL expresion {printf("expmayig\n");}
	| expresion TK_MENOR_IGUAL expresion {printf("expmenig\n");}
	;
operando:
	TK_IDENTIFICADOR {printf("operando\n");
		celda* aux = ((celda*)buscarT(tabla_s,$1));
        $$.place = aux->id;
        $$.type = aux->type;
	}
	| operando TK_ACCESO operando {printf("operando\n");} 
	| operando TK_INICIO_ARRAY expresion TK_FIN_ARRAY {printf("operando\n");}
	| operando TK_REF {printf("operando\n");}
	;
instrucciones:
	instruccion TK_COMP_SEC instrucciones {printf("instrucciones\n");}
	| instruccion {printf("instrucciones\n");}
	;
instruccion:
	TK_CONTINUAR {printf("instruccion\n");}
	| asignacion {printf("instruccion\n");}
	| alternativa {printf("instruccion\n");}
	| iteracion {printf("instruccion\n");}
	| accion_ll {printf("instruccion\n");}
	;
asignacion:
	operando TK_ASIGNACION expresion {printf("asignacion\n");
	if ($1.type == $3.type){
		printf("Normal");
		gen(OP_ASIGNACION,$3.place,NULO,$1.place, &tc);
		$$.type = $1.type;
	}else if ($1.type == TREAL && $3.type == TENTERO){
		printf("Intoreal");
		gen(OP_INTTOREAL,$3.place,NULO,$3.place, &tc);
		gen(OP_ASIGNACION,$3.place,NULO,$1.place, &tc);
		$$.type = TREAL;
	}else{
		printf("Error en asignación\n");
		printf("tipo1 %d \n",$1.type);
		printf("tipo 3 %d\n",$3.type);
	}}
	;
alternativa:
	TK_SI expresion TK_ENTONCES instrucciones lista_opciones TK_FSI {printf("alternativa\n");}
	;
lista_opciones:
	TK_ELSE expresion TK_ENTONCES instrucciones lista_opciones {printf("lista_opciones\n");}
	| /* vacio */ {printf("lista_opciones\n");}
	;
iteracion:
	it_cota_fija {printf("iteracion\n");}
	| it_cota_exp {printf("iteracion\n");}
	;
it_cota_exp:
	TK_MIENTRAS expresion TK_HACER instrucciones TK_FMIENTRAS TK_COMP_SEC {printf("it_cota_exp\n");}
	;
it_cota_fija:
	TK_PARA TK_IDENTIFICADOR TK_ASIGNACION expresion TK_HASTA  expresion TK_HACER instrucciones TK_FPARA {printf("it_cota_fija\n");}
	;
accion_d:
	TK_ACCION a_cabecera bloque TK_FACCION {printf("accion_d\n");}
	;
funcion_d:
	TK_FUNCION f_cabecera bloque TK_DEV expresion TK_FFUNCION {printf("funcion_d\n");}
	;
a_cabecera:
	TK_IDENTIFICADOR TK_ABRIR_PARENTESIS d_par_form TK_CERRAR_PARENTESIS TK_COMP_SEC {printf("a_cabecera\n");}
	;
f_cabecera:
	TK_IDENTIFICADOR TK_ABRIR_PARENTESIS lista_d_var TK_CERRAR_PARENTESIS TK_DEV d_tipo TK_COMP_SEC {printf("f_cabecera\n");}
	;
d_par_form:
	d_p_form TK_COMP_SEC d_par_form {printf("d_par_form\n");}
	| /* vacio */ {printf("d_par_form\n");}
	;
d_p_form:
	TK_ENT lista_id TK_DEF_VARIABLE d_tipo {printf("d_p_form\n");}
	| TK_SAL lista_id TK_DEF_VARIABLE d_tipo {printf("d_p_form\n");}
	| TK_ENT TK_SAL lista_id TK_DEF_VARIABLE d_tipo {printf("d_p_form\n");}
	;
accion_ll:
	TK_IDENTIFICADOR TK_ABRIR_PARENTESIS l_ll TK_CERRAR_PARENTESIS {printf("accion_ll\n");}
	;
funcion_ll:
	TK_IDENTIFICADOR TK_ABRIR_PARENTESIS l_ll TK_CERRAR_PARENTESIS {printf("funcion_ll\n");}
	;
l_ll:
	expresion TK_SEPARADOR l_ll {printf("l_ll\n");}
	| expresion {printf("l_ll\n");}
	;


%%

/*Seccion de funciones de usuario*/

int main (int argc,char **argv){
	++argv, --argc; /*saltamos el nombre del programa*/
	if(argc > 0)
		yyin = fopen(argv[0], "r");
	else
		yyin = stdin;
		
	yyparse();
	imprimirTablaSimbolos(tabla_s);
	imprimirTablaCuadruplas(tc);
}
void yyerror(const char *s){
	exit(-1);
}
