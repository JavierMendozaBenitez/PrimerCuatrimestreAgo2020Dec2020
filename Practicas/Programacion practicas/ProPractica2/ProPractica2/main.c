#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAM 5

typedef struct
{
    int id;
    float dato;
    char nombre[20];
} eParcial;

int ordenarParcialIdNombre(eParcial examen[], int tam);
void mostrarParcial(eParcial examen, int tam);
int mostrarParciales(eParcial examen[], int tam);

int main()
{
    eParcial examen [TAM] =
    {
        {1132, 1.78, "Ana"},
        {1132, 1.75, "AAAA"},
        {1112, 1.78, "Matias"},
        {1102, 1.75, "Nicolas"},
        {1152, 1.78, "Felix"},
    };

    if(ordenarParcialIdNombre(examen, TAM) == 0)
    {
        mostrarParciales(examen, TAM);
    }

    return 0;
}

void mostrarParcial(eParcial examen, int tam)
{
    printf(" %5d     %10f    %10s\n", examen.id, examen.dato, examen.nombre);
}

int mostrarParciales(eParcial examen[], int tam)
{
    int error = 1;

    if(examen != NULL && tam > 0)
    {
        printf("   *** Listado de parciales ***\n");
        printf("----------------------------------------------------------------------\n");
        printf(" Id           dato             nombre  \n\n");

        for(int i = 0; i < tam; i++)
        {
            mostrarParcial(examen[i], tam);

        }
    }
    return error;
}

int ordenarParcialIdNombre(eParcial examen[], int tam)
{
    int error = 1;
    eParcial auxParcial;

    if(examen != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(examen[i].id > examen[j].id)
                {
                    auxParcial = examen[i];
                    examen[i] = examen[j];
                    examen[j] = auxParcial;
                }
                else
                {
                    if((examen[i].id == examen[j].id) && strcmp(examen[i].nombre, examen[j].nombre)>0)
                    {
                        auxParcial = examen[i];
                        examen[i] = examen[j];
                        examen[j] = auxParcial;
                    }
                }
            }
        }
        error = 0;
    }
    return error;
}
