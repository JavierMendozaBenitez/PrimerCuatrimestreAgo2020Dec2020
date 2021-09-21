#include "fecha.h"
#include "persona.h"
#include "comida.h"
#include "deporte.h"

#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED

typedef struct
{
    int id;
    int legajo;
    int idComida;
    eFecha fecha;
    int isEmpty;
}eAlmuerzo;


#endif // ALMUERZO_H_INCLUDED

int inicializarAlmuerzos(eAlmuerzo almuerzo[], int tam);
int mostrarAlmuerzos(eAlmuerzo almuerzos[], int tamA, ePersona gente[], int tamP, eComida foods[], int tamC);
void mostrarAlmuerzo(eAlmuerzo unAlmuerzo, ePersona gente[], int tamP, eComida foods[], int tamC);
int buscarAlmuerzoLibre(eAlmuerzo almuerzo[], int tam);
int altaAlmuerzo(eAlmuerzo almuerzos[], int tamA, ePersona gente[], int tamP, eComida foods[], int tamC, eDeporte sports[], int tamD, int id);
