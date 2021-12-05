/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include "pila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tabla_cuadruplas.h"
#include "tabla_simbolos.h"
#include "codigo_tres_direcciones.h"

#define YYDEBUG 1
void errores_parser(int);
void yyerror(char *s);
int yylex(void);
int yyparse(void);

int separar_cadena(char *);
extern FILE * yyin;

#define ROJO "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET "\x1b[0m"
#define RESET_COLOR    "\x1b[0m"
#define NEGRO_T        "\x1b[30m"
#define NEGRO_F        "\x1b[40m"
#define ROJO_T     "\x1b[31m"
#define ROJO_F     "\x1b[41m"
#define VERDE_T        "\x1b[32m"
#define VERDE_F        "\x1b[42m"
#define AMARILLO_T "\x1b[33m"
#define    AMARILLO_F  "\x1b[43m"
#define AZUL_T     "\x1b[34m"
#define    AZUL_F      "\x1b[44m"
#define MAGENTA_T  "\x1b[35m"
#define MAGENTA_F  "\x1b[45m"
#define CYAN_T     "\x1b[36m"
#define CYAN_F     "\x1b[46m"
#define BLANCO_T   "\x1b[37m"
#define BLANCO_F   "\x1b[47m"

TS_lista simbolos;
TC_tabla_cuadrupla cuadrupla;
tipoPila pila;


#line 119 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 168 "parser.tab.c"

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

#line 275 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   263

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  241

#define YYUNDEFTOK  2
#define YYMAXUTOK   325


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   168,   168,   170,   172,   174,   175,   176,   178,   179,
     180,   182,   184,   185,   186,   187,   190,   192,   194,   197,
     198,   200,   201,   202,   203,   204,   205,   207,   208,   209,
     210,   211,   213,   214,   216,   217,   220,   226,   228,   229,
     230,   231,   232,   235,   236,   238,   245,   254,   255,   256,
     258,   266,   276,   283,   290,   294,   321,   348,   376,   389,
     402,   429,   435,   441,   456,   464,   474,   513,   557,   582,
     598,   644,   681,   704,   730,   731,   732,   735,   737,   740,
     745,   751,   752,   756,   760,   764,   766,   824,   831,   837,
     839,   843,   848,   862,   907,   909,   911,   913,   915,   916,
     919,   920,   921,   923,   925,   927,   928,   929
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_LITERAL_CADENA",
  "TK_LITERAL_CARACTER", "TK_LITERAL_ENTERO", "TK_LITERAL_REAL",
  "TK_LITERAL_BOOLEANO", "TK_IDENTIFICADOR", "TK_ACCION", "TK_ALGORITMO",
  "TK_BOOLEANO", "TK_CADENA", "TK_CARACTER", "TK_CONST", "TK_CONTINUAR",
  "TK_DE", "TK_DEV", "TK_ENT", "TK_ENTERO", "TK_ENT_SAL", "TK_FACCION",
  "TK_FALGORITMO", "TK_FALSO", "TK_FCONST", "TK_FFUNCION", "TK_FMIENTRAS",
  "TK_FPARA", "TK_FSI", "TK_FTIPO", "TK_FTUPLA", "TK_FUNCION", "TK_FVAR",
  "TK_HACER", "TK_HASTA", "TK_MIENTRAS", "TK_PARA", "TK_REAL", "TK_SAL",
  "TK_SI", "TK_TABLA", "TK_TIPO", "TK_TUPLA", "TK_VAR", "TK_VERDADERO",
  "TK_REF", "TK_COMENTARIO", "TK_ASIGNACION", "TK_COMPOSICION_SECUENCIAL",
  "TK_SEPARADOR", "TK_SUBRANGO", "TK_DEF_TIPO", "TK_ENTONCES",
  "TK_SI_NO_SI", "TK_FIN_ARRAY", "TK_INICIO_PARENTESIS",
  "TK_FIN_PARENTESIS", "TK_OPERADOR_RELACIONAL", "TK_REFERENCIA",
  "TK_INICIO_ARRAY", "TK_O", "TK_Y", "TK_NO", "TK_IGUAL", "TK_SUMA",
  "TK_RESTA", "TK_MOD", "TK_DIV", "TK_MULTIPLICACION", "TK_DIVISION",
  "UMINUS", "$accept", "descripcion_algoritmo", "cabecera_algoritmo",
  "bloque_algoritmo", "definiciones_globales",
  "definiciones_acciones_funciones", "bloque", "declaraciones",
  "definicion_tipo", "definicion_const", "definicion_var",
  "lista_definiciones_tipo", "def_tipo", "tipo_base", "expresion_tabla",
  "lista_campos", "lista_definiciones_const", "tipo_literal",
  "lista_definiciones_var", "lista_id",
  "definiciones_variables_interaccion", "definicion_entrada",
  "definicion_salida", "expresion", "expresion_aritmetica",
  "expresion_booleana", "operando", "M", "N", "instrucciones",
  "instruccion", "asignacion", "alternativa", "lista_opciones",
  "iteracion", "it_cota_variable", "it_cota_fija", "definicion_accion",
  "definicion_funcion", "cabecera_accion", "cabecera_funcion",
  "defParForm", "dParForm", "llamada_funcion", "llamada_accion",
  "parametros_reales", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325
};
# endif

