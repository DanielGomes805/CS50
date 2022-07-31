#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int counterWithoutSpaces(char array[])
{
    int counter = 0;
    
    for(int i = 0; i < strlen(array); i++)
    {
        if((array[i] >= 'a' && array[i] <= 'z') || array[i] >= 'A' && array[i] <= 'Z')
        {
            counter++;
        }
    }
    
    return counter;
}

int wordCounter(char array[])
{
    int counter = 0;
    
    for(int i = 0; i < strlen(array); i++)
    {
        if(array[i] == ' ' || array[i+1] == '\0')
        {
            counter++;
        }
    }
    
    return counter;
}

int sentenceCounter(char array[])
{
    int counter = 0;

    for(int i = 0; i < strlen(array); i++)
    {
        if(array[i] == '.' || array[i] == '!' || array[i] == '?')
        {
            counter++;
        }
    }

    return counter;
}

int readability(char array[])
{
    int letters, words, sentences;
    float L, S;

    letters = counterWithoutSpaces(array);
    words = wordCounter(array);
    sentences = sentenceCounter(array);

    L = (letters/ (float) words) * 100;
    S = (sentences/ (float) words) * 100;
    printf("L: %.2f\n", L);
    printf("S: %.2f\n", S);

    float index  = 0.0588 * L - 0.296 * S - 15.8;
    printf("index: %.2f\n", index);
    return round(index);
}

int main(void)
{
    system("cls");
    char array[300];
    int exit = 1;

    do
    {
        printf("\nDigite a frase: ");
        scanf(" %[^\n]s", array);
        
        if(strcmp(array, "exit") != 0)
        {
            int grade = readability(array);

            printf("Letras: %d\n", counterWithoutSpaces(array));
            printf("Palavras: %d\n", wordCounter(array));
            printf("Frases: %d\n", sentenceCounter(array));

            if(grade < 1)
            {
                printf("Before Grade 1\n");
            }
            else if(grade >= 16)
            {
                printf("Grade 16+\n");
            }
            else
            {
                printf("Grade %d\n", grade);
            }
        }
        else
        {
            printf("Programa Encerrado!\n");
            exit = 0;
        }

        
    }
    while(exit != 0);
 
    return 0;
}