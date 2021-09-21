#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    float sueldo;
}eEmpleado;

int main()
{
    //eEmpleado emp = {1234, "Jose", 'm', 38300.50};
    eEmpleado emp;

    //FILE* f = fopen("datos.txt", "wb");//abre en binario, lee el archivo en el disco rigido y lo carga en memoria y devuelve la direccion de memoria donde arranca lo que leyo
    FILE* f = fopen("datos.txt", "rb");//lo abris para lectura en binario
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }
    //fwrite(&emp, sizeof(eEmpleado), 1, f);//para binario, es para escribir en binario. Se guarda exactamente como esta en memoria, lo guardas como binario
    fread(&emp, sizeof(eEmpleado), 1, f);//lees en binario y la cargas, se guarda exactamente como esta en memoria
    //fprintf(f, "%d  %s  %c  %.2f", emp.id, emp.nombre, emp.sexo, emp.sueldo);//lo lees y lo veras como texto, lo guardas como texto, con las mascaras le decis como leerlos, como int, float, texto
    fclose(f);//guarda lo que este en memoria al archivo
    printf("%d  %s  %c  %.2f\n", emp.id, emp.nombre, emp.sexo, emp.sueldo);//podes usarlo para verlo en la consola cuando usas rb

    return 0;
}
