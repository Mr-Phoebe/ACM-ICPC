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
#define eps 1e-9
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1; char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
//---------------------------------------------

const int MAXN=10010;
const int MOD=1000007;
int dir[4][2]={1,0,0,1,0,-1,-1,0};

struct PATH
{
	int x[MAXN],y[MAXN],c[MAXN];
	int tot;
}path;

struct Map
{
	int d[5][5];
	int co[20];
}mapp;

int ans_flag=0;
int r,c;

inline bool in(int x,int y)
{
	return x>=0&&x<r&&y>=0&&y<c;
}

void path_push(int a,int b,int c)
{
	int t=path.tot;
	path.x[t]=a;path.y[t]=b;path.c[t]=c;
	path.tot++;
}

void print()
{
	int t=path.tot;
	printf("%d\n",t);
	for(int i=0;i<t;i++)
		printf("%d %d %d\n",path.x[i]+1,path.y[i]+1,path.c[i]);
	return;
}

void paint(Map *m,int x,int y,int co,int pre,int flag)
{
	m->d[x][y]=co;
	for(int i=0;i<4;i++)
	{
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(in(xx,yy)&&m->d[xx][yy]==pre)
			paint(m,xx,yy,co,pre,0);
	}
	if(flag)
	{
		memset(m->co,0,sizeof(m->co));
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(m->d[i][j])
					m->co[m->d[i][j]]=1;
	}
	return;
}
inline bool near(Map m,int x,int y,int k)
{
    for(int i=0;i<4;i++)
    {
        int xx=x+dir[i][0];
        int yy=y+dir[i][1];
        if(!in(xx,yy))
			continue;
        if(m.d[xx][yy]==k)
            return true;
    }
    return false;
}

bitset<1000024> vis[25];

int hash(Map m)
{
	long long sum=0;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			sum=(m.d[i][j]+(sum*131)%MOD)%MOD;
	return sum;
}

int getsum(int *co)
{
	int sum=0;
	for(int i=1;i<20;i++)
		if(co[i])
			sum++;
	return sum;
}

void dfs(Map m,int dep,int Mdep)
{
	int sum=getsum(m.co);
	if(dep+sum>Mdep || ans_flag)
		return;
	if(!sum)
	{
		print();ans_flag=1;return;
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			for(int k=0;k<20;k++)
			{
				if(k && !m.co[k] || k==m.d[i][j])
					continue;
				if(k && !near(m,i,j,k))
					continue;
                Map temp=m;
                paint(&temp,i,j,k,m.d[i][j],1);
                int t=hash(temp);
                if(vis[dep+1][t])
                    continue;
                vis[dep+1][t]=1;
                path_push(i,j,k);
                dfs(temp,dep+1,Mdep);
                if(ans_flag)
                    return;
                path.tot--;
			}
		}
	}
}

void IDA()
{
    int maxx=getsum(mapp.co);
    ans_flag=0;
    while(!ans_flag)
    {
        for(int i=0;i<=maxx;i++)
        	vis[i].reset();
        path.tot=0;
        dfs(mapp,0,maxx);
        maxx++;
    }
}

int main()
{
    while(read(r)&&read(c))
    {
        memset(mapp.co,0,sizeof(mapp.co));
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                read(mapp.d[i][j]);
                if(mapp.d[i][j])
                   mapp.co[mapp.d[i][j]]=1;
            }
        IDA();
    }
    return 0;
}
