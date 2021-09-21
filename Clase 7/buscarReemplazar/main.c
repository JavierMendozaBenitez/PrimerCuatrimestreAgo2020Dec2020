#include <stdio.h>
#include <stdlib.h>
/** \brief recorre un array de caracteres buscando todas
           las ocurrencias de un caracter y las
           reemplaza por otro caracter
 *
 * \param vec[] char array sobre el cual se realiza la busqueda
 * \param tam int tamaño del array
 * \param a char caracter que se busca
 * \param b char caracter que reemplaza
 * \return int cantidad de caracteres reemplazados
 *
 */
int buscarReemplazar(char vec[], int tam, char a, char b);
void mostrarVectorCaracteres(char vec[], int tam);
int main()
{
    char letras[] = {'a', 'a', 'f', 't', 'w','h', 'a', 'f', 'd',  'e'};
    int ocurrencias;
    //ocurrencias = buscarReemplazar(letras, 10, 'a', 'x'); Harcodeo
    char caracterABuscar = 'a';
    char caracterReemplazo = 'x';
    mostrarVectorCaracteres(letras, 10);
    ocurrencias = buscarReemplazar(letras, 10, caracterABuscar, caracterReemplazo);
    mostrarVectorCaracteres(letras, 10);
    printf("Cantidad de elementos reemplazados: %d\n", ocurrencias);
    return 0;
}
int buscarReemplazar(char vec[], int tam, char a, char b)
{
    int cantidad = 0;
    for(int i=0; i < tam; i++)
    {
        if(vec[i] == a)
        {
            vec[i] = b;
            cantidad++;
        }
    }
    return cantidad;
}

void mostrarVectorCaracteres(char vec[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        printf("%c ", vec[i]);
    }
    printf("\n\n");
}
