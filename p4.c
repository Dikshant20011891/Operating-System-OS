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
  	}
  	else
  	{
   		exit(0);
   		printf("Child Call\n");
  	}
  	
  	return 0;
}
