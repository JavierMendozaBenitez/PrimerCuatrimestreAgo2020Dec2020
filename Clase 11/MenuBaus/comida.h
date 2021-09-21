#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
    float precio;
}eComida;

#endif // COMIDA_H_INCLUDED

void mostrarComida(eComida food);
int mostrarComidas(eComida foods[], int tam);
int validarIdComida(eComida foods[], int tam, int id);
int obtenerDescripcionComida(eComida foods[], int tam, int id, char descripcion[]);
