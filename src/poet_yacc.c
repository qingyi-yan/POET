/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 26 "poet_yacc.y" /* yacc.c:339  */

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
/*  Yacc parser for reading POET specefications and building AST     */
/*********************************************************************/
#define YYDEBUG 1
#define YYERROR_VERBOSE
#include <poet_config.h>
#include <assert.h>

YaccState yaccState;

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

#line 184 "poet_yacc.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ENDLIST = 258,
    ERROR = 259,
    SYNERROR = 260,
    PARAMETER = 261,
    DEFINE = 262,
    EVAL = 263,
    LBEGIN = 264,
    RBEGIN = 265,
    PRINT = 266,
    INPUT_ENDFILE = 267,
    INPUT_ENDL = 268,
    INPUT_CONT = 269,
    COND = 270,
    ANNOT = 271,
    TO = 272,
    FROM = 273,
    TYPE = 274,
    POETTYPE = 275,
    SYNTAX = 276,
    MESSAGE = 277,
    LTAG = 278,
    RTAG = 279,
    ENDTAG = 280,
    PARS = 281,
    XFORM = 282,
    OUTPUT = 283,
    PARSE = 284,
    LOOKAHEAD = 285,
    MATCH = 286,
    CODE = 287,
    GLOBAL = 288,
    SOURCE = 289,
    ENDCODE = 290,
    ENDXFORM = 291,
    INPUT = 292,
    ENDINPUT = 293,
    SEMICOLON = 294,
    IN = 295,
    SUCH_THAT = 296,
    FOR = 297,
    FOREACH = 298,
    FOREACH_R = 299,
    DO = 300,
    ENDDO = 301,
    BREAK = 302,
    CONTINUE = 303,
    RETURN = 304,
    DEBUG = 305,
    IF = 306,
    ELSE = 307,
    CASE = 308,
    SWITCH = 309,
    DEFAULT = 310,
    DOT3 = 311,
    DOT4 = 312,
    ASSIGN = 313,
    PLUS_ASSIGN = 314,
    MINUS_ASSIGN = 315,
    MULT_ASSIGN = 316,
    DIVIDE_ASSIGN = 317,
    MOD_ASSIGN = 318,
    COMMA = 319,
    QUESTION = 320,
    OR = 321,
    TOR = 322,
    AND = 323,
    NOT = 324,
    LT = 325,
    LE = 326,
    EQ = 327,
    GT = 328,
    GE = 329,
    NE = 330,
    ARROW = 331,
    DARROW = 332,
    PLUS = 333,
    MINUS = 334,
    MULTIPLY = 335,
    DIVIDE = 336,
    MOD = 337,
    STR_CONCAT = 338,
    DCOLON = 339,
    UMINUS = 340,
    TILT = 341,
    DELAY = 342,
    APPLY = 343,
    CLEAR = 344,
    SAVE = 345,
    RESTORE = 346,
    REVERSE = 347,
    PERMUTE = 348,
    REPLACE = 349,
    ASSERT = 350,
    RANGE = 351,
    DUPLICATE = 352,
    REBUILD = 353,
    VAR = 354,
    MAP = 355,
    TUPLE = 356,
    LIST = 357,
    LIST1 = 358,
    INT = 359,
    STRING = 360,
    FLOAT = 361,
    NAME = 362,
    EXP = 363,
    TRACE = 364,
    ERASE = 365,
    COPY = 366,
    SPLIT = 367,
    LEN = 368,
    INSERT = 369,
    CAR = 370,
    CDR = 371,
    COLON = 372,
    ID = 373,
    ICONST = 374,
    FCONST = 375,
    ANY = 376,
    DOT = 377,
    DOT2 = 378,
    POND = 379,
    LB = 380,
    RB = 381,
    LBR = 382,
    RBR = 383,
    LP = 384,
    RP = 385
  };
#endif
/* Tokens.  */
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

/* Copy the second part of user declarations.  */

#line 495 "poet_yacc.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   2188

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  131
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  284
/* YYNRULES -- Number of rules.  */
#define YYNRULES  512
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  869

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   385

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
static const yytype_uint16 yyrline[] =
{
       0,   146,   146,   148,   149,   151,   151,   153,   153,   155,
     155,   156,   156,   157,   158,   158,   158,   159,   159,   159,
     160,   160,   160,   161,   161,   163,   165,   165,   166,   167,
     167,   168,   169,   170,   170,   171,   172,   172,   174,   174,
     175,   175,   176,   176,   178,   178,   179,   180,   180,   182,
     182,   184,   184,   186,   186,   188,   189,   191,   191,   191,
     192,   193,   193,   194,   194,   196,   196,   198,   198,   200,
     201,   201,   203,   203,   206,   207,   209,   210,   211,   212,
     214,   215,   217,   218,   221,   222,   222,   223,   225,   225,
     225,   226,   226,   228,   228,   229,   229,   230,   233,   234,
     233,   236,   237,   238,   239,   242,   244,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   258,   259,   260,
     261,   262,   262,   264,   265,   265,   267,   268,   268,   271,
     271,   272,   273,   274,   275,   275,   277,   277,   279,   279,
     281,   281,   283,   283,   284,   284,   286,   287,   287,   288,
     288,   290,   290,   292,   293,   294,   295,   296,   296,   297,
     297,   299,   300,   300,   302,   302,   304,   304,   306,   306,
     308,   308,   310,   310,   311,   311,   313,   313,   314,   316,
     317,   317,   318,   318,   320,   320,   322,   323,   324,   325,
     327,   327,   327,   328,   328,   328,   329,   329,   329,   331,
     332,   333,   333,   335,   336,   338,   339,   340,   341,   342,
     342,   344,   344,   346,   346,   348,   348,   349,   350,   350,
     352,   352,   353,   354,   354,   356,   357,   359,   359,   360,
     361,   361,   362,   363,   363,   363,   364,   365,   365,   366,
     366,   367,   368,   368,   369,   370,   370,   370,   371,   372,
     372,   373,   374,   375,   378,   378,   379,   380,   381,   381,
     381,   381,   383,   384,   385,   385,   386,   387,   388,   388,
     386,   390,   390,   390,   392,   392,   392,   392,   394,   395,
     396,   396,   394,   398,   399,   400,   400,   398,   402,   402,
     403,   404,   405,   407,   408,   410,   411,   414,   414,   416,
     418,   419,   419,   421,   421,   421,   423,   423,   423,   424,
     424,   427,   428,   430,   430,   431,   431,   434,   435,   436,
     436,   437,   437,   438,   438,   439,   439,   440,   442,   443,
     443,   444,   444,   445,   445,   447,   447,   449,   449,   451,
     451,   453,   453,   455,   455,   456,   456,   456,   460,   460,
     461,   461,   462,   462,   463,   463,   464,   464,   465,   465,
     466,   466,   468,   468,   470,   470,   472,   472,   473,   475,
     476,   476,   478,   478,   480,   480,   482,   482,   484,   484,
     486,   486,   488,   488,   489,   489,   491,   491,   494,   494,
     495,   496,   496,   497,   499,   499,   499,   499,   502,   502,
     502,   505,   505,   505,   507,   507,   507,   507,   509,   509,
     510,   511,   510,   513,   513,   514,   514,   514,   516,   516,
     518,   518,   519,   519,   520,   520,   521,   521,   522,   522,
     522,   524,   525,   525,   527,   529,   530,   530,   530,   532,
     532,   533,   535,   536,   538,   539,   540,   540,   541,   541,
     543,   543,   545,   546,   547,   548,   549,   552,   552,   553,
     553,   554,   554,   555,   555,   556,   557,   560,   560,   561,
     562,   563,   564,   565,   567,   567,   568,   568,   569,   570,
     571,   570,   573,   575,   575,   578,   578,   580,   581,   581,
     583,   583,   586,   586,   587,   588,   588,   590,   590,   593,
     594,   595,   597,   597,   599,   602,   602,   604,   604,   608,
     608,   610,   610
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ENDLIST", "ERROR", "SYNERROR",
  "PARAMETER", "DEFINE", "EVAL", "LBEGIN", "RBEGIN", "PRINT",
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
  "@179", "@180", "@181", "code9", "@182", "@183", "@184", "@185",
  "codeUnit", "@186", "varInvoke", "@187", "@188", "varInvoke1", "@189",
  "@190", "pond", "@191", "varInvokeType", "@192", "varInvokeType1",
  "@193", "@194", "varInvokePattern", "@195", "varInvokePattern1", "@196",
  "@197", "configOrSubRef", "selectRef", "@198", "configRef", "@199",
  "@200", "xformConfig", "@201", "@202", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385
};
# endif

#define YYPACT_NINF -657

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-657)))

