#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("height ");
    }

    while (n<1 || n>8);
    
    
    
    

    for (int a = 0; a < n; a++)
    {
        for(int b = 1; b < n - a; b++)
        {
            printf(" ");
        }
        for (int b = 0; b <= a; b++)
        {
            printf("#");
        }
        
        printf("  ");
        
        for (int c = 0; c <= a; c++)
        {
            printf("#");
        }
        
        printf("\n");
    }
   
   



}