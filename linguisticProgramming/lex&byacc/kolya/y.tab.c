/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "lipo.y"
#include <stdio.h>
#include <string.h>
#ifndef YYSTYPE
#define YYSTYPE char*
#endif
#define INTEGER 288
extern YYSTYPE yylval;
extern FILE* yyin; 
void yyerror (const char *str);
int yylex(void);
#line 32 "y.tab.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
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

#define KEY_BEGIN 257
#define KEY_VAR 258
#define KEY_END 259
#define KEY_INTEGER 260
#define IDENTIFIER 261
#define NUMBER 262
#define OPERATION 263
#define MINUS 264
#define PLUS 265
#define OBRACKET 266
#define EBRACKET 267
#define COLON 268
#define SEMICOLON 269
#define COMMA 270
#define SIGN 271
#define UNARY 272
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    3,    4,    4,    2,    5,    5,    6,
    7,    7,    8,    8,    8,    8,    8,    9,    9,
};
static const YYINT yylen[] = {                            2,
    2,    1,    2,    5,    1,    3,    3,    1,    2,    4,
    2,    1,    3,    1,    3,    3,    3,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    2,    5,    0,    0,    1,    3,    0,
    0,    0,    0,    0,    0,    6,    0,    7,    9,    4,
   18,   19,    0,    0,    0,    0,   14,    0,    0,   10,
    0,    0,    0,   13,   15,    0,    0,
};
static const YYINT yydgoto[] = {                          2,
    3,    8,    4,    6,   13,   14,   25,   26,   27,
};
static const YYINT yysindex[] = {                      -251,
 -229,    0, -232,    0,    0, -265, -228,    0,    0, -233,
 -227, -236, -223, -228, -231,    0, -260,    0,    0,    0,
    0,    0, -238, -260, -230, -234,    0, -234, -226,    0,
 -238, -238, -238,    0,    0, -221, -221,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -222,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -254,    0, -248,    0,    0,
    0,    0,    0,    0,    0, -253, -247,
};
static const YYINT yygindex[] = {                         0,
    0,    0,   37,    0,   29,    0,   20,  -23,    0,
};
#define YYTABLESIZE 44
static const YYINT yytable[] = {                         28,
   21,   22,   10,   23,   11,   24,    1,   35,   36,   37,
   17,   17,   12,   17,   12,   17,   16,   16,   11,   16,
   11,   16,   21,   22,    7,    1,   15,   24,   31,   32,
   33,    5,   12,   16,   17,   18,    8,   20,   30,    9,
   34,   31,   19,   29,
};
static const YYINT yycheck[] = {                         23,
  261,  262,  268,  264,  270,  266,  258,   31,   32,   33,
  264,  265,  267,  267,  269,  269,  264,  265,  267,  267,
  269,  269,  261,  262,  257,  258,  260,  266,  263,  264,
  265,  261,  261,  261,  271,  259,  259,  269,  269,    3,
  267,  263,   14,   24,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 272
#define YYUNDFTOKEN 284
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"KEY_BEGIN","KEY_VAR","KEY_END",
"KEY_INTEGER","IDENTIFIER","NUMBER","OPERATION","MINUS","PLUS","OBRACKET",
"EBRACKET","COLON","SEMICOLON","COMMA","SIGN","UNARY",0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : PROGRAM",
"PROGRAM : VARS OPS",
"VARS : VAR",
"VARS : VARS VAR",
"VAR : KEY_VAR IDS COLON KEY_INTEGER SEMICOLON",
"IDS : IDENTIFIER",
"IDS : IDS COMMA IDENTIFIER",
"OPS : KEY_BEGIN LISTASSIGMENTS KEY_END",
"LISTASSIGMENTS : ASSIGMENT",
"LISTASSIGMENTS : ASSIGMENT LISTASSIGMENTS",
"ASSIGMENT : IDENTIFIER SIGN EXPRESSION SEMICOLON",
"EXPRESSION : MINUS SUB",
"EXPRESSION : SUB",
"SUB : OBRACKET EXPRESSION EBRACKET",
"SUB : OPERAND",
"SUB : SUB OPERATION SUB",
"SUB : SUB PLUS SUB",
"SUB : SUB MINUS SUB",
"OPERAND : IDENTIFIER",
"OPERAND : NUMBER",

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
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 110 "lipo.y"

void yyerror (const char *str)
{
	fprintf(stderr,"error: %s\n",str);
}

int main()
{
    yyin = fopen("prog.txt","r"); 
	yyparse();
	fclose(yyin);
	return 0; 
}
#line 229 "y.tab.c"

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
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

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

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
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
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
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

    YYERROR_CALL("syntax error");

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
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
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
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
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
case 2:
#line 25 "lipo.y"
	{
        /*printf("%s",$1);*/
    }
break;
case 3:
#line 29 "lipo.y"
	{
        /*printf("%s",$2);*/
    }
break;
case 4:
#line 35 "lipo.y"
	{
        printf("%s", "Int ");
        printf("%s", yystack.l_mark[-3]);
        printf("\n");
    }
break;
case 6:
#line 44 "lipo.y"
	{
        yyval = strcat(yystack.l_mark[-2],"; ");
        yyval = strcat(yyval,yystack.l_mark[0]);
    }
break;
case 7:
#line 51 "lipo.y"
	{
        printf("%s", yystack.l_mark[-2]);	
        printf("\n%s", yystack.l_mark[-1]);	
    	printf("%s", yystack.l_mark[0]);
        printf(".\n");
    }
break;
case 8:
#line 60 "lipo.y"
	{
        yyval=yystack.l_mark[0];
    }
break;
case 9:
#line 64 "lipo.y"
	{   
        yyval=strcat(yystack.l_mark[-1],yystack.l_mark[0]);
    }
break;
case 10:
#line 70 "lipo.y"
	{
        yyval = strcat(yystack.l_mark[-3]," := ");
        yyval = strcat(yyval,yystack.l_mark[-1]);
        yyval = strcat(yyval,";\n");
    }
break;
case 11:
#line 78 "lipo.y"
	{
        yyval = strcat(yystack.l_mark[-1],yystack.l_mark[0]);	
    }
break;
case 13:
#line 85 "lipo.y"
	{
        yyval = strcat(yystack.l_mark[-2],yystack.l_mark[-1]);
        yyval = strcat(yyval,")");	
    }
break;
case 15:
#line 91 "lipo.y"
	{   
        yyval = strcat(yystack.l_mark[-2],yystack.l_mark[-1]);
        yyval = strcat(yyval,yystack.l_mark[0]);	
    }
break;
case 16:
#line 96 "lipo.y"
	{
        yyval = strcat(yystack.l_mark[-2],yystack.l_mark[-1]);
        yyval = strcat(yyval,yystack.l_mark[0]);	
    }
break;
case 17:
#line 101 "lipo.y"
	{
        yyval = strcat(yystack.l_mark[-2],yystack.l_mark[-1]);
        yyval = strcat(yyval,yystack.l_mark[0]);	    
    }
break;
#line 521 "y.tab.c"
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
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
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
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
