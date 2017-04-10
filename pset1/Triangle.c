#include <stdio.h>
#include <cs50.h>
int main(void)
{
int n, x, z, spaces, rows;
printf("How many rows do you want the triangle to have?\n");
do {
    rows = GetInt();
    }
    while ( rows <= 0 || rows > 23);
spaces = rows;
for(n = 1; n <= rows; n++)
{
    for(z = 1; z <= spaces; z++) {
    printf(" ");
    }
    spaces--;
    for(x = 1; x <= n; x++)
    {
    printf("#");
    }
    printf("  ");
    for(x = 1; x <= n; x++)
    {
    printf("#");
    }
    printf("\n");
    }
return 0;
}
 
