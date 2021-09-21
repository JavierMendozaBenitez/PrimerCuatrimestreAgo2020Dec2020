#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "color.h"

void mostrarColor(eColor color)
{
    printf(" %5d     %10s \n",
           color.id,
           color.nombreColor);
}

int mostrarColores(eColor color[], int tam)
{
    int error = 1;

    if(color != NULL && tam > 0)
    {
        printf("   *** Listado de Colores ***\n");
        printf("----------------------------\n");
        printf("  Id        Nombre Color \n");

        for(int i = 0; i < tam; i++)
        {
            mostrarColor(color[i]);
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

int validarColor(eColor color[], int tamC, int id)
{
    int esValido = 0;
    if(color != NULL && tamC > 0 && id > 0)
    {
        for(int i=0; i < tamC; i++)
        {
            if(color[i].id == id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}


