#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void sect_sort(int arr_num[], int arr_size)
{
    int low_num;
    int swap;
    
    for(int i = 0; i < arr_size; i++)
    {
        low_num = arr_num[i];
        
        for(int j = i; j < arr_size; j++)
        {
            if(arr_num[j] < low_num)
            {
                low_num = arr_num[j];
                swap = j;
            }
        }
        
        if(low_num < arr_num[i])
        {
            arr_num[swap] = arr_num[i];
            arr_num[i] = low_num;
        }
    }
    
    for(int i = 0; i < arr_size; i++)
    {
        printf("%i\n", arr_num[i]);
    }
}

int main(int argc, string argv[])
{
    int num_array[5] = {9, 10, 8, 7, 7};
    int arr_size = 5;
    sect_sort(num_array, arr_size);
    return 0;
}
    
