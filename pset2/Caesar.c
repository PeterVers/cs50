#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int key = atoi(argv[1]);
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
             pt[i] = pt[i]+key;
             if(pt[i] >= 65 && pt[i] <= 90)
                printf("%c", pt[i]);
        }
        if(pt[i] > 90)
        {
            pt[i] = (pt[i] - 90)+64;
            printf("%c", pt[i]);
        }
        }
        if(pt[i] >= 97 && pt[i] <= 122) {
        {
            pt[i] = pt[i]+key;
            if(pt[i] >= 97 && pt[i] <= 122)
                printf("%c", pt[i]);
        }
        if(pt[i] > 122)
        {
            pt[i] = (pt[i] - 122) + 96;
            printf("%c", pt[i]);
        }
        }
    }
    printf("\n");
    return 0;
}
