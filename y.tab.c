/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "trabalho.y" /* yacc.c:339  */

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>

/*
 * Programa exemplo de um compilador para o curso de Compiladores-2014-2 - Zimbrão
 * TODO:
 * - variavel do tipo boolean
 * - Funções e parametros
 * - Variaveis locais
 * - Array
 * - pipes
 *
 */

using namespace std;

const int MAX_STR = 256;

struct Tipo {
  string nome;
  int nDim;
  int d1;
  int d2;
  
  Tipo() { nome = ""; nDim = 0; d1 = 0; d2 = 0; }
  Tipo( string nome ) {
    this->nome = nome;
    nDim = 0; 
    d1 = 0; 
    d2 = 0;
  }
};

struct Atributo {
  string v;  // Valor
  Tipo   t;  // tipo
  string c;  // codigo
  
  Atributo() {}  // inicializacao automatica para vazio ""
  Atributo( string v, string t = "", string c = "" ) {
    this->v = v;
    this->t.nome = t;
    this->c = c;
  }
};

typedef map< string, Tipo > TS;
TS ts_local, ts_global,ts_funcoes;
TS* ts = &ts_global; // Tabela de simbolos da vez

string pipeAtivo; // Tipo do pipe ativo
string passoPipeAtivo; // Label 'fim' do pipe ativo
string geraDeclaracaoVarPipe();
string tamanhoPipe;
string indicePipe;


Tipo tipoResultado( Tipo a, string operador, Tipo b );
string geraTemp( Tipo tipo );
string geraLabel( string cmd);
string geraDeclaracaoTemporarias();

void insereVariavelTS( TS&, string nomeVar, Tipo tipo );
bool buscaVariavelTS( TS&, string nomeVar, Tipo* tipo );
void erro( string msg );
string toStr( int n );

void geraDeclaracaoVariavelComAtribuicao( Atributo* SS, const Atributo& tipo,
                                           const Atributo& id, const Atributo& rvalue );
void geraCodigoAtribuicaoSemIndice( Atributo* SS, Atributo& lvalue, const Atributo& rvalue );
void geraCodigoAtribuicao1Indice( Atributo* SS, Atributo& lvalue, Atributo& indice1, const Atributo& rvalue );
void geraCodigoAtribuicao2Indices( Atributo* SS, Atributo& lvalue, Atributo& indice1, Atributo& indice2, const Atributo& rvalue );
void geraCodigoAtribuicao3Indices( Atributo* SS, Atributo& lvalue, Atributo& indice1, Atributo& indice2, Atributo& indice3, const Atributo& rvalue );

void geraCodigoOperadorBinario( Atributo* SS, const Atributo& S1, const Atributo& S2, const Atributo& S3 );
void geraCodigoFuncaoPrincipal( Atributo* SS, const Atributo& cmds );
void geraCodigoIfComElse( Atributo* SS, const Atributo& expr, 
                                        const Atributo& cmdsThen,
                                        const Atributo& cmdsElse );
void geraCodigoIfSemElse( Atributo* SS, const Atributo& expr, 
                                        const Atributo& cmdsThen );
void geraCodigoFor( Atributo* SS, const Atributo& init,
                                  const Atributo& condicao,
                                  const Atributo& passo,
                                  const Atributo& cmds);
void geraCodigoWhile(Atributo* SS, const Atributo& condicao, const Atributo& cmds);
void geraCodigoDoWhile(Atributo* SS, const Atributo& cmds, 
                                     const Atributo& condicao);
void geraDeclaracaoVariavel( Atributo* SS, const Atributo& tipo,
                                           const Atributo& id );
void geraCodigoOperadorUnario( Atributo* SS, const Atributo& S1, const Atributo& S2 );
void geraCodigoCase(Atributo* SS, const Atributo& cases, const Atributo& tcase, const Atributo& cmdsCase);
void geraCodigoSwitch(Atributo* SS, const Atributo& cases, const Atributo& tdefault);
void geraCodigoInput( Atributo* SS, const Atributo& id);
void geraCodigoFuncao(Atributo* SS, const Atributo& cabecalho,
                                    const Atributo& params,
                                    const Atributo& cmds);
void geraCodigoParam(Atributo* SS, const Atributo& tipo,
                                   const Atributo& id);
void geraCodigoReturn(Atributo* SS, const Atributo expr);

void geraCodigoAcessoArray(Atributo* SS, const Atributo& id, 
                                    const Atributo& expr1,
                                    const Atributo& expr2,
                                    const Atributo& expr3,
                                    int dim);

void geraCodigoFilter( Atributo* SS, const Atributo& condicao ) ;
void geraCodigoFirstN( Atributo* SS, const Atributo& n );
void geraCodigoLastN( Atributo* SS, const Atributo& n );

string toStr( int n );
int toInt( string n );

Tipo tipoResultado( string operador, Tipo a );
int nSwitch = 0;
                                           
// Usando const Atributo& não cria cópia desnecessária

#define YYSTYPE Atributo

int yylex();
int yyparse();
void yyerror(const char *);

#line 196 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    _TK_IB = 258,
    _TK_FB = 259,
    _TK_MAIN = 260,
    _TK_VOID = 261,
    _INT = 262,
    _CHAR = 263,
    _DOUBLE = 264,
    _BOOLEAN = 265,
    _FLOAT = 266,
    _STRING = 267,
    _ID = 268,
    _TK_INT = 269,
    _TK_CHAR = 270,
    _TK_BOOLEAN = 271,
    _TK_DOUBLE = 272,
    _TK_FLOAT = 273,
    _TK_STRING = 274,
    _TK_MAIS = 275,
    _TK_MENOS = 276,
    _TK_DIVIDIDO = 277,
    _TK_VEZES = 278,
    _TK_RESTO = 279,
    _TK_AND = 280,
    _TK_OR = 281,
    _TK_NOT = 282,
    _SHIFTL = 283,
    _SHIFTR = 284,
    _TK_MAIOR = 285,
    _TK_MENOR = 286,
    _TK_MENORIGUAL = 287,
    _TK_MAIORIGUAL = 288,
    _TK_IGUAL = 289,
    _TK_DIFERENTE = 290,
    _COUT = 291,
    _SCANF = 292,
    _TK_IF = 293,
    _TK_ELSE = 294,
    _TK_FOR = 295,
    _TK_TQ = 296,
    _TK_DO = 297,
    _TK_WHILE = 298,
    _TK_SWITCH = 299,
    _TK_CASE = 300,
    _TK_BREAK = 301,
    _TK_DEFAULT = 302,
    _TK_RETURN = 303,
    _TK_NULL = 304,
    _PIPE = 305,
    _INTERVALO = 306,
    _FILTER = 307,
    _FOREACH = 308,
    _2PTS = 309,
    _X = 310,
    _FIRSTN = 311,
    _LASTN = 312
  };
