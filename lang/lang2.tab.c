/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lang2.y"

  #include <stdio.h>
  #include "lang2.tab.h"
  #include "ast2.h"
  extern int yylex();
  extern char* yytext;

  int assign_count = 0, define_count = 0;
  extern Node *top;

#line 82 "lang2.tab.c"

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

#include "lang2.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DEFINE = 3,                     /* DEFINE  */
  YYSYMBOL_ASSIGN = 4,                     /* ASSIGN  */
  YYSYMBOL_ARRAY_DEF = 5,                  /* ARRAY_DEF  */
  YYSYMBOL_L_BRACKET = 6,                  /* L_BRACKET  */
  YYSYMBOL_R_BRACKET = 7,                  /* R_BRACKET  */
  YYSYMBOL_L_PARAN = 8,                    /* L_PARAN  */
  YYSYMBOL_R_PARAN = 9,                    /* R_PARAN  */
  YYSYMBOL_L_BRACE = 10,                   /* L_BRACE  */
  YYSYMBOL_R_BRACE = 11,                   /* R_BRACE  */
  YYSYMBOL_SEMIC = 12,                     /* SEMIC  */
  YYSYMBOL_COMMA = 13,                     /* COMMA  */
  YYSYMBOL_ADD = 14,                       /* ADD  */
  YYSYMBOL_SUB = 15,                       /* SUB  */
  YYSYMBOL_MUL = 16,                       /* MUL  */
  YYSYMBOL_DIV = 17,                       /* DIV  */
  YYSYMBOL_REM = 18,                       /* REM  */
  YYSYMBOL_INCREM = 19,                    /* INCREM  */
  YYSYMBOL_DECREM = 20,                    /* DECREM  */
  YYSYMBOL_EQ = 21,                        /* EQ  */
  YYSYMBOL_NE = 22,                        /* NE  */
  YYSYMBOL_LT = 23,                        /* LT  */
  YYSYMBOL_GT = 24,                        /* GT  */
  YYSYMBOL_LTE = 25,                       /* LTE  */
  YYSYMBOL_GTE = 26,                       /* GTE  */
  YYSYMBOL_AND = 27,                       /* AND  */
  YYSYMBOL_OR = 28,                        /* OR  */
  YYSYMBOL_XOR = 29,                       /* XOR  */
  YYSYMBOL_NOT = 30,                       /* NOT  */
  YYSYMBOL_L_SHIFT = 31,                   /* L_SHIFT  */
  YYSYMBOL_R_SHIFT = 32,                   /* R_SHIFT  */
  YYSYMBOL_FUNCDECL = 33,                  /* FUNCDECL  */
  YYSYMBOL_FUNCCALL = 34,                  /* FUNCCALL  */
  YYSYMBOL_BREAK = 35,                     /* BREAK  */
  YYSYMBOL_FOR = 36,                       /* FOR  */
  YYSYMBOL_WHILE = 37,                     /* WHILE  */
  YYSYMBOL_IF = 38,                        /* IF  */
  YYSYMBOL_ELSE = 39,                      /* ELSE  */
  YYSYMBOL_IDENT = 40,                     /* IDENT  */
  YYSYMBOL_NUMBER = 41,                    /* NUMBER  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_declarations = 44,              /* declarations  */
  YYSYMBOL_array_index = 45,               /* array_index  */
  YYSYMBOL_array = 46,                     /* array  */
  YYSYMBOL_decl_part = 47,                 /* decl_part  */
  YYSYMBOL_func_arg_part = 48,             /* func_arg_part  */
  YYSYMBOL_decl_statement = 49,            /* decl_statement  */
  YYSYMBOL_func_var_decl = 50,             /* func_var_decl  */
  YYSYMBOL_func_define = 51,               /* func_define  */
  YYSYMBOL_func_call = 52,                 /* func_call  */
  YYSYMBOL_statements = 53,                /* statements  */
  YYSYMBOL_statement = 54,                 /* statement  */
  YYSYMBOL_break_stmt = 55,                /* break_stmt  */
  YYSYMBOL_assignment = 56,                /* assignment  */
  YYSYMBOL_assignment_stmt = 57,           /* assignment_stmt  */
  YYSYMBOL_expressions = 58,               /* expressions  */
  YYSYMBOL_expression = 59,                /* expression  */
  YYSYMBOL_term = 60,                      /* term  */
  YYSYMBOL_unary_factor = 61,              /* unary_factor  */
  YYSYMBOL_factor = 62,                    /* factor  */
  YYSYMBOL_add_op = 63,                    /* add_op  */
  YYSYMBOL_mul_op = 64,                    /* mul_op  */
  YYSYMBOL_unary_op = 65,                  /* unary_op  */
  YYSYMBOL_bit_op = 66,                    /* bit_op  */
  YYSYMBOL_var = 67,                       /* var  */
  YYSYMBOL_loop_stmt = 68,                 /* loop_stmt  */
  YYSYMBOL_while_stmt = 69,                /* while_stmt  */
  YYSYMBOL_for_stmt = 70,                  /* for_stmt  */
  YYSYMBOL_cond_stmt = 71,                 /* cond_stmt  */
  YYSYMBOL_if_stmt = 72,                   /* if_stmt  */
  YYSYMBOL_else_stmt = 73,                 /* else_stmt  */
  YYSYMBOL_elif_stmt = 74,                 /* elif_stmt  */
  YYSYMBOL_condition = 75,                 /* condition  */
  YYSYMBOL_comp_op = 76,                   /* comp_op  */
  YYSYMBOL_idents = 77                     /* idents  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   174

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    42,    42,    43,    47,    48,    52,    53,    54,    58,
      62,    65,    71,    74,    80,    81,    86,    89,    95,    98,
     104,   107,   115,   116,   120,   121,   122,   123,   124,   128,
     132,   135,   138,   142,   146,   147,   151,   159,   163,   174,
     191,   195,   203,   214,   215,   216,   217,   222,   223,   227,
     228,   229,   233,   234,   239,   240,   241,   242,   243,   247,
     248,   249,   253,   254,   258,   264,   267,   273,   274,   278,
     284,   290,   296,   319,   320,   321,   322,   323,   324,   328,
     331
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DEFINE", "ASSIGN",
  "ARRAY_DEF", "L_BRACKET", "R_BRACKET", "L_PARAN", "R_PARAN", "L_BRACE",
  "R_BRACE", "SEMIC", "COMMA", "ADD", "SUB", "MUL", "DIV", "REM", "INCREM",
  "DECREM", "EQ", "NE", "LT", "GT", "LTE", "GTE", "AND", "OR", "XOR",
  "NOT", "L_SHIFT", "R_SHIFT", "FUNCDECL", "FUNCCALL", "BREAK", "FOR",
  "WHILE", "IF", "ELSE", "IDENT", "NUMBER", "$accept", "program",
  "declarations", "array_index", "array", "decl_part", "func_arg_part",
  "decl_statement", "func_var_decl", "func_define", "func_call",
  "statements", "statement", "break_stmt", "assignment", "assignment_stmt",
  "expressions", "expression", "term", "unary_factor", "factor", "add_op",
  "mul_op", "unary_op", "bit_op", "var", "loop_stmt", "while_stmt",
  "for_stmt", "cond_stmt", "if_stmt", "else_stmt", "elif_stmt",
  "condition", "comp_op", "idents", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-45)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,   -32,   -27,   -17,    26,    24,    -2,     6,   -45,    34,
     -45,    49,   -45,    55,   -45,   -45,   -45,    17,    62,    57,
     102,   109,    69,   117,   -45,   -45,    24,   -45,   111,   -45,
     -45,    91,   -45,   -45,   -45,   -45,    93,   -45,   -45,   -45,
     -32,     8,   -45,   115,   126,   -45,     5,    12,    12,    12,
     -45,    12,   -45,   -45,   -45,   125,   -45,   -45,   -45,    12,
      98,    71,   -45,    72,    53,   -45,   -45,   -45,    99,   -27,
     130,   128,   133,    10,   131,   132,    79,   136,   137,    81,
      81,    24,    97,   -45,   -45,   141,   -45,   -45,    12,   -45,
     -45,   -45,   -45,   -45,   -45,   -45,   -45,    12,    12,   -45,
     -45,     6,    32,   138,   139,   140,   112,   143,    12,   -45,
     -45,   -45,   -45,   -45,   -45,    12,   144,   145,   142,   -45,
      12,    53,   -45,   -45,    24,   -45,     6,   -45,   146,    12,
     147,   148,    81,    24,    24,   -45,   100,   150,    24,   -45,
     -45,    24,    14,   151,   152,   -45,   -45,   153,   154,   157,
     -45,   -45,   -45,   -45,   149,    24,   156,   -45
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     3,     0,     5,    15,    80,
      10,     0,    11,     0,     1,    52,    53,     0,     0,     0,
       0,     0,     0,     0,    27,     2,    23,    28,     0,    24,
      32,     0,    25,    62,    63,    26,    67,    68,    14,     4,
       0,     0,     9,     0,     0,    29,     0,     0,     0,     0,
      41,     0,    22,    33,    42,     0,    71,    79,     8,     0,
       0,    59,    60,     0,    37,    45,    40,    43,     0,     0,
       0,    16,     0,     0,     0,     0,     0,     0,     0,    30,
      31,     0,     0,    46,    61,     6,    47,    48,     0,    49,
      50,    51,    54,    55,    56,    57,    58,     0,     0,    12,
      13,     0,     0,     0,     0,     0,    35,     0,     0,    73,
      74,    75,    76,    77,    78,     0,     0,     0,     0,    44,
       0,    36,    38,    39,     0,    17,     0,    21,     0,     0,
       0,     0,    72,     0,     0,    70,     0,     0,     0,    20,
      34,     0,     0,     0,     0,     7,    19,     0,     0,     0,
      64,    69,    18,    66,     0,     0,     0,    65
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -45,   -45,    -4,    95,     3,   -45,   -45,   -45,    66,   -45,
     -45,   -25,   -45,   -45,   -44,   -45,    40,   -37,    82,    -5,
     -30,   -45,   -45,   -15,   -45,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,   -42,   -45,   134
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,    42,    23,     6,    71,     7,    72,     8,
      24,    25,    26,    27,    28,    29,   105,    76,    64,    65,
      66,    88,    97,    31,    98,    67,    32,    33,    34,    35,
      36,    56,    37,    77,   115,    10
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      30,    52,    75,    39,    63,    12,    78,    50,     9,     1,
      38,     2,    79,    11,    80,    58,    59,    74,    59,   104,
      59,    30,    82,    13,    15,    16,    14,    15,    16,    15,
      16,    15,    16,    15,    16,    68,   106,    69,    60,     3,
      60,    30,    60,    15,    16,    22,    50,    40,    61,    62,
      61,    62,    61,    62,    22,    41,   118,    44,    17,    18,
      19,    20,    21,    43,    22,    46,   131,   122,   123,    89,
      90,    91,   100,    49,    45,    41,    30,    41,   132,    85,
      92,    93,    94,   136,    95,    96,    86,    87,    15,    16,
      15,    16,   106,    86,    87,    86,    87,   124,   149,   137,
     109,   110,   111,   112,   113,   114,   119,   145,   143,   144,
      47,    86,    87,   147,    86,    87,   148,    48,    68,    30,
      69,    51,   138,    53,    70,   129,    86,    87,    30,    30,
     156,    54,    55,    30,    73,    81,    30,    30,    83,    99,
     101,   102,   103,   107,   108,   116,   117,   120,   126,   128,
      30,   127,   130,   135,   133,   134,    84,   141,   139,   155,
     142,   146,   150,   151,   152,   153,   154,   157,   125,   140,
     121,     0,     0,     0,    57
};

static const yytype_int16 yycheck[] =
{
       5,    26,    46,     7,    41,     2,    48,    22,    40,     3,
      12,     5,    49,    40,    51,     7,     8,    12,     8,     9,
       8,    26,    59,    40,    19,    20,     0,    19,    20,    19,
      20,    19,    20,    19,    20,     3,    73,     5,    30,    33,
      30,    46,    30,    19,    20,    40,    61,    13,    40,    41,
      40,    41,    40,    41,    40,     6,    81,    40,    34,    35,
      36,    37,    38,     8,    40,     8,   108,    97,    98,    16,
      17,    18,    69,     4,    12,     6,    81,     6,   115,     7,
      27,    28,    29,   120,    31,    32,    14,    15,    19,    20,
      19,    20,   129,    14,    15,    14,    15,   101,   142,   124,
      21,    22,    23,    24,    25,    26,     9,     7,   133,   134,
       8,    14,    15,   138,    14,    15,   141,     8,     3,   124,
       5,     4,   126,    12,     9,    13,    14,    15,   133,   134,
     155,    40,    39,   138,     8,    10,   141,   142,    40,    40,
      10,    13,     9,    12,    12,     9,     9,     6,    10,     9,
     155,    12,     9,    11,    10,    10,    61,    10,    12,    10,
      12,    11,    11,    11,    11,    11,     9,    11,   102,   129,
      88,    -1,    -1,    -1,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,    33,    43,    44,    47,    49,    51,    40,
      77,    40,    46,    40,     0,    19,    20,    34,    35,    36,
      37,    38,    40,    46,    52,    53,    54,    55,    56,    57,
      61,    65,    68,    69,    70,    71,    72,    74,    12,    44,
      13,     6,    45,     8,    40,    12,     8,     8,     8,     4,
      65,     4,    53,    12,    40,    39,    73,    77,     7,     8,
      30,    40,    41,    59,    60,    61,    62,    67,     3,     5,
       9,    48,    50,     8,    12,    56,    59,    75,    75,    59,
      59,    10,    59,    40,    45,     7,    14,    15,    63,    16,
      17,    18,    27,    28,    29,    31,    32,    64,    66,    40,
      46,    10,    13,     9,     9,    58,    59,    12,    12,    21,
      22,    23,    24,    25,    26,    76,     9,     9,    53,     9,
       6,    60,    62,    62,    44,    50,    10,    12,     9,    13,
       9,    75,    59,    10,    10,    11,    59,    53,    44,    12,
      58,    10,    12,    53,    53,     7,    11,    53,    53,    56,
      11,    11,    11,    11,     9,    10,    53,    11
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    45,    45,    45,    46,
      47,    47,    48,    48,    49,    49,    50,    50,    51,    51,
      52,    52,    53,    53,    54,    54,    54,    54,    54,    55,
      56,    56,    56,    57,    58,    58,    59,    59,    60,    60,
      60,    61,    61,    62,    62,    62,    62,    63,    63,    64,
      64,    64,    65,    65,    66,    66,    66,    66,    66,    67,
      67,    67,    68,    68,    69,    70,    70,    71,    71,    72,
      73,    74,    75,    76,    76,    76,    76,    76,    76,    77,
      77
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     3,     6,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     3,     9,     8,
       6,     5,     2,     1,     1,     1,     1,     1,     1,     2,
       3,     3,     1,     2,     3,     1,     3,     1,     3,     3,
       1,     2,     2,     1,     3,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     7,    11,     8,     1,     1,     7,
       4,     2,     3,     1,     1,     1,     1,     1,     1,     3,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program: declarations statements  */