#define YYPACT_NINF (-186)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,    38,    84,    39,  -186,    10,    94,   105,    28,    23,
      10,    10,    53,    97,    60,    96,   127,   126,   114,   102,
      28,    28,    28,   143,   154,    65,    23,    23,  -186,  -186,
     191,  -186,   107,  -186,   -10,   137,   119,  -186,  -186,   113,
    -186,  -186,   162,    20,   -11,  -186,   130,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,   125,    28,   128,    28,
     127,   127,   138,   147,  -186,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,   158,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
    -186,   122,   207,   107,   168,  -186,   167,   127,   107,  -186,
     127,    20,   101,   176,  -186,  -186,  -186,   169,   101,   101,
      59,   173,   136,   -30,    32,  -186,  -186,    20,   218,    20,
    -186,    54,   206,   127,   211,  -186,  -186,  -186,  -186,    94,
      90,   178,   200,  -186,   105,    90,  -186,  -186,  -186,   182,
     177,  -186,   136,    37,    20,    20,   108,   -23,  -186,    59,
    -186,  -186,    59,    59,    59,    59,    59,    59,    59,    59,
    -186,  -186,  -186,   -16,   180,   102,   127,   127,   127,   179,
     184,  -186,   181,    20,  -186,   186,   107,  -186,  -186,  -186,
      20,  -186,  -186,   204,   183,  -186,  -186,   123,   102,   145,
     145,   153,   153,    64,    74,  -186,  -186,   101,   101,  -186,
    -186,   189,   190,   192,   194,    54,   227,   220,    90,   198,
    -186,   102,    20,  -186,  -186,   187,  -186,   107,   107,   107,
    -186,  -186,   208,  -186,   193,   207,   224,   219,   201,  -186,
    -186,  -186,   203,   237,  -186,  -186,   102,    20,   228,  -186,
     107,   230,   209,  -186,  -186,  -186,  -186,   102,  -186,   201,
    -186
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     7,    37,    20,    15,    10,
       7,     7,     0,     0,     0,     0,    44,     0,     0,     0,
      15,    15,    15,     0,     0,     0,    10,    10,     5,     6,
       0,    17,     0,    16,     0,     0,     0,     2,     4,    73,
      81,    77,     0,     0,     0,    11,    80,    82,    83,    84,
      91,    90,    85,    12,    13,    14,     0,    15,     0,    15,
      44,    44,     0,    47,    49,     8,     9,    38,    39,    40,
      41,    42,     0,    33,    32,    23,    28,    31,    29,    27,
      30,     0,    35,     0,     0,    26,     0,     0,     0,    18,
      44,   107,     0,     0,    64,    65,    69,    73,     0,     0,
       0,     0,    52,    53,    62,    54,    76,     0,     0,     0,
      77,    99,     0,    44,     0,    50,    51,     3,    48,    37,
       0,     0,     0,    25,    20,     0,    45,    46,    43,   106,
       0,    73,     0,     0,     0,   107,     0,     0,    68,     0,
      63,    77,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    77,    86,    74,     0,     0,     0,     0,     0,     0,
       0,    94,     0,     0,    36,     0,     0,    21,    19,    24,
     107,   104,    78,     0,     0,    61,    72,     0,     0,    70,
      71,    55,    56,    59,    58,    60,    57,     0,     0,    75,
      79,     0,     0,     0,     0,    99,     0,     0,     0,     0,
     105,     0,     0,   103,    78,    67,    66,     0,     0,     0,
      96,    98,     0,    95,     0,    35,     0,     0,    89,   100,
     102,   101,     0,     0,    34,    92,     0,     0,     0,    97,
       0,     0,     0,    87,    22,    93,    77,     0,    78,    89,
      88
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -186,  -186,  -186,  -186,   135,   131,    19,   133,    -4,   129,
    -186,   134,   -80,  -186,  -102,    40,   140,  -186,   -40,   -77,
    -186,  -186,   197,   -41,   -87,   -83,   -19,  -106,  -185,  -138,
    -186,  -186,  -186,    24,  -186,  -186,  -186,  -186,  -186,  -186,
    -186,    67,  -186,  -186,  -186,  -121
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,    17,     9,    25,    18,    19,    20,    21,
      22,    15,    84,    85,    86,   122,    13,    72,    35,    36,
      62,    63,    64,   129,   102,   103,   104,    92,   201,    45,
      46,    47,    48,   228,    49,    50,    51,    26,    27,    57,
      59,   159,   160,   105,    52,   130
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      44,    10,   101,   123,   155,   132,    10,    10,   127,   133,
     126,   136,   132,   140,   174,   137,   138,   190,   165,   218,
     115,   116,     1,   169,     6,    94,    95,    96,    97,   106,
     150,   151,    23,   176,   106,   178,   107,   150,   151,    87,
     204,    88,     6,   109,   187,   188,     3,   108,   109,   200,
     128,     7,   177,   239,    24,   179,   180,   181,   182,   183,
     184,   185,   186,   216,    94,    95,   152,   131,   154,     7,
     172,    16,   156,   162,   157,    98,   112,   106,   114,   191,
     192,   193,    99,    60,     4,   100,   199,     5,   231,   153,
     108,   109,   158,   173,    73,    74,   214,   150,   151,   238,
     132,   132,    12,    61,   205,   206,    94,    95,    96,   131,
      39,    73,    74,    14,   139,    75,    30,    40,    76,    77,
      78,    31,   197,    32,   100,    33,    79,   219,   220,   221,
     237,   147,   148,   149,    11,    34,    44,    41,    42,    11,
      11,    43,   148,   149,    80,    28,    29,    81,    37,    82,
     234,    56,    83,    53,    54,    55,    98,    65,    66,    44,
      38,   217,    58,    99,   175,   142,   100,    90,    91,    89,
      93,   143,   144,   145,   146,   147,   148,   149,   110,   175,
     111,   120,    44,   113,   117,    61,   232,   144,   145,   146,
     147,   148,   149,   142,    67,    68,    69,    70,    71,   143,
     144,   145,   146,   147,   148,   149,   119,    44,   222,   144,
     145,   146,   147,   148,   149,   121,   124,   125,    44,   146,
     147,   148,   149,   134,   135,   141,   131,   161,   163,   166,
     167,   170,   195,   171,   189,   194,   198,   196,   202,   203,
     207,   208,   210,   209,   212,   213,   215,   223,   151,     7,
     225,   229,   226,   230,   227,   224,   233,   235,   168,   164,
     118,   236,   211,   240
};

