#include<stdio.h>


int main()
{
	int n;int i,j;
	int a[6];
	double b[6]={50, 10, 5, 1, 0.5, 0.1};
	int money=0;
	double rest=100;
	scanf("%d",&n);
	rest-=2.5*n;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<6;i++)
	{
		if(rest>a[i]*b[i])
		{
			rest-=a[i]*b[i];
			money+=a[i];
		}
		else{
			j=(int)(rest/b[i]);
			rest-=b[i]*j;
			money+=j;
		}
	}
	printf("%d\n",money);
	return 0;
}