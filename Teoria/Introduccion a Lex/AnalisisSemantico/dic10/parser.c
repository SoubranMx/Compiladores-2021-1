#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

int actual; //token actual
int dir = 0; //variable global para dir
VALUE yylval;


void eat(int t){
    if(actual == t)
        actual = yylex();
    else
    {
        error("Error de sintaxis");
    }
    
}

void error(char *msg){
    printf("%s\n",msg);
}

void D(){
    int tipo;
    if(actual == INT || actual == FLOAT){
        tipo = T();
        L(tipo);
        eat(COMA);
        D();
    }
}

int T(){
    int tipo = B();
    tipo = C(tipo);
    return tipo;
}

int B(){
    if(actual == INT){
        eat(INT);
        return 0;
    }
    if(actual == FLOAT){
        eat(FLOAT);
        return 1;
    }
    else{
        error("Error de sintaxis");
        return -1;
    }
}

int C(int base){
    if(actual == LCOR){
        eat(LCOR);
        int val = atoi(yylval.num.val);
        eat(NUM);
        eat(RCOR);
        int tipo = C(base);
        return insertarTT('array', val, tipo);
    }
    else{
        return base;
    }
    
}

void L(int tipo){
    if(actual == ID){
        if(!buscarTS(yylval.id)){
            insertarTS(yylval.id, tipo, dir, 'var');
            dir += getTamTT(tipo);
            eat(ID);
            LP(tipo);
        }else{
            error("Error semantico");
        }
    }else{
        error("Error de sintaxis");
    }    
}

void LP(int tipo){
    if(actual == COMA){
        eat(COMA);
        if(actual == ID){
            if(!buscarTS(yylval.id)){
                insertarTS(yylval.id, tipo, dir, 'var');
                dir += getTamTT(tipo);
                eat(ID);
                LP(tipo);
            }else{
                error("Error semantico");
            }
        }else{
            error("Error de sintaxis");
        }
    }
}
