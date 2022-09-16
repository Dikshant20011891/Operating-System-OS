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
	}
	else
 	{
   		sleep(10);
   		printf("Child Call");
 	}
 	return 0;
}
