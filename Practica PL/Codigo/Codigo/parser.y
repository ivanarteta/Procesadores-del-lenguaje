%{  
    #include "eaux.h"
    #include "ts.h"
    #include "tc.h"
    #include <stdio.h>
    #include <ctype.h>
    #include <string.h>
    
    
    extern FILE* yyin;
    int yylex (void);
    int yyerror (char *s);
    struct FILA_TS* cabeza_TS;
    struct FILA_TS* cola_TS;
    struct FILA_TS* fila;
    struct TC tabla_cuadruplas;
    
    int operador, *op1, *op2, *res, id, id2, errorFlag;
    
    
    
%}


%union {
    
    enum enum_tipo tipo;
    //int tipo;
    int val_int;
    double val_double;
    char val_char;
    char * val_string;
    struct {
        enum enum_tipo type;
        int place; // ID de la tabla de símbolos
        struct TRUE_FALSE TRUE;
        struct TRUE_FALSE FALSE;
        struct TRUE_FALSE NEXT;
    } e;
    enum enum_tipo lista; /* Sin incluir tipos del usuario. */
}

%token TK_entonces
%token TK_accion
%token TK_algoritmo
%token TK_booleano
%token TK_cadena
%token TK_caracter
%token TK_const
%token TK_continuar
%token TK_de
%token TK_dev
%token TK_ent
%token TK_entero
%token TK_entsal
%token TK_faccion
%token TK_falgoritmo
%token TK_fconst
%token TK_ffuncion
%token TK_fmientras
%token TK_fpara
%token TK_fsi
%token TK_ftipo
%token TK_ftupla
%token TK_funcion
%token TK_fvar
%token TK_hacer
%token TK_mientras
%token TK_para
%token TK_hasta
%token TK_real
%token TK_ref
%token TK_sal
%token TK_si
%token TK_tabla
%token TK_tipo
%token TK_tupla
%token TK_var
%token TK_comentario_pre
%token TK_comentario_post
%token TK_asignacion
%left TK_composicion_secuencial
%token TK_separador
%token TK_subrango
%token TK_definicion
%token TK_si_no_si
%token TK_inicio_array
%token TK_fin_array
%token TK_inicio_parentesis
%token <val_int> TK_literal_entero
%token <val_char> TK_literal_caracter
%token <val_string> TK_literal_cadena
%token <val_double> TK_literal_real
%token <val_int> TK_literal_booleano
%token <val_string> TK_identificador
%left TK_o
%left TK_y
%left <val_string> TK_comparador
%left TK_igual
%left TK_no
%left TK_op_suma
%left TK_op_resta
%left TK_op_division
%left TK_div
%left TK_op_multiplicador
%left TK_mod
%left TK_fin_parentesis

%type <e> expresion
%type <e> exp_a
%type <e> operando
%type <e> instruccion
%type <e> instrucciones
%type <e> asignacion
%type <lista> lista_id_var_o_no
%type <lista> lista_id_var
%type <lista> lista_id_ent_o_no
%type <lista> lista_id_ent
%type <lista> lista_id_sal_o_no
%type <lista> lista_id_sal
%type <tipo> d_tipo
%type <val_int> M

%%
desc_algoritmo      :   TK_algoritmo TK_identificador TK_composicion_secuencial cabecera_alg bloque_alg TK_falgoritmo {printf("\tPARSER: desc_algoritmo\n");}
                    ;
cabecera_alg        :   decl_globales decl_a_f decl_ent_sal TK_comentario_pre {printf("\tPARSER: cabecera_alg\n");}
                    ;
bloque_alg          :   bloque TK_comentario_post {printf("\tPARSER: bloque_alg\n");}
                    ;
decl_globales       :   declaracion_tipo decl_globales  {printf("\tPARSER: decl_globales->tipo\n");} 
                    |   declaracion_cte decl_globales {printf("\tPARSER: decl_globales->const\n");}
                    |   /* empty */  {printf("\tPARSER: decl_globales->epsilon\n");}
                    ;                    
decl_a_f            :   accion_d decl_a_f | funcion_d decl_a_f {printf("\tPARSER: decl_a_f\n");}
                    |   /* empty */  {printf("\tPARSER: decl_a_f->epsilon\n");}
                    ;
bloque              :   declaraciones instrucciones {printf("\tPARSER: bloque\n");}
                    ;
declaraciones       :   declaracion_tipo declaraciones  {printf("\tPARSER: declaraciones->tipo\n");} 
                    |   declaracion_cte declaraciones {printf("\tPARSER: declaraciones->const\n");} 
                    |   declaracion_var declaraciones   {printf("\tPARSER: declaraciones->var\n");} 
                    |   /* empty */ {printf("\tPARSER: declaraciones->epsilon\n");}
                    ;
declaracion_tipo    :   TK_tipo lista_d_tipo TK_ftipo {printf("\tPARSER: declaracion_tipo\n");}
                    ;
declaracion_cte     :   TK_const lista_d_cte TK_fconst {printf("\tPARSER: declaracion_cte\n");}
                    ;
declaracion_var     :   TK_var lista_d_var TK_fvar {printf("\tPARSER: declaracion_var\n");}
                    ;
lista_d_tipo        :   TK_identificador TK_igual d_tipo  TK_composicion_secuencial lista_d_tipo
                    |   /* empty */ {printf("\tPARSER: lista_d_tipo->epsilon\n");}
                    ;
d_tipo              :   TK_tupla lista_campos TK_ftupla {printf("\tPARSER: d_tipo->tupla\n");}
                    |   TK_tabla TK_inicio_array expresion_t TK_subrango expresion_t TK_fin_array TK_de d_tipo {printf("\tPARSER: d_tipo->tabla\n");}
                    |   TK_identificador {printf("\tPARSER: d_tipo->identificador\n");}
                    |   expresion_t TK_subrango expresion_t {printf("\tPARSER: d_tipo->subrango\n");}
                    |   TK_ref d_tipo {printf("\tPARSER: d_tipo->ref\n");}
                    |   TK_entero {printf("\tPARSER: d_tipo->entero\n"); $$ = TIPO_ENTERO;}
                    |   TK_booleano {printf("\tPARSER: d_tipo->booleano\n"); $$ = TIPO_BOOLEANO;}
                    |   TK_real {printf("\tPARSER: d_tipo->real\n"); $$ = TIPO_REAL;}
                    |   TK_caracter {printf("\tPARSER: d_tipo->caracter\n"); $$ = TIPO_CARACTER;}
                    |   TK_cadena {printf("\tPARSER: d_tipo->cadena\n"); $$ = TIPO_CADENA;}
                    ;
