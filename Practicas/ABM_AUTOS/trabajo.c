#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "trabajo.h"
#include "servicio.h"
#include "marca.h"
#include "color.h"
#include "fecha.h"
#include "auto.h"

int inicializarTrabajos(eTrabajo trabajo[], int tamT)
{
    int error = 1;
    if(trabajo != NULL && tamT > 0)
    {
        for(int i = 0; i < tamT; i++)
        {
            trabajo[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

void mostrarTrabajo(eTrabajo trabajo, eServicio servicioT[], int tamT, int tamS)
{
    char descServicio[60];

    for(int i = 0; i < tamS; i++)
    {
        if(servicioT[i].id == trabajo.idServicio)
        {
            strcpy(descServicio, servicioT[i].descripcion);
            break;
        }
    }
    printf(" %5d           %10s           %10s     %02d/%02d/%d\n",
           trabajo.id,
           trabajo.patente,
           descServicio,
           trabajo.fecha.dia,
           trabajo.fecha.mes,
           trabajo.fecha.anio);
}

int mostrarTrabajos(eTrabajo trabajo[], eServicio servicioT[], int tamT, int tamS)
{
    int error = 1;
    int flag = 0;

    if(trabajo != NULL && tamT > 0)
    {
        printf("   *** Listado de Trabajos ***\n");
        printf("------------------------------\n");
        printf("  Id                Patente            ID Servicio   Fecha\n");

        for(int i = 0; i < tamT; i++)
        {
            if(trabajo[i].isEmpty == 0)
            {
                mostrarTrabajo(trabajo[i], servicioT, tamT, tamS);
                flag = 1;
            }
        }
        if( flag == 0)
        {
            printf("    No hay personas en la lista");
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

int buscarLibreTrabajo(eTrabajo trabajo[], int tamT)//carga el lugar libre que encuentre en indice
{
    int indice = -1;//Si es -1 es que no hay lugares libres

    for(int i = 0; i < tamT; i++)
    {
        if(trabajo[i].isEmpty == 1)
        {
            indice = i;
            break;//Sin el break va a seguir buscando, solo queremos un lugar
        }
    }
    return indice;
}

int altaTrabajo(eTrabajo trabajo[], eServicio servicioT[], eAuto cocheT[], eMarca marcaT[], eColor colorT[], int tamT, int tamS, int tamA, int tamM, int tamC, int id)
{
    int error = -1;
    int lugarVacio;
    char auxPatente[8];
    int auxServicio;

    eTrabajo nuevoTrabajo;

    if(trabajo != NULL && tamT > 0 && id > 0)
    {
        system("cls");
        printf("   *** ALTA DE TRABAJO ***\n\n");
        lugarVacio = buscarLibreTrabajo(trabajo, tamT);

        if(lugarVacio == -1)
        {
            printf("ESTA LLENO, NO HAY LUGARES PARA TRABAJOS.\n\n");
        }
        else
        {
            nuevoTrabajo.id = id;

            mostrarAutos(cocheT, marcaT, colorT, tamA);

            printf("Ingrese patente\n");
            fflush(stdin);
            gets(auxPatente);
            while(validarPatente(cocheT, tamT, auxPatente) == 0)
            {
                printf("Patente invalida. Reingrese patente del auto: ");
                fflush(stdin);
                gets(auxPatente);
            }
            strcpy(nuevoTrabajo.patente, auxPatente);


            system("cls");
            mostrarServicios(servicioT, tamS);

            printf("\nIngrese idServicio\n");
            fflush(stdin);
            scanf("%d", &auxServicio);
            while(validarServicio(servicioT, tamS, auxServicio) == 0)
            {
                printf("Id Servicio invalido. Reingrese id Servicio: ");
                scanf("%d", &auxServicio);
            }
            nuevoTrabajo.idServicio = auxServicio;


            printf("\nIngrese fecha de inicio del trabajo\n");
            fflush(stdin);
            scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia,
                  &nuevoTrabajo.fecha.mes,
                  &nuevoTrabajo.fecha.anio);

            nuevoTrabajo.isEmpty = 0;

            trabajo[lugarVacio] = nuevoTrabajo;

            error = 0;
        }
    }
    return error;
}
