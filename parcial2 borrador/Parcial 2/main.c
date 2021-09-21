#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "ePais.h"
#include "validaciones.h"
#include "Controller.h"

void leerTexto(char* path, LinkedList* lista);
//void escribirTexto(char* path, LinkedList* lista);
int filtrarExitosos(void* elemento);
int filtrarAlHorno(void* elemento);
ePais* pFunc (void* element);

int main()
{
    srand (time(NULL));
    char seguir = 's';
    char confirma;
    char respuesta[10];
    int comparacion;
    int opcion1 = 0;
    int opcion2 = 0;
    int opcion3 = 0;
    int opcion4 = 0;
    int opcion5 = 0;
    int opcion6 = 0;
    int opcion7 = 0;
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
                /*printf("Ingrese el nombre del archivo a cargar: ");
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
                system("pause");*/

                if(controller_loadFromText("pandemia.csv", lista) != 0)
                {
                    printf("Problema para cargar los paises\n");
                }
                else
                {
                    printf("Paises cargados correctamente\n");
                    opcion1 = 1;
                }

               /* if(lista != NULL)
                {
                    leerTexto("pandemia.csv", lista);
                    mostrarPaises(lista);
                    opcion1 = 1;
                }*/
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
                   opcion2 = 1;
               }
                //mostrarPaises(lista);

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
                       opcion2 = 1;
                   }
                    //mostrarPaises(listaAsig);
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
                    //mostrarPaises(listaExitoso);
                    printf("\n\nlista Exitosos guardada\n\n");
                    if(controller_saveAsText("listaExitosos.csv", listaExitoso))
                    {
                         printf("Listas en texto realizadas con exito\n\n");
                    }
                        else
                    {
                        printf("Problema para guardar los paises\n");
                    }
                    //escribirTexto("listaExitosos.csv", listaExitoso);
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
                if(listanEnElHorno != NULL)
                {
                    printf("\nLista En El Horno, creada y guardada.\n");
                    printf("Se muestra los paises donde la cantidad de infectados triplica a la de recuperados.\n\n");
                    //mostrarPaises(listanEnElHorno);
                    printf("\n\nLista En El Horno, guardada\n\n");
                    //escribirTexto("listanEnElHorno.csv", listanEnElHorno);
                    if(controller_saveAsText("listanEnElHorno.csv", listanEnElHorno))
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
        case 6:
            if(opcion1)
            {
                if(controller_sortEmployee(listaAsig) == 0)
                {
                    printf("Paises ordenados por infectados descendentes\n\n");
                    controller_ListEmployee(listaAsig);
                }
                //ll_sort(listaAsig, paisSortByInfectados, 0);
                //mostrarPaises(listaAsig);
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
                //ll_sort(listaAsig, paisSortByMuertos, 0);
                paisMasMuertos = (ePais*) ll_get(listaAsig, 0);
                printf("\n\nPais con mas muertos\n\n");
                mostrarPais(paisMasMuertos);
               //controller_ListEmployee(listaAsig);
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


/*void leerTexto(char* path, LinkedList* lista)
{

    ePais* auxPais;
    char buffer[5][100];
    int cant;
    FILE* f;

    f = fopen(path, "r");
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
    printf("%s  %s  %s  %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    while(!feof(f))
    {
        cant = fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

        if(cant == 5)
        {
            auxPais = pais_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
            ll_add(lista, auxPais);
            //printf("%d %s %d %d %d\n", auxPais->id, auxPais->nombrePais, auxPais->recuperados, auxPais->infectados, auxPais->muertos);
        }
        else
        {
            break;
        }
    }

    fclose(f);
}*/


void escribirTexto(char* path, LinkedList* lista)
{
    FILE* f;
    int len = ll_len(lista);
    f = fopen(path, "w");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    for(int i=0; i < len; i++)
    {
        fprintf(f, "%d,%s,%d,%d,%d\n", ((ePais*)ll_get(lista, i))->id, ((ePais*)ll_get(lista, i))->nombrePais, ((ePais*)ll_get(lista, i))->recuperados, ((ePais*)ll_get(lista, i))->infectados, ((ePais*)ll_get(lista, i))->muertos);
    }

    fclose(f);

}


int filtrarExitosos(void* elemento)
{
    int rta = 0;
    ePais* e = (ePais*) elemento;

    if(e != NULL)
    {
        if(e->muertos < 5)
        {
            rta = 1;
        }
    }

    return rta;
}

int filtrarAlHorno(void* elemento)
{
    int rta = 0;
    ePais* e = (ePais*) elemento;

    if(e != NULL)
    {
        if((e->infectados / 3) == (e->recuperados))
        {
            rta = 1;
        }
    }

    return rta;
}



ePais* pFunc (void* element)
{
    ePais* pais = (ePais*) element;

    int aleatorioRecuperados =  rand()%(1001)+50;
    int aleatorioInfectados = rand()%(2001)+400;
    int aleatorioMuertos = rand()%(51)+1;

    if(pais != NULL)
    {
        pais->recuperados = aleatorioRecuperados;
        pais->infectados = aleatorioInfectados;
        pais->muertos = aleatorioMuertos;
    }

    return pais;
}
