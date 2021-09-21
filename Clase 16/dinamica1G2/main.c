#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int mostrarEnteros(int* vec, int tam);

int main()
{
    int numeros[TAM];
    int* numerosD = (int*)malloc(sizeof(int)*TAM);//reservas 5 lugares para un array

    for(int i=0; i<TAM; i++)
    {
        printf("Ingrese un numero (estatico): ");
        scanf("%d", &numeros[i]);
    }

    for(int i=0; i<TAM; i++)
    {
        printf("Ingrese un numero (dinamico): ");
        scanf("%d", numerosD+i);
    }

    mostrarEnteros(numeros, TAM);
    mostrarEnteros(numerosD, TAM);

    /*for(int i=0; i<TAM; i++)
    {
        printf("%d", numeros[i]);
    }

    printf("\n\n");

    for(int i=0; i<TAM; i++)
    {
        printf("%d", *(numerosD+i));
    }*/
    //numeros[3] = 8;
    //numerosD[3] = 8;//es lo mismo de arriba, es notacion vectorial, no hace falta * porque ya es un puntero

    //printf("%d\n", numeros[3]);
    //printf("%d\n", numerosD[3]);

    //printf("Ingrese un numero: ");
    //scanf("%d", &numeros[3]);//aritmerica de vectores
    //scanf("%d", numeros + 3);//aritmetica de punteros


    //printf("%d", numeros[3]);//aritmerica de vectores
    //printf("%d", *(numeros+3));/aritmetica de punteros

    free(numerosD);
    return 0;
}

int mostrarEnteros(int* vec, int tam)
{
    int error = 1;
    if(vec !=NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            printf("%d", *(vec + i));
        }
        printf("\n\n");

        error = 0;
    }
    return error;
}
