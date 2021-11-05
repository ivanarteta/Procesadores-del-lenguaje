%{
	#include <math.h>
	#include "parser.tab.h"
	#include "tablaCuadruplas.h"
	#include "tablaSimbolos.h"
	extern YYSTYPE yylval;
	#include <string.h>
%}

DR_LITERAL_ENTERO {DR_CIFRA}+((e|E){DR_CIFRA}+)?
DR_LITERAL_REAL {DR_LITERAL_ENTERO}+(\.{DR_CIFRA}+)?((e|E){DR_CIFRA}+)?
DR_LITERAL_BOOLEANO (?i:verdadero)|(?i:falso)  

DR_ACCION (?i:accion)
DR_ALGORITMO (?i:algoritmo)
DR_CADENA (?i:cadena)
DR_CARACTER (?i:caracter)
DR_CONST (?i:const)
DR_CONTINUAR (?i:continuar)
DR_DE (?i:de)
DR_DEV (?i:dev)
DR_DIV (?i:div)
DR_ENT (?i:ent)
DR_FACCION (?i:faccion)
DR_FALGORITMO (?i:falgoritmo)
DR_FALSO (?i:falso)
DR_FCONST (?i:fconst)
DR_FFUNCION (?i:ffuncion)
DR_FMIENTRAS (?i:fmientras)
DR_FPARA (?i:fpara)
DR_FSI (?i:fsi)
DR_FTIPO (?i:ftipo)
DR_FTUPLA (?i:ftupla)
DR_FUNCION (?i:funcion)
DR_FVAR (?i:fvar)
DR_HACER (?i:hacer)
DR_HASTA (?i:hasta)
DR_MIENTRAS (?i:mientras)
DR_MOD (?i:mod)
DR_NO (?i:no)
DR_O (?i:o)
DR_PARA (?i:para)
DR_REAL (?i:real)
DR_ENTERO(?:entero)
DR_BOOLEANO(?:booleano)
DR_REF (?i:ref)
DR_SAL (?i:sal)
DR_SI (?i:si)
DR_TABLA (?i:tabla)
DR_TIPO (?i:tipo)
DR_TUPLA (?i:tupla)
DR_VAR (?i:var)
DR_Y (?i:y)

DR_CIFRA [0-9] 
DR_LETRA_O_CIFRA [A-Z|a-z|0-9]
DR_LIT_CADENA '([^/']|\/')*'
DR_COMENTARIO "{"[^}\n]*"}"

DR_LITERAL_CARACTER "CIFRA_O_LETRA" 
DR_IDENTIFICADOR [A-Za-z][(A-Z|a-z)|0-9]*

DR_SUMA "+"
DR_RESTA "-"
DR_MULTI "*"
DR_DIVI "/"
DR_DISTINTO "<>"
DR_MAYOR_IGUAL ">="
DR_MENOR_IGUAL "<="
DR_COMPARADOR_MENOR "<"
DR_COMPARADOR_MAYOR ">"
DR_ABRIR_PARENTESIS "("
DR_CERRAR_PARENTESIS ")"
DR_ASIGNACION ":="
DR_COMP_SEC ";"
DR_SEPARADOR ","
DR_SUBRANGO ".."
DR_DEF_VARIABLE ":"
DR_ENTONCES "->"
DR_CREACION_TIPO "="
DR_ELSE "[]"
DR_INICIO_ARRAY "["
DR_FIN_ARRAY "]"
DR_ACCESO "."



