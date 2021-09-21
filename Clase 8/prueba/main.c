#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);//variable tipo puntero

int main()
{
    int x = 5;
    int y = 10;

    printf("x:%d y:%d\n\n", x, y);

    swap(&x, &y);

    printf("x:%d y:%d\n\n", x, y);

    return 0;
}

void swap(int* a, int* b)
{
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}
