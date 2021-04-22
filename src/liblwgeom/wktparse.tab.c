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


/* Substitute the variable and function names.  */
#define yyparse         lwg_parse_yyparse
#define yylex           lwg_parse_yylex
#define yyerror         lwg_parse_yyerror
#define yydebug         lwg_parse_yydebug
#define yynerrs         lwg_parse_yynerrs
#define yylval          lwg_parse_yylval
#define yychar          lwg_parse_yychar
#define yylloc          lwg_parse_yylloc

/* First part of user prologue.  */
#line 9 "wktparse.y"

#include "wktparse.h"
#include <unistd.h>
#include <stdio.h>

void set_zm(char z, char m);
int lwg_parse_yylex(void);

#line 87 "y.tab.c"

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
#ifndef YY_LWG_PARSE_YY_Y_TAB_H_INCLUDED
# define YY_LWG_PARSE_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int lwg_parse_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    POINT = 258,
    LINESTRING = 259,
    POLYGON = 260,
    MULTIPOINT = 261,
    MULTILINESTRING = 262,
    MULTIPOLYGON = 263,
    GEOMETRYCOLLECTION = 264,
    CIRCULARSTRING = 265,
    COMPOUNDCURVE = 266,
    CURVEPOLYGON = 267,
    MULTICURVE = 268,
    MULTISURFACE = 269,
    POINTM = 270,
    LINESTRINGM = 271,
    POLYGONM = 272,
    MULTIPOINTM = 273,
    MULTILINESTRINGM = 274,
    MULTIPOLYGONM = 275,
    GEOMETRYCOLLECTIONM = 276,
    CIRCULARSTRINGM = 277,
    COMPOUNDCURVEM = 278,
    CURVEPOLYGONM = 279,
    MULTICURVEM = 280,
    MULTISURFACEM = 281,
    SRID = 282,
    EMPTY = 283,
    VALUE = 284,
    LPAREN = 285,
    RPAREN = 286,
    COMMA = 287,
    EQUALS = 288,
    SEMICOLON = 289,
    WKB = 290
  };
#endif
/* Tokens.  */
#define POINT 258
#define LINESTRING 259
#define POLYGON 260
#define MULTIPOINT 261
#define MULTILINESTRING 262
#define MULTIPOLYGON 263
#define GEOMETRYCOLLECTION 264
#define CIRCULARSTRING 265
#define COMPOUNDCURVE 266
#define CURVEPOLYGON 267
#define MULTICURVE 268
#define MULTISURFACE 269
#define POINTM 270
#define LINESTRINGM 271
#define POLYGONM 272
#define MULTIPOINTM 273
#define MULTILINESTRINGM 274
#define MULTIPOLYGONM 275
#define GEOMETRYCOLLECTIONM 276
#define CIRCULARSTRINGM 277
#define COMPOUNDCURVEM 278
#define CURVEPOLYGONM 279
#define MULTICURVEM 280
#define MULTISURFACEM 281
#define SRID 282
#define EMPTY 283
#define VALUE 284
#define LPAREN 285
#define RPAREN 286
#define COMMA 287
#define EQUALS 288
#define SEMICOLON 289
#define WKB 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "wktparse.y"

	double value;
	const char* wkb;

#line 214 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE lwg_parse_yylval;
extern YYLTYPE lwg_parse_yylloc;
int lwg_parse_yyparse (void);

#endif /* !YY_LWG_PARSE_YY_Y_TAB_H_INCLUDED  */



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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   180

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  107
/* YYNRULES -- Number of rules.  */
#define YYNRULES  169
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  237

