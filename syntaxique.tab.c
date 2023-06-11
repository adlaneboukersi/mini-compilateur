
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "syntaxique.y"

    #include <stdio.h>
    #include <stdlib.h> 
    #include <string.h>
    #include "TS.h"
    #include "RS.h"
    #include "QUAD.h"
    #include "Pile.h"
    #include "Optm.h"


    extern FILE* yyin;
    int ligne=1,colomne=1;
    int type=0,i,indx,dans_boucle=0;
    char *x;
    elem* element;


/* Line 189 of yacc.c  */
#line 92 "syntaxique.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     mc_prgm = 258,
     mc_sub = 259,
     mc_var = 260,
     mc_as = 261,
     mc_array = 262,
     mc_cst = 263,
     mc_int = 264,
     mc_flt = 265,
     mc_bol = 266,
     mc_chr = 267,
     mc_str = 268,
     mc_body = 269,
     mc_and = 270,
     mc_or = 271,
     mc_not = 272,
     mc_sup = 273,
     mc_supe = 274,
     mc_inf = 275,
     mc_infe = 276,
     mc_ega = 277,
     mc_dif = 278,
     mc_aff = 279,
     mc_input = 280,
     mc_output = 281,
     mc_if = 282,
     mc_then = 283,
     mc_else = 284,
     mc_do = 285,
     mc_while = 286,
     mc_for = 287,
     mc_until = 288,
     ENTIER = 289,
     ENTIERSigne = 290,
     REEL = 291,
     REELSigne = 292,
     CHR = 293,
     STR = 294,
     BOOL = 295,
     IDF = 296,
     symbole_ouvrant = 297,
     symbole_fermant = 298,
     symbole_ouvrant2 = 299,
     symbole_fermant2 = 300,
     ptexcl = 301,
     parenthes_ouvrante = 302,
     parenthes_fermant = 303,
     soustraction = 304,
     addition = 305,
     multiplication = 306,
     division = 307,
     egal = 308,
     dpts = 309,
     virgule = 310,
     bar = 311,
     croo = 312,
     crof = 313,
     err = 314
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 19 "syntaxique.y"
char* nom;  struct { int type; char* res; }NT; 


