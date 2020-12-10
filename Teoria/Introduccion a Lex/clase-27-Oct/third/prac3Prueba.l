%{
    #include <stdio.h>

%}
%option nowarn
%option yylineno

%%
[a-z] {printf("%c", yytext[0] - 'a' + 'A' );}
\n  {printf("%s",yytext);}
.   {printf("%s",yytext);}

%%
int main(){
    yylex();
}