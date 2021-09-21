#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float altura;

}ePersona;
int main()
{
    ePersona per1;
    per1.legajo = 1234;
    strcpy(per1.nombre, "Juan");
    per1.sexo = 'm';
    per1.altura = 1.78;

    printf("Leg: %d Nombre: %s Sexo: %c Altura: %.2f\n", per1.legajo, per1.nombre, per1.sexo, per1.altura);

    return 0;
}