#line 42 "lang2.y"
                            { top = build_node2(PROGRAM_AST, (yyvsp[-1].np), (yyvsp[0].np)); }
#line 1526 "lang2.tab.c"
    break;

  case 3: /* program: declarations  */
#line 43 "lang2.y"
                            { top = build_node1(PROGRAM_AST, (yyvsp[0].np)); }
#line 1532 "lang2.tab.c"
    break;

  case 4: /* declarations: decl_statement declarations  */
#line 47 "lang2.y"
                                { (yyval.np) = build_node2(DECLARATIONS_AST, (yyvsp[-1].np), (yyvsp[0].np)); }
#line 1538 "lang2.tab.c"
    break;

  case 5: /* declarations: decl_statement  */
#line 48 "lang2.y"
                                { (yyval.np) = build_node1(DECLARATIONS_AST, (yyvsp[0].np)); }
#line 1544 "lang2.tab.c"
    break;

  case 6: /* array_index: L_BRACKET expression R_BRACKET  */
#line 52 "lang2.y"
                                   { (yyval.np) = build_node1(ARRAY_INDEX_AST, (yyvsp[-1].np)); }
#line 1550 "lang2.tab.c"
    break;

  case 7: /* array_index: L_BRACKET expression R_BRACKET L_BRACKET expression R_BRACKET  */