#endif
/* Tokens.  */
#define _TK_IB 258
#define _TK_FB 259
#define _TK_MAIN 260
#define _TK_VOID 261
#define _INT 262
#define _CHAR 263
#define _DOUBLE 264
#define _BOOLEAN 265
#define _FLOAT 266
#define _STRING 267
#define _ID 268
#define _TK_INT 269
#define _TK_CHAR 270
#define _TK_BOOLEAN 271
#define _TK_DOUBLE 272
#define _TK_FLOAT 273
#define _TK_STRING 274
#define _TK_MAIS 275
#define _TK_MENOS 276
#define _TK_DIVIDIDO 277
#define _TK_VEZES 278
#define _TK_RESTO 279
#define _TK_AND 280
#define _TK_OR 281
#define _TK_NOT 282
#define _SHIFTL 283
#define _SHIFTR 284
#define _TK_MAIOR 285
#define _TK_MENOR 286
#define _TK_MENORIGUAL 287
#define _TK_MAIORIGUAL 288
#define _TK_IGUAL 289
#define _TK_DIFERENTE 290
#define _COUT 291
#define _SCANF 292
#define _TK_IF 293
#define _TK_ELSE 294
#define _TK_FOR 295
#define _TK_TQ 296
#define _TK_DO 297
#define _TK_WHILE 298
#define _TK_SWITCH 299
#define _TK_CASE 300
#define _TK_BREAK 301
#define _TK_DEFAULT 302
#define _TK_RETURN 303
#define _TK_NULL 304
#define _PIPE 305
#define _INTERVALO 306
#define _FILTER 307
#define _FOREACH 308
#define _2PTS 309
#define _X 310
#define _FIRSTN 311
#define _LASTN 312

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 358 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1006

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  264

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    68,     2,
      61,    62,     2,     2,    63,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,    60,
      58,    67,    59,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,    70,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    69,     2,    71,     2,     2,     2,
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
      55,    56,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   146,   146,   153,   156,   160,   163,   167,   171,   173,
     175,   177,   181,   183,   186,   188,   190,   194,   199,   205,
     209,   211,   213,   216,   218,   220,   222,   224,   226,   228,
     230,   232,   234,   238,   240,   244,   248,   258,   261,   265,
     267,   271,   275,   278,   280,   284,   288,   292,   296,   301,
     305,   308,   311,   330,   350,   358,   372,   374,   378,   380,
     382,   386,   390,   393,   396,   400,   403,   410,   419,   430,
     431,   432,   433,   434,   435,   438,   440,   442,   444,   448,
     450,   452,   454,   456,   458,   460,   462,   464,   466,   468,
     470,   472,   474,   476,   478,   480,   482,   484,   486,   488,
     491,   494,   498,   504,   513,   516,   519,   522,   525,   528,
     531,   532,   538,   542,   546
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_TK_IB", "_TK_FB", "_TK_MAIN",
  "_TK_VOID", "_INT", "_CHAR", "_DOUBLE", "_BOOLEAN", "_FLOAT", "_STRING",
  "_ID", "_TK_INT", "_TK_CHAR", "_TK_BOOLEAN", "_TK_DOUBLE", "_TK_FLOAT",
  "_TK_STRING", "_TK_MAIS", "_TK_MENOS", "_TK_DIVIDIDO", "_TK_VEZES",
  "_TK_RESTO", "_TK_AND", "_TK_OR", "_TK_NOT", "_SHIFTL", "_SHIFTR",
  "_TK_MAIOR", "_TK_MENOR", "_TK_MENORIGUAL", "_TK_MAIORIGUAL",
  "_TK_IGUAL", "_TK_DIFERENTE", "_COUT", "_SCANF", "_TK_IF", "_TK_ELSE",
  "_TK_FOR", "_TK_TQ", "_TK_DO", "_TK_WHILE", "_TK_SWITCH", "_TK_CASE",
  "_TK_BREAK", "_TK_DEFAULT", "_TK_RETURN", "_TK_NULL", "_PIPE",
  "_INTERVALO", "_FILTER", "_FOREACH", "_2PTS", "_X", "_FIRSTN", "_LASTN",
  "'<'", "'>'", "';'", "'('", "')'", "','", "':'", "'['", "']'", "'='",
  "'&'", "'|'", "'^'", "'~'", "$accept", "S1", "DECLS", "VARGLOBAL",
  "PREPARA_GLOBAL", "FUNCTION", "DECLS_FUNCAO", "PREPARA_FUNCAO", "PARAMS",
  "DECL_PARAM", "MAIN", "CMDS", "CMD", "CMD_IF", "CMD_OUT", "COUT_EXPR",
  "CMD_IN", "COD", "BLOCO", "CMD_RETURN", "CMD_FOR", "CMD_WHILE",
  "CMD_DOWHILE", "CMD_SWITCH", "SW", "DEFAULT", "CMD_PIPE", "INI_PIPE",
  "INI_PIPE_ARRAY", "PROCS", "PROC", "CONSOME", "DECLVAR", "TIPO_ARRAY",
  "TIPO", "ATR", "E", "PARAM", "F", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,    60,    62,
      59,    40,    41,    44,    58,    91,    93,    61,    38,   124,
      94,   126
};
# endif

#define YYPACT_NINF -151

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-151)))

