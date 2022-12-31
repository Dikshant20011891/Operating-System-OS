#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
struct process
{
    int at,bt,pri,ct,wt,tat,rt,st;
};

int main()
{
    printf("Dikshant Joshi\t A\t20011891\n");
    int n;
    printf("Enter no. of process : ");
    scanf("%d", &n);

    struct process arr[n];
    bool finish[n];
    for (int i = 0; i < n; i++)
    {
        finish[i] = false;
    }

    int bt_rem[n],curr = 0,complete = 0;
    int max_cmpt_t = INT_MIN, min_arr = INT_MAX;
    int prev = 0;
    float s_tat = 0, s_wt = 0, s_rt = 0,idle = 0, first = 1;

    for (int i = 0; i < n; i++)
    {
        printf("Enter AT BT priority: ",i + 1);
        scanf("%d%d%d", &arr[i].at, &arr[i].bt,&arr[i].pri);
        if (arr[i].at < min_arr)
        {
            min_arr = arr[i].at;
        }
        bt_rem[i] = arr[i].bt;
    }

    while (complete != n)
    {
        int idx = -1;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].at <= curr && finish[i] == 0)
            {
                if (arr[i].pri < mini)
                {
                    mini = arr[i].pri;
                    idx = i;
                }
                if (arr[i].pri == mini)
                {
                    if (arr[i].at < arr[idx].at)
                    {
                        mini = arr[i].pri;
                        idx = i;
                    }
                }
            }
        }
        if (idx == -1)
        {
            curr++;
        }
        else
        {
            if (bt_rem[idx] == arr[idx].bt)
            {
                arr[idx].st = curr;
                if (first == 1)
                {
                    idle += 0;
                }
                else
                {
                    idle += (arr[idx].st - prev);
                }
                first = 0;
            }
            bt_rem[idx]--;
            curr++;
            prev = curr;

            if (bt_rem[idx] == 0)
            {
                arr[idx].ct = curr;
                if (arr[idx].ct > max_cmpt_t)
                {
                    max_cmpt_t = arr[idx].ct;
                }
                arr[idx].tat = arr[idx].ct - arr[idx].at;
                arr[idx].wt = arr[idx].tat - arr[idx].bt;
                arr[idx].rt = arr[idx].st - arr[idx].at;
                s_tat += arr[idx].tat;
                s_wt += arr[idx].wt;
                s_rt += arr[idx].rt;
                complete++;
                finish[idx] = true;
            }
        }
    }

    printf("\nAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",arr[i].at, arr[i].bt, arr[i].ct, arr[i].tat, arr[i].wt, arr[i].rt);
    }
    printf("\nAverage TAT = %f\n", s_tat / n);
    printf("Average WT = %f\n", s_wt / n);
    printf("Average RT = %f\n", s_rt / n);
    float len = max_cmpt_t - min_arr;
    printf("Length cycle = %f\n", len);
    printf("ThroughPut = %f\n", (float)n / len);
    printf("CPU UTILISATION:- %.2f\n", ((len - idle) / len) * 100 );
    return 0;
}