static const yytype_uint8 yycheck[] =
{
      19,     5,    43,    83,   110,    92,    10,    11,    88,    92,
      87,    98,    99,   100,   135,    98,    99,   155,   120,   204,
      60,    61,    10,   125,    14,     5,     6,     7,     8,    45,
      60,    61,     9,    56,    45,   141,    47,    60,    61,    49,
     178,    51,    14,    59,   150,   151,     8,    58,    59,   170,
      90,    41,   139,   238,    31,   142,   143,   144,   145,   146,
     147,   148,   149,   201,     5,     6,   107,     8,   109,    41,
      33,    43,    18,   113,    20,    55,    57,    45,    59,   156,
     157,   158,    62,    18,     0,    65,   166,    48,   226,   108,
      58,    59,    38,   134,     4,     5,   198,    60,    61,   237,
     187,   188,     8,    38,   187,   188,     5,     6,     7,     8,
       8,     4,     5,     8,    55,     8,    63,    15,    11,    12,
      13,    24,   163,    63,    65,    29,    19,   207,   208,   209,
     236,    67,    68,    69,     5,     8,   155,    35,    36,    10,
      11,    39,    68,    69,    37,    10,    11,    40,    22,    42,
     230,     8,    45,    20,    21,    22,    55,    26,    27,   178,
      46,   202,     8,    62,    56,    57,    65,    48,    55,    32,
       8,    63,    64,    65,    66,    67,    68,    69,    48,    56,
      55,    59,   201,    55,    46,    38,   227,    64,    65,    66,
      67,    68,    69,    57,     3,     4,     5,     6,     7,    63,
      64,    65,    66,    67,    68,    69,    48,   226,   212,    64,
      65,    66,    67,    68,    69,     8,    48,    50,   237,    66,
      67,    68,    69,    47,    55,    52,     8,    21,    17,    51,
      30,    49,    48,    56,    54,    56,    50,    56,    34,    56,
      51,    51,    48,    51,    17,    25,    48,    54,    61,    41,
      26,    48,    33,    16,    53,   215,    28,    27,   124,   119,
      63,    52,   195,   239
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    72,     8,     0,    48,    14,    41,    73,    75,
      79,    80,     8,    87,     8,    82,    43,    74,    77,    78,
      79,    80,    81,     9,    31,    76,   108,   109,    75,    75,
      63,    24,    63,    29,     8,    89,    90,    22,    46,     8,
      15,    35,    36,    39,    97,   100,   101,   102,   103,   105,
     106,   107,   115,    78,    78,    78,     8,   110,     8,   111,
      18,    38,    91,    92,    93,    76,    76,     3,     4,     5,
       6,     7,    88,     4,     5,     8,    11,    12,    13,    19,
      37,    40,    42,    45,    83,    84,    85,    49,    51,    32,
      48,    55,    98,     8,     5,     6,     7,     8,    55,    62,
      65,    94,    95,    96,    97,   114,    45,    47,    58,    59,
      48,    55,    77,    55,    77,    89,    89,    46,    93,    48,
      59,     8,    86,    83,    48,    50,    90,    83,    89,    94,
     116,     8,    95,    96,    47,    55,    95,    96,    96,    55,
      95,    52,    57,    63,    64,    65,    66,    67,    68,    69,
      60,    61,    94,    97,    94,    98,    18,    20,    38,   112,
     113,    21,    89,    17,    87,    85,    51,    30,    82,    85,
      49,    56,    33,    94,   116,    56,    56,    95,    98,    95,
      95,    95,    95,    95,    95,    95,    95,    98,    98,    54,
     100,    90,    90,    90,    56,    48,    56,    94,    50,    83,
     116,    99,    34,    56,   100,    96,    96,    51,    51,    51,
      48,   112,    17,    25,    85,    48,   100,    94,    99,    83,
      83,    83,    79,    54,    86,    26,    33,    53,   104,    48,
      16,   100,    94,    28,    83,    27,    52,    98,   100,    99,
     104
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    71,    72,    73,    74,    75,    75,    75,    76,    76,
      76,    77,    78,    78,    78,    78,    79,    80,    81,    82,
      82,    83,    83,    83,    83,    83,    83,    84,    84,    84,
      84,    84,    85,    85,    86,    86,    87,    87,    88,    88,
      88,    88,    88,    89,    89,    90,    90,    91,    91,    91,
      92,    93,    94,    94,    94,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    96,    96,    96,    96,
      96,    96,    96,    97,    97,    97,    97,    98,    99,   100,
     100,   101,   101,   101,   101,   101,   102,   103,   104,   104,
     105,   105,   106,   107,   108,   109,   110,   111,   112,   112,
     113,   113,   113,   114,   115,   116,   116,   116
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     4,     2,     2,     2,     0,     2,     2,
       0,     2,     2,     2,     2,     0,     3,     3,     3,     5,
       0,     3,     8,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     0,     5,     0,     1,     1,
       1,     1,     1,     3,     0,     3,     3,     1,     2,     1,
       2,     2,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     1,     2,     1,     1,     4,     4,     2,     1,
       3,     3,     3,     1,     3,     4,     2,     0,     0,     4,
       1,     1,     1,     1,     1,     1,     3,     8,     7,     0,
       1,     1,     7,     9,     4,     6,     5,     7,     3,     0,
       4,     4,     4,     4,     4,     3,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 21:
#line 200 "parser.y"
                                            {}
#line 1641 "parser.tab.c"
    break;

  case 22:
#line 201 "parser.y"
                                                                                                               {}
#line 1647 "parser.tab.c"
    break;

  case 23:
#line 202 "parser.y"
                               {}
#line 1653 "parser.tab.c"
    break;

  case 24:
#line 203 "parser.y"
                                                          {}
#line 1659 "parser.tab.c"
    break;

  case 25:
#line 204 "parser.y"
                              {}
#line 1665 "parser.tab.c"
    break;

  case 26:
#line 205 "parser.y"
                        {}
#line 1671 "parser.tab.c"
    break;

  case 27:
#line 207 "parser.y"
                      {(yyval.celda) = TIPO_ENTERO;}
#line 1677 "parser.tab.c"
    break;

  case 28:
#line 208 "parser.y"
                          {(yyval.celda) = TIPO_BOOLEANO;}
#line 1683 "parser.tab.c"
    break;

  case 29:
#line 209 "parser.y"
                          {(yyval.celda) = TIPO_CARACTER;}
#line 1689 "parser.tab.c"
    break;

  case 30:
#line 210 "parser.y"
                      {(yyval.celda) = TIPO_REAL;}
#line 1695 "parser.tab.c"
    break;

  case 31:
#line 211 "parser.y"
                        {(yyval.celda) = TIPO_CADENA;}
#line 1701 "parser.tab.c"
    break;

  case 36:
#line 221 "parser.y"
                                {   
                                    int id = TS_insertar(&simbolos, (yyvsp[-4].ctype));   
                                    TS_modificar_tipo(&simbolos, id, (yyvsp[-2].literales_type).tipo, TS_CONSTANTE);
                                    TS_modificar_valor_cte(&simbolos, id, (yyvsp[-2].literales_type).valor);
                                }
#line 1711 "parser.tab.c"
    break;

  case 38:
#line 228 "parser.y"
                                  {(yyval.literales_type).tipo = TIPO_CADENA; (yyval.literales_type).valor.caracteres = (yyvsp[0].literales_type).valor.caracteres;}
#line 1717 "parser.tab.c"
    break;

  case 39:
#line 229 "parser.y"
                                      {(yyval.literales_type).tipo = TIPO_CARACTER; (yyval.literales_type).valor.caracteres = (yyvsp[0].literales_type).valor.caracteres;}
#line 1723 "parser.tab.c"
    break;

  case 40:
#line 230 "parser.y"
                                    {(yyval.literales_type).tipo = TIPO_ENTERO; (yyval.literales_type).valor.entero = (yyvsp[0].literales_type).valor.entero;}
#line 1729 "parser.tab.c"
    break;

  case 41:
#line 231 "parser.y"
                                  {(yyval.literales_type).tipo = TIPO_REAL; (yyval.literales_type).valor.real = (yyvsp[0].literales_type).valor.real;}
#line 1735 "parser.tab.c"
    break;

  case 42:
#line 232 "parser.y"
                                      {(yyval.literales_type).tipo = TIPO_BOOLEANO; (yyval.literales_type).valor.entero = (yyvsp[0].literales_type).valor.entero;}
#line 1741 "parser.tab.c"
    break;

  case 45:
#line 239 "parser.y"
                {  
                    int id = TS_insertar(&simbolos, (yyvsp[-2].ctype));
                    TS_modificar_tipo(&simbolos, id, (yyvsp[0].itype), TS_VAR);
                    apilar(&pila, id);
                    (yyval.itype)=(yyvsp[0].itype);
                }
#line 1752 "parser.tab.c"
    break;

  case 46:
#line 246 "parser.y"
                {
                    int id = TS_insertar(&simbolos, (yyvsp[-2].ctype));
                    TS_modificar_tipo(&simbolos, id, (yyvsp[0].itype), TS_VAR);
                    apilar(&pila, id);
                    (yyval.itype) = (yyvsp[0].itype);
                }
#line 1763 "parser.tab.c"
    break;

  case 50:
#line 259 "parser.y"
                        {
                            while(!esNulaPila(pila)){
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_INPUT, cima(pila), -1, -1));
                                desapilar(&pila);
                            }
                        }
#line 1774 "parser.tab.c"
    break;

  case 51:
#line 267 "parser.y"
                        {
                            while(!esNulaPila(pila)){
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_OUTPUT, cima(pila), -1, -1));
                                desapilar(&pila);
                            }
                        }
#line 1785 "parser.tab.c"
    break;

  case 52:
#line 277 "parser.y"
                {
                    (yyval.exp_type).sitio = (yyvsp[0].exp_type).sitio;
                    (yyval.exp_type).tipo = (yyvsp[0].exp_type).tipo;
                    (yyval.exp_type).TRUE = (yyvsp[0].exp_type).TRUE;
                    (yyval.exp_type).FALSE = (yyvsp[0].exp_type).FALSE;
                }
#line 1796 "parser.tab.c"
    break;

  case 53:
#line 284 "parser.y"
                {
                    (yyval.exp_type).sitio = (yyvsp[0].exp_type).sitio; 
                    (yyval.exp_type).TRUE = (yyvsp[0].exp_type).TRUE;
                    (yyval.exp_type).FALSE = (yyvsp[0].exp_type).FALSE;
                    (yyval.exp_type).tipo = (yyvsp[0].exp_type).tipo;
                }
#line 1807 "parser.tab.c"
    break;

  case 54:
#line 290 "parser.y"
                              {}
#line 1813 "parser.tab.c"
    break;

  case 55:
