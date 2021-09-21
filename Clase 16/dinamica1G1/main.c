#include <stdio.h>
#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>

int main()
{
    //int num;

    int* pNum = NULL;

    pNum = (int*)malloc(sizeof(int));
    if(pNum == NULL)
    {
        printf("Problema para conseguir memoria\n");
        exit(EXIT_FAILURE);
    }

    //num = 20;

    //*pNum = 20;

    //printf("Ingrese un numero para la memoria estatica: ");
    //scanf("%d", &num);

    printf("Ingrese un numero para la memoria dinamica: ");
    scanf("%d", pNum);


    //printf("num vale %d\n", num);
    printf("pNum vale %d\n", *pNum);

    /*printf("Ingrese un numero: ");
    scanf("%d", &num);*/

    free(pNum);//Libreas la memoria que no usas
    return 0;
}
