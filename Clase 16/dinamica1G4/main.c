#include <stdio.h>
#include <stdlib.h>


int mostrarEnteros(int* vec, int tam);

int main()
{
    int tam = 5;
    int* numeros = (int*)malloc(sizeof(int)*tam);//reservas 5 lugares para un array
    int* aux = NULL;

    for(int i=0; i<tam; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", numeros+i);
    }

    mostrarEnteros(numeros, tam);

    aux = (int*) realloc(numeros, sizeof(int)*10);//el total que quiero a partir de esta ubicacion
    if(aux != NULL)
    {
        numeros = aux;
        aux = NULL;
        tam += 5;
        printf("Vector redimensionado con exito!!!\n\n");
    }

    for(int i=5; i < tam; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", numeros+i);
    }

    mostrarEnteros(numeros, tam);

    numeros = (int*) realloc(numeros, sizeof(int)* 6);

    tam -= 4;
    printf("Vector reducido a tam 6!!!\n");

    mostrarEnteros(numeros, tam);

    free(numeros);
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