#define YYTABLE_NINF -13

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     125,    13,  -151,  -151,  -151,  -151,  -151,  -151,    14,    25,
     125,   125,  -151,   -44,    32,    -8,  -151,  -151,    35,  -151,
    -151,  -151,    -6,  -151,    56,     6,   -46,    70,   955,    18,
    -151,   111,   111,    16,   -21,  -151,    74,    46,    47,   942,
      49,    50,   111,    51,   108,   955,  -151,    54,    55,  -151,
    -151,  -151,  -151,  -151,    57,    75,   -20,    -4,    66,   124,
     -55,  -151,   115,    -2,  -151,  -151,  -151,  -151,  -151,  -151,
     -36,   111,  -151,   111,   111,   881,  -151,   881,    64,   111,
     111,   111,   117,   111,   250,   955,   -21,  -151,    89,  -151,
     111,   111,     5,   211,   111,  -151,  -151,  -151,  -151,   955,
     -34,    80,  -151,    67,  -151,  -151,   124,   177,  -151,  -151,
     111,   111,   881,   227,   881,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   130,   278,   881,   881,  -151,   294,     4,
      85,   143,    87,   345,   361,   111,    86,   145,  -151,   412,
    -151,    88,    90,    92,    75,    93,  -151,  -151,  -151,  -151,
     881,     9,   428,  -151,   895,   895,   907,   907,   881,   881,
     881,   881,   881,   881,   881,   881,   881,   881,   881,   881,
     881,   881,    94,   -11,   942,   139,   139,  -151,   111,   942,
     151,   479,   955,  -151,   111,   111,   111,   111,  -151,   162,
    -151,  -151,   111,   103,  -151,   111,   111,   120,   109,   123,
     495,  -151,   126,   955,  -151,   118,   881,   546,   562,   613,
     119,   881,   111,   629,   881,   942,   148,   160,   149,   111,
    -151,    75,  -151,  -151,  -151,  -151,   680,     1,  -151,   111,
     111,  -151,   696,    80,   121,   111,   111,   747,   763,   955,
    -151,   111,   814,   881,   942,   942,  -151,   830,   136,  -151,
    -151,  -151,   111,   881
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,    69,    70,    71,    72,    73,    74,     0,     0,
       5,     5,    14,     0,     0,     0,    13,     1,     0,     2,
       3,     4,     0,     6,     0,    63,    65,     0,    22,     0,
      62,     0,     0,     0,    55,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    26,     0,     0,    32,
      27,    28,    29,    30,     0,     0,     0,     0,     0,     0,
       0,    16,     0,     0,   104,   107,   105,   108,   106,   109,
     102,     0,   111,     0,     0,    64,    99,    66,    67,     0,
       0,    35,     0,     0,     0,    22,     0,    40,     0,    39,
       0,     0,    51,     0,     0,    19,    20,    24,    25,    22,
      57,     0,    31,    65,    23,     7,     0,     0,    18,    17,
       0,     0,    92,     0,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    36,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    42,     0,
      21,     0,     0,     0,     0,     0,    53,    10,     7,    15,
     101,     0,     0,   110,    79,    80,    82,    81,    83,    84,
      85,    97,    98,    87,    86,    88,    89,    90,    91,    93,
      94,    95,     0,     0,     0,     0,     0,    41,     0,     0,
       0,     0,    22,    47,     0,     0,     0,     0,    56,     0,
       8,   103,     0,   112,    68,     0,     0,    33,     0,     0,
       0,    45,     0,    22,    50,     0,    54,     0,     0,     0,
       0,   100,     0,     0,    76,     0,     0,     0,     0,     0,
      49,     0,    58,    59,    60,    61,     0,     0,    34,     0,
       0,    46,     0,     0,   113,     0,     0,     0,     0,    22,
      52,     0,     0,    77,     0,     0,    48,     0,     0,    43,
      44,   114,     0,    78
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -151,  -151,    65,  -151,    53,  -151,  -151,  -151,  -151,   105,
    -151,   -25,   -38,  -151,  -151,  -151,  -151,  -119,   -53,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -150,
    -151,   -28,    17,    -5,     2,   -81,   -32,  -151,  -151
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    10,   157,    11,    12,    22,    60,    61,
      19,    44,    45,    46,    47,    81,    48,    88,    89,    49,
      50,    51,    52,    53,    92,   147,    54,   215,    55,   101,
     154,   156,    56,    14,    57,    58,    75,   161,    76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      77,    87,    15,   140,   198,    26,   105,   106,   107,   103,
      93,   109,    15,    15,    17,   -12,    23,    13,   151,    24,
      96,    32,   152,   153,    62,   110,    16,    13,    13,   111,
      18,    63,     2,     3,     4,     5,     6,     7,    28,   112,
     102,   113,   114,    24,    79,    25,    80,   134,   135,   136,
     145,   138,   146,   158,   205,    29,   206,    27,   143,   144,
     141,    27,   149,    27,   185,   207,   245,    24,   246,    30,
     211,   201,   202,    31,   150,    20,    21,    33,   160,   162,
      59,   243,    78,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   139,    62,    82,   208,   209,   238,    83,    84,    63,
      90,    91,    95,   191,    97,    98,    94,    99,    64,    65,
      66,    67,    68,    69,    70,   100,   104,    85,   108,   133,
     137,     1,   142,   155,    32,   259,   260,   182,    71,     2,
       3,     4,     5,     6,     7,   186,    87,   187,   188,   193,
     192,    87,    86,   195,   212,   196,   210,   197,   199,   225,
     204,   220,   216,   217,   218,   219,    72,   214,   222,   226,
     221,   229,    73,   223,   224,    86,     2,     3,     4,     5,
       6,     7,    74,   227,   231,   235,   251,    87,   230,   239,
     236,     2,     3,     4,     5,     6,     7,   242,    35,    36,
      37,   240,    38,   262,    39,    40,    41,   247,   248,   241,
      42,   200,   159,   252,   253,   250,    87,    87,     0,   257,
       0,     0,     0,     0,   256,     0,     0,     0,     0,     0,
     263,   115,   116,   117,   118,   119,   120,   121,     0,   122,
     123,   124,   125,   126,   127,   128,   129,   115,   116,   117,
     118,   119,   120,   121,     0,   122,   123,   124,   125,   126,
     127,   128,   129,    86,     2,     3,     4,     5,     6,     7,
       0,   148,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   132,     0,     0,     0,     0,     0,     0,     0,   163,
       0,     0,     0,     0,     0,   130,   131,   132,   115,   116,
     117,   118,   119,   120,   121,     0,   122,   123,   124,   125,
     126,   127,   128,   129,   115,   116,   117,   118,   119,   120,
     121,     0,   122,   123,   124,   125,   126,   127,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   183,     0,   130,   131,   132,     0,
       0,     0,     0,     0,     0,     0,   184,     0,     0,     0,
       0,     0,   130,   131,   132,   115,   116,   117,   118,   119,
     120,   121,     0,   122,   123,   124,   125,   126,   127,   128,
     129,   115,   116,   117,   118,   119,   120,   121,     0,   122,
     123,   124,   125,   126,   127,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   189,     0,     0,
       0,     0,     0,   130,   131,   132,     0,     0,     0,     0,
       0,     0,     0,   190,     0,     0,     0,     0,     0,   130,
     131,   132,   115,   116,   117,   118,   119,   120,   121,     0,
     122,   123,   124,   125,   126,   127,   128,   129,   115,   116,
     117,   118,   119,   120,   121,     0,   122,   123,   124,   125,
     126,   127,   128,   129,     0,     0,   194,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130,   131,   132,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   203,     0,   130,   131,   132,   115,
     116,   117,   118,   119,   120,   121,     0,   122,   123,   124,
     125,   126,   127,   128,   129,   115,   116,   117,   118,   119,
     120,   121,     0,   122,   123,   124,   125,   126,   127,   128,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   213,     0,     0,     0,   130,   131,   132,
       0,     0,     0,     0,     0,     0,     0,   228,     0,     0,
       0,     0,     0,   130,   131,   132,   115,   116,   117,   118,
     119,   120,   121,     0,   122,   123,   124,   125,   126,   127,
     128,   129,   115,   116,   117,   118,   119,   120,   121,     0,
     122,   123,   124,   125,   126,   127,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   232,     0,   130,   131,   132,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,     0,
     130,   131,   132,   115,   116,   117,   118,   119,   120,   121,
       0,   122,   123,   124,   125,   126,   127,   128,   129,   115,
     116,   117,   118,   119,   120,   121,     0,   122,   123,   124,
     125,   126,   127,   128,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
       0,   130,   131,   132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   237,     0,   130,   131,   132,
     115,   116,   117,   118,   119,   120,   121,     0,   122,   123,
     124,   125,   126,   127,   128,   129,   115,   116,   117,   118,
     119,   120,   121,     0,   122,   123,   124,   125,   126,   127,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   244,     0,   130,   131,
     132,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,     0,     0,     0,   130,   131,   132,   115,   116,   117,
     118,   119,   120,   121,     0,   122,   123,   124,   125,   126,
     127,   128,   129,   115,   116,   117,   118,   119,   120,   121,
       0,   122,   123,   124,   125,   126,   127,   128,   129,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
       0,     0,     0,     0,     0,   130,   131,   132,     0,     0,
       0,     0,     0,     0,     0,   255,     0,     0,     0,     0,
       0,   130,   131,   132,   115,   116,   117,   118,   119,   120,
     121,     0,   122,   123,   124,   125,   126,   127,   128,   129,
     115,   116,   117,   118,   119,   120,   121,     0,   122,   123,
     124,   125,   126,   127,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     258,     0,   130,   131,   132,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   261,     0,   130,   131,
     132,   115,   116,   117,   118,   119,   120,   121,     0,   122,
     123,   124,   125,   126,   127,   128,   129,   117,   118,   119,
     120,   121,     0,   122,   123,   124,   125,   126,   127,   128,
     129,   119,   120,   121,     0,   122,   123,   124,   125,   126,
     127,   128,   129,     0,     0,    85,     0,     0,     0,   130,
     131,   132,     0,     0,     0,    86,     2,     3,     4,     5,
       6,     7,     0,   130,   131,   132,     0,     0,    34,     2,
       3,     4,     5,     6,     7,   130,   131,   132,    35,    36,
      37,     0,    38,     0,    39,    40,    41,     0,     0,     0,
      42,    35,    36,    37,     0,    38,     0,    39,    40,    41,
       0,     0,     0,    42,     0,     0,    43
};

