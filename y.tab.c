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
#include <list>
/*
 * Programa exemplo de um compilador para o curso de Compiladores-2014-2 - Zimbrão
 * TODO:
 * - variavel do tipo boolean
 * - Funções e parametros
 * - Variaveis locais
 * - Array
 * - pipes
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

// Tabela para saber quantos parametros uma função possui
typedef map< string, list< Tipo > > TSP;
TSP ts_params;

typedef map< string, Tipo > TS;
TS ts_local, ts_global,ts_funcoes;
TS* ts = &ts_global; // Tabela de simbolos da vez

string pipeAtivo; // Tipo do pipe ativo
string passoPipeAtivo; // Label 'fim' do pipe ativo
string geraDeclaracaoVarPipe();
string tamanhoPipe;
string indicePipe;
string arraySortPipe;


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

void insereParamTS(TSP& ts, string nomeFunc, list<Tipo> params);
bool buscaParamTS( TSP& ts, string nomeFunc, list<Tipo>* tipo );

string toStr( int n );
int toInt( string n );

Tipo tipoResultado( string operador, Tipo a );
int nSwitch = 0;
list<Tipo> listaTemp;
int num_params_chamada = 0;
list<Tipo> listaTempChamada;
                                           
// Usando const Atributo& não cria cópia desnecessária

#define YYSTYPE Atributo

int yylex();
int yyparse();
void yyerror(const char *);

#line 206 "y.tab.c" /* yacc.c:339  */

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
    _TK_SQRT = 285,
    _TK_MAIOR = 286,
    _TK_MENOR = 287,
    _TK_MENORIGUAL = 288,
    _TK_MAIORIGUAL = 289,
    _TK_IGUAL = 290,
    _TK_DIFERENTE = 291,
    _COUT = 292,
    _SCANF = 293,
    _TK_IF = 294,
    _TK_ELSE = 295,
    _TK_FOR = 296,
    _TK_TQ = 297,
    _TK_DO = 298,
    _TK_WHILE = 299,
    _TK_SWITCH = 300,
    _TK_CASE = 301,
    _TK_BREAK = 302,
    _TK_DEFAULT = 303,
    _TK_RETURN = 304,
    _TK_NULL = 305,
    _PIPE = 306,
    _INTERVALO = 307,
    _FILTER = 308,
    _FOREACH = 309,
    _2PTS = 310,
    _X = 311,
    _FIRSTN = 312,
    _LASTN = 313,
    _SORT = 314
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
#define _TK_SQRT 285
#define _TK_MAIOR 286
#define _TK_MENOR 287
#define _TK_MENORIGUAL 288
#define _TK_MAIORIGUAL 289
#define _TK_IGUAL 290
#define _TK_DIFERENTE 291
#define _COUT 292
#define _SCANF 293
#define _TK_IF 294
#define _TK_ELSE 295
#define _TK_FOR 296
#define _TK_TQ 297
#define _TK_DO 298
#define _TK_WHILE 299
#define _TK_SWITCH 300
#define _TK_CASE 301
#define _TK_BREAK 302
#define _TK_DEFAULT 303
#define _TK_RETURN 304
#define _TK_NULL 305
#define _PIPE 306
#define _INTERVALO 307
#define _FILTER 308
#define _FOREACH 309
#define _2PTS 310
#define _X 311
#define _FIRSTN 312
#define _LASTN 313
#define _SORT 314

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 372 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   1072

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  269

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    63,     2,
      66,    67,     2,     2,    68,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    69,    65,
       2,    60,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    70,     2,    71,    62,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    61,     2,    64,     2,     2,     2,
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   167,   167,   174,   177,   181,   184,   188,   192,   194,
     198,   200,   203,   205,   207,   211,   218,   222,   224,   226,
     229,   231,   233,   235,   237,   239,   241,   243,   245,   247,
     251,   253,   257,   261,   271,   274,   278,   280,   284,   288,
     291,   293,   297,   301,   305,   309,   314,   318,   321,   324,
     343,   364,   372,   387,   389,   393,   395,   397,   399,   444,
     448,   451,   454,   460,   461,   467,   476,   477,   478,   479,
     480,   481,   484,   487,   489,   491,   495,   497,   499,   501,
     503,   505,   507,   509,   511,   513,   515,   517,   519,   521,
     523,   525,   527,   529,   531,   533,   535,   537,   539,   542,
     545,   548,   551,   557,   580,   583,   586,   589,   592,   595,
     598,   599,   605,   609,   613
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
  "_TK_SQRT", "_TK_MAIOR", "_TK_MENOR", "_TK_MENORIGUAL", "_TK_MAIORIGUAL",
  "_TK_IGUAL", "_TK_DIFERENTE", "_COUT", "_SCANF", "_TK_IF", "_TK_ELSE",
  "_TK_FOR", "_TK_TQ", "_TK_DO", "_TK_WHILE", "_TK_SWITCH", "_TK_CASE",
  "_TK_BREAK", "_TK_DEFAULT", "_TK_RETURN", "_TK_NULL", "_PIPE",
  "_INTERVALO", "_FILTER", "_FOREACH", "_2PTS", "_X", "_FIRSTN", "_LASTN",
  "_SORT", "'='", "'|'", "'^'", "'&'", "'~'", "';'", "'('", "')'", "','",
  "':'", "'['", "']'", "$accept", "S1", "DECLS", "VARGLOBAL",
  "PREPARA_GLOBAL", "FUNCTION", "DECLS_FUNCAO", "PREPARA_FUNCAO", "PARAMS",
  "DECL_PARAM", "MAIN", "CMDS", "CMD", "CMD_IF", "CMD_OUT", "COUT_EXPR",
  "CMD_IN", "COD", "BLOCO", "CMD_RETURN", "CMD_FOR", "CMD_WHILE",
  "CMD_DOWHILE", "CMD_SWITCH", "SW", "DEFAULT", "CMD_PIPE", "INI_PIPE",
  "INI_PIPE_ARRAY", "PROCS", "PROC", "CONSOME", "DECLVAR", "TIPO",
  "TIPOSIMPLES", "ATR", "E", "PARAM", "F", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
      61,   124,    94,    38,   126,    59,    40,    41,    44,    58,
      91,    93
};
# endif