expresion_t         :   expresion {printf("\tPARSER: expresion\n");}
                    |   TK_literal_caracter {printf("\tPARSER: literal_caracter\n");}
                    ;
lista_campos        :   TK_identificador TK_definicion d_tipo TK_composicion_secuencial lista_campos {printf("\tPARSER: lista_campos (estructura)\n");}
                    |   /* empty */ {printf("\tPARSER: lista_campos->epsilon\n");}
                    ;
lista_d_cte         :   TK_identificador TK_igual TK_literal_cadena TK_composicion_secuencial lista_d_cte {printf("\tPARSER: lista_d_cte->cadena: %s=%s\n", $1, $3);}
                    |   TK_identificador TK_igual TK_literal_caracter TK_composicion_secuencial lista_d_cte {printf("\tPARSER: lista_d_cte->caracter: %s=%c\n", $1, $3);}
                    |   TK_identificador TK_igual TK_literal_entero TK_composicion_secuencial lista_d_cte {printf("\tPARSER: lista_d_cte->entero: %s=%d\n", $1, $3);}
                    |   TK_identificador TK_igual TK_literal_real TK_composicion_secuencial lista_d_cte {printf("\tPARSER: lista_d_cte->real: %s=%f\n", $1, $3);}
                    |   TK_identificador TK_igual TK_literal_booleano TK_composicion_secuencial lista_d_cte {printf("\tPARSER: lista_d_cte->booleano: %s=%d\n", $1, $3);}
                    |   /* empty */ {printf("\tPARSER: lista_d_cte->epsilon\n");}
                    ;
lista_d_var         :   lista_id_var TK_composicion_secuencial lista_d_var {printf("\tPARSER: lista_d_var->tipo estandar\n");}
                    /*|   lista_id_var TK_composicion_secuencial lista_d_var {printf("\tPARSER: lista_d_var->tipo usuario\n");} /* TODO para tipos definidos por el usuario ya no podemos usar un entero como equivalente al tipo porque no se sabe con antelación */
                    |   /* empty */ {printf("\tPARSER: lista_d_var->epsilon\n");}
                    ;
lista_id            :   TK_identificador TK_separador lista_id {printf("\tPARSER: lista_id->mas de uno\n");}
                    |   TK_identificador {printf("\tPARSER: lista_id->ultimo\n");}
                    ;
                    
                    
lista_id_var_o_no   :   TK_identificador TK_definicion d_tipo
                            {
                                printf("\tPARSER: lista_id_var2->linea entera\n"); 
                                $$=$3; 
                                insertar_id_TS($1, $3, &cola_TS);
                            } /* Al empezar por la derecha, se almacena en lista_id_var el tipo "d_tipo", el cual se podrá usar en la siguiente producción */
                    |   TK_identificador TK_separador lista_id_var {printf("\tPARSER: lista_id_var2->mas de uno\n"); $$=$3; insertar_id_TS($1, $3, &cola_TS);}
                    |   /* empty */ {printf("\tPARSER: ultima lista_id_var\n");}
                    ;
lista_id_var        :   TK_identificador TK_definicion d_tipo {printf("\tPARSER: lista_id_var->linea entera\n");$$=$3; insertar_id_TS($1, $3, &cola_TS);}/* Al empezar por la derecha, se almacena en lista_id_var el tipo "d_tipo", el cual se podrá usar en la siguiente producción */
                    |   TK_identificador TK_separador lista_id_var_o_no {printf("\tPARSER: lista_id_var->mas de uno\n"); insertar_id_TS($1, $3, &cola_TS);}
                    ;
                    
                    
lista_id_ent_o_no   :   TK_identificador TK_definicion d_tipo
                            {
                                printf("\tPARSER: lista_id_ent->linea entera\n"); 
                                $$=$3;
                                fila = insertar_id_TS($1, $3, &cola_TS);
                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INPUT, &(fila->id), NULL, NULL);
                            }
                    |   TK_identificador TK_separador lista_id_ent
                            {
                                printf("\tPARSER: lista_id_ent2->mas de uno\n");
                                $$=$3;
                                fila = insertar_id_TS($1, $3, &cola_TS);
                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INPUT, &(fila->id), NULL, NULL);
                            }
                    |   /* empty */ {printf("\tPARSER: ultima lista_id_ent2\n");}
                    ;
lista_id_ent        :   TK_identificador TK_definicion d_tipo
                            {
                                printf("\tPARSER: lista_id_ent->linea entera\n");
                                $$=$3;
                                fila = insertar_id_TS($1, $3, &cola_TS);
                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INPUT, &(fila->id), NULL, NULL);
                            }
                    |   TK_identificador TK_separador lista_id_ent_o_no
                            {
                                printf("\tPARSER: lista_id_ent->mas de uno\n");
                                fila = insertar_id_TS($1, $3, &cola_TS);
                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INPUT, &(fila->id), NULL, NULL);
                            }
                    ;
                    
lista_id_sal_o_no   :   TK_identificador TK_definicion d_tipo
                            {
                                printf("\tPARSER: lista_id_sal->linea entera\n"); 
                                $$=$3;
                                id = TS_consultar_id($1, cabeza_TS);
                                if (id == -1) {
                                    fila = insertar_id_TS($1, $3, &cola_TS);
                                    id = fila->id;
                                }
                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_OUTPUT, &id, NULL, NULL);
                            }
                    |   TK_identificador TK_separador lista_id_sal
                            {
                                printf("\tPARSER: lista_id_sal2->mas de uno\n");
                                $$=$3;
                                id = TS_consultar_id($1, cabeza_TS);
                                if (id == -1) {
                                    fila = insertar_id_TS($1, $3, &cola_TS);
                                    id = fila->id;
                                }
                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_OUTPUT, &id, NULL, NULL);
                            }
                    |   /* empty */ {printf("\tPARSER: ultima lista_id_sal2\n");}
                    ;
lista_id_sal        :   TK_identificador TK_definicion d_tipo
                            {
                                printf("\tPARSER: lista_id_sal->linea entera\n");
                                $$=$3;
                                id = TS_consultar_id($1, cabeza_TS);
                                if (id == -1) {
                                    fila = insertar_id_TS($1, $3, &cola_TS);
                                    id = fila->id;
                                }
                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_OUTPUT, &id, NULL, NULL);
                            }
                    |   TK_identificador TK_separador lista_id_sal_o_no
                            {
                                printf("\tPARSER: lista_id_sal->mas de uno\n");
                                id = TS_consultar_id($1, cabeza_TS);
                                if (id == -1) {
                                    fila = insertar_id_TS($1, $3, &cola_TS);
                                    id = fila->id;
                                }
                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_OUTPUT, &id, NULL, NULL);
                            }
                    ;

                   
                    
