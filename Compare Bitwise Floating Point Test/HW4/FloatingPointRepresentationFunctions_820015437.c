/*
 * FloatingPointRepresentationFunctions.c
 */


//************************************************************************************/
//
//							    FloatCompare
//
//		   Description:Accepts two float numbers and compares them bitwise based 
//			       on floating point representations. This function will have
// 			       to convert the given numbers into IEEE floating 
// 			       representation and then do bitwise comparison
//		   Preconditions:two input arguments are passed
//		   Postconditions:Returns 1,-1 or 0 based on the comparison
//				  1 if number1>number2
//                               -1 if number2>number1
//                                  0 if equal
//		   Calls:			N/A
//		   Called by:		main
//
//***********************************************************************************/

int  bitwisedFloatCompare(float number1,float number2)
{
    int x;
    int y;
    int z;
    int temp1 = number1;
    int temp2 = number2;
    int valuereturned = 0;
    
    
    
    for (x = 31; x >= 0; x--)
    {
        y = temp1 >> x;
        z = temp2 >> x;
        
        if (y == z && x == 0)
            valuereturned = 0;
        else if (y > z)
        {
            valuereturned = 1;
            break;
        }
        else if (z > j)
        {
            valuereturned = -1;
            break;
        }
        else
            valuereturned = 54652;
    }
    return valuereturned;
}

void printFloatRepresentation(float number)
{
    int i;
    int j;
    int w = 8;
    int shift = 0;
    int bias;
    int mantissa;
    int MantDist;
    int exponent;
    union Float_Compare num;
    int temp = number;
    
    
    for (i = 31; i >= 0; i--)
    {
        j = temp >> i;
        
        if ((j & 1) == 1)
            num.binary[i]='1';
        else
            num.binary[i]='0';
    }
    
    
    j = temp >> 31;
    if ((j & 1) == 1)
        num.ieee[31]='1';
    else
        num.ieee[31]='0';
    
    
    for (i=7; i >=0; i--)
    {
        j = temp >> i;
     
        if ((j & 1) == 1)
            break;
        else
            shift++;
    }
    shift = 7-shift;
    
    
    bias = pow(2, (w-1))-1;
    
    exponent = bias + shift;
    
  
    for (i = 7; i >= 0; i--)
    {
        j = exponent >> i;
        if ((j & 1) == 1)
            num.ieee[i+23]='1';
        else
            num.ieee[i+23]='0';
    }
    
    
    mantissa = temp - pow(2, shift);
  
    
   
    MantDist = 23 - shift;
    for (i = shift; i >= 0; i--)
    {
        j = mantissa >> i;
        if ((j & 1) == 1)
            num.ieee[i+MantDist]='1';
        else
            num.ieee[i+MantDist]='0';
    }
    for (i=MantDist-1; i>=0; i--)
        num.ieee[i]='0';
    
    
    printf("\n(%c) ", num.ieee[31]);
    

    for (i=30; i>=23; i--)
        printf("%c",num.ieee[i]);
    

    printf(" (1).");
    for (i=22; i>=0; i--)
        printf("%c",num.ieee[i]);
    
   
}


