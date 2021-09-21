#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//#include "utn.h"

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);
int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);

int main()
{
    //char opcion;
    int edad;
    int peso;
    float opcion;
    char letra;
    int respuesta;

    respuesta = utn_getNumeroFlotante(&opcion, "Ingrese un flotante\n", "Error, debe ser un flotante.\n", 0.1, 10.2,100);
    if(respuesta == 0)
    {
        printf("\nEl flotante es: %f\n\n",opcion);
    }
    else
    {
        printf("\nERROR, no tiene mas reintentos\n\n");
    }

    respuesta = utn_getCaracter(&letra,"Letra?\n","Error la letra debe ser desde A a J\n",'A','J',1);
    if(respuesta == 0)
    {
        printf("\nLa letra es: %c\n\n",letra);
    }
    else
    {
        printf("\nERROR, no tiene mas reintentos\n\n");
    }

    respuesta = utn_getNumero(&edad,"Edad?\n","Error la edad debe ser desde 0 a 199\n",0,199,2);
    if(respuesta == 0)
    {
        printf("\nLa edad es: %d\n\n",edad);
    }
    else
    {
        printf("\nERROR\n");
    }

    respuesta = utn_getNumero(&peso,"Peso?\n","Error el peso debe ser desde 0 a 500\n",0,500,3);
    if(respuesta == 0)
    {
        printf("\nEl peso es: %d\n\n",peso);
    }
    else
    {
        printf("\nERROR\n");
    }

    return 0;
}

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
    int retorno = -1;
    int bufferInt;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%d", &bufferInt);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }
        }
        while(reintentos >=  0);

    }
    return retorno;
}

int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos)
{
    int retorno = -1;
    int bufferChar;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%c", &bufferChar);
            if(bufferChar >= minimo && bufferChar <= maximo)
            {
                *pResultado = bufferChar;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }
        }
        while(reintentos >=  0);

    }
    return retorno;
}

int utn_getNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
    int retorno = -1;
    float bufferFloat;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%f", &bufferFloat);
            if(bufferFloat >= minimo && bufferFloat <= maximo)
            {
                *pResultado = bufferFloat;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }
        }
        while(reintentos >=  0);

    }
    return retorno;
}


