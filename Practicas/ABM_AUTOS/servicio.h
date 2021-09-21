#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
} eServicio;

#endif // SERVICIO_H_INCLUDED

void mostrarServicio(eServicio servicio);
int mostrarServicios(eServicio servicio[], int tam);
int validarServicio(eServicio servicio[], int tamS, int id);