#line 295 "parser.y"
                            {
                                int nueva = TS_newtempt(&simbolos);
                                if(((yyvsp[-2].exp_type).tipo == TIPO_ENTERO) && ((yyvsp[0].exp_type).tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_ENTERO, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_SUMA, (yyvsp[-2].exp_type).sitio, (yyvsp[0].exp_type).sitio, nueva));
                                    (yyval.exp_type).tipo = TIPO_ENTERO;
                                }else if(((yyvsp[-2].exp_type).tipo == TIPO_REAL) && ((yyvsp[0].exp_type).tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, (yyvsp[0].exp_type).sitio, -1, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_SUMA, nueva, (yyvsp[-2].exp_type).sitio, nueva));
                                    (yyval.exp_type).tipo = TIPO_REAL;
                                }else if(((yyvsp[-2].exp_type).tipo == TIPO_ENTERO) && ((yyvsp[0].exp_type).tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, (yyvsp[-2].exp_type).sitio, -1, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_SUMA, nueva, (yyvsp[0].exp_type).sitio, nueva));
                                    (yyval.exp_type).tipo = TIPO_REAL;
                                }else if(((yyvsp[-2].exp_type).tipo == TIPO_REAL) && ((yyvsp[0].exp_type).tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_SUMA, (yyvsp[-2].exp_type).sitio, (yyvsp[0].exp_type).sitio, nueva));
                                    (yyval.exp_type).tipo = TIPO_REAL;
                                }else{
                                    printf("%d y %d \n", (yyvsp[-2].exp_type).tipo, (yyvsp[0].exp_type).tipo);
                                    errores_parser(ERROR_TIPO);
                                }
                                (yyval.exp_type).sitio = nueva;
                            }
#line 1844 "parser.tab.c"
    break;

  case 56:
#line 322 "parser.y"
                            {
                                int nueva = TS_newtempt(&simbolos);
                                if(((yyvsp[-2].exp_type).tipo == TIPO_ENTERO) && ((yyvsp[0].exp_type).tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_ENTERO, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_RESTA, (yyvsp[-2].exp_type).sitio, (yyvsp[0].exp_type).sitio, nueva));
                                    (yyval.exp_type).tipo = TIPO_ENTERO;
                                }else if(((yyvsp[-2].exp_type).tipo == TIPO_REAL) && ((yyvsp[0].exp_type).tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, (yyvsp[0].exp_type).sitio, -1, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_RESTA, nueva, (yyvsp[-2].exp_type).sitio, nueva));
                                    (yyval.exp_type).tipo = TIPO_REAL;
                                }else if(((yyvsp[-2].exp_type).tipo == TIPO_ENTERO) && ((yyvsp[0].exp_type).tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, (yyvsp[-2].exp_type).sitio, -1, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_RESTA, nueva, (yyvsp[0].exp_type).sitio, nueva));
                                    (yyval.exp_type).tipo = TIPO_REAL;
                                }else if(((yyvsp[-2].exp_type).tipo == TIPO_REAL) && ((yyvsp[0].exp_type).tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_RESTA, (yyvsp[-2].exp_type).sitio, (yyvsp[0].exp_type).sitio, nueva));
                                    (yyval.exp_type).tipo = TIPO_REAL;
                                }else{
                                    printf("%d y %d \n", (yyvsp[-2].exp_type).tipo, (yyvsp[0].exp_type).tipo);
                                    errores_parser(ERROR_TIPO);
                                }
                                (yyval.exp_type).sitio = nueva;
                            }
#line 1875 "parser.tab.c"
    break;

  case 57:
#line 349 "parser.y"
                            {
                                int nueva = TS_newtempt(&simbolos);
                                if(((yyvsp[-2].exp_type).tipo == TIPO_ENTERO) && ((yyvsp[0].exp_type).tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_ENTERO, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_DIVISION, (yyvsp[-2].exp_type).sitio, (yyvsp[0].exp_type).sitio, nueva));
                                    (yyval.exp_type).tipo = TIPO_ENTERO;
                                }else if(((yyvsp[-2].exp_type).tipo == TIPO_REAL) && ((yyvsp[0].exp_type).tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, (yyvsp[0].exp_type).sitio, -1, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_DIVISION, nueva, (yyvsp[-2].exp_type).sitio, nueva));
                                    (yyval.exp_type).tipo = TIPO_REAL;
                                }else if(((yyvsp[-2].exp_type).tipo == TIPO_ENTERO) && ((yyvsp[0].exp_type).tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, (yyvsp[-2].exp_type).sitio, -1, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_DIVISION, nueva, (yyvsp[0].exp_type).sitio, nueva));
                                    (yyval.exp_type).tipo = TIPO_REAL;
                                }else if(((yyvsp[-2].exp_type).tipo == TIPO_REAL) && ((yyvsp[0].exp_type).tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_DIVISION, (yyvsp[-2].exp_type).sitio, (yyvsp[0].exp_type).sitio, nueva));
                                    (yyval.exp_type).tipo = TIPO_REAL;
                                }else{
                                    printf("%d y %d \n", (yyvsp[-2].exp_type).tipo, (yyvsp[0].exp_type).tipo);
                                    errores_parser(ERROR_TIPO);
                                }       
                                (yyval.exp_type).tipo = TIPO_REAL;
                                (yyval.exp_type).sitio = nueva;
                            }
#line 1907 "parser.tab.c"
    break;

  case 58:
#line 377 "parser.y"
                            {
                                int nueva = TS_newtempt(&simbolos);
                                if(((yyvsp[-2].exp_type).tipo == TIPO_ENTERO) && ((yyvsp[0].exp_type).tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_ENTERO, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_DIV, (yyvsp[-2].exp_type).sitio, (yyvsp[0].exp_type).sitio, nueva));
                                    (yyval.exp_type).tipo = TIPO_ENTERO;
                                    (yyval.exp_type).sitio = nueva;
                                }else{
                                    printf("%d y %d \n", (yyvsp[-2].exp_type).tipo, (yyvsp[0].exp_type).tipo);
                                    errores_parser(ERROR_TIPO);
                                }
                            }
#line 1924 "parser.tab.c"
    break;

  case 59:
#line 390 "parser.y"
                            {
                                int nueva = TS_newtempt(&simbolos);
                                if(((yyvsp[-2].exp_type).tipo == TIPO_ENTERO) && ((yyvsp[0].exp_type).tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_ENTERO, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_MOD, (yyvsp[-2].exp_type).sitio, (yyvsp[0].exp_type).sitio, nueva));
                                    (yyval.exp_type).tipo = TIPO_ENTERO;
                                    (yyval.exp_type).sitio = nueva;
                                }else{
                                    printf("%d y %d \n", (yyvsp[-2].exp_type).tipo, (yyvsp[0].exp_type).tipo);
                                    errores_parser(ERROR_TIPO);
                                }
                            }
#line 1941 "parser.tab.c"
    break;

  case 60:
#line 403 "parser.y"
                            {
                                int nueva = TS_newtempt(&simbolos);
                                if(((yyvsp[-2].exp_type).tipo == TIPO_ENTERO) && ((yyvsp[0].exp_type).tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_ENTERO, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_MULTIPLICACION, (yyvsp[-2].exp_type).sitio, (yyvsp[0].exp_type).sitio, nueva));
                                    (yyval.exp_type).tipo = TIPO_ENTERO;
                                }else if(((yyvsp[-2].exp_type).tipo == TIPO_REAL) && ((yyvsp[0].exp_type).tipo == TIPO_ENTERO)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, (yyvsp[0].exp_type).sitio, -1, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_MULTIPLICACION, nueva, (yyvsp[-2].exp_type).sitio, nueva));
                                    (yyval.exp_type).tipo = TIPO_REAL;
                                }else if(((yyvsp[-2].exp_type).tipo == TIPO_ENTERO) && ((yyvsp[0].exp_type).tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_INT_TO_REAL, (yyvsp[-2].exp_type).sitio, -1, nueva));
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_MULTIPLICACION, nueva, (yyvsp[0].exp_type).sitio, nueva));
                                    (yyval.exp_type).tipo = TIPO_REAL;
                                }else if(((yyvsp[-2].exp_type).tipo == TIPO_REAL) && ((yyvsp[0].exp_type).tipo == TIPO_REAL)){
                                    TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_VAR);
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_MULTIPLICACION, (yyvsp[-2].exp_type).sitio, (yyvsp[0].exp_type).sitio, nueva));
                                    (yyval.exp_type).tipo = TIPO_REAL;
                                }else{
                                    printf("%d y %d \n", (yyvsp[-2].exp_type).tipo, (yyvsp[0].exp_type).tipo);
                                    errores_parser(ERROR_TIPO);
                                }
                                (yyval.exp_type).sitio = nueva;
                            }
