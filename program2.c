#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	int bt[n],wt[n],tat[n];
	printf("Enter the burst time for %d processes\n",n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&bt[i]);
	}
	//calculating the waiting time
	for(int i=2;i<=n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
	}
	//calculating the turn around time
	for(int i=1;i<=n;i++)
	{
		tat[i]=bt[i]+wt[i];
	}
	//printing the details
	for(int i=1;i<=n;i++)
	{
		printf("Process: %d	%d	%d	%d\n",i,bt[i],wt[i],tat[i]);
	}
}
