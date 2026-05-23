/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     INT_CONSTANT = 259,
     FLOAT_CONSTANT = 260,
     STRING_CONSTANT = 261,
     CHAR_CONSTANT = 262,
     BOOLEAN = 263,
     CHAR = 264,
     INT = 265,
     FLOAT = 266,
     STRING = 267,
     VOID = 268,
     STATIC = 269,
     FINAL = 270,
     CLASS = 271,
     NEW = 272,
     PUBLIC = 273,
     PROTECTED = 274,
     PRIVATE = 275,
     IF = 276,
     ELSE = 277,
     WHILE = 278,
     FOR = 279,
     RETURN = 280,
     PRINT = 281,
     READ = 282,
     TRUE = 283,
     FALSE = 284,
     NULLTOK = 285,
     INC = 286,
     DEC = 287,
     EQ = 288,
     NEQ = 289,
     GE = 290,
     LE = 291,
     AND = 292,
     OR = 293,
     LOWER_THAN_ELSE = 294,
     PREDEC = 295,
     PREINC = 296,
     UPLUS = 297,
     UMINUS = 298,
     POSTDEC = 299,
     POSTINC = 300
   };
#endif
/* Tokens.  */
#define ID 258
#define INT_CONSTANT 259
#define FLOAT_CONSTANT 260
#define STRING_CONSTANT 261
#define CHAR_CONSTANT 262
#define BOOLEAN 263
#define CHAR 264
#define INT 265
#define FLOAT 266
#define STRING 267
#define VOID 268
#define STATIC 269
#define FINAL 270
#define CLASS 271
#define NEW 272
#define PUBLIC 273
#define PROTECTED 274
#define PRIVATE 275
#define IF 276
#define ELSE 277
#define WHILE 278
#define FOR 279
#define RETURN 280
#define PRINT 281
#define READ 282
#define TRUE 283
#define FALSE 284
#define NULLTOK 285
#define INC 286
#define DEC 287
#define EQ 288
#define NEQ 289
#define GE 290
#define LE 291
#define AND 292
#define OR 293
#define LOWER_THAN_ELSE 294
#define PREDEC 295
#define PREINC 296
#define UPLUS 297
#define UMINUS 298
#define POSTDEC 299
#define POSTINC 300




/* Copy the first part of user declarations.  */
#line 1 "B123245006.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
void yyerror(const char *msg);

extern int tokenLine;
extern int tokenChar;
extern char *yytext;

typedef struct Symbol {
	char *name;
	struct Symbol *next;
} Symbol;

typedef struct Scope {
	Symbol *symbols;
	struct Scope *next;
} Scope;

static Scope *scopeStack = NULL;
static int elseLine = 0;
static int elseChar = 0;

static void enter_scope(void)
{
	Scope *scope = (Scope *)malloc(sizeof(Scope));
	if (scope == NULL) {
		fprintf(stderr, "out of memory\n");
		exit(1);
	}
	scope->symbols = NULL;
	scope->next = scopeStack;
	scopeStack = scope;
}

static void leave_scope(void)
{
	Scope *scope = scopeStack;
	Symbol *sym;

	if (scope == NULL) {
		return;
	}

	scopeStack = scope->next;
	while (scope->symbols != NULL) {
		sym = scope->symbols;
		scope->symbols = sym->next;
		free(sym->name);
		free(sym);
	}
	free(scope);
}