decl_ent_sal        :   decl_ent {printf("\tPARSER: decl_ent_sal->entradas\n");}
                    |   decl_ent decl_sal {printf("\tPARSER: decl_ent_sal->entradas y salidas\n");} /* A nivel de algoritmo no hay entsal */
                    |   decl_sal {printf("\tPARSER: decl_ent_sal->salidas\n");}
                    ;
decl_ent            :   TK_ent lista_id_ent TK_composicion_secuencial {printf("\tPARSER: decl_ent\n");} /*TK_ent lista_id TK_definicion d_tipo TK_composicion_secuencial {printf("\tPARSER: decl_ent\n");}*/
                    ;
decl_sal            :   TK_sal lista_id_sal TK_composicion_secuencial {printf("\tPARSER: decl_sal\n");}
                    ;
exp_a               :   exp_a TK_op_suma exp_a {
                                                    printf("\tPARSER: exp_a -> suma\n");
                                                    id = TS_crear_variable_temporal(&cola_TS);
                                                    $$.place = id;
                                                    *op1 = $1.place;
                                                    *op2 = $3.place;
                                                    if ($1.type == TIPO_ENTERO) {
                                                        if ($3.type == TIPO_ENTERO) {
                                                            TS_modificar_tipo(&cabeza_TS, id, TIPO_ENTERO);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_SUMA_ENTERO, op1, op2, &id);
                                                            $$.type = TIPO_ENTERO;
                                                        } else if ($3.type == TIPO_REAL) {
                                                            TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op1, NULL, &id);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_SUMA_REAL, &id, op2, &id);
                                                            $$.type = TIPO_REAL;
                                                        } else {
                                                            printf("ERROR: Operando2 de tipo incorrecto\n");
                                                            errorFlag = 1;
                                                            $$.type = TIPO_ERROR;
                                                        }
                                                    } else if ($1.type == TIPO_REAL) {
                                                        if ($3.type == TIPO_ENTERO) {
                                                            TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op2, NULL, &id);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_SUMA_REAL, op1, &id, &id);
                                                            $$.type = TIPO_REAL;
                                                        } else if ($3.type == TIPO_REAL) {
                                                            TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_SUMA_REAL, op1, op2, &id);
                                                            $$.type = TIPO_REAL;
                                                        } else {
                                                            printf("ERROR: Operando2 de tipo incorrecto\n");
                                                            errorFlag = 1;
                                                            $$.type = TIPO_ERROR;
                                                        }
                                                    } else {
                                                        printf("ERROR: Operando1 de tipo incorrecto\n");
                                                        errorFlag = 1;
                                                        $$.type = TIPO_ERROR;
                                                    }
                                                }
                    |   exp_a TK_op_resta exp_a {
                    
                                                    printf("\tPARSER: exp_a -> resta\n");
                                                    id = TS_crear_variable_temporal(&cola_TS);
                                                    $$.place = id;
                                                    *op1 = $1.place;
                                                    *op2 = $3.place;
                                                    if ($1.type == TIPO_ENTERO) {
                                                        if ($3.type == TIPO_ENTERO) {
                                                            TS_modificar_tipo(&cabeza_TS, id, TIPO_ENTERO);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_RESTA_ENTERO, op1, op2, &id);
                                                            $$.type = TIPO_ENTERO;
                                                        } else if ($3.type == TIPO_REAL) {
                                                            TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op1, NULL, &id);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_RESTA_REAL, &id, op2, &id);
                                                            $$.type = TIPO_REAL;
                                                        } else {
                                                            printf("ERROR: Operando2 de tipo incorrecto\n");
                                                            errorFlag = 1;
                                                            $$.type = TIPO_ERROR;
                                                        }
                                                    } else if ($1.type == TIPO_REAL) {
                                                        if ($3.type == TIPO_ENTERO) {
                                                            TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op2, NULL, &id);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_RESTA_REAL, op1, &id, &id);
                                                            $$.type = TIPO_REAL;
                                                        } else if ($3.type == TIPO_REAL) {
                                                            TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_RESTA_REAL, op1, op2, &id);
                                                            $$.type = TIPO_REAL;
                                                        } else {
                                                            printf("ERROR: Operando2 de tipo incorrecto\n");
                                                            errorFlag = 1;
                                                            $$.type = TIPO_ERROR;
                                                        }
                                                    } else {
                                                        printf("ERROR: Operando1 de tipo incorrecto\n");
                                                        errorFlag = 1;
                                                        $$.type = TIPO_ERROR;
                                                    }
                                                }
                    |   exp_a TK_op_multiplicador exp_a {
                                                            printf("\tPARSER: exp_a -> multiplicacion\n");
                                                            id = TS_crear_variable_temporal(&cola_TS);
                                                            $$.place = id;
                                                            *op1 = $1.place;
                                                            *op2 = $3.place;
                                                            if ($1.type == TIPO_ENTERO) {
                                                                if ($3.type == TIPO_ENTERO) {
                                                                    TS_modificar_tipo(&cabeza_TS, id, TIPO_ENTERO);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_MULTIPLICACION_ENTERO, op1, op2, &id);
                                                                    $$.type = TIPO_ENTERO;
                                                                } else if ($3.type == TIPO_REAL) {
                                                                    TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op1, NULL, &id);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_MULTIPLICACION_REAL, &id, op2, &id);
                                                                    $$.type = TIPO_REAL;
                                                                } else {
                                                                    printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                    errorFlag = 1;
                                                                    $$.type = TIPO_ERROR;
                                                                }
                                                            } else if ($1.type == TIPO_REAL) {
                                                                if ($3.type == TIPO_ENTERO) {
                                                                    TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op2, NULL, &id);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_MULTIPLICACION_REAL, op1, &id, &id);
                                                                    $$.type = TIPO_REAL;
                                                                } else if ($3.type == TIPO_REAL) {
                                                                    TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_MULTIPLICACION_REAL, op1, op2, &id);
                                                                    $$.type = TIPO_REAL;
                                                                } else {
                                                                    printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                    errorFlag = 1;
                                                                    $$.type = TIPO_ERROR;
                                                                }
                                                            } else {
                                                                printf("ERROR: Operando1 de tipo incorrecto\n");
                                                                errorFlag = 1;
                                                                $$.type = TIPO_ERROR;
                                                            }
                                                        }
                    |   exp_a TK_op_division exp_a {
                                                        printf("\tPARSER: exp_a -> division\n");
                                                        id = TS_crear_variable_temporal(&cola_TS);
                                                        TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                        $$.place = id;
                                                        $$.type = TIPO_REAL;
                                                        *op1 = $1.place;
                                                        *op2 = $3.place;
                                                        //TODO: DECIDIR QUE VAMOS A HACER CON LA DIVISIÓN DE DOS ENTEROS. Si lo dejamos como está, tanto 2/3 y 2 div 3 hacen lo mismo...
                                                        if ($1.type == TIPO_ENTERO) {
                                                            if ($3.type == TIPO_ENTERO) {
                                                                id2 = TS_crear_variable_temporal(&cola_TS);
                                                                TS_modificar_tipo(&cabeza_TS, id2, TIPO_REAL);
                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op1, NULL, &id);
                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op2, NULL, &id2);
                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_DIVISION_ENTERO, &id, &id2, &id);
                                                            } else if ($3.type == TIPO_REAL) {
                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op1, NULL, &id);
                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_DIVISION_REAL, &id, op2, &id);
                                                            } else {
                                                                printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                errorFlag = 1;
                                                                $$.type = TIPO_ERROR;
                                                            }
                                                        } else if ($1.type == TIPO_REAL) {
                                                            if ($3.type == TIPO_ENTERO) {
                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op2, NULL, &id);
                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_DIVISION_REAL, op1, &id, &id);
                                                            } else if ($3.type == TIPO_REAL) {
                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_DIVISION_REAL, op1, op2, &id);
                                                            } else {
                                                                printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                errorFlag = 1;
                                                                $$.type = TIPO_ERROR;
                                                            }
                                                        } else {
                                                            printf("ERROR: Operando1 de tipo incorrecto\n");
                                                            errorFlag = 1;
                                                            $$.type = TIPO_ERROR;
                                                        }
                                                    }
                    |   exp_a TK_mod exp_a  {
                                                printf("\tPARSER: exp_a -> mod(resto)\n");
                                                id = TS_crear_variable_temporal(&cola_TS);
                                                $$.place = id;
                                                *op1 = $1.place;
                                                *op2 = $3.place;
                                                //TODO: DECIDIR QUE VAMOS A HACER CON EL RESTO.
                                                if ($1.type == TIPO_ENTERO) {
                                                    if ($3.type == TIPO_ENTERO) {
                                                        TS_modificar_tipo(&cabeza_TS, id, TIPO_ENTERO);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_MOD_ENTERO, op1, op2, &id);
                                                        $$.type = TIPO_ENTERO;
                                                    } else if ($3.type == TIPO_REAL) {
                                                        TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op1, NULL, &id);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_MOD_REAL, &id, op2, &id);
                                                        $$.type = TIPO_REAL;
                                                    } else {
                                                        printf("ERROR: Operando2 de tipo incorrecto\n");
                                                        errorFlag = 1;
                                                        $$.type = TIPO_ERROR;
                                                    }
                                                } else if ($1.type == TIPO_REAL) {
                                                    if ($3.type == TIPO_ENTERO) {
                                                        TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op2, NULL, &id);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_MOD_REAL, op1, &id, &id);
                                                        $$.type = TIPO_REAL;
                                                    } else if ($3.type == TIPO_REAL) {
                                                        TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_MOD_REAL, op1, op2, &id);
                                                        $$.type = TIPO_REAL;
                                                    } else {
                                                        printf("ERROR: Operando2 de tipo incorrecto\n");
                                                        errorFlag = 1;
                                                        $$.type = TIPO_ERROR;
                                                    }
                                                } else {
                                                    printf("ERROR: Operando1 de tipo incorrecto\n");
                                                    errorFlag = 1;
                                                    $$.type = TIPO_ERROR;
                                                }
                                            }
                    |   exp_a TK_div exp_a  {
                                                printf("\tPARSER: exp_a -> division entera\n");
                                                id = TS_crear_variable_temporal(&cola_TS);
                                                $$.place = id;
                                                *op1 = $1.place;
                                                *op2 = $3.place;
                                                TS_modificar_tipo(&cabeza_TS, id, TIPO_ENTERO);
                                                $$.type = TIPO_ENTERO;
                                                //TODO: DECIDIR QUE VAMOS A HACER CON LA DIVISIÓN DE DOS ENTEROS. Si lo dejamos como está, tanto 2/3 y 2 div 3 hacen lo mismo...
                                                if ($1.type == TIPO_ENTERO) {
                                                    if ($3.type == TIPO_ENTERO) {
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_DIVENT, op1, op2, &id);
                                                    } else if ($3.type == TIPO_REAL) {
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_REAL2INT, op2, NULL, &id);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_DIVENT, op1, &id, &id);
                                                    } else {
                                                        printf("ERROR: Operando2 de tipo incorrecto\n");
                                                        errorFlag = 1;
                                                        $$.type = TIPO_ERROR;
                                                    }
                                                } else if ($1.type == TIPO_REAL) {
                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_REAL2INT, op1, NULL, &id);
                                                    if ($3.type == TIPO_ENTERO) {
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_DIVENT, &id, op2, &id);
                                                    } else if ($3.type == TIPO_REAL) {
                                                        id2 = TS_crear_variable_temporal(&cola_TS);
                                                        TS_modificar_tipo(&cabeza_TS, id2, TIPO_ENTERO);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_REAL2INT, op2, NULL, &id2);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_DIVENT, &id, &id2, &id);
                                                    } else {
                                                        printf("ERROR: Operando2 de tipo incorrecto\n");
                                                        errorFlag = 1;
                                                        $$.type = TIPO_ERROR;
                                                    }
                                                } else {
                                                    printf("ERROR: Operando1 de tipo incorrecto\n");
                                                    errorFlag = 1;
                                                    $$.type = TIPO_ERROR;
                                                }
                                            }
                    |   TK_inicio_parentesis exp_a TK_fin_parentesis    {
                                                                            printf("\tPARSER: exp_a -> ()\n");
                                                                            $$ = $2;
                                                                        }
                    |   operando    {
                                        printf("\tPARSER: exp_a -> operando\n");
                                        $$ = $1;
                                        /*if ($$.type == TIPO_BOOLEANO){
                                            $$.TRUE = makelist();
                                            insert_list(&($$.TRUE),tabla_cuadruplas.nextquad);
                                            $$.FALSE = makelist();
                                            insert_list(&($$.FALSE),tabla_cuadruplas.nextquad+1);
                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_VERDADERO, &($1.place), NULL, NULL);
                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL);
                                                        
                                            
                                        }*/
                                    
                                    }
                    |   TK_literal_real     {
                                                printf("\tPARSER: exp_a -> real\n");
                                            }
                    |   TK_literal_entero   {
                                                printf("\tPARSER: exp_a -> entero\n");
                                            }
                    |   TK_op_resta exp_a   {
                                                printf("\tPARSER: exp_a -> numero negativo\n");
                                                //Creamos variable temporal.
                                                id = TS_crear_variable_temporal(&cola_TS);
                                                $$.place = id;
                                                *op1 = $2.place;
                                                if ($2.type == TIPO_ENTERO){
                                                    TS_modificar_tipo(&cabeza_TS, id, TIPO_ENTERO);
                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_RESTA_UNITARIA_ENTERO, op1, NULL, &id);
                                                    $$.type = TIPO_ENTERO;
                                                } else if($2.type == TIPO_REAL) {
                                                    TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_RESTA_UNITARIA_REAL, op1, NULL, &id);
                                                    $$.type = TIPO_REAL;
                                                } else {
                                                    printf("ERROR: Operando de tipo incorrecto\n");
                                                    errorFlag = 1;
                                                    $$.type = TIPO_ERROR;
                                                }
                                                
                                            }
                    |   exp_a TK_y M exp_a    {
                                                printf("\tPARSER: exp_a -> y\n");
                                                if ($1.type == TIPO_BOOLEANO) {
                                                    if ($4.type == TIPO_BOOLEANO) {
                                                        backpatch($1.TRUE, $3, &tabla_cuadruplas);
                                                        $$.FALSE = merge($1.FALSE, $4.FALSE);
                                                        $$.TRUE = $4.TRUE;
                                                        $$.type = TIPO_BOOLEANO;
                                                    } else {
                                                        printf("ERROR: Operando2 de tipo distinto a booleano.\n");
                                                        errorFlag = 1;
                                                        $$.type = TIPO_ERROR;
                                                    }
                                                } else {
                                                    printf("ERROR: Operando1 de tipo distinto a booleano.\n");
                                                    errorFlag = 1;
                                                    $$.type = TIPO_ERROR;
                                                }
                                            }
                    |   exp_a TK_o M exp_a    {
                                                printf("\tPARSER: exp_a -> o\n");
                                                
                                               
                                                if ($1.type == TIPO_BOOLEANO) {
                                                    if ($4.type == TIPO_BOOLEANO) {
                                                        backpatch($1.FALSE, $3, &tabla_cuadruplas);
                                                        $$.TRUE = merge($1.TRUE, $4.TRUE);
                                                        $$.FALSE = $4.FALSE;
                                                        $$.type = TIPO_BOOLEANO;
                                                    } else {
                                                        printf("ERROR: Operando2 de tipo distinto a booleano.\n");
                                                        errorFlag = 1;
                                                        $$.type = TIPO_ERROR;
                                                    }
                                                } else {
                                                    printf("ERROR: Operando1 de tipo distinto a booleano.\n");
                                                    errorFlag = 1;
                                                    $$.type = TIPO_ERROR;
                                                }
                                                
                                            }
                    |   TK_no exp_a {
                                        printf("\tPARSER: exp_a -> no\n");
                                        //id = TS_crear_variable_temporal(&cola_TS);
                                        if ($2.type == TIPO_BOOLEANO) {
                                            //TS_modificar_tipo(&cabeza_TS, id, TIPO_BOOLEANO);
                                            //insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_B_NO, &($2.place), NULL, &id);
                                            $$.TRUE = $2.FALSE;
                                            $$.FALSE = $2.TRUE;
                                            $$.type = TIPO_BOOLEANO;
                                        } else {
                                            printf("ERROR: Operando de tipo distinto a booleano.\n");
                                            errorFlag = 1;
                                            $$.type = TIPO_ERROR;
                                        }
                                    }
                    |   TK_literal_booleano {
                                                printf("\tPARSER: exp_a -> %d\n",$1);
                                                $$.type = TIPO_BOOLEANO;
                                                
                                            } /* Printeara un entero, 1 si es verdadero y 0 si es falso*/
                    |   expresion TK_comparador expresion   {
                                                                printf("\tPARSER: exp_a -> exp_a %s exp_a\n",$2);
                                                                $$.type = TIPO_BOOLEANO;
                                                                //id = TS_crear_variable_temporal(&cola_TS);
                                                                //TS_modificar_tipo(&cabeza_TS, id, TIPO_BOOLEANO);
                                                                int operadorEntero = -1;
                                                                int operadorReal = -1;
                                                                if (strcmp($2, "<") == 0) {
                                                                    operadorEntero =  OPERADOR_GOTO_MENOR_ENTERO;
                                                                    operadorReal =  OPERADOR_GOTO_MENOR_REAL;
                                                                } else if (strcmp($2, ">") == 0) {
                                                                    operadorEntero =  OPERADOR_GOTO_MAYOR_ENTERO;
                                                                    operadorReal = OPERADOR_GOTO_MAYOR_REAL;
                                                                } else if (strcmp($2, "<=") == 0) {
                                                                    operadorEntero = OPERADOR_GOTO_MEOI_ENTERO;
                                                                    operadorReal = OPERADOR_GOTO_MEOI_REAL;
                                                                } else if (strcmp($2, ">=") == 0) {
                                                                    operadorEntero = OPERADOR_GOTO_MAOI_ENTERO;
                                                                    operadorReal = OPERADOR_GOTO_MAOI_REAL;
                                                                }
                                                                if (operadorEntero == -1 || operadorReal == -1) {
                                                                    if (strcmp($2, "<>") == 0) {
                                                                        if ($1.type == TIPO_ENTERO) {
                                                                            if ($3.type == TIPO_ENTERO) {
                                                                                insert_list(&($$.TRUE), tabla_cuadruplas.nextquad);
                                                                                insert_list(&($$.FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_DISTINTO_ENTERO, &($1.place), &($3.place), NULL);//True 
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL); // False
                                                                                //insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_R_DISTINTO_ENTERO, &($1.place), &($3.place), &id);
                                                                            } else if ($3.type == TIPO_REAL) {
                                                                                id2 = TS_crear_variable_temporal(&cola_TS);
                                                                                TS_modificar_tipo(&cabeza_TS, id2, TIPO_REAL);
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, &($1.place), NULL, &id2);
                                                                                
                                                                                insert_list(&($$.TRUE), tabla_cuadruplas.nextquad);
                                                                                insert_list(&($$.FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_DISTINTO_REAL, &id2, &($3.place), NULL);//True 
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL); // False
                                                                                
                                                                                
                                                                                
                                                                                //insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_R_DISTINTO_ENTERO, &id2, &($3.place), &id);
                                                                            } else {
                                                                                printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                                errorFlag = 1;
                                                                                $$.type = TIPO_ERROR;
                                                                            }
                                                                        } else if ($1.type == TIPO_REAL) {
                                                                            if ($3.type == TIPO_ENTERO) {
                                                                                id2 = TS_crear_variable_temporal(&cola_TS);
                                                                                TS_modificar_tipo(&cabeza_TS, id2, TIPO_REAL);
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, &($3.place), NULL, &id2);
                                                                                insert_list(&($$.TRUE), tabla_cuadruplas.nextquad);
                                                                                insert_list(&($$.FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_DISTINTO_REAL, &($1.place), &id2, NULL);//True 
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL); // False
                                                                                
                                                                                
                                                                                
                                                                                //insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_R_DISTINTO_ENTERO, &($1.place), &id2, &id);
                                                                            } else if ($3.type == TIPO_REAL) {
                                                                            
                                                                                insert_list(&($$.TRUE), tabla_cuadruplas.nextquad);
                                                                                insert_list(&($$.FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_DISTINTO_REAL, &($1.place), &($3.place), NULL);//True 
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL); // False
                                                                                
                                                                                //insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_R_DISTINTO_REAL, &($1.place), &($3.place), &id);
                                                                            } else {
                                                                                printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                                errorFlag = 1;
                                                                                $$.type = TIPO_ERROR;
                                                                            }
                                                                        } else if ($1.type == TIPO_BOOLEANO) {
                                                                            if ($3.type == TIPO_BOOLEANO) {
                                                                                insert_list(&($$.TRUE), tabla_cuadruplas.nextquad);
                                                                                
                                                                                insert_list(&($$.FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_DISTINTO_BOOLEANO, &($1.place), &($3.place), NULL);//True 
                                                                                
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL); // False
                                                                                //insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_R_DISTINTO_BOOLEANO, &($1.place), &($3.place), &id);
                                                                            } else {
                                                                                printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                                errorFlag = 1;
                                                                                $$.type = TIPO_ERROR;
                                                                            }
                                                                        } else {
                                                                            printf("ERROR: Operando1 de tipo incorrecto\n");
                                                                            errorFlag = 1;
                                                                            $$.type = TIPO_ERROR;
                                                                        }
                                                                    } else {
                                                                        printf("ERROR: Operador inválido\n");
                                                                        errorFlag = 1;
                                                                        $$.type = TIPO_ERROR;
                                                                    }
                                                                } else {
                                                                    if ($1.type == TIPO_ENTERO) {
                                                                        if ($3.type == TIPO_ENTERO) {
                                                                            insert_list(&($$.TRUE), tabla_cuadruplas.nextquad);
                                                                            insert_list(&($$.FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                            insertar_cuadrupla(&tabla_cuadruplas, operadorEntero, &($1.place), &($3.place), NULL);//True 
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL); // False
                                                                            //insertar_cuadrupla(&tabla_cuadruplas, operadorEntero, &($1.place), &($3.place), &id);
                                                                        } else if ($3.type == TIPO_REAL) {
                                                                            
                                                                            id2 = TS_crear_variable_temporal(&cola_TS);
                                                                            TS_modificar_tipo(&cabeza_TS, id2, TIPO_REAL);
                                                                            //TS_modificar_tipo(&cabeza_TS, id, TIPO_BOOLEANO);
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, &($1.place), NULL, &id2);
                                                                            insert_list(&($$.TRUE), tabla_cuadruplas.nextquad);
                                                                            insert_list(&($$.FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                            insertar_cuadrupla(&tabla_cuadruplas, operadorReal, &($1.place), &id, NULL);//True 
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL); // False
                                                                            //insertar_cuadrupla(&tabla_cuadruplas, operadorReal, &($1.place), &id, &id2);
                                                                        } else {
                                                                            printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                            errorFlag = 1;
                                                                            $$.type = TIPO_ERROR;
                                                                        }
                                                                    } else if ($1.type == TIPO_REAL) {
                                                                        if ($3.type == TIPO_ENTERO) {
                                                                            
                                                                            id2 = TS_crear_variable_temporal(&cola_TS);
                                                                            TS_modificar_tipo(&cabeza_TS, id2, TIPO_REAL);
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, &($3.place), NULL, &id2);
                                                                            
                                                                            insert_list(&($$.TRUE), tabla_cuadruplas.nextquad);
                                                                            insert_list(&($$.FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                            insertar_cuadrupla(&tabla_cuadruplas, operadorReal, &id, &($3.place), NULL);//True 
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL); // False
                                                                            //insertar_cuadrupla(&tabla_cuadruplas, operadorReal, &id, &($3.place), &id2);
                                                                        } else if ($3.type == TIPO_REAL) {
                                                                            insert_list(&($$.TRUE), tabla_cuadruplas.nextquad);
                                                                            insert_list(&($$.FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                            insertar_cuadrupla(&tabla_cuadruplas, operadorReal, &($1.place), &($3.place), NULL);//True 
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL); // False
                                                                            //insertar_cuadrupla(&tabla_cuadruplas, operadorReal, &($1.place), &($3.place), &id);
                                                                        } else {
                                                                            printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                            errorFlag = 1;
                                                                            $$.type = TIPO_ERROR;
                                                                        }
                                                                    } else {
                                                                        printf("ERROR: Operando1 de tipo incorrecto\n");
                                                                        errorFlag = 1;
                                                                        $$.type = TIPO_ERROR;
                                                                    }
                                                                }
                                                            }
                    |   expresion TK_igual expresion    {
                                                            printf("\tPARSER: exp_a -> exp_a == exp_a\n");
                                                            $$.type = TIPO_BOOLEANO;
                                                            
                                                            if ($1.type == TIPO_ENTERO) {
                                                                if ($3.type == TIPO_ENTERO) {
                                                                    insert_list(&($$.TRUE), tabla_cuadruplas.nextquad);
                                                                    insert_list(&($$.FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_IGUAL_ENTERO, &($1.place), &($3.place), NULL);//True 
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL); // False
                                                                } else if ($3.type == TIPO_REAL) {
                                                                    id2 = TS_crear_variable_temporal(&cola_TS);
                                                                    TS_modificar_tipo(&cabeza_TS, id2, TIPO_REAL);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, &($1.place), NULL, &id2);
                                                                    insert_list(&($$.TRUE), tabla_cuadruplas.nextquad);
                                                                    insert_list(&($$.FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_IGUAL_REAL, &id2, &($3.place), NULL);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL);
                                                                } else {
                                                                    printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                    errorFlag = 1;
                                                                    $$.type = TIPO_ERROR;
                                                                }
                                                            } else if ($1.type == TIPO_REAL) {
                                                                if ($3.type == TIPO_ENTERO) {
                                                                    id2 = TS_crear_variable_temporal(&cola_TS);
                                                                    TS_modificar_tipo(&cabeza_TS, id2, TIPO_REAL);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, &($3.place), NULL, &id2);
                                                                    insert_list(&($$.TRUE), tabla_cuadruplas.nextquad);
                                                                    insert_list(&($$.FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                    //insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_R_IGUAL_ENTERO, &($1.place), &id2, &id);
                                                                    // TODO: Como guardamos if id1.val oprel.val id2.val goto
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_IGUAL_REAL, &($1.place), &id2, NULL);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL);
                                                                } else if ($3.type == TIPO_REAL) {
                                                                    insert_list(&($$.TRUE), tabla_cuadruplas.nextquad);
                                                                    insert_list(&($$.FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                    // TODO: Como guardamos if id1.val oprel.val id2.val goto
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_IGUAL_REAL, &($1.place), &($3.place), NULL);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL);
                                                                    //insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_R_IGUAL_REAL, &($1.place), &($3.place), &id);
                                                                } else {
                                                                    printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                    errorFlag = 1;
                                                                    $$.type = TIPO_ERROR;
                                                                }
                                                            } else if ($1.type == TIPO_BOOLEANO) {
                                                                if ($3.type == TIPO_BOOLEANO) {
                                                                    insert_list(&($$.TRUE), tabla_cuadruplas.nextquad);
                                                                    insert_list(&($$.FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                    // TODO: Como guardamos if id1.val oprel.val id2.val goto
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_IGUAL_BOOLEANO, &($1.place), &($3.place), NULL);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL);
                                                                    //insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_R_IGUAL_BOOLEANO, &($1.place), &($3.place), &id);
                                                                } else {
                                                                    printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                    errorFlag = 1;
                                                                    $$.type = TIPO_ERROR;
                                                                }
                                                            } else {
                                                                printf("ERROR: Operando1 de tipo incorrecto\n");
                                                                errorFlag = 1;
                                                                $$.type = TIPO_ERROR;
                                                            }
                                                        }
                    ;
