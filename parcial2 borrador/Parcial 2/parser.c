#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "ePais.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    ePais* auxPais;
    int error = -1;
    int cant;
    char buffer[5][100];

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
    //printf("%s  %s  %s  %s  %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);


    while(!feof(pFile))
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

        if(cant == 5)
        {
            auxPais = pais_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
            ll_add(pArrayListEmployee, auxPais);
            error = 0;
        }
        else
        {
            break;
        }
    }
    int len = ll_len(pArrayListEmployee);
    printf("Cantidad de elementos: %d\n", len);
    system("pause");

    return error;
}
