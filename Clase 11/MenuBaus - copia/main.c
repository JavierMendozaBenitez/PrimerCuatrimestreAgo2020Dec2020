#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//#include "dataStore.h"
#include "persona.h"
#include "deporte.h"
//#include "fecha.h"

#define TAM 10
#define TAM_D 6
//Hacer una funcion que me pida un deporte y
//que me muestre todas las personas que lo
//practican.
//Hacer una funcion que muestre la cantidad de
//personas que practican cada deporte
char menu();

int listarPersonaXDeporte(ePersona gente[], int tam, eDeporte sports[], int tamD);
int contarPersonasXDeporte(ePersona gente[], int tam, eDeporte sports[], int tamD);
int listarPersonasDeCadaDeporte(ePersona gente[], int tam, eDeporte sports[], int tamD);
int deporteFavorito(ePersona gente[], int tam, eDeporte sports[], int tamD);
int ordenarXDeporte(ePersona gente[], int tam, eDeporte sports[], int tamD, int criterio);

int main()
{
    char seguir = 's';
    char confirma;
    int proximoLegajo = 20000;
    int rta;


    ePersona lista [TAM];/* =
    {
        {1122, "Juan", 'm', 1.78, 0},
        {1132, "Jose", 'm', 1.75, 0},
        {1152, "Matias", 'm', 1.78, 0},
        {1132, "Nicolas", 'm', 1.75, 0},
        {1152, "Felix", 'm', 1.78, 0},
    };*/
    eDeporte deportes[TAM_D]=
    {
        {1000, "No practica"},
        {1001, "Bicicleta"},
        {1002, "Surf"},
        {1003, "Snowboard"},
        {1004, "Parapente"},
        {1005, "Buceo"}
    };

    if(inicializarPersonas(lista, TAM)==0)
    {
        printf("Personas inicializadas con exito!");
    }
    else
    {
        printf("Ha ocurrido un problema al inicializar personas");
    }

    proximoLegajo += hardcodearPersonas(lista, TAM, 8);

    do
    {
        switch(menu())
        {

        case 'a':
            if(altaPersona(lista, TAM, deportes, TAM_D, proximoLegajo) == 0)
            {
                proximoLegajo++;
                printf("ALTA EXITOSA!\n");
            }
            else
            {
                printf("Problema para realizar el alta\n\n");
            }
            break;
        case 'b':
            rta = bajaPersona(lista, TAM, deportes, TAM_D);

            if( rta == 0)
            {
                printf("Baja exitosa\n");
            }
            else if(rta == 2)
            {
                printf("Baja cancelada por usuario\n");
            }
            else
            {
                printf("Se ha producido un error en la baja\n");
            }

            break;
        case 'c':
            rta = modificarPersona(lista, TAM, deportes, TAM_D);

            if( rta == 0)
            {
                printf("Modificacion exitosa\n");
            }
            else if(rta == 2)
            {
                printf("La modificacion ha sido cancelada por usuario\n");
            }
            else
            {
                printf("Se ha producido un error en la modificacion\n");
            }

            break;
        case 'd':
            system("cls");
            mostrarPersonas(lista,TAM,deportes,TAM_D);

            break;
        case 'e':
            //if(ordenarPersonasSexoAltura(lista,TAM,ASC,DESC))
           if(ordenarXDeporte(lista, TAM, deportes, TAM_D, ASC))
            {
                printf("\nHubo un problema al intentar ordenar las personas\n\n");
            }
            else
            {
                printf("\nPersonas ordenadas con exito!\n\n");
            }

            break;
        case 'f':
            system("cls");
            mostrarDeportes(deportes, TAM_D);
            break;
        case 'g':
            system("cls");
            listarPersonaXDeporte(lista, TAM, deportes, TAM_D);
            break;
        case 'h':
            system("cls");
            listarPersonasDeCadaDeporte(lista, TAM, deportes, TAM_D);
            break;
        case 'i':
            system("cls");
            contarPersonasXDeporte(lista, TAM, deportes, TAM_D);
            break;
        case 'j':
            system("cls");
            deporteFavorito(lista, TAM, deportes, TAM_D);
            break;
        case 'y':

            break;
        case 'z':
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }

            break;
        default:
            printf("Opcion invalida!!!\n");

        }

        system("pause");

    }
    while( seguir == 's');

    return 0;
}

