#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
} eEmpleado;


#endif // EMPLEADO_H_INCLUDED

void mostrarEmpleadoRef(eEmpleado* empleado);//muestra por referencia
void mostrarEmpleado(eEmpleado empleado);//mustra por valor
int mostrarEmpleados(eEmpleado* lista, int tam);

int ordenarEmpleadosNombre(eEmpleado* lista, int tam);
//Constructores
eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int legajo, char* nombre, char sexo, float sueldo);
//setters
int empleadoSetLegajo(eEmpleado* emp, int legajo);
int empleadoSetNombre(eEmpleado* emp, char* nombre);
int empleadoSetSexo(eEmpleado* emp, char sexo);
int empleadoSetSueldo(eEmpleado* emp, float sueldo);
//Getters
int empleadoGetLegajo(eEmpleado* emp, int* pLegajo);
int empleadoGetNombre(eEmpleado* emp, char* pNombre);
int empleadoGetSexo(eEmpleado* emp, char* pSexo);
int empleadoGetSueldo(eEmpleado* emp, float* pSueldo);
