/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20220114

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "grammar.y"
#include  "proj2.h"
#include  <stdio.h>

  tree type_record, type_method, argtype;  /* globals used to store treenode pointers */

extern  tree  SyntaxTree;
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 10 "grammar.y"
typedef union YYSTYPE{
  int intg;
  tree tptr;
  } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 43 "y.tab.c"

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

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define PROGRAMnum 257
#define IDnum 258
#define SEMInum 259
#define CLASSnum 260
#define DECLARATIONSnum 261
#define ENDDECLARATIONSnum 262
#define COMMAnum 263
#define EQUALnum 264
#define LBRACEnum 265
#define RBRACEnum 266
#define LBRACnum 267
#define RBRACnum 268
#define LPARENnum 269
#define RPARENnum 270
#define VOIDnum 271
#define INTnum 272
#define METHODnum 273
#define VALnum 274
#define DOTnum 275
#define ASSGNnum 276
#define RETURNnum 277
#define IFnum 278
#define ELSEnum 279
#define WHILEnum 280
#define LTnum 281
#define LEnum 282
#define EQnum 283
#define NEnum 284
#define GEnum 285
#define GTnum 286
#define PLUSnum 287
#define MINUSnum 288
#define ORnum 289
#define TIMESnum 290
#define DIVIDEnum 291
#define ANDnum 292
#define NOTnum 293
#define ICONSTnum 294
#define SCONSTnum 295
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    3,    3,    4,    4,    5,    5,
    6,    6,    7,    7,   49,    8,    9,    9,   10,   10,
   11,   11,   12,   12,   14,   14,   14,   15,   16,   16,
   17,   18,   18,   50,   19,   51,   19,   20,   20,   21,
   21,   52,   22,   53,   22,   23,   23,   24,   24,   25,
   25,   25,   26,   26,   13,   13,   27,   28,   28,   29,
   29,   29,   29,   29,   29,   30,   31,   32,   32,   33,
   33,   34,   34,   35,   35,   35,   36,   36,   37,   38,
   38,   39,   39,   39,   39,   39,   39,   40,   40,   40,
   40,   40,   40,   41,   41,   41,   41,   42,   42,   42,
   42,   42,   44,   44,   45,   46,   46,   47,   47,   48,
   48,   43,   43,
};
static const YYINT yylen[] = {                            2,
    4,    1,    2,    3,    3,    4,    0,    1,    1,    2,
    2,    3,    1,    2,    0,    4,    1,    3,    1,    3,
    1,    2,    2,    3,    1,    1,    1,    3,    1,    3,
    2,    3,    4,    0,    8,    0,    8,    0,    1,    1,
    3,    0,    3,    0,    4,    1,    3,    1,    2,    1,
    2,    4,    1,    1,    2,    3,    3,    1,    3,    0,
    1,    1,    1,    1,    1,    3,    2,    3,    2,    1,
    3,    1,    2,    3,    2,    4,    4,    5,    3,    1,
    3,    1,    1,    1,    1,    1,    1,    1,    2,    2,
    3,    3,    3,    1,    3,    3,    3,    1,    1,    1,
    3,    2,    1,    1,    2,    0,    1,    1,    2,    3,
    2,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    2,    0,    3,    0,
    4,    0,    0,    0,    0,    0,    9,   53,   11,   54,
    0,   13,   15,    0,   36,   34,    5,   10,    0,   12,
   14,    0,    0,    0,    0,    0,    6,    0,   19,    0,
    0,    0,    0,    0,    0,    0,    0,   16,    0,    0,
   56,   52,    0,    0,   23,    0,   20,    0,    0,    0,
    0,    0,    0,    0,  103,  104,   18,   26,   27,  100,
   25,    0,    0,   94,   98,    0,   42,    0,    0,    0,
   40,    0,   24,    0,    0,  105,  107,    0,   29,    0,
    0,    0,    0,    0,    0,  102,   82,   83,   84,   85,
   86,   87,    0,    0,    0,    0,    0,    0,    0,    0,
   67,    0,   44,    0,    0,    0,    0,    0,  111,  109,
    0,   28,  101,    0,    0,    0,    0,    0,    0,   95,
   96,   97,   69,    0,    0,   46,    0,    0,    0,    0,
   37,   48,   41,   35,    0,  110,   30,   32,    0,   68,
    0,    0,    0,    0,    0,    0,    0,   58,   61,   62,
   63,   64,    0,   65,    0,   49,  113,   33,   71,   47,
   73,    0,    0,    0,   57,    0,   75,    0,    0,   79,
   59,    0,   66,   77,    0,   78,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  257,  297,  258,  259,  260,  298,  299,  258,  299,  265,
  300,  261,  273,  301,  302,  303,  316,  258,  262,  272,
  304,  305,  322,  323,  271,  322,  266,  316,  301,  262,
  305,  346,  267,  310,  348,  347,  266,  258,  306,  307,
  308,  268,  275,  258,  258,  267,  309,  259,  263,  264,
  310,  322,  269,  269,  268,  267,  306,  258,  265,  269,
  272,  287,  288,  293,  294,  295,  311,  312,  314,  328,
  335,  337,  338,  339,  341,  342,  272,  274,  317,  318,
  319,  317,  268,  267,  275,  343,  344,  345,  311,  313,
  335,  267,  315,  338,  338,  339,  281,  282,  283,  284,
  285,  286,  287,  288,  289,  336,  290,  291,  292,  269,
  329,  349,  272,  270,  259,  270,  335,  340,  258,  344,
  263,  266,  270,  335,  267,  338,  338,  338,  337,  339,
  339,  339,  270,  330,  335,  258,  320,  350,  265,  303,
  321,  324,  319,  321,  263,  268,  311,  268,  335,  270,
  263,  263,  320,  277,  278,  280,  325,  326,  327,  328,
  331,  332,  333,  334,  342,  324,  340,  268,  330,  258,
  335,  335,  335,  259,  266,  278,  324,  276,  324,  324,
  326,  335,  335,  279,  324,  279,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          2,
    6,    7,   11,   14,   15,  140,   21,   22,   39,   40,
   41,   47,   34,   67,   68,   90,   69,   93,   17,   79,
   80,   81,  137,  141,   23,   24,  142,  157,  158,  159,
   70,  111,  134,  161,  162,  163,  164,   71,  106,   72,
   73,   74,  118,   75,   76,   86,   87,   88,   32,   36,
   35,  112,  138,
};
static const YYINT yysindex[] = {                      -227,
 -254,    0, -228, -211, -169, -211,    0, -175,    0, -195,
    0, -245, -191, -165, -166, -166,    0,    0,    0,    0,
 -244,    0,    0, -146,    0,    0,    0,    0, -128,    0,
    0, -119, -117, -103, -106, -101,    0,  -94,    0,  -88,
  -84, -146, -251,  -86,  -78,  -80,  -61,    0, -119, -253,
    0,    0,  -50,  -50,    0,  -56,    0, -252, -253, -190,
  -51, -236, -236, -236,    0,    0,    0,    0,    0,    0,
    0,   58, -219,    0,    0,  -34,    0,  -65,  -53,  -40,
    0,  -20,    0, -190,   -5,    0,    0, -252,    0, -143,
  -13, -190,   -9, -219, -219,    0,    0,    0,    0,    0,
    0,    0, -236, -236, -236, -190, -236, -236, -236, -233,
    0,    2,    0,  -75,  -50,  -75,   24,   -3,    0,    0,
 -253,    0,    0,    8, -190, -219, -219, -219,  -41,    0,
    0,    0,    0,   -7,   25,    0,   26,    2, -194,   29,
    0,    0,    0,    0, -190,    0,    0,    0,   23,    0,
 -190,   40,   26, -190, -190, -190, -167,    0,    0,    0,
    0,    0, -196,    0, -176,    0,    0,    0,    0,    0,
    0,   29,   29, -194,    0, -190,    0, -190,   20,    0,
    0,   29,    0,    0,   22,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,  304,    0,    0,    0,   51,
    0,    0,    0,    0,   62,   51,    0,    0,    0,    0,
    0,    0,    0,   48,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   71,    0,    0,    0, -189,    0,    0,
  -54, -255,    0,    0,    0,    0, -109,    0,    0,    0,
    0,    0,   60,   60,    0,    0,    0, -157,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -81,  -55,    0,    0,  -89,    0,    0,    0,   65,
    0,    0,    0,    0,    0,    0,    0, -123,    0,    0,
    0,    0, -149,  -45,  -14,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   64,    0,    0,    0,
    0,    0,    0,    0,    0,   -4,   27,   37,   68,    0,
    0,    0,    0,    0,   67,    0, -183,    0, -144,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -182, -122,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -144,    0,    0,    0,    0, -118,    0,
    0,    0,    0,    0, -110,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    0,  342,    0,  333,    0,  340,    0,  330,  303,    0,
    0,    0,  311,  -58,    0,    0,    0,    0,  339,  301,
    0,  241,  219,  242,   13,    0, -134,    0,  185,    0,
 -131,    0,  209,    0,    0,    0,    0,  -60,    0,  255,
  -52,  -62,  217,    0, -130,    0,  275,    0,    0,    0,
    0,    0,    0,
};
#define YYTABLESIZE 363
static const YYINT yytable[] = {                         91,
   89,   96,   55,    3,   58,  166,   18,  160,  165,   94,
   95,   59,   18,   18,   84,   60,   19,   30,   61,   55,
   20,   58,   85,  117,   58,   26,   20,   20,  177,    1,
    4,  124,   60,   62,   63,   60,  133,  179,  180,   64,
   65,   66,  160,  165,  130,  131,  132,  185,    5,  135,
  126,  127,  128,   62,   63,   52,   64,   65,   66,   64,
   65,   66,  147,   58,  149,   12,   18,   58,  139,   21,
  107,  108,  109,   21,   21,   43,   45,   13,   60,   25,
   20,  176,  154,  155,  117,  156,   43,   45,    8,   10,
  135,  174,  110,  171,  172,  173,   62,   63,  175,  178,
   27,  106,   64,   65,   66,  106,   13,  106,  106,   31,
  106,  106,  106,   31,   60,  182,   31,  183,  106,  121,
   33,   60,  122,  106,  106,  106,  106,  106,  106,  106,
  106,  106,  106,  106,  106,  108,   72,   37,   38,  108,
   74,  108,  108,   72,  108,  108,  108,   74,   76,   22,
   42,   44,  108,   22,   22,   76,   45,  108,  108,  108,
  108,  108,  108,  108,  108,  108,  108,  108,  108,   99,
   48,   43,   46,   99,   49,   99,   99,   80,   99,   50,
   99,   80,   53,   80,   80,   12,   80,   55,   80,  139,
   54,   99,   99,   99,   99,   99,   99,   99,   99,   99,
   99,   99,   99,   88,   17,   56,  113,   88,   17,   88,
   88,   83,   88,   89,   88,   92,  114,   89,  115,   89,
   89,   77,   89,   78,   89,   88,   88,   88,   88,   88,
   88,   88,   88,   88,  110,   89,   89,   89,   89,   89,
   89,   89,   89,   89,   90,  103,  104,  105,   90,  116,
   90,   90,  119,   90,   91,   90,  123,  125,   91,  136,
   91,   91,  150,   91,  146,   91,   90,   90,   90,   90,
   90,   90,   90,   90,   90,  148,   91,   91,   91,   91,
   91,   91,   91,   91,   91,   92,  145,  151,  152,   92,
  168,   92,   92,  139,   92,   93,   92,  170,  184,   93,
  186,   93,   93,    1,   93,   50,   93,   92,   92,   92,
   92,   92,   92,   92,   92,   92,    7,   93,   93,   93,
   93,   93,   93,   93,   93,   93,   81,    8,   51,   38,
   81,  112,   81,   81,   39,   81,   70,   81,   97,   98,
   99,  100,  101,  102,  103,  104,  105,    9,   29,   16,
   31,   57,   51,   28,   82,  143,  153,  144,  181,  169,
  129,  167,  120,
};
static const YYINT yycheck[] = {                         60,
   59,   64,  258,  258,  258,  140,  258,  139,  139,   62,
   63,  265,  258,  258,  267,  269,  262,  262,  272,  275,
  272,  258,  275,   84,  258,   13,  272,  272,  163,  257,
  259,   92,  269,  287,  288,  269,  270,  172,  173,  293,
  294,  295,  174,  174,  107,  108,  109,  182,  260,  110,
  103,  104,  105,  287,  288,   43,  293,  294,  295,  293,
  294,  295,  121,  258,  125,  261,  258,  258,  265,  259,
  290,  291,  292,  263,  264,  259,  259,  273,  269,  271,
  272,  278,  277,  278,  145,  280,  270,  270,  258,  265,
  151,  259,  269,  154,  155,  156,  287,  288,  266,  276,
  266,  259,  293,  294,  295,  263,  273,  265,  266,  259,
  268,  269,  270,  263,  259,  176,  266,  178,  276,  263,
  267,  266,  266,  281,  282,  283,  284,  285,  286,  287,
  288,  289,  290,  291,  292,  259,  259,  266,  258,  263,
  259,  265,  266,  266,  268,  269,  270,  266,  259,  259,
  268,  258,  276,  263,  264,  266,  258,  281,  282,  283,
  284,  285,  286,  287,  288,  289,  290,  291,  292,  259,
  259,  275,  267,  263,  263,  265,  266,  259,  268,  264,
  270,  263,  269,  265,  266,  261,  268,  268,  270,  265,
  269,  281,  282,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  292,  259,  259,  267,  272,  263,  263,  265,
  266,  268,  268,  259,  270,  267,  270,  263,  259,  265,
  266,  272,  268,  274,  270,  281,  282,  283,  284,  285,
  286,  287,  288,  289,  269,  281,  282,  283,  284,  285,
  286,  287,  288,  289,  259,  287,  288,  289,  263,  270,
  265,  266,  258,  268,  259,  270,  270,  267,  263,  258,
  265,  266,  270,  268,  268,  270,  281,  282,  283,  284,
  285,  286,  287,  288,  289,  268,  281,  282,  283,  284,
  285,  286,  287,  288,  289,  259,  263,  263,  263,  263,
  268,  265,  266,  265,  268,  259,  270,  258,  279,  263,
  279,  265,  266,    0,  268,  258,  270,  281,  282,  283,
  284,  285,  286,  287,  288,  289,  266,  281,  282,  283,
  284,  285,  286,  287,  288,  289,  259,  266,  258,  270,
  263,  268,  265,  266,  270,  268,  270,  270,  281,  282,
  283,  284,  285,  286,  287,  288,  289,    6,   16,   10,
   21,   49,   42,   15,   54,  115,  138,  116,  174,  151,
  106,  145,   88,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,
};
#endif
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 295
#define YYUNDFTOKEN 351
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","PROGRAMnum","IDnum","SEMInum",
"CLASSnum","DECLARATIONSnum","ENDDECLARATIONSnum","COMMAnum","EQUALnum",
"LBRACEnum","RBRACEnum","LBRACnum","RBRACnum","LPARENnum","RPARENnum","VOIDnum",
"INTnum","METHODnum","VALnum","DOTnum","ASSGNnum","RETURNnum","IFnum","ELSEnum",
"WHILEnum","LTnum","LEnum","EQnum","NEnum","GEnum","GTnum","PLUSnum","MINUSnum",
"ORnum","TIMESnum","DIVIDEnum","ANDnum","NOTnum","ICONSTnum","SCONSTnum",
"$accept","Program","ClassDecl_rec","ClassDecl","ClassBody","MethodDecl_z1",
"MethodDecl_rec","Decls","FieldDecl_rec","FieldDecl","Tail","FieldDecl_body",
"VariableDeclId","Bracket_rec1","Bracket_rec2","VariableInitializer",
"ArrayInitializer","ArrayInitializer_body","ArrayCreationExpression",
"ArrayCreationExpression_tail","MethodDecl","FormalParameterList_z1",
"FormalParameterList","FormalParameterList_rec","IDENTIFIER_rec","Block","Type",
"Type_front","StatementList","Statement_rec","Statement","AssignmentStatement",
"MethodCallStatement","MethodCallStatement_tail","Expression_rec",
"ReturnStatement","IfStatement","If_rec","WhileStatement","Expression",
"Comp_op","SimpleExpression","Term","Factor","Expression_rec2",
"UnsignedConstant","Variable","Variable_tail","Variable_rec","Variable_1","$$1",
"$$2","$$3","$$4","$$5","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : Program",
"Program : PROGRAMnum IDnum SEMInum ClassDecl_rec",
"ClassDecl_rec : ClassDecl",
"ClassDecl_rec : ClassDecl_rec ClassDecl",
"ClassDecl : CLASSnum IDnum ClassBody",
"ClassBody : LBRACEnum MethodDecl_z1 RBRACEnum",
"ClassBody : LBRACEnum Decls MethodDecl_z1 RBRACEnum",
"MethodDecl_z1 :",
"MethodDecl_z1 : MethodDecl_rec",
"MethodDecl_rec : MethodDecl",
"MethodDecl_rec : MethodDecl_rec MethodDecl",
"Decls : DECLARATIONSnum ENDDECLARATIONSnum",
"Decls : DECLARATIONSnum FieldDecl_rec ENDDECLARATIONSnum",
"FieldDecl_rec : FieldDecl",
"FieldDecl_rec : FieldDecl_rec FieldDecl",
"$$1 :",
"FieldDecl : Type $$1 FieldDecl_body SEMInum",
"Tail : VariableDeclId",
"Tail : VariableDeclId EQUALnum VariableInitializer",
"FieldDecl_body : Tail",
"FieldDecl_body : FieldDecl_body COMMAnum Tail",
"VariableDeclId : IDnum",
"VariableDeclId : IDnum Bracket_rec1",
"Bracket_rec1 : LBRACnum RBRACnum",
"Bracket_rec1 : Bracket_rec1 LBRACnum RBRACnum",
"VariableInitializer : Expression",
"VariableInitializer : ArrayInitializer",
"VariableInitializer : ArrayCreationExpression",
"ArrayInitializer : LBRACEnum ArrayInitializer_body RBRACEnum",
"ArrayInitializer_body : VariableInitializer",
"ArrayInitializer_body : ArrayInitializer_body COMMAnum VariableInitializer",
"ArrayCreationExpression : INTnum ArrayCreationExpression_tail",
"ArrayCreationExpression_tail : LBRACnum Expression RBRACnum",
"ArrayCreationExpression_tail : ArrayCreationExpression_tail LBRACnum Expression RBRACnum",
"$$2 :",
"MethodDecl : METHODnum Type $$2 IDnum LPARENnum FormalParameterList_z1 RPARENnum Block",
"$$3 :",
"MethodDecl : METHODnum VOIDnum $$3 IDnum LPARENnum FormalParameterList_z1 RPARENnum Block",
"FormalParameterList_z1 :",
"FormalParameterList_z1 : FormalParameterList",
"FormalParameterList : FormalParameterList_rec",
"FormalParameterList : FormalParameterList SEMInum FormalParameterList_rec",
"$$4 :",
"FormalParameterList_rec : INTnum $$4 IDENTIFIER_rec",
"$$5 :",
"FormalParameterList_rec : VALnum INTnum $$5 IDENTIFIER_rec",
"IDENTIFIER_rec : IDnum",
"IDENTIFIER_rec : IDENTIFIER_rec COMMAnum IDnum",
"Block : StatementList",
"Block : Decls StatementList",
"Type : Type_front",
"Type : Type_front Bracket_rec2",
"Type : Type_front Bracket_rec2 DOTnum Type",
"Type_front : IDnum",
"Type_front : INTnum",
"Bracket_rec2 : LBRACnum RBRACnum",
"Bracket_rec2 : LBRACnum RBRACnum Bracket_rec2",
"StatementList : LBRACEnum Statement_rec RBRACEnum",
"Statement_rec : Statement",
"Statement_rec : Statement_rec SEMInum Statement",
"Statement :",
"Statement : AssignmentStatement",
"Statement : MethodCallStatement",
"Statement : ReturnStatement",
"Statement : IfStatement",
"Statement : WhileStatement",
"AssignmentStatement : Variable ASSGNnum Expression",
"MethodCallStatement : Variable MethodCallStatement_tail",
"MethodCallStatement_tail : LPARENnum Expression_rec RPARENnum",
"MethodCallStatement_tail : LPARENnum RPARENnum",
"Expression_rec : Expression",
"Expression_rec : Expression COMMAnum Expression_rec",
"ReturnStatement : RETURNnum",
"ReturnStatement : RETURNnum Expression",
"IfStatement : IFnum Expression StatementList",
"IfStatement : If_rec StatementList",
"IfStatement : If_rec IFnum Expression StatementList",
"If_rec : IFnum Expression StatementList ELSEnum",
"If_rec : If_rec IFnum Expression StatementList ELSEnum",
"WhileStatement : WHILEnum Expression StatementList",
"Expression : SimpleExpression",
"Expression : SimpleExpression Comp_op SimpleExpression",
"Comp_op : LTnum",
"Comp_op : LEnum",
"Comp_op : EQnum",
"Comp_op : NEnum",
"Comp_op : GEnum",
"Comp_op : GTnum",
"SimpleExpression : Term",
"SimpleExpression : PLUSnum Term",
"SimpleExpression : MINUSnum Term",
"SimpleExpression : SimpleExpression PLUSnum Term",
"SimpleExpression : SimpleExpression MINUSnum Term",
"SimpleExpression : SimpleExpression ORnum Term",
"Term : Factor",
"Term : Term TIMESnum Factor",
"Term : Term DIVIDEnum Factor",
"Term : Term ANDnum Factor",
"Factor : UnsignedConstant",
"Factor : Variable",
"Factor : MethodCallStatement",
"Factor : LPARENnum Expression RPARENnum",
"Factor : NOTnum Factor",
"UnsignedConstant : ICONSTnum",
"UnsignedConstant : SCONSTnum",
"Variable : IDnum Variable_tail",
"Variable_tail :",
"Variable_tail : Variable_rec",
"Variable_rec : Variable_1",
"Variable_rec : Variable_1 Variable_rec",
"Variable_1 : LBRACnum Expression_rec2 RBRACnum",
"Variable_1 : DOTnum IDnum",
"Expression_rec2 : Expression",
"Expression_rec2 : Expression COMMAnum Expression_rec2",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

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

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 396 "grammar.y"

