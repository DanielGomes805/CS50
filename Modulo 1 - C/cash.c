#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void cash(float troco)
{
    int counter = 0;
    float novoTroco = troco;

    while(novoTroco > 0.00)
    {
        if(novoTroco >= 0.25)
        {
            counter++;
            novoTroco -= 0.25;
            printf("Você recebeu R$ 0.25. Falta: R$ %.2f\n", novoTroco);
            printf("Foram necessarias %d moedas.\n", counter);
        }
        if(novoTroco >= 0.10 && novoTroco < 0.25)
        {
            counter++;
            novoTroco -= 0.10;
            printf("Você recebeu R$ 0.10. Falta: R$ %.2f\n", novoTroco);
            printf("Foram necessarias %d moedas.\n", counter);
        }
        if(novoTroco >= 0.05 && novoTroco < 0.10)
        {
            counter++;
            novoTroco -= 0.05;
            printf("Você recebeu R$ 0.05. Falta: R$ %.2f\n", novoTroco);
            printf("Foram necessarias %d moedas.\n", counter);
        }
        if(novoTroco >= 0.01 && novoTroco < 0.05)
        {
            counter++;
            novoTroco -= 0.01;
            printf("Você recebeu R$ 0.01. Falta: R$ %.2f\n", novoTroco);
            printf("Foram necessarias %d moedas.\n", counter);
        }
    }
    
    printf("Foram necessarias %d moedas.\n", counter);
}

int main(void)
{
    float troco;
    printf("Digite o valor do troco: ");
    scanf("%f", &troco);
    cash(troco);
    return 0;
}