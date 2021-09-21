#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ePais.h"

ePais* pais_new()
{
    ePais* nuevoPais;
    nuevoPais = (ePais*) malloc(sizeof(ePais));

    if(nuevoPais != NULL)
    {
        nuevoPais->id = 0;
        strcpy(nuevoPais->nombrePais, "");
        nuevoPais->recuperados = 0;
        nuevoPais->infectados = 0;
        nuevoPais->muertos = 0;
    }

    return nuevoPais;
}

ePais* pais_newParametros(char* idStr,char* nombreStr,char* recuperados, char* infectados, char* muertos)
{
    ePais* nuevoPais = pais_new();

    if(nuevoPais != NULL)
    {
        if(
           pais_setId(nuevoPais, idStr) ||
           pais_setNombre(nuevoPais, nombreStr) ||
           pais_setRecuperados(nuevoPais, recuperados) ||
           pais_setInfectados(nuevoPais, infectados) ||
           pais_setMuertos(nuevoPais, muertos))
           {
               free(nuevoPais);
               nuevoPais = NULL;
               printf("Datos ingresados incorrectos, reintente.\n");
           }
    }

    return nuevoPais;
}

int pais_setId(ePais* this,char* id)
{
    int error = 1;

    if(this != NULL && id >0)
    {
        this->id = atoi(id);
        error = 0;
    }

    return error;
}

int pais_getId(ePais* this,int* id)
{
    int error = 1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        error = 0;
    }

    return error;
}

int pais_setNombre(ePais* this,char* nombre)
{
    int error = 1;

    if(this != NULL && strlen(nombre) >= 2 && strlen(nombre) < 20)
    {
        strcpy(this->nombrePais, nombre);
        error = 0;
    }

    return error;
}

int pais_getNombre(ePais* this,char* nombre)
{
    int todoOk = 1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombrePais);
        todoOk = 0;
    }

    return todoOk;
}

int pais_setRecuperados(ePais* this,char* recuperados)
{
    int todoOk = 1;

    if(this != NULL && recuperados > 0)
    {
        this->recuperados = atoi(recuperados);
        todoOk = 0;
    }

    return todoOk;
}

int pais_getRecuperados(ePais* this,int* recuperados)
{
    int todoOk = 1;

    if(this != NULL && recuperados != NULL)
    {
        *recuperados = this->recuperados;
        todoOk = 0;
    }

    return todoOk;
}

int pais_setInfectados(ePais* this,char* infectados)
{
    int todoOk = 1;

    if(this != NULL && infectados > 0)
    {
        this->infectados = atoi(infectados);
        todoOk = 0;
    }

    return todoOk;
}

int pais_getInfectados(ePais* this,int* infectados)
{
    int todoOk = 1;

    if(this != NULL && infectados != NULL)
    {
        *infectados = this->infectados;
        todoOk = 0;
    }

    return todoOk;
}

int pais_setMuertos(ePais* this,char* muertos)
{
    int todoOk = 1;

    if(this != NULL && muertos > 0)
    {
        this->muertos = atoi(muertos);
        todoOk = 0;
    }

    return todoOk;
}

int pais_getMuertos(ePais* this,int* muertos)
{
    int todoOk = 1;

    if(this != NULL && muertos != NULL)
    {
        *muertos = this->muertos;
        todoOk = 0;
    }

    return todoOk;
}

int paisSortByName(void* paisA, void* paisB)
{
    int retorno = 0;
    ePais* pA = (ePais*) paisA;
    ePais* pB = (ePais*) paisB;

    if(strcmp(pA->nombrePais, pB->nombrePais) > 0)
    {
        retorno = 1;
    }
    else
    {
        if(strcmp(pA->nombrePais, pB->nombrePais) < 0)
        {
            retorno = -1;
        }
    }

    return retorno;
}

int paisSortById(void* paisA, void* paisB)
{
    int retorno = 0;
    ePais* pA = (ePais*) paisA;
    ePais* pB = (ePais*) paisB;

    if(pA->id > pB->id)
    {
        retorno = 1;
    }
    else
    {
        if(pA->id < pB->id)
        {
            retorno = -1;
        }
    }

    return retorno;
}

int paisSortByRecuperados(void* paisA, void* paisB)
{
    int retorno = 0;
    ePais* pA = (ePais*) paisA;
    ePais* pB = (ePais*) paisB;

    if(pA->recuperados > pB->recuperados)
    {
        retorno = 1;
    }
    else
    {
        if(pA->recuperados < pB->recuperados)
        {
            retorno = -1;
        }
    }

    return retorno;
}

int paisSortByInfectados(void* paisA, void* paisB)
{
    int retorno = 0;
    ePais* pA = (ePais*) paisA;
    ePais* pB = (ePais*) paisB;

    if(pA->infectados > pB->infectados)
    {
        retorno = 1;
    }
    else
    {
        if(pA->infectados < pB->infectados)
        {
            retorno = -1;
        }
    }

    return retorno;
}

int paisSortByMuertos(void* paisA, void* paisB)
{
    int retorno = 0;
    ePais* pA = (ePais*) paisA;
    ePais* pB = (ePais*) paisB;

    if(pA->muertos > pB->muertos)
    {
        retorno = 1;
    }
    else
    {
        if(pA->muertos < pB->muertos)
        {
            retorno = -1;
        }
    }

    return retorno;
}

int mostrarPais(ePais* pais)
{
    int error = 1;
    int id;
    char nombre[128];
    int recuperados;
    int infectados;
    int muertos;

    if(pais != NULL)
    {
        if((
           (pais_getId(pais, &id) == 0) &&
           (pais_getNombre(pais, nombre) == 0) &&
           (pais_getRecuperados(pais, &recuperados) == 0) &&
           (pais_getInfectados(pais, &infectados) == 0) &&
           (pais_getMuertos(pais, &muertos) == 0)))
        {
            printf("%4d   %20s              %4d             %4d             %4d\n", id, nombre, recuperados, infectados, muertos);
            error = 0;
        }
    }

    return error;
}

int mostrarPaises(LinkedList* lista)
{
    int error = 1;
    int flag = 0;
    int tam = ll_len(lista);
    ePais* auxPais;

    if(lista != NULL )
    {
        error = 0;
        printf(" Id                  Nombre          Recuperados         Infectados         Muertos\n");
        for(int i=0; i< tam; i++)
        {
            auxPais = (ePais*)ll_get(lista, i);
            if( auxPais != NULL)
            {
                mostrarPais(auxPais);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("No hay paises para mostrar\n\n");
        }
    }
    return error;
}