int yycolumn, yyline;

FILE *treelst;

/* main()
{
  treelst = stdout;
  yyparse();
} */

yyerror(char *str)
{
  printf("yyerror: %s at line %d\n", str, yyline);
}

#include "lex.yy.c"

#line 694 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
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
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

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

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
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
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 34 "grammar.y"
	{  
                          yyval.tptr = MakeTree(ProgramOp, yystack.l_mark[0].tptr, MakeLeaf(IDNode, yystack.l_mark[-2].intg));
                          SyntaxTree = yyval.tptr;
                          printtree(yyval.tptr, 0);
                        }
#line 1371 "y.tab.c"
break;
case 2:
#line 41 "grammar.y"
	{  yyval.tptr = MakeTree(ClassOp, NullExp(), yystack.l_mark[0].tptr); }
#line 1376 "y.tab.c"
break;
case 3:
#line 43 "grammar.y"
	{  yyval.tptr = MakeTree(ClassOp, yystack.l_mark[-1].tptr, yystack.l_mark[0].tptr); }
#line 1381 "y.tab.c"
break;
case 4:
#line 46 "grammar.y"
	{  yyval.tptr = MakeTree(ClassDefOp, yystack.l_mark[0].tptr, MakeLeaf(IDNode, yystack.l_mark[-1].intg)); }
