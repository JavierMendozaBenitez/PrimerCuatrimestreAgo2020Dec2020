#include <stdio.h>
#include <stdlib.h>

/*struct Persona
{
    int id;
    char nombre[20];
    int edad;
};*/

typedef struct
{
    int id;
    char nombre[20];
    int edad;
}ePersona;

typedef int (*operacion)(int, int);

int sumar(int, int);
int restar(int, int);
int multiplicar(int, int);

//void mostrarPersona(struct Persona p);
void mostrarPersona(ePersona p);

//int calcular(int num1, int num2, int (*operacion)(int, int));
int calcular(int num1, int num2, operacion op);


int main()
{
    int resultado;

   // struct Persona per1;
    ePersona per1;

    resultado = calcular(3, 4, multiplicar);

    printf("El resutado es: %d\n", resultado);
    return 0;
}

int sumar(int a, int b)
{
    return a+b;
}

int restar(int a, int b)
{
    return a-b;
}

int multiplicar(int a, int b)
{
    return a*b;
}

/*int calcular(int num1, int num2, int (*operacion)(int, int))
{
    return operacion(num1, num2);
}*/

int calcular(int num1, int num2, operacion op)
{
    return op(num1, num2);
}

