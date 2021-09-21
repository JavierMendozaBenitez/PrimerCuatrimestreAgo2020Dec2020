#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

#define TAM 5

int destroyEmpleados(eEmpleado** lista, int tam);
int main()
{
    eEmpleado** lista = (eEmpleado**) malloc(sizeof(eEmpleado*)*5);
    if( lista == NULL)
    {
        printf("Problema para conseguir memoria\n");
        exit(EXIT_FAILURE);
    }

    *(lista + 0) = newEmpleadoParam(1000, "Jorge", 'm', 65300);
    *(lista + 1) = newEmpleadoParam(1001, "Juana", 'f', 54600);
    *(lista + 2) = newEmpleadoParam(1002, "Noelia", 'f', 45800);
    *(lista + 3) = newEmpleadoParam(1003, "Felipe", 'm', 76500);
    *(lista + 4) = newEmpleadoParam(1004, "Raul", 'm', 39300);

    mostrarEmpleadosP(lista, TAM);

    ordenarEmpleadosNombreP(lista, TAM);

    mostrarEmpleadosP(lista, TAM);

    destroyEmpleados(lista, TAM);

    return 0;
}

int destroyEmpleados(eEmpleado** lista, int tam)
{
    int error = 1;
    //contrario de newEmpleadoParam
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i > tam; i++)
        {
            free(*(lista + i));
        }
        free(lista);//liberas la lista, contrario a malloc
        error = 0;
    }
    return error;
}
