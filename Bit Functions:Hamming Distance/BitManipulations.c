/*
 * BitManipulations.c
 *
 *  Created on: Feb 8, 2013
 *      Author: yozturk
 */

#include <stdio.h>
#include "BitManipulations.h"



int main(int *argc, char **argv)
{
	uint32_t Number;
	uint32_t bitPosition;
	uint32_t value;
	int  numOnes; 
	
	uint32_t input1;
	uint32_t input2;
	int32_t hDist;


	value = 1;
	bitPosition = 21;
	Number = 15345;

	numOnes = countNumberofOnes(&Number); 	 

	setBit(&Number, bitPosition,value); // set bit in bitposition to value

	hDist = hammingDistance(input1, input2);	// Calculates hamming distance 
		
	printf("\nHamming Distance = %d \t number of Ones : %d\n", hDist, numOnes);

	return 0;
}

