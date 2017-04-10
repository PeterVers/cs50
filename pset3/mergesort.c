#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void merge_sort(int arr_num, int arr_size)
{
    int left_arr[arr_size/2];
    int right_arr[arr_size/2];
    int unsort[];
    int sort[arr_size];
    int start = 0;
    int end = arr_size - 1;
    
    if(arr_size < 2)
        return;
    else
    {
        while(arr_size >= 2)
        {
            for(int i = 0; i < arr_size / 2; i++)
            {
                left_arr[i] = arr_num[i];
            }
            
            for(int i = arr_size / 2; i <= end; i++)
            {
                right_arr[i] = arr_num[i];
            }
            
           
                  
        
