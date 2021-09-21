#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int* vec = (int*) calloc(5,sizeof(int)*5);//inicializa en 0
    float* vec = (float*) calloc(5,sizeof(float)*5);//inicializa en 0

    for(int i=0; i<5; i++)
    {
        printf("%.2f ", *(vec+i));
    }
    return 0;
}
