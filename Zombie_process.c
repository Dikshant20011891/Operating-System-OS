#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	printf("\nName - Dikshant Joshi \nSection – A");
	printf("\nStudent id - 20011891\n\n");
    
  	int pid=fork();
  	if(pid>0)
  	{
   		sleep(10);
   		printf("Parent Call\n");
		printf("PID = %d\n,getpid());
  	}
  	else
  	{
   		printf("Child Call\n");
		printf("PID = %d\n,getpid());
		printf("Parent PID = %d\n,getppid());
  	}
  	
  	return 0;
}