#line 53 "lang2.y"
                                                                  { (yyval.np) = build_node2(ARRAY_INDEX_AST, (yyvsp[-4].np), (yyvsp[-1].np)); }
#line 1556 "lang2.tab.c"
    break;

  case 8: /* array_index: L_BRACKET R_BRACKET  */
#line 54 "lang2.y"
                        { (yyval.np) = build_node0(ARRAY_INDEX_AST); }
#line 1562 "lang2.tab.c"
    break;

  case 9: /* array: IDENT array_index  */
#line 58 "lang2.y"
                      { (yyval.np) = build_node2(ARRAY_AST, build_ident_node(IDENT_AST, (yyvsp[-1].sp)), (yyvsp[0].np)); }
#line 1568 "lang2.tab.c"
    break;

  case 10: /* decl_part: DEFINE idents  */
#line 62 "lang2.y"
                  {
    (yyval.np) = build_node1(DECL_PART_AST, (yyvsp[0].np));
  }
#line 1576 "lang2.tab.c"
    break;

  case 11: /* decl_part: ARRAY_DEF array  */
#line 65 "lang2.y"
                    {
    (yyval.np) = build_node1(DECL_PART_AST, (yyvsp[0].np));
  }
#line 1584 "lang2.tab.c"
    break;

  case 12: /* func_arg_part: DEFINE IDENT  */
