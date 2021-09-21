#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dataStore.h"
#include <string.h>

#define TAM 10
//#define TAM 1000
#define ASC 1
#define DESC 0

typedef struct
{
    int id;//4byte
    char nombre[51];//51 byte
    char apellido[51];
    char sexo;//1 byte
    float salario;//4 byte
    int sector;
    int isEmpty;// 1 esta vacia 0 esta llena

} eEmpleado;


int menu();
//void mostrarFecha(eFecha unaFecha);
int inicializarPersonas(eEmpleado gente[], int tam);
int mostrarPersonas(eEmpleado gente[], int tam);
void mostrarPersona(eEmpleado unaPersona);
int buscarLibre(eEmpleado gente[], int tam);
int altaPersona(eEmpleado gente[], int tam, int id); //si devuelve 0 todo ok, si devuelve 1 hubo una falla en parametros o sistema completo
int bajaPersona(eEmpleado gente[], int tam);
int modificarPersona(eEmpleado gente[], int tam);
int buscarPersona(eEmpleado gente[], int tam, int id);
int hardcodearPersonas(eEmpleado gente[], int tam, int cantidad);
int ordenarPersonasApellido(eEmpleado gente[], int tam, int criterio);
int ordenarEmpleadosApellidoSector(eEmpleado gente[], int tam, int criterioS, int criterioA);

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo);

float cantidadEmpleados(eEmpleado gente[], int tam);
float acumuladorSalario(eEmpleado gente[], int tam);
float promedioSueldos(eEmpleado gente[], int tam);
float sueldosSuperioresAlPromedio(eEmpleado gente[], int tam);

int main()
{
    char confirma;
    int seguir;
    int proximoLegajo = 0;
    int rta;
    int respuesta;
    int opcion;
    int flag1;
    //int contadorEmpleados;
    float cantidadIngresados;
    //float acuSalarios = 0;
    float acumuladorSalarioIngresado;
    float promedioSueldosIngresados;
    float sueldosSuperioresAPromedio;

    flag1 = 0;

    eEmpleado lista [TAM];
    //cantidadIngresados = cantidadEmpleados(lista,TAM);
    if(inicializarPersonas(lista, TAM)==0)
    {
        printf("Personas inicializadas con exito!\n\n");
    }
    else
    {
        printf("Ha ocurrido un problema al inicializar personas");
    }

    // hardcodearPersonas(lista, TAM, 5);

    proximoLegajo += 1;

    do
    {
        system("cls");

        respuesta = utn_getNumero(&opcion,"*** ABM Empleados ***\n\n1 ALTAS\n2 MODIFICAR\n3 BAJAS\n4 INFORMAR\n5 SALIR\n\n\nQue opcion elige? \n\n","\nError la opcion debe ser desde 1 a 5\n\n",1,5);

        if(!respuesta)
        {
            switch(opcion)
            {

            case 1:
                if(altaPersona(lista, TAM, proximoLegajo) == 0)
                {
                    proximoLegajo++;
                    printf("ALTA EXITOSA!\n");
                    flag1 = 1;
                }
                else
                {
                    printf("Problema para realizar el alta\n\n");
                }
                break;
            case 2:
                if( flag1 == 1)
                {
                    rta = modificarPersona(lista, TAM);
                    if(rta == 0)
                    {
                        printf("La modificacion fue exitosa\n");
                    }

                }
                else
                {
                    printf("\nAun no se cargaron empleados, elija la opcion 1 y carguelos.\n\n");
                }
                break;
            case 3:
                if( flag1 == 1)
                {
                    rta = bajaPersona(lista, TAM);

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
                }
                else
                {
                    printf("\nAun no se cargaron empleados, elija la opcion 1 y carguelos.\n\n");
                }

                break;
            case 4:
                if( flag1 == 1)
                {
                    system("cls");
                    printf("********Epleados ordenados por Apellido y si tienen el mismo Apellido, desempatamos ordenando por Sector********\n\n");
                    ordenarEmpleadosApellidoSector(lista, TAM, 1, 1);
                    mostrarPersonas(lista,TAM);

                    cantidadIngresados = cantidadEmpleados(lista,TAM);
                    printf("\nCantidad empleados: %2.f.\n\n",cantidadIngresados);

                    acumuladorSalarioIngresado = acumuladorSalario(lista, TAM);
                    printf("Sueldos acumulados: %2.f.\n\n",acumuladorSalarioIngresado);

                    promedioSueldosIngresados = promedioSueldos(lista, TAM);
                    printf("El promedio de los sueldos es: %2.f.\n\n",promedioSueldosIngresados);

                    sueldosSuperioresAPromedio = sueldosSuperioresAlPromedio(lista, TAM);
                    printf("La cantidad de sueldos superiores al promedio son:%2.f.\n\n", sueldosSuperioresAPromedio);
                }
                else
                {
                    printf("\nAun no se cargaron empleados, elija la opcion 1 y carguelos.\n\n");
                }

                break;
            /*case 5:
                cantidadIngresados = cantidadEmpleados(lista,TAM);
                printf("\nCantidad empleados: %2.f.\n\n",cantidadIngresados);

                acumuladorSalarioIngresado = acumuladorSalario(lista, TAM);
                printf("Sueldos acumulados: %2.f.\n\n",acumuladorSalarioIngresado);

                promedioSueldosIngresados = promedioSueldos(lista, TAM);
                printf("El promedio de los sueldos es: %2.f.\n\n",promedioSueldosIngresados);

                sueldosSuperioresAPromedio = sueldosSuperioresAlPromedio(lista, TAM);
                printf("La cantidad de sueldos superiores al promedio son:%2.f.\n\n", sueldosSuperioresAPromedio);
                // promedioSueldos = acumuladorSalarioIngresado / cantidadIngresados;
                //printf("El promedio de los sueldos es: %2.f.\n\n", promedioSueldos);
                /*if(ordenarPersonasSexoSalario(lista,TAM,ASC,DESC))
                {
                    printf("\nHubo un problema al intentar ordenar las personas\n\n");
                }
                else
                {
                    printf("\nPersonas ordenadas con exito!\n\n");
                }*/
                /*
                break;*/
            default:
                break;
            }

            system("pause");
        }
        else
        {
            system("pause");
        }

    }
    while( opcion != 5);

    return 0;
}
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo)
{
    int retorno = -1;
    int bufferInt;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%d", &bufferInt);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        while(retorno == 0);

    }
    return retorno;
}

