#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarAlumnos(int legajos[], int notasP1[], int notasP2[], float promedios[], char sexos[], int tam[]);
void mostrarAlumno(int legajo, int n1, int n2, float promedio, char sexo);
int main()
{
    int legajos[TAM]= {234, 4444, 5555, 8989, 5656};
    int notas1[TAM]= {2,5,6,7,10};
    int notas2[TAM]= {6,1,9,8,7};
    float promedios[TAM]= {6.5,8,4.6,10,9};
    char sexos[TAM]= {'f','f','m','f','m'};
    int auxInt;
    float auxFloat;
    char auxChar;

    /*
    for(int i=0; i < TAM; i++)
    {
        printf("Ingrese legajo: ");
        fflush(stdin);
        scanf("%d", &legajos[i]);

        printf("Ingrese nota primer parcial: ");
        scanf("%d", &notas1[i]);

        printf("Ingrese nota segundo parcial: ");
        fflush(stdin);
        scanf("%d", &notas2[i]);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexo[i]);

        promedios[i] = (float) (notas1[i] + notas2[i])/2;

    }*/

    mostrarAlumnos(legajos, notas1, notas2, promedios, sexos, TAM);
    //ordenar los alumnos por promedio descendente
    for(int i=0; i < TAM -1; i++)//va del primero al anteultimo por eso arranca en cero y termina en el anteultimo
    {
        for(int j = i + 1; j < TAM; j++)//va del segundo al ultimo
        {
            if((sexos[i] > sexos[j]) || sexos[i] == sexos[j] && promedios[i] > promedios[j])
            {
                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxInt = notas1[i];
                notas1[i] = notas1[j];
                notas1[j] = auxInt;

                auxInt = notas2[i];
                notas2[i] = notas2[j];
                notas2[j] = auxInt;

                auxFloat = promedios[i];
                promedios[i] = promedios[j];
                promedios[j] = auxFloat;

                auxChar = sexos[i];
                sexos[i] = sexos[j];
                sexos[j] = auxChar;
            }
        }
    }

    mostrarAlumnos(legajos, notas1, notas2, promedios, sexos, TAM);

    return 0;
}

void mostrarAlumnos(int legajos[], int notasP1[], int notasP2[], float promedios[], char sexos[], int tam[])
{
    printf(" Legajo  NotaP1  NotaP2  Promedio  Sexo\n\n");

    for(int i=0; i< TAM; i++)
    {
        mostrarAlumno(legajos[i], notasP1[i], notasP2[i], promedios[i], sexos[i]);
    }

    printf("\n\n");
}

void mostrarAlumno(int legajo, int n1, int n2, float promedio, char sexo)
{
    printf("   %0.4d     %0.2d     %0.2d     %2.2f      %c\n", legajo, n1, n2, promedio, sexo);

}