#define YYTABLE_NINF -257

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -657,    40,    38,  -657,   507,  -657,    70,   -54,   -43,  -657,
    -657,   -30,  -657,   -24,  -657,    -6,   -48,    -7,  -657,  -657,
    -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  1621,  1621,
    -657,   176,  -657,   411,     5,    82,  -657,  -657,  1195,  -657,
     987,  -657,  -657,  -657,    36,    43,    54,  -657,  -657,    55,
      63,    81,  -657,  -657,  -657,   124,   128,   135,  -657,  -657,
     164,   165,   179,  -657,  -657,   167,   200,  -657,   206,   217,
    -657,   190,  -657,   218,   225,  -657,   234,  -657,   235,  -657,
    -657,  -657,  -657,  -657,  -657,   214,   251,  -657,  -657,  -657,
     340,   223,  -657,  -657,   318,     4,  -657,   -17,   981,  -657,
     581,  -657,   -34,   316,   364,    -1,   333,   339,   341,   344,
    -657,  -657,     2,   345,   347,   348,   349,   350,   354,   355,
    -657,  -657,   553,    -6,  -657,  1195,  1195,  2010,  -657,   269,
     285,   290,  -657,  -657,  -657,  -657,  -657,   362,  -657,  -657,
    -657,  -657,  -657,  -657,  -657,   357,  -657,   396,   293,   311,
    2010,   376,  -657,  -657,  -657,  -657,   243,  -657,   553,   553,
     321,  -657,   323,  -657,   324,  -657,  -657,    -9,  -657,  1303,
     325,   320,  -657,  -657,  1912,  1912,  -657,  -657,  -657,   553,
     553,  -657,  -657,   553,   553,  -657,   553,    33,   326,   553,
    -657,  -657,   553,  -657,   553,  -657,   553,   553,  -657,  1621,
    -657,  1621,  -657,  1621,  -657,  -657,  -657,  -657,  -657,  -657,
    -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,
    -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,
    -657,  -657,  1961,  -657,  -657,    84,  -657,  -657,   390,   397,
     399,    26,  -657,  -657,  -657,  -657,  -657,   433,   176,   402,
     413,   414,   415,   417,   418,   423,   424,  -657,  -657,  -657,
    -657,    -4,  -657,  -657,   463,  -657,   175,   411,  -657,  -657,
       9,    18,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  1195,
     171,  -657,  -657,   187,  1621,  -657,  -657,  -657,  2010,  -657,
    -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  1303,  1912,
     428,  -657,   447,  -657,  1912,  -657,   363,  -657,  1303,  1621,
     721,  -657,   382,  1621,  1621,  -657,  -657,  1303,  1303,  -657,
     426,  1303,  -657,  -657,   -35,   416,  -657,  2010,  -657,  1303,
    1303,  -657,  1303,  -657,  1303,  -657,  -657,   368,   365,  -657,
     889,   889,  1912,  1303,  1303,  1912,  1912,  1912,  1912,  1912,
    1912,  1912,  1912,  1912,  1912,  1912,  1912,  1912,  2059,  1303,
    1303,  1303,  1303,  1303,  1303,  1195,  1195,  -657,  -657,   553,
    -657,  -657,  -657,  -657,   553,   367,   369,  -657,  -657,  -657,
    -657,    -1,   553,   553,   553,   553,  -657,  -657,  -657,   371,
    -657,  -657,   378,  -657,  -657,  -657,   193,     2,   553,   553,
    -657,  -657,   553,   553,  -657,   987,   553,  -657,  -657,  -657,
    -657,  -657,  -657,  -657,  1195,  1195,  1195,  1195,    23,   377,
     437,  -657,  -657,  -657,  1195,   448,   451,   452,   458,  -657,
     387,  2010,   395,  1062,   393,   467,   987,   493,  -657,   871,
    -657,   196,  -657,   950,  -657,  1621,   410,   412,   419,   427,
       6,   173,   553,   181,   553,  -657,   553,   260,   178,   178,
     199,   211,  -657,  -657,  -657,  -657,  1031,   473,  -657,   721,
     721,   721,   721,   721,   721,   382,   382,   459,   459,   459,
     459,   459,   430,   434,   496,  -657,  -657,   739,  -657,  -657,
     178,   178,   178,   178,   178,   357,   357,  1961,  -657,   553,
    1814,  -657,  -657,   440,  -657,  2010,  1621,  -657,  -657,  -657,
    -657,  -657,   553,   441,   553,   987,  -657,   153,   553,   553,
    -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,   107,  -657,
     557,  2010,   357,   284,   313,   357,  -657,  1195,  -657,  -657,
    2010,   442,  -657,  -657,   521,  -657,  -657,  -657,  -657,  -657,
    -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  2010,  -657,
    -657,  -657,  -657,  -657,  2059,  -657,  -657,  -657,  1863,  -657,
     435,  -657,   438,  -657,  -657,  -657,  -657,   432,  -657,   489,
    -657,  -657,   -38,   -12,  -657,  -657,  -657,  -657,  -657,  -657,
    2059,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,
    -657,  -657,   -21,   178,   453,   501,   530,   462,    -5,   464,
     516,   552,  -657,   472,     7,  -657,   107,  -657,  -657,   316,
    -657,  -657,  1621,  -657,  -657,  1195,  -657,  -657,  1195,   357,
    -657,  1195,  -657,   532,   -33,  2010,  -657,   987,   553,  2010,
    2010,  2010,  2010,  2010,  2010,  2010,   516,  -657,  2010,  1303,
    2059,   739,  2059,   474,   468,   560,   721,  2059,  -657,  1740,
    -657,  1303,  1303,  -657,  1303,   553,  2010,  -657,  -657,  -657,
    -657,  -657,  -657,  1303,  1303,  1303,  2059,   624,   475,   534,
    2059,  2059,  2059,  2059,  2059,  2059,  2059,  1961,  -657,   486,
    -657,  -657,  -657,  -657,   440,  -657,   492,   483,   550,  -657,
    -657,   441,  -657,   580,   487,    12,    12,   357,  1195,   357,
    -657,  -657,   107,  -657,  -657,   516,   516,   516,   516,   516,
     516,  2010,   516,   579,   227,  -657,   564,   -18,  1912,  -657,
     578,   640,  -657,   587,   574,   -11,   178,   266,  -657,    75,
    1303,  1303,    77,    89,  -657,   288,  -657,  2059,  -657,  -657,
     261,   312,   -37,   -37,   -37,   -37,  -657,  -657,  1303,  -657,
      84,   511,   442,  2010,  -657,  -657,  -657,  -657,   987,  -657,
    -657,  -657,  -657,  -657,   500,   502,  -657,  -657,  -657,  -657,
    -657,  -657,  -657,   494,  1303,  -657,  -657,   586,  -657,     3,
    -657,   -38,  -657,  -657,   130,   154,  -657,  -657,  2059,   739,
    -657,  2059,   178,  -657,   523,  -657,   530,   516,  2010,   464,
     107,  -657,  -657,  1303,  1303,  2010,   474,  -657,  -657,  1621,
    1303,  -657,  -657,  2059,  -657,   537,  -657,  -657,  1303,  -657,
    -657,   739,  2059,   739,   516,  -657,   525,   531,   516,   612,
     616,   535,  1621,   699,  2059,  -657,   186,  -657,  -657,  -657,
    -657,  -657,  -657,  -657,   785,  1621,  -657,  1740,  1740,  1740,
    1621,  -657,  -657,  -657,  -657,  -657,  -657,  1621,  -657
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     0,   444,     1,     0,     4,     0,     0,     0,     9,
      11,     0,    20,     0,    17,     0,     0,     0,    25,   445,
     455,   454,   446,   456,   452,   453,     5,     7,     0,     0,
      23,    46,    14,    28,   251,     0,   448,   450,     0,    88,
       0,   189,   321,   325,    80,    82,     0,   188,   291,     0,
     274,     0,   318,   317,   319,   442,     0,     0,   352,   384,
       0,     0,     0,   426,   424,     0,     0,   323,     0,     0,
     422,   103,   463,     0,     0,   408,     0,   461,     0,   457,
     459,    76,   186,   187,   471,   288,   467,   472,   473,   470,
       0,   254,   262,   257,   311,   312,   327,   328,   368,   369,
     386,   435,   474,   466,     0,   233,     0,     0,     0,     0,
      21,    44,    57,     0,     0,     0,     0,     0,     0,     0,
      18,    26,     0,     0,    13,     0,     0,     0,   114,   115,
       0,     0,   109,   111,   110,   112,   113,    76,   108,   213,
     485,   116,   205,   107,   208,   447,   206,    89,     0,     0,
       0,    76,   124,   117,   200,   199,     0,   120,     0,     0,
       0,    78,     0,    79,     0,   266,   278,     0,   283,     0,
       0,     0,   258,   271,     0,     0,   413,   420,   465,     0,
       0,   401,   394,     0,     0,   404,     0,     0,    98,     0,
     398,   410,     0,   428,     0,   415,     0,     0,   290,     0,
     469,     0,    10,     0,   313,   292,   315,   345,   350,   348,
     354,   356,   358,   360,   362,   364,   370,   372,   374,   378,
     380,   376,   382,   366,   329,   333,   335,   337,   339,   341,
     331,   343,   390,   431,   432,   478,   476,    12,     0,     0,
       0,     0,   234,    53,    51,    47,    49,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    58,    42,
      40,     0,    38,    33,    36,    29,     0,    28,   252,   253,
       0,     0,   115,   126,   207,   190,   193,   196,   209,     0,
     487,   211,     6,     0,     0,   118,   123,   121,     0,     8,
     204,   203,   201,   322,   326,    81,    83,    77,   296,     0,
      76,   492,     0,   299,     0,   320,     0,   418,     0,     0,
     353,   386,   385,     0,     0,   427,   425,     0,     0,   324,
       0,     0,   423,   102,     0,     0,   101,     0,   464,     0,
       0,   409,     0,   462,     0,   458,   460,     0,     0,   255,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   387,   388,     0,
     483,   479,   475,   482,     0,     0,     0,   239,   230,   232,
      24,   233,     0,     0,     0,     0,    22,    45,    63,     0,
      72,    67,     0,    70,    65,    61,     0,    57,     0,     0,
      31,    32,     0,     0,    35,     0,     0,   444,    56,    19,
      27,   449,   451,   127,     0,     0,     0,     0,   215,     0,
     217,   490,   488,   486,     0,     0,     0,     0,     0,    90,
       0,     0,   126,   129,     0,   131,     0,     0,   295,     0,
     297,   494,   275,     0,   443,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,     0,     0,   399,   411,
       0,     0,   289,   468,   314,   316,     0,   351,   349,   355,
     357,   359,   361,   363,   365,   371,   373,   375,   379,   381,
     377,   383,     0,     0,    76,   157,   153,   367,   156,   330,
     334,   336,   338,   340,   342,   332,   344,   393,   433,     0,
       0,   474,   477,     0,   237,     0,     0,   235,    54,    52,
      48,    50,     0,     0,     0,     0,    69,     0,     0,     0,
     227,   229,    16,    59,    43,    41,    39,    34,    37,    30,
       0,     0,   191,     0,     0,   210,   218,   222,   214,   220,
       0,     0,   212,    91,     0,    95,    93,   119,   122,   134,
     133,   132,   149,   136,   138,   140,   142,   144,   146,   125,
     151,   202,   267,   279,     0,   497,   495,   493,     0,   284,
       0,   259,     0,   414,   421,   402,   395,     0,   405,     0,
     105,    99,     0,     0,   429,   416,   346,   154,   155,   174,
       0,   161,   159,   164,   166,   168,   170,   172,   162,   389,
     391,   484,    76,   499,     0,   501,   500,   241,     0,     0,
     240,     0,    64,    84,     0,    73,    68,    75,    71,    74,
      66,    62,     0,    55,   128,   222,   194,   197,     0,   223,
     216,     0,   491,     0,     0,     0,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   147,   130,     0,   296,
       0,   298,     0,     0,     0,   300,   293,     0,   419,     0,
     272,     0,     0,   434,     0,     0,     0,   437,   436,   400,
     439,   441,   412,     0,     0,     0,     0,   176,     0,   178,
       0,     0,     0,     0,     0,     0,     0,   393,   505,     0,
     480,   502,   507,   242,     0,   236,   248,     0,   247,   231,
      85,     0,    60,     0,     0,     0,     0,   219,   222,   221,
     489,    92,    96,    94,   135,   150,   137,   139,   141,   143,
     145,   146,   152,     0,     0,   498,     0,     0,     0,   301,
       0,     0,   260,     0,     0,     0,   396,     0,   106,     0,
       0,     0,     0,     0,   347,   175,   182,   179,   158,   184,
     160,   165,   167,   169,   171,   173,   163,   392,     0,   504,
     478,     0,     0,     0,   244,   249,   238,   245,     0,    87,
     228,   192,   226,   225,     0,     0,   224,   148,   268,   280,
     509,   511,   496,     0,     0,   276,   285,   263,   306,     0,
     403,     0,   406,   100,     0,     0,   430,   417,     0,   180,
     177,     0,   506,   481,     0,   503,   508,   243,     0,     0,
      86,   195,   198,   296,     0,     0,     0,   294,   302,     0,
       0,   264,   261,     0,   303,     0,   273,   397,     0,   438,
     440,   183,   179,   185,   250,   246,     0,     0,   510,   512,
       0,     0,     0,     0,     0,   309,     0,   181,   269,   281,
     277,   286,   265,   307,     0,     0,   407,     0,     0,     0,
       0,   304,   310,   270,   282,   287,   308,     0,   305
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,
    -657,  -657,  -657,  -657,  -657,   400,  -657,  -657,  -657,  -657,
    -657,  -657,  -657,  -657,   420,  -657,  -657,  -657,  -657,  -657,
    -657,  -657,   267,  -657,  -657,  -657,  -657,  -657,  -657,  -657,
    -657,  -657,    88,  -657,  -657,   -32,  -657,  -657,  -657,  -657,
    -657,  -657,  -657,   844,  -657,  -657,  -657,   954,   -27,  -657,
    -657,  -115,  -657,    46,  -657,  -657,  -657,  -657,  -657,  -657,
    -657,   -51,  -657,  -657,  -657,  -657,  -324,  -657,  -657,  -657,
    -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -149,  -657,
    -657,  -657,  -657,   510,   -26,  -657,  -657,  -657,  -657,  -657,
    -657,  -394,  -657,    35,  -657,  -657,  -657,  -657,  -657,  -657,
    -657,  -657,  -615,  -657,   -20,  -657,  -657,  -657,  -657,   303,
    -657,  -657,  -657,  -657,    -2,  -657,  -124,  -657,  -657,  -657,
     566,   -22,  -657,  -155,  -657,  -657,  -657,  -657,  -657,  -656,
    -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,
    -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -641,
    -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,
    -657,  -657,  -657,  -657,  -321,  -657,  -657,  -657,  -657,  -164,
    -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,
    -194,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,
    -657,  -121,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,
    -657,  -657,  -657,  -657,     8,  -657,   -28,  -657,  -657,  -657,
    -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,
    -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,  -657,
    -657,  -101,  -657,  -657,  -657,  -657,   287,  -657,  -657,  -657,
    -657,  -657,  -657,  -657,  -657,   -81,  -657,  -370,  -657,  -657,
     -63,  -657,  -657,  -657,  -657,   -29,  -657,  -657,  -657,  -657,
     536,  -657,  -657,  -657,  -657,  -657,   -62,  -657,  -539,  -657,
    -657,  -118,  -657,  -657
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,    39,    40,    28,    29,   112,   396,
      33,   266,    31,   247,   105,   120,   267,   121,   406,   403,
     405,   402,   399,   398,   110,   248,   111,   384,   385,   383,
     382,   409,   257,   397,   258,   519,   512,   518,   515,   517,
     514,   618,    87,   161,   163,   614,   768,   147,   283,   429,
     635,   638,   637,    88,   327,   666,   324,   153,   273,   431,
     288,   433,   531,   434,   558,   639,   641,   642,   643,   644,
     645,   647,   721,   435,   640,   648,   799,   590,   680,   686,
     681,   682,   683,   684,   685,   676,   678,   747,   800,   832,
     679,   798,   801,    89,   144,   414,   625,   415,   705,   416,
     706,   156,   436,   629,   417,   424,   279,   419,   537,   420,
     628,   631,   630,   708,   774,   522,   622,   380,   506,   241,
     381,   242,   609,   505,   608,   763,   697,   809,   698,   808,
      35,    90,   203,    91,   308,   659,   787,   822,   842,    92,
     298,   649,   813,   857,   309,   734,   167,   568,   819,   299,
     650,   814,   858,   304,   657,   820,   859,   199,   655,   437,
     302,   564,   730,   784,   789,   844,   867,   823,   860,   855,
      93,    94,   340,   341,    95,   169,   158,   183,   159,    96,
     359,   365,   360,   361,   362,   363,   364,   366,   342,   675,
      97,   344,   343,   174,   345,   346,   347,   348,   349,   350,
     358,    98,   351,   352,   353,   356,   354,   355,   357,   175,
      99,   232,   367,   497,   599,   687,   311,   318,   662,   791,
     329,   582,   317,   661,   321,   664,   828,   192,   330,   583,
     313,   334,   674,   445,   314,   186,   180,   179,   332,   673,
     369,   669,   740,   672,   741,   171,     6,    38,   125,   126,
     101,   196,   197,   194,   189,   102,   201,   103,   235,   374,
     372,   500,   760,   373,   499,   157,   280,   423,   541,   540,
     488,   441,   567,   653,   652,   604,   605,   761,   606,   758,
     762,   727,   815,   816
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     100,   100,   634,   732,   502,   305,   692,   104,   723,   146,
     704,   528,   274,   154,   155,    41,   400,   249,    44,   464,
     465,   781,   233,    45,    46,   238,   667,   239,   250,   454,
     251,   252,   253,   254,   487,   286,    41,   688,    -2,    44,
       3,   268,   561,   205,    45,    46,    47,   597,   207,   208,
     378,   209,   670,   310,   312,   208,   824,   209,   825,   694,
      44,     4,   379,   122,    26,    45,    46,    47,   206,   123,
     575,   701,   208,   145,   209,    27,   281,   293,   294,    16,
      17,    36,    18,    19,    20,   281,   598,   536,    30,   234,
     281,   455,   668,   776,    32,   710,   146,   146,   315,   316,
     255,   689,   319,   320,    21,   322,   325,   124,   328,   300,
     782,   331,    34,   333,   401,   335,   336,   240,   671,   790,
     256,   616,    37,   450,   451,   695,   140,   453,   140,   826,
      81,    82,    83,    71,   438,   458,   459,   702,   460,   411,
     461,   100,   413,   208,   446,   209,    22,   619,   412,   467,
     468,    81,    82,    83,    84,   208,    41,   209,   160,   323,
     270,   271,    86,   290,   291,   162,   490,   491,   492,   493,
     494,   100,   836,   100,   292,   100,   164,   337,   439,   338,
      44,   339,   617,   443,   165,    45,    46,    47,    23,    24,
      25,   106,   166,   107,   108,   489,   208,   109,   209,   407,
     408,   863,   864,   865,   368,   793,   425,   796,   370,   426,
     168,   371,   457,   140,   140,   140,   427,   520,   521,   797,
     208,   466,   209,   806,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   576,   140,   208,
     651,   209,   428,   712,   208,   578,   209,   208,  -256,   209,
     146,   170,   208,    71,   209,   301,   100,   172,  -256,  -256,
     829,   432,   430,   584,   173,   208,   677,   209,   289,  -256,
     100,    81,    82,    83,    84,   585,  -256,   208,  -256,   209,
     100,   100,    86,   591,   830,   100,   100,   447,   498,   176,
     177,   448,   449,   501,   592,   421,   181,   178,   422,   290,
     291,   508,   509,   510,   511,   593,   603,   594,   595,   596,
     292,   597,   100,   100,   418,   187,   856,   524,   525,   188,
     565,   526,   527,   566,   581,   529,   724,   413,   725,   182,
     792,   100,   208,   731,   209,   184,   146,   146,   733,   593,
     198,   594,   595,   596,   779,   597,   185,   190,   626,  -256,
     598,   281,   745,  -256,   191,   592,   750,   751,   752,   753,
     754,   755,   756,   193,   195,   202,   593,   140,   594,   595,
     596,   577,   597,   579,   810,   580,   140,   627,   154,   155,
     281,   200,   204,   236,   598,   146,   146,   146,   146,   237,
     610,   243,   594,   595,   596,   146,   597,   244,   275,   245,
     495,   496,   246,   259,   548,   260,   261,   262,   263,   154,
     155,   598,   264,   265,   276,   140,   624,   100,   601,   277,
     278,   282,   284,   570,   281,   632,   113,   114,   115,   116,
     285,   612,   117,   615,   287,   598,   501,   620,   621,   295,
     118,   296,   297,   646,   306,   307,   301,   656,   375,   532,
     533,   534,   535,   140,   140,   376,   326,   377,   386,   542,
     388,   119,   218,   219,   220,   221,   222,   735,   736,   600,
     737,   389,   390,   391,   831,   392,   393,   833,   100,   742,
     743,   394,   395,   404,   611,   438,   440,   442,   154,   155,
     452,   444,   456,   140,   462,   463,   503,   516,   504,   843,
     513,   539,   140,   140,   140,   140,   543,   538,   146,   544,
     545,   744,   140,     7,     8,     9,   546,   547,   549,   140,
     854,   733,    10,   559,   140,   715,   716,   717,   718,   719,
     720,   560,   562,   722,    11,    12,   733,   733,   733,    13,
     571,   209,   572,   222,    14,   573,   794,   795,   143,   587,
     143,   739,   588,   574,   589,   636,    41,   713,   607,   613,
     633,   658,   663,   660,   802,   665,    16,    17,   691,   692,
      19,    20,   216,   217,   218,   219,   220,   221,   222,   693,
      44,   690,   696,   413,   738,    45,    46,    47,   699,   700,
     688,    21,   726,   140,   100,   623,   146,   728,   749,   146,
     703,   729,   146,   140,   759,   748,   646,   783,   432,   765,
     154,   155,   714,   766,   767,   770,    15,   771,   778,   140,
     818,   100,   780,   785,   817,   140,   205,   788,   140,   804,
     811,   100,   812,    22,   846,   143,   143,   143,   821,   224,
     225,   226,   227,   228,   229,   689,   140,   100,   807,   438,
     837,   781,   301,    71,   845,   848,   841,   230,   231,   600,
     143,   849,   850,   707,   523,   851,   709,   410,   387,   769,
     777,    81,    82,    83,    84,    23,    24,    25,   301,   146,
     591,   711,    86,   847,   507,   835,   775,   852,   746,   269,
     827,   592,   764,   834,   530,   757,   591,   803,   839,   805,
     838,     0,   593,   303,   594,   595,   596,   592,   597,     0,
       0,     0,     0,   140,     0,     0,   140,     0,   593,   140,
     594,   595,   596,   140,   597,   140,     0,   140,   140,   140,
     140,   140,   140,   140,     0,     0,   140,     0,   301,     0,
     301,   154,   155,     0,     0,   301,     0,   598,     0,     0,
       0,     0,     0,     0,   140,   591,   100,   786,     0,     0,
       0,     0,     0,   598,   301,     0,   592,     0,   301,   301,
     301,   301,   301,   301,   301,     0,     0,   593,     0,   594,
     595,   596,     0,   597,     0,   100,   100,     0,     0,   143,
       0,   100,   100,   772,   772,   591,   140,   840,   143,   216,
     217,   218,   219,   220,   221,   222,   592,     0,     0,   140,
       0,     0,     0,     0,   100,     0,   853,   593,     0,   594,
     595,   596,   598,   597,     0,     0,     0,   100,     0,   100,
     100,   100,   100,   862,     0,   301,     0,   143,   866,   100,
       0,   591,     0,     0,     0,   868,     0,     0,     0,     0,
       0,   140,   592,     0,     0,     0,   140,     0,     0,     0,
       0,     0,   598,   593,     0,   594,   595,   596,   143,   597,
       0,     0,     0,     0,     0,   143,   143,     0,     0,     0,
       0,     0,   141,     0,   141,     0,   301,     0,     0,   301,
       0,     0,    41,    42,     0,     0,   140,     0,     0,     0,
      43,     0,   861,   140,     0,     0,     0,     0,   598,     0,
       0,   301,     0,     0,     0,   143,    44,     0,     0,     0,
     301,    45,    46,    47,   143,   143,   143,   143,     0,     0,
       0,     0,   301,     0,   143,     0,    52,    53,    54,    55,
       0,   143,     0,     0,     0,     0,   143,     0,     0,   216,
     217,   218,   219,   220,   221,   222,     0,     0,    58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    59,   141,
     141,   141,     0,     0,     0,     0,    60,    61,    62,    63,
      64,     0,    65,    66,    67,    68,    69,    70,   563,    71,
      41,     0,   142,    72,   141,   148,     0,     0,    73,    74,
      75,    76,    77,    78,    79,    80,     0,    81,    82,    83,
      84,     0,     0,     0,    44,   143,     0,     0,    86,    45,
      46,    47,     0,     0,     0,   143,     0,     0,   216,   217,
     218,   219,   220,   221,   222,     0,     0,     0,     0,     0,
       0,   143,     0,     0,     0,     0,     0,   143,     0,     0,
     143,   210,   211,   212,   213,   214,   215,     0,     0,   216,
     217,   218,   219,   220,   221,   222,   149,   569,   143,     0,
       0,     0,     0,   150,   143,     0,     0,     0,     0,   142,
     142,     0,     0,     0,     0,     0,   128,    71,   129,   130,
     131,   132,   133,   134,   135,   136,     0,     0,   223,     0,
     143,     0,     0,     0,     0,   151,    82,    83,   138,   216,
     217,   218,   219,   220,   221,   222,   152,     0,   550,   551,
       0,     0,     0,   141,     0,     0,   552,     0,     0,   413,
       0,     0,   141,     0,     0,   143,     0,     0,   143,     0,
     553,   143,   554,   555,   556,   143,   557,   143,   586,   143,
     143,   143,   143,   143,   143,   143,     0,     0,   143,     0,
     143,     0,   143,     0,     0,     0,     0,   143,     0,     0,
       0,   141,     0,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   143,     0,     0,     0,
     143,   143,   143,   143,   143,   143,   143,     0,    41,     0,
       0,     0,   141,     0,     0,     0,     0,     0,     0,   141,
     141,     0,     0,     0,     0,   773,   773,     0,   143,     0,
       0,     0,    44,     0,     0,     0,     0,    45,    46,    47,
       0,   143,     0,   142,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,     0,     0,     0,     0,     0,   143,   141,   141,
     141,   141,     0,     0,     0,     0,     0,     0,   141,     0,
       0,     0,     0,   143,     0,   141,     0,     0,   143,     0,
     141,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,    71,   129,   130,   131,   132,
     133,   134,   135,   136,     0,     0,    41,     0,   143,     0,
       0,   143,   486,   137,    82,    83,   138,     0,   143,   142,
     142,     0,     0,     0,   139,   143,     0,     0,     0,     0,
      44,     0,     0,   143,     0,    45,    46,    47,     0,     0,
       0,     0,   143,     0,     0,     0,     0,     0,     0,   141,
       0,     0,     0,    55,   143,     0,     0,     0,     0,   141,
       0,     0,     0,     0,     0,     0,     0,     0,   142,   142,
     142,   142,    58,     0,     0,   141,     0,     0,   142,     0,
       0,   141,    59,     0,   141,     0,     0,     0,     0,     0,
      60,    61,    62,    63,    64,     0,    65,    66,     0,    68,
      69,    70,   141,    71,     0,     0,     0,    72,   141,     0,
       0,     0,    73,    74,    75,    76,    77,    78,    79,    80,
       0,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,    86,     0,   141,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,   141,     0,     0,   141,     0,     0,     0,   141,
       0,   141,     0,   141,   141,   141,   141,   141,   141,   141,
       0,   142,   141,     0,   141,     0,   141,     0,     0,     0,
       0,   141,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,     0,     0,     0,     0,     0,   486,     0,
     141,     0,     0,     0,   141,   141,   141,   141,   141,   141,
     141,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   486,     0,     0,     0,     0,     0,
       0,     0,   141,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   142,
       0,     0,   142,     0,     0,   142,     0,     0,     0,     0,
       0,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   486,     0,   486,   141,     0,     0,
       0,   486,   141,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,    42,     0,     0,     0,     0,
     486,     0,    43,     0,   486,   486,   486,   486,   486,   486,
     486,     0,   141,     0,     0,   141,     0,     0,    44,     0,
       0,     0,   141,    45,    46,    47,     0,     0,     0,   141,
      48,     0,   142,    49,    50,    51,     0,   141,    52,    53,
      54,    55,    56,     0,     0,    57,   141,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,     0,
      58,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      59,   486,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,     0,    65,    66,    67,    68,    69,    70,
       0,    71,     0,     0,     0,    72,     0,     0,     0,     0,
      73,    74,    75,    76,    77,    78,    79,    80,     0,    81,
      82,    83,    84,    41,    42,     0,    85,     0,     0,     0,
      86,    43,   486,     0,     0,   486,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,     0,     0,
       0,     0,    45,    46,    47,     0,     0,   486,     0,    48,
       0,     0,    49,    50,    51,     0,   486,    52,    53,    54,
      55,     0,     0,     0,    57,     0,     0,     0,   486,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
       0,     0,     0,     0,     0,     0,     0,    41,     0,    59,
       0,     0,     0,     0,     0,     0,     0,    60,    61,    62,
      63,    64,     0,    65,    66,    67,    68,    69,    70,     0,
      71,    44,     0,     0,    72,     0,    45,    46,    47,    73,
      74,    75,    76,    77,    78,    79,    80,     0,    81,    82,
      83,    84,     0,     0,    55,    85,    41,     0,     0,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,     0,     0,     0,     0,     0,     0,
      44,     0,     0,    59,     0,    45,    46,    47,     0,     0,
       0,    60,    61,    62,    63,    64,     0,    65,    66,     0,
      68,    69,    70,    55,    71,    41,     0,     0,    72,     0,
       0,     0,     0,    73,    74,    75,    76,    77,    78,    79,
      80,     0,   602,    82,    83,    84,     0,     0,     0,    44,
       0,     0,    59,    86,    45,    46,    47,     0,     0,     0,
      60,    61,    62,    63,    64,   654,    65,    66,     0,    68,
      69,    70,    55,    71,    41,     0,     0,    72,     0,     0,
       0,     0,    73,    74,    75,    76,    77,    78,    79,    80,
       0,    81,    82,    83,    84,     0,     0,     0,    44,     0,
       0,    59,    86,    45,    46,    47,     0,     0,     0,    60,
      61,    62,    63,    64,     0,    65,    66,     0,    68,    69,
      70,    55,    71,    41,     0,     0,    72,     0,   148,     0,
       0,    73,    74,    75,    76,    77,    78,    79,    80,     0,
      81,    82,    83,    84,     0,     0,     0,    44,     0,     0,
       0,    86,    45,    46,    47,     0,     0,     0,    60,    61,
      62,    63,    64,     0,    65,    66,     0,    68,    69,    70,
       0,    71,    41,     0,     0,    72,     0,     0,     0,     0,
      73,    74,    75,    76,    77,    78,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,    44,     0,     0,   149,
      86,    45,    46,    47,     0,     0,   150,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   128,
      71,   272,     0,     0,   132,   133,   134,   135,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   151,    82,
      83,   138,     0,     0,     0,     0,     0,     0,   482,   152,
       0,     0,     0,     0,     0,     0,     0,     0,   483,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,    71,
     272,     0,     0,   132,   133,   134,   135,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   484,    82,    83,
     138,     0,     0,     0,     0,     0,     0,     0,   485
};

