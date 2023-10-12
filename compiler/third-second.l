s[ ]

%%
[ ]([ ])* {fprintf(yyout," ");}
([ ])*(\n)([ ])* { fprintf(yyout," ");}

\/\/(.*) {fprintf(yyout," ");}
\/\*(.*\n)*.*\*\/ { fprintf(yyout," ");}



%%
int yywrap() {
return 1; // Indicate the end of input
}
int main()
{

yyin = fopen("t1.c","r");
yyout = fopen("t2.c","w");
yylex();
return 0;
}