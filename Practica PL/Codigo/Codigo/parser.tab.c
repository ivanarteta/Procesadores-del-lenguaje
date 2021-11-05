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
  
    #include "eaux.h"
    #include "ts.h"
    #include "tc.h"
    #include <stdio.h>
    #include <ctype.h>
    #include <string.h>
    
    
    extern FILE* yyin;
    int yylex (void);
    int yyerror (char *s);
    struct FILA_TS* cabeza_TS;
    struct FILA_TS* cola_TS;
    struct FILA_TS* fila;
    struct TC tabla_cuadruplas;
    
    int operador, *op1, *op2, *res, id, id2, errorFlag;
    
    
    

#line 93 "parser.tab.c"

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

#line 231 "parser.tab.c"

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
typedef yytype_int16 yy_state_t;

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
#define YYLAST   307

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  262

#define YYUNDEFTOK  2
#define YYMAXUTOK   322


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
      65,    66,    67
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   125,   125,   127,   129,   131,   132,   133,   135,   135,
     136,   138,   140,   141,   142,   143,   145,   147,   149,   151,
     152,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   165,   166,   168,   169,   171,   172,   173,   174,   175,
     176,   178,   180,   182,   183,   187,   193,   194,   196,   197,
     201,   208,   215,   217,   224,   232,   243,   254,   256,   267,
     281,   282,   283,   285,   287,   289,   331,   374,   416,   457,
     500,   540,   544,   559,   562,   565,   586,   605,   627,   642,
     647,   798,   864,   868,   870,   896,   897,   900,   907,   912,
     915,   920,   921,   922,   924,   965,   967,   968,   970,   971,
     973,   975,   977,   979,   981,   983,   985,   986,   988,   989,
     990,   992,   994,   996,   997,   999
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_entonces", "TK_accion",
  "TK_algoritmo", "TK_booleano", "TK_cadena", "TK_caracter", "TK_const",
  "TK_continuar", "TK_de", "TK_dev", "TK_ent", "TK_entero", "TK_entsal",
  "TK_faccion", "TK_falgoritmo", "TK_fconst", "TK_ffuncion",
  "TK_fmientras", "TK_fpara", "TK_fsi", "TK_ftipo", "TK_ftupla",
  "TK_funcion", "TK_fvar", "TK_hacer", "TK_mientras", "TK_para",
  "TK_hasta", "TK_real", "TK_ref", "TK_sal", "TK_si", "TK_tabla",
  "TK_tipo", "TK_tupla", "TK_var", "TK_comentario_pre",
  "TK_comentario_post", "TK_asignacion", "TK_composicion_secuencial",
  "TK_separador", "TK_subrango", "TK_definicion", "TK_si_no_si",
  "TK_inicio_array", "TK_fin_array", "TK_inicio_parentesis",
  "TK_literal_entero", "TK_literal_caracter", "TK_literal_cadena",
  "TK_literal_real", "TK_literal_booleano", "TK_identificador", "TK_o",
  "TK_y", "TK_comparador", "TK_igual", "TK_no", "TK_op_suma",
  "TK_op_resta", "TK_op_division", "TK_div", "TK_op_multiplicador",
  "TK_mod", "TK_fin_parentesis", "$accept", "desc_algoritmo",
  "cabecera_alg", "bloque_alg", "decl_globales", "decl_a_f", "bloque",
  "declaraciones", "declaracion_tipo", "declaracion_cte",
  "declaracion_var", "lista_d_tipo", "d_tipo", "expresion_t",
  "lista_campos", "lista_d_cte", "lista_d_var", "lista_id",
  "lista_id_var_o_no", "lista_id_var", "lista_id_ent_o_no", "lista_id_ent",
  "lista_id_sal_o_no", "lista_id_sal", "decl_ent_sal", "decl_ent",
  "decl_sal", "exp_a", "expresion", "operando", "instrucciones",
  "instruccion", "asignacion", "alternativa", "lista_opciones",
  "iteracion", "it_cota_exp", "it_cota_fija", "accion_d", "funcion_d",
  "a_cabecera", "f_cabecera", "d_par_form", "d_p_form", "accion_ll",
  "funcion_ll", "l_ll", "M", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   321,   322
};
# endif

#define YYPACT_NINF (-145)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-24)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      28,   -11,    88,    26,  -145,    12,    38,    42,     5,    14,
      12,    12,    56,   100,    63,   105,    78,   150,   111,    -2,
       5,     5,     5,   120,   128,    21,    14,    14,  -145,  -145,
     189,  -145,   154,  -145,    41,   164,   159,  -145,  -145,  -145,
     116,   147,   116,   157,   -16,  -145,   168,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,   162,     5,   163,     5,
     158,   160,   181,   188,  -145,  -145,  -145,   186,   187,   212,
     213,   214,  -145,  -145,  -145,  -145,  -145,   154,   183,   176,
     116,  -145,  -145,  -145,  -145,   215,   116,   116,   216,   217,
     161,    -3,    34,  -145,   204,   154,  -145,    78,  -145,   -12,
     219,     3,   116,  -145,   116,   116,  -145,     7,   246,    78,
     251,    46,   222,    68,   223,  -145,  -145,    38,    38,    38,
      38,    38,  -145,    70,   221,   243,   131,    -3,   172,   -28,
      42,    70,  -145,  -145,   116,   116,   116,   116,   116,   116,
     116,   116,   109,  -145,  -145,  -145,    -2,   116,    -2,    20,
     201,    -3,    37,    -2,   218,   218,   218,   202,   228,  -145,
     205,   116,   220,   154,  -145,   224,   154,  -145,  -145,  -145,
    -145,  -145,  -145,   227,   154,  -145,  -145,  -145,  -145,   116,
     116,   182,   -28,    44,    77,   208,  -145,   225,  -145,    78,
     154,   256,    -1,   231,   116,  -145,  -145,  -145,   235,   236,
     237,   238,   244,     7,   268,    -9,   112,  -145,  -145,   134,
    -145,  -145,    70,   245,    74,   172,  -145,  -145,  -145,   116,
     282,   266,  -145,   218,   154,   154,   154,  -145,  -145,   154,
    -145,   158,   154,   160,   154,   241,   176,     1,    -2,  -145,
    -145,   248,   249,   250,   252,  -145,  -145,  -145,  -145,   284,
    -145,    -2,   231,  -145,  -145,  -145,  -145,   154,   272,  -145,
    -145,  -145
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     7,    40,    20,    15,    10,
       7,     7,     0,     0,     0,     0,    42,     0,     0,     0,
      15,    15,    15,     0,     0,     0,    10,    10,     5,     6,
       0,    17,   112,    16,     0,     0,     0,     2,     4,    89,
     112,     0,   112,    84,     0,    11,    88,    90,    91,    92,
      99,    98,    93,    12,    13,    14,     0,    15,     0,    15,
       0,     0,     0,    60,    62,     8,     9,     0,     0,     0,
       0,     0,    27,    30,    29,    26,    28,   112,     0,    34,
     112,    74,    32,    73,    79,    84,   112,   112,     0,     0,
      82,    31,    72,    83,    47,   112,    18,    42,    84,     0,
       0,     0,   112,    86,   112,   112,   115,   107,     0,    42,
       0,     0,     0,     0,     0,     3,    61,    40,    40,    40,
      40,    40,    25,   112,     0,     0,    82,     0,    78,    75,
      20,   112,   115,   115,   112,   112,   112,   112,   112,   112,
     112,   112,     0,    49,    48,    41,     0,   112,     0,   114,
       0,    94,     0,     0,     0,     0,     0,     0,     0,   102,
       0,   112,    52,   112,    63,    57,   112,    64,    37,    36,
      35,    38,    39,     0,   112,    21,    71,    19,    24,   112,
     112,    65,    66,    68,    70,    67,    69,    80,    81,     0,
     112,     0,     0,    97,   112,   111,    85,    87,    44,     0,
       0,     0,     0,   107,     0,     0,     0,    54,    53,     0,
      59,    58,   112,     0,    77,    76,    46,    45,   100,   112,
       0,     0,   113,     0,   112,   112,   112,   104,   106,   112,
     103,     0,   112,     0,   112,     0,    34,     0,     0,    95,
      43,     0,     0,     0,     0,    51,    50,    56,    55,     0,
      33,     0,    97,   108,   110,   109,   105,   112,     0,    96,
      22,   101
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,  -145,  -145,    54,   137,   123,   152,    72,   136,
    -145,   166,   -76,  -120,    61,   132,   -67,  -143,  -145,   110,
    -145,    69,  -145,    65,  -145,  -145,   239,   -63,   -35,   -19,
    -144,  -145,  -145,  -145,    49,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,   101,  -145,  -145,  -145,   113,    67
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,    17,     9,    25,    18,    19,    20,    21,
      22,    15,    88,    89,   125,    13,    35,   199,   143,    36,
     207,   112,   210,   114,    62,    63,    64,    90,    91,    92,
      45,    46,    47,    48,   221,    49,    50,    51,    26,    27,
      57,    59,   157,   158,    52,    93,   150,   153
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,   122,   191,   173,   193,    99,   148,   101,    39,   197,
     230,   178,   200,   201,     6,   146,   103,   126,    23,   144,
     154,     6,   155,   128,   129,   104,    40,    41,   251,   219,
     145,   105,    42,     1,    60,   136,   137,   138,   139,    24,
     156,     7,   160,    16,     3,   127,   140,   141,     7,   140,
     141,   127,   127,    43,    61,   140,   141,   140,   141,   140,
     141,   140,   141,   194,    28,    29,   103,   149,     5,   151,
     152,   181,   182,   183,   184,   185,   186,    10,   140,   141,
     240,   105,    10,    10,    94,   196,    95,   208,     4,   162,
     211,   163,   235,    12,   252,   140,   141,    14,   213,   127,
     127,   127,   127,   127,   127,   187,   188,   258,   137,   138,
     139,   165,   192,   166,   217,    30,   214,   215,    31,    80,
      81,    82,    32,    83,    84,    98,   205,    44,    33,    44,
      86,   133,    87,    34,    44,   134,   135,   136,   137,   138,
     139,    11,   138,   139,   127,   127,    11,    11,   241,   242,
     243,    38,   189,   244,   190,   231,   246,   232,   248,   149,
      72,    73,    74,    65,    66,    80,    81,    37,    75,    83,
      84,    98,    53,    54,    55,    56,    86,   233,    87,   234,
     108,   260,   110,    58,   237,    76,    77,   132,   133,    78,
      96,    79,   134,   135,   136,   137,   138,   139,   176,   179,
     180,    97,   100,    80,    81,    82,   102,    83,    84,    85,
     106,   107,   109,   111,    86,   113,    87,   132,   133,    44,
     115,    61,   134,   135,   136,   137,   138,   139,   117,   118,
     123,   124,    44,   134,   135,   136,   137,   138,   139,    67,
      68,    69,    70,    71,   135,   136,   137,   138,   139,   168,
     169,   170,   171,   172,   119,   120,   121,   -23,   130,   142,
     147,   131,   159,   161,   164,   167,   174,   175,   195,   202,
     203,   212,   204,   198,   139,   206,   218,   220,   223,   209,
     229,   224,   225,   226,   141,   238,   227,   236,   239,   249,
     253,   254,   255,   261,   256,   257,   177,   250,   247,   216,
     245,   259,   116,     0,   228,     0,     0,   222
};

