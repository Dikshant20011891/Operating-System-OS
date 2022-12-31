#include<stdio.h>

int main()
{
    printf("Dikshant Joshi\t20011891\tA");
	int n,f;
	printf("\nEnter the number of pages : ");
	scanf("%d",&n);
	
	int pages[n];
	printf(" Enter the values of pages : ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&pages[i]);
	}
	
	printf("Enter the size of Frame : ");
	scanf("%d",&f);
	
	int frame[f];
	for(int i=0;i<f;i++)
		frame[i] = -1;
	int k = 0;
    int c = 0;
	
    printf("---------------Frame-------------\n");
    for(int i=0;i<n;i++)
	{
		int x = 0;
		
		for(int j=0;j<f;j++)
		{
			if(frame[j] == pages[i])
			{
				x = 1;
				break;
			}
		}
		
		if(x == 0)
		{
			frame[k] = pages[i];
			k = (k+1)%f;
            c++;
		}
		
		for(int y = 0;y<f;y++)
		{
			printf("%d\t",frame[y]);
		}
		printf("\n");
	}
	
	printf("Page fault = %d",c);
	return 0;
}

	
	