expresion           :   exp_a   {
                                    printf("\tPARSER: expresion -> operaciones aritméticas o booleanas\n");
                                    $$ = $1;
                                }
                    |   funcion_ll {printf("\tPARSER: expresion -> llamada a funcion\n");}
                    ;
operando            :   TK_identificador    {
                                                printf("\tPARSER: operando -> (identificador) %s\n", $1);
                                                id = TS_consultar_id($1, cabeza_TS);
                                                if (id == -1) {
                                                    $$.type = TIPO_ERROR;
                                                    printf("ERROR: Variable no declarada.\n");
                                                    errorFlag = 1;
                                                } else {
                                                    $$.place = id;
                                                    $$.type = TS_consultar_tipo(id, cabeza_TS);
                                                    $$.TRUE = makelist();
                                                    $$.FALSE = makelist();
                                                    if ($$.type == TIPO_BOOLEANO){
                                                       /* $$.TRUE = makelist();
                                                        insert_list(&($$.TRUE),tabla_cuadruplas.nextquad);
                                                        $$.FALSE = makelist();
                                                        insert_list(&($$.FALSE),tabla_cuadruplas.nextquad+1);
                                                        int x = TS_consultar_id($1,cabeza_TS);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_VERDADERO, &(x), NULL, NULL);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL);*/
                                                                    
                                                        
                                                    }
                                                }
                                            }
                    /*|   operando TK_punto operando TODO: hay que hacer en el scanner un token punto*/
                    |   operando TK_inicio_array expresion TK_fin_array {printf("\tPARSER: operando -> operando[expresion]\n");}
                    |   operando TK_ref {printf("\tPARSER: operando -> operando ref\n");}
                    ;

