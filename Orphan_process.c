#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("\nName - Dikshant Joshi \nSection – A");
        printf("\nStudent id - 20011891\n\n");
    
	int pid=fork();
	
	if (pid>0)
	{
 		printf("Parent Call\n");
		printf("PID = %d\n,getpid());
	}
	else
 	{
   		sleep(10);
   		printf("Child Call");
		printf("PID = %d\n,getpid());
		printf("Parent PID = %d\n,getppid());
 	}
 	return 0;
}
