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
const int N = 9; //3*3Êý¶À
const int MaxN = N*N*N + 10;
const int MaxM = N*N*4 + 10;
const int maxnode = MaxN*4 + MaxM + 10;
char g[MaxN];
int cnt;
struct DLX
{
	int n,m,size;
	int U[maxnode],D[maxnode],R[maxnode],L[maxnode],Row[maxnode],Col[maxnode];
	int H[MaxN],S[MaxM];
	int ansd,ans[MaxN];
	void init(int _n,int _m)
	{
		n = _n;
		m = _m;
		for(int i = 0;i <= m;i++)
		{
			S[i] = 0;
			U[i] = D[i] = i;
			L[i] = i-1;
			R[i] = i+1;
		}
		R[m] = 0; L[0] = m;
		size = m;
		for(int i = 1;i <= n;i++)H[i] = -1;
	}
	void Link(int r,int c)
	{
		++S[Col[++size]=c];
		Row[size] = r;
		D[size] = D[c];
		U[D[c]] = size;
		U[size] = c;
		D[c] = size;
		if(H[r] < 0)H[r] = L[size] = R[size] = size;
		else
		{
			R[size] = R[H[r]];
			L[R[H[r]]] = size;
			L[size] = H[r];
			R[H[r]] = size;
		}
	}
	void remove(int c)
	{
		L[R[c]] = L[c]; R[L[c]] = R[c];
		for(int i = D[c];i != c;i = D[i])
			for(int j = R[i];j != i;j = R[j])
			{
				U[D[j]] = U[j];
				D[U[j]] = D[j];
				--S[Col[j]];
			}
	}
	void resume(int c)
	{
		for(int i = U[c];i != c;i = U[i])
			for(int j = L[i];j != i;j = L[j])
				++S[Col[U[D[j]]=D[U[j]]=j]];
		L[R[c]] = R[L[c]] = c;
	}
	void Dance(int d)
	{
		if(cnt > 1)return;
		if(R[0] == 0)
		{
			for(int i = 0;i < d;i++)g[(ans[i]-1)/9] = (ans[i]-1)%9 + '1';
			cnt++;
			return;
		}
		int c = R[0];
		for(int i = R[0];i != 0;i = R[i])
			if(S[i] < S[c])
				c = i;
		remove(c);
		for(int i = D[c];i != c;i = D[i])
		{
			ans[d] = Row[i];
			for(int j = R[i];j != i;j = R[j])remove(Col[j]);
			Dance(d+1);
			if(cnt > 1)return;
			for(int j = L[i];j != i;j = L[j])resume(Col[j]);
		}
		resume(c);
	}
};

int id[20][20];
int a[20][20];
void bfs(int sx,int sy,int d)
{
	queue<pair<int,int> >q;
	q.push(make_pair(sx,sy));
	id[sx][sy] = d;
	while(!q.empty())
	{
		pair<int,int> tmp = q.front();
		int x = tmp.first;
		int y = tmp.second;
		q.pop();
		if(x > 0 && ((a[x][y]%32)/16) == 0)
			if(id[x-1][y] == -1)
			{
				id[x-1][y] = d;
				q.push(make_pair(x-1,y));
			}
		if(x < N-1 && ((a[x][y]%128)/64) == 0)
			if(id[x+1][y] == -1)
			{
				id[x+1][y] = d;
				q.push(make_pair(x+1,y));
			}
		if(y > 0 && ((a[x][y])/128) == 0)
			if(id[x][y-1] == -1)
			{
				id[x][y-1] = d;
				q.push(make_pair(x,y-1));
			}
		if(y < N-1 && ((a[x][y]%64)/32) == 0)
			if(id[x][y+1] == -1)
			{
				id[x][y+1] = d;
				q.push(make_pair(x,y+1));
			}
	}
}
DLX dlx;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	int iCase = 0;
	while(T--)
	{
		iCase++;
		for(int i = 0;i < N;i++)
			for(int j = 0;j < N;j++)
				scanf("%d",&a[i][j]);
		memset(id,-1,sizeof(id));
		int index = 0;
		for(int i = 0;i < N;i++)
			for(int j = 0;j < N;j++)
				if(id[i][j] == -1)
					bfs(i,j,++index);
		dlx.init(N*N*N,N*N*4);
		for(int i = 0;i < N;i++)
			for(int j = 0;j < N;j++)
				for(int k = 1;k <= N;k++)
				{
					if(a[i][j]%16 != 0 && a[i][j]%16 != k)continue;
					int r = (i*N+j)*N + k;
					int c1 = i*N+j+1;
					int c2 = N*N+i*N+k;
					int c3 = N*N*2+j*N+k;
					int c4 = N*N*3+(id[i][j]-1)*N+k;
					dlx.Link(r,c1);
					dlx.Link(r,c2);
					dlx.Link(r,c3);
					dlx.Link(r,c4);
				}
		cnt = 0;
		dlx.Dance(0);
		printf("Case %d:\n",iCase);
		if(cnt == 0)printf("No solution\n");
		else if(cnt > 1)printf("Multiple Solutions\n");
		else
		{
			for(int i = 0;i < N*N;i++)
			{
				printf("%c",g[i]);
				if(i % N == N - 1)
					printf("\n");
			}
		}
	}
    return 0;
}