%{
    #include "y.tab.h"
%}

%%

[ \t\r\n]       ; // whitespaces


[-+<>\[\]\.,]   { yylval = *yytext; return OPERATOR; }
.               ; // everything else is comment

%%
