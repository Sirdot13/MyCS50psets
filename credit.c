#include <cs50.h>
#include <stdio.h>

// MASTERCARD: 16-Digit #'s, Start with: 51, 52, 53, 54, or 55
// VISA: 13-16-Digit #'s, Start with: 4
// AMEX: 15-Digit #'s, Star with: 34 or 37



int main(void)
{
//First set to get Credit card numbers
    // Declaring variables
    int count = 0;
    long n;
    long nNum;
    
    //Getting credit card number
    do
    {
    n = get_long("Please, inform the credit card number: ");
    nNum = n;
    }
    while (n < 0);

//Count characters
    while(n > 0)
    {
        n = n/10;
        count ++;
    }
    //Check leghth validity
    
    if(count != 13 && count != 15 && count != 16)
    {
    printf("INVALID\n");
    return 0;
    }
    
//Luhn's Alorithm
    //Variables
    int sum1 = 0;
    int mod1;
    int sum2 = 0;
    int mod2;
    long nalg = nNum;
    int d1;
    int d2;
    int total = 0;
    
    //Execution of Algorithm
    do
    {
    //Remove last digit and add to sum
        mod1 = nalg % 10;
        nalg = nalg / 10;
        sum1 = sum1 + mod1;
       
    //Remove second to last digit
        mod2 = nalg % 10;
        nalg = nalg / 10;
       
    //Multiply by two last digit and add digits to sum 2
       mod2 = mod2 * 2;
       d1 = mod2 % 10;
       d2 = mod2 / 10;
       sum2 = sum2 + d1 + d2;
    }
    while (nalg >0);
    total = sum1 + sum2;
    
//Check algorithm results
    if(total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    
//Check for CC Flag
  
    //Variables
    long start = nNum;
    
    //Getting first digits
    do
    {
        start = start / 10;
    }
    while(start >100);
    
    //Checking first digits
    if(start / 10 == 4)
    {
        printf("VISA\n");
    }
    
    else if(start == 34 || start == 37)
    {
        printf("AMEX\n");
    }
    
    else if(start == 51 || start == 52 || start == 53 || start == 54 || start == 55)
    {
        printf("MASTERCARD\n");
    }
    
    else
    {
        printf("INVALID\n");
    }
}