#line 1972 "parser.tab.c"
    break;

  case 61:
#line 430 "parser.y"
                            {
                                printf("Entro en \n");
                                (yyval.exp_type).tipo = (yyvsp[-1].exp_type).tipo;
                                (yyval.exp_type).sitio = (yyvsp[-1].exp_type).sitio;
                            }
#line 1982 "parser.tab.c"
    break;

  case 62:
#line 436 "parser.y"
                            {
                                printf("Entro en operandoooooooooo \n");
                                (yyval.exp_type).sitio = (yyvsp[0].exp_type).sitio; 
                                (yyval.exp_type).tipo = (yyvsp[0].exp_type).tipo;
                            }
#line 1992 "parser.tab.c"
    break;

  case 63:
#line 442 "parser.y"
                            {
                                int nueva = TS_newtempt(&simbolos);
                                TS_modificar_tipo(&simbolos, nueva, (yyvsp[0].exp_type).tipo, TS_VAR);
                                if((yyvsp[0].exp_type).tipo == TIPO_ENTERO){
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_RESTA_UNARIA_ENTERO, (yyvsp[0].exp_type).sitio, -1, nueva));
                                }else if((yyvsp[0].exp_type).tipo == TIPO_REAL){
                                    TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_RESTA_UNARIA_REAL, (yyvsp[0].exp_type).sitio, -1, nueva));
                                }else{
                                    printf("%d \n", (yyvsp[0].exp_type).tipo);
                                    errores_parser(ERROR_TIPO);
                                }
                                (yyval.exp_type).sitio = nueva;
                                (yyval.exp_type).tipo = (yyvsp[0].exp_type).tipo;
                            }
#line 2011 "parser.tab.c"
    break;

  case 64:
#line 457 "parser.y"
                            {
                                int nueva = TS_newConst(&simbolos);
                                TS_modificar_tipo(&simbolos, nueva, TIPO_ENTERO, TS_CONSTANTE);
                                TS_modificar_valor_cte(&simbolos, nueva, (yyvsp[0].literales_type).valor);
                                (yyval.exp_type).tipo = TIPO_ENTERO;
                                (yyval.exp_type).sitio = nueva;
                            }
#line 2023 "parser.tab.c"
    break;

  case 65:
#line 465 "parser.y"
                            {
                                /*int nueva = TS_newConst(&simbolos);
                                TS_modificar_tipo(&simbolos, nueva, TIPO_REAL, TS_CONSTANTE);
                                TS_modificar_valor_cte(&simbolos, nueva, $1.valor);
                                $$.tipo = TIPO_REAL;
                                $$.sitio = nueva;*/
                            }
#line 2035 "parser.tab.c"
    break;

  case 66:
#line 475 "parser.y"
                            {
                                printf(MAGENTA"Expresion booleana -> 1\n"RESET);
                                printf("Valor de M %d \n", (yyvsp[-1].itype));
                                (yyval.exp_type).tipo = TIPO_BOOLEANO;
                                printf(ROJO"Cola $1.TRUE: \n"RESET);
                                printf(VERDE_F"Expresion booleana entrada 1"RESET" \n");
                                printf("Datos de la primera expresión: \n");
                                printf("Tipo: %d Sitio: %d \n", (yyvsp[-3].exp_type).tipo, (yyvsp[-3].exp_type).sitio);
                                printf("Cola true:\n");
                                imprimirCola(&(yyvsp[-3].exp_type).TRUE);
                                printf(ROJO"Cola $1.FALSE: \n"RESET);
                                printf("Cola false:\n");
                                imprimirCola(&(yyvsp[-3].exp_type).FALSE);
                                printf(ROJO"Cola $4.TRUE: \n"RESET);
                                printf("Dato de M: %d \n", (yyvsp[-1].itype));
                                printf("Datos de la segunda expresión: \n");
                                printf("Tipo: %d Sitio: %d \n", (yyvsp[0].exp_type).tipo, (yyvsp[0].exp_type).sitio);
                                printf("Cola true:\n");
                                imprimirCola(&(yyvsp[0].exp_type).TRUE);
                                printf(ROJO"Cola $4.FALSE: \n"RESET);
                                printf("Cola false:\n");
                                imprimirCola(&(yyvsp[0].exp_type).FALSE);

                                (yyval.exp_type).tipo = TIPO_EXPRESION_BOOLEANA;
                                backpatch(&cuadrupla, &(yyvsp[-3].exp_type).TRUE, (yyvsp[-1].itype));
                                if(!esNulaCola((yyvsp[-3].exp_type).FALSE) && !esNulaCola((yyvsp[0].exp_type).FALSE)){
                                    (yyval.exp_type).FALSE = merge((yyvsp[-3].exp_type).FALSE, (yyvsp[0].exp_type).FALSE);
                                }
                                (yyval.exp_type).TRUE = (yyvsp[0].exp_type).TRUE;

                                /*printf(VERDE_F"Expresion booleana salida 1"RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", $$.tipo, $$.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$$.TRUE);
                                printf(ROJO"Cola $$.FALSE: \n"RESET);
                                printf("Cola false:\n");
                                imprimirCola(&$$.FALSE);*/
                            }
#line 2078 "parser.tab.c"
    break;

  case 67:
#line 514 "parser.y"
                            {
                                printf(MAGENTA"Expresion booleana -> 2\n"RESET);
                                printf("Valor de M %d \n", (yyvsp[-1].itype));
                                (yyval.exp_type).tipo = TIPO_BOOLEANO;
                                printf(ROJO"Cola $1.TRUE: \n"RESET);
                                printf(VERDE_F"Expresion booleana entrada 2"RESET" \n");
                                printf("Datos de la primera expresión: \n");
                                printf("Tipo: %d Sitio: %d \n", (yyvsp[-3].exp_type).tipo, (yyvsp[-3].exp_type).sitio);
                                printf("Cola true:\n");
                                imprimirCola(&(yyvsp[-3].exp_type).TRUE);
                                printf(ROJO"Cola $1.FALSE: \n"RESET);
                                printf("Cola false:\n");
                                imprimirCola(&(yyvsp[-3].exp_type).FALSE);
                                printf(ROJO"Cola $4.TRUE: \n"RESET);
                                printf("Dato de M: %d \n", (yyvsp[-1].itype));
                                printf("Datos de la segunda expresión: \n");
                                printf("Tipo: %d Sitio: %d \n", (yyvsp[0].exp_type).tipo, (yyvsp[0].exp_type).sitio);
                                printf("Cola true:\n");
                                imprimirCola(&(yyvsp[0].exp_type).TRUE);
                                printf(ROJO"Cola $4.FALSE: \n"RESET);
                                imprimirCola(&(yyvsp[0].exp_type).FALSE);
                                TC_imprimir(&cuadrupla);

                                (yyval.exp_type).tipo = TIPO_EXPRESION_BOOLEANA;
                                backpatch(&cuadrupla, &(yyvsp[-3].exp_type).FALSE, (yyvsp[-1].itype));
                                printf("Llego \n");
                                if(!esNulaCola((yyvsp[-3].exp_type).TRUE) && !esNulaCola((yyvsp[0].exp_type).TRUE)){
                                    (yyval.exp_type).TRUE = merge((yyvsp[-3].exp_type).TRUE, (yyvsp[0].exp_type).TRUE);
                                }
                                printf("Llego \n");
                                (yyval.exp_type).FALSE = (yyvsp[0].exp_type).FALSE;  

                                /*TC_imprimir(&cuadrupla);
                                printf(ROJO"Cola $$.TRUE: \n"RESET);
                                printf(VERDE_F"Expresion booleana salida 2"RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", $$.tipo, $$.sitio);
                                printf("Cola true:\n");
                                imprimirCola(&$$.TRUE);
                                printf(ROJO"Cola $$.FALSE: \n"RESET);
                                printf("Cola false:\n");
                                imprimirCola(&$$.FALSE);*/

                            }
