#include <stdio.h>
#include<math.h>
#include<stdlib.h>

void sort(int l[], int x)
{
    for (int i = 0; i < x - 1; i++)
    {
        for (int j = 0; j < x - i - 1; j++)
        {
            if (l[j] > l[j + 1])
            {
                int tmp = l[j];
                l[j] = l[j + 1];
                l[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    int n, h, d, x = 0, y = 0, mx,seek_count=0;
    printf("Dikshant Joshi\t20011891\tA\n");
    printf("Enter the disk size, head position , maximum request size\n");
    scanf("%d%d%d", &n, &h, &mx);
    int l[n], r[n];
    printf("Enter the requests : ");
    for (int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        if (tmp < h)
            l[x++] = tmp;
        if (tmp > h)
            r[y++] = tmp;
    }
    printf("Enter the direction\n1. Left\n2. Right");
    scanf("%d", &d);

    if (d == 1)
        l[x++] = 0;
    else
        r[y++] = mx - 1;

    sort(l, x);
    sort(r, y);

    int run = 2;
    printf("\nSeek Sequence : ");
    while (run--)
    {
        if (d == 1)
        {
            for (int i = x - 1; i >= 0; i--)
            {
                printf("%d\t",l[i]);
                seek_count += abs(l[i] - h);
                h = l[i];
            }
            d = 2;
        }
        else if (d == 2)
        {
            for (int i = 0; i < y; i++)
            {
                printf("%d\t",r[i]);
                seek_count += abs(r[i] - h);
                h = r[i];
            }
            d = 1;
        }
    }
    printf("\nSeek Operation = %d",seek_count);
}