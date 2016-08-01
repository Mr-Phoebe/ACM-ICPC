#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<set>
using namespace std;
typedef long long lld;
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define maxn 510
#define mod 10007
struct Edge
{
	int u,v,next;
	bool flag;
}edge[100010];
int head[maxn];
int pos;
void insert(int x,int y)
{
	edge[pos].u=x;
	edge[pos].v=y;
	edge[pos].flag=true;
	edge[pos].next=head[x];
	head[x]=pos++;
}
int n;
int size[maxn];
int big[maxn];
int total;
void ddd(int now,int pre)
{
	size[now]=1;
	big[now]=0;
	for(int i=head[now];i;i=edge[i].next)
	{
		int v=edge[i].v;
		if(v == pre)
			continue;
		ddd(v,now);
		size[now]+=size[v];
		big[now]=max(big[now],size[v]);
	}
	big[now]=max(big[now],total-size[now]);
}
int dp[maxn][maxn];
int save[maxn];
void dfs(int now,int pre)
{
	for(int i=0;i<=n;i++)
		dp[now][i]=0;
	dp[now][0]=1;
	int T=0;
	for(int i=head[now];i;i=edge[i].next)
	{
		if(!edge[i].flag)
			continue;
		int v=edge[i].v;
		if(v == pre)
			continue;
		dfs(v,now);
		for(int a=0;a<=n;a++)
			save[a]=0;
		for(int a=0;a<=T;a++)
			for(int b=0;b<=size[v];b++)
			{
				int add=(dp[now][a]*dp[v][b])%mod;
				save[a+b]=(save[a+b]+add)%mod;
			}
		for(int a=0;a<=n;a++)
			dp[now][a]=save[a];
		T+=size[v];
	}
	for(int i=n;i>=0;i--)
		dp[now][i+1]=dp[now][i];
	dp[now][0]=1;
}
vector<int>g;
int f[2][maxn];
int main()
{
	int cas;
	scanf("%d",&cas);
	for(int cc=1;cc<=cas;cc++)
	{
		printf("Case %d: ",cc);
		scanf("%d",&n);
		total=n;
		memset(head,0,sizeof(head));
		pos=1;
		for(int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			insert(x,y);
			insert(y,x);
		}
		ddd(1,-1);
		g.clear();
		g.pb(1);
		for(int i=2;i<=n;i++)
		{
			if(big[i] < big[g[0]])
			{
				g.clear();
				g.pb(i);
			}
			else if(big[i] == big[g[0]])
				g.pb(i);
		}
		if((int)g.size() == 1)
		{
			int rt=g[0];
			ddd(rt,-1);
			dfs(rt,-1);
			g.clear();
			for(int i=head[rt];i;i=edge[i].next)
				g.pb(edge[i].v);
			int ans=1;
			int len=g.size();
			for(int i=0;i<len;i++)
			{
				int x=g[i];
				int T=0;
				for(int j=0;j<=n;j++)
					T=(T+dp[x][j])%mod;
				ans=(ans*T)%mod;
			}
			for(int i=0;i<len;i++)
			{
				int x=g[i];
				int T=0;
				int now=0;
				int pre=1;
				memset(f,0,sizeof(f));
				f[now][0]=1;
				for(int j=0;j<len;j++)
				{
					if(i == j)
						continue;
					int y=g[j];
					now^=1;
					pre^=1;
					for(int a=0;a<=n;a++)
						f[now][a]=0;
					for(int a=0;a<=T;a++)
						for(int b=0;b<=size[y];b++)
						{
							f[now][a+b]+=f[pre][a]*dp[y][b];
							f[now][a+b]%=mod;
						}
					T+=size[y];
				}
				int sum=0;
				for(int j=1;j<=n;j++)
				{
					sum=(sum+f[now][j-1])%mod;
					int add=(dp[x][j]*sum)%mod;
					ans=(ans-add+mod)%mod;
				}
			}
			printf("%d\n",ans);
		}
		else
		{
			int x=g[0];
			int y=g[1];
			for(int i=1;i<pos;i++)
			{
				if(edge[i].u == x && edge[i].v == y)
					edge[i].flag=false;
				if(edge[i].u == y && edge[i].v == x)
					edge[i].flag=false;
			}
			dfs(x,-1);
			dfs(y,-1);
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				int add=(dp[x][i]*dp[y][i])%mod;
				ans=(ans+add)%mod;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
