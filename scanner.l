 /* MIRAR LAS MAYUSCULAS EN EL IDENTIFICADOR */
%{
 /* Aquí van los includes */
#include <stdio.h>
%}

 /* Definitions */
DR_letra               [a-z]|[A-Z]|\_
DR_letra_o_cifra       DR_letra|DR_cifra
DR_cifra               [0-9]
DR_caracteres_blancos  [ \t\n]
DR_id                  [a-zA-Z][a-zA-Z0-9]*


 /* Palabras reservadas */
DR_algoritmo   (?i:algoritmo)
DR_falgoritmo  (?i:falgoritmo)
DR_accion      (?i:accion)
DR_faccion     (?i:faccion)
DR_booleano    (?i:booleano)
DR_cadena      (?i:cadena)
DR_caracter    (?i:caracter)
DR_const       (?i:const)
DR_continuar   (?i:continuar)
DR_de          (?i:de)
DR_dev         (?i:dev)
DR_div         (?i:div)
DR_ent         (?i:ent)
DR_entero      (?i:entero)
DR_entrada_salida         (?i:e\/s)
DR_falso       (?i:falso)
DR_fconst      (?i:fconst)
DR_ffuncion    (?i:ffuncion)
DR_funcion     (?i:funcion)
DR_mientras    (?i:mientras)
DR_fmientras   (?i:fmientras)
DR_para        (?i:para)
DR_fpara       (?i:fpara)
DR_si          (?i:si)
DR_fsi         (?i:fsi)
DR_tipo        (?i:tipo)
DR_ftipo       (?i:ftipo)
DR_tupla       (?i:tupla)
DR_ftupla      (?i:ftupla)
DR_var         (?i:var)
DR_fvar        (?i:fvar)
DR_hacer       (?i:hacer)
DR_hasta       (?i:hasta)
DR_mod         (?i:mod)
DR_no          (?i:no)
DR_o           (?i:o)
DR_real        (?i:real) 
DR_ref         (?i:ref)
DR_sal         (?i:sal)
DR_tabla       (?i:tabla)
DR_verdadero   (?i:verdadero)
DR_y           (?i:y)
DR_precondicion \{(?i:prec)([^\}]|\/\})*\}
DR_postcondicion \{(?i:post)([^\}]|\/\})*\}
 /*DR_nombre       \b\w+\b(?=\algoritmo )*/

 /* Operadores: No se si son con o sin comillas */
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
DR_operadores_relacionales =|>|<|<>|>=|<=


 /* Identificadores */

 /* Constantes */

 /* Signos de puntuacion como parentesis, punto y coma ... */

 /* Marcas de comienzo y fin de bloque */


%%
 /* rules */
"+"|"\-"|"*"|"\/"	{printf("operador: %s \n", yytext);}
{DR_algoritmo}      {printf("algoritmo: %s \n", yytext);}
{DR_falgoritmo}     {printf("falgoritmo: %s \n", yytext);}
{DR_accion}         {printf("accion: %s \n", yytext);}
{DR_faccion}        {printf("faccion: %s \n", yytext);}
{DR_booleano}       {printf("booleano: %s \n", yytext);}
{DR_ent}            {printf("entrada: %s \n", yytext);}
{DR_sal}            {printf("salida: %s \n", yytext);}
{DR_entero}         {printf("entero: %s \n", yytext);}
{DR_precondicion}   {printf("precondicion: %s \n", yytext);}
{DR_postcondicion}  {printf("postcondicion: %s \n", yytext);}
{DR_var}            {printf("var: %s \n", yytext);}
{DR_fvar}           {printf("fvar: %s \n", yytext);}
{DR_div}            {printf("div: %s \n", yytext);}
{DR_mod}            {printf("mod: %s \n", yytext);}
-?{DR_cifra}+         {printf("numero entero: %s \n", yytext);}
-?{DR_cifra}+\.{DR_cifra}+    {printf("numero real: %s \n", yytext);}
{DR_hacer}          {printf("hacer: %s \n", yytext);}


{DR_id}             {printf("identificador: %s \n", yytext);}
{DR_composicion_secuencial} {printf("composicion secuencial: %s \n", yytext);}
{DR_tipo_variable}  {printf("tipo variable: %s \n", yytext);}
{DR_asignacion}     {printf("asignacion: %s \n", yytext);}
{DR_separador}      {printf("separador: %s \n", yytext);}
{DR_subrango}       {printf("subrango: %s \n", yytext);}
{DR_entonces}       {printf("entonces: %s \n", yytext);}
{DR_si_no_si}       {printf("si no si: %s \n", yytext);}
{DR_inicio_array}   {printf("inicio array: %s \n", yytext);}
{DR_fin_array}      {printf("fin array: %s \n", yytext);}
{DR_operadores_relacionales}    {printf("operador relacional: %s \n", yytext);}
{DR_inicio_parentesis}    {printf("inicio parentesis: %s \n", yytext);}
{DR_fin_parentesis}    {printf("fin parentesis: %s \n", yytext);}

{DR_caracteres_blancos}+
.   printf("caracter no reconocido: \n");


%%
 /* user code */
int main(int argc, char **argv){
    ++argv, --argc; /* skip over program name */
    if ( argc > 0 )
        yyin = fopen( argv[0], "r" );
    else
        yyin = stdin;
    yylex();
}