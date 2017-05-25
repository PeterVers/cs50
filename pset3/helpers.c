/**
 * helpers.c
 *
 * Helper functions for Problem Set 3. Implemented by myself.
 */
 
#include <cs50.h>
#include <time.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
     clock_t begin = clock();
    int start = 0;
    int end = n - 1;
    while(!(start == end))
    {
        int midpoint = (start + end) / 2;
        if(value == values[midpoint])
        {
            clock_t end = clock();
            double elapsed_time = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("Target number found: %i\n", values[midpoint]);
            printf("Program executed in %f seconds.\n", elapsed_time);
            return true;
        }
        else if(value < values[midpoint])
        {
            end = midpoint - 1;
        }
        else if(value > values[midpoint])
        {
            start = midpoint +1;
        }
    }
    
    if(value == values[start])
    {
        printf("Target number found: %i\n", values[start]);
        return true;
    }
    else 
    {
        printf("Target number not found.\n");
        return false;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    clock_t begin = clock();
    int num_swap;
    int swap_counter = -1;
    while(swap_counter != 0)
    {
       swap_counter = 0;
       for(int i = 0; i < n; i++)
       {
            if(i <= n - 2 && values[i] > values[i+1])
            {
                num_swap = values[i+1];
                values[i+1] = values[i];
                values[i] = num_swap;
                swap_counter++;
            }
        }
        n--;
    }
    clock_t end = clock();
    double elapsed_time = (double)(end - begin) / CLOCKS_PER_SEC;
    for(int i = 0; i < n; i++)
    {
        printf("%i\n", values[i]);
    }
    printf("Program executed in %f seconds.\n", elapsed_time);
    return;
}
