%{
#include <stdio.h>
%}

%token NUMBER
%left '+' '-'
%left '*' '/'

%%

input: /* empty */
     | input line
     ;

line: '\n'
    | exp '\n' { printf("Result: %d\n", $1); }
    ;

exp: exp '+' exp   { $$ = $1 + $3; }
   | exp '-' exp   { $$ = $1 - $3; }
   | exp '*' exp   { $$ = $1 * $3; }
   | exp '/' exp   { if ($3 != 0) $$ = $1 / $3; else yyerror("Division by zero"); }
   | '(' exp ')'    { $$ = $2; }
   | NUMBER        { $$ = atoi(yytext); }
   ;

%%

int main() {
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}

int yywrap() {
    return 1;
}
