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
static int syntaxErrorCount = 0;
static int semanticErrorCount = 0;
static int syntaxErrorReported = 0;

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
			semanticErrorCount++;
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
#line 90 "B123245006.y"
{
	char *strVal;
}
/* Line 193 of yacc.c.  */
#line 279 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 292 "y.tab.c"

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
#define YYLAST   610

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  161
/* YYNRULES -- Number of states.  */
#define YYNSTATES  271

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
     208,   210,   212,   215,   220,   226,   232,   235,   237,   242,
     248,   252,   258,   266,   272,   278,   284,   294,   300,   304,
     307,   311,   313,   314,   317,   319,   320,   322,   326,   330,
     332,   333,   335,   336,   339,   342,   346,   348,   350,   354,
     358,   362,   366,   370,   374,   378,   382,   386,   390,   392,
     396,   400,   404,   406,   408,   411,   414,   417,   420,   423,
     426,   429,   432,   435,   439,   441,   446,   452,   454,   456,
     458,   460,   462,   464,   466,   471,   473,   474,   476,   480,
     482,   486
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
      -1,    10,    -1,    11,    -1,    12,    -1,    55,   117,    -1,
      -1,    84,    -1,    83,    52,    84,    -1,    -1,     3,    85,
      82,    -1,    87,    -1,    86,    52,    87,    -1,     3,    55,
     117,    -1,     3,    -1,    79,    -1,    13,    -1,    -1,    -1,
      56,    91,    92,    57,    98,    89,    -1,    93,    -1,    -1,
      94,    -1,    93,    52,    94,    -1,    79,     3,    -1,    96,
      99,    97,    -1,    49,    -1,    50,    -1,    49,    99,    50,
      -1,    49,    99,     1,    -1,    99,   100,    -1,    -1,    -1,
      88,     3,   101,   102,    -1,    76,    -1,   103,    -1,    67,
      -1,     1,    51,    -1,    82,    51,    -1,    82,    52,    83,
      51,    -1,   104,    -1,    95,    -1,   105,    -1,   106,    -1,
     107,    -1,    22,   103,    -1,   124,    55,   117,    51,    -1,
      26,    56,   117,    57,    51,    -1,    27,    56,   124,    57,
      51,    -1,   117,    51,    -1,    51,    -1,   124,    55,     1,
      51,    -1,   124,    55,   117,     1,    51,    -1,   117,     1,
      51,    -1,    21,    56,   116,    57,   103,    -1,    21,    56,
     116,    57,   103,    22,   103,    -1,    21,    56,     1,    57,
     103,    -1,    23,    56,   116,    57,   103,    -1,    23,    56,
       1,    57,   103,    -1,    24,    56,   108,    51,   113,    51,
     114,    57,   103,    -1,    24,    56,     1,    57,   103,    -1,
      25,   117,    51,    -1,    25,    51,    -1,    25,   117,     1,
      -1,   109,    -1,    -1,   110,   111,    -1,    10,    -1,    -1,
     112,    -1,   111,    52,   112,    -1,   124,    55,   117,    -1,
     116,    -1,    -1,   115,    -1,    -1,   124,    31,    -1,   124,
      32,    -1,   124,    55,   117,    -1,   117,    -1,   118,    -1,
     117,    58,   118,    -1,   117,    59,   118,    -1,   117,    33,
     118,    -1,   117,    34,   118,    -1,   117,    40,   118,    -1,
     117,    41,   118,    -1,   117,    36,   118,    -1,   117,    35,
     118,    -1,   117,    37,   118,    -1,   117,    38,   118,    -1,
     119,    -1,   118,    60,   119,    -1,   118,    61,   119,    -1,
     118,    62,   119,    -1,   124,    -1,   120,    -1,    42,   119,
      -1,    58,   119,    -1,    59,   119,    -1,    31,   124,    -1,
      32,   124,    -1,   120,    31,    -1,   120,    32,    -1,   124,
      31,    -1,   124,    32,    -1,    56,   117,    57,    -1,   121,
      -1,    17,     3,    56,    57,    -1,    17,    80,    53,   117,
      54,    -1,     4,    -1,     5,    -1,     6,    -1,     7,    -1,
      28,    -1,    29,    -1,    30,    -1,   124,    56,   122,    57,
      -1,   123,    -1,    -1,   117,    -1,   123,    52,   117,    -1,
       3,    -1,   124,    63,     3,    -1,   124,    53,   117,    54,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   113,   113,   118,   119,   124,   129,   133,   137,   138,
     149,   149,   150,   150,   151,   152,   152,   153,   154,   159,
     160,   161,   166,   167,   172,   173,   174,   175,   179,   180,
     181,   182,   187,   188,   189,   193,   194,   198,   199,   200,
     201,   202,   206,   207,   211,   212,   216,   216,   220,   221,
     225,   226,   230,   231,   235,   240,   240,   244,   245,   249,
     250,   254,   260,   264,   268,   273,   274,   280,   281,   285,
     285,   286,   287,   288,   289,   293,   294,   301,   302,   303,
     304,   305,   306,   311,   312,   313,   314,   315,   316,   318,
     320,   325,   326,   327,   332,   333,   335,   336,   341,   342,
     343,   348,   349,   353,   357,   358,   362,   363,   367,   371,
     372,   376,   377,   381,   382,   383,   387,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   405,   406,
     407,   408,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   430,   431,   432,
     433,   434,   435,   436,   440,   444,   445,   449,   450,   454,
     455,   456
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
  "local_decl_tail", "statement", "simple_stmt", "if_stmt", "loop_stmt",
  "return_stmt", "for_init_opt", "for_init", "opt_int", "for_init_list",
  "for_init_item", "boolean_expr_opt", "for_update_opt", "for_update",
  "boolean_expr", "expression", "term", "factor", "literal",
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
     103,   103,   103,   104,   104,   104,   104,   104,   104,   104,
     104,   105,   105,   105,   106,   106,   106,   106,   107,   107,
     107,   108,   108,   109,   110,   110,   111,   111,   112,   113,
     113,   114,   114,   115,   115,   115,   116,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   118,   118,
     118,   118,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   120,   120,   120,
     120,   120,   120,   120,   121,   122,   122,   123,   123,   124,
     124,   124
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
       1,     1,     2,     4,     5,     5,     2,     1,     4,     5,
       3,     5,     7,     5,     5,     5,     9,     5,     3,     2,
       3,     1,     0,     2,     1,     0,     1,     3,     3,     1,
       0,     1,     0,     2,     2,     3,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     1,     4,     5,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     0,     1,     3,     1,
       3,     4
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
       0,    19,     0,     0,    57,    59,   159,   147,   148,   149,
     150,     0,   151,   152,   153,     0,     0,     0,     0,     0,
       0,    50,   117,   128,   133,   144,   132,    49,    11,    42,
      20,     0,    61,     0,     0,    36,     0,    35,   137,   138,
     134,     0,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   139,   140,   141,
     142,     0,   156,     0,    46,     0,    44,    68,    54,    60,
       0,     0,   143,   120,   121,   125,   124,   126,   127,   122,
     123,   118,   119,   129,   130,   131,     0,   157,     0,   155,
     160,    43,    21,     0,     0,    56,   145,     0,   161,   154,
       0,    47,    45,    66,   159,     0,     0,     0,     0,     0,
       0,     0,    63,    65,    87,    73,    71,     0,    78,    68,
      67,    72,    77,    79,    80,    81,     0,   132,   146,   158,
      74,     0,    82,     0,     0,    99,     0,     0,     0,    69,
       0,     0,    86,     0,     0,     0,   116,     0,     0,     0,
     104,     0,   101,     0,   100,    98,     0,     0,    43,     0,
      64,    62,    90,     0,     0,     0,     0,     0,     0,     0,
     110,   103,   106,     0,     0,     0,     0,    70,    88,     0,
      83,    93,    91,    95,    94,    97,     0,   109,     0,     0,
      84,    85,    75,     0,    89,     0,   112,   107,   108,     0,
      92,     0,   111,     0,    76,     0,   113,   114,     0,    96,
     115
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   175,     8,    40,    10,    26,    57,    51,
      33,    59,   176,    28,    37,    29,    96,    30,    60,   125,
     126,   151,    47,    48,   177,   155,    61,    52,    63,    64,
      65,   178,   179,   221,   128,   154,   180,   218,   237,   181,
     182,   183,   184,   185,   211,   212,   213,   231,   232,   246,
     261,   262,   205,   186,    82,    83,    84,    85,   148,   149,
      86
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -178
static const yytype_int16 yypact[] =
{
      -9,    10,    24,    -9,  -178,  -178,  -178,  -178,   -13,  -178,
     491,    -8,    54,  -178,  -178,  -178,  -178,  -178,  -178,    21,
     120,  -178,  -178,  -178,  -178,  -178,  -178,  -178,    73,  -178,
      35,    58,  -178,    65,  -178,  -178,  -178,  -178,  -178,    91,
    -178,   112,    71,  -178,  -178,  -178,    63,     8,  -178,  -178,
    -178,    15,   120,   439,  -178,  -178,    91,    15,   439,  -178,
       3,  -178,   138,    85,    93,  -178,  -178,  -178,  -178,  -178,
    -178,   157,  -178,  -178,  -178,   140,   140,   439,   439,   439,
     439,   551,    38,  -178,    59,  -178,   117,  -178,  -178,   551,
    -178,   143,  -178,   107,   120,   101,   106,  -178,   -35,   -35,
    -178,   479,  -178,  -178,   439,   439,   439,   439,   439,   439,
     439,   439,   439,   439,   439,   439,   439,  -178,  -178,  -178,
    -178,   439,   439,   155,  -178,    50,  -178,  -178,  -178,  -178,
     114,   439,  -178,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,  -178,  -178,  -178,   488,   551,   115,   110,
    -178,   121,  -178,   143,   196,  -178,  -178,   515,  -178,  -178,
     439,  -178,  -178,   124,    54,   122,   399,   123,   127,   432,
     128,   129,  -178,  -178,  -178,  -178,  -178,   183,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,   306,    64,  -178,   551,
    -178,    16,  -178,   105,    28,  -178,   333,   439,   140,  -178,
     255,   136,  -178,   295,   131,   132,   551,   133,   135,   137,
    -178,   142,  -178,   140,  -178,  -178,   524,    -1,   121,   124,
    -178,  -178,  -178,   144,   360,   399,   399,   399,   399,   399,
     439,   146,  -178,    34,   159,   163,    53,  -178,  -178,   165,
    -178,  -178,   207,  -178,  -178,  -178,   179,  -178,   140,   439,
    -178,  -178,  -178,   143,  -178,   399,   140,  -178,   551,    62,
    -178,   174,  -178,   -21,  -178,   399,  -178,  -178,   439,  -178,
     551
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -178,  -178,  -178,    27,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,   175,   223,  -178,  -178,   -17,  -178,   164,  -145,   -19,
      83,  -178,  -178,   181,    -2,  -178,   206,  -178,  -178,  -178,
     147,  -178,  -178,  -178,  -178,    61,  -178,  -178,  -178,  -162,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,    -6,  -178,
    -178,  -178,  -177,   -53,   489,   -65,  -178,  -178,  -178,  -178,
     -74
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -106
static const yytype_int16 yytable[] =
{
      81,    98,    99,    39,   192,    89,   161,     1,    31,    54,
     266,   267,   100,     5,   102,   103,   208,   204,   121,    66,
      67,    68,    69,    70,     6,   101,    41,     4,   123,   209,
       7,  -105,   121,    71,   268,    62,     9,    25,   210,    34,
      35,    36,   123,    32,    72,    73,    74,    75,    76,   143,
     144,   145,   121,   247,    90,    91,   235,   -33,    77,    55,
      56,    43,   123,   241,   242,   243,   244,   245,   146,   147,
      58,    44,    78,   236,    79,    80,    38,    62,   157,  -102,
     187,    13,    14,    15,    16,    17,    18,   121,    42,   249,
     117,   118,   187,   260,    46,   119,   120,   123,   114,   115,
     116,   152,   153,   269,   252,   253,   207,   189,    66,    67,
      68,    69,    70,   264,   153,    49,   196,   121,    53,   203,
     122,    44,    71,    38,   217,    50,   187,   123,    13,    14,
      15,    16,    17,    72,    73,    74,    75,    76,   206,   233,
     206,    92,    93,    66,   216,    94,   124,    77,   119,   120,
     224,   187,   187,   187,   187,   187,   127,   130,   150,   131,
      95,    78,   160,    79,    80,    13,    14,    15,    16,    17,
     121,   156,   159,   122,   233,   190,    58,   206,   191,   193,
     123,   187,   263,   194,   197,   198,   199,   222,   225,   226,
     227,   187,   228,   230,   229,   238,   258,   163,   248,   164,
      67,    68,    69,    70,    13,    14,    15,    16,    17,    18,
     250,    20,     1,    71,   251,   270,   254,   165,   166,   167,
     168,   169,   170,   171,    72,    73,    74,    75,    76,   255,
     256,   265,    88,    27,   259,    97,   162,    87,    77,    45,
     200,   129,   257,     0,     0,   172,   173,   174,     0,     0,
       0,     0,    78,     0,    79,    80,   219,     0,   164,    67,
      68,    69,    70,    13,    14,    15,    16,    17,    18,     0,
      20,     1,    71,     0,     0,     0,   165,   166,   167,   168,
     169,   170,   171,    72,    73,    74,    75,    76,     0,     0,
       0,     0,     0,     0,     0,     0,   223,    77,    66,    67,
      68,    69,    70,     0,   172,   220,   174,   201,     0,     0,
       0,    78,    71,    79,    80,     0,     0,     0,     0,     0,
       0,     0,     0,    72,    73,    74,    75,    76,     0,     0,
       0,     0,     0,     0,   214,     0,     0,    77,     0,   104,
     105,   106,   107,   108,   109,     0,   110,   111,     0,     0,
       0,    78,     0,    79,    80,     0,     0,   202,     0,     0,
       0,   239,     0,     0,   112,   113,   104,   105,   106,   107,
     108,   109,     0,   110,   111,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   215,     0,     0,     0,     0,     0,
       0,   112,   113,   104,   105,   106,   107,   108,   109,     0,
     110,   111,    66,    67,    68,    69,    70,     0,     0,     0,
       0,   240,     0,     0,     0,     0,    71,     0,   112,   113,
     165,   166,   167,   168,   169,   170,   171,    72,    73,    74,
      75,    76,     0,     0,     0,    66,    67,    68,    69,    70,
       0,    77,    66,    67,    68,    69,    70,     0,   172,    71,
     174,     0,     0,     0,     0,    78,    71,    79,    80,     0,
      72,    73,    74,    75,    76,     0,     0,    72,    73,    74,
      75,    76,     0,     0,    77,     0,     0,     0,     0,     0,
       0,    77,     0,   195,     0,     0,     0,     0,    78,     0,
      79,    80,    11,     0,    12,    78,     0,    79,    80,    13,
      14,    15,    16,    17,    18,    19,    20,     1,     0,    21,
      22,    23,   104,   105,   106,   107,   108,   109,     0,   110,
     111,   104,   105,   106,   107,   108,   109,     0,   110,   111,
       0,     0,     0,     0,     0,     0,   132,   112,   113,     0,
       0,    24,   158,     0,     0,     0,   112,   113,   104,   105,
     106,   107,   108,   109,     0,   110,   111,   104,   105,   106,
     107,   108,   109,     0,   110,   111,     0,     0,     0,   188,
       0,     0,     0,   112,   113,     0,     0,     0,     0,     0,
       0,   234,   112,   113,   104,   105,   106,   107,   108,   109,
       0,   110,   111,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,     0,     0,     0,     0,     0,     0,   112,
     113
};

static const yytype_int16 yycheck[] =
{
      53,    75,    76,    20,   166,    58,   151,    16,    10,     1,
      31,    32,    77,     3,    79,    80,   193,     1,    53,     3,
       4,     5,     6,     7,     0,    78,    28,     0,    63,     1,
       3,     3,    53,    17,    55,    52,    49,    10,    10,    18,
      19,    20,    63,    51,    28,    29,    30,    31,    32,   114,
     115,   116,    53,   230,    51,    52,    57,     3,    42,    51,
      52,     3,    63,   225,   226,   227,   228,   229,   121,   122,
      55,    56,    56,   218,    58,    59,     3,    94,   131,    51,
     154,     8,     9,    10,    11,    12,    13,    53,    53,    55,
      31,    32,   166,   255,     3,    31,    32,    63,    60,    61,
      62,    51,    52,   265,    51,    52,     1,   160,     3,     4,
       5,     6,     7,    51,    52,     3,   169,    53,    55,    55,
      56,    56,    17,     3,   198,    54,   200,    63,     8,     9,
      10,    11,    12,    28,    29,    30,    31,    32,   191,   213,
     193,     3,    57,     3,   197,    52,     3,    42,    31,    32,
     203,   225,   226,   227,   228,   229,    49,    56,     3,    53,
       3,    56,    52,    58,    59,     8,     9,    10,    11,    12,
      53,    57,    57,    56,   248,    51,    55,   230,    56,    56,
      63,   255,   256,    56,    56,    56,     3,    51,    57,    57,
      57,   265,    57,    51,    57,    51,   249,     1,    52,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      51,    15,    16,    17,    51,   268,    51,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    22,
      51,    57,    57,    10,   253,    71,   153,    56,    42,    33,
     179,    94,   248,    -1,    -1,    49,    50,    51,    -1,    -1,
      -1,    -1,    56,    -1,    58,    59,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      15,    16,    17,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,
       5,     6,     7,    -1,    49,    50,    51,     1,    -1,    -1,
      -1,    56,    17,    58,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    42,    -1,    33,
      34,    35,    36,    37,    38,    -1,    40,    41,    -1,    -1,
      -1,    56,    -1,    58,    59,    -1,    -1,    51,    -1,    -1,
      -1,     1,    -1,    -1,    58,    59,    33,    34,    35,    36,
      37,    38,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    33,    34,    35,    36,    37,    38,    -1,
      40,    41,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    17,    -1,    58,    59,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    42,     3,     4,     5,     6,     7,    -1,    49,    17,
      51,    -1,    -1,    -1,    -1,    56,    17,    58,    59,    -1,
      28,    29,    30,    31,    32,    -1,    -1,    28,    29,    30,
      31,    32,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    51,    -1,    -1,    -1,    -1,    56,    -1,
      58,    59,     1,    -1,     3,    56,    -1,    58,    59,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    33,    34,    35,    36,    37,    38,    -1,    40,
      41,    33,    34,    35,    36,    37,    38,    -1,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,    -1,
      -1,    50,    54,    -1,    -1,    -1,    58,    59,    33,    34,
      35,    36,    37,    38,    -1,    40,    41,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    58,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    58,    59,    33,    34,    35,    36,    37,    38,
      -1,    40,    41,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59
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
      59,   117,   118,   119,   120,   121,   124,    87,    75,   117,
      51,    52,     3,    57,    52,     3,    80,    81,   124,   124,
     119,   117,   119,   119,    33,    34,    35,    36,    37,    38,
      40,    41,    58,    59,    60,    61,    62,    31,    32,    31,
      32,    53,    56,    63,     3,    83,    84,    49,    98,    94,
      56,    53,    57,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   119,   119,   119,   117,   117,   122,   123,
       3,    85,    51,    52,    99,    89,    57,   117,    54,    57,
      52,    82,    84,     1,     3,    21,    22,    23,    24,    25,
      26,    27,    49,    50,    51,    67,    76,    88,    95,    96,
     100,   103,   104,   105,   106,   107,   117,   124,    54,   117,
      51,    56,   103,    56,    56,    51,   117,    56,    56,     3,
      99,     1,    51,    55,     1,   116,   117,     1,   116,     1,
      10,   108,   109,   110,     1,    51,   117,   124,   101,     1,
      50,    97,    51,     1,   117,    57,    57,    57,    57,    57,
      51,   111,   112,   124,    57,    57,    82,   102,    51,     1,
      51,   103,   103,   103,   103,   103,   113,   116,    52,    55,
      51,    51,    51,    52,    51,    22,    51,   112,   117,    83,
     103,   114,   115,   124,    51,    57,    31,    32,    55,   103,
     117
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
#line 125 "B123245006.y"
    { free((yyvsp[(2) - (7)].strVal)); }
    break;

  case 6:
#line 129 "B123245006.y"
    { enter_scope(); }
    break;

  case 7:
#line 133 "B123245006.y"
    { leave_scope(); }
    break;

  case 10:
#line 149 "B123245006.y"
    { declare_identifier((yyvsp[(3) - (3)].strVal)); }
    break;

  case 12:
#line 150 "B123245006.y"
    { declare_identifier((yyvsp[(2) - (2)].strVal)); }
    break;

  case 15:
#line 152 "B123245006.y"
    { declare_identifier((yyvsp[(1) - (1)].strVal)); }
    break;

  case 18:
#line 154 "B123245006.y"
    {yyerror("invalid class member");yyerrok;}
    break;

  case 23:
#line 168 "B123245006.y"
    { yyerror("statement without semicolon"); yyerrok; }
    break;

  case 33:
#line 188 "B123245006.y"
    { free((yyvsp[(1) - (1)].strVal)); }
    break;

  case 36:
#line 194 "B123245006.y"
    { free((yyvsp[(1) - (1)].strVal)); }
    break;

  case 46:
#line 216 "B123245006.y"
    { declare_identifier((yyvsp[(1) - (1)].strVal)); }
    break;

  case 50:
#line 225 "B123245006.y"
    { declare_identifier((yyvsp[(1) - (3)].strVal)); }
    break;

  case 51:
#line 226 "B123245006.y"
    { declare_identifier((yyvsp[(1) - (1)].strVal)); yyerror("final declaration needs an initializer"); }
    break;

  case 54:
#line 235 "B123245006.y"
    { leave_scope(); }
    break;

  case 55:
#line 240 "B123245006.y"
    { enter_scope(); }
    break;

  case 61:
#line 254 "B123245006.y"
    { declare_identifier((yyvsp[(2) - (2)].strVal)); }
    break;

  case 63:
#line 264 "B123245006.y"
    { enter_scope(); }
    break;

  case 64:
#line 268 "B123245006.y"
    { leave_scope(); }
    break;

  case 66:
#line 275 "B123245006.y"
    { yyerror("missing '}' after compound statement"); yyerrok; }
    break;

  case 69:
#line 285 "B123245006.y"
    { declare_identifier((yyvsp[(2) - (2)].strVal)); }
    break;

  case 74:
#line 289 "B123245006.y"
    {yyerror("invalid class member");yyerrok;}
    break;

  case 82:
#line 307 "B123245006.y"
    { printf("******Else Without If at line %d, char %d******\n", tokenLine, tokenChar); syntaxErrorCount++; }
    break;

  case 88:
#line 317 "B123245006.y"
    { yyerror("invalid expression"); yyerrok; }
    break;

  case 89:
#line 319 "B123245006.y"
    { yyerror("statement without semicolon"); yyerrok; }
    break;

  case 90:
#line 321 "B123245006.y"
    { yyerror("statement without semicolon"); yyerrok; }
    break;

  case 93:
#line 328 "B123245006.y"
    { yyerror("invalid boolean expression"); yyerrok; }
    break;

  case 95:
#line 334 "B123245006.y"
    { yyerror("invalid boolean expression"); yyerrok; }
    break;

  case 97:
#line 337 "B123245006.y"
    { yyerror("invalid for statement"); yyerrok; }
    break;

  case 100:
#line 344 "B123245006.y"
    { yyerror("statement without semicolon"); yyerrok; }
    break;

  case 145:
#line 425 "B123245006.y"
    { free((yyvsp[(2) - (4)].strVal)); }
    break;

  case 147:
#line 430 "B123245006.y"
    { free((yyvsp[(1) - (1)].strVal)); }
    break;

  case 148:
#line 431 "B123245006.y"
    { free((yyvsp[(1) - (1)].strVal)); }
    break;

  case 149:
#line 432 "B123245006.y"
    { free((yyvsp[(1) - (1)].strVal)); }
    break;

  case 150:
#line 433 "B123245006.y"
    { free((yyvsp[(1) - (1)].strVal)); }
    break;

  case 159:
#line 454 "B123245006.y"
    { free((yyvsp[(1) - (1)].strVal)); }
    break;

  case 160:
#line 455 "B123245006.y"
    { free((yyvsp[(3) - (3)].strVal)); }
    break;


/* Line 1267 of yacc.c.  */
#line 2010 "y.tab.c"
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


#line 459 "B123245006.y"


void yyerror(const char *msg)
{
	printf("Line %d, char: %d, %s at \"%s\"\n", tokenLine, tokenChar, msg, yytext);
	syntaxErrorCount++;
	syntaxErrorReported = 1;
}

int main(void)
{
	enter_scope();
	if (yyparse() == 0) {
		if (syntaxErrorCount == 0 && semanticErrorCount == 0) {
			printf("Parsing completed successfully.\n");
		} else {
			printf("Parsing completed with %d syntax error(s) and %d semantic error(s).\n",
			       syntaxErrorCount, semanticErrorCount);
		}
	}
	while (scopeStack != NULL) {
		leave_scope();
	}
	return 0;
}

