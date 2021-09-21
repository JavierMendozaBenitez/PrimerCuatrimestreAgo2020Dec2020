#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "servicio.h"
#include "trabajo.h"

void mostrarServicio(eServicio servicio)
{
    printf(" %5d     %10s       %5d\n",
           servicio.id,
           servicio.descripcion,
           servicio.precio);
}

int mostrarServicios(eServicio servicio[], int tam)
{
    int error = 1;

    if(servicio != NULL && tam > 0)
    {
        printf("   *** Listado de servicios ***\n");
        printf("-----------------------------------\n");
        printf("  Id        Descripcion       precio\n");

        for(int i = 0; i < tam; i++)
        {
            mostrarServicio(servicio[i]);
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

int validarServicio(eServicio servicio[], int tamS, int id)
{
    int esValido = 0;
    if(servicio != NULL && tamS > 0 && id > 0)
    {
        for(int i=0; i < tamS; i++)
        {
            if(servicio[i].id == id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}