static const yytype_int16 yycheck[] =
{
      28,    29,   541,   659,   374,   169,    39,    29,   649,    38,
     625,   405,   127,    40,    40,     3,    20,    15,    27,   340,
     341,    39,    56,    32,    33,    26,    64,    28,    26,    64,
      28,    29,    30,    31,   358,   150,     3,    58,     0,    27,
       0,   122,   436,    39,    32,    33,    34,    84,    65,    66,
      24,    68,    64,   174,   175,    66,    53,    68,    55,    64,
      27,    23,    36,    58,   118,    32,    33,    34,    64,    64,
      64,    64,    66,    38,    68,   118,    67,   158,   159,     9,
      10,   129,    12,    13,    14,    67,   123,    64,   118,   123,
      67,   126,   130,   708,   118,   128,   125,   126,   179,   180,
      98,   122,   183,   184,    34,   186,   187,    25,   189,   118,
     128,   192,   118,   194,   118,   196,   197,   118,   130,   130,
     118,   515,   129,   317,   318,   130,    38,   321,    40,   126,
     118,   119,   120,   100,   298,   329,   330,   130,   332,   130,
     334,   169,    67,    66,   308,    68,    76,   517,   130,   343,
     344,   118,   119,   120,   121,    66,     3,    68,   122,   126,
     125,   126,   129,    56,    57,   122,   360,   361,   362,   363,
     364,   199,   813,   201,    67,   203,   122,   199,   299,   201,
      27,   203,    29,   304,   129,    32,    33,    34,   118,   119,
     120,    15,   129,    17,    18,   359,    66,    21,    68,    24,
      25,   857,   858,   859,   232,   130,    19,   130,   124,    22,
     129,   127,   327,   125,   126,   127,    29,    24,    25,   130,
      66,   342,    68,   762,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,    64,   150,    66,
     564,    68,    55,   637,    66,    64,    68,    66,    25,    68,
     279,   127,    66,   100,    68,   167,   284,   129,    35,    36,
     130,   288,   284,    64,   129,    66,   590,    68,    25,    46,
     298,   118,   119,   120,   121,    64,    53,    66,    55,    68,
     308,   309,   129,    56,   130,   313,   314,   309,   369,   125,
     125,   313,   314,   374,    67,   124,   129,   118,   127,    56,
      57,   382,   383,   384,   385,    78,   500,    80,    81,    82,
      67,    84,   340,   341,   279,   125,   130,   398,   399,   129,
     124,   402,   403,   127,    64,   406,   650,    67,   652,   129,
      64,   359,    66,   657,    68,   129,   365,   366,   659,    78,
     126,    80,    81,    82,   117,    84,   129,   129,    64,   126,
     123,    67,   676,   130,   129,    67,   680,   681,   682,   683,
     684,   685,   686,   129,   129,    25,    78,   279,    80,    81,
      82,   452,    84,   454,   768,   456,   288,    64,   405,   405,
      67,   130,    64,    67,   123,   414,   415,   416,   417,    25,
     505,    58,    80,    81,    82,   424,    84,    58,   129,    58,
     365,   366,    58,    58,   431,    58,    58,    58,    58,   436,
     436,   123,    58,    58,   129,   327,   531,   445,   499,   129,
      58,    25,   129,   445,    67,   540,    15,    16,    17,    18,
     119,   512,    21,   514,    58,   123,   517,   518,   519,   118,
      29,   118,   118,   558,   119,   125,   358,   568,    58,   414,
     415,   416,   417,   365,   366,    58,   130,    58,    25,   424,
      58,    50,    80,    81,    82,    83,    84,   661,   662,   497,
     664,    58,    58,    58,   798,    58,    58,   801,   506,   673,
     674,    58,    58,    20,   506,   649,    58,    40,   515,   515,
      64,   128,    76,   405,   126,   130,   129,   119,   129,   823,
     129,    64,   414,   415,   416,   417,    58,   130,   537,    58,
      58,   675,   424,     6,     7,     8,    58,   130,   123,   431,
     844,   842,    15,   130,   436,   640,   641,   642,   643,   644,
     645,    64,    39,   648,    27,    28,   857,   858,   859,    32,
     130,    68,   130,    84,    37,   126,   740,   741,    38,   119,
      40,   666,   118,   126,    58,    34,     3,   638,   118,   118,
     118,   126,   130,   125,   758,    76,     9,    10,    67,    39,
      13,    14,    78,    79,    80,    81,    82,    83,    84,   117,
      27,   128,   118,    67,   665,    32,    33,    34,    36,   117,
      58,    34,   118,   505,   622,    38,   625,   129,    64,   628,
     622,    41,   631,   515,   118,   130,   721,   728,   635,   117,
     637,   637,   639,   130,    64,    35,   109,   130,    39,   531,
     784,   649,    58,    45,   130,   537,    39,    53,   540,   118,
     130,   659,   130,    76,   828,   125,   126,   127,    52,    58,
      59,    60,    61,    62,    63,   122,   558,   675,   763,   813,
     814,    39,   564,   100,   117,   130,   820,    76,    77,   687,
     150,   130,    46,   628,   397,   130,   631,   267,   248,   701,
     721,   118,   119,   120,   121,   118,   119,   120,   590,   708,
      56,   635,   129,   832,   381,   809,   706,   842,    64,   123,
     791,    67,   694,   808,   407,   687,    56,   760,   816,   761,
     815,    -1,    78,   167,    80,    81,    82,    67,    84,    -1,
      -1,    -1,    -1,   625,    -1,    -1,   628,    -1,    78,   631,
      80,    81,    82,   635,    84,   637,    -1,   639,   640,   641,
     642,   643,   644,   645,    -1,    -1,   648,    -1,   650,    -1,
     652,   768,   768,    -1,    -1,   657,    -1,   123,    -1,    -1,
      -1,    -1,    -1,    -1,   666,    56,   784,   117,    -1,    -1,
      -1,    -1,    -1,   123,   676,    -1,    67,    -1,   680,   681,
     682,   683,   684,   685,   686,    -1,    -1,    78,    -1,    80,
      81,    82,    -1,    84,    -1,   813,   814,    -1,    -1,   279,
      -1,   819,   820,   705,   706,    56,   708,   819,   288,    78,
      79,    80,    81,    82,    83,    84,    67,    -1,    -1,   721,
      -1,    -1,    -1,    -1,   842,    -1,   117,    78,    -1,    80,
      81,    82,   123,    84,    -1,    -1,    -1,   855,    -1,   857,
     858,   859,   860,   855,    -1,   747,    -1,   327,   860,   867,
      -1,    56,    -1,    -1,    -1,   867,    -1,    -1,    -1,    -1,
      -1,   763,    67,    -1,    -1,    -1,   768,    -1,    -1,    -1,
      -1,    -1,   123,    78,    -1,    80,    81,    82,   358,    84,
      -1,    -1,    -1,    -1,    -1,   365,   366,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    40,    -1,   798,    -1,    -1,   801,
      -1,    -1,     3,     4,    -1,    -1,   808,    -1,    -1,    -1,
      11,    -1,   117,   815,    -1,    -1,    -1,    -1,   123,    -1,
      -1,   823,    -1,    -1,    -1,   405,    27,    -1,    -1,    -1,
     832,    32,    33,    34,   414,   415,   416,   417,    -1,    -1,
      -1,    -1,   844,    -1,   424,    -1,    47,    48,    49,    50,
      -1,   431,    -1,    -1,    -1,    -1,   436,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,   125,
     126,   127,    -1,    -1,    -1,    -1,    87,    88,    89,    90,
      91,    -1,    93,    94,    95,    96,    97,    98,   117,   100,
       3,    -1,    38,   104,   150,     8,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,   118,   119,   120,
     121,    -1,    -1,    -1,    27,   505,    -1,    -1,   129,    32,
      33,    34,    -1,    -1,    -1,   515,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,   531,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,
     540,    70,    71,    72,    73,    74,    75,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    79,   117,   558,    -1,
      -1,    -1,    -1,    86,   564,    -1,    -1,    -1,    -1,   125,
     126,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,   117,    -1,
     590,    -1,    -1,    -1,    -1,   118,   119,   120,   121,    78,
      79,    80,    81,    82,    83,    84,   129,    -1,    56,    57,
      -1,    -1,    -1,   279,    -1,    -1,    64,    -1,    -1,    67,
      -1,    -1,   288,    -1,    -1,   625,    -1,    -1,   628,    -1,
      78,   631,    80,    81,    82,   635,    84,   637,   117,   639,
     640,   641,   642,   643,   644,   645,    -1,    -1,   648,    -1,
     650,    -1,   652,    -1,    -1,    -1,    -1,   657,    -1,    -1,
      -1,   327,    -1,    -1,    -1,    -1,   666,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   676,    -1,    -1,    -1,
     680,   681,   682,   683,   684,   685,   686,    -1,     3,    -1,
      -1,    -1,   358,    -1,    -1,    -1,    -1,    -1,    -1,   365,
     366,    -1,    -1,    -1,    -1,   705,   706,    -1,   708,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    33,    34,
      -1,   721,    -1,   279,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   405,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   747,   414,   415,
     416,   417,    -1,    -1,    -1,    -1,    -1,    -1,   424,    -1,
      -1,    -1,    -1,   763,    -1,   431,    -1,    -1,   768,    -1,
     436,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,    -1,     3,    -1,   798,    -1,
      -1,   801,   358,   118,   119,   120,   121,    -1,   808,   365,
     366,    -1,    -1,    -1,   129,   815,    -1,    -1,    -1,    -1,
      27,    -1,    -1,   823,    -1,    32,    33,    34,    -1,    -1,
      -1,    -1,   832,    -1,    -1,    -1,    -1,    -1,    -1,   505,
      -1,    -1,    -1,    50,   844,    -1,    -1,    -1,    -1,   515,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   414,   415,
     416,   417,    69,    -1,    -1,   531,    -1,    -1,   424,    -1,
      -1,   537,    79,    -1,   540,    -1,    -1,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    -1,    93,    94,    -1,    96,
      97,    98,   558,   100,    -1,    -1,    -1,   104,   564,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,   118,   119,   120,   121,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,    -1,   590,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   625,
      -1,    -1,   628,    -1,    -1,   631,    -1,    -1,    -1,   635,
      -1,   637,    -1,   639,   640,   641,   642,   643,   644,   645,
      -1,   537,   648,    -1,   650,    -1,   652,    -1,    -1,    -1,
      -1,   657,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     666,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   564,    -1,
     676,    -1,    -1,    -1,   680,   681,   682,   683,   684,   685,
     686,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   590,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   708,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   721,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   625,
      -1,    -1,   628,    -1,    -1,   631,    -1,    -1,    -1,    -1,
      -1,   747,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   650,    -1,   652,   763,    -1,    -1,
      -1,   657,   768,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,
     676,    -1,    11,    -1,   680,   681,   682,   683,   684,   685,
     686,    -1,   798,    -1,    -1,   801,    -1,    -1,    27,    -1,
      -1,    -1,   808,    32,    33,    34,    -1,    -1,    -1,   815,
      39,    -1,   708,    42,    43,    44,    -1,   823,    47,    48,
      49,    50,    51,    -1,    -1,    54,   832,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   844,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,   747,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,    90,    91,    -1,    93,    94,    95,    96,    97,    98,
      -1,   100,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,   118,
     119,   120,   121,     3,     4,    -1,   125,    -1,    -1,    -1,
     129,    11,   798,    -1,    -1,   801,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    32,    33,    34,    -1,    -1,   823,    -1,    39,
      -1,    -1,    42,    43,    44,    -1,   832,    47,    48,    49,
      50,    -1,    -1,    -1,    54,    -1,    -1,    -1,   844,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,
      90,    91,    -1,    93,    94,    95,    96,    97,    98,    -1,
     100,    27,    -1,    -1,   104,    -1,    32,    33,    34,   109,
     110,   111,   112,   113,   114,   115,   116,    -1,   118,   119,
     120,   121,    -1,    -1,    50,   125,     3,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    79,    -1,    32,    33,    34,    -1,    -1,
      -1,    87,    88,    89,    90,    91,    -1,    93,    94,    -1,
      96,    97,    98,    50,   100,     3,    -1,    -1,   104,    -1,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,    -1,   118,   119,   120,   121,    -1,    -1,    -1,    27,
      -1,    -1,    79,   129,    32,    33,    34,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
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
      -1,   100,     3,    -1,    -1,   104,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,   118,
     119,   120,   121,    -1,    -1,    -1,    27,    -1,    -1,    79,
     129,    32,    33,    34,    -1,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,   101,    -1,    -1,   104,   105,   106,   107,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,
     120,   121,    -1,    -1,    -1,    -1,    -1,    -1,    79,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,    -1,    -1,   104,   105,   106,   107,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
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
     347,   381,   386,   388,   262,   145,    15,    17,    18,    21,
     155,   157,   139,    15,    16,    17,    18,    21,    29,    50,
     146,   148,    58,    64,    25,   379,   380,    86,    99,   101,
     102,   103,   104,   105,   106,   107,   108,   118,   121,   129,
     173,   184,   188,   224,   225,   234,   396,   178,     8,    79,
      86,   118,   129,   188,   189,   225,   232,   396,   307,   309,
     122,   174,   122,   175,   122,   129,   129,   277,   129,   306,
     127,   376,   129,   129,   324,   340,   125,   125,   118,   368,
     367,   129,   129,   308,   129,   129,   366,   125,   129,   385,
     129,   129,   358,   129,   384,   129,   382,   383,   126,   288,
     130,   387,    25,   263,    64,    39,    64,    65,    66,    68,
      70,    71,    72,    73,    74,    75,    78,    79,    80,    81,
      82,    83,    84,   117,    58,    59,    60,    61,    62,    63,
      76,    77,   342,    56,   123,   389,    67,    25,    26,    28,
     118,   250,   252,    58,    58,    58,    58,   144,   156,    15,
      26,    28,    29,    30,    31,    98,   118,   163,   165,    58,
      58,    58,    58,    58,    58,    58,   142,   147,   386,   261,
     234,   234,   101,   189,   192,   129,   129,   129,    58,   237,
     397,    67,    25,   179,   129,   119,   192,    58,   191,    25,
      56,    57,    67,   386,   386,   118,   118,   118,   271,   280,
     118,   173,   291,   401,   284,   310,   119,   125,   265,   275,
     332,   347,   332,   361,   365,   386,   386,   353,   348,   386,
     386,   355,   386,   126,   187,   386,   130,   185,   386,   351,
     359,   386,   369,   386,   362,   386,   386,   262,   262,   262,
     303,   304,   319,   323,   322,   325,   326,   327,   328,   329,
     330,   333,   334,   335,   337,   338,   336,   339,   331,   311,
     313,   314,   315,   316,   317,   312,   318,   343,   347,   371,
     124,   127,   391,   394,   390,    58,    58,    58,    24,    36,
     248,   251,   161,   160,   158,   159,    25,   155,    58,    58,
      58,    58,    58,    58,    58,    58,   140,   164,   154,   153,
      20,   118,   152,   150,    20,   151,   149,    24,    25,   162,
     146,   130,   130,    67,   226,   228,   230,   235,   234,   238,
     240,   124,   127,   398,   236,    19,    22,    29,    55,   180,
     262,   190,   189,   192,   194,   204,   233,   290,   310,   332,
      58,   402,    40,   332,   128,   364,   310,   262,   262,   262,
     321,   321,    64,   321,    64,   126,    76,   192,   321,   321,
     321,   321,   126,   130,   305,   305,   332,   321,   321,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,    79,    89,   118,   129,   188,   207,   401,   310,
     321,   321,   321,   321,   321,   234,   234,   344,   386,   395,
     392,   386,   388,   129,   129,   254,   249,   250,   386,   386,
     386,   386,   167,   129,   171,   169,   119,   170,   168,   166,
      24,    25,   246,   163,   386,   386,   386,   386,   232,   386,
     377,   193,   234,   234,   234,   234,    64,   239,   130,    64,
     400,   399,   234,    58,    58,    58,    58,   130,   189,   123,
      56,    57,    64,    78,    80,    81,    82,    84,   195,   130,
      64,   232,    39,   117,   292,   124,   127,   403,   278,   117,
     262,   130,   130,   126,   126,    64,    64,   386,    64,   386,
     386,    64,   352,   360,    64,    64,   117,   119,   118,    58,
     208,    56,    67,    78,    80,    81,    82,    84,   123,   345,
     347,   386,   118,   321,   406,   407,   409,   118,   255,   253,
     192,   262,   386,   118,   176,   386,   232,    29,   172,   388,
     386,   386,   247,    38,   192,   227,    64,    64,   241,   234,
     243,   242,   192,   118,   409,   181,    34,   183,   182,   196,
     205,   197,   198,   199,   200,   201,   192,   202,   206,   272,
     281,   207,   405,   404,    92,   289,   332,   285,   126,   266,
     125,   354,   349,   130,   356,    76,   186,    64,   130,   372,
      64,   130,   374,   370,   363,   320,   216,   207,   217,   221,
     209,   211,   212,   213,   214,   215,   210,   346,    58,   122,
     128,    67,    39,   117,    64,   130,   118,   257,   259,    36,
     117,    64,   130,   262,   243,   229,   231,   234,   244,   234,
     128,   194,   232,   386,   189,   192,   192,   192,   192,   192,
     192,   203,   192,   290,   207,   207,   118,   412,   129,    41,
     293,   207,   270,   305,   276,   321,   321,   321,   386,   192,
     373,   375,   321,   321,   310,   207,    64,   218,   130,    64,
     207,   207,   207,   207,   207,   207,   207,   345,   410,   118,
     393,   408,   411,   256,   255,   117,   130,    64,   177,   176,
      35,   130,   173,   224,   245,   245,   243,   202,    39,   117,
      58,    39,   128,   332,   294,    45,   117,   267,    53,   295,
     130,   350,    64,   130,   321,   321,   130,   130,   222,   207,
     219,   223,   321,   391,   118,   407,   409,   192,   260,   258,
     232,   130,   130,   273,   282,   413,   414,   130,   310,   279,
     286,    52,   268,   298,    53,    55,   126,   372,   357,   130,
     130,   207,   220,   207,   192,   257,   290,   310,   192,   412,
     262,   310,   269,   207,   296,   117,   321,   219,   130,   130,
      46,   130,   264,   117,   207,   300,   130,   274,   283,   287,
     299,   117,   262,   270,   270,   270,   262,   297,   262
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
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
     381,   384,   381,   385,   381,   381,   381,   387,   386,   386,
     386,   386,   386,   386,   389,   388,   390,   388,   391,   392,
     393,   391,   391,   395,   394,   397,   396,   398,   399,   398,
     400,   398,   402,   401,   403,   404,   403,   405,   403,   406,
     406,   406,   408,   407,   407,   410,   409,   411,   409,   413,
     412,   414,   412
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
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
       3,     0,     3,     0,     3,     2,     1,     0,     4,     2,
       1,     1,     1,     1,     0,     3,     0,     4,     0,     0,
       0,     6,     1,     0,     3,     0,     3,     0,     0,     4,
       0,     3,     0,     3,     0,     0,     4,     0,     3,     1,
       1,     1,     0,     4,     3,     0,     4,     0,     4,     0,
       4,     0,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 5:
#line 151 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=insert_parameter((yyvsp[0]).ptr);}
#line 2542 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 6:
#line 152 "poet_yacc.y" /* yacc.c:1646  */
    {finish_parameter((yyvsp[-2])); }
#line 2548 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 7:
#line 153 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=GLOBAL_SCOPE; }
#line 2554 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 8:
#line 154 "poet_yacc.y" /* yacc.c:1646  */
    {eval_define(make_macroVar((yyvsp[-3]).ptr),(yyvsp[-1]).ptr); }
#line 2560 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 9:
#line 155 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=GLOBAL_VAR; }
#line 2566 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 10:
#line 155 "poet_yacc.y" /* yacc.c:1646  */
    { insert_eval((yyvsp[-1]).ptr); }
#line 2572 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 11:
#line 156 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=GLOBAL_VAR; }
#line 2578 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 12:
#line 156 "poet_yacc.y" /* yacc.c:1646  */
    { insert_cond((yyvsp[-1]).ptr); }
#line 2584 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 13:
#line 157 "poet_yacc.y" /* yacc.c:1646  */
    { insert_trace((yyvsp[-1])); }
#line 2590 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 14:
#line 158 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=insert_code((yyvsp[0]).ptr);(yyval).config=0; }
#line 2596 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 15:
#line 158 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = (yyvsp[-1]).ptr; }
#line 2602 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 17:
#line 159 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=insert_input(); }
#line 2608 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 18:
#line 159 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=(yyvsp[-1]).ptr; }
#line 2614 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 20:
#line 160 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=insert_output(); }
#line 2620 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 21:
#line 160 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=(yyvsp[-1]).ptr; }
#line 2626 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 23:
#line 161 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=insert_xform((yyvsp[0]).ptr); }
#line 2632 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 24:
#line 162 "poet_yacc.y" /* yacc.c:1646  */
    { set_xform_def((yyvsp[-2]).ptr,(yyvsp[0]).ptr); }
#line 2638 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 25:
#line 163 "poet_yacc.y" /* yacc.c:1646  */
    { insert_source((yyvsp[-1]).ptr); }
#line 2644 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 26:
#line 165 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = (yyvsp[-1]).ptr; }
#line 2650 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 29:
#line 167 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=GLOBAL_SCOPE;}
#line 2656 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 30:
#line 167 "poet_yacc.y" /* yacc.c:1646  */
    { set_input_debug((yyvsp[-4]).ptr,(yyvsp[0]).ptr); }
#line 2662 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 31:
#line 168 "poet_yacc.y" /* yacc.c:1646  */
    { set_input_target((yyvsp[-3]).ptr, (yyvsp[-3]).ptr); }
#line 2668 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 32:
#line 169 "poet_yacc.y" /* yacc.c:1646  */
    { set_input_target((yyvsp[-3]).ptr,make_varRef((yyvsp[0]).ptr,GLOBAL_VAR)); }
#line 2674 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 33:
#line 170 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=GLOBAL_SCOPE;}
#line 2680 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 34:
#line 170 "poet_yacc.y" /* yacc.c:1646  */
    {set_input_syntax((yyvsp[-4]).ptr,(yyvsp[0]).ptr);}
#line 2686 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 35:
#line 171 "poet_yacc.y" /* yacc.c:1646  */
    { set_input_codeType((yyvsp[-3]).ptr, (yyvsp[-3]).ptr); }
#line 2692 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 36:
#line 172 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=CODE_OR_XFORM_VAR; }
#line 2698 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 37:
#line 173 "poet_yacc.y" /* yacc.c:1646  */
    { set_input_codeType((yyvsp[-4]).ptr,(yyvsp[0]).ptr); }
#line 2704 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 38:
#line 174 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=GLOBAL_SCOPE;}
#line 2710 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 39:
#line 174 "poet_yacc.y" /* yacc.c:1646  */
    {set_input_files((yyvsp[-4]).ptr,(yyvsp[0]).ptr); }
#line 2716 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 40:
#line 175 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=GLOBAL_SCOPE;}
#line 2722 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 41:
#line 175 "poet_yacc.y" /* yacc.c:1646  */
    { set_input_annot((yyvsp[-4]).ptr,(yyvsp[0]).ptr); }
#line 2728 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 42:
#line 176 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=GLOBAL_SCOPE;}
#line 2734 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 43:
#line 176 "poet_yacc.y" /* yacc.c:1646  */
    { set_input_cond((yyvsp[-4]).ptr,(yyvsp[0]).ptr); }
#line 2740 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 44:
#line 178 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = (yyvsp[-1]).ptr; }
#line 2746 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 47:
#line 180 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=GLOBAL_VAR;}
#line 2752 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 48:
#line 181 "poet_yacc.y" /* yacc.c:1646  */
    { set_output_target((yyvsp[-4]).ptr,(yyvsp[0]).ptr); }
#line 2758 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 49:
#line 182 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=GLOBAL_SCOPE;}
#line 2764 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 50:
#line 183 "poet_yacc.y" /* yacc.c:1646  */
    { set_output_syntax((yyvsp[-4]).ptr,(yyvsp[0]).ptr); }
#line 2770 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 51:
#line 184 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=GLOBAL_VAR;}
#line 2776 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 52:
#line 185 "poet_yacc.y" /* yacc.c:1646  */
    { set_output_file((yyvsp[-4]).ptr,(yyvsp[0]).ptr); }
#line 2782 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 53:
#line 186 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=GLOBAL_SCOPE;}
#line 2788 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 54:
#line 187 "poet_yacc.y" /* yacc.c:1646  */
    { set_output_cond((yyvsp[-4]).ptr,(yyvsp[0]).ptr); }
#line 2794 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 55:
#line 188 "poet_yacc.y" /* yacc.c:1646  */
    { set_input_inline((yyvsp[-3]).ptr,(yyvsp[-1]).ptr);  }
#line 2800 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 58:
#line 191 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=(yyvsp[-1]).ptr; (yyval).config=(yyvsp[0]).config;}
#line 2806 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 60:
#line 192 "poet_yacc.y" /* yacc.c:1646  */
    { set_code_params((yyvsp[-5]).ptr,(yyvsp[-1]).ptr); (yyval).config=(yyvsp[-5]).config; }
#line 2812 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 61:
#line 193 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=ID_DEFAULT;}
#line 2818 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 62:
#line 193 "poet_yacc.y" /* yacc.c:1646  */
    { set_code_attr((yyvsp[-4]).ptr, (yyvsp[-3]).ptr, (yyvsp[0]).ptr); }
#line 2824 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 63:
#line 194 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=ID_DEFAULT;}
#line 2830 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 64:
#line 195 "poet_yacc.y" /* yacc.c:1646  */
    { set_local_static(make_sourceString("cond",4), (yyvsp[0]).ptr,LVAR_ATTR,(yyvsp[0]).ptr,1); (yyval).config=(yyvsp[-4]).config; }
#line 2836 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 65:
#line 196 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=ID_DEFAULT; }
#line 2842 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 66:
#line 197 "poet_yacc.y" /* yacc.c:1646  */
    { set_local_static(make_sourceString("rebuild",7), (yyvsp[0]).ptr,LVAR_ATTR,(yyvsp[0]).ptr,1); (yyval).config=(yyvsp[-4]).config; }
#line 2848 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 67:
#line 198 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=ID_DEFAULT; }
#line 2854 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 68:
#line 199 "poet_yacc.y" /* yacc.c:1646  */
    { set_code_parse((yyvsp[-4]).ptr,(yyvsp[0]).ptr); (yyval).config=(yyvsp[-4]).config; }
#line 2860 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 69:
#line 200 "poet_yacc.y" /* yacc.c:1646  */
    { set_code_lookahead((yyvsp[-3]).ptr, (yyvsp[0]).ptr); (yyval).config=(yyvsp[-3]).config; }
#line 2866 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 70:
#line 201 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=ID_DEFAULT; }
#line 2872 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 71:
#line 202 "poet_yacc.y" /* yacc.c:1646  */
    { set_local_static(make_sourceString("match",5), (yyvsp[0]).ptr,LVAR_ATTR,(yyvsp[0]).ptr,1); (yyval).config=(yyvsp[-4]).config; }
#line 2878 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 72:
#line 203 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=ID_DEFAULT; }
#line 2884 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 73:
#line 204 "poet_yacc.y" /* yacc.c:1646  */
    { set_local_static(make_sourceString("output",6), (yyvsp[0]).ptr,LVAR_ATTR,(yyvsp[0]).ptr,1); (yyval).config=(yyvsp[-4]).config; }
#line 2890 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 74:
#line 206 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2896 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 75:
#line 207 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceString("PARSE",5); }
#line 2902 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 76:
#line 209 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr= make_varRef((yyvsp[0]).ptr,(yyvsp[-1]).config); (yyval).config=(yyvsp[-1]).config; }
#line 2908 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 77:
#line 210 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_varRef((yyvsp[0]).ptr,GLOBAL_SCOPE); (yyval).config=(yyvsp[-3]).config; }
#line 2914 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 78:
#line 211 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]); }
#line 2920 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 79:
#line 212 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]); }
#line 2926 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 80:
#line 214 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_dummyOperator(POET_OP_XFORM); (yyval).config=(yyvsp[0]).config; }
#line 2932 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 81:
#line 215 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_varRef((yyvsp[0]).ptr,XFORM_VAR); (yyval).config=(yyvsp[-2]).config; }
#line 2938 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 82:
#line 217 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_dummyOperator(POET_OP_CODE); }
#line 2944 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 83:
#line 218 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_varRef((yyvsp[0]).ptr,CODE_VAR); }
#line 2950 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 84:
#line 221 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_localPar((yyvsp[0]).ptr,0,LVAR_CODEPAR); }
#line 2956 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 85:
#line 222 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=CODE_OR_XFORM_VAR; }
#line 2962 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 86:
#line 222 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_localPar((yyvsp[-3]).ptr, (yyvsp[0]).ptr,LVAR_CODEPAR); }
#line 2968 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 87:
#line 223 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = make_sourceVector((yyvsp[-2]).ptr, (yyvsp[0]).ptr); }
#line 2974 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 89:
#line 225 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=(yyvsp[-1]).ptr; }
#line 2980 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 91:
#line 226 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=GLOBAL_SCOPE;}
#line 2986 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 92:
#line 227 "poet_yacc.y" /* yacc.c:1646  */
    {set_param_type((yyvsp[-4]).ptr,(yyvsp[0]).ptr); }
#line 2992 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 93:
#line 228 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=GLOBAL_SCOPE;}
#line 2998 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 94:
#line 228 "poet_yacc.y" /* yacc.c:1646  */
    { set_param_default((yyvsp[-4]).ptr, (yyvsp[0]).ptr); }
#line 3004 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 95:
#line 229 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=GLOBAL_SCOPE; }
#line 3010 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 96:
#line 229 "poet_yacc.y" /* yacc.c:1646  */
    { set_param_parse((yyvsp[-4]).ptr, (yyvsp[0]).ptr); }
#line 3016 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 97:
#line 230 "poet_yacc.y" /* yacc.c:1646  */
    { set_param_message((yyvsp[-3]).ptr, (yyvsp[0]).ptr); }
#line 3022 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 98:
#line 233 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config; }
#line 3028 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 99:
#line 234 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-5]).config; }
#line 3034 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 100:
#line 235 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_MAP, (yyvsp[-4]).ptr, (yyvsp[-1]).ptr); }
#line 3040 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 101:
#line 236 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_dummyOperator(POET_OP_MAP); }
#line 3046 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 102:
#line 237 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_dummyOperator(POET_OP_MAP); }
#line 3052 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 103:
#line 238 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_dummyOperator(POET_OP_MAP); }
#line 3058 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 104:
#line 240 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=make_sourceUop(POET_OP_MAP, (yyvsp[-1]).ptr); }
#line 3064 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 105:
#line 243 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceVector2((yyvsp[-2]).ptr,(yyvsp[0]).ptr); }
#line 3070 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 106:
#line 245 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_inputlist((yyvsp[-4]).ptr,make_sourceVector2((yyvsp[-2]).ptr,(yyvsp[0]).ptr)); }
#line 3076 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 107:
#line 247 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=(yyvsp[0]).ptr; }
#line 3082 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 108:
#line 248 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_any(); }
#line 3088 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 109:
#line 249 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_type(TYPE_INT); }
#line 3094 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 110:
#line 250 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_type(TYPE_FLOAT); }
#line 3100 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 111:
#line 251 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_type(TYPE_STRING); }
#line 3106 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 112:
#line 252 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_type(TYPE_ID); }
#line 3112 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 113:
#line 253 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_dummyOperator(POET_OP_EXP); }
#line 3118 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 114:
#line 254 "poet_yacc.y" /* yacc.c:1646  */
    {  (yyval).ptr = make_dummyOperator(POET_OP_VAR); }
#line 3124 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 115:
#line 255 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_dummyOperator(POET_OP_TUPLE); }
#line 3130 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 116:
#line 256 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 3136 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 117:
#line 258 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]); }
#line 3142 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 118:
#line 259 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = negate_Iconst((yyvsp[0]).ptr); }
#line 3148 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 119:
#line 260 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_sourceUop(POET_OP_APPLY, (yyvsp[-1]).ptr); }
#line 3154 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 120:
#line 261 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=(yyvsp[0]).ptr; }
#line 3160 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 121:
#line 262 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config; }
#line 3166 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 122:
#line 263 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_sourceAssign(make_varRef((yyvsp[-3]).ptr,ASSIGN_VAR), (yyvsp[0]).ptr); }
#line 3172 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 123:
#line 264 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_typeNot((yyvsp[0])); }
#line 3178 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 124:
#line 265 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 3184 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 125:
#line 265 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[-1]).ptr; }
#line 3190 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 126:
#line 267 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]); }
#line 3196 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 127:
#line 268 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3202 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 128:
#line 269 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_typeTor((yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 3208 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 129:
#line 271 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config; }
#line 3214 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 130:
#line 271 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = ((yyvsp[0]).ptr==0)? (yyvsp[-2]).ptr : make_typelist2((yyvsp[-2]).ptr,(yyvsp[0]).ptr); }
#line 3220 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 131:
#line 272 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[0]).ptr; }
#line 3226 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 132:
#line 273 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = make_typeUop(TYPE_LIST1, (yyvsp[-1]).ptr); }
#line 3232 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 133:
#line 274 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = make_typeUop(TYPE_LIST, (yyvsp[-1]).ptr); }
#line 3238 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 134:
#line 275 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3244 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 135:
#line 276 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = make_sourceBop(POET_OP_RANGE, (yyvsp[-3]).ptr,(yyvsp[0]).ptr);}
#line 3250 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 136:
#line 277 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3256 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 137:
#line 278 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_sourceBop(POET_OP_PLUS, (yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 3262 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 138:
#line 279 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3268 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 139:
#line 280 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_MULT,  (yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 3274 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 140:
#line 281 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3280 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 141:
#line 282 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_DIVIDE,  (yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 3286 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 142:
#line 283 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3292 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 143:
#line 283 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_MOD,  (yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 3298 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 144:
#line 284 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3304 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 145:
#line 284 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_CONS,(yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 3310 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 146:
#line 286 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=0; }
#line 3316 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 147:
#line 287 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config; }
#line 3322 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 148:
#line 287 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_typelist2((yyvsp[-2]).ptr,(yyvsp[0]).ptr); }
#line 3328 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 149:
#line 288 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3334 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 150:
#line 289 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceVector2((yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 3340 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 151:
#line 290 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3346 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 152:
#line 290 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceVector((yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 3352 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 153:
#line 292 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]); }
#line 3358 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 154:
#line 293 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = negate_Iconst((yyvsp[0]).ptr); }
#line 3364 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 155:
#line 294 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceUop(POET_OP_CLEAR, make_varRef((yyvsp[0]).ptr,ASSIGN_VAR)); }
#line 3370 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 156:
#line 295 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=(yyvsp[0]).ptr; }
#line 3376 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 157:
#line 296 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 3382 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 158:
#line 296 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[-1]).ptr; }
#line 3388 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 159:
#line 297 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3394 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 160:
#line 298 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_typeTor((yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 3400 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 161:
#line 299 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = make_typeUop(TYPE_LIST, (yyvsp[-1]).ptr); }
#line 3406 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 162:
#line 300 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3412 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 163:
#line 301 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = make_sourceBop(POET_OP_RANGE, (yyvsp[-3]).ptr,(yyvsp[0]).ptr);}
#line 3418 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 164:
#line 302 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3424 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 165:
#line 303 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_sourceBop(POET_OP_PLUS, (yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 3430 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 166:
#line 304 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3436 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 167:
#line 305 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_MULT,  (yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 3442 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 168:
#line 306 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3448 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 169:
#line 307 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_DIVIDE,  (yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 3454 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 170:
#line 308 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3460 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 171:
#line 309 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_MOD,  (yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 3466 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 172:
#line 310 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3472 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 173:
#line 310 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_CONS,(yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 3478 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 174:
#line 311 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3484 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 175:
#line 311 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_sourceAssign(make_varRef((yyvsp[-3]).ptr,ASSIGN_VAR), (yyvsp[0]).ptr); }
#line 3490 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 176:
#line 313 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config; }
#line 3496 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 177:
#line 313 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = ((yyvsp[0]).ptr==0)? (yyvsp[-2]).ptr : make_typelist2((yyvsp[-2]).ptr,(yyvsp[0]).ptr); }
#line 3502 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 178:
#line 314 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[0]).ptr; }
#line 3508 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 179:
#line 316 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=0; }
#line 3514 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 180:
#line 317 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config; }
#line 3520 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 181:
#line 317 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_typelist2((yyvsp[-2]).ptr,(yyvsp[0]).ptr); }
#line 3526 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 182:
#line 318 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3532 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 183:
#line 319 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceVector2((yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 3538 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 184:
#line 320 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3544 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 185:
#line 320 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceVector((yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 3550 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 186:
#line 322 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=(yyvsp[0]).ptr; }
#line 3556 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 187:
#line 323 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[0]).ptr; }
#line 3562 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 188:
#line 324 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[0]).ptr; }
#line 3568 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 189:
#line 325 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_empty_list(); }
#line 3574 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 190:
#line 327 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config; }
#line 3580 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 191:
#line 327 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-4]).config;}
#line 3586 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 192:
#line 327 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceUop(POET_OP_TUPLE, make_typelist2((yyvsp[-3]).ptr,(yyvsp[-1]).ptr)); }
#line 3592 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 193:
#line 328 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config; }
#line 3598 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 194:
#line 328 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-5]).config;}
#line 3604 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 195:
#line 328 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_LIST,(yyvsp[-4]).ptr,(yyvsp[-1]).ptr); }
#line 3610 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 196:
#line 329 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config; }
#line 3616 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 197:
#line 329 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-5]).config;}
#line 3622 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 198:
#line 329 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_LIST1,(yyvsp[-4]).ptr,(yyvsp[-1]).ptr); }
#line 3628 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 199:
#line 331 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]); }
#line 3634 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 200:
#line 332 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 3640 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 201:
#line 333 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3646 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 202:
#line 334 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_typeTor((yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 3652 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 203:
#line 335 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = make_typeUop(TYPE_LIST1, (yyvsp[-1]).ptr); }
#line 3658 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 204:
#line 336 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = make_typeUop(TYPE_LIST, (yyvsp[-1]).ptr); }
#line 3664 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 205:
#line 338 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 3670 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 206:
#line 339 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=(yyvsp[0]).ptr; }
#line 3676 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 207:
#line 340 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_typeNot((yyvsp[0])); }
#line 3682 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 208:
#line 341 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3688 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 209:
#line 342 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config; }
#line 3694 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 210:
#line 343 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_sourceAssign(make_varRef((yyvsp[-3]).ptr,ASSIGN_VAR), (yyvsp[0]).ptr); }
#line 3700 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 211:
#line 344 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3706 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 212:
#line 345 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_typeTor((yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 3712 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 213:
#line 346 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 3718 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 214:
#line 346 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[-1]).ptr; }
#line 3724 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 215:
#line 348 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config; }
#line 3730 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 216:
#line 348 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = ((yyvsp[0]).ptr==0)? (yyvsp[-2]).ptr : make_typelist2((yyvsp[-2]).ptr,(yyvsp[0]).ptr); }
#line 3736 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 217:
#line 349 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[0]).ptr; }
#line 3742 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 218:
#line 350 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3748 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 219:
#line 351 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceVector2((yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 3754 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 220:
#line 352 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3760 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 221:
#line 352 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceVector((yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 3766 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 222:
#line 353 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=0; }
#line 3772 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 223:
#line 354 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config; }
#line 3778 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 224:
#line 354 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_typelist2((yyvsp[-2]).ptr,(yyvsp[0]).ptr); }
#line 3784 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 225:
#line 356 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=(yyvsp[0]).ptr; }
#line 3790 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 226:
#line 357 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3796 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 227:
#line 359 "poet_yacc.y" /* yacc.c:1646  */
    {yaccState=YACC_CODE; (yyval).config=ID_DEFAULT;}
#line 3802 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 228:
#line 359 "poet_yacc.y" /* yacc.c:1646  */
    { yaccState=YACC_DEFAULT; set_code_def((yyvsp[-4]).ptr,(yyvsp[-1]).ptr); }
#line 3808 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 229:
#line 360 "poet_yacc.y" /* yacc.c:1646  */
    { set_code_def((yyvsp[-1]).ptr, 0); }
#line 3814 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 230:
#line 361 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=ID_DEFAULT; }
#line 3820 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 231:
#line 361 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=(yyvsp[-1]).ptr; }
#line 3826 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 232:
#line 362 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = 0; }
#line 3832 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 234:
#line 363 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]); }
#line 3838 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 236:
#line 364 "poet_yacc.y" /* yacc.c:1646  */
    {set_xform_params((yyvsp[-5]).ptr,(yyvsp[-1]).ptr); }
#line 3844 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 237:
#line 365 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=0;}
#line 3850 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 239:
#line 366 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=CODE_VAR;}
#line 3856 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 240:
#line 366 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = set_local_static((yyvsp[-3]).ptr,(yyvsp[0]).ptr,LVAR_TUNE,0,1); }
#line 3862 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 241:
#line 367 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_localPar((yyvsp[0]).ptr,0,LVAR_XFORMPAR); }
#line 3868 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 242:
#line 368 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=CODE_VAR;}
#line 3874 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 243:
#line 368 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_localPar((yyvsp[-3]).ptr, (yyvsp[0]).ptr,LVAR_XFORMPAR); }
#line 3880 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 244:
#line 369 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = make_sourceVector((yyvsp[-2]).ptr, (yyvsp[0]).ptr); }
#line 3886 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 245:
#line 370 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = (yyvsp[-2]).ptr + 1; }
#line 3892 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 248:
#line 371 "poet_yacc.y" /* yacc.c:1646  */
    { set_local_static((yyvsp[0]).ptr,make_Iconst1((yyvsp[-1]).ptr), LVAR_OUTPUT,0,1); }
#line 3898 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 249:
#line 372 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=CODE_VAR;}
#line 3904 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 250:
#line 372 "poet_yacc.y" /* yacc.c:1646  */
    { set_local_static((yyvsp[-3]).ptr,make_Iconst1((yyvsp[-4]).ptr), LVAR_OUTPUT,(yyvsp[0]).ptr,1); }
#line 3910 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 251:
#line 373 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_traceVar((yyvsp[0]).ptr,0); }
#line 3916 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 252:
#line 374 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_traceVar((yyvsp[-2]).ptr,0); eval_define((yyval).ptr,(yyvsp[0]).ptr); }
#line 3922 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 253:
#line 376 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_traceVar((yyvsp[-2]).ptr,(yyvsp[0]).ptr);  }
#line 3928 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 254:
#line 378 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 3934 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 255:
#line 378 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_seq((yyvsp[-2]).ptr, (yyvsp[0]).ptr); }
#line 3940 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 256:
#line 379 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=(yyvsp[0]).ptr; }
#line 3946 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 257:
#line 380 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[0]).ptr; }
#line 3952 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 258:
#line 381 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 3958 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 259:
#line 381 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-5]).config;}
#line 3964 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 260:
#line 381 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-7]).config;}
#line 3970 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 261:
#line 382 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_ifElse((yyvsp[-5]).ptr, (yyvsp[-2]).ptr, (yyvsp[0]).ptr); }
#line 3976 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 262:
#line 383 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 3982 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 263:
#line 384 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_empty(); }
#line 3988 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 264:
#line 385 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 3994 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 265:
#line 385 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[0]).ptr; }
#line 4000 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 266:
#line 386 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4006 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 267:
#line 387 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-5]).config;}
#line 4012 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 268:
#line 388 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-8]).config;}
#line 4018 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 269:
#line 388 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-11]).config;}
#line 4024 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 270:
#line 389 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceQop(POET_OP_FOR, (yyvsp[-9]).ptr,(yyvsp[-6]).ptr,(yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 4030 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 271:
#line 390 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4036 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 272:
#line 390 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-6]).config;}
#line 4042 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 273:
#line 391 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_CASE, (yyvsp[-5]).ptr,(yyvsp[-1]).ptr); }
#line 4048 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 274:
#line 392 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 4054 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 275:
#line 392 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-4]).config;}
#line 4060 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 276:
#line 392 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-8]).config;}
#line 4066 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 277:
#line 393 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_sourceQop(POET_OP_FOREACH,(yyvsp[-5]).ptr,(yyvsp[-8]).ptr,(yyvsp[-4]).ptr,(yyvsp[-1]).ptr); }
#line 4072 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 278:
#line 394 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4078 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 279:
#line 395 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-5]).config;}
#line 4084 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 280:
#line 396 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-8]).config;}
#line 4090 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 281:
#line 396 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-11]).config;}
#line 4096 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 282:
#line 397 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceQop(POET_OP_FOREACH, (yyvsp[-9]).ptr,(yyvsp[-6]).ptr,(yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 4102 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 283:
#line 398 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4108 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 284:
#line 399 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-5]).config;}
#line 4114 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 285:
#line 400 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-8]).config;}
#line 4120 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 286:
#line 400 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-11]).config;}
#line 4126 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 287:
#line 401 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceQop(POET_OP_FOREACH, make_sourceUop(POET_OP_REVERSE,(yyvsp[-9]).ptr),(yyvsp[-6]).ptr,(yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 4132 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 288:
#line 402 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config; }
#line 4138 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 289:
#line 402 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[-1]).ptr; }
#line 4144 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 290:
#line 403 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_empty(); }
#line 4150 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 291:
#line 404 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_empty(); }
#line 4156 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 292:
#line 405 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceStmt((yyvsp[-1]).ptr); }
#line 4162 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 293:
#line 407 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=(yyvsp[0]).ptr; }
#line 4168 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 294:
#line 408 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_sourceUop(POET_OP_REVERSE,(yyvsp[-1]).ptr); }
#line 4174 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 295:
#line 410 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[0]).ptr; }
#line 4180 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 296:
#line 411 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_empty(); }
#line 4186 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 297:
#line 414 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config; }
#line 4192 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 298:
#line 415 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_sourceAssign(make_varRef((yyvsp[-3]).ptr,ASSIGN_VAR), (yyvsp[0]).ptr); }
#line 4198 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 299:
#line 416 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=(yyvsp[0]).ptr;}
#line 4204 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 300:
#line 418 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_Iconst1(1); }
#line 4210 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 301:
#line 419 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 4216 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 302:
#line 419 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=(yyvsp[0]).ptr; }
#line 4222 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 303:
#line 421 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4228 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 304:
#line 421 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-5]).config;}
#line 4234 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 305:
#line 422 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = make_sourceVector( (yyvsp[-6]).ptr, make_inputlist((yyvsp[-3]).ptr,(yyvsp[0]).ptr)); }
#line 4240 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 306:
#line 423 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 4246 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 307:
#line 423 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-4]).config;}
#line 4252 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 308:
#line 423 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_inputlist((yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 4258 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 309:
#line 424 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-3]).config;}
#line 4264 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 310:
#line 425 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = make_sourceVector( (yyvsp[-4]).ptr, make_inputlist(make_any(),(yyvsp[0]).ptr)); }
#line 4270 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 311:
#line 427 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[0]).ptr; }
#line 4276 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 312:
#line 428 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[0]).ptr; }
#line 4282 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 313:
#line 430 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4288 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 314:
#line 430 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = make_sourceVector((yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 4294 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 315:
#line 431 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4300 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 316:
#line 431 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceVector2((yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 4306 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 317:
#line 434 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_dummyOperator(POET_OP_CONTINUE); }
#line 4312 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 318:
#line 435 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_dummyOperator(POET_OP_BREAK); }
#line 4318 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 319:
#line 436 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 4324 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 320:
#line 436 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_sourceUop(POET_OP_RETURN, (yyvsp[0]).ptr); }
#line 4330 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 321:
#line 437 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 4336 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 322:
#line 437 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceUop(POET_OP_ERROR,(yyvsp[0]).ptr); }
#line 4342 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 323:
#line 438 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 4348 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 324:
#line 438 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceUop(POET_OP_ASSERT,(yyvsp[0]).ptr); }
#line 4354 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 325:
#line 439 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 4360 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 326:
#line 439 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_sourceUop(POET_OP_PRINT,(yyvsp[0]).ptr); }
#line 4366 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 327:
#line 440 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[0]).ptr; }
#line 4372 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 328:
#line 442 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[0]).ptr; }
#line 4378 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 329:
#line 443 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4384 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 330:
#line 443 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_sourceAssign((yyvsp[-3]).ptr, (yyvsp[0]).ptr); }
#line 4390 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 331:
#line 444 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4396 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 332:
#line 444 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_codeMatch((yyvsp[-3]).ptr, (yyvsp[0]).ptr); }
#line 4402 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 333:
#line 445 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4408 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 334:
#line 446 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_sourceAssign((yyvsp[-3]).ptr, make_sourceBop(POET_OP_PLUS, (yyvsp[-3]).ptr,(yyvsp[0]).ptr)); }
#line 4414 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 335:
#line 447 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4420 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 336:
#line 448 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_sourceAssign((yyvsp[-3]).ptr, make_sourceBop(POET_OP_MINUS, (yyvsp[-3]).ptr,(yyvsp[0]).ptr)); }
#line 4426 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 337:
#line 449 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4432 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 338:
#line 450 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_sourceAssign((yyvsp[-3]).ptr, make_sourceBop(POET_OP_MULT, (yyvsp[-3]).ptr,(yyvsp[0]).ptr)); }
#line 4438 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 339:
#line 451 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4444 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 340:
#line 452 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_sourceAssign((yyvsp[-3]).ptr, make_sourceBop(POET_OP_DIVIDE, (yyvsp[-3]).ptr,(yyvsp[0]).ptr)); }
#line 4450 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 341:
#line 453 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4456 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 342:
#line 454 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_sourceAssign((yyvsp[-3]).ptr, make_sourceBop(POET_OP_MOD, (yyvsp[-3]).ptr,(yyvsp[0]).ptr)); }
#line 4462 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 343:
#line 455 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4468 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 344:
#line 455 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_codeMatchQ((yyvsp[-3]).ptr, (yyvsp[0]).ptr); }
#line 4474 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 345:
#line 456 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4480 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 346:
#line 456 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-5]).config;}
#line 4486 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 347:
#line 457 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_ifElse( (yyvsp[-6]).ptr, (yyvsp[-3]).ptr, (yyvsp[0]).ptr); }
#line 4492 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 348:
#line 460 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4498 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 349:
#line 460 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_AND,  (yyvsp[-3]).ptr, (yyvsp[0]).ptr); }
#line 4504 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 350:
#line 461 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4510 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 351:
#line 461 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_OR,   (yyvsp[-3]).ptr, (yyvsp[0]).ptr); }
#line 4516 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 352:
#line 462 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 4522 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 353:
#line 462 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceUop(POET_OP_NOT, (yyvsp[0]).ptr); }
#line 4528 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 354:
#line 463 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4534 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 355:
#line 463 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_LT, (yyvsp[-3]).ptr, (yyvsp[0]).ptr); }
#line 4540 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 356:
#line 464 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4546 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 357:
#line 464 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_LE, (yyvsp[-3]).ptr, (yyvsp[0]).ptr); }
#line 4552 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 358:
#line 465 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4558 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 359:
#line 465 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_EQ, (yyvsp[-3]).ptr, (yyvsp[0]).ptr); }
#line 4564 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 360:
#line 466 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4570 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 361:
#line 467 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_GT,   (yyvsp[-3]).ptr, (yyvsp[0]).ptr); }
#line 4576 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 362:
#line 468 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4582 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 363:
#line 469 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_GE,   (yyvsp[-3]).ptr, (yyvsp[0]).ptr); }
#line 4588 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 364:
#line 470 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4594 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 365:
#line 471 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_NE,   (yyvsp[-3]).ptr, (yyvsp[0]).ptr); }
#line 4600 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 366:
#line 472 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4606 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 367:
#line 472 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_ASTMATCH, (yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 4612 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 368:
#line 473 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[0]).ptr; }
#line 4618 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 369:
#line 475 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[0]).ptr; }
#line 4624 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 370:
#line 476 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4630 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 371:
#line 477 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_sourceBop(POET_OP_PLUS, (yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 4636 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 372:
#line 478 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4642 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 373:
#line 479 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_MINUS,  (yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 4648 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 374:
#line 480 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4654 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 375:
#line 481 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_MULT,  (yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 4660 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 376:
#line 482 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4666 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 377:
#line 483 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_CONCAT, (yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 4672 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 378:
#line 484 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4678 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 379:
#line 485 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_DIVIDE,  (yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 4684 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 380:
#line 486 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4690 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 381:
#line 487 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_MOD,  (yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 4696 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 382:
#line 488 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4702 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 383:
#line 488 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_CONS,(yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 4708 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 384:
#line 489 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 4714 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 385:
#line 489 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceUop(POET_OP_UMINUS,(yyvsp[0]).ptr); }
#line 4720 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 386:
#line 491 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 4726 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 387:
#line 492 "poet_yacc.y" /* yacc.c:1646  */
    { if ((yyvsp[0]).ptr==0) (yyval).ptr=(yyvsp[-2]).ptr; else (yyval).ptr = make_xformList((yyvsp[-2]).ptr, (yyvsp[0]).ptr); }
#line 4732 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 388:
#line 494 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config; }
#line 4738 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 389:
#line 494 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr =make_xformList((yyvsp[-2]).ptr,(yyvsp[0]).ptr);}
#line 4744 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 390:
#line 495 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=0; }
#line 4750 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 391:
#line 496 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config; }
#line 4756 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 392:
#line 496 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr =make_xformList((yyvsp[-2]).ptr,(yyvsp[0]).ptr);}
#line 4762 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 393:
#line 497 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=0; }
#line 4768 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 394:
#line 499 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4774 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 395:
#line 499 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-5]).config;}
#line 4780 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 396:
#line 499 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-7]).config;}
#line 4786 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 397:
#line 500 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=((yyvsp[0]).ptr==0)? make_sourceBop(POET_OP_REPLACE,(yyvsp[-5]).ptr,(yyvsp[-2]).ptr) 
                       : make_sourceTop(POET_OP_REPLACE,(yyvsp[-5]).ptr,(yyvsp[-2]).ptr,(yyvsp[0]).ptr); }
