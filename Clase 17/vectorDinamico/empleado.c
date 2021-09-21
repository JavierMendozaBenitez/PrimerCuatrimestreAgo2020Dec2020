#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"


void mostrarEmpleadoRef(eEmpleado* empleado)//falta las validaciones de NULL
{
    if(empleado != NULL)
    {
        printf("%d   %10s   %c   %.2f\n", empleado->legajo, empleado->nombre, empleado->sexo, empleado->sueldo);
    }
}

void mostrarEmpleado(eEmpleado empleado)//falta las validaciones de NULL
{
    printf("%d   %10s   %c   %.2f\n", empleado.legajo, empleado.nombre, empleado.sexo, empleado.sueldo);
    /*if(empleado != NULL)
    {
        printf("%d   %10s   %c   %.2f\n", empleado.legajo, empleado.nombre, empleado.sexo, empleado.sueldo);
    }*/
}

eEmpleado* newEmpleado()//constructor de un empleado
{
    eEmpleado* nuevoEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado));

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->legajo = 0;
        strcpy(nuevoEmpleado->nombre, "Natalia Natalia");
        nuevoEmpleado->sexo = '-';
        nuevoEmpleado->sueldo = 0;
    }
    return nuevoEmpleado;
}

eEmpleado* newEmpleadoParam(int legajo, char* nombre, char sexo, float sueldo)
{
    eEmpleado* nuevoEmpleado = newEmpleado();

    if(nuevoEmpleado != NULL)
    {
        if(!(//si esto falla (0) al negarlo con ! da 1, entonces libera la memoria. Si funciona viene con un 1, sino con un 0. Si uno falla libera.
             empleadoSetLegajo(nuevoEmpleado, legajo) &&
             empleadoSetNombre(nuevoEmpleado, nombre) &&
             empleadoSetSexo(nuevoEmpleado, sexo) &&
             empleadoSetSueldo(nuevoEmpleado, sueldo))
          )
        {
            free(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }
    }
    return nuevoEmpleado;
}

int empleadoSetLegajo(eEmpleado* emp, int legajo)
{
    int todoOk = 0;

    if(emp != NULL && legajo > 0)
    {
        emp->legajo = legajo;
        todoOk = 1;
    }

    return todoOk;
}

int empleadoSetNombre(eEmpleado* emp, char* nombre)
{
    int todoOk = 0;

    if(emp != NULL && nombre != NULL && strlen(nombre) >= 3 && strlen(nombre) < 20)//Faltan validaciones)
    {
        strcpy(emp->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;
}

int empleadoSetSexo(eEmpleado* emp, char sexo)
{
    int todoOk = 0;

    if(emp != NULL && (sexo == 'f' || sexo == 'm'))
    {
        emp->sexo = sexo;
        todoOk = 1;
    }

    return todoOk;
}

int empleadoSetSueldo(eEmpleado* emp, float sueldo)
{
    int todoOk = 0;

    if(emp != NULL && sueldo > 0)
    {
        emp->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;
}


int empleadoGetLegajo(eEmpleado* emp, int* pLegajo)
{
    int todoOk = 0;

    if(emp != NULL && pLegajo != NULL)
    {
        *pLegajo = emp->legajo;
        todoOk = 1;
    }

    return todoOk;
}

int empleadoGetNombre(eEmpleado* emp, char* pNombre)
{
    int todoOk = 0;

    if(emp != NULL && pNombre != NULL)
    {
        strcpy(*pNombre, emp->nombre);
        todoOk = 1;
    }

    return todoOk;
}
int empleadoGetSexo(eEmpleado* emp, char* pSexo)
{
    int todoOk = 0;

    if(emp != NULL && pSexo != NULL)
    {
        *pSexo = emp->sexo;
        todoOk = 1;
    }

    return todoOk;
}

int empleadoGetSueldo(eEmpleado* emp, float* pSueldo)
{
    int todoOk = 0;

    if(emp != NULL && pSueldo != NULL)
    {
        *pSueldo = emp->sueldo;
        todoOk = 1;
    }

    return todoOk;
}

int mostrarEmpleados(eEmpleado* lista, int tam)
{
    int error = 1;

    if(lista != NULL && tam > 0)
    {
        printf("Lista de empleados\n");
        printf("  Legajo  Nombre  Sexo  Sueldo\n\n");
        for(int i=0; i < tam; i++)
        {
            //mostrarEmpleado(*(lista + i));//estructura empleado
            //mostrarEmpleadoRef(lista + i);//valor en esa direccion de memoria de un empleado
            mostrarEmpleado(*(lista + i));
        }

        error = 0;
    }

    return error;
}

int ordenarEmpleadosNombre(eEmpleado* lista, int tam)
{
    int error = 1;

    eEmpleado auxEmp;
    if(lista != NULL && tam > 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {
                //if(strcmp( (*(lista + i)).nombre ))
                if(strcmp( (lista + i)->nombre, (lista+j)->nombre ) > 0)
                {
                    auxEmp = *(lista + i);//valor en esa direccion de memoria
                    *(lista + i) = *(lista + j),
                    *(lista + j) = auxEmp;
                }
            }
        }
        error = 0;
    }
    return error;
}

int mostrarEmpleadosP(eEmpleado** lista, int tam)
{
    int error = 1;

    if(lista != NULL && tam > 0)
    {
        printf("Lista de empleados\n");
        printf("  Legajo  Nombre  Sexo  Sueldo\n\n");
        for(int i=0; i < tam; i++)
        {
            mostrarEmpleadoRef(*(lista + i));
        }

        error = 0;
    }
}
