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
#line 26 "poet_yacc.y"

/*
   POET : Parameterized Optimizations for Empirical Tuning
   Copyright (c)  2008,  Qing Yi.  All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
 3. Neither the name of UTSA nor the names of its contributors may be used to
    endorse or promote products derived from this software without specific
    prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISEDOF THE POSSIBILITY OF SUCH DAMAGE.
*/
/*********************************************************************/
/*  Yacc parser for reading POET specifications and building AST     */
/*********************************************************************/
#define YYDEBUG 1
#define YYERROR_VERBOSE
#include <poet_config.h>
#include <assert.h>

YaccState yaccState;
int yylex();
void yyerror(const char *);

extern void* insert_input();
extern void set_input_debug();
extern void set_input_cond();
extern void set_input_annot();
extern void set_input_target();
extern void set_input_codeType();
extern void set_input_syntax();
extern void set_input_files();
extern void set_input_inline();

extern void* insert_output();
extern void set_output_target();
extern void set_output_syntax();
extern void set_output_file();
extern void set_output_cond();

extern void* insert_code();
extern void set_code_params();
extern void set_code_def();
extern void set_code_parse();
extern void set_code_lookahead();
extern void* set_code_attr();
extern void set_code_inherit();

extern void insert_source(void* code);
extern void* insert_xform();
extern void set_xform_params();
extern void set_xform_def();
extern void* set_local_static(void* id, void* code, LocalVarType t, void* restr, int insert);


extern void insert_eval();
extern void insert_cond();
extern void eval_define();

extern void insert_trace();
extern void* insert_parameter();
extern void set_param_type();
extern void set_param_default();
extern void set_param_parse();
extern void set_param_message();
extern void finish_parameter();
extern void* make_codeMatch();
extern void* make_annot_single();
extern void* make_annot_lbegin();
extern void* make_codeMatchQ();
extern void* make_empty_list();
extern void* make_empty();
extern void* make_any();
extern void* make_seq(void*, void*);
extern void* make_typelist2();
extern void* make_inputlist();
extern void* make_xformList();
extern void* make_sourceString();
extern void* make_sourceAssign();
extern void* make_codeRef();
extern void* make_traceVar();
extern void* negate_Iconst();
extern void* make_Iconst();
extern void* make_Iconst1();
extern void* make_tupleAccess();
extern void* make_type();
extern void* make_typeNot();
extern void* make_typeUop();
extern void* make_typeTor();
extern void* make_sourceQop();
extern void* make_sourceTop();
extern void* make_ifElse();
extern void* make_sourceBop();
extern void* make_sourceUop();
extern void* make_sourceStmt();
extern void* make_dummyOperator();
extern void* make_macroVar();
extern void* make_localPar();
extern void* make_varRef();
extern void* make_attrAccess();
extern void* make_sourceVector();
extern void* make_sourceVector2();
extern void* make_parseOperator();

