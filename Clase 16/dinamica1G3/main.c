#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
} eEmpleado;

void mostrarEmpleado(eEmpleado* empleado);

eEmpleado* newEmpleado();

eEmpleado* newEmpleadoParam(int legajo, char* nombre, char sexo, float sueldo);

int empleadoSetLegajo(eEmpleado* emp, int legajo);
int empleadoSetNombre(eEmpleado* emp, char* nombre);
int empleadoSetSexo(eEmpleado* emp, char sexo);
int empleadoSetSueldo(eEmpleado* emp, float sueldo);

int empleadoGetLegajo(eEmpleado* emp, int* pLegajo);
int empleadoGetNombre(eEmpleado* emp, char* pNombre);
int empleadoGetSexo(eEmpleado* emp, char* pSexo);
int empleadoGetSueldo(eEmpleado* emp, float* pSueldo);

int main()
{
    eEmpleado emp1;

    eEmpleado* pEmp2 = (eEmpleado*) malloc(sizeof(eEmpleado));

    eEmpleado* pEmp3 = newEmpleado();

    //pEmp3 = newEmpleadoParam(5000, "Javier", 'm', 45000);

    eEmpleado* pEmp4 =  newEmpleadoParam(1234, "Andrea", 'f', 45000);

    mostrarEmpleado(pEmp4);


    /*emp1.legajo = 1234;
    strcpy(emp1.nombre, "Juan");
    emp1.sexo = 'm';
    emp1.sueldo = 45000;

    pEmp2->legajo = 2233;
    strcpy(pEmp2->nombre, "Analia");
    pEmp2->sexo = 'f';
    pEmp2->sueldo = 53000;*/

    //mostrarEmpleado(&emp1);//estatico

    //mostrarEmpleado(pEmp2);//dinamico

    mostrarEmpleado(pEmp3);

    return 0;
}

void mostrarEmpleado(eEmpleado* empleado)//falta las validaciones de NULL
{
    if(empleado != NULL)
    {
        printf("%d   %s   %c   %.2f\n", empleado->legajo, empleado->nombre, empleado->sexo, empleado->sueldo);
    }
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
