#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int lin_search(int *arr_num[], int *target_num)
{
    for(int i = 0; i < strlen(arr_num); i++)
    {
        if(arr_num[i] == target_num)
            return arr_num[i];
        return 0;
    }
}

int main(void)
{
    int num_string[];
    int cur_num;
    printf("Please enter a string of 5 numbers.\n");
    
    for(int i = 0; i <= 5; i++)
    {
        scanf("%i", &cur_num);
        num_string[i] = cur_num;
    }
    
    for(int i = 0; i <= 5; i++)
    {
        printf("%i\n", num_string[i]);
    }
}
    
        
