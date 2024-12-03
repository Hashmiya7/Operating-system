#include<stdio.h>
#include<stdlib.h>
int mutex=1;
int full=0;
int empty=10;
int main()
{
	printf("Press 1 for producer\n");
	printf("Press 2 for consumer\n");
	printf("Press 3 for exit\n");
	again:printf("Enter your choice:\n");
	int n,i;
	scanf("%d",&n);
	switch(n)
	{
		case 1:
		if((mutex==1)&&(empty!=0))
		{
			producer();
		}
		else
		{
			printf("The buffer is full\n");
		}
		break;
		case 2:
		if((mutex==1)&&(full!=0))
		{
			consumer();
		}
		else
		{
			printf("Buffer is empty\n");
		}
		break;
		case 3:
			exit(0);
			break;
		default:
			printf("Invalid input\n");
			goto again;
		}
}
void producer()
{
	--mutex;
	++full;
	--empty;
	++mutex;
}
void consumer()
{
	--full;
	--mutex;
	++empty;
	++mutex;
}