instrucciones       :   instruccion TK_composicion_secuencial M instrucciones       {
                                                                                        printf("\tPARSER: instrucciones -> lista/composicion de instrucciones\n");
                                                                                        if (!empty($1.NEXT)){
                                                                                            backpatch($1.NEXT, $3, &tabla_cuadruplas);
                                                                                        }
                                                                                        $$.NEXT = $4.NEXT;
                                                                                    }
                    |   instruccion     {
                                            printf("\tPARSER: instrucciones -> una instruccion\n");
                                            $$.NEXT = $1.NEXT;
                                        }
                    ;
instruccion         :   TK_continuar    {
                                            printf("\tPARSER: instruccion -> continuar\n");
                                        }
                    |   asignacion  {
                                        printf("\tPARSER: instruccion -> instruccion de asignacion\n");
                                        $$.NEXT = $1.NEXT;
                                        
                                    }
                    |   alternativa {printf("\tPARSER: instruccion -> instruccion alternativa(if)\n");}
                    |   iteracion {printf("\tPARSER: instruccion -> instruccion iterativa\n");}
                    |   accion_ll {printf("\tPARSER: instruccion -> llamada a accion\n");}
                    ;
asignacion          :   operando TK_asignacion expresion    {
                                                                printf("\tPARSER: asignacion -> operando := expresion\n");
                                                                *op1 = $3.place;
                                                                if ($1.type != $3.type) {
                                                                    printf("ERROR: Asignación de tipos incorrectos.\n");
                                                                    errorFlag = 1;
                                                                } else {
                                                                    switch ($1.type) {
                                                                        case TIPO_ENTERO:
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_ASIGNACION_ENTERO, op1, NULL, &($1.place));
                                                                            break;
                                                                        case TIPO_REAL:
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_ASIGNACION_REAL, op1, NULL, &($1.place));
                                                                            break;
                                                                        case TIPO_CARACTER:
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_ASIGNACION_CARACTER, op1, NULL, &($1.place));
                                                                            break;
                                                                        case TIPO_CADENA:
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_ASIGNACION_CADENA, op1, NULL, &($1.place));
                                                                            break;
                                                                        case TIPO_BOOLEANO:
                                                                            backpatch($3.TRUE, tabla_cuadruplas.nextquad, &tabla_cuadruplas);
                                                                            backpatch($3.FALSE,tabla_cuadruplas.nextquad + 2, &tabla_cuadruplas);
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_ASIGNACION_BOOLEANO_TRUE, NULL, NULL, &($1.place));
                                                                            // En caso de OPERADOR_GOTO: El primer operando es un puntero a un entero que representa 
                                                                            // la cuadrupla y no el id de la tabla de simbolos.
                                                                            
                                                                            int* y;
                                                                            y = (int*)malloc(sizeof(int));
                                                                            *y = tabla_cuadruplas.nextquad + 2;
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, y);
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_ASIGNACION_BOOLEANO_FALSE, NULL, NULL, &($1.place));
                                                                            
                                                                            // NO hace falta porque la lista ya está incializada a null.
                                                                            // Es decir, es una estructura con doS punteros(cabeza, cola) que apuntan a NULL.
                                                                            //$$.NEXT = makelist();
                                                                            break;
                                                                    }
                                                                }
                                                            }
                    ;
