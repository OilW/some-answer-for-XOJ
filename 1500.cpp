#include<stdio.h>
#include<stdio.h>
#define len 10
/*测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( < 100 )；
随后的N(N-1)/2行对应村庄间的距离，每行给出三个正整数，分别是两个村庄的编号，以及此两村庄间的距离。为简单起见，村庄从1到N编号。
当N为0时，输入结束，该用例不被处理。
对每个测试用例，在一行里输出最小的公路总长度。*/
//Prim

int min1(int s[],int d[],int n)
{
	int v,i;
	v=0;
	for(i=1;i<=n;i++)
		if(!s[i])
		{
			v=i;
			break;
		}
	for(i++;i<=n;i++)
		if(!s[i] && d[i]<d[v])
			v=i;
	return v;
}

int main()
{
	int n;int i,j;int u,v,min,sum;
	int d[len];//表示最短路径的值
	int s[len];//表示是否已经是最短路径
	int way[len][len];int x,y;//表示直接路径。
	for(i=0;i<len;i++)way[i][i]=0;
	scanf("%d",&n);
	while(n){
		for(i=0;i<len;i++){
			d[i]=0;s[i]=0;
		}
		for(i=0;i<n*(n-1)/2;i++)
		{
			scanf("%d %d",&x,&y);
			scanf("%d",&way[x][y]);
			way[y][x]=way[x][y];
		}
/*    	for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				printf("%d ",way[i][j]);
			printf("\n");
		}*/
		u=1;s[u]=1;
	    for(i=1;i<=n;i++)
			d[i]=way[u][i];
		for(i=1;i<=n;i++)
		{
			v=min1(s,d,n);
		//	printf("%d\n",v);
			if(v){
				s[v]=1;
				for(j=1;j<=n;j++)
				{
					if(!s[j] && d[j]>way[v][j])
						d[j]=way[v][j];
				}
			//	for(j=1;j<=n;j++)printf("%d ",d[j]);printf("\n");
			}
		}/**/
		sum=0;
		for(i=1;i<=n;i++)sum+=d[i];
		printf("%d\n",sum);
		scanf("%d",&n);
	}
	return 0;
}
/*3
1 2 1
1 3 2
2 3 4
4
1 2 1
1 3 4
1 4 1
2 3 3
2 4 2
3 4 5
0
*/