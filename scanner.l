 /* MIRAR LAS MAYUSCULAS EN EL IDENTIFICADOR */
%{
 /* Aquí van los includes */
#include "definiciones.h"
#include <stdio.h>
#include "parser.tab.h"

%}
 /* Expresiones regulares básicas */
DR_letra               [a-zA-Z]|\_
DR_cifra               [0-9]
DR_caracteres_blancos  [ \t\n]
DR_id                  [a-zA-Z][a-zA-Z0-9]* 

 /* Palabras reservadas */
DR_algoritmo            (?i:algoritmo)
DR_falgoritmo           (?i:falgoritmo)
DR_accion               (?i:accion)
DR_faccion              (?i:faccion)
DR_booleano             (?i:booleano)
DR_cadena               (?i:cadena)
DR_caracter             (?i:caracter)
DR_const                (?i:const)
DR_continuar            (?i:continuar)
DR_de                   (?i:de)
DR_dev                  (?i:dev)
DR_div                  (?i:div)
DR_ent                  (?i:ent)
DR_entero               (?i:entero)
DR_entrada_salida       (?i:e\/s)
DR_falso                (?i:falso)
DR_fconst               (?i:fconst)
DR_ffuncion             (?i:ffuncion)
DR_funcion              (?i:funcion)
DR_mientras             (?i:mientras)
DR_fmientras            (?i:fmientras)
DR_para                 (?i:para)
DR_fpara                (?i:fpara)
DR_si                   (?i:si)
DR_fsi                  (?i:fsi)
DR_tipo                 (?i:tipo)
DR_ftipo                (?i:ftipo)
DR_tupla                (?i:tupla)
DR_ftupla               (?i:ftupla)
DR_var                  (?i:var)
DR_fvar                 (?i:fvar)
DR_hacer                (?i:hacer)
DR_hasta                (?i:hasta)
DR_mod                  (?i:mod)
DR_no                   (?i:no)
DR_o                    (?i:o)
DR_real                 (?i:real) 
DR_ref                  (?i:ref)
DR_sal                  (?i:sal)
DR_tabla                (?i:tabla)
DR_verdadero            (?i:verdadero)
DR_y                    (?i:y)

 /* Precondición, postcondición y comentarios */ 
 /*DR_precondicion         \{(?i:prec)([^\}]|\/\})*\}
DR_postcondicion        \{(?i:post)([^\}]|\/\})*\}*/
DR_comentario           \{([^\}]|\/\})*\}

 /* Expresiones regulares */
DR_asignacion              :=
DR_composicion_secuencial  ;
DR_separador               ,
DR_subrango                \.\.
DR_tipo_variable           :
DR_entonces                \->
DR_si_no_si                \[\]
DR_inicio_array            \[
DR_fin_array               \]
DR_inicio_parentesis        \(
DR_fin_parentesis           \)

 /* Operadores */
DR_suma                     \+
DR_resta                    \-
DR_multiplicacion           \*
DR_division                 \/
DR_referencia               \.
DR_igual                    =
DR_operador_relacional      >|<|<>|>=|<=

 /* Strings, y números enteros o reales, positivos y negativos */
DR_literal_cadena           \'([^\']|\/\')*\'
DR_literal_caracter         \"{DR_letra}\"
DR_literal_entero           {DR_cifra}+((e|E)(\+|\-){DR_cifra}+)? 
DR_literal_real             {DR_cifra}+(\.{DR_cifra}+)?((e|E)(\+|\-){DR_cifra}+)? 

