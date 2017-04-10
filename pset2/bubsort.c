#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void bub_sort(int arr_num[], int arr_size)
{
    int num_swap;
    int swap_counter = -1;
    while(swap_counter != 0)
    {
       swap_counter = 0;
       for(int i = 0; i < arr_size; i++)
       {
            if(i <= arr_size - 2 && arr_num[i] > arr_num[i+1])
            {
                num_swap = arr_num[i+1];
                arr_num[i+1] = arr_num[i];
                arr_num[i] = num_swap;
                swap_counter++;
            }
        }
        arr_size--;
    }
    arr_size = 5;
    for(int i = 0; i < arr_size; i++)
    {
        printf("%i\n", arr_num[i]);
    }
}

int main(void)
{
    int num_array[5] = {9, 10, 8, 6, 7};
    int arr_size = 5;
    bub_sort(num_array, arr_size);
    return 0;
}
