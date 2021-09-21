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
int sumar(int a, int b);

int main()
{
    int num1;
    int num2;
    int resultado;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);

    printf("Ingrese un numero: ");
    scanf("%d", &num2);

    resultado = sumar(num1, num2);

    printf("La suma es %d\n", resultado);

    return 0;
}


int sumar(int a, int b)
{
    int rdo;

    rdo = a + b;

    return rdo;
}
