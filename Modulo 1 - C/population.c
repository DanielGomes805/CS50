#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int populationGrowth(int initialPop, int finalPop)
{
    int counter = 0, currentPop = initialPop, birthRate, deathRate;

    while(currentPop < finalPop)
    {
        birthRate = currentPop/3;
        deathRate = currentPop/4;
        counter++;
        currentPop += (birthRate - deathRate);
    }

    printf("Irá levar %d anos para atingir %d\n", counter, currentPop);
}

int main(void)
{
    setlocale(LC_ALL,"");

    int exit = 0, initialPop, finalPop;

    do
    {
        printf("\n");
        printf("Digite a população inical (>8): ");
        scanf("%d", &initialPop);
        if(initialPop >= 9)
        {
            printf("Digite a população final: ");
            scanf("%d", &finalPop);
            while((finalPop <= initialPop && initialPop > 0))
            {
                printf("Digite a população final: ");
                scanf("%d", &finalPop);
            }
        }
        else
        {
            while(initialPop < 9 && initialPop > 0)
            {
                printf("Digite a população inicial(>8): ");
                scanf("%d", &initialPop);
            }
        }

        if(initialPop < 0 || finalPop < 0)
        {
            exit = 1;
        }
        else
        {
            printf("Inicial: %d\n", initialPop);
            printf("Final: %d\n", finalPop);
            
            populationGrowth(initialPop, finalPop);
        }
        
        initialPop = 0;
        finalPop = 0;
    }
    while(exit == 0);

    printf("FIM DO PROGRAMA\n");

    return 0;
}