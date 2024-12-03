#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	int p[n],bt[n],wt[n],tat[n],pr[n];
	printf("Enter the burst time of %d processes:",n);
	for(int i=1;i<=n;i++)
	{
		p[i]=i;
		scanf("%d",&bt[i]);
	}
	printf("Enter the priority of %d proesses:",n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&pr[i]);
	}
	int temp;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(pr[i]>pr[j])
			{
				temp=pr[i];
				pr[i]=pr[j];
				pr[j]=temp;
			}
		}
	}
	wt[1]=0;
	for(int i=2;i<=n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		tat[i]=bt[i]+wt[i];
	}
	for(int i=1;i<=n;i++)
	{
		printf("Process: %d	%d	%d	%d	%d\n",p[i],pr[i],bt[i],wt[i],tat[i]);
	}
}
