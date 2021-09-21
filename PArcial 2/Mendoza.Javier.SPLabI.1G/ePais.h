#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombrePais[128];
    int recuperados;
    int infectados;
    int muertos;
}ePais;

ePais* pais_new();
ePais* pais_newParametros(char* idStr,char* nombreStr,char* recuperados, char* infectados, char* muertos);


int pais_setId(ePais* this,char* id);
int pais_getId(ePais* this,int* id);

int pais_setNombre(ePais* this,char* nombre);
int pais_getNombre(ePais* this,char* nombre);

int pais_setRecuperados(ePais* this,char* recuperados);
int pais_getRecuperados(ePais* this,int* recuperados);

int pais_setInfectados(ePais* this,char* infectados);
int pais_getInfectados(ePais* this,int* infectados);

int pais_setMuertos(ePais* this,char* muertos);
int pais_getMuertos(ePais* this,int* muertos);

int mostrarPais(ePais* pais);
int mostrarPaises(LinkedList* lista);

int paisSortByName(void* paisA, void* paisB);
int paisSortById(void* paisA, void* paisB);
int paisSortByRecuperados(void* paisA, void* paisB);
int paisSortByInfectados(void* paisA, void* paisB);
int paisSortByMuertos(void* paisA, void* paisB);

ePais* pFunc (void* element);
int filtrarExitosos(void* elemento);
int filtrarAlHorno(void* elemento);

#endif // employee_H_INCLUDED


