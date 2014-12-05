%{
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
%}

%token _TK_IB _TK_FB _TK_MAIN _TK_VOID
%token _INT _CHAR _DOUBLE _BOOLEAN _FLOAT _STRING _ID 
%token _TK_INT _TK_CHAR _TK_BOOLEAN _TK_DOUBLE _TK_FLOAT _TK_STRING
%token _TK_MAIS _TK_MENOS _TK_DIVIDIDO _TK_VEZES _TK_RESTO _TK_AND _TK_OR _TK_NOT _SHIFTL _SHIFTR
%token _TK_MAIOR _TK_MENOR _TK_MENORIGUAL _TK_MAIORIGUAL _TK_IGUAL _TK_DIFERENTE
%token _COUT _SCANF _TK_IF _TK_ELSE _TK_FOR _TK_TQ _TK_DO _TK_WHILE _TK_SWITCH _TK_CASE _TK_BREAK _TK_DEFAULT
%token _TK_RETURN _TK_NULL
%token _PIPE _INTERVALO _FILTER _FOREACH _2PTS _X _FIRSTN _LASTN _SORT

// Usando associatividade e precedencia igual a C
%right '='
%left _TK_OR
%left _TK_AND
%left '|'
%left '^'
%left '&'
%left  _TK_IGUAL _TK_DIFERENTE
%left _TK_MENOR _TK_MENORIGUAL _TK_MAIOR _TK_MAIORIGUAL 
%left _SHIFTR _SHIFTL
%left _TK_MAIS _TK_MENOS  
%left _TK_VEZES _TK_DIVIDIDO _TK_RESTO
%right _TK_NOT '~'


%% 

S1 : DECLS MAIN
     { cout << "#include <stdio.h>\n"
               "#include <stdlib.h>\n"
               "#include <string.h>\n\n"
            << $1.c << $2.c << endl; }
   ;
     
DECLS : VARGLOBAL DECLS 
        { $$ = Atributo();
          $$.c = $1.c + $2.c; }        
      | FUNCTION DECLS
        { $$ = Atributo();
          $$.c = $1.c + $2.c; }    
      |
        { $$ = Atributo(); }
      ;
      
VARGLOBAL : DECLVAR ';'
            { $$ = $1;}
          ;

PREPARA_GLOBAL : { ts = &ts_global;}
          ;

// Aqui é referente a funções
FUNCTION : DECLS_FUNCAO PREPARA_FUNCAO '(' PARAMS ')' BLOCO PREPARA_GLOBAL
          { geraCodigoFuncao(&$$, $1, $4, $6); insereParamTS(ts_params, $1.v, listaTemp); }
         | DECLS_FUNCAO PREPARA_FUNCAO '(' ')' BLOCO PREPARA_GLOBAL
          { geraCodigoFuncao(&$$, $1, Atributo(), $5); }
         ;

DECLS_FUNCAO : TIPO _ID
          { insereVariavelTS(ts_funcoes, $2.v, $1.t); $$.v = $2.v; $$.t = $1.t; listaTemp = list<Tipo>();}
          | _TK_VOID _ID
          { insereVariavelTS(ts_funcoes, $2.v, $1.t); $$.v = $2.v; $$.t = $1.t; listaTemp = list<Tipo>(); }

PREPARA_FUNCAO : { ts_local = TS(); ts = &ts_local;} // Passa a usar a tabela de var local.

PARAMS : PARAMS ',' DECL_PARAM
       { $$.c = $1.c + ',' + ' ' + $3.c; }
       | DECL_PARAM
       { $$ = $1; }
       ;

DECL_PARAM: TIPO _ID
      {
        insereVariavelTS( *ts, $2.v, $1.t );
        geraCodigoParam(&$$, $1, $2);
        listaTemp.push_back($1.t);
      }

MAIN : _TK_MAIN _TK_IB CMDS _TK_FB
       { geraCodigoFuncaoPrincipal( &$$, $3 ); }
     ; 