#define YYPACT_NINF -164

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-164)))

#define YYTABLE_NINF -11

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     124,    -6,  -164,  -164,  -164,  -164,  -164,  -164,    16,    35,
     124,   124,  -164,   -42,    94,    39,  -164,  -164,   110,  -164,
    -164,  -164,    55,  -164,   109,   -49,   122,   966,    43,  -164,
     107,    62,   -55,  -164,   106,    70,    78,   771,    79,    80,
     107,    77,   144,   966,  -164,    85,    86,  -164,  -164,  -164,
    -164,  -164,    88,   111,     4,   147,    96,   162,   -43,  -164,
     153,  -164,  -164,  -164,  -164,  -164,  -164,   -16,   107,   107,
     108,  -164,   107,   107,   862,  -164,    97,   107,   107,   107,
     159,   107,   312,   966,   -55,  -164,   139,  -164,   107,   107,
       7,   801,   107,  -164,  -164,  -164,  -164,   966,   -23,   140,
    -164,   135,  -164,  -164,   162,    84,  -164,   107,   107,    41,
    -164,   107,  -164,   521,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   189,   862,   210,   862,  -164,   538,     5,   132,
     195,   134,   586,   603,   107,   133,   197,  -164,   818,  -164,
     136,   137,   138,   142,   111,   145,  -164,  -164,  -164,  -164,
     862,    27,   227,   651,  -164,    41,    41,  -164,  -164,  -164,
     898,   879,    23,    23,   103,   103,   103,   103,   246,   246,
     915,   934,  1036,   143,   -52,   771,   190,   190,  -164,   107,
     771,   206,   156,   966,  -164,   107,   107,   107,   107,   164,
    -164,  1006,  -164,  -164,   107,   151,  -164,  -164,   107,   107,
     182,   158,   161,   668,  -164,   178,   966,  -164,   166,   862,
     271,   288,   332,   169,   183,   862,   107,   862,   349,   771,
     215,   222,   200,   107,  -164,   111,  -164,  -164,  -164,  -164,
    -164,   393,   -51,  -164,   107,   107,  -164,   471,   140,   212,
     107,   107,   716,   733,   966,  -164,   107,   862,   410,   771,
     771,  -164,   454,   216,  -164,  -164,  -164,   107,   862
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,    66,    67,    68,    69,    70,    71,     0,     0,
       5,     5,    12,     0,     0,    63,    11,     1,     0,     2,
       3,     4,     0,     6,     0,    61,     0,    19,     0,    60,
       0,     0,    52,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    23,     0,     0,    29,    24,    25,
      26,    27,     0,     0,     0,     0,     0,     0,     0,    14,
       0,   104,   107,   105,   108,   106,   109,   102,     0,     0,
       0,   111,     0,     0,    62,    98,    64,     0,     0,    32,
       0,     0,     0,    19,     0,    37,     0,    36,     0,     0,
      48,     0,     0,    16,    17,    21,    22,    19,    54,     0,
      28,    61,    20,     7,     0,     0,    15,   101,     0,    96,
      89,     0,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,     0,    33,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    39,     0,    18,
       0,     0,     0,     0,     0,     0,    50,     9,     7,    13,
     100,     0,     0,     0,   110,    76,    77,    79,    78,    80,
      81,    82,    94,    95,    84,    83,    85,    86,    87,    88,
      91,    92,    90,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,    19,    44,     0,     0,     0,     0,     0,
      53,     0,     8,   103,     0,   112,    97,    65,     0,     0,
      30,     0,     0,     0,    42,     0,    19,    47,     0,    51,
       0,     0,     0,     0,     0,    99,     0,    73,     0,     0,
       0,     0,     0,     0,    46,     0,    55,    56,    57,    58,
      59,     0,     0,    31,     0,     0,    43,     0,     0,   113,
       0,     0,     0,     0,    19,    49,     0,    74,     0,     0,
       0,    45,     0,     0,    40,    41,   114,     0,    75
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,   101,  -164,   125,  -164,  -164,  -164,  -164,   179,
    -164,   -41,   -31,  -164,  -164,  -164,  -164,  -163,   -53,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -142,
    -164,    37,    10,     3,  -164,   -81,   -40,  -164,  -164
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    10,   157,    11,    12,    22,    58,    59,
      19,    42,    43,    44,    45,    79,    46,    86,    87,    47,
      48,    49,    50,    51,    90,   146,    52,   218,    53,    99,
     154,   156,    54,    55,    15,    56,    74,   161,    75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      91,   139,    94,    14,   103,    77,    85,    16,   208,   250,
      13,    30,   200,    14,    14,    78,    17,   -10,   209,   251,
      13,    13,   210,    23,   104,   105,    24,   214,   109,   110,
     150,    60,   112,   113,   151,   152,   153,   133,   134,   135,
      18,   137,   140,   114,   115,   116,   117,   118,   142,   143,
     107,   158,   148,   144,   108,   145,   149,     2,     3,     4,
       5,     6,     7,   116,   117,   118,   243,   160,   162,   100,
     186,   163,    24,    24,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   138,   248,   203,   204,   264,   265,     2,     3,
       4,     5,     6,     7,   192,   211,   212,    25,    60,    26,
      57,    20,    21,    27,    61,    62,    63,    64,    65,    66,
      67,    28,    29,   114,   115,   116,   117,   118,    68,    31,
       1,   121,   122,    76,    69,    80,    81,    70,     2,     3,
       4,     5,     6,     7,    82,    88,    89,    92,    93,   213,
      95,    96,   217,    97,    85,   219,   220,   221,   222,    85,
     101,   102,    98,    71,   225,    83,   106,   132,   227,   228,
     224,    72,   136,    73,   111,   234,   114,   115,   116,   117,
     118,   119,   120,   141,   121,   122,   241,   123,   124,   125,
     126,   127,   128,   247,   155,    30,   183,   187,    85,   188,
     189,   194,   193,    84,   252,   253,   196,   197,   198,   215,
     257,   258,   199,   261,   207,   201,   262,   129,   130,   131,
     223,   226,   229,   230,   233,   216,   231,   268,    85,    85,
     114,   115,   116,   117,   118,   119,   120,   235,   121,   122,
     239,   123,   124,   125,   126,   127,   128,   114,   115,   116,
     117,   118,   119,   120,   240,   121,   122,   244,   123,   124,
     125,   126,   127,   128,   245,   246,   114,   115,   116,   117,
     118,   129,   130,   131,   121,   122,   267,   123,   124,   125,
     126,   184,   256,   202,   159,   255,     0,     0,   129,   130,
     131,   114,   115,   116,   117,   118,   119,   120,   205,   121,
     122,     0,   123,   124,   125,   126,   127,   128,   114,   115,
     116,   117,   118,   119,   120,     0,   121,   122,     0,   123,
     124,   125,   126,   127,   128,    84,     2,     3,     4,     5,
       6,     7,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,   236,     0,     0,     0,     0,     0,     0,   129,
     130,   131,   114,   115,   116,   117,   118,   119,   120,   237,
     121,   122,     0,   123,   124,   125,   126,   127,   128,   114,
     115,   116,   117,   118,   119,   120,     0,   121,   122,     0,
     123,   124,   125,   126,   127,   128,     0,     0,     0,     0,
       0,     0,     0,   129,   130,   131,     0,     0,     0,     0,
       0,     0,     0,   238,     0,     0,     0,     0,     0,     0,
     129,   130,   131,   114,   115,   116,   117,   118,   119,   120,
     242,   121,   122,     0,   123,   124,   125,   126,   127,   128,
     114,   115,   116,   117,   118,   119,   120,     0,   121,   122,
       0,   123,   124,   125,   126,   127,   128,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,     0,     0,     0,
       0,     0,     0,     0,   249,     0,     0,     0,     0,     0,
       0,   129,   130,   131,   114,   115,   116,   117,   118,   119,
     120,   263,   121,   122,     0,   123,   124,   125,   126,   127,
     128,   114,   115,   116,   117,   118,   119,   120,     0,   121,
     122,     0,   123,   124,   125,   126,   127,   128,     0,     0,
       0,     0,     0,     0,     0,   129,   130,   131,     0,     0,
       0,     0,     0,     0,     0,   266,     0,     0,     0,     0,
       0,     0,   129,   130,   131,     0,     0,     0,     0,     0,
     254,   114,   115,   116,   117,   118,   119,   120,     0,   121,
     122,     0,   123,   124,   125,   126,   127,   128,   114,   115,
     116,   117,   118,   119,   120,     0,   121,   122,     0,   123,
     124,   125,   126,   127,   128,     0,     0,     0,     0,     0,
       0,     0,   129,   130,   131,     0,     0,     0,   164,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,   131,     0,     0,     0,   185,   114,   115,   116,   117,
     118,   119,   120,     0,   121,   122,     0,   123,   124,   125,
     126,   127,   128,   114,   115,   116,   117,   118,   119,   120,
       0,   121,   122,     0,   123,   124,   125,   126,   127,   128,
       0,     0,     0,     0,     0,     0,     0,   129,   130,   131,
       0,     0,     0,   190,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,     0,     0,     0,
     191,   114,   115,   116,   117,   118,   119,   120,     0,   121,
     122,     0,   123,   124,   125,   126,   127,   128,   114,   115,
     116,   117,   118,   119,   120,     0,   121,   122,     0,   123,
     124,   125,   126,   127,   128,     0,     0,     0,     0,     0,
       0,     0,   129,   130,   131,     0,     0,     0,   206,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,   131,     0,     0,     0,   232,   114,   115,   116,   117,
     118,   119,   120,     0,   121,   122,     0,   123,   124,   125,
     126,   127,   128,   114,   115,   116,   117,   118,   119,   120,
       0,   121,   122,     0,   123,   124,   125,   126,   127,   128,
       0,     0,     0,     0,    83,     0,     0,   129,   130,   131,
       0,     0,     0,   259,    84,     2,     3,     4,     5,     6,
       7,     0,     0,     0,   129,   130,   131,     0,     0,     0,
     260,     0,     0,     0,     0,     0,     0,     0,    33,    34,
      35,     0,    36,     0,    37,    38,    39,     0,     0,     0,
      40,   114,   115,   116,   117,   118,   119,   120,     0,   121,
     122,     0,   123,   124,   125,   126,   127,   128,   114,   115,
     116,   117,   118,   119,   120,     0,   121,   122,     0,   123,
     124,   125,   126,   127,   128,     0,     0,     0,     0,     0,
       0,     0,   129,   130,   131,     0,   147,     0,     0,     0,
       0,     0,     0,   195,     0,     0,     0,     0,     0,   129,
     130,   131,   114,   115,   116,   117,   118,   119,   120,     0,
     121,   122,     0,   123,   124,   125,   126,   127,   128,   114,
     115,   116,   117,   118,   119,     0,     0,   121,   122,     0,
     123,   124,   125,   126,   127,   128,     0,     0,   114,   115,
     116,   117,   118,   129,   130,   131,   121,   122,     0,   123,
     124,   125,   126,   127,   128,   114,   115,   116,   117,   118,
     129,   130,   131,   121,   122,     0,   123,   124,   125,   126,
     127,   128,     0,     0,   114,   115,   116,   117,   118,   129,
     130,   131,   121,   122,     0,   123,   124,   125,   126,   127,
     128,     0,     0,     0,     0,     0,     0,   130,   131,    32,
       2,     3,     4,     5,     6,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   131,     0,     0,
       0,     0,     0,    33,    34,    35,     0,    36,     0,    37,
      38,    39,     0,     0,     0,    40,     0,     0,    41,    84,
       2,     3,     4,     5,     6,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,     0,    36,     0,    37,
      38,    39,     0,     0,     0,    40,   114,   115,   116,   117,
     118,     0,     0,     0,   121,   122,     0,   123,   124,   125,
     126,   127,   128
};

