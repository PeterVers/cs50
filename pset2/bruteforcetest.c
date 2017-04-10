#include <stdio.h>
#include <string.h>
#include <cs50.h>

const int CONST_STRING_SIZE = 2;

int main(void)
{
    char arr_char[] = {"abcd"};
    for(int i = 0; i < CONST_STRING_SIZE+1; i++)
    {
        for(int num_chars = 0; num_chars <= i; num_chars++)
        {
            for(int pos = 0; pos < i; pos++)
            {
                if(pos > 0)
                printf("%c", arr_char[num_chars]);
                for(int idx = 0; idx < strlen(arr_char); idx++)
                {
                printf("%c\n", arr_char[idx]);
                }
            } 
        }
    }
    return 0;
}
        

