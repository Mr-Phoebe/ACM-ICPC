#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int map[200][200];
double a[200][200],b[200][200];
int n,sum;

int main()
{
//	freopen("data.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>map[i][j];
			if(i==j)
			{
				a[i][j]=(double)map[i][j];
				b[i][j]=0.0;
			}
		}	
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			a[i][j]=a[j][i]=((double)map[i][j]+(double)map[j][i])/2;
			b[i][j]=(double)map[i][j]-a[i][j];
			if(fabs(b[i][j])<1e-9)
				b[j][i]=b[i][j];
			else
				b[j][i]=-b[i][j];
		}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j)
				printf(" ");
			printf("%.8lf",a[i][j]);
		}
		puts("");	
	}	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j)
				printf(" ");
			printf("%.8lf",b[i][j]);
		}
		puts("");	
	}	
	return 0;
} 