#line 71 "lang2.y"
                 {
    (yyval.np) = build_node1(FUNC_ARG_PART_AST, build_ident_node(IDENT_AST, (yyvsp[0].sp)));
  }
#line 1592 "lang2.tab.c"
    break;

  case 13: /* func_arg_part: ARRAY_DEF array  */
#line 74 "lang2.y"
                    {
    (yyval.np) = build_node1(FUNC_ARG_PART_AST, (yyvsp[0].np));
  }
#line 1600 "lang2.tab.c"
    break;

  case 14: /* decl_statement: decl_part SEMIC  */
#line 80 "lang2.y"
                    { (yyval.np) = build_node1(DECL_STATEMENT_AST, (yyvsp[-1].np)); }
#line 1606 "lang2.tab.c"
    break;

  case 15: /* decl_statement: func_define  */
#line 81 "lang2.y"
                    { (yyval.np) = build_node1(DECL_STATEMENT_AST, (yyvsp[0].np)); }
#line 1612 "lang2.tab.c"
    break;

  case 16: /* func_var_decl: func_arg_part  */
#line 86 "lang2.y"
                                      { 
    (yyval.np) = build_node1(FUNC_VAR_DECL_AST, (yyvsp[0].np)); 
  }
#line 1620 "lang2.tab.c"
    break;

  case 17: /* func_var_decl: func_arg_part COMMA func_var_decl  */
