#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // getting the number
    
    long a = get_long("numero do cartao ");
    
    
    //counter length
    
    long b =  a;
    int i = 0;
    while(b>0)
    {
        b= b / 10;
        i++;
    }
    
    // check if lenght is valid
     
    if (i != 13 && i != 15 && i!= 16)
    {
        printf("INVALID");
        return 0;
    }
    
    //checksum
    
    int soma1 = 0;
    int soma2 = 0;
    long num = a;
    int op1;
    int op2;
    int total = 0;
    int op3;
    int op4;
    
    do
    {
    //operação 1
    
       op1 = num % 10;
       num = num / 10;
       soma1 = soma1 + op1;
    // operação 2
       
       //num % 10 = op2;
       op2 = num % 10;
       num = num / 10;
       op2 = op2 * 2;
       op3 = op2 % 10;
       op4 = op2 / 10;
       soma2 = soma2 + op3 + op4;
    }

    while (num>0);
    
    total = soma1 + soma2;
    
    //check if final is 0
    if (total % 10 != 0)
    {
        printf ("INVALID");
        return 0;
    }
    
    long x = a;
    do
    {
        x = x / 10;
    }
    while (x>100);
    
    if ((x / 10 == 5)&&(0<x % 10 && x % 10 < 6))
    {
        printf ("Mastercard\n");
    }
    
    else if ((x / 10 == 3)&&(x % 10 == 4 || x % 10 == 7))
    {
        printf ("AMEX\n");
    }
    
    else if(x / 10 == 4)
    {
        printf("Visa");
    }
    
    else
    {
        printf ("INVALID");
    }
    
}
  