#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "check.y"


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

#line 58 "y.tab.c"

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define T_ARRAY 257
#define T_BEGIN 258
#define T_CALL 259
#define T_CONST 260
#define T_DO 261
#define T_DECLARATION 262
#define T_EACH 263
#define T_END 264
#define T_FOR 265
#define T_FUNCTION 266
#define T_IF 267
#define T_IN 268
#define T_IMPLEMENTATION 269
#define T_OF 270
#define T_PROCEDURE 271
#define T_THEN 272
#define T_TYPE 273
#define T_VAR 274
#define T_WHILE 275
#define T_MINUS 276
#define T_MULTIPLY 277
#define T_COMMA 278
#define T_PERIOD 279
#define T_TO 280
#define T_DIVIDE 281
#define T_COLON 282
#define T_ASSIGN 283
#define T_SEMICOLON 284
#define T_SQUAREL 285
#define T_SQUARER 286
#define T_CURLYL 287
#define T_CURLYR 288
#define T_PLUS 289
#define T_BRACKETL 290
#define T_BRACKETR 291
#define T_EQUALS 292
#define T_NUMBER 293
#define T_IDENT 294
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    1,    3,    3,    4,    4,    5,    5,    6,
    6,    7,    7,   11,   12,   10,   13,   13,   15,   16,
   16,    8,   17,   17,   18,    9,   19,   19,   20,   14,
   14,   21,   21,   21,   23,   25,   25,   24,   22,   26,
    2,   27,   28,   28,   28,   28,   28,   30,   31,   29,
   33,   33,   33,   33,   33,   33,   33,   34,   35,   36,
   37,   38,   39,   32,   41,   41,   40,   42,   42,   42,
   43,   44,   44,   44,   45,   45,
};
static const short yylen[] = {                            2,
    1,    1,   10,    0,    2,    0,    2,    0,    1,    0,
    1,    0,    1,    3,    3,    5,    0,    1,    3,    1,
    3,    2,    1,    3,    3,    2,    1,    3,    3,    1,
    1,    1,    1,    1,    3,    1,    3,    3,    7,    3,
    5,    2,    0,    2,    2,    1,    1,    5,    5,    1,
    1,    1,    1,    1,    1,    1,    1,    3,    2,    6,
    6,    6,    9,    3,    1,    3,    1,    1,    3,    3,
    1,    1,    3,    3,    1,    1,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    1,    2,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   46,   47,    0,
    5,    0,   23,    0,    0,   44,    0,    0,    0,   45,
    0,   27,   41,    0,   42,   50,    0,    0,   22,    7,
    0,    0,    9,    0,    0,    0,    0,   26,    0,    0,
    0,    0,    0,    0,   57,   65,   51,   52,   53,   54,
   55,   56,    0,   25,   24,    0,    0,    0,   11,    0,
    0,   29,   28,   59,    0,    0,   76,   75,    0,    0,
   68,    0,   72,    0,    0,   64,    0,    0,    0,    0,
    0,   13,   49,   48,    0,    0,    0,    0,    0,    0,
    0,    0,   58,   66,    0,    0,    0,   32,    0,   30,
   31,   33,   34,    0,   14,   18,    0,    0,    0,    0,
    0,   70,   69,   73,   74,    0,    0,    0,    0,   36,
    0,   16,   20,    0,   15,    3,    0,    0,    0,    0,
    0,    0,   38,    0,   35,    0,   19,   62,    0,   60,
   61,    0,   40,   37,   21,    0,    0,    0,    0,   63,
   39,
};
static const short yydgoto[] = {                          3,
    4,    5,   11,   25,   42,   68,   91,   21,   30,   43,
   69,   92,  115,  109,  116,  134,   22,   23,   31,   32,
  110,  111,  112,  113,  131,  129,   16,   17,   35,   18,
   19,   55,   56,   57,   58,   59,   60,   61,   62,   79,
   63,   80,   81,   82,   83,
};
static const short yysindex[] = {                      -254,
 -259, -238,    0,    0,    0, -251, -249, -237, -220, -239,
 -211, -239, -219, -215, -213, -201, -176,    0,    0, -209,
    0, -231,    0, -213, -189,    0, -195, -194, -193,    0,
 -228,    0,    0, -255,    0,    0, -207, -239,    0,    0,
 -206, -180,    0, -220, -220, -202, -213,    0, -200, -176,
 -170, -272, -272, -188,    0,    0,    0,    0,    0,    0,
    0,    0, -257,    0,    0, -186, -197, -168,    0, -185,
 -184,    0,    0,    0, -174, -192,    0,    0, -169, -271,
    0, -216,    0, -157, -272,    0, -255, -256, -183, -182,
 -156,    0,    0,    0, -272, -163, -176, -272, -272, -272,
 -272, -176,    0,    0, -181, -179, -178,    0, -175,    0,
    0,    0,    0, -177,    0,    0, -183, -154, -153, -173,
 -149,    0,    0,    0,    0, -146, -166, -172, -164,    0,
 -269,    0,    0, -242,    0,    0, -141, -138, -143, -150,
 -179, -167,    0, -165,    0, -161,    0,    0, -176,    0,
    0, -159,    0,    0,    0, -136, -140, -134, -256,    0,
    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0, -214, -124,    0,
 -204,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -236,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -198,    0, -124, -124,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -127,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -247,
    0, -248,    0,    0,    0,    0,    0,    0, -196,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -126,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,  125,  114,    0,
    0,    0,   22,  -19,    0,    0,    0,  103,    0,   95,
    0,    0,    0,    0,    0,    2,   27,    0,    0,    0,
    0,  -17,   57,    0,    0,    0,    0,    0,    0,  -51,
    0,    0,  -25,    0,  -24,
};
#define YYTABLESIZE 144
static const short yytable[] = {                         36,
  105,   84,   34,   49,   98,   50,   86,    1,  144,   51,
    6,   52,   71,   67,    2,   71,   67,   99,  145,   53,
   77,   78,   10,   71,   67,    8,   87,   71,  106,    8,
  107,    7,   75,  103,    8,   71,   67,  108,   54,   12,
   71,  146,    8,  119,    9,   13,   38,    4,  147,   47,
   14,    4,   39,   15,   20,   48,    4,    6,    4,    4,
  100,    6,   24,   10,  101,   17,    6,   10,    6,   17,
   70,   71,  122,  123,   27,  124,  125,   33,   28,  121,
   29,   34,   37,   41,  126,   64,   44,   66,   46,   45,
   67,   72,   76,   74,   85,   88,   89,   90,   93,   94,
   95,   96,   97,  102,  120,  118,  114,  142,  132,  136,
  137,  117,  127,  128,  139,  130,  133,  140,  141,  148,
  138,  143,  149,  150,  151,  153,  157,  158,  154,  159,
  160,  156,  155,   43,   12,   17,   26,   40,  135,  161,
   65,   73,  152,  104,
};
static const short yycheck[] = {                         17,
  257,   53,  258,  259,  276,  261,  264,  262,  278,  265,
  270,  267,  261,  261,  269,  264,  264,  289,  288,  275,
  293,  294,  260,  272,  272,  262,  284,  276,  285,  266,
  287,  270,   50,   85,  271,  284,  284,  294,  294,  260,
  289,  284,  294,   95,  294,  266,  278,  262,  291,  278,
  271,  266,  284,  274,  294,  284,  271,  262,  273,  274,
  277,  266,  274,  262,  281,  262,  271,  266,  273,  266,
   44,   45,   98,   99,  294,  100,  101,  279,  294,   97,
  294,  258,  292,  273,  102,  293,  282,  294,  282,  284,
  271,  294,  263,  294,  283,  282,  294,  266,  284,  284,
  275,  294,  272,  261,  268,  262,  290,  280,  284,  264,
  264,  294,  294,  293,  264,  294,  294,  264,  285,  261,
  294,  286,  261,  267,  275,  293,  286,  264,  294,  270,
  265,  149,  294,  258,  262,  262,   12,   24,  117,  159,
   38,   47,  141,   87,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 294
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"T_ARRAY","T_BEGIN","T_CALL",
"T_CONST","T_DO","T_DECLARATION","T_EACH","T_END","T_FOR","T_FUNCTION","T_IF",
"T_IN","T_IMPLEMENTATION","T_OF","T_PROCEDURE","T_THEN","T_TYPE","T_VAR",
"T_WHILE","T_MINUS","T_MULTIPLY","T_COMMA","T_PERIOD","T_TO","T_DIVIDE",
"T_COLON","T_ASSIGN","T_SEMICOLON","T_SQUAREL","T_SQUARER","T_CURLYL",
"T_CURLYR","T_PLUS","T_BRACKETL","T_BRACKETR","T_EQUALS","T_NUMBER","T_IDENT",
};
static const char *yyrule[] = {
"$accept : basic_program",
"basic_program : declaration_unit",
"basic_program : implementation_unit",
"declaration_unit : T_DECLARATION T_OF T_IDENT o_const_declaration o_var_declaration o_type_declaration o_procedure_interface o_function_interface T_DECLARATION T_END",
"o_const_declaration :",
"o_const_declaration : T_CONST constant_declaration",
"o_var_declaration :",
"o_var_declaration : T_VAR variable_declaration",
"o_type_declaration :",
"o_type_declaration : type_declaration",
"o_procedure_interface :",
"o_procedure_interface : procedure_interface",
"o_function_interface :",
"o_function_interface : function_interface",
"procedure_interface : T_PROCEDURE T_IDENT o_formal_parameters",
"function_interface : T_FUNCTION T_IDENT o_formal_parameters",
"type_declaration : T_TYPE T_IDENT T_COLON type T_SEMICOLON",
"o_formal_parameters :",
"o_formal_parameters : formal_parameters",
"formal_parameters : T_BRACKETL o_parameters T_BRACKETR",
"o_parameters : T_IDENT",
"o_parameters : o_parameters T_SEMICOLON T_IDENT",
"constant_declaration : comma_const_declarations T_SEMICOLON",
"comma_const_declarations : const_var_declaration",
"comma_const_declarations : comma_const_declarations T_COMMA const_var_declaration",
"const_var_declaration : T_IDENT T_EQUALS T_NUMBER",
"variable_declaration : comma_variable_declaration T_SEMICOLON",
"comma_variable_declaration : var_declaration",
"comma_variable_declaration : comma_variable_declaration T_COMMA var_declaration",
"var_declaration : T_IDENT T_COLON T_IDENT",
"type : basic_type",
"type : array_type",
"basic_type : T_IDENT",
"basic_type : enumerated_type",
"basic_type : range_type",
"enumerated_type : T_CURLYL comma_ident T_CURLYR",
"comma_ident : T_IDENT",
"comma_ident : comma_ident T_COMMA T_IDENT",
"range_type : T_SQUAREL range T_SQUARER",
"array_type : T_ARRAY T_IDENT T_SQUAREL range T_SQUARER T_OF type",
"range : T_NUMBER T_TO T_NUMBER",
"implementation_unit : T_IMPLEMENTATION T_OF T_IDENT block T_PERIOD",
"block : specification_part implementation_part",
"specification_part :",
"specification_part : T_CONST constant_declaration",
"specification_part : T_VAR variable_declaration",
"specification_part : procedure_declaration",
"specification_part : function_declaration",
"procedure_declaration : T_PROCEDURE T_IDENT T_SEMICOLON block T_SEMICOLON",
"function_declaration : T_FUNCTION T_IDENT T_COLON block T_SEMICOLON",
"implementation_part : compound_statement",
"statement : assignment",
"statement : procedure_call",
"statement : if_statement",
"statement : while_statement",
"statement : do_statement",
"statement : for_statement",
"statement : compound_statement",
"assignment : T_IDENT T_ASSIGN expression",
"procedure_call : T_CALL T_IDENT",
"if_statement : T_IF expression T_THEN compound_statement T_END T_IF",
"while_statement : T_WHILE expression T_DO compound_statement T_END T_WHILE",
"do_statement : T_DO compound_statement T_WHILE expression T_END T_DO",
"for_statement : T_FOR T_EACH T_IDENT T_IN T_IDENT T_DO compound_statement T_END T_FOR",
"compound_statement : T_BEGIN compound_sequence T_END",
"compound_sequence : statement",
"compound_sequence : compound_sequence T_SEMICOLON statement",
"expression : a_s_term",
"a_s_term : term",
"a_s_term : a_s_term T_PLUS term",
"a_s_term : a_s_term T_MINUS term",
"term : m_d_idnum",
"m_d_idnum : id_num",
"m_d_idnum : m_d_idnum T_MULTIPLY id_num",
"m_d_idnum : m_d_idnum T_DIVIDE id_num",
"id_num : T_IDENT",
"id_num : T_NUMBER",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 84 "check.y"
	{NONTERMINAL(basic_program)}
break;
case 2:
#line 86 "check.y"
	{NONTERMINAL(basic_program)}
break;
case 3:
#line 99 "check.y"
	{NONTERMINAL(declaration_unit)}
break;
case 4:
#line 103 "check.y"
	{NONTERMINAL(o_const_declaration)}
break;
case 5:
#line 106 "check.y"
	{NONTERMINAL(o_const_declaration)}
break;
case 6:
#line 110 "check.y"
	{NONTERMINAL(o_var_declaration)}
break;
case 7:
#line 113 "check.y"
	{NONTERMINAL(o_var_declaration)}
break;
case 8:
#line 117 "check.y"
	{NONTERMINAL(o_type_declaration)}
break;
case 9:
#line 119 "check.y"
	{NONTERMINAL(o_type_declaration)}
break;
case 10:
#line 123 "check.y"
	{NONTERMINAL(o_procedure_interface)}
break;
case 11:
#line 125 "check.y"
	{NONTERMINAL(o_procedure_interface)}
break;
case 12:
#line 129 "check.y"
	{NONTERMINAL(o_function_interface)}
break;
case 13:
#line 131 "check.y"
	{NONTERMINAL(o_function_interface)}
break;
case 14:
#line 137 "check.y"
	{NONTERMINAL(procedure_interface)}
break;
case 15:
#line 143 "check.y"
	{NONTERMINAL(function_interface)}
break;
case 16:
#line 151 "check.y"
	{NONTERMINAL(type_declaration)}
break;
case 17:
#line 155 "check.y"
	{NONTERMINAL(o_formal_parameters)}
break;
case 18:
#line 157 "check.y"
	{NONTERMINAL(o_formal_parameters)}
break;
case 19:
#line 163 "check.y"
	{NONTERMINAL(formal_parameters)}
break;
case 20:
#line 167 "check.y"
	{NONTERMINAL(o_parameters)}
break;
case 21:
#line 171 "check.y"
	{NONTERMINAL(o_parameters)}
break;
case 22:
#line 177 "check.y"
	{NONTERMINAL(constant_declaration)}
break;
case 23:
#line 181 "check.y"
	{NONTERMINAL(comma_const_declarations)}
break;
case 24:
#line 185 "check.y"
	{NONTERMINAL(comma_const_declarations)}
break;
case 25:
#line 191 "check.y"
	{NONTERMINAL(const_var_declaration)}
break;
case 26:
#line 196 "check.y"
	{NONTERMINAL(variable_declaration)}
break;
case 27:
#line 200 "check.y"
	{NONTERMINAL(comma_variable_declaration)}
break;
case 28:
#line 204 "check.y"
	{NONTERMINAL(comma_variable_declaration)}
break;
case 29:
#line 210 "check.y"
	{NONTERMINAL(var_declaration)}
break;
case 30:
#line 214 "check.y"
	{NONTERMINAL(type)}
break;
case 31:
#line 216 "check.y"
	{NONTERMINAL(type)}
break;
case 32:
#line 220 "check.y"
	{NONTERMINAL(basic_type)}
break;
case 33:
#line 222 "check.y"
	{NONTERMINAL(basic_type)}
break;
case 34:
#line 224 "check.y"
	{NONTERMINAL(basic_type)}
break;
case 35:
#line 230 "check.y"
	{NONTERMINAL(enumerated_type)}
break;
case 36:
#line 234 "check.y"
	{NONTERMINAL(comma_ident)}
break;
case 37:
#line 238 "check.y"
	{NONTERMINAL(comma_ident)}
break;
case 38:
#line 244 "check.y"
	{NONTERMINAL(range_type)}
break;
case 39:
#line 254 "check.y"
	{NONTERMINAL(array_type)}
break;
case 40:
#line 260 "check.y"
	{NONTERMINAL(range)}
break;
case 41:
#line 268 "check.y"
	{NONTERMINAL(implementation_unit)}
break;
case 42:
#line 273 "check.y"
	{NONTERMINAL(block)}
break;
case 43:
#line 277 "check.y"
	{NONTERMINAL(specification_part)}
break;
case 44:
#line 280 "check.y"
	{NONTERMINAL(specification_part)}
break;
case 45:
#line 283 "check.y"
	{NONTERMINAL(specification_part)}
break;
case 46:
#line 285 "check.y"
	{NONTERMINAL(specification_part)}
break;
case 47:
#line 287 "check.y"
	{NONTERMINAL(specification_part)}
break;
case 48:
#line 295 "check.y"
	{NONTERMINAL(procedure_declaration)}
break;
case 49:
#line 303 "check.y"
	{NONTERMINAL(function_declaration)}
break;
case 50:
#line 307 "check.y"
	{NONTERMINAL(implementation_part)}
break;
case 51:
#line 311 "check.y"
	{NONTERMINAL(statement)}
break;
case 52:
#line 313 "check.y"
	{NONTERMINAL(statement)}
break;
case 53:
#line 315 "check.y"
	{NONTERMINAL(statement)}
break;
case 54:
#line 317 "check.y"
	{NONTERMINAL(statement)}
break;
case 55:
#line 319 "check.y"
	{NONTERMINAL(statement)}
break;
case 56:
#line 321 "check.y"
	{NONTERMINAL(statement)}
break;
case 57:
#line 323 "check.y"
	{NONTERMINAL(statement)}
break;
case 58:
#line 329 "check.y"
	{NONTERMINAL(assignment)}
break;
case 59:
#line 334 "check.y"
	{NONTERMINAL(procedure_call)}
break;
case 60:
#line 343 "check.y"
	{NONTERMINAL(if_statement)}
break;
case 61:
#line 352 "check.y"
	{NONTERMINAL(while_statement)}
break;
case 62:
#line 361 "check.y"
	{NONTERMINAL(do_statement)}
break;
case 63:
#line 373 "check.y"
	{NONTERMINAL(for_statement)}
break;
case 64:
#line 379 "check.y"
	{NONTERMINAL(compound_statement)}
break;
case 65:
#line 383 "check.y"
	{NONTERMINAL(compound_sequence)}
break;
case 66:
#line 387 "check.y"
	{NONTERMINAL(compound_sequence)}
break;
case 67:
#line 392 "check.y"
	{NONTERMINAL(expression)}
break;
case 68:
#line 396 "check.y"
	{NONTERMINAL(a_s_term)}
break;
case 69:
#line 400 "check.y"
	{NONTERMINAL(a_s_term)}
break;
case 70:
#line 404 "check.y"
	{NONTERMINAL(a_s_term)}
break;
case 71:
#line 408 "check.y"
	{NONTERMINAL(term)}
break;
case 72:
#line 412 "check.y"
	{NONTERMINAL(m_d_idnum)}
break;
case 73:
#line 416 "check.y"
	{NONTERMINAL(m_d_idnum)}
break;
case 74:
#line 420 "check.y"
	{NONTERMINAL(m_d_idnum)}
break;
case 75:
#line 424 "check.y"
	{NONTERMINAL(id_num)}
break;
case 76:
#line 426 "check.y"
	{NONTERMINAL(id_num)}
break;
#line 905 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
