#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int sustitucionStrlen(char* cadena, int longitud);

int main()
{
    char cadena[4];
   // int longitud = 4;
    printf("Ingrese cadena\n");
    fflush(stdin);
    //gets(cadena);
    //scanf("%s", &cadena);
    //fgets(cadena, sizeof(cadena), stdin);
   // sustitucionStrlen(cadena, /*sizeof(cadena)*/4);
    sustitucionStrlen(cadena, sizeof(cadena));
    printf("La cadena es: %s\n\n", cadena);

    return 0;
}

int sustitucionStrlen(char* cadena, int longitud)
{
    fflush(stdin);
    fgets(cadena, longitud, stdin);

    return 0;
}