#line 2126 "parser.tab.c"
    break;

  case 68:
#line 558 "parser.y"
                            {
                                printf(MAGENTA"Expresion booleana -> 3\n"RESET);
                                printf(VERDE_F"Expresion booleana entrada 3"RESET" \n");
                                printf("Datos de la expresión: \n");
                                printf("Tipo: %d Sitio: %d \n", (yyvsp[0].exp_type).tipo, (yyvsp[0].exp_type).sitio);
                                printf("Cola true:\n");
                                imprimirCola(&(yyvsp[0].exp_type).TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&(yyvsp[0].exp_type).FALSE);
                                
                                (yyval.exp_type).tipo = TIPO_EXPRESION_BOOLEANA;
                                (yyval.exp_type).TRUE = (yyvsp[0].exp_type).FALSE;
                                (yyval.exp_type).FALSE = (yyvsp[0].exp_type).TRUE;

                                printf(VERDE_F"Expresion booleana salida 3"RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", (yyval.exp_type).tipo, (yyval.exp_type).sitio);
                                printf("Cola true:\n");
                                imprimirCola(&(yyval.exp_type).TRUE);
                                printf(ROJO"Cola $$.FALSE: \n"RESET);
                                imprimirCola(&(yyval.exp_type).FALSE);

                                printf("Cola false:\n");
                                imprimirCola(&(yyval.exp_type).FALSE);
                            }
#line 2155 "parser.tab.c"
    break;

  case 69:
#line 583 "parser.y"
                            {
                                int nueva = TS_newConst(&simbolos);
                                TS_modificar_tipo(&simbolos, nueva, TIPO_BOOLEANO, TS_CONSTANTE);
                                TS_modificar_valor_cte(&simbolos, nueva, (yyvsp[0].literales_type).valor);

                                int nextquad = TC_elemento_siguiente(&cuadrupla);
                                nuevaCola(&(yyval.exp_type).TRUE);
                                nuevaCola(&(yyval.exp_type).FALSE);
                                pideTurnoCola(&(yyval.exp_type).TRUE, nextquad);
                                pideTurnoCola(&(yyval.exp_type).FALSE, nextquad+1);
                                //$$.tipo = TIPO_ENTERO;
                                (yyval.exp_type).sitio = nueva;
                                (yyval.exp_type).tipo = TIPO_BOOLEANO;
                                //$$.sitio = $1;
                            }
#line 2175 "parser.tab.c"
    break;

  case 70:
#line 599 "parser.y"
                            {
                                printf(MAGENTA"Expresion booleana -> 6\n"RESET);
                                printf(VERDE_F"Expresion booleana entrada 6"RESET" \n");
                                printf("Datos de la primera expresión: \n");
                                printf("Tipo: %d Sitio: %d \n", (yyvsp[-2].exp_type).tipo, (yyvsp[-2].exp_type).sitio);
                                printf("Cola true:\n");
                                imprimirCola(&(yyvsp[-2].exp_type).TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&(yyvsp[-2].exp_type).FALSE);
                                printf("Datos de la segunda expresión: \n");
                                printf("Tipo: %d Sitio: %d \n", (yyvsp[0].exp_type).tipo, (yyvsp[0].exp_type).sitio);
                                printf("Cola true:\n");
                                imprimirCola(&(yyvsp[0].exp_type).TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&(yyvsp[0].exp_type).FALSE);

                                
                                (yyval.exp_type).tipo = TIPO_EXPRESION_BOOLEANA;
                                int nextquad = TC_elemento_siguiente(&cuadrupla);
                                nuevaCola(&(yyval.exp_type).TRUE);
                                nuevaCola(&(yyval.exp_type).FALSE);
                                pideTurnoCola(&(yyval.exp_type).TRUE, nextquad);
                                pideTurnoCola(&(yyval.exp_type).FALSE, nextquad+1);
                                if(strcmp((yyvsp[-1].ctype), "<") == 0){
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO_MENOR, (yyvsp[-2].exp_type).sitio, (yyvsp[0].exp_type).sitio, -1));
                                }else if(strcmp((yyvsp[-1].ctype), "<=") == 0){
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO_MENOR_O_IGUAL, (yyvsp[-2].exp_type).sitio, (yyvsp[0].exp_type).sitio, -1));
                                }else if(strcmp((yyvsp[-1].ctype), ">") == 0){
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO_MAYOR, (yyvsp[-2].exp_type).sitio, (yyvsp[0].exp_type).sitio, -1));
                                }else if(strcmp((yyvsp[-1].ctype), ">=") == 0){
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO_MAYOR_O_IGUAL, (yyvsp[-2].exp_type).sitio, (yyvsp[0].exp_type).sitio, -1));
                                }else if(strcmp((yyvsp[-1].ctype), "<>") == 0){
                                    TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO_DISTINTO, (yyvsp[-2].exp_type).sitio, (yyvsp[0].exp_type).sitio, -1));
                                }else{
                                    errores_parser(ERROR_OPERADOR);
                                }
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO, -1, -1, -1));

                                printf(VERDE_F"Expresion booleana salida 6"RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", (yyval.exp_type).tipo, (yyval.exp_type).sitio);
                                printf("Cola true:\n");
                                imprimirCola(&(yyval.exp_type).TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&(yyval.exp_type).FALSE);
                            }
#line 2225 "parser.tab.c"
    break;

  case 71:
#line 645 "parser.y"
                            {
                                printf(MAGENTA"Expresion booleana -> 7\n"RESET);
                                printf(VERDE_F"Expresion booleana entrada 7"RESET" \n");
                                printf("Datos de la primera expresión: \n");
                                printf("Tipo: %d Sitio: %d \n", (yyvsp[-2].exp_type).tipo, (yyvsp[-2].exp_type).sitio);
                                printf("Cola true:\n");
                                imprimirCola(&(yyvsp[-2].exp_type).TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&(yyvsp[-2].exp_type).FALSE);
                                printf("Datos de la segunda expresión: \n");
                                printf("Tipo: %d Sitio: %d \n", (yyvsp[0].exp_type).tipo, (yyvsp[0].exp_type).sitio);
                                printf("Cola true:\n");
                                imprimirCola(&(yyvsp[0].exp_type).TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&(yyvsp[0].exp_type).FALSE);
                                
                                int nextquad = TC_elemento_siguiente(&cuadrupla);
                                nuevaCola(&(yyval.exp_type).TRUE);
                                nuevaCola(&(yyval.exp_type).FALSE);
                                pideTurnoCola(&(yyval.exp_type).TRUE, nextquad);
                                pideTurnoCola(&(yyval.exp_type).FALSE, nextquad+1);
                                
                                nextquad = TC_elemento_siguiente(&cuadrupla);
                                pideTurnoCola(&(yyval.exp_type).TRUE, nextquad);
                                pideTurnoCola(&(yyval.exp_type).FALSE, nextquad+1);
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO_IGUAL, (yyvsp[-2].exp_type).sitio, (yyvsp[0].exp_type).sitio, -1));
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO, -1, -1, -1));
                                (yyval.exp_type).tipo = TIPO_EXPRESION_BOOLEANA;

                                printf(VERDE_F"Expresion booleana salida 7"RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", (yyval.exp_type).tipo, (yyval.exp_type).sitio);
                                printf("Cola true:\n");
                                imprimirCola(&(yyval.exp_type).TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&(yyval.exp_type).FALSE);
                            }
