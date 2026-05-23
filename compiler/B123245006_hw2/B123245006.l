%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "y.tab.h"

int lineCount = 1;
int charCount = 1;
int tokenLine = 1;
int tokenChar = 1;
static char lineBuffer[8192];
static int lineBufferLen = 0;

static void advance_location(const char *text, int length)
{
	for (int i = 0; i < length; i++) {
		if (text[i] == '\n') {
			lineCount++;
			charCount = 1;
		} else {
			charCount++;
		}
	}
}

static void append_to_line(const char *text, int length)
{
	for (int i = 0; i < length; i++) {
		if (lineBufferLen < (int)sizeof(lineBuffer) - 1) {
			lineBuffer[lineBufferLen++] = text[i];
		}
	}
}

static void emit_line(void)
{
	lineBuffer[lineBufferLen] = '\0';
	printf("line %d: %s\n", lineCount, lineBuffer);
	lineBufferLen = 0;
}

static void mark_token(void)
{
	tokenLine = lineCount;
	tokenChar = charCount;
}

static void consume_text(void)
{
	append_to_line(yytext, yyleng);
	advance_location(yytext, yyleng);
}
%}

%x COMMENT

digit [0-9]
identifier [a-zA-Z_$][a-zA-Z0-9_$]*
integer_constant [+-]?{digit}+
float_constant [+-]?(({digit}+\.{digit}*)|({digit}*\.{digit}+))([eE][+-]?{digit}+)?
string_constant \"([^\"\\\n]|\\.)*\"
char_constant \'([^\'\\\n]|\\.)\'

%%

"//"[^\n\r]*		{ consume_text(); }
"/*"			{ BEGIN(COMMENT); consume_text(); }
<COMMENT>"*/"		{ BEGIN(INITIAL); consume_text(); }
<COMMENT>\n			{ emit_line(); advance_location(yytext, yyleng); }
<COMMENT>. 			{ consume_text(); }
<COMMENT><<EOF>>	{
	if (lineBufferLen > 0) {
		emit_line();
	}
	fprintf(stderr, "Line: %d, 1st char: %d, \"unterminated comment\".\n", lineCount, charCount);
	return 0;
}

[ \t\r]+            { consume_text(); }
\n                  { emit_line(); advance_location(yytext, yyleng); }

"boolean"          { mark_token(); consume_text(); return BOOLEAN; }
"char"             { mark_token(); consume_text(); return CHAR; }
"int"              { mark_token(); consume_text(); return INT; }
"float"            { mark_token(); consume_text(); return FLOAT; }
"String"           { mark_token(); consume_text(); return STRING; }
"void"             { mark_token(); consume_text(); return VOID; }
"static"           { mark_token(); consume_text(); return STATIC; }
"final"            { mark_token(); consume_text(); return FINAL; }
"class"            { mark_token(); consume_text(); return CLASS; }
"new"              { mark_token(); consume_text(); return NEW; }
"public"           { mark_token(); consume_text(); return PUBLIC; }
"protected"        { mark_token(); consume_text(); return PROTECTED; }
"private"          { mark_token(); consume_text(); return PRIVATE; }
"if"               { mark_token(); consume_text(); return IF; }
"else"             { mark_token(); consume_text(); return ELSE; }
"while"            { mark_token(); consume_text(); return WHILE; }
"for"              { mark_token(); consume_text(); return FOR; }
"return"           { mark_token(); consume_text(); return RETURN; }
"print"            { mark_token(); consume_text(); return PRINT; }
"read"             { mark_token(); consume_text(); return READ; }
"true"             { mark_token(); consume_text(); return TRUE; }
"false"            { mark_token(); consume_text(); return FALSE; }
"null"             { mark_token(); consume_text(); return NULLTOK; }

"++"              { mark_token(); consume_text(); return INC; }
"--"              { mark_token(); consume_text(); return DEC; }
"=="              { mark_token(); consume_text(); return EQ; }
"!="              { mark_token(); consume_text(); return NEQ; }
">="              { mark_token(); consume_text(); return GE; }
"<="              { mark_token(); consume_text(); return LE; }
"&&"              { mark_token(); consume_text(); return AND; }
"||"              { mark_token(); consume_text(); return OR; }

"+"               { mark_token(); consume_text(); return '+'; }
"-"               { mark_token(); consume_text(); return '-'; }
"*"               { mark_token(); consume_text(); return '*'; }
"/"               { mark_token(); consume_text(); return '/'; }
"%"               { mark_token(); consume_text(); return '%'; }
"="               { mark_token(); consume_text(); return '='; }
">"               { mark_token(); consume_text(); return '>'; }
"<"               { mark_token(); consume_text(); return '<'; }
"!"               { mark_token(); consume_text(); return '!'; }

","|":"|";"|"("|")"|"{"|"}"|"["|"]"|"." {
	mark_token();
	consume_text();
	return yytext[0];
}

{float_constant}		{
	mark_token();
	consume_text();
	yylval.strVal = strdup(yytext);
	return FLOAT_CONSTANT;
}
{integer_constant}		{
	mark_token();
	consume_text();
	yylval.strVal = strdup(yytext);
	return INT_CONSTANT;
}
{string_constant}		{
	mark_token();
	consume_text();
	yylval.strVal = strdup(yytext);
	return STRING_CONSTANT;
}
{char_constant}		{
	mark_token();
	consume_text();
	yylval.strVal = strdup(yytext);
	return CHAR_CONSTANT;
}
{identifier}			{
	mark_token();
	consume_text();
	yylval.strVal = strdup(yytext);
	return ID;
}

. {
	fprintf(stderr, "Line: %d, 1st char: %d, \"%s\" is an \"unknown token\".\n", lineCount, charCount, yytext);
	consume_text();
}

<<EOF>> {
	if (lineBufferLen > 0) {
		emit_line();
	}
	return 0;
}

%%

int yywrap(void)
{
	return 1;
}