#line 1386 "y.tab.c"
break;
case 5:
#line 49 "grammar.y"
	{  yyval.tptr = yystack.l_mark[-1].tptr; }
#line 1391 "y.tab.c"
break;
case 6:
#line 51 "grammar.y"
	{  /*tree tt;
			       tt = MakeTree(BodyOp, NullExp(), $2);*/

                             if ( NodeKind(yystack.l_mark[-1].tptr) == DUMMYNode )/* $3 is a NULL node */
                               yyval.tptr = yystack.l_mark[-2].tptr;
                             else/* $2 is the left child of $3 */
			       yyval.tptr = MkLeftC(yystack.l_mark[-2].tptr, yystack.l_mark[-1].tptr);
			  }
#line 1403 "y.tab.c"
break;
case 7:
#line 61 "grammar.y"
	{  yyval.tptr = NullExp(); }
#line 1408 "y.tab.c"
break;
case 8:
#line 63 "grammar.y"
	{  yyval.tptr = yystack.l_mark[0].tptr; }
#line 1413 "y.tab.c"
break;
case 9:
#line 66 "grammar.y"
	{  yyval.tptr = MakeTree(BodyOp, NullExp(), yystack.l_mark[0].tptr); }
#line 1418 "y.tab.c"
break;
case 10:
#line 68 "grammar.y"
	{  yyval.tptr = MakeTree(BodyOp, yystack.l_mark[-1].tptr, yystack.l_mark[0].tptr); }
