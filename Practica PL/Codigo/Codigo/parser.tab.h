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

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_entonces = 258,
    TK_accion = 259,
    TK_algoritmo = 260,
    TK_booleano = 261,
    TK_cadena = 262,
    TK_caracter = 263,
    TK_const = 264,
    TK_continuar = 265,
    TK_de = 266,
    TK_dev = 267,
    TK_ent = 268,
    TK_entero = 269,
    TK_entsal = 270,
    TK_faccion = 271,
    TK_falgoritmo = 272,
    TK_fconst = 273,
    TK_ffuncion = 274,
    TK_fmientras = 275,
    TK_fpara = 276,
    TK_fsi = 277,
    TK_ftipo = 278,
    TK_ftupla = 279,
    TK_funcion = 280,
    TK_fvar = 281,
    TK_hacer = 282,
    TK_mientras = 283,
    TK_para = 284,
    TK_hasta = 285,
    TK_real = 286,
    TK_ref = 287,
    TK_sal = 288,
    TK_si = 289,
    TK_tabla = 290,
    TK_tipo = 291,
    TK_tupla = 292,
    TK_var = 293,
    TK_comentario_pre = 294,
    TK_comentario_post = 295,
    TK_asignacion = 296,
    TK_composicion_secuencial = 297,
    TK_separador = 298,
    TK_subrango = 299,
    TK_definicion = 300,
    TK_si_no_si = 301,
    TK_inicio_array = 302,
    TK_fin_array = 303,
    TK_inicio_parentesis = 304,
    TK_literal_entero = 305,
    TK_literal_caracter = 306,
    TK_literal_cadena = 307,
    TK_literal_real = 308,
    TK_literal_booleano = 309,
    TK_identificador = 310,
    TK_o = 311,
    TK_y = 312,
    TK_comparador = 313,
    TK_igual = 314,
    TK_no = 315,
    TK_op_suma = 316,
    TK_op_resta = 317,
    TK_op_division = 318,
    TK_div = 319,
    TK_op_multiplicador = 320,
    TK_mod = 321,
    TK_fin_parentesis = 322
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "parser.y"

    
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

#line 143 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