static const yytype_int16 yycheck[] =
{
      40,    82,    43,     0,    57,    60,    37,    13,    60,    60,
       0,    60,   154,    10,    11,    70,     0,    66,    70,    70,
      10,    11,   185,    65,    67,    68,    68,   190,    68,    69,
      53,    28,    72,    73,    57,    58,    59,    77,    78,    79,
       5,    81,    83,    20,    21,    22,    23,    24,    88,    89,
      66,   104,    92,    46,    70,    48,    97,    14,    15,    16,
      17,    18,    19,    22,    23,    24,   229,   107,   108,    65,
      65,   111,    68,    68,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    82,   235,    67,    68,   259,   260,    14,    15,
      16,    17,    18,    19,   144,   186,   187,    13,   105,    70,
      67,    10,    11,     3,     7,     8,     9,    10,    11,    12,
      13,    66,    13,    20,    21,    22,    23,    24,    21,     7,
       6,    28,    29,    71,    27,    29,    66,    30,    14,    15,
      16,    17,    18,    19,    66,    66,    66,    70,     4,   189,
      65,    65,   193,    65,   185,   195,   196,   197,   198,   190,
      13,    65,    51,    56,   204,     3,    13,    70,   208,   209,
     201,    64,    13,    66,    66,   216,    20,    21,    22,    23,
      24,    25,    26,    44,    28,    29,   226,    31,    32,    33,
      34,    35,    36,   233,    54,    60,     7,    65,   229,     4,
      66,     4,    69,    13,   244,   245,    70,    70,    70,     3,
     250,   251,    70,   254,    71,    70,   256,    61,    62,    63,
      56,    70,    40,    65,    46,    69,    65,   267,   259,   260,
      20,    21,    22,    23,    24,    25,    26,    71,    28,    29,
      71,    31,    32,    33,    34,    35,    36,    20,    21,    22,
      23,    24,    25,    26,    71,    28,    29,    42,    31,    32,
      33,    34,    35,    36,    42,    65,    20,    21,    22,    23,
      24,    61,    62,    63,    28,    29,    60,    31,    32,    33,
      34,    71,    70,   158,   105,   248,    -1,    -1,    61,    62,
      63,    20,    21,    22,    23,    24,    25,    26,    71,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    20,    21,
      22,    23,    24,    25,    26,    -1,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    13,    14,    15,    16,    17,
      18,    19,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    20,    21,    22,    23,    24,    25,    26,    71,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    20,
      21,    22,    23,    24,    25,    26,    -1,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    20,    21,    22,    23,    24,    25,    26,
      71,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      20,    21,    22,    23,    24,    25,    26,    -1,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    63,    20,    21,    22,    23,    24,    25,
      26,    71,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    20,    21,    22,    23,    24,    25,    26,    -1,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      69,    20,    21,    22,    23,    24,    25,    26,    -1,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    20,    21,
      22,    23,    24,    25,    26,    -1,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    67,    20,    21,    22,    23,
      24,    25,    26,    -1,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    20,    21,    22,    23,    24,    25,    26,
      -1,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    -1,    -1,    -1,
      67,    20,    21,    22,    23,    24,    25,    26,    -1,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    20,    21,
      22,    23,    24,    25,    26,    -1,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    67,    20,    21,    22,    23,
      24,    25,    26,    -1,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    20,    21,    22,    23,    24,    25,    26,
      -1,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,     3,    -1,    -1,    61,    62,    63,
      -1,    -1,    -1,    67,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    61,    62,    63,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    -1,    41,    -1,    43,    44,    45,    -1,    -1,    -1,
      49,    20,    21,    22,    23,    24,    25,    26,    -1,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    20,    21,
      22,    23,    24,    25,    26,    -1,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    20,
      21,    22,    23,    24,    25,    -1,    -1,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    -1,    -1,    20,    21,
      22,    23,    24,    61,    62,    63,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    20,    21,    22,    23,    24,
      61,    62,    63,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    -1,    -1,    20,    21,    22,    23,    24,    61,
      62,    63,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    -1,    41,    -1,    43,
      44,    45,    -1,    -1,    -1,    49,    -1,    -1,    52,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    -1,    41,    -1,    43,
      44,    45,    -1,    -1,    -1,    49,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    28,    29,    -1,    31,    32,    33,
      34,    35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    14,    15,    16,    17,    18,    19,    73,    74,
      75,    77,    78,   104,   105,   106,    13,     0,     5,    82,
      74,    74,    79,    65,    68,    13,    70,     3,    66,    13,
      60,     7,    13,    37,    38,    39,    41,    43,    44,    45,
      49,    52,    83,    84,    85,    86,    88,    91,    92,    93,
      94,    95,    98,   100,   104,   105,   107,    67,    80,    81,
     105,     7,     8,     9,    10,    11,    12,    13,    21,    27,
      30,    56,    64,    66,   108,   110,    71,    60,    70,    87,
      29,    66,    66,     3,    13,    84,    89,    90,    66,    66,
      96,   108,    70,     4,    83,    65,    65,    65,    51,   101,
      65,    13,    65,    90,    67,    68,    13,    66,    70,   108,
     108,    66,   108,   108,    20,    21,    22,    23,    24,    25,
      26,    28,    29,    31,    32,    33,    34,    35,    36,    61,
      62,    63,    70,   108,   108,   108,    13,   108,   104,   107,
      83,    44,   108,   108,    46,    48,    97,    65,   108,    83,
      53,    57,    58,    59,   102,    54,   103,    76,    90,    81,
     108,   109,   108,   108,    67,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,     7,    71,    67,    65,    65,     4,    66,
      67,    67,   108,    69,     4,    55,    70,    70,    70,    70,
     101,    70,    76,    67,    68,    71,    67,    71,    60,    70,
      89,   107,   107,   108,    89,     3,    69,    83,    99,   108,
     108,   108,   108,    56,    84,   108,    70,   108,   108,    40,
      65,    65,    67,    46,    83,    71,    71,    71,    71,    71,
      71,   108,    71,    89,    42,    42,    65,   108,   101,    71,
      60,    70,   108,   108,    69,   103,    70,   108,   108,    67,
      67,    83,   108,    71,    89,    89,    71,    60,   108
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    74,    74,    74,    75,    76,    77,    77,
      78,    78,    79,    80,    80,    81,    82,    83,    83,    83,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      85,    85,    86,    87,    87,    88,    89,    89,    90,    91,
      92,    92,    93,    94,    95,    96,    96,    97,    97,    98,
      98,    99,   100,   101,   101,   102,   102,   102,   102,   103,
     104,   104,   104,   105,   105,   105,   106,   106,   106,   106,
     106,   106,   107,   107,   107,   107,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   109,
     109,   109,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     2,     0,     7,     6,
       2,     2,     0,     3,     1,     2,     4,     2,     3,     0,
       2,     2,     2,     1,     1,     1,     1,     1,     2,     1,
       5,     7,     2,     2,     0,     3,     1,     1,     3,     3,
      10,    10,     5,     7,     4,     8,     5,     3,     0,     8,
       3,     1,     1,     3,     1,     4,     4,     4,     4,     4,
       3,     2,     4,     1,     4,     7,     1,     1,     1,     1,
       1,     1,     3,     6,     9,    12,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     2,     3,     3,     2,     4,     1,     3,
       1,     0,     1,     4,     1,     1,     1,     1,     1,     1,
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
#line 168 "trabalho.y" /* yacc.c:1646  */
    { cout << "#include <stdio.h>\n"
               "#include <stdlib.h>\n"
               "#include <string.h>\n\n"
            << (yyvsp[-1]).c << (yyvsp[0]).c << endl; }
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 175 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Atributo();
          (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c; }
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 178 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Atributo();
          (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c; }
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 181 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Atributo(); }
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 185 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]);}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 188 "trabalho.y" /* yacc.c:1646  */
    { ts = &ts_global;}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 193 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoFuncao(&(yyval), (yyvsp[-6]), (yyvsp[-3]), (yyvsp[-1])); insereParamTS(ts_params, (yyvsp[-6]).v, listaTemp); }
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 195 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoFuncao(&(yyval), (yyvsp[-5]), Atributo(), (yyvsp[-1])); }
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 199 "trabalho.y" /* yacc.c:1646  */
    { insereVariavelTS(ts_funcoes, (yyvsp[0]).v, (yyvsp[-1]).t); (yyval).v = (yyvsp[0]).v; (yyval).t = (yyvsp[-1]).t; listaTemp = list<Tipo>();}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 201 "trabalho.y" /* yacc.c:1646  */
    { insereVariavelTS(ts_funcoes, (yyvsp[0]).v, (yyvsp[-1]).t); (yyval).v = (yyvsp[0]).v; (yyval).t = (yyvsp[-1]).t; listaTemp = list<Tipo>(); }
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 203 "trabalho.y" /* yacc.c:1646  */
    { ts_local = TS(); ts = &ts_local;}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 206 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + ',' + ' ' + (yyvsp[0]).c; }
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 208 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 212 "trabalho.y" /* yacc.c:1646  */
    {
        insereVariavelTS( *ts, (yyvsp[0]).v, (yyvsp[-1]).t );
        geraCodigoParam(&(yyval), (yyvsp[-1]), (yyvsp[0]));
        listaTemp.push_back((yyvsp[-1]).t);
      }
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 219 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoFuncaoPrincipal( &(yyval), (yyvsp[-1]) ); }
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 223 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c; }
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 224 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c; }
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 226 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Atributo(); }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 230 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c;  }
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 232 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c; }
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 234 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c; }
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 236 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c; }
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 238 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c; }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 240 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c; }
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 242 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c; }
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 244 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c; }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 246 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c; }
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 248 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c; }
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 252 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoIfSemElse( &(yyval), (yyvsp[-2]), (yyvsp[0]) );}
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 254 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoIfComElse( &(yyval), (yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]) ); }
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 258 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 262 "trabalho.y" /* yacc.c:1646  */
    { if( (yyvsp[0]).t.nome == "int" )
                (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c + 
                       "  printf( \"%d\" , " + (yyvsp[0]).v + " );\n";
              else if( (yyvsp[0]).t.nome == "string" )
                (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c + 
                       "  printf( \"%s\" , " + (yyvsp[0]).v + " );\n";
              else if( (yyvsp[0]).t.nome == "double")
                (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c +
                      "  printf( \"%f\" , " + (yyvsp[0]).v + " );\n";}
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 271 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Atributo(); }
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 275 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoInput(&(yyval), (yyvsp[0])); }
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 279 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c;}
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 281 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c;}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 285 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c;}
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 289 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoReturn(&(yyval), (yyvsp[-1])); }
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 292 "trabalho.y" /* yacc.c:1646  */
    {geraCodigoFor(&(yyval), (yyvsp[-7]), (yyvsp[-2]), (yyvsp[-5]), (yyvsp[0]));}
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 294 "trabalho.y" /* yacc.c:1646  */
    {geraCodigoFor(&(yyval), (yyvsp[-7]), (yyvsp[-2]), (yyvsp[-5]), (yyvsp[0]));}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 298 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoWhile( &(yyval), (yyvsp[-2]), (yyvsp[0])); }
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 302 "trabalho.y" /* yacc.c:1646  */
    {geraCodigoDoWhile(&(yyval), (yyvsp[-5]), (yyvsp[-2])) ;}
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 306 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoSwitch(&(yyval), (yyvsp[-2]), (yyvsp[-1])); }
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 310 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-6]).c;
        (yyval).v = (yyvsp[-6]).v;
        nSwitch++;
        geraCodigoCase(&(yyval), Atributo(), (yyvsp[-2]), (yyvsp[0])); }
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 315 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoCase(&(yyval), (yyvsp[-4]), (yyvsp[-2]), (yyvsp[0])); }
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 319 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c; }
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 321 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = ""; }
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 325 "trabalho.y" /* yacc.c:1646  */
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
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 343 "trabalho.y" /* yacc.c:1646  */
    {
              Atributo inicio, condicao, passo, cmd;

              inicio.c = indicePipe + " = 0;\n" +
                          "sortArray_"+(yyvsp[-2]).t.nome+" = " + (yyvsp[-2]).v + ";\n" +
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
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 365 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);
            indicePipe = "x_"+pipeAtivo;
             tamanhoPipe = (yyvsp[0]).v;
             pipeAtivo =  (yyvsp[0]).t.nome;
       passoPipeAtivo = geraLabel( "passo_pipe" ); }
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 373 "trabalho.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
            if( buscaVariavelTS( *ts, (yyvsp[0]).v, &(yyval).t ) ){
              pipeAtivo = (yyval).t.nome;
              arraySortPipe = "x_array_"+pipeAtivo;
              tamanhoPipe = toStr((yyval).t.d1);
              string counter = geraTemp(Tipo("int"));
              indicePipe = counter;
              passoPipeAtivo = geraLabel( "passo_pipe" );
            }
            else
              erro("Array nao declarado."); 
        }
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 388 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c; }
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 390 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Atributo(); }
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 394 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoFilter( &(yyval), (yyvsp[-1]) ); }
#line 2185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 396 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoFirstN( &(yyval), (yyvsp[-1]) ); }
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 398 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoLastN( &(yyval), (yyvsp[-1]) ); }
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 400 "trabalho.y" /* yacc.c:1646  */
    { 
              Atributo for1, for2, comparacao;
              Atributo inicio1, condicao1, passo1, cmd1;
              Atributo inicio2, condicao2, passo2, cmd2;

              string sortArrayAtivo = "sortArray_"+pipeAtivo;
              string i = geraTemp(Tipo("int"));
              string j = geraTemp(Tipo("int"));
              string auxiliar = geraTemp(Tipo(pipeAtivo));

              inicio1.c = i + " = " + tamanhoPipe+ " - 1;\n";
              condicao1.t.nome = "boolean";
              condicao1.v = geraTemp(Tipo("boolean"));
              condicao1.c = " "+ condicao1.v + " = " + i + " >= 1;\n";
              passo1.c = " "+ i + " = " + i + " - 1;\n";

              inicio2.c = j + " = 0;\n";
              condicao2.t.nome = "boolean";
              condicao2.v = geraTemp(Tipo("boolean"));
              condicao2.c = " "+ condicao2.v + " = " + j + " < "+i+";\n";
              passo2.c = " "+ j + " = " + j + " + 1;\n";

              Atributo expr, cmds;
              string indiceTemp = geraTemp(Tipo("int"));
              string temp1 = geraTemp(Tipo(pipeAtivo));
              string temp2 = geraTemp(Tipo(pipeAtivo));

              expr.v = geraTemp(Tipo("boolean"));
              expr.c = indiceTemp + "= " + j + "+ 1;\n" +
                      temp1 + " = "+sortArrayAtivo+"[" + indiceTemp +"];\n"+
                      temp2 + " = "+sortArrayAtivo+"[" + j + "];\n"+
                      expr.v + " = "+temp2+">"+temp1+";\n";
              cmds.c = auxiliar + " = "+sortArrayAtivo+"[" + j + "];\n"+
                       ""+sortArrayAtivo+"["+j+"] = "+sortArrayAtivo+"["+indiceTemp+"];\n"+
                       ""+sortArrayAtivo+"["+indiceTemp+"] = "+auxiliar+";\n ";
              geraCodigoIfSemElse(&comparacao, expr, cmds);
              cmd2 = comparacao;
              geraCodigoFor(&for2, inicio2, condicao2, passo2, cmd2);
              cmd1 = for2;

              geraCodigoFor( &(yyval) , inicio1, condicao1, passo1, cmd1 );
        }
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 445 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c; }
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 449 "trabalho.y" /* yacc.c:1646  */
    { insereVariavelTS( *ts, (yyvsp[0]).v, (yyvsp[-2]).t ); 
            geraDeclaracaoVariavel( &(yyval), (yyvsp[-2]), (yyvsp[0]) ); }
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 452 "trabalho.y" /* yacc.c:1646  */
    { insereVariavelTS( *ts, (yyvsp[0]).v, (yyvsp[-1]).t ); 
            geraDeclaracaoVariavel( &(yyval), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 455 "trabalho.y" /* yacc.c:1646  */
    { insereVariavelTS( *ts, (yyvsp[-2]).v, (yyvsp[-3]).t ); 
            geraDeclaracaoVariavelComAtribuicao( &(yyval), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[0]) );
          }
#line 2272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 462 "trabalho.y" /* yacc.c:1646  */
    { 
         (yyval) = (yyvsp[-3]);
         (yyval).t.nDim = 1;
         (yyval).t.d1 = toInt( (yyvsp[-1]).v ); 
         }
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 468 "trabalho.y" /* yacc.c:1646  */
    { 
         (yyval) = (yyvsp[-6]);
         (yyval).t.nDim = 2;
         (yyval).t.d1 = toInt( (yyvsp[-4]).v ); 
         (yyval).t.d2 = toInt( (yyvsp[-1]).v ); 
         }
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 485 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoAtribuicaoSemIndice( &(yyval), (yyvsp[-2]), (yyvsp[0]) ); 
      }
