#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include "marca.h"
#include "color.h"
//#include "fecha.h"
//#include "trabajo.h"
typedef struct
{
    int id;
    char patente[20];
    int idMarca;//los 4 id deben ser iguales en rango, en el main los id y en dataStore los idMarca
    int idColor;//los 4 id deben ser iguales en rango, en el main los id y en dataStore los idColor
    int modelo;
    int isEmpty;// 1 esta vacia 0 esta llena
} eAuto;

#endif // AUTO_H_INCLUDED

int inicializarAutos(eAuto coche[], int tam);
void mostrarAuto(eAuto coche, eMarca marca[], eColor color[], int tam);
int mostrarAutos(eAuto coche[], eMarca marca[], eColor color[], int tam);
int harcodearDatos(eAuto coche[], int tam, int cantidad);
int buscarLibre(eAuto coche[], int tam);
int altaAuto(eAuto coche[], int tam, eMarca marca[], int tamM, eColor color[], int tamC, int id);
int buscarAuto(eAuto coche[], int tam, char patente[]);
int bajaAutos(eAuto coche[], eMarca marca[], eColor color[], int tam);
int modificarAuto(eAuto coche[], int tam, eMarca marca[], int tamM, eColor color[], int tamC);
int ordenarAutosMarcaPatente(eAuto coche[], eMarca marca[], int tam, int criterioM, int criterioP);
int obtenerDescripcionMarca(eMarca marca[], int tam, int id, char descripcion[]);
int obtenerDescripcionColor(eColor color[], int tam, int id, char nombreColor[]);
int validarPatente(eAuto coche[], int tamA, char patente[]);
