#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int rows,userInput, blocks, spaces, numSpaces;
printf("How many rows do you want the triangle to have?\n");
scanf("%i", &userInput);

//Loop until user enters number within accepted range.
while(userInput <= 0 || userInput > 23)
{
    printf("Please enter a number between 0 and 23.\n");
    scanf("%i", &userInput);
}
numSpaces = userInput;

/* Set up a loop that adds blocks in designed manner
incrementing the number of blocks per line until hitting the set limits.
*/
for(rows = 1; rows <= userInput; rows++)
{
    for(spaces = 1; spaces <= numSpaces; spaces++) {
    printf(" ");
    }
    numSpaces--;
    for(blocks = 1; blocks <= rows; blocks++)
    {
    printf("#");
    }
    printf("  ");
    for(blocks = 1; blocks <= rows; blocks++)
    {
    printf("#");
    }
    printf("\n");
    }
return 0;
}
