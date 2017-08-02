%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int yywrap(void)
{
	return 1;
}

void yyerror(const char *s)
{
	fprintf(stderr, "Parser: Unexpected error - '%s'\n", s);
}

int main(int argc, char* argv[])
{
	extern FILE* yyin;
	FILE* f = fopen(argv[1], "r");
	
	if(!f)
	{
		fprintf(stderr, "Unable to open file '%s'\n", argv[1]);
		exit(1);
	}
	
	yyin = f;
	yyparse();
	printf(" \n");
	printf("PROGRAM SUCCESSFULLY PARSED!\n");
	return 0;
}

#define NONTERMINAL(SYMBOL)	printf("Parser: found " #SYMBOL "\n");

%}	

%token
	T_ARRAY
	T_BEGIN
	T_CALL
	T_CONST
	T_DO
	T_DECLARATION
	T_EACH
	T_END
	T_FOR
	T_FUNCTION
	T_IF
	T_IN
	T_IMPLEMENTATION
	T_OF
	T_PROCEDURE
	T_THEN
	T_TYPE
	T_VAR
	T_WHILE
	T_MINUS
	T_MULTIPLY
	T_COMMA
	T_PERIOD
	T_TO
	T_DIVIDE
	T_COLON
	T_ASSIGN
	T_SEMICOLON
	T_SQUAREL
	T_SQUARER
	T_CURLYL
	T_CURLYR
	T_PLUS
	T_BRACKETL
	T_BRACKETR
	T_EQUALS
	T_NUMBER
	T_IDENT

%%

basic_program	:	declaration_unit
			{NONTERMINAL(basic_program)}
		|	implementation_unit
			{NONTERMINAL(basic_program)}
		;
				
declaration_unit	:	T_DECLARATION
				T_OF 
				T_IDENT
				o_const_declaration
				o_var_declaration
				o_type_declaration
				o_procedure_interface
				o_function_interface
				T_DECLARATION
				T_END
				{NONTERMINAL(declaration_unit)}
			;

o_const_declaration	:	
				{NONTERMINAL(o_const_declaration)}
			|	T_CONST 
				constant_declaration
				{NONTERMINAL(o_const_declaration)}
			;

o_var_declaration	:	
				{NONTERMINAL(o_var_declaration)}
			|	T_VAR 
				variable_declaration
				{NONTERMINAL(o_var_declaration)}
			;
					      
o_type_declaration	:	
				{NONTERMINAL(o_type_declaration)}
			|	type_declaration
				{NONTERMINAL(o_type_declaration)}
			;

o_procedure_interface	:	
				{NONTERMINAL(o_procedure_interface)}
			|	procedure_interface
				{NONTERMINAL(o_procedure_interface)}
			;
						
o_function_interface	:	
				{NONTERMINAL(o_function_interface)}
			|	function_interface
				{NONTERMINAL(o_function_interface)}
			;
						
procedure_interface	:	T_PROCEDURE
				T_IDENT
				o_formal_parameters
				{NONTERMINAL(procedure_interface)}
			;
					
function_interface	:	T_FUNCTION
				T_IDENT
				o_formal_parameters
				{NONTERMINAL(function_interface)}
			;

type_declaration	:	T_TYPE 
				T_IDENT 
				T_COLON
				type 
				T_SEMICOLON
				{NONTERMINAL(type_declaration)}
			;

o_formal_parameters	:	
				{NONTERMINAL(o_formal_parameters)}
			|	formal_parameters
				{NONTERMINAL(o_formal_parameters)}
			;

formal_parameters	:	T_BRACKETL
				o_parameters
				T_BRACKETR
				{NONTERMINAL(formal_parameters)}
			;
					
o_parameters	:	T_IDENT
			{NONTERMINAL(o_parameters)}
		|	o_parameters
			T_SEMICOLON
			T_IDENT
			{NONTERMINAL(o_parameters)}
		;
					
					
constant_declaration	:	comma_const_declarations
				T_SEMICOLON
				{NONTERMINAL(constant_declaration)}
			;
						
comma_const_declarations	:	const_var_declaration
					{NONTERMINAL(comma_const_declarations)}
				|	comma_const_declarations
					T_COMMA
					const_var_declaration
					{NONTERMINAL(comma_const_declarations)}
				;
					
const_var_declaration	:	T_IDENT
				T_EQUALS
				T_NUMBER
				{NONTERMINAL(const_var_declaration)}
			;
						
variable_declaration	:	comma_variable_declaration
				T_SEMICOLON
				{NONTERMINAL(variable_declaration)}
			;

comma_variable_declaration	:	var_declaration
					{NONTERMINAL(comma_variable_declaration)}
				|	comma_variable_declaration
					T_COMMA
					var_declaration
					{NONTERMINAL(comma_variable_declaration)}
				;
						      
var_declaration	:	T_IDENT
			T_COLON
			T_IDENT
			{NONTERMINAL(var_declaration)}
		;
				
