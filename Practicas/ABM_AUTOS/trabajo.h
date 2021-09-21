#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "fecha.h"
#include "servicio.h"
#include "marca.h"
#include "color.h"
#include "auto.h"

typedef struct
{
    int id;
    char patente[20];
    int idServicio;
    eFecha fecha;
    int isEmpty;//1 vacio, 0 lleno
} eTrabajo;

#endif // TRABAJO_H_INCLUDED

//void mostrarTrabajo(eTrabajo trabajo);
void mostrarTrabajo(eTrabajo trabajo, eServicio servicioT[], int tamT, int tamS);
int inicializarTrabajos(eTrabajo trabajo[], int tamT);
//int mostrarTrabajos(eTrabajo trabajo[], int tam);
int mostrarTrabajos(eTrabajo trabajo[], eServicio servicioT[], int tamT, int tamS);
int buscarLibreTrabajo(eTrabajo trabajo[], int tamT);
int altaTrabajo(eTrabajo trabajo[], eServicio servicioT[], eAuto cocheT[], eMarca marcaT[], eColor colorT[], int tamT, int tamS, int tamA, int tamM, int tamC, int id);