static void declare_identifier(char *name)
{
	Symbol *sym;

	if (name == NULL) {
		return;
	}
	if (scopeStack == NULL) {
		enter_scope();
	}

	for (sym = scopeStack->symbols; sym != NULL; sym = sym->next) {
		if (strcmp(sym->name, name) == 0) {
			printf("******'%s' in the next line is a duplicated identifier in the current scope.******\n", name);
			free(name);
			return;
		}
	}

	sym = (Symbol *)malloc(sizeof(Symbol));
	if (sym == NULL) {
		fprintf(stderr, "out of memory\n");
		exit(1);
	}
	sym->name = name;
	sym->next = scopeStack->symbols;
	scopeStack->symbols = sym;
}


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 88 "B123245006.y"
{
	char *strVal;
}
/* Line 193 of yacc.c.  */
#line 277 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 290 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   584

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  162
/* YYNRULES -- Number of states.  */
#define YYNSTATES  272

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,     2,     2,    62,     2,     2,
      56,    57,    60,    58,    52,    59,    63,    61,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
      40,    55,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    43,    44,    45,    46,    47,
      48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    18,    19,    20,    23,
      24,    25,    31,    32,    37,    39,    40,    44,    46,    49,
      51,    54,    59,    64,    69,    72,    74,    76,    78,    80,
      82,    84,    85,    87,    89,    93,    95,    97,    99,   101,
     103,   105,   107,   110,   111,   113,   117,   118,   122,   124,
     128,   132,   134,   136,   138,   139,   140,   147,   149,   150,
     152,   156,   159,   163,   165,   167,   171,   175,   178,   179,
     180,   185,   187,   189,   191,   194,   197,   202,   204,   206,
     208,   210,   212,   213,   217,   222,   228,   234,   237,   239,
     244,   250,   254,   260,   268,   274,   280,   286,   296,   302,
     306,   309,   313,   315,   316,   319,   321,   322,   324,   328,
     332,   334,   335,   337,   338,   341,   344,   348,   350,   352,
     356,   360,   364,   368,   372,   376,   380,   384,   388,   392,
     394,   398,   402,   406,   408,   410,   413,   416,   419,   422,
     425,   428,   431,   434,   437,   441,   443,   448,   454,   456,
     458,   460,   462,   464,   466,   468,   473,   475,   476,   478,
     482,   484,   488
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      65,     0,    -1,    66,    -1,    66,    67,    -1,    67,    -1,
      16,     3,    68,    49,    70,    50,    69,    -1,    -1,    -1,
      70,    71,    -1,    -1,    -1,    77,    88,     3,    72,    75,
      -1,    -1,    88,     3,    73,    75,    -1,    76,    -1,    -1,
       3,    74,    90,    -1,    67,    -1,     1,    51,    -1,    90,
      -1,    82,    51,    -1,    82,    52,    83,    51,    -1,    15,
      79,    86,    51,    -1,    15,    79,    86,     1,    -1,    14,
      78,    -1,    18,    -1,    19,    -1,    20,    -1,    18,    -1,
      19,    -1,    20,    -1,    -1,    81,    -1,     3,    -1,    81,
      53,    54,    -1,    81,    -1,     3,    -1,     8,    -1,     9,
      -1,    10,    -1,    11,    -1,    12,    -1,    55,   118,    -1,
      -1,    84,    -1,    83,    52,    84,    -1,    -1,     3,    85,
      82,    -1,    87,    -1,    86,    52,    87,    -1,     3,    55,
     118,    -1,     3,    -1,    79,    -1,    13,    -1,    -1,    -1,
      56,    91,    92,    57,    98,    89,    -1,    93,    -1,    -1,
      94,    -1,    93,    52,    94,    -1,    79,     3,    -1,    96,
      99,    97,    -1,    49,    -1,    50,    -1,    49,    99,    50,
      -1,    49,    99,     1,    -1,    99,   100,    -1,    -1,    -1,
      88,     3,   101,   102,    -1,    76,    -1,   103,    -1,    67,
      -1,     1,    51,    -1,    82,    51,    -1,    82,    52,    83,
      51,    -1,   105,    -1,    95,    -1,   106,    -1,   107,    -1,
     108,    -1,    -1,    22,   104,   103,    -1,   125,    55,   118,
      51,    -1,    26,    56,   118,    57,    51,    -1,    27,    56,
     125,    57,    51,    -1,   118,    51,    -1,    51,    -1,   125,
      55,     1,    51,    -1,   125,    55,   118,     1,    51,    -1,
     118,     1,    51,    -1,    21,    56,   117,    57,   103,    -1,
      21,    56,   117,    57,   103,    22,   103,    -1,    21,    56,
       1,    57,   103,    -1,    23,    56,   117,    57,   103,    -1,
      23,    56,     1,    57,   103,    -1,    24,    56,   109,    51,
     114,    51,   115,    57,   103,    -1,    24,    56,     1,    57,
     103,    -1,    25,   118,    51,    -1,    25,    51,    -1,    25,
     118,     1,    -1,   110,    -1,    -1,   111,   112,    -1,    10,
      -1,    -1,   113,    -1,   112,    52,   113,    -1,   125,    55,
     118,    -1,   117,    -1,    -1,   116,    -1,    -1,   125,    31,
      -1,   125,    32,    -1,   125,    55,   118,    -1,   118,    -1,
     119,    -1,   118,    58,   119,    -1,   118,    59,   119,    -1,
     118,    33,   119,    -1,   118,    34,   119,    -1,   118,    40,
     119,    -1,   118,    41,   119,    -1,   118,    36,   119,    -1,
     118,    35,   119,    -1,   118,    37,   119,    -1,   118,    38,
     119,    -1,   120,    -1,   119,    60,   120,    -1,   119,    61,
     120,    -1,   119,    62,   120,    -1,   125,    -1,   121,    -1,
      42,   120,    -1,    58,   120,    -1,    59,   120,    -1,    31,
     125,    -1,    32,   125,    -1,   121,    31,    -1,   121,    32,
      -1,   125,    31,    -1,   125,    32,    -1,    56,   118,    57,
      -1,   122,    -1,    17,     3,    56,    57,    -1,    17,    80,
      53,   118,    54,    -1,     4,    -1,     5,    -1,     6,    -1,
       7,    -1,    28,    -1,    29,    -1,    30,    -1,   125,    56,
     123,    57,    -1,   124,    -1,    -1,   118,    -1,   124,    52,
     118,    -1,     3,    -1,   125,    63,     3,    -1,   125,    53,
     118,    54,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   111,   111,   116,   117,   122,   127,   131,   135,   136,
     147,   147,   148,   148,   149,   150,   150,   151,   152,   157,
     158,   159,   164,   165,   170,   171,   172,   173,   177,   178,
     179,   180,   185,   186,   187,   191,   192,   196,   197,   198,
     199,   200,   204,   205,   209,   210,   214,   214,   218,   219,
     223,   224,   228,   229,   233,   238,   238,   242,   243,   247,
     248,   252,   258,   262,   266,   271,   272,   278,   279,   283,
     283,   284,   285,   286,   287,   291,   292,   299,   300,   301,
     302,   303,   304,   304,   308,   309,   310,   311,   312,   313,
     315,   317,   322,   323,   324,   329,   330,   332,   333,   338,
     339,   340,   345,   346,   350,   354,   355,   359,   360,   364,
     368,   369,   373,   374,   378,   379,   380,   384,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   402,
     403,   404,   405,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   427,   428,
     429,   430,   431,   432,   433,   437,   441,   442,   446,   447,
     451,   452,   453
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INT_CONSTANT", "FLOAT_CONSTANT",
  "STRING_CONSTANT", "CHAR_CONSTANT", "BOOLEAN", "CHAR", "INT", "FLOAT",
  "STRING", "VOID", "STATIC", "FINAL", "CLASS", "NEW", "PUBLIC",
  "PROTECTED", "PRIVATE", "IF", "ELSE", "WHILE", "FOR", "RETURN", "PRINT",
  "READ", "TRUE", "FALSE", "NULLTOK", "INC", "DEC", "EQ", "NEQ", "GE",
  "LE", "AND", "OR", "LOWER_THAN_ELSE", "'<'", "'>'", "'!'", "PREDEC",
  "PREINC", "UPLUS", "UMINUS", "POSTDEC", "POSTINC", "'{'", "'}'", "';'",
  "','", "'['", "']'", "'='", "'('", "')'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'.'", "$accept", "program", "class_list", "class_decl",
  "class_scope_start", "class_scope_end", "class_body", "class_member",
  "@1", "@2", "@3", "member_tail", "const_decl", "modifiers",
  "opt_access_modifier", "type", "new_type", "base_type",
  "initializer_opt", "class_declarator_list", "class_declarator", "@4",
  "const_declarator_list", "const_declarator", "return_type",
  "method_scope_end", "method_tail", "@5", "formal_opt", "formal_list",
  "formal_arg", "compound_stmt", "compound_scope_start",
  "compound_scope_end", "compound_body", "block_items", "block_item", "@6",
  "local_decl_tail", "statement", "@7", "simple_stmt", "if_stmt",
  "loop_stmt", "return_stmt", "for_init_opt", "for_init", "opt_int",
  "for_init_list", "for_init_item", "boolean_expr_opt", "for_update_opt",
  "for_update", "boolean_expr", "expression", "term", "factor", "literal",
  "method_invocation", "argument_opt", "argument_list", "name", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      60,    62,    33,   295,   296,   297,   298,   299,   300,   123,
     125,    59,    44,    91,    93,    61,    40,    41,    43,    45,
      42,    47,    37,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    68,    69,    70,    70,
      72,    71,    73,    71,    71,    74,    71,    71,    71,    75,
      75,    75,    76,    76,    77,    77,    77,    77,    78,    78,
      78,    78,    79,    79,    79,    80,    80,    81,    81,    81,
      81,    81,    82,    82,    83,    83,    85,    84,    86,    86,
      87,    87,    88,    88,    89,    91,    90,    92,    92,    93,
      93,    94,    95,    96,    97,    98,    98,    99,    99,   101,
     100,   100,   100,   100,   100,   102,   102,   103,   103,   103,
     103,   103,   104,   103,   105,   105,   105,   105,   105,   105,
     105,   105,   106,   106,   106,   107,   107,   107,   107,   108,
     108,   108,   109,   109,   110,   111,   111,   112,   112,   113,
     114,   114,   115,   115,   116,   116,   116,   117,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   119,
     119,   119,   119,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   121,   121,
     121,   121,   121,   121,   121,   122,   123,   123,   124,   124,
     125,   125,   125
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     7,     0,     0,     2,     0,
       0,     5,     0,     4,     1,     0,     3,     1,     2,     1,
       2,     4,     4,     4,     2,     1,     1,     1,     1,     1,
       1,     0,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     0,     1,     3,     0,     3,     1,     3,
       3,     1,     1,     1,     0,     0,     6,     1,     0,     1,
       3,     2,     3,     1,     1,     3,     3,     2,     0,     0,
       4,     1,     1,     1,     2,     2,     4,     1,     1,     1,
       1,     1,     0,     3,     4,     5,     5,     2,     1,     4,
       5,     3,     5,     7,     5,     5,     5,     9,     5,     3,
       2,     3,     1,     0,     2,     1,     0,     1,     3,     3,
       1,     0,     1,     0,     2,     2,     3,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     1,     4,     5,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     0,     1,     3,
       1,     3,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     6,     1,     3,     0,     9,
       0,     0,    15,    37,    38,    39,    40,    41,    53,    31,
       0,    25,    26,    27,     7,    17,     8,    14,     0,    52,
      32,     0,    18,     0,    28,    29,    30,    24,    33,     0,
       5,     0,     0,    12,    55,    16,    51,     0,    48,    10,
      34,    43,    58,     0,    23,    22,     0,    43,     0,    13,
       0,    19,     0,     0,    57,    59,   160,   148,   149,   150,
     151,     0,   152,   153,   154,     0,     0,     0,     0,     0,
       0,    50,   118,   129,   134,   145,   133,    49,    11,    42,
      20,     0,    61,     0,     0,    36,     0,    35,   138,   139,
     135,     0,   136,   137,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   140,   141,   142,
     143,     0,   157,     0,    46,     0,    44,    68,    54,    60,
       0,     0,   144,   121,   122,   126,   125,   127,   128,   123,
     124,   119,   120,   130,   131,   132,     0,   158,     0,   156,
     161,    43,    21,     0,     0,    56,   146,     0,   162,   155,
       0,    47,    45,    66,   160,     0,    82,     0,     0,     0,
       0,     0,    63,    65,    88,    73,    71,     0,    78,    68,
      67,    72,    77,    79,    80,    81,     0,   133,   147,   159,
      74,     0,     0,     0,     0,   100,     0,     0,     0,    69,
       0,     0,    87,     0,     0,     0,   117,    83,     0,     0,
       0,   105,     0,   102,     0,   101,    99,     0,     0,    43,
       0,    64,    62,    91,     0,     0,     0,     0,     0,     0,
       0,   111,   104,   107,     0,     0,     0,     0,    70,    89,
       0,    84,    94,    92,    96,    95,    98,     0,   110,     0,
       0,    85,    86,    75,     0,    90,     0,   113,   108,   109,
       0,    93,     0,   112,     0,    76,     0,   114,   115,     0,
      97,   116
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   175,     8,    40,    10,    26,    57,    51,
      33,    59,   176,    28,    37,    29,    96,    30,    60,   125,
     126,   151,    47,    48,   177,   155,    61,    52,    63,    64,
      65,   178,   179,   222,   128,   154,   180,   219,   238,   181,
     192,   182,   183,   184,   185,   212,   213,   214,   232,   233,
     247,   262,   263,   205,   186,    82,    83,    84,    85,   148,
     149,    86
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -192
static const yytype_int16 yypact[] =
{
      -7,     9,    14,    -7,  -192,  -192,  -192,  -192,   -23,  -192,
     465,   -21,    25,  -192,  -192,  -192,  -192,  -192,  -192,    36,
     162,  -192,  -192,  -192,  -192,  -192,  -192,  -192,    92,  -192,
     -20,    39,  -192,    27,  -192,  -192,  -192,  -192,  -192,    67,
    -192,    95,    40,  -192,  -192,  -192,    58,    28,  -192,  -192,
    -192,    35,   162,   413,  -192,  -192,    67,    35,   413,  -192,
      91,  -192,   112,    66,    74,  -192,  -192,  -192,  -192,  -192,
    -192,   177,  -192,  -192,  -192,   129,   129,   413,   413,   413,
     413,   525,    69,  -192,   117,  -192,    61,  -192,  -192,   525,
    -192,   136,  -192,   111,   162,   106,   113,  -192,    23,    23,
    -192,   453,  -192,  -192,   413,   413,   413,   413,   413,   413,
     413,   413,   413,   413,   413,   413,   413,  -192,  -192,  -192,
    -192,   413,   413,   165,  -192,   100,  -192,  -192,  -192,  -192,
     118,   413,  -192,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,  -192,  -192,  -192,   462,   525,   122,   138,
    -192,   137,  -192,   136,   197,  -192,  -192,   489,  -192,  -192,
     413,  -192,  -192,   140,    25,   139,  -192,   143,   155,   406,
     159,   161,  -192,  -192,  -192,  -192,  -192,   191,  -192,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,    26,    65,  -192,   525,
    -192,    15,   373,   105,    48,  -192,   307,   413,   129,  -192,
     256,   145,  -192,   296,   173,   174,   525,  -192,   175,   176,
     178,  -192,   183,  -192,   129,  -192,  -192,   498,   -46,   137,
     140,  -192,  -192,  -192,   185,   334,   373,   373,   373,   373,
     373,   413,   186,  -192,   -40,   189,   190,   107,  -192,  -192,
     192,  -192,  -192,   215,  -192,  -192,  -192,   193,  -192,   129,
     413,  -192,  -192,  -192,   136,  -192,   373,   129,  -192,   525,
     130,  -192,   188,  -192,   114,  -192,   373,  -192,  -192,   413,
    -192,   525
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -192,  -192,  -192,    31,  -192,  -192,  -192,  -192,  -192,  -192,
    -192,   194,   232,  -192,  -192,   -12,  -192,   179,  -147,    -5,
      99,  -192,  -192,   198,    -4,  -192,   225,  -192,  -192,  -192,
     180,  -192,  -192,  -192,  -192,    96,  -192,  -192,  -192,  -191,
    -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,    21,
    -192,  -192,  -192,  -183,   -53,   463,   -27,  -192,  -192,  -192,
    -192,   -73
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -107
static const yytype_int16 yytable[] =
{
      81,   207,    98,    99,   161,    89,    31,   121,    39,     1,
     209,   236,     5,   121,     6,   250,   204,   123,    66,    67,
      68,    69,    70,   123,    41,   101,     9,   201,   -33,    54,
      32,     4,    71,    42,     7,   242,   243,   244,   245,   246,
      62,    25,    43,    72,    73,    74,    75,    76,   248,   210,
     100,  -106,   102,   103,    34,    35,    36,    77,   211,   104,
     105,   106,   107,   108,   109,   261,   110,   111,   146,   147,
      46,    78,   237,    79,    80,   270,   121,   202,   157,    55,
      56,   187,    62,    44,   112,   113,   123,   143,   144,   145,
      58,    44,   119,   120,    50,    38,   119,   120,    49,  -103,
      13,    14,    15,    16,    17,    18,   208,   189,    66,    67,
      68,    69,    70,    53,   121,    92,   196,   122,   121,   187,
     203,   122,    71,    93,   123,   218,    94,   187,   123,   114,
     115,   116,    66,    72,    73,    74,    75,    76,   206,   124,
     206,   234,    90,    91,   217,   267,   268,    77,   117,   118,
     225,   152,   153,   187,   187,   187,   187,   187,   253,   254,
     127,    78,   130,    79,    80,    38,   131,   121,   150,   269,
      13,    14,    15,    16,    17,   156,   234,   123,   206,   159,
      95,   265,   153,   187,   264,    13,    14,    15,    16,    17,
     160,   190,    58,   187,   199,   191,   223,   259,   163,   193,
     164,    67,    68,    69,    70,    13,    14,    15,    16,    17,
      18,   194,    20,     1,    71,   197,   271,   198,   165,   166,
     167,   168,   169,   170,   171,    72,    73,    74,    75,    76,
     226,   227,   228,   229,   231,   230,   239,   256,   249,    77,
     251,   252,    27,   255,   257,   266,   172,   173,   174,   260,
      97,    88,   162,    78,    87,    79,    80,   220,    45,   164,
      67,    68,    69,    70,    13,    14,    15,    16,    17,    18,
     258,    20,     1,    71,   129,   200,     0,   165,   166,   167,
     168,   169,   170,   171,    72,    73,    74,    75,    76,     0,
       0,     0,     0,     0,     0,     0,     0,   224,    77,    66,
      67,    68,    69,    70,     0,   172,   221,   174,   215,     0,
       0,     0,    78,    71,    79,    80,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    73,    74,    75,    76,     0,
       0,     0,     0,     0,     0,   240,     0,     0,    77,     0,
     104,   105,   106,   107,   108,   109,     0,   110,   111,     0,
       0,     0,    78,     0,    79,    80,     0,     0,   216,     0,
       0,     0,     0,     0,     0,   112,   113,   104,   105,   106,
     107,   108,   109,     0,   110,   111,    66,    67,    68,    69,
      70,     0,     0,     0,     0,   241,     0,     0,     0,     0,
      71,     0,   112,   113,   165,   166,   167,   168,   169,   170,
     171,    72,    73,    74,    75,    76,     0,     0,     0,    66,
      67,    68,    69,    70,     0,    77,    66,    67,    68,    69,
      70,     0,   172,    71,   174,     0,     0,     0,     0,    78,
      71,    79,    80,     0,    72,    73,    74,    75,    76,     0,
       0,    72,    73,    74,    75,    76,     0,     0,    77,     0,
       0,     0,     0,     0,     0,    77,     0,   195,     0,     0,
       0,     0,    78,     0,    79,    80,    11,     0,    12,    78,
       0,    79,    80,    13,    14,    15,    16,    17,    18,    19,
      20,     1,     0,    21,    22,    23,   104,   105,   106,   107,
     108,   109,     0,   110,   111,   104,   105,   106,   107,   108,
     109,     0,   110,   111,     0,     0,     0,     0,     0,     0,
     132,   112,   113,     0,     0,    24,   158,     0,     0,     0,
     112,   113,   104,   105,   106,   107,   108,   109,     0,   110,
     111,   104,   105,   106,   107,   108,   109,     0,   110,   111,
       0,     0,     0,   188,     0,     0,     0,   112,   113,     0,
       0,     0,     0,     0,     0,   235,   112,   113,   104,   105,
     106,   107,   108,   109,     0,   110,   111,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,     0,     0,     0,
       0,     0,     0,   112,   113
};

static const yytype_int16 yycheck[] =
{
      53,   192,    75,    76,   151,    58,    10,    53,    20,    16,
     193,    57,     3,    53,     0,    55,     1,    63,     3,     4,
       5,     6,     7,    63,    28,    78,    49,     1,     3,     1,
      51,     0,    17,    53,     3,   226,   227,   228,   229,   230,
      52,    10,     3,    28,    29,    30,    31,    32,   231,     1,
      77,     3,    79,    80,    18,    19,    20,    42,    10,    33,
      34,    35,    36,    37,    38,   256,    40,    41,   121,   122,
       3,    56,   219,    58,    59,   266,    53,    51,   131,    51,
      52,   154,    94,    56,    58,    59,    63,   114,   115,   116,
      55,    56,    31,    32,    54,     3,    31,    32,     3,    51,
       8,     9,    10,    11,    12,    13,     1,   160,     3,     4,
       5,     6,     7,    55,    53,     3,   169,    56,    53,   192,
      55,    56,    17,    57,    63,   198,    52,   200,    63,    60,
      61,    62,     3,    28,    29,    30,    31,    32,   191,     3,
     193,   214,    51,    52,   197,    31,    32,    42,    31,    32,
     203,    51,    52,   226,   227,   228,   229,   230,    51,    52,
      49,    56,    56,    58,    59,     3,    53,    53,     3,    55,
       8,     9,    10,    11,    12,    57,   249,    63,   231,    57,
       3,    51,    52,   256,   257,     8,     9,    10,    11,    12,
      52,    51,    55,   266,     3,    56,    51,   250,     1,    56,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    56,    15,    16,    17,    56,   269,    56,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      57,    57,    57,    57,    51,    57,    51,    22,    52,    42,
      51,    51,    10,    51,    51,    57,    49,    50,    51,   254,
      71,    57,   153,    56,    56,    58,    59,     1,    33,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
     249,    15,    16,    17,    94,   179,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    42,     3,
       4,     5,     6,     7,    -1,    49,    50,    51,     1,    -1,
      -1,    -1,    56,    17,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    42,    -1,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    -1,
      -1,    -1,    56,    -1,    58,    59,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,
      17,    -1,    58,    59,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    42,     3,     4,     5,     6,
       7,    -1,    49,    17,    51,    -1,    -1,    -1,    -1,    56,
      17,    58,    59,    -1,    28,    29,    30,    31,    32,    -1,
      -1,    28,    29,    30,    31,    32,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    51,    -1,    -1,
      -1,    -1,    56,    -1,    58,    59,     1,    -1,     3,    56,
      -1,    58,    59,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    33,    34,    35,    36,
      37,    38,    -1,    40,    41,    33,    34,    35,    36,    37,
      38,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    -1,    -1,    50,    54,    -1,    -1,    -1,
      58,    59,    33,    34,    35,    36,    37,    38,    -1,    40,
      41,    33,    34,    35,    36,    37,    38,    -1,    40,    41,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    33,    34,
      35,    36,    37,    38,    -1,    40,    41,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    59
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    65,    66,    67,     3,     0,    67,    68,    49,
      70,     1,     3,     8,     9,    10,    11,    12,    13,    14,
      15,    18,    19,    20,    50,    67,    71,    76,    77,    79,
      81,    88,    51,    74,    18,    19,    20,    78,     3,    79,
      69,    88,    53,     3,    56,    90,     3,    86,    87,     3,
      54,    73,    91,    55,     1,    51,    52,    72,    55,    75,
      82,    90,    79,    92,    93,    94,     3,     4,     5,     6,
       7,    17,    28,    29,    30,    31,    32,    42,    56,    58,
      59,   118,   119,   120,   121,   122,   125,    87,    75,   118,
      51,    52,     3,    57,    52,     3,    80,    81,   125,   125,
     120,   118,   120,   120,    33,    34,    35,    36,    37,    38,
      40,    41,    58,    59,    60,    61,    62,    31,    32,    31,
      32,    53,    56,    63,     3,    83,    84,    49,    98,    94,
      56,    53,    57,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   120,   120,   120,   118,   118,   123,   124,
       3,    85,    51,    52,    99,    89,    57,   118,    54,    57,
      52,    82,    84,     1,     3,    21,    22,    23,    24,    25,
      26,    27,    49,    50,    51,    67,    76,    88,    95,    96,
     100,   103,   105,   106,   107,   108,   118,   125,    54,   118,
      51,    56,   104,    56,    56,    51,   118,    56,    56,     3,
      99,     1,    51,    55,     1,   117,   118,   103,     1,   117,
       1,    10,   109,   110,   111,     1,    51,   118,   125,   101,
       1,    50,    97,    51,     1,   118,    57,    57,    57,    57,
      57,    51,   112,   113,   125,    57,    57,    82,   102,    51,
       1,    51,   103,   103,   103,   103,   103,   114,   117,    52,
      55,    51,    51,    51,    52,    51,    22,    51,   113,   118,
      83,   103,   115,   116,   125,    51,    57,    31,    32,    55,
     103,   118
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 123 "B123245006.y"
    { free((yyvsp[(2) - (7)].strVal)); }
    break;

  case 6:
#line 127 "B123245006.y"
    { enter_scope(); }
    break;

  case 7:
#line 131 "B123245006.y"
    { leave_scope(); }
    break;

  case 10:
#line 147 "B123245006.y"
    { declare_identifier((yyvsp[(3) - (3)].strVal)); }
    break;

  case 12:
#line 148 "B123245006.y"
    { declare_identifier((yyvsp[(2) - (2)].strVal)); }
    break;

  case 15:
#line 150 "B123245006.y"
    { declare_identifier((yyvsp[(1) - (1)].strVal)); }
    break;

  case 18:
#line 152 "B123245006.y"
    { yyerrok; }
    break;

  case 23:
#line 166 "B123245006.y"
    { yyerror("statement without semicolon"); yyerrok; }
    break;

  case 33:
#line 186 "B123245006.y"
    { free((yyvsp[(1) - (1)].strVal)); }
    break;

  case 36:
#line 192 "B123245006.y"
    { free((yyvsp[(1) - (1)].strVal)); }
    break;

  case 46:
#line 214 "B123245006.y"
    { declare_identifier((yyvsp[(1) - (1)].strVal)); }
    break;

  case 50:
#line 223 "B123245006.y"
    { declare_identifier((yyvsp[(1) - (3)].strVal)); }
    break;

  case 51:
#line 224 "B123245006.y"
    { declare_identifier((yyvsp[(1) - (1)].strVal)); yyerror("final declaration needs an initializer"); }
    break;

  case 54:
#line 233 "B123245006.y"
    { leave_scope(); }
    break;

  case 55:
#line 238 "B123245006.y"
    { enter_scope(); }
    break;

  case 61:
#line 252 "B123245006.y"
    { declare_identifier((yyvsp[(2) - (2)].strVal)); }
    break;

  case 63:
#line 262 "B123245006.y"
    { enter_scope(); }
    break;

  case 64:
#line 266 "B123245006.y"
    { leave_scope(); }
    break;

  case 66:
#line 273 "B123245006.y"
    { yyerror("missing '}' after compound statement"); yyerrok; }
    break;

  case 69:
#line 283 "B123245006.y"
    { declare_identifier((yyvsp[(2) - (2)].strVal)); }
    break;

  case 74:
#line 287 "B123245006.y"
    { yyerrok; }
    break;

  case 82:
#line 304 "B123245006.y"
    { elseLine = tokenLine; elseChar = tokenChar; printf("******Else Without If at line %d, char %d******\n", elseLine, elseChar);}
    break;

  case 89:
#line 314 "B123245006.y"
    { yyerror("invalid expression"); yyerrok; }
    break;

  case 90:
#line 316 "B123245006.y"
    { yyerror("statement without semicolon"); yyerrok; }
    break;

  case 91:
#line 318 "B123245006.y"
    { yyerror("statement without semicolon"); yyerrok; }
    break;

  case 94:
#line 325 "B123245006.y"
    { yyerror("invalid boolean expression"); yyerrok; }
    break;

  case 96:
#line 331 "B123245006.y"
    {yyerrok; }
    break;

  case 98:
#line 334 "B123245006.y"
    { yyerror("invalid for statement"); yyerrok; }
    break;

  case 101:
#line 341 "B123245006.y"
    { yyerror("statement without semicolon"); yyerrok; }
    break;

  case 146:
#line 422 "B123245006.y"
    { free((yyvsp[(2) - (4)].strVal)); }
    break;

  case 148:
#line 427 "B123245006.y"
    { free((yyvsp[(1) - (1)].strVal)); }
    break;

  case 149:
#line 428 "B123245006.y"
    { free((yyvsp[(1) - (1)].strVal)); }
    break;

  case 150:
#line 429 "B123245006.y"
    { free((yyvsp[(1) - (1)].strVal)); }
    break;

  case 151:
#line 430 "B123245006.y"
    { free((yyvsp[(1) - (1)].strVal)); }
    break;

  case 160:
#line 451 "B123245006.y"
    { free((yyvsp[(1) - (1)].strVal)); }
    break;

  case 161:
#line 452 "B123245006.y"
    { free((yyvsp[(3) - (3)].strVal)); }
    break;


/* Line 1267 of yacc.c.  */
#line 2002 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 456 "B123245006.y"


void yyerror(const char *msg)
{
	printf("Line %d, char: %d, %s at \"%s\"\n", tokenLine, tokenChar, msg, yytext);
}

int main(void)
{
	enter_scope();
	while (scopeStack != NULL) {
		leave_scope();
	}
	return 0;
}

