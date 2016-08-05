#include <stdio.h>
#include <stdlib.h>
using namespace std;

int T,N,n,m,i,j,k,l;
int a[35][35],id[35][35];
int A[905],C[905],b[905][905],c[905][905];

int main()
{
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%d%d",&n,&m);
		N=0;
		for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		scanf("%d",&a[i][j]),id[i][j]=++N;
		for(i=1;i<=N;++i)
		for(j=i;j<=N;++j)
		b[i][j]=0;
		for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		{
			for(k=1;k<=N;++k)A[k]=C[k]=0;
			A[id[i][j]]=2;C[id[i][j]]=1;
			if(i>1)A[id[i-1][j]]=1;
			if(j>1)A[id[i][j-1]]=1;
			if(i<n)A[id[i+1][j]]=1;
			if(j<m)A[id[i][j+1]]=1;
			for(k=1;k<=N;++k)
			if(A[k])
			{
				if(!b[k][k])
				{
					for(l=1;l<=N;++l)b[k][l]=A[l],c[k][l]=C[l];
					break;
				}
				for(;A[k];)
				for(l=1;l<=N;++l)
				{
					A[l]+=b[k][l];if(A[l]>=3)A[l]-=3;
					C[l]+=c[k][l];if(C[l]>=3)C[l]-=3;
				}
			}
		}
		for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		A[id[i][j]]=a[i][j];
		for(i=1;i<=N;++i)C[i]=0;
		for(i=1;i<=N;++i)
		if(A[i])
		{
			if(!b[i][i])break;
			for(;A[i];)
			for(j=1;j<=N;++j)
			{
				A[j]+=b[i][j];if(A[j]>=3)A[j]-=3;
				C[j]+=c[i][j];if(C[j]>=3)C[j]-=3;
			}
		}
		k=0;
		for(i=1;i<=N;++i)k+=C[i];
		printf("%d\n",k);
		for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		for(;C[id[i][j]];--C[id[i][j]])
		printf("%d %d\n",i,j);
	}
}
