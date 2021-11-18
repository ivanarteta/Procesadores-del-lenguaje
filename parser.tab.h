/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_LITERAL_CADENA = 258,
    TK_LITERAL_CARACTER = 259,
    TK_LITERAL_ENTERO = 260,
    TK_LITERAL_REAL = 261,
    TK_IDENTIFICADOR = 262,
    TK_ACCION = 263,
    TK_ALGORITMO = 264,
    TK_BOOLEANO = 265,
    TK_CADENA = 266,
    TK_CARACTER = 267,
    TK_CONST = 268,
    TK_CONTINUAR = 269,
    TK_DE = 270,
    TK_DEV = 271,
    TK_ENT = 272,
    TK_ENTERO = 273,
    TK_ENT_SAL = 274,
    TK_FACCION = 275,
    TK_FALGORITMO = 276,
    TK_FALSO = 277,
    TK_FCONST = 278,
    TK_FFUNCION = 279,
    TK_FMIENTRAS = 280,
    TK_FPARA = 281,
    TK_FSI = 282,
    TK_FTIPO = 283,
    TK_FTUPLA = 284,
    TK_FUNCION = 285,
    TK_FVAR = 286,
    TK_HACER = 287,
    TK_HASTA = 288,
    TK_MIENTRAS = 289,
    TK_PARA = 290,
    TK_REAL = 291,
    TK_SAL = 292,
    TK_SI = 293,
    TK_TABLA = 294,
    TK_TIPO = 295,
    TK_TUPLA = 296,
    TK_VAR = 297,
    TK_VERDADERO = 298,
    TK_REF = 299,
    TK_COMENTARIO = 300,
    TK_ASIGNACION = 301,
    TK_COMPOSICION_SECUENCIAL = 302,
    TK_SEPARADOR = 303,
    TK_SUBRANGO = 304,
    TK_DEF_TIPO = 305,
    TK_ENTONCES = 306,
    TK_SI_NO_SI = 307,
    TK_FIN_ARRAY = 308,
    TK_INICIO_PARENTESIS = 309,
    TK_FIN_PARENTESIS = 310,
    TK_REFERENCIA = 311,
    TK_INICIO_ARRAY = 312,
    TK_O = 313,
    TK_Y = 314,
    TK_NO = 315,
    TK_OPERADOR_RELACIONAL = 316,
    TK_IGUAL = 317,
    TK_SUMA = 318,
    TK_RESTA = 319,
    TK_MOD = 320,
    TK_DIV = 321,
    TK_MULTIPLICACION = 322,
    TK_DIVISION = 323,
    UMINUS = 324
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "parser.y"

    char* ctype; /* Para las cadenas de caracteres (id, string, ...) */
    int itype; /* Para los números enteros y los booleanos */
    float ftype; /* Para los números reales */   
    /* Para las expresiones */
    struct exp_type{
        int tipo;
        int sitio; //Apuntador para la tabla de simbolos
    }exp_type;

#line 138 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
