#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"
int main()
{
    int auxInt;
    float opcion;
    char test[5];

    switch(menuInt())
    {
    case 1:
        printf("\n\nIngreso 1.\n\n");
        break;
    }

    /*char koko[] = "11";
    int lolo;

    printf("\n\n%d\n\n", lolo);
    printf("\n\n%s\n\n", koko);

    lolo = atoi(koko);
    //lolo = koko;

    printf("\n\n%d\n\n", lolo);
    printf("\n\n%s\n\n", koko);*/


   /* if(utn_getNumeroFlotante(&opcion, "Ingrese un numero: \n\n", "El numero no esta en el rango.\n\n", -10.0, 10.2,1) == 0)
    {
        printf("\nEl numero ingresado es: %.2f\n\n", opcion);
    }
    else
    {
        printf("Se quedo sin reintentos.\n");
    }*/



    /*largoCadena(&test, 5, "\nIngrese nombre\n", "\nDebe ser solo letras.\n\n");

    printf("\nEl nombre es: %s\n\n", test);*/



   /* while(1)
    {
        if(utn_getNumero(&auxInt,"NUMERO?\n", "ERROR\n",-2,2,2) == 0)
        {
            printf("\nEl numero es: %d\n\n", auxInt);
        }
    }*/

    /*if(utn_getNumero(&auxInt,"NUMERO?\n", "ERROR\n",-2,2,2) == 0)
    {
        printf("\nEl numero es: %d\n\n", auxInt);
    }*/

    return 0;
}



