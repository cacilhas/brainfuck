%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "bfapi.h"
    #include "y.tab.h"

    FILE *yyin;
%}

%token OPERATOR

%%

program
    : statement program
    |   { bf_perform(); }
    ;

statement
    : OPERATOR  { bf_add_operator($1); }
    ;

%%


int main(int argc, char *argv[]) {
    if (argc == 2)
        yyin = fopen(argv[1], "r");
    yyparse();
    if (argc == 2)
        fclose(yyin);
    return EXIT_SUCCESS;
}


void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
    exit(EXIT_FAILURE);
}
