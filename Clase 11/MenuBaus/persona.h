#include "fecha.h"
#include "deporte.h"

#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct
{
    int legajo;//4byte
    char nombre[20];//20 byte
    char sexo;//1 byte
    float altura;//4 byte
    eFecha fNac;
    int idDeporte;
    int isEmpty;// 1 esta vacia 0 esta llena

} ePersona;


#endif // PERSONA_H_INCLUDED

#define ASC 1
#define DESC 0

int inicializarPersonas(ePersona gente[], int tam);
int mostrarPersonas(ePersona gente[], int tam, eDeporte sports[], int tamD);
void mostrarPersona(ePersona unaPersona, eDeporte sports[], int tam);
int buscarLibre(ePersona gente[], int tam);
int altaPersona(ePersona gente[], int tam, eDeporte sports[], int tamD, int legajo); //si devuelve 0 todo ok, si devuelve 1 hubo una falla en parametros o sistema completo
int bajaPersona(ePersona gente[], int tam, eDeporte sports[], int tamD);
int modificarPersona(ePersona gente[], int tam, eDeporte sports[], int tamD);
int buscarPersona(ePersona gente[], int tam, int legajo);
int hardcodearPersonas(ePersona gente[], int tam, int cantidad);
int ordenarPersonasNombre(ePersona gente[], int tam, int criterio);
int ordenarPersonasSexoAltura(ePersona gente[], int tam, int criterioS, int criterioA);
int obtenerDescripcionDeporte(eDeporte sports[], int tam, int id, char descripcion[]);
int obtenerNombrePersona(ePersona gente[], int tam, int legajo, char nombre[]);
int validarLegajoPersona(ePersona gente[], int tam, int legajo);