/* Line 214 of yacc.c  */
#line 191 "syntaxique.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 203 "syntaxique.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   336

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNRULES -- Number of states.  */
#define YYNSTATES  263

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    14,    16,    18,    20,    22,    24,
      26,    28,    30,    33,    35,    40,    45,    49,    52,    54,
      58,    64,    70,    73,    75,    85,    91,    97,   100,   103,
     105,   107,   112,   117,   121,   123,   125,   127,   129,   131,
     133,   135,   137,   139,   143,   147,   151,   154,   156,   158,
     160,   162,   164,   166,   169,   171,   173,   178,   182,   186,
     190,   194,   198,   205,   212,   219,   226,   233,   240,   247,
     254,   259,   261,   263,   265,   267,   269,   277,   284,   290,
     294,   300,   308,   314,   320,   324,   330,   334,   339,   343,
     350,   354,   358,   364,   372,   380,   384,   388,   393
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      61,     0,    -1,    62,    68,    85,   110,    -1,    42,    46,
       3,    41,    45,    -1,     9,    -1,    10,    -1,    13,    -1,
      12,    -1,    11,    -1,    70,    -1,    79,    -1,    73,    -1,
      64,    65,    -1,    64,    -1,    42,     4,     5,    43,    -1,
      44,     4,     5,    43,    -1,    66,    65,    67,    -1,    66,
      67,    -1,    41,    -1,    41,    56,    69,    -1,    42,    69,
       6,    63,    45,    -1,    42,    41,    54,    34,    45,    -1,
      71,    72,    -1,    71,    -1,    42,     7,     6,    63,    43,
      72,    44,     7,    43,    -1,    42,    41,    53,    92,    45,
      -1,    42,    69,     6,    63,    45,    -1,    74,    76,    -1,
      75,    76,    -1,    74,    -1,    75,    -1,    42,     4,     8,
      43,    -1,    44,     4,     8,    43,    -1,    77,    76,    78,
      -1,    34,    -1,    35,    -1,    36,    -1,    37,    -1,    80,
      -1,    81,    -1,    39,    -1,    38,    -1,    40,    -1,    42,
      14,    43,    -1,    44,    14,    43,    -1,    83,    87,    84,
      -1,    83,    84,    -1,    93,    -1,    94,    -1,    96,    -1,
     100,    -1,   104,    -1,   109,    -1,    87,    86,    -1,    86,
      -1,    41,    -1,    41,    57,    92,    58,    -1,    92,    50,
      92,    -1,    92,    49,    92,    -1,    92,    51,    92,    -1,
      92,    52,    92,    -1,    47,    92,    48,    -1,    18,    47,
      92,    55,    92,    48,    -1,    19,    47,    92,    55,    92,
      48,    -1,    20,    47,    92,    55,    92,    48,    -1,    21,
      47,    92,    55,    92,    48,    -1,    22,    47,    92,    55,
      92,    48,    -1,    23,    47,    92,    55,    92,    48,    -1,
      15,    47,    92,    55,    92,    48,    -1,    16,    47,    92,
      55,    92,    48,    -1,    17,    47,    92,    48,    -1,    90,
      -1,    89,    -1,    91,    -1,    88,    -1,    82,    -1,    42,
      24,    54,    88,    55,    92,    45,    -1,    42,    25,    54,
      88,    39,    45,    -1,    95,    50,    39,    50,    88,    -1,
      39,    50,    88,    -1,    42,    26,    54,    95,    45,    -1,
      42,    26,    54,    95,    50,    39,    45,    -1,    42,    26,
      54,    39,    45,    -1,    42,    26,    54,    88,    45,    -1,
      42,    30,    43,    -1,    42,    31,    54,    92,    45,    -1,
      44,    30,    43,    -1,    97,    87,    98,    99,    -1,    88,
      53,    92,    -1,    42,    32,   101,    33,    92,    43,    -1,
      44,    32,    43,    -1,   102,    87,   103,    -1,    42,    27,
      54,    92,    43,    -1,    42,    28,    43,    87,    44,    28,
      43,    -1,    42,    29,    43,    87,    44,    29,    43,    -1,
      44,    27,    43,    -1,   105,   106,   108,    -1,   105,   106,
     107,   108,    -1,    44,     3,    43,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    45,    45,    48,    60,    61,    62,    63,    64,    68,
      68,    68,    70,    70,    74,    76,    79,    80,    85,    86,
      90,   107,   113,   113,   115,   132,   144,   157,   157,   157,
     157,   161,   163,   165,   169,   170,   172,   173,   175,   181,
     186,   191,   196,   204,   206,   208,   209,   213,   213,   213,
     213,   213,   213,   215,   215,   220,   231,   248,   256,   263,
     270,   278,   289,   297,   304,   311,   318,   324,   333,   341,
     349,   355,   363,   369,   375,   391,   399,   412,   424,   431,
     440,   442,   448,   454,   463,   469,   475,   480,   484,   496,
     502,   507,   514,   520,   526,   528,   530,   535,   542
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "mc_prgm", "mc_sub", "mc_var", "mc_as",
  "mc_array", "mc_cst", "mc_int", "mc_flt", "mc_bol", "mc_chr", "mc_str",
  "mc_body", "mc_and", "mc_or", "mc_not", "mc_sup", "mc_supe", "mc_inf",
  "mc_infe", "mc_ega", "mc_dif", "mc_aff", "mc_input", "mc_output",
  "mc_if", "mc_then", "mc_else", "mc_do", "mc_while", "mc_for", "mc_until",
  "ENTIER", "ENTIERSigne", "REEL", "REELSigne", "CHR", "STR", "BOOL",
  "IDF", "symbole_ouvrant", "symbole_fermant", "symbole_ouvrant2",
  "symbole_fermant2", "ptexcl", "parenthes_ouvrante", "parenthes_fermant",
  "soustraction", "addition", "multiplication", "division", "egal", "dpts",
  "virgule", "bar", "croo", "crof", "err", "$accept", "S", "DEBUT", "TYPE",
  "DECLARATION", "LIST_DECLARATION", "DEB_DECLAR", "FIN_DECLAR", "DECLAR",
  "LIST_IDF", "DECLARATION_VAR", "BALISE_ARRAY", "LIST_ARRAY",
  "DECLARATION_ARRAY", "BALISE_CST_F1", "BALISE_CST_F2", "LIST_CST",
  "DEB_DECLARATION_CST", "FIN_DECLARATION_CST", "DECLARATION_CST", "INT",
  "FLT", "VAL", "DEB_BODY", "FIN_BODY", "BODY", "INST", "BLOC_INST",
  "VARIABLE", "EXP_ARTH", "EXP_COMP", "EXP_BOOL", "EXP", "AFF", "INPUT",
  "OUTPUT_SUITE", "OUTPUT", "DEB_WHILE", "CONDT_WHILE", "FIN_WHILE",
  "WHILE", "INIT_FOR", "DEB_FOR", "FIN_FOR", "FOR", "DEB_IF", "THEN",
  "ELSE", "FIN_IF", "IF", "FIN", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    63,    63,    63,    63,    63,    64,
      64,    64,    65,    65,    66,    67,    68,    68,    69,    69,
      70,    71,    72,    72,    73,    74,    75,    76,    76,    76,
      76,    77,    78,    79,    80,    80,    81,    81,    82,    82,
      82,    82,    82,    83,    84,    85,    85,    86,    86,    86,
      86,    86,    86,    87,    87,    88,    88,    89,    89,    89,
      89,    89,    90,    90,    90,    90,    90,    90,    91,    91,
      91,    91,    92,    92,    92,    92,    93,    94,    95,    95,
      96,    96,    96,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   109,   110
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     4,     4,     3,     2,     1,     3,
       5,     5,     2,     1,     9,     5,     5,     2,     2,     1,
       1,     4,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     4,     3,     3,     3,
       3,     3,     6,     6,     6,     6,     6,     6,     6,     6,
       4,     1,     1,     1,     1,     1,     7,     6,     5,     3,
       5,     7,     5,     5,     3,     5,     3,     4,     3,     6,
       3,     3,     5,     7,     7,     3,     3,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,    13,     0,    17,     9,    11,     0,    10,
       0,     0,     0,     0,     0,     0,     0,    18,     0,     0,
      12,    16,     0,    29,    30,     0,     0,     0,     0,    46,
      54,     0,    47,    48,    49,     0,    50,     0,    51,     0,
      52,     0,     2,     3,    14,     0,     0,     0,     0,     0,
      18,     0,    27,    28,     0,    33,    43,     0,     0,     0,
       0,     0,     0,     0,    45,    53,     0,     0,     0,     0,
       0,    31,     4,     5,     8,     7,     6,     0,    19,     0,
      15,     0,     0,     0,     0,     0,     0,     0,    84,    55,
       0,     0,    44,     0,     0,     0,    91,     0,     0,     0,
       0,    96,    98,     0,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,    35,    36,    37,    41,    40,
      42,     0,    38,    39,    75,    74,    72,    71,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,     0,     0,     0,     0,    97,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,     0,     0,     0,     0,    26,    32,     0,
       0,    82,     0,    83,    80,     0,    92,     0,    88,     0,
       0,     0,    90,     0,     0,    95,     0,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,    58,
      57,    59,    60,     0,    77,    79,     0,    56,    89,     0,
      86,     0,     0,     0,     0,     0,     0,    70,     0,     0,
       0,     0,     0,     0,    76,    81,     0,    85,     0,     0,
       0,    24,     0,     0,     0,     0,     0,     0,     0,     0,
      78,    93,     0,    21,    68,    69,    62,    63,    64,    65,
      66,    67,    94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    87,    13,    14,     7,    15,     8,    28,
      16,   160,   161,    17,    33,    34,    35,    18,    65,    19,
     132,   133,   134,    21,    39,    22,    40,    41,   135,   136,
     137,   138,   139,    42,    43,   146,    44,    45,   104,   153,
      46,   101,    47,   106,    48,    49,    79,   110,   111,    50,
      52
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -95
static const yytype_int16 yypact[] =
{
     -21,    38,    57,    41,    87,   -95,   101,   -22,    68,    84,
     114,     1,   122,   100,   105,   -95,   -95,   -95,   115,   -95,
     144,    -1,   120,   126,   129,   171,   172,   130,   181,   188,
     -95,   -95,   153,   115,   115,   156,   158,    76,   247,   -95,
     -95,    -1,   -95,   -95,   -95,   220,   -95,   220,   -95,   221,
     -95,   261,   -95,   -95,   -95,   222,    54,   225,    54,   224,
      51,   262,   -95,   -95,   265,   -95,   -95,   217,   218,   219,
     223,   227,   233,   232,   -95,   -95,   234,    99,   250,   106,
     236,   -95,   -95,   -95,   -95,   -95,   -95,   237,   -95,   238,
     -95,    11,    54,   273,   233,   233,    79,    11,   -95,   228,
     229,   251,   -95,    67,   242,   255,   -95,   245,   260,   263,
     248,   -95,   -95,   249,   -95,   246,   252,   253,   254,   256,
     257,   258,   259,   264,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,    11,   -95,   -95,   -95,   -95,   -95,   -95,   -95,    64,
     267,   266,   239,   268,   -38,   269,   -31,   -34,    11,    11,
      11,   241,   272,   -95,   270,   220,   274,   275,   -95,   278,
     249,   271,    11,    11,    11,    11,    11,    11,    11,    11,
      11,   155,   -95,    11,    11,    11,    11,   -95,   -95,    11,
     276,   -95,   233,   -95,   -95,   277,   -95,    37,   204,    10,
      11,   279,   -95,   215,   220,   -95,   243,   -95,   289,    78,
     104,   160,   111,   118,   125,   133,   140,   147,   -95,    26,
      26,   -95,   -95,    72,   -95,   -95,    -6,   -95,   -95,    95,
     -95,   280,   216,   286,   281,    11,    11,   -95,    11,    11,
      11,    11,    11,    11,   -95,   -95,   233,   -95,   282,   294,
     283,   -95,   165,   170,   175,   180,   185,   190,   195,   200,
     -95,   -95,   284,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   -95,   -52,   -95,   285,   -95,   296,   -95,   -19,
     -95,   -95,   166,   -95,   -95,   -95,   -23,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   288,   -95,   -41,   -43,   -71,   -95,
     -95,   -95,   -94,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   226,   -95,
     -95
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      75,   100,    76,   147,    77,    25,    89,   181,    26,   186,
      62,    63,   182,    61,   184,   173,   174,   175,   176,   185,
      11,     1,    12,   142,   143,   145,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    75,    75,   171,    88,   235,
     140,    37,    27,    38,   236,   124,   125,   126,   127,   128,
     129,   130,    99,   218,   187,   188,   189,     5,   131,   173,
     174,   175,   176,    82,    83,    84,    85,    86,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   175,   176,   209,
     210,   211,   212,     6,     4,   213,   173,   174,   175,   176,
       9,    67,    68,    69,    70,   217,   219,    71,   151,    72,
      67,    68,    69,    70,    91,    10,    71,    57,    72,   172,
      20,   215,   193,   173,   174,   175,   176,   234,   144,    24,
      99,   173,   174,   175,   176,    23,    29,   173,   174,   175,
     176,   242,   243,   225,   244,   245,   246,   247,   248,   249,
     237,    37,    11,   105,   173,   174,   175,   176,   108,    12,
     109,   222,    75,   173,   174,   175,   176,    32,    36,   226,
     173,   174,   175,   176,    51,   250,   228,   173,   174,   175,
     176,    53,    54,   229,   173,   174,   175,   176,    56,    55,
     230,    75,   173,   174,   175,   176,    57,    58,   231,   173,
     174,   175,   176,    59,    60,   232,   173,   174,   175,   176,
      64,    66,   233,   208,   173,   174,   175,   176,   227,   173,
     174,   175,   176,   254,   173,   174,   175,   176,   255,   173,
     174,   175,   176,   256,   173,   174,   175,   176,   257,   173,
     174,   175,   176,   258,   173,   174,   175,   176,   259,   173,
     174,   175,   176,   260,   173,   174,   175,   176,   261,   173,
     174,   175,   176,   173,   174,   175,   176,    37,    37,   221,
     239,    73,    37,    78,    80,    81,    27,    90,    92,    93,
      98,    94,    95,    96,    99,   102,   103,    97,   107,   112,
     113,   141,   149,   114,   150,   148,   152,   154,   155,   156,
     157,   159,   109,   162,   179,   190,   224,   223,    30,   163,
     164,   165,   191,   166,   167,   168,   169,   180,   238,   178,
      31,   170,   177,   192,   183,   198,   216,   194,   195,   196,
     240,   214,   220,   252,   241,   251,   197,   262,   253,    74,
       0,     0,     0,     0,     0,     0,   158
};