#define YYUNDEFTOK  2
#define YYMAXUTOK   290


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
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    38,    38,    38,    40,    40,    43,    45,    47,    49,
      51,    53,    55,    57,    59,    61,    63,    65,    67,    70,
      73,    79,    81,    81,    84,    86,    89,    89,    92,    92,
      95,   100,   100,   102,   102,   105,   107,   107,   110,   112,
     115,   118,   118,   124,   126,   126,   129,   131,   134,   134,
     137,   137,   140,   140,   143,   143,   146,   148,   153,   155,
     155,   158,   160,   160,   163,   165,   168,   170,   173,   173,
     176,   176,   179,   179,   182,   182,   185,   187,   192,   192,
     194,   194,   197,   199,   199,   202,   204,   206,   208,   213,
     213,   216,   216,   220,   222,   222,   225,   227,   232,   232,
     235,   235,   239,   241,   241,   244,   246,   248,   250,   255,
     257,   257,   260,   262,   265,   265,   268,   268,   271,   271,
     274,   276,   281,   281,   283,   283,   287,   289,   289,   292,
     294,   296,   298,   303,   303,   305,   305,   309,   311,   311,
     314,   316,   321,   321,   323,   323,   327,   329,   329,   332,
     334,   336,   338,   343,   343,   346,   346,   350,   352,   352,
     356,   358,   360,   364,   366,   368,   371,   374,   377,   380
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "POINT", "LINESTRING", "POLYGON",
  "MULTIPOINT", "MULTILINESTRING", "MULTIPOLYGON", "GEOMETRYCOLLECTION",
  "CIRCULARSTRING", "COMPOUNDCURVE", "CURVEPOLYGON", "MULTICURVE",
  "MULTISURFACE", "POINTM", "LINESTRINGM", "POLYGONM", "MULTIPOINTM",
  "MULTILINESTRINGM", "MULTIPOLYGONM", "GEOMETRYCOLLECTIONM",
  "CIRCULARSTRINGM", "COMPOUNDCURVEM", "CURVEPOLYGONM", "MULTICURVEM",
  "MULTISURFACEM", "SRID", "EMPTY", "VALUE", "LPAREN", "RPAREN", "COMMA",
  "EQUALS", "SEMICOLON", "WKB", "$accept", "geometry", "$@1", "$@2",
  "geometry_int", "srid", "geom_wkb", "geom_point", "$@3", "point",
  "empty_point", "$@4", "nonempty_point", "$@5", "point_int",
  "geom_multipoint", "$@6", "$@7", "multipoint", "$@8", "multipoint_int",
  "mpoint_element", "$@9", "geom_linestring", "$@10", "linestring",
  "empty_linestring", "$@11", "nonempty_linestring", "$@12",
  "nonempty_linestring_closed", "$@13", "linestring_1", "$@14",
  "linestring_int", "geom_circularstring", "$@15",
  "geom_circularstring_closed", "$@16", "circularstring",
  "circularstring_closed", "empty_circularstring", "$@17",
  "nonempty_circularstring", "$@18", "nonempty_circularstring_closed",
  "$@19", "circularstring_1", "$@20", "circularstring_int",
  "geom_compoundcurve", "$@21", "$@22", "compoundcurve", "$@23",
  "compoundcurve_int", "geom_multilinestring", "$@24", "$@25",
  "multilinestring", "$@26", "multilinestring_int", "geom_multicurve",
  "$@27", "$@28", "multicurve", "$@29", "multicurve_int", "geom_polygon",
  "$@30", "polygon", "empty_polygon", "$@31", "nonempty_polygon", "$@32",
  "polygon_1", "$@33", "polygon_int", "geom_curvepolygon", "$@34", "$@35",
  "curvepolygon", "$@36", "curvepolygon_int", "geom_multipolygon", "$@37",
  "$@38", "multipolygon", "$@39", "multipolygon_int", "geom_multisurface",
  "$@40", "$@41", "multisurface", "$@42", "multisurface_int",
  "geom_geometrycollection", "$@43", "$@44", "geometrycollection", "$@45",
  "geometrycollection_int", "a_point", "point_2d", "point_3d", "point_4d",
  "empty", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290
};
# endif

