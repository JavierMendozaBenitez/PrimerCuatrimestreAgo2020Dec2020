#include <stdio.h>
#include <stdlib.h>

void sumar(int x, int y);

int main()
{
    int x;
    int y;

    printf("Ingrese un numero: ");
    scanf("%d", &x);

    printf("Ingrese otro numero: ");
    scanf("%d", &y);

    sumar(x, y);

    return 0;
}

void sumar(int x, int y)
{
    int rta = x + y;
    printf("La suma es %d\n", rta);
}
