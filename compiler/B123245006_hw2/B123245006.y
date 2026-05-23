%{
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
	int used;
	int line;
	int ch;
	int reportUnused;
	struct Symbol *next;
} Symbol;

typedef struct Scope {
	Symbol *symbols;
	struct Scope *next;
} Scope;

static Scope *scopeStack = NULL;
static int elseLine = 0;
static int elseChar = 0;

// Helper functions for symbol table management
static Symbol *find_identifier(const char *name)
{
	Scope *scope;
	Symbol *sym;

	if (name == NULL) {
		return NULL;
	}

	for (scope = scopeStack; scope != NULL; scope = scope->next) {
		for (sym = scope->symbols; sym != NULL; sym = sym->next) {
			if (strcmp(sym->name, name) == 0) {
				return sym;
			}
		}
	}

	return NULL;
}

// Mark an identifier as used when it is referenced in the code
static void mark_identifier_used(const char *name)
{
	Symbol *sym = find_identifier(name);

	if (sym != NULL) {
		sym->used = 1;
	}
}

// Enter a new scope by pushing a new Scope struct onto the scope stack
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

// Leave the current scope by popping the top Scope struct from the scope stack and freeing its memory
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
		if (sym->reportUnused && !sym->used) {
			printf("******'%s' at line %d is never used.******\n", sym->name, sym->line);
		}
		free(sym->name);
		free(sym);
	}
	free(scope);
}

// Declare a new identifier in the current scope. If the identifier already exists in the current scope, print an error message and do not add it to the symbol table. The reportUnused parameter indicates whether to report an unused variable warning for this identifier when leaving the scope.
static void declare_identifier(char *name, int reportUnused)
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
	sym->used = 0;
	sym->line = tokenLine;
	sym->ch = tokenChar;
	sym->reportUnused = reportUnused;
	sym->next = scopeStack->symbols;
	scopeStack->symbols = sym;
}
%}

%union {
	char *strVal;
}

%token <strVal> ID INT_CONSTANT FLOAT_CONSTANT STRING_CONSTANT CHAR_CONSTANT
%token BOOLEAN CHAR INT FLOAT STRING VOID STATIC FINAL CLASS NEW
%token PUBLIC PROTECTED PRIVATE IF ELSE WHILE FOR RETURN PRINT READ
%token TRUE FALSE NULLTOK
%token INC DEC EQ NEQ GE LE AND OR

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%left OR
%left AND
%left EQ NEQ
%left '<' '>' LE GE
%right UMINUS UPLUS '!' PREINC PREDEC
%left POSTINC POSTDEC

%%

/* A program may contain several classes, as in the public test cases. */
program
	: class_list
	;

/* Allow multiple class declarations */
class_list
	: class_list class_decl
	| class_decl
	;

/* Each class owns a scope for fields and methods. */
class_decl
	: CLASS ID class_scope_start '{' class_body '}' class_scope_end
		{ free($2); }
	;

class_scope_start
	: /* empty */ { enter_scope(); }
	;

class_scope_end
	: /* empty */ { leave_scope(); }
	;

class_body
	: class_body class_member
	| /* empty */
	;

/* e.g. 
	static int x; | final int x=5, y=10;
	(opt_method_modifier)private void foo() { ... }
	void foo() { ... } | String toString() { ... } | ERROR HANDLE
*/
class_member
	: modifiers return_type ID { declare_identifier($3, 0); } member_tail
	| return_type ID { declare_identifier($2, 0); } member_tail
	| const_decl
	| ID { declare_identifier($1, 0); } method_tail
	| class_decl
	| error ';' { yyerrok; }
	;

/* e.g. (...){...} | ; | =5; | =1,y,z=2 */
member_tail
	: method_tail
	| initializer_opt ';'
	| initializer_opt ',' class_declarator_list ';'
	;

/* e.g. final int x=5; */
const_decl
	: FINAL type const_declarator_list ';'
	| FINAL type const_declarator_list error
		{ yyerror("statement without semicolon"); yyerrok; }
	;

modifiers
	: STATIC opt_access_modifier
	| PUBLIC
	| PROTECTED
	| PRIVATE
	;

opt_access_modifier
	: PUBLIC
	| PROTECTED
	| PRIVATE
	| /* empty */
	;

/* Besides primitive types, class names are valid variable and return types. */
type
	: base_type
	| ID { free($1); }
	| base_type '[' ']'
	;

new_type
	: base_type
	| ID { free($1); }
	;

base_type
	: BOOLEAN
	| CHAR
	| INT
	| FLOAT
	| STRING
	;

initializer_opt
	: '=' expression
	| /* empty */
	;

class_declarator_list
	: class_declarator
	| class_declarator_list ',' class_declarator
	;

class_declarator
	: ID { declare_identifier($1, 0); } initializer_opt
	;

const_declarator_list
	: const_declarator
	| const_declarator_list ',' const_declarator
	;

const_declarator
	: ID '=' expression { declare_identifier($1, 0); }
	| ID { declare_identifier($1, 0); yyerror("final declaration needs an initializer"); }
	;

return_type
	: type
	| VOID
	;

method_scope_end
	: /* empty */ { leave_scope(); }
	;

/* (...){...} */
method_tail
	: '(' { enter_scope(); } formal_opt ')' compound_body method_scope_end
	;

formal_opt
	: formal_list
	| /* empty */
	;

formal_list
	: formal_arg
	| formal_list ',' formal_arg
	;

formal_arg
	: type ID { declare_identifier($2, 0); }
	;

/* Compound statements create a new scope. */
compound_stmt
	: compound_scope_start block_items compound_scope_end
	;

