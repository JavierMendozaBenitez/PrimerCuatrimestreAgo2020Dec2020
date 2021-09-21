#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee* nuevoEmpleado;
    nuevoEmpleado = (Employee*) malloc(sizeof(Employee));

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id = 0;
        strcpy(nuevoEmpleado->nombre, "");
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->sueldo = 0;
    }

    return nuevoEmpleado;
}

//Employee* new_EmpleadoParam(int id, char* nombre, char sexo, float sueldo)//constructor. Faltan los setters y getters
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)//recibe todo como cadena y haces la conversion aca
{
    Employee* nuevoEmpleado = employee_new();

    if(nuevoEmpleado != NULL)
    {

        /*if(personaSetId(nuevaPersona, id) ||
            personaSetNombre(nuevaPersona, nombre) ||
            personaSetSexo(nuevaPersona, sexo) ||
            personaSetAltura(nuevaPersona, altura)
          )
        {
            free(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }*/
        //nuevoEmpleado->id = id;
        nuevoEmpleado->id = atoi(idStr);
        strcpy(nuevoEmpleado->nombre, nombreStr);
        //nuevoEmpleado->sexo = sexo;
        nuevoEmpleado->horasTrabajadas = atoi(horasTrabajadasStr);//le pasas el primer caracter
        //nuevoEmpleado->sueldo = sueldo;
        nuevoEmpleado->sueldo = atoi(sueldo);//los convertis
        idStr++;
    }

    return nuevoEmpleado;
}




void employee_delete();





int employee_setId(Employee* this,int id)
{
    int error = 1;

    if(this != NULL && id >0)
    {
        this->id = id;
        error = 0;
    }

    return error;
}

int employee_getId(Employee* this,int* id)
{
    int error = 1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        error = 0;
    }

    return error;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int error = 1;

    if(this != NULL && strlen(nombre) >= 2 && strlen(nombre) < 20)//Faltan validaciones
    {
        strcpy(this->nombre, nombre);
        error = 0;
    }

    return error;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(*nombre, this->nombre);
        todoOk = 1;
    }

    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;

    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 0;

    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }

    return todoOk;
}

int employeeSortByName(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    char nombreA[128];
    char nombreB[128];

    //if(empleadoA != NULL && empleadoB != NULL)
    //{
        //Employee* empA = (Employee*)empleadoA;//casteo de una forma

        //if(employee_getNombre(empA, nombreA) &&//traes empA
             //cargas las dos cadenas con el get
        if((employee_getNombre((Employee*)empleadoA, nombreA)) &&/*traes empA*/
           (employee_getNombre((Employee*)empleadoB, nombreB)))//casteo de una forma directa
        {
            retorno = strcmp(nombreA, nombreB);
        }


    //}
    return retorno;
}

int employeeSortById(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    int idA;
    int idB;

    if((employee_getId((Employee*)empleadoA, &idA)) &&
       (employee_getId((Employee*)empleadoB, &idB)))
    {
        retorno = idA - idB;
    }

    return retorno;
}

int employeeSortByWorkHours(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    int horasA;
    int horasB;

    if((employee_getHorasTrabajadas((Employee*)empleadoA, &horasA)) &&
       (employee_getHorasTrabajadas((Employee*)empleadoB, &horasB)))
    {
        retorno = horasA - horasB;
    }

    return retorno;
}

int employeeSortBySalary(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    int sueldoA;
    int sueldoB;

    if((employee_getSueldo((Employee*)empleadoA, &sueldoA)) &&
       (employee_getSueldo((Employee*)empleadoB, &sueldoB)))
    {
        retorno = sueldoA - sueldoB;
    }

    return retorno;
}

//void printEmpleadoTexto(FILE* pFile, Employee* empleado);

int mostrarEmpleado(Employee* empleado)
{
    int error = 1;

    if(empleado != NULL )
    {
        printf("%d   %10s        %d         %d\n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
        error = 0;
    }
    return error;
}

int mostrarEmpleados(LinkedList* lista)
{
    int error = 1;
    int flag = 0;
    int tam = ll_len(lista);//le decis el tamanio
    Employee* auxEmp;

    if(lista != NULL )
    {
        error = 0;
        printf(" Id        Nombre      Sexo     Sueldo\n");
        for(int i=0; i< tam; i++)
        {
            auxEmp = (Employee*)ll_get(lista, i);//devuelve el puntero, le pasas el indice del elemento que queremos y lo guardamos en empleado. Cada vez que quieras acceder al puntero que esta en un indice haces esto
            //if(*(vec + i) != NULL)
            //if( ((eEmpleado*)ll_get(lista, i)) != NULL)//devuelve un puntero a void y lo casteas a eEmpleado*
            if( auxEmp != NULL)
            {
                mostrarEmpleado(auxEmp);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("No hay empleados para mostrar\n\n");
        }
    }
    return error;
}
