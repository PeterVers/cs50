#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int find_max(int *O_A, int arr_size)
{
    int max_num = 0;
    for(int i = 0; i < arr_size; i++)
    {
        if(max_num < O_A[i])
        {
            max_num = O_A[i];
        }
    }
    
    return max_num;
}

void count_sort(int *O_A, int arr_size)
{
    int count;
    int max_num = find_max(O_A, arr_size);
    int count_arr[max_num+1];
    printf("%i\n", max_num);
    
    for(int i = 0; i < max_num+1; i++)
    {
        count_arr[i] = 0;
    }
    
    for(int i = 0; i < arr_size; i++)
    {
        for(count = 0; count < max_num+1; count++)
        {
            if(O_A[i] == count)
            {
                count_arr[count]++;
            }
        }
    }
    
    for(int j = 0; j < arr_size; j++)
    {
       for(int k = 0; k < max_num+1; k++)
       {
           if(count_arr[k] != 0)
           {
               while(count_arr[k] != 0)
               {
                   O_A[j] = k;
                   j++;
                   count_arr[k]--;
               }
           }
       }
   }
   for(int i = 0; i < arr_size; i++)
   {
       printf("%i\n", O_A[i]);
   }
}

int main(void)
{
    int num_array[10] = {4, 7, 3, 2, 8, 3, 2, 8, 13, 34};
    int arr_size = 10;
    count_sort(num_array, arr_size);
}
    

           
            
                 
           
        
       
    
