#include<stdio.h>
#include<stdlib.h>

struct fcfs{
	int at,bt,ct,tat,wt,pid,rt;
};

int cmp(const void *a , const void *b)
{
    int arg1 = ((const struct fcfs *)a)->at;
    int arg2 = ((const struct fcfs *)b)->bt;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}
 
int main()
{
	int n;
	printf("Enter the size : ");
	scanf("%d",&n);
	
	struct fcfs arr[n];
	
	for(int i = 0;i<n;i++)
	{
		printf("Enter the value of At and Bt\n");
		scanf("%d%d",&arr[i].at,&arr[i].bt);
		arr[i].pid = i+1;
	}
	
	qsort(arr,n,sizeof(struct fcfs),cmp);
	
	int stat=0,swt = 0;
	
	arr[0].ct = arr[0].at + arr[0].bt;
	
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
		arr[i].tat = arr[i].ct - arr[i].at;
		arr[i].wt = arr[i].tat - arr[i].bt;
		arr[i].rt = arr[i].ct - arr[i].bt;
		stat += arr[i].tat;
		swt += arr[i].wt;
	}
	
	printf("Pid\tAT\tBT\tCT\tTAT\tWT\tRT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",arr[i].pid,arr[i].at,arr[i].bt,arr[i].ct,arr[i].tat,arr[i].wt,arr[i].rt);
	}
	return 0;
}