static const yytype_int16 yycheck[] =
{
      32,    39,     0,    84,   154,    13,    59,    62,    63,    13,
      42,    13,    10,    11,     0,    61,    60,     0,    52,    63,
      45,    67,    56,    57,    29,    61,    13,    10,    11,    65,
       5,    29,    14,    15,    16,    17,    18,    19,     3,    71,
      60,    73,    74,    63,    65,    13,    67,    79,    80,    81,
      45,    83,    47,   106,    65,    61,    67,    65,    90,    91,
      85,    65,    94,    65,    60,   184,    65,    63,    67,    13,
     189,    62,    63,    67,    99,    10,    11,     7,   110,   111,
      62,   231,    66,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    84,   107,    29,   185,   186,   225,    61,    61,   107,
      61,    61,     4,   145,    60,    60,    65,    60,     7,     8,
       9,    10,    11,    12,    13,    50,    60,     3,    13,    65,
      13,     6,    43,    53,    67,   254,   255,     7,    27,    14,
      15,    16,    17,    18,    19,    60,   184,     4,    61,     4,
      64,   189,    13,    65,     3,    65,   188,    65,    65,    39,
      66,   199,   194,   195,   196,   197,    55,   192,    65,    60,
     202,    45,    61,   205,   206,    13,    14,    15,    16,    17,
      18,    19,    71,    60,    66,    66,    65,   225,   213,    41,
     222,    14,    15,    16,    17,    18,    19,   229,    36,    37,
      38,    41,    40,    67,    42,    43,    44,   239,   240,    60,
      48,   158,   107,   245,   246,   243,   254,   255,    -1,   251,
      -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,
     262,    20,    21,    22,    23,    24,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    20,    21,    22,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    13,    14,    15,    16,    17,    18,    19,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    20,    21,
      22,    23,    24,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    20,    21,    22,    23,    24,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    20,    21,    22,    23,    24,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    20,    21,    22,    23,    24,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    20,    21,
      22,    23,    24,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    68,    69,    70,    20,
      21,    22,    23,    24,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    20,    21,    22,    23,    24,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    20,    21,    22,    23,
      24,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      68,    69,    70,    20,    21,    22,    23,    24,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    20,
      21,    22,    23,    24,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    68,    69,    70,
      20,    21,    22,    23,    24,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    20,    21,    22,    23,
      24,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    -1,    -1,    -1,    68,    69,    70,    20,    21,    22,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    20,    21,    22,    23,    24,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    20,    21,    22,    23,    24,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      20,    21,    22,    23,    24,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,    68,    69,
      70,    20,    21,    22,    23,    24,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    22,    23,    24,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    24,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,     3,    -1,    -1,    -1,    68,
      69,    70,    -1,    -1,    -1,    13,    14,    15,    16,    17,
      18,    19,    -1,    68,    69,    70,    -1,    -1,    13,    14,
      15,    16,    17,    18,    19,    68,    69,    70,    36,    37,
      38,    -1,    40,    -1,    42,    43,    44,    -1,    -1,    -1,
      48,    36,    37,    38,    -1,    40,    -1,    42,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    14,    15,    16,    17,    18,    19,    73,    74,
      75,    77,    78,   104,   105,   106,    13,     0,     5,    82,
      74,    74,    79,    60,    63,    13,    13,    65,     3,    61,
      13,    67,    67,     7,    13,    36,    37,    38,    40,    42,
      43,    44,    48,    51,    83,    84,    85,    86,    88,    91,
      92,    93,    94,    95,    98,   100,   104,   106,   107,    62,
      80,    81,   105,   106,     7,     8,     9,    10,    11,    12,
      13,    27,    55,    61,    71,   108,   110,   108,    66,    65,
      67,    87,    29,    61,    61,     3,    13,    84,    89,    90,
      61,    61,    96,   108,    65,     4,    83,    60,    60,    60,
      50,   101,    60,    13,    60,    90,    62,    63,    13,    13,
      61,    65,   108,   108,   108,    20,    21,    22,    23,    24,
      25,    26,    28,    29,    30,    31,    32,    33,    34,    35,
      68,    69,    70,    65,   108,   108,   108,    13,   108,   104,
     107,    83,    43,   108,   108,    45,    47,    97,    60,   108,
      83,    52,    56,    57,   102,    53,   103,    76,    90,    81,
     108,   109,   108,    62,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,     7,    66,    62,    60,    60,     4,    61,    62,
      62,   108,    64,     4,    54,    65,    65,    65,   101,    65,
      76,    62,    63,    66,    66,    65,    67,    89,   107,   107,
     108,    89,     3,    64,    83,    99,   108,   108,   108,   108,
      84,   108,    65,   108,   108,    39,    60,    60,    62,    45,
      83,    66,    66,    66,    66,    66,   108,    66,    89,    41,
      41,    60,   108,   101,    66,    65,    67,   108,   108,    64,
     103,    65,   108,   108,    62,    62,    83,   108,    66,    89,
      89,    66,    67,   108
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    74,    74,    74,    75,    76,    77,    77,
      77,    77,    78,    78,    79,    80,    80,    81,    81,    82,
      83,    83,    83,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    85,    85,    86,    87,    87,    88,    89,
      89,    90,    91,    92,    92,    93,    94,    95,    96,    96,
      97,    97,    98,    98,    99,   100,   101,   101,   102,   102,
     102,   103,   104,   104,   104,   104,   104,   105,   105,   106,
     106,   106,   106,   106,   106,   107,   107,   107,   107,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     109,   109,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     2,     0,     7,     7,
       6,     6,     2,     2,     0,     3,     1,     2,     2,     4,
       2,     3,     0,     2,     2,     2,     1,     1,     1,     1,
       1,     2,     1,     5,     7,     2,     2,     0,     3,     1,
       1,     3,     3,    10,    10,     5,     7,     4,     8,     5,
       3,     0,     8,     3,     1,     1,     3,     1,     4,     4,
       4,     4,     3,     2,     4,     2,     4,     4,     7,     1,
       1,     1,     1,     1,     1,     3,     6,     9,    12,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     2,     3,     3,     1,
       3,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       3,     1,     4,     7,    10
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 147 "trabalho.y" /* yacc.c:1646  */
    { cout << "#include <stdio.h>\n"
               "#include <stdlib.h>\n"
               "#include <string.h>\n\n"
            << (yyvsp[-1]).c << (yyvsp[0]).c << endl; }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 154 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Atributo();
          (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c; }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 157 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Atributo();
          (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c; }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 160 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Atributo(); }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 164 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]);}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 167 "trabalho.y" /* yacc.c:1646  */
    { ts = &ts_global;}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 172 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoFuncao(&(yyval), (yyvsp[-6]), (yyvsp[-3]), (yyvsp[-1]));  }
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 174 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoFuncao(&(yyval), (yyvsp[-6]), (yyvsp[-3]), (yyvsp[-1]));}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 176 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoFuncao(&(yyval), (yyvsp[-5]), Atributo(), (yyvsp[-1]));}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 178 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoFuncao(&(yyval), (yyvsp[-5]), Atributo(), (yyvsp[-1]));}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 182 "trabalho.y" /* yacc.c:1646  */
    { insereVariavelTS(ts_funcoes, (yyvsp[0]).v, (yyvsp[-1]).t); (yyval).v = (yyvsp[-1]).t.nome + " " + (yyvsp[0]).v; }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 184 "trabalho.y" /* yacc.c:1646  */
    { insereVariavelTS(ts_funcoes, (yyvsp[0]).v, (yyvsp[-1]).t); (yyval).v = (yyvsp[-1]).t.nome + " " + (yyvsp[0]).v; }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 186 "trabalho.y" /* yacc.c:1646  */
    { ts = &ts_local;}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 189 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + ',' + ' ' + (yyvsp[0]).c; }
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 191 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 195 "trabalho.y" /* yacc.c:1646  */
    {
        insereVariavelTS( *ts, (yyvsp[0]).v, (yyvsp[-1]).t );
        geraCodigoParam(&(yyval), (yyvsp[-1]), (yyvsp[0]));
      }
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 200 "trabalho.y" /* yacc.c:1646  */
    {
        insereVariavelTS( *ts, (yyvsp[0]).v, (yyvsp[-1]).t );
        geraCodigoParam(&(yyval), (yyvsp[-1]), (yyvsp[0]));
      }
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 206 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoFuncaoPrincipal( &(yyval), (yyvsp[-1]) ); }
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 210 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c; }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 211 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c; }
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 213 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Atributo(); }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 217 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c;  }
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 219 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c; }
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 221 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c; }
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 223 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c; }
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 225 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c; }
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 227 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c; }
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 229 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c; }
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 231 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c; }
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 233 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c; }
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 235 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c; }
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 239 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoIfSemElse( &(yyval), (yyvsp[-2]), (yyvsp[0]) );}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 241 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoIfComElse( &(yyval), (yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]) ); }
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 245 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 249 "trabalho.y" /* yacc.c:1646  */
    { if( (yyvsp[0]).t.nome == "int" )
                (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c + 
                       "  printf( \"%d\" , " + (yyvsp[0]).v + " );\n";
              else if( (yyvsp[0]).t.nome == "string" )
                (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c + 
                       "  printf( \"%s\" , " + (yyvsp[0]).v + " );\n";
              else if( (yyvsp[0]).t.nome == "double")
                (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c +
                      "  printf( \"%f\" , " + (yyvsp[0]).v + " );\n";}
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 258 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Atributo(); }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 262 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoInput(&(yyval), (yyvsp[0])); }
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 266 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c;}
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 268 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c;}
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 272 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c;}
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 276 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoReturn(&(yyval), (yyvsp[-1])); }
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 279 "trabalho.y" /* yacc.c:1646  */
    {geraCodigoFor(&(yyval), (yyvsp[-7]), (yyvsp[-2]), (yyvsp[-5]), (yyvsp[0]));}
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 281 "trabalho.y" /* yacc.c:1646  */
    {geraCodigoFor(&(yyval), (yyvsp[-7]), (yyvsp[-2]), (yyvsp[-5]), (yyvsp[0]));}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 285 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoWhile( &(yyval), (yyvsp[-2]), (yyvsp[0])); }
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 289 "trabalho.y" /* yacc.c:1646  */
    {geraCodigoDoWhile(&(yyval), (yyvsp[-5]), (yyvsp[-2])) ;}
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 293 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoSwitch(&(yyval), (yyvsp[-2]), (yyvsp[-1])); }
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 297 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-6]).c;
        (yyval).v = (yyvsp[-6]).v;
        nSwitch++;
        geraCodigoCase(&(yyval), Atributo(), (yyvsp[-2]), (yyvsp[0])); }
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 302 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoCase(&(yyval), (yyvsp[-4]), (yyvsp[-2]), (yyvsp[0])); }
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 306 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c; }
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 308 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = ""; }
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 312 "trabalho.y" /* yacc.c:1646  */
    { 
            Atributo inicio, condicao, passo, cmd;
            
            
            inicio.c = (yyvsp[-5]).c + (yyvsp[-3]).c +
                       "  x_" + pipeAtivo + " = " + (yyvsp[-5]).v + ";\n";
            condicao.t.nome = "boolean";
            condicao.v = geraTemp( Tipo( "boolean" ) ); 
            condicao.c = "  " + condicao.v + " = " + "x_" + pipeAtivo + 
                         " <= " + (yyvsp[-3]).v + ";\n";
            passo.c = passoPipeAtivo + ":\n" + 
                      "  x_" + pipeAtivo + " = x_" + pipeAtivo + " + 1;\n";
            cmd.c = (yyvsp[-1]).c + (yyvsp[0]).c;
            
            geraCodigoFor( &(yyval), inicio, condicao, passo, cmd );
            
            pipeAtivo = ""; }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 330 "trabalho.y" /* yacc.c:1646  */
    {
              Atributo inicio, condicao, passo, cmd;
            
              inicio.c = indicePipe + " = 0;\n" +
                          "x_"+pipeAtivo+" = "+(yyvsp[-2]).v+"["+indicePipe+"];"; 
              condicao.t.nome = "boolean";
              condicao.v = geraTemp( Tipo( "boolean" ) ); 
              condicao.c = "  " + condicao.v + " = " + indicePipe + 
                           " < " + tamanhoPipe + ";\n";
              passo.c = passoPipeAtivo + ":\n" + 
                        indicePipe+ " = " + indicePipe + " + 1;\n"+
                        "x_"+pipeAtivo+" = "+(yyvsp[-2]).v+"["+indicePipe+"];"; 
              cmd.c = (yyvsp[-1]).c + (yyvsp[0]).c;
              
              geraCodigoFor( &(yyval), inicio, condicao, passo, cmd );
              
              pipeAtivo = "";
          }
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 351 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);
            indicePipe = "x_"+pipeAtivo;
             tamanhoPipe = (yyvsp[0]).v;
             pipeAtivo =  (yyvsp[0]).t.nome;
       passoPipeAtivo = geraLabel( "passo_pipe" ); }
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 359 "trabalho.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
            if( buscaVariavelTS( *ts, (yyvsp[0]).v, &(yyval).t ) ){
              pipeAtivo = (yyval).t.nome;
              tamanhoPipe = toStr((yyval).t.d1);
              string counter = geraTemp(Tipo("int"));
              indicePipe = counter;
              passoPipeAtivo = geraLabel( "passo_pipe" );
            }
            else
              erro("Array nao declarado."); 
        }
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 373 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c; }
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 375 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Atributo(); }
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 379 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoFilter( &(yyval), (yyvsp[-1]) ); }
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 381 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoFirstN( &(yyval), (yyvsp[-1]) ); }
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 383 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoLastN( &(yyval), (yyvsp[-1]) ); }
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 387 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c; }
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 391 "trabalho.y" /* yacc.c:1646  */
    { insereVariavelTS( *ts, (yyvsp[0]).v, (yyvsp[-2]).t ); 
            geraDeclaracaoVariavel( &(yyval), (yyvsp[-2]), (yyvsp[0]) ); }
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 394 "trabalho.y" /* yacc.c:1646  */
    { insereVariavelTS( *ts, (yyvsp[0]).v, (yyvsp[-1]).t ); 
            geraDeclaracaoVariavel( &(yyval), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 397 "trabalho.y" /* yacc.c:1646  */
    { insereVariavelTS( *ts, (yyvsp[-2]).v, (yyvsp[-3]).t ); 
            geraDeclaracaoVariavelComAtribuicao( &(yyval), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[0]) );
          }
#line 2215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 401 "trabalho.y" /* yacc.c:1646  */
    { insereVariavelTS( *ts, (yyvsp[0]).v, (yyvsp[-1]).t ); 
            geraDeclaracaoVariavel( &(yyval), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 404 "trabalho.y" /* yacc.c:1646  */
    { insereVariavelTS( *ts, (yyvsp[-2]).v, (yyvsp[-3]).t ); 
            geraDeclaracaoVariavelComAtribuicao( &(yyval), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[0]) );
          }
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 411 "trabalho.y" /* yacc.c:1646  */
    { 
         (yyval) = (yyvsp[-3]);
         (yyval).t.nDim = 1;
         (yyval).t.d1 = toInt( (yyvsp[-1]).v ); 
         // cout<< $$.t.d1 << endl;
         // cout<<"array unidimensional"<<$3.v<<endl; //DEPURANDO O TO INT
         // cout<<"array unidimensional toint"<<toInt($3.v)<<endl; //DEPURANDO O TO INT
         }
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 420 "trabalho.y" /* yacc.c:1646  */
    { 
         (yyval) = (yyvsp[-6]);
         (yyval).t.nDim = 2;
         (yyval).t.d1 = toInt( (yyvsp[-4]).v ); 
         (yyval).t.d2 = toInt( (yyvsp[-1]).v ); 
     	 // cout << "array bidimensional" << $3.v << " - " << $6.v <<endl; // DEPURANDO O TOINT
      	 // cout << "array bidimensional toint "<< toInt($3.v) << " - "<<toInt($6.v)<<endl; // DEPURANDO O TOINT
         }
#line 2256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 439 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoAtribuicaoSemIndice( &(yyval), (yyvsp[-2]), (yyvsp[0]) ); }
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 441 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoAtribuicao1Indice( &(yyval), (yyvsp[-5]), (yyvsp[-3]), (yyvsp[0]) ); }
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 443 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoAtribuicao2Indices( &(yyval), (yyvsp[-8]), (yyvsp[-6]), (yyvsp[-3]), (yyvsp[0]) );}
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 445 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoAtribuicao3Indices( &(yyval), (yyvsp[-11]), (yyvsp[-9]), (yyvsp[-6]), (yyvsp[-3]), (yyvsp[0]) ); }
#line 2280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 449 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 451 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 453 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 455 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 457 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 459 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 461 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 463 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 465 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 467 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 469 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 471 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 473 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 475 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorUnario( &(yyval), (yyvsp[-1]), (yyvsp[0])); }
#line 2364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 477 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 479 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 481 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 483 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorUnario( &(yyval), (yyvsp[-1]), (yyvsp[0])); }
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 485 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 487 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 492 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c;
          (yyval).v = (yyvsp[-2]).v + ',' + (yyvsp[0]).v; }
