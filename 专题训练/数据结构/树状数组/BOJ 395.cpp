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
#define lowbit(x) x&(-x)

using namespace std;

const int MAXN=100010;
vector<int> head[MAXN];
int n,ans[MAXN];
bool vis[MAXN];
int c[MAXN]; //ê÷×′êy×é

struct Con
{
	int va,num;
}a[MAXN];//à?é￠?ˉ
int tot=0,now[MAXN];//now表述压缩过的value，角标相同


void update(int i,int v)
{
	for(;i<=tot;i+=lowbit(i))
		c[i]+=v;
}

int getsum(int i)
{
	int sum=0;
	for(;i>0;i-=lowbit(i))
		sum+=c[i];
	return sum;
}

void add(int a,int b)
{
    head[a].push_back(b);
    head[b].push_back(a);
}

void dfs(int x)
{
	vis[x]=true;
	update(now[x],1);
    ans[x]=getsum(tot)-getsum(now[x]);
	for(int i=0;i<head[x].size();i++)
    {
        int temp=head[x][i];
        if(!vis[temp])
            dfs(temp);
    }
    update(now[x],-1);
    return ;
}

bool cmp(Con a,Con b)
{
    return a.va<b.va;
}

void compress()
{
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(a[i].va==a[i-1].va&&i!=1)
            now[a[i].num]=tot;
        else
            now[a[i].num]=++tot;
    }

}

void init()
{
    memset(ans,0,sizeof(ans));
    memset(c,0,sizeof(c));
    memset(vis,0,sizeof(vis));
    memset(now,0,sizeof(now));
    for(int i=0;i<=n;i++)
        head[i].clear();
	tot=0;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		init();
		for(int i=1;i<n;i++)
        {
        	int a,b;
            scanf("%d %d",&a,&b);
            add(a,b);
        }
        for(int i=1;i<=n;i++)
        {
            int value;
            scanf("%d",&value);
            a[i].num=i;a[i].va=value;
        }
        compress();
        dfs(1);
        for(int i=1;i<=n;i++)
            printf("%d\n",ans[i]);
	}
	return 0;
}