int inicializarPersonas(eEmpleado gente[], int tam)
{

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

int mostrarPersonas(eEmpleado gente[], int tam)
{

    int error = 1;
    int flag = 0;

    if( gente != NULL && tam > 0)
    {
        //system("cls");
        printf("     ID         Nombre            Apellido        Salario      Sector\n");
        printf("---------------------------------------------------------------------\n\n");

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
            printf("No hay personas en la lista");
        }
        printf("\n\n");

        error = 0;

    }
    return error;

}
void mostrarPersona(eEmpleado unaPersona)
{

    printf(" | %4d |   %12s   |   %12s   |  %4.2f | %6d\n", unaPersona.id, unaPersona.nombre, unaPersona.apellido, unaPersona.salario, unaPersona.sector);

}

int buscarLibre(eEmpleado gente[], int tam) //////para dar de alta
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

int altaPersona(eEmpleado gente[], int tam, int id)
{

    int error = 1;
    int indice;
    eEmpleado nuevaPersona;

    if(gente!=NULL && tam > 0 && id > 0)
    {

        system("cls");
        printf("ALTA DE EMPLEADO\n\n");
        indice = buscarLibre(gente, tam);

        if(indice == -1)
        {
            printf("El sistema esta completo.\n");
        }
        else
        {
            //aplicar validaciones a las cargas
            nuevaPersona.id = id;
            nuevaPersona.isEmpty = 0;
            printf("\n\nIngrese nombre: ");
            fflush(stdin);
            gets(nuevaPersona.nombre);
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(nuevaPersona.apellido);
            printf("Ingrese salario: ");
            scanf("%f", &nuevaPersona.salario);
            printf("Ingrese sector: ");
            scanf("%d", &nuevaPersona.sector);

            //printf("Ingrese fecha nacimiento dd/mm/aaaa: ");
            //scanf("%d/%d/%d", &nuevaPersona.fNac.dia, &nuevaPersona.fNac.mes, &nuevaPersona.fNac.anio);

            gente[indice] = nuevaPersona;
            error = 0;
        }
    }

    return error;
}

int buscarPersona(eEmpleado gente[], int tam, int id)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(gente[i].id == id && gente[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int bajaPersona(eEmpleado gente[], int tam)
{
    int error = 1;
    int id;
    int indice;
    int confirma;

    if(gente != NULL && tam > 0)
    {
        system("cls");
        printf("    *** BAJA DE EMPLEADO ***\n");
        mostrarPersonas(gente, tam);
        printf("Ingrese el id: ");
        scanf("%d", &id);

        indice = buscarPersona(gente, tam, id);

        if( indice == -1)
        {
            printf("No existe un empleado con ese id.\n");
        }
        else
        {
            mostrarPersona(gente[indice]);
            printf("Confirma baja: Presione 1 para dar de baja o 2 para NO dar de baja: ");
            scanf("%d", &confirma);
            if(confirma == 1)
            {
                gente[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 2;
            }
        }

    }
    return error;
}

int modificarPersona(eEmpleado gente[], int tam)
{
    int id;
    int indice;
    int elegido;
    int respondio;
    char confirma;
    eEmpleado nuevosDatos;

    if(gente != NULL && tam > 0)
    {
        system("cls");
        printf("    *** MODIFICAR EMPLEADO ***\n");
        mostrarPersonas(gente, tam);
        printf("Ingrese el id: ");
        scanf("%d", &id);

        indice = buscarPersona(gente, tam, id);

        if( indice == -1)
        {
            printf("No existe un empleado con ese id.\n");
        }
        else
        {
            mostrarPersona(gente[indice]);

            do
            {
                system("cls");

                respondio = utn_getNumero(&elegido,"Que desea modificar?\n\n1 NOMBRE\n2 APELLIDO\n3 SALARIO\n4 SECTOR\n5 TERMINAR\n\nQue opcion elige? \n\n","\nError la opcion debe ser desde 1 a 4\n\n",1,5);

                if(!respondio)
                {
                    switch(elegido)
                    {

                    case 1:
                        printf("\nIngrese nuevo nombre: ");
                        fflush(stdin);
                        gets(nuevosDatos.nombre);
                        strcpy(gente[indice].nombre, nuevosDatos.nombre);
                        break;
                    case 2:
                        printf("\nIngrese nuevo apellido: ");
                        fflush(stdin);
                        gets(nuevosDatos.apellido);
                        strcpy(gente[indice].apellido, nuevosDatos.apellido);
                        break;
                    case 3:
                        printf("\nIngrese nuevo salario: ");
                        fflush(stdin);
                        scanf("%f", &nuevosDatos.salario);
                        gente[indice].salario = nuevosDatos.salario;
                        break;
                    case 4:
                        printf("\nIngrese nuevo sector: ");
                        fflush(stdin);
                        scanf("%d", &nuevosDatos.sector);
                        gente[indice].sector = nuevosDatos.sector;
                        break;
                    case 5:
                        break;
                    default:
                        break;
                    }
                    system("pause");
                }
                else
                {
                    system("pause");
                }

                printf("\nLos datos modificados quedaron asi: \n\n");
                mostrarPersona(gente[indice]);

            }
            while( elegido != 5);
        }

        return 0;

    }
}

int hardcodearPersonas(eEmpleado gente[], int tam, int cantidad)
{
    int error = 1;

    if(gente!= NULL && tam>0 && cantidad >= 0 && cantidad <= tam)
    {

        for(int i=0; i<tam; i++)
        {
            gente[i].id = ids[i];
            strcpy(gente[i].nombre, nombres[i]);
            strcpy(gente[i].apellido, apellidos[i]);
            gente[i].salario = salarios[i];
            gente[i].sector = sectores[i];
            gente[i].isEmpty = 0;
        }

        error = 0;
    }

    return error;
}

int ordenarPersonasApellido(eEmpleado gente[], int tam, int criterio)
{
    int error = 1;
    eEmpleado auxEmpleado;

    if(gente!=NULL && tam>0 && criterio>=0 && criterio<=1)
    {


        for(int i=0; i-tam -1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if((strcmp(gente[i].apellido, gente[j].apellido) > 0 && criterio == 1) || (strcmp(gente[i].apellido, gente[j].apellido) < 0 && criterio == 0))
                {
                    auxEmpleado = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxEmpleado;
                }
            }
        }
        error = 0;
    }

    return 0;
}

int ordenarEmpleadosApellidoSector(eEmpleado gente[], int tam, int criterioS, int criterioA)
{

    int error = 1;
    eEmpleado auxPersona;

    if(gente!=NULL && tam>0 && criterioS>=0 && criterioS<=1 && criterioA >= 0 && criterioA <= 1)
    {


        for(int i=0; i-tam -1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if((strcmp(gente[i].apellido, gente[j].apellido) > 0 && criterioS == 1))
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
                else if((strcmp(gente[i].apellido, gente[j].apellido) < 0 && criterioS == 0))
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
                else if((strcmp(gente[i].apellido, gente[j].apellido) == 0) && gente[i].sector > gente[j].sector && criterioA == 1)
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
                else if(gente[i].apellido == gente[j].apellido && gente[i].sector < gente[j].sector && criterioA == 0)
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
            }
        }
        error = 0;
    }

    return 0;

}


float cantidadEmpleados(eEmpleado gente[], int tam)
{
    int flag = 0;
    float contadorEmpleados = 0;

    if( gente != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(gente[i].isEmpty == 0)
            {
                contadorEmpleados++;
            }
        }
    }
    return contadorEmpleados;
}

