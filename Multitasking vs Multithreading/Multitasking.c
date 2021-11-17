
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int NUM_TASKS[] = {2, 4, 8};
long int N[] = {100000000, 1000000000, 10000000000};

int main(int argc, char *argv[]) {

	clock_t start, end;
	
	int i, j;

    FILE* fp1;
    FILE* fp2;
    FILE* fp3;
    FILE* fp4;
    FILE* fp5;
    FILE* fp6;
    FILE* fp7;
    FILE* fp8;
    
    long long int sum = 0;
    long long int receive1 = 0;
    long long int receive2 = 0;
    long long int receive3 = 0;
    long long int receive4 = 0;
    long long int receive5 = 0;
    long long int receive6 = 0;
    long long int receive7 = 0;
    long long int receive8 = 0;
    
    for(i = 0; i < 3; i++){
    	for(j = 0; j < 3; j++){
    		if(i == 0){
				if(NUM_TASKS[j] == 2){ 
					start = clock();
					fp1 = popen("./case3file 1 50000000", "r");
					fscanf(fp1, "%lld", &receive1);
					fp2 = popen("./case3file 50000001 100000000", "r");
					fscanf(fp2, "%lld", &receive2);

					sum = receive1+receive2;
					end = clock();
					
					double totalTime = difftime(end, start)/CLOCKS_PER_SEC;
					
					printf("SUM: %lld\tTime: %.4f\n", sum, totalTime);
				}//end N = 0, NUM_TASK = 0
				if(NUM_TASKS[j] == 4){ 
					start = clock();
					fp1 = popen("./case3file 1 25000000", "r");
					fscanf(fp1, "%lld", &receive1);
					fp2 = popen("./case3file 25000001 50000000", "r");
					fscanf(fp2, "%lld", &receive2);
					fp3 = popen("./case3file 50000001 75000000", "r");
					fscanf(fp3, "%lld", &receive3);
					fp4 = popen("./case3file 75000001 100000000", "r");
					fscanf(fp4, "%lld", &receive4);

					sum = receive1+receive2+receive3+receive4;
					end = clock();
					
					double totalTime = difftime(end, start)/CLOCKS_PER_SEC;
					
					printf("SUM: %lld\tTime: %.4f\n", sum, totalTime);
				}//end N = 0, NUM_TASK = 1
				if(NUM_TASKS[j] == 8){ 
					start = clock();
					fp1 = popen("./case3file 1 12500000", "r");
					fscanf(fp1, "%lld", &receive1);
					fp2 = popen("./case3file 12500001 25000000", "r");
					fscanf(fp2, "%lld", &receive2);
					fp3 = popen("./case3file 25000001 37500000", "r");
					fscanf(fp3, "%lld", &receive3);
					fp4 = popen("./case3file 37500001 50000000", "r");
					fscanf(fp4, "%lld", &receive4);
					fp5 = popen("./case3file 50000001 62500000", "r");
					fscanf(fp5, "%lld", &receive5);
					fp6 = popen("./case3file 62500001 75000000", "r");
					fscanf(fp6, "%lld", &receive6);
					fp7 = popen("./case3file 75000001 87500000", "r");
					fscanf(fp7, "%lld", &receive7);
					fp8 = popen("./case3file 87500001 100000000", "r");
					fscanf(fp8, "%lld", &receive8);
					
					sum = receive1+receive2+receive3+receive4+receive5+receive6+receive7+receive8;
					end = clock();
					
					double totalTime = difftime(end, start)/CLOCKS_PER_SEC;
					
					printf("SUM: %lld\tTime: %.4f\n", sum, totalTime);
				}//end N = 0, NUM_TASK = 2
			}//end N = 100 million
			if(i == 1){
				if(NUM_TASKS[j] == 2){ 
					start = clock();
					fp1 = popen("./case3file 1 500000000", "r");
					fscanf(fp1, "%lld", &receive1);
					fp2 = popen("./case3file 500000001 1000000000", "r");
					fscanf(fp2, "%lld", &receive2);

					sum = receive1+receive2;
					end = clock();
					
					double totalTime = difftime(end, start)/CLOCKS_PER_SEC;
					
					printf("SUM: %lld\tTime: %.4f\n", sum, totalTime);
				}//end N = 1, NUM_TASK = 0
				if(NUM_TASKS[j] == 4){ 
					start = clock();
					fp1 = popen("./case3file 1 250000000", "r");
					fscanf(fp1, "%lld", &receive1);
					fp2 = popen("./case3file 250000001 500000000", "r");
					fscanf(fp2, "%lld", &receive2);
					fp3 = popen("./case3file 500000001 750000000", "r");
					fscanf(fp3, "%lld", &receive3);
					fp4 = popen("./case3file 750000001 1000000000", "r");
					fscanf(fp4, "%lld", &receive4);

					sum = receive1+receive2+receive3+receive4;
					end = clock();
					
					double totalTime = difftime(end, start)/CLOCKS_PER_SEC;
					
					printf("SUM: %lld\tTime: %.4f\n", sum, totalTime);
				}//end N = 1, NUM_TASK = 1
				if(NUM_TASKS[j] == 8){ 
					start = clock();
					fp1 = popen("./case3file 1 125000000", "r");
					fscanf(fp1, "%lld", &receive1);
					fp2 = popen("./case3file 125000001 250000000", "r");
					fscanf(fp2, "%lld", &receive2);
					fp3 = popen("./case3file 250000001 375000000", "r");
					fscanf(fp3, "%lld", &receive3);
					fp4 = popen("./case3file 375000001 500000000", "r");
					fscanf(fp4, "%lld", &receive4);
					fp5 = popen("./case3file 500000001 625000000", "r");
					fscanf(fp5, "%lld", &receive5);
					fp6 = popen("./case3file 625000001 750000000", "r");
					fscanf(fp6, "%lld", &receive6);
					fp7 = popen("./case3file 750000001 875000000", "r");
					fscanf(fp7, "%lld", &receive7);
					fp8 = popen("./case3file 875000001 1000000000", "r");
					fscanf(fp8, "%lld", &receive8);
					
					sum = receive1+receive2+receive3+receive4+receive5+receive6+receive7+receive8;
					end = clock();
					
					double totalTime = difftime(end, start)/CLOCKS_PER_SEC;
					
					printf("SUM: %lld\tTime: %.4f\n", sum, totalTime);
				}//end N = 1, NUM_TASK = 2
			}//end N = 1 Billion
			if(i == 2){
				if(NUM_TASKS[j] == 2){ 
					start = clock();
					fp1 = popen("./case3file 1 5000000000", "r");
					fscanf(fp1, "%lld", &receive1);
					fp2 = popen("./case3file 5000000001 10000000000", "r");
					fscanf(fp2, "%lld", &receive2);

					sum = receive1+receive2;
					end = clock();
					
					double totalTime = difftime(end, start)/CLOCKS_PER_SEC;
					
					printf("SUM: %lld\tTime: %.4f\n", sum, totalTime);
				}//end N = 0, NUM_TASK = 0
				if(NUM_TASKS[j] == 4){ 
					start = clock();
					fp1 = popen("./case3file 1 2500000000", "r");
					fscanf(fp1, "%lld", &receive1);
					fp2 = popen("./case3file 2500000001 5000000000", "r");
					fscanf(fp2, "%lld", &receive2);
					fp3 = popen("./case3file 5000000001 7500000000", "r");
					fscanf(fp3, "%lld", &receive3);
					fp4 = popen("./case3file 7500000001 10000000000", "r");
					fscanf(fp4, "%lld", &receive4);

					sum = receive1+receive2+receive3+receive4;
					end = clock();
					
					double totalTime = difftime(end, start)/CLOCKS_PER_SEC;
					
					printf("SUM: %lld\tTime: %.4f\n", sum, totalTime);
				}//end N = 0, NUM_TASK = 1
				if(NUM_TASKS[j] == 8){ 
					start = clock();
					fp1 = popen("./case3file 1 1250000000", "r");
					fscanf(fp1, "%lld", &receive1);
					fp2 = popen("./case3file 1250000001 2500000000", "r");
					fscanf(fp2, "%lld", &receive2);
					fp3 = popen("./case3file 2500000001 3750000000", "r");
					fscanf(fp3, "%lld", &receive3);
					fp4 = popen("./case3file 3750000001 5000000000", "r");
					fscanf(fp4, "%lld", &receive4);
					fp5 = popen("./case3file 5000000001 6250000000", "r");
					fscanf(fp5, "%lld", &receive5);
					fp6 = popen("./case3file 6250000001 7500000000", "r");
					fscanf(fp6, "%lld", &receive6);
					fp7 = popen("./case3file 7500000001 8750000000", "r");
					fscanf(fp7, "%lld", &receive7);
					fp8 = popen("./case3file 8750000001 10000000000", "r");
					fscanf(fp8, "%lld", &receive8);
					
					sum = receive1+receive2+receive3+receive4+receive5+receive6+receive7+receive8;
					end = clock();
					
					double totalTime = difftime(end, start)/CLOCKS_PER_SEC;
					
					printf("SUM: %lld\tTime: %.4f\n", sum, totalTime);
				}//end N = 0, NUM_TASK = 2
			}//end N = 10 Billion
		}//end NUM_TASK for loop
	}//end N for loop
    return 0;
}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char const *argv[])
{		
	long int i = 0;
	char *c = argv[1];
	char *d = argv[2];
	long int start = atol(c);
	long int end = atol(d);


	
	long int sum = 0;
	for(i = start; i <= end ; i++){
		sum += i;
	}
	
	printf("%ld", sum);
	return 0;

}