#line 1423 "y.tab.c"
break;
case 11:
#line 71 "grammar.y"
	{  yyval.tptr = MakeTree(BodyOp, NullExp(), NullExp()); }
#line 1428 "y.tab.c"
break;
case 12:
#line 73 "grammar.y"
	{  yyval.tptr = yystack.l_mark[-1].tptr; }
#line 1433 "y.tab.c"
break;
case 13:
#line 76 "grammar.y"
	{  yyval.tptr = MakeTree(BodyOp, NullExp(), yystack.l_mark[0].tptr); }
#line 1438 "y.tab.c"
break;
case 14:
#line 78 "grammar.y"
	{  yyval.tptr = MakeTree(BodyOp, yystack.l_mark[-1].tptr, yystack.l_mark[0].tptr); }
#line 1443 "y.tab.c"
break;
case 15:
#line 80 "grammar.y"
	{ type_record = yystack.l_mark[0].tptr; }
#line 1448 "y.tab.c"
break;
case 16:
#line 81 "grammar.y"
	{  yyval.tptr = yystack.l_mark[-1].tptr; /* $3 is FieldDecl_body */ }
#line 1453 "y.tab.c"
break;
case 17:
#line 84 "grammar.y"
	{ 
                              tree commat;
                              commat = MakeTree(CommaOp, type_record, NullExp());
                              yyval.tptr = MakeTree(CommaOp, yystack.l_mark[0].tptr, commat);
                           }
