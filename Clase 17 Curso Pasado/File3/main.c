#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre[120];
    char sexo;
    float sueldo;
}eEmpleado;

int main()
{
    eEmpleado lista[] = {{1234,"Ana",'f',45000},{4444,"Miguel",'m',42000},{8976,"Analia",'f',49000}};

    FILE* f;

    f = fopen("listaEmpleados.csv", "w");//aca escribimos en texto en el archivo que usaremos en File2
    /*falta validacion*/

    for(int i=0; i < 3; i++)
    {
        fprintf(f, "%d,%s,%c,%.2f\n", lista[i].id, lista[i].nombre, lista[i].sexo, lista[i].sueldo);//lo mostras en texto
    }

    fclose(f);

    return 0;
}
