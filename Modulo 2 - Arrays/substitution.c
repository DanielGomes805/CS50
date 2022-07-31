#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 200

int verifyKey(char key[])
{

    char auxiliar[26];
    /* printf("Key in verifyKey: %s\n", key);
    printf("Key Length: %d\n", strlen(key)); */
    
    if(strlen(key) == 0)
    {
        printf("ERROR! Key is empty!!");
        return 1;
    }
    else if(strlen(key) != 26)
    {
        printf("ERROR! INVALID KEY! Key must contain 26 characters\n");
        return 1;
    }
    
    strcpy(auxiliar, key);

    for(int i = 0; i < strlen(key); i++)
    {
        if(!(key[i] >= 'a' && key[i] <= 'z' || key[i] >= 'A' && key[i] <= 'Z'))
        {
            printf("ERROR! INVALID KEY! Only Letters are Allowed!\n");
            return 1;
        }

        for(int j = 0; j < strlen(auxiliar); j++)
        {
            if(i != j)
            {
                if(auxiliar[j] == key[i])
                {
                    printf("ERROR! INVALID KEY! Repeated letters are not allowed!\n");
                    return 1;
                }
            }
        }
    }

    printf("OK!\n");

    return 0;
}

//YTNSHKVEFXRBAUQZCLWDMIPGJO
//ABCDEFGHIJKLMNOPQRSTUVWXYZ

int substitution(char message[], char key[])
{   
    char A_Z[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char a_z[] = "abcdefghijklmnopqrstuvwxyz";
    char newMessage[200];

    for(int i = 0; i < strlen(key); i++)
    {
        if(key[i] >= 'a' && key[i] <= 'z')
        {
            key[i] -= 32;
        }
    }

    
    for(int i = 0; i < strlen(message); i++)
    {
        //JTREKYAVOGDXPSNCUIZLFBMWHQ
        //ABCDEFGHIJKLMNOPQRSTUVWXYZ
        //jtREKYaVOGdXPsNCuiZLFBmWHq
        //HELLO
        //VKXXN
        for(int j = 0; j < strlen(key); j++)
        {
            if(message[i] == a_z[j])
            {
                message[i] = key[j] + 32;
                //printf("%c", message[i]);
                break;
            }
            
            if(message[i] == A_Z[j])
            {
                message[i] = key[j];
                //printf("%c", message[i]);
                break;
            }
        }
        printf("%c", message[i]);
    }
}

int main(void)
{
    system("cls");
    char message[200];
    char key[26], keyAux[26];
    
    printf("Enter your key: ");
    scanf(" %[^\n]s", key);
    strcpy(keyAux, key);
    
    printf("Enter your message: ");
    scanf(" %[^\n]s", message);
    printf("message: %s\n", message);
    
    //JTREKYAVOGDXPSNCUIZLFBMWHQ

    int answer = verifyKey(keyAux);
    if(answer != 0)
    {
        return 1;
    }
    substitution(message, keyAux);

    return 0;
}