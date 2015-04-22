#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void heapadjust(int x[],int start,int end)
{
	int child;
	int temp,i;
	for(i=start;i*2+1<=end;i=child)
	{
		child=i*2;
		if((x[child+1]>x[child])&&(child+1<=end))child++;
		if(x[i]<x[child])
		{
			temp=x[i];
			x[i]=x[child];
			x[child]=temp;
		}
		else break;
	}
}

int main()
{
	int x[100000];
	int i;
	int n;
	srand((unsigned)time(NULL));
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&x[i]);
	for(i=1;i<=n;i++)printf("%d ",x[i]);printf("\n");
	for(i=n/2;i>0;i--)
	{
		heapadjust(x,i,n);
	}
	for(i=n;i>1;i--)
	{
		x[0]=x[1];
		x[1]=x[i];
		x[i]=x[0];
		heapadjust(x,1,i-1);
	}
	for(i=1;i<=n;i++)printf("%d ",x[i]);printf("\n");
	return 0;
}