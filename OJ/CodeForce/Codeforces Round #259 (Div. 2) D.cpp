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

const int MAXN=111;
int bin[20]={1};
int n,cnt,m,ans=0;;
int f[MAXN][1<<16],num[105][1<<16];
int v[MAXN],q[MAXN],a[60];
int prime[50]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

inline int cal(int x)
{
    int sum=0;
    for(int i=0;i<16;i++)
        if(x%prime[i]==0)
			sum|=bin[i];
    return sum;
}

void init()
{
	for(int i=1;i<20;i++)
		bin[i]=bin[i-1]<<1;//状压 
    for(int i=1;i<59;i++)
		a[i]=cal(i);       //状压因数 
    memset(f,-1,sizeof(f));
    m=(1<<16)-1;
    f[0][0]=0;
}

int main()
{
	init();
    read(n);
    for(int i=1;i<=n;i++)
		read(v[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<=ed;j++)
            if(f[i][j]!=-1)
                for(int k=1;k<59;k++)
                {
                    int to=j+a[k],t=f[i][j]+abs(k-v[i+1]);
                    if((j|a[k])==to&&(t<f[i+1][to]||f[i+1][to]==-1))//公约数为 1 且绝对值最小 
                    {
                        f[i+1][to]=t;
                        num[i+1][to]=k;
                    }
                }
    int minn=INF,po=0;
    for(int i=0;i<=m;i++)
        if(f[n][i]!=-1&&f[n][i]<minn)
        {
            po=i;minn=f[n][i];
        }
    for(int i=n;i>0;po-=a[q[i--]])
        q[i]=num[i][po];
    for(int i=1;i<=n;i++)
        printf("%d ",q[i]);
    return 0;
}