float acumuladorSalario(eEmpleado gente[], int tam)
{
    float acumuladorSueldo = 0;

    if( gente != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(gente[i].salario != 0)
            {
                acumuladorSueldo = acumuladorSueldo + gente[i].salario;
            }
        }
    }
    return acumuladorSueldo;
}

float promedioSueldos(eEmpleado gente[], int tam)
{
    float promedio;

    promedio = (acumuladorSalario(gente, tam)) / (cantidadEmpleados(gente, tam));

    return promedio;
}

float sueldosSuperioresAlPromedio(eEmpleado gente[], int tam)
{
    float proSueldos;
    float contadorSuperioresAlPromedio = 0;

    proSueldos = promedioSueldos(gente, tam);

    if( gente != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(gente[i].salario > proSueldos)
            {
                contadorSuperioresAlPromedio++;
            }

        }
    }

    return contadorSuperioresAlPromedio;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"

#define TAM 1000
#define ASC 1
#define DESC 0

typedef struct
{
    int id;//4byte
    char nombre[51];//51 byte
    char apellido[51];
    char sexo;//1 byte
    float salario;//4 byte
    int sector;
    int isEmpty;// 1 esta vacia 0 esta llena

} eEmpleado;


int initEmployees(eEmpleado gente[], int tam);
int printEmployees(eEmpleado gente[], int tam);
void mostrarEmpleado(eEmpleado unEmpleado);
int buscarLibre(eEmpleado gente[], int tam);
int addEmployee(eEmpleado gente[], int tam, int id); //si devuelve 0 todo ok, si devuelve 1 hubo una falla en parametros o sistema completo
int removeEmployee(eEmpleado gente[], int tam);
int modificarEmpleado(eEmpleado gente[], int tam);
int findEmployeeById(eEmpleado gente[], int tam, int id);
int sortEmployees(eEmpleado gente[], int tam, int criterioS, int criterioA);
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo);
float cantidadEmpleados(eEmpleado gente[], int tam);
float acumuladorSalario(eEmpleado gente[], int tam);
float promedioSueldos(eEmpleado gente[], int tam);
float sueldosSuperioresAlPromedio(eEmpleado gente[], int tam);

int main()
{
    int proximoLegajo = 0;
    int rta;
    int respuesta;
    int opcion;
    int flag1;
    float cantidadIngresados;
    float acumuladorSalarioIngresado;
    float promedioSueldosIngresados;
    float sueldosSuperioresAPromedio;

    flag1 = 0;

    eEmpleado lista [TAM];

    if(initEmployees(lista, TAM)==0)
    {
        printf("Personas inicializadas con exito!\n\n");
    }
    else
    {
        printf("Ha ocurrido un problema al inicializar personas");
    }

    proximoLegajo += 1;

    do
    {
        system("cls");

        respuesta = utn_getNumero(&opcion,"*** ABM Empleados ***\n\n1 ALTA\n2 MODIFICAR\n3 BAJA\n4 INFORMAR\n5 SALIR\n\n\nQue opcion elige? \n\n","\nError la opcion debe ser desde 1 a 5\n\n",1,5);

        if(!respuesta)
        {
            switch(opcion)
            {

            case 1:
                if(addEmployee(lista, TAM, proximoLegajo) == 0)
                {
                    proximoLegajo++;
                    printf("\nALTA EXITOSA!\n\n");
                    flag1 = 1;
                }
                else
                {
                    printf("Problema para realizar el alta\n\n");
                }
                break;
            case 2:
                if( flag1 == 1)
                {
                    rta = modificarEmpleado(lista, TAM);
                    if(rta == 0)
                    {
                        printf("La modificacion fue exitosa\n\n");
                    }
                }
                else
                {
                    printf("\nAun no se cargaron empleados, elija la opcion 1 y carguelos.\n\n");
                }
                break;
            case 3:
                if( flag1 == 1)
                {
                    rta = removeEmployee(lista, TAM);

                    if( rta == 0)
                    {
                        printf("\n\nBaja exitosa\n\n");
                    }
                    else if(rta == 2)
                    {
                        printf("\n\nBaja cancelada por usuario\n\n");
                    }
                    else if(rta == 3)
                    {
                        printf("\nNo existe un empleado con ese id.\n\n");
                    }
                    else if(rta == 4)
                    {
                        printf("\nEliminaste todos los empleados. Carga nuevos en la opcion 1.\n\n");
                    }
                }
                else
                {
                    printf("\nAun no se cargaron empleados, elija la opcion 1 y carguelos.\n\n");
                }

                break;
            case 4:
                if( flag1 == 1)
                {
                    system("cls");
                    printf("********Epleados ordenados por Apellido y si tienen el mismo Apellido, desempatamos ordenando por Sector********\n\n");
                    sortEmployees(lista, TAM, 1, 1);
                    printEmployees(lista,TAM);

                    cantidadIngresados = cantidadEmpleados(lista,TAM);
                    printf("\nCantidad empleados: %2.f.\n\n",cantidadIngresados);

                    acumuladorSalarioIngresado = acumuladorSalario(lista, TAM);
                    printf("Sueldos acumulados: %2.f.\n\n",acumuladorSalarioIngresado);

                    promedioSueldosIngresados = promedioSueldos(lista, TAM);
                    printf("El promedio de los sueldos es: %2.f.\n\n",promedioSueldosIngresados);

                    sueldosSuperioresAPromedio = sueldosSuperioresAlPromedio(lista, TAM);
                    printf("La cantidad de sueldos superiores al promedio son:%2.f.\n\n", sueldosSuperioresAPromedio);
                }
                else
                {
                    printf("\nAun no se cargaron empleados, elija la opcion 1 y carguelos.\n\n");
                }

                break;
            default:
                break;
            }

            system("pause");
        }
        else
        {
            system("pause");
        }

    }
    while( opcion != 5);

    return 0;
}
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo)
{
    int retorno = -1;
    int bufferInt;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%d", &bufferInt);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        while(retorno == 0);

    }
    return retorno;
}