static const yytype_int16 yycheck[] =
{
      41,    72,    45,    97,    47,     4,    58,    45,     7,    43,
      33,    34,    50,    32,    45,    49,    50,    51,    52,    50,
      42,    42,    44,    94,    95,    96,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    76,    77,   131,    57,    45,
      92,    42,    41,    44,    50,    34,    35,    36,    37,    38,
      39,    40,    41,    43,   148,   149,   150,     0,    47,    49,
      50,    51,    52,     9,    10,    11,    12,    13,   162,   163,
     164,   165,   166,   167,   168,   169,   170,    51,    52,   173,
     174,   175,   176,    42,    46,   179,    49,    50,    51,    52,
       3,    24,    25,    26,    27,    58,   190,    30,    31,    32,
      24,    25,    26,    27,    53,     4,    30,    56,    32,    45,
      42,   182,   155,    49,    50,    51,    52,    45,    39,     5,
      41,    49,    50,    51,    52,    41,     4,    49,    50,    51,
      52,   225,   226,    55,   228,   229,   230,   231,   232,   233,
      45,    42,    42,    44,    49,    50,    51,    52,    42,    44,
      44,   194,   193,    49,    50,    51,    52,    42,    14,    55,
      49,    50,    51,    52,    44,   236,    55,    49,    50,    51,
      52,    45,    43,    55,    49,    50,    51,    52,     6,     8,
      55,   222,    49,    50,    51,    52,    56,     6,    55,    49,
      50,    51,    52,     5,    41,    55,    49,    50,    51,    52,
      44,    43,    55,    48,    49,    50,    51,    52,    48,    49,
      50,    51,    52,    48,    49,    50,    51,    52,    48,    49,
      50,    51,    52,    48,    49,    50,    51,    52,    48,    49,
      50,    51,    52,    48,    49,    50,    51,    52,    48,    49,
      50,    51,    52,    48,    49,    50,    51,    52,    48,    49,
      50,    51,    52,    49,    50,    51,    52,    42,    42,    44,
      44,    14,    42,    42,     3,    43,    41,    43,     6,     4,
      43,    54,    54,    54,    41,    43,    42,    54,    28,    43,
      43,     8,    53,    45,    33,    57,    44,    32,    43,    29,
      27,    42,    44,    47,    55,    54,     7,    54,    13,    47,
      47,    47,    30,    47,    47,    47,    47,    39,    28,    43,
      14,    47,    45,    43,    45,    44,    39,    43,    43,    41,
      34,    45,    43,    29,    43,    43,   160,    43,    45,    41,
      -1,    -1,    -1,    -1,    -1,    -1,   110
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    61,    62,    46,     0,    42,    66,    68,     3,
       4,    42,    44,    64,    65,    67,    70,    73,    77,    79,
      42,    83,    85,    41,     5,     4,     7,    41,    69,     4,
      65,    67,    42,    74,    75,    76,    14,    42,    44,    84,
      86,    87,    93,    94,    96,    97,   100,   102,   104,   105,
     109,    44,   110,    45,    43,     8,     6,    56,     6,     5,
      41,    69,    76,    76,    44,    78,    43,    24,    25,    26,
      27,    30,    32,    14,    84,    86,    87,    87,    42,   106,
       3,    43,     9,    10,    11,    12,    13,    63,    69,    63,
      43,    53,     6,     4,    54,    54,    54,    54,    43,    41,
      88,   101,    43,    42,    98,    44,   103,    28,    42,    44,
     107,   108,    43,    43,    45,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    34,    35,    36,    37,    38,    39,
      40,    47,    80,    81,    82,    88,    89,    90,    91,    92,
      63,     8,    88,    88,    39,    88,    95,    92,    57,    53,
      33,    31,    44,    99,    32,    43,    29,    27,   108,    42,
      71,    72,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    92,    45,    49,    50,    51,    52,    45,    43,    55,
      39,    45,    50,    45,    45,    50,    43,    92,    92,    92,
      54,    30,    43,    87,    43,    43,    41,    72,    44,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    48,    92,
      92,    92,    92,    92,    45,    88,    39,    58,    43,    92,
      43,    44,    87,    54,     7,    55,    55,    48,    55,    55,
      55,    55,    55,    55,    45,    45,    50,    45,    28,    44,
      34,    43,    92,    92,    92,    92,    92,    92,    92,    92,
      88,    43,    29,    45,    48,    48,    48,    48,    48,    48,
      48,    48,    43
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 45 "syntaxique.y"
    {printf("le programme lexicalement, syntaxiquement et semantiquement correct\n");YYACCEPT;;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 49 "syntaxique.y"
    {
 
indx=Fhach((yyvsp[(4) - (5)].nom));//trouver de l'idf dans TS
inserer(strdup((yyvsp[(4) - (5)].nom)),0,0,0,indx);//inserer le comme l'id de prg
get_obj((yyvsp[(4) - (5)].nom))->nbrUse+=2;//pour proteger l'id de optimisation 

 ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 60 "syntaxique.y"
    {type=1;;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 61 "syntaxique.y"
    {type=2;;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 62 "syntaxique.y"
    {type=3;;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 63 "syntaxique.y"
    {type=4;;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 64 "syntaxique.y"
    {type=5;;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 85 "syntaxique.y"
    {empiler(strdup((yyvsp[(1) - (1)].nom)));;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 86 "syntaxique.y"
    {empiler(strdup((yyvsp[(1) - (3)].nom)));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 91 "syntaxique.y"
    {

  while(!pileVide())
{
x=depiler();
i=recherche(x,&indx,&element);
doubleDec(i);
inserer(x,type,1,0,indx);                                       
}
type=0;
x="";

;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 108 "syntaxique.y"
    {
empiler(strdup((yyvsp[(4) - (5)].nom)));//empiler la taille
empiler(strdup((yyvsp[(2) - (5)].nom)));
;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 116 "syntaxique.y"
    {
while(!pileVide())
{
x=depiler();
i=recherche(x,&indx,&element);
doubleDec(i);
i=atoi(depiler());//la taille
erreur_taille(i);
inserer(x,type,2,i,indx);                                       
 }
 type=0;
 x="";
                ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 133 "syntaxique.y"
    {
  x=strdup((yyvsp[(2) - (5)].nom));
i=recherche(x,&indx,&element);
doubleDec(i);
inserer(x,(yyvsp[(4) - (5)].NT).type,3,0,indx);
quadAFF((yyvsp[(2) - (5)].nom),(yyvsp[(4) - (5)].NT).res);
get_obj(x)->nbrAff++;
x="";

;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 145 "syntaxique.y"
    {
while(!pileVide())
{
x=depiler();
i=recherche(x,&indx,&element);
doubleDec(i);
inserer(x,type,4,0,indx);                                       
}
type=0;
x="";
 ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 169 "syntaxique.y"
    {(yyval.nom)=ajuster_entier((yyvsp[(1) - (1)].nom));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 170 "syntaxique.y"
    {(yyval.nom)=ajuster_entier((yyvsp[(1) - (1)].nom));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 172 "syntaxique.y"
    {(yyval.nom)=ajuster_float((yyvsp[(1) - (1)].nom));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 173 "syntaxique.y"
    {(yyval.nom)=ajuster_float((yyvsp[(1) - (1)].nom));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 176 "syntaxique.y"
    {
(yyval.NT).type=1;
(yyval.NT).res=strdup((yyvsp[(1) - (1)].nom));
;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 182 "syntaxique.y"
    {
(yyval.NT).type=2;
(yyval.NT).res=strdup((yyvsp[(1) - (1)].nom));
;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 187 "syntaxique.y"
    {
(yyval.NT).type=3;
(yyval.NT).res=strdup((yyvsp[(1) - (1)].nom));
;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 192 "syntaxique.y"
    {
(yyval.NT).type=4;
(yyval.NT).res=strdup((yyvsp[(1) - (1)].nom));
;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 197 "syntaxique.y"
    {
(yyval.NT).type=5;
(yyval.NT).res=(yyvsp[(1) - (1)].nom);
;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 221 "syntaxique.y"
    {
x=strdup((yyvsp[(1) - (1)].nom));
i=recherche(x,&indx,&element);
nonDec(i);
erreur_indice(element->classe);
(yyval.NT).type=element->type;
(yyval.NT).res=strdup(x);
x="";
;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 232 "syntaxique.y"
    {
x=strdup((yyvsp[(1) - (4)].nom));

i=recherche(x,&indx,&element);
nonDec(i);
erreur_tab(element->classe);                   
incomptabiliteType((yyvsp[(3) - (4)].NT).type,1);//l'indice' doit etre int
(yyval.NT).type=element->type;
sprintf(x,"%s[%s]",strdup(x),strdup((yyvsp[(3) - (4)].NT).res));
(yyval.NT).res=strdup(x);
x="";
;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 249 "syntaxique.y"
    {
(yyval.NT).type=incomptabiliteType((yyvsp[(1) - (3)].NT).type,(yyvsp[(3) - (3)].NT).type);
err_type_arth((yyval.NT).type);
(yyval.NT).res=quadARTH("+",(yyvsp[(1) - (3)].NT).res,(yyvsp[(3) - (3)].NT).res);
;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 257 "syntaxique.y"
    {
(yyval.NT).type=incomptabiliteType((yyvsp[(1) - (3)].NT).type,(yyvsp[(3) - (3)].NT).type);
err_type_arth((yyval.NT).type);
(yyval.NT).res=quadARTH("-",(yyvsp[(1) - (3)].NT).res,(yyvsp[(3) - (3)].NT).res);
;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 264 "syntaxique.y"
    {
(yyval.NT).type=incomptabiliteType((yyvsp[(1) - (3)].NT).type,(yyvsp[(3) - (3)].NT).type);
err_type_arth((yyval.NT).type);
(yyval.NT).res=quadARTH("*",(yyvsp[(1) - (3)].NT).res,(yyvsp[(3) - (3)].NT).res);
;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 271 "syntaxique.y"
    {
(yyval.NT).type=incomptabiliteType((yyvsp[(1) - (3)].NT).type,(yyvsp[(3) - (3)].NT).type);
err_type_arth((yyval.NT).type);
div_zero((yyvsp[(3) - (3)].NT).res);
(yyval.NT).res=quadARTH("/",(yyvsp[(1) - (3)].NT).res,(yyvsp[(3) - (3)].NT).res);
;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 279 "syntaxique.y"
    {
err_type_arth((yyvsp[(2) - (3)].NT).type);
(yyval.NT).type=(yyvsp[(2) - (3)].NT).type;
(yyval.NT).res=(yyvsp[(2) - (3)].NT).res;
;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 290 "syntaxique.y"
    {

(yyval.NT).type=incomptabiliteType((yyvsp[(3) - (6)].NT).type,(yyvsp[(5) - (6)].NT).type);
err_type_arth((yyval.NT).type);
(yyval.NT).res=quadSUP((yyvsp[(3) - (6)].NT).res,(yyvsp[(5) - (6)].NT).res);
;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 298 "syntaxique.y"
    {
(yyval.NT).type=incomptabiliteType((yyvsp[(3) - (6)].NT).type,(yyvsp[(5) - (6)].NT).type);
err_type_arth((yyval.NT).type);
(yyval.NT).res=quadSUPE((yyvsp[(3) - (6)].NT).res,(yyvsp[(5) - (6)].NT).res);
;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 305 "syntaxique.y"
    {
(yyval.NT).type=incomptabiliteType((yyvsp[(3) - (6)].NT).type,(yyvsp[(5) - (6)].NT).type);
err_type_arth((yyval.NT).type);
(yyval.NT).res=quadINF((yyvsp[(3) - (6)].NT).res,(yyvsp[(5) - (6)].NT).res);
;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 312 "syntaxique.y"
    {
(yyval.NT).type=incomptabiliteType((yyvsp[(3) - (6)].NT).type,(yyvsp[(5) - (6)].NT).type);
err_type_arth((yyval.NT).type);
(yyval.NT).res=quadINFE((yyvsp[(3) - (6)].NT).res,(yyvsp[(5) - (6)].NT).res);
;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 319 "syntaxique.y"
    {
(yyval.NT).type=incomptabiliteType((yyvsp[(3) - (6)].NT).type,(yyvsp[(5) - (6)].NT).type);
(yyval.NT).res=quadEGA((yyvsp[(3) - (6)].NT).res,(yyvsp[(5) - (6)].NT).res);
;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 325 "syntaxique.y"
    {
(yyval.NT).type=incomptabiliteType((yyvsp[(3) - (6)].NT).type,(yyvsp[(5) - (6)].NT).type);
(yyval.NT).res=quadDIF((yyvsp[(3) - (6)].NT).res,(yyvsp[(5) - (6)].NT).res);
;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 334 "syntaxique.y"
    {
incomptabiliteType((yyvsp[(3) - (6)].NT).type,5);
incomptabiliteType(5,(yyvsp[(5) - (6)].NT).type);
(yyval.NT).type=5;
(yyval.NT).res=quadAND((yyvsp[(3) - (6)].NT).res,(yyvsp[(5) - (6)].NT).res);
;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 342 "syntaxique.y"
    {
incomptabiliteType((yyvsp[(3) - (6)].NT).type,5);
incomptabiliteType(5,(yyvsp[(5) - (6)].NT).type);
(yyval.NT).type=5;
(yyval.NT).res=quadOR((yyvsp[(3) - (6)].NT).res,(yyvsp[(5) - (6)].NT).res);
;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 350 "syntaxique.y"
    {
(yyval.NT).type=incomptabiliteType(5,(yyvsp[(3) - (4)].NT).type);
(yyval.NT).res=quadNOT((yyvsp[(3) - (4)].NT).res);
;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 356 "syntaxique.y"
    {
(yyval.NT).type=5;
(yyval.NT).res=(yyvsp[(1) - (1)].NT).res;
;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 364 "syntaxique.y"
    {
(yyval.NT).type=(yyvsp[(1) - (1)].NT).type;
(yyval.NT).res=(yyvsp[(1) - (1)].NT).res;
;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 370 "syntaxique.y"
    {
(yyval.NT).type=5;
(yyval.NT).res=(yyvsp[(1) - (1)].NT).res;
;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 376 "syntaxique.y"
    {
(yyval.NT).type=(yyvsp[(1) - (1)].NT).type;
(yyval.NT).res=(yyvsp[(1) - (1)].NT).res;
                                       
if(dans_boucle==0)
{
(element->nbrUse)++;
} 
else
{  //les var des conditions des boucles sont utilisé plusieurs fois
(element->nbrUse)+=2;
} 

;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 392 "syntaxique.y"
    {
(yyval.NT).type=(yyvsp[(1) - (1)].NT).type;
(yyval.NT).res=(yyvsp[(1) - (1)].NT).res;
;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 400 "syntaxique.y"
    {
incomptabiliteType((yyvsp[(4) - (7)].NT).type,(yyvsp[(6) - (7)].NT).type);
element=get_obj((yyvsp[(4) - (7)].NT).res);//car exp peut avoir var
err_aff_cst(element->classe,element->nbrAff);                                                                
(element->nbrAff)++;
quadAFF((yyvsp[(4) - (7)].NT).res,(yyvsp[(6) - (7)].NT).res);
element=NULL;
x="";
;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 413 "syntaxique.y"
    {
err_aff_cst(element->classe,element->nbrAff);
i=traitement_io((yyvsp[(5) - (6)].nom),(yyvsp[(4) - (6)].NT).type);
quadIN(i,(yyvsp[(4) - (6)].NT).res,(yyvsp[(5) - (6)].nom));
(element->nbrAff)++;
(element->nbrUse)=+2;
element=NULL;
;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 425 "syntaxique.y"
    {
i=traitement_io((yyvsp[(3) - (5)].nom),(yyvsp[(5) - (5)].NT).type);
quadOUT(i,(yyvsp[(3) - (5)].nom),(yyvsp[(5) - (5)].NT).res);
(element->nbrUse)+=2;
element=NULL;
;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 432 "syntaxique.y"
    {
i=traitement_io((yyvsp[(1) - (3)].nom),(yyvsp[(3) - (3)].NT).type);
quadOUT(i,(yyvsp[(1) - (3)].nom),(yyvsp[(3) - (3)].NT).res);
(element->nbrUse)+=2;
element=NULL;
;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 443 "syntaxique.y"
    {
traitement_str((yyvsp[(6) - (7)].nom));
quadOUT(-1,(yyvsp[(6) - (7)].nom),"");
;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 449 "syntaxique.y"
    {
traitement_str((yyvsp[(4) - (5)].nom));
quadOUT(-1,(yyvsp[(4) - (5)].nom),"");
;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 455 "syntaxique.y"
    {
quadOUT(-1,"",(yyvsp[(4) - (5)].NT).res);
(element->nbrUse)+=2;
element=NULL;
;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 464 "syntaxique.y"
    {
dans_boucle=1;
sauvDEB_WHILE();
;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 470 "syntaxique.y"
    {
incomptabiliteType((yyvsp[(4) - (5)].NT).type,5);
quadBR_DEB_WHILE((yyvsp[(4) - (5)].NT).res);
;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 476 "syntaxique.y"
    {
dans_boucle=0;
;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 485 "syntaxique.y"
    {
incomptabiliteType((yyvsp[(1) - (3)].NT).type,1);
incomptabiliteType((yyvsp[(3) - (3)].NT).type,1);
quadAFF((yyvsp[(1) - (3)].NT).res,(yyvsp[(3) - (3)].NT).res);
(yyval.nom)=strdup((yyvsp[(1) - (3)].NT).res);

dans_boucle=1;
(get_obj((yyvsp[(1) - (3)].NT).res)->nbrUse)+=2;//car on est dans une boucle et $1 n'est pas dans une exp
(get_obj((yyvsp[(1) - (3)].NT).res)->nbrAff)++;
;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 497 "syntaxique.y"
    {
                   incomptabiliteType((yyvsp[(5) - (6)].NT).type,1);
                   quadBR_FIN_FOR((yyvsp[(3) - (6)].nom),(yyvsp[(5) - (6)].NT).res); 
               ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 503 "syntaxique.y"
    {
dans_boucle=0;
;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 508 "syntaxique.y"
    {
quadBR_DEB_FOR();
;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 515 "syntaxique.y"
    {
incomptabiliteType((yyvsp[(4) - (5)].NT).type,5);
quadBR_FIN_THEN((yyvsp[(4) - (5)].NT).res);
;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 521 "syntaxique.y"
    {
remplir_FIN_THEN();
quadBR_FIN_IF();
;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 531 "syntaxique.y"
    {
remplir_FIN_IF();
;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 536 "syntaxique.y"
    {
remplir_FIN_IF();
;}
    break;



/* Line 1455 of yacc.c  */
#line 2308 "syntaxique.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 544 "syntaxique.y"

int yyerror(char *msg)
{
    printf("\n%s la ligne %d la colomne %d >>\n",msg,ligne,colomne);
    exit(0);
    return 1;
}
main()
{
    yyin =fopen ("testgeneral.txt" ,"r");
    init();
    initQuad();
    initPile();
    
    yyparse();

    //optimisation();

    generationCode();
    
    afficherTS();
    afficherOpt();
    afficherQUAD();

    fclose(yyin);
}
yywrap()
{
}