#line 89 "lang2.y"
                                      { 
    (yyval.np) = build_node2(FUNC_VAR_DECL_AST, (yyvsp[-2].np), (yyvsp[0].np)); 
  }
#line 1628 "lang2.tab.c"
    break;

  case 18: /* func_define: FUNCDECL IDENT L_PARAN func_var_decl R_PARAN L_BRACE declarations statements R_BRACE  */
#line 95 "lang2.y"
                                                                                         { 
    (yyval.np) = build_node4(FUNC_DEFINE_AST, build_ident_node(IDENT_AST, (yyvsp[-7].sp)), (yyvsp[-5].np), (yyvsp[-2].np), (yyvsp[-1].np));
  }
#line 1636 "lang2.tab.c"
    break;

  case 19: /* func_define: FUNCDECL IDENT L_PARAN R_PARAN L_BRACE declarations statements R_BRACE  */
#line 98 "lang2.y"
                                                                           { 
    (yyval.np) = build_node3(FUNC_DEFINE_AST, build_ident_node(IDENT_AST, (yyvsp[-6].sp)), (yyvsp[-2].np), (yyvsp[-1].np));
  }
#line 1644 "lang2.tab.c"
    break;

  case 20: /* func_call: FUNCCALL IDENT L_PARAN expressions R_PARAN SEMIC  */
#line 104 "lang2.y"
                                                     {
    (yyval.np) = build_node2(FUNC_CALL_AST, build_ident_node(IDENT_AST, (yyvsp[-4].sp)), (yyvsp[-2].np));
  }
#line 1652 "lang2.tab.c"
    break;

  case 21: /* func_call: FUNCCALL IDENT L_PARAN R_PARAN SEMIC  */
#line 107 "lang2.y"
                                          {
    (yyval.np) = build_node1(FUNC_CALL_AST, build_ident_node(IDENT_AST, (yyvsp[-3].sp)));
  }
#line 1660 "lang2.tab.c"
    break;

  case 22: /* statements: statement statements  */
#line 115 "lang2.y"
                         { (yyval.np) = build_node2(STATEMENTS_AST, (yyvsp[-1].np), (yyvsp[0].np)); }
#line 1666 "lang2.tab.c"
    break;

  case 23: /* statements: statement  */
#line 116 "lang2.y"
                         { (yyval.np) = build_node1(STATEMENTS_AST, (yyvsp[0].np)); }
#line 1672 "lang2.tab.c"
    break;

  case 24: /* statement: assignment_stmt  */
#line 120 "lang2.y"
                    { (yyval.np) = build_node1(STATEMENT_AST, (yyvsp[0].np)); }
#line 1678 "lang2.tab.c"
    break;

  case 25: /* statement: loop_stmt  */
#line 121 "lang2.y"
                    { (yyval.np) = build_node1(STATEMENT_AST, (yyvsp[0].np)); }
#line 1684 "lang2.tab.c"
    break;

  case 26: /* statement: cond_stmt  */
#line 122 "lang2.y"
                    { (yyval.np) = build_node1(STATEMENT_AST, (yyvsp[0].np)); }
#line 1690 "lang2.tab.c"
    break;

  case 27: /* statement: func_call  */
#line 123 "lang2.y"
                    { (yyval.np) = build_node1(STATEMENT_AST, (yyvsp[0].np)); }
#line 1696 "lang2.tab.c"
    break;

  case 28: /* statement: break_stmt  */
#line 124 "lang2.y"
                    { (yyval.np) = build_node1(STATEMENT_AST, (yyvsp[0].np)); }
#line 1702 "lang2.tab.c"
    break;

  case 29: /* break_stmt: BREAK SEMIC  */
