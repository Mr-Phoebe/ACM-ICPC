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
//-----------------------------------

const int N=16;
const int maxn=N*N;
const int maxm=N*N;
const int maxnode=maxn*maxm+10;
int n,m,n1,m1;
int ma[N][N];

struct DLX
{
    int n,m,size;
    int U[maxnode],D[maxnode],R[maxnode],L[maxnode],Row[maxnode],Col[maxnode];
    int H[maxn],S[maxn];
    int ansd,ans[maxn];

    void init(int _n,int _m)
    {
        n=_n;
        m=_m;
        for(int i=0;i<=m;i++)
        {
            S[i]=0;
            U[i]=D[i]=i;
            L[i]=i-1;
            R[i]=i+1;
        }
        R[m]=0,L[0]=m;
        size=m;
        for(int i=1;i<=n;i++)
            H[i]=-1;
    }

    void link(int r,int c)
    {
        ++S[Col[++size]=c];
        Row[size]=r;
        D[size]=D[c];
        U[D[c]]=size;
        U[size]=c;
        D[c]=size;
        if(H[r]<0)
            H[r]=L[size]=R[size]=size;
        else
        {
            R[size]=R[H[r]];
            L[R[H[r]]]=size;
            L[size]=H[r];
            R[H[r]]=size;
        }
    }

    void remove(int c)
    {
        for(int i=D[c];i!=c;i=D[i])
            L[R[i]]=L[i],R[L[i]]=R[i];
    }

    void resume(int c)
    {
        for(int i=U[c];i!=c;i=U[i])
            L[R[i]]=R[L[i]]=i;
    }

    bool v[maxnode];

    int h()
    {
        int ret=0;
        for(int c=R[0];c!=0;c=R[c])
            v[c]=true;
        for(int c=R[0];c!=0;c=R[c])
            if(v[c])
        {
            ret++;
            v[c]=false;
            for(int i=D[c];i!=c;i=D[i])
                for(int j=R[i];j!=i;j=R[j])
                v[Col[j]]=false;
        }
        return ret;
    }

    void dance(int d)
    {
        if(d+h()>=ansd)
            return ;
        if(R[0]==0)
        {
            if(ansd>d)
                ansd=d;
            return ;
        }
        int c=R[0];
        for(int i=R[0];i!=0;i=R[i])
            if(S[i]<S[c])
            c=i;
        for(int i=D[c];i!=c;i=D[i])
        {
            remove(i);
            for(int j=R[i];j!=i;j=R[j])
                remove(j);
            dance(d+1);
            for(int j=L[i];j!=i;j=L[j])
                resume(j);
            resume(i);
        }
    }
}x;


int main()
{
	freopen("data.txt","r",stdin);
    while(read(n)&&read(m))
    {
        int size=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
	        {
	            read(ma[i][j]);
	            if(ma[i][j])
	                ma[i][j]=(++size);
	        }
        read(n1),read(m1);
        x.init((n-n1+1)*(m-m1+1),size);
        size=1;
        for(int i=1;i<=n-n1+1;i++)
            for(int j=1;j<=m-m1+1;j++)
	        {
	            for(int ii=0;ii<n1&&i+ii<=n;ii++)
	                for(int jj=0;jj<m1&&j+jj<=m;jj++)
			                if(ma[i+ii][j+jj])
			                    x.link(size,ma[i+ii][j+jj]);
	            size++;
	        }
        x.ansd=INF;
        x.dance(0);
        printf("%d\n",x.ansd);

    }
    return 0;
}
