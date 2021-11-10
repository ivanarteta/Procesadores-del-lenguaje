%{
#include "y.tab.h"
extern YYSTYPE yylval;
%}
number [0-9]+(\.[0-9]+)?([eE][+-]?[0-9]+)?
%%
{number} { yylval = atof(yytext); return NUMBER; }
.|\n     { return yytext[0];}
%%
int yywrap() { return 1; }