#define YYPACT_NINF (-166)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-117)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -17,   -14,    21,   145,    -7,     5,  -166,    29,    30,    40,
    -166,  -166,  -166,  -166,    51,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
      23,  -166,    53,  -166,  -166,    23,  -166,  -166,  -166,  -166,
      23,  -166,  -166,    23,    23,    23,    23,  -166,  -166,    23,
    -166,  -166,    23,    23,    23,    23,    29,    30,    40,    23,
      23,    23,    23,    51,    23,    23,    23,    23,   145,  -166,
    -166,    55,  -166,  -166,  -166,    56,  -166,  -166,    57,  -166,
      58,  -166,  -166,    59,  -166,  -166,    61,  -166,  -166,    62,
    -166,  -166,  -166,    63,  -166,    64,  -166,  -166,    65,  -166,
    -166,    66,  -166,  -166,    67,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,    70,
      54,  -166,  -166,  -166,    55,  -166,    72,  -166,  -166,   112,
      55,     8,    19,     8,    28,    73,  -166,   -18,  -166,  -166,
      16,  -166,    18,  -166,    55,  -166,    24,  -166,    31,  -166,
      33,  -166,    35,  -166,  -166,  -166,    42,    74,  -166,  -166,
    -166,  -166,    44,  -166,  -166,    46,  -166,  -166,    48,    76,
    -166,    55,  -166,  -166,  -166,    72,  -166,  -166,  -166,  -166,
    -166,  -166,   145,  -166,    55,  -166,     8,  -166,  -166,  -166,
    -166,    74,  -166,  -166,    19,  -166,     8,  -166,    28,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     0,     0,     1,    26,    48,   114,
      31,    89,   133,   153,    68,    78,   122,    98,   142,    22,
      44,   110,    33,    91,   135,   155,    59,    80,   124,   100,
     144,    20,     5,     6,     7,    13,     8,     9,    11,    14,
      15,    10,    12,    16,    17,    18,     2,    19,    21,    24,
       0,    25,     0,    43,    46,     0,    47,    54,   109,   112,
       0,   113,   118,    36,    94,   138,   158,    58,    64,     0,
      65,    74,    83,   127,   103,   147,    26,    48,   114,    36,
      94,   138,   158,    68,    83,   127,   103,   147,     0,   169,
      27,     0,    29,    49,    51,     0,   115,   117,     0,    32,
       0,    35,    90,     0,    93,   134,     0,   137,   154,     0,
     157,    69,    71,     0,    79,     0,    82,   123,     0,   126,
      99,     0,   102,   143,     0,   146,    23,    45,   111,    34,
      92,   136,   156,    60,    81,   125,   101,   145,     3,     0,
       0,   163,   164,   165,     0,    54,    28,    50,   116,     0,
       0,    50,    52,    50,   116,   166,    30,     0,    56,   120,
       0,    40,     0,    38,     0,    96,     0,   140,     0,   161,
       0,   160,     0,    76,    85,    86,     0,    68,    62,   129,
      54,   130,     0,   105,   106,     0,   149,   150,     0,   167,
      55,     0,   119,    54,    37,    28,    42,    95,    50,   139,
     116,   159,     0,    75,     0,    84,    50,    61,    66,    67,
      74,    68,    53,   128,    52,   104,    50,   148,   116,   168,
      57,   121,    39,    97,   141,   162,    77,    87,    88,    73,
      63,   131,   132,   107,   108,   151,   152
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,  -166,  -166,   -88,  -166,  -166,  -166,  -166,    27,
    -166,  -166,  -142,  -166,  -166,  -166,  -166,  -166,    32,  -166,
    -166,   -89,  -166,  -166,  -166,    36,  -166,  -166,  -108,  -166,
    -107,  -166,  -136,  -166,  -166,  -148,  -166,  -105,  -166,    60,
    -101,  -165,  -166,  -166,  -166,  -166,  -166,   -98,  -166,  -166,
    -166,  -166,  -166,    88,  -166,  -166,  -166,  -166,  -166,    93,
    -166,  -166,  -166,  -166,  -166,    89,  -166,  -166,  -166,  -166,
      68,  -166,  -166,  -146,  -166,  -166,  -166,  -166,  -147,  -166,
    -166,    91,  -166,  -166,  -166,  -166,  -166,    96,  -166,  -166,
    -166,  -166,  -166,    52,  -166,  -166,  -166,  -166,  -166,    92,
    -166,  -166,  -122,  -166,  -166,  -166,   -49
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    88,     3,    32,     4,    33,    34,    76,    48,
      49,    50,    51,    52,    92,    35,    63,    79,    99,   100,
     162,   163,   164,    36,    77,    53,    54,    55,    56,    57,
     179,   180,    94,    95,   157,    37,    83,   181,   211,    67,
     207,    68,    69,    70,    71,   209,   210,   112,   113,   172,
      38,    72,    84,   114,   115,   176,    39,    64,    80,   102,
     103,   166,    40,    74,    86,   120,   121,   185,    41,    78,
      58,    59,    60,    61,    62,    97,    98,   160,    42,    73,
      85,   117,   118,   182,    43,    65,    81,   105,   106,   168,
      44,    75,    87,   123,   124,   188,    45,    66,    82,   108,
     109,   170,   140,   141,   142,   143,   101
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     138,    90,   167,   175,   161,   184,    93,   187,   186,   159,
       1,    96,   208,   190,   191,   104,   107,   110,    14,     5,
     111,     6,   158,   116,   119,   122,   125,    46,   173,   177,
      26,   104,   107,   110,    47,   116,   119,   122,   125,   165,
      16,   178,   196,   174,   212,   183,   208,   192,   193,   194,
     195,    89,    28,   161,   224,   197,   198,   221,   228,   -28,
     -50,   169,   199,   200,   201,   202,   203,   204,   234,   220,
    -116,   236,   235,   205,   206,   213,   214,   215,   216,   217,
     218,   -70,   226,    91,   139,   156,   144,   145,   146,   147,
     223,   148,   149,   150,   151,   152,   153,   154,   227,   155,
     171,   -41,   189,   126,   -72,   219,   222,   231,   233,   232,
     230,   129,   229,   127,   225,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,   137,
      89,     0,     0,   133,     0,     0,   128,    31,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,   134,   130,   132,   136,   135,   131,     0,     0,
      31
};

