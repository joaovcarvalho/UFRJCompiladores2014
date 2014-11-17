DELIM   [\t ]
LINHA   [\n]
NUMERO  [0-9]
LETRA   [A-Za-z_]
INT     {NUMERO}+
DOUBLE  {NUMERO}+("."{NUMERO}+)
FLOAT   {DOUBLE}'f'
CHAR    \'[^\n]\'
BOOLEAN (Veridico|Equivoco)
ID      {LETRA}({LETRA}|{NUMERO})*
STRING  \"[^"\n]*\"
IF      Na_hipotese_de
ELSE    Salvo
FOR     Seja_qual_for
TQ	    Tal_que
DO      Realize
WHILE   Ao_passo_que
SWITCH  Assemelhe
CASE    Sendo
BREAK   Aborta
IBLOCO  Preludio
FBLOCO	Epilogo
DEFAULT	Padrao
RETURN  Restitua
NULL    Inexistente

%%

{LINHA}    { nlinha++; }
{DELIM}    {}

{IF}        { return _TK_IF; }
{ELSE}      { return _TK_ELSE; }
{FOR}       { return _TK_FOR; }
{TQ}	    { return _TK_TQ; }
{DO}        { return _TK_DO; }
{WHILE}     { return _TK_WHILE; }
{SWITCH}    { return _TK_SWITCH; }
{CASE}      { return _TK_CASE; }
{BREAK}     { return _TK_BREAK; }
{DEFAULT}   { return _TK_DEFAULT;}

{IBLOCO}	{ return _TK_IB;}
{FBLOCO}	{ return _TK_FB;}
{RETURN}  { return _TK_RETURN;}
{NULL}    { return _TK_NULL;}

"Indiviso"	{  yylval = Atributo( "", yytext ); return _TK_INT; }
"Diade"		{  yylval = Atributo( "", yytext ); return _TK_DOUBLE; }
"Irresoluto"	{  yylval = Atributo( "", yytext ); return _TK_FLOAT; }
"Grafema"	{  yylval = Atributo( "", yytext ); return _TK_CHAR; }
"Booliano"	{  yylval = Atributo( "", yytext ); return _TK_BOOLEAN; }
"Manifesto"	{  yylval = Atributo( "", yytext ); return _TK_STRING; }
"Devoluto"      {  yylval = Atributo( "", yytext ); return _TK_VOID; }

"Mais"          { return _TK_MAIS; }
"Menos"         { return _TK_MENOS; }
"Sobre"         { return _TK_DIVIDIDO; }
"Vezes"         { return _TK_VEZES; }
"Remanescente"  { return _TK_RESTO; }
"Bem como"      { return _TK_AND; }
"Ora"           { return _TK_OR; }
"Reves"		{ return _TK_NOT; }

"Superior a"                { return _TK_MAIOR; }
"Inferior a"                { return _TK_MENOR; }
"Superior ou equivalente a" { return _TK_MENORIGUAL; }
"Inferior ou equivalente a" { return _TK_MAIORIGUAL; }
"Equivalente a"             { return _TK_IGUAL; }
"Divergente a"		    { return _TK_DIFERENTE; }

"<<" 		{  yylval = Atributo( yytext ); return _SHIFTL; }
">>" 		{  yylval = Atributo( yytext ); return _SHIFTR; }

"Exclame"	{  yylval = Atributo( yytext ); return _PRINTF; }
"Averigue"	{  yylval = Atributo( yytext ); return _SCANF; }

{INT}      { yylval = Atributo( yytext ); return _INT; }
{DOUBLE}   { yylval = Atributo( yytext ); return _DOUBLE; }
{FLOAT}    { yylval = Atributo( yytext ); return _FLOAT; }
{CHAR}     { yylval = Atributo( yytext ); return _CHAR; }
{BOOLEAN}  { yylval = Atributo( yytext ); return _BOOLEAN; }
{STRING}   { yylval = Atributo( yytext ); return _STRING; }
{ID}       { yylval = Atributo( yytext ); return _ID; }

.          { yylval = Atributo( yytext ); return *yytext; }

%%
