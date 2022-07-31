#include <ctype.h>
#include <stdio.h>
#include <string.h>
                        /*Simples Jogo de Scrabble*/

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int compute_score(char word[])
{
    int sum = 0;

    for(int i = 0; i < strlen(word); i++)
    {
        if(word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] -= 32;
        }
    }   

    for(int i = 0; i < strlen(word); i++)
    {
        if(word[i] >= 'A' && word[i] <= 'Z')
        {
            for(int j = 0; j < strlen(alphabet); j++)
            {
                if(word[i] == alphabet[j])
                {
                    sum += POINTS[j];
                }
            }   
        }
    }

    return sum;
}

int main(void)
{
    system("cls");
    // Get input words from both players
    char word1[100], word2[100];
    printf("Digite a palavra 1: ");
    scanf(" %[^\n]", word1);

    printf("\nDigite a palavra 2: ");
    scanf(" %[^\n]", word2);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    printf("\nPlayer 1 score: %d\n", score1);
    printf("Player 2 score: %d\n", score2);

    // TODO: Print the winner
    if(score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if(score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}