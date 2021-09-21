#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = -1;

    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {
            if(!parser_EmployeeFromText(pFile, pArrayListEmployee))
            {
                todoOk = 0;
            }
        }
    }
    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = -1;

    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "rb");

        if(pFile != NULL)
        {
            if(!parser_EmployeeFromBinary(pFile, pArrayListEmployee))
            {
                todoOk = 0;
            }
        }
    }
    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* nuevoEmpleado;

    char id [120]= "1001";
    char nombre[20];
    char horasTrabajadas[20];
    char sueldo[20];

    FILE* agregar;

    agregar = fopen("data.csv", "a");

    if(agregar == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }


    /*printf("Ingrese Nombre\n");
    fflush(stdin);
    scanf("%s", &nuevoEmpleado->nombre);
    while(employee_setNombre(nuevoEmpleado, nuevoEmpleado->nombre) != 0)
    {
        printf("Reingrese un nombre valido.\n");
        scanf("%s", &nuevoEmpleado->nombre);
    }
    printf("Nombre ingresado: %s\n", nuevoEmpleado->nombre);



    printf("Ingrese Horas Trabajadas\n");
    fflush(stdin);
    scanf("%d", &nuevoEmpleado->horasTrabajadas);
    while(employee_setHorasTrabajadas(nuevoEmpleado, nuevoEmpleado->horasTrabajadas) == 0)
    {
        printf("Reingrese Horas Trabajadas validas.\n");
        scanf("%d", &nuevoEmpleado->horasTrabajadas);
    }
    printf("Horas ingresadas: %d\n", nuevoEmpleado->horasTrabajadas);



    printf("Ingrese Sueldo\n");
    fflush(stdin);
    scanf("%d", &nuevoEmpleado->sueldo);
    while(employee_setSueldo(nuevoEmpleado, nuevoEmpleado->sueldo) == 0)
    {
        printf("Reingrese sueldo.\n");
        scanf("%d", &nuevoEmpleado->sueldo);
    }
    printf("Sueldo ingresado: %d\n", nuevoEmpleado->sueldo);



    nuevoEmpleado->id = id;
    if(employee_setId(nuevoEmpleado, nuevoEmpleado->id) == 0)
    {
        printf("Le corresponde el ID: %d\n", nuevoEmpleado->id);
        nuevoEmpleado->id++;
    }*/

    //printf("Le corresponde el ID: %d\n", nuevoEmpleado->id);

    printf("Ingrese Nombre\n");
    fflush(stdin);
    scanf("%s", &nombre);
    /*while(employee_setNombre(nuevoEmpleado, nuevoEmpleado->nombre) != 0)
    {
        printf("Reingrese un nombre valido.\n");
        scanf("%s", &nuevoEmpleado->nombre);
    }*/
    printf("Nombre ingresado: %s\n", nombre);



    printf("Ingrese Horas Trabajadas\n");
    fflush(stdin);
    scanf("%s", &horasTrabajadas);
    /*while(employee_setHorasTrabajadas(nuevoEmpleado, nuevoEmpleado->horasTrabajadas) == 0)
    {
        printf("Reingrese Horas Trabajadas validas.\n");
        scanf("%s", &nuevoEmpleado->horasTrabajadas);
    }*/
    printf("Horas ingresadas: %s\n", horasTrabajadas);



    printf("Ingrese Sueldo\n");
    fflush(stdin);
    scanf("%s", &sueldo);
    /*while(employee_setSueldo(nuevoEmpleado, nuevoEmpleado->sueldo) == 0)
    {
        printf("Reingrese sueldo.\n");
        scanf("%s", &nuevoEmpleado->sueldo);
    }*/
    printf("Sueldo ingresado: %s\n", sueldo);



     /*strcpy(nuevoEmpleado->id, id);
   if(employee_setId(nuevoEmpleado, nuevoEmpleado->id) == 0)
    {
        printf("Le corresponde el ID: %s\n", nuevoEmpleado->id);
        nuevoEmpleado->id++;
    }
*/
    fprintf(agregar, "%s,%s,%s,%s", id, nombre, horasTrabajadas, sueldo);

    nuevoEmpleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);



    //nuevoEmpleado = employee_newParametros("22222", "pepepep", "9999999", "11111111");
    //ll_add(pArrayListEmployee, nuevoEmpleado);
    //printf("%d %s %d %d\n", nuevoEmpleado->id, nuevoEmpleado->nombre, nuevoEmpleado->horasTrabajadas, nuevoEmpleado->sueldo);

    fclose(agregar);

    return 0;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

