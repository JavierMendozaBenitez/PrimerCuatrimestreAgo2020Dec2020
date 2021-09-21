#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

#define TAM 5

int main()
{

    eEmpleado* lista = (eEmpleado*) malloc(sizeof(eEmpleado)*5);

    if(lista == NULL)
    {
        printf("Problema para conseguir memoria\n\n");
        exit(EXIT_FAILURE);
    }

    (lista + 0)->legajo = 1000;
    strcpy((lista + 0)->nombre, "Juan");
    (lista + 0)->sexo = 'm';
    (lista + 0)->sueldo = 50000;

    (lista + 1)->legajo = 1001;
    strcpy((lista + 1)->nombre, "Amalia");
    (lista + 1)->sexo = 'f';
    (lista + 1)->sueldo = 52300;

    (lista + 2)->legajo = 1002;
    strcpy((lista + 2)->nombre, "Miguel");
    (lista + 2)->sexo = 'm';
    (lista + 2)->sueldo = 41700;

    (lista + 3)->legajo = 1003;
    strcpy((lista + 3)->nombre, "Sofia");
    (lista + 3)->sexo = 'm';
    (lista + 3)->sueldo = 38400;

    (lista + 4)->legajo = 1004;
    strcpy((lista + 4)->nombre, "Luisa");
    (lista + 4)->sexo = 'f';
    (lista + 4)->sueldo = 43200;

    mostrarEmpleados(lista, TAM);

    ordenarEmpleadosNombre(lista, TAM);

    mostrarEmpleados(lista, TAM);

    return 0;
}
