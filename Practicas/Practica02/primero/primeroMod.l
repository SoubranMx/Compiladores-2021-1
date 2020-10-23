%option noyywrap
%{
    #include <stdio.h>
%}

digito [0-9]
letra [a-zA-Z]
letra_hex [a-fA-F]
hexa {digito}|{letra_hex}
hexadecimal 0x{hexa}{2}

decimal {digito}*"."{digito}+|{digito}+"."
exp [eE][+-]?{digito}+
notCientifica [+-]?({decimal}{exp}?|{digito}+{exp})[fF]

pointer "%pointer"
array "%array"
line "%line"
option "%option"
include "#include"
directivas {pointer}|{array}|{line}|{option}|{include}

identificador "@"({letra}|"-"|{digito}){5,32}
%%
comentario {/* Estrada Soubran Uriel Alejandro 312096568*/}
{hexadecimal}+ {printf("Encontre un hexadecimal %s\n",yytext);}
{notCientifica}+ {printf("Encontre un exponencial %s\n",yytext);}
{identificador}+ {printf("Encontre un identificador %s\n",yytext);}
{directivas}+ {printf("Encontre una directiva %s\n",yytext);}

%%

int main(){
    yylex();
}