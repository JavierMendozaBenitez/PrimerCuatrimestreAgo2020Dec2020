#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int esPar(int a);

int main()
{
    int numero;
    char nombre[10] = "gAston";
    char d = 'd';


    //strlwr(nombre);//perez garcia, juan luis
    //nombre[0] = toupper(nombre[0]);//Perez garcia, juan luis
   // strcpy(nombre[0], "d"); NO ANDA
    printf("Nombre: %s\n", nombre);
    /*
    printf("Ingrese un numero: \n");
    fflush(stdin);
    scanf("%d", &numero);

    if(esPar(numero) == 0)
    {
        printf("El numero es par.\n\n");
    }
    else
    {
        printf("El numero es impar.\n\n");
    }*/

    return 0;
}

int esPar(int a)
{
    int error = 1;

    if((a%2) == 0)
    {
        error = 0;
    }
    return error;
}
