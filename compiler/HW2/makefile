all:	clean y.tab.c lex.yy.c
	gcc lex.yy.c y.tab.c -ly -ll -o parser

mac:	clean y.tab.c lex.yy.c

	gcc lex.yy.c y.tab.c -L/opt/homebrew/opt/flex/lib -ly -ll -o parser || gcc lex.yy.c y.tab.c -ly -ll -o parser

y.tab.c:
	bison -y -d B123245006.y

lex.yy.c:
	flex B123245006.l

clean:
	rm -f parser lex.yy.c y.tab.c y.tab.h
