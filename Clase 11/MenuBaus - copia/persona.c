#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "persona.h"
#include "dataStore.h"

int inicializarPersonas(ePersona gente[], int tam)
{

    int error = 1;
    if (gente!=NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            gente[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

void mostrarPersona(ePersona unaPersona, eDeporte sports[], int tam)
{
    char descDeporte[20];
    //Tengo que buscar en el array de deportes
    //aquel deporte que tiene como campo id el mismo valor que
    //unaPersona.idDeporte
    if(obtenerDescripcionDeporte(sports, tam, unaPersona.idDeporte, descDeporte)==0)
    {
        printf(" %4d    %10s    %c  %3.2f   %02d/%02d/%d       %s\n",
               unaPersona.legajo,
               unaPersona.nombre,
               unaPersona.sexo,
               unaPersona.altura,
               unaPersona.fNac.dia,
               unaPersona.fNac.mes,
               unaPersona.fNac.anio,
               descDeporte);
    }
    else
    {
        printf("Problema al obtener descripcion del deporte\n\n");
    }

}

int mostrarPersonas(ePersona gente[], int tam, eDeporte sports[], int tamD)
{

    int error = 1;
    int flag = 0;

    if( gente != NULL && tam > 0)
    {
        //system("cls");
        printf(" Legajo    Nombre    Sexo    Altura     F.Nacimiento   idDeporte\n");
        printf("-------------------------------------------------------------------\n\n");

        for(int i=0; i<tam; i++)
        {
            if(gente[i].isEmpty == 0)
            {
                mostrarPersona(gente[i], sports, tamD);
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

int buscarLibre(ePersona gente[], int tam) //para dar de alta, busca los vacios
//y guarda ese vacio en indice
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(gente[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int altaPersona(ePersona gente[], int tam, eDeporte sports[], int tamD, int legajo)
//Creas una nuava persona y luego la copias en gente
{

    int error = 1;
    int indice;
    int auxIdDeporte;
    ePersona nuevaPersona;

    if(gente!=NULL && tam > 0 && legajo > 0)
    {
        system("cls");
        printf("ALTA DE PERSONA\n\n");
        indice = buscarLibre(gente, tam);

        if(indice == -1)
        {
            printf("El sistema esta completo.\n");
        }
        else
        {
            //aplicar validaciones a las cargas
            nuevaPersona.legajo = legajo;
            nuevaPersona.isEmpty = 0;
            printf("\n\nIngrese nombre: ");
            fflush(stdin);
            gets(nuevaPersona.nombre);
            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevaPersona.sexo);
            printf("Ingrese altura: ");
            scanf("%f", &nuevaPersona.altura);

            printf("Ingrese fecha nacimiento dd/mm/aaaa: ");
            scanf("%d/%d/%d", &nuevaPersona.fNac.dia, &nuevaPersona.fNac.mes, &nuevaPersona.fNac.anio);

            mostrarDeportes(sports, tamD);

            printf("Ingrese id deporte: ");
            scanf("%d", &auxIdDeporte);
            //VALIDACION
            while(validarIdDeporte(sports, tamD, auxIdDeporte) == 0)
            {
                printf("Id invalido. Reingrese id deporte: ");
                scanf("%d", &auxIdDeporte);
            }

            nuevaPersona.idDeporte = auxIdDeporte;

            gente[indice] = nuevaPersona;
            error = 0;
        }
    }

    return error;
}

int buscarPersona(ePersona gente[], int tam, int legajo)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(gente[i].legajo == legajo && gente[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int bajaPersona(ePersona gente[], int tam, eDeporte sports[], int tamD)
{
    int error = 1;
    int legajo;
    int indice;
    int confirma;

    if(gente != NULL && tam > 0)
    {
        system("cls");
        printf("    *** BAJA DE PERSONA ***\n");
        mostrarPersonas(gente, tam, sports, tamD);
        printf("Ingrese el legajo: ");
        scanf("%d", &legajo);

        indice = buscarPersona(gente, tam, legajo);

        if( indice == -1)
        {
            printf("No existe una persona con ese legajo.\n");
        }
        else
        {
            mostrarPersona(gente[indice], sports, tamD);
            printf("Confirma baja: 1 - SI 2 - NO");
            scanf("%d", &confirma);
            if(confirma == 1)
            {
                gente[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 2;
            }
        }
    }

    return error;

}

int modificarPersona(ePersona gente[], int tam, eDeporte sports[], int tamD)
{
    int error = 1;
    int legajo;
    int indice;
    char confirma;
    eFecha nuevaFecha;

    if(gente != NULL && tam > 0)
    {
        system("cls");
        printf("    *** MODIFICAR PERSONA ***\n");
        mostrarPersonas(gente, tam, sports, tamD);
        printf("Ingrese el legajo: ");
        scanf("%d", &legajo);

        indice = buscarPersona(gente, tam, legajo);

        if( indice == -1)
        {
            printf("No existe una persona con ese legajo.\n");
        }
        else
        {
            mostrarPersona(gente[indice], sports, tamD);
            printf("\nIngrese nueva fecha de nacimiento: ");
            scanf("%d/%d/%d", &nuevaFecha.dia, &nuevaFecha.mes, &nuevaFecha.anio);
            mostrarFecha(nuevaFecha);
            printf("Confirma modificacion?");
            fflush(stdin);
            scanf("%c", &confirma);
            if (confirma == 's')
            {
                gente[indice].fNac = nuevaFecha;
                error = 0;
            }
            else
            {
                error = 2;
            }

        }

    }

    return error;
}

int hardcodearPersonas(ePersona gente[], int tam, int cantidad)
{
    int error = -1;

    if(gente!= NULL && tam>0 && cantidad >= 0 && cantidad <= tam)
    {
        error = 0;
        for(int i=0; i<cantidad; i++)
        {
            gente[i].legajo = legajos[i];
            strcpy(gente[i].nombre, nombres[i]);
            gente[i].sexo = sexos[i];
            gente[i].altura = alturas[i];
            gente[i].fNac.dia = dia[i];
            gente[i].fNac.mes = meses[i];
            gente[i].fNac.anio = anios[i];
            gente[i].idDeporte = idDeportes[i];
            gente[i].isEmpty = 0;
            error++;
        }
    }

    return error;
}

int ordenarPersonasNombre(ePersona gente[], int tam, int criterio)
{
    int error = 1;
    ePersona auxPersona;

    if(gente!=NULL && tam>0 && criterio>=0 && criterio<=1)
    {


        for(int i=0; i < tam -1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                /*
                if(strcmp(gente[i].nombre, gente[j].nombre) > 0 && criterio == 1)
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
                else if(strcmp(gente[i].nombre, gente[j].nombre) < 0 && criterio == 0)
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
                */
                ///////////////////////////////// OTRA FORMA DE HACERLO //////////////////////

                if((strcmp(gente[i].nombre, gente[j].nombre) > 0 && criterio == 1) || (strcmp(gente[i].nombre, gente[j].nombre) < 0 && criterio == 0))
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
            }
        }
        error = 0;
    }

    return error;
}

int ordenarPersonasSexoAltura(ePersona gente[], int tam, int criterioS, int criterioA)
{

    int error = 1;
    ePersona auxPersona;

    if(gente!=NULL && tam>0 && criterioS>=0 && criterioS<=1 && criterioA >= 0 && criterioA <= 1)
    {


        for(int i=0; i-tam -1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                //a- comparando personas del mismo sexos desempata la altura
                //b- comparando personas de distinto sexo
                ///////////ORDENAMIENTO POR SEXO ASCENDENTE O DESCENDENTE
                if( gente[i].sexo > gente[j].sexo && criterioS == 1)
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
                else if(gente[i].sexo < gente[j].sexo && criterioS == 0)
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
                else if(gente[i].sexo == gente[j].sexo && gente[i].altura > gente[j].altura && criterioA == 1)
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
                else if(gente[i].sexo == gente[j].sexo && gente[i].altura < gente[j].altura && criterioA == 0)
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
            }
        }
        error = 0;
    }

    return error;

}

int obtenerDescripcionDeporte(eDeporte sports[], int tam, int id, char descripcion[])
{
    int error = 1;

    if(sports != NULL && tam > 0 && id >=1000 && descripcion != NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(sports[i].id == id)
            {
                strcpy(descripcion, sports[i].descripcion);
                error = 0;
                break;
            }
        }
    }

    return error;
}










