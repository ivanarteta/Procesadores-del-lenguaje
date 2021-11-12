%{
/* File: /home/pl/src/precedencia/hoc1/hoc1.y */
#include <stdio.h>
#define YYDEBUG 1
int yyerror(char *s);
int yylex(void);
int yyparse(void);
%}
%token NUMBER
%left '+' '-'
%left '*' '/'
%%
list:
        | list '\n'
        | list expr   
        ;

expr:   NUMBER 
        | expr '+' expr 
        | expr '-' expr 
        | expr '*' expr 
        | expr '/' expr 
        ;
%%

extern FILE * yyin;

int main(int argc, char **argv) {
if (argc > 1) yyin = fopen(argv[1],"r");
    yydebug = 1;
    yyparse();
}

int yyerror(char *s) {
    printf("%s\n",s);
}