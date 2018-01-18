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

const int M=1024*110;
const int N=1024;
char str[111];

struct DLX
{
	int l[M], r[M], d[M], u[M], col[M], row[M], h[N], control[N];
	int dcnt;
	void init(int cols)
	{
		memset(control,0,sizeof(control));
		memset(h,-1,sizeof(h));
		for(int i=0;i<=cols;i++)
		{
			u[i]=d[i]=i;
			l[i]=i-1;
			r[i]=i+1;
		}
		r[cols]=0;l[0]=cols;
		dcnt = cols;
	}

	void remove(int c)
	{
	    l[r[c]]=l[c];
	    r[l[c]]=r[c];

	    for(int i=d[c];i!=c;i=d[i])
	        for(int j=r[i];j!=i;j=r[j])
	        {
	            u[d[j]]=u[j];
	            d[u[j]]=d[j];
	            control[col[j]]--;
	        }
	}

	void resume(int c)
	{
	    for(int i=u[c];i!=c;i=u[i])
	        for(int j=l[i];j!=i;j=l[j])
	            control[col[u[d[j]]=d[u[j]]=j]]++;
        r[l[c]]=l[r[c]]=c;
	}

	bool dance(int deep)
	{
	    if(r[0]==0)
	    {
	        puts(str);
	        return true;
	    }

	    int tempc=r[0];
	    for(int i=r[0];i!=0;i=r[i])
			if(control[i]<control[tempc])
	        	tempc=i;
	    remove(tempc);
	    for(int i=d[tempc];i!=tempc;i=d[i])
	    {
	        str[row[i]/9]=row[i]%9+'1';
	        for(int j=r[i];j!=i;j=r[j]) remove(col[j]);
	        if(dance(deep+1)) return true;
	        for(int j=l[i];j!=i;j=l[j]) resume(col[j]);
	    }
	    resume(tempc);
	    return false;
	}

	inline void link(int x, int y)
	{
		++control[col[++dcnt]=y];
		row[dcnt]=x;
		d[dcnt]=d[y];
		u[d[y]]=dcnt;
		u[dcnt]=y;
		d[y]= dcnt;
		if(h[x]<0)
			h[x]=l[dcnt]=r[dcnt]=dcnt;
		else
		{
			r[dcnt]=r[h[x]];
			l[r[h[x]]]=dcnt;
			l[dcnt]=h[x];
			r[h[x]]=dcnt;
		}
	}
}dlx;


int main()
{
//	freopen("data.txt","r",stdin);
    while(~scanf("%s", str) && strcmp(str, "end")!=0)
    {
        dlx.init(4*9*9);
        for(int i=0;i<9;i++)
			for(int j=0;j<9;j++)
	            for(int k=1;k<=9;k++)
					if(str[i*9+j]=='.' || str[i*9+j]=='0'+k)
		            {
		                int rr=i*9*9+j*9+k-1;
		                dlx.link(rr, 81*0+i*9+k);
		                dlx.link(rr, 81*1+j*9+k);
		                dlx.link(rr, 81*2+(i/3+j/3*3)*9+k);
		                dlx.link(rr, 81*3+i*9+j+1);
		            }
        dlx.dance(0);
    }
}
