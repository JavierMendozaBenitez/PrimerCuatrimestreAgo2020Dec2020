#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"

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

int main()
{

    char seguir = 's';
    char confirma;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        switch(menuInt())
        {
        case 1:
            if(controller_loadFromText("data.csv", listaEmpleados) != 0)
            {
                printf("Problema para cargar los empleados\n");
            }
            else
            {
                printf("Empleados cargados correctamente\n");
            }
            break;
        case 2:
            if(controller_loadFromBinary("data.bin", listaEmpleados) != 0)
            {
                printf("Problema para cargar los empleados\n");
            }
            else
            {
                printf("Empleados cargados correctamente\n");
            }
            break;
        case 3:
            if(controller_addEmployee(listaEmpleados) == 0)
            {
                printf("Empleado agregado con exito\n\n");
            }
            break;
        case 4:
            if(controller_editEmployee(listaEmpleados) == 0)
            {
                printf("Empleado modificado con exito\n\n");
            }
            break;
        case 5:
            if(controller_removeEmployee(listaEmpleados) == 0)
            {
                printf("Empleado quitado con exito\n\n");
            }
            break;
        case 6:
            if(controller_ListEmployee(listaEmpleados) == 0)
            {
                printf("Empleados listados con exito\n\n");
            }
            break;
        case 7:
            if(controller_sortEmployee(listaEmpleados) == 0)
            {
                printf("Empleados ordenados con exito\n\n");
            }
            break;
        case 8:
            if(controller_saveAsText("data.csv", listaEmpleados) == 0)
            {
                printf("Listas en texto realizadas con exito\n\n");
            }
            else
            {
                printf("Problema para guardar los empleados\n");
            }
            break;
        case 9:
            if(controller_saveAsBinary("data.bin", listaEmpleados) == 0)
            {
                printf("Listas en binario realizadas con exito\n\n");
            }
            else
            {
                printf("Problema para guardar los empleados\n");
            }
            break;
        case 10:
            printf("Confirma salida? Presione s para si o n para no: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        default:
            printf("Opcion invalida!!!\n");
        }
        system("pause");
    }
    while(seguir == 's');

    return 0;
}
/*
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    char buffer[4][100];//es para guardar todos los datos en esta matriz en cada fila, leeremos todo como texto

    //Employee* pArrayListEmployee;

//    Employee* nuevoEmpleado;

    char* path;
    int cant;

    //FILE* f;

    //f = fopen("data.csv", "r");//lo creamos en file3, lo creamos como csv texto y lo leo con uno que lee csv
    //pFile = fopen("data.csv", "r");//lo creamos en file3, lo creamos como csv texto y lo leo con uno que lee csv
    pFile = fopen(path, "rb");
    //if(f == NULL)
    if(pFile == NULL)
    {
        printf("No se pudo abrir el archivojj\n");
        exit(EXIT_FAILURE);
    }

    //fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);//lectura fantasma, es para que haga una sola lectura y salteas la primera linea que es un encabezado
    //printf("\n%s  %s  %s  %s\n", buffer[0], buffer[1], buffer[2], buffer[3]);//asi podes mostrar el encbezado antes del while

    while(!feof(pFile))//con feof recorres hasta que encuentre el final del archivo, son los datos de un empleado
    {
        //cant = fscanf(f,"%d,%[^,],%c,%f\n", &id, nombre, &sexo, &sueldo);//le decis que tiene que leer, asi levanta la primera linea, el cursor quedo al inicio de la segunda linea
        //cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);//ahora leo todo como texto

        fread(&pArrayListEmployee, sizeof(LinkedList), 1000, pFile);
        pArrayListEmployee = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

        /*if(cant == 4)//mostras si devolvio 4 variables en fscanf
        {
            //auxEmpleado = new_EmpleadoParam(id, nombre, sexo, sueldo);//validar que sea distinto de null, primera version
            //auxEmpleado = new_EmpleadoParam(atoi(buffer[0]), buffer[1], buffer[2][0], atof(buffer[3]));//ahora convierto los caracteres en el tipo de dato que necesito cuando llamo al constructor
        /*!=NULL*////nuevoEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);//ahora ya estan convertidos entoces le paso los buffer sin el atoi o el atof
        //pArrayListEmployee = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
        //auxiliarEmpleado = new_EmpleadoParam("3434", "Juanita", "f", "38500.50");
        //ll_add(pArrayListEmployee, nuevoEmpleado);
        //printf("%d %s %d %d\n", nuevoEmpleado->id, nuevoEmpleado->nombre, nuevoEmpleado->horasTrabajadas, nuevoEmpleado->sueldo);//si pude leer lo muestro
        /*}
        else
        {
            break;//asi salis del while si no hay 4
        }*/
    /*}

    fclose(pFile);



    return 0;
}
*/