#line 2407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 495 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 499 "trabalho.y" /* yacc.c:1646  */
    { if( buscaVariavelTS( *ts, (yyvsp[0]).v, &(yyval).t ) ) 
      (yyval).v = (yyvsp[0]).v; 
    else
      erro( "Variavel nao declarada: " + (yyvsp[0]).v );
  }
#line 2423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 505 "trabalho.y" /* yacc.c:1646  */
    {
    if( buscaVariavelTS( ts_funcoes, (yyvsp[-3]).v, &(yyval).t ) ){
      (yyval).c = (yyvsp[-1]).c;
      (yyval).v = (yyvsp[-3]).v + '(' + (yyvsp[-1]).v + ')';
    }else{ 
      erro( "Funcao nao declarada: "+ (yyvsp[-3]).v);
    }
  }
#line 2436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 514 "trabalho.y" /* yacc.c:1646  */
    {  (yyval).v = (yyvsp[0]).v; 
       (yyval).t = Tipo( "int" ); }
#line 2443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 517 "trabalho.y" /* yacc.c:1646  */
    {  (yyval).v = (yyvsp[0]).v; 
       (yyval).t = Tipo( "double" ); }
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 520 "trabalho.y" /* yacc.c:1646  */
    {  (yyval).v = (yyvsp[0]).v; 
       (yyval).t = Tipo( "float" ); }
