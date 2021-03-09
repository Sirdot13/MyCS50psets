#include <stdio.h>
#include <cs50.h>

int main(void)
{
//User entry of height
    
    int height;//Declaring the variable
    
    do
    {
    height = get_int("Enter a Height from 1 to 8: ");
    }
    while(height < 1 || height > 8);
    

//Loop to print the pyramid
    
    //loop to add lines (left side)
    for (int x = 0; x < height; x++)
    {
        //loop to add spaces (left side)
        for (int s = height - x ; s > 1; s--)
        {
            printf(" ");
        }
        //loop to add hashes (left side)
        for (int d = 0; d <= x; d++)
        {
            printf("#");
        }
        //To add spaces between pyramids
        {
        printf("  ");
        }
        //loop to add hashes (right side)
        for (int d = 0; d <= x; d++)
        {
            printf("#");
        }
        
        {
        printf("\n");
        }
    }
}