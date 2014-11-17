%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>

using namespace std;

struct Tipo {
  string nome;
  
  Tipo() {}
  Tipo( string nome ) {
    this->nome = nome;
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
TS ts; // Tabela de simbolos

Tipo tipoResultado( Tipo a, string operador, Tipo b );
string geraTemp( Tipo tipo );
string geraDeclaracaoTemporarias();

void insereVariavelTS( TS&, string nomeVar, Tipo tipo );
bool buscaVariavelTS( TS&, string nomeVar, Tipo* tipo );
void erro( string msg );
string toStr( int n );

void geraCodigoOperadorBinario( Atributo* SS, Atributo S1, Atributo S2, Atributo S3 );

#define YYSTYPE Atributo

int yylex();
int yyparse();
void yyerror(const char *);
%}

%token _CTE_INT _CTE_CHAR _CTE_DOUBLE _CTE_STRING _ID 
%token _INT _CHAR _BOOL _DOUBLE _FLOAT _STRING  _COUT _SHIFTL

%nonassoc '<' '>'
%left '+' '-'
%left '*' '/'

%% 

S1 : S { cout << geraDeclaracaoTemporarias() << $1.c << endl; }

S : VAR ';' S
    { $$.c = $1.c + $3.c; }
  | ATR ';' S 
    { $$.c = $1.c + $3.c; }
  | CMD ';' S  
    { $$.c = $1.c + $3.c; }
  |
    { $$.c = ""; }
  ;

BLOCO : _TK_IB S _TK_FB
      | VAR ';'
      | ATR ';'
      | CMD ';'
    ;
    
CASO : _TK_CASE F ':' S _TK_BREAK ';' CASO
     | _TK_DEFAULT ':' S
     |
        { $$.c = ""; }
    ;
  
CMD : _TK_IF '('E')' BLOCO
    | _TK_IF '('E')' S _TK_ELSE BLOCO
    | _TK_FOR '('ATR ';' ATR ';' _TK_TQ E')' BLOCO
    | _TK_WHILE '(' E ')' BLOCO
    | _TK_DO BLOCO _TK_WHILE '(' E ')' ';'
    | _TK_SWITCH '(' _ID ')' _TK_IB CASO _TK_FB
        { if( !buscaVariavelTS( ts, $3.v, &$3.t ) ) {
            erro( "Variavel nao declarada: " + $3.v );
          }
        }
  ;

VAR : VAR ',' _ID
      { insereVariavelTS( ts, $3.v, $1.t ); 
        $$.v = "";
        $$.t = $1.t;
        $$.c = $1.c + 
               "  " + $1.t.nome + " " + $3.v + ";\n"; }
    | TIPO _ID
      { insereVariavelTS( ts, $2.v, $1.t ); 
        $$.v = "";
        $$.t = $1.t;
        $$.c = "  " + $1.t.nome + " " + $2.v + ";\n"; }
    ;
    
PARAM : ',' TIPO _ID PARAM
      |
        { $$.c = ""; }
      ;
      
FUNCTION : TIPO _ID '(' TIPO _ID PARAM ')' BLOCO
         | _TK_VOID _ID '(' TIPO _ID PARAM ')' BLOCO
         | TIPO _ID '(' ')' BLOCO
         | _TK_VOID _ID '(' ')' BLOCO
         ;
    
TIPO : _TK_INT
     | _TK_CHAR
     | _TK_BOOL
     | _TK_DOUBLE
     | _TK_FLOAT
     | _TK_STRING
     ;
  
ATR : _ID '=' E 
    { if( buscaVariavelTS( ts, $1.v, &$1.t ) ) {
        if( $1.t.nome == $3.t.nome ) {
          $$.c = $1.c + $3.c + 
                 "  " + $1.v + " = " + $3.v + ";\n"; 
        }
        else
          erro( "Expressao " + $3.t.nome + 
                " nao pode ser atribuida a variavel " +
                $1.t.nome );
      } 
      else
        erro( "Variavel nao declarada: " + $1.v );
      
       }
    ;

E : E _TK_+ E   
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_- E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_* E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_/ E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_% E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_AND E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_OR E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_< E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_> E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_<= E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_>= E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_== E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_!= E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | _TK_NOT E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E '&' E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E '|' E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E '^' E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | '~' E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _SHIFTL E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _SHIFTR E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | F
  ;

F : _ID   
  { if( buscaVariavelTS( ts, $1.v, &$$.t ) ) 
      $$.v = $1.v; 
    else
      erro( "Variavel nao declarada: " + $1.v );
  } 
  | _INT 
    {  $$.v = $1.v; 
       $$.t = Tipo( "int" ); }
  | _DOUBLE 
    {  $$.v = $1.v; 
       $$.t = Tipo( "double" ); }
  | _FLOAT 
    {  $$.v = $1.v; 
       $$.t = Tipo( "float" ); }
  | _CHAR 
    {  $$.v = $1.v; 
       $$.t = Tipo( "char" ); }
  | _BOOLEAN 
    {  $$.v = $1.v; 
       $$.t = Tipo( "bool" ); }
  | _STRING 
    {  $$.v = $1.v; 
       $$.t = Tipo( "string" ); }
  | '(' E ')'  { $$ = $2; }
  ;
  

%%

int nlinha = 1;
map<string,int> n_var_temp;
map<string,Tipo> resultadoOperador;

string geraDeclaracaoTemporarias() {
  string c;
  
  for( int i = 0; i < n_var_temp["bool"]; i++ )
    c += "  int temp_bool_" + toStr( i + 1 ) + ";\n";
    
  for( int i = 0; i < n_var_temp["int"]; i++ )
    c += "  int temp_int_" + toStr( i + 1 ) + ";\n";
    
  for( int i = 0; i < n_var_temp["double"]; i++ )
    c += "  double temp_double_" + toStr( i + 1 ) + ";\n";
    
  return c;  
}

void geraCodigoOperadorBinario( Atributo* SS, Atributo S1, Atributo S2, Atributo S3 ) {
  SS->t = tipoResultado( S1.t, S2.v, S3.t );
  SS->v = geraTemp( SS->t );
  SS->c = S1.c + S3.c + 
          "  " + SS->v + " = " + S1.v + " " + S2.v + " " + S3.v + ";\n";
}

void inicializaResultadoOperador() {
  resultadoOperador["int+int"] = Tipo( "int" );
  resultadoOperador["int-int"] = Tipo( "int" );
  resultadoOperador["int*int"] = Tipo( "int" );
  resultadoOperador["int/int"] = Tipo( "int" );
  resultadoOperador["int<int"] = Tipo( "bool" );
  resultadoOperador["double+int"] = Tipo( "double" );
  resultadoOperador["int*double"] = Tipo( "double" );
  // TODO: completar essa lista... :(
}

#include "lex.yy.c"

int yyparse();

string toStr( int n ) {
  char buf[1024] = "";
  
  sprintf( buf, "%d", n );
  
  return buf;
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

Tipo tipoResultado( Tipo a, string operador, Tipo b ) {
  if( resultadoOperador.find( a.nome + operador + b.nome ) == resultadoOperador.end() )
    erro( "Operacao nao permitida: " + a.nome + operador + b.nome );

  return resultadoOperador[a.nome + operador + b.nome];
}

int main( int argc, char* argv[] )
{
  inicializaResultadoOperador();
  yyparse();
}