#line 2300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 488 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoAtribuicao1Indice( &(yyval), (yyvsp[-5]), (yyvsp[-3]), (yyvsp[0]) ); }
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 490 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoAtribuicao2Indices( &(yyval), (yyvsp[-8]), (yyvsp[-6]), (yyvsp[-3]), (yyvsp[0]) );}
#line 2312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 492 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoAtribuicao3Indices( &(yyval), (yyvsp[-11]), (yyvsp[-9]), (yyvsp[-6]), (yyvsp[-3]), (yyvsp[0]) ); }
#line 2318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 496 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 498 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 500 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 502 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 504 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 506 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 508 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 510 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 512 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 514 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 516 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 518 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 520 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 522 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorUnario( &(yyval), (yyvsp[-1]), (yyvsp[0])); }
#line 2402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 524 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 526 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 528 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 530 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorUnario( &(yyval), (yyvsp[-1]), (yyvsp[0])); }
#line 2426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 532 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 534 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorBinario( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 2438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 536 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorUnario (&(yyval), (yyvsp[-1]), (yyvsp[0])); }
#line 2444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 538 "trabalho.y" /* yacc.c:1646  */
    { geraCodigoOperadorUnario (&(yyval), (yyvsp[-3]), (yyvsp[-1]));}
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 543 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c;
          (yyval).v = (yyvsp[-2]).v + ',' + (yyvsp[0]).v; num_params_chamada++; listaTempChamada.push_back((yyvsp[0]).t); }
