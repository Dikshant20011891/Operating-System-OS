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
    int c = 0;
    while(c != n)
    {
        int d = 10000;
        int idx;
        for(int i=0;i<n;i++)
        {
            int tmp = abs(h - arr[i]);
            if(tmp < d)
            {
                d = tmp;
                idx = i;
            }
        }

        printf("%d\t",arr[idx]);
        seek_operation += d;
        h = arr[idx];
        arr[idx] = 10000;
        c++;
    }
    printf("\nSeek Operation = %d",seek_operation);
}