%{

#include <stdio.h>
#include "y.tab.h"

#define TOKF(SYMBOL) { \
	printf("Lex: found T_" #SYMBOL "\n"); \
	return T_ ## SYMBOL; \
}

#define TOKV(SYMBOL) { \
	printf("Lex: found T_" #SYMBOL ": %s\n", yytext); \
	return T_ ## SYMBOL; \
}

%}

%%

ARRAY					TOKF(ARRAY)
BEGIN					TOKF(BEGIN)	
CALL					TOKF(CALL)
CONST					TOKF(CONST)
DECLARATION				TOKF(DECLARATION)
DO					TOKF(DO)
EACH					TOKF(EACH)
END					TOKF(END)
FOR					TOKF(FOR)
FUNCTION				TOKF(FUNCTION)
IF					TOKF(IF)
IMPLEMENTATION				TOKF(IMPLEMENTATION)
IN					TOKF(IN)
OF					TOKF(OF)
PROCEDURE				TOKF(PROCEDURE)
THEN					TOKF(THEN)
TYPE					TOKF(TYPE)
VAR					TOKF(VAR)
WHILE					TOKF(WHILE)
\-					TOKF(MINUS)
\*					TOKF(MULTIPLY)
\,					TOKF(COMMA)
\.					TOKF(PERIOD)
\.\.					TOKF(TO)
\/					TOKF(DIVIDE)
\:					TOKF(COLON)
:=					TOKF(ASSIGN)
\;					TOKF(SEMICOLON)
\[					TOKF(SQUAREL)
\]					TOKF(SQUARER)
\{					TOKF(CURLYL)
\}					TOKF(CURLYR)
\+					TOKF(PLUS)
\(					TOKF(BRACKETL)
\)					TOKF(BRACKETR)
=					TOKF(EQUALS)
[0-9]+					TOKV(NUMBER)
[a-z]+					TOKV(IDENT)
[ \t\n]+				;
.					{
						fprintf(stderr, "Lex: Unexpected character '%s'\n", yytext);
						exit(1);
					}

