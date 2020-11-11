%{
    #include <stdio.h>
    #include <string.h>


    void guardar_binario(void);
    void suma_print(void);
    int conversion(char *cadenaBinaria, int len);
    int suma = 0;

%}
%option noyywrap
%option nowarn
%option yylineno

digito  [0-1]
binario 0[bB]{digito}+
termino [sS][uU][mM][aA][rR]
%%
{binario}+  {guardar_binario();}
{termino}   {suma_print();}
.           {printf("Error, no es un numero binario valido.\n");}

%%

int main(){
    printf("Escriba cadenas binarias de modo que '0bxxxxx' donde x sea 1 o 0, minimo 1 digito.\nPara sumar, teclee \"sumar\" \n");
    yylex();
}

void guardar_binario(){
    char *binario = yytext;
    int len = 0;
    binario = strdup(binario+2);
    len = strlen(binario);
    printf("Guardado %s\n", binario);
    suma += conversion(binario,len);

    return;
};

void suma_print(void){
    printf("El valor sumado es: %d\n",suma);
    suma = 0;
    return;
}

int conversion(char *cadenaBinaria, int len) {
  int decimal = 0;
  int multiplicador = 1;
  char caracterActual;
  for (int i = len - 1; i >= 0; i--) {
    caracterActual = cadenaBinaria[i];
    if (caracterActual == '1') {
      decimal += multiplicador;
    }
    multiplicador = multiplicador * 2;
  }
  return decimal;
}