#line 4793 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 398:
#line 502 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4799 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 399:
#line 502 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-4]).config;}
#line 4805 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 400:
#line 503 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=((yyvsp[0]).ptr==0)? make_sourceUop(POET_OP_TRACE,(yyvsp[-2]).ptr)
                      : make_sourceBop(POET_OP_TRACE,(yyvsp[-2]).ptr,(yyvsp[0]).ptr); }
#line 4812 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 401:
#line 505 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4818 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 402:
#line 505 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-5]).config;}
#line 4824 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 403:
#line 506 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_sourceBop(POET_OP_PERMUTE,(yyvsp[-4]).ptr,(yyvsp[-1]).ptr); }
#line 4830 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 404:
#line 507 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4836 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 405:
#line 507 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-5]).config;}
#line 4842 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 406:
#line 507 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-8]).config;}
#line 4848 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 407:
#line 508 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_sourceTop(POET_OP_DUPLICATE,(yyvsp[-7]).ptr,(yyvsp[-4]).ptr,(yyvsp[-1]).ptr); }
#line 4854 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 408:
#line 509 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 4860 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 409:
#line 509 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceUop(POET_OP_COPY, (yyvsp[0]).ptr); }
#line 4866 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 410:
#line 510 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4872 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 411:
#line 511 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-4]).config;(yyval).ptr=(yyvsp[0]).ptr; }
#line 4878 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 412:
#line 512 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = make_sourceBop(POET_OP_ERASE,(yyvsp[-2]).ptr,(yyvsp[0]).ptr); }
#line 4884 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 413:
#line 513 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4890 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 414:
#line 513 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceUop(POET_OP_DELAY, (yyvsp[-1]).ptr); }
#line 4896 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 415:
#line 514 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4902 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 416:
#line 514 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-5]).config;}
#line 4908 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 417:
#line 515 "poet_yacc.y" /* yacc.c:1646  */
    {  (yyval).ptr=make_sourceBop(POET_OP_INSERT, (yyvsp[-4]).ptr,(yyvsp[-1]).ptr); }
