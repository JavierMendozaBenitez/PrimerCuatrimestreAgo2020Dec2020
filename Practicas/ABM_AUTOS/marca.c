#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "marca.h"

void mostrarMarca(eMarca marca)
{
    printf(" %5d     %10s \n",
           marca.id,
           marca.descripcion);
}

int mostrarMarcas(eMarca marca[], int tam)
{
    int error = 1;

    if(marca != NULL && tam > 0)
    {
        printf("   *** Listado de Marcas ***\n");
        printf("----------------------------\n");
        printf("  Id        Descripcion \n");

        for(int i = 0; i < tam; i++)
        {
            mostrarMarca(marca[i]);
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

int validarMarca(eMarca marca[], int tamM, int id)
{
    int esValido = 0;
    if(marca != NULL && tamM > 0 && id > 0)
    {
        for(int i=0; i < tamM; i++)
        {
            if(marca[i].id == id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}
