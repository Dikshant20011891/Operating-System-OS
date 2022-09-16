#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Name – Dikshant Joshi \nSection - A ");
    printf("\nStudent ID - 20011891\n\n");
    
    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    int pid = fork();
    if (pid == 0)
    {
    	int s = 0;
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] % 2)
                s += arr[i];
        }
        printf("Sum of Odd Numbers: %d\n", s);
    }
    else
    {
    	int s = 0;
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] % 2 == 0)
                s += arr[i];
        }
        printf("Sum of Even Numbers: %d\n", s);
    }

    return 0;
}
