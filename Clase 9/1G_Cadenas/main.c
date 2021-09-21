#include <stdio.h>
#include <stdlib.h>
#define TAM 5
#define LEN 20

//void CargarNombres(char [][20], int sizeNombres);
//void MostrarUnNombre(char unNombre[]);
//void MostrarTodosLosNombres(char [][20], int sizeNombres);

void CargarAlumnos(char nombres[][20], int legajos[], float promedios[], int edades[], int sizeT);
void MostrarTodosLosNombres(char nombres[][20], int legajos[], float promedios[], int edades[], int sizeT);
void MostrarUnAlumno(char unNombre[], int unLegajo, float unPromedio, int unaEdad);
void OrdenarAlumnosPorNombre(char nombres[][20], int legajos[], float promedios[], int edades[], int sizeT);

int main()
{
    char nombres[TAM][LEN]= {"Jose","Maria","Pedro","Christian","German"}; //5 filas por 20 columnas, 5 nomobres de 19 caracteres
    //char nombres[TAM][LEN];
    int legajos[TAM]= {100,105,101,103,109};
    float promedios[TAM]= {7,7.5,9,4.66,8};
    int edades[TAM]= {20,18,46,55,34};

    //CargarAlumnos(nombres, legajos, promedios, edades, TAM);
    MostrarTodosLosNombres(nombres, legajos, promedios, edades, TAM);
    OrdenarAlumnosPorNombre(nombres, legajos, promedios, edades, TAM);
    //CargarNombres(nombres, TAM);

    //MostrarTodosLosNombres(nombres, TAM);

    return 0;
}
void OrdenarAlumnosPorNombre(char nombres[][20], int legajos[], float promedios[], int edades[], int sizeT)
{
    int auxInt;
    float auxFloat;
    char auxString[20];
    for(int i=0; i<sizeT; i++)
    {
        for(int j=i+1; j<sizeT; j++)
        {
            if(strcmp(nombres[i], nombres[j])>0)
            {
                strcpy(auxString, nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j],auxString);

                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxInt = promedios[i];
                promedios[i] = promedios[j];
                promedios[j] = auxInt;

                auxInt = edades[i];
                edades[i] = edades[j];
                edades[j] = auxInt;
            }
        }
    }
}
void CargarAlumnos(char nombres[][20], int legajos[], float promedios[], int edades[], int sizeT)
{
    for(int i=0; i<sizeT; i++)
    {
        printf("Ingrese un nombre: ");
        fflush(stdin);
        scanf("%[^\n]", nombres[i]);

        printf("Ingrese legajo: ");
        scanf("%d", &legajos[i]);

        printf("Ingrese promedio: ");
        scanf("%f", &promedios[i]);

        printf("Ingrese edad: ");
        scanf("%d", &edades[i]);
    }
}
void MostrarTodosLosNombres(char nombres[][20], int legajos[], float promedios[], int edades[], int sizeT)
{
    for(int i=0; i<sizeT; i++)
    {
        printf("%15s %4d %2.2f %3d\n", nombres, legajos, promedios, edades);
    }
}
void MostrarUnAlumno(char unNombre[], int unLegajo, float unPromedio, int unaEdad)
{
    printf("%15s %4d %2.2f %3d\n", unNombre, unLegajo, unPromedio, unaEdad);
}
/*void CargarNombres(char vec[][20], int sizeNombres)
{
    for(int i=0; i<sizeNombres; i++)
    {
        printf("Ingrese un nombre: ");
        fflush(stdin);
        scanf("%[^\n]", vec[i]);
    }
}*/
/*
void MostrarTodosLosNombres(char listaDeNombres[][20], int sizeNombres)
{
    for(int i=0; i<sizeNombres; i++)
    {
        MostrarUnNombre(listaDeNombres[i]);
    }
}
void MostrarUnNombre(char unNombre[])
{
    puts(unNombre);
}*/
