#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "almuerzo.h"

int inicializarAlmuerzos(eAlmuerzo almuerzo[], int tam)
{
    int error = 1;
    if (almuerzo!=NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            almuerzo[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}
int mostrarAlmuerzos(eAlmuerzo almuerzos[], int tamA, ePersona gente[], int tamP, eComida foods[], int tamC)
{
    int error = 1;
    int flag = 0;

    if( gente != NULL && tamP > 0)
    {
        //system("cls");
        printf(" Id             Nombre    Comida  Fecha\n");
        printf("----------------------------------\n\n");

        for(int i=0; i<tamA; i++)
        {
            if(almuerzos[i].isEmpty == 0)
            {
                mostrarAlmuerzo(almuerzos[i], gente, tamP, foods, tamC);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("    No hay almuerzos en la lista");
        }
        printf("\n\n");

        error = 0;

    }
    return error;
}
void mostrarAlmuerzo(eAlmuerzo unAlmuerzo, ePersona gente[], int tamP, eComida foods[], int tamC)
{
    char descComida[20];
    char nombrePersona[20];
    //Tengo que buscar en el array de deportes
    //aquel deporte que tiene como campo id el mismo valor que
    //unaPersona.idDeporte
    if(obtenerDescripcionComida(foods, tamC, unAlmuerzo.idComida, descComida) == 0
       && obtenerNombrePersona(gente, tamP, unAlmuerzo.legajo, nombrePersona) == 0)
    {
        printf(" %4d    %10s   %10s   %02d/%02d/%d \n",
               unAlmuerzo.id,
               nombrePersona,
               descComida,
               unAlmuerzo.fecha.dia,
               unAlmuerzo.fecha.mes,
               unAlmuerzo.fecha.anio);
    }
    else
    {
        printf("Problema al obtener descripciones\n\n");
    }
}
int buscarAlmuerzoLibre(eAlmuerzo almuerzo[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(almuerzo[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
int altaAlmuerzo(eAlmuerzo almuerzos[], int tamA, ePersona gente[], int tamP, eComida foods[], int tamC, eDeporte sports[], int tamD, int id)
{
    int error = 1;
    int indice;
    int auxIdComida;
    int auxLegajo;
    eAlmuerzo nuevoAlmuerzo;

    if(almuerzos!=NULL && tamA > 0 && id > 0)
    {
        system("cls");
        printf("ALTA DE ALMUERZO\n\n");
        indice = buscarAlmuerzoLibre(almuerzos, tamA);

        if(indice == -1)
        {
            printf("No hay lugar para otro almuerzo.\n");
        }
        else
        {
            //aplicar validaciones a las cargas
            nuevoAlmuerzo.id = id;
            nuevoAlmuerzo.isEmpty = 0;

            mostrarPersonas(gente, tamP, sports, tamD);
            printf("Ingrese legajo persona: ");
            fflush(stdin);
            scanf("%d", &auxLegajo);

            while(validarLegajoPersona(gente, tamP, auxLegajo) == 0)
            {
                printf("Legajo invalido. Reingrese legajo: ");
                fflush(stdin);
                scanf("%d", &auxLegajo);
            }
            nuevoAlmuerzo.legajo = auxLegajo;


            mostrarComidas(foods, tamC);
            printf("Ingrese id comida: ");
            fflush(stdin);
            scanf("%d", &auxIdComida);

            while(validarIdComida(foods, tamC, auxIdComida) == 0)
            {
                printf("Id comida invalido. Reingrese id comida: ");
                fflush(stdin);
                scanf("%d", &auxIdComida);
            }
            nuevoAlmuerzo.idComida = auxIdComida;


            printf("Ingrese fecha dd/mm/aaaa: ");
            fflush(stdin);
            scanf("%d/%d/%d", &nuevoAlmuerzo.fecha.dia, &nuevoAlmuerzo.fecha.mes, &nuevoAlmuerzo.fecha.anio);

            almuerzos[indice] = nuevoAlmuerzo;

            error = 0;
        }
    }
    return error;
}
