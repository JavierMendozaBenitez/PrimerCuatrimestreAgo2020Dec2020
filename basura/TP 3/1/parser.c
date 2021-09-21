#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmpleado;
    int error = -1;
    int cant;
    char buffer[4][100];


    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);//lectura fantasma, es para que haga una sola lectura y salteas la primera linea que es un encabezado
    printf("%s  %s  %s  %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]);//asi podes mostrar el encbezado antes del while

    while(!feof(pFile))
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);//ahora leo todo como texto

        if(cant == 4)
        {
            auxEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
            ll_add(pArrayListEmployee, auxEmpleado);
            printf("%d %s %d %d\n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado->horasTrabajadas, auxEmpleado->sueldo);
            error = 0;
        }
        else
        {
            break;
        }
    }

    return error;
}
/*int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* nuevoEmpleado;
    char buffer[4][100];
    char* path;
    int cant;

    pFile = fopen(path, "r");

    if(pFile == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        //fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);//lectura fantasma, es para que haga una sola lectura y salteas la primera linea que es un encabezado
        //printf("%s  %s  %s  %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]);//asi podes mostrar el encbezado antes del while

        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);//ahora leo todo como texto

            if(cant == 4)
            {
              nuevoEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
              ll_add(pArrayListEmployee, nuevoEmpleado);
              //printf("%s,%s,%s,%s\n", buffer[0], buffer[1], buffer[2], buffer[3]);
              printf("%d %s %d %d\n", nuevoEmpleado->id, nuevoEmpleado->nombre, nuevoEmpleado->horasTrabajadas, nuevoEmpleado->sueldo);
            }
            else
            {
                break;
            }
        }
    }
    fclose(pFile);

    return 0;
}*/

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmpleado;
    int error = -1;
    int cant;
    char buffer[4][100];


    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);//lectura fantasma, es para que haga una sola lectura y salteas la primera linea que es un encabezado
    printf("%s  %s  %s  %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]);//asi podes mostrar el encbezado antes del while

    while(!feof(pFile))
    {
        fread(&auxEmpleado, sizeof(Employee*), 1, pFile);
    }
    error = 0;

    return error;
}
/*int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* nuevoEmpleado;

    int cant;
    //char buffer[4][100];
    char* path;

    pFile = fopen(path, "rb");

    if(pFile == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        while(!feof(pFile))
        {
            //cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);//ahora leo todo como texto
            //if(cant == 4)
            //{
                fread(&nuevoEmpleado, sizeof(Employee*), 1, pFile);
                 //nuevoEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
              //ll_add(pArrayListEmployee, nuevoEmpleado);
              //printf("%s,%s,%s,%s\n", buffer[0], buffer[1], buffer[2], buffer[3]);
              //printf("%d %s %d %d\n", nuevoEmpleado->id, nuevoEmpleado->nombre, nuevoEmpleado->horasTrabajadas, nuevoEmpleado->sueldo);
            //}
            //else
            //{
             //   break;
            //}
        }
    }
//printf("%d %s %d %d\n", &nuevoEmpleado->id, nuevoEmpleado->nombre, nuevoEmpleado->horasTrabajadas, nuevoEmpleado->sueldo);
    fclose(pFile);

    return 0;
}*/

