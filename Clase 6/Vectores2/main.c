#include <stdio.h>
#include <stdlib.h>

#define TAM 6

/*declarar vector de enteros de tamaño 6 (0 a 5).
Pedir 5 numeros y acumular el total de los numeros
en la ultima posición.
Al finalizar mostrar el array completo.*/
void mostraVectorEnteros(int vec[], int tam);
int main()
{
    int numeros[TAM] = {0};

    //numeros[5] = 0;

    for(int i = 0; i < TAM -1; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]);
        numeros[5] += numeros[i];
    }

    mostraVectorEnteros(numeros, TAM);

    return 0;
}

void mostraVectorEnteros(int vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("\n%d", vec[i]);
    }

    printf("\n\n");
}
