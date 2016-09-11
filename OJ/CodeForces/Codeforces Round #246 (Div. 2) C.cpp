#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;

const int MAXN=100005;

int p[MAXN],top=1,a[MAXN],b[MAXN];
bool pan[MAXN];
int n,ans[5*MAXN][2];


void prime(int n)
{
	for(int i=2;i<=n;i++)
        if(!pan[i])
        	for(int j=i*2;j<=n;j+=i)
            	pan[j]=1;
}

int main()
{
	scanf("%d",&n);
	prime(n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
		p[a[i]]=i;	
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
        while(p[b[i]]!=i)
		{
            for(int j=i;j<p[b[i]];j++) 
			{
                if(!pan[p[b[i]]-j+1])
				{
                    ans[top][1]=p[b[i]];
                    ans[top++][0]=j;

                    int t=p[b[i]];
                    p[b[i]]=j;
                    p[a[j]]=t;
                    swap(a[j],a[t]);
                    break;
                }
            }
        }
    }
	printf("%d\n",--top);
	for(int i=1;i<=top;i++)
		printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
} 