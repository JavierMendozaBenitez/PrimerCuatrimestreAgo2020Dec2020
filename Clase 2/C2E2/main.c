#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numero1;
	int numero2;
	float resultado;

	printf("Ingrese número 1: ");
	fflush(stdin);
	scanf("%d", &numero1);

	printf("Ingrese número 2: ");
	fflush(stdin);
	scanf("%d", &numero2);

	resultado = (float)(numero1 + numero2)/2;

	printf("Promedio:%.2f\n", resultado);

	return 0;
}
