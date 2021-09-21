#include <stdio.h>
#include <stdlib.h>
#define TAM 5

//void mostrarEnteros(int vec[], int tam);
void mostrarEnterosP(int* vec, int tam);
void cargarEnteros(int* vec, int tam);
void mostrarCaracteres(char* vec, int tam);

int main()
{
    int numeros[TAM];//= {3, 5, 8, 1, 6};
    char sexos[TAM] = {'f', 'm', 'm', 'f', 'f'};

    //cargarEnteros(numeros, TAM);

    //mostrarEnterosP(numeros, TAM);
    //mostrarEnteros(numeros, TAM);

    mostrarCaracteres(sexos, TAM);

    return 0;
}

void mostrarEnterosP(int* vec, int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%d ", *(vec + i));
    }
    printf("\n\n");
}

/*void mostrarEnteros(int vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n\n");
}*/

void cargarEnteros(int* vec, int tam)
{
    for(int i=0; i < tam; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", vec + i);
    }
}

void mostrarCaracteres(char* vec, int tam)
{
    for(int i=0; i < tam; i++)
    {
        printf("%c ", *(vec + i));
    }
    printf("\n\n");
}
