/*
 * BitFunctions.c
 *
 *  Created on: Feb 8, 2013
 *      Author: Peter Azmy
 */
#include "BitManipulations.h"

//************************************************************************************/
//
//							    countNumberofOnes
//
//		   Description: Counts the number of 1s in an integer passed as argument
//		   Preconditions:input argument is passed as a pointer
//		   Postconditions:the number of 1s  returned 
//
//		   Calls:			N/A
//		   Called by:		main
//
//***********************************************************************************/

int  countNumberofOnes(uint32_t *intData)
{

      int placeholder = 0;


      uint32_t temp = *intData;


      while (temp != 0)

      {


           temp = temp&(temp - 1);


          placeholder++;

      }


      return placeholder;

}


//***********************************************************************************/
//*
//*							    setBit
//*
//*		   Description: The function sets the bit in the specified bit position in an to the specifid value.
//*		   Preconditions: Value can be a 1 or 0.  bitPosition will be between 0 and 31 (for integer size argument)
//*		   Postconditions: The bit of *inData at position biPosition will be set to value
//*
//*		   Calls:			N/A
//*		   Called by:		main
//*
//***********************************************************************************/

void setBit(uint32_t *inData, uint32_t bitPosition,uint32_t  value)
{


      uint32_t x = 1 << bitPosition - 1;


      if (value == 1)

           *inData = *inData | x;


      else if (value == 0)

           *inData = *inData^x;

}

//***********************************************************************************/
//*							hammingDistance 
//*			Description: Function hammingDistance calculates total number of bits 
//*    		that need to be inverted in order to change inData1 into inData2 or vice versa. 
//*			Preconditions: The function accepts two unsigned integers as input 
//*		    Postconditions: The function returns the hamming distance
//*
//		   Calls:			N/A
//		   Called by:		main
//*
//***********************************************************************************/

int hammingDistance(uint32_t inData1, unint32_t inData2)
{

      uint32_t dif = inData1 ^ inData2;


      int placeholder = countNumberofOnes(&dif);


      return placeholder;

}