#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
    //int isEmpty;
} eColor;

#endif // COLOR_H_INCLUDED

void mostrarColor(eColor color);
int mostrarColores(eColor color[], int tam);
int validarColor(eColor color[], int tamC, int id);