alternativa         :   TK_si expresion TK_entonces instrucciones lista_opciones TK_fsi {printf("\tPARSER: alternativa -> if expresion -> instrucciones fsi\n");}
                    ;
lista_opciones      :   TK_si_no_si TK_entonces instrucciones lista_opciones {printf("\tPARSER: lista_opciones -> [] entonces instrucciones lista_opciones\n");}
                    |   /* empty */ {printf("\tPARSER: lista_opciones -> epsilon (no hay si_no_si)\n");}
                    ;
iteracion           :   it_cota_fija {printf("\tPARSER: iteracion -> it_cota_fija(para)\n");}
                    |   it_cota_exp {printf("\tPARSER: iteracion -> it_cota_exp(mientras)\n");}
                    ;
it_cota_exp         :   TK_mientras expresion TK_hacer instrucciones TK_fmientras  {printf("\tPARSER: it_cota_exp -> mientras\n");}
                    ;
it_cota_fija        :   TK_para TK_identificador TK_asignacion expresion TK_hasta expresion TK_hacer instrucciones TK_fpara {printf("\tPARSER: it_cota_fija -> para\n");}
                    ;
accion_d            :   TK_accion a_cabecera bloque TK_faccion {printf("\tPARSER: accion_d -> implementacion de accion\n");}
                    ;