#line 128 "lang2.y"
                { (yyval.np) = build_node1(BREAK_STMT_AST, build_node0(BREAK_AST));}
#line 1708 "lang2.tab.c"
    break;

  case 30: /* assignment: IDENT ASSIGN expression  */
#line 132 "lang2.y"
                            {
    (yyval.np) = build_node2(ASSIGNMENT_AST, build_ident_node(IDENT_AST, (yyvsp[-2].sp)), (yyvsp[0].np));
  }
#line 1716 "lang2.tab.c"
    break;

  case 31: /* assignment: array ASSIGN expression  */
#line 135 "lang2.y"
                             {
    (yyval.np) = build_node2(ASSIGNMENT_AST, (yyvsp[-2].np), (yyvsp[0].np));
  }
#line 1724 "lang2.tab.c"
    break;

  case 32: /* assignment: unary_factor  */
#line 138 "lang2.y"
                 { (yyval.np) = build_node1(ASSIGNMENT_AST, (yyvsp[0].np)); }
#line 1730 "lang2.tab.c"
    break;

  case 33: /* assignment_stmt: assignment SEMIC  */
#line 142 "lang2.y"
                     { (yyval.np) = (yyvsp[-1].np); }
#line 1736 "lang2.tab.c"
    break;

  case 34: /* expressions: expression COMMA expressions  */
#line 146 "lang2.y"
                                 { (yyval.np) = build_node2(EXPRESSIONS_AST, (yyvsp[-2].np), (yyvsp[0].np)); }
#line 1742 "lang2.tab.c"
    break;

  case 36: /* expression: expression add_op term  */
#line 151 "lang2.y"
                           {
    if ((yyvsp[-1].ival) == OP_ADD) {
      (yyval.np) = build_node2(ADD_AST, (yyvsp[-2].np), (yyvsp[0].np));
    }
    else if ((yyvsp[-1].ival) == OP_SUB) {
      (yyval.np) = build_node2(SUB_AST, (yyvsp[-2].np), (yyvsp[0].np));
    }
  }
#line 1755 "lang2.tab.c"
    break;

  case 38: /* term: term mul_op factor  */
#line 163 "lang2.y"
                       {
    if ((yyvsp[-1].ival) == OP_MUL) {
      (yyval.np) = build_node2(MUL_AST, (yyvsp[-2].np), (yyvsp[0].np));
    }
    else if ((yyvsp[-1].ival) == OP_DIV) {
      (yyval.np) = build_node2(DIV_AST, (yyvsp[-2].np), (yyvsp[0].np));
    }
    else if ((yyvsp[-1].ival) == OP_REM) {
      (yyval.np) = build_node2(REM_AST, (yyvsp[-2].np), (yyvsp[0].np));
    }
  }
#line 1771 "lang2.tab.c"
    break;

  case 39: /* term: term bit_op factor  */
#line 174 "lang2.y"
                       { 
    if ((yyvsp[-1].np) == OP_AND) {
      (yyval.np) = build_node2(AND_AST, (yyvsp[-2].np), (yyvsp[0].np));
    }
    else if ((yyvsp[-1].np) == OP_OR) {
      (yyval.np) = build_node2(OR_AST, (yyvsp[-2].np), (yyvsp[0].np));
    }
    else if ((yyvsp[-1].np) == OP_XOR) {
      (yyval.np) = build_node2(XOR_AST, (yyvsp[-2].np), (yyvsp[0].np));
    }
    else if ((yyvsp[-1].np) == OP_L_SHIFT) {
      (yyval.np) = build_node2(L_SHIFT_AST, (yyvsp[-2].np), (yyvsp[0].np));
    }
    else if ((yyvsp[-1].np) == OP_R_SHIFT) {
      (yyval.np) = build_node2(R_SHIFT_AST, (yyvsp[-2].np), (yyvsp[0].np));
    }
  }
#line 1793 "lang2.tab.c"
    break;

  case 41: /* unary_factor: IDENT unary_op  */
#line 195 "lang2.y"
                   {
    if ((yyvsp[0].np) == INCREM_AST) {
      (yyval.np) = build_node2(UNARY_OP_AST, build_node0(B_INCREM_AST), build_ident_node(IDENT_AST, (yyvsp[-1].sp))); 
    } 
    else if ((yyvsp[0].np) == DECREM_AST) {
      (yyval.np) = build_node2(UNARY_OP_AST, build_node0(B_DECREM_AST), build_ident_node(IDENT_AST, (yyvsp[-1].sp))); 
    }
  }
#line 1806 "lang2.tab.c"
    break;

  case 42: /* unary_factor: unary_op IDENT  */