static const yytype_int16 yycheck[] =
{
      88,    50,   148,   151,   146,   153,    55,   154,   154,   145,
      27,    60,   177,    31,    32,    64,    65,    66,    10,    33,
      69,     0,   144,    72,    73,    74,    75,    34,   150,    10,
      22,    80,    81,    82,    29,    84,    85,    86,    87,   147,
      12,    22,   164,   151,   180,   153,   211,    31,    32,    31,
      32,    28,    24,   195,   200,    31,    32,   193,   206,    30,
      30,   149,    31,    32,    31,    32,    31,    32,   216,   191,
      30,   218,   218,    31,    32,    31,    32,    31,    32,    31,
      32,    30,   204,    30,    29,    31,    30,    30,    30,    30,
     198,    30,    30,    30,    30,    30,    30,    30,   206,    29,
     149,    29,    29,    76,    30,    29,   195,   214,   216,   214,
     211,    79,   210,    77,   202,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    87,
      28,    -1,    -1,    83,    -1,    -1,    78,    35,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    84,    80,    82,    86,    85,    81,    -1,    -1,
      35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    37,    39,    41,    33,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    35,    40,    42,    43,    51,    59,    71,    86,    92,
      98,   104,   114,   120,   126,   132,    34,    29,    45,    46,
      47,    48,    49,    61,    62,    63,    64,    65,   106,   107,
     108,   109,   110,    52,    93,   121,   133,    75,    77,    78,
      79,    80,    87,   115,    99,   127,    44,    60,   105,    53,
      94,   122,   134,    72,    88,   116,   100,   128,    38,    28,
     142,    30,    50,   142,    68,    69,   142,   111,   112,    54,
      55,   142,    95,    96,   142,   123,   124,   142,   135,   136,
     142,   142,    83,    84,    89,    90,   142,   117,   118,   142,
     101,   102,   142,   129,   130,   142,    45,    61,   106,    54,
      95,   123,   135,    75,    89,   117,   101,   129,    40,    29,
     138,   139,   140,   141,    30,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    29,    31,    70,   138,    68,
     113,    48,    56,    57,    58,    64,    97,   109,   125,    40,
     137,   142,    85,   138,    64,    71,    91,    10,    22,    66,
      67,    73,   119,    64,    71,   103,   109,   114,   131,    29,
      31,    32,    31,    32,    31,    32,   138,    31,    32,    31,
      32,    31,    32,    31,    32,    31,    32,    76,    77,    81,
      82,    74,    68,    31,    32,    31,    32,    31,    32,    29,
     138,    68,    57,    64,   109,    40,   138,    64,    71,    83,
      76,    66,    73,    64,    71,   109,   114
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    38,    37,    39,    37,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    41,
      42,    43,    44,    43,    45,    45,    47,    46,    49,    48,
      50,    52,    51,    53,    51,    54,    55,    54,    56,    56,
      57,    58,    57,    59,    60,    59,    61,    61,    63,    62,
      65,    64,    67,    66,    69,    68,    70,    70,    71,    72,
      71,    73,    74,    73,    75,    75,    76,    76,    78,    77,
      80,    79,    82,    81,    84,    83,    85,    85,    87,    86,
      88,    86,    89,    90,    89,    91,    91,    91,    91,    93,
      92,    94,    92,    95,    96,    95,    97,    97,    99,    98,
     100,    98,   101,   102,   101,   103,   103,   103,   103,   104,
     105,   104,   106,   106,   108,   107,   110,   109,   112,   111,
     113,   113,   115,   114,   116,   114,   117,   118,   117,   119,
     119,   119,   119,   121,   120,   122,   120,   123,   124,   123,
     125,   125,   127,   126,   128,   126,   129,   130,   129,   131,
     131,   131,   131,   133,   132,   134,   132,   135,   136,   135,
     137,   137,   137,   138,   138,   138,   139,   140,   141,   142
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     0,     3,     1,     1,     0,     2,     0,     2,
       3,     0,     3,     0,     3,     1,     0,     4,     1,     3,
       1,     0,     2,     2,     0,     3,     1,     1,     0,     2,
       0,     2,     0,     2,     0,     4,     1,     3,     2,     0,
       3,     2,     0,     3,     1,     1,     1,     1,     0,     2,
       0,     2,     0,     2,     0,     4,     1,     3,     0,     3,
       0,     3,     1,     0,     4,     1,     1,     3,     3,     0,
       3,     0,     3,     1,     0,     4,     1,     3,     0,     3,
       0,     3,     1,     0,     4,     1,     1,     3,     3,     2,
       0,     3,     1,     1,     0,     2,     0,     2,     0,     4,
       1,     3,     0,     3,     0,     3,     1,     0,     4,     1,
       1,     3,     3,     0,     3,     0,     3,     1,     0,     4,
       1,     3,     0,     3,     0,     3,     1,     0,     4,     1,
       1,     3,     3,     0,     3,     0,     3,     1,     0,     4,
       1,     1,     3,     1,     1,     1,     2,     3,     4,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 38 "wktparse.y"
                         { alloc_lwgeom(srid); }
#line 1697 "y.tab.c"
    break;

  case 4:
#line 40 "wktparse.y"
        { alloc_lwgeom(-1); }
#line 1703 "y.tab.c"
    break;

  case 19:
#line 70 "wktparse.y"
                          { set_srid((yyvsp[0].value)); }
#line 1709 "y.tab.c"
    break;

  case 20:
#line 73 "wktparse.y"
            { alloc_wkb((yyvsp[0].wkb)); }
#line 1715 "y.tab.c"
    break;

  case 22:
#line 81 "wktparse.y"
               { set_zm(0, 1); }
#line 1721 "y.tab.c"
    break;

  case 26:
#line 89 "wktparse.y"
        { alloc_point(); }
#line 1727 "y.tab.c"
    break;

  case 27:
#line 89 "wktparse.y"
                                 { pop(); }
#line 1733 "y.tab.c"
    break;

  case 28:
#line 92 "wktparse.y"
        { alloc_point(); }
#line 1739 "y.tab.c"
    break;

  case 29:
#line 92 "wktparse.y"
                                     { pop(); }
#line 1745 "y.tab.c"
    break;

  case 31:
#line 100 "wktparse.y"
                   { alloc_multipoint(); }
#line 1751 "y.tab.c"
    break;

  case 32:
#line 100 "wktparse.y"
                                                       { pop(); }
#line 1757 "y.tab.c"
    break;

  case 33:
#line 102 "wktparse.y"
                    { set_zm(0, 1); alloc_multipoint(); }
#line 1763 "y.tab.c"
    break;

  case 34:
#line 102 "wktparse.y"
                                                                     {pop(); }
#line 1769 "y.tab.c"
    break;

  case 36:
#line 107 "wktparse.y"
        { alloc_counter(); }
#line 1775 "y.tab.c"
    break;

  case 37:
#line 107 "wktparse.y"
                                                          { pop(); }
#line 1781 "y.tab.c"
    break;

  case 41:
#line 118 "wktparse.y"
        { alloc_point(); }
#line 1787 "y.tab.c"
    break;

  case 42:
#line 118 "wktparse.y"
                                   { pop(); }
#line 1793 "y.tab.c"
    break;

  case 44:
#line 126 "wktparse.y"
                    { set_zm(0, 1); }
#line 1799 "y.tab.c"
    break;

  case 48:
#line 134 "wktparse.y"
        { alloc_linestring(); }
#line 1805 "y.tab.c"
    break;

  case 49:
#line 134 "wktparse.y"
                                      { pop(); }
#line 1811 "y.tab.c"
    break;

  case 50:
#line 137 "wktparse.y"
        { alloc_linestring(); }
#line 1817 "y.tab.c"
    break;

  case 51:
#line 137 "wktparse.y"
                                             { pop(); }
#line 1823 "y.tab.c"
    break;

  case 52:
#line 140 "wktparse.y"
        { alloc_linestring_closed(); }
#line 1829 "y.tab.c"
    break;

  case 53:
#line 140 "wktparse.y"
                                                    { pop(); }
#line 1835 "y.tab.c"
    break;

  case 54:
#line 143 "wktparse.y"
        { alloc_counter(); }
#line 1841 "y.tab.c"
    break;

  case 55:
#line 143 "wktparse.y"
                                                          { popc(); }
#line 1847 "y.tab.c"
    break;

  case 59:
#line 155 "wktparse.y"
                        {set_zm(0, 1); }
#line 1853 "y.tab.c"
    break;

  case 62:
#line 160 "wktparse.y"
                        {set_zm(0, 1); }
#line 1859 "y.tab.c"
    break;

  case 68:
#line 173 "wktparse.y"
        { alloc_circularstring(); }
#line 1865 "y.tab.c"
    break;

  case 69:
#line 173 "wktparse.y"
                                          { pop(); }
#line 1871 "y.tab.c"
    break;

  case 70:
#line 176 "wktparse.y"
        { alloc_circularstring(); }
#line 1877 "y.tab.c"
    break;

  case 71:
#line 176 "wktparse.y"
                                                     { pop(); }
#line 1883 "y.tab.c"
    break;

  case 72:
#line 179 "wktparse.y"
        { alloc_circularstring_closed(); }
#line 1889 "y.tab.c"
    break;

  case 73:
#line 179 "wktparse.y"
                                                            { pop(); }
#line 1895 "y.tab.c"
    break;

  case 74:
#line 182 "wktparse.y"
        { alloc_counter(); }
#line 1901 "y.tab.c"
    break;

  case 75:
#line 182 "wktparse.y"
                                                              { popc(); }
#line 1907 "y.tab.c"
    break;

  case 78:
#line 192 "wktparse.y"
                      { alloc_compoundcurve(); }
#line 1913 "y.tab.c"
    break;

  case 79:
#line 192 "wktparse.y"
                                                               { pop(); }
#line 1919 "y.tab.c"
    break;

  case 80:
#line 194 "wktparse.y"
                       {set_zm(0, 1); alloc_compoundcurve(); }
#line 1925 "y.tab.c"
    break;

  case 81:
#line 194 "wktparse.y"
                                                                             { pop(); }
#line 1931 "y.tab.c"
    break;

  case 83:
#line 199 "wktparse.y"
        { alloc_counter(); }
#line 1937 "y.tab.c"
    break;

  case 84:
#line 199 "wktparse.y"
                                                             { pop(); }
#line 1943 "y.tab.c"
    break;

  case 89:
#line 213 "wktparse.y"
                        { alloc_multilinestring(); }
#line 1949 "y.tab.c"
    break;

  case 90:
#line 214 "wktparse.y"
                                 { pop(); }
#line 1955 "y.tab.c"
    break;

  case 91:
#line 216 "wktparse.y"
                         { set_zm(0, 1); alloc_multilinestring(); }
#line 1961 "y.tab.c"
    break;

  case 92:
#line 217 "wktparse.y"
                                { pop(); }
#line 1967 "y.tab.c"
    break;

  case 94:
#line 222 "wktparse.y"
        { alloc_counter(); }
#line 1973 "y.tab.c"
    break;

  case 95:
#line 222 "wktparse.y"
                                                              { pop();}
#line 1979 "y.tab.c"
    break;

  case 98:
#line 232 "wktparse.y"
                   { alloc_multicurve(); }
#line 1985 "y.tab.c"
    break;

  case 99:
#line 233 "wktparse.y"
                           { pop(); }
#line 1991 "y.tab.c"
    break;

  case 100:
#line 235 "wktparse.y"
                    { set_zm(0, 1); alloc_multicurve(); }
#line 1997 "y.tab.c"
    break;

  case 101:
#line 236 "wktparse.y"
                           { pop(); }
#line 2003 "y.tab.c"
    break;

  case 103:
#line 241 "wktparse.y"
        { alloc_counter(); }
#line 2009 "y.tab.c"
    break;

  case 104:
#line 241 "wktparse.y"
                                                          { pop(); }
#line 2015 "y.tab.c"
    break;

  case 110:
#line 257 "wktparse.y"
                 { set_zm(0, 1); }
#line 2021 "y.tab.c"
    break;

  case 114:
#line 265 "wktparse.y"
        { alloc_polygon(); }
#line 2027 "y.tab.c"
    break;

  case 115:
#line 265 "wktparse.y"
                                    { pop(); }
#line 2033 "y.tab.c"
    break;

  case 116:
#line 268 "wktparse.y"
        { alloc_polygon(); }
#line 2039 "y.tab.c"
    break;

  case 117:
#line 268 "wktparse.y"
                                        { pop(); }
#line 2045 "y.tab.c"
    break;

  case 118:
#line 271 "wktparse.y"
        { alloc_counter(); }
#line 2051 "y.tab.c"
    break;

  case 119:
#line 271 "wktparse.y"
                                                       { pop();}
#line 2057 "y.tab.c"
    break;

  case 122:
#line 281 "wktparse.y"
                     { alloc_curvepolygon(); }
#line 2063 "y.tab.c"
    break;

  case 123:
#line 281 "wktparse.y"
                                                            { pop(); }
#line 2069 "y.tab.c"
    break;

  case 124:
#line 283 "wktparse.y"
                      { set_zm(0, 1); alloc_curvepolygon(); }
#line 2075 "y.tab.c"
    break;

  case 125:
#line 284 "wktparse.y"
                                     { pop(); }
#line 2081 "y.tab.c"
    break;

  case 127:
#line 289 "wktparse.y"
        { alloc_counter(); }
#line 2087 "y.tab.c"
    break;

  case 128:
#line 289 "wktparse.y"
                                                            { pop(); }
#line 2093 "y.tab.c"
    break;

  case 133:
#line 303 "wktparse.y"
                     { alloc_multipolygon(); }
#line 2099 "y.tab.c"
    break;

  case 134:
#line 303 "wktparse.y"
                                                            { pop(); }
#line 2105 "y.tab.c"
    break;

  case 135:
#line 305 "wktparse.y"
                      { set_zm(0, 1); alloc_multipolygon(); }
#line 2111 "y.tab.c"
    break;

  case 136:
#line 306 "wktparse.y"
                             { pop();}
#line 2117 "y.tab.c"
    break;

  case 138:
#line 311 "wktparse.y"
        { alloc_counter(); }
#line 2123 "y.tab.c"
    break;

  case 139:
#line 311 "wktparse.y"
                                                            { pop(); }
#line 2129 "y.tab.c"
    break;

  case 142:
#line 321 "wktparse.y"
                     {alloc_multisurface(); }
#line 2135 "y.tab.c"
    break;

  case 143:
#line 321 "wktparse.y"
                                                           { pop(); }
#line 2141 "y.tab.c"
    break;

  case 144:
#line 323 "wktparse.y"
                      { set_zm(0, 1); alloc_multisurface(); }
#line 2147 "y.tab.c"
    break;

  case 145:
#line 324 "wktparse.y"
                             { pop(); }
#line 2153 "y.tab.c"
    break;

  case 147:
#line 329 "wktparse.y"
        { alloc_counter(); }
#line 2159 "y.tab.c"
    break;

  case 148:
#line 329 "wktparse.y"
                                                            { pop(); }
#line 2165 "y.tab.c"
    break;

  case 153:
#line 343 "wktparse.y"
                           { alloc_geomertycollection(); }
#line 2171 "y.tab.c"
    break;

  case 154:
#line 344 "wktparse.y"
                                   { pop(); }
#line 2177 "y.tab.c"
    break;

  case 155:
#line 346 "wktparse.y"
                            { set_zm(0, 1); alloc_geomertycollection(); }
#line 2183 "y.tab.c"
    break;

  case 156:
#line 347 "wktparse.y"
                                   { pop();}
#line 2189 "y.tab.c"
    break;

  case 158:
#line 352 "wktparse.y"
        { alloc_counter(); }
#line 2195 "y.tab.c"
    break;

  case 159:
#line 352 "wktparse.y"
                                                                  { pop(); }
#line 2201 "y.tab.c"
    break;

  case 166:
#line 371 "wktparse.y"
                    {alloc_point_2d((yyvsp[-1].value),(yyvsp[0].value)); }
#line 2207 "y.tab.c"
    break;

  case 167:
#line 374 "wktparse.y"
                          {alloc_point_3d((yyvsp[-2].value),(yyvsp[-1].value),(yyvsp[0].value)); }
#line 2213 "y.tab.c"
    break;

  case 168:
#line 377 "wktparse.y"
                                {alloc_point_4d((yyvsp[-3].value),(yyvsp[-2].value),(yyvsp[-1].value),(yyvsp[0].value)); }
#line 2219 "y.tab.c"
    break;

  case 169:
#line 380 "wktparse.y"
              { alloc_empty(); }
#line 2225 "y.tab.c"
    break;


#line 2229 "y.tab.c"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 381 "wktparse.y"





