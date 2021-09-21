#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[120];
    char sexo;
    float sueldo;
}eEmpleado;

eEmpleado* new_Empleado();//esto para hacerlo en memoria dinamica
//eEmpleado* new_EmpleadoParam(int id, char* nombre, char sexo, float sueldo);//esto para hacerlo en memoria dinamica
eEmpleado* new_EmpleadoParam(char* id, char* nombre, char* sexo, char* sueldo);//recibe todo como cadena y haces la conversion aca

int main()
{
    /*int id;
    char nombre[20];
    char sexo;
    float sueldo;*/

    char buffer[4][100];//es para guardar todos los datos en esta matriz en cada fila, leeremos todo como texto

    eEmpleado* auxEmpleado;

    int cant;

    FILE* f;

    //f = fopen("numeros.txt", "r");//lo abris como lectura de texto
    //f = fopen("empleados.csv", "r");//lo abris como lectura de texto
    f = fopen("listaEmpleados.csv", "r");//lo creamos en file3, lo creamos como csv texto y lo leo con uno que lee csv
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);//lectura fantasma, es para que haga una sola lectura y salteas la primera linea que es un encabezado
    printf("%s  %s  %s  %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]);//asi podes mostrar el encbezado antes del while

    while(!feof(f))//con feof recorres hasta que encuentre el final del archivo, son los datos de un empleado
    {
        //cant = fscanf(f,"%d,%[^,],%c,%f\n", &id, nombre, &sexo, &sueldo);//le decis que tiene que leer, asi levanta la primera linea, el cursor quedo al inicio de la segunda linea
        cant = fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);//ahora leo todo como texto

        if(cant == 4)//mostras si devolvio 4 variables en fscanf
        {
            //auxEmpleado = new_EmpleadoParam(id, nombre, sexo, sueldo);//validar que sea distinto de null, primera version
            //auxEmpleado = new_EmpleadoParam(atoi(buffer[0]), buffer[1], buffer[2][0], atof(buffer[3]));//ahora convierto los caracteres en el tipo de dato que necesito cuando llamo al constructor
/*!=NULL*/auxEmpleado = new_EmpleadoParam(buffer[0], buffer[1], buffer[2], buffer[3]);//ahora ya estan convertidos entoces le paso los buffer sin el atoi o el atof

            printf("%d %s %c %.2f\n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado->sexo, auxEmpleado->sueldo);//si pude leer lo muestro
        }
        else
        {
            break;//asi salis del while si no hay 4
        }
    }

    fclose(f);

    return 0;
}

eEmpleado* new_Empleado()
{
    return (eEmpleado*) malloc(sizeof(eEmpleado));
}

//eEmpleado* new_EmpleadoParam(int id, char* nombre, char sexo, float sueldo)//constructor. Faltan los setters y getters
eEmpleado* new_EmpleadoParam(char* id, char* nombre, char* sexo, char* sueldo)//recibe todo como cadena y haces la conversion aca
{
    eEmpleado* nuevoEmpleado = new_Empleado();

    if(nuevoEmpleado != NULL)
    {

        /*if(personaSetId(nuevaPersona, id) ||
            personaSetNombre(nuevaPersona, nombre) ||
            personaSetSexo(nuevaPersona, sexo) ||
            personaSetAltura(nuevaPersona, altura)
          )
        {
            free(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }*/
        //nuevoEmpleado->id = id;
        nuevoEmpleado->id = atoi(id);
        strcpy(nuevoEmpleado->nombre, nombre);
        //nuevoEmpleado->sexo = sexo;
        nuevoEmpleado->sexo = sexo[0];//le pasas el primer caracter
        //nuevoEmpleado->sueldo = sueldo;
        nuevoEmpleado->sueldo = atof(sueldo);//los convertis
    }

    return nuevoEmpleado;
}
