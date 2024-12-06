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

  int assign_count = 0, define_count = 0;
  extern Node *top;

#line 81 "lang2.tab.c"

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
  YYSYMBOL_CHAR = 41,                      /* CHAR  */
  YYSYMBOL_STRING = 42,                    /* STRING  */
  YYSYMBOL_NUMBER = 43,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 44,                     /* FLOAT  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_declarations = 47,              /* declarations  */
  YYSYMBOL_array_index = 48,               /* array_index  */
  YYSYMBOL_array = 49,                     /* array  */
  YYSYMBOL_decl_part = 50,                 /* decl_part  */
  YYSYMBOL_func_arg_part = 51,             /* func_arg_part  */
  YYSYMBOL_decl_statement = 52,            /* decl_statement  */
  YYSYMBOL_func_var_decl = 53,             /* func_var_decl  */
  YYSYMBOL_func_define = 54,               /* func_define  */
  YYSYMBOL_func_call = 55,                 /* func_call  */
  YYSYMBOL_statements = 56,                /* statements  */
  YYSYMBOL_statement = 57,                 /* statement  */
  YYSYMBOL_break_stmt = 58,                /* break_stmt  */
  YYSYMBOL_assignment = 59,                /* assignment  */
  YYSYMBOL_assignment_stmt = 60,           /* assignment_stmt  */
  YYSYMBOL_expression = 61,                /* expression  */
  YYSYMBOL_expressions = 62,               /* expressions  */
  YYSYMBOL_term = 63,                      /* term  */
  YYSYMBOL_unary_factor = 64,              /* unary_factor  */
  YYSYMBOL_factor = 65,                    /* factor  */
  YYSYMBOL_add_op = 66,                    /* add_op  */
  YYSYMBOL_sub_op = 67,                    /* sub_op  */
  YYSYMBOL_mul_op = 68,                    /* mul_op  */
  YYSYMBOL_div_op = 69,                    /* div_op  */
  YYSYMBOL_rem_op = 70,                    /* rem_op  */
  YYSYMBOL_unary_op = 71,                  /* unary_op  */
  YYSYMBOL_bit_op = 72,                    /* bit_op  */
  YYSYMBOL_var = 73,                       /* var  */
  YYSYMBOL_loop_stmt = 74,                 /* loop_stmt  */
  YYSYMBOL_while_stmt = 75,                /* while_stmt  */
  YYSYMBOL_for_stmt = 76,                  /* for_stmt  */
  YYSYMBOL_cond_stmt = 77,                 /* cond_stmt  */
  YYSYMBOL_if_stmt = 78,                   /* if_stmt  */
  YYSYMBOL_elif_stmt = 79,                 /* elif_stmt  */
  YYSYMBOL_condition = 80,                 /* condition  */
  YYSYMBOL_eq_op = 81,                     /* eq_op  */
  YYSYMBOL_ne_op = 82,                     /* ne_op  */
  YYSYMBOL_lt_op = 83,                     /* lt_op  */
  YYSYMBOL_gt_op = 84,                     /* gt_op  */
  YYSYMBOL_lte_op = 85,                    /* lte_op  */
  YYSYMBOL_gte_op = 86,                    /* gte_op  */
  YYSYMBOL_idents = 87                     /* idents  */
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
#define YYLAST   184

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    39,    39,    40,    44,    45,    49,    50,    54,    58,
      61,    67,    70,    76,    77,    82,    83,    87,    90,    96,
      99,   107,   108,   112,   113,   114,   115,   116,   120,   124,
     127,   130,   131,   132,   136,   140,   141,   142,   146,   147,
     151,   152,   153,   154,   155,   159,   160,   164,   165,   166,
     167,   172,   176,   180,   184,   188,   193,   194,   199,   200,
     201,   202,   203,   207,   208,   209,   210,   214,   215,   219,
     225,   228,   234,   235,   239,   245,   251,   252,   253,   254,
     255,   256,   260,   264,   268,   272,   276,   280,   284,   287
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
  "WHILE", "IF", "ELSE", "IDENT", "CHAR", "STRING", "NUMBER", "FLOAT",
  "$accept", "program", "declarations", "array_index", "array",
  "decl_part", "func_arg_part", "decl_statement", "func_var_decl",
  "func_define", "func_call", "statements", "statement", "break_stmt",
  "assignment", "assignment_stmt", "expression", "expressions", "term",
  "unary_factor", "factor", "add_op", "sub_op", "mul_op", "div_op",
  "rem_op", "unary_op", "bit_op", "var", "loop_stmt", "while_stmt",
  "for_stmt", "cond_stmt", "if_stmt", "elif_stmt", "condition", "eq_op",
  "ne_op", "lt_op", "gt_op", "lte_op", "gte_op", "idents", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-74)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-4)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,   -32,   -22,   -17,    15,    59,    26,    17,    33,    30,
     -74,    65,   -74,    67,   -74,   -74,   -74,    52,    91,    97,
      99,   100,    94,   117,   -74,   -74,    59,   -74,    92,   -74,
     -74,    82,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -32,    47,   -74,    51,   118,   -74,    -3,    47,    47,
       5,   -74,    47,   -74,   -74,   -74,   -74,    47,    85,    96,
     -74,   -74,   103,    41,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,    95,   -22,   121,   123,   128,    21,   126,   127,
     134,   131,   -74,   -74,   -74,   -74,   -74,   -74,   132,   -74,
     -74,    38,    38,   119,   -74,   -74,   136,    47,    47,    47,
      47,    47,   -74,   -74,   -74,   -74,   -74,    47,   -74,   -74,
      17,    83,   142,   141,    38,    23,   145,    47,    47,    47,
      47,    47,    47,    47,   151,   152,   -74,    47,    41,    41,
     -74,   -74,   -74,   -74,    59,   -74,    17,   -74,   155,    47,
     153,   156,    38,    38,    38,    38,    38,    38,    59,    59,
     105,   158,    59,   -74,    38,    59,    -9,   159,   160,   -74,
     -74,   161,   162,   165,   -74,   125,   -74,   -74,   166,   167,
      59,    59,   164,   168,   -74,   -74
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     5,    14,    89,
       9,     0,    10,     0,     1,    56,    57,     0,     0,     0,
       0,     0,     0,     0,    26,     2,    22,    27,     0,    23,
      31,     0,    24,    67,    68,    25,    72,    73,    13,     4,
      14,     0,     0,     8,     0,     0,    28,     0,     0,     0,
       0,    45,     0,    21,    34,    46,    88,     0,     0,    63,
      64,    65,     0,    37,    48,    44,    35,    36,    40,    41,
      42,    47,     0,     0,     0,    15,     0,     0,     0,     0,
       0,     0,    76,    77,    78,    79,    80,    81,     0,    32,
      33,    29,    30,     0,    49,    66,     6,     0,     0,     0,
       0,     0,    58,    59,    60,    61,    62,     0,    11,    12,
       0,     0,     0,     0,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,     0,    51,    52,
      53,    54,    55,    43,     0,    16,     0,    20,     0,     0,
       0,     0,    82,    83,    84,    85,    86,    87,     0,     0,
       0,     0,     0,    19,    38,     0,     0,     0,     0,     7,
      18,     0,     0,     0,    69,    74,    17,    71,     0,     0,
       0,     0,     0,     0,    70,    75
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,    -4,   122,     3,   -74,   -74,   -74,    69,   178,
     -74,   -25,   -74,   -74,   -45,   -74,   -38,   -74,   -35,    -5,
     -73,   -74,   -74,   -74,   -74,   -74,   -15,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -43,   -74,   -74,   -74,   -74,
     -74,   -74,   143
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,    43,    23,     6,    75,     7,    76,    40,
      24,    25,    26,    27,    28,    29,    80,   115,    63,    64,
      65,    66,    67,    68,    69,    70,    31,   107,    71,    32,
      33,    34,    35,    36,    37,    81,    82,    83,    84,    85,
      86,    87,    10
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    53,    79,    39,    62,    12,    88,    51,     9,    78,
      15,    16,    91,    57,    92,    14,    15,    16,    11,    93,
       1,    30,     2,    13,    15,    16,   130,   131,   132,    57,
     113,    22,   138,    -3,   133,    58,   139,    22,    38,   114,
      15,    16,    30,    41,    51,    59,    89,    90,    60,    61,
       3,    58,    97,    98,    72,    57,    73,    99,   100,   101,
      74,    59,   128,   129,    60,    61,    15,    16,   102,   103,
     104,    42,   105,   106,   141,    44,   109,    58,    15,    16,
     142,   143,   144,   145,   146,   147,    72,    59,    73,   150,
      60,    61,    45,    17,    18,    19,    20,    21,    50,    22,
      42,   154,    42,    46,    54,    47,   134,    48,    49,   151,
      96,   163,   159,    15,    16,    15,    16,    97,    98,    97,
      98,    52,    55,   157,   158,    94,    77,   161,   126,    30,
     162,   110,   152,    97,    98,   108,   111,   112,   116,   117,
     124,   125,   127,    30,    30,   172,   173,    30,    97,    98,
      30,    30,   136,   137,   140,   118,   119,   120,   121,   122,
     123,   148,   149,   155,   169,    30,    30,   153,   156,   160,
     164,   165,   166,   167,   168,   174,   170,   171,     8,   175,
     135,    95,     0,     0,    56
};