int initEmployees(eEmpleado gente[], int tam)
{

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

int printEmployees(eEmpleado gente[], int tam)
{

    int error = 1;
    int flag = 0;

    if( gente != NULL && tam > 0)
    {
        printf("     ID         Nombre            Apellido        Salario      Sector\n");
        printf("---------------------------------------------------------------------\n\n");

        for(int i=0; i<tam; i++)
        {
            if(gente[i].isEmpty == 0)
            {
                mostrarEmpleado(gente[i]);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("No hay empleados en la lista");
        }
        printf("\n\n");

        error = 0;

    }
    return error;

}
void mostrarEmpleado(eEmpleado unEmpleado)
{
    printf("\n | %4d |   %12s   |   %12s   |  %6.2f | %6d\n\n", unEmpleado.id, unEmpleado.nombre, unEmpleado.apellido, unEmpleado.salario, unEmpleado.sector);

}

int buscarLibre(eEmpleado gente[], int tam) //////para dar de alta
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

int soloLetras(char cadena[])
{
    int retorno=1;

    for(int i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'a'||cadena[i]>'z')&&(cadena[i]<'A'||cadena[i]>'Z'))
        {
            retorno=0;
        }
    }

    return retorno;
}

void largoCadena(char cadena[],int tamanio,char mensaje[],char errorMensaje[])
{
    puts(mensaje);
    fflush(stdin);;
    fgets(cadena,tamanio,stdin);
    cadena[strlen(cadena)-1]='\0';

    while(!soloLetras(cadena))
    {
        puts(errorMensaje);
        fflush(stdin);
        fgets(cadena,tamanio,stdin);
        cadena[strlen(cadena)-1]='\0';
    }
}

int addEmployee(eEmpleado gente[], int tam, int id)
{

    int error = 1;
    int indice;
    eEmpleado nuevoEmpleado;
    //int letras;
    //char auxCad[100];

    if(gente!=NULL && tam > 0 && id > 0)
    {

        system("cls");
        printf("ALTA DE EMPLEADO\n\n");
        indice = buscarLibre(gente, tam);

        if(indice == -1)
        {
            printf("El sistema esta completo.\n");
        }
        else
        {
            //aplicar validaciones a las cargas
            nuevoEmpleado.id = id;
            nuevoEmpleado.isEmpty = 0;

            /*printf("\n\nIngrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);
            letras = soloLetras(nuevoEmpleado.nombre);*/
            largoCadena(nuevoEmpleado.nombre,51,"\n\nIngrese nombre: ","\nReingrese nombre, escribio uno con caracteres diferentes a letras.");
            printf("El nombre ingresado es:%s\n",nuevoEmpleado.nombre);
            /*letras = soloLetras(nuevoEmpleado.nombre);

            while(letras == 0)
            {
                printf("\nReingrese nombre, con solo letras!!! ");
                fflush(stdin);
                gets(nuevoEmpleado.nombre);
                letras = soloLetras(nuevoEmpleado.nombre);
            }
            printf("El nombre ingresado es:%s\n",nuevoEmpleado.nombre);*/




            /*printf("\n\nIngrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);*/
            /*printf("\n\nIngrese nombre: ");
            fflush(stdin);
            gets(auxCad);

            while(strlen(auxCad) >= 51)
            {
                printf("\nNombre demasiado largo. REINGRESE.\n\n");
                fflush(stdin);
                gets(auxCad);
            }
            strcpy(nuevoEmpleado.nombre, auxCad);
            printf("El nombre ingresado es:%s\n",nuevoEmpleado.nombre);*/

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(nuevoEmpleado.apellido);
            printf("Ingrese salario: ");
            scanf("%f", &nuevoEmpleado.salario);
            printf("Ingrese sector: ");
            scanf("%d", &nuevoEmpleado.sector);

            gente[indice] = nuevoEmpleado;
            error = 0;
        }
    }

    return error;
}

int findEmployeeById(eEmpleado gente[], int tam, int id)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(gente[i].id == id && gente[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int removeEmployee(eEmpleado gente[], int tam)
{
    int error = 1;
    int id;
    int indice;
    int confirma;
    int respuesta;
    int cantEmpleados;

    cantEmpleados = cantidadEmpleados(gente,tam);

    if(gente != NULL && tam > 0 && cantEmpleados >0)
    {
        system("cls");
        printf("******************** BAJA DE EMPLEADO **********************\n");
        printEmployees(gente, tam);
        printf("Ingrese el id: ");
        scanf("%d", &id);

        indice = findEmployeeById(gente, tam, id);

        if( indice == -1)
        {
            error = 3;
        }
        else
        {
            mostrarEmpleado(gente[indice]);
            do
            {
                respuesta = utn_getNumero(&confirma,"\nConfirma baja: Presione 1 para dar de baja o 2 para NO dar de baja.\n\nQue opcion elige? \n\n","\nError la opcion debe ser desde 1 o 2\n\n",1,2);

                if(!respuesta)
                {
                    switch(confirma)
                    {

                    case 1:
                        gente[indice].isEmpty = 1;
                        error = 0;
                        break;
                    case 2:
                        error = 2;
                        break;
                    default:
                        break;
                    }

                    system("pause");
                }
            }
            while(confirma != 1 && confirma !=2);
        }
    }
    else
    {
        error = 4;
    }

    return error;
}

int modificarEmpleado(eEmpleado gente[], int tam)
{
    int id;
    int indice;
    int elegido;
    int respondio;
    eEmpleado nuevosDatos;

    if(gente != NULL && tam > 0)
    {
        system("cls");
        printf("    *** MODIFICAR EMPLEADO ***\n");
        printEmployees(gente, tam);
        printf("\nIngrese el id: ");
        scanf("%d", &id);

        indice = findEmployeeById(gente, tam, id);

        if( indice == -1)
        {
            printf("\nNo existe un empleado con ese id.\n");
        }
        else
        {
            mostrarEmpleado(gente[indice]);

            do
            {
                system("cls");

                respondio = utn_getNumero(&elegido,"Que desea modificar?\n\n1 NOMBRE\n2 APELLIDO\n3 SALARIO\n4 SECTOR\n5 TERMINAR\n\nQue opcion elige? \n\n","\nError la opcion debe ser desde 1 a 4\n\n",1,5);

                if(!respondio)
                {
                    switch(elegido)
                    {

                    case 1:
                        printf("\nIngrese nuevo nombre: ");
                        fflush(stdin);
                        gets(nuevosDatos.nombre);
                        strcpy(gente[indice].nombre, nuevosDatos.nombre);
                        break;
                    case 2:
                        printf("\nIngrese nuevo apellido: ");
                        fflush(stdin);
                        gets(nuevosDatos.apellido);
                        strcpy(gente[indice].apellido, nuevosDatos.apellido);
                        break;
                    case 3:
                        printf("\nIngrese nuevo salario: ");
                        fflush(stdin);
                        scanf("%f", &nuevosDatos.salario);
                        gente[indice].salario = nuevosDatos.salario;
                        break;
                    case 4:
                        printf("\nIngrese nuevo sector: ");
                        fflush(stdin);
                        scanf("%d", &nuevosDatos.sector);
                        gente[indice].sector = nuevosDatos.sector;
                        break;
                    default:
                        break;
                    }
                    system("pause");
                }
                else
                {
                    system("pause");
                }

                printf("\nLos datos modificados quedaron de este modo: \n\n");
                mostrarEmpleado(gente[indice]);

            }
            while( elegido != 5);
        }
    }
    return 0;
}

int sortEmployees(eEmpleado gente[], int tam, int criterioS, int criterioA)
{
    eEmpleado auxEmpleado;

    if(gente!=NULL && tam>0 && criterioS>=0 && criterioS<=1 && criterioA >= 0 && criterioA <= 1)
    {


        for(int i=0; i-tam -1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if((strcmp(gente[i].apellido, gente[j].apellido) > 0 && criterioS == 1))
                {
                    auxEmpleado = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxEmpleado;
                }
                else if((strcmp(gente[i].apellido, gente[j].apellido) < 0 && criterioS == 0))
                {
                    auxEmpleado = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxEmpleado;
                }
                else if((strcmp(gente[i].apellido, gente[j].apellido) == 0) && gente[i].sector > gente[j].sector && criterioA == 1)
                {
                    auxEmpleado = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxEmpleado;
                }
                else if(gente[i].apellido == gente[j].apellido && gente[i].sector < gente[j].sector && criterioA == 0)
                {
                    auxEmpleado = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxEmpleado;
                }
            }
        }
    }

    return 0;

}

float cantidadEmpleados(eEmpleado gente[], int tam)
{
    float contadorEmpleados = 0;

    if( gente != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(gente[i].isEmpty == 0)
            {
                contadorEmpleados++;
            }
        }
    }
    return contadorEmpleados;
}

