#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int array[] = { 0, 1, 2, 3, 4, 5, 6};
    
    printf("Length of array: %d\n", (int) sizeof(array)/sizeof(array[0]));
    
}