#line 2457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 546 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); num_params_chamada = 1; listaTempChamada = list<Tipo>(); listaTempChamada.push_back((yyvsp[0]).t); }
#line 2463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 548 "trabalho.y" /* yacc.c:1646  */
    {}
#line 2469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 552 "trabalho.y" /* yacc.c:1646  */
    { if( buscaVariavelTS( *ts, (yyvsp[0]).v, &(yyval).t ) ) 
      (yyval).v = (yyvsp[0]).v; 
    else
      erro( "Variavel nao declarada: " + (yyvsp[0]).v );
  }
#line 2479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 558 "trabalho.y" /* yacc.c:1646  */
    {
    if( buscaVariavelTS( ts_funcoes, (yyvsp[-3]).v, &(yyval).t ) ){
      list<Tipo> meus_params;
      if(buscaParamTS(ts_params, (yyvsp[-3]).v, &meus_params)){ 
        if(meus_params.size() != num_params_chamada)
          erro("Numero de parmetros incorreto.");

        list<Tipo>::iterator it1 = meus_params.begin();
        list<Tipo>::iterator it2 = listaTempChamada.begin();

        for(; it1 != meus_params.end() && it2 != listaTempChamada.end(); ++it1, ++it2)
        {
            if((*it1).nome != (*it2).nome)
              erro("Tipo incorreto de parametros para a funcao.");
        }
      }
        (yyval).c = (yyvsp[-1]).c;
        (yyval).v = (yyvsp[-3]).v + '(' + (yyvsp[-1]).v + ')';
    }else{ 
      erro( "Funcao nao declarada: "+ (yyvsp[-3]).v);
    }
  }
