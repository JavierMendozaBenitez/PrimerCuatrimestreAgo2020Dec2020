#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personas.h"

int initPersonas(ePersona** vec, int tam)
{
    int error = 1;

    if(vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            *(vec + i) = NULL;
        }
        error = 0;
    }
    return error;
}

int buscarLibrePersonas(int* pIndice, ePersona** vec, int tam)
{
    int error = 1;

    if(vec != NULL && pIndice != NULL && tam > 0)
    {
        *pIndice = -1;
        for(int i = 0; i < tam ; i++)
        {
            if(*(vec + i) == NULL)
            {
                *pIndice = i;
                break;
            }
        }
        error = 0;
    }

    return error;
}

int mostrarPersona(ePersona* persona)
{
    int error = 1;

    if(persona != NULL )
    {
        printf("%d   %10s        %c         %.2f\n", persona->id, persona->nombre, persona->sexo, persona->altura);
        error = 0;
    }
    return error;
}

int mostrarPersonas(ePersona** vec, int tam)
{
    int error = 1;
    int flag = 0;

    if(vec != NULL )
    {
        printf(" Id        Nombre      Sexo     Altura\n");
        for(int i=0; i<tam; i++)
        {
            if(*(vec + i) != NULL)
            {
                mostrarPersona(*(vec + i));
                flag = 1;
            }
        }

        if(flag == 0)
        {
            printf("No hay personas para mostrar\n\n");
        }

        error = 0;
    }
    return error;
}

ePersona* new_Persona()
{
    ePersona* nuevaPersona;
    nuevaPersona = (ePersona*) malloc(sizeof(ePersona));

    if(nuevaPersona != NULL)
    {
        nuevaPersona->id = 0;
        strcpy(nuevaPersona->nombre, "");
        nuevaPersona->sexo = ' ';
        nuevaPersona->altura = 0;
    }

    return nuevaPersona;
}

ePersona* new_PersonaParam(int id, char* nombre, char sexo, float altura)
{
    ePersona* nuevaPersona;

    nuevaPersona = new_Persona();

    if(nuevaPersona != NULL)
    {

        if(personaSetId(nuevaPersona, id) ||
            personaSetNombre(nuevaPersona, nombre) ||
            personaSetSexo(nuevaPersona, sexo) ||
            personaSetAltura(nuevaPersona, altura)
          )
        {
            free(nuevaPersona);
            nuevaPersona = NULL;
        }
    }

    return nuevaPersona;
}

int personaSetId(ePersona* persona, int id)
{
    int error = 1;

    if(persona != NULL && id >= 10000 && id <= 20000)
    {
        persona->id = id;
        error = 0;
    }

    return error;
}

int personaSetNombre(ePersona* persona, char* nombre)
{
    int error = 1;

    if(persona != NULL && strlen(nombre) >= 3 && strlen(nombre) < 20)//Faltan validaciones
    {
        strcpy(persona->nombre, nombre);
        error = 0;
    }

    return error;
}

int personaSetSexo(ePersona* persona, char sexo)
{
    int error = 1;

    if(persona != NULL && (sexo == 'f' || sexo == 'm'))
    {
        persona->sexo = sexo;
        error = 0;
    }

    return error;
}

int personaSetAltura(ePersona* persona, float altura)
{
    int error = 1;

    if(persona != NULL && altura > 0)
    {
        persona->altura = altura;
        error = 0;
    }

    return error;
}

int personaGetId(int* pId, ePersona* persona)
{
    int error = 1;

    if(persona != NULL && pId != NULL)
    {
        *pId = persona->id;
        error = 0;
    }

    return error;
}

int personaGetNombre(char* pNombre, ePersona* persona)
{
    int todoOk = 1;

    if(persona != NULL && pNombre != NULL)
    {
        strcpy(pNombre, persona->nombre);
        todoOk = 0;
    }

    return todoOk;
}

int personaGetSexo(char* pSexo, ePersona* persona)
{
    int todoOk = 1;

    if(persona != NULL && pSexo != NULL)
    {
        *pSexo = persona->sexo;
        todoOk = 0;
    }

    return todoOk;
}

int personaGetAltura(float* pAltura, ePersona* persona)
{
    int todoOk = 1;

    if(persona != NULL && pAltura != NULL)
    {
        *pAltura = persona->altura;
        todoOk = 0;
    }

    return todoOk;
}

int destruirPersona(ePersona* persona)
{
    int error = 1;

    if(persona != NULL)
    {
        free(persona);
        error = 0;
    }

    return error;
}

int buscarPersona(int* pIndice, int id, ePersona** vec, int tam)
{
    int error = 1;

    if(vec != NULL && pIndice != NULL && tam > 0)
    {
        *pIndice = -1;
        for(int i = 0; i < tam ; i++)
        {
            if(*(vec + i) != NULL && (*(vec + i))->id == id)
            {
                *pIndice = i;
                break;
            }
        }
        error = 0;
    }

    return error;
}