#line 2266 "parser.tab.c"
    break;

  case 72:
#line 682 "parser.y"
                            {
                                printf(MAGENTA"Expresion booleana -> 8\n"RESET);
                                printf(VERDE_F"Expresion booleana entrada 8"RESET" \n");
                                printf("Datos de la expresión: \n");
                                printf("Tipo: %d Sitio: %d \n", (yyvsp[-1].exp_type).tipo, (yyvsp[-1].exp_type).sitio);
                                printf("Cola true:\n");
                                imprimirCola(&(yyvsp[-1].exp_type).TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&(yyvsp[-1].exp_type).FALSE);

                                (yyval.exp_type) = (yyvsp[-1].exp_type);
                                //TC_imprimir(&cuadrupla);

                                printf(VERDE_F"Expresion booleana salida 8"RESET" \n");
                                printf("Tipo: %d Sitio: %d \n", (yyval.exp_type).tipo, (yyval.exp_type).sitio);
                                printf("Cola true:\n");
                                imprimirCola(&(yyval.exp_type).TRUE);
                                printf("Cola false:\n");
                                imprimirCola(&(yyval.exp_type).FALSE);
                            }
#line 2291 "parser.tab.c"
    break;

  case 73:
#line 705 "parser.y"
                {
                    /* ERROR AL COMPROBAR SI EXISTE */
                    printf("%s \n", (yyvsp[0].ctype));
                    int id = TS_buscar_id(&simbolos,(yyvsp[0].ctype)); 
                    if(id == -1){
                        errores_parser(ERROR_SIMBOLO);
                    }else{
                        (yyval.exp_type).sitio = id;
                    }
                    
                    /* SI ES DIFERENTE A VARIABLE O CONSTANTE ERROR */
                    //$$.tipo = TS_consulta_tipo(&simbolos, $$.sitio);
                    int tipo = TS_consulta_tipo(&simbolos, (yyval.exp_type).sitio);
                    if(tipo == TIPO_BOOLEANO){
                        (yyval.exp_type).tipo = TIPO_BOOLEANO;
                        //int nextquad = TC_elemento_siguiente(&cuadrupla);
                        nuevaCola(&(yyval.exp_type).TRUE);
                        nuevaCola(&(yyval.exp_type).FALSE);
                        //pideTurnoCola(&$$.TRUE, nextquad);
                        //pideTurnoCola(&$$.FALSE, nextquad+1);
                    }else{
                        (yyval.exp_type).tipo = tipo;
                    }
                    
                }
#line 2321 "parser.tab.c"
    break;

  case 74:
#line 730 "parser.y"
                                              {}
#line 2327 "parser.tab.c"
    break;

  case 75:
#line 731 "parser.y"
                                                              {}
#line 2333 "parser.tab.c"
    break;

  case 76:
#line 732 "parser.y"
                              {}
#line 2339 "parser.tab.c"
    break;

  case 77:
#line 735 "parser.y"
                 {(yyval.itype) = TC_elemento_siguiente(&cuadrupla);}
#line 2345 "parser.tab.c"
    break;

  case 78:
#line 737 "parser.y"
                {(yyval.itype) = TC_elemento_siguiente(&cuadrupla);}
#line 2351 "parser.tab.c"
    break;

  case 79:
#line 741 "parser.y"
                    {
                        backpatch(&cuadrupla, &(yyvsp[-3].inst_type).siguiente, (yyvsp[-1].itype));
                        (yyval.inst_type) = (yyvsp[-3].inst_type);
                    }
#line 2360 "parser.tab.c"
    break;

  case 80:
#line 746 "parser.y"
                    {
                        (yyval.inst_type) = (yyvsp[0].inst_type);
                    }
#line 2368 "parser.tab.c"
    break;

  case 81:
#line 751 "parser.y"
                             {}
#line 2374 "parser.tab.c"
    break;

  case 82:
#line 753 "parser.y"
                    {
                        (yyval.inst_type) = (yyvsp[0].inst_type);
                    }
#line 2382 "parser.tab.c"
    break;

  case 83:
#line 757 "parser.y"
                    {
                        (yyval.inst_type) = (yyvsp[0].inst_type);
                    }
#line 2390 "parser.tab.c"
    break;

  case 84:
#line 761 "parser.y"
                    {
                        (yyval.inst_type) = (yyvsp[0].inst_type);
                    }
#line 2398 "parser.tab.c"
    break;

  case 85:
#line 764 "parser.y"
                                 {}
#line 2404 "parser.tab.c"
    break;

  case 86:
#line 767 "parser.y"
                    {
                        /*printf(YELLOW"Entro en asignacion2 \n"RESET);
                        printf(YELLOW"Asignación entrada \n"RESET);
                        printf("Datos del operando: \n");
                        printf("Tipo: %d Sitio: %d \n", $1.tipo, $1.sitio);
                        printf("Cola true: \n");
                        imprimirCola(&$1.TRUE);
                        printf("Cola false: \n");
                        imprimirCola(&$1.FALSE);
                        printf("Datos de la expresion: \n");
                        printf("Tipo: %d Sitio: %d \n", $3.tipo, $3.sitio);
                        printf("Cola true: \n");
                        imprimirCola(&$3.TRUE);
                        printf("Cola false: \n");
                        imprimirCola(&$3.FALSE);*/
                        

                        if(TS_consulta_tipo_simbolo(&simbolos, (yyvsp[-2].exp_type).sitio) == TS_VAR){
                            if((yyvsp[-2].exp_type).tipo == (yyvsp[0].exp_type).tipo){
                                TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_ASIGNACION, (yyvsp[-2].exp_type).sitio, -1, (yyvsp[0].exp_type).sitio));   
                            }else if((((yyvsp[-2].exp_type).tipo == TIPO_BOOLEANO) && ((yyvsp[0].exp_type).tipo == TIPO_EXPRESION_BOOLEANA)) 
                            || (((yyvsp[-2].exp_type).tipo == TIPO_EXPRESION_BOOLEANA) && ((yyvsp[0].exp_type).tipo == TIPO_BOOLEANO)) ){
                                //printf("Entro aqui 2\n");
                                int nextquad = TC_elemento_siguiente(&cuadrupla);
                                backpatch(&cuadrupla, &(yyvsp[0].exp_type).FALSE, nextquad+2);
                                printf("%d \n", (yyvsp[-2].exp_type).sitio);
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_ASIGNACION_TRUE, -1, -1, (yyvsp[-2].exp_type).sitio));
                                printf("%d \n", (yyvsp[-2].exp_type).sitio);
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO, -1, -1, nextquad+3));
                                printf("%d \n", (yyvsp[-2].exp_type).sitio);
                                backpatch(&cuadrupla, &(yyvsp[0].exp_type).TRUE, nextquad);
                                printf("%d \n", (yyvsp[-2].exp_type).sitio);
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_ASIGNACION_FALSE, -1, -1, (yyvsp[-2].exp_type).sitio));
                                TC_imprimir(&cuadrupla);
                            }else if(((yyvsp[-2].exp_type).tipo == TIPO_REAL) && ((yyvsp[0].exp_type).tipo == TIPO_ENTERO)){
                                TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_ASIGNACION, (yyvsp[-2].exp_type).sitio, -1, (yyvsp[0].exp_type).sitio));
                            }/*else if((($1.tipo == TIPO_BOOLEANO) && ($3.tipo == TIPO_FALSO)) 
                            || (($1.tipo == TIPO_LITERAL_BOOLEANO) && ($3.tipo == TIPO_FALSO)) ){
                                TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_ASIGNACION_TIPO_FALSO, $1.sitio, -1, $3.sitio));
                            }else if((($1.tipo == TIPO_BOOLEANO) && ($3.tipo == TIPO_VERDADERO))
                            || (($1.tipo == TIPO_LITERAL_BOOLEANO) && ($3.tipo == TIPO_VERDADERO))){
                                TC_insertar(&cuadrupla,TC_crear_cuadrupla(OP_ASIGNACION_TIPO_VERDADERO, $1.sitio, -1, $3.sitio));
                            }*/else if(((yyvsp[-2].exp_type).tipo == TIPO_ENTERO) && ((yyvsp[0].exp_type).tipo == TIPO_REAL)){
                                printf("%d y %d \n", (yyvsp[-2].exp_type).tipo, (yyvsp[0].exp_type).tipo);
                                errores_parser(ERROR_TIPO);
                            }else{
                                printf("%d y %d \n", (yyvsp[-2].exp_type).tipo, (yyvsp[0].exp_type).tipo);
                                errores_parser(ERROR_TIPO);
                            }
                        }else{
                            //printf("Entro aqui 2 \n");
                            printf("%d y %d \n", (yyvsp[-2].exp_type).tipo, (yyvsp[0].exp_type).tipo);
                            errores_parser(ERROR_TIPO);
                        }
                        nuevaCola(&(yyval.inst_type).siguiente);
                    }
