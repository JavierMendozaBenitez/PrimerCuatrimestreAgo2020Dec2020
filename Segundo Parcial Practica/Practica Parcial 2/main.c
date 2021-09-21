#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "validaciones.h"

void leerTexto(char* path, LinkedList* lista);
void escribirTexto(char* path, LinkedList* lista);
int filtrarHoras(void* elemento);
int filtrarSueldo(void* elemento);
ePais* pFunc (void* element);

int main()
{
    char seguir = 's';
    char confirma;
    //int flagLoadFromText = 0;
    //int flagLoadFromBinary = 0;
    //int aleatorio = rand();
    LinkedList* lista = ll_newLinkedList();
    /*printf("Numero: %d %d %d %d\n\n", aleatorio, aleatorio, aleatorio, aleatorio);
    printf("Numero: %d %d %d %d\n\n", rand(), rand(), rand(), rand());
    printf("Numero: %d %d %d %d \n\n", rand()%100001+5000, rand()%100001+5000, rand()%100001+5000, rand()%100001+5000);
    system("pause");*/
    LinkedList* lista2 = ll_newLinkedList();

    ePais* pais = pais_new();
    do
    {
        switch(menuInt())
        {
        case 1:

            if(lista != NULL)
            {
                printf("\n\n*******************************ll_newLinkedList*********************************\n\n");
                leerTexto("paises.csv", lista);
                //mostrarPaises(lista);
                int len = ll_len(lista);

                if(len != -1)
                {
                    printf("\n\n*******************************ll_len***************************************\n\n");
                    printf("El tamanio de la lista devuelto por ll_len() debe ser 5 y es: %d: \n\n", len);
                }
            }
        case 2:
            mostrarPaises(lista);
            break;
        case 3:
            pFunc(pais);
            printf("%d      %s     %d         %d           %d\n", pais->id, pais->nombrePais, pais->recuperados, pais->infectados, pais->muertos);

            lista2 = ll_map(lista, pFunc);
            if(lista2 != NULL)
            {
                printf("Entro a la lista 2\n\n");
                mostrarPaises(lista2);
            }
            else
            {
                printf("\nError\n");
            }

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

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


void leerTexto(char* path, LinkedList* lista)
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
}


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


int filtrarHoras(void* elemento)
{
    int rta = 0;
    ePais* e = (ePais*) elemento;

    if(e != NULL)
    {
        if(e->recuperados > 30)
        {
            rta = 1;
        }
    }

    return rta;
}

int filtrarSueldo(void* elemento)
{
    int rta = 0;
    ePais* e = (ePais*) elemento;

    if(e != NULL)
    {
        if(e->infectados > 50000)
        {
            rta = 1;
        }
    }

    return rta;
}

ePais* pFunc (void* element)
{
    ePais* pais = (ePais*) element;

    //int aleatorio = rand();
    if(pais != NULL)
    {
        //pais->id=2;
        //strcpy(pais->nombrePais, "JAVIER");
        pais->recuperados = rand()%100001+5000;
        pais->infectados = rand()%2000001+40000;
        pais->muertos = rand()%5001+1000;
    }

    return pais;
}
