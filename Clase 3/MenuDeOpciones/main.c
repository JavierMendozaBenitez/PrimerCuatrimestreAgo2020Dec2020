#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char opcion;
    char seguir = 's';
    char confirma;
    int flagSaludo = 0;
    int flagBrindis = 0;

    do
    {
        system("cls");//Limpia la pantalla

        printf("*** Menu de Opciones ***\n\n");
        printf("a Saludar\n");
        printf("b Brindar\n");
        printf("c Despedir\n");
        printf("d Salir\n\n");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion = tolower(opcion);

        switch(opcion)
        {
        case 'a':
            printf("Hola, como andas?...\n");
            flagSaludo = 1;
            break;
        case 'b':
            if(flagSaludo == 1)
            {
                printf("chin chin...\n");
                flagBrindis = 1;
            }
            else
            {
                printf("Antes de brindar primero debeos saludarnos\n");
            }
            break;
        case 'c':
            if(flagSaludo == 0)
            {
                printf("Para despedirnos primero debemos saludarnos\n");
            }
            else if(flagBrindis == 1)
            {
                printf("Hasta luego...\n");
                flagBrindis = 0;
                flagSaludo = 0;
            }
            else
            {
                printf("Antes de despedirnos primero brindemos");
            }
            break;
        case 'd':
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            seguir='n';
            break;
        default:
            printf("Opcion invalida!!!\n");
        }

        system("pause");

    }
    while(seguir == 's');

    return 0;
}
