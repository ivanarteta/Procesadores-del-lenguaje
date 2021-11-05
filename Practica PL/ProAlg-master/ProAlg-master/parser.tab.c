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
#line 8 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabla_simbolos.h"
#include "errores.h"


#line 79 "parser.tab.c"

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
#line 18 "parser.y"

	#include "util/pila.h"
	#include "tabla_simbolos.h"
	#include "traducciones.h"
	
	
	/* estructura auxiliar para valores semánticos de ctes */
	typedef struct C_cte_t
	{
		int tipo;  /* tipo de cte */
		TS_cte_val val; /* el valor de la cte */
	} C_cte_t;
	
	/* estructura auxiliar para valores semánticos de exp aritméticas y booleanas */
	typedef struct C_exp_t
	{
		int tipo; /* es TS_REAL, TS_ENTERO, TS_BOOLEANO, ... */
		union
		{
			int place; /* apuntador a la tabla de símbolos  */
			struct
			{
				lista true,false; /* son listas de cuadruplas (se rellenan solo cuando es booleano) */
			};
		};
	} C_exp_t;

	/* estructura auxiliar para valores semánticos de las instrucciones */
	typedef struct C_instr_t
	{
		lista next; 
	} C_instr_t;
	

#line 157 "parser.tab.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_literal_entero = 258,
    T_literal_real = 259,
    T_literal_booleano = 260,
    T_literal_caracter = 261,
    T_literal_string = 262,
    T_id = 263,
    T_asignacion = 264,
    T_comp_secuencial = 265,
    T_separador = 266,
    T_subrango = 267,
    T_def_tipo_variable = 268,
    T_entonces = 269,
    T_si_no_si = 270,
    T_creacion_tipo = 271,
    T_inic_array = 272,
    T_fin_array = 273,
    T_suma = 274,
    T_resta = 275,
    T_div = 276,
    T_mult = 277,
    T_mod = 278,
    T_inic_parentesis = 279,
    T_fin_parentesis = 280,
    T_oprel = 281,
    T_referencia = 282,
    T_accion = 283,
    T_ref = 284,
    T_de = 285,
    T_algoritmo = 286,
    T_const = 287,
    T_continuar = 288,
    T_dev = 289,
    T_ent = 290,
    T_es = 291,
    T_faccion = 292,
    T_falgoritmo = 293,
    T_fconst = 294,
    T_ffuncion = 295,
    T_fmientras = 296,
    T_fpara = 297,
    T_fsi = 298,
    T_ftipo = 299,
    T_ftupla = 300,
    T_funcion = 301,
    T_fvar = 302,
    T_hacer = 303,
    T_hasta = 304,
    T_mientras = 305,
    T_no = 306,
    T_o = 307,
    T_para = 308,
    T_sal = 309,
    T_si = 310,
    T_tabla = 311,
    T_tipo = 312,
    T_tupla = 313,
    T_var = 314,
    T_y = 315,
    T_div_entera = 316,
    T_comentario = 317,
    T_tipo_base = 318
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 56 "parser.y"

	char C_id[128];	
	int C_literal_entero;
	float C_literal_real;
	char C_literal_caracter;
	char C_literal_string[256];
	int C_literal_booleano; 
	int C_tipo_base;
	int C_oprel; 
	
	
	pila C_lista_id; /* para listados de ids */
	C_cte_t C_cte;	/* para la declaración de ctes */
	int C_tipo;  /* para la declaración de tipos */
	C_exp_t C_exp; /* para expresiones aritméticas/lógicas/llamadas a funciones */
	C_instr_t C_instr; /* para instrucciones */
	int E; /* para reducciones por cadena vacia (tienen como valor semántico nextquad()) */
	int V; /* se usa en la estructura iterativa de cota fija, para almacenar la id de la variable de control */

#line 252 "parser.tab.c"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   327

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  233

#define YYUNDEFTOK  2
#define YYMAXUTOK   318


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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   199,   199,   202,   205,   207,   211,   212,   215,   216,
     217,   220,   224,   225,   226,   231,   232,   236,   269,   302,
     359,   379,   415,   416,   417,   418,   419,   442,   443,   444,
     445,   446,   447,   451,   452,   467,   468,   470,   490,   491,
     492,   493,   500,   502,   504,   509,   513,   517,   521,   527,
     528,   529,   534,   582,   620,   633,   652,   657,   670,   675,
     686,   687,   690,   701,   709,   720,   740,   752,   754,   763,
     767,   772,   775,   778,   781,   784,   791,   792,   794,   795,
     800,   801,   804,   805,   807,   808,   809,   810,   813,   814,
     815,   817,   818,   821,   822,   823,   824,   826,   828,   833,
     836,   839,   842,   845,   846,   847,   849,   850,   851,   857,
     860,   861,   862
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_literal_entero", "T_literal_real",
  "T_literal_booleano", "T_literal_caracter", "T_literal_string", "T_id",
  "T_asignacion", "T_comp_secuencial", "T_separador", "T_subrango",
  "T_def_tipo_variable", "T_entonces", "T_si_no_si", "T_creacion_tipo",
  "T_inic_array", "T_fin_array", "T_suma", "T_resta", "T_div", "T_mult",
  "T_mod", "T_inic_parentesis", "T_fin_parentesis", "T_oprel",
  "T_referencia", "T_accion", "T_ref", "T_de", "T_algoritmo", "T_const",
  "T_continuar", "T_dev", "T_ent", "T_es", "T_faccion", "T_falgoritmo",
  "T_fconst", "T_ffuncion", "T_fmientras", "T_fpara", "T_fsi", "T_ftipo",
  "T_ftupla", "T_funcion", "T_fvar", "T_hacer", "T_hasta", "T_mientras",
  "T_no", "T_o", "T_para", "T_sal", "T_si", "T_tabla", "T_tipo", "T_tupla",
  "T_var", "T_y", "T_div_entera", "T_comentario", "T_tipo_base", "$accept",
  "axioma", "desc_algoritmo", "cabecera_alg", "bloque_alg",
  "decl_globales", "decl_a_f", "bloque", "declaraciones", "expresion",
  "exp_a", "exp_b", "operando_b", "operando_a", "operando", "M", "N", "P",
  "instrucciones", "instruccion", "asignacion", "condicion", "alternativa",
  "lista_opciones", "iteracion", "it_cota_exp", "expresion_f",
  "it_cota_fija_c", "it_cota_fija", "declaracion_cte", "declaracion_var",
  "d_tipo", "dd_tipo", "expresion_t", "lista_campos", "lista_de_cte",
  "constante", "literal", "lista_de_var", "lista_id", "decl_ent_sal",
  "decl_ent", "decl_sal", "accion_d", "funcion_d", "a_cabecera",
  "f_cabecera", "d_par_form", "d_p_form", "funcion_ll", "l_ll", YY_NULLPTR
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
     315,   316,   317,   318
};
# endif

