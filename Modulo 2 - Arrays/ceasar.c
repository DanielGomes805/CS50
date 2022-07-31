#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 300
// CÓDIGO INCOMPLETO!!!!
/*
    O PROGRAMA TEM COMO OBJETIVO RECEBER UMA MENSAGEM COM ENTRADA E RETORNAR UMA MENSAGEM CRIPTOGRAFADA COMO SAÍDA
*/

// c i = (p i + k)% 26

int ceasar(int key, char plaintext[])
{
    int tam = strlen(plaintext), counter = 0, diferenca;
    char ciphertext[tam];
    int aux[tam];

    for(int i = 0; i < tam; i++)
    {

        if(plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            aux[i] = plaintext[i];
            ciphertext[i] = aux[i]+(key%26);

            while(ciphertext[i] > 122) //TABELA ASCII - 122 = 'z' 
            {
                diferenca = ciphertext[i]-122;
                ciphertext[i] = 'a'-1+diferenca;
            }
        }
        else if(plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            aux[i] = plaintext[i];
            ciphertext[i] = aux[i]+(key%26);
            
            while(ciphertext[i] > 90) //TABELA ASCII - 90 = 'Z' 
            {
                diferenca = ciphertext[i]-90;
                ciphertext[i] = 'a'-1+diferenca;
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    
    printf("plaintext: %s\n\n", plaintext);
    //printf("ciphertext: %s\n", ciphertext);
    for(int i = 0; i < tam; i++)
    {
        //printf("%c", ciphertext[i]);
        printf("%c: %d /=/ %c: %d\n", plaintext[i], plaintext[i], ciphertext[i], ciphertext[i]);
    }
    printf("\n");
}

int main(void)
{
    system("cls");
    int key;
    char plaintext[N];

    printf("\nPlaintext: ");
    scanf(" %[^\n]s", plaintext);
    printf("\nChave: ");
    scanf("%d", &key);

    ceasar(key, plaintext);
    return 0;
}