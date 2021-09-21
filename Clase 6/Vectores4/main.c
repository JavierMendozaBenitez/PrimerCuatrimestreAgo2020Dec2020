#include <stdio.h>
#include <stdlib.h>
//Cuenta la cantidad de veces que un caracter esta en un array
int contarCaracter(char vec[], int tam, char car);
int main()
{
    char letras[6] = {'a', 'a', 'f','f','f', 't', 'w','h'};
    char caracterABuscar = 'f';
    printf("%d\n", contarCaracter(letras, 6, caracterABuscar));

    return 0;
}
int contarCaracter(char vec[], int tam, char car)
{
    int cantidad = 0;
    for(int i=0; i < tam;i++)
    {
        if(vec[i] == car)
        {
            cantidad++;
        }
    }
    return cantidad;
}