float acumuladorSalario(eEmpleado gente[], int tam)
{
    float acumuladorSueldo = 0;

    if( gente != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(gente[i].salario != 0)
            {
                acumuladorSueldo = acumuladorSueldo + gente[i].salario;
            }
        }
    }
    return acumuladorSueldo;
}

float promedioSueldos(eEmpleado gente[], int tam)
{
    float promedio;

    promedio = (acumuladorSalario(gente, tam)) / (cantidadEmpleados(gente, tam));

    return promedio;
}

float sueldosSuperioresAlPromedio(eEmpleado gente[], int tam)
{
    float proSueldos;
    float contadorSuperioresAlPromedio = 0;

    proSueldos = promedioSueldos(gente, tam);

    if( gente != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(gente[i].salario > proSueldos)
            {
                contadorSuperioresAlPromedio++;
            }

        }
    }

    return contadorSuperioresAlPromedio;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"

#define TAM 1000
#define ASC 1
#define DESC 0

typedef struct
{
    int id;//4byte
    char nombre[51];//51 byte
    char apellido[51];
    char sexo;//1 byte
    float salario;//4 byte
    int sector;
    int isEmpty;// 1 esta vacia 0 esta llena

} eEmpleado;


int initEmployees(eEmpleado gente[], int tam);
int printEmployees(eEmpleado gente[], int tam);
void mostrarEmpleado(eEmpleado unEmpleado);
int buscarLibre(eEmpleado gente[], int tam);
int addEmployee(eEmpleado gente[], int tam, int id); //si devuelve 0 todo ok, si devuelve 1 hubo una falla en parametros o sistema completo
int removeEmployee(eEmpleado gente[], int tam);
int modificarEmpleado(eEmpleado gente[], int tam);
int findEmployeeById(eEmpleado gente[], int tam, int id);
int sortEmployees(eEmpleado gente[], int tam, int criterioS, int criterioA);
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo);
float cantidadEmpleados(eEmpleado gente[], int tam);
float acumuladorSalario(eEmpleado gente[], int tam);
float promedioSueldos(eEmpleado gente[], int tam);
float sueldosSuperioresAlPromedio(eEmpleado gente[], int tam);

int main()
{
    int proximoLegajo = 0;
    int rta;
    int respuesta;
    int opcion;
    int flag1;
    float cantidadIngresados;
    float acumuladorSalarioIngresado;
    float promedioSueldosIngresados;
    float sueldosSuperioresAPromedio;

    flag1 = 0;

    eEmpleado lista [TAM];

    if(initEmployees(lista, TAM)==0)
    {
        printf("Personas inicializadas con exito!\n\n");
    }
    else
    {
        printf("Ha ocurrido un problema al inicializar personas");
    }

    proximoLegajo += 1;

    do
    {
        system("cls");

        respuesta = utn_getNumero(&opcion,"*** ABM Empleados ***\n\n1 ALTA\n2 MODIFICAR\n3 BAJA\n4 INFORMAR\n5 SALIR\n\n\nQue opcion elige? \n\n","\nError la opcion debe ser desde 1 a 5\n\n",1,5);

        if(!respuesta)
        {
            switch(opcion)
            {

            case 1:
                if(addEmployee(lista, TAM, proximoLegajo) == 0)
                {
                    proximoLegajo++;
                    printf("\nALTA EXITOSA!\n\n");
                    flag1 = 1;
                }
                else
                {
                    printf("Problema para realizar el alta\n\n");
                }
                break;
            case 2:
                if( flag1 == 1)
                {
                    rta = modificarEmpleado(lista, TAM);
                    if(rta == 0)
                    {
                        printf("La modificacion fue exitosa\n\n");
                    }
                }
                else
                {
                    printf("\nAun no se cargaron empleados, elija la opcion 1 y carguelos.\n\n");
                }
                break;
            case 3:
                if( flag1 == 1)
                {
                    rta = removeEmployee(lista, TAM);

                    if( rta == 0)
                    {
                        printf("\n\nBaja exitosa\n\n");
                    }
                    else if(rta == 2)
                    {
                        printf("\n\nBaja cancelada por usuario\n\n");
                    }
                    else if(rta == 3)
                    {
                        printf("\nNo existe un empleado con ese id.\n\n");
                    }
                    else if(rta == 4)
                    {
                        printf("\nEliminaste todos los empleados. Carga nuevos en la opcion 1.\n\n");
                    }
                }
                else
                {
                    printf("\nAun no se cargaron empleados, elija la opcion 1 y carguelos.\n\n");
                }

                break;
            case 4:
                if( flag1 == 1)
                {
                    system("cls");
                    printf("********Epleados ordenados por Apellido y si tienen el mismo Apellido, desempatamos ordenando por Sector********\n\n");
                    sortEmployees(lista, TAM, 1, 1);
                    printEmployees(lista,TAM);

                    cantidadIngresados = cantidadEmpleados(lista,TAM);
                    printf("\nCantidad empleados: %2.f.\n\n",cantidadIngresados);

                    acumuladorSalarioIngresado = acumuladorSalario(lista, TAM);
                    printf("Sueldos acumulados: %2.f.\n\n",acumuladorSalarioIngresado);

                    promedioSueldosIngresados = promedioSueldos(lista, TAM);
                    printf("El promedio de los sueldos es: %2.f.\n\n",promedioSueldosIngresados);

                    sueldosSuperioresAPromedio = sueldosSuperioresAlPromedio(lista, TAM);
                    printf("La cantidad de sueldos superiores al promedio son:%2.f.\n\n", sueldosSuperioresAPromedio);
                }
                else
                {
                    printf("\nAun no se cargaron empleados, elija la opcion 1 y carguelos.\n\n");
                }

                break;
            default:
                break;
            }

            system("pause");
        }
        else
        {
            system("pause");
        }

    }
    while( opcion != 5);

    return 0;
}
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo)
{
    int retorno = -1;
    int bufferInt;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%d", &bufferInt);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        while(retorno == 0);

    }
    return retorno;
}

