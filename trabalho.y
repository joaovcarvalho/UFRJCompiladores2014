%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Atributo {
  string v;  // Valor
  string c;  // codigo
  string t;  // tipo
};

#define YYSTYPE Atributo

int yylex();
int yyparse();
void yyerror(const char *);
%}

%token _CTE_INT _CTE_CHAR _CTE_DOUBLE _CTE_STRING _ID 

%left '+' '-'
%left '*' '/'

%%

ATR : _ID '=' E { cout << "Aceito" << endl; }
    ;

E : E '+' E
  | E '-' E
  | E '*' E
  | E '/' E
  | F
  ;

F : _ID		{ cout << "ID: " << $1.v << endl; } 
  | _CTE_INT   { cout << "int: " << $1.v << endl; }
  | _CTE_DOUBLE { cout << "double: " << $1.v << endl; }
  | '(' E ')'
  ;

%%
int nlinha = 1;

#include "lex.yy.c"

int yyparse();

void yyerror( const char* st )
{
  puts( st );
  printf( "Linha: %d\nPerto de: '%s'\n", nlinha, yytext );
}

int main( int argc, char* argv[] )
{
  yyparse();
}
