#ifndef LEXER_H
#define LEXER_H
#include <stdio.h>
#include <stdbool.h>

//TODO(1) definir una constante para representar el fin de archivo.
char  *yytext;
FILE *yyin;
char c;

// A = 0, B = 1, C = 2, D = 3
// -1 es el edo de error, por si llega cualquier otra cosa dif. de a y b
int estados[5][4] = {
    {1, 0, -1, 4},
    {1, 2, -1, -1},
    {1, 3, -1, -1},
    {1, 0, -1, -1},
    {-1, =1, -1, 4}
};

bool accep[4] = {false, false, false, true};

int yylex();
void init(char *name);

#endif