int initEmployees(eEmpleado gente[], int tam)
{

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

int printEmployees(eEmpleado gente[], int tam)
{

    int error = 1;
    int flag = 0;

    if( gente != NULL && tam > 0)
    {
        printf("     ID         Nombre            Apellido        Salario      Sector\n");
        printf("---------------------------------------------------------------------\n\n");

        for(int i=0; i<tam; i++)
        {
            if(gente[i].isEmpty == 0)
            {
                mostrarEmpleado(gente[i]);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("No hay empleados en la lista");
        }
        printf("\n\n");

        error = 0;

    }
    return error;

}
void mostrarEmpleado(eEmpleado unEmpleado)
{
    printf("\n | %4d |   %12s   |   %12s   |  %6.2f | %6d\n\n", unEmpleado.id, unEmpleado.nombre, unEmpleado.apellido, unEmpleado.salario, unEmpleado.sector);

}

int buscarLibre(eEmpleado gente[], int tam) //////para dar de alta
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

int soloLetras(char cadena[])
{
    int retorno = 1;

    for(int i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'a'||cadena[i]>'z')&&(cadena[i]<'A'||cadena[i]>'Z'))
        {
            retorno=0;
        }
    }

    return retorno;
}

void largoCadena(char cadena[],int tamanio,char mensaje[],char errorMensaje[])
{
    puts(mensaje);
    fflush(stdin);;
    fgets(cadena,tamanio,stdin);
    cadena[strlen(cadena)-1]='\0';

    while(!soloLetras(cadena))
    {
        puts(errorMensaje);
        fflush(stdin);
        fgets(cadena,tamanio,stdin);
        cadena[strlen(cadena)-1]='\0';
    }
}

int soloPositivos(char numero[])
{
    int retorno = 1;

    for(int i=0;numero[i]!='\0';i++)
    {
        if(numero[i]<'0'||numero[i]>'9')
        {
            retorno=0;
            break;
        }
    }

    return retorno;
}

int soloEntero(char mensaje[],char mensajeError[])
{
    char numeroGuardar[32];
    int numero;

    puts(mensaje);
    fflush(stdin);
    fgets(numeroGuardar,sizeof(numeroGuardar),stdin);
    numeroGuardar[strlen(numeroGuardar)-1]='\0';

    while(!soloPositivos(numeroGuardar))
    {
        puts(mensajeError);
        fflush(stdin);
        fgets(numeroGuardar,sizeof(numeroGuardar),stdin);
        numeroGuardar[strlen(numeroGuardar)-1]='\0';
    }

    numero = atoi(numeroGuardar);

    return numero;
}

int addEmployee(eEmpleado gente[], int tam, int id)
{

    int error = 1;
    int indice;
    int entero;
    eEmpleado nuevoEmpleado;

    if(gente!=NULL && tam > 0 && id > 0)
    {

        system("cls");
        printf("ALTA DE EMPLEADO\n\n");
        indice = buscarLibre(gente, tam);

        if(indice == -1)
        {
            printf("El sistema esta completo.\n");
        }
        else
        {
            //aplicar validaciones a las cargas
            nuevoEmpleado.id = id;
            nuevoEmpleado.isEmpty = 0;

            largoCadena(nuevoEmpleado.nombre,51,"\n\nIngrese nombre: ","\nReingrese nombre, escribio uno con caracteres diferentes a letras.");
            printf("El nombre ingresado es:%s\n",nuevoEmpleado.nombre);

            largoCadena(nuevoEmpleado.apellido,51,"\n\nIngrese apellido: ","\nReingrese apellido, escribio uno con caracteres diferentes a letras.");
            printf("\nEl apellido ingresado es:%s\n",nuevoEmpleado.apellido);

            printf("Ingrese salario: ");
            scanf("%f", &nuevoEmpleado.salario);

            //entero = soloEntero("\nIngrese salario: ","\nIngrese solo numeros positivos.\n");

            printf("Ingrese sector: ");
            scanf("%d", &nuevoEmpleado.sector);
            //entero = soloEntero("\nIngrese sector: ","\nIngrese solo numeros positivos para el sector.\n");

            gente[indice] = nuevoEmpleado;
            error = 0;
        }
    }

    return error;
}

