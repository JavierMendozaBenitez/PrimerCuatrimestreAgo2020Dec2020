#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "ePais.h"
#include "validaciones.h"
#include "Controller.h"

int main()
{
    srand (time(NULL));
    char seguir = 's';
    char confirma;
    char respuesta[10];
    int comparacion;
    int opcion1 = 0;
    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaAsig = ll_newLinkedList();
    LinkedList* listaExitoso = ll_newLinkedList();
    LinkedList* listanEnElHorno = ll_newLinkedList();
    ePais* paisMasMuertos = pais_new();

    do
    {
        switch(menuInt())
        {
        case 1:
            if(!opcion1)
            {
                printf("Ingrese el nombre del archivo a cargar: ");
                fflush(stdin);
                scanf("%s", respuesta);
                comparacion = strcmp("pandemia", respuesta);
                while(comparacion != 0)
                {
                    printf("Reingrese el nombre del archivo a cargar: ");
                    fflush(stdin);
                    scanf("%s", respuesta);
                    comparacion = strcmp("pandemia", respuesta);
                }
                printf("Nombre del archivo: %s\n\n", respuesta);
                system("pause");

                if(controller_loadFromText("pandemia.csv", lista) != 0)
                {
                    printf("Problema para cargar los paises\n");
                }
                else
                {
                    printf("Paises cargados correctamente\n");
                    opcion1 = 1;
                }
            }
            else
            {
                printf("Ya cargo el archivo\n");
            }

            break;
        case 2:
            if(opcion1)
            {
               if(!controller_ListEmployee(lista))
               {
                   printf("Paises listados con exito\n\n");
               }
            }
            else
            {
                printf("Primero debe ir a la opcion 1 para cargar la lista.\n");
            }

            break;
        case 3:
            if(opcion1)
            {
                listaAsig = ll_map(lista, pFunc);
                if(listaAsig != NULL)
                {
                   if(!controller_ListEmployee(listaAsig))
                   {
                       printf("Paises listados con exito\n\n");
                   }
                }
                else
                {
                    printf("\nError en el punto 3\n");
                }
            }
            else
            {
                printf("Primero debe ir a la opcion 1 para cargar la lista.\n");
            }
            break;
        case 4:
            if(opcion1)
            {
                listaExitoso = ll_filter(listaAsig, filtrarExitosos);
                if(listaExitoso != NULL)
                {
                    printf("\nLista Exitosos creada.\n");
                    printf("Se muestra los paises con menos de 5k\n\n");
                    controller_ListEmployee(listaExitoso);
                    printf("\n\nlista Exitosos guardada\n\n");
                    if(controller_saveAsText("listaExitosos.csv", listaExitoso))
                    {
                         printf("Listas en texto realizadas con exito\n\n");
                    }

                    else
                    {
                        printf("Problema para guardar los paises\n");
                    }
                }
            }
            else
            {
                printf("Primero debe ir a la opcion 1 para cargar la lista.\n");
            }

            break;
        case 5:
            if(opcion1)
            {
                listanEnElHorno = ll_filter(listaAsig, filtrarAlHorno);
                int cant = ll_len(listanEnElHorno);
                if(listanEnElHorno != NULL && cant > 0)
                {
                    printf("\nLista En El Horno, creada y guardada.\n");
                    printf("Se muestra los paises donde la cantidad de infectados triplica a la de recuperados.\n\n");
                    printf("\n\nLista En El Horno, guardada\n\n");
                    if(controller_saveAsText("listanEnElHorno.csv", listanEnElHorno))
                    {
                         printf("Listas en texto realizadas con exito\n\n");
                    }
                    else
                    {
                        printf("Problema para guardar los paises\n");
                    }
                }
                else
                {
                    printf("\nNo se muestra la lista porque no hay nigun pais donde la cantidad de infectados triplica a la de recuperados.\n\n");
                }
            }
            else
            {
                printf("Primero debe ir a la opcion 1 para cargar la lista.\n");
            }

            break;
        case 6:
            if(opcion1)
            {
                if(controller_sortEmployee(listaAsig) == 0)
                {
                    printf("Paises ordenados por infectados descendentes\n\n");
                    controller_ListEmployee(listaAsig);
                }
            }
            else
            {
                printf("Primero debe ir a la opcion 1 para cargar la lista.\n");
            }

            break;
        case 7:
            if(opcion1)
            {
                controller_sortPaisPorMuerte(listaAsig);
                paisMasMuertos = (ePais*) ll_get(listaAsig, 0);
                printf("\n\nPais con mas muertos\n\n");
                mostrarPais(paisMasMuertos);
            }
            else
            {
                printf("Primero debe ir a la opcion 1 para cargar la lista.\n");
            }

            break;
        case 8:
            printf("Confirma salida? Presione s para si o n para no: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        default:
            printf("Opcion invalida!!!\n");
        }
        system("pause");
    }
    while(seguir == 's');

    return 0;
}
