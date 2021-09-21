#include <stdio.h>
#include <stdlib.h>

void duplicar(int x);

int main()
{
    int x = 20;

    duplicar(x);

    printf("X vale %d\n", x);
    return 0;
}

void duplicar(int x)
{
    x = x * 2;
    printf("X vale %d\n", x);
}