int findEmployeeById(eEmpleado gente[], int tam, int id)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(gente[i].id == id && gente[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int removeEmployee(eEmpleado gente[], int tam)
{
    int error = 1;
    int id;
    int indice;
    int confirma;
    int respuesta;
    int cantEmpleados;

    cantEmpleados = cantidadEmpleados(gente,tam);

    if(gente != NULL && tam > 0 && cantEmpleados >0)
    {
        system("cls");
        printf("******************** BAJA DE EMPLEADO **********************\n");
        printEmployees(gente, tam);
        printf("Ingrese el id: ");
        scanf("%d", &id);

        indice = findEmployeeById(gente, tam, id);

        if( indice == -1)
        {
            error = 3;
        }
        else
        {
            mostrarEmpleado(gente[indice]);
            do
            {
                respuesta = utn_getNumero(&confirma,"\nConfirma baja: Presione 1 para dar de baja o 2 para NO dar de baja.\n\nQue opcion elige? \n\n","\nError la opcion debe ser desde 1 o 2\n\n",1,2);

                if(!respuesta)
                {
                    switch(confirma)
                    {

                    case 1:
                        gente[indice].isEmpty = 1;
                        error = 0;
                        break;
                    case 2:
                        error = 2;
                        break;
                    default:
                        break;
                    }

                    system("pause");
                }
            }
            while(confirma != 1 && confirma !=2);
        }
    }
    else
    {
        error = 4;
    }

    return error;
}

int modificarEmpleado(eEmpleado gente[], int tam)
{
    int id;
    int indice;
    int elegido;
    int respondio;
    eEmpleado nuevosDatos;

    if(gente != NULL && tam > 0)
    {
        system("cls");
        printf("    *** MODIFICAR EMPLEADO ***\n");
        printEmployees(gente, tam);
        printf("\nIngrese el id: ");
        scanf("%d", &id);

        indice = findEmployeeById(gente, tam, id);

        if( indice == -1)
        {
            printf("\nNo existe un empleado con ese id.\n");
        }
        else
        {
            mostrarEmpleado(gente[indice]);

            do
            {
                system("cls");

                respondio = utn_getNumero(&elegido,"Que desea modificar?\n\n1 NOMBRE\n2 APELLIDO\n3 SALARIO\n4 SECTOR\n5 TERMINAR\n\nQue opcion elige? \n\n","\nError la opcion debe ser desde 1 a 4\n\n",1,5);

                if(!respondio)
                {
                    switch(elegido)
                    {

                    case 1:
                        printf("\nIngrese nuevo nombre: ");
                        fflush(stdin);
                        gets(nuevosDatos.nombre);
                        strcpy(gente[indice].nombre, nuevosDatos.nombre);
                        break;
                    case 2:
                        printf("\nIngrese nuevo apellido: ");
                        fflush(stdin);
                        gets(nuevosDatos.apellido);
                        strcpy(gente[indice].apellido, nuevosDatos.apellido);
                        break;
                    case 3:
                        printf("\nIngrese nuevo salario: ");
                        fflush(stdin);
                        scanf("%f", &nuevosDatos.salario);
                        gente[indice].salario = nuevosDatos.salario;
                        break;
                    case 4:
                        printf("\nIngrese nuevo sector: ");
                        fflush(stdin);
                        scanf("%d", &nuevosDatos.sector);
                        gente[indice].sector = nuevosDatos.sector;
                        break;
                    default:
                        break;
                    }
                    system("pause");
                }
                else
                {
                    system("pause");
                }

                printf("\nLos datos modificados quedaron de este modo: \n\n");
                mostrarEmpleado(gente[indice]);

            }
            while( elegido != 5);
        }
    }
    return 0;
}

int sortEmployees(eEmpleado gente[], int tam, int criterioS, int criterioA)
{
    eEmpleado auxEmpleado;

    if(gente!=NULL && tam>0 && criterioS>=0 && criterioS<=1 && criterioA >= 0 && criterioA <= 1)
    {
        for(int i=0; i-tam -1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if((strcmp(gente[i].apellido, gente[j].apellido) > 0 && criterioS == 1))
                {
                    auxEmpleado = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxEmpleado;
                }
                else if((strcmp(gente[i].apellido, gente[j].apellido) < 0 && criterioS == 0))
                {
                    auxEmpleado = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxEmpleado;
                }
                else if((strcmp(gente[i].apellido, gente[j].apellido) == 0) && gente[i].sector > gente[j].sector && criterioA == 1)
                {
                    auxEmpleado = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxEmpleado;
                }
                else if(gente[i].apellido == gente[j].apellido && gente[i].sector < gente[j].sector && criterioA == 0)
                {
                    auxEmpleado = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxEmpleado;
                }
            }
        }
    }

    return 0;

}

float cantidadEmpleados(eEmpleado gente[], int tam)
{
    float contadorEmpleados = 0;

    if( gente != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(gente[i].isEmpty == 0)
            {
                contadorEmpleados++;
            }
        }
    }
    return contadorEmpleados;
}

float acumuladorSalario(eEmpleado gente[], int tam)
{
    float acumuladorSueldo = 0;

    if( gente != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(gente[i].salario != 0)
            {
                acumuladorSueldo = acumuladorSueldo + gente[i].salario;
            }
        }
    }
    return acumuladorSueldo;
}

float promedioSueldos(eEmpleado gente[], int tam)
{
    float promedio;

    promedio = (acumuladorSalario(gente, tam)) / (cantidadEmpleados(gente, tam));

    return promedio;
}

float sueldosSuperioresAlPromedio(eEmpleado gente[], int tam)
{
    float proSueldos;
    float contadorSuperioresAlPromedio = 0;

    proSueldos = promedioSueldos(gente, tam);

    if( gente != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(gente[i].salario > proSueldos)
            {
                contadorSuperioresAlPromedio++;
            }

        }
    }

    return contadorSuperioresAlPromedio;
}


int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo)
{
    int retorno = -1;
    int bufferInt;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%d", &bufferInt);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        while(retorno == 0);

    }
    return retorno;
}

int initEmployees(eEmpleado gente[], int tam)
{

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

int printEmployees(eEmpleado gente[], int tam)
{

    int error = 1;
    int flag = 0;

    if( gente != NULL && tam > 0)
    {
        printf("     ID         Nombre            Apellido        Salario      Sector\n");
        printf("---------------------------------------------------------------------\n\n");

        for(int i=0; i<tam; i++)
        {
            if(gente[i].isEmpty == 0)
            {
                mostrarEmpleado(gente[i]);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("No hay empleados en la lista");
        }
        printf("\n\n");

        error = 0;

    }
    return error;

}
void mostrarEmpleado(eEmpleado unEmpleado)
{
    printf("\n | %4d |   %12s   |   %12s   |  %6.2f | %6d\n\n", unEmpleado.id, unEmpleado.nombre, unEmpleado.apellido, unEmpleado.salario, unEmpleado.sector);

}

int buscarLibre(eEmpleado gente[], int tam)
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

int soloLetras(char cadena[])
{
    int retorno = 1;

    for(int i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'a'||cadena[i]>'z')&&(cadena[i]<'A'||cadena[i]>'Z'))
        {
            retorno=0;
        }
    }

    return retorno;
}

void largoCadena(char cadena[],int tamanio,char mensaje[],char errorMensaje[])
{
    puts(mensaje);
    fflush(stdin);;
    fgets(cadena,tamanio,stdin);
    cadena[strlen(cadena)-1]='\0';

    while(!soloLetras(cadena))
    {
        puts(errorMensaje);
        fflush(stdin);
        fgets(cadena,tamanio,stdin);
        cadena[strlen(cadena)-1]='\0';
    }
}
int addEmployee(eEmpleado gente[], int tam, int id)
{

    int error = 1;
    int indice;
    eEmpleado nuevoEmpleado;

    if(gente!=NULL && tam > 0 && id > 0)
    {

        system("cls");
        printf("ALTA DE EMPLEADO\n\n");
        indice = buscarLibre(gente, tam);

        if(indice == -1)
        {
            printf("El sistema esta completo.\n");
        }
        else
        {
            nuevoEmpleado.id = id;
            nuevoEmpleado.isEmpty = 0;

            largoCadena(nuevoEmpleado.nombre,51,"\n\nIngrese nombre: ","\nReingrese nombre, escribio uno con caracteres diferentes a letras.");
            printf("El nombre ingresado es:%s\n",nuevoEmpleado.nombre);

            largoCadena(nuevoEmpleado.apellido,51,"\n\nIngrese apellido: ","\nReingrese apellido, escribio uno con caracteres diferentes a letras.");
            printf("\nEl apellido ingresado es:%s\n",nuevoEmpleado.apellido);

            printf("Ingrese salario: ");
            scanf("%f", &nuevoEmpleado.salario);

            printf("Ingrese sector: ");
            scanf("%d", &nuevoEmpleado.sector);

            gente[indice] = nuevoEmpleado;
            error = 0;
        }
    }

    return error;
}

