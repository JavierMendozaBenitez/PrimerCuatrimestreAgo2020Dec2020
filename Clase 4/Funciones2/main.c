#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

// prototipo

/** \brief devuelve la suma de los parametros
 *
 * \param a int  primer valor a sumar
 * \param b int  segundo valor asumar
 * \return int   la suma de los parametros
 *
 */
int sumar();

int main()
{
    printf("La suma es %d\n", sumar());
    return 0;
}


int sumar()
{
    int x;
    int y;

    printf("Ingrese un numero: ");
    scanf("%d", &x);

    printf("Ingrese otro numero: ");
    scanf("%d", &y);

    return x + y;
}


/*
void saludar();

int main()
{
    saludar();
    return 0;
}

void saludar()
{
    printf("Hell world!\n");
}*/
