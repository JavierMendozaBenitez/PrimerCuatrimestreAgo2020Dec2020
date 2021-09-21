#include <stdio.h>
#include "deporte.h"

void mostrarDeporte(eDeporte sport)
{
    printf(" %d      %20s\n", sport.id, sport.descripcion);
}
int mostrarDeportes(eDeporte sports[], int tam)
{
    int error = 1;
    if(sports != NULL && tam > 0)
    {
        printf("******Listado Deportes*****\n");
        printf("---------------------------------\n");
        printf("    Id        Descripcion\n");
        for(int i = 0; i<tam; i++)
        {
            mostrarDeporte(sports[i]);
        }
        printf("\n\n");
        error = 0;
    }

    return error;
}

int validarIdDeporte(eDeporte sports[], int tam, int id)
{
    int esValido = 0;
    if(sports != NULL && tam > 0 && id >= 1000)
    {
        for(int i=0; i < tam; i++)
        {
            if(sports[i].id == id)
            {
                esValido = 1;
                break;
            }
        }
    }


    return esValido;
}
