%{
%}
number [0-9]+(\.[0-9]+)?([eE][+-]?[0-9]+)?
caracter_blanco [ \t\n]
%%
{number} {printf("numero: %s \n", yytext);}
{caracter_blanco}+     
%%
int yywrap() { return 1; }