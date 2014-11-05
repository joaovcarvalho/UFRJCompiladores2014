DELIM   [\t ]
LINHA   [\n]
NUMERO  [0-9]
LETRA   [A-Za-z_]
INT     {NUMERO}+
DOUBLE  {NUMERO}+("."{NUMERO}+)
ID      {LETRA}({LETRA}|{NUMERO})*


%%

{LINHA}    { nlinha++; }
{DELIM}    {}

{ID}       { yylval.c = ""; yylval.t = ""; yylval.v = yytext; return _ID; }
{INT}      { yylval.c = ""; yylval.t = ""; yylval.v = yytext; return _CTE_INT; }
{DOUBLE}   { yylval.c = ""; yylval.t = ""; yylval.v = yytext; return _CTE_DOUBLE; }

.          { yylval.c = ""; yylval.t = ""; yylval.v = yytext; return *yytext; }

%%

 


