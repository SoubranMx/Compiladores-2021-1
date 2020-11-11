%{
    #include <stdio.h>


    typedef struct _token{
        int clase;
        char valor[50];
    } token;

    #define YY_DECL token yylex (void)

    token nuevo(int clase, char* valor);

%}

%option yylineno

letra [a-zA-Z]
digito[0-9]
id {letra}({letra}|{digito})*

%%
[ \t\n\r\v] {/*Ignorar espacios en blanco*/}

int { return nuevo(1, yytext);}
float { return nuevo(2, yytext);}
double { return nuevo(3, yytext);}
char { return nuevo(4, yytext);}
short { return nuevo(5, yytext);}
<<EOF>> {return nuevo(0,"");}
{id} {return nuevo(6, yytext);}

. {printf("Error lexico %s",yytext); return nuevo(-1, yytext);}

%%

int yywrap(){
    return 1;
}


token nuevo (int clase, char* valor){
    token t;
    t.clase = clase;
    strcpy(t.valor, valor);
    return t;
}

int main (int argc, char **argv){
    FILE *file;
    if(argc < 2){
        printf("No se especifico el archivo\n");
        return -1;
    }

    file = fopen(argv[1], "r");
    if (!file){
        printf("No puede abrir el archivo: %s\n",argv[1]);
        return -1;
    }

    

    token t = yylex();
    token f = nuevo(0,"");

    while(t.clase != f.clase){
        printf("Encontre: <%d, %s>\n",t.clase, t.valor);
        t = yylex();
    }

    return 0;
}