char menu()
{
    char opcion;
    system("cls");

    printf("*** ABM Personas ***\n\n");
    printf("a Alta\n");
    printf("b Baja\n");
    printf("c Modificacion\n");
    printf("d Listar Personas\n");
    printf("e Ordenar\n");
    printf("f Listar Deportes\n");
    printf("g Listar personas de un deporte\n");
    printf("h Listar personas de todos los deportes\n");
    printf("i Contar personas de un deporte\n");
    printf("j Deporte Favorito\n");
    printf("y Informes\n");
    printf("z Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

    return opcion;
}

int listarPersonaXDeporte(ePersona gente[], int tam, eDeporte sports[], int tamD)
{
    int error = -1;
    int idDeporte;
    int flag = 0;
    char deporte[20];

    if(gente != NULL && sports != NULL && tam >0 && tamD > 0)
    {
        /*
        limpiar pantalla y poner un titulo
        muestro los deportes
        pido e ingreso un deporte
        con el id del deporte recorro el array de personas
        en busca de aquellas personas activas que tienen el mismo en su campo
        idDeportes y cada vez que encuentro una muestro sus datos si no se
        mostraron personas estaria bueno informarlo
        */
        system("cls");
        printf("   *** Listado de Personas que practican algun deporte ***\n");
        mostrarDeportes(sports, tamD);
        printf("Ingrese id deporte.\n");
        scanf("%d", &idDeporte);

        while(validarIdDeporte(sports, tamD, idDeporte) == 0)
        {
            printf("Id invalido. Reingrese id deporte: ");
            scanf("%d", &idDeporte);
        }

        obtenerDescripcionDeporte(sports, tamD, idDeporte, deporte);
        printf("Personas que practican %s:\n", deporte);

        for(int i=0; i<tam; i++)
        {
            if(gente[i].isEmpty == 0 && gente[i].idDeporte == idDeporte)
            {
                mostrarPersona(gente[i], sports, tamD);
                flag = 1;
            }
        }

        if(flag == 0)
        {
            printf("No hay personas que practiquen %s\n\n", deporte);
        }

        printf("\n\n");

        error = 0;
    }

    return error;
}

int listarPersonasDeCadaDeporte(ePersona gente[], int tam, eDeporte sports[], int tamD)
{
    int error = -1;
    int flag = 0;
    char deporte[20];

    if(gente != NULL && sports != NULL && tam >0 && tamD > 0)
    {
        system("cls");
        printf("   *** Listado de Personas de cada deporte deporte ***\n");
        for(int d = 0; d < tamD; d++)//este for me permite recorrer los deportes
        {
            flag = 0;
            obtenerDescripcionDeporte(sports, tamD, sports[d].id, deporte);
            printf("Deporte: %s\n", deporte);
            for(int i=0; i<tam; i++)//este for me permite recorrer las personas
            {
                if(gente[i].isEmpty == 0 && gente[i].idDeporte == sports[d].id)
                {
                    mostrarPersona(gente[i], sports, tamD);
                    flag = 1;
                }
            }

            if(flag == 0)
            {
                printf("No hay personas que practiquen %s\n\n", deporte);
            }

            printf("\n\n");
        }
        error = 0;
    }

    return error;
}

int contarPersonasXDeporte(ePersona gente[], int tam, eDeporte sports[], int tamD)
{
    int error = -1;
    int idDeporte;
    char deporte[20];
    int contador = 0;

    if(gente != NULL && sports != NULL && tam >0 && tamD > 0)
    {
        system("cls");
        printf("   *** Cantidad de Personas que practican algun deporte ***\n");
        mostrarDeportes(sports, tamD);
        printf("Ingrese id deporte.\n");
        scanf("%d", &idDeporte);

        while(validarIdDeporte(sports, tamD, idDeporte) == 0)
        {
            printf("Id invalido. Reingrese id deporte: ");
            scanf("%d", &idDeporte);
        }


        for(int i=0; i<tam; i++)
        {
            if(gente[i].isEmpty == 0 && gente[i].idDeporte == idDeporte)
            {
                //mostrarPersona(gente[i], sports, tamD);
                contador++;
            }
        }
        obtenerDescripcionDeporte(sports, tamD, idDeporte, deporte);

        printf("Cantidad personas que practiquen %s: %d\n\n", deporte, contador);

        error = 0;
    }

    return error;
}

int deporteFavorito(ePersona gente[], int tam, eDeporte sports[], int tamD)
{
    int error = 1;
    int mayor;
    int contadores[tamD];
    int flag = 0;

    for(int i=0; i<tamD; i++)
    {
        contadores[i] = 0;
    }

    if(gente != NULL && sports != NULL && tam >0 && tamD > 0)
    {
        system("cls");
        printf("   *** Deporte favorito ***\n");
        for(int d = 0; d < tamD; d++)//este for me permite recorrer los deportes
        {
            for(int i=0; i<tam; i++)//este for me permite recorrer las personas
            {
                if(gente[i].isEmpty == 0 && gente[i].idDeporte == sports[d].id)
                {
                    contadores[d]++;
                }
            }
        }

        for(int i=0; i<tamD; i++)
        {
            if(contadores[i] > mayor || flag == 0)
            {
                mayor = contadores[i];
                flag = 1;
            }
        }

        printf("El o los deportes favoritos son: \n\n");

        for(int i=0; i<tamD; i++)
        {
            if(contadores[i] == mayor)
            {
                printf("%s\n", sports[i].descripcion);
            }
        }

        printf("\n\n");
        error = 0;
    }

    return error;
}

int ordenarXDeporte(ePersona gente[], int tam, eDeporte sports[], int tamD, int criterio)
{
    int error = 1;
    ePersona auxPersona;
    char deporteI[20];
    char deporteJ[20];

    if(gente!=NULL && tam>0 && criterio>=0 && criterio<=1)
    {
        for(int i=0; i<tam -1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                obtenerDescripcionDeporte(sports, tamD, gente[i].idDeporte, deporteI);
                obtenerDescripcionDeporte(sports, tamD, gente[j].idDeporte, deporteJ);
                 if(((strcmp(deporteI, deporteJ) > 0) && criterio)
                    || ((strcmp(deporteI, deporteJ) < 0) && !criterio))
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
            }
        }
        error = 0;
    }

    return error;
}
