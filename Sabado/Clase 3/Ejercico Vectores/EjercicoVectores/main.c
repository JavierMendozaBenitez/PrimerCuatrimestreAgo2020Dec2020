#include <stdio.h>
#include <stdlib.h>
/*
1- realizar el pedido de 10 números entre -100 y 100 al usuario y guardarlos en un vector, luego de ese vector obtén
a- la suma de los números pares
b- que se muestren los números impares
c- la cantidad de ceros*/
int main()
{
    float num;
    int ent;
    /*int numeros[]
    printf("Hello world!\n");*/
    printf("Ingrese numero: ");
    fflush(stdin);
    scanf("%f", &num);
    ent = num;
    if(num - ent != 0)
    {
        printf("\nEs un decimal\n");
    }
    else
    {
        printf("\nEs un entero\n");
    }


    return 0;
}
