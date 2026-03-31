%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned charCount = 1, lineCount = 1;

char commentBuffer[8192];
int commentLen = 0;
int commentStartLine = 1;
int commentStartChar = 1;

struct node{
	char* key;
	struct node* next;
};
struct hashMap{
	int numOfElements,capacity;
	struct node** arr;
};
void setNode(struct node* node, char* key){
	node->key = strdup(key);
	node->next = NULL;
}
struct hashMap* create(int capacity){
	struct hashMap* map = (struct hashMap*)malloc(sizeof(struct hashMap));
	map->numOfElements = 0;
	map->capacity = capacity;
	map->arr = (struct node**)malloc(sizeof(struct node*)*capacity);
	for (int i = 0; i < capacity; i++){
		map->arr[i] = NULL;
	}
	return map;
}
int hashFunction(struct hashMap* map, char* key){
	int hash = 0;
	for (int i = 0; key[i] != '\0'; i++){
		hash = (hash * 31 + key[i]) % map->capacity;
	}
	return hash;
}
int lookup(struct hashMap* map, char* key){
	int hash = hashFunction(map, key);
	struct node* current = map->arr[hash];
	while (current != NULL){
		if (strcmp(current->key, key) == 0){
			return hash;
		}
		current = current->next;
	}
	return -1;
}
int insert(struct hashMap* map, char* key){
	int check = lookup(map, key);
	if (check != -1){
		return check;
	}
	int hash = hashFunction(map, key);
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	setNode(newNode, key);
	if (map->arr[hash] == NULL){
		map->arr[hash] = newNode;
	}
	else{
		newNode->next = map->arr[hash];
		map->arr[hash] = newNode;
	}
	map->numOfElements++;
	return hash;
}
void dump(struct hashMap* map){
    printf("The symbol table contains:\n");
    for (int i = 0; i < map->capacity; i++){
        struct node* current = map->arr[i];
        while (current != NULL){
            printf("%s\n", current->key);
            current = current->next;
        }
    }
}
struct hashMap* map;

%}

%x COMMENT

symbol [,:;\(\)\{\}\[\]]
operator (\+|\+\+|\-|\-\-|\*|\/|%|=|==|!=|>|<|>=|<=|&&|\|\||!)
reserved_word (abstract|assert|boolean|break|byte|case|catch|char|class|const|continue|default|do|double|else|enum|extends|false|final|finally|float|for|goto|if|implements|import|instanceof|int|interface|long|main|native|new|null|package|print|private|protected|public|return|short|static|string|strictfp|super|switch|synchronized|this|throw|throws|transient|true|try|void|volatile|while)

id [a-zA-Z_][a-zA-Z0-9_]*
int_constant [+-]?[0-9]+
float_constant [+-]?([0-9]*\.[0-9]+|[0-9]+\.[0-9]*)([eE][+-]?[0-9]+)?
string_constant \"([^\\\"]|\\.)*\"

space [ \r\t]
eol \n

%%

"//"[^\n]* {
	printf("Line: %d, 1st char: %d, \"%s\" is a \"comment\".\n", lineCount, charCount, yytext);
	charCount += yyleng;
}
"/*" {
	BEGIN(COMMENT);
	commentStartLine = lineCount;
	commentStartChar = charCount;
	strcpy(commentBuffer, yytext);
	commentLen = yyleng;
	charCount += 2;
}
<COMMENT>"*/" {
	if (commentLen + yyleng < (int)sizeof(commentBuffer)) {
		strcpy(commentBuffer + commentLen, yytext);
		commentLen += yyleng;
		commentBuffer[commentLen] = '\0';
	}
	BEGIN(INITIAL);
	printf("Line: %d, 1st char: %d, \"%s\" is a \"comment\".\n", commentStartLine, commentStartChar, commentBuffer);
	charCount += 2;
	commentLen = 0;
}
<COMMENT>\n {
	if (commentLen + 1 < (int)sizeof(commentBuffer)) {
		commentBuffer[commentLen++] = '\n';
		commentBuffer[commentLen] = '\0';
	}
	lineCount++;
	charCount = 1;
}
<COMMENT>. {
	if (commentLen + yyleng < (int)sizeof(commentBuffer)) {
		strcpy(commentBuffer + commentLen, yytext);
		commentLen += yyleng;
		commentBuffer[commentLen] = '\0';
	}
	charCount++;
}
<COMMENT><<EOF>> {
	fprintf(stderr, "Unterminated comment at line %d.\n", lineCount);
	return 0;
}

{operator} {
	printf("Line: %d, 1st char: %d, \"%s\" is an \"operator\".\n", lineCount, charCount, yytext);
	charCount += yyleng;
}
{space} {
	charCount++;
}
{eol}   {
	lineCount++;
	charCount = 1;
}
{reserved_word} {
	printf("Line: %d, 1st char: %d, \"%s\" is a \"reserved word\".\n", lineCount, charCount, yytext);
	charCount += yyleng;
}
{symbol} {
	printf("Line: %d, 1st char: %d, \"%s\" is a \"symbol\".\n", lineCount, charCount, yytext);
	charCount += yyleng;
}
{id} {
	printf("Line: %d, 1st char: %d, \"%s\" is an \"identifier\".\n", lineCount, charCount, yytext);
	insert(map, yytext);
	charCount += yyleng;
}
{int_constant} {
	printf("Line: %d, 1st char: %d, \"%s\" is an \"integer\".\n", lineCount, charCount, yytext);
	charCount += yyleng;
}
{float_constant} {
	printf("Line: %d, 1st char: %d, \"%s\" is a \"float\".\n", lineCount, charCount, yytext);
	charCount += yyleng;
}
{string_constant} {
	printf("Line: %d, 1st char: %d, \"%s\" is a \"string\".\n", lineCount, charCount, yytext);
	charCount += yyleng;
}
. {
	printf("Line: %d, 1st char: %d, \"%s\" is an \"unknown token\".\n", lineCount, charCount, yytext);
	charCount += yyleng;
}
%%
int main(){
	map = create(100);
	yylex();
	dump(map);
	return 0;
}