funcion_d           :   TK_funcion f_cabecera bloque TK_dev expresion TK_ffuncion {printf("\tPARSER: funcion_d -> implementacion de funcion\n");}
                    ;
a_cabecera          :   TK_identificador TK_inicio_parentesis d_par_form TK_fin_parentesis TK_composicion_secuencial {printf("\tPARSER: a_cabecera -> cabecera de accion\n");}
                    ;
f_cabecera          :   TK_identificador TK_inicio_parentesis lista_d_var TK_fin_parentesis TK_dev d_tipo TK_composicion_secuencial {printf("\tPARSER: f_cabecera -> cabecera de funcion");}
                    ;
d_par_form          :   d_p_form TK_composicion_secuencial d_par_form {printf("\tPARSER: d_par_form -> ent --; sal ---;\n");} /*TODO: PRINTEAR UN MENSAJE MEJOR*/
                    |   /* empty */ {printf("\tPARSER: d_par_form -> epsilon\n");}
                    ;
d_p_form            :   TK_ent lista_id TK_definicion d_tipo TK_composicion_secuencial {printf("\tPARSER: d_p_form -> ent listaIdentificadores : tipo;\n");}
                    |   TK_sal lista_id TK_definicion d_tipo TK_composicion_secuencial {printf("\tPARSER: d_p_form -> sal listaIdentificadores : tipo;\n");}
                    |   TK_entsal lista_id TK_definicion d_tipo TK_composicion_secuencial {printf("\tPARSER: d_p_form -> e/s listaIdentificadores : tipo;\n");}
                    ;
