#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <time.h>

int NUM_THREADS[] = {2, 4, 8};
long int N[] = {100000000, 1000000000, 10000000000};
int THREAD_INDEX, N_INDEX;

long int threadSum = 0;
int count = 0;

sem_t sem;

void* ArraySum(void* data) {
	sem_wait(&sem);
	int thread_num = count++;
	//find the start for each thread
	long long int start = thread_num * (N[N_INDEX] / NUM_THREADS[THREAD_INDEX]);
	//find the end for each thread
	long long int end = (thread_num + 1) * (N[N_INDEX] / NUM_THREADS[THREAD_INDEX]);
	for (long int i = start; i < end; i++) {
		threadSum += i;
	}	
	if(thread_num == 0){
		threadSum += N[N_INDEX];  //grabbing the last N value once
	}
	free(data);
	sem_post(&sem);
}

int main() {
	clock_t start, end;
	int i,j;
	long int sum = 0;
	sem_init(&sem, 0, 1);
	for(N_INDEX = 0; N_INDEX < 3; N_INDEX++){
		
		for(THREAD_INDEX = 0; THREAD_INDEX < 3; THREAD_INDEX++){
			
			start = clock();
			pthread_t sumThreads[NUM_THREADS[THREAD_INDEX]];

			for (j = 0; j < NUM_THREADS[THREAD_INDEX]; j++) {
				int* a = malloc(sizeof(int));
				*a = i;
				pthread_create( &sumThreads[j], NULL, ArraySum, a);
			}
			
			long int* tSum;
			for (j = 0; j < NUM_THREADS[THREAD_INDEX]; j++) {
				pthread_join(sumThreads[j], NULL);
				//sum += *tSum;
			}
			end = clock();
			double totalTime = difftime(end,start)/CLOCKS_PER_SEC;
			printf("SUM: %ld\tTHREADS: %d\tTime: %.4f sec\n", threadSum, NUM_THREADS[THREAD_INDEX], totalTime);
			
			count = 0;
			threadSum = 0;
				
		}//end of thread index loop
	}//end of N index loop
	sem_destroy(&sem);
	return (0);
}

