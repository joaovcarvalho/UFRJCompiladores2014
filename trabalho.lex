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
ELSE    Salvo
DO      Realize
SWITCH  Assemelhe
CASE    Sendo
BREAK   Aborta
IBLOCO  Preludio
FBLOCO	Epilogo
DEFAULT	Padrao
RETURN  Restitua
NULL    Inexistente
MAIN 	Primacial
COMMENT "//".*

%%

{LINHA}    	{ nlinha++; }
{DELIM}    	{}
{COMMENT}	{}

{MAIN}				  {  yylval = Atributo(  yytext ); return _TK_MAIN; }
"Na hipotese de"      {  yylval = Atributo(  yytext ); return _TK_IF; }
{ELSE}      		  {  yylval = Atributo(  yytext ); return _TK_ELSE; }
"Seja qual for"       {  yylval = Atributo(  yytext ); return _TK_FOR; }
"Tal que"	    	  {  yylval = Atributo(  yytext ); return _TK_TQ; }
"Ao passo que"    	  {  yylval = Atributo(  yytext ); return _TK_WHILE; }

"=>"		{  yylval = Atributo( yytext ); return _PIPE; }
".."		{  yylval = Atributo( yytext ); return _2PTS; }

"Intervalo"	{ yylval = Atributo( yytext ); return _INTERVALO; }
"Segregue"	{ yylval = Atributo( yytext ); return _FILTER; }
"EmCompletude"	{ yylval = Atributo( yytext ); return _FOREACH; }
"X"		{ yylval = Atributo( yytext ); return _X; }

{DO}        {  yylval = Atributo(  yytext ); return _TK_DO; }
{SWITCH}    {  yylval = Atributo( yytext ); return _TK_SWITCH; }
{CASE}      {  yylval = Atributo(  yytext ); return _TK_CASE; }
{BREAK}     {  yylval = Atributo(  yytext ); return _TK_BREAK; }
{DEFAULT}   {  yylval = Atributo(  yytext ); return _TK_DEFAULT;}

{IBLOCO}	{  yylval = Atributo( yytext ); return _TK_IB;}
{FBLOCO}	{  yylval = Atributo( yytext ); return _TK_FB;}
{RETURN}  {  yylval = Atributo( yytext ); return _TK_RETURN;}
{NULL}    {  yylval = Atributo( yytext ); return _TK_NULL;}

"Indiviso"	{  yylval = Atributo( "", "int" ); return _TK_INT; }
"Diade"		{  yylval = Atributo( "", "double" ); return _TK_DOUBLE; }
"Irresoluto"	{  yylval = Atributo( "", "float" ); return _TK_FLOAT; }
"Grafema"	{  yylval = Atributo( "", "char" ); return _TK_CHAR; }
"Booliano"	{  yylval = Atributo( "", "boolean" ); return _TK_BOOLEAN; }
"Manifesto"	{  yylval = Atributo( "", "string" ); return _TK_STRING; }

"Devoluto"      {  yylval = Atributo( yytext ); return _TK_VOID; }
"Mais"          {  yylval = Atributo( "+" ); return _TK_MAIS; }
"Menos"         {  yylval = Atributo( "-" ); return _TK_MENOS; }
"Sobre"         {  yylval = Atributo( "/" ); return _TK_DIVIDIDO; }
"Vezes"         {  yylval = Atributo( "*" ); return _TK_VEZES; }
"Remanescente"  {  yylval = Atributo( "%" ); return _TK_RESTO; }
"Bem como"      {  yylval = Atributo( "&&" ); return _TK_AND; }
"Ora"           {   yylval = Atributo( "||" );return _TK_OR; }
"Reves"		{  yylval = Atributo( "", "!" ); return _TK_NOT; }

"Superior a"                {  yylval = Atributo( ">" ); return _TK_MAIOR; }
"Inferior a"                {  yylval = Atributo( "<" ); return _TK_MENOR; }
"Superior ou equivalente a" {  yylval = Atributo( ">=" ); return _TK_MENORIGUAL; }
"Inferior ou equivalente a" {  yylval = Atributo( "<=" ); return _TK_MAIORIGUAL; }
"Equivalente a"             {  yylval = Atributo( "==" ); return _TK_IGUAL; }
"Divergente a"		    {  yylval = Atributo( "!=" ); return _TK_DIFERENTE; }

"<<" 		{  yylval = Atributo( yytext ); return _SHIFTL; }
">>" 		{  yylval = Atributo( yytext ); return _SHIFTR; }

"Exclame"	{  yylval = Atributo( yytext ); return _COUT; }
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
