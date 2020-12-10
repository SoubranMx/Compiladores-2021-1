#include <stdio.h>
#include <string.h>
#include "tablas.h"

int buscarTS(char *id){
    for(int i=0; i <= numSym; i++){
        if(strcmp(TS[i].id, id) == 0){
            return 1;
        }
    }
    return 0;
}

int getTamTT(int id){
    return TT[id].tam;
}

int insertarTT(char *tipo, int num, int base){
    TT[numType].id = numType;
    strcpy(TT[numType].tipo, tipo);
    TT[numType].tam = num * getTamTT(base);
    TT[numType].tipoBase = base;
    numType++;
    return numType-1;
}

int insertarTS(char *id, int tipo, int dir, char var){
    strcpy(TS[numSym].id,id);
    TS[numSym].tipo = tipo;
    TS[numSym].dir = dir;
    strcpy(TS[numSym].var, var);
    return 1;
}

printTT(){
    print("Tabla de Tipos\n")
    for(int i=0; i <= numType ; i++){
        print("")
    }
}