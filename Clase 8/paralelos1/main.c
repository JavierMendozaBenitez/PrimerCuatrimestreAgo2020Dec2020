#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarVectorEnteros(int vec[], int tam);

int main()
{
    int x[TAM];
    int y[TAM];
    int z[TAM];

    for(int i=0; i < TAM; i++)
    {
        printf("Ingrese el valor para x: ");
        scanf("%d",&x[i]);//guarda en el indice i de x lo que se ingresa
        printf("Ingrese el valor para y: ");
        scanf("%d",&y[i]);

        z[i] = x[i] + y[i];
    }

    mostrarVectorEnteros(x, TAM);
    mostrarVectorEnteros(y, TAM);
    mostrarVectorEnteros(z, TAM);

    return 0;
}
void mostrarVectorEnteros(int vec[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        printf("%d", vec[i]);

    }
    printf("\n\n");
}