#line 191 "poet_yacc.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ENDLIST = 258,                 /* ENDLIST  */
    ERROR = 259,                   /* ERROR  */
    SYNERROR = 260,                /* SYNERROR  */
    PARAMETER = 261,               /* PARAMETER  */
    DEFINE = 262,                  /* DEFINE  */
    EVAL = 263,                    /* EVAL  */
    LBEGIN = 264,                  /* LBEGIN  */
    RBEGIN = 265,                  /* RBEGIN  */
    PRINT = 266,                   /* PRINT  */
    INPUT_ENDFILE = 267,           /* INPUT_ENDFILE  */
    INPUT_ENDL = 268,              /* INPUT_ENDL  */
    INPUT_CONT = 269,              /* INPUT_CONT  */
    COND = 270,                    /* COND  */
    ANNOT = 271,                   /* ANNOT  */
    TO = 272,                      /* TO  */
    FROM = 273,                    /* FROM  */
    TYPE = 274,                    /* TYPE  */
    POETTYPE = 275,                /* POETTYPE  */
    SYNTAX = 276,                  /* SYNTAX  */
    MESSAGE = 277,                 /* MESSAGE  */
    LTAG = 278,                    /* LTAG  */
    RTAG = 279,                    /* RTAG  */
    ENDTAG = 280,                  /* ENDTAG  */
    PARS = 281,                    /* PARS  */
    XFORM = 282,                   /* XFORM  */
    OUTPUT = 283,                  /* OUTPUT  */
    PARSE = 284,                   /* PARSE  */
    LOOKAHEAD = 285,               /* LOOKAHEAD  */
    MATCH = 286,                   /* MATCH  */
    CODE = 287,                    /* CODE  */
    GLOBAL = 288,                  /* GLOBAL  */
    SOURCE = 289,                  /* SOURCE  */
    ENDCODE = 290,                 /* ENDCODE  */
    ENDXFORM = 291,                /* ENDXFORM  */
    INPUT = 292,                   /* INPUT  */
    ENDINPUT = 293,                /* ENDINPUT  */
    SEMICOLON = 294,               /* SEMICOLON  */
    IN = 295,                      /* IN  */
    SUCH_THAT = 296,               /* SUCH_THAT  */
    FOR = 297,                     /* FOR  */
    FOREACH = 298,                 /* FOREACH  */
    FOREACH_R = 299,               /* FOREACH_R  */
    DO = 300,                      /* DO  */
    ENDDO = 301,                   /* ENDDO  */
    BREAK = 302,                   /* BREAK  */
    CONTINUE = 303,                /* CONTINUE  */
    RETURN = 304,                  /* RETURN  */
    DEBUG = 305,                   /* DEBUG  */
    IF = 306,                      /* IF  */
    ELSE = 307,                    /* ELSE  */
    CASE = 308,                    /* CASE  */
    SWITCH = 309,                  /* SWITCH  */
    DEFAULT = 310,                 /* DEFAULT  */
    DOT3 = 311,                    /* DOT3  */
    DOT4 = 312,                    /* DOT4  */
    ASSIGN = 313,                  /* ASSIGN  */
    PLUS_ASSIGN = 314,             /* PLUS_ASSIGN  */
    MINUS_ASSIGN = 315,            /* MINUS_ASSIGN  */
    MULT_ASSIGN = 316,             /* MULT_ASSIGN  */
    DIVIDE_ASSIGN = 317,           /* DIVIDE_ASSIGN  */
    MOD_ASSIGN = 318,              /* MOD_ASSIGN  */
    COMMA = 319,                   /* COMMA  */
    QUESTION = 320,                /* QUESTION  */
    OR = 321,                      /* OR  */
    TOR = 322,                     /* TOR  */
    AND = 323,                     /* AND  */
    NOT = 324,                     /* NOT  */
    LT = 325,                      /* LT  */
    LE = 326,                      /* LE  */
    EQ = 327,                      /* EQ  */
    GT = 328,                      /* GT  */
    GE = 329,                      /* GE  */
    NE = 330,                      /* NE  */
    ARROW = 331,                   /* ARROW  */
    DARROW = 332,                  /* DARROW  */
    PLUS = 333,                    /* PLUS  */
    MINUS = 334,                   /* MINUS  */
    MULTIPLY = 335,                /* MULTIPLY  */
    DIVIDE = 336,                  /* DIVIDE  */
    MOD = 337,                     /* MOD  */
    STR_CONCAT = 338,              /* STR_CONCAT  */
    DCOLON = 339,                  /* DCOLON  */
    UMINUS = 340,                  /* UMINUS  */
    TILT = 341,                    /* TILT  */
    DELAY = 342,                   /* DELAY  */
    APPLY = 343,                   /* APPLY  */
    CLEAR = 344,                   /* CLEAR  */
    SAVE = 345,                    /* SAVE  */
    RESTORE = 346,                 /* RESTORE  */
    REVERSE = 347,                 /* REVERSE  */
    PERMUTE = 348,                 /* PERMUTE  */
    REPLACE = 349,                 /* REPLACE  */
    ASSERT = 350,                  /* ASSERT  */
    RANGE = 351,                   /* RANGE  */
    DUPLICATE = 352,               /* DUPLICATE  */
    REBUILD = 353,                 /* REBUILD  */
    VAR = 354,                     /* VAR  */
    MAP = 355,                     /* MAP  */
    TUPLE = 356,                   /* TUPLE  */
    LIST = 357,                    /* LIST  */
    LIST1 = 358,                   /* LIST1  */
    INT = 359,                     /* INT  */
    STRING = 360,                  /* STRING  */
    FLOAT = 361,                   /* FLOAT  */
    NAME = 362,                    /* NAME  */
    EXP = 363,                     /* EXP  */
    TRACE = 364,                   /* TRACE  */
    ERASE = 365,                   /* ERASE  */
    COPY = 366,                    /* COPY  */
    SPLIT = 367,                   /* SPLIT  */
    LEN = 368,                     /* LEN  */
    INSERT = 369,                  /* INSERT  */
    CAR = 370,                     /* CAR  */
    CDR = 371,                     /* CDR  */
    COLON = 372,                   /* COLON  */
    ID = 373,                      /* ID  */
    ICONST = 374,                  /* ICONST  */
    FCONST = 375,                  /* FCONST  */
    ANY = 376,                     /* ANY  */
    DOT = 377,                     /* DOT  */
    DOT2 = 378,                    /* DOT2  */
    POND = 379,                    /* POND  */
    LB = 380,                      /* LB  */
    RB = 381,                      /* RB  */
    LBR = 382,                     /* LBR  */
    RBR = 383,                     /* RBR  */
    LP = 384,                      /* LP  */
    RP = 385                       /* RP  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ENDLIST 258
#define ERROR 259
#define SYNERROR 260
#define PARAMETER 261
#define DEFINE 262
#define EVAL 263
#define LBEGIN 264
#define RBEGIN 265
#define PRINT 266
#define INPUT_ENDFILE 267
#define INPUT_ENDL 268
#define INPUT_CONT 269
#define COND 270
#define ANNOT 271
#define TO 272
#define FROM 273
#define TYPE 274
#define POETTYPE 275
#define SYNTAX 276
#define MESSAGE 277
#define LTAG 278
#define RTAG 279
#define ENDTAG 280
#define PARS 281
#define XFORM 282
#define OUTPUT 283
#define PARSE 284
#define LOOKAHEAD 285
#define MATCH 286
#define CODE 287
#define GLOBAL 288
#define SOURCE 289
#define ENDCODE 290
#define ENDXFORM 291
#define INPUT 292
#define ENDINPUT 293
#define SEMICOLON 294
#define IN 295
#define SUCH_THAT 296
#define FOR 297
#define FOREACH 298
#define FOREACH_R 299
#define DO 300
#define ENDDO 301
#define BREAK 302
#define CONTINUE 303
#define RETURN 304
#define DEBUG 305
#define IF 306
#define ELSE 307
#define CASE 308
#define SWITCH 309
#define DEFAULT 310
#define DOT3 311
#define DOT4 312
#define ASSIGN 313
#define PLUS_ASSIGN 314
#define MINUS_ASSIGN 315
#define MULT_ASSIGN 316
#define DIVIDE_ASSIGN 317
#define MOD_ASSIGN 318
#define COMMA 319
#define QUESTION 320
#define OR 321
#define TOR 322
#define AND 323
#define NOT 324
#define LT 325
#define LE 326
#define EQ 327
#define GT 328
#define GE 329
#define NE 330
#define ARROW 331
#define DARROW 332
#define PLUS 333
#define MINUS 334
#define MULTIPLY 335
#define DIVIDE 336
#define MOD 337
#define STR_CONCAT 338
#define DCOLON 339
#define UMINUS 340
#define TILT 341
#define DELAY 342
#define APPLY 343
#define CLEAR 344
#define SAVE 345
#define RESTORE 346
#define REVERSE 347
#define PERMUTE 348
#define REPLACE 349
#define ASSERT 350
#define RANGE 351
#define DUPLICATE 352
#define REBUILD 353
#define VAR 354
#define MAP 355
#define TUPLE 356
#define LIST 357
#define LIST1 358
#define INT 359
#define STRING 360
#define FLOAT 361
#define NAME 362
#define EXP 363
#define TRACE 364
#define ERASE 365
#define COPY 366
#define SPLIT 367
#define LEN 368
#define INSERT 369
#define CAR 370
#define CDR 371
#define COLON 372
#define ID 373
#define ICONST 374
#define FCONST 375
#define ANY 376
#define DOT 377
#define DOT2 378
#define POND 379
#define LB 380
#define RB 381
#define LBR 382
#define RBR 383
#define LP 384
#define RP 385

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ENDLIST = 3,                    /* ENDLIST  */
  YYSYMBOL_ERROR = 4,                      /* ERROR  */
  YYSYMBOL_SYNERROR = 5,                   /* SYNERROR  */
  YYSYMBOL_PARAMETER = 6,                  /* PARAMETER  */
  YYSYMBOL_DEFINE = 7,                     /* DEFINE  */
  YYSYMBOL_EVAL = 8,                       /* EVAL  */
  YYSYMBOL_LBEGIN = 9,                     /* LBEGIN  */
  YYSYMBOL_RBEGIN = 10,                    /* RBEGIN  */
  YYSYMBOL_PRINT = 11,                     /* PRINT  */
  YYSYMBOL_INPUT_ENDFILE = 12,             /* INPUT_ENDFILE  */
  YYSYMBOL_INPUT_ENDL = 13,                /* INPUT_ENDL  */
  YYSYMBOL_INPUT_CONT = 14,                /* INPUT_CONT  */
  YYSYMBOL_COND = 15,                      /* COND  */
  YYSYMBOL_ANNOT = 16,                     /* ANNOT  */
  YYSYMBOL_TO = 17,                        /* TO  */
  YYSYMBOL_FROM = 18,                      /* FROM  */
  YYSYMBOL_TYPE = 19,                      /* TYPE  */
  YYSYMBOL_POETTYPE = 20,                  /* POETTYPE  */
  YYSYMBOL_SYNTAX = 21,                    /* SYNTAX  */
  YYSYMBOL_MESSAGE = 22,                   /* MESSAGE  */
  YYSYMBOL_LTAG = 23,                      /* LTAG  */
  YYSYMBOL_RTAG = 24,                      /* RTAG  */
  YYSYMBOL_ENDTAG = 25,                    /* ENDTAG  */
  YYSYMBOL_PARS = 26,                      /* PARS  */
  YYSYMBOL_XFORM = 27,                     /* XFORM  */
  YYSYMBOL_OUTPUT = 28,                    /* OUTPUT  */
  YYSYMBOL_PARSE = 29,                     /* PARSE  */
  YYSYMBOL_LOOKAHEAD = 30,                 /* LOOKAHEAD  */
  YYSYMBOL_MATCH = 31,                     /* MATCH  */
  YYSYMBOL_CODE = 32,                      /* CODE  */
  YYSYMBOL_GLOBAL = 33,                    /* GLOBAL  */
  YYSYMBOL_SOURCE = 34,                    /* SOURCE  */
  YYSYMBOL_ENDCODE = 35,                   /* ENDCODE  */
  YYSYMBOL_ENDXFORM = 36,                  /* ENDXFORM  */
  YYSYMBOL_INPUT = 37,                     /* INPUT  */
  YYSYMBOL_ENDINPUT = 38,                  /* ENDINPUT  */
  YYSYMBOL_SEMICOLON = 39,                 /* SEMICOLON  */
  YYSYMBOL_IN = 40,                        /* IN  */
  YYSYMBOL_SUCH_THAT = 41,                 /* SUCH_THAT  */
  YYSYMBOL_FOR = 42,                       /* FOR  */
  YYSYMBOL_FOREACH = 43,                   /* FOREACH  */
  YYSYMBOL_FOREACH_R = 44,                 /* FOREACH_R  */
  YYSYMBOL_DO = 45,                        /* DO  */
  YYSYMBOL_ENDDO = 46,                     /* ENDDO  */
  YYSYMBOL_BREAK = 47,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 48,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 49,                    /* RETURN  */
  YYSYMBOL_DEBUG = 50,                     /* DEBUG  */
  YYSYMBOL_IF = 51,                        /* IF  */
  YYSYMBOL_ELSE = 52,                      /* ELSE  */
  YYSYMBOL_CASE = 53,                      /* CASE  */
  YYSYMBOL_SWITCH = 54,                    /* SWITCH  */
  YYSYMBOL_DEFAULT = 55,                   /* DEFAULT  */
  YYSYMBOL_DOT3 = 56,                      /* DOT3  */
  YYSYMBOL_DOT4 = 57,                      /* DOT4  */
  YYSYMBOL_ASSIGN = 58,                    /* ASSIGN  */
  YYSYMBOL_PLUS_ASSIGN = 59,               /* PLUS_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 60,              /* MINUS_ASSIGN  */
  YYSYMBOL_MULT_ASSIGN = 61,               /* MULT_ASSIGN  */
  YYSYMBOL_DIVIDE_ASSIGN = 62,             /* DIVIDE_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 63,                /* MOD_ASSIGN  */
  YYSYMBOL_COMMA = 64,                     /* COMMA  */
  YYSYMBOL_QUESTION = 65,                  /* QUESTION  */
  YYSYMBOL_OR = 66,                        /* OR  */
  YYSYMBOL_TOR = 67,                       /* TOR  */
  YYSYMBOL_AND = 68,                       /* AND  */
  YYSYMBOL_NOT = 69,                       /* NOT  */
  YYSYMBOL_LT = 70,                        /* LT  */
  YYSYMBOL_LE = 71,                        /* LE  */
  YYSYMBOL_EQ = 72,                        /* EQ  */
  YYSYMBOL_GT = 73,                        /* GT  */
  YYSYMBOL_GE = 74,                        /* GE  */
  YYSYMBOL_NE = 75,                        /* NE  */
  YYSYMBOL_ARROW = 76,                     /* ARROW  */
  YYSYMBOL_DARROW = 77,                    /* DARROW  */
  YYSYMBOL_PLUS = 78,                      /* PLUS  */
  YYSYMBOL_MINUS = 79,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 80,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 81,                    /* DIVIDE  */
  YYSYMBOL_MOD = 82,                       /* MOD  */
  YYSYMBOL_STR_CONCAT = 83,                /* STR_CONCAT  */
  YYSYMBOL_DCOLON = 84,                    /* DCOLON  */
  YYSYMBOL_UMINUS = 85,                    /* UMINUS  */
  YYSYMBOL_TILT = 86,                      /* TILT  */
  YYSYMBOL_DELAY = 87,                     /* DELAY  */
  YYSYMBOL_APPLY = 88,                     /* APPLY  */
  YYSYMBOL_CLEAR = 89,                     /* CLEAR  */
  YYSYMBOL_SAVE = 90,                      /* SAVE  */
  YYSYMBOL_RESTORE = 91,                   /* RESTORE  */
  YYSYMBOL_REVERSE = 92,                   /* REVERSE  */
  YYSYMBOL_PERMUTE = 93,                   /* PERMUTE  */
  YYSYMBOL_REPLACE = 94,                   /* REPLACE  */
  YYSYMBOL_ASSERT = 95,                    /* ASSERT  */
  YYSYMBOL_RANGE = 96,                     /* RANGE  */
  YYSYMBOL_DUPLICATE = 97,                 /* DUPLICATE  */
  YYSYMBOL_REBUILD = 98,                   /* REBUILD  */
  YYSYMBOL_VAR = 99,                       /* VAR  */
  YYSYMBOL_MAP = 100,                      /* MAP  */
  YYSYMBOL_TUPLE = 101,                    /* TUPLE  */
  YYSYMBOL_LIST = 102,                     /* LIST  */
  YYSYMBOL_LIST1 = 103,                    /* LIST1  */
  YYSYMBOL_INT = 104,                      /* INT  */
  YYSYMBOL_STRING = 105,                   /* STRING  */
  YYSYMBOL_FLOAT = 106,                    /* FLOAT  */
  YYSYMBOL_NAME = 107,                     /* NAME  */
  YYSYMBOL_EXP = 108,                      /* EXP  */
  YYSYMBOL_TRACE = 109,                    /* TRACE  */
  YYSYMBOL_ERASE = 110,                    /* ERASE  */
  YYSYMBOL_COPY = 111,                     /* COPY  */
  YYSYMBOL_SPLIT = 112,                    /* SPLIT  */
  YYSYMBOL_LEN = 113,                      /* LEN  */
  YYSYMBOL_INSERT = 114,                   /* INSERT  */
  YYSYMBOL_CAR = 115,                      /* CAR  */
  YYSYMBOL_CDR = 116,                      /* CDR  */
  YYSYMBOL_COLON = 117,                    /* COLON  */
  YYSYMBOL_ID = 118,                       /* ID  */
  YYSYMBOL_ICONST = 119,                   /* ICONST  */
  YYSYMBOL_FCONST = 120,                   /* FCONST  */
  YYSYMBOL_ANY = 121,                      /* ANY  */
  YYSYMBOL_DOT = 122,                      /* DOT  */
  YYSYMBOL_DOT2 = 123,                     /* DOT2  */
  YYSYMBOL_POND = 124,                     /* POND  */
  YYSYMBOL_LB = 125,                       /* LB  */
  YYSYMBOL_RB = 126,                       /* RB  */
  YYSYMBOL_LBR = 127,                      /* LBR  */
  YYSYMBOL_RBR = 128,                      /* RBR  */
  YYSYMBOL_LP = 129,                       /* LP  */
  YYSYMBOL_RP = 130,                       /* RP  */
  YYSYMBOL_YYACCEPT = 131,                 /* $accept  */
  YYSYMBOL_poet = 132,                     /* poet  */
  YYSYMBOL_sections = 133,                 /* sections  */
  YYSYMBOL_section = 134,                  /* section  */
  YYSYMBOL_135_1 = 135,                    /* @1  */
  YYSYMBOL_136_2 = 136,                    /* @2  */
  YYSYMBOL_137_3 = 137,                    /* @3  */
  YYSYMBOL_138_4 = 138,                    /* @4  */
  YYSYMBOL_139_5 = 139,                    /* @5  */
  YYSYMBOL_140_6 = 140,                    /* @6  */
  YYSYMBOL_141_7 = 141,                    /* @7  */
  YYSYMBOL_142_8 = 142,                    /* @8  */
  YYSYMBOL_143_9 = 143,                    /* @9  */
  YYSYMBOL_144_10 = 144,                   /* @10  */
  YYSYMBOL_145_11 = 145,                   /* @11  */
  YYSYMBOL_inputAttrs = 146,               /* inputAttrs  */
  YYSYMBOL_147_12 = 147,                   /* @12  */
  YYSYMBOL_inputAttr = 148,                /* inputAttr  */
  YYSYMBOL_149_13 = 149,                   /* @13  */
  YYSYMBOL_150_14 = 150,                   /* @14  */
  YYSYMBOL_151_15 = 151,                   /* @15  */
  YYSYMBOL_152_16 = 152,                   /* @16  */
  YYSYMBOL_153_17 = 153,                   /* @17  */
  YYSYMBOL_154_18 = 154,                   /* @18  */
  YYSYMBOL_outputAttrs = 155,              /* outputAttrs  */
  YYSYMBOL_156_19 = 156,                   /* @19  */
  YYSYMBOL_outputAttr = 157,               /* outputAttr  */
  YYSYMBOL_158_20 = 158,                   /* @20  */
  YYSYMBOL_159_21 = 159,                   /* @21  */
  YYSYMBOL_160_22 = 160,                   /* @22  */
  YYSYMBOL_161_23 = 161,                   /* @23  */
  YYSYMBOL_inputRHS = 162,                 /* inputRHS  */
  YYSYMBOL_codeAttrs = 163,                /* codeAttrs  */
  YYSYMBOL_164_24 = 164,                   /* @24  */
  YYSYMBOL_codeAttr = 165,                 /* codeAttr  */
  YYSYMBOL_166_25 = 166,                   /* @25  */
  YYSYMBOL_167_26 = 167,                   /* @26  */
  YYSYMBOL_168_27 = 168,                   /* @27  */
  YYSYMBOL_169_28 = 169,                   /* @28  */
  YYSYMBOL_170_29 = 170,                   /* @29  */
  YYSYMBOL_171_30 = 171,                   /* @30  */
  YYSYMBOL_matchSpec = 172,                /* matchSpec  */
  YYSYMBOL_varRef = 173,                   /* varRef  */
  YYSYMBOL_xformRef = 174,                 /* xformRef  */
  YYSYMBOL_codeRef = 175,                  /* codeRef  */
  YYSYMBOL_codePars = 176,                 /* codePars  */
  YYSYMBOL_177_31 = 177,                   /* @31  */
  YYSYMBOL_paramAttrs = 178,               /* paramAttrs  */
  YYSYMBOL_179_32 = 179,                   /* @32  */
  YYSYMBOL_paramAttr = 180,                /* paramAttr  */
  YYSYMBOL_181_33 = 181,                   /* @33  */
  YYSYMBOL_182_34 = 182,                   /* @34  */
  YYSYMBOL_183_35 = 183,                   /* @35  */
  YYSYMBOL_map = 184,                      /* map  */
  YYSYMBOL_185_36 = 185,                   /* @36  */
  YYSYMBOL_186_37 = 186,                   /* @37  */
  YYSYMBOL_mapEntries = 187,               /* mapEntries  */
  YYSYMBOL_singletype = 188,               /* singletype  */
  YYSYMBOL_typeSpec1 = 189,                /* typeSpec1  */
  YYSYMBOL_190_38 = 190,                   /* @38  */
  YYSYMBOL_191_39 = 191,                   /* @39  */
  YYSYMBOL_typeSpec = 192,                 /* typeSpec  */
  YYSYMBOL_193_40 = 193,                   /* @40  */
  YYSYMBOL_typeMulti = 194,                /* typeMulti  */
  YYSYMBOL_195_41 = 195,                   /* @41  */
  YYSYMBOL_196_42 = 196,                   /* @42  */
  YYSYMBOL_197_43 = 197,                   /* @43  */
  YYSYMBOL_198_44 = 198,                   /* @44  */
  YYSYMBOL_199_45 = 199,                   /* @45  */
  YYSYMBOL_200_46 = 200,                   /* @46  */
  YYSYMBOL_201_47 = 201,                   /* @47  */
  YYSYMBOL_typeList = 202,                 /* typeList  */
  YYSYMBOL_203_48 = 203,                   /* @48  */
  YYSYMBOL_typeTuple = 204,                /* typeTuple  */
  YYSYMBOL_205_49 = 205,                   /* @49  */
  YYSYMBOL_206_50 = 206,                   /* @50  */
  YYSYMBOL_patternSpec = 207,              /* patternSpec  */
  YYSYMBOL_208_51 = 208,                   /* @51  */
  YYSYMBOL_209_52 = 209,                   /* @52  */
  YYSYMBOL_210_53 = 210,                   /* @53  */
  YYSYMBOL_211_54 = 211,                   /* @54  */
  YYSYMBOL_212_55 = 212,                   /* @55  */
  YYSYMBOL_213_56 = 213,                   /* @56  */
  YYSYMBOL_214_57 = 214,                   /* @57  */
  YYSYMBOL_215_58 = 215,                   /* @58  */
  YYSYMBOL_216_59 = 216,                   /* @59  */
  YYSYMBOL_patternMulti = 217,             /* patternMulti  */
  YYSYMBOL_218_60 = 218,                   /* @60  */
  YYSYMBOL_patternList = 219,              /* patternList  */
  YYSYMBOL_220_61 = 220,                   /* @61  */
  YYSYMBOL_patternTuple = 221,             /* patternTuple  */
  YYSYMBOL_222_62 = 222,                   /* @62  */
  YYSYMBOL_223_63 = 223,                   /* @63  */
  YYSYMBOL_constant = 224,                 /* constant  */
  YYSYMBOL_parseType1 = 225,               /* parseType1  */
  YYSYMBOL_226_64 = 226,                   /* @64  */
  YYSYMBOL_227_65 = 227,                   /* @65  */
  YYSYMBOL_228_66 = 228,                   /* @66  */
  YYSYMBOL_229_67 = 229,                   /* @67  */
  YYSYMBOL_230_68 = 230,                   /* @68  */
  YYSYMBOL_231_69 = 231,                   /* @69  */
  YYSYMBOL_parseType = 232,                /* parseType  */
  YYSYMBOL_233_70 = 233,                   /* @70  */
  YYSYMBOL_parseElem = 234,                /* parseElem  */
  YYSYMBOL_235_71 = 235,                   /* @71  */
  YYSYMBOL_236_72 = 236,                   /* @72  */
  YYSYMBOL_237_73 = 237,                   /* @73  */
  YYSYMBOL_parseElemMulti = 238,           /* parseElemMulti  */
  YYSYMBOL_239_74 = 239,                   /* @74  */
  YYSYMBOL_parseElemTuple = 240,           /* parseElemTuple  */
  YYSYMBOL_241_75 = 241,                   /* @75  */
  YYSYMBOL_242_76 = 242,                   /* @76  */
  YYSYMBOL_parseElemList = 243,            /* parseElemList  */
  YYSYMBOL_244_77 = 244,                   /* @77  */
  YYSYMBOL_constantOrVar = 245,            /* constantOrVar  */
  YYSYMBOL_codeRHS = 246,                  /* codeRHS  */
  YYSYMBOL_247_78 = 247,                   /* @78  */
  YYSYMBOL_xformRHS = 248,                 /* xformRHS  */
  YYSYMBOL_249_79 = 249,                   /* @79  */
  YYSYMBOL_xformAttrs = 250,               /* xformAttrs  */
  YYSYMBOL_251_80 = 251,                   /* @80  */
  YYSYMBOL_xformAttr = 252,                /* xformAttr  */
  YYSYMBOL_253_81 = 253,                   /* @81  */
  YYSYMBOL_254_82 = 254,                   /* @82  */
  YYSYMBOL_xformPars = 255,                /* xformPars  */
  YYSYMBOL_256_83 = 256,                   /* @83  */
  YYSYMBOL_outputPars = 257,               /* outputPars  */
  YYSYMBOL_258_84 = 258,                   /* @84  */
  YYSYMBOL_outputPar = 259,                /* outputPar  */
  YYSYMBOL_260_85 = 260,                   /* @85  */
  YYSYMBOL_traceVars = 261,                /* traceVars  */
  YYSYMBOL_code = 262,                     /* code  */
  YYSYMBOL_263_86 = 263,                   /* @86  */
  YYSYMBOL_codeIf = 264,                   /* codeIf  */
  YYSYMBOL_265_87 = 265,                   /* @87  */
  YYSYMBOL_266_88 = 266,                   /* @88  */
  YYSYMBOL_267_89 = 267,                   /* @89  */
  YYSYMBOL_codeIfHelp = 268,               /* codeIfHelp  */
  YYSYMBOL_269_90 = 269,                   /* @90  */
  YYSYMBOL_code1 = 270,                    /* code1  */
  YYSYMBOL_271_91 = 271,                   /* @91  */
  YYSYMBOL_272_92 = 272,                   /* @92  */
  YYSYMBOL_273_93 = 273,                   /* @93  */
  YYSYMBOL_274_94 = 274,                   /* @94  */
  YYSYMBOL_275_95 = 275,                   /* @95  */
  YYSYMBOL_276_96 = 276,                   /* @96  */
  YYSYMBOL_277_97 = 277,                   /* @97  */
  YYSYMBOL_278_98 = 278,                   /* @98  */
  YYSYMBOL_279_99 = 279,                   /* @99  */
  YYSYMBOL_280_100 = 280,                  /* @100  */
  YYSYMBOL_281_101 = 281,                  /* @101  */
  YYSYMBOL_282_102 = 282,                  /* @102  */
  YYSYMBOL_283_103 = 283,                  /* @103  */
  YYSYMBOL_284_104 = 284,                  /* @104  */
  YYSYMBOL_285_105 = 285,                  /* @105  */
  YYSYMBOL_286_106 = 286,                  /* @106  */
  YYSYMBOL_287_107 = 287,                  /* @107  */
  YYSYMBOL_288_108 = 288,                  /* @108  */
  YYSYMBOL_foreach_body = 289,             /* foreach_body  */
  YYSYMBOL_e_code4 = 290,                  /* e_code4  */
  YYSYMBOL_patternAssign = 291,            /* patternAssign  */
  YYSYMBOL_292_109 = 292,                  /* @109  */
  YYSYMBOL_suchThat = 293,                 /* suchThat  */
  YYSYMBOL_294_110 = 294,                  /* @110  */
  YYSYMBOL_switchHelp = 295,               /* switchHelp  */
  YYSYMBOL_296_111 = 296,                  /* @111  */
  YYSYMBOL_297_112 = 297,                  /* @112  */
  YYSYMBOL_298_113 = 298,                  /* @113  */
  YYSYMBOL_299_114 = 299,                  /* @114  */
  YYSYMBOL_300_115 = 300,                  /* @115  */
  YYSYMBOL_code23 = 301,                   /* code23  */
  YYSYMBOL_code2 = 302,                    /* code2  */
  YYSYMBOL_303_116 = 303,                  /* @116  */
  YYSYMBOL_304_117 = 304,                  /* @117  */
  YYSYMBOL_code3 = 305,                    /* code3  */
  YYSYMBOL_306_118 = 306,                  /* @118  */
  YYSYMBOL_307_119 = 307,                  /* @119  */
  YYSYMBOL_308_120 = 308,                  /* @120  */
  YYSYMBOL_309_121 = 309,                  /* @121  */
  YYSYMBOL_code4 = 310,                    /* code4  */
  YYSYMBOL_311_122 = 311,                  /* @122  */
  YYSYMBOL_312_123 = 312,                  /* @123  */
  YYSYMBOL_313_124 = 313,                  /* @124  */
  YYSYMBOL_314_125 = 314,                  /* @125  */
  YYSYMBOL_315_126 = 315,                  /* @126  */
  YYSYMBOL_316_127 = 316,                  /* @127  */
  YYSYMBOL_317_128 = 317,                  /* @128  */
  YYSYMBOL_318_129 = 318,                  /* @129  */
  YYSYMBOL_319_130 = 319,                  /* @130  */
  YYSYMBOL_320_131 = 320,                  /* @131  */
  YYSYMBOL_code5 = 321,                    /* code5  */
  YYSYMBOL_322_132 = 322,                  /* @132  */
  YYSYMBOL_323_133 = 323,                  /* @133  */
  YYSYMBOL_324_134 = 324,                  /* @134  */
  YYSYMBOL_325_135 = 325,                  /* @135  */
  YYSYMBOL_326_136 = 326,                  /* @136  */
  YYSYMBOL_327_137 = 327,                  /* @137  */
  YYSYMBOL_328_138 = 328,                  /* @138  */
  YYSYMBOL_329_139 = 329,                  /* @139  */
  YYSYMBOL_330_140 = 330,                  /* @140  */
  YYSYMBOL_331_141 = 331,                  /* @141  */
  YYSYMBOL_code6 = 332,                    /* code6  */
  YYSYMBOL_333_142 = 333,                  /* @142  */
  YYSYMBOL_334_143 = 334,                  /* @143  */
  YYSYMBOL_335_144 = 335,                  /* @144  */
  YYSYMBOL_336_145 = 336,                  /* @145  */
  YYSYMBOL_337_146 = 337,                  /* @146  */
  YYSYMBOL_338_147 = 338,                  /* @147  */
  YYSYMBOL_339_148 = 339,                  /* @148  */
  YYSYMBOL_340_149 = 340,                  /* @149  */
  YYSYMBOL_code7 = 341,                    /* code7  */
  YYSYMBOL_342_150 = 342,                  /* @150  */
  YYSYMBOL_code7Help = 343,                /* code7Help  */
  YYSYMBOL_344_151 = 344,                  /* @151  */
  YYSYMBOL_code7Help2 = 345,               /* code7Help2  */
  YYSYMBOL_346_152 = 346,                  /* @152  */
  YYSYMBOL_code8 = 347,                    /* code8  */
  YYSYMBOL_348_153 = 348,                  /* @153  */
  YYSYMBOL_349_154 = 349,                  /* @154  */
  YYSYMBOL_350_155 = 350,                  /* @155  */
  YYSYMBOL_351_156 = 351,                  /* @156  */
  YYSYMBOL_352_157 = 352,                  /* @157  */
  YYSYMBOL_353_158 = 353,                  /* @158  */
  YYSYMBOL_354_159 = 354,                  /* @159  */
  YYSYMBOL_355_160 = 355,                  /* @160  */
  YYSYMBOL_356_161 = 356,                  /* @161  */
  YYSYMBOL_357_162 = 357,                  /* @162  */
  YYSYMBOL_358_163 = 358,                  /* @163  */
  YYSYMBOL_359_164 = 359,                  /* @164  */
  YYSYMBOL_360_165 = 360,                  /* @165  */
  YYSYMBOL_361_166 = 361,                  /* @166  */
  YYSYMBOL_362_167 = 362,                  /* @167  */
  YYSYMBOL_363_168 = 363,                  /* @168  */
  YYSYMBOL_364_169 = 364,                  /* @169  */
  YYSYMBOL_365_170 = 365,                  /* @170  */
  YYSYMBOL_366_171 = 366,                  /* @171  */
  YYSYMBOL_367_172 = 367,                  /* @172  */
  YYSYMBOL_368_173 = 368,                  /* @173  */
  YYSYMBOL_369_174 = 369,                  /* @174  */
  YYSYMBOL_370_175 = 370,                  /* @175  */
  YYSYMBOL_371_176 = 371,                  /* @176  */
  YYSYMBOL_paramRHS = 372,                 /* paramRHS  */
  YYSYMBOL_373_177 = 373,                  /* @177  */
  YYSYMBOL_eraseRHS = 374,                 /* eraseRHS  */
  YYSYMBOL_375_178 = 375,                  /* @178  */
  YYSYMBOL_debugConfig = 376,              /* debugConfig  */
  YYSYMBOL_inputBase = 377,                /* inputBase  */
  YYSYMBOL_378_179 = 378,                  /* @179  */
  YYSYMBOL_379_180 = 379,                  /* @180  */
  YYSYMBOL_380_181 = 380,                  /* @181  */
  YYSYMBOL_code9 = 381,                    /* code9  */
  YYSYMBOL_382_182 = 382,                  /* @182  */
  YYSYMBOL_383_183 = 383,                  /* @183  */
  YYSYMBOL_384_184 = 384,                  /* @184  */
  YYSYMBOL_385_185 = 385,                  /* @185  */
  YYSYMBOL_386_186 = 386,                  /* @186  */
  YYSYMBOL_codeUnit = 387,                 /* codeUnit  */
  YYSYMBOL_388_187 = 388,                  /* @187  */
  YYSYMBOL_varInvoke = 389,                /* varInvoke  */
  YYSYMBOL_390_188 = 390,                  /* @188  */
  YYSYMBOL_391_189 = 391,                  /* @189  */
  YYSYMBOL_varInvoke1 = 392,               /* varInvoke1  */
  YYSYMBOL_393_190 = 393,                  /* @190  */
  YYSYMBOL_394_191 = 394,                  /* @191  */
  YYSYMBOL_pond = 395,                     /* pond  */
  YYSYMBOL_396_192 = 396,                  /* @192  */
  YYSYMBOL_varInvokeType = 397,            /* varInvokeType  */
  YYSYMBOL_398_193 = 398,                  /* @193  */
  YYSYMBOL_varInvokeType1 = 399,           /* varInvokeType1  */
  YYSYMBOL_400_194 = 400,                  /* @194  */
  YYSYMBOL_401_195 = 401,                  /* @195  */
  YYSYMBOL_varInvokePattern = 402,         /* varInvokePattern  */
  YYSYMBOL_403_196 = 403,                  /* @196  */
  YYSYMBOL_varInvokePattern1 = 404,        /* varInvokePattern1  */
  YYSYMBOL_405_197 = 405,                  /* @197  */
  YYSYMBOL_406_198 = 406,                  /* @198  */
  YYSYMBOL_configOrSubRef = 407,           /* configOrSubRef  */
  YYSYMBOL_selectRef = 408,                /* selectRef  */
  YYSYMBOL_409_199 = 409,                  /* @199  */
  YYSYMBOL_configRef = 410,                /* configRef  */
  YYSYMBOL_411_200 = 411,                  /* @200  */
  YYSYMBOL_412_201 = 412,                  /* @201  */
  YYSYMBOL_xformConfig = 413,              /* xformConfig  */
  YYSYMBOL_414_202 = 414,                  /* @202  */
  YYSYMBOL_415_203 = 415                   /* @203  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2198

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  131
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  285
/* YYNRULES -- Number of rules.  */
#define YYNRULES  513
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  870

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   385


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   148,   148,   150,   151,   153,   153,   155,   155,   157,
     157,   158,   158,   159,   160,   160,   160,   161,   161,   161,
     162,   162,   162,   163,   163,   165,   167,   167,   168,   169,
     169,   170,   171,   172,   172,   173,   174,   174,   176,   176,
     177,   177,   178,   178,   180,   180,   181,   182,   182,   184,
     184,   186,   186,   188,   188,   190,   191,   193,   193,   193,
     194,   195,   195,   196,   196,   198,   198,   200,   200,   202,
     203,   203,   205,   205,   208,   209,   211,   212,   213,   214,
     216,   217,   219,   220,   223,   224,   224,   225,   227,   227,
     227,   228,   228,   230,   230,   231,   231,   232,   235,   236,
     235,   238,   239,   240,   241,   244,   246,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   260,   261,   262,
     263,   264,   264,   266,   267,   267,   269,   270,   270,   273,
     273,   274,   275,   276,   277,   277,   279,   279,   281,   281,
     283,   283,   285,   285,   286,   286,   288,   289,   289,   290,
     290,   292,   292,   294,   295,   296,   297,   298,   298,   299,
     299,   301,   302,   302,   304,   304,   306,   306,   308,   308,
     310,   310,   312,   312,   313,   313,   315,   315,   316,   318,
     319,   319,   320,   320,   322,   322,   324,   325,   326,   327,
     329,   329,   329,   330,   330,   330,   331,   331,   331,   333,
     334,   335,   335,   337,   338,   340,   341,   342,   343,   344,
     344,   346,   346,   348,   348,   350,   350,   351,   352,   352,
     354,   354,   355,   356,   356,   358,   359,   361,   361,   362,
     363,   363,   364,   365,   365,   365,   366,   367,   367,   368,
     368,   369,   370,   370,   371,   372,   372,   372,   373,   374,
     374,   375,   376,   377,   380,   380,   381,   382,   383,   383,
     383,   383,   385,   386,   387,   387,   388,   389,   390,   390,
     388,   392,   392,   392,   394,   394,   394,   394,   396,   397,
     398,   398,   396,   400,   401,   402,   402,   400,   404,   404,
     405,   406,   407,   409,   410,   412,   413,   416,   416,   418,
     420,   421,   421,   423,   423,   423,   425,   425,   425,   426,
     426,   429,   430,   432,   432,   433,   433,   436,   437,   438,
     438,   439,   439,   440,   440,   441,   441,   442,   444,   445,
     445,   446,   446,   447,   447,   449,   449,   451,   451,   453,
     453,   455,   455,   457,   457,   458,   458,   458,   462,   462,
     463,   463,   464,   464,   465,   465,   466,   466,   467,   467,
     468,   468,   470,   470,   472,   472,   474,   474,   475,   477,
     478,   478,   480,   480,   482,   482,   484,   484,   486,   486,
     488,   488,   490,   490,   491,   491,   493,   493,   496,   496,
     497,   498,   498,   499,   501,   501,   501,   501,   504,   504,
     504,   507,   507,   507,   509,   509,   509,   509,   511,   511,
     512,   513,   512,   515,   515,   516,   516,   516,   518,   518,
     520,   520,   521,   521,   522,   522,   523,   523,   524,   524,
     524,   526,   527,   527,   529,   531,   532,   532,   532,   534,
     534,   535,   537,   538,   540,   541,   542,   542,   543,   543,
     545,   545,   547,   548,   549,   550,   551,   554,   554,   555,
     555,   556,   556,   557,   557,   558,   558,   559,   562,   562,
     563,   564,   565,   566,   567,   569,   569,   570,   570,   571,
     572,   573,   572,   575,   577,   577,   580,   580,   582,   583,
     583,   585,   585,   588,   588,   589,   590,   590,   592,   592,
     595,   596,   597,   599,   599,   601,   604,   604,   606,   606,
     610,   610,   612,   612
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ENDLIST", "ERROR",
  "SYNERROR", "PARAMETER", "DEFINE", "EVAL", "LBEGIN", "RBEGIN", "PRINT",
  "INPUT_ENDFILE", "INPUT_ENDL", "INPUT_CONT", "COND", "ANNOT", "TO",
  "FROM", "TYPE", "POETTYPE", "SYNTAX", "MESSAGE", "LTAG", "RTAG",
  "ENDTAG", "PARS", "XFORM", "OUTPUT", "PARSE", "LOOKAHEAD", "MATCH",
  "CODE", "GLOBAL", "SOURCE", "ENDCODE", "ENDXFORM", "INPUT", "ENDINPUT",
  "SEMICOLON", "IN", "SUCH_THAT", "FOR", "FOREACH", "FOREACH_R", "DO",
  "ENDDO", "BREAK", "CONTINUE", "RETURN", "DEBUG", "IF", "ELSE", "CASE",
  "SWITCH", "DEFAULT", "DOT3", "DOT4", "ASSIGN", "PLUS_ASSIGN",
  "MINUS_ASSIGN", "MULT_ASSIGN", "DIVIDE_ASSIGN", "MOD_ASSIGN", "COMMA",
  "QUESTION", "OR", "TOR", "AND", "NOT", "LT", "LE", "EQ", "GT", "GE",
  "NE", "ARROW", "DARROW", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MOD",
  "STR_CONCAT", "DCOLON", "UMINUS", "TILT", "DELAY", "APPLY", "CLEAR",
  "SAVE", "RESTORE", "REVERSE", "PERMUTE", "REPLACE", "ASSERT", "RANGE",
  "DUPLICATE", "REBUILD", "VAR", "MAP", "TUPLE", "LIST", "LIST1", "INT",
  "STRING", "FLOAT", "NAME", "EXP", "TRACE", "ERASE", "COPY", "SPLIT",
  "LEN", "INSERT", "CAR", "CDR", "COLON", "ID", "ICONST", "FCONST", "ANY",
  "DOT", "DOT2", "POND", "LB", "RB", "LBR", "RBR", "LP", "RP", "$accept",
  "poet", "sections", "section", "@1", "@2", "@3", "@4", "@5", "@6", "@7",
  "@8", "@9", "@10", "@11", "inputAttrs", "@12", "inputAttr", "@13", "@14",
  "@15", "@16", "@17", "@18", "outputAttrs", "@19", "outputAttr", "@20",
  "@21", "@22", "@23", "inputRHS", "codeAttrs", "@24", "codeAttr", "@25",
  "@26", "@27", "@28", "@29", "@30", "matchSpec", "varRef", "xformRef",
  "codeRef", "codePars", "@31", "paramAttrs", "@32", "paramAttr", "@33",
  "@34", "@35", "map", "@36", "@37", "mapEntries", "singletype",
  "typeSpec1", "@38", "@39", "typeSpec", "@40", "typeMulti", "@41", "@42",
  "@43", "@44", "@45", "@46", "@47", "typeList", "@48", "typeTuple", "@49",
  "@50", "patternSpec", "@51", "@52", "@53", "@54", "@55", "@56", "@57",
  "@58", "@59", "patternMulti", "@60", "patternList", "@61",
  "patternTuple", "@62", "@63", "constant", "parseType1", "@64", "@65",
  "@66", "@67", "@68", "@69", "parseType", "@70", "parseElem", "@71",
  "@72", "@73", "parseElemMulti", "@74", "parseElemTuple", "@75", "@76",
  "parseElemList", "@77", "constantOrVar", "codeRHS", "@78", "xformRHS",
  "@79", "xformAttrs", "@80", "xformAttr", "@81", "@82", "xformPars",
  "@83", "outputPars", "@84", "outputPar", "@85", "traceVars", "code",
  "@86", "codeIf", "@87", "@88", "@89", "codeIfHelp", "@90", "code1",
  "@91", "@92", "@93", "@94", "@95", "@96", "@97", "@98", "@99", "@100",
  "@101", "@102", "@103", "@104", "@105", "@106", "@107", "@108",
  "foreach_body", "e_code4", "patternAssign", "@109", "suchThat", "@110",
  "switchHelp", "@111", "@112", "@113", "@114", "@115", "code23", "code2",
  "@116", "@117", "code3", "@118", "@119", "@120", "@121", "code4", "@122",
  "@123", "@124", "@125", "@126", "@127", "@128", "@129", "@130", "@131",
  "code5", "@132", "@133", "@134", "@135", "@136", "@137", "@138", "@139",
  "@140", "@141", "code6", "@142", "@143", "@144", "@145", "@146", "@147",
  "@148", "@149", "code7", "@150", "code7Help", "@151", "code7Help2",
  "@152", "code8", "@153", "@154", "@155", "@156", "@157", "@158", "@159",
  "@160", "@161", "@162", "@163", "@164", "@165", "@166", "@167", "@168",
  "@169", "@170", "@171", "@172", "@173", "@174", "@175", "@176",
  "paramRHS", "@177", "eraseRHS", "@178", "debugConfig", "inputBase",
  "@179", "@180", "@181", "code9", "@182", "@183", "@184", "@185", "@186",
  "codeUnit", "@187", "varInvoke", "@188", "@189", "varInvoke1", "@190",
  "@191", "pond", "@192", "varInvokeType", "@193", "varInvokeType1",
  "@194", "@195", "varInvokePattern", "@196", "varInvokePattern1", "@197",
  "@198", "configOrSubRef", "selectRef", "@199", "configRef", "@200",
  "@201", "xformConfig", "@202", "@203", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-658)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-257)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -658,    36,    32,  -658,    39,  -658,    10,   -17,    -9,  -658,
    -658,    58,  -658,    66,  -658,    68,    63,   103,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  1560,  1560,
    -658,   213,  -658,   357,   127,   132,  -658,  -658,  1754,  -658,
    2020,  -658,  -658,  -658,    90,   111,   119,  -658,  -658,   116,
     124,   131,  -658,  -658,  -658,   139,   149,   153,  -658,  -658,
     163,   164,  -658,  -658,  -658,   168,   169,  -658,   174,   175,
    -658,   -88,  -658,   181,   183,  -658,   188,  -658,   190,  -658,
    -658,  -658,  -658,  -658,  -658,   199,   200,  -658,  -658,  -658,
     304,    52,  -658,  -658,   284,   141,  -658,   -15,  1126,  -658,
     803,  -658,   -39,   296,   339,   -10,   307,   312,   340,   342,
    -658,  -658,    33,   343,   353,   362,   368,   375,   377,   383,
    -658,  -658,   363,    68,  -658,  1754,  1754,  2069,  -658,   292,
     299,   327,  -658,  -658,  -658,  -658,  -658,   389,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,   316,  -658,   390,   328,   335,
    2069,   404,  -658,  -658,  -658,  -658,   259,  -658,   363,   363,
     346,  -658,   347,  -658,   349,  -658,  -658,    -6,  -658,     6,
     352,   341,  -658,  -658,  1922,  1922,  -658,  -658,   363,   363,
     363,  -658,  -658,   363,   363,  -658,   363,   129,   344,   363,
    -658,  -658,   363,  -658,   363,  -658,   363,   363,  -658,  1560,
    -658,  1560,  -658,  1560,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,  -658,  1971,  -658,  -658,   144,  -658,  -658,   415,   418,
     419,   159,  -658,  -658,  -658,  -658,  -658,   463,   213,   431,
     432,   433,   435,   444,   445,   449,   450,  -658,  -658,  -658,
    -658,    -7,  -658,  -658,   489,  -658,    44,   357,  -658,  -658,
       7,    15,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  1754,
     222,  -658,  -658,   235,  1560,  -658,  -658,  -658,  2069,  -658,
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,     6,  1922,
     452,  -658,   471,  -658,  1922,  -658,   385,  -658,     6,  1560,
     867,  -658,   254,  1560,  1560,  -658,  -658,  -658,     6,     6,
    -658,   453,     6,  -658,  -658,   -36,   438,  -658,  2069,  -658,
       6,     6,  -658,     6,  -658,     6,  -658,  -658,   392,   391,
    -658,  1799,  1799,  1922,     6,     6,  1922,  1922,  1922,  1922,
    1922,  1922,  1922,  1922,  1922,  1922,  1922,  1922,  1922,  1015,
       6,     6,     6,     6,     6,     6,  1754,  1754,  -658,  -658,
     363,  -658,  -658,  -658,  -658,   363,   399,   406,  -658,  -658,
    -658,  -658,   -10,   363,   363,   363,   363,  -658,  -658,  -658,
     407,  -658,  -658,   400,  -658,  -658,  -658,   182,    33,   363,
     363,  -658,  -658,   363,   363,  -658,  2020,   363,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,  1754,  1754,  1754,  1754,   130,
     408,   456,  -658,  -658,  -658,  1754,   479,   484,   485,   486,
    -658,   411,  2069,   422,   791,   416,   492,  2020,   519,  -658,
     417,  -658,   252,  -658,   688,  -658,  1560,   430,   446,   436,
     454,   178,   348,   363,   359,   363,  -658,   363,   318,    -8,
      -8,   370,   382,  -658,  -658,  -658,  -658,   739,   511,  -658,
     867,   867,   867,   867,   867,   867,   254,   254,   494,   494,
     494,   494,   494,   464,   467,   524,  -658,  -658,   655,  -658,
    -658,    -8,    -8,    -8,    -8,    -8,   316,   316,  1971,  -658,
     363,  1873,  -658,  -658,   468,  -658,  2069,  1560,  -658,  -658,
    -658,  -658,  -658,   363,   469,   363,  2020,  -658,   240,   363,
     363,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,    93,
    -658,   286,  2069,   316,   324,   325,   316,  -658,  1754,  -658,
    -658,  2069,   475,  -658,  -658,   555,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  2069,
    -658,  -658,  -658,  -658,  -658,  1015,  -658,  -658,  -658,   875,
    -658,   472,  -658,   474,  -658,  -658,  -658,  -658,   480,  -658,
     528,  -658,  -658,    28,    69,  -658,  -658,  -658,  -658,  -658,
    -658,  1015,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,   -33,    -8,   477,   545,   575,   498,    78,
     499,   549,   582,  -658,   502,    83,  -658,    93,  -658,  -658,
     296,  -658,  -658,  1560,  -658,  -658,  1754,  -658,  -658,  1754,
     316,  -658,  1754,  -658,   565,    -5,  2069,  -658,  2020,   363,
    2069,  2069,  2069,  2069,  2069,  2069,  2069,   549,  -658,  2069,
       6,  1015,   655,  1015,   507,   497,   587,   867,  1015,  -658,
    1680,  -658,     6,     6,  -658,     6,   363,  2069,  -658,  -658,
    -658,  -658,  -658,  -658,     6,     6,     6,  1015,   483,   500,
     567,  1015,  1015,  1015,  1015,  1015,  1015,  1015,  1971,  -658,
     518,  -658,  -658,  -658,  -658,   468,  -658,   512,   514,   578,
    -658,  -658,   469,  -658,   612,   522,    46,    46,   316,  1754,
     316,  -658,  -658,    93,  -658,  -658,   549,   549,   549,   549,
     549,   549,  2069,   549,   610,   227,  -658,   595,    18,  1922,
    -658,   609,   510,  -658,   616,   608,    70,    -8,   387,  -658,
      24,     6,     6,   121,   122,  -658,   473,  -658,  1015,  -658,
    -658,   261,   195,    75,    75,    75,    75,  -658,  -658,     6,
    -658,   144,   544,   475,  2069,  -658,  -658,  -658,  -658,  2020,
    -658,  -658,  -658,  -658,  -658,   533,   534,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,   490,     6,  -658,  -658,   613,  -658,
      17,  -658,    28,  -658,  -658,   171,   172,  -658,  -658,  1015,
     655,  -658,  1015,    -8,  -658,   546,  -658,   575,   549,  2069,
     499,    93,  -658,  -658,     6,     6,  2069,   507,  -658,  -658,
    1560,     6,  -658,  -658,  1015,  -658,   553,  -658,  -658,     6,
    -658,  -658,   655,  1015,   655,   549,  -658,   536,   541,   549,
     634,   630,   547,  1560,   557,  1015,  -658,   197,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,   637,  1560,  -658,  1680,  1680,
    1680,  1560,  -658,  -658,  -658,  -658,  -658,  -658,  1560,  -658
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       3,     0,   444,     1,     0,     4,     0,     0,     0,     9,
      11,     0,    20,     0,    17,     0,     0,     0,    25,   445,
     455,   454,   446,   456,   452,   453,     5,     7,     0,     0,
      23,    46,    14,    28,   251,     0,   448,   450,     0,    88,
       0,   189,   321,   325,    80,    82,     0,   188,   291,     0,
     274,     0,   318,   317,   319,   442,     0,     0,   352,   384,
       0,     0,   465,   426,   424,     0,     0,   323,     0,     0,
     422,   103,   463,     0,     0,   408,     0,   461,     0,   457,
     459,    76,   186,   187,   472,   288,   468,   473,   474,   471,
       0,   254,   262,   257,   311,   312,   327,   328,   368,   369,
     386,   435,   475,   467,     0,   233,     0,     0,     0,     0,
      21,    44,    57,     0,     0,     0,     0,     0,     0,     0,
      18,    26,     0,     0,    13,     0,     0,     0,   114,   115,
       0,     0,   109,   111,   110,   112,   113,    76,   108,   213,
     486,   116,   205,   107,   208,   447,   206,    89,     0,     0,
       0,    76,   124,   117,   200,   199,     0,   120,     0,     0,
       0,    78,     0,    79,     0,   266,   278,     0,   283,     0,
       0,     0,   258,   271,     0,     0,   413,   420,     0,     0,
       0,   401,   394,     0,     0,   404,     0,     0,    98,     0,
     398,   410,     0,   428,     0,   415,     0,     0,   290,     0,
     470,     0,    10,     0,   313,   292,   315,   345,   350,   348,
     354,   356,   358,   360,   362,   364,   370,   372,   374,   378,
     380,   376,   382,   366,   329,   333,   335,   337,   339,   341,
     331,   343,   390,   431,   432,   479,   477,    12,     0,     0,
       0,     0,   234,    53,    51,    47,    49,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    58,    42,
      40,     0,    38,    33,    36,    29,     0,    28,   252,   253,
       0,     0,   115,   126,   207,   190,   193,   196,   209,     0,
     488,   211,     6,     0,     0,   118,   123,   121,     0,     8,
     204,   203,   201,   322,   326,    81,    83,    77,   296,     0,
      76,   493,     0,   299,     0,   320,     0,   418,     0,     0,
     353,   386,   385,     0,     0,   466,   427,   425,     0,     0,
     324,     0,     0,   423,   102,     0,     0,   101,     0,   464,
       0,     0,   409,     0,   462,     0,   458,   460,     0,     0,
     255,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   387,   388,
       0,   484,   480,   476,   483,     0,     0,     0,   239,   230,
     232,    24,   233,     0,     0,     0,     0,    22,    45,    63,
       0,    72,    67,     0,    70,    65,    61,     0,    57,     0,
       0,    31,    32,     0,     0,    35,     0,     0,   444,    56,
      19,    27,   449,   451,   127,     0,     0,     0,     0,   215,
       0,   217,   491,   489,   487,     0,     0,     0,     0,     0,
      90,     0,     0,   126,   129,     0,   131,     0,     0,   295,
       0,   297,   495,   275,     0,   443,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,     0,     0,   399,
     411,     0,     0,   289,   469,   314,   316,     0,   351,   349,
     355,   357,   359,   361,   363,   365,   371,   373,   375,   379,
     381,   377,   383,     0,     0,    76,   157,   153,   367,   156,
     330,   334,   336,   338,   340,   342,   332,   344,   393,   433,
       0,     0,   475,   478,     0,   237,     0,     0,   235,    54,
      52,    48,    50,     0,     0,     0,     0,    69,     0,     0,
       0,   227,   229,    16,    59,    43,    41,    39,    34,    37,
      30,     0,     0,   191,     0,     0,   210,   218,   222,   214,
     220,     0,     0,   212,    91,     0,    95,    93,   119,   122,
     134,   133,   132,   149,   136,   138,   140,   142,   144,   146,
     125,   151,   202,   267,   279,     0,   498,   496,   494,     0,
     284,     0,   259,     0,   414,   421,   402,   395,     0,   405,
       0,   105,    99,     0,     0,   429,   416,   346,   154,   155,
     174,     0,   161,   159,   164,   166,   168,   170,   172,   162,
     389,   391,   485,    76,   500,     0,   502,   501,   241,     0,
       0,   240,     0,    64,    84,     0,    73,    68,    75,    71,
      74,    66,    62,     0,    55,   128,   222,   194,   197,     0,
     223,   216,     0,   492,     0,     0,     0,    97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,   130,     0,
     296,     0,   298,     0,     0,     0,   300,   293,     0,   419,
       0,   272,     0,     0,   434,     0,     0,     0,   437,   436,
     400,   439,   441,   412,     0,     0,     0,     0,   176,     0,
     178,     0,     0,     0,     0,     0,     0,     0,   393,   506,
       0,   481,   503,   508,   242,     0,   236,   248,     0,   247,
     231,    85,     0,    60,     0,     0,     0,     0,   219,   222,
     221,   490,    92,    96,    94,   135,   150,   137,   139,   141,
     143,   145,   146,   152,     0,     0,   499,     0,     0,     0,
     301,     0,     0,   260,     0,     0,     0,   396,     0,   106,
       0,     0,     0,     0,     0,   347,   175,   182,   179,   158,
     184,   160,   165,   167,   169,   171,   173,   163,   392,     0,
     505,   479,     0,     0,     0,   244,   249,   238,   245,     0,
      87,   228,   192,   226,   225,     0,     0,   224,   148,   268,
     280,   510,   512,   497,     0,     0,   276,   285,   263,   306,
       0,   403,     0,   406,   100,     0,     0,   430,   417,     0,
     180,   177,     0,   507,   482,     0,   504,   509,   243,     0,
       0,    86,   195,   198,   296,     0,     0,     0,   294,   302,
       0,     0,   264,   261,     0,   303,     0,   273,   397,     0,
     438,   440,   183,   179,   185,   250,   246,     0,     0,   511,
     513,     0,     0,     0,     0,     0,   309,     0,   181,   269,
     281,   277,   286,   265,   307,     0,     0,   407,     0,     0,
       0,     0,   304,   310,   270,   282,   287,   308,     0,   305
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,   424,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,   434,  -658,  -658,  -658,  -658,  -658,
    -658,  -658,   280,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,  -658,    43,  -658,  -658,    -4,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,   724,  -658,  -658,  -658,   798,   -29,  -658,
    -658,  -119,  -658,    59,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,   -23,  -658,  -658,  -658,  -658,  -330,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -133,  -658,
    -658,  -658,  -658,   379,   -38,  -658,  -658,  -658,  -658,  -658,
    -658,  -402,  -658,    27,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,  -658,  -596,  -658,    -2,  -658,  -658,  -658,  -658,   320,
    -658,  -658,  -658,  -658,     8,  -658,  -104,  -658,  -658,  -658,
     585,   -22,  -658,  -134,  -658,  -658,  -658,  -658,  -658,  -657,
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -640,
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -327,  -658,  -658,  -658,  -658,  -164,
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
     596,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,  -132,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,    25,  -658,   -28,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,   -80,  -658,  -658,  -658,  -658,   306,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,  -658,  1117,  -658,  -363,  -658,
    -658,   -45,  -658,  -658,  -658,  -658,    14,  -658,  -658,  -658,
    -658,   574,  -658,  -658,  -658,  -658,  -658,   -30,  -658,  -536,
    -658,  -658,   -83,  -658,  -658
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,     5,    39,    40,    28,    29,   112,   397,
      33,   266,    31,   247,   105,   120,   267,   121,   407,   404,
     406,   403,   400,   399,   110,   248,   111,   385,   386,   384,
     383,   410,   257,   398,   258,   520,   513,   519,   516,   518,
     515,   619,    87,   161,   163,   615,   769,   147,   283,   430,
     636,   639,   638,    88,   328,   667,   325,   153,   273,   432,
     288,   434,   532,   435,   559,   640,   642,   643,   644,   645,
     646,   648,   722,   436,   641,   649,   800,   591,   681,   687,
     682,   683,   684,   685,   686,   677,   679,   748,   801,   833,
     680,   799,   802,    89,   144,   415,   626,   416,   706,   417,
     707,   156,   437,   630,   418,   425,   279,   420,   538,   421,
     629,   632,   631,   709,   775,   523,   623,   381,   507,   241,
     382,   242,   610,   506,   609,   764,   698,   810,   699,   809,
      35,    90,   203,    91,   308,   660,   788,   823,   843,    92,
     298,   650,   814,   858,   309,   735,   167,   569,   820,   299,
     651,   815,   859,   304,   658,   821,   860,   199,   656,   438,
     302,   565,   731,   785,   790,   845,   868,   824,   861,   856,
      93,    94,   341,   342,    95,   169,   158,   183,   159,    96,
     360,   366,   361,   362,   363,   364,   365,   367,   343,   676,
      97,   345,   344,   174,   346,   347,   348,   349,   350,   351,
     359,    98,   352,   353,   354,   357,   355,   356,   358,   175,
      99,   232,   368,   498,   600,   688,   311,   319,   663,   792,
     330,   583,   318,   662,   322,   665,   829,   192,   331,   584,
     313,   335,   675,   446,   314,   186,   180,   179,   333,   674,
     370,   670,   741,   673,   742,   171,     6,    38,   125,   126,
     101,   196,   197,   194,   189,   178,   102,   201,   103,   235,
     375,   373,   501,   761,   374,   500,   157,   280,   424,   542,
     541,   489,   442,   568,   654,   653,   605,   606,   762,   607,
     759,   763,   728,   816,   817
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     100,   100,   155,   733,   529,   305,   635,   104,   274,    41,
     724,   154,   503,   401,   465,   466,   238,   233,   239,    16,
      17,    44,    18,    19,    20,   689,    45,    46,   455,   488,
     705,   286,    -2,    44,   693,   562,     3,   187,    45,    46,
      47,   188,   310,   312,    21,     7,     8,     9,   249,    41,
     207,   208,   146,   209,    10,     4,    55,   782,   208,   250,
     209,   251,   252,   253,   254,   145,    11,    12,   408,   409,
     825,    13,   826,    44,   281,    58,    14,  -256,    45,    46,
      47,   140,   281,   140,   234,    59,    22,  -256,  -256,   690,
     456,   414,   668,    60,    61,    62,    63,    64,  -256,    65,
      66,    26,    68,    69,    70,  -256,    71,  -256,   240,    27,
      72,   402,   300,   777,   617,    73,    74,    75,    76,    77,
      78,    79,    80,   711,    81,    82,    83,    84,    23,    24,
      25,   255,    41,   671,   439,    86,   208,   412,   209,   146,
     146,   100,   695,   827,   447,   413,   783,   702,    15,   290,
     291,   256,   270,   271,   794,   620,    44,   124,   669,   598,
     292,    45,    46,    47,    81,    82,    83,   440,   140,   140,
     140,   100,   444,   100,   837,   100,    30,   338,  -256,   339,
     205,   340,  -256,   379,    32,   122,    34,   208,   208,   209,
     209,   123,    36,   140,   537,   380,   490,   281,   599,   672,
     791,   864,   865,   866,   369,   206,   521,   522,   696,   458,
     301,   467,   160,   703,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   807,   106,    71,
     107,   108,    37,   162,   109,   652,   713,   208,   208,   209,
     209,   164,   576,    41,   208,   165,   209,    81,    82,    83,
      84,   797,   798,   166,   426,   324,   100,   427,    86,   433,
     168,   678,   431,   208,   428,   209,   170,    44,   371,   618,
     100,   372,    45,    46,    47,   595,   596,   597,   172,   598,
     100,   100,   173,   592,   289,   100,   100,   448,   176,   177,
     429,   449,   450,   146,   593,    16,    17,   181,   182,    19,
      20,   830,   831,   184,   185,   594,   419,   595,   596,   597,
     190,   598,   191,   100,   100,   290,   291,   193,   599,   195,
      21,   725,   140,   726,   624,   198,   292,   857,   732,   202,
     200,   140,   100,   734,   218,   219,   220,   221,   222,   594,
      71,   595,   596,   597,   780,   598,   422,   746,   204,   423,
     599,   751,   752,   753,   754,   755,   756,   757,    81,    82,
      83,    84,    22,   236,   237,   243,    41,   811,   155,    86,
     244,   140,   113,   114,   115,   116,   566,   154,   117,   567,
     146,   146,   582,   281,   599,   414,   118,   611,   627,   628,
      44,   281,   281,   496,   497,    45,    46,    47,   245,   155,
     246,   259,   301,   549,    23,    24,    25,   119,   154,   140,
     140,   260,   577,   625,   208,   282,   209,   143,   100,   143,
     261,   275,   633,   579,   571,   208,   262,   209,   276,   146,
     146,   146,   146,   263,   585,   264,   208,   657,   209,   146,
     647,   265,   533,   534,   535,   536,   586,   278,   208,   140,
     209,   793,   543,   208,   285,   209,   277,   284,   140,   140,
     140,   140,   287,    71,   295,   296,   307,   297,   140,   832,
     601,   306,   834,   376,   327,   140,   377,   378,   155,   100,
     140,    81,    82,    83,    84,   612,   439,   154,   387,   389,
     390,   391,    86,   392,   844,   216,   217,   218,   219,   220,
     221,   222,   393,   394,   143,   143,   143,   395,   396,   405,
     441,   443,   745,   445,   457,   855,   734,   453,   463,   517,
     540,   464,   716,   717,   718,   719,   720,   721,   504,   143,
     723,   734,   734,   734,   564,   505,   514,   544,   539,   592,
     593,   548,   545,   546,   547,   550,   560,   747,   740,   140,
     593,   594,   146,   595,   596,   597,   561,   598,   563,   140,
     572,   594,   574,   595,   596,   597,   592,   598,   216,   217,
     218,   219,   220,   221,   222,   140,   573,   593,   222,   209,
     575,   140,   590,   588,   140,   589,   608,   614,   594,   637,
     595,   596,   597,   634,   598,   100,   599,   784,   659,   661,
     155,   704,   140,   647,   666,   691,   599,   433,   301,   154,
     664,   715,   692,   592,   693,   694,   414,   697,   700,   701,
     818,   819,   100,   689,   593,   727,   729,   787,   730,   766,
     749,   750,   100,   599,   301,   594,   760,   595,   596,   597,
     146,   598,   768,   146,   767,   808,   146,   771,   100,   779,
     439,   838,   772,   781,   786,   205,   708,   842,   143,   710,
     601,   789,   805,   812,   813,   822,   849,   143,   690,   140,
     846,   850,   140,   782,   854,   140,   851,   852,   524,   140,
     599,   140,   388,   140,   140,   140,   140,   140,   140,   140,
     835,   411,   140,   592,   301,   712,   301,   839,   770,   778,
     848,   301,   508,   765,   593,   776,   836,   143,   269,   853,
     140,   592,   828,   758,   531,   594,   804,   595,   596,   597,
     301,   598,   593,   146,   301,   301,   301,   301,   301,   301,
     301,   155,   806,   594,   840,   595,   596,   597,   143,   598,
     154,   303,     0,     0,     0,   143,   143,     0,     0,   773,
     773,     0,   140,     0,   862,     0,     0,   100,     0,     0,
     599,     0,   141,     0,   141,   140,   216,   217,   218,   219,
     220,   221,   222,     0,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,     0,   143,   100,   100,     0,     0,
       0,   301,   100,   100,   143,   143,   143,   143,   841,     0,
       0,     0,     0,     0,   143,   570,     0,   140,     0,     0,
       0,   143,   140,     0,     0,   100,   143,   216,   217,   218,
     219,   220,   221,   222,     0,     0,     0,     0,   100,     0,
     100,   100,   100,   100,   863,     0,   142,     0,     0,   867,
     100,     0,   301,     0,     0,   301,   869,   551,   552,   141,
     141,   141,   140,     0,     0,   553,   587,     0,   414,   140,
       0,   224,   225,   226,   227,   228,   229,   301,     0,   554,
       0,   555,   556,   557,   141,   558,   301,     0,    41,   230,
     231,     0,     0,     0,     0,   143,     0,     0,   301,     0,
       0,     0,     0,     0,     0,   143,     0,     0,     0,     0,
       0,     0,    44,     0,     0,     0,     0,    45,    46,    47,
       0,   143,     0,     0,   451,   452,     0,   143,   454,     0,
     143,     0,     0,   142,   142,    55,   459,   460,     0,   461,
       0,   462,     0,     0,     0,     0,     0,     0,   143,     0,
     468,   469,     0,     0,   143,   216,   217,   218,   219,   220,
     221,   222,     0,     0,    59,     0,     0,   491,   492,   493,
     494,   495,    60,    61,    62,    63,    64,   655,    65,    66,
     143,    68,    69,    70,     0,    71,     0,     0,     0,    72,
       0,     0,     0,     0,    73,    74,    75,    76,    77,    78,
      79,    80,     0,    81,    82,    83,    84,     0,     0,     0,
       0,     0,     0,   141,    86,   143,     0,     0,   143,     0,
       0,   143,   141,     0,     0,   143,     0,   143,    41,   143,
     143,   143,   143,   143,   143,   143,     0,     0,   143,     0,
     143,     0,   143,     0,     0,     0,     0,   143,     0,     0,
       0,     0,    44,     0,     0,     0,   143,    45,    46,    47,
       0,     0,   141,     0,     0,     0,   143,     0,     0,     0,
     143,   143,   143,   143,   143,   143,   143,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   142,     0,     0,
       0,     0,     0,   141,     0,   774,   774,     0,   143,     0,
     141,   141,     0,     0,   483,     0,     0,   604,     0,     0,
       0,   143,     0,     0,   484,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,    71,   272,     0,     0,   132,
     133,   134,   135,   136,     0,     0,     0,   143,     0,     0,
     141,     0,     0,   485,    82,    83,   138,     0,     0,   141,
     141,   141,   141,   143,   486,     0,     0,     0,   143,   141,
       0,     0,     0,     0,     0,     0,   141,   487,     0,     0,
       0,   141,     0,     0,   142,   142,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   143,     0,
       0,   143,     0,     0,     0,     0,     0,     0,   143,     0,
       0,     0,     0,     0,     0,   143,   210,   211,   212,   213,
     214,   215,     0,   143,   216,   217,   218,   219,   220,   221,
     222,     0,   143,   142,   142,   142,   142,     0,     0,     0,
       0,     0,     0,   142,   143,     0,     0,     0,     0,     0,
     141,     0,     0,     0,     0,     0,     0,     0,     0,   268,
     141,     0,     0,   223,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,     0,   736,   737,
       0,   738,   141,     0,     0,   141,     0,     0,     0,     0,
     743,   744,     0,     0,     0,   293,   294,     0,     0,     0,
       0,     0,     0,   141,     0,     0,     0,     0,     0,   141,
       0,     0,     0,     0,     0,   315,   316,   317,     0,     0,
     320,   321,     0,   323,   326,     0,   329,     0,     0,   332,
       0,   334,     0,   336,   337,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   795,   796,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   141,     0,   803,   141,     0,     0,     0,
     141,     0,   141,   487,   141,   141,   141,   141,   141,   141,
     141,     0,     0,   141,     0,   141,     0,   141,     0,     0,
       0,     0,   141,     0,     0,     0,     0,     0,     0,   487,
       0,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,     0,     0,     0,   141,   141,   141,   141,   141,
     141,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   847,     0,   142,     0,     0,
     142,     0,     0,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,     0,     0,   487,
       0,   487,     0,     0,     0,     0,   487,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,     0,     0,   487,     0,     0,     0,   487,
     487,   487,   487,   487,   487,   487,     0,   499,   141,     0,
       0,     0,   502,   141,     0,     0,     0,     0,     0,     0,
     509,   510,   511,   512,     0,     0,     0,   142,     0,     0,
       0,     0,     0,     0,     0,     0,   525,   526,     0,     0,
     527,   528,     0,   141,   530,     0,   141,     0,     0,     0,
       0,     0,     0,   141,     0,     0,     0,     0,     0,     0,
     141,     0,     0,     0,     0,     0,   487,     0,   141,     0,
       0,     0,     0,     0,     0,     0,     0,   141,     0,     0,
       0,     0,     0,    41,    42,     0,     0,     0,     0,   141,
     578,    43,   580,     0,   581,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,     0,     0,
       0,     0,    45,    46,    47,     0,     0,   487,     0,    48,
     487,     0,    49,    50,    51,     0,     0,    52,    53,    54,
      55,    56,     0,     0,    57,     0,     0,   602,     0,     0,
       0,     0,   487,     0,     0,     0,     0,     0,     0,    58,
     613,   487,   616,     0,     0,   502,   621,   622,     0,    59,
       0,     0,     0,   487,     0,     0,     0,    60,    61,    62,
      63,    64,     0,    65,    66,    67,    68,    69,    70,     0,
      71,     0,     0,     0,    72,     0,     0,     0,     0,    73,
      74,    75,    76,    77,    78,    79,    80,     0,    81,    82,
      83,    84,     0,    41,    42,    85,     0,     0,     0,    86,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,     0,     0,
       0,     0,    45,    46,    47,     0,     0,     0,     0,    48,
       0,     0,    49,    50,    51,     0,     0,    52,    53,    54,
      55,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
       0,     0,     0,     0,     0,     0,   714,    41,     0,    59,
       0,     0,     0,     0,     0,     0,     0,    60,    61,    62,
      63,    64,     0,    65,    66,    67,    68,    69,    70,     0,
      71,    44,     0,   739,    72,     0,    45,    46,    47,    73,
      74,    75,    76,    77,    78,    79,    80,     0,    81,    82,
      83,    84,    41,    42,     0,    85,     0,     0,     0,    86,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,     0,     0,     0,
       0,    45,    46,    47,     0,     0,     0,     0,     0,     0,
     127,     0,     0,     0,     0,     0,    52,    53,    54,    55,
       0,     0,     0,   128,    71,   129,   130,   131,   132,   133,
     134,   135,   136,     0,     0,     0,     0,     0,    58,     0,
       0,     0,   137,    82,    83,   138,    41,     0,    59,     0,
       0,     0,     0,   139,     0,     0,    60,    61,    62,    63,
      64,     0,    65,    66,    67,    68,    69,    70,     0,    71,
      44,     0,     0,    72,     0,    45,    46,    47,    73,    74,
      75,    76,    77,    78,    79,    80,     0,    81,    82,    83,
      84,     0,     0,    55,     0,    41,     0,     0,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,    44,
       0,     0,    59,     0,    45,    46,    47,     0,     0,     0,
      60,    61,    62,    63,    64,     0,    65,    66,     0,    68,
      69,    70,    55,    71,    41,     0,     0,    72,     0,     0,
       0,     0,    73,    74,    75,    76,    77,    78,    79,    80,
       0,   603,    82,    83,    84,     0,     0,     0,    44,     0,
       0,    59,    86,    45,    46,    47,     0,     0,     0,    60,
      61,    62,    63,    64,     0,    65,    66,     0,    68,    69,
      70,    55,    71,    41,     0,     0,    72,     0,   148,     0,
       0,    73,    74,    75,    76,    77,    78,    79,    80,     0,
      81,    82,    83,    84,     0,     0,     0,    44,     0,     0,
       0,    86,    45,    46,    47,     0,     0,     0,    60,    61,
      62,    63,    64,     0,    65,    66,     0,    68,    69,    70,
       0,    71,    41,     0,     0,    72,     0,   148,     0,     0,
      73,    74,    75,    76,    77,    78,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,    44,     0,     0,   149,
      86,    45,    46,    47,     0,     0,   150,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   128,
      71,   129,   130,   131,   132,   133,   134,   135,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   151,    82,
      83,   138,     0,     0,     0,     0,     0,     0,   149,   152,
       0,     0,     0,     0,     0,   150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,    71,
     272,     0,     0,   132,   133,   134,   135,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   151,    82,    83,
     138,     0,     0,     0,     0,     0,     0,     0,   152
};