#line 1462 "y.tab.c"
break;
case 18:
#line 90 "grammar.y"
	{
                              tree commat;
                              commat = MakeTree(CommaOp, type_record, yystack.l_mark[0].tptr);
                              yyval.tptr = MakeTree(CommaOp, yystack.l_mark[-2].tptr, commat);
                           }
#line 1471 "y.tab.c"
break;
case 19:
#line 97 "grammar.y"
	{  yyval.tptr = MakeTree(DeclOp, NullExp(), yystack.l_mark[0].tptr);  }
#line 1476 "y.tab.c"
break;
case 20:
#line 99 "grammar.y"
	{  yyval.tptr = MakeTree(DeclOp, yystack.l_mark[-2].tptr, yystack.l_mark[0].tptr);  }
#line 1481 "y.tab.c"
break;
case 21:
#line 102 "grammar.y"
	{  yyval.tptr = MakeLeaf(IDNode, yystack.l_mark[0].intg); }
#line 1486 "y.tab.c"
break;
case 22:
#line 104 "grammar.y"
	{   yyval.tptr = MakeLeaf(IDNode, yystack.l_mark[-1].intg); /* "[]" do not construct tree */ }
#line 1491 "y.tab.c"
break;
case 23:
#line 106 "grammar.y"
	{ yyval.tptr = NullExp(); }
#line 1496 "y.tab.c"
break;
case 24:
#line 107 "grammar.y"
	{ yyval.tptr = NullExp(); }
#line 1501 "y.tab.c"
break;
case 25:
#line 110 "grammar.y"
	{  yyval.tptr = yystack.l_mark[0].tptr; }
#line 1506 "y.tab.c"
break;
case 26:
#line 112 "grammar.y"
	{  yyval.tptr = yystack.l_mark[0].tptr; }
#line 1511 "y.tab.c"
break;
case 27:
#line 114 "grammar.y"
	{  yyval.tptr = yystack.l_mark[0].tptr; }
#line 1516 "y.tab.c"
break;
case 28:
#line 117 "grammar.y"
	{  yyval.tptr = MakeTree(ArrayTypeOp, yystack.l_mark[-1].tptr, type_record); }
#line 1521 "y.tab.c"
break;
case 29:
#line 120 "grammar.y"
	{ yyval.tptr = MakeTree( CommaOp, NullExp(), yystack.l_mark[0].tptr); }
#line 1526 "y.tab.c"
break;
case 30:
#line 122 "grammar.y"
	{ yyval.tptr = MakeTree( CommaOp, yystack.l_mark[-2].tptr, yystack.l_mark[0].tptr ); }
#line 1531 "y.tab.c"
break;
case 31:
#line 125 "grammar.y"
	{  yyval.tptr = MakeTree( ArrayTypeOp, yystack.l_mark[0].tptr, MakeLeaf(INTEGERTNode, yystack.l_mark[-1].intg) ); }
#line 1536 "y.tab.c"
break;
case 32:
#line 128 "grammar.y"
	{ yyval.tptr = MakeTree( BoundOp, NullExp(), yystack.l_mark[-1].tptr ); }
#line 1541 "y.tab.c"
break;
case 33:
#line 130 "grammar.y"
	{ yyval.tptr = MakeTree( BoundOp, yystack.l_mark[-3].tptr, yystack.l_mark[-1].tptr ); }
#line 1546 "y.tab.c"
break;
case 34:
#line 132 "grammar.y"
	{type_method=yystack.l_mark[0].tptr;}
#line 1551 "y.tab.c"
break;
case 35:
#line 134 "grammar.y"
	{ 
                        tree head;
                        head = MakeTree(HeadOp, MakeLeaf(IDNode, yystack.l_mark[-4].intg), yystack.l_mark[-2].tptr);
                        yyval.tptr = MakeTree(MethodOp, head, yystack.l_mark[0].tptr);
                      }
