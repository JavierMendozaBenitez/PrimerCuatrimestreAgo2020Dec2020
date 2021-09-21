#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    float altura;
}ePersona;

int personaSetId(ePersona* persona, int id);
int personaSetNombre(ePersona* persona, char* nombre);
int personaSetSexo(ePersona* persona, char sexo);
int personaSetAltura(ePersona* persona, float altura);

int personaGetId(int* pId, ePersona* persona);
int personaGetNombre(char* pNombre, ePersona* persona);
int personaGetSexo(char* pSexo, ePersona* persona);
int personaGetAltura(float* pAltura, ePersona* persona);


int initPersonas(ePersona** vec, int tam);
int buscarLibrePersonas(int* pIndice, ePersona** vec, int tam);
int buscarPersona(int* pIndice, int id, ePersona** vec, int tam);
int mostrarPersona(ePersona* persona);
int mostrarPersonas(ePersona** vec, int tam);


ePersona* new_Persona();
ePersona* new_PersonaParam(int id, char* nombre, char sexo, float altura);

int destruirPersona(ePersona* persona);

#endif // PERSONAS_H_INCLUDED
