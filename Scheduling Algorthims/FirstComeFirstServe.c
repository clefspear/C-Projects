#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>  
#include <stdlib.h>  
#include <sys/wait.h> 
#include <string.h> 
#include <time.h> 
#include <signal.h>
#include <sys/time.h>

/************************************************************************************************ 
		These DEFINE statements represent the workload size of each task and 
		the time quantum values for Round Robin scheduling for each task.
*************************************************************************************************/

#define WORKLOAD1 100000
#define WORKLOAD2 50000
#define WORKLOAD3 25000
#define WORKLOAD4 10000

#define QUANTUM1 1000
#define QUANTUM2 1000
#define QUANTUM3 1000
#define QUANTUM4 1000



/************************************************************************************************ 
					DO NOT CHANGE THE FUNCTION IMPLEMENTATION
*************************************************************************************************/
void myfunction(int param){

	int i = 2;
	int j, k;

	while(i < param){
		k = i; 
		for (j = 2; j <= k; j++)
		{
			if (k % j == 0){
				k = k/j;
				j--;
				if (k == 1){
					break;
				}
			}
		}
		i++;
	}
}
/************************************************************************************************/


int main(int argc, char const *argv[])
{


	pid_t pid1, pid2, pid3, pid4;
	int running1, running2, running3, running4;


	pid1 = fork();


	if (pid1 == 0){
		myfunction(WORKLOAD1);
		exit(0);
	}
	
	kill(pid1, SIGSTOP);


	pid2 = fork();

	if (pid2 == 0){
		myfunction(WORKLOAD2);
		exit(0);
	}
	kill(pid2, SIGSTOP);


	pid3 = fork();

	if (pid3 == 0){
		myfunction(WORKLOAD3);
		exit(0);
	}
	kill(pid3, SIGSTOP);


	pid4 = fork();

	if (pid4 == 0){
		myfunction(WORKLOAD4);
		exit(0);
	}
	kill(pid4, SIGSTOP);

	/************************************************************************************************ 
		At this point, all  newly-created child processes are stopped, and ready for scheduling.
	*************************************************************************************************/



	/************************************************************************************************
		- Scheduling code starts here 
		- Below is a sample schedule. (which scheduling algorithm is this? Round Robin)
		- For the assignment purposes, you have to replace this part with the other scheduling methods 
		to be implemented.
	************************************************************************************************/

	
	running1 = 1;
	running2 = 1;
	running3 = 1;
	running4 = 1;
	
	
	//clock_t start[];
	//clock_t end[];


struct timeval {
    time_t      tv_sec;     // seconds 
    suseconds_t tv_usec;    // microseconds
};

    struct timeval start;
	struct timeval end[4];

   gettimeofday(&start, NULL);

		if (running1 > 0){
	
			kill(pid1, SIGCONT);
			waitpid(pid1, NULL, 0);
			kill(pid1, SIGSTOP);
		}    gettimeofday(&end[0], NULL);

		if (running2 > 0){
				
			kill(pid2, SIGCONT);
			waitpid(pid2, NULL, 0);
			kill(pid2, SIGSTOP);
			
		} gettimeofday(&end[1], NULL);

		if (running3 > 0){
			
			kill(pid3, SIGCONT);
			waitpid(pid3, NULL, 0);
			kill(pid3, SIGSTOP);
			
		}    gettimeofday(&end[2], NULL);

		if (running4 > 0){
			
			kill(pid4, SIGCONT);
			waitpid(pid4, NULL, 0);
			kill(pid4, SIGSTOP);
	
		}    gettimeofday(&end[3], NULL);

	double sum = 0.0;
	double time_taken[4];


		for (int i = 0 ; i < 4; i++) {
			
			//sum = end[0]+end[1]+end[2]+end[3];
			
			//sum += end[i];

			//time_taken = (end[0].tv_sec - start.tv_sec);

			time_taken[i] = (end[i].tv_sec - start.tv_sec);
    		time_taken[i] = (time_taken[i] + (end[i].tv_usec - start.tv_usec) * 1e-6);

    		sum += time_taken[i];
		}

		double averageTime = sum / 4.0;

		printf("%f\n", averageTime);


		
	/************************************************************************************************
		- Scheduling code ends here
	************************************************************************************************/

	return 0;
}