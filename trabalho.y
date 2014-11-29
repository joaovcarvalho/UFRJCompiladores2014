%{
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
string geraLabel( string cmd);
string geraDeclaracaoTemporarias();

void insereVariavelTS( TS&, string nomeVar, Tipo tipo );
bool buscaVariavelTS( TS&, string nomeVar, Tipo* tipo );
void erro( string msg );
string toStr( int n );


void geraCodigoAtribuicao( Atributo* SS, Atributo& lvalue, const Atributo& rvalue );
void geraCodigoOperadorBinario( Atributo* SS, const Atributo& S1, const Atributo& S2, const Atributo& S3 );
void geraCodigoFuncaoPrincipal( Atributo* SS, const Atributo& cmds );
void geraCodigoIfComElse( Atributo* SS, const Atributo& expr, 
                                        const Atributo& cmdsThen,
                                        const Atributo& cmdsElse );
void geraCodigoIfSemElse( Atributo* SS, const Atributo& expr, 
                                        const Atributo& cmdsThen );

void geraDeclaracaoVariavel( Atributo* SS, const Atributo& tipo,
                                           const Atributo& id );

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

%nonassoc '<' '>'
%left '+' '-'
%left '*' '/'

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
            { $$ = $2; }
          ;

MAIN : _TK_MAIN _TK_IB CMDS _TK_FB
       { geraCodigoFuncaoPrincipal( &$$, $2 ); }
     ; 

CMDS  : CMD CMDS
       { $$.c = $1.c + $2.c; }
     |
       { $$ = Atributo(); }
     ;

CMD : ATR ';'
       { $$.c = $1.c; }
     | CMD_OUT ';'
       { $$.c = $1.c; }
     | CMD_IF ';'  
       { $$.c = $1.c; }
     | CMD_FOR ';'
       { $$.c = $1.c; }
     | CMD_WHILE ';'
       { $$.c = $1.c; }
     | CMD_DOWHILE ';'
       { $$.c = $1.c; }
     | CMD_SWITCH ';'
       { $$.c = $1.c; }
     | DECLVAR ';'
       { $$.c = $1.c; }

  
CMD_IF : _TK_IF '('E')' COD
           { geraCodigoIfSemElse( &$$, $3, $5 ); }
        | _TK_IF '('E')' COD _TK_ELSE COD
           { geraCodigoIfComElse( &$$, $3, $5, $7 ); }
        ;

CMD_OUT : _COUT COUT_EXPR
          { $$ = $2; }
        ;

COUT_EXPR : COUT_EXPR _SHIFTL E 
            { if( $3.t.nome == "int" )
                $$.c = $1.c + $3.c + 
                       "  printf( \"%d\" , " + $3.v + " );\n";
              else if( $3.t.nome == "string" )
                $$.c = $1.c + $3.c + 
                       "  printf( \"%s\" , " + $3.v + " );\n";}
          | { $$ = Atributo(); }
          ;

COD :  BLOCO
       { $$.c = $1.c; }
       | CMD
       { $$.c = $1.c; }
       ;

BLOCO : _TK_IB CMDS _TK_FB
        ;

BLOCOFUNC : _TK_IB CMDS _TK_RETURN _ID _TK_FB 
          | _TK_RETURN;
    
CASOS : _TK_CASE F ':' CMDS _TK_BREAK ';' CASOS
      | _TK_DEFAULT ':' CMDS
      |
        { $$.c = ""; }
    ;
  
CMD_FOR:  | _TK_FOR '('ATR ';' ATR ';' _TK_TQ E ')' COD
              {geraCodigoFor(&$$, $3, $8, $5, $10);}
          
          
CMD_WHILE:  | _TK_WHILE '(' E ')' COD
              { geraCodigoWhile( &$$, $3, $5); }
            ;
            
CMD_DOWHILE: | _TK_DO COD _TK_WHILE '(' E ')' ';'
               {geraCodigoDoWhile(&$$, $2, $5) ;}
             ;
             
CMD_SWITCH:  | _TK_SWITCH '(' _ID ')' _TK_IB CASOS _TK_FB
                    { if( !buscaVariavelTS( ts, $3.v, &$3.t ) ) {
                          erro( "Variavel nao declarada: " + $3.v );
                       }
                      else
                        geraCodigoSwitch(&$$, $3, $6);  
                    }
            ;
            
DECLVAR : DECLVAR ',' _ID
          { insereVariavelTS( ts, $3.v, $1.t ); 
            geraDeclaracaoVariavel( &$$, $1, $3 ); }
        | TIPO _ID
          { insereVariavelTS( ts, $2.v, $1.t ); 
            geraDeclaracaoVariavel( &$$, $1, $2 ); }
    | TIPO '[' E ']' _ID
      {

      }
        ;
    
PARAM : ',' TIPO _ID PARAM
      |
        { $$.c = ""; }
      ;
      
FUNCTION : TIPO _ID '(' TIPO _ID PARAM ')' BLOCOFUNC
         | _TK_VOID _ID '(' TIPO _ID PARAM ')' BLOCO
         | TIPO _ID '(' ')' BLOCOFUNC
         | _TK_VOID _ID '(' ')' BLOCO
         ;
    
TIPO : _TK_INT
     | _TK_CHAR
     | _TK_BOOLEAN
     | _TK_DOUBLE
     | _TK_FLOAT
     | _TK_STRING
     ;
  
ATR : _ID '=' E 
      { geraCodigoAtribuicao( &$$, $1, $3 ); }
    ;

ARRAY : _ID '[' E ']'

E : E _TK_MAIS E   
    { cout << "Expressao: " << $1.v << " - " << $2.v << " - " << $3.v << endl; geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
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
  | E '&' E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E '|' E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E '^' E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | '~' E
  | E _SHIFTL E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _SHIFTR E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E '>' E
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
  | _TK_NULL
  {

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

void geraCodigoAtribuicao( Atributo* SS, Atributo& lvalue, 
                                         const Atributo& rvalue ) {
  if( buscaVariavelTS( ts, lvalue.v, &lvalue.t ) ) {
    if( lvalue.t.nome == rvalue.t.nome ) {
      if( lvalue.t.nome == "string" ) {
        SS->c = lvalue.c + rvalue.c + 
                "  strncpy( " + lvalue.v + ", " + rvalue.v + ", " + 
                            toStr( MAX_STR - 1 ) + " );\n" +
                "  " + lvalue.v + "[" + toStr( MAX_STR - 1 ) + "] = 0;\n";
      }
      else
        SS->c = lvalue.c + rvalue.c + 
                "  " + lvalue.v + " = " + rvalue.v + ";\n"; 
    }
    else
      erro( "Expressao " + rvalue.t.nome + 
            " nao pode ser atribuida a variavel " +
            lvalue.t.nome );
    } 
    else
      erro( "Variavel nao declarada: " + lvalue.v );
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
          "  "+l_if_fim+":\n";
}

void geraCodigoIfSemElse( Atributo* SS, const Atributo& expr, 
                                        const Atributo& cmdsThen ) {
  *SS = Atributo();
  string l_if_true = geraLabel( "if_true");
  string l_if_fim = geraLabel( "if_fim");

  SS->c = expr.c + 
          "  if( " + expr.v + " ) goto " + l_if_true + ";\n" +
          "  goto " + l_if_fim + ";\n" +
          "  " + l_if_true + ":\n" + cmdsThen.c +
          "  " + l_if_fim + ":\n";
}

void geraCodigoFor( Atributo* SS, const Atributo& init,
                                  const Atributo& condicao,
                                  const Atributo& passo,
                                  const Atributo& cmds){

  if(condicao.t.nome != "bool")
    erro( "A condicao de teste deve ser Buliano: " + condicao.t.nome);

  *SS = Atributo();
  string forFim = geraLabel("for_fim");
  string forCond = geraLabel("for_cond");
  string valorCond = geraTemp( Tipo("bool"));

  SS->c = init.c 
          +forCond+": \n" +
          valorCond + " = !" + condicao.v + ";\n"+
          " if( " + valorCond + " ) goto "+forFim+";\n"+
          cmds.c + "\n" + passo.c+
          " goto "+forCond+";" +
          " "+forFim+":\n";
}

void geraCodigoWhile(Atributo* SS, const Atributo& condicao,
                                   const Atributo& cmds){

  if(condicao.t.nome != "bool")
    erro( "A condicao de teste deve ser Buliano: " + condicao.t.nome);
    
 // *SS = Atributo();
 // string inicioWhile = geraLabel("while_inicio"), fimWhile = geraLabel("while_fim");
 // string valorCond = geraTemp("bool");

 // SS->c = inicioWhile+": \n" +
 //        valorCond + " = !" + condicao.v + ";\n"+
 //        "if( "+ valorCond+" ) goto "+fimWhile+";\n"+
 //        cmds.c +
 //        " goto "+inicioWhile+";"+
 //        " "+fimWhile+": \n";
}

void geraCodigoDoWhile(Atributo* SS, const Atributo& cmds, 
                                     const Atributo& condicao){
  if(condicao.t.nome != "bool")
    erro( "A condicao de teste deve ser Buliano: " + condicao.t.nome);
}

void geraCodigoSwitch( ){
    
    
}

void geraDeclaracaoVariavel( Atributo* SS, const Atributo& tipo,
                                           const Atributo& id ) {
  SS->v = "";
  SS->t = tipo.t;
  if( tipo.t.nome == "string" ) {
    SS->c = tipo.c + 
           "char " + id.v + "["+ toStr( MAX_STR ) +"];\n";   
  }
  else {
    SS->c = tipo.c + 
            tipo.t.nome + " " + id.v + ";\n";
  }
}

void geraCodigoFuncaoPrincipal( Atributo* SS, const Atributo& cmds ) {
  *SS = Atributo();
  SS->c = "\nint main() {\n" +
           geraDeclaracaoTemporarias() + 
           "\n" +
           cmds.c + 
           "  return 0;\n" 
           "}\n";
}  

string geraDeclaracaoTemporarias() {
  string c;
  
  for( int i = 0; i < n_var_temp["bool"]; i++ )
    c += "  int temp_bool_" + toStr( i + 1 ) + ";\n";
    
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
  // SS->t = tipoResultado( S1.t, S2.v, S3.t );
  // SS->v = geraTemp( SS->t );

  // if( SS->t.nome == "string" ) {
  //   SS->c = S1.c + S3.c + 
  //           "\n  strncpy( " + SS->v + ", " + S1.v + ", " + 
  //                       toStr( MAX_STR - 1 ) + " );\n" +
  //           "  strncat( " + SS->v + ", " + S3.v + ", " + 
  //                       toStr( MAX_STR - 1 ) + " );\n" +
  //           "  " + SS->v + "[" + toStr( MAX_STR - 1 ) + "] = 0;\n\n";    
  // }
  // else
  //   SS->c = S1.c + S3.c + 
  //           "  " + SS->v + " = " + S1.v + " " + S2.v + " " + S3.v + ";\n";
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
  resultadoOperador["Indiviso+Indiviso"] = Tipo( "Indiviso" );
  resultadoOperador["Indiviso-Indiviso"] = Tipo( "Indiviso" );
  resultadoOperador["Indiviso*Indiviso"] = Tipo( "Indiviso" );
  resultadoOperador["Indiviso/Indiviso"] = Tipo( "Indiviso" );
  
  //op basicas: double e double
  resultadoOperador["Diade+Diade"] = Tipo("Diade");
  resultadoOperador["Diade-Diade"] = Tipo("Diade");
  resultadoOperador["Diade*Diade"] = Tipo("Diade");
  resultadoOperador["Diade/Diade"] = Tipo("Diade");
  
  //op basicas: float e float
  resultadoOperador["Irresoluto+Irresoluto"] = Tipo("Irresoluto");
  resultadoOperador["Irresoluto-Irresoluto"] = Tipo("Irresoluto");
  resultadoOperador["Irresoluto*Irresoluto"] = Tipo("Irresoluto");
  resultadoOperador["Irresoluto/Irresoluto"] = Tipo("Irresoluto");
  
  //op basicas: inteiro e double
  resultadoOperador["Indiviso+Diade"] = Tipo("Diade");
  resultadoOperador["Indiviso-Diade"] = Tipo("Diade");
  resultadoOperador["Indiviso*Diade"] = Tipo("Diade");
  resultadoOperador["Indiviso/Diade"] = Tipo("Diade");

  //op basicas: inteiro e float
  resultadoOperador["Indiviso+Irresoluto"] = Tipo("Irresoluto");
  resultadoOperador["Indiviso-Irresoluto"] = Tipo("Irresoluto");
  resultadoOperador["Indiviso*Irresoluto"] = Tipo("Irresoluto");
  resultadoOperador["Indiviso/Irresoluto"] = Tipo("Irresoluto");
  
  //op basicas: double e float
  resultadoOperador["Diade+Irresoluto"] = Tipo("Diade");
  resultadoOperador["Diade-Irresoluto"] = Tipo("Diade");
  resultadoOperador["Diade*Irresoluto"] = Tipo("Diade");
  resultadoOperador["Diade/Irresoluto"] = Tipo("Diade");
  
  // comparações : inteiro e inteiro
  resultadoOperador["Indiviso<Indiviso"] = Tipo( "Buliano" );
  resultadoOperador["Indiviso<=Indiviso"] = Tipo( "Buliano" );
  resultadoOperador["Indiviso>Indiviso"] = Tipo( "Buliano" );
  resultadoOperador["Indiviso>=Indiviso"] = Tipo( "Buliano" );
  resultadoOperador["Indiviso==Indiviso"] = Tipo( "Buliano" );
  resultadoOperador["Indiviso!=Indiviso"] = Tipo( "Buliano" );
  
  //comparações: double e double
  resultadoOperador["Diade<Diade"] = Tipo( "Buluano" );
  resultadoOperador["Diade<=Diade"] = Tipo( "Buliano" );
  resultadoOperador["Diade>Diade"] = Tipo( "Buliano" );
  resultadoOperador["Diade>=Diade"] = Tipo( "Buliano" );
  resultadoOperador["Diade==Diade"] = Tipo( "Buliano" );
  resultadoOperador["Diade!=Diade"] = Tipo( "Buliano" );
  
  //comparações float e float
  resultadoOperador["Irresoluto<Irresoluto"] = Tipo( "Buliano" );
  resultadoOperador["Irresoluto<=Irresoluto"] = Tipo( "Buliano" );
  resultadoOperador["Irresoluto>Irresoluto"] = Tipo( "Buliano" );
  resultadoOperador["Irresoluto>=Irresoluto"] = Tipo( "Buliano" );
  resultadoOperador["Irresoluto==Irresoluto"] = Tipo( "Buliano" );
  resultadoOperador["Irresoluto!=Irresoluto"] = Tipo( "Buliano" );
  
  //comparações : inteiro e double
  resultadoOperador["Indiviso<Diade"] = Tipo( "Buliano" );
  resultadoOperador["Indiviso<=Diade"] = Tipo( "Buliano" );
  resultadoOperador["Indiviso>Diade"] = Tipo( "Buliano" );
  resultadoOperador["Indiviso>=Diade"] = Tipo( "Buliano" );
  resultadoOperador["Indiviso==Diade"] = Tipo( "Buliano" );
  resultadoOperador["Indiviso!=Diade"] = Tipo( "Buliano" );
  
  //comparações : inteiro e float
  resultadoOperador["Indiviso<Irresoluto"] = Tipo( "Buliano" );
  resultadoOperador["Indiviso<=Irresoluto"] = Tipo( "Buliano" );
  resultadoOperador["Indiviso>Irresoluto"] = Tipo( "Buliano" );
  resultadoOperador["Indiviso>=Irresoluto"] = Tipo( "Buliano" );
  resultadoOperador["Indiviso==Irresoluto"] = Tipo( "Buliano" );
  resultadoOperador["Indiviso!=Irresoluto"] = Tipo( "Buliano" );
 
  //comparações : double e float
  resultadoOperador["Diade<Irresoluto"] = Tipo( "Buliano" );
  resultadoOperador["Diade<=Irresoluto"] = Tipo( "Buliano" );
  resultadoOperador["Diade>Irresoluto"] = Tipo( "Buliano" );
  resultadoOperador["Diade>=Irresoluto"] = Tipo( "Buliano" );
  resultadoOperador["Diade==Irresoluto"] = Tipo( "Buliano" );
  resultadoOperador["Diade!=Irresoluto"] = Tipo( "Buliano" );
  
  //concatenação
  resultadoOperador["Manifesto+Manifesto"] = Tipo( "Manifesto" );
  
  //operadores lógicos : bool e bool
  resultadoOperador["Buliano&&Buliano"] = Tipo("Buliano");
  resultadoOperador["Buliano||Buliano"] = Tipo("Buliano");
  resultadoOperador["!Buliano"] = Tipo("Buliano");
  
  //operadores bit a bit
  
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

Tipo tipoResultado() {

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
