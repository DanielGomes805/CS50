#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int bannerChecker(long long cardNumber)
{
    long long currentNumber, diviser = 10;
    int counter = 0;
    
    currentNumber = cardNumber;
    while(currentNumber > 0)
    {
        counter++;
        currentNumber /= 10;
    }

    for(int i = 0; i < counter-2; i++)
    {
        diviser *= 10;
    }

    currentNumber = cardNumber;
    int firstDigit = currentNumber/diviser;
    int firstTwoDigits = currentNumber/(diviser/10);

    if(firstDigit == 4 && (counter == 13 || counter == 16))
    {
        printf("VISA\n");
    }
    else if((firstTwoDigits == 34 || firstTwoDigits == 37) && (counter == 15))
    {
        printf("AMERICAN EXPRESS\n");
    }
    else if((firstTwoDigits > 50 && firstTwoDigits < 56) && (counter == 16))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("Cartão Ainda Não Suportado!\n");
    }
}

int  cardChecker(long long cardNumber)
{
    long long currentNumber;
    int sum1 = 0, sum2 = 0, totalSum;
    currentNumber = cardNumber;
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
        int mult = lastDigit*2;
        sum2 += (mult%10) + (mult/10);
        currentNumber /= 100;
    }

    totalSum = sum1 + sum2;

    currentNumber = cardNumber;
    if((totalSum%10 == 0) && cardNumber != 0)
    {
        printf("Sucesso!\n");
        bannerChecker(currentNumber);
    }
    else if(cardNumber == 0)
    {
        printf("FIM DO PROGRAMA\n");
    }
    else
    {
        printf("Cartão Inválido");
    }
}

int main(void)
{
    setlocale(LC_ALL,"");
    long long cardNumber;

    //VISA: 4929168466576126
    //MASTERCARD: 5430479207926820
    //AMERICAN EXPRESS: 345577905961729

    do
    {
        printf("Digite o número do seu cartão: ");
        scanf("%lld", &cardNumber);
        cardChecker(cardNumber);
    }
    while(cardNumber != 0);
    return 0;
}