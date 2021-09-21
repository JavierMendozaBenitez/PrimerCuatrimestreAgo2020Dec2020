#include <stdio.h>
#include <string.h>
#include "comida.h"

void mostrarComida(eComida food)
{
    printf(" %d      %20s  %.2f\n", food.id, food.descripcion, food.precio);
}

int mostrarComidas(eComida foods[], int tam)
{
    int error = 1;
    if(foods != NULL && tam > 0)
    {
        printf("******Listado Comidas*****\n");
        printf("---------------------------------\n");
        printf("    Id        Descripcion\n");
        for(int i = 0; i<tam; i++)
        {
            mostrarComida(foods[i]);
        }
        printf("\n\n");
        error = 0;
    }

    return error;
}

int validarIdComida(eComida food[], int tam, int id)
{
    int esValido = 0;
    if(food != NULL && tam > 0 && id >= 1000)
    {
        for(int i=0; i < tam; i++)
        {
            if(food[i].id == id)
            {
                esValido = 1;
                break;
            }
        }
    }


    return esValido;
}

int obtenerDescripcionComida(eComida foods[], int tam, int id, char descripcion[])
{
    int error = 1;

    if(foods != NULL && tam > 0 && id >=1000 && descripcion != NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(foods[i].id == id)
            {
                strcpy(descripcion, foods[i].descripcion);
                error = 0;
                break;
            }
        }
    }

    return error;
}
