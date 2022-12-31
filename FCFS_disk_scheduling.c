#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n,h;
    printf("Dikshant Joshi\t20011891\tA\n");
    printf("Enter the size of disk queue : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the sequence : ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("\nEnter the head position : ");
    scanf("%d",&h);
    
    int seek_operation = 0;
    printf("\nSeek Sequence : ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
        int d = abs(arr[i] - h);
        seek_operation += d;
        h = arr[i];
    }
    printf("\nSeek Operation = %d",seek_operation);
}