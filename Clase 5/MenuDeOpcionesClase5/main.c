#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/** \brief Muestra un menu
 *
 * \return char
 *
 */
char menu();
/** \brief Muestra un saludo por consola
 *
 * \return int retorna 0 si pudo saludar o 1 si ocurrio algun problema
 *
 */
int saludar();
/** \brief muestra in brindis por consola si recibe un 1 como parametro u otro mensaje
 *
 * \param saludo int valor que bloquea (0) o desbloquea (1) el brindis
 * \return int o si pudo brindar 0 1 sino
 *
 */
int brindar(int saludo);
/** \brief Muestra un mensaje de despedida si los parametros están en 1 y para otra combinación de  dato de entrada muestra otro mensaje
 *
 * \param saludo int si vale 1 se saludó, sino vale 0
 * \param brindis int si vale 1 se brindó, sino muestra 0
 * \return int 0 si pudo despedirse o 0 si hubo algun problema
 *
 */
int despedir(int saludo, int brindis);

int main()
{
    char seguir = 's';
    char confirma;
    int flagSaludo = 0;
    int flagBrindis = 0;

    do
    {
        switch(menu())
        {
        case 'a':
            if(!saludar())// if( saludar () == 0)
            {
                flagSaludo = 1;
            }
            break;
        case 'b':
            if(!brindar(flagSaludo))
            {
                flagBrindis = 1;
            }
            break;
        case 'c':
            if( !despedir(flagSaludo, flagBrindis))
            {
                flagBrindis = 0;
                flagSaludo = 0;
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

char menu()
{
    char opcion;
    system("cls");//Limpia la pantalla

    printf("*** Menu de Opciones ***\n\n");
    printf("a Saludar\n");
    printf("b Brindar\n");
    printf("c Despedir\n");
    printf("d Salir\n\n");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = tolower(opcion);
    //opcion=tolower(getchar()); otra opcion mas acotada que el scanf

    return opcion;
}

int saludar()
{
    int error = 0;
    int cant;

    cant = printf("Hola, como andas?...\n");
    if( cant != 21)
    {
        error = 1;
    }

    return error;
}

int brindar(int saludo)
{
    int error;

    if( saludo ) // saludo == 1;
    {
        printf("Chin chin...\n");
        error = 0;
    }
    else
    {
        printf("Antes de brindar primero debemos saludarnos\n");
        error = 1;
    }

    return error;
}

int despedir(int saludo, int brindis)
{
    int error;

    if( !saludo ) // saludo == 0;
    {
        printf("Para despedirnos primero debemos saludarnos\n");
        error = 1;
    }
    else if( brindis )
    {
        printf("Hasta luego...\n");
        error = 0;
    }
    else
    {
        printf("Antes de despedirnos primero brindemos");
        error = 1;
    }
}
