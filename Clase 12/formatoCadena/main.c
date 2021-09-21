#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre[20];
    char apellido[20];
    char nombreCompleto[41];//pERez GARcia
    //int length;
    int i = 0;

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(nombre);

    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(apellido);

    strcpy(nombreCompleto, apellido);//pERez GARcia
    strcat(nombreCompleto, ", ");//pEREez GARcia,
    strcat(nombreCompleto, nombre);//pEREez GARcia, JUan

    strlwr(nombreCompleto);//perez garcia, juan luis
    nombreCompleto[0] = toupper(nombreCompleto[0]);//Perez garcia, juan luis

    //length = strlen(nombreCompleto);
    //for(int i=0; i< length; i++)
    /*for(int i=0; i< strlen(nombreCompleto); i++)
    {
        if(nombreCompleto[i] == ' ')
        {
            nombreCompleto[i+1] = toupper(nombreCompleto[i+1]);
        }
    }*/
    //jaVier CarLOS menDOZA beNITEz
    /*while(nombreCompleto[i] != '\0')
    {
        if(nombreCompleto[i] == ' ')
        {
            nombreCompleto[i+1] = toupper(nombreCompleto[i+1]);
        }
        i++;
    }*/
    /*while(nombreCompleto[i] != '\0')
    {
        if(isspace(nombreCompleto[i]))
        {
            nombreCompleto[i+1] = toupper(nombreCompleto[i+1]);
        }
        i++;
    }*/
    //Perez garcia, juan luis
    printf("%s\n",nombreCompleto);

    return 0;
}
