#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "ePais.h"
#include "parser.h"
#include "validaciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
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
            fclose(pFile);
        }
    }
    return todoOk;
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
    mostrarPaises(pArrayListEmployee);

    return 0;
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
    ll_sort(pArrayListEmployee, paisSortByInfectados, 0);

    return 0;
}

/** \brief Ordenar paises
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortPaisPorMuerte(LinkedList* pArrayListEmployee)
{
    ll_sort(pArrayListEmployee, paisSortByMuertos, 0);

    return 0;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int error = 1;

    if(pArrayListEmployee != NULL)
    {
        FILE* archivo = fopen(path, "w");
        ePais* auxPais;
        if(archivo != NULL)
        {
            fprintf(archivo, "id,nombre,recuperados,infectados,muertos\n");
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                auxPais = (ePais*) ll_get(pArrayListEmployee, i);
                if(auxPais != NULL)
                {
                    fprintf(archivo, "%d,%s,%d,%d,%d\n", auxPais->id, auxPais->nombrePais, auxPais->recuperados, auxPais->infectados, auxPais->muertos);
                    error = 0;
                }
            }
            fclose(archivo);
        }
    }

    return error;
}
