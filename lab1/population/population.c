#include <stdio.h>
#include <cs50.h>

int main (void)
{
    
    // perguntando o numero de lhamas
    int n;
    do
    {
        n = get_int("Numero iniciais de lhamas\n ");
    }
    while (n<9);
    
    
    
    int nf;
    do
    {
        nf = get_int("Numero final de lhamas\n ");
        
    }
    while (nf<n);
    
    int x = 0;
    while (n<nf)
    {
        n = n + (n/3) - (n/4);
        x++;
    }
    
    printf("numero de anos %i\n", x);
    
    
}