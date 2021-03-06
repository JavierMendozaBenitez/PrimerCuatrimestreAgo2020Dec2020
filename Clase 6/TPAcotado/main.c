#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"
char menu();
int main()
{
    int opcion;
    int respuesta;
    int ingreso1;
    int ingreso2;
    int sumando;
    int restando;
    int multiplicando;
    int factorizando;
    int resolucionSuma;
    int resolucionResta;
    int resolucionMultiplicacion;
    int resolucionFactorial;
    int resolucionFactorial2;
    int flag1;
    int flag2;
    int flag3;
    int contadorOperando1;
    int contadorOperando2;
    int dividiendo;
    float resolucionDivision;

    flag1 = 0;
    flag2 = 0;
    flag3 = 0;
    contadorOperando1 = 0;
    contadorOperando2 = 0;

    do
    {
        system("cls");

        if(contadorOperando1 == 0)
        {
            printf("*** Menu de Opciones ***\n\n1. Ingresar 1er operando (A=x)\n2. Ingresar 2do operando (B=y)\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n\n");
        }
        else
        {
            if(contadorOperando2 == 0)
            {
                printf("*** Menu de Opciones ***\n\n1. Ingresar 1er operando (A=%d)\n2. Ingresar 2do operando (B=y)\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n\n", ingreso1);
            }
            else
            {
                printf("*** Menu de Opciones ***\n\n1. Ingresar 1er operando (A=%d)\n2. Ingresar 2do operando (B=%d)\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n\n", ingreso1, ingreso2);
            }
        }

        respuesta = utn_getNumero(&opcion,"\nQue opcion elige? \n\n","\nError la opcion debe ser desde 1 a 5\n\n",1,5);

        if(!respuesta)
        {
            switch(opcion)
            {
            case 1:
                contadorOperando1++;
                printf("\nIngrese el primer operando\n");
                fflush(stdin);
                scanf("%d", &ingreso1);
                flag1 = 1;
                break;
            case 2:
                if(flag1 == 1)
                {
                    printf("\nIngrese el segundo operando\n");
                    fflush(stdin);
                    scanf("%d", &ingreso2);
                    flag2 = 1;
                    flag1 = 0;
                    contadorOperando2++;
                }
                else
                {
                    printf("\nPrimero debe ingresar el primer operando, reintente.\n\n");
                }
                break;
            case 3:
                if(flag2 == 1)
                {
                    sumando = suma(ingreso1, ingreso2);
                    restando = resta(ingreso1, ingreso2);
                    dividiendo = division(&resolucionDivision, ingreso1, ingreso2);
                    multiplicando = multiplicacion(ingreso1, ingreso2);
                    factorizando = factorial(&resolucionFactorial, ingreso1);
                    flag3 = 1;
                    flag2 = 0;
                    printf("\nLas operaciones se hicieron correctamente.\n\n");
                }
                else
                {
                    printf("\nPara hacer las operaciones es obligatorio ingresar el primero y segundo operando, reintente.\n\n");
                }
                break;
            case 4:
                if(flag3 == 1)
                {
                    printf("\nEl resultado de A+B es: %d\n", sumando);
                    printf("\nEl resultado de A-B es: %d\n", restando);
                    if(dividiendo == 0)
                    {
                        printf("\nEl resultado de A/B es: %.2f\n", resolucionDivision);
                    }
                    else
                    {
                        printf("\nNo es posible dividir por cero.\n");
                    }

                    printf("\nEl resultado de A*B es: %d\n", multiplicando);

                    if(factorizando == 0)
                    {
                        printf("\nEl factorial de A es: %d\n", resolucionFactorial);
                    }
                    else
                    {
                        printf("\nA no se puede factorizar, debe ingresar un numero mayor a 0.\n");
                    }

                    if(ingreso2 > 0)
                    {
                        factorizando = factorial(&resolucionFactorial2, ingreso2);
                        printf("\nEl factorial de B es: %d\n\n", resolucionFactorial2);
                    }
                    else
                    {
                        printf("\nB no se puede factorizar, debe ingresar un numero mayor a 0.\n\n");
                    }

                    contadorOperando1 = 0;
                    contadorOperando2 = 0;
                    flag3 = 0;
                }
                else
                {
                    printf("\nPara ver los resultados primero debe ingresar los dos operandos y realizar las cuentas del punto 3, reintente.\n\n");
                }
                break;
            default:
                break;
            }
            system("pause");
        }
        else
        {
            system("pause");
        }
    }

    while(opcion != 5);

    return 0;
}

char menu()
{
    char opcion;
    system("cls");//Limpia la pantalla

    printf("*** Menu de Opciones ***\n\n");
    printf("a Saludar\n");
    printf("b Brindar\n");
    printf("c Despedir\n");
    printf("d Salir\n\n");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = tolower(opcion);
    //opcion=tolower(getchar()); otra opcion mas acotada que el scanf

    return opcion;
}
