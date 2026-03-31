FILE_lex=	B123245006.l
PROG_lex=	lex.yy.c
all:	$(PROG_lex)
	gcc $(PROG_lex) -o scanner -lfl
mac:
	flex $(FILE_lex)
	gcc $(PROG_lex) -o scanner -L/opt/homebrew/opt/flex/lib -lfl
$(PROG_lex):	$(FILE_lex)
	flex $(FILE_lex)

clean:
	rm scanner $(PROG_lex)
