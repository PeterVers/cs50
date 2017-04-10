#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

const int CONST_WORD_SIZE = 128;
const int CONST_MAX_PASSWD_SIZE = 4;
clock_t begin;


bool try_passwd(const char *plain, const char *cipher, const char *salt)
{
    if(!strcmp(crypt(plain, salt), cipher))
    {
        clock_t end = clock();
        double elapsed_time = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Hack completed. Password successfully cracked. Matching password - %s\n", plain);
        printf("Program executed in %f seconds.\n", elapsed_time);
        
        return true;
    }
    
    return false;
}

bool dict_attack(const char *passwd, const char *salt)
{
    char cur_word[CONST_WORD_SIZE];
    FILE *f;
    
    f = fopen("/usr/share/dict/words", "r");
    
    if(!f)
    {
        printf("Error opening dictionary file.\n");
        return false;
    }
    
    while (fgets(cur_word, CONST_WORD_SIZE, f))
    {
        cur_word[strlen(cur_word) - 1] = '\0';
        
        if(try_passwd(cur_word, passwd, salt))
            return true; 
            
    }
    
    return false;
}

bool brute_attack(char *passwd, char *salt)
{
    char arr_chars[] = {"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ/."}; 
    int arr_length = strlen(arr_chars);
    char cur_word[CONST_MAX_PASSWD_SIZE+1];
    int pos[CONST_MAX_PASSWD_SIZE];
    cur_word[CONST_MAX_PASSWD_SIZE] = '\0';
    
    for(int max_chars = 0; max_chars < CONST_MAX_PASSWD_SIZE; max_chars++)
    {
        printf("Trying length %d\n", max_chars + 1);
        bool loop_completed = false;
        int idx;
        for(idx = 0; idx < max_chars; idx++)
        {
            pos[idx] = 0;
            cur_word[idx] = arr_chars[pos[idx]];
        }
        
        cur_word[idx] = '\0';
        
        while(!loop_completed)
        {
            if(try_passwd(cur_word, passwd, salt))
                return true;
                
            bool shift = true;
            
            for(int cur_char = 0; cur_char <= max_chars; cur_char++)
                if(shift)
                {
                    if(pos[cur_char] == arr_length - 1)
                    {
                        if(cur_char == max_chars)
                            loop_completed = true;
                        else
                        {
                            pos[cur_char] = 0;
                            cur_word[cur_char] = arr_chars[pos[cur_char]];
                        }
                    }
                    else
                    {
                        cur_word[cur_char] = arr_chars[++pos[cur_char]];
                        shift = false;
                    }
                }
        }
    }
    
    return false;
}                                              
                
    
int main( int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Error: Incorrect number of parameters.\n");
        return 1;
    }
    
    begin = clock();
    char salt[2]; 
    strncpy(salt, argv[1], 2);
    printf("Using dictionary attack...\n");
    
    if(dict_attack(argv[1], salt))
        return 0;
        
    printf("Dictionary attack failed. Trying brute-force...\n");
    
    if(brute_attack(argv[1], salt))
        return 0;
        
    printf("Encrypted key could not be deciphered. You're a shitty hacker.\n");
    
    return 0;  
}
    
    
    