%%
{DR_ACCION} {
						printf("Una accion: %s\n", yytext);
						return(TK_ACCION);
                  }
{DR_ALGORITMO} {
						printf("Un algoritmo: %s\n", yytext);
												return(TK_ALGORITMO);

                  }
{DR_CADENA} {
						printf("Una cadena: %s\n", yytext);
						yylval.ival = TCADENA; 
												return(TK_CADENA);

                  }
{DR_CARACTER} {
						printf("Un caracter: %s\n", yytext);
						yylval.ival = TCARACTER; 
												return(TK_CARACTER);

                  }
{DR_CONST} {
						printf("Un const: %s\n", yytext);
												return(TK_CONST);

                  }
{DR_CONTINUAR} {
						printf("Un continuar: %s\n", yytext);
												return(TK_CONTINUAR);

                  }
{DR_DE} {
						printf("Un de: %s\n", yytext);
												return(TK_DE);

                  }
{DR_DEV} {
						printf("Un dev: %s\n", yytext);
												return(TK_DEV);

                  }
{DR_DIV} {
						printf("Un div: %s\n", yytext);
												return(TK_DIV);

                  }
{DR_ENT} {
						printf("Un ent: %s\n", yytext);
												return(TK_ENT);

                  }
{DR_ENTERO} {
						printf("Un entero: %s\n", yytext);
						yylval.ival = TENTERO;
						return(TK_ENTERO);

                  }
{DR_BOOLEANO} {
						printf("Un booleano: %s\n", yytext);
						yylval.ival = TBOOLEANO;
												return(TK_BOOLEANO);

                  }
{DR_FACCION} {
						printf("Un fin de accion: %s\n", yytext);
												return(TK_FACCION);

                  }
{DR_FALGORITMO} {
						printf("Un fin de algoritmo: %s\n", yytext);
												return(TK_FALGORITMO);

                  }
{DR_FCONST} {
						printf("Un fin de const: %s\n", yytext);
												return(TK_FCONST);

                  }
{DR_FFUNCION} {
						printf("Un fin de funcion: %s\n", yytext);
												return(TK_FFUNCION);

                  }
{DR_FMIENTRAS} {
						printf("Un fin de mientras: %s\n", yytext);
												return(TK_FMIENTRAS);

                  }
{DR_FPARA} {
						printf("Un fin de para: %s\n", yytext);
												return(TK_FPARA);

                  }
{DR_FSI} {
						printf("Un fin de si: %s\n", yytext);
												return(TK_FSI);

                  }
{DR_FTIPO} {
						printf("Un fin de tipo: %s\n", yytext);
												return(TK_FTIPO);

                  }
{DR_FTUPLA} {
						printf("Un fin de tupla: %s\n", yytext);
												return(TK_FTUPLA);

                  }
{DR_FUNCION} {
						printf("Una funcion: %s\n", yytext);
												return(TK_FUNCION);

                  }
{DR_FVAR} {
						printf("Un fin de var: %s\n", yytext);
												return(TK_FVAR);

                  }
{DR_HACER} {
						printf("Un hacer: %s\n", yytext);
												return(TK_HACER);

                  }
{DR_HASTA} {
						printf("Un hasta: %s\n", yytext);
												return(TK_HASTA);

                  }
{DR_MIENTRAS} {
						printf("Un mientras: %s\n", yytext);
												return(TK_MIENTRAS);

                  }
{DR_MOD} {
						printf("Un mod: %s\n", yytext);
												return(TK_MOD);

                  }
{DR_NO} {
						printf("Un no: %s\n", yytext);
												return(TK_NO);

                  }
{DR_O} {
						printf("Un o: %s \n", yytext);
												return(TK_O);

                  }
{DR_PARA} {
						printf("Un para: %s\n", yytext);
												return(TK_PARA);

                  }
{DR_REAL} {
						printf("Un real: %s\n", yytext);
						yylval.ival = TREAL;
						return(TK_REAL);

                  }
{DR_REF} {
						printf("Un ref: %s \n", yytext);
						return(TK_REF);

                  }
{DR_SAL} {
						printf("Un sal: %s\n", yytext);
												return(TK_SAL);

                  }
{DR_SI} {
						printf("Un si: %s\n", yytext);
												return(TK_SI);

                  }
{DR_TABLA} {
						printf("Una tabla: %s\n", yytext);
												return(TK_TABLA);

                  }
{DR_TIPO} {
						printf("Un tipo: %s\n", yytext);
												return(TK_TIPO);

                  }
{DR_TUPLA} {
						printf("Una tupla: %s\n", yytext);
												return(TK_TUPLA);

                  }
{DR_VAR} {
						printf("Un var: %s\n", yytext);
												return(TK_VAR);

                  }
{DR_Y} {
						printf("Una y: %s\n", yytext);
												return(TK_Y);

                  }
{DR_LIT_CADENA} {
						printf("Un literal cadena: %s\n", yytext);
												return(TK_LIT_CADENA);

                  }
{DR_COMENTARIO} {
						printf("Un comentario \n");
												return(TK_COMENTARIO);

                  }

