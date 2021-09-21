#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personas.h"

#define TAM 5

int main()
{
    int indiceLibre;
    int indiceBaja;

    ePersona** lista = (ePersona**) malloc(TAM* sizeof(ePersona*));
    ePersona* auxPersona;

    if(lista == NULL)
    {
        printf("No se pudo conseguir memoria\n");
        exit(EXIT_FAILURE);
    }

    if( !initPersonas(lista, TAM))
    {
        printf("Inicializacion exitosa!\n");
    }
    else
    {
        printf("Problema al inicializar persona!\n");
    }

    if(buscarLibrePersonas(&indiceLibre, lista, TAM))
    {
        printf("Alguno de los punteros es NULL\n");
    }
    if(indiceLibre == -1)
    {
        printf("No hay mas lugar\n");
    }
    else
    {
        auxPersona = new_PersonaParam(12000, "Aldo", 'm', 1.82);
        if(auxPersona == NULL)
        {
            printf("No se pudo conseguir memoria! o datos invalidos\n");
        }
        else
        {
            *(lista + indiceLibre) = auxPersona;

            printf("Alta exitosa!\n");
        }
    }

    mostrarPersonas(lista, TAM);
    printf("\n----------------------------------------\n");

    if(buscarLibrePersonas(&indiceLibre, lista, TAM))
    {
        printf("Alguno de los punteros es NULL\n");
    }
    if(indiceLibre == -1)
    {
        printf("No hay mas lugar\n");
    }
    else
    {
        auxPersona = new_PersonaParam(14500, "Juana", 'f', 1.78);
        if(auxPersona == NULL)
        {
            printf("No se pudo conseguir memoria! o datos invalidos\n");
        }
        else
        {
            *(lista + indiceLibre) = auxPersona;

            printf("Alta exitosa!\n");
        }
    }

    mostrarPersonas(lista, TAM);
    printf("\n----------------------------------------\n");

    if(buscarLibrePersonas(&indiceLibre, lista, TAM))
    {
        printf("Alguno de los punteros es NULL\n");
    }
    if(indiceLibre == -1)
    {
        printf("No hay mas lugar\n");
    }
    else
    {
        auxPersona = new_PersonaParam(12780, "Raul", 'm', 1.65);
        if(auxPersona == NULL)
        {
            printf("No se pudo conseguir memoria! o datos invalidos\n");
        }
        else
        {
            *(lista + indiceLibre) = auxPersona;

            printf("Alta exitosa!\n");
        }
    }

    mostrarPersonas(lista, TAM);
    printf("\n----------------------------------------\n");

    buscarPersona(&indiceBaja, 14500, lista, TAM);

    if(indiceBaja == -1)
    {
        printf("No hay ninguna persona con ese id\n");
    }
    else
    {
        destruirPersona(*(lista + indiceBaja));
        *(lista + indiceBaja) = NULL;
    }

    mostrarPersonas(lista, TAM);
    printf("\n----------------------------------------\n");

    return 0;
}
