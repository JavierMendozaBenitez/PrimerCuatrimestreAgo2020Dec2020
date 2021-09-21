#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
} eMarca;

#endif // MARCA_H_INCLUDED

void mostrarMarca(eMarca marca);
int mostrarMarcas(eMarca marca[], int tam);
int validarMarca(eMarca marca[], int tamM, int id);
