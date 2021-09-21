#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

typedef struct
{
    int id;
    char nombre[120];
    char sexo;
    float sueldo;
}eEmpleado;

eEmpleado* new_Empleado();//esto para hacerlo en memoria dinamica
//eEmpleado* new_EmpleadoParam(int id, char* nombre, char sexo, float sueldo);//esto para hacerlo en memoria dinamica
eEmpleado* new_EmpleadoParam(char* id, char* nombre, char* sexo, char* sueldo);//recibe todo como cadena y haces la conversion aca

int mostrarEmpleados(LinkedList* lista);
int mostrarEmpleado(eEmpleado* empleado);
int compararEmpleadosId(void* emp1, void* emp2);

int main()
{
    int option = 0;
    eEmpleado* auxiliarEmpleado;
    LinkedList* listaEmpleados = ll_newLinkedList();

    //printf("Cant %d\n", ll_len(listaEmpleados));

    //mostrarEmpleados(listaEmpleados);
    auxiliarEmpleado = new_EmpleadoParam("1122", "Josecito", "m", "24500.50");
    ll_add(listaEmpleados, auxiliarEmpleado);

    //mostrarEmpleados(listaEmpleados);

    auxiliarEmpleado = new_EmpleadoParam("3434", "Juanita", "f", "38500.50");
    ll_add(listaEmpleados, auxiliarEmpleado);

    //mostrarEmpleados(listaEmpleados);

    auxiliarEmpleado = new_EmpleadoParam("2211", "Alfredo", "m", "48500.50");
    ll_add(listaEmpleados, auxiliarEmpleado);

    auxiliarEmpleado = new_EmpleadoParam("8888", "Natalia", "f", "32500.50");
    ll_add(listaEmpleados, auxiliarEmpleado);

    auxiliarEmpleado = new_EmpleadoParam("5400", "Ramiro", "m", "23000.50");
    ll_add(listaEmpleados, auxiliarEmpleado);

    auxiliarEmpleado = (eEmpleado*) ll_get(listaEmpleados, 2);

    auxiliarEmpleado->sueldo = auxiliarEmpleado->sueldo + 1.5;


    //ll_sort(listaEmpleados, compararEmpleadosId, 1);//mayor a menor
    ll_sort(listaEmpleados, compararEmpleadosId, 0);//menor a mayor

    mostrarEmpleados(listaEmpleados);


    //ll_remove(listaEmpleados, 1);
   // printf("Cant %d\n", ll_len(listaEmpleados));
    /*do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);*/

    ll_deleteLinkedList(listaEmpleados);

    return 0;
}

int mostrarEmpleado(eEmpleado* empleado)
{
    int error = 1;

    if(empleado != NULL )
    {
        printf("%d   %10s        %c         %.2f\n", empleado->id, empleado->nombre, empleado->sexo, empleado->sueldo);
        error = 0;
    }
    return error;
}

int mostrarEmpleados(LinkedList* lista)
{
    int error = 0;
    int flag = 0;
    int tam = ll_len(lista);//le decis el tamanio
    eEmpleado* auxEmp;

    if(lista != NULL )
    {
        error = 1;
        printf(" Id        Nombre      Sexo     Sueldo\n");
        for(int i=0; i< tam; i++)
        {
            auxEmp = (eEmpleado*)ll_get(lista, i);//devuelve el puntero, le pasas el indice del elemento que queremos y lo guardamos en empleado. Cada vez que quieras acceder al puntero que esta en un indice haces esto
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
eEmpleado* new_Empleado()
{
    return (eEmpleado*) malloc(sizeof(eEmpleado));
}

//eEmpleado* new_EmpleadoParam(int id, char* nombre, char sexo, float sueldo)//constructor. Faltan los setters y getters
eEmpleado* new_EmpleadoParam(char* id, char* nombre, char* sexo, char* sueldo)//recibe todo como cadena y haces la conversion aca
{
    eEmpleado* nuevoEmpleado = new_Empleado();

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
        nuevoEmpleado->id = atoi(id);
        strcpy(nuevoEmpleado->nombre, nombre);
        //nuevoEmpleado->sexo = sexo;
        nuevoEmpleado->sexo = sexo[0];//le pasas el primer caracter
        //nuevoEmpleado->sueldo = sueldo;
        nuevoEmpleado->sueldo = atof(sueldo);//los convertis
    }

    return nuevoEmpleado;
}

int compararEmpleadosId(void* emp1, void* emp2)
{
    int rta;
    eEmpleado* a = (eEmpleado*) emp1;
    eEmpleado* b = (eEmpleado*) emp2;

    if(a-> id == b->id)
    {
        rta = 0;
    }
    else if(a-> id > b->id)
    {
        rta = -1;
    }
    else
    {
        rta = 1;
    }

    return rta;
}
