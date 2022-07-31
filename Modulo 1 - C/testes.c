#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    float troco;
    printf("Digite o valor do troco: ");
    scanf("%f", &troco);
    
    printf("%.2f", (troco-0.25));
    return 0;
}