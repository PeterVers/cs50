#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Error: Please enter an argument.\n");
        return 1;
    }
    string key = argv[1];
    for(int x = 0; x < strlen(key); x++)
    {
        if((key[x] < 65 || key[x] > 90) && (key[x] < 97 || key[x] > 122))
        {
            printf("Error: Please enter an alphabetical keyword.\n");
            return 1;
        }
    }
    int c;
    char upperalphaidx[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char loweralphaidx[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    printf("Please enter a string.\n");
    string pt = GetString();
    printf("plaintext: %s\n", pt);
    printf("ciphertext: ");
    for(int i = 0, k = 0; i < strlen(pt); i++)
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
                        if(k == strlen(key))
                        {
                            k = 0;
                        }
                        if((key[k] >= 65 && key[k] <= 90) || (key[k] >= 97 && key[k] <= 122))
                        {
                            for(int l = 0; l < 26; l++)
                            {
                                if(upperalphaidx[l] == key[k])
                                {
                                    c =(j+l) % 26;
                                    
                                }
                                else if(loweralphaidx[l] == key[k])
                                {
                                    c =(j+l) % 26;
                                    
                                }
                            }
                        }
                    printf("%c", upperalphaidx[c]);     
                }
             }
         k++;
        }
        }
        if(pt[i] >= 97 && pt[i] <= 122) {
        {
            for(int j = 0; j < 26; j++)
             {
                if(loweralphaidx[j] == pt[i])
                {  
                    if(k == strlen(key))
                    {
                        k = 0;
                    }
                    if((key[k] >= 65 && key[k] >= 90)|| (key[k] >= 97 && key[k] <= 122))
                    {
                        for(int l = 0; l < 26; l++)
                        {
                            if(loweralphaidx[l] == key[k])
                            {
                                c =(j+l) % 26;
                            }
                            else if(upperalphaidx[l] == key[k])
                            {
                                c =(j+l) % 26;
                            }
                        }
                    }
                    printf("%c", loweralphaidx[c]);
                }
        }
        k++;
    }
    }
    }
    printf("\n");
    return 0;
}
