%{
    #include "y.tab.h"
%}

%%


[-+<>\[\]\.,]   { yylval = *yytext; return OPERATOR; }
.               ; // everything else is comment

%%
