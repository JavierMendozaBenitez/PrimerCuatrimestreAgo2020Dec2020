#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

typedef struct
{
    int legajo;//4byte
    char nombre[20];//20 byte
    char sexo;//1 byte
    float altura;//4 byte
    int isEmpty;// 1 esta vacia 0 esta llena

}ePersona;

int inicializarPersonas(ePersona gente[], int tam);
int mostrarPersonas(ePersona gente[], int tam);
void mostrarPersona(ePersona unaPersona);
int buscarLibre(ePersona gente[], int tam);
int altaPersona(ePersona gente[], int tam, int legajo); //si devuelve 0 todo ok, si devuelve 1 hubo una falla en parametros o sistema completo
int bajaPersona(ePersona gente[], int tam);
int buscarPersona(ePersona gente[], int tam, int legajo);

int main()
{
    int proximoLegajo = 20000;
    /*int rta;

    ePersona lista [TAM] =
    {
        {1122, "Juan", 'm', 1.78, 0},
        {1132, "Jose", 'm', 1.75, 0},
        {1152, "Matias", 'm', 1.78, 0},
        {1132, "Nicolas", 'm', 1.75, 0},
        {1152, "Felix", 'm', 1.78, 0},
    };

    mostrarPersonas(lista,TAM);
    rta = bajaPersona(lista, TAM);

    if( rta == 0)
    {
        printf("Baja exitosa\n");
    }
    else if(rta == 2)
    {
        printf("Baja cancelada por usuario\n");
    }else
    {
        printf("Se ha producido un error en la baja\n");
    }

    mostrarPersonas(lista,TAM);
    */

    if(inicializarPersonas(lista, TAM)==0)
    {
        printf("Personas inicializadas con exito!");
    }else
    {
        printf("Ha ocurrido un problema al inicializar personas");
    }


    if(altaPersona(lista, TAM, proximoLegajo) == 0)
    {
        proximoLegajo++;
        printf("ALTA EXITOSA!\n");
    }
    else
    {
        printf("Problema para realizar el alta");
    }

    mostrarPersonas(lista, TAM);

    if(altaPersona(lista, TAM, proximoLegajo) == 0)
    {
        proximoLegajo++;
        printf("ALTA EXITOSA!\n");
    }
    else
    {
        printf("Problema para realizar el alta\n");
    }

    mostrarPersonas(lista, TAM);

    return 0;
}


int inicializarPersonas(ePersona gente[], int tam){

    int error = 1;
    if (gente!=NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            gente[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

int mostrarPersonas(ePersona gente[], int tam){

    int error = 1;
    int flag = 0;

    if( gente != NULL && tam > 0)
    {
        //system("cls");
        printf(" Legajo    Nombre    Sexo    Altura\n");
        printf("------------------------------------\n\n");

        for(int i=0; i<tam; i++)
        {
            if(gente[i].isEmpty == 0)
            {
                mostrarPersona(gente[i]);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("    No hay empleados en la lista");
        }
        printf("\n\n");

        error = 0;

    }
    return error;

}
void mostrarPersona(ePersona unaPersona){

    printf(" %4d    %10s    %c  %3.2f\n", unaPersona.legajo, unaPersona.nombre, unaPersona.sexo, unaPersona.altura);

}

int buscarLibre(ePersona gente[], int tam) //////para dar de alta
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(gente[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int altaPersona(ePersona gente[], int tam, int legajo){

    int error = 1;
    int indice;
    ePersona nuevaPersona;

    if(gente!=NULL && tam > 0 && legajo > 0)
    {
        indice = buscarLibre(gente, tam);

        if(indice == -1)
        {
            printf("El sistema esta completo.\n");
        }
        else
        {
            //aplicar validaciones a las cargas
            nuevaPersona.legajo = legajo;
            nuevaPersona.isEmpty = 0;
            printf("\n\nIngrese nombre: ");
            fflush(stdin);
            gets(nuevaPersona.nombre);
            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevaPersona.sexo);
            printf("Ingrese altura: ");
            scanf("%f", &nuevaPersona.altura);

            gente[indice] = nuevaPersona;
            error = 0;
        }
    }

    return error;
}

int buscarPersona(ePersona gente[], int tam, int legajo)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(gente[i].legajo == legajo && gente[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int bajaPersona(ePersona gente[], int tam)
{
    int error = 1;
    int legajo;
    int indice;
    int confirma;

    if(gente != NULL && tam > 0)
    {
        system("cls");
        printf("    *** BAJA DE PERSONA ***\n");
        mostrarPersonas(gente, tam);
        printf("Ingrese el legajo: ");
        scanf("%d", &legajo);

        indice = buscarPersona(gente, tam, legajo);

        if( indice == -1)
        {
            printf("No existe una persona con ese legajo.\n");
        }
        else
        {
            mostrarPersona(gente[indice]);
            printf("Confirma baja: 1 - SI 2 - NO");
            scanf("%d", &confirma);
            if(confirma == 1)
            {
                gente[indice].isEmpty = 1;
                error = 0;
            }else
            {
                error = 2;
            }
        }

    }

    return error;

}