#line 4914 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 418:
#line 516 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-3]).config;}
#line 4920 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 419:
#line 517 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_DEBUG,(yyvsp[-4]).ptr,(yyvsp[-1]).ptr); }
#line 4926 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 420:
#line 518 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4932 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 421:
#line 518 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceUop(POET_OP_APPLY, (yyvsp[-1]).ptr); }
#line 4938 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 422:
#line 519 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 4944 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 423:
#line 519 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceUop(POET_OP_REBUILD,(yyvsp[0]).ptr); }
#line 4950 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 424:
#line 520 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 4956 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 425:
#line 520 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceUop(POET_OP_RESTORE,(yyvsp[0]).ptr); }
#line 4962 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 426:
#line 521 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 4968 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 427:
#line 521 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceUop(POET_OP_SAVE,(yyvsp[0]).ptr); }
#line 4974 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 428:
#line 522 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 4980 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 429:
#line 522 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-5]).config;}
#line 4986 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 430:
#line 523 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceBop(POET_OP_SPLIT, (yyvsp[-4]).ptr,(yyvsp[-1]).ptr); }
#line 4992 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 431:
#line 524 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = make_typeUop(TYPE_LIST, (yyvsp[-1]).ptr); }
#line 4998 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 432:
#line 525 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 5004 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 433:
#line 526 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = make_sourceBop(POET_OP_RANGE, (yyvsp[-3]).ptr,(yyvsp[0]).ptr);}
#line 5010 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 434:
#line 528 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = make_sourceBop(POET_OP_RANGE, (yyvsp[-3]).ptr,(yyvsp[0]).ptr);}
#line 5016 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 435:
#line 529 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[0]).ptr; }
#line 5022 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 436:
#line 530 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = 0; }
#line 5028 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 437:
#line 530 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 5034 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 438:
#line 530 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[-1]).ptr; }
#line 5040 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 439:
#line 532 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 5046 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 440:
#line 532 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[-1]).ptr; }
#line 5052 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 441:
#line 533 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[-1]).ptr; }
#line 5058 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 442:
#line 535 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = make_Iconst1(1); }
#line 5064 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 443:
#line 536 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[-1]).ptr; }
#line 5070 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 444:
#line 538 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = 0; }
#line 5076 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 445:
#line 539 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_inputlist((yyvsp[-1]).ptr,(yyvsp[0]).ptr); }
#line 5082 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 446:
#line 540 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=CODE_OR_XFORM_VAR;}
#line 5088 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 447:
#line 540 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_annot_single((yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 5094 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 448:
#line 541 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=CODE_OR_XFORM_VAR; }
#line 5100 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 449:
#line 542 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_annot_lbegin((yyvsp[-5]).ptr,(yyvsp[-1]).ptr); }
#line 5106 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 450:
#line 543 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=CODE_OR_XFORM_VAR; }
#line 5112 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 451:
#line 544 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_inputlist((yyvsp[-5]).ptr,make_sourceUop(POET_OP_ANNOT,(yyvsp[-1]).ptr)); }
#line 5118 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 452:
#line 545 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_inputlist((yyvsp[-1]).ptr, (yyvsp[0]).ptr); }
#line 5124 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 453:
#line 546 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_inputlist((yyvsp[-1]).ptr, (yyvsp[0]).ptr); }
#line 5130 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 454:
#line 547 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_inputlist((yyvsp[-1]).ptr, (yyvsp[0]).ptr); }
#line 5136 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 455:
#line 548 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_inputlist((yyvsp[-1]).ptr, (yyvsp[0]).ptr); }
#line 5142 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 456:
#line 549 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_inputlist((yyvsp[-1]).ptr,make_varRef((yyvsp[0]).ptr,GLOBAL_VAR)); }
#line 5148 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 457:
#line 552 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 5154 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 458:
#line 552 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceUop(POET_OP_CAR, (yyvsp[0]).ptr); }
#line 5160 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 459:
#line 553 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 5166 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 460:
#line 553 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceUop(POET_OP_CDR, (yyvsp[0]).ptr); }
#line 5172 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 461:
#line 554 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 5178 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 462:
#line 554 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceUop(POET_OP_LEN, (yyvsp[0]).ptr); }
#line 5184 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 463:
#line 555 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 5190 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 464:
#line 555 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceUop(TYPE_INT, (yyvsp[0]).ptr); }
#line 5196 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 465:
#line 556 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceUop(POET_OP_CLEAR, make_varRef((yyvsp[0]).ptr,ASSIGN_VAR)); }
#line 5202 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 466:
#line 557 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=(yyvsp[0]).ptr; }
#line 5208 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 467:
#line 560 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config;}
#line 5214 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 468:
#line 560 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=(yyvsp[-1]).ptr; }
#line 5220 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 469:
#line 561 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=make_empty(); }
#line 5226 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 470:
#line 562 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr=(yyvsp[0]).ptr; }
#line 5232 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 471:
#line 563 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_any(); }
#line 5238 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 472:
#line 564 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 5244 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 473:
#line 565 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]); }
#line 5250 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 474:
#line 567 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=(yyvsp[0]).ptr; (yyval).config=(yyvsp[-1]).config; }
#line 5256 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 475:
#line 567 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 5262 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 476:
#line 568 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config; }
#line 5268 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 477:
#line 568 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_typeTor((yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 5274 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 478:
#line 569 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]); }
#line 5280 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 479:
#line 570 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config; (yyval).ptr=(yyvsp[-1]).ptr; }
#line 5286 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 480:
#line 571 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_tupleAccess((yyvsp[-4]).ptr, (yyvsp[-1]).ptr); (yyval).config=(yyvsp[-4]).config; }
#line 5292 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 481:
#line 572 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 5298 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 482:
#line 573 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 5304 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 483:
#line 575 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config; }
#line 5310 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 484:
#line 576 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_codeRef((yyvsp[-3]).ptr,(yyvsp[0]).ptr,(yyvsp[-3]).config); (yyval).config=(yyvsp[-3]).config; }
#line 5316 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 485:
#line 578 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=(yyvsp[0]).ptr; (yyval).config=(yyvsp[-1]).config; }
#line 5322 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 486:
#line 578 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 5328 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 487:
#line 580 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]); }
#line 5334 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 488:
#line 581 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config; (yyval).ptr=(yyvsp[-1]).ptr; }
#line 5340 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 489:
#line 582 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_tupleAccess((yyvsp[-4]).ptr, (yyvsp[-1]).ptr); (yyval).config=(yyvsp[-4]).config; }
#line 5346 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 490:
#line 583 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config; }
#line 5352 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 491:
#line 584 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_codeRef((yyvsp[-3]).ptr,(yyvsp[0]).ptr,(yyvsp[-3]).config);(yyval).config=(yyvsp[-3]).config; }
#line 5358 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 492:
#line 586 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=(yyvsp[0]).ptr; (yyval).config=(yyvsp[-1]).config; }
#line 5364 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 493:
#line 586 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 5370 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 494:
#line 587 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]); }
#line 5376 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 495:
#line 588 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config; (yyval).ptr=(yyvsp[-1]).ptr; }
#line 5382 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 496:
#line 589 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_tupleAccess((yyvsp[-4]).ptr, (yyvsp[-1]).ptr); (yyval).config=(yyvsp[-4]).config; }
#line 5388 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 497:
#line 590 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-1]).config; }
#line 5394 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 498:
#line 591 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_codeRef((yyvsp[-3]).ptr,(yyvsp[0]).ptr,(yyvsp[-3]).config);(yyval).config=(yyvsp[-3]).config; }
#line 5400 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 499:
#line 593 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=(yyvsp[0]).ptr;}
#line 5406 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 500:
#line 594 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = (yyvsp[0]).ptr; }
#line 5412 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 501:
#line 595 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr = (yyvsp[0]).ptr; }
#line 5418 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 502:
#line 597 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 5424 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 503:
#line 598 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_typeTor((yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 5430 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 504:
#line 599 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_attrAccess(make_varRef((yyvsp[-2]).ptr,CODE_OR_XFORM_VAR), (yyvsp[0]).ptr); }
#line 5436 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 505:
#line 602 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 5442 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 506:
#line 603 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceAssign( make_attrAccess((yyvsp[-4]).ptr,(yyvsp[-3]).ptr),(yyvsp[0]).ptr); }
#line 5448 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 507:
#line 604 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=(yyvsp[-2]).ptr; (yyval).config=(yyvsp[-2]).config;}
#line 5454 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 508:
#line 605 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_seq((yyvsp[-3]).ptr,(yyvsp[0]).ptr); }
#line 5460 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 509:
#line 608 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).config=(yyvsp[-2]).config;}
#line 5466 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 510:
#line 609 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_sourceAssign( make_attrAccess((yyvsp[-4]).ptr,(yyvsp[-3]).ptr),(yyvsp[0]).ptr); }
#line 5472 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 511:
#line 610 "poet_yacc.y" /* yacc.c:1646  */
    {(yyval).ptr=(yyvsp[-2]).ptr; (yyval).config=(yyvsp[-2]).config;}
#line 5478 "poet_yacc.c" /* yacc.c:1646  */
    break;

  case 512:
#line 611 "poet_yacc.y" /* yacc.c:1646  */
    { (yyval).ptr = make_seq((yyvsp[-3]).ptr, (yyvsp[0]).ptr);}
#line 5484 "poet_yacc.c" /* yacc.c:1646  */
    break;


#line 5488 "poet_yacc.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 612 "poet_yacc.y" /* yacc.c:1906  */