#line 2465 "parser.tab.c"
    break;

  case 87:
#line 825 "parser.y"
                {
                    (yyval.inst_type).siguiente = (yyvsp[-3].inst_type).siguiente;
                    backpatch(&cuadrupla, &(yyvsp[-6].exp_type).TRUE, (yyvsp[-4].itype));
                    backpatch(&cuadrupla, &(yyvsp[-6].exp_type).FALSE, (yyvsp[-2].itype));
                }
#line 2475 "parser.tab.c"
    break;

  case 88:
#line 832 "parser.y"
                {
                    backpatch(&cuadrupla, &(yyvsp[-5].exp_type).TRUE, (yyvsp[-3].itype));
                    backpatch(&cuadrupla, &(yyvsp[-5].exp_type).FALSE, (yyvsp[-1].itype));
                    (yyval.inst_type).siguiente = (yyvsp[-2].inst_type).siguiente;
                }
#line 2485 "parser.tab.c"
    break;

  case 89:
#line 837 "parser.y"
                              {nuevaCola(&(yyval.inst_type).siguiente);}
#line 2491 "parser.tab.c"
    break;

  case 90:
#line 840 "parser.y"
                {
                    (yyval.inst_type) = (yyvsp[0].inst_type);
                }
#line 2499 "parser.tab.c"
    break;

  case 91:
#line 844 "parser.y"
                {
                    (yyval.inst_type) = (yyvsp[0].inst_type);
                }
#line 2507 "parser.tab.c"
    break;

  case 92:
#line 849 "parser.y"
                        {
                            backpatch(&cuadrupla, &(yyvsp[-4].exp_type).TRUE, (yyvsp[-2].itype));
                            if(!esNulaCola((yyvsp[-1].inst_type).siguiente)){
                                backpatch(&cuadrupla, &(yyvsp[-1].inst_type).siguiente, (yyvsp[-5].itype));
                            }else{
                                TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO, -1, -1, (yyvsp[-2].itype))); 
                            }    
                            /* Se supone que estas dos lineas pueden no hacer falta aqui */
                            int nextquad = TC_elemento_siguiente(&cuadrupla);
                            backpatch(&cuadrupla, &(yyvsp[-4].exp_type).FALSE, nextquad);
                            (yyval.inst_type).siguiente = (yyvsp[-4].exp_type).FALSE;
                        }
#line 2524 "parser.tab.c"
    break;

  case 93:
#line 863 "parser.y"
                    {
                        //printf(GREEN"IT COTA FIJA, PARA\n"RESET);
                        //printf("Datos del identificador: \n");
                        //printf("tipo: %d sitio: %d \n", $2.tipo, $2.sitio);
                        /*printf("Datos de expresión 1: \n");
                        printf("tipo: %d sitio: %d \n", $4.tipo, $4.sitio);
                        printf("Cola true: \n");
                        imprimirCola(&$4.TRUE);
                        printf("Cola false: \n");
                        imprimirCola(&$4.FALSE);
                        printf("Datos de expresión 2: \n");
                        printf("tipo: %d sitio: %d \n", $6.tipo, $6.sitio);
                        printf("Cola true: \n");
                        imprimirCola(&$6.TRUE);
                        printf("Cola false: \n");
                        imprimirCola(&$6.FALSE);
                        printf("Datos de instrucciones: \n");
                        printf("Cola siguiente: \n");
                        imprimirCola(&$8.siguiente);*/

                        /*Primero metermos las instrucciones */
                        /*if(!esNulaCola($8.siguiente)){
                            int nextquad = TC_elemento_siguiente(&cuadrupla);
                            backpatch(&cuadrupla, &$8.siguiente, nextquad);
                        }*/

                        //Tiene que ser una constante
                        //Creamos una constante con un 1
                        /*int nextquad = TC_elemento_siguiente(&cuadrupla);
                        int nueva = TS_newConst(&simbolos);
                        TS_modificar_tipo(&simbolos, nueva, TIPO_ENTERO, TS_CONSTANTE);
                        Constante_valor constante;
                        constante.entero = 1;
                        TS_modificar_valor_cte(&simbolos, nueva, constante);
                        TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_SUMA, $2.sitio, nueva ,$2.sitio));
                        TC_insertar(&cuadrupla, TC_crear_cuadrupla(OP_GOTO, -1,-1 ,nextquad+2));*/
                        
                        //backpatch()
                        

                    }
#line 2570 "parser.tab.c"
    break;


#line 2574 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 932 "parser.y"

void errores_parser(int tipo_error){
    switch(tipo_error){
        case ERROR_TIPO:
            printf("Tipos no compatibles para la operación \n");
            break;
        case ERROR_OPERADOR:
            printf("Error en el operador \n");
            break;
        case ERROR_SIMBOLO:
            printf("Símbolo no encontrado \n");
            break;
        default:
            break;
    }
}


int main(int argc, char **argv){  
    if (argc > 1) {
        yyin = fopen(argv[1],"r");
    }
    nuevaPila(&pila);
    TS_nuevaLista(&simbolos);
    TC_nuevaLista(&cuadrupla);
    //yydebug = 1;
    yyparse(); 
    TS_imprimir(&simbolos);
    TC_imprimir(&cuadrupla);
    CTD_imprimir(&cuadrupla, &simbolos);
}
	
void yyerror(char* s){
    //Poner aqui otro mensaje, tipo "error en la sintaxis en la linea nosecual"
    printf(ROJO"PARSER ERROR: %s\n" RESET,s);
}
