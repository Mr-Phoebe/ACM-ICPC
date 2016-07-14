#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int f[111][111];
const int maxn=11111111;
int mi=maxn,po=1;

void floyd(int n)
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(f[i][j]>f[i][k]+f[k][j])
					f[i][j]=f[i][k]+f[k][j];
	return;
}

int main()
{
	int n;
//	freopen("data.txt","r",stdin);
	while(scanf("%d",&n)&&n!=0)
	{
		int m;
		po=0;mi=maxn;
		for(int i=0;i<111;i++)
			for(int j=0;j<111;j++)
				f[i][j]=maxn;	
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(int j=1;j<=n;j++)
				f[j][j]=0;
			for(int j=0;j<m;j++)
			{
				int temp,t;
				scanf("%d %d",&temp,&t);
				f[i][temp]=t;
			}
		}	
		floyd(n);
	/*	for(int k=1;k<=n;k++)
		{
			for(int j=1;j<=n;j++)
				cout<<f[k][j]<<" ";
			cout<<"\t"<<k<<endl;
		}	 */
		int num=0;
		for(int k=1;k<=n;k++)
		{
			int j;num=0;
			for(j=1;j<=n;j++)
				if(f[k][j]>num)
					num=f[k][j];	
			if(num<mi)
			{
				mi=num;
				po=k;
			}	
		}
		printf("%d %d\n",po,mi);
	}
	return 0;
} 