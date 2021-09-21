/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    float sueldo;
}eEmpleado;

void mostrarEmpleados(LinkedList* lista)
{
    int tam = ll_len(lista);
    eEmpleado* emp;
    for(int i = 0; i < tam; i++)
    {
        emp = (eEmpleado*)ll_get(lista, i);//cargas en emp los punteros a los elementos de la lista cargada para despues mostrarlo
        printf("%d  %s  %c  %.2f\n", emp->id, emp->nombre, emp->sexo, emp->sueldo);
    }
    printf("\n\n");
}

int filtrarVarones(void* elemento)
{
    int rta = 0;
    eEmpleado* e = (eEmpleado*) elemento;//casteas el elemento a lo que quieras filtrar

    if(e->sexo == 'm')
    {
        rta = 1;
    }

    return rta;  //devuelve 1 si logro filtrar
}

int filtrarMas30(void* elemento)
{
    int rta = 0;
    eEmpleado* e = (eEmpleado*) elemento;//casteas el elemento a lo que quieras filtrar

    if(e->sueldo >= 30000)
    {
        rta = 1;
    }

    return rta;  //devuelve 1 si logro filtrar
}

int main(void)
{
    eEmpleado e1 = {1, "Juan", 'm', 12000};
    eEmpleado e2 = {2, "Juana", 'f', 60000};
    eEmpleado e3 = {3, "Natalia", 'f', 34000};
    eEmpleado e4 = {4, "Julieta", 'f', 45000};
    eEmpleado e5 = {5, "Arturo", 'm', 67000};
    eEmpleado e6 = {6, "Joaquin", 'm', 28000};
    eEmpleado e7 = {7, "Miguel", 'm', 30000};

    LinkedList* lista = ll_newLinkedList();
    LinkedList* varones = NULL;
    LinkedList* ganadores = NULL;

    ll_add(lista, &e1);
    ll_add(lista, &e2);
    ll_add(lista, &e3);
    ll_add(lista, &e4);
    ll_add(lista, &e5);
    ll_add(lista, &e6);
    ll_add(lista, &e7);

    int len = ll_len(lista);
    printf("Lista tiene %d\n", len);
    system("pause");

    mostrarEmpleados(lista);

    varones = ll_filter(lista, filtrarVarones);//varones es la nueva lista con los filtrados

    mostrarEmpleados(varones);

    ganadores = ll_filter(lista, filtrarMas30);

    mostrarEmpleados(ganadores);

    ganadores = ll_filter(varones, filtrarMas30);

    mostrarEmpleados(ganadores);

    ll_deleteLinkedList(lista);
    ll_deleteLinkedList(varones);
    ll_deleteLinkedList(ganadores);//eliminas los elementos y el LinkedList

    // startTesting(1);  // ll_newLinkedList
     //startTesting(2);  // ll_len
       // startTesting(3);  // getNode - test_getNode
        //startTesting(4);  // addNode - test_addNode
          // startTesting(5);  // ll_add
        //startTesting(6);  // ll_get
        //startTesting(7);  // ll_set
        //startTesting(8);  // ll_remove
//        startTesting(9);  // ll_clear
//        startTesting(10); // ll_deleteLinkedList
//        startTesting(11); // ll_indexOf
//        startTesting(12); // ll_isEmpty
//        startTesting(13); // ll_push
//        startTesting(14); // ll_pop
//        startTesting(15); // ll_contains
//        startTesting(16); // ll_containsAll
//        startTesting(17); // ll_subList
//        startTesting(18); // ll_clone
//        startTesting(19); // ll_sort */

    return 0;
}

