{DR_LITERAL_CARACTER} {
						printf("Un literal ca: %s\n", yytext);
						yylval.sval = strdup(yytext);
						return(TK_LITERAL_CARACTER);

                  }
{DR_IDENTIFICADOR} {
						printf("Un identificador: %s\n", yytext);
						yylval.sval = (char*)malloc(sizeof(strlen(yytext)));
						strcpy(yylval.sval,yytext);
						return(TK_IDENTIFICADOR);

                  }
{DR_LITERAL_ENTERO} {
						printf("Un entero: %s(%d)\n", yytext,
                               (int)atof(yytext));
                        yylval.ival=(int)atof(yytext);
                        return(TK_LITERAL_ENTERO);
                    }
{DR_LITERAL_REAL} {
						printf("Un literal real: %s(%g)\n", yytext,
                               atof(yytext));
                        yylval.fval=atof(yytext);
                        return(TK_LITERAL_REAL);
                  }
{DR_LITERAL_BOOLEANO} {
						printf("Un literal booleano: %s\n", yytext);
						yylval.sval = strdup(yytext);
						return(TK_LITERAL_BOOLEANO);
						
					}



{DR_SUMA} {
						printf("Un operador suma: %s\n", yytext);
												return(TK_SUMA);

                  }
{DR_RESTA} {
						printf("Una resta: %s\n", yytext);
												return(TK_RESTA);

                  }
{DR_MULTI} {
						printf("Una multiplicacion: %s\n", yytext);
												return(TK_MULTI);

                  }
{DR_DIVI} {
						printf("Una division: %s\n", yytext);
												return(TK_DIVI);

                  }
{DR_COMPARADOR_MENOR} {
						printf("Un comparador menor: %s\n", yytext);
												return(TK_COMPARADOR_MENOR);

                  }
{DR_COMPARADOR_MAYOR} {
						printf("Un comparador mayor: %s\n", yytext);
												return(TK_COMPARADOR_MAYOR);

                  }
{DR_ABRIR_PARENTESIS} {
						printf("Un abrir parentesis: %s\n", yytext);
												return(TK_ABRIR_PARENTESIS);

                  }
{DR_CERRAR_PARENTESIS} {
						printf("Un cerrar parentesis: %s\n", yytext);
												return(TK_CERRAR_PARENTESIS);

                  }
{DR_ASIGNACION} {
						printf("Una asignacion: %s\n", yytext);
												return(TK_ASIGNACION);

                  }
{DR_COMP_SEC} {
						printf("Un comparador secuencial: %s\n", yytext);
												return(TK_COMP_SEC);

                  }
{DR_SEPARADOR} {
						printf("Un separador: %s\n", yytext);
												return(TK_SEPARADOR);

                  }
{DR_SUBRANGO} {
						printf("Un subrango: %s\n", yytext);
						yylval.sval = strdup(yytext);
												return(TK_SUBRANGO);

                  }
{DR_DEF_VARIABLE} {
						printf("Una definicion de variable: %s\n", yytext);
												return(TK_DEF_VARIABLE);

                  }
{DR_ENTONCES} {
						printf("Un entonces: %s\n", yytext);
												return(TK_ENTONCES);

                  }
{DR_CREACION_TIPO} {
						printf("Un creacion de tipo: %s\n", yytext);
												return(TK_CREACION_TIPO);

                  }
{DR_INICIO_ARRAY} {
						printf("Un inicio de array: %s\n", yytext);
						return(TK_INICIO_ARRAY);

                  }
{DR_FIN_ARRAY} {
						printf("Un fin de array: %s\n", yytext);
												return(TK_FIN_ARRAY);

                  }
{DR_ACCESO} {
						printf("Un acceso: %s\n", yytext);
						return(TK_ACCESO);
                  }
{DR_DISTINTO} {
						printf("Un distinto que: %s\n", yytext);
						return(TK_DISTINTO);
                  }
{DR_MAYOR_IGUAL} {
						printf("Un mayor o igual: que %s\n", yytext);
						return(TK_MAYOR_IGUAL);
                  }
{DR_MENOR_IGUAL} {
						printf("Un menor o igual que: %s\n", yytext);
						return(TK_MENOR_IGUAL);
                  }
{DR_ELSE} {
						printf("Un else: %s\n", yytext);
						return(TK_ELSE);
                  }

%%