CMDS  : CMD CMDS
       { $$.c = $1.c + $2.c; }
     | CMD_PIPE ';' CMDS    { $$.c = $1.c + $3.c; }
     |
       { $$ = Atributo(); }
     ;

CMD : ATR ';'
       { $$.c = $1.c;  }
     | CMD_OUT ';'
       { $$.c = $1.c; }
     | CMD_IN ';'
       { $$.c = $1.c; }
     | CMD_IF  
       { $$.c = $1.c; }
     | CMD_FOR
       { $$.c = $1.c; }
     | CMD_WHILE
       { $$.c = $1.c; }
     | CMD_DOWHILE
       { $$.c = $1.c; }
     | CMD_SWITCH
       { $$.c = $1.c; }
     | DECLVAR ';'
       { $$.c = $1.c; }
     | CMD_RETURN
       { $$.c = $1.c; }

  
CMD_IF : _TK_IF '('E')' COD
           { geraCodigoIfSemElse( &$$, $3, $5 );}
        | _TK_IF '('E')' COD _TK_ELSE COD
           { geraCodigoIfComElse( &$$, $3, $5, $7 ); }
        ;

CMD_OUT : _COUT COUT_EXPR
          { $$ = $2; }
        ;

COUT_EXPR : COUT_EXPR E 
            { if( $2.t.nome == "int" )
                $$.c = $1.c + $2.c + 
                       "  printf( \"%d\" , " + $2.v + " );\n";
              else if( $2.t.nome == "string" )
                $$.c = $1.c + $2.c + 
                       "  printf( \"%s\" , " + $2.v + " );\n";
              else if( $2.t.nome == "double")
                $$.c = $1.c + $2.c +
                      "  printf( \"%lf\" , " + $2.v + " );\n";
              else if( $2.t.nome == "float")
                $$.c = $1.c + $2.c +
                      "  printf( \"%f\" , " + $2.v + " );\n";}
          | { $$ = Atributo(); }
          ;

CMD_IN : _SCANF _SHIFTR _ID
        { geraCodigoInput(&$$, $3); }
      ;

COD :  BLOCO
       { $$.c = $1.c;}
       | CMD
       { $$.c = $1.c;}
       ;

BLOCO : _TK_IB CMDS _TK_FB
        { $$.c = $2.c;}
        ;

CMD_RETURN : _TK_RETURN E ';'
          { geraCodigoReturn(&$$, $2); }

CMD_FOR: _TK_FOR '('DECLVAR ';' ATR ';' _TK_TQ E ')' COD
              {geraCodigoFor(&$$, $3, $8, $5, $10);}
      | _TK_FOR '('ATR ';' ATR ';' _TK_TQ E ')' COD
              {geraCodigoFor(&$$, $3, $8, $5, $10);}
          
          
CMD_WHILE: _TK_WHILE '(' E ')' COD
              { geraCodigoWhile( &$$, $3, $5); }
            ;
            
CMD_DOWHILE: _TK_DO COD _TK_WHILE '(' E ')' ';'
               {geraCodigoDoWhile(&$$, $2, $5) ;}
             ;

CMD_SWITCH : _TK_SWITCH SW DEFAULT _TK_FB
              { geraCodigoSwitch(&$$, $2, $3); }
            ;

SW  : '(' E ')' _TK_IB _TK_CASE E ':' CMDS
      { $$.c = $2.c;
        $$.v = $2.v;
        nSwitch++;
        geraCodigoCase(&$$, Atributo(), $6, $8); }
    | SW _TK_CASE E ':' CMDS
      { geraCodigoCase(&$$, $1, $3, $5); }
    ;

DEFAULT : _TK_DEFAULT ':' CMDS
          { $$.c = $3.c; }
        |
          { $$.c = ""; }
        ;

