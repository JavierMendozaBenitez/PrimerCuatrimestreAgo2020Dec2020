#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

int employee_setId(Employee* this,int id)
{//hacer todas las validaciones y return
    this->id = id;
}

int employee_getId(Employee* this,int* id)
{//hacer todas las validaciones y return
    *id = this->id;
}


int employee_CompareByName(Employee* e1, Employee* e2)
{
    return strcmp(e1->nombre, e2->nombre);
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    int comp = 0;//si es igual vale 0

    if(e1->id > e2->id)
    {
        comp = 1;
    }
    else
    {
        if(e1->id < e2->id)
        {
            comp = -1;
        }
    }

    return comp;
}

/*void mostrarEmpleado(Employee* unEmpleado)
{
    printf("%4d  %15s  %8d  %8d\n", unEmpleado->id, unEmpleado->nombre, unEmpleado->horasTrabajadas, unEmpleado->sueldo);
}*/

void mostrarEmpleado(Employee* unEmpleado)//deberia devolver un int de returno, no van flechas afuera de la estructura, son funciones para no mostrar flechas
{
    int id;

    employee_getId(unEmpleado, &id);//devuelve un 1 o 0 si se pudo obtener el dato o no, llamas a la funcion y te llevas el puntero, evitas las flechitas
    //se ejecuta el printf si todos los get pudieron obtener el dato
    printf("%4d  %15s  %8d  %8d\n", id,
           unEmpleado->nombre,
           unEmpleado->horasTrabajadas,
           unEmpleado->sueldo);
}


