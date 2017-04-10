#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int key = atoi(argv[1]), c;
    char upperalphaidx[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char loweralphaidx[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    printf("Please enter a string.\n");
    string pt = GetString();
    printf("plaintext: %s\n", pt);
    printf("ciphertext: ");
    for(int i = 0; i < strlen(pt); i++)
    {
        if((pt[i] < 65 || pt[i] > 90) && (pt[i] < 97 || pt[i] > 122))
        {
            printf("%c", pt[i]);
        }
        else if(pt[i] >= 65 && pt[i] <= 90) {
        {
             for(int j = 0; j < 26; j++)
             {
                if(upperalphaidx[j] == pt[i])
                {
                    c =(j+key) % 26;
                    printf("%c", upperalphaidx[c]);
                }
             }
        }
        }
        if(pt[i] >= 97 && pt[i] <= 122) {
        {
            for(int j = 0; j < 26; j++)
             {
                if(loweralphaidx[j] == pt[i])
                {
                    c =(j+key) % 26;
                    printf("%c", loweralphaidx[c]);
                }
        }
    }
    }
    }
    printf("\n");
    return 0;
}