#line 1560 "y.tab.c"
break;
case 36:
#line 139 "grammar.y"
	{type_method=NullExp();}
#line 1565 "y.tab.c"
break;
case 37:
#line 140 "grammar.y"
	{ 
                        tree head;
                        head = MakeTree(HeadOp, MakeLeaf(IDNode, yystack.l_mark[-4].intg), yystack.l_mark[-2].tptr);
                        yyval.tptr = MakeTree(MethodOp, head, yystack.l_mark[0].tptr);
                      }
#line 1574 "y.tab.c"
break;
case 38:
#line 147 "grammar.y"
	{  yyval.tptr = MakeTree(SpecOp, NullExp(), type_method); }
#line 1579 "y.tab.c"
break;
case 39:
#line 149 "grammar.y"
	{  yyval.tptr = MakeTree(SpecOp, yystack.l_mark[0].tptr, type_method); }
#line 1584 "y.tab.c"
break;
case 40:
#line 153 "grammar.y"
	{ yyval.tptr = yystack.l_mark[0].tptr; }
#line 1589 "y.tab.c"
break;
case 41:
#line 155 "grammar.y"
	{ yyval.tptr = MkRightC(yystack.l_mark[0].tptr, yystack.l_mark[-2].tptr); }
#line 1594 "y.tab.c"
break;
case 42:
#line 158 "grammar.y"
	{
                                      argtype = MakeTree(RArgTypeOp, NullExp(), NullExp());
                                      yyval.tptr = MakeTree(RArgTypeOp, NullExp(), argtype);/* lchild is unknown*/
                                    }
#line 1602 "y.tab.c"
break;
case 43:
#line 163 "grammar.y"
	{ 
                                      SetLeftChild(yystack.l_mark[-1].tptr, yystack.l_mark[0].tptr);
                                      if ( NodeKind(LeftChild(RightChild(yystack.l_mark[-1].tptr))) == DUMMYNode )/* no comma */
                                         SetRightChild( yystack.l_mark[-1].tptr, NullExp() );
                                      else
					{
					  tree t = yystack.l_mark[-1].tptr; /* head of the tree */
                                          /* delete the tangling right most child */
                                          while ( t->RightC != argtype )
                                                 t = t->RightC;
                                          t->RightC = NullExp();
                                          free( argtype );
                                        }
                                      yyval.tptr = yystack.l_mark[-1].tptr;  /* return to FormalParameterList_rec */                  
                                    }
#line 1621 "y.tab.c"
break;
case 44:
#line 180 "grammar.y"
	{
                                      argtype = MakeTree(VArgTypeOp, NullExp(), NullExp());
                                      yyval.tptr = MakeTree(VArgTypeOp, NullExp(), argtype);/* lchild is unknown*/
				    }
#line 1629 "y.tab.c"
break;
case 45:
#line 185 "grammar.y"
	{
                                      SetLeftChild(yystack.l_mark[-1].tptr, yystack.l_mark[0].tptr); 
                                      if ( NodeKind(LeftChild(RightChild(yystack.l_mark[-1].tptr))) == DUMMYNode )/* no comma */
                                         SetRightChild( yystack.l_mark[-1].tptr, NullExp() );  
                                      else
					{
					  tree t = yystack.l_mark[-1].tptr; /* head of the tree */
                                          /* delete the tangling right most child */
                                          while ( t->RightC != argtype )
                                                 t = t->RightC;
                                          t->RightC = NullExp();
                                          free( argtype );
                                        }
                                      yyval.tptr = yystack.l_mark[-1].tptr;  /* return to FormalParameterList_rec */                  
			            }
#line 1648 "y.tab.c"
break;
case 46:
#line 203 "grammar.y"
	{ yyval.tptr = MakeTree(CommaOp, MakeLeaf(IDNode,yystack.l_mark[0].intg), MakeLeaf(INTEGERTNode,0)); }
#line 1653 "y.tab.c"
break;
case 47:
#line 205 "grammar.y"
	{ 
                                    tree comma, temp;

                                    yyval.tptr = yystack.l_mark[-2].tptr;
                                    comma = MakeTree(CommaOp, MakeLeaf(IDNode,yystack.l_mark[0].intg), MakeLeaf(INTEGERTNode,0));
                                    MkLeftC( comma, argtype );
                                    temp = MakeTree(NodeOp(argtype), NullExp(), NullExp());
                                    SetRightChild(argtype, temp);
                                    argtype = temp;
                                  }
#line 1667 "y.tab.c"
break;
case 48:
#line 217 "grammar.y"
	{ yyval.tptr = MakeTree(BodyOp, NullExp(), yystack.l_mark[0].tptr); }
#line 1672 "y.tab.c"
break;
case 49:
#line 219 "grammar.y"
	{ yyval.tptr = MakeTree(BodyOp, yystack.l_mark[-1].tptr, yystack.l_mark[0].tptr); }
#line 1677 "y.tab.c"
break;
case 50:
#line 222 "grammar.y"
	{ yyval.tptr = MakeTree(TypeIdOp, yystack.l_mark[0].tptr, NullExp()); }
#line 1682 "y.tab.c"
break;
case 51:
#line 224 "grammar.y"
	{ yyval.tptr = MakeTree(TypeIdOp, yystack.l_mark[-1].tptr, yystack.l_mark[0].tptr); }
#line 1687 "y.tab.c"
break;
case 52:
#line 226 "grammar.y"
	{ 
                         tree temp;
                         temp = MakeTree(TypeIdOp, yystack.l_mark[-3].tptr, yystack.l_mark[-2].tptr);
                         yyval.tptr = MkRightC( yystack.l_mark[0].tptr, temp );
		       }
#line 1696 "y.tab.c"
break;
case 53:
#line 233 "grammar.y"
	{ yyval.tptr = MakeLeaf(IDNode, yystack.l_mark[0].intg); }
#line 1701 "y.tab.c"
break;
case 54:
#line 235 "grammar.y"
	{ yyval.tptr = MakeLeaf(INTEGERTNode, yystack.l_mark[0].intg);}
