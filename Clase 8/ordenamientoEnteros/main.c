#include <stdio.h>
#include <stdlib.h>
#include "prueba.h"
#define TAM 5
#define ASC 1
#define DESC 0
void mostrarEnteros(int x[], int tam);
void ordenarEnteros(int x[], int tam, int criterio);// 1 ascendente, 0 descendente
void swap(int* a, int* b);

int main()
{
    int vec[TAM] = {4, 2, 7, 1, 3};
    int aux;

    mostrarEnteros(vec, TAM);

    ordenarEnteros(vec, TAM, DESC);

    mostrarEnteros(vec, TAM);

    return 0;
}

void mostrarEnteros(int x[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n\n");
}

void ordenarEnteros(int x[], int tam, int criterio)
{
    for(int i=0; i < tam -1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if((x[i] > x[j] && criterio) || (x[i] < x[j] && !criterio))
            {
                swap(&x[i], &x[j]);
            }
        }
    }
}

void swap(int* a, int* b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}


/*int x = 10;
int y = 5;
int aux;

aux = x;
x = y;

printf(" x, y aux %d, %d%, %d",x,y,aux);*/
