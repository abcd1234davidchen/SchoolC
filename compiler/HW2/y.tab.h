/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 88 "B123245006.y"
{
	char *strVal;
}
/* Line 1529 of yacc.c.  */
#line 143 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

