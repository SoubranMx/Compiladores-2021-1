#include "lexer.h"
#include <stdlib.h>
#include <string.h>

void init(char *name){
    yyin = fopen(name,"r");
    if(!yyin){
        printf("El archivo no se encontro\n");
        exit(-1);
    }

    c = fgetc(yyin);
    // Debemos referenciar memoria para usar un apuntador

    //yytext almacena lo que se va leyendo
    yytext = (char*) malloc (sizeof(char));
}

int yylex(){
    //necesitamos una var. que guarde el edo actual
    int edo = 0;
    char cc[2];
    cc[1] = '\0'
    strcpy(yytext,""); //copiar la cadena vacia

    //TODO(2) Comprobar que encontro fin de archivo y retornar la constante para fin de archivo.
    while(true){ //cuando reconoce el token, se acaba el ciclo
        //Si la transicion esta definida...
        if (estados[edo][chartoint(c)] != -1){
            //transicion
            edo = estados[edo][chartoint(c)];
            cc[0] = c;
            strcat(yytext,cc);
            c = fgetc(yyin); //leemos sig caracter
        }else{
            // Cuando no esta definida la transicion
            // 2 opciones:
            // 1. El estado actual es aceptacion, y la transicion con otro caracter no esta definida.
            // Significa que acabmos de leer un token, el otro caracter es el inicio de un nuevo token.

            if( accep[edo]){
                return 1; //por el momento 1 aceptada, 0 no aceptada
            }else{
                return -1; // -1 es un error.
            }
        }
    }
    
}

//TODO(4) Modificar la funcion para la columna de los espacios en blanco
int chartoint(char d){
    if(d=='a') return 0;
    if(d=='b') return 1;
    return 2;
}


int main(int argc, char **argv){
    if(argc<2){
        printf("Falta nombre de archivo\n");
        return -1;
    }
    init(argv[1]);  //argv[0] es el nombre del programa, 1 es el primer argumento mandado.
    
    //
    int token = yylex();
    //TODO(3) Programar un ciclo que permita leer todos los tokens
    // de un archivo. Es decir, mandar a llamar yylex varias veces
    // hasta que yylex retorne la constante de fin de archivo.
    if(token != -1){
        printf("Encontre una cadena %s\n",yytext);
    }
    fclose(yyin);
    free(yytext);
}