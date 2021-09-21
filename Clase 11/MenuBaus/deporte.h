
#ifndef DEPORTE_H_INCLUDED
#define DEPORTE_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eDeporte;

#endif // DEPORTE_H_INCLUDED

void mostrarDeporte(eDeporte sport);
int mostrarDeportes(eDeporte sports[], int tam);
int validarIdDeporte(eDeporte sports[], int tam, int id);
