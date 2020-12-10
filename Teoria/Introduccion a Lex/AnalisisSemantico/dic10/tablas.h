#ifndef TABLAS_H
#define TABLAS_H

struct _symbol{
    char id[32];
    int dir;
    int tipo;
    char var[20];
};

typedef struct _symbol sym;

struct _type{
    int id;
    char tipo[32];
    char tam;
    int elem;
    int tipoBase;
};

typedef struct _type type;


sym TS[100];
type TT[50];
int numSym = 0, numType = 0; //Contadores para saber cuantos simbolos y tipos tenemos en las tablas


int buscarTS(char *id);
int getTamTT(int id);
int insertarTT(char *tipo, int num, int base);
int insertarTS(char *id, int tipo, int dir, char var);

void printTT();
void printTS();

#endif