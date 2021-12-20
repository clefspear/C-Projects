/*/*
 * FloatingPointRepresentation.c
 Please do not return this file or the main function with your homework
 */

#include <stdio.h>
#include <stdlib>

int main()
{
    float number1;
    float number2;
    
    int comparison;
    
    number1=56;
    number2=12;
    
    comparison=bitwisedFloatCompare(number1,number2) ; // Compare two floating point numbers
    
    if (comparison==1)
        printf(“%f is greater than %f\n”,number1,number2);
    else if (comparison==-1)
        printf(“%f is greater than %f\n”,number2,number1);
    else if (comparison==0)
        printf(“Number are equal\n”);
    else
        printf(“Error\n);
    
    
    
    return 0;
}
