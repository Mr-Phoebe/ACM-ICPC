#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int MAXN=1010;
int c[MAXN][MAXN],n;

inline int lowbit(int x)
{
	return x&(-x);
}

void update(int x,int y)
{
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
			c[i][j]^=1;
}

int getsum(int x,int y)
{
	int sum=0;
	for(int i=x;i<MAXN;i+=lowbit(i))
		for(int j=y;j<MAXN;j+=lowbit(j))
			sum+=c[i][j];
	return sum%2;
}


int main()
{
	int T,q;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d\n",&n,&q);
		memset(c,0,sizeof(c)); 
		while(q--)
		{
			char ch=getchar();
			if(ch=='Q')
			{
				int x,y;
				scanf("%d %d",&x,&y);
				printf("%d\n",getsum(x,y));
			}	
			else
			{
				int x1,y1,x2,y2;
				scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                update(--x1,--y1);
                update(x1,y2);
                update(x2,y1);
                update(x2,y2);
			}
			getchar();
		}
		puts("");
	}
	return 0;
}