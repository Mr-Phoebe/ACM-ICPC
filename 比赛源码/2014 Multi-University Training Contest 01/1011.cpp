#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
#include<ctime>
using namespace std;
const int N = 100005;
const int INF = 1000000007;
typedef pair<int,int> per;
#define mp(x,y) make_pair(x,y)
int n,d[N];
bool u[N];
vector<per>E[N],G[N];
priority_queue<per>q;
void dijkstra()
{
	int i;
	memset(u,0,sizeof(u));
	for(i=1;i<=n;i++)d[i]=INF;
	d[1]=0;
	q.push(mp(0,1));
	int cnt=0,m=0,nt=0;
	while(!q.empty())
	{
		cnt++;
		per fr=q.top();
		q.pop();
		int x=fr.second;
		if(u[x])continue;
		u[x]=true;
		for(i=E[x].size()-1;i>=0;i--)
		{
			m++;
			int j=E[x][i].first;
			if(!u[j]&&d[j]>E[x][i].second+d[x])
			{
				d[j]=E[x][i].second+d[x];
				q.push(mp(-d[j],j));
				nt++;
			}
		}
	}
	//printf("cnt:%d m:%d nt:%d \n",cnt,m,nt);
}
int Q[N*10];
void SPFA()
{
	int i;
	memset(u,0,sizeof(u));
	for(i=1;i<=n;i++)d[i]=INF;
	d[1]=0;
	int t=0,w=1;
	Q[0]=1;
	u[1]=true;
	while(t<w)
	{
		int x=Q[t++];
		u[x]=false;
		for(i=E[x].size()-1;i>=0;i--)
		{
			int j=E[x][i].first;
			if(d[j]>E[x][i].second+d[x])
			{
				d[j]=E[x][i].second+d[x];
				if(!u[j])
				{
					u[j]=true;
					Q[w++]=j;
				}
			}
		}
	}
}
void ddfs(int i)
{
	u[i]=true;
	int sz=E[i].size();
	for(int j=0;j<sz;j++)
	{
		int x=E[i][j].first,y=E[i][j].second;
		if(!u[x]&&d[i]+y==d[x])
		{
			G[i].push_back(mp(x,y));
			G[x].push_back(mp(i,y));
			//printf("%d -> %d %d \n",i,x,y);
			ddfs(x);
		}
	}
}

bool v[N];
int a[N],ds[N],dd[N],son[N],root,sz,k,all,key1[N],r1,K;
__int64 key2[N],r2;
void getson(int x)
{
    v[x]=true;
    son[x]=1;
    for(int i=G[x].size()-1;i>=0;i--)
    {
        int j=G[x][i].first;
        if(!u[j]&&!v[j])
        {
            getson(j);
            son[x]+=son[j];
        }
    }
    v[x]=false;
}
void dfs(int x)
{
    v[x]=true;
    int key=all-son[x];
    for(int i=G[x].size()-1;i>=0;i--)
    {
        int j=G[x][i].first;
        if(!u[j]&&!v[j])
        {
            dfs(j);
            if(key<son[j])key=son[j];
        }
    }
    if(sz>key){sz=key;root=x;}
    v[x]=false;
}
void get(int x,int dis,int dep)
{
    v[x]=true;
	ds[k]=dis;
	dd[k]=dep;
    a[k++]=x;
    for(int i=G[x].size()-1;i>=0;i--)
    {
        int j=G[x][i].first;
        if(!u[j]&&!v[j])
        {
            get(j,dis+G[x][i].second,dep+1);
        }
    }
    v[x]=false;
}
int cr[N];
void work(int x,int dep)
{
    sz=N;
    getson(x);
    all=son[x];
    dfs(x);
    x=root;
	//if(n==100000&&dep<5)printf("x:%d dep:%d \n",x,dep);
	cr[x]=dep;
    u[x]=true;
    int i,j;
    k=0;
	key1[0]=0;
	key2[0]=1;
    for(i=G[x].size()-1;i>=0;i--)
    {
        j=G[x][i].first;
        k=0;
        if(!u[j])get(j,G[x][i].second,1);
        for(int h=0;h<k;h++)
        {
            int nx=a[h],ny=dd[h],nz=ds[h];
			if(ny<=K-1&&key2[K-1-ny])
			{
				if(nz+key1[K-1-ny]>r1)
				{
					r1=nz+key1[K-1-ny];
					r2=key2[K-1-ny];
				}
				else if(nz+key1[K-1-ny]==r1)
				{
					r2+=key2[K-1-ny];
				}
			}
			//printf("j:%d nx:%d ny:%d nz:%d r1:%d r2:%I64d \n",j,nx,ny,nz,r1,r2);
			//求解
        }
        for(int h=0;h<k;h++)
        {
            int nx=a[h],ny=dd[h],nz=ds[h];
			if(key1[ny]<nz)
			{
				key1[ny]=nz;
				key2[ny]=1;
			}
			else if(key1[ny]==nz)
			{
				key2[ny]++;
			}
			//更新
        }
    }
	//printf("r1:%d r2:%I64d \n",r1,r2);
	for(i=G[x].size()-1;i>=0;i--)
    {
        j=G[x][i].first;
        k=0;
        if(!u[j])get(j,G[x][i].second,1);
        for(int h=0;h<k;h++)
        {
            int nx=a[h],ny=dd[h],nz=ds[h];
			key1[ny]=key2[ny]=0;
		}
	}
	key1[0]=key2[0]=0;
    for(i=G[x].size()-1;i>=0;i--)
    {
        j=G[x][i].first;
        if(!u[j])work(j,dep+1);
    }
    u[x]=false;
}

char in[]="0.in";
char out[]="0.out";
int main()
{
	int m,i,T;
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&K);
		//scanf("%d%d%d",&n,&m,&K);
		while(m--)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			E[a].push_back(mp(b,c));
			E[b].push_back(mp(a,c));
		}
		//dijkstra();
		SPFA();
		//for(i=1;i<=n;i++)printf("i:%d d:%d \n",i,d[i]);
		for(i=1;i<=n;i++)sort(E[i].begin(),E[i].end());
		memset(u,0,sizeof(u));
		ddfs(1);
		memset(v,0,sizeof(v));
		memset(u,0,sizeof(u));
		memset(key1,0,sizeof(key1));
		memset(key2,0,sizeof(key2));
		r1=r2=0;
		//puts("enter");
		work(1,0);
		printf("%d %I64d\n",r1,r2);
		for(i=1;i<=n;i++)E[i].clear(),G[i].clear();
	}
	return 0;
}