accion_ll           :   TK_identificador TK_inicio_parentesis l_ll TK_fin_parentesis {printf("\tPARSER: accion_ll -> llamada a accion\n");}
                    ;
funcion_ll          :   /* empty */ /* TK_identificador TK_inicio_parentesis l_ll TK_fin_parentesis {printf("\tPARSER: funcion_ll -> llamada a funcion");} */
                    ;
l_ll                :   expresion TK_separador l_ll {printf("\tPARSER: l_ll -> concatenacion de expresiones\n");}
                    |   expresion {printf("\tPARSER: l_ll -> una expresion\n");}
                    ;
M                   :   /* empty */ {
                                        printf("\tPARSER: M -> epsilon\n");
                                        // Almacenamos el valor de nextquad.
                                        $$ = tabla_cuadruplas.nextquad;     
                                    }
                    ;
%%

int yyerror(char *s) {
    printf("ERROR: %s\n", s);
}

int main(int argc, char *argv[]) {
    errorFlag = 0;
    cabeza_TS = (struct FILA_TS*) malloc(sizeof(struct FILA_TS));
    cola_TS = (struct FILA_TS*) malloc(sizeof(struct FILA_TS));
    inicializar_TS(&cabeza_TS, &cola_TS);
    inicializar_TC(&tabla_cuadruplas);
    op1 = (int*) malloc(sizeof(int));
    op2 = (int*) malloc(sizeof(int));
    res = (int*) malloc(sizeof(int));
    if (argc > 1){
            yyin = fopen(argv[1], "r");	
    }
    yyparse();
    if (argc > 1){
            fclose(yyin);
    }
    guardar_TS("Resultados/TS.txt", cabeza_TS, errorFlag);
    guardar_TC("Resultados/TC.txt", tabla_cuadruplas, errorFlag);
    guardar_CTD("Resultados/CTD.txt", tabla_cuadruplas, cabeza_TS, errorFlag);
    /*free(op1);
    free(op2);
    free(res);
    free(tabla_cuadruplas);
    free(cola_TS);
    free(cabeza_TS);*/
    return 0;
}