CMD_PIPE : _INTERVALO '[' E _2PTS INI_PIPE ']' PROCS CONSOME 
          { 
            Atributo inicio, condicao, passo, cmd;
            
            
            inicio.c = $3.c + $5.c +
                       "  x_" + pipeAtivo + " = " + $3.v + ";\n";
            condicao.t.nome = "boolean";
            condicao.v = geraTemp( Tipo( "boolean" ) ); 
            condicao.c = "  " + condicao.v + " = " + "x_" + pipeAtivo + 
                         " <= " + $5.v + ";\n";
            passo.c = passoPipeAtivo + ":\n" + 
                      "  x_" + pipeAtivo + " = x_" + pipeAtivo + " + 1;\n";
            cmd.c = $7.c + $8.c;
            
            geraCodigoFor( &$$, inicio, condicao, passo, cmd );
            
            pipeAtivo = ""; }

          | INI_PIPE_ARRAY PROCS CONSOME{
              Atributo inicio, condicao, passo, cmd;

              inicio.c = indicePipe + " = 0;\n" +
                          "sortArray_"+$1.t.nome+" = " + $1.v + ";\n" +
                          "x_"+pipeAtivo+" = "+$1.v+"["+indicePipe+"];"; 
              condicao.t.nome = "boolean";
              condicao.v = geraTemp( Tipo( "boolean" ) ); 
              condicao.c = "  " + condicao.v + " = " + indicePipe + 
                           " < " + tamanhoPipe + ";\n";
              passo.c = passoPipeAtivo + ":\n" + 
                        indicePipe+ " = " + indicePipe + " + 1;\n"+
                        "x_"+pipeAtivo+" = "+$1.v+"["+indicePipe+"];"; 
              cmd.c = $2.c + $3.c;
              
              geraCodigoFor( &$$, inicio, condicao, passo, cmd );
              
              pipeAtivo = "";
          }
        ;

INI_PIPE : E
           { $$ = $1;
            indicePipe = "x_"+pipeAtivo;
             tamanhoPipe = $1.v;
             pipeAtivo =  $1.t.nome;
       passoPipeAtivo = geraLabel( "passo_pipe" ); }
   ;

INI_PIPE_ARRAY : _ID
        {
            $$ = $1;
            if( buscaVariavelTS( *ts, $1.v, &$$.t ) ){
              pipeAtivo = $$.t.nome;
              arraySortPipe = "x_array_"+pipeAtivo;
              tamanhoPipe = toStr($$.t.d1);
              string counter = geraTemp(Tipo("int"));
              indicePipe = counter;
              passoPipeAtivo = geraLabel( "passo_pipe" );
            }
            else
              erro("Array nao declarado."); 
        }    

PROCS : _PIPE PROC PROCS 
        { $$.c = $2.c + $3.c; }
      | _PIPE
        { $$ = Atributo(); }
      ;
      
PROC : _FILTER '[' E ']'
       { geraCodigoFilter( &$$, $3 ); }
      | _FIRSTN '[' E ']'
       { geraCodigoFirstN( &$$, $3 ); }
      | _LASTN '[' E ']'
       { geraCodigoLastN( &$$, $3 ); }
      | _SORT '[' _X ']'
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

              geraCodigoFor( &$$ , inicio1, condicao1, passo1, cmd1 );
        }
     ;
      
CONSOME : _FOREACH '[' CMD ']'
          { $$.c = $3.c; }
        ;
            
DECLVAR : DECLVAR ',' _ID
          { insereVariavelTS( *ts, $3.v, $1.t ); 
            geraDeclaracaoVariavel( &$$, $1, $3 ); }
        | TIPO _ID
          { insereVariavelTS( *ts, $2.v, $1.t ); 
            geraDeclaracaoVariavel( &$$, $1, $2 ); }
        | TIPO _ID '=' E
          { insereVariavelTS( *ts, $2.v, $1.t ); 
            geraDeclaracaoVariavelComAtribuicao( &$$, $1, $2, $4 );
          }
        ;

