#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

const int CONST_MAX_NUM_ELEM = 1000;
clock_t begin;

void bub_sort(int arr_num[], int arr_size)
{
    begin = clock();
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
    clock_t end = clock();
    double elapsed_time = (double)(end - begin) / CLOCKS_PER_SEC;
    for(int i = 0; i < arr_size; i++)
    {
        printf("%i\n", arr_num[i]);
    }
    printf("Program executed in %f seconds.\n", elapsed_time);
    return;
}

void lin_search(int arr_num[], int target_num, int arr_size)
{
    begin = clock();
    for(int i = 0; i < arr_size; i++)
    {
        if(arr_num[i] == target_num)
        {
            clock_t end = clock();
            double elapsed_time = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("Target number found: %i\n", arr_num[i]);
            printf("Program executed in %f seconds.\n", elapsed_time);
            return;
        } 
    }
    printf("Target number not found.\n"); 
}

int bin_search(int arr_num[], int target_num, int arr_size)
{
    begin = clock();
    int start = 0;
    int end = arr_size - 1;
    while(!(start == end))
    {
        int midpoint = (start + end) / 2;
        if(target_num == arr_num[midpoint])
        {
            clock_t end = clock();
            double elapsed_time = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("Target number found: %i\n", arr_num[midpoint]);
            printf("Program executed in %f seconds.\n", elapsed_time);
            return arr_num[midpoint];
        }
        else if(target_num < arr_num[midpoint])
        {
            end = midpoint - 1;
        }
        else if(target_num > arr_num[midpoint])
        {
            start = midpoint +1;
        }
    }
    
    if(target_num == arr_num[start])
    {
        printf("Target number found: %i\n", arr_num[start]);
        return arr_num[start];
    }
    else 
    {
        printf("Target number not found.\n");
        return 0;
    }
}

int main(void)
{
    FILE *numfile;
    numfile = fopen("/home/jharvard/Downloads/unsortedinput.txt", "r");
    if(!numfile)
    {
        printf("Error opening file.\n");
        return false;
    }
    int target_num;
    int num_string[CONST_MAX_NUM_ELEM];
    int count = 0;
    while(count < CONST_MAX_NUM_ELEM && fscanf(numfile, "%i", &num_string[count]) == 1)
        count++;
    printf("The number of integers in the file is: %i\n", count);
    bub_sort(num_string, count);
    printf("Please enter the target number.\n");
    scanf("%i", &target_num);
    printf("Starting linear search...\n");
    lin_search(num_string, target_num, count);
    printf("Starting binary search...\n");
    bin_search(num_string, target_num, count);
   
}
    
        