type	:	basic_type
		{NONTERMINAL(type)}
	|	array_type
		{NONTERMINAL(type)}
	;

basic_type	:	T_IDENT
			{NONTERMINAL(basic_type)}
		|	enumerated_type
			{NONTERMINAL(basic_type)}
		|	range_type
			{NONTERMINAL(basic_type)}
		;
			
enumerated_type	:	T_CURLYL 
			comma_ident
			T_CURLYR
			{NONTERMINAL(enumerated_type)}
		;
	
comma_ident	:	T_IDENT
			{NONTERMINAL(comma_ident)}
		|	comma_ident
			T_COMMA
			T_IDENT
			{NONTERMINAL(comma_ident)}
		;
				
range_type	:	T_SQUAREL
			range 
			T_SQUARER
			{NONTERMINAL(range_type)}
		;

array_type	:	T_ARRAY
			T_IDENT
			T_SQUAREL
			range 
			T_SQUARER
			T_OF
			type
			{NONTERMINAL(array_type)}
		;

range	:	T_NUMBER
		T_TO
		T_NUMBER
		{NONTERMINAL(range)}
	;
		
implementation_unit	:	T_IMPLEMENTATION
				T_OF
				T_IDENT
				block
				T_PERIOD
				{NONTERMINAL(implementation_unit)}
			;

block	:	specification_part
		implementation_part
		{NONTERMINAL(block)}
	;

specification_part	:	
				{NONTERMINAL(specification_part)}
			|	T_CONST
				constant_declaration
				{NONTERMINAL(specification_part)}
			|	T_VAR
				variable_declaration
				{NONTERMINAL(specification_part)}
			|	procedure_declaration
				{NONTERMINAL(specification_part)}
			|	function_declaration
				{NONTERMINAL(specification_part)}
			;
					
procedure_declaration	:	T_PROCEDURE
				T_IDENT
				T_SEMICOLON
				block
				T_SEMICOLON
				{NONTERMINAL(procedure_declaration)}
			;
						
function_declaration	:	T_FUNCTION
				T_IDENT
				T_COLON
				block
				T_SEMICOLON
				{NONTERMINAL(function_declaration)}
			;

implementation_part	:	compound_statement
				{NONTERMINAL(implementation_part)}
			;

statement	:	assignment
			{NONTERMINAL(statement)}
		|	procedure_call
			{NONTERMINAL(statement)}
		|	if_statement
			{NONTERMINAL(statement)}
		|	while_statement
			{NONTERMINAL(statement)}
		|	do_statement
			{NONTERMINAL(statement)}
		|	for_statement
			{NONTERMINAL(statement)}
		|	compound_statement
			{NONTERMINAL(statement)}
		;
		      
assignment	:	T_IDENT
			T_ASSIGN
			expression
			{NONTERMINAL(assignment)}
		;

procedure_call	:	T_CALL
			T_IDENT
			{NONTERMINAL(procedure_call)}
		;

if_statement	:	T_IF
			expression
			T_THEN
			compound_statement
			T_END
			T_IF
			{NONTERMINAL(if_statement)}
		;

while_statement	:	T_WHILE
			expression
			T_DO
			compound_statement
			T_END
			T_WHILE
			{NONTERMINAL(while_statement)}
		;
				
do_statement	:	T_DO
			compound_statement
			T_WHILE
			expression
			T_END
			T_DO
			{NONTERMINAL(do_statement)}
		;
				
for_statement	:	T_FOR
			T_EACH
			T_IDENT
			T_IN
			T_IDENT
			T_DO
			compound_statement
			T_END
			T_FOR
			{NONTERMINAL(for_statement)}
		;
				
compound_statement	:	T_BEGIN
				compound_sequence
				T_END
				{NONTERMINAL(compound_statement)}
			;

compound_sequence	:	statement
				{NONTERMINAL(compound_sequence)}
			|	compound_sequence
				T_SEMICOLON
				statement
				{NONTERMINAL(compound_sequence)}
			;
						
					
expression	:	a_s_term
			{NONTERMINAL(expression)}
		;

a_s_term	:	term
			{NONTERMINAL(a_s_term)}
		|	a_s_term
			T_PLUS
			term
			{NONTERMINAL(a_s_term)}
		|	a_s_term
			T_MINUS
			term
			{NONTERMINAL(a_s_term)}
		;
			
term	:	m_d_idnum
		{NONTERMINAL(term)}
	;
		
m_d_idnum	:	id_num
			{NONTERMINAL(m_d_idnum)}
		|	m_d_idnum
			T_MULTIPLY
			id_num
			{NONTERMINAL(m_d_idnum)}
		|	m_d_idnum
			T_DIVIDE
			id_num
			{NONTERMINAL(m_d_idnum)}
		;
	      
id_num	:	T_IDENT
		{NONTERMINAL(id_num)}
	|	T_NUMBER
		{NONTERMINAL(id_num)}
	;