static const yytype_int16 yycheck[] =
{
       5,    26,    47,     7,    42,     2,    49,    22,    40,    12,
      19,    20,    50,     8,    52,     0,    19,    20,    40,    57,
       3,    26,     5,    40,    19,    20,    99,   100,   101,     8,
       9,    40,     9,     0,   107,    30,    13,    40,    12,    77,
      19,    20,    47,    13,    59,    40,    41,    42,    43,    44,
      33,    30,    14,    15,     3,     8,     5,    16,    17,    18,
       9,    40,    97,    98,    43,    44,    19,    20,    27,    28,
      29,     6,    31,    32,   117,     8,    73,    30,    19,    20,
     118,   119,   120,   121,   122,   123,     3,    40,     5,   127,
      43,    44,    40,    34,    35,    36,    37,    38,     4,    40,
       6,   139,     6,    12,    12,     8,   110,     8,     8,   134,
       7,   156,     7,    19,    20,    19,    20,    14,    15,    14,
      15,     4,    40,   148,   149,    40,     8,   152,     9,   134,
     155,    10,   136,    14,    15,    40,    13,     9,    12,    12,
       9,     9,     6,   148,   149,   170,   171,   152,    14,    15,
     155,   156,    10,    12,     9,    21,    22,    23,    24,    25,
      26,    10,    10,    10,    39,   170,   171,    12,    12,    11,
      11,    11,    11,    11,     9,    11,    10,    10,     0,    11,
     111,    59,    -1,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,    33,    46,    47,    50,    52,    54,    40,
      87,    40,    49,    40,     0,    19,    20,    34,    35,    36,
      37,    38,    40,    49,    55,    56,    57,    58,    59,    60,
      64,    71,    74,    75,    76,    77,    78,    79,    12,    47,
      54,    13,     6,    48,     8,    40,    12,     8,     8,     8,
       4,    71,     4,    56,    12,    40,    87,     8,    30,    40,
      43,    44,    61,    63,    64,    65,    66,    67,    68,    69,
      70,    73,     3,     5,     9,    51,    53,     8,    12,    59,
      61,    80,    81,    82,    83,    84,    85,    86,    80,    41,
      42,    61,    61,    61,    40,    48,     7,    14,    15,    16,
      17,    18,    27,    28,    29,    31,    32,    72,    40,    49,
      10,    13,     9,     9,    61,    62,    12,    12,    21,    22,
      23,    24,    25,    26,     9,     9,     9,     6,    63,    63,
      65,    65,    65,    65,    47,    53,    10,    12,     9,    13,
       9,    80,    61,    61,    61,    61,    61,    61,    10,    10,
      61,    56,    47,    12,    61,    10,    12,    56,    56,     7,
      11,    56,    56,    59,    11,    11,    11,    11,     9,    39,
      10,    10,    56,    56,    11,    11
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    46,    47,    47,    48,    48,    49,    50,
      50,    51,    51,    52,    52,    53,    53,    54,    54,    55,
      55,    56,    56,    57,    57,    57,    57,    57,    58,    59,
      59,    59,    59,    59,    60,    61,    61,    61,    62,    62,
      63,    63,    63,    63,    63,    64,    64,    65,    65,    65,
      65,    66,    67,    68,    69,    70,    71,    71,    72,    72,
      72,    72,    72,    73,    73,    73,    73,    74,    74,    75,
      76,    76,    77,    77,    78,    79,    80,    80,    80,    80,
      80,    80,    81,    82,    83,    84,    85,    86,    87,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     3,     6,     2,     2,
       2,     2,     2,     2,     1,     1,     3,     9,     8,     6,
       5,     2,     1,     1,     1,     1,     1,     1,     2,     3,
       3,     1,     3,     3,     2,     1,     1,     1,     3,     1,
       1,     1,     1,     3,     1,     2,     2,     1,     1,     2,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     7,
      11,     8,     1,     1,     7,    11,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     1
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
#line 39 "lang2.y"
                            { top = build_node2(PROGRAM_AST, (yyvsp[-1].np), (yyvsp[0].np)); }
#line 1546 "lang2.tab.c"
    break;

  case 3: /* program: func_define  */
#line 40 "lang2.y"
                            { top = build_node1(PROGRAM_AST, (yyvsp[0].np)); }
#line 1552 "lang2.tab.c"
    break;

  case 4: /* declarations: decl_statement declarations  */
#line 44 "lang2.y"
                                { (yyval.np) = build_node2(DECLARATIONS_AST, (yyvsp[-1].np), (yyvsp[0].np)); }
#line 1558 "lang2.tab.c"
    break;

  case 5: /* declarations: decl_statement  */
#line 45 "lang2.y"
                                { (yyval.np) = build_node1(DECLARATIONS_AST, (yyvsp[0].np)); }
#line 1564 "lang2.tab.c"
    break;

  case 6: /* array_index: L_BRACKET expression R_BRACKET  */
#line 49 "lang2.y"
                                   {}
#line 1570 "lang2.tab.c"
    break;

  case 7: /* array_index: L_BRACKET expression R_BRACKET L_BRACKET expression R_BRACKET  */
#line 50 "lang2.y"
                                                                  {}
#line 1576 "lang2.tab.c"
    break;

  case 8: /* array: IDENT array_index  */
#line 54 "lang2.y"
                      { (yyval.np) = build_node2(ARRAY_AST, build_node0(IDENT_AST), (yyvsp[0].np)); }
#line 1582 "lang2.tab.c"
    break;

  case 9: /* decl_part: DEFINE idents  */
#line 58 "lang2.y"
                  {
    (yyval.np) = build_node1(DECL_PART_AST, (yyvsp[0].np));
  }
#line 1590 "lang2.tab.c"
    break;

  case 10: /* decl_part: ARRAY_DEF array  */
#line 61 "lang2.y"
                    {
    (yyval.np) = build_node1(DECL_PART_AST, (yyvsp[0].np));
  }
#line 1598 "lang2.tab.c"
    break;

  case 11: /* func_arg_part: DEFINE IDENT  */
#line 67 "lang2.y"
                 {
    (yyval.np) = build_node1(FUNC_ARG_PART_AST, build_node0(IDENT_AST));
  }
#line 1606 "lang2.tab.c"
    break;

  case 12: /* func_arg_part: ARRAY_DEF array  */
#line 70 "lang2.y"
                    {
    (yyval.np) = build_node1(FUNC_ARG_PART_AST, (yyvsp[0].np));
  }
#line 1614 "lang2.tab.c"
    break;

  case 13: /* decl_statement: decl_part SEMIC  */
#line 76 "lang2.y"
                    { (yyval.np) = build_node1(DECL_STATEMENT_AST, (yyvsp[-1].np)); }
#line 1620 "lang2.tab.c"
    break;

  case 14: /* decl_statement: func_define  */
#line 77 "lang2.y"
                    { (yyval.np) = build_node1(DECL_STATEMENT_AST, (yyvsp[0].np)); }
#line 1626 "lang2.tab.c"
    break;

  case 15: /* func_var_decl: func_arg_part  */
#line 82 "lang2.y"
                                      { (yyval.np) = build_node1(FUNC_VAR_DECL_AST, (yyvsp[0].np)); }
#line 1632 "lang2.tab.c"
    break;

  case 16: /* func_var_decl: func_arg_part COMMA func_var_decl  */
#line 83 "lang2.y"
                                      { (yyval.np) = build_node2(FUNC_VAR_DECL_AST, (yyvsp[-2].np), (yyvsp[0].np)); }
#line 1638 "lang2.tab.c"
    break;

  case 17: /* func_define: FUNCDECL IDENT L_PARAN func_var_decl R_PARAN L_BRACE declarations statements R_BRACE  */
#line 87 "lang2.y"
                                                                                         { 
    (yyval.np) = build_node4(FUNC_DEFINE_AST, build_node0(IDENT_AST), (yyvsp[-5].np), (yyvsp[-2].np), (yyvsp[-1].np));
  }
#line 1646 "lang2.tab.c"
    break;

  case 18: /* func_define: FUNCDECL IDENT L_PARAN R_PARAN L_BRACE declarations statements R_BRACE  */
#line 90 "lang2.y"
                                                                           { 
    (yyval.np) = build_node3(FUNC_DEFINE_AST, build_node0(IDENT_AST), (yyvsp[-2].np), (yyvsp[-1].np));
  }
#line 1654 "lang2.tab.c"
    break;

  case 19: /* func_call: FUNCCALL IDENT L_PARAN expressions R_PARAN SEMIC  */
#line 96 "lang2.y"
                                                     {
    (yyval.np) = build_node2(FUNC_CALL_AST, build_node0(IDENT_AST), (yyvsp[-2].np));
  }
#line 1662 "lang2.tab.c"
    break;

  case 20: /* func_call: FUNCCALL IDENT L_PARAN R_PARAN SEMIC  */
#line 99 "lang2.y"
                                          {
    (yyval.np) = build_node1(FUNC_CALL_AST, build_node0(IDENT_AST));
  }
#line 1670 "lang2.tab.c"
    break;

  case 21: /* statements: statement statements  */
#line 107 "lang2.y"
                         { (yyval.np) = build_node2(STATEMENTS_AST, (yyvsp[-1].np), (yyvsp[0].np)); }
#line 1676 "lang2.tab.c"
    break;

  case 22: /* statements: statement  */
#line 108 "lang2.y"
                         { (yyval.np) = build_node1(STATEMENTS_AST, (yyvsp[0].np)); }
#line 1682 "lang2.tab.c"
    break;

  case 23: /* statement: assignment_stmt  */
#line 112 "lang2.y"
                    { (yyval.np) = build_node1(STATEMENT_AST, (yyvsp[0].np)); }
#line 1688 "lang2.tab.c"
    break;

  case 24: /* statement: loop_stmt  */
#line 113 "lang2.y"
                    { (yyval.np) = build_node1(STATEMENT_AST, (yyvsp[0].np)); }
#line 1694 "lang2.tab.c"
    break;

  case 25: /* statement: cond_stmt  */
#line 114 "lang2.y"
                    { (yyval.np) = build_node1(STATEMENT_AST, (yyvsp[0].np)); }
#line 1700 "lang2.tab.c"
    break;

  case 26: /* statement: func_call  */
#line 115 "lang2.y"
                    { (yyval.np) = build_node1(STATEMENT_AST, (yyvsp[0].np)); }
#line 1706 "lang2.tab.c"
    break;

  case 27: /* statement: break_stmt  */
#line 116 "lang2.y"
                    { (yyval.np) = build_node1(STATEMENT_AST, (yyvsp[0].np)); }
#line 1712 "lang2.tab.c"
    break;

  case 28: /* break_stmt: BREAK SEMIC  */
#line 120 "lang2.y"
                { (yyval.np) = build_node1(BREAK_STMT_AST, build_node0(BREAK_AST));}
#line 1718 "lang2.tab.c"
    break;

  case 29: /* assignment: IDENT ASSIGN expression  */
#line 124 "lang2.y"
                            {
    (yyval.np) = build_node2(ASSIGNMENT_AST, build_node0(IDENT_AST), (yyvsp[0].np));
  }
#line 1726 "lang2.tab.c"
    break;

  case 30: /* assignment: array ASSIGN expression  */
#line 127 "lang2.y"
                             {
    (yyval.np) = build_node2(ASSIGNMENT_AST, (yyvsp[-2].np), (yyvsp[0].np));
  }
#line 1734 "lang2.tab.c"
    break;

  case 31: /* assignment: unary_factor  */
#line 130 "lang2.y"
                 { (yyval.np) = build_node1(ASSIGNMENT_AST, (yyvsp[0].np)); }
#line 1740 "lang2.tab.c"
    break;

  case 32: /* assignment: IDENT ASSIGN CHAR  */
#line 131 "lang2.y"
                      {}
#line 1746 "lang2.tab.c"
    break;

  case 33: /* assignment: IDENT ASSIGN STRING  */
#line 132 "lang2.y"
                        {}
#line 1752 "lang2.tab.c"
    break;

  case 34: /* assignment_stmt: assignment SEMIC  */
#line 136 "lang2.y"
                     { (yyval.np) = build_node1(ASSIGNMENT_STMT_AST, (yyvsp[-1].np)); }
#line 1758 "lang2.tab.c"
    break;

  case 43: /* term: term bit_op factor  */
#line 154 "lang2.y"
                       { (yyval.np) = build_node3(TERM_AST, (yyvsp[-2].np), (yyvsp[-1].np), (yyvsp[0].np)); }
#line 1764 "lang2.tab.c"
    break;

  case 45: /* unary_factor: IDENT unary_op  */
#line 159 "lang2.y"
                   { (yyval.np) = build_node2(UNARY_FACTOR_AST, build_node0(IDENT_AST), (yyvsp[0].np)); }
#line 1770 "lang2.tab.c"
    break;

  case 46: /* unary_factor: unary_op IDENT  */
#line 160 "lang2.y"
                   { (yyval.np) = build_node2(UNARY_FACTOR_AST, (yyvsp[-1].np), build_node0(IDENT_AST)); }
#line 1776 "lang2.tab.c"
    break;

  case 48: /* factor: unary_factor  */
#line 165 "lang2.y"
                                { (yyval.np) = build_node1(FACTOR_AST, (yyvsp[0].np)); }
#line 1782 "lang2.tab.c"
    break;

  case 49: /* factor: NOT IDENT  */
#line 166 "lang2.y"
                                { (yyval.np) = build_node1(FACTOR_AST, build_node0(IDENT_AST)); }
#line 1788 "lang2.tab.c"
    break;

  case 51: /* add_op: expression ADD term  */
#line 172 "lang2.y"
                        { (yyval.np) = build_node2(ADD_AST, (yyvsp[-2].np), (yyvsp[0].np)); }
#line 1794 "lang2.tab.c"
    break;

  case 52: /* sub_op: expression SUB term  */
#line 176 "lang2.y"
                        { (yyval.np) = build_node2(SUB_AST, (yyvsp[-2].np), (yyvsp[0].np)); }
#line 1800 "lang2.tab.c"
    break;

  case 53: /* mul_op: term MUL factor  */
#line 180 "lang2.y"
                    { (yyval.np) = build_node2(MUL_AST, (yyvsp[-2].np), (yyvsp[0].np)); }
#line 1806 "lang2.tab.c"
    break;

  case 54: /* div_op: term DIV factor  */
#line 184 "lang2.y"
                    { (yyval.np) = build_node2(DIV_AST, (yyvsp[-2].np), (yyvsp[0].np)); }
#line 1812 "lang2.tab.c"
    break;

  case 55: /* rem_op: term REM factor  */
#line 188 "lang2.y"
                    { (yyval.np) = build_node2(REM_AST, (yyvsp[-2].np), (yyvsp[0].np)); }
#line 1818 "lang2.tab.c"
    break;

  case 56: /* unary_op: INCREM  */
#line 193 "lang2.y"
           { (yyval.np) = build_node1(UNARY_OP_AST, build_node0(INCREM_AST));}
#line 1824 "lang2.tab.c"
    break;

  case 57: /* unary_op: DECREM  */
#line 194 "lang2.y"
           { (yyval.np) = build_node1(UNARY_OP_AST, build_node0(DECREM_AST));}
#line 1830 "lang2.tab.c"
    break;

  case 58: /* bit_op: AND  */
#line 199 "lang2.y"
            { (yyval.np) = build_node1(BIT_OP_AST, build_node0(AND_AST));}
#line 1836 "lang2.tab.c"
    break;

  case 59: /* bit_op: OR  */
#line 200 "lang2.y"
            { (yyval.np) = build_node1(BIT_OP_AST, build_node0(OR_AST));}
#line 1842 "lang2.tab.c"
    break;

  case 60: /* bit_op: XOR  */
#line 201 "lang2.y"
            { (yyval.np) = build_node1(BIT_OP_AST, build_node0(XOR_AST));}
#line 1848 "lang2.tab.c"
    break;

  case 61: /* bit_op: L_SHIFT  */
#line 202 "lang2.y"
            { (yyval.np) = build_node1(BIT_OP_AST, build_node0(L_SHIFT_AST));}
#line 1854 "lang2.tab.c"
    break;

  case 62: /* bit_op: R_SHIFT  */
#line 203 "lang2.y"
            { (yyval.np) = build_node1(BIT_OP_AST, build_node0(R_SHIFT_AST));}
#line 1860 "lang2.tab.c"
    break;

  case 63: /* var: IDENT  */
#line 207 "lang2.y"
                                { (yyval.np) = build_node0(IDENT_AST);}
#line 1866 "lang2.tab.c"
    break;

  case 64: /* var: NUMBER  */
#line 208 "lang2.y"
                                { (yyval.np) = build_node0(NUMBER_AST); }
#line 1872 "lang2.tab.c"
    break;

  case 65: /* var: FLOAT  */
#line 209 "lang2.y"
                                { (yyval.np) = build_node0(FLOAT_AST); }
#line 1878 "lang2.tab.c"
    break;

  case 66: /* var: IDENT array_index  */
#line 210 "lang2.y"
                                { (yyval.np) = build_node2(ARRAY_AST, build_node0(IDENT_AST), (yyvsp[0].np)); }
#line 1884 "lang2.tab.c"
    break;

  case 69: /* while_stmt: WHILE L_PARAN condition R_PARAN L_BRACE statements R_BRACE  */
#line 219 "lang2.y"
                                                               {
    (yyval.np) = build_node2(WHILE_STMT_AST, (yyvsp[-4].np), (yyvsp[-1].np));
  }
#line 1892 "lang2.tab.c"
    break;

  case 70: /* for_stmt: FOR L_PARAN assignment SEMIC condition SEMIC assignment R_PARAN L_BRACE statements R_BRACE  */
#line 225 "lang2.y"
                                                                                               {
    (yyval.np) = build_node4(FOR_STMT_AST, (yyvsp[-8].np), (yyvsp[-6].np), (yyvsp[-4].np), (yyvsp[-1].np));
  }
#line 1900 "lang2.tab.c"
    break;

  case 71: /* for_stmt: FOR L_PARAN SEMIC SEMIC R_PARAN L_BRACE statements R_BRACE  */
#line 228 "lang2.y"
                                                               {
    (yyval.np) = build_node1(FOR_STMT_AST, (yyvsp[-1].np));
  }
#line 1908 "lang2.tab.c"
    break;

  case 74: /* if_stmt: IF L_PARAN condition R_PARAN L_BRACE statements R_BRACE  */
#line 239 "lang2.y"
                                                            { 
    (yyval.np) = build_node2(COND_STMT_AST, (yyvsp[-4].np), (yyvsp[-1].np));
  }
#line 1916 "lang2.tab.c"
    break;

  case 75: /* elif_stmt: IF L_PARAN condition R_PARAN L_BRACE statements R_BRACE ELSE L_BRACE statements R_BRACE  */
#line 245 "lang2.y"
                                                                                            { 
    (yyval.np) = build_node3(COND_STMT_AST, (yyvsp[-8].np), (yyvsp[-5].np), (yyvsp[-1].np));
  }
#line 1924 "lang2.tab.c"
    break;

  case 82: /* eq_op: expression EQ expression  */
#line 260 "lang2.y"
                             { (yyval.np) = build_node2(EQ_AST, (yyvsp[-2].np), (yyvsp[0].np)); }
#line 1930 "lang2.tab.c"
    break;

  case 83: /* ne_op: expression NE expression  */
#line 264 "lang2.y"
                             { (yyval.np) = build_node2(NE_AST, (yyvsp[-2].np), (yyvsp[0].np)); }
#line 1936 "lang2.tab.c"
    break;

  case 84: /* lt_op: expression LT expression  */
#line 268 "lang2.y"
                             { (yyval.np) = build_node2(LT_AST, (yyvsp[-2].np), (yyvsp[0].np)); }
#line 1942 "lang2.tab.c"
    break;

  case 85: /* gt_op: expression GT expression  */
#line 272 "lang2.y"
                             { (yyval.np) = build_node2(GT_AST, (yyvsp[-2].np), (yyvsp[0].np)); }
#line 1948 "lang2.tab.c"
    break;

  case 86: /* lte_op: expression LTE expression  */
#line 276 "lang2.y"
                              { (yyval.np) = build_node2(LTE_AST, (yyvsp[-2].np), (yyvsp[0].np)); }
#line 1954 "lang2.tab.c"
    break;

  case 87: /* gte_op: expression GTE expression  */
#line 280 "lang2.y"
                              { (yyval.np) = build_node2(GTE_AST, (yyvsp[-2].np), (yyvsp[0].np)); }
#line 1960 "lang2.tab.c"
    break;

  case 88: /* idents: IDENT COMMA idents  */
#line 284 "lang2.y"
                       { 
    (yyval.np) = build_node2(IDENTS_AST, build_node0(IDENT_AST), (yyvsp[0].np)); 
  }
#line 1968 "lang2.tab.c"
    break;

  case 89: /* idents: IDENT  */
#line 287 "lang2.y"
                       { (yyval.np) = build_node1(IDENTS_AST, build_node0(IDENT_AST)); }
#line 1974 "lang2.tab.c"
    break;


#line 1978 "lang2.tab.c"

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

#line 290 "lang2.y"

