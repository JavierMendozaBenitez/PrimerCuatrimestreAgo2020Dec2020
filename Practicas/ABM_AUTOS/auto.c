#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dataStore.h"
#include "auto.h"
#include "color.h"
#include "marca.h"
#include "validaciones.h"

int inicializarAutos(eAuto coche[], int tam)
{
    int error = 1;
    if(coche != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            coche[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

void mostrarAuto(eAuto coche, eMarca marca[], eColor color[], int tam)
{
    char descMarca[30];
    char descColor[30];


    if((obtenerDescripcionColor(color, tam, coche.idColor, descColor) == 0) && (obtenerDescripcionMarca(marca, tam, coche.idMarca, descMarca) == 0))
    {
        printf(" %5d     %10s    %5d       %10s           %10s\n",
               coche.id,
               coche.patente,
               //coche.idMarca,)
               //coche.idColor,
               coche.modelo,
               descMarca,
               descColor);
    }

    /* for(int i = 0; i < tam; i++)
     {
         if(marca[i].id == coche.idMarca)
         {
             strcpy(descMarca, marca[i].descripcion);
             break;
         }
     }
     for(int i = 0; i < tam; i++)
     {
         if(color[i].id == coche.idColor)
         {
             strcpy(descColor, color[i].nombreColor);
             break;
         }
     }*/
//printf(" %5d     %10s    %5d       %5d           %5d\n",
}

int mostrarAutos(eAuto coche[], eMarca marca[], eColor color[], int tam)
{
    int error = 1;
    int flag = 0;

    if(coche != NULL && tam > 0)
    {
        printf("   *** Listado de autos ***\n");
        printf("------------------------------------------------------------\n");
        printf(" Id           Patente     Modelo        idMarca              idColor  \n\n");


        for(int i = 0; i < tam; i++)
        {
            if(coche[i].isEmpty == 0)
            {
                mostrarAuto(coche[i], marca, color, tam);
                flag = 1;
            }
        }
        if( flag == 0)
        {
            printf("No hay personas en la lista");
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

int harcodearDatos(eAuto coche[], int tam, int cantidad)
{
    int error = 1;

    if(coche != NULL && cantidad > 0 && cantidad <= tam)
    {
        for(int i = 0; i < cantidad; i++)
        {
            coche[i].id = ids[i];
            strcpy(coche[i].patente, patentes[i]);
            coche[i].idMarca = idMarcas[i];
            coche[i].idColor = idColores[i];
            coche[i].modelo = modelos[i];
            coche[i].isEmpty = 0;
            error++;
        }
    }
    return error;
}

int buscarLibre(eAuto coche[], int tam)
{
    int indice = -1;//Si es -1 es que no hay lugares libres

    for(int i = 0; i < tam; i++)
    {
        if(coche[i].isEmpty == 1)
        {
            indice = i;
            break;//Sin el break va a seguir buscando, solo queremos un lugar
        }
    }
    return indice;
}

int altaAuto(eAuto coche[], int tam, eMarca marca[], int tamM, eColor color[], int tamC, int id)
{
    int error = -1;
    int lugarVacio;
    int auxMarca;
    int auxColor;
    char auxPatente[7];

    eAuto nuevoAuto;

    if(coche != NULL && tam > 0 && id > 0)
    {
        system("cls");
        printf("   *** ALTA DE Auto ***\n\n");
        lugarVacio = buscarLibre(coche, tam);

        if(lugarVacio == -1)
        {
            printf("ESTA LLENO, NO HAY LUGARES.\n\n");
        }
        else
        {
            nuevoAuto.id = id;

            largoCadena(auxPatente, 8, "Ingrese patente de 7 caracteres\n", "Error, reingrese patente\n");
            strcpy(nuevoAuto.patente, auxPatente);
            printf("\nLa patente ingresada es: %s\n\n", nuevoAuto.patente);
            system("pause");


            system("cls");
            mostrarMarcas(marca,tamM);

            printf("Ingrese idMarca\n");
            fflush(stdin);
            scanf("%d", &auxMarca);
            while(validarMarca(marca, tamM, auxMarca) == 0)
            {
                printf("Id Marca invalido no coincide con los registros. Reingrese id Marca: ");
                fflush(stdin);
                scanf("%d", &auxMarca);
            }
            nuevoAuto.idMarca = auxMarca;
            printf("\nEl id Marca ingresado es: %d\n\n", nuevoAuto.idMarca);
            system("pause");


            system("cls");
            mostrarColores(color, tamC);

            printf("Ingrese idColor\n");
            fflush(stdin);
            scanf("%d", &auxColor);
            while(validarColor(color, tamC, auxColor) == 0)
            {
                printf("Id Color invalido. Reingrese id Color: ");
                fflush(stdin);
                scanf("%d", &auxColor);
            }
            nuevoAuto.idColor = auxColor;
            printf("\nEl id Color ingresado es: %d\n\n", nuevoAuto.idColor);
            system("pause");


            system("cls");
            printf("   *** MODELO ***\n\n");
            utn_getNumeroConScanf(&nuevoAuto.modelo, "Ingrese modelo\n", "Ringrese modelo, debe ingresar anios desde 1900 hasta 2020.\n", 1900, 2020, 100);
            printf("\nEl Modelo ingresado es: %d\n\n", nuevoAuto.modelo);
            system("pause");
            nuevoAuto.isEmpty = 0;

            coche[lugarVacio] = nuevoAuto;

            error = 0;
        }
    }
    return error;
}

int buscarAuto(eAuto coche[], int tam, char patente[])
//busca la patente que ingresaste, si esta lleno, guarda su ubicacion en indice
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if((strcmp(coche[i].patente, patente)==0)&&(coche[i].isEmpty == 0))
        {
            indice = i;
            break;//para que deje de buscar
        }
    }
    return indice;
}

int bajaAutos(eAuto coche[], eMarca marca[], eColor color[], int tam)
{
    char patente[8];
    int indice;
    int error = 1;
    int confirma;

    if(coche != NULL && tam > 0)
    {
        system("cls");
        printf("   *** BAJA AUTOS ***\n\n");
        mostrarAutos(coche, marca, color, tam);
        printf("\nIngrese la patente del auto a bajar\n");
        fflush(stdin);
        gets(patente);

        while(validarPatente(coche, tam, patente) == 0)
        {
            printf("Patente invalida. Reingrese patente del auto: ");
            fflush(stdin);
            gets(patente);
        }
        printf("\nPatente ingresada: %s\n\n", patente);
        system("pause");


        indice = buscarAuto(coche, tam, patente);

        if(indice == -1)
        {
            printf("\nNo existe esa patente\n\n");
            system("pause");
        }
        else
        {   system("cls");
            printf("\nEliminara el siguiente auto\n\n");
            mostrarAuto(coche[indice], marca, color, tam);
            printf("\nPara eliminar presione 1, para cancelar, 2\n");
            scanf("%d", &confirma);

            if(confirma == 1)
            {
                coche[indice].isEmpty = 1;
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

int modificarAuto(eAuto coche[], int tam, eMarca marca[], int tamM, eColor color[], int tamC)
{
    char patente[8];
    int indice;
    int error = 1;
    int confirma;
    eAuto modificadoAuto;

    eColor modificadoColor;

    if(coche != NULL && tam > 0)
    {
        system("cls");
        printf("   *** MODIFICAR AUTOS ***\n\n");
        mostrarAutos(coche, marca, color, tam);
        printf("\nIngrese la patente del auto a modificar\n");
        fflush(stdin);
        gets(patente);

        indice = buscarAuto(coche, tam, patente);

        if(indice == -1)
        {
            printf("\nNo existe esa patente\n\n");
            system("pause");
        }
        else
        {
            system("cls");
            printf("   *** AUTO A MODIFICAR ***\n");
            printf("---------------------------\n\n");
            mostrarAuto(coche[indice], marca, color, tam);

            printf("\n\n");
            mostrarColores(color, tamC);
            printf("\nIngrese ID del nuevo color\n\n");
            fflush(stdin);
            //gets(modificadoColor.nombreColor);
            scanf("%d", &modificadoColor.id);

            printf("\nIngrese nuevo modelo\n\n");
            fflush(stdin);
            scanf("%d", &modificadoAuto.modelo);

            printf("\n\nPara modificar presione 1, para cancelar, 2\n");
            scanf("%d", &confirma);

            if(confirma == 1)
            {
                coche[indice].modelo = modificadoAuto.modelo;
                coche[indice].idColor = modificadoColor.id;
                //color[indice].id = modificadoColor.id;
                //strcpy(color[indice].nombreColor, modificadoColor.nombreColor);
                // modificadoColor.id = color[indice].id;

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

int obtenerDescripcionColor(eColor color[], int tam, int id, char nombreColor[])
{
    int error = 1;

    if(color != NULL && tam > 0 && id >= 1 && nombreColor != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(color[i].id == id)
            {
                strcpy(nombreColor, color[i].nombreColor);
                error = 0;
                break;
            }
        }
    }
    return error;
}

int obtenerDescripcionMarca(eMarca marca[], int tam, int id, char descripcion[])
{
    int error = 1;

    if(marca != NULL && tam > 0 && id >=1 && descripcion != NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(marca[i].id == id)
            {
                strcpy(descripcion, marca[i].descripcion);
                error = 0;
                break;
            }
        }
    }
    return error;
}

int ordenarAutosMarcaPatente(eAuto coche[], eMarca marca[], int tam, int criterioM, int criterioP)
{
    int error = 1;
    eAuto auxAuto;
    char marcaI[20];
    char marcaJ[20];
    //eMarca auxMarca;

    // if(marca != NULL && coche != NULL && tam > 0 && criterioM >= 0 && criterioM <= 1 && criterioP >= 0 && criterioP <= 1)
    if(coche != NULL && tam > 0 && criterioM >= 0 && criterioM <= 1 && criterioP >= 0 && criterioP <= 1)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                obtenerDescripcionMarca(marca, tam, coche[i].idMarca, marcaI);
                obtenerDescripcionMarca(marca, tam, coche[j].idMarca, marcaJ);

                if(strcmp(marcaI, marcaJ) > 0 && criterioM == 1)//menor a mayor
                {
                    auxAuto = coche[i];
                    coche[i] = coche[j];
                    coche[j] = auxAuto;
                }
                else if(strcmp(marcaI, marcaJ) < 0 && criterioM == 0)//Mayor a menor
                {
                    auxAuto = coche[i];
                    coche[i] = coche[j];
                    coche[j] = auxAuto;
                }
                else if((strcmp(marcaI, marcaJ) == 0) &&(strcmp(coche[i].patente, coche[j].patente) > 0 && criterioP == 1))
                {
                    auxAuto = coche[i];
                    coche[i] = coche[j];
                    coche[j] = auxAuto;
                }
                else if((strcmp(marcaI, marcaJ) == 0) &&(strcmp(coche[i].patente, coche[j].patente) < 0 && criterioP == 0))
                {
                    auxAuto = coche[i];
                    coche[i] = coche[j];
                    coche[j] = auxAuto;
                }
                /*
                if(coche[i].idMarca > coche[j].idMarca && criterioM == 1)//menor a mayor
                {
                    auxAuto = coche[i];
                    coche[i] = coche[j];
                    coche[j] = auxAuto;
                }
                else if(coche[i].idMarca < coche[j].idMarca && criterioM == 0)//menor a mayor
                {
                    auxAuto = coche[i];
                    coche[i] = coche[j];
                    coche[j] = auxAuto;
                }
                else if((coche[i].idMarca == coche[j].idMarca && criterioM == 0) &&(strcmp(coche[i].patente, coche[j].patente) > 0) && (criterioP == 1))
                {
                    auxAuto = coche[i];
                    coche[i] = coche[j];
                    coche[j] = auxAuto;
                }
                else if((coche[i].idMarca == coche[j].idMarca && criterioM == 0) &&(strcmp(coche[i].patente, coche[j].patente) < 0) && (criterioP == 0))
                {
                    auxAuto = coche[i];
                    coche[i] = coche[j];
                    coche[j] = auxAuto;
                }  */
            }
        }
        error = 0;
    }
    return error;
}

int validarPatente(eAuto coche[], int tamA, char patente[])
{
    int esValido = 0;
    if(coche != NULL && tamA > 0 && patente != NULL)
    {
        for(int i=0; i < tamA; i++)
        {
            if(strcmp(coche[i].patente, patente) == 0)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

