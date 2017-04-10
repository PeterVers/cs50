#include <stdio.h>
#include <cs50.h>
int steps = 0;

int collatz(int n)
{
    
    if(n == 1)
    {
        printf("n is now equal to 1.\n");
        printf("Steps it took to complete: %i\n", steps);
        return n;
    }
    else if(n % 2)
    {
        steps++;
        collatz((3*n)+1);
    }
    else if(!(n % 2))
    {
        steps++;
        collatz(n/2);
    }
    else
        printf("n must be a positive integer.\n");
        return 0;
}

int main(void)
{
    int n;
    printf("Please enter a positive integer.\n");
    scanf("%i", &n);
    collatz(n);
}