#line 2457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 523 "trabalho.y" /* yacc.c:1646  */
    {  (yyval).v = (yyvsp[0]).v; 
       (yyval).t = Tipo( "char" ); }
#line 2464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 526 "trabalho.y" /* yacc.c:1646  */
    {  (yyval).v = (yyvsp[0]).v; 
       (yyval).t = Tipo( "boolean" ); }
#line 2471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 529 "trabalho.y" /* yacc.c:1646  */
    {  (yyval).v = (yyvsp[0]).v; 
       (yyval).t = Tipo( "string" ); }
#line 2478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 531 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 533 "trabalho.y" /* yacc.c:1646  */
    { if( pipeAtivo != "" )
        (yyval) = Atributo( "x_" + pipeAtivo, pipeAtivo ); 
      else
        erro( "Variavel 'x' so pode ser usada dentro de pipe" );
    }
#line 2494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 539 "trabalho.y" /* yacc.c:1646  */
    {
    geraCodigoAcessoArray(&(yyval), (yyvsp[-3]), (yyvsp[-1]), Atributo(), Atributo(), 1);
  }
#line 2502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 543 "trabalho.y" /* yacc.c:1646  */
    {
    geraCodigoAcessoArray(&(yyval), (yyvsp[-6]), (yyvsp[-4]), (yyvsp[-1]), Atributo(), 2);
  }
#line 2510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 547 "trabalho.y" /* yacc.c:1646  */
    {
    geraCodigoAcessoArray(&(yyval), (yyvsp[-9]), (yyvsp[-7]), (yyvsp[-4]), (yyvsp[-1]), 3);
  }
#line 2518 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2522 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 553 "trabalho.y" /* yacc.c:1906  */


int nlinha = 1;
map<string,int> n_var_temp;
map<string,Tipo> resultadoOperador;
map<string, int> label;

string geraLabel(string cmd){
  return "l_"+cmd+"_"+toStr( ++label[cmd] );
}

void geraCodigoAcessoArray(Atributo* SS, const Atributo& id, 
                                    const Atributo& expr1,
                                    const Atributo& expr2,
                                    const Atributo& expr3,
                                    int dim){
  Tipo t;
  if(buscaVariavelTS(*ts, id.v, &t)){

  switch(dim){
    case 1:
        SS->c = expr1.c;
        SS->v = "  " + id.v + "[" + expr1.v + "]";
    break;

    case 2: 
        string temp1 = geraTemp(Tipo("int"));
        string temp2 = geraTemp(Tipo("int"));

        SS->c = expr1.c + expr2.c +
                temp1 + " = " + expr1.v + "*" + toStr(t.d1) +";\n" +
                temp2 + " = " + temp1 + " + "+expr2.v+";\n";
                // "printf(\"%d \\n \", "+temp2+ ");\n";

        SS->v = id.v + "[" + temp2 + "]";
        SS->t = t;

    break;
  }

  }else{
    erro("Array nao declarado");
  }

}

void geraCodigoAtribuicaoSemIndice( Atributo* SS, Atributo& lvalue, 
                                         const Atributo& rvalue ) {
  if( !buscaVariavelTS( *ts, lvalue.v, &lvalue.t ) ) 
    erro( "Variavel nao declarada: " + lvalue.v );
  else if( lvalue.t.nome != rvalue.t.nome )
    erro( "Expressao " + rvalue.t.nome + 
            " nao pode ser atribuida a variavel " + lvalue.t.nome );
  else if( lvalue.t.nDim != 0 || rvalue.t.nDim != 0 )
    erro( "Atribuicao de array nao e permitida: " + lvalue.v + " = " + rvalue.v );
  else if( lvalue.t.nome == "string" ) {
        SS->c = lvalue.c + rvalue.c + 
                "  strncpy( " + lvalue.v + ", " + rvalue.v + ", " + 
                            toStr( MAX_STR - 1 ) + " );\n" +
                "  " + lvalue.v + "[" + toStr( MAX_STR - 1 ) + "] = 0;\n";
      }
      else
        SS->c = lvalue.c + rvalue.c + 
                "  " + lvalue.v + " = " + rvalue.v + ";\n"; 
}      
       
void geraCodigoAtribuicao1Indice( Atributo* SS, Atributo& lvalue, 
                                                Atributo& indice1, 
                                                const Atributo& rvalue ) {
  SS->c = indice1.c + rvalue.c +
          "  " + lvalue.v + "[" + indice1.v + "] = " + rvalue.v + ";\n";
}
void geraCodigoAtribuicao2Indices( Atributo* SS, Atributo& lvalue, 
                                                 Atributo& indice1, 
                                                 Atributo& indice2, 
                                                 const Atributo& rvalue ){
  if(buscaVariavelTS(*ts, lvalue.v, &lvalue.t)){

  string temp1 = geraTemp(Tipo("int"));
  string temp2 = geraTemp(Tipo("int"));

  SS->c = indice1.c + indice2.c + rvalue.c +
          temp1 + " = " + indice1.v + "*" + toStr(lvalue.t.d2) +";\n" +
          temp2 + " = " + temp1 + " + "+indice2.v+";\n"+
          // "printf(\" Indice: %d \\n \", "+temp2+ ");\n"+
          "  " + lvalue.v + "[" + temp2 + "] = " + rvalue.v + ";\n";
        }else{
          erro("Array nao declarado");
        }

}
void geraCodigoAtribuicao3Indices( Atributo* SS, Atributo& lvalue, 
                                                 Atributo& indice1, 
                                                 Atributo& indice2, 
                                                 Atributo& indice3, 
                                                 const Atributo& rvalue ){
}

void geraCodigoInput( Atributo* SS, const Atributo& id){
  if(buscaVariavelTS(*ts, id.v, (Tipo*) &id.t)){
     if( id.t.nome == "int" )
        SS->c = id.c + "  scanf( \"%d\" , &" + id.v + " );\n";
      else if( id.t.nome == "string" )
        SS->c = id.c + "  scanf( \"%s\" , &" + id.v + " );\n";
      else if( id.t.nome == "double")
        SS->c = id.c +"  scanf( \"%f\" , &" + id.v + " );\n";
  }
  else
    erro( "Variável nao declarada: " + id.v);
}    

void geraCodigoReturn(Atributo* SS, const Atributo expr){
  *SS = Atributo();

  SS->c = expr.c + "\n" +
          "return " + expr.v + ";\n" ;
}

void geraCodigoParam(Atributo* SS, const Atributo& tipo,
                                   const Atributo& id){
  *SS = Atributo();

  SS->v = "";
  SS->t = tipo.t;
  if( tipo.t.nome == "string" ) {
    SS->c = tipo.c + 
           "char " + id.v + "["+ toStr( MAX_STR ) +"]";   
  }
  else {
    if(tipo.t.nome == "boolean"){
      SS->c = "int " + id.v; 
    }
    else
      SS->c = tipo.c + 
            tipo.t.nome + " " + id.v;
  }
}

void geraCodigoFuncao(Atributo* SS, const Atributo& cabecalho,
                                    const Atributo& params,
                                    const Atributo& cmds){
  *SS = Atributo();

  SS->c = cabecalho.v + "( "+params.c+ " ) {\n" +
           geraDeclaracaoTemporarias() + 
           "\n" +
           cmds.c +  
           "}\n";
}
       
void geraCodigoIfComElse( Atributo* SS, const Atributo& expr, 
                                        const Atributo& cmdsThen,
                                        const Atributo& cmdsElse ) {
  *SS = Atributo();
  string l_if_true = geraLabel( "if_true");
  string l_if_false = geraLabel( "if_false");
  string l_if_fim = geraLabel( "if_fim");

  SS->c = expr.c + 
          "  if( " + expr.v + " ) goto "+ l_if_true + ";\n" +
          "  goto "+ l_if_false +";\n" +
          "  "+l_if_true+":\n" + cmdsThen.c +
          "  goto "+l_if_fim+";\n" +
          "  "+ l_if_false +":\n" + cmdsElse.c +
          "  "+l_if_fim+":;\n";
}

