CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
YACC = yacc
LEX = lex

PL2016_check: lex.yy.c y.tab.c y.tab.h
	$(CC) $(CFLAGS) y.tab.c lex.yy.c -o PL2016_check

lex.yy.c: check.l
	$(LEX) check.l

y.tab.c: check.y
	$(YACC) -v -o y.tab.c check.y

y.tab.h: check.y
	$(YACC) -v -d -o y.tab.c check.y

clean:
	rm -f *.c *.h *.o *.output *.out PL2016_check
