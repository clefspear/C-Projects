#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	clock_t start, end;
	long int N[] = {100000000, 1000000000, 10000000000};
	long int i;
	int k;
	
	for(k = 0; k < 3; k++){
		long int sum = 0;
		start = clock();
		for(i = 0; i <= N[k]; i++){
			sum = sum + i;
		}
		end = clock();
		
		double totalTime = difftime(end, start)/CLOCKS_PER_SEC;
		printf("%ld\ttime: %.5f sec\n", sum, totalTime);
	}
	return(0);
}