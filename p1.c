#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("\nName - Dikshant Joshi \nSection – A");
    printf("\nStudent id - 20011891\n\n");
    
    fork();
    printf("Hello World!\n");
    printf("Get PID: %d\n\n", getpid());
    
    return 0;
}
