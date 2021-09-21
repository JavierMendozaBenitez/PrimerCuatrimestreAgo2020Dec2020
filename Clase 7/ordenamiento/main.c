#include <stdio.h>
#include <stdlib.h>
#define TAM 5
void mostrarEnteros(int x[], int tam);
void ordenarEnteros(int x[], int tam, int criterio);// 1 ascendente, 0 descendente

int main()
{
    int vec[5] = {4, 2, 7, 1, 3};
    int aux;

    mostrarEnteros(vec, TAM);

    ordenarEnteros(vec, TAM, 0);

    mostrarEnteros(vec, TAM);

    for(int i=0; i < TAM -1; i++)
    {
        for(int j = i +1; j < TAM; j++)
        {
            if(vec[i] > vec[j])
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }

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

void ordenarEnteros(int x[], int tam)
{
    int aux;
    for(int i=0; i < tam -1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(x[i] > x[j])
            {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }
        }
    }
}




/*int x = 10;
int y = 5;
int aux;

aux = x;
x = y;

printf(" x, y aux %d, %d%, %d",x,y,aux);*/