static const yytype_int16 yycheck[] =
{
      19,    77,   146,   123,   148,    40,     3,    42,    10,   153,
      19,   131,   155,   156,     9,    27,    32,    80,     4,    95,
      13,     9,    15,    86,    87,    41,    28,    29,    27,    30,
      97,    47,    34,     5,    13,    63,    64,    65,    66,    25,
      33,    36,   109,    38,    55,    80,    58,    59,    36,    58,
      59,    86,    87,    55,    33,    58,    59,    58,    59,    58,
      59,    58,    59,    43,    10,    11,    32,   102,    42,   104,
     105,   134,   135,   136,   137,   138,   139,     5,    58,    59,
     223,    47,    10,    11,    43,    48,    45,   163,     0,    43,
     166,    45,   212,    55,   238,    58,    59,    55,   174,   134,
     135,   136,   137,   138,   139,   140,   141,   251,    64,    65,
      66,    43,   147,    45,   190,    59,   179,   180,    18,    49,
      50,    51,    59,    53,    54,    55,   161,   146,    23,   148,
      60,    57,    62,    55,   153,    61,    62,    63,    64,    65,
      66,     5,    65,    66,   179,   180,    10,    11,   224,   225,
     226,    40,    43,   229,    45,    43,   232,    45,   234,   194,
       6,     7,     8,    26,    27,    49,    50,    17,    14,    53,
      54,    55,    20,    21,    22,    55,    60,    43,    62,    45,
      57,   257,    59,    55,   219,    31,    32,    56,    57,    35,
      26,    37,    61,    62,    63,    64,    65,    66,    67,   132,
     133,    42,    55,    49,    50,    51,    49,    53,    54,    55,
      42,    49,    49,    55,    60,    55,    62,    56,    57,   238,
      39,    33,    61,    62,    63,    64,    65,    66,    42,    42,
      47,    55,   251,    61,    62,    63,    64,    65,    66,    50,
      51,    52,    53,    54,    62,    63,    64,    65,    66,   117,
     118,   119,   120,   121,    42,    42,    42,    42,    42,    55,
      41,    44,    16,    12,    42,    42,    45,    24,    67,    67,
      42,    44,    67,    55,    66,    55,    20,    46,    43,    55,
      12,    45,    45,    45,    59,     3,    42,    42,    22,    48,
      42,    42,    42,    21,    42,    11,   130,   236,   233,   189,
     231,   252,    63,    -1,   203,    -1,    -1,   194
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    69,    55,     0,    42,     9,    36,    70,    72,
      76,    77,    55,    83,    55,    79,    38,    71,    74,    75,
      76,    77,    78,     4,    25,    73,   106,   107,    72,    72,
      59,    18,    59,    23,    55,    84,    87,    17,    40,    10,
      28,    29,    34,    55,    97,    98,    99,   100,   101,   103,
     104,   105,   112,    75,    75,    75,    55,   108,    55,   109,
      13,    33,    92,    93,    94,    73,    73,    50,    51,    52,
      53,    54,     6,     7,     8,    14,    31,    32,    35,    37,
      49,    50,    51,    53,    54,    55,    60,    62,    80,    81,
      95,    96,    97,   113,    43,    45,    26,    42,    55,    96,
      55,    96,    49,    32,    41,    47,    42,    49,    74,    49,
      74,    55,    89,    55,    91,    39,    94,    42,    42,    42,
      42,    42,    80,    47,    55,    82,    95,    96,    95,    95,
      42,    44,    56,    57,    61,    62,    63,    64,    65,    66,
      58,    59,    55,    86,    80,    84,    27,    41,     3,    96,
     114,    96,    96,   115,    13,    15,    33,   110,   111,    16,
      84,    12,    43,    45,    42,    43,    45,    42,    83,    83,
      83,    83,    83,    81,    45,    24,    67,    79,    81,   115,
     115,    95,    95,    95,    95,    95,    95,    96,    96,    43,
      45,    98,    96,    98,    43,    67,    48,    98,    55,    85,
      85,    85,    67,    42,    67,    96,    55,    88,    80,    55,
      90,    80,    44,    80,    95,    95,    87,    80,    20,    30,
      46,   102,   114,    43,    45,    45,    45,    42,   110,    12,
      19,    43,    45,    43,    45,    81,    42,    96,     3,    22,
      85,    80,    80,    80,    80,    89,    80,    91,    80,    48,
      82,    27,    98,    42,    42,    42,    42,    11,    98,   102,
      80,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    68,    69,    70,    71,    72,    72,    72,    73,    73,
      73,    74,    75,    75,    75,    75,    76,    77,    78,    79,
      79,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    81,    81,    82,    82,    83,    83,    83,    83,    83,
      83,    84,    84,    85,    85,    86,    86,    86,    87,    87,
      88,    88,    88,    89,    89,    90,    90,    90,    91,    91,
      92,    92,    92,    93,    94,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    96,    96,    97,    97,    97,    98,    98,    99,
      99,    99,    99,    99,   100,   101,   102,   102,   103,   103,
     104,   105,   106,   107,   108,   109,   110,   110,   111,   111,
     111,   112,   113,   114,   114,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     4,     2,     2,     2,     0,     2,     2,
       0,     2,     2,     2,     2,     0,     3,     3,     3,     5,
       0,     3,     8,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     5,     0,     5,     5,     5,     5,     5,
       0,     3,     0,     3,     1,     3,     3,     0,     3,     3,
       3,     3,     0,     3,     3,     3,     3,     0,     3,     3,
       1,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     2,     4,     4,     2,     1,
       3,     3,     1,     1,     1,     4,     2,     4,     1,     1,
       1,     1,     1,     1,     3,     6,     4,     0,     1,     1,
       5,     9,     4,     6,     5,     7,     3,     0,     5,     5,
       5,     4,     0,     3,     1,     0
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
  case 2:
#line 125 "parser.y"
                                                                                                                      {printf("\tPARSER: desc_algoritmo\n");}
#line 1610 "parser.tab.c"
    break;

  case 3:
#line 127 "parser.y"
                                                                              {printf("\tPARSER: cabecera_alg\n");}
#line 1616 "parser.tab.c"
    break;

  case 4:
#line 129 "parser.y"
                                                  {printf("\tPARSER: bloque_alg\n");}
#line 1622 "parser.tab.c"
    break;

  case 5:
#line 131 "parser.y"
                                                        {printf("\tPARSER: decl_globales->tipo\n");}
#line 1628 "parser.tab.c"
    break;

  case 6:
#line 132 "parser.y"
                                                      {printf("\tPARSER: decl_globales->const\n");}
#line 1634 "parser.tab.c"
    break;

  case 7:
#line 133 "parser.y"
                                     {printf("\tPARSER: decl_globales->epsilon\n");}
#line 1640 "parser.tab.c"
    break;

  case 9:
#line 135 "parser.y"
                                                               {printf("\tPARSER: decl_a_f\n");}
#line 1646 "parser.tab.c"
    break;

  case 10:
#line 136 "parser.y"
                                     {printf("\tPARSER: decl_a_f->epsilon\n");}
#line 1652 "parser.tab.c"
    break;

  case 11:
#line 138 "parser.y"
                                                    {printf("\tPARSER: bloque\n");}
#line 1658 "parser.tab.c"
    break;

  case 12:
#line 140 "parser.y"
                                                        {printf("\tPARSER: declaraciones->tipo\n");}
#line 1664 "parser.tab.c"
    break;

  case 13:
#line 141 "parser.y"
                                                      {printf("\tPARSER: declaraciones->const\n");}
#line 1670 "parser.tab.c"
    break;

  case 14:
#line 142 "parser.y"
                                                        {printf("\tPARSER: declaraciones->var\n");}
#line 1676 "parser.tab.c"
    break;

  case 15:
#line 143 "parser.y"
                                    {printf("\tPARSER: declaraciones->epsilon\n");}
#line 1682 "parser.tab.c"
    break;

  case 16:
#line 145 "parser.y"
                                                      {printf("\tPARSER: declaracion_tipo\n");}
#line 1688 "parser.tab.c"
    break;

  case 17:
#line 147 "parser.y"
                                                       {printf("\tPARSER: declaracion_cte\n");}
#line 1694 "parser.tab.c"
    break;

  case 18:
#line 149 "parser.y"
                                                   {printf("\tPARSER: declaracion_var\n");}
#line 1700 "parser.tab.c"
    break;

  case 20:
#line 152 "parser.y"
                                    {printf("\tPARSER: lista_d_tipo->epsilon\n");}
#line 1706 "parser.tab.c"
    break;

  case 21:
#line 154 "parser.y"
                                                        {printf("\tPARSER: d_tipo->tupla\n");}
#line 1712 "parser.tab.c"
    break;

  case 22:
#line 155 "parser.y"
                                                                                                               {printf("\tPARSER: d_tipo->tabla\n");}
#line 1718 "parser.tab.c"
    break;

  case 23:
#line 156 "parser.y"
                                         {printf("\tPARSER: d_tipo->identificador\n");}
#line 1724 "parser.tab.c"
    break;

  case 24:
#line 157 "parser.y"
                                                            {printf("\tPARSER: d_tipo->subrango\n");}
#line 1730 "parser.tab.c"
    break;

  case 25:
#line 158 "parser.y"
                                      {printf("\tPARSER: d_tipo->ref\n");}
#line 1736 "parser.tab.c"
    break;

  case 26:
#line 159 "parser.y"
                                  {printf("\tPARSER: d_tipo->entero\n"); (yyval.tipo) = TIPO_ENTERO;}
#line 1742 "parser.tab.c"
    break;

  case 27:
#line 160 "parser.y"
                                    {printf("\tPARSER: d_tipo->booleano\n"); (yyval.tipo) = TIPO_BOOLEANO;}
#line 1748 "parser.tab.c"
    break;

  case 28:
#line 161 "parser.y"
                                {printf("\tPARSER: d_tipo->real\n"); (yyval.tipo) = TIPO_REAL;}
#line 1754 "parser.tab.c"
    break;

  case 29:
#line 162 "parser.y"
                                    {printf("\tPARSER: d_tipo->caracter\n"); (yyval.tipo) = TIPO_CARACTER;}
#line 1760 "parser.tab.c"
    break;

  case 30:
#line 163 "parser.y"
                                  {printf("\tPARSER: d_tipo->cadena\n"); (yyval.tipo) = TIPO_CADENA;}
#line 1766 "parser.tab.c"
    break;

  case 31:
#line 165 "parser.y"
                                  {printf("\tPARSER: expresion\n");}
#line 1772 "parser.tab.c"
    break;

  case 32:
#line 166 "parser.y"
                                            {printf("\tPARSER: literal_caracter\n");}
#line 1778 "parser.tab.c"
    break;

  case 33:
#line 168 "parser.y"
                                                                                                     {printf("\tPARSER: lista_campos (estructura)\n");}
#line 1784 "parser.tab.c"
    break;

  case 34:
#line 169 "parser.y"
                                    {printf("\tPARSER: lista_campos->epsilon\n");}
#line 1790 "parser.tab.c"
    break;

  case 35:
#line 171 "parser.y"
                                                                                                          {printf("\tPARSER: lista_d_cte->cadena: %s=%s\n", (yyvsp[-4].val_string), (yyvsp[-2].val_string));}
#line 1796 "parser.tab.c"
    break;

  case 36:
#line 172 "parser.y"
                                                                                                            {printf("\tPARSER: lista_d_cte->caracter: %s=%c\n", (yyvsp[-4].val_string), (yyvsp[-2].val_char));}
#line 1802 "parser.tab.c"
    break;

  case 37:
#line 173 "parser.y"
                                                                                                          {printf("\tPARSER: lista_d_cte->entero: %s=%d\n", (yyvsp[-4].val_string), (yyvsp[-2].val_int));}
#line 1808 "parser.tab.c"
    break;

  case 38:
#line 174 "parser.y"
                                                                                                        {printf("\tPARSER: lista_d_cte->real: %s=%f\n", (yyvsp[-4].val_string), (yyvsp[-2].val_double));}
#line 1814 "parser.tab.c"
    break;

  case 39:
#line 175 "parser.y"
                                                                                                            {printf("\tPARSER: lista_d_cte->booleano: %s=%d\n", (yyvsp[-4].val_string), (yyvsp[-2].val_int));}
#line 1820 "parser.tab.c"
    break;

  case 40:
#line 176 "parser.y"
                                    {printf("\tPARSER: lista_d_cte->epsilon\n");}
#line 1826 "parser.tab.c"
    break;

  case 41:
#line 178 "parser.y"
                                                                           {printf("\tPARSER: lista_d_var->tipo estandar\n");}
#line 1832 "parser.tab.c"
    break;

  case 42:
#line 180 "parser.y"
                                    {printf("\tPARSER: lista_d_var->epsilon\n");}
#line 1838 "parser.tab.c"
    break;

  case 43:
#line 182 "parser.y"
                                                               {printf("\tPARSER: lista_id->mas de uno\n");}
#line 1844 "parser.tab.c"
    break;

  case 44:
#line 183 "parser.y"
                                         {printf("\tPARSER: lista_id->ultimo\n");}
#line 1850 "parser.tab.c"
    break;

  case 45:
#line 188 "parser.y"
                            {
                                printf("\tPARSER: lista_id_var2->linea entera\n"); 
                                (yyval.lista)=(yyvsp[0].tipo); 
                                insertar_id_TS((yyvsp[-2].val_string), (yyvsp[0].tipo), &cola_TS);
                            }
#line 1860 "parser.tab.c"
    break;

  case 46:
#line 193 "parser.y"
                                                                   {printf("\tPARSER: lista_id_var2->mas de uno\n"); (yyval.lista)=(yyvsp[0].lista); insertar_id_TS((yyvsp[-2].val_string), (yyvsp[0].lista), &cola_TS);}
#line 1866 "parser.tab.c"
    break;

  case 47:
#line 194 "parser.y"
                                    {printf("\tPARSER: ultima lista_id_var\n");}
#line 1872 "parser.tab.c"
    break;

  case 48:
#line 196 "parser.y"
                                                              {printf("\tPARSER: lista_id_var->linea entera\n");(yyval.lista)=(yyvsp[0].tipo); insertar_id_TS((yyvsp[-2].val_string), (yyvsp[0].tipo), &cola_TS);}
#line 1878 "parser.tab.c"
    break;

  case 49:
#line 197 "parser.y"
                                                                        {printf("\tPARSER: lista_id_var->mas de uno\n"); insertar_id_TS((yyvsp[-2].val_string), (yyvsp[0].lista), &cola_TS);}
#line 1884 "parser.tab.c"
    break;

  case 50:
#line 202 "parser.y"
                            {
                                printf("\tPARSER: lista_id_ent->linea entera\n"); 
                                (yyval.lista)=(yyvsp[0].tipo);
                                fila = insertar_id_TS((yyvsp[-2].val_string), (yyvsp[0].tipo), &cola_TS);
                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INPUT, &(fila->id), NULL, NULL);
                            }
