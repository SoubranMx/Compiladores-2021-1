#ifndef TOKENS_H
#define TOKENS_H

#define ID      1001
#define LCOR    1002
#define RCOR    1003
#define COMA    1004
#define PYC     1005
#define NUME    1006
#define INT     1007
#define FLOAT   1008

typedef union _value{
    char id[32];
    struct{
        int tipo;
        char val[100];
    } num;
} VALUE;

extern VALUE yylval;    //

#endif