#line 203 "lang2.y"
                   {
    if ((yyvsp[-1].np) == INCREM_AST) {
      (yyval.np) = build_node2(UNARY_OP_AST, build_node0(F_INCREM_AST), build_ident_node(IDENT_AST, (yyvsp[0].sp))); 
    } 
    else if ((yyvsp[-1].np) == DECREM_AST) {
      (yyval.np) = build_node2(UNARY_OP_AST, build_node0(F_DECREM_AST), build_ident_node(IDENT_AST, (yyvsp[0].sp))); 
    }
  }
#line 1819 "lang2.tab.c"
    break;

  case 44: /* factor: L_PARAN expression R_PARAN  */
#line 215 "lang2.y"
                                { (yyval.np) = (yyvsp[-1].np); }
#line 1825 "lang2.tab.c"
    break;

  case 46: /* factor: NOT IDENT  */
#line 217 "lang2.y"
                                { (yyval.np) = build_node1(NOT_AST, build_ident_node(IDENT_AST, (yyvsp[0].sp))); }
#line 1831 "lang2.tab.c"
    break;

  case 47: /* add_op: ADD  */
#line 222 "lang2.y"
        { (yyval.ival) = OP_ADD; }
#line 1837 "lang2.tab.c"
    break;

  case 48: /* add_op: SUB  */
#line 223 "lang2.y"
        { (yyval.ival) = OP_SUB; }
#line 1843 "lang2.tab.c"
    break;

  case 49: /* mul_op: MUL  */
#line 227 "lang2.y"
        { (yyval.ival) = OP_MUL; }
#line 1849 "lang2.tab.c"
    break;

  case 50: /* mul_op: DIV  */
#line 228 "lang2.y"
        { (yyval.ival) = OP_DIV; }
#line 1855 "lang2.tab.c"
    break;

  case 51: /* mul_op: REM  */
#line 229 "lang2.y"
        { (yyval.ival) = OP_REM; }
#line 1861 "lang2.tab.c"
    break;

  case 52: /* unary_op: INCREM  */
#line 233 "lang2.y"
           { (yyval.np) = INCREM_AST;}
#line 1867 "lang2.tab.c"
    break;

  case 53: /* unary_op: DECREM  */
#line 234 "lang2.y"
           { (yyval.np) = DECREM_AST;}
#line 1873 "lang2.tab.c"
    break;

  case 54: /* bit_op: AND  */
#line 239 "lang2.y"
            { (yyval.np) = OP_AND; }
#line 1879 "lang2.tab.c"
    break;

  case 55: /* bit_op: OR  */
#line 240 "lang2.y"
            { (yyval.np) = OP_OR; }
#line 1885 "lang2.tab.c"
    break;

  case 56: /* bit_op: XOR  */
#line 241 "lang2.y"
            { (yyval.np) = OP_XOR; }
#line 1891 "lang2.tab.c"
    break;

  case 57: /* bit_op: L_SHIFT  */
#line 242 "lang2.y"
            { (yyval.np) = OP_L_SHIFT; }
#line 1897 "lang2.tab.c"
    break;

  case 58: /* bit_op: R_SHIFT  */
#line 243 "lang2.y"
            { (yyval.np) = OP_R_SHIFT; }
#line 1903 "lang2.tab.c"
    break;

  case 59: /* var: IDENT  */
#line 247 "lang2.y"
                                { (yyval.np) = build_ident_node(IDENT_AST, (yyvsp[0].sp));}
#line 1909 "lang2.tab.c"
    break;

  case 60: /* var: NUMBER  */
#line 248 "lang2.y"
                                { (yyval.np) = build_num_node(NUMBER_AST, (yyvsp[0].ival)); }
#line 1915 "lang2.tab.c"
    break;

  case 61: /* var: IDENT array_index  */
#line 249 "lang2.y"
                                { (yyval.np) = build_node2(ARRAY_AST, build_ident_node(IDENT_AST, (yyvsp[-1].sp)), (yyvsp[0].np)); }
#line 1921 "lang2.tab.c"
    break;

  case 64: /* while_stmt: WHILE L_PARAN condition R_PARAN L_BRACE statements R_BRACE  */
#line 258 "lang2.y"
                                                               {
    (yyval.np) = build_node2(WHILE_STMT_AST, (yyvsp[-4].np), (yyvsp[-1].np));
  }
#line 1929 "lang2.tab.c"
    break;

  case 65: /* for_stmt: FOR L_PARAN assignment SEMIC condition SEMIC assignment R_PARAN L_BRACE statements R_BRACE  */
#line 264 "lang2.y"
                                                                                               {
    (yyval.np) = build_node4(FOR_STMT_AST, (yyvsp[-8].np), (yyvsp[-6].np), (yyvsp[-4].np), (yyvsp[-1].np));
  }