int findEmployeeById(eEmpleado gente[], int tam, int id)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(gente[i].id == id && gente[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int removeEmployee(eEmpleado gente[], int tam)
{
    int error = 1;
    int id;
    int indice;
    int confirma;
    int respuesta;
    int cantEmpleados;

    cantEmpleados = cantidadEmpleados(gente,tam);

    if(gente != NULL && tam > 0 && cantEmpleados >0)
    {
        system("cls");
        printf("******************** BAJA DE EMPLEADO **********************\n");
        printEmployees(gente, tam);
        printf("Ingrese el id: ");
        scanf("%d", &id);

        indice = findEmployeeById(gente, tam, id);

        if( indice == -1)
        {
            error = 3;
        }
        else
        {
            mostrarEmpleado(gente[indice]);
            do
            {
                respuesta = utn_getNumero(&confirma,"\nConfirma baja: Presione 1 para dar de baja o 2 para NO dar de baja.\n\nQue opcion elige? \n\n","\nError la opcion debe ser desde 1 o 2\n\n",1,2);

                if(!respuesta)
                {
                    switch(confirma)
                    {

                    case 1:
                        gente[indice].isEmpty = 1;
                        error = 0;
                        break;
                    case 2:
                        error = 2;
                        break;
                    default:
                        break;
                    }

                    system("pause");
                }
            }
            while(confirma != 1 && confirma !=2);
        }
    }
    else
    {
        error = 4;
    }

    return error;
}

int modificarEmpleado(eEmpleado gente[], int tam)
{
    int id;
    int indice;
    int elegido;
    int respondio;
    eEmpleado nuevosDatos;

    if(gente != NULL && tam > 0)
    {
        system("cls");
        printf("    *** MODIFICAR EMPLEADO ***\n");
        printEmployees(gente, tam);
        printf("\nIngrese el id: ");
        scanf("%d", &id);

        indice = findEmployeeById(gente, tam, id);

        if( indice == -1)
        {
            printf("\nNo existe un empleado con ese id.\n");
        }
        else
        {
            mostrarEmpleado(gente[indice]);

            do
            {
                system("cls");

                respondio = utn_getNumero(&elegido,"Que desea modificar?\n\n1 NOMBRE\n2 APELLIDO\n3 SALARIO\n4 SECTOR\n5 TERMINAR\n\nQue opcion elige? \n\n","\nError la opcion debe ser desde 1 a 4\n\n",1,5);

                if(!respondio)
                {
                    switch(elegido)
                    {

                    case 1:
                        printf("\nIngrese nuevo nombre: ");
                        fflush(stdin);
                        gets(nuevosDatos.nombre);
                        strcpy(gente[indice].nombre, nuevosDatos.nombre);
                        break;
                    case 2:
                        printf("\nIngrese nuevo apellido: ");
                        fflush(stdin);
                        gets(nuevosDatos.apellido);
                        strcpy(gente[indice].apellido, nuevosDatos.apellido);
                        break;
                    case 3:
                        printf("\nIngrese nuevo salario: ");
                        fflush(stdin);
                        scanf("%f", &nuevosDatos.salario);
                        gente[indice].salario = nuevosDatos.salario;
                        break;
                    case 4:
                        printf("\nIngrese nuevo sector: ");
                        fflush(stdin);
                        scanf("%d", &nuevosDatos.sector);
                        gente[indice].sector = nuevosDatos.sector;
                        break;
                    default:
                        break;
                    }
                    system("pause");
                }
                else
                {
                    system("pause");
                }

                printf("\nLos datos modificados quedaron de este modo: \n\n");
                mostrarEmpleado(gente[indice]);

            }
            while( elegido != 5);
        }
    }
    return 0;
}

int sortEmployees(eEmpleado gente[], int tam, int criterioS, int criterioA)
{
    eEmpleado auxEmpleado;

    if(gente!=NULL && tam>0 && criterioS>=0 && criterioS<=1 && criterioA >= 0 && criterioA <= 1)
    {
        for(int i=0; i-tam -1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if((strcmp(gente[i].apellido, gente[j].apellido) > 0 && criterioS == 1))
                {
                    auxEmpleado = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxEmpleado;
                }
                else if((strcmp(gente[i].apellido, gente[j].apellido) < 0 && criterioS == 0))
                {
                    auxEmpleado = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxEmpleado;
                }
                else if((strcmp(gente[i].apellido, gente[j].apellido) == 0) && gente[i].sector > gente[j].sector && criterioA == 1)
                {
                    auxEmpleado = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxEmpleado;
                }
                else if(gente[i].apellido == gente[j].apellido && gente[i].sector < gente[j].sector && criterioA == 0)
                {
                    auxEmpleado = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxEmpleado;
                }
            }
        }
    }

    return 0;

}

float cantidadEmpleados(eEmpleado gente[], int tam)
{
    float contadorEmpleados = 0;

    if( gente != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(gente[i].isEmpty == 0)
            {
                contadorEmpleados++;
            }
        }
    }
    return contadorEmpleados;
}

float acumuladorSalario(eEmpleado gente[], int tam)
{
    float acumuladorSueldo = 0;

    if( gente != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(gente[i].salario != 0)
            {
                acumuladorSueldo = acumuladorSueldo + gente[i].salario;
            }
        }
    }
    return acumuladorSueldo;
}

float promedioSueldos(eEmpleado gente[], int tam)
{
    float promedio;

    promedio = (acumuladorSalario(gente, tam)) / (cantidadEmpleados(gente, tam));

    return promedio;
}

float sueldosSuperioresAlPromedio(eEmpleado gente[], int tam)
{
    float proSueldos;
    float contadorSuperioresAlPromedio = 0;

    proSueldos = promedioSueldos(gente, tam);

    if( gente != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(gente[i].salario > proSueldos)
            {
                contadorSuperioresAlPromedio++;
            }

        }
    }

    return contadorSuperioresAlPromedio;
}





