#include <stdio.h>
#include <stdlib.h>
int suma(int res,int operando1, int operando2);
int main()
{
    int num1 = 10;
    int num2 = 2;
    int resultado;
    int div;

    div = suma(resultado, num1, num2);
    if(!div)
    {
       printf("El resultado es: %d\n",resultado);
    }
    printf("El resultado es: %d\n",resultado);
    return 0;
}
int suma(int res,int operando1, int operando2)
{
    //int resultadoSuma;

    res = operando1 + operando2;

    return res;
}