#define YYPACT_NINF (-189)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-70)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -12,    26,    41,  -189,  -189,  -189,  -189,    72,     5,    19,
     140,   101,   131,  -189,  -189,  -189,  -189,   109,  -189,   149,
     129,   165,    63,   137,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,   134,   117,   153,   129,   159,   129,   113,
     125,  -189,  -189,  -189,   149,   149,  -189,  -189,  -189,   251,
     149,   149,  -189,    10,    78,   108,   242,    91,   167,   173,
     139,   174,   149,   149,   181,  -189,   183,    27,    64,   294,
     186,   191,  -189,  -189,   192,  -189,  -189,  -189,  -189,   196,
     217,   194,   172,   251,  -189,   -11,    20,   205,   220,  -189,
    -189,  -189,  -189,   251,   251,   251,   251,   251,   251,   251,
    -189,   129,   211,   107,  -189,   206,   213,    49,   233,    11,
    -189,    -4,  -189,  -189,  -189,  -189,  -189,   237,  -189,  -189,
      40,   215,   129,   214,   149,  -189,  -189,   260,  -189,  -189,
     149,   149,   -11,   -11,   227,   227,  -189,   260,   227,    27,
    -189,  -189,  -189,    69,   120,   239,   249,  -189,  -189,   250,
     257,  -189,   149,  -189,  -189,   101,   129,   129,   129,   245,
     264,  -189,   252,   149,  -189,    27,  -189,   235,    -5,   129,
      97,  -189,  -189,   198,   272,   243,   129,   198,  -189,   224,
     240,  -189,   277,   281,   282,   292,    40,   270,   265,    15,
    -189,  -189,  -189,   295,   120,  -189,  -189,  -189,   149,   120,
     120,   120,  -189,  -189,   120,  -189,  -189,   291,   198,   298,
     261,  -189,  -189,  -189,   300,   149,   268,   296,   249,  -189,
    -189,   299,  -189,   285,  -189,  -189,   120,    27,  -189,    -3,
    -189,   291,  -189
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     7,     1,    14,    10,     0,     0,
       0,    81,    96,     6,     3,     5,    48,    37,    42,     0,
      90,     0,     0,    11,    46,    49,    50,    51,    61,    60,
      12,    13,    41,     0,     0,     0,    90,     0,    90,     0,
      93,    95,     8,     9,   112,     0,    23,    24,    30,     0,
       0,     0,    54,    15,    16,     0,     0,    36,     0,    92,
       0,     0,     0,     0,     0,    40,     0,     0,     0,     0,
       0,     0,    14,    97,     0,    14,    98,     4,    94,   111,
      34,     0,     0,     0,    35,    25,    36,    35,    33,    33,
      29,    42,    42,     0,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,    52,    53,     0,    38,     0,     0,
      47,    42,    84,    85,    83,    86,    87,     0,    82,    67,
     105,     0,    90,     0,     0,   109,    43,     0,    22,    32,
       0,     0,    17,    18,    21,    19,    26,    31,    20,     0,
      91,    68,    77,    37,     0,     0,    79,    75,    76,     0,
       0,    39,     0,    66,    45,    81,     0,     0,     0,     0,
     104,    99,     0,     0,   110,     0,    28,    27,    44,    90,
      37,    74,    70,     0,     0,     0,    90,     0,    63,    36,
       0,    80,     0,     0,     0,     0,   105,     0,     0,     0,
      57,    43,    88,     0,     0,    71,    89,    73,     0,     0,
       0,     0,   101,   103,     0,   100,    62,     0,     0,     0,
       0,   106,   108,   107,     0,     0,     0,     0,    79,    65,
     102,     0,    56,     0,    78,    42,     0,     0,    72,    44,
      43,     0,    58
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -189,  -189,  -189,  -189,  -189,  -189,  -189,    60,  -189,   -18,
     -35,   -28,   -33,   115,   -10,    -1,  -188,    83,   -65,   208,
    -189,   102,  -189,    85,  -189,  -189,   122,  -189,  -189,   312,
    -189,    92,   221,  -153,   105,   170,  -189,  -189,   -30,   -88,
    -189,  -189,   286,  -189,  -189,  -189,  -189,   141,  -189,  -189,
    -189
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     8,     7,    12,     9,    10,   148,
      53,    54,    55,    56,    80,    22,   165,   191,    23,    24,
      25,    58,    26,   216,    27,    28,   180,    67,    29,    13,
      31,   171,   172,   150,   175,    34,   117,   118,    60,    61,
      39,    40,    41,    42,    43,    72,    75,   159,   160,    32,
      81
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    52,   109,   207,    17,    68,    73,    68,    76,    57,
      95,    96,    97,   140,    84,    87,    84,    45,    90,     1,
     193,    68,    88,    89,   197,    68,    79,    82,    16,   -35,
     -35,   -35,   -35,   -35,     4,    17,   -35,    63,   190,    86,
     -59,     5,   231,    14,   104,   106,    18,    64,    87,    65,
      99,    19,   105,   153,   107,   217,   206,    21,    84,    84,
      84,    84,    84,    84,    84,   110,    63,   111,   182,   183,
     184,   -35,   -42,    86,   168,   156,   157,    18,    65,   169,
     -42,    15,    19,    86,    86,    86,    86,    86,    86,    86,
     130,   131,   162,    44,   158,    84,    84,   166,   167,   139,
     189,    21,    89,    89,    11,   -55,   164,   -69,    63,    33,
      46,    47,    48,   142,   -42,   143,    66,   -42,    64,   -42,
      65,    44,   -69,    46,    47,    48,   142,    49,   170,    21,
     -33,    50,   121,    44,   178,   123,   144,    59,   -33,   192,
      49,    16,   179,   -34,    50,   188,   196,    68,    17,   144,
      69,   -34,    46,    47,    48,    21,    70,    17,    51,    35,
      91,    71,   229,   145,    85,   146,    36,    74,    92,    49,
     147,    51,    11,    50,    62,    77,   145,    37,   146,    38,
     178,   100,    63,   147,   101,    38,   102,   103,   179,    17,
      18,   108,    64,   -42,    65,    19,   119,    52,   127,    20,
      51,    46,    47,    48,   142,    57,    17,   124,   132,   133,
     134,   135,   136,   137,   138,   120,   122,    21,    49,   125,
     126,   141,    50,    63,   227,   -36,   -36,   -36,   -36,   -36,
     128,   151,   -36,    64,    63,    65,   -36,   -36,   -36,   -36,
     -36,    63,   152,   -36,    64,   129,    65,   155,   163,    51,
      97,    64,   161,    65,    46,    47,   173,   174,   -34,    17,
     176,    93,    94,    95,    96,    97,   -34,   -36,    98,   177,
     185,    49,   -64,   -64,   186,    83,   -34,   187,   -36,    93,
      94,    95,    96,    97,   -34,   194,   209,    91,   195,   198,
     199,   211,   212,   213,   200,   201,   214,   112,   113,   114,
     115,   116,   202,    99,   204,   205,   215,   208,   218,   219,
     220,   222,   230,   225,   223,   226,   232,   221,   228,   154,
     210,    99,    30,   224,   149,   181,    78,   203
};