void geraCodigoIfSemElse( Atributo* SS, const Atributo& expr, 
                                        const Atributo& cmdsThen ) {
  *SS = Atributo();
  string l_if_fim = geraLabel( "if_fim");

  SS->c = expr.c + 
          "  if( !" + expr.v + " ) goto " + l_if_fim + ";\n" +
          cmdsThen.c +
          "  " + l_if_fim + ":;\n";
}

void geraCodigoFor( Atributo* SS, const Atributo& init,
                                  const Atributo& condicao,
                                  const Atributo& passo,
                                  const Atributo& cmds){

  if(condicao.t.nome != "boolean")
    erro( "A condicao de teste deve ser Buliano: " + condicao.t.nome);

  *SS = Atributo();
  string  forFim = geraLabel("for_fim"),
          forCond = geraLabel("for_cond");
  string valorCond = geraTemp(Tipo("boolean"));

  SS->c = init.c +
          forCond+": \n" +
          condicao.c +
          valorCond + " = !" + condicao.v + ";\n"+
          " if( " + valorCond + " ) goto "+forFim+";\n"+
          cmds.c + "\n" + passo.c +
          " goto "+forCond+";" +
          " "+forFim+":;\n";
}

void geraCodigoWhile(Atributo* SS, const Atributo& condicao,
                                    const Atributo& cmds){

  if(condicao.t.nome != "boolean")
    erro( "A condicao de teste deve ser Buliano: " + condicao.t.nome);
    
 *SS = Atributo();
 string inicioWhile = geraLabel("while_inicio"),
       fimWhile = geraLabel("while_fim");
 string valorCond = geraTemp(Tipo("boolean"));

 SS->c = inicioWhile+": ;\n" +
        condicao.c + 
        valorCond + " = !" + condicao.v + ";\n"+
        "if( "+ valorCond+" ) goto "+fimWhile+";\n"+
        cmds.c +
        " goto "+inicioWhile+"; \n"+
        " "+fimWhile+": ;\n";
}

void geraCodigoDoWhile(Atributo* SS, const Atributo& cmds, 
                                     const Atributo& condicao){
  if(condicao.t.nome != "boolean")
    erro( "A condicao de teste deve ser Buliano: " + condicao.t.nome);
    
  *SS = Atributo();
  string inicioDoWhile = geraLabel("dowhile_inicio");
  string valorCond = geraTemp(Tipo("boolean"));
  
  SS->c = inicioDoWhile + ": \n"+
  cmds.c + "\n" +
  condicao.c + "\n" +
  valorCond + "= "+condicao.v + ";\n"+
  "if( "+valorCond+" ) goto " +inicioDoWhile+";\n";
}

void geraCodigoCase(Atributo* SS, const Atributo& cases, const Atributo& tcase, const Atributo& cmdsCase){

  string l_if_fim = geraLabel("if_fim");
  string l_switch_fim = "l_switch_fim_" + nSwitch;

  SS->c = cases.c + tcase.c +
          "  if( " + SS->v + " != " + tcase.v + " ) goto " + l_if_fim + ";\n" +
          cmdsCase.c +
          "goto " + l_switch_fim + ";\n" +
          "  " + l_if_fim + ":;\n";
}

void geraCodigoSwitch(Atributo* SS, const Atributo& cases, const Atributo& tdefault){
  *SS = Atributo();
  string l_switch_fim = "l_switch_fim_" + nSwitch;

  SS->c = cases.c + 
          tdefault.c +
          "  " + l_switch_fim + ":;\n";

  nSwitch--;      
}

void geraDeclaracaoVariavel( Atributo* SS, const Atributo& tipo,
                                           const Atributo& id ) {
  SS->v = "";
  SS->t = tipo.t;
 
  switch( tipo.t.nDim ) {
    case 0: 
      if(tipo.t.nome == "boolean")
      	SS->c = "int " + id.v + ";\n"; 
      else if( tipo.t.nome == "string" )
        SS->c = tipo.c + "char " + id.v + "["+ toStr( MAX_STR ) +"];\n";  
      else 
      	SS->c = tipo.c + tipo.t.nome + " " + id.v + ";\n"; 
      break;
   case 1:
     SS->c = tipo.c + tipo.t.nome + " " + id.v + "[" + toStr( tipo.t.d1 ) + "];\n";
     break;
   case 2:
     int tam = tipo.t.d1 * tipo.t.d2;
     SS->c = tipo.c + tipo.t.nome + " " + id.v + "[" + toStr(tam) + "];\n";
     break;
  }   
}


void geraDeclaracaoVariavelComAtribuicao( Atributo* SS, const Atributo& tipo,
                                           const Atributo& id, const Atributo& rvalue ) {
  SS->v = "";
  SS->t = tipo.t;
  if( tipo.t.nome == "string" ) {
    SS->c = tipo.c + 
           "char " + id.v + "["+ toStr( MAX_STR ) +"];\n";   
  }
  else {
    if(tipo.t.nome == "boolean"){
      SS->c = "int " + id.v + ";\n"; 
    }
    else
      SS->c = tipo.c + 
            tipo.t.nome + " " + id.v + ";\n";
  }

  if( tipo.t.nome == rvalue.t.nome ) {
    if( tipo.t.nome == "string" ) {
      SS->c += SS->c + rvalue.c + 
              "  strncpy( " + SS->v + ", " + rvalue.v + ", " + 
                          toStr( MAX_STR - 1 ) + " );\n" +
              "  " + SS->v + "[" + toStr( MAX_STR - 1 ) + "] = 0;\n";
    }
    else
      SS->c += rvalue.c + 
              "  " + id.v + " = " + rvalue.v + ";\n"; 
  }
  else
    erro( "Expressao " + rvalue.t.nome + 
          " nao pode ser atribuida a variavel " +
          SS->t.nome );
}

void geraCodigoFuncaoPrincipal( Atributo* SS, const Atributo& cmds ) {
  *SS = Atributo();
  SS->c = "\nint main() {\n" +
           geraDeclaracaoVarPipe() + 
           geraDeclaracaoTemporarias() + 
           "\n" +
           cmds.c + 
           "  return 0;\n"    
           "}\n";
}  

string geraDeclaracaoTemporarias() {
  string c;
  
  for( int i = 0; i < n_var_temp["boolean"]; i++ )
    c += "  int temp_boolean_" + toStr( i + 1 ) + ";\n";
    
  for( int i = 0; i < n_var_temp["int"]; i++ )
    c += "  int temp_int_" + toStr( i + 1 ) + ";\n";

    for( int i = 0; i < n_var_temp["char"]; i++ )
    c += "  char temp_char_" + toStr( i + 1 ) + ";\n";
    
  for( int i = 0; i < n_var_temp["double"]; i++ )
    c += "  double temp_double_" + toStr( i + 1 ) + ";\n";

    for( int i = 0; i < n_var_temp["float"]; i++ )
    c += "  float temp_float_" + toStr( i + 1 ) + ";\n";
    
  for( int i = 0; i < n_var_temp["string"]; i++ )
    c += "  char temp_string_" + toStr( i + 1 ) + "[" + toStr( MAX_STR )+ "];\n";
  
  return c;  
}

void geraCodigoOperadorUnario( Atributo* SS, const Atributo& S1, const Atributo& S2 ) {
  SS->t = tipoResultado( S1.v, S2.t );
  SS->v = geraTemp( SS->t );

  SS->c = S1.c + S2.c + 
          "  " + SS->v + " = " + S1.v + " " + S2.v + ";\n";
}

void geraCodigoOperadorBinario( Atributo* SS, const Atributo& S1, const Atributo& S2, const Atributo& S3 ) {
  SS->t = tipoResultado( S1.t, S2.v, S3.t );
  SS->v = geraTemp( SS->t );

  if( SS->t.nome == "string" ) {
    SS->c = S1.c + S3.c + 
            "\n  strncpy( " + SS->v + ", " + S1.v + ", " + 
                        toStr( MAX_STR - 1 ) + " );\n" +
            "  strncat( " + SS->v + ", " + S3.v + ", " + 
                        toStr( MAX_STR - 1 ) + " );\n" +
            "  " + SS->v + "[" + toStr( MAX_STR - 1 ) + "] = 0;\n\n";    
  }
  else
    SS->c = S1.c + S3.c + 
            "  " + SS->v + " = " + S1.v + " " + S2.v + " " + S3.v + ";\n";
}

