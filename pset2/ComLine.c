#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    printf("Please enter a name: \n");
    string s = GetString();
    if (s != NULL)
    {
        if(s[0] >= 65 && s[0] <= 122)
        {
            printf("%c", toupper(s[0]));
        }
        for ( int i = 0; i < strlen(s); i++)
        {
            if (s[i] == 32)
                {
                    while(s[i] == 32)
                    {
                        i++;
                    }
                    printf("%c", toupper(s[i]));
                }
        }
        printf("\n");
   }
return 0;
}
