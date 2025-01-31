/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LANG2_TAB_H_INCLUDED
# define YY_YY_LANG2_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DEFINE = 258,                  /* DEFINE  */
    ASSIGN = 259,                  /* ASSIGN  */
    ARRAY_DEF = 260,               /* ARRAY_DEF  */
    L_BRACKET = 261,               /* L_BRACKET  */
    R_BRACKET = 262,               /* R_BRACKET  */
    L_PARAN = 263,                 /* L_PARAN  */
    R_PARAN = 264,                 /* R_PARAN  */
    L_BRACE = 265,                 /* L_BRACE  */
    R_BRACE = 266,                 /* R_BRACE  */
    SEMIC = 267,                   /* SEMIC  */
    COMMA = 268,                   /* COMMA  */
    ADD = 269,                     /* ADD  */
    SUB = 270,                     /* SUB  */
    MUL = 271,                     /* MUL  */
    DIV = 272,                     /* DIV  */
    REM = 273,                     /* REM  */
    INCREM = 274,                  /* INCREM  */
    DECREM = 275,                  /* DECREM  */
    EQ = 276,                      /* EQ  */
    NE = 277,                      /* NE  */
    LT = 278,                      /* LT  */
    GT = 279,                      /* GT  */
    LTE = 280,                     /* LTE  */
    GTE = 281,                     /* GTE  */
    AND = 282,                     /* AND  */
    OR = 283,                      /* OR  */
    XOR = 284,                     /* XOR  */
    NOT = 285,                     /* NOT  */
    L_SHIFT = 286,                 /* L_SHIFT  */
    R_SHIFT = 287,                 /* R_SHIFT  */
    FUNCDECL = 288,                /* FUNCDECL  */
    FUNCCALL = 289,                /* FUNCCALL  */
    BREAK = 290,                   /* BREAK  */
    FOR = 291,                     /* FOR  */
    WHILE = 292,                   /* WHILE  */
    IF = 293,                      /* IF  */
    ELSE = 294,                    /* ELSE  */
    IDENT = 295,                   /* IDENT  */
    NUMBER = 296                   /* NUMBER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "lang2.y"

  struct node *np;
  char* sp;
  int   ival;

#line 111 "lang2.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LANG2_TAB_H_INCLUDED  */
