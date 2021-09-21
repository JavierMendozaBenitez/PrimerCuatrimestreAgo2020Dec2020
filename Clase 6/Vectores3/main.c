#include <stdio.h>
#include <stdlib.h>

#define TAM 5
//Cual es el mayor y en que posicion del usuario se ingreso
int main()
{
    int numeros[TAM];
    int mayor;
    int indiceMayor;

    for(int i = 0; i < TAM; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]);
    }

    for(int i = 0; i < TAM; i++)
    {
        if(i == 0 || numeros[i] >= mayor)
        {
            mayor =  numeros[i];
            indiceMayor = i;
        }
    }

    printf("El mayor numero ingresado es %d y se ingreso en la posicion ",mayor);

    for(int i = 0; i < TAM; i++)
    {
        if(numeros[i] == mayor)
        {
            printf("y %d ", i + 1);
        }
    }


    return 0;
}
