#include <stdio.h>
#include <stdlib.h>

// factorial(int numero);
int factorialRecursivo(int numero);
int main()
{
    int numero;
    int f;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    f = factorialRecursivo(numero);

    printf("El factorial es %d\n", f);

    return 0;
}

/*int factorial(int numero)
{
    int fact = 1;

   // for(int i = numero; i > 0; i--)

    for ( int i = 1; i <= numero; i++)
    {
        fact = fact * i;
        //fact *= i;
    }


    return fact;
}
*/
int factorialRecursivo(int n)
{
    int fact;

    if( n == 1)
    {
        fact = 1;
    }
    else
    {
        fact = n * factorialRecursivo(n-1);
    }

    return fact;
}

/*int x;
    int a;
    int b;

    printf("Ingrese un numero: ");
    x = scanf("%d", &a);
    printf("a vale %d\n", a);
    printf("scanf devolvio el numero %d\n", x);*/
    /* int x;
    char nombre[20] = "Juan";
    x = printf("%s\n", nombre);
    printf("%d", x);*/
