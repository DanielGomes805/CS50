#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mario(int tam)
{
    int i, j, k;
    for(i = 0; i <= tam; i++)
    {
        for(k = tam-i; k >= 1; k--)
        {
            printf(" ");
        }
        for(j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int main(void)
{
    mario(8);
    return 0;
}