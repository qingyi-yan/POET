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

#ifndef YY_YY_POET_YACC_H_INCLUDED
# define YY_YY_POET_YACC_H_INCLUDED
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


#endif /* !YY_YY_POET_YACC_H_INCLUDED  */
