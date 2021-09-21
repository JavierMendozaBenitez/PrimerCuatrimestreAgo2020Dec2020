#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numero1;
	int numero2;
	int resultado;

	printf("Ingrese número 1: ");
	fflush(stdin);
	scanf("%d", &numero1);

	printf("Ingrese número 2: ");
	fflush(stdin);
	scanf("%d", &numero2);

	resultado = numero1 + numero2;

	printf("Suma:%d", resultado);

	return 0;
}