void inicializaResultadoOperador() {
  //op basicas: inteiro e inteiro
  resultadoOperador["int+int"] = Tipo( "int" );
  resultadoOperador["int-int"] = Tipo( "int" );
  resultadoOperador["int*int"] = Tipo( "int" );
  resultadoOperador["int/int"] = Tipo( "int" );
  
  //op basicas: double e double
  resultadoOperador["double+double"] = Tipo("double");
  resultadoOperador["double-double"] = Tipo("double");
  resultadoOperador["double*double"] = Tipo("double");
  resultadoOperador["double/double"] = Tipo("double");
  
  //op basicas: float e float
  resultadoOperador["float+float"] = Tipo("float");
  resultadoOperador["float-float"] = Tipo("float");
  resultadoOperador["float*float"] = Tipo("float");
  resultadoOperador["float/float"] = Tipo("float");
  
  //op basicas: inteiro e double
  resultadoOperador["int+double"] = Tipo("double");
  resultadoOperador["int-double"] = Tipo("double");
  resultadoOperador["int*double"] = Tipo("double");
  resultadoOperador["int/double"] = Tipo("double");

  //op basicas: inteiro e float
  resultadoOperador["int+float"] = Tipo("float");
  resultadoOperador["int-float"] = Tipo("float");
  resultadoOperador["int*float"] = Tipo("float");
  resultadoOperador["int/float"] = Tipo("float");
  
  //op basicas: double e float
  resultadoOperador["double+float"] = Tipo("double");
  resultadoOperador["double-float"] = Tipo("double");
  resultadoOperador["double*float"] = Tipo("double");
  resultadoOperador["double/float"] = Tipo("double");
  
  // comparações : inteiro e inteiro
  resultadoOperador["int<int"] = Tipo( "boolean" );
  resultadoOperador["int<=int"] = Tipo( "boolean" );
  resultadoOperador["int>int"] = Tipo( "boolean" );
  resultadoOperador["int>=int"] = Tipo( "boolean" );
  resultadoOperador["int==int"] = Tipo( "boolean" );
  resultadoOperador["int!=int"] = Tipo( "boolean" );
  
  //comparações: double e double
  resultadoOperador["double<double"] = Tipo( "Buluano" );
  resultadoOperador["double<=double"] = Tipo( "boolean" );
  resultadoOperador["double>double"] = Tipo( "boolean" );
  resultadoOperador["double>=double"] = Tipo( "boolean" );
  resultadoOperador["double==double"] = Tipo( "boolean" );
  resultadoOperador["double!=double"] = Tipo( "boolean" );
  
  //comparações float e float
  resultadoOperador["float<float"] = Tipo( "boolean" );
  resultadoOperador["float<=float"] = Tipo( "boolean" );
  resultadoOperador["float>float"] = Tipo( "boolean" );
  resultadoOperador["float>=float"] = Tipo( "boolean" );
  resultadoOperador["float==float"] = Tipo( "boolean" );
  resultadoOperador["float!=float"] = Tipo( "boolean" );
  
  //comparações : inteiro e double
  resultadoOperador["int<double"] = Tipo( "boolean" );
  resultadoOperador["int<=double"] = Tipo( "boolean" );
  resultadoOperador["int>double"] = Tipo( "boolean" );
  resultadoOperador["int>=double"] = Tipo( "boolean" );
  resultadoOperador["int==double"] = Tipo( "boolean" );
  resultadoOperador["int!=double"] = Tipo( "boolean" );
  
  //comparações : inteiro e float
  resultadoOperador["int<float"] = Tipo( "boolean" );
  resultadoOperador["int<=float"] = Tipo( "boolean" );
  resultadoOperador["int>float"] = Tipo( "boolean" );
  resultadoOperador["int>=float"] = Tipo( "boolean" );
  resultadoOperador["int==float"] = Tipo( "boolean" );
  resultadoOperador["int!=float"] = Tipo( "boolean" );
 
  //comparações : double e float
  resultadoOperador["double<float"] = Tipo( "boolean" );
  resultadoOperador["double<=float"] = Tipo( "boolean" );
  resultadoOperador["double>float"] = Tipo( "boolean" );
  resultadoOperador["double>=float"] = Tipo( "boolean" );
  resultadoOperador["double==float"] = Tipo( "boolean" );
  resultadoOperador["double!=float"] = Tipo( "boolean" );
  
  //concatenação
  resultadoOperador["string+string"] = Tipo( "string" );
  resultadoOperador["string+int"] = Tipo("string");

  //resto : inteiro e inteiro
  resultadoOperador["int%int"] = Tipo("int");
  
  //operadores lógicos : bool e bool
  resultadoOperador["boolean&&boolean"] = Tipo("boolean");
  resultadoOperador["boolean||boolean"] = Tipo("boolean");
  resultadoOperador["!boolean"] = Tipo("boolean");
  
  //operadores bit a bit
  resultadoOperador["int<<int"] = Tipo("int");
  resultadoOperador["int>>int"] = Tipo("int");
  resultadoOperador["int&&int"] = Tipo("int");
  resultadoOperador["int||int"] = Tipo("int");
  resultadoOperador["int^int"] = Tipo("int");
  resultadoOperador["~int"] = Tipo("int");
}

#include "lex.yy.c"

int yyparse();

string toStr( int n ) {
  char buf[1024] = "";
  
  sprintf( buf, "%d", n );
  
  return buf;
}

int toInt( string n ) {
  int aux = 0;
  sscanf( n.c_str(), "%d", &aux );
  
  return aux;
}

void yyerror( const char* st )
{
  puts( st );
  printf( "Linha: %d\nPerto de: '%s'\n", nlinha, yytext );
}

void erro( string msg ) {
  yyerror( msg.c_str() );
  exit(0);
}

string geraTemp( Tipo tipo ) {
  return "temp_" + tipo.nome + "_" + toStr( ++n_var_temp[tipo.nome] );
}

string geraDeclaracaoVarPipe() {
  return "  int x_int;\n"
         "  double x_double;\n"
         "  float x_float;\n";
}

void insereVariavelTS( TS& ts, string nomeVar, Tipo tipo ) {
  if( !buscaVariavelTS( ts, nomeVar, &tipo ) )
    ts[nomeVar] = tipo;
  else  
    erro( "Variavel já definida: " + nomeVar );
}

bool buscaVariavelTS( TS& ts, string nomeVar, Tipo* tipo ) {
  if( ts.find( nomeVar ) != ts.end() ) {
    *tipo = ts[ nomeVar ];
    return true;
  }
  else
    return false;
}

void geraCodigoFilter( Atributo* SS, const Atributo& condicao ) {
  *SS = Atributo();
  SS->v = geraTemp( Tipo( "boolean" ) );
  SS->c = condicao.c + 
          "  " + SS->v + " = !" + condicao.v + ";\n" +
          "  if( " + SS->v + " ) goto " + passoPipeAtivo + ";\n";
}

void geraCodigoFirstN( Atributo* SS, const Atributo& n ) {
  *SS = Atributo();
  SS->c = n.c + 
          " if( "+ indicePipe +" > " + n.v + ") goto "  + passoPipeAtivo + ";\n";
}

void geraCodigoLastN( Atributo* SS, const Atributo& n ) {
  *SS = Atributo();
  SS->c = n.c + 
          " if( "+ indicePipe +" < " +tamanhoPipe+ " - "+ n.v + ") goto "  + passoPipeAtivo + ";\n";
}

Tipo tipoResultado( string operador, Tipo a ) {
  if( resultadoOperador.find( operador + a.nome ) == resultadoOperador.end() )
    erro( "Operacao nao permitida: " + operador + a.nome );

  return resultadoOperador[operador + a.nome];
}

Tipo tipoResultado( Tipo a, string operador, Tipo b ) {
  if( resultadoOperador.find( a.nome + operador + b.nome ) != resultadoOperador.end() )
    return resultadoOperador[a.nome + operador + b.nome];

  if( resultadoOperador.find( b.nome + operador + a.nome ) != resultadoOperador.end() )
    return resultadoOperador[b.nome + operador + a.nome];
    
  erro( "Operacao nao permitida: " + a.nome + operador + b.nome );
}

int main( int argc, char* argv[] )
{
  inicializaResultadoOperador();
  yyparse();
}
