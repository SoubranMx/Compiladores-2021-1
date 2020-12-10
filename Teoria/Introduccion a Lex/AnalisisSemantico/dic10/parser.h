#ifndef PARSER_H
#define PARSER_H

#include "tablas.h" //Definir tabla de simbolos y tabla de tipos
#include "tokens.h"

void D();
int T();    //Por ser atributo sintetizado
int B();
int C(int base);
void L(int tipo);
void LP(int tipo);

void eat(int t);    //??
void error(char *msg);

#endif