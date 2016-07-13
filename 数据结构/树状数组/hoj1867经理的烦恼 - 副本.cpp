//hoj 1867 经理的烦恼 一维树状数组
#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 1000005

int C[N],A[N];
int c,n,m;

int lowbit(int x)
{
	return x&(x^(x-1));
}

void update(int k,int delta)
{
	int i;

	for (i=k;i<=c;i+=lowbit(i))
		C[i]+=delta;
}

int getSum(int k)
{
	int result=0,i;

	for (i=k;i>0;i-=lowbit(i))
		result+=C[i];
	return result;
}

int isPrime(int x)
{
	int i;

	if (x<=1) return 0;
	for (i=2;i<=sqrt(x);i++)
		if (x%i==0) return 0;
	return 1;
}

int main()
{
	int x,y,Ins,i,count=1;

	freopen("data.txt","r",stdin);

	while(scanf("%d %d %d",&c,&n,&m))
	{
		if (c==0&&n==0&&m==0) break;
		for (i=1;i<=c;i++)
			A[i]=m;
		memset(C,0,sizeof(C));
		if (isPrime(m))
			for (i=1;i<=c;i++)
				update(i,1);	
        printf("CASE #%d:\n",count++);
		for (i=1;i<=n;i++)
		{
			scanf("%d %d %d",&Ins,&x,&y);
			if (Ins==0)
			{
				A[x]+=y;
				if ((!isPrime(A[x]-y))&&(isPrime(A[x])))
					update(x,1);
				else if((isPrime(A[x]-y))&&(!isPrime(A[x])))
					update(x,-1);
			}
			if (Ins==1)
				printf("%d\n",getSum(y)-getSum(x-1));
		}
		printf("\n");
	}
}