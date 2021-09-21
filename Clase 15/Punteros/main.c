#include <stdio.h>
#include <stdlib.h>

void duplicarVariable(int* pVariable);

int main()
{
    int x = 20;

    //x = x*2;

    //*p = *p * 2;

    duplicarVariable(&x);
    printf("X vale: %d\n\n",x); // nombre de fantasia
    //printf("X vale: %d\n\n",*p);// un puntero que apunta a x
    //printf("X vale: %p\n\n",*(&x));//*/

    return 0;
}

void duplicarVariable(int* pVariable)
{
    *pVariable = *pVariable * 2;
}
