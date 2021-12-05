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
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 50 "parser.y"

    #include "cola.h"
    #include "definiciones.h"
    #include "tabla_simbolos.h"

#line 54 "parser.tab.h"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_LITERAL_CADENA = 258,
    TK_LITERAL_CARACTER = 259,
    TK_LITERAL_ENTERO = 260,
    TK_LITERAL_REAL = 261,
    TK_LITERAL_BOOLEANO = 262,
    TK_IDENTIFICADOR = 263,
    TK_ACCION = 264,
    TK_ALGORITMO = 265,
    TK_BOOLEANO = 266,
    TK_CADENA = 267,
    TK_CARACTER = 268,
    TK_CONST = 269,
    TK_CONTINUAR = 270,
    TK_DE = 271,
    TK_DEV = 272,
    TK_ENT = 273,
    TK_ENTERO = 274,
    TK_ENT_SAL = 275,
    TK_FACCION = 276,
    TK_FALGORITMO = 277,
    TK_FALSO = 278,
    TK_FCONST = 279,
    TK_FFUNCION = 280,
    TK_FMIENTRAS = 281,
    TK_FPARA = 282,
    TK_FSI = 283,
    TK_FTIPO = 284,
    TK_FTUPLA = 285,
    TK_FUNCION = 286,
    TK_FVAR = 287,
    TK_HACER = 288,
    TK_HASTA = 289,
    TK_MIENTRAS = 290,
    TK_PARA = 291,
    TK_REAL = 292,
    TK_SAL = 293,
    TK_SI = 294,
    TK_TABLA = 295,
    TK_TIPO = 296,
    TK_TUPLA = 297,
    TK_VAR = 298,
    TK_VERDADERO = 299,
    TK_REF = 300,
    TK_COMENTARIO = 301,
    TK_ASIGNACION = 302,
    TK_COMPOSICION_SECUENCIAL = 303,
    TK_SEPARADOR = 304,
    TK_SUBRANGO = 305,
    TK_DEF_TIPO = 306,
    TK_ENTONCES = 307,
    TK_SI_NO_SI = 308,
    TK_FIN_ARRAY = 309,
    TK_INICIO_PARENTESIS = 310,
    TK_FIN_PARENTESIS = 311,
    TK_OPERADOR_RELACIONAL = 312,
    TK_REFERENCIA = 313,
    TK_INICIO_ARRAY = 314,
    TK_O = 315,
    TK_Y = 316,
    TK_NO = 317,
    TK_IGUAL = 318,
    TK_SUMA = 319,
    TK_RESTA = 320,
    TK_MOD = 321,
    TK_DIV = 322,
    TK_MULTIPLICACION = 323,
    TK_DIVISION = 324,
    UMINUS = 325
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 56 "parser.y"

    char* ctype; /* Para las cadenas de caracteres (id, string, ...) */
    int itype; /* Para los números enteros y los booleanos */
    int btype;
    float ftype; /* Para los números reales */   
    enum enum_tipo_celda celda;
    enum enum_literales literales;
    struct exp_type{
        int tipo;
        int sitio;
        union{
            struct{
                Cola TRUE, FALSE;
            };
        };
    }exp_type;
    struct inst_type{
        Cola siguiente;
    }inst_type;
    struct literales_type{
        int tipo;
        Constante_valor valor;
    }literales_type;

#line 161 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