#line 1937 "lang2.tab.c"
    break;

  case 66: /* for_stmt: FOR L_PARAN SEMIC SEMIC R_PARAN L_BRACE statements R_BRACE  */
#line 267 "lang2.y"
                                                               {
    (yyval.np) = build_node1(FOR_STMT_AST, (yyvsp[-1].np));
  }
#line 1945 "lang2.tab.c"
    break;

  case 69: /* if_stmt: IF L_PARAN condition R_PARAN L_BRACE statements R_BRACE  */
#line 278 "lang2.y"
                                                            { 
    (yyval.np) = build_node2(IF_STMT_AST, (yyvsp[-4].np), (yyvsp[-1].np));
  }
#line 1953 "lang2.tab.c"
    break;

  case 70: /* else_stmt: ELSE L_BRACE statements R_BRACE  */
#line 284 "lang2.y"
                                    {
    (yyval.np) = build_node1(ELSE_STMT_AST, (yyvsp[-1].np));
  }
#line 1961 "lang2.tab.c"
    break;

  case 71: /* elif_stmt: if_stmt else_stmt  */
#line 290 "lang2.y"
                      { 
    (yyval.np) = build_node2(ELIF_STMT_AST, (yyvsp[-1].np), (yyvsp[0].np));
  }
#line 1969 "lang2.tab.c"
    break;

  case 72: /* condition: expression comp_op expression  */
#line 296 "lang2.y"
                                  {
    if ((yyvsp[-1].np) == OP_EQ) {
      (yyval.np) = build_node1(CONDITION_AST, build_node2(EQ_AST, (yyvsp[-2].np), (yyvsp[0].np)));
    }
    else if ((yyvsp[-1].np) == OP_NE) {
      (yyval.np) = build_node1(CONDITION_AST, build_node2(NE_AST, (yyvsp[-2].np), (yyvsp[0].np)));
    }
    else if ((yyvsp[-1].np) == OP_LT) {
      (yyval.np) = build_node1(CONDITION_AST, build_node2(LT_AST, (yyvsp[-2].np), (yyvsp[0].np)));
    }
    else if ((yyvsp[-1].np) == OP_GT) {
      (yyval.np) = build_node1(CONDITION_AST, build_node2(LTE_AST, (yyvsp[-2].np), (yyvsp[0].np)));
    }
    else if ((yyvsp[-1].np) == OP_LTE) {
      (yyval.np) = build_node1(CONDITION_AST, build_node2(LTE_AST, (yyvsp[-2].np), (yyvsp[0].np)));
    }
    else if ((yyvsp[-1].np) == OP_GTE) {
      (yyval.np) = build_node1(CONDITION_AST, build_node2(GTE_AST, (yyvsp[-2].np), (yyvsp[0].np)));
    }
  }
#line 1994 "lang2.tab.c"
    break;

  case 73: /* comp_op: EQ  */
#line 319 "lang2.y"
        { (yyval.np) = OP_EQ; }
#line 2000 "lang2.tab.c"
    break;

  case 74: /* comp_op: NE  */
#line 320 "lang2.y"
        { (yyval.np) = OP_NE; }
#line 2006 "lang2.tab.c"
    break;

  case 75: /* comp_op: LT  */
#line 321 "lang2.y"
        { (yyval.np) = OP_LT; }
#line 2012 "lang2.tab.c"
    break;

  case 76: /* comp_op: GT  */
#line 322 "lang2.y"
        { (yyval.np) = OP_GT; }
#line 2018 "lang2.tab.c"
    break;

  case 77: /* comp_op: LTE  */
#line 323 "lang2.y"
        { (yyval.np) = OP_LTE; }
#line 2024 "lang2.tab.c"
    break;

  case 78: /* comp_op: GTE  */
#line 324 "lang2.y"
        { (yyval.np) = OP_GTE; }
#line 2030 "lang2.tab.c"
    break;

  case 79: /* idents: IDENT COMMA idents  */
#line 328 "lang2.y"
                       { 
    (yyval.np) = build_node2(IDENTS_AST, build_ident_node(IDENT_AST, (yyvsp[-2].sp)), (yyvsp[0].np)); 
  }
#line 2038 "lang2.tab.c"
    break;

  case 80: /* idents: IDENT  */
#line 331 "lang2.y"
                       { (yyval.np) = build_node1(IDENTS_AST, build_ident_node(IDENT_AST, (yyvsp[0].sp))); }
#line 2044 "lang2.tab.c"
    break;


#line 2048 "lang2.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 334 "lang2.y"

