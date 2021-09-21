#include <stdio.h>
#include <stdlib.h>

void saludar(void);

void despedir(void);

void queHago(void (*pepe)(void));

int main()
{

    //int x = 14;
    //int numeros[5] = {23, 12, 65, 43, 67};
    //void (*pepe)(void);

    /*int*p;
    int* y;

    p = &x;
    y = numeros;

    printf("%d\n", x);
    printf("%d\n", *p);

    printf("%d\n", numeros[3]);
    printf("%d\n", y[3]);*/

    //pepe = saludar;

    //saludar();
    //pepe();

    //pepe = despedir();
    //pepe();

    queHago(saludar);
    queHago(despedir);

    return 0;
}

void saludar(void)
{
    printf("Hola mundo\n");
}

void despedir(void)
{
    printf("Chau mundo\n");
}

void queHago(void (*pepe)(void))
{
    pepe();
}
