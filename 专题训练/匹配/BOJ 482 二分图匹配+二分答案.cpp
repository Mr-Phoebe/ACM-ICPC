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
#define CLR(x,y) memset(x,y,sizeof(x))
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
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
//-----------------------------------

const int MAXN=60;

struct Point
{
	int x,y;
}a[MAXN],b[MAXN];

struct Edge
{
    int to,next;
    int val;
}e[MAXN*MAXN*MAXN];

int n,m,t,t2,v;
double w[MAXN*MAXN][MAXN];
int head[MAXN*MAXN],pre[MAXN*MAXN],idx;
bool vis[MAXN*MAXN];

void add_edge(int u,int v)
{
    e[idx].to=v;
    e[idx].next=head[u];
    head[u]=idx++;
}

void make_graph(double limit)
{
    idx=0;
    CLR(head,-1);
    CLR(pre,-1);
    for(int i=0;i<n*m;i++)
        for(int j=0;j<m;j++)
            if(w[i][j]<=limit)
                add_edge(i,j);
}

bool dfs(int u)
{
    for(int i=head[u];i!=-1;i=e[i].next)
    {
        int v=e[i].to;
        if(!vis[v])
        {
            vis[v]=true;
            if(pre[v]==-1 || dfs(pre[v]))
            {
                pre[v]=u;
                return true;
            }
        }
    }
    return false;
}

double dist(int x,int y,int xx,int yy)
{
    return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy))/(double)v;
}

int main()
{
//    freopen("data.txt","r",stdin);
	while(read(n)&&read(m)&&read(t)&&read(t2)&&read(v))
	{
		double t1=(double)t/60.0;
		for(int i=0;i<m;i++)
            read(b[i].x),read(b[i].y);
		for(int i=0;i<n;i++)
			read(a[i].x),read(a[i].y);
		for(int i=0;i<n;i++)		    //第 I 个炮
		{
			for(int j=0;j<m;j++)        //第 J 个敌人
			{
			    int temp=i*m;
			    w[temp][j]=dist(a[i].x,a[i].y,b[j].x,b[j].y)+t1;  //打到敌人的时间
//			    cout<<i<<" "<<j<<" : "<<dis<<endl;
				for(int k=1;k<m;k++)    //第 K 次开炮
					w[temp+k][j]=w[temp+k-1][j]+t1+t2;
			}
		}
/*
		for(int i=0;i<n*m;i++)
        {
            for(int j=0;j<m;j++)
                cout<<w[i][j]<<" ";
            cout<<endl;
        }
*/
		double b_low=0,b_high=(1<<31)-1,b_mid;
		double ans=0;
		int time=100;
		while(time--)
        {
            b_mid=b_low+(b_high-b_low)/2;
            make_graph(b_mid);
            int temp=0;
            for(int i=0;i<n*m&&temp!=m;i++)
            {
                CLR(vis,0);
                if(dfs(i))
                    temp++;
            }
            if(temp==m)
            {
                ans=b_mid;
                b_high=b_mid;
            }
            else
                b_low=b_mid;
        }
        printf("%.6f\n",ans+1e-7);
	}
	return 0;
}
