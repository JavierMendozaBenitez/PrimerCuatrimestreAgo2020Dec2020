#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dataStore.h"

#define TAM_C 6
#define TAM_M 20

typedef struct
{
    int legajo;
    char nombre[20];
    char apellido[20];
    char localidad[20];
    int telefono;
    int edad;
    char sexo;
    int idMascota;
    int isEmpty;// 1 esta vacia 0 esta llena

} eCliente;

typedef struct
{
    char nombreRaza[20];
    char pais[20];
} eRaza;

typedef struct
{
    int id;
    char nombre[20];
    char tipo [20];
    //char raza[20];
    int edad;
    float peso;
    eRaza mRaza;
    char sexo;
} eMascota;

int menuInt();
int inicializarClientes(eCliente persona[], int tam);
void mostrarCliente(eCliente persona, int tam);
int mostrarClientes(eCliente persona[], int tam);
int harcodearDatos(eCliente persona[], int tam, int cantidad);
int buscarLibre(eCliente persona[], int tam);
int altaCliente(eCliente persona[], int tam, int legajo);

int main()
{
    /*int legajo;
    char nombre[20];
    char apellido[20];
    char localidad[20];
    long int telefono;
    int edad;
    char sexo;
    int idMascota;
    int isEmpty;*/
    char seguir = 's';
    char confirma;
    int proximoLegajo = 1;

    eCliente clientela[TAM_C];
    eMascota mascota[TAM_M];

    if(inicializarClientes(clientela, TAM_C) == 0)
    {
        printf("Clientes inicializados con exito.\n");
    }
    else
    {
        printf("Ha ocurrido un problema al inicializar personas");
    }

    harcodearDatos(clientela, TAM_C, 5);

    do
    {
        switch(menuInt())
        {
        case 1:
            if(altaCliente(clientela, TAM_C, proximoLegajo) == 0)
            {
                proximoLegajo++;
                printf("\n\nALTA EXITOSA\n\n");
            }
            else
            {
                printf("Error al dar el alta.\n\n");
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            system("cls");
            mostrarClientes(clientela, TAM_C);
            break;
        case 9:
            break;
        case 10:
            break;
        case 15:
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
    while(seguir == 's');


    return 0;
}

int menuInt()
{
    int opcion;
    system("cls");

    printf("*** ABM Personas ***\n\n");
    printf("1 Alta\n");
    printf("2 Baja\n");
    printf("3 Modificacion\n");
    printf("4 Listar Personas\n");
    printf("5 Ordenar\n");
    printf("6 Listar Deportes\n");
    printf("7 Listar personas de un deporte\n");
    printf("8 Listar personas de todos los deportes\n");
    printf("9 Contar personas de un deporte\n");
    printf("10 Deporte Favorito\n");
    printf("11 Informes\n");
    printf("12 Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int inicializarClientes(eCliente persona[], int tam)
{
    int error = 1;
    if(persona != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            persona[i].isEmpty = 1;
            error = 0;
        }
    }
    return error;
}

void mostrarCliente(eCliente persona, int tam)
{
    printf(" %5d     %10s    %10s     %10s       %10ld        %4d        %4c               %4d\n",
           persona.legajo,
           persona.nombre,
           persona.apellido,
           persona.localidad,
           persona.telefono,
           persona.edad,
           persona.sexo,
           persona.idMascota);
}

int mostrarClientes(eCliente persona[], int tam)
{
    int error = 1;

    if(persona != NULL && tam > 0)
    {
        printf(" Legajo        Nombre       Apellido     Localidad         Telefono         Edad        Sexo          idMascota\n");
        printf("-------------------------------------------------------------------------------------------------------------------\n\n");

        for(int i = 0; i < tam; i++)
        {
            if(persona[i].isEmpty == 0)
            {
                mostrarCliente(persona[i], tam);
            }
        }
        error = 0;
    }
    return error;
}

int harcodearDatos(eCliente persona[], int tam, int cantidad)
{
    int error = 1;

    if(persona != NULL && cantidad > 0 && cantidad <= tam)
    {
        for(int i = 0; i < cantidad; i++)
        {
            persona[i].legajo = legajos[i];
            strcpy(persona[i].nombre, nombres[i]);
            strcpy(persona[i].apellido, apellidos[i]);
            strcpy(persona[i].localidad, localidades[i]);
            persona[i].telefono = telefonos[i];
            persona[i].edad = edades[i];
            persona[i].sexo = sexos[i];
            persona[i].idMascota = idMascotas[i];
            persona[i].isEmpty = 0;
            error++;
        }
    }
    return error;
}

int buscarLibre(eCliente persona[], int tam)
{
    int indice = -1;//Si es -1 es que no hay lugares libres

    for(int i = 0; i < tam; i++)
    {
        if(persona[i].isEmpty == 1)
        {
            indice = i;
            break;//Sin el break va a seguir buscando, solo queremos un lugar
        }
    }
    return indice;
}

int altaCliente(eCliente persona[], int tam, int legajo)
{
    int error = -1;
    int lugarVacio;

    eCliente nuevoCliente;

    if(persona != NULL && tam > 0 && legajo > 0)
    {
        system("cls");
        printf("   *** ALTA DE CLIENTE ***\n\n");
        lugarVacio = buscarLibre(persona, tam);

        if(lugarVacio == -1)
        {
            printf("ESTA LLENO, NO HAY LUGARES.\n\n");
        }
        else
        {
            nuevoCliente.legajo = legajo;
            printf("Ingrese nombre\n");
            fflush(stdin);
            gets(nuevoCliente.nombre);
            printf("Ingrese apellido\n");
            fflush(stdin);
            gets(nuevoCliente.apellido);
            printf("Ingrese localidad\n");
            fflush(stdin);
            gets(nuevoCliente.localidad);
            printf("Ingrese telefono\n");
            fflush(stdin);
            scanf("%ld", &nuevoCliente.telefono);
            printf("Ingrese edad\n");
            fflush(stdin);
            scanf("%d", &nuevoCliente.edad);
            printf("Ingrese sexo. 'f' o 'm'\n");
            fflush(stdin);
            scanf("%c", &nuevoCliente.sexo);
            printf("Ingrese id de su mascota\n");
            fflush(stdin);
            scanf("%d", &nuevoCliente.idMascota);
            nuevoCliente.isEmpty = 0;

            persona[lugarVacio] = nuevoCliente;

            error = 0;
        }
    }
    return error;
}


