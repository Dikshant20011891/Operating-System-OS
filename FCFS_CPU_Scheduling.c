#include<stdio.h>
#include<stdlib.h>
 
struct fcfs{
	int at,bt,ct,tat,wt,pid,rt;
};
 
int cmp(const void *a , const void *b)
{
	int arg1 = ((const struct fcfs *)a)->at;
    int arg2 = ((const struct fcfs *)b)->at;
    
    if(arg1 == arg2)
    {
        return 1;
    }
    return (arg1 - arg2);
}
 
int main()
{
	int n;
	printf("Enter the size : ");
	scanf("%d",&n);
 
	struct fcfs arr[n];
 
    printf("Enter the value of At and Bt\n");
	for(int i = 0;i<n;i++)
	{
		scanf("%d%d",&arr[i].at,&arr[i].bt);
		arr[i].pid = i+1;
	}

	// Sort on the bases of arrival time
	qsort(arr,n,sizeof(struct fcfs),cmp);
 
	arr[0].ct = arr[0].at + arr[0].bt;
    arr[0].tat = arr[0].ct - arr[0].at;
	arr[0].wt = arr[0].tat - arr[0].bt;
	arr[0].rt = arr[0].wt;

	int stat=arr[0].tat,swt = arr[0].wt,idle = 0,sat=arr[0].at;

	for(int i=1;i<n;i++)
	{
		if(arr[i].at >= arr[i-1].ct)
		{
			arr[i].ct = arr[i].at + arr[i].bt;
		}
		else
		{
			arr[i].ct = arr[i-1].ct + arr[i].bt;
		}

		if(arr[i-1].ct < arr[i].at)
		{
		    idle += arr[i].at - arr[i-1].ct;
		}
        
		arr[i].tat = arr[i].ct - arr[i].at;
		arr[i].wt = arr[i].tat - arr[i].bt;
		arr[i].rt = arr[i].wt;
		sat += arr[i].rt;
		stat += arr[i].tat;
		swt += arr[i].wt;
	}
 
	printf("Pid\tAT\tBT\tCT\tTAT\tWT\tRT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",arr[i].pid,arr[i].at,arr[i].bt,arr[i].ct,arr[i].tat,arr[i].wt,arr[i].rt);
	}

	int lengthCycle = arr[n-1].ct-arr[0].at;
	float cpuUt = (lengthCycle-idle)/lengthCycle;
	printf("\n Average Turn around time = %f",(float)stat/n);
	printf("\n Average waiting time = %f",(float)swt/n);
	printf("\n Average response time = %f",(float)sat/n);
	printf("\n Throughput = %d",lengthCycle);
	printf("\n Idle Time = %d",idle);
	printf("\n Cpu Utilization = %f %",cpuUt*100);
	
	return 0;   
}

