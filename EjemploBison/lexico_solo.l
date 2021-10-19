%{
/* Ejemplo para una pequeña calculadora que permite 
trabajar con numeros enteros y reales con las operaciones
básicas de suma, resta, producto, division y trigonometricas como el seno y el coseno */
#include <stdio.h>
#include <stdlib.h>
int nlines=0;
%}
DIGITO [0-9]
ID [a-zA-Z][a-zA-Z0-9_]*
%%
{DIGITO}+ {printf("Encontrado TKN_NUM_ENTERO: %d",atoi(yytext));}
{DIGITO}+"."{DIGITO}+ {printf("Encontrado TKN_NUM_REAL: %f",atof(yytext));}
"=" {printf("Encontrado TKN_ASIGN: %s",yytext);}
";" {printf("Encontrado TKN_PTOCOMA: %s",yytext);}
"*" {printf("Encontrado TKN_MULT: %s",yytext);}
"/" {printf("Encontrado TKN_DIV: %s",yytext);}
"+" {printf("Encontrado TKN_MAS: %s",yytext);}
"-" {printf("Encontrado TKN_MENOS: %s",yytext);}
"(" {printf("Encontrado TKN_PAA: %s",yytext);}
")" {printf("Encontrado TKN_PAC: %s",yytext);}
"cos" {printf("Encontrado TKN_COS: %s",yytext);}
"sen" {printf("Encontrado TKN_SEN: %s",yytext);}
{ID} {printf("Encontrado TKN_ID: %s",yytext);}
"\n" {nlines++;}
.
%%
void main(int argc,char **argv)
{
if (argc>1)
 yyin=fopen(argv[1],"rt");
else
 yyin=stdin;
yylex();
printf("\nNumero lineas analizadas: %d\n", nlines);
}
/* para compilar 
flex lexico.l
cc lex.yy.c -o milex -lfl -lm
*/