%%
 /* Reglas para literales */
{DR_literal_cadena}	        {
                                printf("literal cadena: %s \n", yytext);
                                yylval.ctype = yytext;
                                return TK_LITERAL_CADENA;
                            }
{DR_literal_caracter}	    {
                                printf("literal caracter: %s \n", yytext);
                                yylval.ctype = yytext;
                                return TK_LITERAL_CARACTER;
                            }

 /* Palabras reservadas */
{DR_algoritmo}              {
                                printf("algoritmo: %s \n", yytext); 
                                return TK_ALGORITMO;
                            }
{DR_falgoritmo}             {
                                printf("falgoritmo: %s \n", yytext); 
                                return TK_FALGORITMO;
                            }
{DR_accion}                 {
                                printf("accion: %s \n", yytext);
                                return TK_ACCION;
                            }
{DR_faccion}                {
                                printf("faccion: %s \n", yytext); 
                                return TK_FACCION;
                            }
{DR_booleano}               {
                                printf("booleano: %s \n", yytext); 
                                return TK_BOOLEANO;
                            }
{DR_cadena}                 {
                                printf("cadena: %s \n", yytext); 
                                return TK_CADENA;
                            }
{DR_caracter}               {
                                printf("caracter: %s \n", yytext); 
                                return TK_CARACTER;
                            }
{DR_const}                  {
                                printf("const: %s \n", yytext); 
                                return TK_CONST;
                            }
{DR_fconst}                 {
                                printf("fin constante: %s \n", yytext); 
                                return TK_FCONST;
                            }
{DR_continuar}              {
                                printf("continuar: %s \n", yytext); 
                                return TK_CONTINUAR;
                            }
{DR_de}                     {
                                printf("de: %s \n", yytext); 
                                return TK_DE;
                            }
{DR_dev}                    {
                                printf("dev: %s \n", yytext); 
                                return TK_DEV;
                            }
{DR_div}                    {
                                printf("div: %s \n", yytext); 
                                return TK_DIV;
                            }
{DR_ent}                    {
                                printf("entrada: %s \n", yytext); 
                                return TK_ENT;
                            }
{DR_entero}                 {
                                printf("entero: %s \n", yytext); 
                                yylval.celda = TIPO_ENTERO;
                                return TK_ENTERO;
                            }
{DR_entrada_salida}         {
                                printf("entrada salida: %s \n", yytext); 
                                return TK_ENT_SAL;
                            }
{DR_falso}                  {
                                printf("falso: %s \n", yytext); 
                                yylval.itype =0;
                                return TK_FALSO;
                            }
{DR_funcion}                {
                                printf("funcion: %s \n", yytext); 
                                return TK_FUNCION;
                            }
{DR_ffuncion}               {
                                printf("fin funcion: %s \n", yytext); 
                                return TK_FFUNCION;
                            }
{DR_mientras}               {
                                printf("mientras: %s \n", yytext); 
                                return TK_MIENTRAS;
                            }
{DR_fmientras}              {
                                printf("fin mientras: %s \n", yytext); 
                                return TK_FMIENTRAS;
                            }
{DR_para}                   {
                                printf("para: %s \n", yytext); 
                                return TK_PARA;
                            }
{DR_fpara}                  {
                                printf("fin para: %s \n", yytext); 
                                return TK_FPARA;
                            }
{DR_si}                     {
                                printf("si: %s \n", yytext); 
                                return TK_SI;
                            }
{DR_fsi}                    {
                                printf("fin si: %s \n", yytext); 
                                return TK_FSI;
                            }
{DR_tipo}                   {
                                printf("tipo: %s \n", yytext); 
                                return TK_TIPO;
                            }
{DR_ftipo}                  {
                                printf("fin tipo: %s \n", yytext); 
                                return TK_FTIPO;
                            }
{DR_tupla}                  {
                                printf("tupla: %s \n", yytext); 
                                return TK_TUPLA;
                            }
{DR_ftupla}                 {
                                printf("fin tupla: %s \n", yytext); 
                                return TK_FTUPLA;
                            }
{DR_var}                    {
                                printf("var: %s \n", yytext); 
                                return TK_VAR;
                            }
{DR_fvar}                   {
                                printf("fvar: %s \n", yytext); 
                                return TK_FVAR;
                            }
{DR_hacer}                  {
                                printf("hacer: %s \n", yytext); 
                                return TK_HACER;
                            }
{DR_hasta}                  {
                                printf("hasta: %s \n", yytext); 
                                return TK_HASTA;
                            }
{DR_mod}                    {
                                printf("mod: %s \n", yytext); 
                                return TK_MOD;
                            }
{DR_no}                     {
                                printf("no: %s \n", yytext); 
                                return TK_NO;
                            }
{DR_o}                      {
                                printf("o: %s \n", yytext); 
                                return TK_O;
                            }
{DR_real}                   {
                                printf("real: %s \n", yytext); 
                                return TK_REAL;
                            }
{DR_ref}                    {
                                printf("ref: %s \n", yytext); 
                                return TK_REF;
                            }
{DR_sal}                    {
                                printf("salida: %s \n", yytext); 
                                return TK_SAL;
                            }
{DR_tabla}                  {
                                printf("tabla: %s \n", yytext); 
                                return TK_TABLA;
                            }
{DR_verdadero}              {
                                printf("verdadero: %s \n", yytext); 
                                yylval.itype = 1;
                                return TK_VERDADERO;
                            }
{DR_y}                      {
                                printf("y: %s \n", yytext); 
                                return TK_Y;
                            }

 /* Precondición, postcondición y comentario */
 /*{DR_precondicion}           {printf("precondicion: %s \n", yytext);}
{DR_postcondicion}          {printf("postcondicion: %s \n", yytext);}*/
{DR_comentario}		        {
                                printf("comentario: %s \n", yytext); 
                                return TK_COMENTARIO;
                            }
 
 /*-?{DR_cifra}+               {printf("numero entero: %s \n", yytext);}
 -?{DR_cifra}+\.{DR_cifra}+  {printf("numero real: %s \n", yytext);}*/
 
 /* Operadores aritméticos */
{DR_suma}                   {
                                printf("operador: %s \n", yytext); 
                                return TK_SUMA;
                            }
{DR_resta}                  {
                                printf("operador: %s \n", yytext); 
                                return TK_RESTA;
                            }
{DR_multiplicacion}         {
                                printf("operador: %s \n", yytext); 
                                return TK_MULTIPLICACION;
                            }
{DR_division}               {
                                printf("operador: %s \n", yytext); 
                                return TK_DIVISION;
                            }
{DR_referencia}             {
                                printf("referencia: %s \n", yytext); 
                                return TK_REFERENCIA;
                            }
{DR_asignacion}             {
                                printf("asignacion: %s \n", yytext); 
                                return TK_ASIGNACION;
                            }
{DR_composicion_secuencial} {
                                printf("composicion secuencial: %s \n", yytext); 
                                return TK_COMPOSICION_SECUENCIAL;
                            }
{DR_separador}              {
                                printf("separador: %s \n", yytext); 
                                return TK_SEPARADOR;
                            }
{DR_subrango}               {
                                printf("subrango: %s \n", yytext); 
                                return TK_SUBRANGO;
                            }
{DR_tipo_variable}          {
                                printf("tipo variable: %s \n", yytext); 
                                return TK_DEF_TIPO;
                            }
{DR_entonces}               {
                                printf("entonces: %s \n", yytext); 
                                return TK_ENTONCES;
                            }
{DR_si_no_si}               {
                                printf("si no si: %s \n", yytext); 
                                return TK_SI_NO_SI;
                            }
{DR_inicio_parentesis}      {
                                printf("inicio parentesis: %s \n", yytext); 
                                return TK_INICIO_PARENTESIS;
                            }
{DR_fin_parentesis}         {
                                printf("fin parentesis: %s \n", yytext); 
                                return TK_FIN_PARENTESIS;
                            }
{DR_inicio_array}           {
                                printf("inicio array: %s \n", yytext); 
                                return TK_INICIO_ARRAY;
                            }
{DR_fin_array}              {
                                printf("fin array: %s \n", yytext); 
                                return TK_FIN_ARRAY;
                            }
{DR_igual}                  {
                                printf("igual: %s \n", yytext); 
                                return TK_IGUAL;
                            }
{DR_operador_relacional}    {
                                printf("operador relacional: %s \n", yytext); 
                                return TK_OPERADOR_RELACIONAL;
                            }

 /* Identificadores */
{DR_literal_entero} 	    {
                                printf("literal entero: %s \n", yytext); 
                                yylval.itype = atoi(yytext);
                                return TK_LITERAL_ENTERO;
                            }
{DR_literal_real} 	        {
                                printf("literal real: %s \n", yytext); 
                                yylval.ftype = atof(yytext);
                                return TK_LITERAL_REAL;
                            }
{DR_id}                     {
                                printf("identificador: %s \n", yytext); 
                                yylval.ctype = (char*)malloc(sizeof(strlen(yytext)));
						        strcpy(yylval.ctype,yytext);
                                return TK_IDENTIFICADOR;
                            }

 /* Reglas para delimitadores */
{DR_caracteres_blancos}+    

%%