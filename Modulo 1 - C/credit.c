#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

//VALIDADOR DE CARTÃO DE CREDITO/DÉBITO.

int bannerChecker(long long cardNumber)
{
    long long currentNumber =  cardNumber, divider = 10;
    int counter = 0;

    while(currentNumber > 0)
    {
        currentNumber /= 10;
        counter++;
    }

    for(int i = 0; i < counter-2; i++)
    {
        divider *= 10;
    }

    currentNumber = cardNumber;
    int firstDigit = currentNumber/divider;
    int twoFirstDigits = currentNumber/ (divider/10);

    if(firstDigit == 4 && (counter == 13 || counter == 16))
    {
        printf("VISA\n");
    }
    else if((twoFirstDigits == 34 || twoFirstDigits == 37) && (counter == 15))
    {
        printf("AMERICAN EXPRESS\n");
    }
    else if((twoFirstDigits > 50 && twoFirstDigits < 56) && (counter == 16))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("Cartão Não Suportado!\n");
    }
}

int cardCheck(long long cardNumber)
{
    long long currentNumber = cardNumber;
    int sum1 = 0, sum2 = 0, totalSum;

    while(currentNumber > 0)
    {
        int lastDigit = currentNumber%10;
        sum1 += lastDigit;
        currentNumber /= 100;
    }

    currentNumber = cardNumber/10;
    while(currentNumber > 0)
    {
        int lastDigit = currentNumber%10;
        int mult = (lastDigit*2);
        sum2 += (mult%10) + (mult/10);
        currentNumber /= 100;
    }

    totalSum = sum1+sum2;
    currentNumber = cardNumber;

    if(((totalSum%10) == 0) && currentNumber != 0){
        printf("SUCESSO!!\n");
        bannerChecker(currentNumber);
    }
    else if(currentNumber == 0)
    {
        printf("FIM DO PROGRAMA!!!\n");
    }
    else
    {
        printf("Cartão Inválido!\n");
    }
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    
    long long cardNumber;
    
    do
    {
        printf("Digite o numero do cartão: ");
        scanf("%lld", &cardNumber);
        cardCheck(cardNumber);
    }
    while(cardNumber != 0);

    return 0;
}
