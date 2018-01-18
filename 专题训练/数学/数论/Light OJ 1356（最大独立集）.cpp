//      whn6325689
//		Mr.Phoebe
//		http://blog.csdn.net/u013007900
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
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")


using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))
#define MID(x,y) (x+((y-x)>>1))
#define speed std::ios::sync_with_stdio(false);
#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
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
//-----------------------------------]

const int MAXN=500010;

int n,a[40010],pos[MAXN];
int is[MAXN],prime[45000],cnt;
int p[40010],num[40010];

struct Edge
{
	int to,next;
}e[80010];
int head[40010],tot;

void addedge(int u,int v)
{
	e[tot].to=v;
	e[tot].next=head[u];
	head[u]=tot++;
}

int cx[40010],cy[40010];  
int dx[40010],dy[40010];  
int dis;

bool bfs()  
{  
    dis = INF;  
    CLR(dx,-1);  
    CLR(dy,-1);  
    queue <int> Q;  
    for(int i=1; i<=n; i++)  
    {  
        if(cx[i]==-1 && (num[i]&1))  
        {  
            Q.push(i);  
            dx[i]=0;  
        }  
    }  
    while(!Q.empty())  
    {  
        int u=Q.front(); Q.pop();  
        if(dx[u] > dis)  
            break;  
        for(int i=head[u]; ~i; i=e[i].next)  
        {  
            int v=e[i].to;  
            if(dy[v]==-1)  
            {  
                dy[v]=dx[u]+1;  
                if(cy[v]==-1)
                    dis = dy[v]; 
                else  
                {  
                    dx[cy[v]]=dy[v]+1;  
                    Q.push(cy[v]);  
                }  
            }  
        }  
    }  
    return dis != INF;  
}  
  
bool dfs(int u)  
{  
    for(int i=head[u]; ~i; i=e[i].next)  
    {  
        int v=e[i].to;  
        if(dy[v]==dx[u]+1)  
        {  
            dy[v]=0;  
            if(cy[v]==-1 || dfs(cy[v]))  
            {  
                cx[u]=v;  
                cy[v]=u;  
                return true;  
            }  
        }  
    }  
    return false;  
}  
int match()  
{  
    int ans=0;  
    CLR(cx,-1);  
    CLR(cy,-1);  
    while(bfs())  
    {  
        for(int i=1; i<=n; i++)  
            if(cx[i]==-1 && (num[i]&1) && dfs(i))  
                ans++;  
    }  
    return ans;  
}  


void init()
{
	for(int i=2;i<MAXN;i++)
	{
		if(is[i])	continue;
		prime[cnt++]=i;
		for(int j=i+i;j<MAXN;j+=i)
			is[j]=1;
	}
}

int main()
{
//	freopen("data.txt","r",stdin);
	init();
	int T,cas=1;
	read(T);
	while(T--)
	{
		CLR(head,-1);tot=0;
		CLR(pos,0); 
		read(n);
		for(int i=1;i<=n;i++)
			read(a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			pos[a[i]]=i;
		for(int i=1; i<=n; i++)  
        {  
            int x=a[i];  
            int sum=0,sum2=0;  
            for(int j=0; j<cnt && prime[j]*prime[j]<=x; j++)  
            {  
                if(x%prime[j]==0)  
                {  
                    p[sum++]=prime[j];  
                    while(x%prime[j]==0)  
                    {  
                        x/=prime[j];  
                        sum2++;  
                    }  
                }  
            }  
            if(x>1)  
            {  
                p[sum++]=x;  
                sum2++;  
            }  
            num[i]=sum2; 
            for(int j=0; j<sum; j++)  
            {  
                int temp=pos[a[i]/p[j]];  
                if(temp>i)  
                    continue;  
                if(temp)  
                {  
                    if((sum2&1)==(num[temp]&1))  
                        continue;             
                    if((sum2&1))  
                        addedge(i,temp);  
                    else  
                        addedge(temp,i);  
                }  
            }  
        }
        int ans=match();  
        printf("Case %d: %d\n",cas++,n-ans);  
	}
	return 0;
} 