static const yytype_uint8 yycheck[] =
{
      10,    19,    67,   191,     8,    10,    36,    10,    38,    19,
      21,    22,    23,   101,    49,    50,    51,    18,    51,    31,
     173,    10,    50,    51,   177,    10,    44,    45,     1,    19,
      20,    21,    22,    23,     8,     8,    26,    17,    43,    49,
      43,     0,   230,    38,    62,    63,    50,    27,    83,    29,
      61,    55,    62,    42,    64,   208,    41,    67,    93,    94,
      95,    96,    97,    98,    99,     1,    17,    68,   156,   157,
     158,    61,     8,    83,   139,    35,    36,    50,    29,    10,
      53,    62,    55,    93,    94,    95,    96,    97,    98,    99,
      91,    92,   122,    24,    54,   130,   131,   130,   131,   100,
     165,   111,   130,   131,    32,    14,   124,    10,    17,     8,
       3,     4,     5,     6,    50,     8,    53,    53,    27,    55,
      29,    24,    25,     3,     4,     5,     6,    20,     8,   139,
      52,    24,    72,    24,   152,    75,    29,     8,    60,   169,
      20,     1,   152,    52,    24,   163,   176,    10,     8,    29,
      16,    60,     3,     4,     5,   165,    39,     8,    51,    28,
      52,     8,   227,    56,    49,    58,    35,     8,    60,    20,
      63,    51,    32,    24,     9,    62,    56,    46,    58,    54,
     198,    14,    17,    63,    11,    54,    47,    13,   198,     8,
      50,     8,    27,    53,    29,    55,    10,   215,    83,    59,
      51,     3,     4,     5,     6,   215,     8,    11,    93,    94,
      95,    96,    97,    98,    99,    24,    24,   227,    20,    25,
      48,    10,    24,    17,   225,    19,    20,    21,    22,    23,
      25,    18,    26,    27,    17,    29,    19,    20,    21,    22,
      23,    17,     9,    26,    27,    25,    29,    10,    34,    51,
      23,    27,    37,    29,     3,     4,    17,     8,    52,     8,
      10,    19,    20,    21,    22,    23,    60,    61,    26,    12,
      25,    20,    48,    49,    10,    24,    52,    25,    61,    19,
      20,    21,    22,    23,    60,    13,   194,    52,    45,    49,
      13,   199,   200,   201,    13,    13,   204,     3,     4,     5,
       6,     7,    10,    61,    34,    40,    15,    12,    10,    48,
      10,    43,   229,    14,    18,    30,   231,   215,   226,   111,
     198,    61,    10,   218,   103,   155,    40,   186
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    31,    65,    66,     8,     0,    67,    69,    68,    71,
      72,    32,    70,    93,    38,    62,     1,     8,    50,    55,
      59,    78,    79,    82,    83,    84,    86,    88,    89,    92,
      93,    94,   113,     8,    99,    28,    35,    46,    54,   104,
     105,   106,   107,   108,    24,    79,     3,     4,     5,    20,
      24,    51,    73,    74,    75,    76,    77,    78,    85,     8,
     102,   103,     9,    17,    27,    29,    53,    91,    10,    16,
      39,     8,   109,   102,     8,   110,   102,    62,   106,    73,
      78,   114,    73,    24,    74,    77,    78,    74,    75,    75,
      76,    52,    60,    19,    20,    21,    22,    23,    26,    61,
      14,    11,    47,    13,    73,    78,    73,    78,     8,    82,
       1,    79,     3,     4,     5,     6,     7,   100,   101,    10,
      24,    71,    24,    71,    11,    25,    48,    77,    25,    25,
      79,    79,    77,    77,    77,    77,    77,    77,    77,    79,
     103,    10,     6,     8,    29,    56,    58,    63,    73,    96,
      97,    18,     9,    42,    83,    10,    35,    36,    54,   111,
     112,    37,   102,    34,    73,    80,    76,    76,    82,    10,
       8,    95,    96,    17,     8,    98,    10,    12,    73,    78,
      90,    99,   103,   103,   103,    25,    10,    25,    73,    82,
      43,    81,   102,    97,    13,    45,   102,    97,    49,    13,
      13,    13,    10,   111,    34,    40,    41,    80,    12,    95,
      90,    95,    95,    95,    95,    15,    87,    97,    10,    48,
      10,    85,    43,    18,    98,    14,    30,    79,    95,    82,
      81,    80,    87
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    66,    67,    68,    69,    69,    70,    70,
      70,    71,    72,    72,    72,    73,    73,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    75,    75,    75,
      75,    75,    75,    76,    76,    77,    77,    78,    78,    78,
      78,    78,    79,    80,    81,    82,    82,    82,    82,    83,
      83,    83,    84,    84,    85,    85,    86,    86,    87,    87,
      88,    88,    89,    90,    90,    91,    92,    93,    94,    95,
      95,    96,    96,    96,    96,    96,    97,    97,    98,    98,
      99,    99,   100,   100,   101,   101,   101,   101,   102,   102,
     102,   103,   103,   104,   104,   104,   104,   105,   106,   107,
     108,   109,   110,   111,   111,   111,   112,   112,   112,   113,
     114,   114,   114
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     5,     4,     2,     2,     0,     2,     2,
       0,     2,     2,     2,     0,     1,     1,     3,     3,     3,
       3,     3,     3,     1,     1,     2,     3,     4,     4,     2,
       1,     3,     3,     1,     1,     1,     1,     1,     3,     4,
       2,     1,     0,     0,     0,     4,     1,     3,     1,     1,
       1,     1,     3,     3,     1,     1,     9,     6,     8,     5,
       1,     1,     7,     1,     1,     7,     4,     4,     4,     1,
       1,     3,     8,     3,     2,     1,     1,     1,     5,     0,
       5,     0,     1,     1,     1,     1,     1,     1,     5,     5,
       0,     3,     1,     1,     2,     1,     0,     2,     2,     4,
       6,     5,     7,     3,     1,     0,     4,     4,     4,     4,
       3,     1,     0
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
#line 199 "parser.y"
                       { CHECK_PARSE_ERRORS; }
#line 1622 "parser.tab.c"
    break;

  case 15:
#line 231 "parser.y"
               { (yyval.C_exp).place = (yyvsp[0].C_exp).place; (yyval.C_exp).tipo = TS_consultar_tipo((yyvsp[0].C_exp).place)&0xFF00; }
#line 1628 "parser.tab.c"
    break;

  case 16:
#line 232 "parser.y"
                { (yyval.C_exp).true = (yyvsp[0].C_exp).true; (yyval.C_exp).false = (yyvsp[0].C_exp).false; (yyval.C_exp).tipo = TS_BOOLEANO; }
#line 1634 "parser.tab.c"
    break;

  case 17:
#line 236 "parser.y"
                                     { 
		int T=TS_newtempvar();
		(yyval.C_exp).place = T;
		if((yyvsp[-2].C_exp).tipo == TS_ENTERO)
		{
			if((yyvsp[0].C_exp).tipo == TS_ENTERO)
			{
				TS_modificar_simbolo(T,TS_VAR|TS_ENTERO);
				gen_asig_binaria(TR_OP_SUMA, (yyvsp[-2].C_exp).place, (yyvsp[0].C_exp).place, T);
			}
			else
			{
				TS_modificar_simbolo(T,TS_VAR|TS_REAL);
				gen_asig_unaria(TR_OP_INT_TO_REAL, (yyvsp[-2].C_exp).place, T);
				gen_asig_binaria(TR_OP_SUMA_REAL, T, (yyvsp[0].C_exp).place, T);
			}
		} 
		else 
		{	
			if((yyvsp[0].C_exp).tipo == TS_ENTERO)
			{
				TS_modificar_simbolo(T,TS_VAR|TS_REAL);
				gen_asig_unaria(TR_OP_INT_TO_REAL, (yyvsp[0].C_exp).place, T);
				gen_asig_binaria(TR_OP_SUMA_REAL, (yyvsp[-2].C_exp).place, T, T);
			}
			else
			{
				TS_modificar_simbolo(T,TS_VAR|TS_REAL);
				gen_asig_binaria(TR_OP_SUMA_REAL, (yyvsp[-2].C_exp).place, (yyvsp[0].C_exp).place, T);
			}
		}

	}
#line 1672 "parser.tab.c"
    break;

  case 18:
#line 269 "parser.y"
                                        { 
		int T=TS_newtempvar();
		(yyval.C_exp).place = T;
		if((yyvsp[-2].C_exp).tipo == TS_ENTERO)
		{
			if((yyvsp[0].C_exp).tipo == TS_ENTERO)
			{
				TS_modificar_simbolo(T,TS_VAR|TS_ENTERO);
				gen_asig_binaria(TR_OP_RESTA, (yyvsp[-2].C_exp).place, (yyvsp[0].C_exp).place, T);
			}
			else
			{
				TS_modificar_simbolo(T,TS_VAR|TS_REAL);
				gen_asig_unaria(TR_OP_INT_TO_REAL, (yyvsp[-2].C_exp).place, T);
				gen_asig_binaria(TR_OP_RESTA_REAL, T, (yyvsp[0].C_exp).place, T);
			}
		} 
		else 
		{	
			if((yyvsp[0].C_exp).tipo == TS_ENTERO)
			{
				TS_modificar_simbolo(T,TS_VAR|TS_REAL);
				gen_asig_unaria(TR_OP_INT_TO_REAL, (yyvsp[0].C_exp).place, T);
				gen_asig_binaria(TR_OP_RESTA_REAL, (yyvsp[-2].C_exp).place, T, T);
			}
			else
			{
				TS_modificar_simbolo(T,TS_VAR|TS_REAL);
				gen_asig_binaria(TR_OP_RESTA_REAL, (yyvsp[-2].C_exp).place, (yyvsp[0].C_exp).place, T);
			}
		}

	}
#line 1710 "parser.tab.c"
    break;

  case 19:
#line 302 "parser.y"
                                       { 
		int T=TS_newtempvar();
		(yyval.C_exp).place = T;
		if((yyvsp[-2].C_exp).tipo == TS_ENTERO)
		{
			if((yyvsp[0].C_exp).tipo == TS_ENTERO)
			{
				/* si es una multiplicación en la que uno de los operandos es
				 * una cte(sabemos su valor) y es una potencia de 2, en vez de usar la instrucción producto,
				 * podemos hacer un shift*/
				TS_modificar_simbolo(T,TS_VAR|TS_ENTERO);
				if(((TS_consultar_tipo((yyvsp[-2].C_exp).place)&TS_CTE) == TS_CTE) && es_potencia_2(TS_consultar_cte((yyvsp[-2].C_exp).place).entero))
				{
					/* creo una nueva cte en la tabla de símbolos, con el valor del logaritmo en base 2 del
					 * operando que es potencia de  2 */
					int L = TS_newliteral();
					TS_modificar_simbolo(L, TS_CTE|TS_ENTERO);
					TS_cte_val val; val.entero = log_base_2(TS_consultar_cte((yyvsp[-2].C_exp).place).entero);
					TS_modificar_cte(L,val);
					
					
					gen_asig_binaria(TR_OP_SHIFT_LEFT, (yyvsp[0].C_exp).place, L, T);
				}
				else if(((TS_consultar_tipo((yyvsp[0].C_exp).place)&TS_CTE) == TS_CTE) && es_potencia_2(TS_consultar_cte((yyvsp[0].C_exp).place).entero))
				{
					int L = TS_newliteral();
					TS_modificar_simbolo(L,TS_CTE|TS_ENTERO);
					TS_cte_val val; val.entero = log_base_2(TS_consultar_cte((yyvsp[0].C_exp).place).entero);
					TS_modificar_cte(L,val);
					
					gen_asig_binaria(TR_OP_SHIFT_LEFT, (yyvsp[-2].C_exp).place, L, T);
				}
				else
					gen_asig_binaria(TR_OP_MULT, (yyvsp[-2].C_exp).place, (yyvsp[0].C_exp).place, T);
			}
			else
			{
				TS_modificar_simbolo(T,TS_VAR|TS_REAL);
				gen_asig_unaria(TR_OP_INT_TO_REAL, (yyvsp[-2].C_exp).place, T);
				gen_asig_binaria(TR_OP_MULT_REAL, T, (yyvsp[0].C_exp).place, T);
			}
		} 
		else 
		{	
			if((yyvsp[0].C_exp).tipo == TS_ENTERO)
			{
				TS_modificar_simbolo(T,TS_VAR|TS_REAL);
				gen_asig_unaria(TR_OP_INT_TO_REAL, (yyvsp[0].C_exp).place, T);
				gen_asig_binaria(TR_OP_MULT_REAL, (yyvsp[-2].C_exp).place, T, T);
			}
			else
			{
				TS_modificar_simbolo(T,TS_VAR|TS_REAL);
				gen_asig_binaria(TR_OP_MULT_REAL, (yyvsp[-2].C_exp).place, (yyvsp[0].C_exp).place, T);
			}
		}
}
#line 1772 "parser.tab.c"
    break;

  case 20:
#line 359 "parser.y"
                                             { 
		int T=TS_newtempvar();
		(yyval.C_exp).place = T;
		if(((yyvsp[-2].C_exp).tipo == TS_ENTERO) && ((yyvsp[0].C_exp).tipo == TS_ENTERO))
		{
			TS_modificar_simbolo(T,TS_VAR|TS_ENTERO);
			gen_asig_binaria(TR_OP_DIV, (yyvsp[-2].C_exp).place, (yyvsp[0].C_exp).place, T);
		}
		else
		{
			if((yyvsp[-2].C_exp).tipo != TS_ENTERO)
			{
				PARSE_ERROR(E_OPERANDO_NO_VALIDO, (yyvsp[-2].C_exp).place);
			}
			else
			{
				PARSE_ERROR(E_OPERANDO_NO_VALIDO, (yyvsp[0].C_exp).place);
			}	
		}
	}
#line 1797 "parser.tab.c"
    break;

  case 21:
#line 379 "parser.y"
                                      { 
		int T=TS_newtempvar();
		(yyval.C_exp).place = T;
		if((yyvsp[-2].C_exp).tipo == TS_ENTERO)
		{
			if((yyvsp[0].C_exp).tipo == TS_ENTERO)
			{
				int S=TS_newtempvar();
				TS_modificar_simbolo(S,TS_VAR|TS_REAL);
				TS_modificar_simbolo(T,TS_VAR|TS_REAL);
				gen_asig_unaria(TR_OP_INT_TO_REAL, (yyvsp[-2].C_exp).place, T);
				gen_asig_unaria(TR_OP_INT_TO_REAL, (yyvsp[0].C_exp).place, S);
				gen_asig_binaria(TR_OP_DIV, T, S, T);
			}
			else
			{
				TS_modificar_simbolo(T,TS_VAR|TS_REAL);
				gen_asig_unaria(TR_OP_INT_TO_REAL, (yyvsp[-2].C_exp).place, T);
				gen_asig_binaria(TR_OP_DIV_REAL, T, (yyvsp[0].C_exp).place, T);
			}
		} 
		else 
		{	
			if((yyvsp[0].C_exp).tipo == TS_ENTERO)
			{
				TS_modificar_simbolo(T,TS_VAR|TS_REAL);
				gen_asig_unaria(TR_OP_INT_TO_REAL, (yyvsp[0].C_exp).place, T);
				gen_asig_binaria(TR_OP_DIV_REAL, (yyvsp[-2].C_exp).place, T, T);
			}
			else
			{
				TS_modificar_simbolo(T,TS_VAR|TS_REAL);
				gen_asig_binaria(TR_OP_DIV_REAL, (yyvsp[-2].C_exp).place, (yyvsp[0].C_exp).place, T);
			}
		}
	}
#line 1838 "parser.tab.c"
    break;

  case 22:
#line 415 "parser.y"
                                                   { (yyval.C_exp) = (yyvsp[-1].C_exp); }
#line 1844 "parser.tab.c"
    break;

  case 23:
#line 416 "parser.y"
                           { int L=TS_newliteral(); TS_modificar_simbolo(L, TS_CTE|TS_ENTERO); TS_cte_val val; val.entero=(yyvsp[0].C_literal_entero); TS_modificar_cte(L, val); (yyval.C_exp).place = L; (yyval.C_exp).tipo = TS_ENTERO;  }
#line 1850 "parser.tab.c"
    break;

  case 24:
#line 417 "parser.y"
                         { int L=TS_newliteral(); TS_modificar_simbolo(L, TS_CTE|TS_REAL); TS_cte_val val;  val.real=(yyvsp[0].C_literal_real); TS_modificar_cte(L, val); (yyval.C_exp).place = L; (yyval.C_exp).tipo = TS_REAL;  }
#line 1856 "parser.tab.c"
    break;

  case 25:
#line 418 "parser.y"
                             { int T=TS_newtempvar(); TS_modificar_simbolo(T,TS_VAR|(yyvsp[0].C_exp).tipo); (yyval.C_exp).place = T; (yyval.C_exp).tipo = (yyvsp[0].C_exp).tipo; if((yyvsp[0].C_exp).tipo == TS_REAL) { gen_asig_unaria((yyvsp[0].C_exp).place, TR_OP_NEG_REAL , T); } else { gen_asig_unaria((yyvsp[0].C_exp).place, TR_OP_NEG , T); }  }
#line 1862 "parser.tab.c"
    break;

  case 26:
#line 419 "parser.y"
                                      {
		if(((yyvsp[-2].C_exp).tipo == TS_ENTERO) && ((yyvsp[0].C_exp).tipo == TS_ENTERO))
		{
			int T = TS_newtempvar();
			TS_modificar_simbolo(T,TS_VAR|TS_ENTERO);
			gen_asig_binaria(TR_OP_MOD, (yyvsp[-2].C_exp).place, (yyvsp[0].C_exp).place, T);
		}
		else
		{
			if((yyvsp[-2].C_exp).tipo != TS_ENTERO)
			{
				PARSE_ERROR(E_OPERANDO_NO_VALIDO, (yyvsp[-2].C_exp).place);
			}
			else
			{
				PARSE_ERROR(E_OPERANDO_NO_VALIDO, (yyvsp[0].C_exp).place);
			}
		}
	}
#line 1886 "parser.tab.c"
    break;

  case 27:
#line 442 "parser.y"
                                    {  backpatch((yyval.C_exp).true, (yyvsp[-1].E)); (yyval.C_exp).false = merge((yyvsp[-3].C_exp).false, (yyvsp[0].C_exp).false); (yyval.C_exp).true = (yyvsp[0].C_exp).true;  }
#line 1892 "parser.tab.c"
    break;

  case 28:
#line 443 "parser.y"
                                      { backpatch((yyval.C_exp).false, (yyvsp[-1].E)); (yyval.C_exp).true = merge((yyvsp[-3].C_exp).true, (yyvsp[0].C_exp).true); (yyval.C_exp).false = (yyvsp[0].C_exp).false;  }
#line 1898 "parser.tab.c"
    break;

  case 29:
#line 444 "parser.y"
                          { (yyval.C_exp).true = (yyvsp[0].C_exp).false; (yyval.C_exp).false = (yyval.C_exp).true; }
#line 1904 "parser.tab.c"
    break;

  case 30:
#line 445 "parser.y"
                             {(yyval.C_exp).true = makelist(nextquad()); (yyval.C_exp).false = makelist(nextquad()+1); gen_salto_incondicional(-1); gen_salto_incondicional(-1); if(!(yyvsp[0].C_literal_booleano)) { lista aux = (yyval.C_exp).false; (yyval.C_exp).false = (yyval.C_exp).true; (yyval.C_exp).true = aux; }  }
#line 1910 "parser.tab.c"
    break;

  case 31:
#line 446 "parser.y"
                                        { (yyval.C_exp).true = makelist(nextquad()); (yyval.C_exp).false = makelist(nextquad()+1); gen_salto_condicional((yyvsp[-1].C_oprel), (yyvsp[-2].C_exp).place, (yyvsp[0].C_exp).place, -1); gen_salto_incondicional(-1);   }
#line 1916 "parser.tab.c"
    break;

  case 32:
#line 447 "parser.y"
                                                   { (yyval.C_exp) = (yyvsp[-1].C_exp); }
#line 1922 "parser.tab.c"
    break;

  case 33:
#line 451 "parser.y"
              { (yyval.C_exp) = (yyvsp[0].C_exp); }
#line 1928 "parser.tab.c"
    break;

  case 34:
#line 452 "parser.y"
                   { 
		if((yyvsp[0].C_exp).tipo == TS_BOOLEANO) 
		{ 
			(yyval.C_exp).tipo = (yyvsp[0].C_exp).tipo; 					
			(yyval.C_exp).true = makelist(nextquad()); 
			(yyval.C_exp).false = makelist(nextquad()+1);  
			gen_salto_condicional(TR_OP_EQUAL, (yyvsp[0].C_exp).place, TS_cte_verdadero(), -1); 
			gen_salto_incondicional(-1); 
		} else 
		{ 
			/* error */ 
			PARSE_ERROR(E_OPERANDO_NO_VALIDO, (yyvsp[0].C_exp).place);
		} 
	}
#line 1947 "parser.tab.c"
    break;

  case 35:
#line 467 "parser.y"
              { (yyval.C_exp) = (yyvsp[0].C_exp); }
#line 1953 "parser.tab.c"
    break;

  case 36:
#line 468 "parser.y"
                   { if(((yyvsp[0].C_exp).tipo == TS_REAL) || ((yyvsp[0].C_exp).tipo == TS_ENTERO)) { (yyval.C_exp) = (yyvsp[0].C_exp); } else { PARSE_ERROR(E_OPERANDO_NO_VALIDO, (yyvsp[0].C_exp).place);  } }
#line 1959 "parser.tab.c"
    break;

  case 37:
#line 470 "parser.y"
              { 
		int id; 
		if((id=TS_buscar_simbolo((yyvsp[0].C_id))) == -1) 
		{ 
			/* error */ 
			PARSE_ERROR(E_SIMBOLO_NO_DEFINIDO, (yyvsp[0].C_id));
		} 
		else 
		{  
			/* también hay que comprobar si es una cte o una variable */
			int tipo=TS_consultar_tipo(id); 
			if(((tipo&0x00FF) != TS_VAR) && ((tipo&0x00FF) != TS_CTE))
			{
				/* error */
				PARSE_ERROR(E_OPERANDO_NO_VALIDO, id);
			}
			(yyval.C_exp).place = id;
			(yyval.C_exp).tipo = tipo&0xFF00; 
		}  
	}
#line 1984 "parser.tab.c"
    break;

  case 41:
#line 493 "parser.y"
                     {
		/* guardar el tipo de valor de retorno en la traducción .tipo. Generar una variable temporal
		 * donde se almacenará dicho valor */
		}
#line 1993 "parser.tab.c"
    break;

  case 42:
#line 500 "parser.y"
               {(yyval.E)=nextquad();}
#line 1999 "parser.tab.c"
    break;

  case 43:
#line 502 "parser.y"
               {(yyval.E)=nextquad();}
#line 2005 "parser.tab.c"
    break;

  case 44:
#line 504 "parser.y"
               { (yyval.C_instr).next = makelist(nextquad()); gen_salto_incondicional(-1); }
#line 2011 "parser.tab.c"
    break;

  case 45:
#line 509 "parser.y"
                                                      { 
		backpatch((yyvsp[-3].C_instr).next, (yyvsp[-1].E));
		(yyval.C_instr) = (yyvsp[0].C_instr);
	}
#line 2020 "parser.tab.c"
    break;

  case 46:
#line 513 "parser.y"
                      { 
		(yyval.C_instr) = (yyvsp[0].C_instr); 
	}
#line 2028 "parser.tab.c"
    break;

  case 47:
#line 517 "parser.y"
                                                {
		(yyval.C_instr) = (yyvsp[-2].C_instr);
		REPORT_PARSE_ERROR;
	}
#line 2037 "parser.tab.c"
    break;

  case 48:
#line 521 "parser.y"
                { 
		(yyval.C_instr).next = makelistempty();
		REPORT_PARSE_ERROR;
	}
#line 2046 "parser.tab.c"
    break;

  case 49:
#line 527 "parser.y"
                   {  (yyval.C_instr) = (yyvsp[0].C_instr); }
#line 2052 "parser.tab.c"
    break;

  case 50:
#line 528 "parser.y"
                      { (yyval.C_instr) = (yyvsp[0].C_instr); }
#line 2058 "parser.tab.c"
    break;

  case 51:
#line 529 "parser.y"
                    { (yyval.C_instr) = (yyvsp[0].C_instr); }
#line 2064 "parser.tab.c"
    break;

  case 52:
#line 534 "parser.y"
                                        {
		(yyval.C_instr).next = makelistempty();
		
		/* la parte izquierda de la asignación debe ser una variable */
		if((TS_consultar_tipo((yyvsp[-2].C_exp).place)&0x00FF) != TS_VAR)
		{
			PARSE_ERROR(E_OPERANDO_NO_VALIDO, (yyvsp[-2].C_exp).place);
		}
		
		/* los tipos deben coincidir, o el tipo expresión expresion sea convertible
		 * al tipo operando. */
		if((yyvsp[-2].C_exp).tipo == (yyvsp[0].C_exp).tipo)
		{
			if((yyvsp[0].C_exp).tipo == TS_BOOLEANO)
			{
				backpatch((yyvsp[0].C_exp).true, nextquad());
				backpatch((yyvsp[0].C_exp).false, nextquad()+1);
				gen_copia(TS_cte_verdadero(), (yyvsp[-2].C_exp).place);
				gen_copia(TS_cte_falso(), (yyvsp[-2].C_exp).place);
			}
			else
			{
				gen_copia((yyvsp[0].C_exp).place, (yyvsp[-2].C_exp).place);
			}
		}
		else
		{
			/* puede que los tipos de ambos operandos sean compatibles, en tal
			 * caso hacemos una conversión de tipos implicita */
			if((((yyvsp[-2].C_exp).tipo == TS_ENTERO) && ((yyvsp[0].C_exp).tipo == TS_REAL)) || (((yyvsp[-2].C_exp).tipo == TS_REAL) && ((yyvsp[0].C_exp).tipo == TS_ENTERO)))
			{
				/* reales y enteros compatibles */
				int T;
				if((yyvsp[-2].C_exp).tipo == TS_ENTERO)
				{
					gen_asig_unaria(TR_OP_REAL_TO_INT, (yyvsp[0].C_exp).place, (yyvsp[-2].C_exp).place);
				}
				else
				{
					gen_asig_unaria(TR_OP_INT_TO_REAL, (yyvsp[0].C_exp).place, (yyvsp[-2].C_exp).place);
				}
			}
			else 
			{
				PARSE_ERROR(E_CONVERSION_NO_VALIDA);
			}
		}
	}
#line 2117 "parser.tab.c"
    break;

  case 53:
#line 582 "parser.y"
                                         {
		(yyval.C_instr).next = makelistempty();
			
		/* la parte izquierda de la asignación debe ser una variable */
		if((TS_consultar_tipo((yyvsp[-2].C_exp).place)&0x00FF) != TS_VAR)
		{
			PARSE_ERROR(E_MODIFICANDO_CTE,(yyvsp[-2].C_exp).place);
		}
			
		/* comprobar si tipos coinciden (Si son tipos estructurados, hay que 
		 * llevar a cabo comprobaciones adicionales) */
		if((yyvsp[-2].C_exp).tipo == (yyvsp[0].C_exp).tipo)
		{
			gen_copia((yyvsp[0].C_exp).place, (yyvsp[-2].C_exp).place);
		}
		else
		{
			if((((yyvsp[-2].C_exp).tipo == TS_ENTERO) && ((yyvsp[0].C_exp).tipo == TS_REAL)) || (((yyvsp[-2].C_exp).tipo == TS_REAL) && ((yyvsp[0].C_exp).tipo == TS_ENTERO)))
			{
				int T;
				if((yyvsp[-2].C_exp).tipo == TS_ENTERO)
				{
					gen_asig_unaria(TR_OP_REAL_TO_INT, (yyvsp[0].C_exp).place, (yyvsp[-2].C_exp).place);
				}
				else
				{
					gen_asig_unaria(TR_OP_INT_TO_REAL, (yyvsp[0].C_exp).place, (yyvsp[-2].C_exp).place);
				}
			}
			else
			{
				PARSE_ERROR(E_CONVERSION_NO_VALIDA);
			}
		}
	}
#line 2157 "parser.tab.c"
    break;

  case 54:
#line 620 "parser.y"
                  {
		if((yyvsp[0].C_exp).tipo == TS_BOOLEANO)
		{
			(yyval.C_exp) = (yyvsp[0].C_exp);
		}
		else if((yyvsp[0].C_exp).tipo == TS_ENTERO)
		{
			(yyval.C_exp).true = makelist(nextquad()); 
			(yyval.C_exp).false = makelist(nextquad()+1);  
			gen_salto_condicional(TR_OP_NOT_EQUAL, (yyvsp[0].C_exp).place, TS_cte_0(), -1); 
			gen_salto_incondicional(-1); 
		}
	}
#line 2175 "parser.tab.c"
    break;

  case 55:
#line 633 "parser.y"
                   {
		if((yyvsp[0].C_exp).tipo == TS_BOOLEANO)
		{
			(yyval.C_exp) = (yyvsp[0].C_exp);
		}
		else if((yyvsp[0].C_exp).tipo == TS_ENTERO)
		{				
			(yyval.C_exp).true = makelist(nextquad()); 
			(yyval.C_exp).false = makelist(nextquad()+1);  
			gen_salto_condicional(TR_OP_NOT_EQUAL, (yyvsp[0].C_exp).place, TS_cte_0(), -1); 
			gen_salto_incondicional(-1); 
		}
		else
		{
			PARSE_ERROR(E_OPERANDO_NO_VALIDO, (yyvsp[0].C_exp).place);
		}
	}
#line 2197 "parser.tab.c"
    break;

  case 56:
#line 652 "parser.y"
                                                                           { 
		backpatch((yyvsp[-7].C_exp).true, (yyvsp[-5].E));
		backpatch((yyvsp[-7].C_exp).false, (yyvsp[-2].E));
		(yyval.C_instr).next = merge((yyvsp[-4].C_instr).next, merge((yyvsp[-3].C_instr).next, (yyvsp[-1].C_instr).next));
	}
#line 2207 "parser.tab.c"
    break;

  case 57:
#line 657 "parser.y"
                                                          {
		backpatch((yyvsp[-4].C_exp).true, (yyvsp[-2].E));
		if(!empty((yyvsp[-1].C_instr).next))
			(yyval.C_instr).next = merge((yyvsp[-4].C_exp).false, (yyvsp[-1].C_instr).next);
		else
		{
			(yyval.C_instr).next = merge((yyvsp[-4].C_exp).false, makelist(nextquad()));
			gen_salto_incondicional(-1);
		} 
	}
#line 2222 "parser.tab.c"
    break;

  case 58:
#line 670 "parser.y"
                                                                           {
		backpatch((yyvsp[-6].C_exp).true, (yyvsp[-4].E));
		backpatch((yyvsp[-6].C_exp).false, (yyvsp[-1].E));
		(yyval.C_instr).next = merge((yyvsp[-3].C_instr).next, merge((yyvsp[-2].C_instr).next, (yyvsp[0].C_instr).next));
	}
#line 2232 "parser.tab.c"
    break;

  case 59:
#line 675 "parser.y"
                                                          {
		backpatch((yyvsp[-3].C_exp).true, (yyvsp[-1].E));
		if(!empty((yyvsp[0].C_instr).next))
			(yyval.C_instr).next = merge((yyvsp[-3].C_exp).false, (yyvsp[0].C_instr).next);
		else 
		{
			(yyval.C_instr).next = merge((yyvsp[-3].C_exp).false, makelist(nextquad()));
			gen_salto_incondicional(-1);
		}
	}
#line 2247 "parser.tab.c"
    break;

  case 60:
#line 686 "parser.y"
                     { (yyval.C_instr) = (yyvsp[0].C_instr); }
#line 2253 "parser.tab.c"
    break;

  case 61:
#line 687 "parser.y"
                      { (yyval.C_instr) = (yyvsp[0].C_instr); }
#line 2259 "parser.tab.c"
    break;

  case 62:
#line 690 "parser.y"
                                                                   {
		backpatch((yyvsp[-4].C_exp).true, (yyvsp[-2].E));
		if(!empty((yyvsp[-1].C_instr).next))
			backpatch((yyvsp[-1].C_instr).next, (yyvsp[-5].E));
		else
			gen_salto_incondicional((yyvsp[-5].E));
		(yyval.C_instr).next = (yyvsp[-4].C_exp).false;
	}
#line 2272 "parser.tab.c"
    break;

  case 63:
#line 701 "parser.y"
                  { 
		if((yyvsp[0].C_exp).tipo == TS_ENTERO)
			(yyval.C_exp) = (yyvsp[0].C_exp);
		else
		{
			PARSE_ERROR(E_OPERANDO_NO_VALIDO, (yyvsp[0].C_exp).place);
		}
	}
#line 2285 "parser.tab.c"
    break;

  case 64:
#line 709 "parser.y"
                   {
		if((yyvsp[0].C_exp).tipo == TS_ENTERO)
			(yyval.C_exp) = (yyvsp[0].C_exp);
		else
		{
			PARSE_ERROR(E_OPERANDO_NO_VALIDO, (yyvsp[0].C_exp).place);
		}
	}
#line 2298 "parser.tab.c"
    break;

  case 65:
#line 720 "parser.y"
                                                                         { 
		/* inicializar variable de control & comparar variable de control con cota */
		
		/* comprobar variable de control */
		int v;
		if((v=TS_buscar_simbolo((yyvsp[-5].C_id))) == -1)
		{
			PARSE_ERROR(E_SIMBOLO_NO_DEFINIDO, (yyvsp[-5].C_id));
		}
		else if(TS_consultar_tipo(v) != (TS_ENTERO | TS_VAR))
		{
			PARSE_ERROR(E_OPERANDO_NO_VALIDO, v);
		}
		
		gen_copia((yyvsp[-3].C_exp).place, v);
		gen_salto_condicional(TR_OP_GREATER, v, (yyvsp[-1].C_exp).place, -1);
		(yyval.V) = v;
	}
#line 2321 "parser.tab.c"
    break;

  case 66:
#line 740 "parser.y"
                                               {
		backpatch((yyvsp[-1].C_instr).next, nextquad());
		gen_asig_binaria(TR_OP_SUMA, (yyvsp[-2].V), TS_cte_1(), (yyvsp[-2].V));
		gen_salto_incondicional((yyvsp[-3].E)+1);
		(yyval.C_instr).next = makelist((yyvsp[-3].E)+1);
	}
#line 2332 "parser.tab.c"
    break;

  case 69:
#line 763 "parser.y"
             { 
		/* comprobar que existe este tipo en la TS */	
	
	}
#line 2341 "parser.tab.c"
    break;

  case 70:
#line 767 "parser.y"
                  {
		(yyval.C_tipo) = (yyvsp[0].C_tipo);
	}
#line 2349 "parser.tab.c"
    break;

  case 71:
#line 772 "parser.y"
                                      { 
		/* insertar nuevo tipo tupla en TS*/
	}
#line 2357 "parser.tab.c"
    break;

  case 72:
#line 775 "parser.y"
                                                                                          {
		/* insertar nuevo tipo tabla en TS */
	}
#line 2365 "parser.tab.c"
    break;

  case 73:
#line 778 "parser.y"
                                              {
		/* insertar nuevo tipo subrango en TS */
	}
#line 2373 "parser.tab.c"
    break;

  case 74:
#line 781 "parser.y"
                       {
		/* insertar nuevo tipo ptro en TS */
	}
#line 2381 "parser.tab.c"
    break;

  case 75:
#line 784 "parser.y"
                      {
		/* insertar nuevo tipo base en TS */

		(yyval.C_tipo) = (yyvsp[0].C_tipo_base);
	}
#line 2391 "parser.tab.c"
    break;

  case 80:
#line 800 "parser.y"
                                                                      { int id=TS_insertar_simbolo((yyvsp[-4].C_id)); TS_modificar_simbolo(id, TS_CTE | (yyvsp[-2].C_cte).tipo); TS_modificar_cte(id,(yyvsp[-2].C_cte).val); }
#line 2397 "parser.tab.c"
    break;

  case 82:
#line 804 "parser.y"
                { (yyval.C_cte) = (yyvsp[0].C_cte); }
#line 2403 "parser.tab.c"
    break;

  case 83:
#line 805 "parser.y"
                             { (yyval.C_cte).tipo = TS_BOOLEANO; (yyval.C_cte).val.booleano = (yyvsp[0].C_literal_booleano); }
#line 2409 "parser.tab.c"
    break;

  case 84:
#line 807 "parser.y"
                         { (yyval.C_cte).tipo = TS_ENTERO; (yyval.C_cte).val.entero = (yyvsp[0].C_literal_entero);  }
#line 2415 "parser.tab.c"
    break;

  case 85:
#line 808 "parser.y"
                         { (yyval.C_cte).tipo = TS_REAL; (yyval.C_cte).val.real = (yyvsp[0].C_literal_real); }
#line 2421 "parser.tab.c"
    break;

  case 86:
#line 809 "parser.y"
                             { (yyval.C_cte).tipo = TS_CARACTER; (yyval.C_cte).val.caracter = (yyvsp[0].C_literal_caracter); }
#line 2427 "parser.tab.c"
    break;

  case 87:
#line 810 "parser.y"
                           { (yyval.C_cte).tipo = TS_STRING; strcpy((yyval.C_cte).val.string, (yyvsp[0].C_literal_string)); }
#line 2433 "parser.tab.c"
    break;

  case 88:
#line 813 "parser.y"
                                                                         { while(!pila_vacia((yyvsp[-4].C_lista_id))) { TS_modificar_var(desapilar((yyvsp[-4].C_lista_id)), (yyvsp[-2].C_id)); } }
#line 2439 "parser.tab.c"
    break;

  case 89:
#line 814 "parser.y"
                                                                              { while(!pila_vacia((yyvsp[-4].C_lista_id))) { TS_modificar_simbolo(desapilar((yyvsp[-4].C_lista_id)), TS_VAR | (yyvsp[-2].C_tipo)); } }
#line 2445 "parser.tab.c"
    break;

  case 91:
#line 817 "parser.y"
                                  { apilar((yyvsp[0].C_lista_id), TS_insertar_simbolo((yyvsp[-2].C_id))); (yyval.C_lista_id) = (yyvsp[0].C_lista_id); }
#line 2451 "parser.tab.c"
    break;

  case 92:
#line 818 "parser.y"
               { (yyval.C_lista_id) = crear_pila(); apilar((yyval.C_lista_id), TS_insertar_simbolo((yyvsp[0].C_id))); }
#line 2457 "parser.tab.c"
    break;


#line 2461 "parser.tab.c"

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
#line 864 "parser.y"

	/* Métodos auxiliares */
	int es_potencia_2(int n)
	{
		if(n < 0)
			n = -n;
		else if(n == 0)
			return 0;
		while((n > 1) && ((n % 2) == 0))
			n /= 2;
		return n == 1;
	}
	
	int log_base_2(int n)
	{
		// n debe ser potencia de 2 y mayor que 0
		int m = 0;
		while(n > 1)
		{
			n /= 2;
			m++;
		}
		return m;
	}
		
	/* Rutina principal */
	int main(int argc,char ** argv)
	{
		TS_inicializar();
		switch(yyparse())
		{
			case 0:
				printf("\nCompilación exitosa\n");
			break;
			case 1:
				printf("\nError en la compilación\n");
			break;
		}
		print_quads();
		TS_liberar();
	}
	
	int yyerror(const char* s)
	{
		printf("error de parseo(linea %d): %s\n", line_number, s);
	}