#line 1706 "y.tab.c"
break;
case 55:
#line 238 "grammar.y"
	{ yyval.tptr = MakeTree(IndexOp, NullExp(), NullExp()); }
#line 1711 "y.tab.c"
break;
case 56:
#line 240 "grammar.y"
	{ yyval.tptr = MakeTree(IndexOp, NullExp(), yystack.l_mark[0].tptr); }
#line 1716 "y.tab.c"
break;
case 57:
#line 243 "grammar.y"
	{ yyval.tptr = yystack.l_mark[-1].tptr; }
#line 1721 "y.tab.c"
break;
case 58:
#line 246 "grammar.y"
	{ yyval.tptr = MakeTree(StmtOp, NullExp(), yystack.l_mark[0].tptr);  }
#line 1726 "y.tab.c"
break;
case 59:
#line 248 "grammar.y"
	{ 
                        if ( NodeKind(yystack.l_mark[0].tptr) == DUMMYNode )
                           yyval.tptr = yystack.l_mark[-2].tptr;
                        else
                           yyval.tptr = MakeTree(StmtOp, yystack.l_mark[-2].tptr, yystack.l_mark[0].tptr);
                      }
#line 1736 "y.tab.c"
break;
case 60:
#line 256 "grammar.y"
	{ yyval.tptr = NullExp(); }
#line 1741 "y.tab.c"
break;
case 61:
#line 258 "grammar.y"
	{ yyval.tptr = yystack.l_mark[0].tptr; }
#line 1746 "y.tab.c"
break;
case 62:
#line 260 "grammar.y"
	{ yyval.tptr = yystack.l_mark[0].tptr; }
#line 1751 "y.tab.c"
break;
case 63:
#line 262 "grammar.y"
	{ yyval.tptr = yystack.l_mark[0].tptr; }
#line 1756 "y.tab.c"
break;
case 64:
#line 264 "grammar.y"
	{ yyval.tptr = yystack.l_mark[0].tptr; }
#line 1761 "y.tab.c"
break;
case 65:
#line 266 "grammar.y"
	{ yyval.tptr = yystack.l_mark[0].tptr; }
#line 1766 "y.tab.c"
break;
case 66:
#line 269 "grammar.y"
	{ yyval.tptr = MakeTree(AssignOp, MakeTree(AssignOp, NullExp(), yystack.l_mark[-2].tptr), yystack.l_mark[0].tptr); }
#line 1771 "y.tab.c"
break;
case 67:
#line 272 "grammar.y"
	{ yyval.tptr = MakeTree(RoutineCallOp, yystack.l_mark[-1].tptr, yystack.l_mark[0].tptr); }
#line 1776 "y.tab.c"
break;
case 68:
#line 275 "grammar.y"
	{ yyval.tptr = yystack.l_mark[-1].tptr; }
#line 1781 "y.tab.c"
break;
case 69:
#line 277 "grammar.y"
	{ yyval.tptr = NullExp(); }
#line 1786 "y.tab.c"
break;
case 70:
#line 280 "grammar.y"
	{  yyval.tptr = MakeTree( CommaOp, yystack.l_mark[0].tptr, NullExp() ); }
#line 1791 "y.tab.c"
break;
case 71:
#line 282 "grammar.y"
	{  yyval.tptr = MakeTree( CommaOp, yystack.l_mark[-2].tptr, yystack.l_mark[0].tptr ); }
#line 1796 "y.tab.c"
break;
case 72:
#line 285 "grammar.y"
	{  yyval.tptr = MakeTree(ReturnOp, NullExp(), NullExp() ); }
#line 1801 "y.tab.c"
break;
case 73:
#line 287 "grammar.y"
	{  yyval.tptr = MakeTree(ReturnOp, yystack.l_mark[0].tptr, NullExp()); }
#line 1806 "y.tab.c"
break;
case 74:
#line 290 "grammar.y"
	{ yyval.tptr = MakeTree(IfElseOp, NullExp(), MakeTree(CommaOp, yystack.l_mark[-1].tptr, yystack.l_mark[0].tptr)); }
#line 1811 "y.tab.c"
break;
case 75:
#line 292 "grammar.y"
	{ yyval.tptr = MakeTree(IfElseOp, yystack.l_mark[-1].tptr, yystack.l_mark[0].tptr); }
#line 1816 "y.tab.c"
break;
case 76:
#line 294 "grammar.y"
	{ 
                            tree temp;
                            temp = MakeTree(IfElseOp, NullExp(), MakeTree(CommaOp, yystack.l_mark[-1].tptr, yystack.l_mark[0].tptr)); 
                            yyval.tptr = MkLeftC( yystack.l_mark[-3].tptr, temp);
                          }
#line 1825 "y.tab.c"
break;
case 77:
#line 301 "grammar.y"
	{ yyval.tptr = MakeTree(IfElseOp, NullExp(), MakeTree(CommaOp, yystack.l_mark[-2].tptr, yystack.l_mark[-1].tptr)); }
#line 1830 "y.tab.c"
break;
case 78:
#line 303 "grammar.y"
	{  
                            tree temp;
                            temp = MakeTree(IfElseOp, NullExp(), MakeTree(CommaOp, yystack.l_mark[-2].tptr, yystack.l_mark[-1].tptr));
                            yyval.tptr = MkLeftC( yystack.l_mark[-4].tptr, temp);                          
                          }
#line 1839 "y.tab.c"
break;
case 79:
#line 310 "grammar.y"
	{  yyval.tptr = MakeTree(LoopOp, yystack.l_mark[-1].tptr, yystack.l_mark[0].tptr); }
#line 1844 "y.tab.c"
break;
case 80:
#line 313 "grammar.y"
	{yyval.tptr = yystack.l_mark[0].tptr;}
#line 1849 "y.tab.c"
break;
case 81:
#line 315 "grammar.y"
	{
                            MkLeftC(yystack.l_mark[-2].tptr, yystack.l_mark[-1].tptr);
                            yyval.tptr = MkRightC(yystack.l_mark[0].tptr, yystack.l_mark[-1].tptr);
                          }
#line 1857 "y.tab.c"
break;
case 82:
#line 321 "grammar.y"
	{ yyval.tptr = MakeTree(LTOp, NullExp(), NullExp()); }