TIPO : TIPOSIMPLES
      | TIPOSIMPLES '[' _INT ']'
       { 
         $$ = $1;
         $$.t.nDim = 1;
         $$.t.d1 = toInt( $3.v ); 
         }
     | TIPOSIMPLES '[' _INT ']' '['_INT']'
       { 
         $$ = $1;
         $$.t.nDim = 2;
         $$.t.d1 = toInt( $3.v ); 
         $$.t.d2 = toInt( $6.v ); 
         }
        ;    

TIPOSIMPLES : _TK_INT
         | _TK_CHAR
            | _TK_BOOLEAN
            | _TK_DOUBLE
            | _TK_FLOAT
            | _TK_STRING
            ;
  
ATR : _ID '=' E 
      { geraCodigoAtribuicaoSemIndice( &$$, $1, $3 ); 
      }
    | _ID '[' E ']' '=' E 
          { geraCodigoAtribuicao1Indice( &$$, $1, $3, $6 ); }
    | _ID '[' E ']''[' E ']' '=' E 
          { geraCodigoAtribuicao2Indices( &$$, $1, $3, $6, $9 );}
    | _ID '[' E ']''[' E ']''[' E ']'  '=' E 
          { geraCodigoAtribuicao3Indices( &$$, $1, $3, $6, $9, $12 ); }
    ;

E : E _TK_MAIS E   
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_MENOS E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_VEZES E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_DIVIDIDO E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_RESTO E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_AND E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_OR E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_MENOR E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_MAIOR E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_MENORIGUAL E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_MAIORIGUAL E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_IGUAL E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _TK_DIFERENTE E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | _TK_NOT E
  	{ geraCodigoOperadorUnario( &$$, $1, $2); }
  | E '&' E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E '|' E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E '^' E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | '~' E
    { geraCodigoOperadorUnario( &$$, $1, $2); }
  | E _SHIFTL E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _SHIFTR E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | F
  ;

PARAM : PARAM ',' E
        { $$.c = $1.c + $3.c;
          $$.v = $1.v + ',' + $3.v; num_params_chamada++; listaTempChamada.push_back($3.t); }
      | E
        { $$ = $1; num_params_chamada = 1; listaTempChamada = list<Tipo>(); listaTempChamada.push_back($1.t); }
      |
        {}
      ;

F : _ID   
  { if( buscaVariavelTS( *ts, $1.v, &$$.t ) ) 
      $$.v = $1.v; 
    else
      erro( "Variavel nao declarada: " + $1.v );
  } 
  | _ID '(' PARAM ')'
  {
    if( buscaVariavelTS( ts_funcoes, $1.v, &$$.t ) ){
      list<Tipo> meus_params;
      if(buscaParamTS(ts_params, $1.v, &meus_params)){ 
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
        $$.c = $3.c;
        $$.v = $1.v + '(' + $3.v + ')';
    }else{ 
      erro( "Funcao nao declarada: "+ $1.v);
    }
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
       $$.t = Tipo( "boolean" ); }
  | _STRING 
    {  $$.v = $1.v; 
       $$.t = Tipo( "string" ); }
  | '(' E ')'  { $$ = $2; }
  | _X
    { if( pipeAtivo != "" )
        $$ = Atributo( "x_" + pipeAtivo, pipeAtivo ); 
      else
        erro( "Variavel 'x' so pode ser usada dentro de pipe" );
    }
  | _ID '[' E ']'
  {
    geraCodigoAcessoArray(&$$, $1, $3, Atributo(), Atributo(), 1);
  }
  | _ID '[' E ']' '[' E ']'
  {
    geraCodigoAcessoArray(&$$, $1, $3, $6, Atributo(), 2);
  }
  | _ID '[' E ']' '[' E ']' '[' E ']' // Esse caso só ocorre em Matriz de string
  {
    geraCodigoAcessoArray(&$$, $1, $3, $6, $9, 3);
  }
  ;
  

%%

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
      else if( id.t.nome == "float")
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