static const yytype_int16 yycheck[] =
{
      28,    29,    40,   660,   406,   169,   542,    29,   127,     3,
     650,    40,   375,    20,   341,   342,    26,    56,    28,     9,
      10,    27,    12,    13,    14,    58,    32,    33,    64,   359,
     626,   150,     0,    27,    39,   437,     0,   125,    32,    33,
      34,   129,   174,   175,    34,     6,     7,     8,    15,     3,
      65,    66,    38,    68,    15,    23,    50,    39,    66,    26,
      68,    28,    29,    30,    31,    38,    27,    28,    24,    25,
      53,    32,    55,    27,    67,    69,    37,    25,    32,    33,
      34,    38,    67,    40,   123,    79,    76,    35,    36,   122,
     126,    67,    64,    87,    88,    89,    90,    91,    46,    93,
      94,   118,    96,    97,    98,    53,   100,    55,   118,   118,
     104,   118,   118,   709,   516,   109,   110,   111,   112,   113,
     114,   115,   116,   128,   118,   119,   120,   121,   118,   119,
     120,    98,     3,    64,   298,   129,    66,   130,    68,   125,
     126,   169,    64,   126,   308,   130,   128,    64,   109,    56,
      57,   118,   125,   126,   130,   518,    27,    25,   130,    84,
      67,    32,    33,    34,   118,   119,   120,   299,   125,   126,
     127,   199,   304,   201,   814,   203,   118,   199,   126,   201,
      39,   203,   130,    24,   118,    58,   118,    66,    66,    68,
      68,    64,   129,   150,    64,    36,   360,    67,   123,   130,
     130,   858,   859,   860,   232,    64,    24,    25,   130,   328,
     167,   343,   122,   130,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   763,    15,   100,
      17,    18,   129,   122,    21,   565,   638,    66,    66,    68,
      68,   122,    64,     3,    66,   129,    68,   118,   119,   120,
     121,   130,   130,   129,    19,   126,   284,    22,   129,   288,
     129,   591,   284,    66,    29,    68,   127,    27,   124,    29,
     298,   127,    32,    33,    34,    80,    81,    82,   129,    84,
     308,   309,   129,    56,    25,   313,   314,   309,   125,   125,
      55,   313,   314,   279,    67,     9,    10,   129,   129,    13,
      14,   130,   130,   129,   129,    78,   279,    80,    81,    82,
     129,    84,   129,   341,   342,    56,    57,   129,   123,   129,
      34,   651,   279,   653,    38,   126,    67,   130,   658,    25,
     130,   288,   360,   660,    80,    81,    82,    83,    84,    78,
     100,    80,    81,    82,   117,    84,   124,   677,    64,   127,
     123,   681,   682,   683,   684,   685,   686,   687,   118,   119,
     120,   121,    76,    67,    25,    58,     3,   769,   406,   129,
      58,   328,    15,    16,    17,    18,   124,   406,    21,   127,
     366,   367,    64,    67,   123,    67,    29,   506,    64,    64,
      27,    67,    67,   366,   367,    32,    33,    34,    58,   437,
      58,    58,   359,   432,   118,   119,   120,    50,   437,   366,
     367,    58,    64,   532,    66,    25,    68,    38,   446,    40,
      58,   129,   541,    64,   446,    66,    58,    68,   129,   415,
     416,   417,   418,    58,    64,    58,    66,   569,    68,   425,
     559,    58,   415,   416,   417,   418,    64,    58,    66,   406,
      68,    64,   425,    66,   119,    68,   129,   129,   415,   416,
     417,   418,    58,   100,   118,   118,   125,   118,   425,   799,
     498,   119,   802,    58,   130,   432,    58,    58,   516,   507,
     437,   118,   119,   120,   121,   507,   650,   516,    25,    58,
      58,    58,   129,    58,   824,    78,    79,    80,    81,    82,
      83,    84,    58,    58,   125,   126,   127,    58,    58,    20,
      58,    40,   676,   128,    76,   845,   843,    64,   126,   119,
      64,   130,   641,   642,   643,   644,   645,   646,   129,   150,
     649,   858,   859,   860,   117,   129,   129,    58,   130,    56,
      67,   130,    58,    58,    58,   123,   130,    64,   667,   506,
      67,    78,   538,    80,    81,    82,    64,    84,    39,   516,
     130,    78,   126,    80,    81,    82,    56,    84,    78,    79,
      80,    81,    82,    83,    84,   532,   130,    67,    84,    68,
     126,   538,    58,   119,   541,   118,   118,   118,    78,    34,
      80,    81,    82,   118,    84,   623,   123,   729,   126,   125,
     638,   623,   559,   722,    76,   128,   123,   636,   565,   638,
     130,   640,    67,    56,    39,   117,    67,   118,    36,   117,
     130,   785,   650,    58,    67,   118,   129,   117,    41,   117,
     130,    64,   660,   123,   591,    78,   118,    80,    81,    82,
     626,    84,    64,   629,   130,   764,   632,    35,   676,    39,
     814,   815,   130,    58,    45,    39,   629,   821,   279,   632,
     688,    53,   118,   130,   130,    52,   130,   288,   122,   626,
     117,   130,   629,    39,   117,   632,    46,   130,   398,   636,
     123,   638,   248,   640,   641,   642,   643,   644,   645,   646,
     809,   267,   649,    56,   651,   636,   653,   816,   702,   722,
     833,   658,   382,   695,    67,   707,   810,   328,   123,   843,
     667,    56,   792,   688,   408,    78,   761,    80,    81,    82,
     677,    84,    67,   709,   681,   682,   683,   684,   685,   686,
     687,   769,   762,    78,   817,    80,    81,    82,   359,    84,
     769,   167,    -1,    -1,    -1,   366,   367,    -1,    -1,   706,
     707,    -1,   709,    -1,   117,    -1,    -1,   785,    -1,    -1,
     123,    -1,    38,    -1,    40,   722,    78,    79,    80,    81,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,   123,    -1,
      -1,    -1,    -1,    -1,    -1,   406,   814,   815,    -1,    -1,
      -1,   748,   820,   821,   415,   416,   417,   418,   820,    -1,
      -1,    -1,    -1,    -1,   425,   117,    -1,   764,    -1,    -1,
      -1,   432,   769,    -1,    -1,   843,   437,    78,    79,    80,
      81,    82,    83,    84,    -1,    -1,    -1,    -1,   856,    -1,
     858,   859,   860,   861,   856,    -1,    38,    -1,    -1,   861,
     868,    -1,   799,    -1,    -1,   802,   868,    56,    57,   125,
     126,   127,   809,    -1,    -1,    64,   117,    -1,    67,   816,
      -1,    58,    59,    60,    61,    62,    63,   824,    -1,    78,
      -1,    80,    81,    82,   150,    84,   833,    -1,     3,    76,
      77,    -1,    -1,    -1,    -1,   506,    -1,    -1,   845,    -1,
      -1,    -1,    -1,    -1,    -1,   516,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    33,    34,
      -1,   532,    -1,    -1,   318,   319,    -1,   538,   322,    -1,
     541,    -1,    -1,   125,   126,    50,   330,   331,    -1,   333,
      -1,   335,    -1,    -1,    -1,    -1,    -1,    -1,   559,    -1,
     344,   345,    -1,    -1,   565,    78,    79,    80,    81,    82,
      83,    84,    -1,    -1,    79,    -1,    -1,   361,   362,   363,
     364,   365,    87,    88,    89,    90,    91,    92,    93,    94,
     591,    96,    97,    98,    -1,   100,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,    -1,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,    -1,    -1,   279,   129,   626,    -1,    -1,   629,    -1,
      -1,   632,   288,    -1,    -1,   636,    -1,   638,     3,   640,
     641,   642,   643,   644,   645,   646,    -1,    -1,   649,    -1,
     651,    -1,   653,    -1,    -1,    -1,    -1,   658,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,   667,    32,    33,    34,
      -1,    -1,   328,    -1,    -1,    -1,   677,    -1,    -1,    -1,
     681,   682,   683,   684,   685,   686,   687,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   279,    -1,    -1,
      -1,    -1,    -1,   359,    -1,   706,   707,    -1,   709,    -1,
     366,   367,    -1,    -1,    79,    -1,    -1,   501,    -1,    -1,
      -1,   722,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,    -1,    -1,   104,
     105,   106,   107,   108,    -1,    -1,    -1,   748,    -1,    -1,
     406,    -1,    -1,   118,   119,   120,   121,    -1,    -1,   415,
     416,   417,   418,   764,   129,    -1,    -1,    -1,   769,   425,
      -1,    -1,    -1,    -1,    -1,    -1,   432,   359,    -1,    -1,
      -1,   437,    -1,    -1,   366,   367,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   799,    -1,
      -1,   802,    -1,    -1,    -1,    -1,    -1,    -1,   809,    -1,
      -1,    -1,    -1,    -1,    -1,   816,    70,    71,    72,    73,
      74,    75,    -1,   824,    78,    79,    80,    81,    82,    83,
      84,    -1,   833,   415,   416,   417,   418,    -1,    -1,    -1,
      -1,    -1,    -1,   425,   845,    -1,    -1,    -1,    -1,    -1,
     506,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,
     516,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   532,    -1,   662,   663,
      -1,   665,   538,    -1,    -1,   541,    -1,    -1,    -1,    -1,
     674,   675,    -1,    -1,    -1,   158,   159,    -1,    -1,    -1,
      -1,    -1,    -1,   559,    -1,    -1,    -1,    -1,    -1,   565,
      -1,    -1,    -1,    -1,    -1,   178,   179,   180,    -1,    -1,
     183,   184,    -1,   186,   187,    -1,   189,    -1,    -1,   192,
      -1,   194,    -1,   196,   197,   591,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   538,   741,   742,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     626,    -1,    -1,   629,    -1,   759,   632,    -1,    -1,    -1,
     636,    -1,   638,   565,   640,   641,   642,   643,   644,   645,
     646,    -1,    -1,   649,    -1,   651,    -1,   653,    -1,    -1,
      -1,    -1,   658,    -1,    -1,    -1,    -1,    -1,    -1,   591,
      -1,   667,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   677,    -1,    -1,    -1,   681,   682,   683,   684,   685,
     686,   687,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   626,   829,    -1,   629,    -1,    -1,
     632,    -1,    -1,   709,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   722,    -1,    -1,   651,
      -1,   653,    -1,    -1,    -1,    -1,   658,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   748,    -1,    -1,   677,    -1,    -1,    -1,   681,
     682,   683,   684,   685,   686,   687,    -1,   370,   764,    -1,
      -1,    -1,   375,   769,    -1,    -1,    -1,    -1,    -1,    -1,
     383,   384,   385,   386,    -1,    -1,    -1,   709,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   399,   400,    -1,    -1,
     403,   404,    -1,   799,   407,    -1,   802,    -1,    -1,    -1,
      -1,    -1,    -1,   809,    -1,    -1,    -1,    -1,    -1,    -1,
     816,    -1,    -1,    -1,    -1,    -1,   748,    -1,   824,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   833,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,   845,
     453,    11,   455,    -1,   457,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    32,    33,    34,    -1,    -1,   799,    -1,    39,
     802,    -1,    42,    43,    44,    -1,    -1,    47,    48,    49,
      50,    51,    -1,    -1,    54,    -1,    -1,   500,    -1,    -1,
      -1,    -1,   824,    -1,    -1,    -1,    -1,    -1,    -1,    69,
     513,   833,   515,    -1,    -1,   518,   519,   520,    -1,    79,
      -1,    -1,    -1,   845,    -1,    -1,    -1,    87,    88,    89,
      90,    91,    -1,    93,    94,    95,    96,    97,    98,    -1,
     100,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,    -1,   118,   119,
     120,   121,    -1,     3,     4,   125,    -1,    -1,    -1,   129,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    32,    33,    34,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    42,    43,    44,    -1,    -1,    47,    48,    49,
      50,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,   639,     3,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,
      90,    91,    -1,    93,    94,    95,    96,    97,    98,    -1,
     100,    27,    -1,   666,   104,    -1,    32,    33,    34,   109,
     110,   111,   112,   113,   114,   115,   116,    -1,   118,   119,
     120,   121,     3,     4,    -1,   125,    -1,    -1,    -1,   129,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      -1,    -1,    -1,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,   118,   119,   120,   121,     3,    -1,    79,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    87,    88,    89,    90,
      91,    -1,    93,    94,    95,    96,    97,    98,    -1,   100,
      27,    -1,    -1,   104,    -1,    32,    33,    34,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,   118,   119,   120,
     121,    -1,    -1,    50,    -1,     3,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    79,    -1,    32,    33,    34,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    -1,    93,    94,    -1,    96,
      97,    98,    50,   100,     3,    -1,    -1,   104,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,   118,   119,   120,   121,    -1,    -1,    -1,    27,    -1,
      -1,    79,   129,    32,    33,    34,    -1,    -1,    -1,    87,
      88,    89,    90,    91,    -1,    93,    94,    -1,    96,    97,
      98,    50,   100,     3,    -1,    -1,   104,    -1,     8,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,    -1,
     118,   119,   120,   121,    -1,    -1,    -1,    27,    -1,    -1,
      -1,   129,    32,    33,    34,    -1,    -1,    -1,    87,    88,
      89,    90,    91,    -1,    93,    94,    -1,    96,    97,    98,
      -1,   100,     3,    -1,    -1,   104,    -1,     8,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,   118,
     119,   120,   121,    -1,    -1,    -1,    27,    -1,    -1,    79,
     129,    32,    33,    34,    -1,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,
     120,   121,    -1,    -1,    -1,    -1,    -1,    -1,    79,   129,
      -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,    -1,    -1,   104,   105,   106,   107,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   132,   133,     0,    23,   134,   377,     6,     7,     8,
      15,    27,    28,    32,    37,   109,     9,    10,    12,    13,
      14,    34,    76,   118,   119,   120,   118,   118,   137,   138,
     118,   143,   118,   141,   118,   261,   129,   129,   378,   135,
     136,     3,     4,    11,    27,    32,    33,    34,    39,    42,
      43,    44,    47,    48,    49,    50,    51,    54,    69,    79,
      87,    88,    89,    90,    91,    93,    94,    95,    96,    97,
      98,   100,   104,   109,   110,   111,   112,   113,   114,   115,
     116,   118,   119,   120,   121,   125,   129,   173,   184,   224,
     262,   264,   270,   301,   302,   305,   310,   321,   332,   341,
     347,   381,   387,   389,   262,   145,    15,    17,    18,    21,
     155,   157,   139,    15,    16,    17,    18,    21,    29,    50,
     146,   148,    58,    64,    25,   379,   380,    86,    99,   101,
     102,   103,   104,   105,   106,   107,   108,   118,   121,   129,
     173,   184,   188,   224,   225,   234,   397,   178,     8,    79,
      86,   118,   129,   188,   189,   225,   232,   397,   307,   309,
     122,   174,   122,   175,   122,   129,   129,   277,   129,   306,
     127,   376,   129,   129,   324,   340,   125,   125,   386,   368,
     367,   129,   129,   308,   129,   129,   366,   125,   129,   385,
     129,   129,   358,   129,   384,   129,   382,   383,   126,   288,
     130,   388,    25,   263,    64,    39,    64,    65,    66,    68,
      70,    71,    72,    73,    74,    75,    78,    79,    80,    81,
      82,    83,    84,   117,    58,    59,    60,    61,    62,    63,
      76,    77,   342,    56,   123,   390,    67,    25,    26,    28,
     118,   250,   252,    58,    58,    58,    58,   144,   156,    15,
      26,    28,    29,    30,    31,    98,   118,   163,   165,    58,
      58,    58,    58,    58,    58,    58,   142,   147,   387,   261,
     234,   234,   101,   189,   192,   129,   129,   129,    58,   237,
     398,    67,    25,   179,   129,   119,   192,    58,   191,    25,
      56,    57,    67,   387,   387,   118,   118,   118,   271,   280,
     118,   173,   291,   402,   284,   310,   119,   125,   265,   275,
     332,   347,   332,   361,   365,   387,   387,   387,   353,   348,
     387,   387,   355,   387,   126,   187,   387,   130,   185,   387,
     351,   359,   387,   369,   387,   362,   387,   387,   262,   262,
     262,   303,   304,   319,   323,   322,   325,   326,   327,   328,
     329,   330,   333,   334,   335,   337,   338,   336,   339,   331,
     311,   313,   314,   315,   316,   317,   312,   318,   343,   347,
     371,   124,   127,   392,   395,   391,    58,    58,    58,    24,
      36,   248,   251,   161,   160,   158,   159,    25,   155,    58,
      58,    58,    58,    58,    58,    58,    58,   140,   164,   154,
     153,    20,   118,   152,   150,    20,   151,   149,    24,    25,
     162,   146,   130,   130,    67,   226,   228,   230,   235,   234,
     238,   240,   124,   127,   399,   236,    19,    22,    29,    55,
     180,   262,   190,   189,   192,   194,   204,   233,   290,   310,
     332,    58,   403,    40,   332,   128,   364,   310,   262,   262,
     262,   321,   321,    64,   321,    64,   126,    76,   192,   321,
     321,   321,   321,   126,   130,   305,   305,   332,   321,   321,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,    79,    89,   118,   129,   188,   207,   402,
     310,   321,   321,   321,   321,   321,   234,   234,   344,   387,
     396,   393,   387,   389,   129,   129,   254,   249,   250,   387,
     387,   387,   387,   167,   129,   171,   169,   119,   170,   168,
     166,    24,    25,   246,   163,   387,   387,   387,   387,   232,
     387,   377,   193,   234,   234,   234,   234,    64,   239,   130,
      64,   401,   400,   234,    58,    58,    58,    58,   130,   189,
     123,    56,    57,    64,    78,    80,    81,    82,    84,   195,
     130,    64,   232,    39,   117,   292,   124,   127,   404,   278,
     117,   262,   130,   130,   126,   126,    64,    64,   387,    64,
     387,   387,    64,   352,   360,    64,    64,   117,   119,   118,
      58,   208,    56,    67,    78,    80,    81,    82,    84,   123,
     345,   347,   387,   118,   321,   407,   408,   410,   118,   255,
     253,   192,   262,   387,   118,   176,   387,   232,    29,   172,
     389,   387,   387,   247,    38,   192,   227,    64,    64,   241,
     234,   243,   242,   192,   118,   410,   181,    34,   183,   182,
     196,   205,   197,   198,   199,   200,   201,   192,   202,   206,
     272,   281,   207,   406,   405,    92,   289,   332,   285,   126,
     266,   125,   354,   349,   130,   356,    76,   186,    64,   130,
     372,    64,   130,   374,   370,   363,   320,   216,   207,   217,
     221,   209,   211,   212,   213,   214,   215,   210,   346,    58,
     122,   128,    67,    39,   117,    64,   130,   118,   257,   259,
      36,   117,    64,   130,   262,   243,   229,   231,   234,   244,
     234,   128,   194,   232,   387,   189,   192,   192,   192,   192,
     192,   192,   203,   192,   290,   207,   207,   118,   413,   129,
      41,   293,   207,   270,   305,   276,   321,   321,   321,   387,
     192,   373,   375,   321,   321,   310,   207,    64,   218,   130,
      64,   207,   207,   207,   207,   207,   207,   207,   345,   411,
     118,   394,   409,   412,   256,   255,   117,   130,    64,   177,
     176,    35,   130,   173,   224,   245,   245,   243,   202,    39,
     117,    58,    39,   128,   332,   294,    45,   117,   267,    53,
     295,   130,   350,    64,   130,   321,   321,   130,   130,   222,
     207,   219,   223,   321,   392,   118,   408,   410,   192,   260,
     258,   232,   130,   130,   273,   282,   414,   415,   130,   310,
     279,   286,    52,   268,   298,    53,    55,   126,   372,   357,
     130,   130,   207,   220,   207,   192,   257,   290,   310,   192,
     413,   262,   310,   269,   207,   296,   117,   321,   219,   130,
     130,    46,   130,   264,   117,   207,   300,   130,   274,   283,
     287,   299,   117,   262,   270,   270,   270,   262,   297,   262
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   131,   132,   133,   133,   135,   134,   136,   134,   137,
     134,   138,   134,   134,   139,   140,   134,   141,   142,   134,
     143,   144,   134,   145,   134,   134,   147,   146,   146,   149,
     148,   148,   148,   150,   148,   148,   151,   148,   152,   148,
     153,   148,   154,   148,   156,   155,   155,   158,   157,   159,
     157,   160,   157,   161,   157,   162,   162,   163,   164,   163,
     165,   166,   165,   167,   165,   168,   165,   169,   165,   165,
     170,   165,   171,   165,   172,   172,   173,   173,   173,   173,
     174,   174,   175,   175,   176,   177,   176,   176,   178,   179,
     178,   181,   180,   182,   180,   183,   180,   180,   185,   186,
     184,   184,   184,   184,   184,   187,   187,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   189,   189,   189,
     189,   190,   189,   189,   191,   189,   192,   193,   192,   195,
     194,   194,   194,   194,   196,   194,   197,   194,   198,   194,
     199,   194,   200,   194,   201,   194,   202,   203,   202,   205,
     204,   206,   204,   207,   207,   207,   207,   208,   207,   209,
     207,   207,   210,   207,   211,   207,   212,   207,   213,   207,
     214,   207,   215,   207,   216,   207,   218,   217,   217,   219,
     220,   219,   222,   221,   223,   221,   224,   224,   224,   224,
     226,   227,   225,   228,   229,   225,   230,   231,   225,   232,
     232,   233,   232,   232,   232,   234,   234,   234,   234,   235,
     234,   236,   234,   237,   234,   239,   238,   238,   241,   240,
     242,   240,   243,   244,   243,   245,   245,   247,   246,   246,
     249,   248,   248,   250,   251,   250,   252,   253,   252,   254,
     252,   255,   256,   255,   255,   258,   257,   257,   259,   260,
     259,   261,   261,   261,   263,   262,   262,   262,   265,   266,
     267,   264,   264,   268,   269,   268,   271,   272,   273,   274,
     270,   275,   276,   270,   277,   278,   279,   270,   280,   281,
     282,   283,   270,   284,   285,   286,   287,   270,   288,   270,
     270,   270,   270,   289,   289,   290,   290,   292,   291,   291,
     293,   294,   293,   296,   297,   295,   298,   299,   295,   300,
     295,   301,   301,   303,   302,   304,   302,   305,   305,   306,
     305,   307,   305,   308,   305,   309,   305,   305,   310,   311,
     310,   312,   310,   313,   310,   314,   310,   315,   310,   316,
     310,   317,   310,   318,   310,   319,   320,   310,   322,   321,
     323,   321,   324,   321,   325,   321,   326,   321,   327,   321,
     328,   321,   329,   321,   330,   321,   331,   321,   321,   332,
     333,   332,   334,   332,   335,   332,   336,   332,   337,   332,
     338,   332,   339,   332,   340,   332,   342,   341,   344,   343,
     343,   346,   345,   345,   348,   349,   350,   347,   351,   352,
     347,   353,   354,   347,   355,   356,   357,   347,   358,   347,
     359,   360,   347,   361,   347,   362,   363,   347,   364,   347,
     365,   347,   366,   347,   367,   347,   368,   347,   369,   370,
     347,   347,   371,   347,   347,   347,   372,   373,   372,   375,
     374,   374,   376,   376,   377,   377,   378,   377,   379,   377,
     380,   377,   377,   377,   377,   377,   377,   382,   381,   383,
     381,   384,   381,   385,   381,   386,   381,   381,   388,   387,
     387,   387,   387,   387,   387,   390,   389,   391,   389,   392,
     393,   394,   392,   392,   396,   395,   398,   397,   399,   400,
     399,   401,   399,   403,   402,   404,   405,   404,   406,   404,
     407,   407,   407,   409,   408,   408,   411,   410,   412,   410,
     414,   413,   415,   413
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     0,     6,     0,     6,     0,
       5,     0,     5,     4,     0,     0,     7,     0,     0,     6,
       0,     0,     6,     0,     6,     2,     0,     3,     0,     0,
       4,     3,     3,     0,     4,     3,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     3,     0,     0,     4,     0,
       4,     0,     4,     0,     4,     3,     1,     0,     0,     3,
       5,     0,     4,     0,     4,     0,     4,     0,     4,     3,
       0,     4,     0,     4,     1,     1,     1,     3,     2,     2,
       0,     2,     0,     2,     1,     0,     4,     3,     0,     0,
       3,     0,     4,     0,     4,     0,     4,     3,     0,     0,
       8,     3,     3,     1,     4,     3,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       1,     0,     4,     2,     0,     4,     1,     0,     4,     0,
       3,     1,     2,     2,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     0,     3,     0,
       4,     0,     4,     1,     2,     2,     1,     0,     4,     0,
       4,     2,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     3,     1,     0,
       0,     3,     0,     4,     0,     4,     1,     1,     1,     1,
       0,     0,     7,     0,     0,     8,     0,     0,     8,     1,
       1,     0,     4,     2,     2,     1,     1,     2,     1,     0,
       4,     0,     4,     0,     4,     0,     3,     1,     0,     4,
       0,     4,     0,     0,     3,     1,     1,     0,     4,     1,
       0,     4,     1,     0,     0,     3,     5,     0,     6,     0,
       4,     1,     0,     4,     3,     0,     4,     1,     1,     0,
       4,     1,     3,     3,     0,     3,     1,     1,     0,     0,
       0,     9,     1,     0,     0,     3,     0,     0,     0,     0,
      13,     0,     0,     9,     0,     0,     0,    11,     0,     0,
       0,     0,    13,     0,     0,     0,     0,    13,     0,     4,
       2,     1,     2,     1,     4,     1,     0,     0,     4,     1,
       0,     0,     3,     0,     0,     7,     0,     0,     6,     0,
       5,     1,     1,     0,     4,     0,     4,     1,     1,     0,
       3,     0,     3,     0,     3,     0,     3,     1,     1,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     0,     7,     0,     4,
       0,     4,     0,     3,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     1,     1,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     3,     0,     3,     0,     3,
       0,     0,     3,     0,     0,     0,     0,     9,     0,     0,
       6,     0,     0,     8,     0,     0,     0,    11,     0,     3,
       0,     0,     6,     0,     5,     0,     0,     8,     0,     6,
       0,     5,     0,     3,     0,     3,     0,     3,     0,     0,
       8,     2,     0,     4,     6,     1,     1,     0,     4,     0,
       4,     1,     0,     3,     0,     2,     0,     4,     0,     6,
       0,     6,     2,     2,     2,     2,     2,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     1,     0,     4,
       2,     1,     1,     1,     1,     0,     3,     0,     4,     0,
       0,     0,     6,     1,     0,     3,     0,     3,     0,     0,
       4,     0,     3,     0,     3,     0,     0,     4,     0,     3,
       1,     1,     1,     0,     4,     3,     0,     4,     0,     4,
       0,     4,     0,     4
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
  case 5: /* @1: %empty  */
#line 153 "poet_yacc.y"
                            {yyval.ptr=insert_parameter(yyvsp[0].ptr);}
#line 2850 "poet_yacc.c"
    break;

  case 6: /* section: LTAG PARAMETER ID @1 paramAttrs ENDTAG  */
#line 154 "poet_yacc.y"
            {finish_parameter(yyvsp[-2]); }
#line 2856 "poet_yacc.c"
    break;

  case 7: /* @2: %empty  */
#line 155 "poet_yacc.y"
                     {yyval.config=GLOBAL_SCOPE; }
#line 2862 "poet_yacc.c"
    break;

  case 8: /* section: LTAG DEFINE ID @2 parseType ENDTAG  */
#line 156 "poet_yacc.y"
            {eval_define(make_macroVar(yyvsp[-3].ptr),yyvsp[-1].ptr); }
#line 2868 "poet_yacc.c"
    break;

  case 9: /* @3: %empty  */
#line 157 "poet_yacc.y"
                {yyval.config=GLOBAL_VAR; }
#line 2874 "poet_yacc.c"
    break;

  case 10: /* section: LTAG EVAL @3 code ENDTAG  */
#line 157 "poet_yacc.y"
                                                     { insert_eval(yyvsp[-1].ptr); }
#line 2880 "poet_yacc.c"
    break;

  case 11: /* @4: %empty  */
#line 158 "poet_yacc.y"
                {yyval.config=GLOBAL_VAR; }
#line 2886 "poet_yacc.c"
    break;

  case 12: /* section: LTAG COND @4 code ENDTAG  */
#line 158 "poet_yacc.y"
                                                      { insert_cond(yyvsp[-1].ptr); }
#line 2892 "poet_yacc.c"
    break;

  case 13: /* section: LTAG TRACE traceVars ENDTAG  */
#line 159 "poet_yacc.y"
                                  { insert_trace(yyvsp[-1]); }
#line 2898 "poet_yacc.c"
    break;

  case 14: /* @5: %empty  */
#line 160 "poet_yacc.y"
                   {yyval.ptr=insert_code(yyvsp[0].ptr);yyval.config=0; }
#line 2904 "poet_yacc.c"
    break;

  case 15: /* @6: %empty  */
#line 160 "poet_yacc.y"
                                                                        {yyval.ptr = yyvsp[-1].ptr; }
#line 2910 "poet_yacc.c"
    break;

  case 17: /* @7: %empty  */
#line 161 "poet_yacc.y"
                 {yyval.ptr=insert_input(); }
#line 2916 "poet_yacc.c"
    break;

  case 18: /* @8: %empty  */
#line 161 "poet_yacc.y"
                                                      {yyval.ptr=yyvsp[-1].ptr; }
#line 2922 "poet_yacc.c"
    break;

  case 20: /* @9: %empty  */
#line 162 "poet_yacc.y"
                  {yyval.ptr=insert_output(); }
#line 2928 "poet_yacc.c"
    break;

  case 21: /* @10: %empty  */
#line 162 "poet_yacc.y"
                                                         {yyval.ptr=yyvsp[-1].ptr; }
#line 2934 "poet_yacc.c"
    break;

  case 23: /* @11: %empty  */
#line 163 "poet_yacc.y"
                    { yyval.ptr=insert_xform(yyvsp[0].ptr); }
#line 2940 "poet_yacc.c"
    break;

  case 24: /* section: LTAG XFORM ID @11 xformAttrs xformRHS  */
#line 164 "poet_yacc.y"
            { set_xform_def(yyvsp[-2].ptr,yyvsp[0].ptr); }
#line 2946 "poet_yacc.c"
    break;

  case 25: /* section: inputBase INPUT_ENDFILE  */
#line 165 "poet_yacc.y"
                              { insert_source(yyvsp[-1].ptr); }
#line 2952 "poet_yacc.c"
    break;

  case 26: /* @12: %empty  */
#line 167 "poet_yacc.y"
                       {yyval.ptr = yyvsp[-1].ptr; }
#line 2958 "poet_yacc.c"
    break;

  case 29: /* @13: %empty  */
#line 169 "poet_yacc.y"
                         {yyval.config=GLOBAL_SCOPE;}
#line 2964 "poet_yacc.c"
    break;

  case 30: /* inputAttr: DEBUG ASSIGN @13 codeUnit  */
#line 169 "poet_yacc.y"
                                                            { set_input_debug(yyvsp[-4].ptr,yyvsp[0].ptr); }
#line 2970 "poet_yacc.c"
    break;

  case 31: /* inputAttr: TO ASSIGN POETTYPE  */
#line 170 "poet_yacc.y"
                               { set_input_target(yyvsp[-3].ptr, yyvsp[-3].ptr); }
#line 2976 "poet_yacc.c"
    break;

  case 32: /* inputAttr: TO ASSIGN ID  */
#line 171 "poet_yacc.y"
                         { set_input_target(yyvsp[-3].ptr,make_varRef(yyvsp[0].ptr,GLOBAL_VAR)); }
#line 2982 "poet_yacc.c"
    break;

  case 33: /* @14: %empty  */
#line 172 "poet_yacc.y"
                          {yyval.config=GLOBAL_SCOPE;}
#line 2988 "poet_yacc.c"
    break;

  case 34: /* inputAttr: SYNTAX ASSIGN @14 codeUnit  */
#line 172 "poet_yacc.y"
                                                             {set_input_syntax(yyvsp[-4].ptr,yyvsp[0].ptr);}
#line 2994 "poet_yacc.c"
    break;

  case 35: /* inputAttr: PARSE ASSIGN POETTYPE  */
#line 173 "poet_yacc.y"
                                   { set_input_codeType(yyvsp[-3].ptr, yyvsp[-3].ptr); }
#line 3000 "poet_yacc.c"
    break;

  case 36: /* @15: %empty  */
#line 174 "poet_yacc.y"
                          {yyval.config=CODE_OR_XFORM_VAR; }
#line 3006 "poet_yacc.c"
    break;

  case 37: /* inputAttr: PARSE ASSIGN @15 parseType  */
#line 175 "poet_yacc.y"
                   { set_input_codeType(yyvsp[-4].ptr,yyvsp[0].ptr); }
#line 3012 "poet_yacc.c"
    break;

  case 38: /* @16: %empty  */
#line 176 "poet_yacc.y"
                        {yyval.config=GLOBAL_SCOPE;}
#line 3018 "poet_yacc.c"
    break;

  case 39: /* inputAttr: FROM ASSIGN @16 codeUnit  */
#line 176 "poet_yacc.y"
                                                           {set_input_files(yyvsp[-4].ptr,yyvsp[0].ptr); }
#line 3024 "poet_yacc.c"
    break;

  case 40: /* @17: %empty  */
#line 177 "poet_yacc.y"
                         {yyval.config=GLOBAL_SCOPE;}
#line 3030 "poet_yacc.c"
    break;

  case 41: /* inputAttr: ANNOT ASSIGN @17 codeUnit  */
#line 177 "poet_yacc.y"
                                                            { set_input_annot(yyvsp[-4].ptr,yyvsp[0].ptr); }
#line 3036 "poet_yacc.c"
    break;

  case 42: /* @18: %empty  */
#line 178 "poet_yacc.y"
                        {yyval.config=GLOBAL_SCOPE;}
#line 3042 "poet_yacc.c"
    break;

  case 43: /* inputAttr: COND ASSIGN @18 codeUnit  */
#line 178 "poet_yacc.y"
                                                           { set_input_cond(yyvsp[-4].ptr,yyvsp[0].ptr); }
#line 3048 "poet_yacc.c"
    break;

  case 44: /* @19: %empty  */
#line 180 "poet_yacc.y"
                         {yyval.ptr = yyvsp[-1].ptr; }
#line 3054 "poet_yacc.c"
    break;

  case 47: /* @20: %empty  */
#line 182 "poet_yacc.y"
                         {yyval.config=GLOBAL_VAR;}
#line 3060 "poet_yacc.c"
    break;

  case 48: /* outputAttr: FROM ASSIGN @20 codeUnit  */
#line 183 "poet_yacc.y"
                  { set_output_target(yyvsp[-4].ptr,yyvsp[0].ptr); }
#line 3066 "poet_yacc.c"
    break;

  case 49: /* @21: %empty  */
#line 184 "poet_yacc.y"
                          {yyval.config=GLOBAL_SCOPE;}
#line 3072 "poet_yacc.c"
    break;

  case 50: /* outputAttr: SYNTAX ASSIGN @21 codeUnit  */
#line 185 "poet_yacc.y"
                  { set_output_syntax(yyvsp[-4].ptr,yyvsp[0].ptr); }
#line 3078 "poet_yacc.c"
    break;

  case 51: /* @22: %empty  */
#line 186 "poet_yacc.y"
                      {yyval.config=GLOBAL_VAR;}
#line 3084 "poet_yacc.c"
    break;

  case 52: /* outputAttr: TO ASSIGN @22 codeUnit  */
#line 187 "poet_yacc.y"
                  { set_output_file(yyvsp[-4].ptr,yyvsp[0].ptr); }
#line 3090 "poet_yacc.c"
    break;

  case 53: /* @23: %empty  */
#line 188 "poet_yacc.y"
                        {yyval.config=GLOBAL_SCOPE;}
#line 3096 "poet_yacc.c"
    break;

  case 54: /* outputAttr: COND ASSIGN @23 codeUnit  */
#line 189 "poet_yacc.y"
                  { set_output_cond(yyvsp[-4].ptr,yyvsp[0].ptr); }
#line 3102 "poet_yacc.c"
    break;

  case 55: /* inputRHS: RTAG inputBase ENDINPUT  */
#line 190 "poet_yacc.y"
                                    { set_input_inline(yyvsp[-3].ptr,yyvsp[-1].ptr);  }
#line 3108 "poet_yacc.c"
    break;

  case 58: /* @24: %empty  */
#line 193 "poet_yacc.y"
                        {yyval.ptr=yyvsp[-1].ptr; yyval.config=yyvsp[0].config;}
#line 3114 "poet_yacc.c"
    break;

  case 60: /* codeAttr: PARS ASSIGN LP codePars RP  */
#line 194 "poet_yacc.y"
                                      { set_code_params(yyvsp[-5].ptr,yyvsp[-1].ptr); yyval.config=yyvsp[-5].config; }
#line 3120 "poet_yacc.c"
    break;

  case 61: /* @25: %empty  */
#line 195 "poet_yacc.y"
                {yyval.config=ID_DEFAULT;}
#line 3126 "poet_yacc.c"
    break;

  case 62: /* codeAttr: ID ASSIGN @25 codeUnit  */
#line 195 "poet_yacc.y"
                                                 { set_code_attr(yyvsp[-4].ptr, yyvsp[-3].ptr, yyvsp[0].ptr); }
#line 3132 "poet_yacc.c"
    break;

  case 63: /* @26: %empty  */
#line 196 "poet_yacc.y"
                  {yyval.config=ID_DEFAULT;}
#line 3138 "poet_yacc.c"
    break;

  case 64: /* codeAttr: COND ASSIGN @26 codeUnit  */
#line 197 "poet_yacc.y"
      { set_local_static(make_sourceString("cond",4), yyvsp[0].ptr,LVAR_ATTR,yyvsp[0].ptr,1); yyval.config=yyvsp[-4].config; }
#line 3144 "poet_yacc.c"
    break;

  case 65: /* @27: %empty  */
#line 198 "poet_yacc.y"
                     {yyval.config=ID_DEFAULT; }
#line 3150 "poet_yacc.c"
    break;

  case 66: /* codeAttr: REBUILD ASSIGN @27 codeUnit  */
#line 199 "poet_yacc.y"
      { set_local_static(make_sourceString("rebuild",7), yyvsp[0].ptr,LVAR_ATTR,yyvsp[0].ptr,1); yyval.config=yyvsp[-4].config; }
#line 3156 "poet_yacc.c"
    break;

  case 67: /* @28: %empty  */
#line 200 "poet_yacc.y"
                   {yyval.config=ID_DEFAULT; }
#line 3162 "poet_yacc.c"
    break;

  case 68: /* codeAttr: PARSE ASSIGN @28 parseType  */
#line 201 "poet_yacc.y"
      { set_code_parse(yyvsp[-4].ptr,yyvsp[0].ptr); yyval.config=yyvsp[-4].config; }
#line 3168 "poet_yacc.c"
    break;

  case 69: /* codeAttr: LOOKAHEAD ASSIGN ICONST  */
#line 202 "poet_yacc.y"
                              { set_code_lookahead(yyvsp[-3].ptr, yyvsp[0].ptr); yyval.config=yyvsp[-3].config; }
#line 3174 "poet_yacc.c"
    break;

  case 70: /* @29: %empty  */
#line 203 "poet_yacc.y"
                   {yyval.config=ID_DEFAULT; }
#line 3180 "poet_yacc.c"
    break;

  case 71: /* codeAttr: MATCH ASSIGN @29 matchSpec  */
#line 204 "poet_yacc.y"
      { set_local_static(make_sourceString("match",5), yyvsp[0].ptr,LVAR_ATTR,yyvsp[0].ptr,1); yyval.config=yyvsp[-4].config; }
#line 3186 "poet_yacc.c"
    break;

  case 72: /* @30: %empty  */
#line 205 "poet_yacc.y"
                    {yyval.config=ID_DEFAULT; }
#line 3192 "poet_yacc.c"
    break;

  case 73: /* codeAttr: OUTPUT ASSIGN @30 codeUnit  */
#line 206 "poet_yacc.y"
      { set_local_static(make_sourceString("output",6), yyvsp[0].ptr,LVAR_ATTR,yyvsp[0].ptr,1); yyval.config=yyvsp[-4].config; }
#line 3198 "poet_yacc.c"
    break;

  case 74: /* matchSpec: varInvoke  */
#line 208 "poet_yacc.y"
                      { yyval = yyvsp[0]; }
#line 3204 "poet_yacc.c"
    break;

  case 75: /* matchSpec: PARSE  */
#line 209 "poet_yacc.y"
            { yyval.ptr = make_sourceString("PARSE",5); }
#line 3210 "poet_yacc.c"
    break;

  case 76: /* varRef: ID  */
#line 211 "poet_yacc.y"
           { yyval.ptr= make_varRef(yyvsp[0].ptr,yyvsp[-1].config); yyval.config=yyvsp[-1].config; }
#line 3216 "poet_yacc.c"
    break;

  case 77: /* varRef: GLOBAL DOT ID  */
#line 212 "poet_yacc.y"
                    { yyval.ptr=make_varRef(yyvsp[0].ptr,GLOBAL_SCOPE); yyval.config=yyvsp[-3].config; }
#line 3222 "poet_yacc.c"
    break;

  case 78: /* varRef: XFORM xformRef  */
#line 213 "poet_yacc.y"
                     {yyval=yyvsp[0]; }
#line 3228 "poet_yacc.c"
    break;

  case 79: /* varRef: CODE codeRef  */
#line 214 "poet_yacc.y"
                   {yyval=yyvsp[0]; }
#line 3234 "poet_yacc.c"
    break;

  case 80: /* xformRef: %empty  */
#line 216 "poet_yacc.y"
            { yyval.ptr = make_dummyOperator(POET_OP_XFORM); yyval.config=yyvsp[0].config; }
#line 3240 "poet_yacc.c"
    break;

  case 81: /* xformRef: DOT ID  */
#line 217 "poet_yacc.y"
              { yyval.ptr=make_varRef(yyvsp[0].ptr,XFORM_VAR); yyval.config=yyvsp[-2].config; }
#line 3246 "poet_yacc.c"
    break;

  case 82: /* codeRef: %empty  */
#line 219 "poet_yacc.y"
          { yyval.ptr = make_dummyOperator(POET_OP_CODE); }
#line 3252 "poet_yacc.c"
    break;

  case 83: /* codeRef: DOT ID  */
#line 220 "poet_yacc.y"
              { yyval.ptr=make_varRef(yyvsp[0].ptr,CODE_VAR); }
#line 3258 "poet_yacc.c"
    break;

  case 84: /* codePars: ID  */
#line 223 "poet_yacc.y"
               { yyval.ptr=make_localPar(yyvsp[0].ptr,0,LVAR_CODEPAR); }
#line 3264 "poet_yacc.c"
    break;

  case 85: /* @31: %empty  */
#line 224 "poet_yacc.y"
               {yyval.config=CODE_OR_XFORM_VAR; }
#line 3270 "poet_yacc.c"
    break;

  case 86: /* codePars: ID COLON @31 parseType  */
#line 224 "poet_yacc.y"
                                                         { yyval.ptr = make_localPar(yyvsp[-3].ptr, yyvsp[0].ptr,LVAR_CODEPAR); }
#line 3276 "poet_yacc.c"
    break;

  case 87: /* codePars: codePars COMMA codePars  */
#line 225 "poet_yacc.y"
                              {yyval.ptr = make_sourceVector(yyvsp[-2].ptr, yyvsp[0].ptr); }
#line 3282 "poet_yacc.c"
    break;

  case 89: /* @32: %empty  */
#line 227 "poet_yacc.y"
                           {yyval.ptr=yyvsp[-1].ptr; }
#line 3288 "poet_yacc.c"
    break;

  case 91: /* @33: %empty  */
#line 228 "poet_yacc.y"
                        {yyval.config=GLOBAL_SCOPE;}
#line 3294 "poet_yacc.c"
    break;

  case 92: /* paramAttr: TYPE ASSIGN @33 typeMulti  */
#line 229 "poet_yacc.y"
                {set_param_type(yyvsp[-4].ptr,yyvsp[0].ptr); }
#line 3300 "poet_yacc.c"
    break;

  case 93: /* @34: %empty  */
#line 230 "poet_yacc.y"
                      {yyval.config=GLOBAL_SCOPE;}
#line 3306 "poet_yacc.c"
    break;

  case 94: /* paramAttr: DEFAULT ASSIGN @34 codeUnit  */
#line 230 "poet_yacc.y"
                                                         { set_param_default(yyvsp[-4].ptr, yyvsp[0].ptr); }
#line 3312 "poet_yacc.c"
    break;

  case 95: /* @35: %empty  */
#line 231 "poet_yacc.y"
                    {yyval.config=GLOBAL_SCOPE; }
#line 3318 "poet_yacc.c"
    break;

  case 96: /* paramAttr: PARSE ASSIGN @35 parseType  */
#line 231 "poet_yacc.y"
                                                         { set_param_parse(yyvsp[-4].ptr, yyvsp[0].ptr); }
#line 3324 "poet_yacc.c"
    break;

  case 97: /* paramAttr: MESSAGE ASSIGN SOURCE  */
#line 232 "poet_yacc.y"
                             { set_param_message(yyvsp[-3].ptr, yyvsp[0].ptr); }
#line 3330 "poet_yacc.c"
    break;

  case 98: /* @36: %empty  */
#line 235 "poet_yacc.y"
             {yyval.config=yyvsp[-2].config; }
#line 3336 "poet_yacc.c"
    break;

  case 99: /* @37: %empty  */
#line 236 "poet_yacc.y"
              {yyval.config=yyvsp[-5].config; }
#line 3342 "poet_yacc.c"
    break;

  case 100: /* map: MAP LP @36 typeSpec COMMA @37 typeSpec RP  */
#line 237 "poet_yacc.y"
          { yyval.ptr = make_sourceBop(POET_OP_MAP, yyvsp[-4].ptr, yyvsp[-1].ptr); }
#line 3348 "poet_yacc.c"
    break;

  case 101: /* map: MAP LP RP  */
#line 238 "poet_yacc.y"
                { yyval.ptr=make_dummyOperator(POET_OP_MAP); }
#line 3354 "poet_yacc.c"
    break;

  case 102: /* map: MAP LB RB  */
#line 239 "poet_yacc.y"
                { yyval.ptr=make_dummyOperator(POET_OP_MAP); }
#line 3360 "poet_yacc.c"
    break;

  case 103: /* map: MAP  */
#line 240 "poet_yacc.y"
          { yyval.ptr=make_dummyOperator(POET_OP_MAP); }
#line 3366 "poet_yacc.c"
    break;

  case 104: /* map: MAP LB mapEntries RB  */
#line 242 "poet_yacc.y"
        {yyval.ptr=make_sourceUop(POET_OP_MAP, yyvsp[-1].ptr); }
#line 3372 "poet_yacc.c"
    break;

  case 105: /* mapEntries: codeUnit ARROW codeUnit  */
#line 245 "poet_yacc.y"
      { yyval.ptr = make_sourceVector2(yyvsp[-2].ptr,yyvsp[0].ptr); }
#line 3378 "poet_yacc.c"
    break;

  case 106: /* mapEntries: mapEntries COMMA codeUnit ARROW codeUnit  */
#line 247 "poet_yacc.y"
      { yyval.ptr = make_inputlist(yyvsp[-4].ptr,make_sourceVector2(yyvsp[-2].ptr,yyvsp[0].ptr)); }
#line 3384 "poet_yacc.c"
    break;

  case 107: /* singletype: constant  */
#line 249 "poet_yacc.y"
                      {yyval.ptr=yyvsp[0].ptr; }
#line 3390 "poet_yacc.c"
    break;

  case 108: /* singletype: ANY  */
#line 250 "poet_yacc.y"
          { yyval.ptr = make_any(); }
#line 3396 "poet_yacc.c"
    break;

  case 109: /* singletype: INT  */
#line 251 "poet_yacc.y"
          { yyval.ptr = make_type(TYPE_INT); }
#line 3402 "poet_yacc.c"
    break;

  case 110: /* singletype: FLOAT  */
#line 252 "poet_yacc.y"
            { yyval.ptr = make_type(TYPE_FLOAT); }
#line 3408 "poet_yacc.c"
    break;

  case 111: /* singletype: STRING  */
#line 253 "poet_yacc.y"
             { yyval.ptr = make_type(TYPE_STRING); }
#line 3414 "poet_yacc.c"
    break;

  case 112: /* singletype: NAME  */
#line 254 "poet_yacc.y"
           { yyval.ptr = make_type(TYPE_ID); }
#line 3420 "poet_yacc.c"
    break;

  case 113: /* singletype: EXP  */
#line 255 "poet_yacc.y"
          { yyval.ptr = make_dummyOperator(POET_OP_EXP); }
#line 3426 "poet_yacc.c"
    break;

  case 114: /* singletype: VAR  */
#line 256 "poet_yacc.y"
           {  yyval.ptr = make_dummyOperator(POET_OP_VAR); }
#line 3432 "poet_yacc.c"
    break;

  case 115: /* singletype: TUPLE  */
#line 257 "poet_yacc.y"
            { yyval.ptr = make_dummyOperator(POET_OP_TUPLE); }
#line 3438 "poet_yacc.c"
    break;

  case 116: /* singletype: map  */
#line 258 "poet_yacc.y"
          { yyval=yyvsp[0]; }
#line 3444 "poet_yacc.c"
    break;

  case 117: /* typeSpec1: singletype  */
#line 260 "poet_yacc.y"
                      {yyval=yyvsp[0]; }
#line 3450 "poet_yacc.c"
    break;

  case 118: /* typeSpec1: MINUS ICONST  */
#line 261 "poet_yacc.y"
                   { yyval.ptr = negate_Iconst(yyvsp[0].ptr); }
#line 3456 "poet_yacc.c"
    break;

  case 119: /* typeSpec1: EVAL LP code RP  */
#line 262 "poet_yacc.y"
                      { yyval.ptr=make_sourceUop(POET_OP_APPLY, yyvsp[-1].ptr); }
#line 3462 "poet_yacc.c"
    break;

  case 120: /* typeSpec1: varInvokeType  */
#line 263 "poet_yacc.y"
                    { yyval.ptr=yyvsp[0].ptr; }
#line 3468 "poet_yacc.c"
    break;

  case 121: /* @38: %empty  */
#line 264 "poet_yacc.y"
                {yyval.config=yyvsp[-2].config; }
#line 3474 "poet_yacc.c"
    break;

  case 122: /* typeSpec1: ID ASSIGN @38 typeSpec1  */
#line 265 "poet_yacc.y"
         { yyval.ptr=make_sourceAssign(make_varRef(yyvsp[-3].ptr,ASSIGN_VAR), yyvsp[0].ptr); }
#line 3480 "poet_yacc.c"
    break;

  case 123: /* typeSpec1: TILT typeSpec  */
#line 266 "poet_yacc.y"
                    { yyval.ptr = make_typeNot(yyvsp[0]); }
#line 3486 "poet_yacc.c"
    break;

  case 124: /* @39: %empty  */
#line 267 "poet_yacc.y"
         {yyval.config=yyvsp[-1].config;}
#line 3492 "poet_yacc.c"
    break;

  case 125: /* typeSpec1: LP @39 typeMulti RP  */
#line 267 "poet_yacc.y"
                                             { yyval.ptr = yyvsp[-1].ptr; }
#line 3498 "poet_yacc.c"
    break;

  case 126: /* typeSpec: typeSpec1  */
#line 269 "poet_yacc.y"
                    {yyval=yyvsp[0]; }
#line 3504 "poet_yacc.c"
    break;

  case 127: /* @40: %empty  */
#line 270 "poet_yacc.y"
                   {yyval.config=yyvsp[-2].config;}
#line 3510 "poet_yacc.c"
    break;

  case 128: /* typeSpec: typeSpec TOR @40 typeSpec  */
#line 271 "poet_yacc.y"
            { yyval.ptr = make_typeTor(yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 3516 "poet_yacc.c"
    break;

  case 129: /* @41: %empty  */
#line 273 "poet_yacc.y"
                     {yyval.config=yyvsp[-1].config; }
#line 3522 "poet_yacc.c"
    break;

  case 130: /* typeMulti: typeSpec @41 typeList  */
#line 273 "poet_yacc.y"
                                                       { yyval.ptr = (yyvsp[0].ptr==0)? yyvsp[-2].ptr : make_typelist2(yyvsp[-2].ptr,yyvsp[0].ptr); }
#line 3528 "poet_yacc.c"
    break;

  case 131: /* typeMulti: typeTuple  */
#line 274 "poet_yacc.y"
                  { yyval.ptr = yyvsp[0].ptr; }
#line 3534 "poet_yacc.c"
    break;

  case 132: /* typeMulti: typeSpec DOT4  */
#line 275 "poet_yacc.y"
                    {yyval.ptr = make_typeUop(TYPE_LIST1, yyvsp[-1].ptr); }
#line 3540 "poet_yacc.c"
    break;

  case 133: /* typeMulti: typeSpec DOT3  */
#line 276 "poet_yacc.y"
                    {yyval.ptr = make_typeUop(TYPE_LIST, yyvsp[-1].ptr); }
#line 3546 "poet_yacc.c"
    break;

  case 134: /* @42: %empty  */
#line 277 "poet_yacc.y"
                     {yyval.config=yyvsp[-2].config;}
#line 3552 "poet_yacc.c"
    break;

  case 135: /* typeMulti: typeSpec1 DOT2 @42 typeSpec1  */
#line 278 "poet_yacc.y"
           {yyval.ptr = make_sourceBop(POET_OP_RANGE, yyvsp[-3].ptr,yyvsp[0].ptr);}
#line 3558 "poet_yacc.c"
    break;

  case 136: /* @43: %empty  */
#line 279 "poet_yacc.y"
                    {yyval.config=yyvsp[-2].config;}
#line 3564 "poet_yacc.c"
    break;

  case 137: /* typeMulti: typeSpec PLUS @43 typeSpec  */
#line 280 "poet_yacc.y"
           { yyval.ptr=make_sourceBop(POET_OP_PLUS, yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 3570 "poet_yacc.c"
    break;

  case 138: /* @44: %empty  */
#line 281 "poet_yacc.y"
                        {yyval.config=yyvsp[-2].config;}
#line 3576 "poet_yacc.c"
    break;

  case 139: /* typeMulti: typeSpec MULTIPLY @44 typeSpec  */
#line 282 "poet_yacc.y"
           { yyval.ptr = make_sourceBop(POET_OP_MULT,  yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 3582 "poet_yacc.c"
    break;

  case 140: /* @45: %empty  */
#line 283 "poet_yacc.y"
                      {yyval.config=yyvsp[-2].config;}
#line 3588 "poet_yacc.c"
    break;

  case 141: /* typeMulti: typeSpec DIVIDE @45 typeSpec  */
#line 284 "poet_yacc.y"
           { yyval.ptr = make_sourceBop(POET_OP_DIVIDE,  yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 3594 "poet_yacc.c"
    break;

  case 142: /* @46: %empty  */
#line 285 "poet_yacc.y"
                   {yyval.config=yyvsp[-2].config;}
#line 3600 "poet_yacc.c"
    break;

  case 143: /* typeMulti: typeSpec MOD @46 typeSpec  */
#line 285 "poet_yacc.y"
                                                   { yyval.ptr = make_sourceBop(POET_OP_MOD,  yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 3606 "poet_yacc.c"
    break;

  case 144: /* @47: %empty  */
#line 286 "poet_yacc.y"
                       {yyval.config=yyvsp[-2].config;}
#line 3612 "poet_yacc.c"
    break;

  case 145: /* typeMulti: typeSpec DCOLON @47 typeSpec  */
#line 286 "poet_yacc.y"
                                                       { yyval.ptr = make_sourceBop(POET_OP_CONS,yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 3618 "poet_yacc.c"
    break;

  case 146: /* typeList: %empty  */
#line 288 "poet_yacc.y"
            {yyval.ptr=0; }
#line 3624 "poet_yacc.c"
    break;

  case 147: /* @48: %empty  */
#line 289 "poet_yacc.y"
                {yyval.config=yyvsp[-1].config; }
#line 3630 "poet_yacc.c"
    break;

  case 148: /* typeList: typeSpec @48 typeList  */
#line 289 "poet_yacc.y"
                                                 { yyval.ptr = make_typelist2(yyvsp[-2].ptr,yyvsp[0].ptr); }
#line 3636 "poet_yacc.c"
    break;

  case 149: /* @49: %empty  */
#line 290 "poet_yacc.y"
                            {yyval.config=yyvsp[-2].config;}
#line 3642 "poet_yacc.c"
    break;

  case 150: /* typeTuple: typeSpec COMMA @49 typeSpec  */
#line 291 "poet_yacc.y"
                   { yyval.ptr = make_sourceVector2(yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 3648 "poet_yacc.c"
    break;

  case 151: /* @50: %empty  */
#line 292 "poet_yacc.y"
                      {yyval.config=yyvsp[-2].config;}
#line 3654 "poet_yacc.c"
    break;

  case 152: /* typeTuple: typeTuple COMMA @50 typeSpec  */
#line 292 "poet_yacc.y"
                                                      { yyval.ptr = make_sourceVector(yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 3660 "poet_yacc.c"
    break;

  case 153: /* patternSpec: singletype  */
#line 294 "poet_yacc.y"
                        {yyval=yyvsp[0]; }
#line 3666 "poet_yacc.c"
    break;

  case 154: /* patternSpec: MINUS ICONST  */
#line 295 "poet_yacc.y"
                   { yyval.ptr = negate_Iconst(yyvsp[0].ptr); }
#line 3672 "poet_yacc.c"
    break;

  case 155: /* patternSpec: CLEAR ID  */
#line 296 "poet_yacc.y"
               { yyval.ptr = make_sourceUop(POET_OP_CLEAR, make_varRef(yyvsp[0].ptr,ASSIGN_VAR)); }
#line 3678 "poet_yacc.c"
    break;

  case 156: /* patternSpec: varInvokePattern  */
#line 297 "poet_yacc.y"
                       { yyval.ptr=yyvsp[0].ptr; }
#line 3684 "poet_yacc.c"
    break;

  case 157: /* @51: %empty  */
#line 298 "poet_yacc.y"
         {yyval.config=yyvsp[-1].config;}
#line 3690 "poet_yacc.c"
    break;

  case 158: /* patternSpec: LP @51 patternMulti RP  */
#line 298 "poet_yacc.y"
                                                { yyval.ptr = yyvsp[-1].ptr; }
#line 3696 "poet_yacc.c"
    break;

  case 159: /* @52: %empty  */
#line 299 "poet_yacc.y"
                      {yyval.config=yyvsp[-2].config;}
#line 3702 "poet_yacc.c"
    break;

  case 160: /* patternSpec: patternSpec TOR @52 patternSpec  */
#line 300 "poet_yacc.y"
            { yyval.ptr = make_typeTor(yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 3708 "poet_yacc.c"
    break;

  case 161: /* patternSpec: patternSpec DOT3  */
#line 301 "poet_yacc.y"
                       {yyval.ptr = make_typeUop(TYPE_LIST, yyvsp[-1].ptr); }
#line 3714 "poet_yacc.c"
    break;

  case 162: /* @53: %empty  */
#line 302 "poet_yacc.y"
                       {yyval.config=yyvsp[-2].config;}
#line 3720 "poet_yacc.c"
    break;

  case 163: /* patternSpec: patternSpec DOT2 @53 patternSpec  */
#line 303 "poet_yacc.y"
           {yyval.ptr = make_sourceBop(POET_OP_RANGE, yyvsp[-3].ptr,yyvsp[0].ptr);}
#line 3726 "poet_yacc.c"
    break;

  case 164: /* @54: %empty  */
#line 304 "poet_yacc.y"
                       {yyval.config=yyvsp[-2].config;}
#line 3732 "poet_yacc.c"
    break;

  case 165: /* patternSpec: patternSpec PLUS @54 patternSpec  */
#line 305 "poet_yacc.y"
           { yyval.ptr=make_sourceBop(POET_OP_PLUS, yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 3738 "poet_yacc.c"
    break;

  case 166: /* @55: %empty  */
#line 306 "poet_yacc.y"
                           {yyval.config=yyvsp[-2].config;}
#line 3744 "poet_yacc.c"
    break;

  case 167: /* patternSpec: patternSpec MULTIPLY @55 patternSpec  */
#line 307 "poet_yacc.y"
           { yyval.ptr = make_sourceBop(POET_OP_MULT,  yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 3750 "poet_yacc.c"
    break;

  case 168: /* @56: %empty  */
#line 308 "poet_yacc.y"
                         {yyval.config=yyvsp[-2].config;}
#line 3756 "poet_yacc.c"
    break;

  case 169: /* patternSpec: patternSpec DIVIDE @56 patternSpec  */
#line 309 "poet_yacc.y"
           { yyval.ptr = make_sourceBop(POET_OP_DIVIDE,  yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 3762 "poet_yacc.c"
    break;

  case 170: /* @57: %empty  */
#line 310 "poet_yacc.y"
                      {yyval.config=yyvsp[-2].config;}
#line 3768 "poet_yacc.c"
    break;

  case 171: /* patternSpec: patternSpec MOD @57 patternSpec  */
#line 311 "poet_yacc.y"
           { yyval.ptr = make_sourceBop(POET_OP_MOD,  yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 3774 "poet_yacc.c"
    break;

  case 172: /* @58: %empty  */
#line 312 "poet_yacc.y"
                         {yyval.config=yyvsp[-2].config;}
#line 3780 "poet_yacc.c"
    break;

  case 173: /* patternSpec: patternSpec DCOLON @58 patternSpec  */
#line 312 "poet_yacc.y"
                                                            { yyval.ptr = make_sourceBop(POET_OP_CONS,yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 3786 "poet_yacc.c"
    break;

  case 174: /* @59: %empty  */
#line 313 "poet_yacc.y"
                {yyval.config=yyvsp[-2].config;}
#line 3792 "poet_yacc.c"
    break;

  case 175: /* patternSpec: ID ASSIGN @59 patternSpec  */
#line 313 "poet_yacc.y"
                                                   { yyval.ptr=make_sourceAssign(make_varRef(yyvsp[-3].ptr,ASSIGN_VAR), yyvsp[0].ptr); }
#line 3798 "poet_yacc.c"
    break;

  case 176: /* @60: %empty  */
#line 315 "poet_yacc.y"
                           {yyval.config=yyvsp[-1].config; }
#line 3804 "poet_yacc.c"
    break;

  case 177: /* patternMulti: patternSpec @60 patternList  */
#line 315 "poet_yacc.y"
                                                                { yyval.ptr = (yyvsp[0].ptr==0)? yyvsp[-2].ptr : make_typelist2(yyvsp[-2].ptr,yyvsp[0].ptr); }
#line 3810 "poet_yacc.c"
    break;

  case 178: /* patternMulti: patternTuple  */
#line 316 "poet_yacc.y"
                     { yyval.ptr = yyvsp[0].ptr; }
#line 3816 "poet_yacc.c"
    break;

  case 179: /* patternList: %empty  */
#line 318 "poet_yacc.y"
               {yyval.ptr=0; }
#line 3822 "poet_yacc.c"
    break;

  case 180: /* @61: %empty  */
#line 319 "poet_yacc.y"
                   {yyval.config=yyvsp[-1].config; }
#line 3828 "poet_yacc.c"
    break;

  case 181: /* patternList: patternSpec @61 patternList  */
#line 319 "poet_yacc.y"
                                                       { yyval.ptr = make_typelist2(yyvsp[-2].ptr,yyvsp[0].ptr); }
#line 3834 "poet_yacc.c"
    break;

  case 182: /* @62: %empty  */
#line 320 "poet_yacc.y"
                                  {yyval.config=yyvsp[-2].config;}
#line 3840 "poet_yacc.c"
    break;

  case 183: /* patternTuple: patternSpec COMMA @62 patternSpec  */
#line 321 "poet_yacc.y"
                   { yyval.ptr = make_sourceVector2(yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 3846 "poet_yacc.c"
    break;

  case 184: /* @63: %empty  */
#line 322 "poet_yacc.y"
                         {yyval.config=yyvsp[-2].config;}
#line 3852 "poet_yacc.c"
    break;

  case 185: /* patternTuple: patternTuple COMMA @63 patternSpec  */
#line 322 "poet_yacc.y"
                                                            { yyval.ptr = make_sourceVector(yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 3858 "poet_yacc.c"
    break;

  case 186: /* constant: ICONST  */
#line 324 "poet_yacc.y"
                  { yyval.ptr=yyvsp[0].ptr; }
#line 3864 "poet_yacc.c"
    break;

  case 187: /* constant: FCONST  */
#line 325 "poet_yacc.y"
             { yyval.ptr = yyvsp[0].ptr; }
#line 3870 "poet_yacc.c"
    break;

  case 188: /* constant: SOURCE  */
#line 326 "poet_yacc.y"
              { yyval.ptr = yyvsp[0].ptr; }
#line 3876 "poet_yacc.c"
    break;

  case 189: /* constant: ENDLIST  */
#line 327 "poet_yacc.y"
              { yyval.ptr=make_empty_list(); }
#line 3882 "poet_yacc.c"
    break;

  case 190: /* @64: %empty  */
#line 329 "poet_yacc.y"
                       {yyval.config=yyvsp[-2].config; }
#line 3888 "poet_yacc.c"
    break;

  case 191: /* @65: %empty  */
#line 329 "poet_yacc.y"
                                                         {yyval.config=yyvsp[-4].config;}
#line 3894 "poet_yacc.c"
    break;

  case 192: /* parseType1: TUPLE LP @64 parseElem @65 parseElemList RP  */
#line 329 "poet_yacc.y"
                                                                                                 { yyval.ptr = make_sourceUop(POET_OP_TUPLE, make_typelist2(yyvsp[-3].ptr,yyvsp[-1].ptr)); }
#line 3900 "poet_yacc.c"
    break;

  case 193: /* @66: %empty  */
#line 330 "poet_yacc.y"
              {yyval.config=yyvsp[-2].config; }
#line 3906 "poet_yacc.c"
    break;

  case 194: /* @67: %empty  */
#line 330 "poet_yacc.y"
                                                      {yyval.config=yyvsp[-5].config;}
#line 3912 "poet_yacc.c"
    break;

  case 195: /* parseType1: LIST LP @66 parseElem COMMA @67 constantOrVar RP  */
#line 330 "poet_yacc.y"
                                                                                              { yyval.ptr = make_sourceBop(POET_OP_LIST,yyvsp[-4].ptr,yyvsp[-1].ptr); }
#line 3918 "poet_yacc.c"
    break;

  case 196: /* @68: %empty  */
#line 331 "poet_yacc.y"
               {yyval.config=yyvsp[-2].config; }
#line 3924 "poet_yacc.c"
    break;

  case 197: /* @69: %empty  */
#line 331 "poet_yacc.y"
                                                       {yyval.config=yyvsp[-5].config;}
#line 3930 "poet_yacc.c"
    break;

  case 198: /* parseType1: LIST1 LP @68 parseElem COMMA @69 constantOrVar RP  */
#line 331 "poet_yacc.y"
                                                                                               { yyval.ptr = make_sourceBop(POET_OP_LIST1,yyvsp[-4].ptr,yyvsp[-1].ptr); }
#line 3936 "poet_yacc.c"
    break;

  case 199: /* parseType: parseType1  */
#line 333 "poet_yacc.y"
                       {yyval=yyvsp[0]; }
#line 3942 "poet_yacc.c"
    break;

  case 200: /* parseType: typeSpec1  */
#line 334 "poet_yacc.y"
                { yyval=yyvsp[0]; }
#line 3948 "poet_yacc.c"
    break;

  case 201: /* @70: %empty  */
#line 335 "poet_yacc.y"
                    {yyval.config=yyvsp[-2].config;}
#line 3954 "poet_yacc.c"
    break;

  case 202: /* parseType: parseType TOR @70 parseType  */
#line 336 "poet_yacc.y"
            { yyval.ptr = make_typeTor(yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 3960 "poet_yacc.c"
    break;

  case 203: /* parseType: parseType DOT4  */
#line 337 "poet_yacc.y"
                     {yyval.ptr = make_typeUop(TYPE_LIST1, yyvsp[-1].ptr); }
#line 3966 "poet_yacc.c"
    break;

  case 204: /* parseType: parseType DOT3  */
#line 338 "poet_yacc.y"
                     {yyval.ptr = make_typeUop(TYPE_LIST, yyvsp[-1].ptr); }
#line 3972 "poet_yacc.c"
    break;

  case 205: /* parseElem: singletype  */
#line 340 "poet_yacc.y"
                       { yyval=yyvsp[0]; }
#line 3978 "poet_yacc.c"
    break;

  case 206: /* parseElem: varInvokeType  */
#line 341 "poet_yacc.y"
                      { yyval.ptr=yyvsp[0].ptr; }
#line 3984 "poet_yacc.c"
    break;

  case 207: /* parseElem: TILT typeSpec  */
#line 342 "poet_yacc.y"
                      { yyval.ptr = make_typeNot(yyvsp[0]); }
#line 3990 "poet_yacc.c"
    break;

  case 208: /* parseElem: parseType1  */
#line 343 "poet_yacc.y"
                   { yyval = yyvsp[0]; }
#line 3996 "poet_yacc.c"
    break;

  case 209: /* @71: %empty  */
#line 344 "poet_yacc.y"
                  {yyval.config=yyvsp[-2].config; }
#line 4002 "poet_yacc.c"
    break;

  case 210: /* parseElem: ID ASSIGN @71 parseElem  */
#line 345 "poet_yacc.y"
         { yyval.ptr=make_sourceAssign(make_varRef(yyvsp[-3].ptr,yyvsp[-4].config), yyvsp[0].ptr); }
#line 4008 "poet_yacc.c"
    break;

  case 211: /* @72: %empty  */
#line 346 "poet_yacc.y"
                      {yyval.config=yyvsp[-2].config;}
#line 4014 "poet_yacc.c"
    break;

  case 212: /* parseElem: parseElem TOR @72 parseElem  */
#line 347 "poet_yacc.y"
            { yyval.ptr = make_typeTor(yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 4020 "poet_yacc.c"
    break;

  case 213: /* @73: %empty  */
#line 348 "poet_yacc.y"
           {yyval.config=yyvsp[-1].config;}
#line 4026 "poet_yacc.c"
    break;

  case 214: /* parseElem: LP @73 parseElemMulti RP  */
#line 348 "poet_yacc.y"
                                                    { yyval.ptr = yyvsp[-1].ptr; }
#line 4032 "poet_yacc.c"
    break;

  case 215: /* @74: %empty  */
#line 350 "poet_yacc.y"
                           {yyval.config=yyvsp[-1].config; }
#line 4038 "poet_yacc.c"
    break;

  case 216: /* parseElemMulti: parseElem @74 parseElemList  */
#line 350 "poet_yacc.y"
                                                                  { yyval.ptr = (yyvsp[0].ptr==0)? yyvsp[-2].ptr : make_typelist2(yyvsp[-2].ptr,yyvsp[0].ptr); }
#line 4044 "poet_yacc.c"
    break;

  case 217: /* parseElemMulti: parseElemTuple  */
#line 351 "poet_yacc.y"
                       { yyval.ptr = yyvsp[0].ptr; }
#line 4050 "poet_yacc.c"
    break;

  case 218: /* @75: %empty  */
#line 352 "poet_yacc.y"
                                  {yyval.config=yyvsp[-2].config;}
#line 4056 "poet_yacc.c"
    break;

  case 219: /* parseElemTuple: parseElem COMMA @75 parseElem  */
#line 353 "poet_yacc.y"
                   { yyval.ptr = make_sourceVector2(yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 4062 "poet_yacc.c"
    break;

  case 220: /* @76: %empty  */
#line 354 "poet_yacc.y"
                           {yyval.config=yyvsp[-2].config;}
#line 4068 "poet_yacc.c"
    break;

  case 221: /* parseElemTuple: parseElemTuple COMMA @76 parseElem  */
#line 354 "poet_yacc.y"
                                                            { yyval.ptr = make_sourceVector(yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 4074 "poet_yacc.c"
    break;

  case 222: /* parseElemList: %empty  */
#line 355 "poet_yacc.y"
                {yyval.ptr=0; }
#line 4080 "poet_yacc.c"
    break;

  case 223: /* @77: %empty  */
#line 356 "poet_yacc.y"
                  {yyval.config=yyvsp[-1].config; }
#line 4086 "poet_yacc.c"
    break;

  case 224: /* parseElemList: parseElem @77 parseElemList  */
#line 356 "poet_yacc.y"
                                                         { yyval.ptr = make_typelist2(yyvsp[-2].ptr,yyvsp[0].ptr); }
#line 4092 "poet_yacc.c"
    break;

  case 225: /* constantOrVar: constant  */
#line 358 "poet_yacc.y"
                         {yyval.ptr=yyvsp[0].ptr; }
#line 4098 "poet_yacc.c"
    break;

  case 226: /* constantOrVar: varRef  */
#line 359 "poet_yacc.y"
              { yyval = yyvsp[0]; }
#line 4104 "poet_yacc.c"
    break;

  case 227: /* @78: %empty  */
#line 361 "poet_yacc.y"
               {yaccState=YACC_CODE; yyval.config=ID_DEFAULT;}
#line 4110 "poet_yacc.c"
    break;

  case 228: /* codeRHS: RTAG @78 code ENDCODE  */
#line 361 "poet_yacc.y"
                                                                         { yaccState=YACC_DEFAULT; set_code_def(yyvsp[-4].ptr,yyvsp[-1].ptr); }
#line 4116 "poet_yacc.c"
    break;

  case 229: /* codeRHS: ENDTAG  */
#line 362 "poet_yacc.y"
             { set_code_def(yyvsp[-1].ptr, 0); }
#line 4122 "poet_yacc.c"
    break;

  case 230: /* @79: %empty  */
#line 363 "poet_yacc.y"
                {yyval.config=ID_DEFAULT; }
#line 4128 "poet_yacc.c"
    break;

  case 231: /* xformRHS: RTAG @79 code ENDXFORM  */
#line 363 "poet_yacc.y"
                                                       {yyval.ptr=yyvsp[-1].ptr; }
#line 4134 "poet_yacc.c"
    break;

  case 232: /* xformRHS: ENDXFORM  */
#line 364 "poet_yacc.y"
               {yyval.ptr = 0; }
#line 4140 "poet_yacc.c"
    break;

  case 234: /* @80: %empty  */
#line 365 "poet_yacc.y"
                         {yyval=yyvsp[-1]; }
#line 4146 "poet_yacc.c"
    break;

  case 236: /* xformAttr: PARS ASSIGN LP xformPars RP  */
#line 366 "poet_yacc.y"
                                        {set_xform_params(yyvsp[-5].ptr,yyvsp[-1].ptr); }
#line 4152 "poet_yacc.c"
    break;

  case 237: /* @81: %empty  */
#line 367 "poet_yacc.y"
                       {yyval.ptr=0;}
#line 4158 "poet_yacc.c"
    break;

  case 239: /* @82: %empty  */
#line 368 "poet_yacc.y"
                {yyval.config=CODE_VAR;}
#line 4164 "poet_yacc.c"
    break;

  case 240: /* xformAttr: ID ASSIGN @82 typeSpec  */
#line 368 "poet_yacc.y"
                                               { yyval.ptr = set_local_static(yyvsp[-3].ptr,yyvsp[0].ptr,LVAR_TUNE,0,1); }
#line 4170 "poet_yacc.c"
    break;

  case 241: /* xformPars: ID  */
#line 369 "poet_yacc.y"
                { yyval.ptr=make_localPar(yyvsp[0].ptr,0,LVAR_XFORMPAR); }
#line 4176 "poet_yacc.c"
    break;

  case 242: /* @83: %empty  */
#line 370 "poet_yacc.y"
               {yyval.config=CODE_VAR;}
#line 4182 "poet_yacc.c"
    break;

  case 243: /* xformPars: ID COLON @83 typeSpec  */
#line 370 "poet_yacc.y"
                                              { yyval.ptr = make_localPar(yyvsp[-3].ptr, yyvsp[0].ptr,LVAR_XFORMPAR); }
#line 4188 "poet_yacc.c"
    break;

  case 244: /* xformPars: xformPars COMMA xformPars  */
#line 371 "poet_yacc.y"
                                {yyval.ptr = make_sourceVector(yyvsp[-2].ptr, yyvsp[0].ptr); }
#line 4194 "poet_yacc.c"
    break;

  case 245: /* @84: %empty  */
#line 372 "poet_yacc.y"
                             {yyval.ptr = yyvsp[-2].ptr + 1; }
#line 4200 "poet_yacc.c"
    break;

  case 248: /* outputPar: ID  */
#line 373 "poet_yacc.y"
               { set_local_static(yyvsp[0].ptr,make_Iconst1(yyvsp[-1].ptr), LVAR_OUTPUT,0,1); }
#line 4206 "poet_yacc.c"
    break;

  case 249: /* @85: %empty  */
#line 374 "poet_yacc.y"
               {yyval.config=CODE_VAR;}
#line 4212 "poet_yacc.c"
    break;

  case 250: /* outputPar: ID COLON @85 typeSpec  */
#line 374 "poet_yacc.y"
                                              { set_local_static(yyvsp[-3].ptr,make_Iconst1(yyvsp[-4].ptr), LVAR_OUTPUT,yyvsp[0].ptr,1); }
#line 4218 "poet_yacc.c"
    break;

  case 251: /* traceVars: ID  */
#line 375 "poet_yacc.y"
               { yyval.ptr = make_traceVar(yyvsp[0].ptr,0); }
#line 4224 "poet_yacc.c"
    break;

  case 252: /* traceVars: ID ASSIGN codeUnit  */
#line 376 "poet_yacc.y"
                         { yyval.ptr = make_traceVar(yyvsp[-2].ptr,0); eval_define(yyval.ptr,yyvsp[0].ptr); }
#line 4230 "poet_yacc.c"
    break;

  case 253: /* traceVars: ID COMMA traceVars  */
#line 378 "poet_yacc.y"
           { yyval.ptr = make_traceVar(yyvsp[-2].ptr,yyvsp[0].ptr);  }
#line 4236 "poet_yacc.c"
    break;

  case 254: /* @86: %empty  */
#line 380 "poet_yacc.y"
              {yyval.config=yyvsp[-1].config;}
#line 4242 "poet_yacc.c"
    break;

  case 255: /* code: codeIf @86 code  */
#line 380 "poet_yacc.y"
                                          { yyval.ptr=make_seq(yyvsp[-2].ptr, yyvsp[0].ptr); }
#line 4248 "poet_yacc.c"
    break;

  case 256: /* code: codeIf  */
#line 381 "poet_yacc.y"
             {yyval.ptr=yyvsp[0].ptr; }
#line 4254 "poet_yacc.c"
    break;

  case 257: /* code: code23  */
#line 382 "poet_yacc.y"
             { yyval.ptr = yyvsp[0].ptr; }
#line 4260 "poet_yacc.c"
    break;

  case 258: /* @87: %empty  */
#line 383 "poet_yacc.y"
               {yyval.config=yyvsp[-2].config;}
#line 4266 "poet_yacc.c"
    break;

  case 259: /* @88: %empty  */
#line 383 "poet_yacc.y"
                                               {yyval.config=yyvsp[-5].config;}
#line 4272 "poet_yacc.c"
    break;

  case 260: /* @89: %empty  */
#line 383 "poet_yacc.y"
                                                                            {yyval.config=yyvsp[-7].config;}
#line 4278 "poet_yacc.c"
    break;

  case 261: /* codeIf: IF LP @87 code4 RP @88 code1 @89 codeIfHelp  */
#line 384 "poet_yacc.y"
        { yyval.ptr = make_ifElse(yyvsp[-5].ptr, yyvsp[-2].ptr, yyvsp[0].ptr); }
#line 4284 "poet_yacc.c"
    break;

  case 262: /* codeIf: code1  */
#line 385 "poet_yacc.y"
            { yyval=yyvsp[0]; }
#line 4290 "poet_yacc.c"
    break;

  case 263: /* codeIfHelp: %empty  */
#line 386 "poet_yacc.y"
             { yyval.ptr=make_empty(); }
#line 4296 "poet_yacc.c"
    break;

  case 264: /* @90: %empty  */
#line 387 "poet_yacc.y"
             {yyval.config=yyvsp[-1].config;}
#line 4302 "poet_yacc.c"
    break;

  case 265: /* codeIfHelp: ELSE @90 codeIf  */
#line 387 "poet_yacc.y"
                                           { yyval.ptr = yyvsp[0].ptr; }
#line 4308 "poet_yacc.c"
    break;

  case 266: /* @91: %empty  */
#line 388 "poet_yacc.y"
               {yyval.config=yyvsp[-2].config;}
#line 4314 "poet_yacc.c"
    break;

  case 267: /* @92: %empty  */
#line 389 "poet_yacc.y"
               {yyval.config=yyvsp[-5].config;}
#line 4320 "poet_yacc.c"
    break;

  case 268: /* @93: %empty  */
#line 390 "poet_yacc.y"
               {yyval.config=yyvsp[-8].config;}
#line 4326 "poet_yacc.c"
    break;

  case 269: /* @94: %empty  */
#line 390 "poet_yacc.y"
                                                 {yyval.config=yyvsp[-11].config;}
#line 4332 "poet_yacc.c"
    break;

  case 270: /* code1: FOR LP @91 e_code4 SEMICOLON @92 e_code4 SEMICOLON @93 e_code4 RP @94 code1  */
#line 391 "poet_yacc.y"
        { yyval.ptr = make_sourceQop(POET_OP_FOR, yyvsp[-9].ptr,yyvsp[-6].ptr,yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 4338 "poet_yacc.c"
    break;

  case 271: /* @95: %empty  */
#line 392 "poet_yacc.y"
                 {yyval.config=yyvsp[-2].config;}
#line 4344 "poet_yacc.c"
    break;

  case 272: /* @96: %empty  */
#line 392 "poet_yacc.y"
                                                   {yyval.config=yyvsp[-6].config;}
#line 4350 "poet_yacc.c"
    break;

  case 273: /* code1: SWITCH LP @95 code RP LB @96 switchHelp RB  */
#line 393 "poet_yacc.y"
        { yyval.ptr = make_sourceBop(POET_OP_CASE, yyvsp[-5].ptr,yyvsp[-1].ptr); }
#line 4356 "poet_yacc.c"
    break;

  case 274: /* @97: %empty  */
#line 394 "poet_yacc.y"
               {yyval.config=yyvsp[-1].config;}
#line 4362 "poet_yacc.c"
    break;

  case 275: /* @98: %empty  */
#line 394 "poet_yacc.y"
                                                       {yyval.config=yyvsp[-4].config;}
#line 4368 "poet_yacc.c"
    break;

  case 276: /* @99: %empty  */
#line 394 "poet_yacc.y"
                                                                                                       {yyval.config=yyvsp[-8].config;}
#line 4374 "poet_yacc.c"
    break;

  case 277: /* code1: FOREACH @97 patternAssign IN @98 foreach_body suchThat DO @99 code ENDDO  */
#line 395 "poet_yacc.y"
        { yyval.ptr=make_sourceQop(POET_OP_FOREACH,yyvsp[-5].ptr,yyvsp[-8].ptr,yyvsp[-4].ptr,yyvsp[-1].ptr); }
#line 4380 "poet_yacc.c"
    break;

  case 278: /* @100: %empty  */
#line 396 "poet_yacc.y"
                  {yyval.config=yyvsp[-2].config;}
#line 4386 "poet_yacc.c"
    break;

  case 279: /* @101: %empty  */
#line 397 "poet_yacc.y"
                  {yyval.config=yyvsp[-5].config;}
#line 4392 "poet_yacc.c"
    break;

  case 280: /* @102: %empty  */
#line 398 "poet_yacc.y"
                  {yyval.config=yyvsp[-8].config;}
#line 4398 "poet_yacc.c"
    break;

  case 281: /* @103: %empty  */
#line 398 "poet_yacc.y"
                                                  {yyval.config=yyvsp[-11].config;}
#line 4404 "poet_yacc.c"
    break;

  case 282: /* code1: FOREACH LP @100 code6 COLON @101 patternSpec COLON @102 code4 RP @103 code1  */
#line 399 "poet_yacc.y"
        { yyval.ptr = make_sourceQop(POET_OP_FOREACH, yyvsp[-9].ptr,yyvsp[-6].ptr,yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 4410 "poet_yacc.c"
    break;

  case 283: /* @104: %empty  */
#line 400 "poet_yacc.y"
                    {yyval.config=yyvsp[-2].config;}
#line 4416 "poet_yacc.c"
    break;

  case 284: /* @105: %empty  */
#line 401 "poet_yacc.y"
                    {yyval.config=yyvsp[-5].config;}
#line 4422 "poet_yacc.c"
    break;

  case 285: /* @106: %empty  */
#line 402 "poet_yacc.y"
                    {yyval.config=yyvsp[-8].config;}
#line 4428 "poet_yacc.c"
    break;

  case 286: /* @107: %empty  */
#line 402 "poet_yacc.y"
                                                    {yyval.config=yyvsp[-11].config;}
#line 4434 "poet_yacc.c"
    break;

  case 287: /* code1: FOREACH_R LP @104 code6 COLON @105 patternSpec COLON @106 code4 RP @107 code1  */
#line 403 "poet_yacc.y"
        { yyval.ptr = make_sourceQop(POET_OP_FOREACH, make_sourceUop(POET_OP_REVERSE,yyvsp[-9].ptr),yyvsp[-6].ptr,yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 4440 "poet_yacc.c"
    break;

  case 288: /* @108: %empty  */
#line 404 "poet_yacc.y"
          {yyval.config=yyvsp[-1].config; }
#line 4446 "poet_yacc.c"
    break;

  case 289: /* code1: LB @108 code RB  */
#line 404 "poet_yacc.y"
                                          { yyval.ptr = yyvsp[-1].ptr; }
#line 4452 "poet_yacc.c"
    break;

  case 290: /* code1: LB RB  */
#line 405 "poet_yacc.y"
             { yyval.ptr=make_empty(); }
#line 4458 "poet_yacc.c"
    break;

  case 291: /* code1: SEMICOLON  */
#line 406 "poet_yacc.y"
                 { yyval.ptr = make_empty(); }
#line 4464 "poet_yacc.c"
    break;

  case 292: /* code1: code3 SEMICOLON  */
#line 407 "poet_yacc.y"
                       { yyval.ptr = make_sourceStmt(yyvsp[-1].ptr); }
#line 4470 "poet_yacc.c"
    break;

  case 293: /* foreach_body: code6  */
#line 409 "poet_yacc.y"
                      { yyval.ptr=yyvsp[0].ptr; }
#line 4476 "poet_yacc.c"
    break;

  case 294: /* foreach_body: REVERSE LP code6 RP  */
#line 410 "poet_yacc.y"
                           { yyval.ptr=make_sourceUop(POET_OP_REVERSE,yyvsp[-1].ptr); }
#line 4482 "poet_yacc.c"
    break;

  case 295: /* e_code4: code4  */
#line 412 "poet_yacc.y"
                { yyval.ptr = yyvsp[0].ptr; }
#line 4488 "poet_yacc.c"
    break;

  case 296: /* e_code4: %empty  */
#line 413 "poet_yacc.y"
      { yyval.ptr = make_empty(); }
#line 4494 "poet_yacc.c"
    break;

  case 297: /* @109: %empty  */
#line 416 "poet_yacc.y"
               {yyval.config=yyvsp[-2].config; }
#line 4500 "poet_yacc.c"
    break;

  case 298: /* patternAssign: ID ASSIGN @109 patternSpec  */
#line 417 "poet_yacc.y"
         { yyval.ptr=make_sourceAssign(make_varRef(yyvsp[-3].ptr,ASSIGN_VAR), yyvsp[0].ptr); }
#line 4506 "poet_yacc.c"
    break;

  case 299: /* patternAssign: varInvokePattern  */
#line 418 "poet_yacc.y"
                       { yyval.ptr=yyvsp[0].ptr;}
#line 4512 "poet_yacc.c"
    break;

  case 300: /* suchThat: %empty  */
#line 420 "poet_yacc.y"
           { yyval.ptr=make_Iconst1(1); }
#line 4518 "poet_yacc.c"
    break;

  case 301: /* @110: %empty  */
#line 421 "poet_yacc.y"
               {yyval.config=yyvsp[-1].config;}
#line 4524 "poet_yacc.c"
    break;

  case 302: /* suchThat: SUCH_THAT @110 code4  */
#line 421 "poet_yacc.y"
                                             { yyval.ptr=yyvsp[0].ptr; }
#line 4530 "poet_yacc.c"
    break;

  case 303: /* @111: %empty  */
#line 423 "poet_yacc.y"
                             {yyval.config=yyvsp[-2].config;}
#line 4536 "poet_yacc.c"
    break;

  case 304: /* @112: %empty  */
#line 423 "poet_yacc.y"
                                                                      {yyval.config=yyvsp[-5].config;}
#line 4542 "poet_yacc.c"
    break;

  case 305: /* switchHelp: switchHelp CASE @111 patternSpec COLON @112 code  */
#line 424 "poet_yacc.y"
           {yyval.ptr = make_sourceVector( yyvsp[-6].ptr, make_inputlist(yyvsp[-3].ptr,yyvsp[0].ptr)); }
#line 4548 "poet_yacc.c"
    break;

  case 306: /* @113: %empty  */
#line 425 "poet_yacc.y"
            {yyval.config=yyvsp[-1].config;}
#line 4554 "poet_yacc.c"
    break;

  case 307: /* @114: %empty  */
#line 425 "poet_yacc.y"
                                                      {yyval.config=yyvsp[-4].config;}
#line 4560 "poet_yacc.c"
    break;

  case 308: /* switchHelp: CASE @113 patternSpec COLON @114 code  */
#line 425 "poet_yacc.y"
                                                                                   { yyval.ptr = make_inputlist(yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 4566 "poet_yacc.c"
    break;

  case 309: /* @115: %empty  */
#line 426 "poet_yacc.y"
                                {yyval.config=yyvsp[-3].config;}
#line 4572 "poet_yacc.c"
    break;

  case 310: /* switchHelp: switchHelp DEFAULT COLON @115 code  */
#line 427 "poet_yacc.y"
           {yyval.ptr = make_sourceVector( yyvsp[-4].ptr, make_inputlist(make_any(),yyvsp[0].ptr)); }
#line 4578 "poet_yacc.c"
    break;

  case 311: /* code23: code2  */
#line 429 "poet_yacc.y"
               { yyval.ptr = yyvsp[0].ptr; }
#line 4584 "poet_yacc.c"
    break;

  case 312: /* code23: code3  */
#line 430 "poet_yacc.y"
             { yyval.ptr = yyvsp[0].ptr; }
#line 4590 "poet_yacc.c"
    break;

  case 313: /* @116: %empty  */
#line 432 "poet_yacc.y"
                    {yyval.config=yyvsp[-2].config;}
#line 4596 "poet_yacc.c"
    break;

  case 314: /* code2: code2 COMMA @116 code3  */
#line 432 "poet_yacc.y"
                                                 {yyval.ptr = make_sourceVector(yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 4602 "poet_yacc.c"
    break;

  case 315: /* @117: %empty  */
#line 433 "poet_yacc.y"
                   {yyval.config=yyvsp[-2].config;}
#line 4608 "poet_yacc.c"
    break;

  case 316: /* code2: code3 COMMA @117 code3  */
#line 433 "poet_yacc.y"
                                                { yyval.ptr = make_sourceVector2(yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 4614 "poet_yacc.c"
    break;

  case 317: /* code3: CONTINUE  */
#line 436 "poet_yacc.y"
                { yyval.ptr=make_dummyOperator(POET_OP_CONTINUE); }
#line 4620 "poet_yacc.c"
    break;

  case 318: /* code3: BREAK  */
#line 437 "poet_yacc.y"
             { yyval.ptr=make_dummyOperator(POET_OP_BREAK); }
#line 4626 "poet_yacc.c"
    break;

  case 319: /* @118: %empty  */
#line 438 "poet_yacc.y"
              {yyval.config=yyvsp[-1].config;}
#line 4632 "poet_yacc.c"
    break;

  case 320: /* code3: RETURN @118 code4  */
#line 438 "poet_yacc.y"
                                           { yyval.ptr=make_sourceUop(POET_OP_RETURN, yyvsp[0].ptr); }
#line 4638 "poet_yacc.c"
    break;

  case 321: /* @119: %empty  */
#line 439 "poet_yacc.y"
             {yyval.config=yyvsp[-1].config;}
#line 4644 "poet_yacc.c"
    break;

  case 322: /* code3: ERROR @119 codeUnit  */
#line 439 "poet_yacc.y"
                                             { yyval.ptr = make_sourceUop(POET_OP_ERROR,yyvsp[0].ptr); }
#line 4650 "poet_yacc.c"
    break;

  case 323: /* @120: %empty  */
#line 440 "poet_yacc.y"
              {yyval.config=yyvsp[-1].config;}
#line 4656 "poet_yacc.c"
    break;

  case 324: /* code3: ASSERT @120 codeUnit  */
#line 440 "poet_yacc.y"
                                              { yyval.ptr = make_sourceUop(POET_OP_ASSERT,yyvsp[0].ptr); }
#line 4662 "poet_yacc.c"
    break;

  case 325: /* @121: %empty  */
#line 441 "poet_yacc.y"
             {yyval.config=yyvsp[-1].config;}
#line 4668 "poet_yacc.c"
    break;

  case 326: /* code3: PRINT @121 codeUnit  */
#line 441 "poet_yacc.y"
                                             { yyval.ptr=make_sourceUop(POET_OP_PRINT,yyvsp[0].ptr); }
#line 4674 "poet_yacc.c"
    break;

  case 327: /* code3: code4  */
#line 442 "poet_yacc.y"
             { yyval.ptr = yyvsp[0].ptr; }
#line 4680 "poet_yacc.c"
    break;

  case 328: /* code4: code5  */
#line 444 "poet_yacc.y"
              { yyval.ptr = yyvsp[0].ptr; }
#line 4686 "poet_yacc.c"
    break;

  case 329: /* @122: %empty  */
#line 445 "poet_yacc.y"
                    {yyval.config=yyvsp[-2].config;}
#line 4692 "poet_yacc.c"
    break;

  case 330: /* code4: code8 ASSIGN @122 code4  */
#line 445 "poet_yacc.y"
                                                 { yyval.ptr=make_sourceAssign(yyvsp[-3].ptr, yyvsp[0].ptr); }
#line 4698 "poet_yacc.c"
    break;

  case 331: /* @123: %empty  */
#line 446 "poet_yacc.y"
                   {yyval.config=yyvsp[-2].config;}
#line 4704 "poet_yacc.c"
    break;

  case 332: /* code4: code8 ARROW @123 parseElem  */
#line 446 "poet_yacc.y"
                                                    { yyval.ptr = make_codeMatch(yyvsp[-3].ptr, yyvsp[0].ptr); }
#line 4710 "poet_yacc.c"
    break;

  case 333: /* @124: %empty  */
#line 447 "poet_yacc.y"
                         {yyval.config=yyvsp[-2].config;}
#line 4716 "poet_yacc.c"
    break;

  case 334: /* code4: code8 PLUS_ASSIGN @124 code5  */
#line 448 "poet_yacc.y"
           { yyval.ptr=make_sourceAssign(yyvsp[-3].ptr, make_sourceBop(POET_OP_PLUS, yyvsp[-3].ptr,yyvsp[0].ptr)); }
#line 4722 "poet_yacc.c"
    break;

  case 335: /* @125: %empty  */
#line 449 "poet_yacc.y"
                          {yyval.config=yyvsp[-2].config;}
#line 4728 "poet_yacc.c"
    break;

  case 336: /* code4: code8 MINUS_ASSIGN @125 code5  */
#line 450 "poet_yacc.y"
           { yyval.ptr=make_sourceAssign(yyvsp[-3].ptr, make_sourceBop(POET_OP_MINUS, yyvsp[-3].ptr,yyvsp[0].ptr)); }
#line 4734 "poet_yacc.c"
    break;

  case 337: /* @126: %empty  */
#line 451 "poet_yacc.y"
                         {yyval.config=yyvsp[-2].config;}
#line 4740 "poet_yacc.c"
    break;

  case 338: /* code4: code8 MULT_ASSIGN @126 code5  */
#line 452 "poet_yacc.y"
           { yyval.ptr=make_sourceAssign(yyvsp[-3].ptr, make_sourceBop(POET_OP_MULT, yyvsp[-3].ptr,yyvsp[0].ptr)); }
#line 4746 "poet_yacc.c"
    break;

  case 339: /* @127: %empty  */
#line 453 "poet_yacc.y"
                           {yyval.config=yyvsp[-2].config;}
#line 4752 "poet_yacc.c"
    break;

  case 340: /* code4: code8 DIVIDE_ASSIGN @127 code5  */
#line 454 "poet_yacc.y"
           { yyval.ptr=make_sourceAssign(yyvsp[-3].ptr, make_sourceBop(POET_OP_DIVIDE, yyvsp[-3].ptr,yyvsp[0].ptr)); }
#line 4758 "poet_yacc.c"
    break;

  case 341: /* @128: %empty  */
#line 455 "poet_yacc.y"
                        {yyval.config=yyvsp[-2].config;}
#line 4764 "poet_yacc.c"
    break;

  case 342: /* code4: code8 MOD_ASSIGN @128 code5  */
#line 456 "poet_yacc.y"
           { yyval.ptr=make_sourceAssign(yyvsp[-3].ptr, make_sourceBop(POET_OP_MOD, yyvsp[-3].ptr,yyvsp[0].ptr)); }
#line 4770 "poet_yacc.c"
    break;

  case 343: /* @129: %empty  */
#line 457 "poet_yacc.y"
                    {yyval.config=yyvsp[-2].config;}
#line 4776 "poet_yacc.c"
    break;

  case 344: /* code4: code8 DARROW @129 parseElem  */
#line 457 "poet_yacc.y"
                                                     { yyval.ptr = make_codeMatchQ(yyvsp[-3].ptr, yyvsp[0].ptr); }
#line 4782 "poet_yacc.c"
    break;

  case 345: /* @130: %empty  */
#line 458 "poet_yacc.y"
                      {yyval.config=yyvsp[-2].config;}
#line 4788 "poet_yacc.c"
    break;

  case 346: /* @131: %empty  */
#line 458 "poet_yacc.y"
                                                         {yyval.config=yyvsp[-5].config;}
#line 4794 "poet_yacc.c"
    break;

  case 347: /* code4: code5 QUESTION @130 code6 COLON @131 code4  */
#line 459 "poet_yacc.y"
        { yyval.ptr = make_ifElse( yyvsp[-6].ptr, yyvsp[-3].ptr, yyvsp[0].ptr); }
#line 4800 "poet_yacc.c"
    break;

  case 348: /* @132: %empty  */
#line 462 "poet_yacc.y"
                 {yyval.config=yyvsp[-2].config;}
#line 4806 "poet_yacc.c"
    break;

  case 349: /* code5: code5 AND @132 code5  */
#line 462 "poet_yacc.y"
                                              { yyval.ptr = make_sourceBop(POET_OP_AND,  yyvsp[-3].ptr, yyvsp[0].ptr); }
#line 4812 "poet_yacc.c"
    break;

  case 350: /* @133: %empty  */
#line 463 "poet_yacc.y"
                {yyval.config=yyvsp[-2].config;}
#line 4818 "poet_yacc.c"
    break;

  case 351: /* code5: code5 OR @133 code5  */
#line 463 "poet_yacc.y"
                                             { yyval.ptr = make_sourceBop(POET_OP_OR,   yyvsp[-3].ptr, yyvsp[0].ptr); }
#line 4824 "poet_yacc.c"
    break;

  case 352: /* @134: %empty  */
#line 464 "poet_yacc.y"
           {yyval.config=yyvsp[-1].config;}
#line 4830 "poet_yacc.c"
    break;

  case 353: /* code5: NOT @134 code6  */
#line 464 "poet_yacc.y"
                                        { yyval.ptr = make_sourceUop(POET_OP_NOT, yyvsp[0].ptr); }
#line 4836 "poet_yacc.c"
    break;

  case 354: /* @135: %empty  */
#line 465 "poet_yacc.y"
                {yyval.config=yyvsp[-2].config;}
#line 4842 "poet_yacc.c"
    break;

  case 355: /* code5: code6 LT @135 code6  */
#line 465 "poet_yacc.y"
                                             { yyval.ptr = make_sourceBop(POET_OP_LT, yyvsp[-3].ptr, yyvsp[0].ptr); }
#line 4848 "poet_yacc.c"
    break;

  case 356: /* @136: %empty  */
#line 466 "poet_yacc.y"
                {yyval.config=yyvsp[-2].config;}
#line 4854 "poet_yacc.c"
    break;

  case 357: /* code5: code6 LE @136 code6  */
#line 466 "poet_yacc.y"
                                             { yyval.ptr = make_sourceBop(POET_OP_LE, yyvsp[-3].ptr, yyvsp[0].ptr); }
#line 4860 "poet_yacc.c"
    break;

  case 358: /* @137: %empty  */
#line 467 "poet_yacc.y"
                {yyval.config=yyvsp[-2].config;}
#line 4866 "poet_yacc.c"
    break;

  case 359: /* code5: code6 EQ @137 code6  */
#line 467 "poet_yacc.y"
                                             { yyval.ptr = make_sourceBop(POET_OP_EQ, yyvsp[-3].ptr, yyvsp[0].ptr); }
#line 4872 "poet_yacc.c"
    break;

  case 360: /* @138: %empty  */
#line 468 "poet_yacc.y"
                {yyval.config=yyvsp[-2].config;}
#line 4878 "poet_yacc.c"
    break;

  case 361: /* code5: code6 GT @138 code6  */
#line 469 "poet_yacc.y"
           { yyval.ptr = make_sourceBop(POET_OP_GT,   yyvsp[-3].ptr, yyvsp[0].ptr); }
#line 4884 "poet_yacc.c"
    break;

  case 362: /* @139: %empty  */
#line 470 "poet_yacc.y"
                {yyval.config=yyvsp[-2].config;}
#line 4890 "poet_yacc.c"
    break;

  case 363: /* code5: code6 GE @139 code6  */
#line 471 "poet_yacc.y"
           { yyval.ptr = make_sourceBop(POET_OP_GE,   yyvsp[-3].ptr, yyvsp[0].ptr); }
#line 4896 "poet_yacc.c"
    break;

  case 364: /* @140: %empty  */
#line 472 "poet_yacc.y"
                {yyval.config=yyvsp[-2].config;}
#line 4902 "poet_yacc.c"
    break;

  case 365: /* code5: code6 NE @140 code6  */
#line 473 "poet_yacc.y"
           { yyval.ptr = make_sourceBop(POET_OP_NE,   yyvsp[-3].ptr, yyvsp[0].ptr); }
#line 4908 "poet_yacc.c"
    break;

  case 366: /* @141: %empty  */
#line 474 "poet_yacc.y"
                   {yyval.config=yyvsp[-2].config;}
#line 4914 "poet_yacc.c"
    break;

  case 367: /* code5: code6 COLON @141 patternSpec  */
#line 474 "poet_yacc.y"
                                                      { yyval.ptr = make_sourceBop(POET_OP_ASTMATCH, yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 4920 "poet_yacc.c"
    break;

  case 368: /* code5: code6  */
#line 475 "poet_yacc.y"
             { yyval.ptr = yyvsp[0].ptr; }
#line 4926 "poet_yacc.c"
    break;

  case 369: /* code6: code7  */
#line 477 "poet_yacc.y"
              { yyval.ptr = yyvsp[0].ptr; }
#line 4932 "poet_yacc.c"
    break;

  case 370: /* @142: %empty  */
#line 478 "poet_yacc.y"
                  {yyval.config=yyvsp[-2].config;}
#line 4938 "poet_yacc.c"
    break;

  case 371: /* code6: code6 PLUS @142 code6  */
#line 479 "poet_yacc.y"
           { yyval.ptr=make_sourceBop(POET_OP_PLUS, yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 4944 "poet_yacc.c"
    break;

  case 372: /* @143: %empty  */
#line 480 "poet_yacc.y"
                   {yyval.config=yyvsp[-2].config;}
#line 4950 "poet_yacc.c"
    break;

  case 373: /* code6: code6 MINUS @143 code6  */
#line 481 "poet_yacc.y"
           { yyval.ptr = make_sourceBop(POET_OP_MINUS,  yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 4956 "poet_yacc.c"
    break;

  case 374: /* @144: %empty  */
#line 482 "poet_yacc.y"
                      {yyval.config=yyvsp[-2].config;}
#line 4962 "poet_yacc.c"
    break;

  case 375: /* code6: code6 MULTIPLY @144 code6  */
#line 483 "poet_yacc.y"
           { yyval.ptr = make_sourceBop(POET_OP_MULT,  yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 4968 "poet_yacc.c"
    break;

  case 376: /* @145: %empty  */
#line 484 "poet_yacc.y"
                        {yyval.config=yyvsp[-2].config;}
#line 4974 "poet_yacc.c"
    break;

  case 377: /* code6: code6 STR_CONCAT @145 code6  */
#line 485 "poet_yacc.y"
           { yyval.ptr = make_sourceBop(POET_OP_CONCAT, yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 4980 "poet_yacc.c"
    break;

  case 378: /* @146: %empty  */
#line 486 "poet_yacc.y"
                    {yyval.config=yyvsp[-2].config;}
#line 4986 "poet_yacc.c"
    break;

  case 379: /* code6: code6 DIVIDE @146 code6  */
#line 487 "poet_yacc.y"
           { yyval.ptr = make_sourceBop(POET_OP_DIVIDE,  yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 4992 "poet_yacc.c"
    break;

  case 380: /* @147: %empty  */
#line 488 "poet_yacc.y"
                 {yyval.config=yyvsp[-2].config;}
#line 4998 "poet_yacc.c"
    break;

  case 381: /* code6: code6 MOD @147 code6  */
#line 489 "poet_yacc.y"
           { yyval.ptr = make_sourceBop(POET_OP_MOD,  yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 5004 "poet_yacc.c"
    break;

  case 382: /* @148: %empty  */
#line 490 "poet_yacc.y"
                    {yyval.config=yyvsp[-2].config;}
#line 5010 "poet_yacc.c"
    break;

  case 383: /* code6: code6 DCOLON @148 code6  */
#line 490 "poet_yacc.y"
                                                 { yyval.ptr = make_sourceBop(POET_OP_CONS,yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 5016 "poet_yacc.c"
    break;

  case 384: /* @149: %empty  */
#line 491 "poet_yacc.y"
             {yyval.config=yyvsp[-1].config;}
#line 5022 "poet_yacc.c"
    break;

  case 385: /* code6: MINUS @149 code6  */
#line 491 "poet_yacc.y"
                                          { yyval.ptr = make_sourceUop(POET_OP_UMINUS,yyvsp[0].ptr); }
#line 5028 "poet_yacc.c"
    break;

  case 386: /* @150: %empty  */
#line 493 "poet_yacc.y"
               {yyval.config=yyvsp[-1].config;}
#line 5034 "poet_yacc.c"
    break;

  case 387: /* code7: code8 @150 code7Help  */
#line 494 "poet_yacc.y"
            { if (yyvsp[0].ptr==0) yyval.ptr=yyvsp[-2].ptr; else yyval.ptr = make_xformList(yyvsp[-2].ptr, yyvsp[0].ptr); }
#line 5040 "poet_yacc.c"
    break;

  case 388: /* @151: %empty  */
#line 496 "poet_yacc.y"
                 {yyval.config=yyvsp[-1].config; }
#line 5046 "poet_yacc.c"
    break;

  case 389: /* code7Help: code8 @151 code7Help2  */
#line 496 "poet_yacc.y"
                                                    { yyval.ptr =make_xformList(yyvsp[-2].ptr,yyvsp[0].ptr);}
#line 5052 "poet_yacc.c"
    break;

  case 390: /* code7Help: %empty  */
#line 497 "poet_yacc.y"
        { yyval.ptr=0; }
#line 5058 "poet_yacc.c"
    break;

  case 391: /* @152: %empty  */
#line 498 "poet_yacc.y"
                   {yyval.config=yyvsp[-1].config; }
#line 5064 "poet_yacc.c"
    break;

  case 392: /* code7Help2: code8 @152 code7Help2  */
#line 498 "poet_yacc.y"
                                                      { yyval.ptr =make_xformList(yyvsp[-2].ptr,yyvsp[0].ptr);}
#line 5070 "poet_yacc.c"
    break;

  case 393: /* code7Help2: %empty  */
#line 499 "poet_yacc.y"
        { yyval.ptr=0; }
#line 5076 "poet_yacc.c"
    break;

  case 394: /* @153: %empty  */
#line 501 "poet_yacc.y"
                   {yyval.config=yyvsp[-2].config;}
#line 5082 "poet_yacc.c"
    break;

  case 395: /* @154: %empty  */
#line 501 "poet_yacc.y"
                                                      {yyval.config=yyvsp[-5].config;}
#line 5088 "poet_yacc.c"
    break;

  case 396: /* @155: %empty  */
#line 501 "poet_yacc.y"
                                                                                   {yyval.config=yyvsp[-7].config;}
#line 5094 "poet_yacc.c"
    break;

  case 397: /* code8: REPLACE LP @153 code5 COMMA @154 code5 @155 paramRHS  */
#line 502 "poet_yacc.y"
         { yyval.ptr=(yyvsp[0].ptr==0)? make_sourceBop(POET_OP_REPLACE,yyvsp[-5].ptr,yyvsp[-2].ptr) 
                       : make_sourceTop(POET_OP_REPLACE,yyvsp[-5].ptr,yyvsp[-2].ptr,yyvsp[0].ptr); }
#line 5101 "poet_yacc.c"
    break;

  case 398: /* @156: %empty  */
#line 504 "poet_yacc.y"
                {yyval.config=yyvsp[-2].config;}
#line 5107 "poet_yacc.c"
    break;

  case 399: /* @157: %empty  */
#line 504 "poet_yacc.y"
                                             {yyval.config=yyvsp[-4].config;}
#line 5113 "poet_yacc.c"
    break;

  case 400: /* code8: TRACE LP @156 code5 @157 paramRHS  */
#line 505 "poet_yacc.y"
         { yyval.ptr=(yyvsp[0].ptr==0)? make_sourceUop(POET_OP_TRACE,yyvsp[-2].ptr)
                      : make_sourceBop(POET_OP_TRACE,yyvsp[-2].ptr,yyvsp[0].ptr); }
#line 5120 "poet_yacc.c"
    break;

  case 401: /* @158: %empty  */
#line 507 "poet_yacc.y"
                  {yyval.config=yyvsp[-2].config;}
#line 5126 "poet_yacc.c"
    break;

  case 402: /* @159: %empty  */
#line 507 "poet_yacc.y"
                                                     {yyval.config=yyvsp[-5].config;}
#line 5132 "poet_yacc.c"
    break;

  case 403: /* code8: PERMUTE LP @158 code5 COMMA @159 code5 RP  */
#line 508 "poet_yacc.y"
         { yyval.ptr=make_sourceBop(POET_OP_PERMUTE,yyvsp[-4].ptr,yyvsp[-1].ptr); }
#line 5138 "poet_yacc.c"
    break;

  case 404: /* @160: %empty  */
#line 509 "poet_yacc.y"
                    {yyval.config=yyvsp[-2].config;}
#line 5144 "poet_yacc.c"
    break;

  case 405: /* @161: %empty  */
#line 509 "poet_yacc.y"
                                                       {yyval.config=yyvsp[-5].config;}
#line 5150 "poet_yacc.c"
    break;

  case 406: /* @162: %empty  */
#line 509 "poet_yacc.y"
                                                                                          {yyval.config=yyvsp[-8].config;}
#line 5156 "poet_yacc.c"
    break;

  case 407: /* code8: DUPLICATE LP @160 code5 COMMA @161 code5 COMMA @162 code5 RP  */
#line 510 "poet_yacc.y"
         { yyval.ptr=make_sourceTop(POET_OP_DUPLICATE,yyvsp[-7].ptr,yyvsp[-4].ptr,yyvsp[-1].ptr); }
#line 5162 "poet_yacc.c"
    break;

  case 408: /* @163: %empty  */
#line 511 "poet_yacc.y"
            {yyval.config=yyvsp[-1].config;}
#line 5168 "poet_yacc.c"
    break;

  case 409: /* code8: COPY @163 codeUnit  */
#line 511 "poet_yacc.y"
                                            { yyval.ptr = make_sourceUop(POET_OP_COPY, yyvsp[0].ptr); }
#line 5174 "poet_yacc.c"
    break;

  case 410: /* @164: %empty  */
#line 512 "poet_yacc.y"
                {yyval.config=yyvsp[-2].config;}
#line 5180 "poet_yacc.c"
    break;

  case 411: /* @165: %empty  */
#line 513 "poet_yacc.y"
           {yyval.config=yyvsp[-4].config;yyval.ptr=yyvsp[0].ptr; }
#line 5186 "poet_yacc.c"
    break;

  case 412: /* code8: ERASE LP @164 code5 @165 eraseRHS  */
#line 514 "poet_yacc.y"
         {yyval.ptr = make_sourceBop(POET_OP_ERASE,yyvsp[-2].ptr,yyvsp[0].ptr); }
#line 5192 "poet_yacc.c"
    break;

  case 413: /* @166: %empty  */
#line 515 "poet_yacc.y"
                {yyval.config=yyvsp[-2].config;}
#line 5198 "poet_yacc.c"
    break;

  case 414: /* code8: DELAY LB @166 code RB  */
#line 515 "poet_yacc.y"
                                               { yyval.ptr = make_sourceUop(POET_OP_DELAY, yyvsp[-1].ptr); }
#line 5204 "poet_yacc.c"
    break;

  case 415: /* @167: %empty  */
#line 516 "poet_yacc.y"
                 {yyval.config=yyvsp[-2].config;}
#line 5210 "poet_yacc.c"
    break;

  case 416: /* @168: %empty  */
#line 516 "poet_yacc.y"
                                                    {yyval.config=yyvsp[-5].config;}
#line 5216 "poet_yacc.c"
    break;

  case 417: /* code8: INSERT LP @167 code5 COMMA @168 code5 RP  */
#line 517 "poet_yacc.y"
           {  yyval.ptr=make_sourceBop(POET_OP_INSERT, yyvsp[-4].ptr,yyvsp[-1].ptr); }
#line 5222 "poet_yacc.c"
    break;

  case 418: /* @169: %empty  */
#line 518 "poet_yacc.y"
                            {yyval.config=yyvsp[-3].config;}
#line 5228 "poet_yacc.c"
    break;

  case 419: /* code8: DEBUG debugConfig LB @169 code RB  */
#line 519 "poet_yacc.y"
         { yyval.ptr = make_sourceBop(POET_OP_DEBUG,yyvsp[-4].ptr,yyvsp[-1].ptr); }
#line 5234 "poet_yacc.c"
    break;

  case 420: /* @170: %empty  */
#line 520 "poet_yacc.y"
                {yyval.config=yyvsp[-2].config;}
#line 5240 "poet_yacc.c"
    break;

  case 421: /* code8: APPLY LB @170 code RB  */
#line 520 "poet_yacc.y"
                                               { yyval.ptr = make_sourceUop(POET_OP_APPLY, yyvsp[-1].ptr); }
#line 5246 "poet_yacc.c"
    break;

  case 422: /* @171: %empty  */
#line 521 "poet_yacc.y"
               {yyval.config=yyvsp[-1].config;}
#line 5252 "poet_yacc.c"
    break;

  case 423: /* code8: REBUILD @171 codeUnit  */
#line 521 "poet_yacc.y"
                                               { yyval.ptr = make_sourceUop(POET_OP_REBUILD,yyvsp[0].ptr); }
#line 5258 "poet_yacc.c"
    break;

  case 424: /* @172: %empty  */
#line 522 "poet_yacc.y"
                {yyval.config=yyvsp[-1].config;}
#line 5264 "poet_yacc.c"
    break;

  case 425: /* code8: RESTORE @172 codeUnit  */
#line 522 "poet_yacc.y"
                                                 { yyval.ptr = make_sourceUop(POET_OP_RESTORE,yyvsp[0].ptr); }
#line 5270 "poet_yacc.c"
    break;

  case 426: /* @173: %empty  */
#line 523 "poet_yacc.y"
             {yyval.config=yyvsp[-1].config;}
#line 5276 "poet_yacc.c"
    break;

  case 427: /* code8: SAVE @173 codeUnit  */
#line 523 "poet_yacc.y"
                                              { yyval.ptr = make_sourceUop(POET_OP_SAVE,yyvsp[0].ptr); }
#line 5282 "poet_yacc.c"
    break;

  case 428: /* @174: %empty  */
#line 524 "poet_yacc.y"
                {yyval.config=yyvsp[-2].config;}
#line 5288 "poet_yacc.c"
    break;

  case 429: /* @175: %empty  */
#line 524 "poet_yacc.y"
                                                   {yyval.config=yyvsp[-5].config;}
#line 5294 "poet_yacc.c"
    break;

  case 430: /* code8: SPLIT LP @174 code5 COMMA @175 code5 RP  */
#line 525 "poet_yacc.y"
         { yyval.ptr = make_sourceBop(POET_OP_SPLIT, yyvsp[-4].ptr,yyvsp[-1].ptr); }
#line 5300 "poet_yacc.c"
    break;

  case 431: /* code8: codeUnit DOT3  */
#line 526 "poet_yacc.y"
                     {yyval.ptr = make_typeUop(TYPE_LIST, yyvsp[-1].ptr); }
#line 5306 "poet_yacc.c"
    break;

  case 432: /* @176: %empty  */
#line 527 "poet_yacc.y"
                     {yyval.config=yyvsp[-2].config;}
#line 5312 "poet_yacc.c"
    break;

  case 433: /* code8: codeUnit DOT2 @176 codeUnit  */
#line 528 "poet_yacc.y"
           {yyval.ptr = make_sourceBop(POET_OP_RANGE, yyvsp[-3].ptr,yyvsp[0].ptr);}
#line 5318 "poet_yacc.c"
    break;

  case 434: /* code8: RANGE LP codeUnit COMMA codeUnit RP  */
#line 530 "poet_yacc.y"
           {yyval.ptr = make_sourceBop(POET_OP_RANGE, yyvsp[-3].ptr,yyvsp[0].ptr);}
#line 5324 "poet_yacc.c"
    break;

  case 435: /* code8: code9  */
#line 531 "poet_yacc.y"
             { yyval.ptr = yyvsp[0].ptr; }
#line 5330 "poet_yacc.c"
    break;

  case 436: /* paramRHS: RP  */
#line 532 "poet_yacc.y"
              { yyval.ptr = 0; }
#line 5336 "poet_yacc.c"
    break;

  case 437: /* @177: %empty  */
#line 532 "poet_yacc.y"
                                      {yyval.config=yyvsp[-1].config;}
#line 5342 "poet_yacc.c"
    break;

  case 438: /* paramRHS: COMMA @177 code5 RP  */
#line 532 "poet_yacc.y"
                                                                      { yyval.ptr = yyvsp[-1].ptr; }
#line 5348 "poet_yacc.c"
    break;

  case 439: /* @178: %empty  */
#line 534 "poet_yacc.y"
                 {yyval.config=yyvsp[-1].config;}
#line 5354 "poet_yacc.c"
    break;

  case 440: /* eraseRHS: COMMA @178 code5 RP  */
#line 534 "poet_yacc.y"
                                                  { yyval.ptr = yyvsp[-1].ptr; }
#line 5360 "poet_yacc.c"
    break;

  case 441: /* eraseRHS: RP  */
#line 535 "poet_yacc.y"
              { yyval.ptr = yyvsp[-1].ptr; }
#line 5366 "poet_yacc.c"
    break;

  case 442: /* debugConfig: %empty  */
#line 537 "poet_yacc.y"
              {yyval.ptr = make_Iconst1(1); }
#line 5372 "poet_yacc.c"
    break;

  case 443: /* debugConfig: LBR ICONST RBR  */
#line 538 "poet_yacc.y"
                      { yyval.ptr = yyvsp[-1].ptr; }
#line 5378 "poet_yacc.c"
    break;

  case 444: /* inputBase: %empty  */
#line 540 "poet_yacc.y"
            { yyval.ptr = 0; }
#line 5384 "poet_yacc.c"
    break;

  case 445: /* inputBase: inputBase INPUT_ENDL  */
#line 541 "poet_yacc.y"
                            { yyval.ptr=make_inputlist(yyvsp[-1].ptr,yyvsp[0].ptr); }
#line 5390 "poet_yacc.c"
    break;

  case 446: /* @179: %empty  */
#line 542 "poet_yacc.y"
                       {yyval.config=TRACE_VAR;}
#line 5396 "poet_yacc.c"
    break;

  case 447: /* inputBase: inputBase ARROW @179 parseElem  */
#line 542 "poet_yacc.y"
                                                        { yyval.ptr = make_annot_single(yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 5402 "poet_yacc.c"
    break;

  case 448: /* @180: %empty  */
#line 543 "poet_yacc.y"
                           {yyval.config=TRACE_VAR; }
#line 5408 "poet_yacc.c"
    break;

  case 449: /* inputBase: inputBase LBEGIN LP @180 parseElem RP  */
#line 544 "poet_yacc.y"
        { yyval.ptr = make_annot_lbegin(yyvsp[-5].ptr,yyvsp[-1].ptr); }
#line 5414 "poet_yacc.c"
    break;

  case 450: /* @181: %empty  */
#line 545 "poet_yacc.y"
                           {yyval.config=TRACE_VAR; }
#line 5420 "poet_yacc.c"
    break;

  case 451: /* inputBase: inputBase RBEGIN LP @181 parseElem RP  */
#line 546 "poet_yacc.y"
       { yyval.ptr = make_inputlist(yyvsp[-5].ptr,make_sourceUop(POET_OP_ANNOT,yyvsp[-1].ptr)); }
#line 5426 "poet_yacc.c"
    break;

  case 452: /* inputBase: inputBase ICONST  */
#line 547 "poet_yacc.y"
                        { yyval.ptr = make_inputlist(yyvsp[-1].ptr, yyvsp[0].ptr); }
#line 5432 "poet_yacc.c"
    break;

  case 453: /* inputBase: inputBase FCONST  */
#line 548 "poet_yacc.y"
                        { yyval.ptr = make_inputlist(yyvsp[-1].ptr, yyvsp[0].ptr); }
#line 5438 "poet_yacc.c"
    break;

  case 454: /* inputBase: inputBase SOURCE  */
#line 549 "poet_yacc.y"
                        { yyval.ptr = make_inputlist(yyvsp[-1].ptr, yyvsp[0].ptr); }
#line 5444 "poet_yacc.c"
    break;

  case 455: /* inputBase: inputBase INPUT_CONT  */
#line 550 "poet_yacc.y"
                            { yyval.ptr = make_inputlist(yyvsp[-1].ptr, yyvsp[0].ptr); }
#line 5450 "poet_yacc.c"
    break;

  case 456: /* inputBase: inputBase ID  */
#line 551 "poet_yacc.y"
                    { yyval.ptr = make_inputlist(yyvsp[-1].ptr,make_varRef(yyvsp[0].ptr,GLOBAL_VAR)); }
#line 5456 "poet_yacc.c"
    break;

  case 457: /* @182: %empty  */
#line 554 "poet_yacc.y"
           {yyval.config=yyvsp[-1].config;}
#line 5462 "poet_yacc.c"
    break;

  case 458: /* code9: CAR @182 codeUnit  */
#line 554 "poet_yacc.y"
                                           { yyval.ptr = make_sourceUop(POET_OP_CAR, yyvsp[0].ptr); }
#line 5468 "poet_yacc.c"
    break;

  case 459: /* @183: %empty  */
#line 555 "poet_yacc.y"
           {yyval.config=yyvsp[-1].config;}
#line 5474 "poet_yacc.c"
    break;

  case 460: /* code9: CDR @183 codeUnit  */
#line 555 "poet_yacc.y"
                                           { yyval.ptr = make_sourceUop(POET_OP_CDR, yyvsp[0].ptr); }
#line 5480 "poet_yacc.c"
    break;

  case 461: /* @184: %empty  */
#line 556 "poet_yacc.y"
           {yyval.config=yyvsp[-1].config;}
#line 5486 "poet_yacc.c"
    break;

  case 462: /* code9: LEN @184 codeUnit  */
#line 556 "poet_yacc.y"
                                           { yyval.ptr = make_sourceUop(POET_OP_LEN, yyvsp[0].ptr); }
#line 5492 "poet_yacc.c"
    break;

  case 463: /* @185: %empty  */
#line 557 "poet_yacc.y"
           {yyval.config=yyvsp[-1].config;}
#line 5498 "poet_yacc.c"
    break;

  case 464: /* code9: INT @185 codeUnit  */
#line 557 "poet_yacc.y"
                                           { yyval.ptr = make_sourceUop(TYPE_INT, yyvsp[0].ptr); }
#line 5504 "poet_yacc.c"
    break;

  case 465: /* @186: %empty  */
#line 558 "poet_yacc.y"
             {yyval.config=ASSIGN_VAR;}
#line 5510 "poet_yacc.c"
    break;

  case 466: /* code9: CLEAR @186 codeUnit  */
#line 558 "poet_yacc.y"
                                              { yyval.ptr = make_sourceUop(POET_OP_CLEAR, yyvsp[0].ptr); }
#line 5516 "poet_yacc.c"
    break;

  case 467: /* code9: varInvoke  */
#line 559 "poet_yacc.y"
                 { yyval.ptr=yyvsp[0].ptr; }
#line 5522 "poet_yacc.c"
    break;

  case 468: /* @187: %empty  */
#line 562 "poet_yacc.y"
          {yyval.config=yyvsp[-1].config;}
#line 5528 "poet_yacc.c"
    break;

  case 469: /* codeUnit: LP @187 code RP  */
#line 562 "poet_yacc.y"
                                         { yyval.ptr=yyvsp[-1].ptr; }
#line 5534 "poet_yacc.c"
    break;

  case 470: /* codeUnit: LP RP  */
#line 563 "poet_yacc.y"
             { yyval.ptr=make_empty(); }
#line 5540 "poet_yacc.c"
    break;

  case 471: /* codeUnit: constant  */
#line 564 "poet_yacc.y"
                { yyval.ptr=yyvsp[0].ptr; }
#line 5546 "poet_yacc.c"
    break;

  case 472: /* codeUnit: ANY  */
#line 565 "poet_yacc.y"
           { yyval.ptr = make_any(); }
#line 5552 "poet_yacc.c"
    break;

  case 473: /* codeUnit: varRef  */
#line 566 "poet_yacc.y"
              { yyval=yyvsp[0]; }
#line 5558 "poet_yacc.c"
    break;

  case 474: /* codeUnit: map  */
#line 567 "poet_yacc.y"
           {yyval=yyvsp[0]; }
#line 5564 "poet_yacc.c"
    break;

  case 475: /* @188: %empty  */
#line 569 "poet_yacc.y"
                     {yyval.ptr=yyvsp[0].ptr; yyval.config=yyvsp[-1].config; }
#line 5570 "poet_yacc.c"
    break;

  case 476: /* varInvoke: codeUnit @188 varInvoke1  */
#line 569 "poet_yacc.y"
                                                                       { yyval = yyvsp[0]; }
#line 5576 "poet_yacc.c"
    break;

  case 477: /* @189: %empty  */
#line 570 "poet_yacc.y"
                     {yyval.config=yyvsp[-2].config; }
#line 5582 "poet_yacc.c"
    break;

  case 478: /* varInvoke: varInvoke TOR @189 varInvoke  */
#line 570 "poet_yacc.y"
                                                       { yyval.ptr = make_typeTor(yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 5588 "poet_yacc.c"
    break;

  case 479: /* varInvoke1: %empty  */
#line 571 "poet_yacc.y"
             {yyval=yyvsp[0]; }
#line 5594 "poet_yacc.c"
    break;

  case 480: /* @190: %empty  */
#line 572 "poet_yacc.y"
          {yyval.config=yyvsp[-1].config; yyval.ptr=yyvsp[-1].ptr; }
#line 5600 "poet_yacc.c"
    break;

  case 481: /* @191: %empty  */
#line 573 "poet_yacc.y"
          { yyval.ptr = make_tupleAccess(yyvsp[-4].ptr, yyvsp[-1].ptr); yyval.config=yyvsp[-4].config; }
#line 5606 "poet_yacc.c"
    break;

  case 482: /* varInvoke1: LBR @190 configOrSubRef RBR @191 varInvoke1  */
#line 574 "poet_yacc.y"
                 { yyval=yyvsp[0]; }
#line 5612 "poet_yacc.c"
    break;

  case 483: /* varInvoke1: pond  */
#line 575 "poet_yacc.y"
           { yyval=yyvsp[0]; }
#line 5618 "poet_yacc.c"
    break;

  case 484: /* @192: %empty  */
#line 577 "poet_yacc.y"
           {yyval.config=yyvsp[-1].config; }
#line 5624 "poet_yacc.c"
    break;

  case 485: /* pond: POND @192 codeUnit  */
#line 578 "poet_yacc.y"
       { yyval.ptr = make_codeRef(yyvsp[-3].ptr,yyvsp[0].ptr,yyvsp[-3].config); yyval.config=yyvsp[-3].config; }
#line 5630 "poet_yacc.c"
    break;

  case 486: /* @193: %empty  */
#line 580 "poet_yacc.y"
                       {yyval.ptr=yyvsp[0].ptr; yyval.config=yyvsp[-1].config; }
#line 5636 "poet_yacc.c"
    break;

  case 487: /* varInvokeType: varRef @193 varInvokeType1  */
#line 580 "poet_yacc.y"
                                                                             { yyval = yyvsp[0]; }
#line 5642 "poet_yacc.c"
    break;

  case 488: /* varInvokeType1: %empty  */
#line 582 "poet_yacc.y"
                 {yyval=yyvsp[0]; }
#line 5648 "poet_yacc.c"
    break;

  case 489: /* @194: %empty  */
#line 583 "poet_yacc.y"
          {yyval.config=yyvsp[-1].config; yyval.ptr=yyvsp[-1].ptr; }
#line 5654 "poet_yacc.c"
    break;

  case 490: /* varInvokeType1: LBR @194 configRef RBR  */
#line 584 "poet_yacc.y"
          { yyval.ptr = make_tupleAccess(yyvsp[-4].ptr, yyvsp[-1].ptr); yyval.config=yyvsp[-4].config; }
#line 5660 "poet_yacc.c"
    break;

  case 491: /* @195: %empty  */
#line 585 "poet_yacc.y"
           {yyval.config=yyvsp[-1].config; }
#line 5666 "poet_yacc.c"
    break;

  case 492: /* varInvokeType1: POND @195 typeSpec  */
#line 586 "poet_yacc.y"
         { yyval.ptr = make_codeRef(yyvsp[-3].ptr,yyvsp[0].ptr,yyvsp[-3].config);yyval.config=yyvsp[-3].config; }
#line 5672 "poet_yacc.c"
    break;

  case 493: /* @196: %empty  */
#line 588 "poet_yacc.y"
                          {yyval.ptr=yyvsp[0].ptr; yyval.config=yyvsp[-1].config; }
#line 5678 "poet_yacc.c"
    break;

  case 494: /* varInvokePattern: varRef @196 varInvokePattern1  */
#line 588 "poet_yacc.y"
                                                                                   { yyval = yyvsp[0]; }
#line 5684 "poet_yacc.c"
    break;

  case 495: /* varInvokePattern1: %empty  */
#line 589 "poet_yacc.y"
                    {yyval=yyvsp[0]; }
#line 5690 "poet_yacc.c"
    break;

  case 496: /* @197: %empty  */
#line 590 "poet_yacc.y"
          {yyval.config=yyvsp[-1].config; yyval.ptr=yyvsp[-1].ptr; }
#line 5696 "poet_yacc.c"
    break;

  case 497: /* varInvokePattern1: LBR @197 xformConfig RBR  */
#line 591 "poet_yacc.y"
          { yyval.ptr = make_tupleAccess(yyvsp[-4].ptr, yyvsp[-1].ptr); yyval.config=yyvsp[-4].config; }
#line 5702 "poet_yacc.c"
    break;

  case 498: /* @198: %empty  */
#line 592 "poet_yacc.y"
           {yyval.config=yyvsp[-1].config; }
#line 5708 "poet_yacc.c"
    break;

  case 499: /* varInvokePattern1: POND @198 patternSpec  */
#line 593 "poet_yacc.y"
         { yyval.ptr = make_codeRef(yyvsp[-3].ptr,yyvsp[0].ptr,yyvsp[-3].config);yyval.config=yyvsp[-3].config; }
#line 5714 "poet_yacc.c"
    break;

  case 500: /* configOrSubRef: code5  */
#line 595 "poet_yacc.y"
                       {yyval.ptr=yyvsp[0].ptr;}
#line 5720 "poet_yacc.c"
    break;

  case 501: /* configOrSubRef: configRef  */
#line 596 "poet_yacc.y"
                { yyval.ptr = yyvsp[0].ptr; }
#line 5726 "poet_yacc.c"
    break;

  case 502: /* configOrSubRef: selectRef  */
#line 597 "poet_yacc.y"
               {yyval.ptr = yyvsp[0].ptr; }
#line 5732 "poet_yacc.c"
    break;

  case 503: /* @199: %empty  */
#line 599 "poet_yacc.y"
                          {yyval.config=yyvsp[-2].config;}
#line 5738 "poet_yacc.c"
    break;

  case 504: /* selectRef: selectRef TOR @199 selectRef  */
#line 600 "poet_yacc.y"
                    { yyval.ptr = make_typeTor(yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 5744 "poet_yacc.c"
    break;

  case 505: /* selectRef: ID DOT ID  */
#line 601 "poet_yacc.y"
                { yyval.ptr = make_attrAccess(make_varRef(yyvsp[-2].ptr,CODE_OR_XFORM_VAR), yyvsp[0].ptr); }
#line 5750 "poet_yacc.c"
    break;

  case 506: /* @200: %empty  */
#line 604 "poet_yacc.y"
               {yyval.config=yyvsp[-2].config;}
#line 5756 "poet_yacc.c"
    break;

  case 507: /* configRef: ID ASSIGN @200 code5  */
#line 605 "poet_yacc.y"
         { yyval.ptr = make_sourceAssign( make_attrAccess(yyvsp[-4].ptr,yyvsp[-3].ptr),yyvsp[0].ptr); }
#line 5762 "poet_yacc.c"
    break;

  case 508: /* @201: %empty  */
#line 606 "poet_yacc.y"
                         {yyval.ptr=yyvsp[-2].ptr; yyval.config=yyvsp[-2].config;}
#line 5768 "poet_yacc.c"
    break;

  case 509: /* configRef: configRef SEMICOLON @201 configRef  */
#line 607 "poet_yacc.y"
       { yyval.ptr = make_seq(yyvsp[-3].ptr,yyvsp[0].ptr); }
#line 5774 "poet_yacc.c"
    break;

  case 510: /* @202: %empty  */
#line 610 "poet_yacc.y"
               {yyval.config=yyvsp[-2].config;}
#line 5780 "poet_yacc.c"
    break;

  case 511: /* xformConfig: ID ASSIGN @202 typeSpec  */
#line 611 "poet_yacc.y"
         { yyval.ptr = make_sourceAssign( make_attrAccess(yyvsp[-4].ptr,yyvsp[-3].ptr),yyvsp[0].ptr); }
#line 5786 "poet_yacc.c"
    break;

  case 512: /* @203: %empty  */
#line 612 "poet_yacc.y"
                           {yyval.ptr=yyvsp[-2].ptr; yyval.config=yyvsp[-2].config;}
#line 5792 "poet_yacc.c"
    break;

  case 513: /* xformConfig: xformConfig SEMICOLON @203 xformConfig  */
#line 613 "poet_yacc.y"
       { yyval.ptr = make_seq(yyvsp[-3].ptr, yyvsp[0].ptr);}
#line 5798 "poet_yacc.c"
    break;


#line 5802 "poet_yacc.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 614 "poet_yacc.y"

