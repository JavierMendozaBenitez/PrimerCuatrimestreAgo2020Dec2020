#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "ePais.h"
#include "parser.h"
#include "validaciones.h"


/** \brief Carga los datos de los paises desde el archivo lista.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pLista)
{
    int todoOk = -1;

    FILE* pFile;

    if(path != NULL && pLista != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {
            if(!parser_EmployeeFromText(pFile, pLista))
            {
                todoOk = 0;
            }
            fclose(pFile);
        }
    }
    return todoOk;
}


/** \brief Listar paises
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pLista)
{
    mostrarPaises(pLista);

    return 0;
}

/** \brief Ordenar paises
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pLista)
{
    ll_sort(pLista, paisSortByInfectados, 0);

    return 0;
}

/** \brief Ordenar paises
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int
 *
 */
int controller_sortPaisPorMuerte(LinkedList* pLista)
{
    ll_sort(pLista, paisSortByMuertos, 0);

    return 0;
}

/** \brief Guarda los datos de los paises en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pLista)
{
    int error = 1;

    if(pLista != NULL)
    {
        FILE* archivo = fopen(path, "w");
        ePais* auxPais;
        if(archivo != NULL)
        {
            fprintf(archivo, "id,nombre,recuperados,infectados,muertos\n");
            for(int i=0; i<ll_len(pLista); i++)
            {
                auxPais = (ePais*) ll_get(pLista, i);
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