#line 2506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 581 "trabalho.y" /* yacc.c:1646  */
    {  (yyval).v = (yyvsp[0]).v; 
       (yyval).t = Tipo( "int" ); }
#line 2513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 584 "trabalho.y" /* yacc.c:1646  */
    {  (yyval).v = (yyvsp[0]).v; 
       (yyval).t = Tipo( "double" ); }
#line 2520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 587 "trabalho.y" /* yacc.c:1646  */
    {  (yyval).v = (yyvsp[0]).v; 
       (yyval).t = Tipo( "float" ); }
#line 2527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 590 "trabalho.y" /* yacc.c:1646  */
    {  (yyval).v = (yyvsp[0]).v; 
       (yyval).t = Tipo( "char" ); }
#line 2534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 593 "trabalho.y" /* yacc.c:1646  */
    {  (yyval).v = (yyvsp[0]).v; 
       (yyval).t = Tipo( "boolean" ); }
#line 2541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 596 "trabalho.y" /* yacc.c:1646  */
    {  (yyval).v = (yyvsp[0]).v; 
       (yyval).t = Tipo( "string" ); }
#line 2548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 598 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 600 "trabalho.y" /* yacc.c:1646  */
    { if( pipeAtivo != "" )
        (yyval) = Atributo( "x_" + pipeAtivo, pipeAtivo ); 
      else
        erro( "Variavel 'x' so pode ser usada dentro de pipe" );
    }
