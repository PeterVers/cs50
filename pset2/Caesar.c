#include <stdio.h>
#include <string.h>
#include <ctype.h>

//This is a cipher program that takes a string, then encodes using it a simple Caesar cipher.
int main(int argc, char* argv[])
{
    int key = atoi(argv[1]);
    printf("Please enter a string.\n");
    char pt[256];
    gets(pt);
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
