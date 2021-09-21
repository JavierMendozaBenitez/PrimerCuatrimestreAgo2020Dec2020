#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/
/*int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);*/

int main()
{
    LinkedList* miLista;//cres el puntero a la lista que esta en la pila, en esta lista guardaras cada estructura empleado
    miLista = ll_newLinkedList();//constructor, tenes la lista creada en memoria, si no pones esto tira error porque la lista no apunta a nada

    int len;

    len = ll_len(miLista);//cuantos elementos tiene la lista

    printf("Cantidad de elementos: %d\n", len);

    /***************************************************************/
    //agregar elementos en la lista, hacerlo en el heap, dinamico.

    Employee* e1;
    e1 = (Employee*)malloc(sizeof(Employee));//constructor de empleado en dinamica
    //simulamos un alta como en controller_addEmployee. Pedir los datos al usuario, crearlo y agregarlo a la lista
    //usar Employee* employee_new();Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
    employee_setId(e1,100);//usas el setter para cargar campos que no habias asigna en el constructor new_param
    //e1->id = 100;//asi es sin set
    e1->horasTrabajadas = 10;//creas los datos pero aun no se cargaron a la lista, los datos ya estan en dinamica
    e1->sueldo = 50000;
    strcpy(e1->nombre, "Juan");

    //mostrarEmpleado(e1);//aun no esta en dinamica

    ll_add(miLista, e1);//cargas a la lista el empleado

    len = ll_len(miLista);//cuantos elementos tiene la lista
    printf("Cantidad de elementos: %d\n", len);


    /***************************************************************/
    //agregar elementos en la lista, hacerlo en el heap, dinamico.

    Employee* e2;
    e2 = (Employee*)malloc(sizeof(Employee));//constructor de empleado en dinamica
    //simulamos un alta como en controller_addEmployee. Pedir los datos al usuario, crearlo y agregarlo a la lista
    //usar Employee* employee_new();Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
    e2->id = 200;
    e2->horasTrabajadas = 15;//creas los datos pero aun no se cargaron a la lista, los datos ya estan en dinamica
    e2->sueldo = 40000;
    strcpy(e2->nombre, "Luis");

    //mostrarEmpleado(e2);//aun no esta en dinamica

    ll_add(miLista, e2);//cargas a la lista el empleado

    len = ll_len(miLista);//cuantos elementos tiene la lista
    printf("Cantidad de elementos: %d\n", len);

    /***************************************************************/
    //agregar elementos en la lista, hacerlo en el heap, dinamico.

    Employee* e3;
    e3 = (Employee*)malloc(sizeof(Employee));//constructor de empleado en dinamica
    //simulamos un alta como en controller_addEmployee. Pedir los datos al usuario, crearlo y agregarlo a la lista
    //usar Employee* employee_new();Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
    e3->id = 150;
    e3->horasTrabajadas = 25;//creas los datos pero aun no se cargaron a la lista, los datos ya estan en dinamica
    e3->sueldo = 70000;
    strcpy(e3->nombre, "Maria");

    //mostrarEmpleado(e3);//aun no esta en dinamica

    ll_add(miLista, e3);//cargas a la lista el empleado

    len = ll_len(miLista);//cuantos elementos tiene la lista
    printf("Cantidad de elementos: %d\n", len);

    /***************************************************************/
    //agregar elementos en la lista, hacerlo en el heap, dinamico.

    Employee* e4;
    e4 = (Employee*) malloc(sizeof(Employee));//constructor de empleado en dinamica
    //simulamos un alta como en controller_addEmployee. Pedir los datos al usuario, crearlo y agregarlo a la lista
    //usar Employee* employee_new();Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
    e4->id = 250;
    e4->horasTrabajadas = 5;//creas los datos pero aun no se cargaron a la lista, los datos ya estan en dinamica
    e4->sueldo = 100000;
    strcpy(e4->nombre, "Pedro");

    //mostrarEmpleado(e4);//aun no esta en dinamica

    ll_add(miLista, e4);//cargas a la lista el empleado

    len = ll_len(miLista);//cuantos elementos tiene la lista
    printf("Cantidad de elementos: %d\n", len);


    /***************************************************************/
    //Ahora los vamos a mostrar
    //recorremos la lista para mostar todo
    Employee* aux;//creamos un puntero Employee porque ll_get devuelve un puntero a void y tengo que castear
    printf("La lista de empleados:\n");
    len = ll_len(miLista);//lo calculamos una vez mas para mostrar cuantos elementos hay
    for(int i=0; i<len; i++)
    {
        aux = (Employee*) ll_get(miLista,i);//devuelve un puntero a void y debes colocar la lista y un indice del dato que en este cado es la i del for.
        //if(aux->sueldo > 50000)//asi mostras los que cobran mas de 50000
        {
            printf("%d-", i+1);//mostras un indice al lado de cada empleado y le sumas de a 1
            mostrarEmpleado(aux);//mostras los empleados que estan en i
        }
    }

    /***************************************************************/
    //vamos a quitar un empleado

    int index;
    index = 2;//esto deberia ingresarlo el usuario, que empleado eliminar por indice y no por id

    printf("Sacamos un empleado: \n");

    ll_remove(miLista, index-1);//colocar la lista y el index a eliminar, es index 2 posicion 1

    len = ll_len(miLista);//lo calculamos una vez mas para mostrar cuantos elementos hay
    for(int i=0; i<len; i++)
    {
        aux = (Employee*) ll_get(miLista,i);//devuelve un puntero a void y debes colocar la lista y un indice del dato que en este cado es la i del for.
        //if(aux->sueldo > 50000)//asi mostras los que cobran mas de 50000
        {
            printf("%d-", i+1);//mostras un indice al lado de cada empleado y le sumas de a 1
            mostrarEmpleado(aux);//mostras los empleados que estan en i
        }
    }

    /************************  SET  ***************************************/
    //reemplazamos algo en la lista

    Employee* e5;
    index = 2;//el usuario quiere modificar el 2
    e5 = (Employee*) malloc(sizeof(Employee));//constructor de empleado en dinamica
    //simulamos un alta como en controller_addEmployee. Pedir los datos al usuario, crearlo y agregarlo a la lista
    //usar Employee* employee_new();Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
    e5->id = 1000;
    e5->horasTrabajadas = 35;
    e5->sueldo = 100501;
    strcpy(e5->nombre, "Ana");

    ll_set(miLista, index-1, e5);//seleccionas algo para modificar, empleado en la posicion 2, reemplazas por e5

    printf("La lista de empleados con el segundo modificado:\n");
    len = ll_len(miLista);//lo calculamos una vez mas para mostrar cuantos elementos hay
    for(int i=0; i<len; i++)
    {//recorremos la list
        aux = (Employee*) ll_get(miLista,i);//devuelve un puntero a void y debes colocar la lista y un indice del dato que en este cado es la i del for.
        //if(aux->sueldo > 50000)//asi mostras los que cobran mas de 50000
        {
            printf("%d-", i+1);//mostras un indice al lado de cada empleado y le sumas de a 1
            mostrarEmpleado(aux);//mostras los empleados que estan en i
        }
    }


    /************************  PUSH  ***************************************/

    ll_push(miLista, 1, e3);//con esto agregas nuevamente un empleado que hayas eliminado, agregas a maria en la posicion 1, indice 2, el usuario deberia elegir la posicion. Pudo usar e3 porque esta en el main, deberiamos hacerlo de manera dinamica

    printf("La lista de empleados con Maria pusheada:\n");
    len = ll_len(miLista);//lo calculamos una vez mas para mostrar cuantos elementos hay
    for(int i=0; i<len; i++)
    {//recorremos la list
        aux = (Employee*) ll_get(miLista,i);//devuelve un puntero a void y debes colocar la lista y un indice del dato que en este cado es la i del for.
        //if(aux->sueldo > 50000)//asi mostras los que cobran mas de 50000
        {
            printf("%d-", i+1);//mostras un indice al lado de cada empleado y le sumas de a 1
            mostrarEmpleado(aux);//mostras los empleados que estan en i
        }
    }


    /************************  POP  ***************************************/
    /*
    aux = ll_pop(miLista, 3);//elimina un registro pero te deja mostrarlo si lo guardas en aux

    printf("Se acaba de borrar el siguiente registro: \n");
    mostrarEmpleado(aux);


    printf("La lista de empleados con siguiente popeado: \n");
    len = ll_len(miLista);//lo calculamos una vez mas para mostrar cuantos elementos hay
    for(int i=0; i<len; i++)
    {//recorremos la list
        aux = (Employee*) ll_get(miLista,i);//devuelve un puntero a void y debes colocar la lista y un indice del dato que en este cado es la i del for.
        //if(aux->sueldo > 50000)//asi mostras los que cobran mas de 50000
        {
            printf("%d-", i+1);//mostras un indice al lado de cada empleado y le sumas de a 1
            mostrarEmpleado(aux);//mostras los empleados que estan en i
        }
    }
    */

    /************************ SORT  ***************************************/
    //ordenar la lista
    //debemos crear un funcion de ordenar en Employee.h y lo colocas en el sort

    ll_sort(miLista, employee_CompareByName, 1);//de A a Z

    printf("La lista de empleados ordenados por nombre: \n");
    len = ll_len(miLista);//lo calculamos una vez mas para mostrar cuantos elementos hay
    for(int i=0; i<len; i++)
    {//recorremos la list
        aux = (Employee*) ll_get(miLista,i);//devuelve un puntero a void y debes colocar la lista y un indice del dato que en este cado es la i del for.
        //if(aux->sueldo > 50000)//asi mostras los que cobran mas de 50000
        {
            printf("%d-", i+1);//mostras un indice al lado de cada empleado y le sumas de a 1
            mostrarEmpleado(aux);//mostras los empleados que estan en i
        }
    }


    ll_sort(miLista, employee_CompareById, 0);//de menor a mayor los id

    printf("La lista de empleados ordenados por id: \n");
    len = ll_len(miLista);//lo calculamos una vez mas para mostrar cuantos elementos hay
    for(int i=0; i<len; i++)
    {//recorremos la list
        aux = (Employee*) ll_get(miLista,i);//devuelve un puntero a void y debes colocar la lista y un indice del dato que en este cado es la i del for.
        //if(aux->sueldo > 50000)//asi mostras los que cobran mas de 50000
        {
            printf("%d-", i+1);//mostras un indice al lado de cada empleado y le sumas de a 1
            mostrarEmpleado(aux);//mostras los empleados que estan en i
        }
    }


    return 0;
}

