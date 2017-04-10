#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

const int CONST_ALPHABET_SIZE = 26;
const int CONST_LOWER_OFFSET = 'a';
const int CONST_UPPER_OFFSET = 'A';

void encode_string(char *str, int k)
{
    for(int i = 0; i < strlen(str); i++)
    {
        if(islower(str[i]))
            str[i] = CONST_LOWER_OFFSET + (str[i] - CONST_LOWER_OFFSET + k) % CONST_ALPHABET_SIZE;
        else if(isupper(str[i]))
            str[i] = CONST_UPPER_OFFSET + (str[i] - CONST_UPPER_OFFSET + k) % CONST_ALPHABET_SIZE;
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Incorrect number of command-line arguments specified.\n");
        
        return 1;
    }
    
    int k = atoi(argv[1]);
    char *str = GetString();
    encode_string(str, k);
    printf("%s\n", str);
    free(str);
    
    return 0;
    
}
    
            