#line 1862 "y.tab.c"
break;
case 83:
#line 323 "grammar.y"
	{ yyval.tptr = MakeTree(LEOp, NullExp(), NullExp()); }
#line 1867 "y.tab.c"
break;
case 84:
#line 325 "grammar.y"
	{ yyval.tptr = MakeTree(EQOp, NullExp(), NullExp()); }
#line 1872 "y.tab.c"
break;
case 85:
#line 327 "grammar.y"
	{ yyval.tptr = MakeTree(NEOp, NullExp(), NullExp()); }
#line 1877 "y.tab.c"
break;
case 86:
#line 329 "grammar.y"
	{ yyval.tptr = MakeTree(GEOp, NullExp(), NullExp()); }
#line 1882 "y.tab.c"
break;
case 87:
#line 331 "grammar.y"
	{ yyval.tptr = MakeTree(GTOp, NullExp(), NullExp()); }
#line 1887 "y.tab.c"
break;
case 88:
#line 334 "grammar.y"
	{ yyval.tptr = yystack.l_mark[0].tptr; }
#line 1892 "y.tab.c"
break;
case 89:
#line 336 "grammar.y"
	{ yyval.tptr = yystack.l_mark[0].tptr; }
#line 1897 "y.tab.c"
break;
case 90:
#line 338 "grammar.y"
	{ yyval.tptr = MakeTree(UnaryNegOp, yystack.l_mark[0].tptr, NullExp()); }
#line 1902 "y.tab.c"
break;
case 91:
#line 340 "grammar.y"
	{ yyval.tptr = MakeTree(AddOp, yystack.l_mark[-2].tptr, yystack.l_mark[0].tptr); }
#line 1907 "y.tab.c"
break;
case 92:
#line 342 "grammar.y"
	{ yyval.tptr = MakeTree(SubOp, yystack.l_mark[-2].tptr, yystack.l_mark[0].tptr); }
#line 1912 "y.tab.c"
break;
case 93:
#line 344 "grammar.y"
	{ yyval.tptr = MakeTree(OrOp, yystack.l_mark[-2].tptr, yystack.l_mark[0].tptr); }
#line 1917 "y.tab.c"
break;
case 94:
#line 347 "grammar.y"
	{ yyval.tptr = yystack.l_mark[0].tptr; }
#line 1922 "y.tab.c"
break;
case 95:
#line 349 "grammar.y"
	{ yyval.tptr = MakeTree(MultOp, yystack.l_mark[-2].tptr, yystack.l_mark[0].tptr); }
#line 1927 "y.tab.c"
break;
case 96:
#line 351 "grammar.y"
	{ yyval.tptr = MakeTree(DivOp, yystack.l_mark[-2].tptr, yystack.l_mark[0].tptr); }
#line 1932 "y.tab.c"
break;
case 97:
#line 353 "grammar.y"
	{ yyval.tptr = MakeTree(AndOp, yystack.l_mark[-2].tptr, yystack.l_mark[0].tptr); }
#line 1937 "y.tab.c"
break;
case 98:
#line 356 "grammar.y"
	{ yyval.tptr = yystack.l_mark[0].tptr; }
#line 1942 "y.tab.c"
break;
case 99:
#line 358 "grammar.y"
	{ yyval.tptr = yystack.l_mark[0].tptr; }
#line 1947 "y.tab.c"
break;
case 100:
#line 360 "grammar.y"
	{ yyval.tptr = yystack.l_mark[0].tptr; }
#line 1952 "y.tab.c"
break;
case 101:
#line 362 "grammar.y"
	{ yyval.tptr = yystack.l_mark[-1].tptr; }
#line 1957 "y.tab.c"
break;
case 102:
#line 364 "grammar.y"
	{ yyval.tptr = MakeTree(NotOp, yystack.l_mark[0].tptr, NullExp()); }
#line 1962 "y.tab.c"
break;
case 103:
#line 367 "grammar.y"
	{ yyval.tptr = MakeLeaf(NUMNode, yystack.l_mark[0].intg); }
#line 1967 "y.tab.c"
break;
case 104:
#line 369 "grammar.y"
	{ yyval.tptr = MakeLeaf(STRINGNode, yystack.l_mark[0].intg); }
#line 1972 "y.tab.c"
break;
case 105:
#line 372 "grammar.y"
	{ yyval.tptr = MakeTree( VarOp, MakeLeaf(IDNode, yystack.l_mark[-1].intg), yystack.l_mark[0].tptr); }
#line 1977 "y.tab.c"
break;
case 106:
#line 375 "grammar.y"
	{  yyval.tptr = NullExp(); }
#line 1982 "y.tab.c"
break;
case 107:
#line 377 "grammar.y"
	{  yyval.tptr = yystack.l_mark[0].tptr; }
#line 1987 "y.tab.c"
break;
case 108:
#line 380 "grammar.y"
	{ yyval.tptr = MakeTree( SelectOp, yystack.l_mark[0].tptr, NullExp() ); }
#line 1992 "y.tab.c"
break;
case 109:
#line 382 "grammar.y"
	{ yyval.tptr = MakeTree( SelectOp, yystack.l_mark[-1].tptr, yystack.l_mark[0].tptr ); }
#line 1997 "y.tab.c"
break;
case 110:
#line 385 "grammar.y"
	{  yyval.tptr = yystack.l_mark[-1].tptr; }
#line 2002 "y.tab.c"
break;
case 111:
#line 387 "grammar.y"
	{  yyval.tptr = MakeTree(FieldOp, MakeLeaf(IDNode, yystack.l_mark[0].intg), NullExp() ); }
#line 2007 "y.tab.c"
break;
case 112:
#line 390 "grammar.y"
	{ yyval.tptr = MakeTree(IndexOp, yystack.l_mark[0].tptr, NullExp()); }
#line 2012 "y.tab.c"
break;
case 113:
#line 392 "grammar.y"
	{ yyval.tptr = MakeTree(IndexOp, yystack.l_mark[-2].tptr, yystack.l_mark[0].tptr); }
#line 2017 "y.tab.c"
break;
#line 2019 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
