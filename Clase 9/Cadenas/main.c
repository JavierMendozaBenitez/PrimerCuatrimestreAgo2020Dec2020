#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void copiarCadena(char cadDestino[], char cadOrigen[]);
char miTolower(char x);
void aMinuscula(char vec[]);
int main()
{
    char nombre[5];
    char auxCad[100];

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(auxCad);

    while(strlen(auxCad) >= 5)
    {
        printf("Nombre demasiado largo. Reingrese nombre: ");
        fflush(stdin);
        gets(auxCad);
    }
    strcpy(nombre, auxCad);
    //scanf("%s", nombre);
    //gets(nombre);
    //fgets(nombre, 5, stdin);
    printf("%s\n", nombre);


    //char cadena[15]="JuAna";
    //char cadena2[15]="juAna";
    //cadena == cadena2;//Comparas direcciones de memoria de ambos. No funciona
    //printf("%d\n", strcmp(cadena, cadena2));
    //strcat(cadena, cadena2);
    //strcpy(cadena, cadena2);
    //printf("%s\n", cadena);
    //printf("%s\n", cadena2);
    //int largo;
    //char letra = 'A';
    //printf("%s", cadena);
    //puts(cadena);//muestra una cadena
    //strcpy(cadenaDestino, cadenaOrigen);//recibe dos parametros de tipo puntero a char
    //strcpy(cadena, cadena2);//recibe dos parametros de tipo puntero a char
    //copiarCadena(cadena, cadena2);
    //aMinuscula(cadena2);
    //letra = miTolower(letra);
    //largo = strlen(cadena2);
    //printf("%d\n", largo);
    //printf("%c\n", letra);

    //strupr(cadena2);
    //printf("%s\n", cadena);
    //printf("%s", cadena2);
    return 0;
}

char miTolower(char x)
{
    if(x >= 65 && x <= 90)
    {
        x += 32;
    }

    return x;
}
void aMinuscula(char vec[])
{
    int i = 0;
    while( vec[i] != '\0')
    {
        vec[i] = miTolower(vec[i]);

        i++;
    }
}

/*
void copiarCadena(char cadDestino[], char cadOrigen[])
{
    int i = 0;
    while( cadOrigen[i] != '\0')
    {
        cadDestino[i] = cadOrigen[i];

        i++;
    }
}*/