#line 2564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 606 "trabalho.y" /* yacc.c:1646  */
    {
    geraCodigoAcessoArray(&(yyval), (yyvsp[-3]), (yyvsp[-1]), Atributo(), Atributo(), 1);
  }
#line 2572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 610 "trabalho.y" /* yacc.c:1646  */
    {
    geraCodigoAcessoArray(&(yyval), (yyvsp[-6]), (yyvsp[-4]), (yyvsp[-1]), Atributo(), 2);
  }
#line 2580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 614 "trabalho.y" /* yacc.c:1646  */
    {
    geraCodigoAcessoArray(&(yyval), (yyvsp[-9]), (yyvsp[-7]), (yyvsp[-4]), (yyvsp[-1]), 3);
  }
#line 2588 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2592 "y.tab.c" /* yacc.c:1646  */
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
#line 620 "trabalho.y" /* yacc.c:1906  */


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

  SS->t = t;
  switch(dim){
    case 1:
        SS->c = expr1.c;
        SS->v = "  " + id.v + "[" + expr1.v + "]";
    break;

    case 2: 
        string temp1 = geraTemp(Tipo("int"));
        string temp2 = geraTemp(Tipo("int"));

        SS->c = expr1.c + expr2.c +
                temp1 + " = " + expr1.v + "*" + toStr(t.d2) +";\n" +
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
  // else if( lvalue.t.nDim != 0 || rvalue.t.nDim != 0 )
  //   erro( "Atribuicao de array nao e permitida: " + lvalue.v + " = " + rvalue.v );
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
        SS->c = id.c +"  scanf( \"%lf\" , &" + id.v + " );\n";
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

  SS->c = cabecalho.t.nome + " " + cabecalho.v + "( "+params.c+ " ) {\n" +
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
  
  if ((S1.t.nome == "string") && (S3.t.nome == "string") && (S2.v == "==")){
      SS->c = S1.c + S3.c +
      "  " + SS->v + " = " + "strcmp("+ S1.v + ","+ S3.v +") == 0; \n";
  }
  
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
  resultadoOperador["-int"] = Tipo("int");
  
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
  resultadoOperador["double<double"] = Tipo( "boolean" );
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
  
  //string
  resultadoOperador["string+string"] = Tipo( "string" );
  resultadoOperador["string+int"] = Tipo("string");
  resultadoOperador["string==string"] = Tipo("boolean");
  
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
         "  float x_float;\n"
         "  int* sortArray_int;\n"
         "  int* sortArray_double;\n"
         "  int* sortArray_float;\n";
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

bool buscaParamTS( TSP& ts, string nomeFunc, list<Tipo>* tipo ) {
  if( ts.find( nomeFunc ) != ts.end() ) {
    *tipo = ts[ nomeFunc ];
    return true;
  }
  else
    return false;
}

void insereParamTS(TSP& ts, string nomeFunc, list<Tipo> params){
  if( !buscaParamTS( ts, nomeFunc, &params ) )
    ts[nomeFunc] = params;
  else  
    erro( "Função já definida: " + nomeFunc );
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
  string temp = geraTemp(Tipo("boolean"));

  SS->c = n.c + 
          temp + "=" + indicePipe +" >= " + n.v + ";\n"+
          " if( "+temp+") goto "  + passoPipeAtivo + ";\n";
}

void geraCodigoLastN( Atributo* SS, const Atributo& n ) {
  *SS = Atributo();
  string temp = geraTemp(Tipo("int"));
  string condicao = geraTemp(Tipo("boolean"));

  SS->c = n.c + 
          temp + " = "+tamanhoPipe+ " - "+ n.v + ";\n"+
          condicao + "= "+ indicePipe +" < "+temp+";\n"
          " if( "+condicao+" ) goto "  + passoPipeAtivo + ";\n";
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
