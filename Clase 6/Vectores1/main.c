#include <stdio.h>
#include <stdlib.h>

#define TAM 5
//pedir 5 numeros y mostrar el promedio
int main()
{
    int numeros[TAM];
    float promedio;
    int acu;

    acu = 0;

    for(int i=0; i<TAM; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]);
    }
    for(int i=0; i<TAM; i++)
    {
        acu += numeros[i];
    }
    promedio = (float) acu / TAM;
    printf("\nEl promedio es: %.2f\n", promedio);
    //int numeros [5] = {21, 45, 32, 46, 78};//declaracion explicita
    //int numeros [5] = {0};
    //int x = 20;

    //numeros[5] = 100;
   /* for(int i=0; i < 5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]);
    }*/
    /*for(int i = 0; i < 6; i++)
    {
        printf("\n%d", numeros[i]);
    }*/

    printf("\n\n");

    //printf("x vale: %d\n",x);

    return 0;
}

