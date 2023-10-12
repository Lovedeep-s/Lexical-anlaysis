s[ ]
%%
[ ]([ ])* { /* Pattern for recognizing multiple spaces */
fprintf(yyout," ");
}
([ ])*(\n)([ ])* { /* spaces followed by newline followed by
spaces */
fprintf(yyout," ");
}
%%
int yywrap() {
return 1; // Indicate the end of input
}
int main()
{

yyin = fopen("text1.txt","r");
yyout = fopen("text2.txt","w");
yylex();
return 0;
}