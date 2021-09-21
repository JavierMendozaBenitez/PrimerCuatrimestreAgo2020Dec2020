/*1)De 5  personas que ingresan al hospital se deben tomar y
validar los siguientes datos.
inicialNombre , temperatura, sexo y edad.Temperatura de 34 a 45, edad de 20 a 65
a)informar la cantidad de personas de cada sexo.
b)la edad promedio en total
c)la inicial de la mujer con más temperatura(si la hay)*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char sexo;
    char inicialMaxTemp;
    char inicial;
    int edad;
    int contadorM = 0;
    int contadorF = 0;
    int acumEdad = 0;
    int contador = 0;
    int flagMaxTemp = 0;
    float temperatura;
    float maxTemp;
    float promEdad;

    for(int i=0; i < 5; i++)
    {
        printf("Ingrese edad: ");
        scanf("%d", &edad);
        while(edad < 20 || edad > 65)
        {
            printf("Edad invalida. Reingrese edad: ");
            scanf("%d", &edad);
        }

        printf("Ingrese temperatura: ");
        scanf("%f", &temperatura);
        while(!(temperatura >=34 && temperatura <=45))
        {
            printf("Reingrese temperatura: ");
            scanf("%f", &temperatura);
        }

        printf("Ingrese inicial: ");
        fflush(stdin);
        scanf("%c", &inicial);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexo);
        sexo = tolower(sexo);
        while(sexo!= 'f' && sexo != 'm')
        {
            printf("Reingrese sexo: ");
            fflush(stdin);
            scanf("%c", &sexo);
            sexo = tolower(sexo);
        }

        switch(sexo)
        {
        case 'f':
            contadorF++;
            if(flagMaxTemp == 0)
            {
                maxTemp = temperatura;
                inicialMaxTemp = inicial;
                flagMaxTemp = 1;
            }
            else
            {
                if(temperatura > maxTemp)
                {
                    maxTemp = temperatura;
                    inicialMaxTemp = inicial;
                }
            }
            break;
        case 'm':
            contadorM++;
            break;
        default:
            break;
        }

        acumEdad = acumEdad + edad;
        contador++;
    }

    promEdad= (float) acumEdad/contador;

    printf("La cantidad de mujeres es: %d\n", contadorF);
    printf("La cantidad de hombres es: %d\n", contadorM);
    printf("El promedio de edades es: %.2f\n", promEdad);

    if(contadorF != 0)
    {
        printf("La inicial de la mujer con más temperatura es: %c\n", inicialMaxTemp);
        fflush(stdin);
    }

    return 0;
}
