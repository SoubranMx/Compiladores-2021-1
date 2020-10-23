#include <stdio.h>
/**
 * Estrada Soubran Uriel Alejandro
 * 3120996568
 * 
 */
#define PI 3.14159265535897

#ifdef PI
#define area(r) (PI * r * r)
#else
#define area(r) (3.1416 * r * r)
#endif

/**
 * Compiladores
 * 
 */

int main (void){
    printf("Hola Mundo! \n");
    float mi_area = area(3); // soy un comentario ...
    printf("Resultado: %f\n", mi_area);
    return 0;
    
}