compound_scope_start
	: '{' { enter_scope(); }
	;

compound_scope_end
	: '}' { leave_scope(); }
	;

/* {...} */
compound_body
	: '{' block_items '}'
	| '{' block_items error
		{ yyerror("missing '}' after compound statement"); yyerrok; }
	;

/* either empty or contains block items */
block_items
	: block_items block_item
	| /* empty */
	;

/* Inside compound statements or method bodies
   e.g.
   int foo(...){...} | final int x=5; | x=5; | if(...){...}else{...} | 
   while(...){...}' | ERROR HANDLE
*/
block_item
	: return_type ID { declare_identifier($2, 1); } local_decl_tail
	| const_decl
	| statement
	| class_decl
	| error ';' { yyerrok; }
	;

local_decl_tail
	: initializer_opt ';'
	| initializer_opt ',' class_declarator_list ';'
	;

/*
	e.g.
	x=5; | print(x); | read(x); | while(...){...} | if(...){...}else{...}
	return x; | ELSE ERROR
*/
statement
	: simple_stmt
	| compound_stmt
	| if_stmt
	| loop_stmt
	| return_stmt
	| ELSE { elseLine = tokenLine; elseChar = tokenChar; printf("******Else Without If at line %d, char %d******\n", elseLine, elseChar);} statement
	;

/* 
	e.g.
	x=5; | print(x); | read(x); | x+5; | ERROR
*/
simple_stmt
	: name '=' expression ';'
	| PRINT '(' expression ')' ';'
	| READ '(' name ')' ';'
	| expression ';'
	| ';'
	| name '=' error ';'
		{ yyerror("invalid expression"); yyerrok; }
	| name '=' expression error ';'
		{ yyerror("statement without semicolon"); yyerrok; }
	| expression error ';'
		{ yyerror("statement without semicolon"); yyerrok; }
	;

/* if statements */
if_stmt
	: IF '(' boolean_expr ')' statement %prec LOWER_THAN_ELSE
	| IF '(' boolean_expr ')' statement ELSE statement
	| IF '(' error ')' statement {yyerrok;}
	;

/* loop statements */
loop_stmt
	: WHILE '(' boolean_expr ')' statement
	| WHILE '(' error ')' statement {yyerrok;}
	| FOR '(' for_init_opt ';' boolean_expr_opt ';' for_update_opt ')' statement
	| FOR '(' error ')' statement {yyerrok;}
	;

/* return statements */
return_stmt
	: RETURN expression ';'
	| RETURN ';'
	| RETURN expression error
		{ yyerror("statement without semicolon"); yyerrok; }
	;

/* for initialization */
for_init_opt
	: for_init
	| /* empty */
	;

for_init
	: opt_int for_init_list
	;

opt_int
	: INT
	| /* empty */
	;

for_init_list
	: for_init_item
	| for_init_list ',' for_init_item
	;

for_init_item
	: name '=' expression
	;

boolean_expr_opt
	: boolean_expr
	| /* empty */
	;

for_update_opt
	: for_update
	| /* empty */
	;

for_update
	: name INC
	| name DEC
	| name '=' expression
	;

boolean_expr
	: expression
	;

/* Expressions
	e.g.
	x+5 | x-5 | x==5 | x!=5 | x<5 | x>5 | x<=5 | x>=5 | x&&y | x||y
*/
expression
	: term
	| expression '+' term
	| expression '-' term
	| expression EQ term
	| expression NEQ term
	| expression '<' term
	| expression '>' term
	| expression LE term
	| expression GE term
	| expression AND term
	| expression OR term
	;

/*
	e.g.
	x | 5 | !x | +x | -x | ++x | --x | x++ | x-- | (x) | method_invocation()
	new A() | new int[5] | x*y | x/y | x%y
*/
term
	: factor
	| term '*' factor
	| term '/' factor
	| term '%' factor
	;

/*
	e.g.
	x | 5 | !x | +x | -x | ++x | --x | x++ | x-- | (x) | method_invocation()
	new A() | new int[5]
*/
factor
	: name
	| literal
	| '!' factor
	| '+' factor %prec UPLUS
	| '-' factor %prec UMINUS
	| INC name %prec PREINC
	| DEC name %prec PREDEC
	| literal INC %prec POSTINC
	| literal DEC %prec POSTDEC
	| name INC %prec POSTINC
	| name DEC %prec POSTDEC
	| '(' expression ')'
	| method_invocation
	| NEW ID '(' ')' { free($2); }
	| NEW new_type '[' expression ']'
	;

/* Constants and boolean literals */
literal
	: INT_CONSTANT { free($1); }
	| FLOAT_CONSTANT { free($1); }
	| STRING_CONSTANT { free($1); }
	| CHAR_CONSTANT { free($1); }
	| TRUE
	| FALSE
	| NULLTOK
	;

/* Method invocations
	e.g.: foo()
*/
method_invocation
	: name '(' argument_opt ')'
	;

argument_opt
	: argument_list
	| /* empty */
	;

argument_list
	: expression
	| argument_list ',' expression
	;

name
	: ID { mark_identifier_used($1); free($1); }
	| name '.' ID { mark_identifier_used($3); free($3); }
	| name '[' expression ']'
	;

%%

void yyerror(const char *msg)
{
	printf("Line %d, char: %d, %s at \"%s\"\n", tokenLine, tokenChar, msg, yytext);
}

int main(void)
{
	enter_scope();
	yyparse();
	while (scopeStack != NULL) {
		leave_scope();
	}
	return 0;
}
