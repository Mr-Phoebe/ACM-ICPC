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
#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

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

bool vis[16][16];
char s[16][16];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int num;

bool in(int x,int y,char t)
{
	return x>=0 && y>=0 && x<10 && y<15 && s[x][y]==t;
}

bool empty(int j)
{
	for(int i=0;i<10;i++)
		if(s[i][j])
			return 0;
	return 1;
}


void print()
{
	for(int i = 9; i >=0; i--) {
		for(int j = 0; j < 15; j++)
			putchar(s[i][j] ? s[i][j] : ' ');
		putchar(10);
	}
	puts("---------------");
}

void dfs(int x,int y,char t)
{
	vis[x][y]=1;
	num++;
	for(int i=0;i<4;i++)
	{
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(!vis[xx][yy] && in(xx,yy,t))
			dfs(xx,yy,t);
	}
}

void dfs2(int x,int y,char t)
{
	s[x][y]='\0';
	for(int i=0;i<4;i++)
	{
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(in(xx,yy,t))
			dfs2(xx,yy,t);
	}
}

void move()
{
	for(int j=0;j<15;j++)
	{
		int num=0;
		for(int i=0;i<10;i++)
			if(s[i][j])
				s[num++][j]=s[i][j];
		for(int i=num;i<10;i++)
			s[i][j]='\0';
	}
	int num=0;
	for(int j=0;j<15;j++)
		if(!empty(j))
		{
			for(int i=0;i<10;i++)
				s[i][num]=s[i][j];
			num++;
		}
	for(int j=num;j<15;j++)
		for(int i=0;i<10;i++)
			s[i][j]='\0';		
}

int main()
{
//	freopen("data.txt","r",stdin);
	int T,cas=0;
	scanf("%d\n",&T);
	while(T--)
	{
		if(cas)
			putchar('\n');
		for(int i=9;i>=0;i--)
			scanf("%s",s[i]);
		int tot=0,sc=0,mo=1;
		printf("Game %d:\n\n",++cas);
		while(1)
		{
			CLR(vis,0);
			int maxx=-INF,sx,sy;
			for(int j=0;j<15;j++)
				for(int i=0;i<10;i++)
					if(!vis[i][j] && s[i][j])
					{
						num=0;
						dfs(i,j,s[i][j]);
						if(num>maxx)
						{
							sx=i;sy=j;
							maxx=num;
						}
					}	
			if(maxx<2)
				break;
			printf("Move %d at (%d,%d): ",mo++,sx+1,sy+1);
			printf("removed %d balls of color %c, ",maxx,s[sx][sy]);
			printf("got %d points.\n", (maxx-2)*(maxx-2));
			sc+=(maxx-2)*(maxx-2);
			tot+=maxx;
			if(tot==150)
			{
				sc+=1000;
				break;
			}
			dfs2(sx,sy,s[sx][sy]);
			move();
		}
		printf("Final score: %d, with %d balls remaining.\n", sc, 150-tot);
	}
	return 0;
}