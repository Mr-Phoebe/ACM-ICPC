#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

const int MAXN=200010;

int n,dp[MAXN];
int fa[MAXN];

int first[MAXN],q[MAXN],po[MAXN],res=1,tot=1;
struct Edge
{
	int u,w;
	int kind;
	int next;
}e[MAXN];


void add(int x,int y,int w,int t)
{
    e[tot].u=y;
    e[tot].w=w;
    e[tot].kind=t;
    e[tot].next=first[x];
    first[x]=tot++;
}

int dfs(int x)
{
	int sum=0;
	for(int i=first[x];i;i=e[i].next)
    {
        int y=e[i].u,w=e[i].w;
        if(!fa[y])
        {
            fa[y]=x;
            if(e[i].kind>=0)
                w=0;
            sum+=w;
            sum+=dfs(y);
        }
    }
    return sum;
}

void DFS(int x)
{
    for(int i=first[x];i;i=e[i].next)
    {
        if(fa[e[i].u]!=x)
            continue;
        dp[e[i].u]=dp[x]+e[i].w*e[i].kind;//cout<<e[i].u<<" "<<dp[e[i].u]<<endl;
        DFS(e[i].u);
    }
    return;
}

int main()
{
//    freopen("data.txt","r",stdin);
	while(scanf("%d",&n)!=EOF)
	{
	    memset(fa,0,sizeof(fa));
	    memset(first,0,sizeof(first));
	    memset(po,0,sizeof(po));
	    memset(q,0,sizeof(q));
	    memset(dp,0,sizeof(dp));
	    res=tot=1;
        int t,u,v,w;
		for(int i=1;i<n;i++)
		{
			scanf("%d %d %d %d",&t,&u,&v,&w);
            if(!q[u])
            {
                q[u]=res;
                po[res++]=u;//cout<<u<<"£º"<<q[u]<<endl;
            }
            if(!q[v])
            {
                q[v]=res;
                po[res++]=v;//cout<<v<<"£º"<<q[v]<<endl;
            }
			add(q[u],q[v],w,t);
			add(q[v],q[u],w,-1*t);
		}
/*		for(int i=1;i<res;i++)
        {
            cout<<q[i]<<" : "<<first[q[i]]<<endl;
            int m=q[i];
            for(int j=first[m];j;j=e[j].next)
                cout<<"     "<<e[j].u<<" "<<e[j].w<<" "<<e[j].kind<<endl;
        }*/
		fa[1]=-1;
		dp[1]=dfs(1);
		DFS(1);
		int k=1,mi=dp[1];
        for(int i=2;i<res;i++)
            if(mi>dp[i])
                mi=dp[i],k=i;
        printf("%d %d\n",po[k],dp[k]);
	}
    return 0;
}
