#include <stdio.h>
// Macros extra: if, undef, __TIME__, __LINE__
/**
 * Estrada Soubran Uriel Alejandro
 * 3120996568
 * 
 */
//#define PI 3.141595

#if defined PI
    #undef PI
    #define PI 2
#elif !defined PI // No esta definido PI
    #include <math.h>
    #define PI M_PI
#endif

int main (void){

    #if defined PI <= 2
        printf("Hola, este programa debe decir el valor de PI si estuviera definido: %f\n", PI);
    #else
        printf("Hola, PI no esta definido, deberia decir math.pi %f\n", M_PI);
    #endif


    printf("Esta linea se encuentra en %s\n", __LINE__);

    printf("La fecha de hoy es: %s\n",__DATE__);

    printf("Y la hora es: %s",__TIME__);

    return 0;
}