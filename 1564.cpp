#include<stdio.h>
#include<string.h>

int main()
{
	int n;
	int i,j;
	int xuefen;char chengji[4];int score;
	double sum=0,ave;
	int total=0;
	char dengji[11][4]={"A+","A","A-","B+","B","B-","C+","C","C-","D","F"};
	int scores[11]={95, 90, 85, 81, 78, 75, 72, 68, 64, 60, 0};
	double jidian[11]={4.0, 4.0, 3.7, 3.3, 3.0, 2.7, 2.3, 2.0, 1.7, 1.0, 0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&xuefen);
		scanf("%s",chengji);
		total+=xuefen;
		if(chengji[0]<='9'&&chengji[0]>='0')
		{
			if(strlen(chengji)==1)score=chengji[0]-'0';
			else if(strlen(chengji)==3)score=100;
			else score=(chengji[0]-'0')*10+chengji[1]-'0';
			for(j=0;j<11;j++)
			{
				if(score>=scores[j]){
			    	sum+=xuefen*jidian[j];
			    	break;
				}
			}
		}
		else
		for(j=0;j<11;j++)
		{
			if(strcmp(dengji[j],chengji)==0)
			{
				sum+=xuefen*jidian[j];
				break;
			}
		}
	}
	ave=sum/total;
	printf("%.3f\n",ave);
	return 0;
}
