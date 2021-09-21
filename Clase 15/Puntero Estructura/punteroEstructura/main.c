#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fIngreso;
}eEmpleado;

void cargarEmpleado(eEmpleado* pEmpleado);
void mostrarEmpleado(eEmpleado unEmpleado);
void mostrarEmpleadoP(eEmpleado* pEmpleado);

int main()
{
    eEmpleado emp1;

    cargarEmpleado(&emp1);

    mostrarEmpleado(emp1);
    mostrarEmpleadoP(&emp1);

    //printf("Legajo: %d\n", emp1.legajo);
    return 0;
}

void cargarEmpleado(eEmpleado* pEmpleado)
{
    printf("Ingrese legajo: ");
    //scanf("%d", &(*pEmpleado).legajo);
    scanf("%d", & pEmpleado->legajo);

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(pEmpleado->nombre);

    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c", &pEmpleado->sexo);

    printf("Ingrese sueldo: ");
    scanf("%f", &pEmpleado->sueldo);

    printf("Ingrese fecha ingreso dd/mm/aaaa: ");
    scanf("%d/%d/%d",
            &pEmpleado->fIngreso.dia,
            &pEmpleado->fIngreso.mes,
            &pEmpleado->fIngreso.anio);
}

void mostrarEmpleado(eEmpleado unEmpleado)
{
   printf("Legajo: %d   Nombre: %s   Sexo: %c     Sueldo: %.2f    Ingreso: %02d/%02d/%d\n",
           unEmpleado.legajo,
           unEmpleado.nombre,
           unEmpleado.sexo,
           unEmpleado.sueldo,
           unEmpleado.fIngreso.dia,
           unEmpleado.fIngreso.mes,
           unEmpleado.fIngreso.anio);
}

void mostrarEmpleadoP(eEmpleado* pEmpleado)
{
   printf("Legajo: %d   Nombre: %s   Sexo: %c     Sueldo: %.2f    Ingreso: %02d/%02d/%d\n",
           pEmpleado->legajo,
           pEmpleado->nombre,
           pEmpleado->sexo,
           pEmpleado->sueldo,
           pEmpleado->fIngreso.dia,
           pEmpleado->fIngreso.mes,
           pEmpleado->fIngreso.anio);
}