#line 1895 "parser.tab.c"
    break;

  case 51:
#line 209 "parser.y"
                            {
                                printf("\tPARSER: lista_id_ent2->mas de uno\n");
                                (yyval.lista)=(yyvsp[0].lista);
                                fila = insertar_id_TS((yyvsp[-2].val_string), (yyvsp[0].lista), &cola_TS);
                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INPUT, &(fila->id), NULL, NULL);
                            }
#line 1906 "parser.tab.c"
    break;

  case 52:
#line 215 "parser.y"
                                    {printf("\tPARSER: ultima lista_id_ent2\n");}
#line 1912 "parser.tab.c"
    break;

  case 53:
#line 218 "parser.y"
                            {
                                printf("\tPARSER: lista_id_ent->linea entera\n");
                                (yyval.lista)=(yyvsp[0].tipo);
                                fila = insertar_id_TS((yyvsp[-2].val_string), (yyvsp[0].tipo), &cola_TS);
                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INPUT, &(fila->id), NULL, NULL);
                            }
#line 1923 "parser.tab.c"
    break;

  case 54:
#line 225 "parser.y"
                            {
                                printf("\tPARSER: lista_id_ent->mas de uno\n");
                                fila = insertar_id_TS((yyvsp[-2].val_string), (yyvsp[0].lista), &cola_TS);
                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INPUT, &(fila->id), NULL, NULL);
                            }
#line 1933 "parser.tab.c"
    break;

  case 55:
#line 233 "parser.y"
                            {
                                printf("\tPARSER: lista_id_sal->linea entera\n"); 
                                (yyval.lista)=(yyvsp[0].tipo);
                                id = TS_consultar_id((yyvsp[-2].val_string), cabeza_TS);
                                if (id == -1) {
                                    fila = insertar_id_TS((yyvsp[-2].val_string), (yyvsp[0].tipo), &cola_TS);
                                    id = fila->id;
                                }
                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_OUTPUT, &id, NULL, NULL);
                            }
#line 1948 "parser.tab.c"
    break;

  case 56:
#line 244 "parser.y"
                            {
                                printf("\tPARSER: lista_id_sal2->mas de uno\n");
                                (yyval.lista)=(yyvsp[0].lista);
                                id = TS_consultar_id((yyvsp[-2].val_string), cabeza_TS);
                                if (id == -1) {
                                    fila = insertar_id_TS((yyvsp[-2].val_string), (yyvsp[0].lista), &cola_TS);
                                    id = fila->id;
                                }
                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_OUTPUT, &id, NULL, NULL);
                            }
#line 1963 "parser.tab.c"
    break;

  case 57:
#line 254 "parser.y"
                                    {printf("\tPARSER: ultima lista_id_sal2\n");}
#line 1969 "parser.tab.c"
    break;

  case 58:
#line 257 "parser.y"
                            {
                                printf("\tPARSER: lista_id_sal->linea entera\n");
                                (yyval.lista)=(yyvsp[0].tipo);
                                id = TS_consultar_id((yyvsp[-2].val_string), cabeza_TS);
                                if (id == -1) {
                                    fila = insertar_id_TS((yyvsp[-2].val_string), (yyvsp[0].tipo), &cola_TS);
                                    id = fila->id;
                                }
                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_OUTPUT, &id, NULL, NULL);
                            }
#line 1984 "parser.tab.c"
    break;

  case 59:
#line 268 "parser.y"
                            {
                                printf("\tPARSER: lista_id_sal->mas de uno\n");
                                id = TS_consultar_id((yyvsp[-2].val_string), cabeza_TS);
                                if (id == -1) {
                                    fila = insertar_id_TS((yyvsp[-2].val_string), (yyvsp[0].lista), &cola_TS);
                                    id = fila->id;
                                }
                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_OUTPUT, &id, NULL, NULL);
                            }
#line 1998 "parser.tab.c"
    break;

  case 60:
#line 281 "parser.y"
                                 {printf("\tPARSER: decl_ent_sal->entradas\n");}
#line 2004 "parser.tab.c"
    break;

  case 61:
#line 282 "parser.y"
                                          {printf("\tPARSER: decl_ent_sal->entradas y salidas\n");}
#line 2010 "parser.tab.c"
    break;

  case 62:
#line 283 "parser.y"
                                 {printf("\tPARSER: decl_ent_sal->salidas\n");}
#line 2016 "parser.tab.c"
    break;

  case 63:
#line 285 "parser.y"
                                                                      {printf("\tPARSER: decl_ent\n");}
#line 2022 "parser.tab.c"
    break;

  case 64:
#line 287 "parser.y"
                                                                      {printf("\tPARSER: decl_sal\n");}
#line 2028 "parser.tab.c"
    break;

  case 65:
#line 289 "parser.y"
                                               {
                                                    printf("\tPARSER: exp_a -> suma\n");
                                                    id = TS_crear_variable_temporal(&cola_TS);
                                                    (yyval.e).place = id;
                                                    *op1 = (yyvsp[-2].e).place;
                                                    *op2 = (yyvsp[0].e).place;
                                                    if ((yyvsp[-2].e).type == TIPO_ENTERO) {
                                                        if ((yyvsp[0].e).type == TIPO_ENTERO) {
                                                            TS_modificar_tipo(&cabeza_TS, id, TIPO_ENTERO);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_SUMA_ENTERO, op1, op2, &id);
                                                            (yyval.e).type = TIPO_ENTERO;
                                                        } else if ((yyvsp[0].e).type == TIPO_REAL) {
                                                            TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op1, NULL, &id);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_SUMA_REAL, &id, op2, &id);
                                                            (yyval.e).type = TIPO_REAL;
                                                        } else {
                                                            printf("ERROR: Operando2 de tipo incorrecto\n");
                                                            errorFlag = 1;
                                                            (yyval.e).type = TIPO_ERROR;
                                                        }
                                                    } else if ((yyvsp[-2].e).type == TIPO_REAL) {
                                                        if ((yyvsp[0].e).type == TIPO_ENTERO) {
                                                            TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op2, NULL, &id);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_SUMA_REAL, op1, &id, &id);
                                                            (yyval.e).type = TIPO_REAL;
                                                        } else if ((yyvsp[0].e).type == TIPO_REAL) {
                                                            TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_SUMA_REAL, op1, op2, &id);
                                                            (yyval.e).type = TIPO_REAL;
                                                        } else {
                                                            printf("ERROR: Operando2 de tipo incorrecto\n");
                                                            errorFlag = 1;
                                                            (yyval.e).type = TIPO_ERROR;
                                                        }
                                                    } else {
                                                        printf("ERROR: Operando1 de tipo incorrecto\n");
                                                        errorFlag = 1;
                                                        (yyval.e).type = TIPO_ERROR;
                                                    }
                                                }
#line 2075 "parser.tab.c"
    break;

  case 66:
#line 331 "parser.y"
                                                {
                    
                                                    printf("\tPARSER: exp_a -> resta\n");
                                                    id = TS_crear_variable_temporal(&cola_TS);
                                                    (yyval.e).place = id;
                                                    *op1 = (yyvsp[-2].e).place;
                                                    *op2 = (yyvsp[0].e).place;
                                                    if ((yyvsp[-2].e).type == TIPO_ENTERO) {
                                                        if ((yyvsp[0].e).type == TIPO_ENTERO) {
                                                            TS_modificar_tipo(&cabeza_TS, id, TIPO_ENTERO);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_RESTA_ENTERO, op1, op2, &id);
                                                            (yyval.e).type = TIPO_ENTERO;
                                                        } else if ((yyvsp[0].e).type == TIPO_REAL) {
                                                            TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op1, NULL, &id);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_RESTA_REAL, &id, op2, &id);
                                                            (yyval.e).type = TIPO_REAL;
                                                        } else {
                                                            printf("ERROR: Operando2 de tipo incorrecto\n");
                                                            errorFlag = 1;
                                                            (yyval.e).type = TIPO_ERROR;
                                                        }
                                                    } else if ((yyvsp[-2].e).type == TIPO_REAL) {
                                                        if ((yyvsp[0].e).type == TIPO_ENTERO) {
                                                            TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op2, NULL, &id);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_RESTA_REAL, op1, &id, &id);
                                                            (yyval.e).type = TIPO_REAL;
                                                        } else if ((yyvsp[0].e).type == TIPO_REAL) {
                                                            TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_RESTA_REAL, op1, op2, &id);
                                                            (yyval.e).type = TIPO_REAL;
                                                        } else {
                                                            printf("ERROR: Operando2 de tipo incorrecto\n");
                                                            errorFlag = 1;
                                                            (yyval.e).type = TIPO_ERROR;
                                                        }
                                                    } else {
                                                        printf("ERROR: Operando1 de tipo incorrecto\n");
                                                        errorFlag = 1;
                                                        (yyval.e).type = TIPO_ERROR;
                                                    }
                                                }
#line 2123 "parser.tab.c"
    break;

  case 67:
#line 374 "parser.y"
                                                        {
                                                            printf("\tPARSER: exp_a -> multiplicacion\n");
                                                            id = TS_crear_variable_temporal(&cola_TS);
                                                            (yyval.e).place = id;
                                                            *op1 = (yyvsp[-2].e).place;
                                                            *op2 = (yyvsp[0].e).place;
                                                            if ((yyvsp[-2].e).type == TIPO_ENTERO) {
                                                                if ((yyvsp[0].e).type == TIPO_ENTERO) {
                                                                    TS_modificar_tipo(&cabeza_TS, id, TIPO_ENTERO);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_MULTIPLICACION_ENTERO, op1, op2, &id);
                                                                    (yyval.e).type = TIPO_ENTERO;
                                                                } else if ((yyvsp[0].e).type == TIPO_REAL) {
                                                                    TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op1, NULL, &id);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_MULTIPLICACION_REAL, &id, op2, &id);
                                                                    (yyval.e).type = TIPO_REAL;
                                                                } else {
                                                                    printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                    errorFlag = 1;
                                                                    (yyval.e).type = TIPO_ERROR;
                                                                }
                                                            } else if ((yyvsp[-2].e).type == TIPO_REAL) {
                                                                if ((yyvsp[0].e).type == TIPO_ENTERO) {
                                                                    TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op2, NULL, &id);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_MULTIPLICACION_REAL, op1, &id, &id);
                                                                    (yyval.e).type = TIPO_REAL;
                                                                } else if ((yyvsp[0].e).type == TIPO_REAL) {
                                                                    TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_MULTIPLICACION_REAL, op1, op2, &id);
                                                                    (yyval.e).type = TIPO_REAL;
                                                                } else {
                                                                    printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                    errorFlag = 1;
                                                                    (yyval.e).type = TIPO_ERROR;
                                                                }
                                                            } else {
                                                                printf("ERROR: Operando1 de tipo incorrecto\n");
                                                                errorFlag = 1;
                                                                (yyval.e).type = TIPO_ERROR;
                                                            }
                                                        }
#line 2170 "parser.tab.c"
    break;

  case 68:
#line 416 "parser.y"
                                                   {
                                                        printf("\tPARSER: exp_a -> division\n");
                                                        id = TS_crear_variable_temporal(&cola_TS);
                                                        TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                        (yyval.e).place = id;
                                                        (yyval.e).type = TIPO_REAL;
                                                        *op1 = (yyvsp[-2].e).place;
                                                        *op2 = (yyvsp[0].e).place;
                                                        //TODO: DECIDIR QUE VAMOS A HACER CON LA DIVISIÓN DE DOS ENTEROS. Si lo dejamos como está, tanto 2/3 y 2 div 3 hacen lo mismo...
                                                        if ((yyvsp[-2].e).type == TIPO_ENTERO) {
                                                            if ((yyvsp[0].e).type == TIPO_ENTERO) {
                                                                id2 = TS_crear_variable_temporal(&cola_TS);
                                                                TS_modificar_tipo(&cabeza_TS, id2, TIPO_REAL);
                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op1, NULL, &id);
                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op2, NULL, &id2);
                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_DIVISION_ENTERO, &id, &id2, &id);
                                                            } else if ((yyvsp[0].e).type == TIPO_REAL) {
                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op1, NULL, &id);
                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_DIVISION_REAL, &id, op2, &id);
                                                            } else {
                                                                printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                errorFlag = 1;
                                                                (yyval.e).type = TIPO_ERROR;
                                                            }
                                                        } else if ((yyvsp[-2].e).type == TIPO_REAL) {
                                                            if ((yyvsp[0].e).type == TIPO_ENTERO) {
                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op2, NULL, &id);
                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_DIVISION_REAL, op1, &id, &id);
                                                            } else if ((yyvsp[0].e).type == TIPO_REAL) {
                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_DIVISION_REAL, op1, op2, &id);
                                                            } else {
                                                                printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                errorFlag = 1;
                                                                (yyval.e).type = TIPO_ERROR;
                                                            }
                                                        } else {
                                                            printf("ERROR: Operando1 de tipo incorrecto\n");
                                                            errorFlag = 1;
                                                            (yyval.e).type = TIPO_ERROR;
                                                        }
                                                    }
#line 2216 "parser.tab.c"
    break;

  case 69:
#line 457 "parser.y"
                                            {
                                                printf("\tPARSER: exp_a -> mod(resto)\n");
                                                id = TS_crear_variable_temporal(&cola_TS);
                                                (yyval.e).place = id;
                                                *op1 = (yyvsp[-2].e).place;
                                                *op2 = (yyvsp[0].e).place;
                                                //TODO: DECIDIR QUE VAMOS A HACER CON EL RESTO.
                                                if ((yyvsp[-2].e).type == TIPO_ENTERO) {
                                                    if ((yyvsp[0].e).type == TIPO_ENTERO) {
                                                        TS_modificar_tipo(&cabeza_TS, id, TIPO_ENTERO);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_MOD_ENTERO, op1, op2, &id);
                                                        (yyval.e).type = TIPO_ENTERO;
                                                    } else if ((yyvsp[0].e).type == TIPO_REAL) {
                                                        TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op1, NULL, &id);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_MOD_REAL, &id, op2, &id);
                                                        (yyval.e).type = TIPO_REAL;
                                                    } else {
                                                        printf("ERROR: Operando2 de tipo incorrecto\n");
                                                        errorFlag = 1;
                                                        (yyval.e).type = TIPO_ERROR;
                                                    }
                                                } else if ((yyvsp[-2].e).type == TIPO_REAL) {
                                                    if ((yyvsp[0].e).type == TIPO_ENTERO) {
                                                        TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, op2, NULL, &id);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_MOD_REAL, op1, &id, &id);
                                                        (yyval.e).type = TIPO_REAL;
                                                    } else if ((yyvsp[0].e).type == TIPO_REAL) {
                                                        TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_MOD_REAL, op1, op2, &id);
                                                        (yyval.e).type = TIPO_REAL;
                                                    } else {
                                                        printf("ERROR: Operando2 de tipo incorrecto\n");
                                                        errorFlag = 1;
                                                        (yyval.e).type = TIPO_ERROR;
                                                    }
                                                } else {
                                                    printf("ERROR: Operando1 de tipo incorrecto\n");
                                                    errorFlag = 1;
                                                    (yyval.e).type = TIPO_ERROR;
                                                }
                                            }
#line 2264 "parser.tab.c"
    break;

  case 70:
#line 500 "parser.y"
                                            {
                                                printf("\tPARSER: exp_a -> division entera\n");
                                                id = TS_crear_variable_temporal(&cola_TS);
                                                (yyval.e).place = id;
                                                *op1 = (yyvsp[-2].e).place;
                                                *op2 = (yyvsp[0].e).place;
                                                TS_modificar_tipo(&cabeza_TS, id, TIPO_ENTERO);
                                                (yyval.e).type = TIPO_ENTERO;
                                                //TODO: DECIDIR QUE VAMOS A HACER CON LA DIVISIÓN DE DOS ENTEROS. Si lo dejamos como está, tanto 2/3 y 2 div 3 hacen lo mismo...
                                                if ((yyvsp[-2].e).type == TIPO_ENTERO) {
                                                    if ((yyvsp[0].e).type == TIPO_ENTERO) {
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_DIVENT, op1, op2, &id);
                                                    } else if ((yyvsp[0].e).type == TIPO_REAL) {
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_REAL2INT, op2, NULL, &id);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_DIVENT, op1, &id, &id);
                                                    } else {
                                                        printf("ERROR: Operando2 de tipo incorrecto\n");
                                                        errorFlag = 1;
                                                        (yyval.e).type = TIPO_ERROR;
                                                    }
                                                } else if ((yyvsp[-2].e).type == TIPO_REAL) {
                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_REAL2INT, op1, NULL, &id);
                                                    if ((yyvsp[0].e).type == TIPO_ENTERO) {
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_DIVENT, &id, op2, &id);
                                                    } else if ((yyvsp[0].e).type == TIPO_REAL) {
                                                        id2 = TS_crear_variable_temporal(&cola_TS);
                                                        TS_modificar_tipo(&cabeza_TS, id2, TIPO_ENTERO);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_REAL2INT, op2, NULL, &id2);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_DIVENT, &id, &id2, &id);
                                                    } else {
                                                        printf("ERROR: Operando2 de tipo incorrecto\n");
                                                        errorFlag = 1;
                                                        (yyval.e).type = TIPO_ERROR;
                                                    }
                                                } else {
                                                    printf("ERROR: Operando1 de tipo incorrecto\n");
                                                    errorFlag = 1;
                                                    (yyval.e).type = TIPO_ERROR;
                                                }
                                            }
#line 2309 "parser.tab.c"
    break;

  case 71:
#line 540 "parser.y"
                                                                        {
                                                                            printf("\tPARSER: exp_a -> ()\n");
                                                                            (yyval.e) = (yyvsp[-1].e);
                                                                        }
#line 2318 "parser.tab.c"
    break;

  case 72:
#line 544 "parser.y"
                                    {
                                        printf("\tPARSER: exp_a -> operando\n");
                                        (yyval.e) = (yyvsp[0].e);
                                        /*if ($$.type == TIPO_BOOLEANO){
                                            $$.TRUE = makelist();
                                            insert_list(&($$.TRUE),tabla_cuadruplas.nextquad);
                                            $$.FALSE = makelist();
                                            insert_list(&($$.FALSE),tabla_cuadruplas.nextquad+1);
                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_VERDADERO, &($1.place), NULL, NULL);
                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL);
                                                        
                                            
                                        }*/
                                    
                                    }
#line 2338 "parser.tab.c"
    break;

  case 73:
#line 559 "parser.y"
                                            {
                                                printf("\tPARSER: exp_a -> real\n");
                                            }
#line 2346 "parser.tab.c"
    break;

  case 74:
#line 562 "parser.y"
                                            {
                                                printf("\tPARSER: exp_a -> entero\n");
                                            }
#line 2354 "parser.tab.c"
    break;

  case 75:
#line 565 "parser.y"
                                            {
                                                printf("\tPARSER: exp_a -> numero negativo\n");
                                                //Creamos variable temporal.
                                                id = TS_crear_variable_temporal(&cola_TS);
                                                (yyval.e).place = id;
                                                *op1 = (yyvsp[0].e).place;
                                                if ((yyvsp[0].e).type == TIPO_ENTERO){
                                                    TS_modificar_tipo(&cabeza_TS, id, TIPO_ENTERO);
                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_RESTA_UNITARIA_ENTERO, op1, NULL, &id);
                                                    (yyval.e).type = TIPO_ENTERO;
                                                } else if((yyvsp[0].e).type == TIPO_REAL) {
                                                    TS_modificar_tipo(&cabeza_TS, id, TIPO_REAL);
                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_RESTA_UNITARIA_REAL, op1, NULL, &id);
                                                    (yyval.e).type = TIPO_REAL;
                                                } else {
                                                    printf("ERROR: Operando de tipo incorrecto\n");
                                                    errorFlag = 1;
                                                    (yyval.e).type = TIPO_ERROR;
                                                }
                                                
                                            }
#line 2380 "parser.tab.c"
    break;

  case 76:
#line 586 "parser.y"
                                              {
                                                printf("\tPARSER: exp_a -> y\n");
                                                if ((yyvsp[-3].e).type == TIPO_BOOLEANO) {
                                                    if ((yyvsp[0].e).type == TIPO_BOOLEANO) {
                                                        backpatch((yyvsp[-3].e).TRUE, (yyvsp[-1].val_int), &tabla_cuadruplas);
                                                        (yyval.e).FALSE = merge((yyvsp[-3].e).FALSE, (yyvsp[0].e).FALSE);
                                                        (yyval.e).TRUE = (yyvsp[0].e).TRUE;
                                                        (yyval.e).type = TIPO_BOOLEANO;
                                                    } else {
                                                        printf("ERROR: Operando2 de tipo distinto a booleano.\n");
                                                        errorFlag = 1;
                                                        (yyval.e).type = TIPO_ERROR;
                                                    }
                                                } else {
                                                    printf("ERROR: Operando1 de tipo distinto a booleano.\n");
                                                    errorFlag = 1;
                                                    (yyval.e).type = TIPO_ERROR;
                                                }
                                            }
#line 2404 "parser.tab.c"
    break;

  case 77:
#line 605 "parser.y"
                                              {
                                                printf("\tPARSER: exp_a -> o\n");
                                                
                                               
                                                if ((yyvsp[-3].e).type == TIPO_BOOLEANO) {
                                                    if ((yyvsp[0].e).type == TIPO_BOOLEANO) {
                                                        backpatch((yyvsp[-3].e).FALSE, (yyvsp[-1].val_int), &tabla_cuadruplas);
                                                        (yyval.e).TRUE = merge((yyvsp[-3].e).TRUE, (yyvsp[0].e).TRUE);
                                                        (yyval.e).FALSE = (yyvsp[0].e).FALSE;
                                                        (yyval.e).type = TIPO_BOOLEANO;
                                                    } else {
                                                        printf("ERROR: Operando2 de tipo distinto a booleano.\n");
                                                        errorFlag = 1;
                                                        (yyval.e).type = TIPO_ERROR;
                                                    }
                                                } else {
                                                    printf("ERROR: Operando1 de tipo distinto a booleano.\n");
                                                    errorFlag = 1;
                                                    (yyval.e).type = TIPO_ERROR;
                                                }
                                                
                                            }
#line 2431 "parser.tab.c"
    break;

  case 78:
#line 627 "parser.y"
                                    {
                                        printf("\tPARSER: exp_a -> no\n");
                                        //id = TS_crear_variable_temporal(&cola_TS);
                                        if ((yyvsp[0].e).type == TIPO_BOOLEANO) {
                                            //TS_modificar_tipo(&cabeza_TS, id, TIPO_BOOLEANO);
                                            //insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_B_NO, &($2.place), NULL, &id);
                                            (yyval.e).TRUE = (yyvsp[0].e).FALSE;
                                            (yyval.e).FALSE = (yyvsp[0].e).TRUE;
                                            (yyval.e).type = TIPO_BOOLEANO;
                                        } else {
                                            printf("ERROR: Operando de tipo distinto a booleano.\n");
                                            errorFlag = 1;
                                            (yyval.e).type = TIPO_ERROR;
                                        }
                                    }
#line 2451 "parser.tab.c"
    break;

  case 79:
#line 642 "parser.y"
                                            {
                                                printf("\tPARSER: exp_a -> %d\n",(yyvsp[0].val_int));
                                                (yyval.e).type = TIPO_BOOLEANO;
                                                
                                            }
#line 2461 "parser.tab.c"
    break;

  case 80:
#line 647 "parser.y"
                                                            {
                                                                printf("\tPARSER: exp_a -> exp_a %s exp_a\n",(yyvsp[-1].val_string));
                                                                (yyval.e).type = TIPO_BOOLEANO;
                                                                //id = TS_crear_variable_temporal(&cola_TS);
                                                                //TS_modificar_tipo(&cabeza_TS, id, TIPO_BOOLEANO);
                                                                int operadorEntero = -1;
                                                                int operadorReal = -1;
                                                                if (strcmp((yyvsp[-1].val_string), "<") == 0) {
                                                                    operadorEntero =  OPERADOR_GOTO_MENOR_ENTERO;
                                                                    operadorReal =  OPERADOR_GOTO_MENOR_REAL;
                                                                } else if (strcmp((yyvsp[-1].val_string), ">") == 0) {
                                                                    operadorEntero =  OPERADOR_GOTO_MAYOR_ENTERO;
                                                                    operadorReal = OPERADOR_GOTO_MAYOR_REAL;
                                                                } else if (strcmp((yyvsp[-1].val_string), "<=") == 0) {
                                                                    operadorEntero = OPERADOR_GOTO_MEOI_ENTERO;
                                                                    operadorReal = OPERADOR_GOTO_MEOI_REAL;
                                                                } else if (strcmp((yyvsp[-1].val_string), ">=") == 0) {
                                                                    operadorEntero = OPERADOR_GOTO_MAOI_ENTERO;
                                                                    operadorReal = OPERADOR_GOTO_MAOI_REAL;
                                                                }
                                                                if (operadorEntero == -1 || operadorReal == -1) {
                                                                    if (strcmp((yyvsp[-1].val_string), "<>") == 0) {
                                                                        if ((yyvsp[-2].e).type == TIPO_ENTERO) {
                                                                            if ((yyvsp[0].e).type == TIPO_ENTERO) {
                                                                                insert_list(&((yyval.e).TRUE), tabla_cuadruplas.nextquad);
                                                                                insert_list(&((yyval.e).FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_DISTINTO_ENTERO, &((yyvsp[-2].e).place), &((yyvsp[0].e).place), NULL);//True 
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL); // False
                                                                                //insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_R_DISTINTO_ENTERO, &($1.place), &($3.place), &id);
                                                                            } else if ((yyvsp[0].e).type == TIPO_REAL) {
                                                                                id2 = TS_crear_variable_temporal(&cola_TS);
                                                                                TS_modificar_tipo(&cabeza_TS, id2, TIPO_REAL);
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, &((yyvsp[-2].e).place), NULL, &id2);
                                                                                
                                                                                insert_list(&((yyval.e).TRUE), tabla_cuadruplas.nextquad);
                                                                                insert_list(&((yyval.e).FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_DISTINTO_REAL, &id2, &((yyvsp[0].e).place), NULL);//True 
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL); // False
                                                                                
                                                                                
                                                                                
                                                                                //insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_R_DISTINTO_ENTERO, &id2, &($3.place), &id);
                                                                            } else {
                                                                                printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                                errorFlag = 1;
                                                                                (yyval.e).type = TIPO_ERROR;
                                                                            }
                                                                        } else if ((yyvsp[-2].e).type == TIPO_REAL) {
                                                                            if ((yyvsp[0].e).type == TIPO_ENTERO) {
                                                                                id2 = TS_crear_variable_temporal(&cola_TS);
                                                                                TS_modificar_tipo(&cabeza_TS, id2, TIPO_REAL);
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, &((yyvsp[0].e).place), NULL, &id2);
                                                                                insert_list(&((yyval.e).TRUE), tabla_cuadruplas.nextquad);
                                                                                insert_list(&((yyval.e).FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_DISTINTO_REAL, &((yyvsp[-2].e).place), &id2, NULL);//True 
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL); // False
                                                                                
                                                                                
                                                                                
                                                                                //insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_R_DISTINTO_ENTERO, &($1.place), &id2, &id);
                                                                            } else if ((yyvsp[0].e).type == TIPO_REAL) {
                                                                            
                                                                                insert_list(&((yyval.e).TRUE), tabla_cuadruplas.nextquad);
                                                                                insert_list(&((yyval.e).FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_DISTINTO_REAL, &((yyvsp[-2].e).place), &((yyvsp[0].e).place), NULL);//True 
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL); // False
                                                                                
                                                                                //insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_R_DISTINTO_REAL, &($1.place), &($3.place), &id);
                                                                            } else {
                                                                                printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                                errorFlag = 1;
                                                                                (yyval.e).type = TIPO_ERROR;
                                                                            }
                                                                        } else if ((yyvsp[-2].e).type == TIPO_BOOLEANO) {
                                                                            if ((yyvsp[0].e).type == TIPO_BOOLEANO) {
                                                                                insert_list(&((yyval.e).TRUE), tabla_cuadruplas.nextquad);
                                                                                
                                                                                insert_list(&((yyval.e).FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_DISTINTO_BOOLEANO, &((yyvsp[-2].e).place), &((yyvsp[0].e).place), NULL);//True 
                                                                                
                                                                                insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL); // False
                                                                                //insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_R_DISTINTO_BOOLEANO, &($1.place), &($3.place), &id);
                                                                            } else {
                                                                                printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                                errorFlag = 1;
                                                                                (yyval.e).type = TIPO_ERROR;
                                                                            }
                                                                        } else {
                                                                            printf("ERROR: Operando1 de tipo incorrecto\n");
                                                                            errorFlag = 1;
                                                                            (yyval.e).type = TIPO_ERROR;
                                                                        }
                                                                    } else {
                                                                        printf("ERROR: Operador inválido\n");
                                                                        errorFlag = 1;
                                                                        (yyval.e).type = TIPO_ERROR;
                                                                    }
                                                                } else {
                                                                    if ((yyvsp[-2].e).type == TIPO_ENTERO) {
                                                                        if ((yyvsp[0].e).type == TIPO_ENTERO) {
                                                                            insert_list(&((yyval.e).TRUE), tabla_cuadruplas.nextquad);
                                                                            insert_list(&((yyval.e).FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                            insertar_cuadrupla(&tabla_cuadruplas, operadorEntero, &((yyvsp[-2].e).place), &((yyvsp[0].e).place), NULL);//True 
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL); // False
                                                                            //insertar_cuadrupla(&tabla_cuadruplas, operadorEntero, &($1.place), &($3.place), &id);
                                                                        } else if ((yyvsp[0].e).type == TIPO_REAL) {
                                                                            
                                                                            id2 = TS_crear_variable_temporal(&cola_TS);
                                                                            TS_modificar_tipo(&cabeza_TS, id2, TIPO_REAL);
                                                                            //TS_modificar_tipo(&cabeza_TS, id, TIPO_BOOLEANO);
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, &((yyvsp[-2].e).place), NULL, &id2);
                                                                            insert_list(&((yyval.e).TRUE), tabla_cuadruplas.nextquad);
                                                                            insert_list(&((yyval.e).FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                            insertar_cuadrupla(&tabla_cuadruplas, operadorReal, &((yyvsp[-2].e).place), &id, NULL);//True 
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL); // False
                                                                            //insertar_cuadrupla(&tabla_cuadruplas, operadorReal, &($1.place), &id, &id2);
                                                                        } else {
                                                                            printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                            errorFlag = 1;
                                                                            (yyval.e).type = TIPO_ERROR;
                                                                        }
                                                                    } else if ((yyvsp[-2].e).type == TIPO_REAL) {
                                                                        if ((yyvsp[0].e).type == TIPO_ENTERO) {
                                                                            
                                                                            id2 = TS_crear_variable_temporal(&cola_TS);
                                                                            TS_modificar_tipo(&cabeza_TS, id2, TIPO_REAL);
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, &((yyvsp[0].e).place), NULL, &id2);
                                                                            
                                                                            insert_list(&((yyval.e).TRUE), tabla_cuadruplas.nextquad);
                                                                            insert_list(&((yyval.e).FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                            insertar_cuadrupla(&tabla_cuadruplas, operadorReal, &id, &((yyvsp[0].e).place), NULL);//True 
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL); // False
                                                                            //insertar_cuadrupla(&tabla_cuadruplas, operadorReal, &id, &($3.place), &id2);
                                                                        } else if ((yyvsp[0].e).type == TIPO_REAL) {
                                                                            insert_list(&((yyval.e).TRUE), tabla_cuadruplas.nextquad);
                                                                            insert_list(&((yyval.e).FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                            insertar_cuadrupla(&tabla_cuadruplas, operadorReal, &((yyvsp[-2].e).place), &((yyvsp[0].e).place), NULL);//True 
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL); // False
                                                                            //insertar_cuadrupla(&tabla_cuadruplas, operadorReal, &($1.place), &($3.place), &id);
                                                                        } else {
                                                                            printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                            errorFlag = 1;
                                                                            (yyval.e).type = TIPO_ERROR;
                                                                        }
                                                                    } else {
                                                                        printf("ERROR: Operando1 de tipo incorrecto\n");
                                                                        errorFlag = 1;
                                                                        (yyval.e).type = TIPO_ERROR;
                                                                    }
                                                                }
                                                            }
#line 2617 "parser.tab.c"
    break;

  case 81:
#line 798 "parser.y"
                                                        {
                                                            printf("\tPARSER: exp_a -> exp_a == exp_a\n");
                                                            (yyval.e).type = TIPO_BOOLEANO;
                                                            
                                                            if ((yyvsp[-2].e).type == TIPO_ENTERO) {
                                                                if ((yyvsp[0].e).type == TIPO_ENTERO) {
                                                                    insert_list(&((yyval.e).TRUE), tabla_cuadruplas.nextquad);
                                                                    insert_list(&((yyval.e).FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_IGUAL_ENTERO, &((yyvsp[-2].e).place), &((yyvsp[0].e).place), NULL);//True 
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL); // False
                                                                } else if ((yyvsp[0].e).type == TIPO_REAL) {
                                                                    id2 = TS_crear_variable_temporal(&cola_TS);
                                                                    TS_modificar_tipo(&cabeza_TS, id2, TIPO_REAL);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, &((yyvsp[-2].e).place), NULL, &id2);
                                                                    insert_list(&((yyval.e).TRUE), tabla_cuadruplas.nextquad);
                                                                    insert_list(&((yyval.e).FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_IGUAL_REAL, &id2, &((yyvsp[0].e).place), NULL);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL);
                                                                } else {
                                                                    printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                    errorFlag = 1;
                                                                    (yyval.e).type = TIPO_ERROR;
                                                                }
                                                            } else if ((yyvsp[-2].e).type == TIPO_REAL) {
                                                                if ((yyvsp[0].e).type == TIPO_ENTERO) {
                                                                    id2 = TS_crear_variable_temporal(&cola_TS);
                                                                    TS_modificar_tipo(&cabeza_TS, id2, TIPO_REAL);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_INT2REAL, &((yyvsp[0].e).place), NULL, &id2);
                                                                    insert_list(&((yyval.e).TRUE), tabla_cuadruplas.nextquad);
                                                                    insert_list(&((yyval.e).FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                    //insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_R_IGUAL_ENTERO, &($1.place), &id2, &id);
                                                                    // TODO: Como guardamos if id1.val oprel.val id2.val goto
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_IGUAL_REAL, &((yyvsp[-2].e).place), &id2, NULL);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL);
                                                                } else if ((yyvsp[0].e).type == TIPO_REAL) {
                                                                    insert_list(&((yyval.e).TRUE), tabla_cuadruplas.nextquad);
                                                                    insert_list(&((yyval.e).FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                    // TODO: Como guardamos if id1.val oprel.val id2.val goto
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_IGUAL_REAL, &((yyvsp[-2].e).place), &((yyvsp[0].e).place), NULL);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL);
                                                                    //insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_R_IGUAL_REAL, &($1.place), &($3.place), &id);
                                                                } else {
                                                                    printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                    errorFlag = 1;
                                                                    (yyval.e).type = TIPO_ERROR;
                                                                }
                                                            } else if ((yyvsp[-2].e).type == TIPO_BOOLEANO) {
                                                                if ((yyvsp[0].e).type == TIPO_BOOLEANO) {
                                                                    insert_list(&((yyval.e).TRUE), tabla_cuadruplas.nextquad);
                                                                    insert_list(&((yyval.e).FALSE),(tabla_cuadruplas.nextquad)+1);
                                                                    // TODO: Como guardamos if id1.val oprel.val id2.val goto
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_IGUAL_BOOLEANO, &((yyvsp[-2].e).place), &((yyvsp[0].e).place), NULL);
                                                                    insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL);
                                                                    //insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_R_IGUAL_BOOLEANO, &($1.place), &($3.place), &id);
                                                                } else {
                                                                    printf("ERROR: Operando2 de tipo incorrecto\n");
                                                                    errorFlag = 1;
                                                                    (yyval.e).type = TIPO_ERROR;
                                                                }
                                                            } else {
                                                                printf("ERROR: Operando1 de tipo incorrecto\n");
                                                                errorFlag = 1;
                                                                (yyval.e).type = TIPO_ERROR;
                                                            }
                                                        }
#line 2687 "parser.tab.c"
    break;

  case 82:
#line 864 "parser.y"
                                {
                                    printf("\tPARSER: expresion -> operaciones aritméticas o booleanas\n");
                                    (yyval.e) = (yyvsp[0].e);
                                }
#line 2696 "parser.tab.c"
    break;

  case 83:
#line 868 "parser.y"
                                   {printf("\tPARSER: expresion -> llamada a funcion\n");}
#line 2702 "parser.tab.c"
    break;

  case 84:
#line 870 "parser.y"
                                            {
                                                printf("\tPARSER: operando -> (identificador) %s\n", (yyvsp[0].val_string));
                                                id = TS_consultar_id((yyvsp[0].val_string), cabeza_TS);
                                                if (id == -1) {
                                                    (yyval.e).type = TIPO_ERROR;
                                                    printf("ERROR: Variable no declarada.\n");
                                                    errorFlag = 1;
                                                } else {
                                                    (yyval.e).place = id;
                                                    (yyval.e).type = TS_consultar_tipo(id, cabeza_TS);
                                                    (yyval.e).TRUE = makelist();
                                                    (yyval.e).FALSE = makelist();
                                                    if ((yyval.e).type == TIPO_BOOLEANO){
                                                       /* $$.TRUE = makelist();
                                                        insert_list(&($$.TRUE),tabla_cuadruplas.nextquad);
                                                        $$.FALSE = makelist();
                                                        insert_list(&($$.FALSE),tabla_cuadruplas.nextquad+1);
                                                        int x = TS_consultar_id($1,cabeza_TS);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO_VERDADERO, &(x), NULL, NULL);
                                                        insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, NULL);*/
                                                                    
                                                        
                                                    }
                                                }
                                            }
#line 2732 "parser.tab.c"
    break;

  case 85:
#line 896 "parser.y"
                                                                        {printf("\tPARSER: operando -> operando[expresion]\n");}
#line 2738 "parser.tab.c"
    break;

  case 86:
#line 897 "parser.y"
                                        {printf("\tPARSER: operando -> operando ref\n");}
#line 2744 "parser.tab.c"
    break;

  case 87:
#line 900 "parser.y"
                                                                                    {
                                                                                        printf("\tPARSER: instrucciones -> lista/composicion de instrucciones\n");
                                                                                        if (!empty((yyvsp[-3].e).NEXT)){
                                                                                            backpatch((yyvsp[-3].e).NEXT, (yyvsp[-1].val_int), &tabla_cuadruplas);
                                                                                        }
                                                                                        (yyval.e).NEXT = (yyvsp[0].e).NEXT;
                                                                                    }
#line 2756 "parser.tab.c"
    break;

  case 88:
#line 907 "parser.y"
                                        {
                                            printf("\tPARSER: instrucciones -> una instruccion\n");
                                            (yyval.e).NEXT = (yyvsp[0].e).NEXT;
                                        }
#line 2765 "parser.tab.c"
    break;

  case 89:
#line 912 "parser.y"
                                        {
                                            printf("\tPARSER: instruccion -> continuar\n");
                                        }
#line 2773 "parser.tab.c"
    break;

  case 90:
#line 915 "parser.y"
                                    {
                                        printf("\tPARSER: instruccion -> instruccion de asignacion\n");
                                        (yyval.e).NEXT = (yyvsp[0].e).NEXT;
                                        
                                    }
#line 2783 "parser.tab.c"
    break;

  case 91:
#line 920 "parser.y"
                                    {printf("\tPARSER: instruccion -> instruccion alternativa(if)\n");}
#line 2789 "parser.tab.c"
    break;

  case 92:
#line 921 "parser.y"
                                  {printf("\tPARSER: instruccion -> instruccion iterativa\n");}
#line 2795 "parser.tab.c"
    break;

  case 93:
#line 922 "parser.y"
                                  {printf("\tPARSER: instruccion -> llamada a accion\n");}
#line 2801 "parser.tab.c"
    break;

  case 94:
#line 924 "parser.y"
                                                            {
                                                                printf("\tPARSER: asignacion -> operando := expresion\n");
                                                                *op1 = (yyvsp[0].e).place;
                                                                if ((yyvsp[-2].e).type != (yyvsp[0].e).type) {
                                                                    printf("ERROR: Asignación de tipos incorrectos.\n");
                                                                    errorFlag = 1;
                                                                } else {
                                                                    switch ((yyvsp[-2].e).type) {
                                                                        case TIPO_ENTERO:
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_ASIGNACION_ENTERO, op1, NULL, &((yyvsp[-2].e).place));
                                                                            break;
                                                                        case TIPO_REAL:
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_ASIGNACION_REAL, op1, NULL, &((yyvsp[-2].e).place));
                                                                            break;
                                                                        case TIPO_CARACTER:
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_ASIGNACION_CARACTER, op1, NULL, &((yyvsp[-2].e).place));
                                                                            break;
                                                                        case TIPO_CADENA:
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_ASIGNACION_CADENA, op1, NULL, &((yyvsp[-2].e).place));
                                                                            break;
                                                                        case TIPO_BOOLEANO:
                                                                            backpatch((yyvsp[0].e).TRUE, tabla_cuadruplas.nextquad, &tabla_cuadruplas);
                                                                            backpatch((yyvsp[0].e).FALSE,tabla_cuadruplas.nextquad + 2, &tabla_cuadruplas);
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_ASIGNACION_BOOLEANO_TRUE, NULL, NULL, &((yyvsp[-2].e).place));
                                                                            // En caso de OPERADOR_GOTO: El primer operando es un puntero a un entero que representa 
                                                                            // la cuadrupla y no el id de la tabla de simbolos.
                                                                            
                                                                            int* y;
                                                                            y = (int*)malloc(sizeof(int));
                                                                            *y = tabla_cuadruplas.nextquad + 2;
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_GOTO, NULL, NULL, y);
                                                                            insertar_cuadrupla(&tabla_cuadruplas, OPERADOR_ASIGNACION_BOOLEANO_FALSE, NULL, NULL, &((yyvsp[-2].e).place));
                                                                            
                                                                            // NO hace falta porque la lista ya está incializada a null.
                                                                            // Es decir, es una estructura con doS punteros(cabeza, cola) que apuntan a NULL.
                                                                            //$$.NEXT = makelist();
                                                                            break;
                                                                    }
                                                                }
                                                            }
#line 2846 "parser.tab.c"
    break;

  case 95:
#line 965 "parser.y"
                                                                                        {printf("\tPARSER: alternativa -> if expresion -> instrucciones fsi\n");}
#line 2852 "parser.tab.c"
    break;

  case 96:
#line 967 "parser.y"
                                                                             {printf("\tPARSER: lista_opciones -> [] entonces instrucciones lista_opciones\n");}
#line 2858 "parser.tab.c"
    break;

  case 97:
#line 968 "parser.y"
                                    {printf("\tPARSER: lista_opciones -> epsilon (no hay si_no_si)\n");}
#line 2864 "parser.tab.c"
    break;

  case 98:
#line 970 "parser.y"
                                     {printf("\tPARSER: iteracion -> it_cota_fija(para)\n");}
#line 2870 "parser.tab.c"
    break;

  case 99:
#line 971 "parser.y"
                                    {printf("\tPARSER: iteracion -> it_cota_exp(mientras)\n");}
#line 2876 "parser.tab.c"
    break;

  case 100:
#line 973 "parser.y"
                                                                                   {printf("\tPARSER: it_cota_exp -> mientras\n");}
#line 2882 "parser.tab.c"
    break;

  case 101:
#line 975 "parser.y"
                                                                                                                            {printf("\tPARSER: it_cota_fija -> para\n");}
#line 2888 "parser.tab.c"
    break;

  case 102:
#line 977 "parser.y"
                                                               {printf("\tPARSER: accion_d -> implementacion de accion\n");}
#line 2894 "parser.tab.c"
    break;

  case 103:
#line 979 "parser.y"
                                                                                  {printf("\tPARSER: funcion_d -> implementacion de funcion\n");}
#line 2900 "parser.tab.c"
    break;

  case 104:
#line 981 "parser.y"
                                                                                                                     {printf("\tPARSER: a_cabecera -> cabecera de accion\n");}
#line 2906 "parser.tab.c"
    break;

  case 105:
#line 983 "parser.y"
                                                                                                                                    {printf("\tPARSER: f_cabecera -> cabecera de funcion");}
#line 2912 "parser.tab.c"
    break;

  case 106:
#line 985 "parser.y"
                                                                      {printf("\tPARSER: d_par_form -> ent --; sal ---;\n");}
#line 2918 "parser.tab.c"
    break;

  case 107:
#line 986 "parser.y"
                                    {printf("\tPARSER: d_par_form -> epsilon\n");}
#line 2924 "parser.tab.c"
    break;

  case 108:
#line 988 "parser.y"
                                                                                       {printf("\tPARSER: d_p_form -> ent listaIdentificadores : tipo;\n");}
#line 2930 "parser.tab.c"
    break;

  case 109:
#line 989 "parser.y"
                                                                                       {printf("\tPARSER: d_p_form -> sal listaIdentificadores : tipo;\n");}
#line 2936 "parser.tab.c"
    break;

  case 110:
#line 990 "parser.y"
                                                                                          {printf("\tPARSER: d_p_form -> e/s listaIdentificadores : tipo;\n");}
#line 2942 "parser.tab.c"
    break;

  case 111:
#line 992 "parser.y"
                                                                                     {printf("\tPARSER: accion_ll -> llamada a accion\n");}
#line 2948 "parser.tab.c"
    break;

  case 113:
#line 996 "parser.y"
                                                    {printf("\tPARSER: l_ll -> concatenacion de expresiones\n");}
#line 2954 "parser.tab.c"
    break;

  case 114:
#line 997 "parser.y"
                                  {printf("\tPARSER: l_ll -> una expresion\n");}
#line 2960 "parser.tab.c"
    break;

  case 115:
#line 999 "parser.y"
                                    {
                                        printf("\tPARSER: M -> epsilon\n");
                                        // Almacenamos el valor de nextquad.
                                        (yyval.val_int) = tabla_cuadruplas.nextquad;     
                                    }
#line 2970 "parser.tab.c"
    break;


#line 2974 "parser.tab.c"

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
#line 1005 "parser.y"


int yyerror(char *s) {
    printf("ERROR: %s\n", s);
}

int main(int argc, char *argv[]) {
    errorFlag = 0;
    cabeza_TS = (struct FILA_TS*) malloc(sizeof(struct FILA_TS));
    cola_TS = (struct FILA_TS*) malloc(sizeof(struct FILA_TS));
    inicializar_TS(&cabeza_TS, &cola_TS);
    inicializar_TC(&tabla_cuadruplas);
    op1 = (int*) malloc(sizeof(int));
    op2 = (int*) malloc(sizeof(int));
    res = (int*) malloc(sizeof(int));
    if (argc > 1){
            yyin = fopen(argv[1], "r");	
    }
    yyparse();
    if (argc > 1){
            fclose(yyin);
    }
    guardar_TS("Resultados/TS.txt", cabeza_TS, errorFlag);
    guardar_TC("Resultados/TC.txt", tabla_cuadruplas, errorFlag);
    guardar_CTD("Resultados/CTD.txt", tabla_cuadruplas, cabeza_TS, errorFlag);
    /*free(op1);
    free(op2);
    free(res);
    free(tabla_cuadruplas);
    free(cola_TS);
    free(cabeza_TS);*/
    return 0;
}
