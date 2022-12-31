#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int check(int frame[],int f,int a)
{
    for(int i=0;i<f;i++)
    {
        if(frame[i] == a)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n;
    printf("enter number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("enter pages values: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }
    int f;
    printf("enter number of frames: ");
    scanf("%d", &f);
    int frame[f];
    int dis[f];

    for(int i=0;i<f;i++)
    {
        frame[i] = -1;
        dis[i] = -1;
    }

    int c = 0;
    printf("*************Frame****************\n");
    for(int i=0;i<n;i++)
    {
        if(check(frame,f,pages[i]))
        {
            for(int j=0;j<f;j++)
            {
                if(pages[i] == frame[j])
                {
                    dis[j] = i;
                }
            }
        }
        else
        {
            printf("New\n");
            int tmp = 10000;
            int idx;
            for(int j=0;j<f;j++)
            {
                if(dis[j] < tmp)
                {
                    tmp = dis[j];
                    idx = j;
                }
            }
            frame[idx] = pages[i];
            dis[idx] = i;
            c++;
        }

        for(int j=0;j<f;j++)
        {
            if(frame[j] != -1)
            {
                printf("%d\t",frame[j]);
            }
        }
        printf("\n");
    }

    printf("\nPage fault = %d",c);
    return 0;   
}