#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: ./recover filename\n");
        return 1;
    }
    
    char *infile = argv[1];
    int filenum = 1;
    int n = 0;
    
    //Creating buffer to store the data as I read through the memory card. Later when program works remove uint8_t to see effect. 
    
    uint8_t buffer[512];
    
    FILE *inptr = fopen(infile, "r");
    FILE *outptr;
    if(inptr == NULL)
    {
        fprintf(stderr, "Could not open %s. Please try again.\n", infile);
        return 2;
    }
    
    while(fread(buffer, 512, 1, inptr) > 0)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(n != 0)
            {
                fclose(outptr);
            }  
            
            printf("Found JPEG Image. Writing image to file...\n");
            char filename[20];
            sprintf(filename, "%03i.jpg", filenum);
            filenum++;
            outptr = fopen(filename, "w");
            fwrite(buffer, 512, 1, outptr);
            n++;
        }
        
        else
        {
            if(n != 0)
            {
                fwrite(buffer, 512, 1, outptr);
            }
        }
    }
    
    fclose(inptr);
    
    return 0;
}
            
    
    
