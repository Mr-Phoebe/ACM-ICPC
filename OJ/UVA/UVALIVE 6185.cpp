//      whn6325689
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
#define eps 1e-5
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

const int MAXN=10;

double matrix[MAXN][MAXN+1];
double ans[MAXN];
double a[MAXN];


bool gauss(int n)
{
    int i,j,k;
    int p;
    double r;
    for(i=0; i<n-1; i++)
    {
        p=i;
        for(j=i+1; j<n; j++)
            if(abs(matrix[j][i])>abs(matrix[p][i]))
                p=j;
        if(p!=i)
            for(int k=0; k<=n; k++)
        		swap(matrix[i][k],matrix[p][k]);
        if(abs(matrix[i][i])<eps)
			return false;
        for(j=i+1; j<n; j++)
        {
            double tmp=matrix[j][i]/matrix[i][i];
            for(k=i; k<=n; k++)
                matrix[j][k]-=tmp*matrix[i][k];
        }
    }
    for(i=0; i<n; i++)
    {
        ans[i]=matrix[i][n];
        for(j=i+1; j<n; j++)
            ans[i]-=matrix[i][j]*ans[j];
        if(abs(matrix[i][i])<eps)
			return false;
        ans[i]/=matrix[i][i];
    }
    return true;
}

int main()
{
    int d;
    while(read(d)&&d)
    {
        CLR(matrix,0);
        for(int i=0; i<=d+2; i++)
            scanf("%lf",&a[i]);
        for(int k=0; k<=d+2; k++)
        {
            int cnt=0;
            for(int j=0; j<=d+2; j++)
            {
                if(k==j)
					continue;
                matrix[cnt][d+1]=a[j];
                for(int i=0; i<=d; i++)
                    if(!i)
						matrix[cnt][i]=1;
                    else
						matrix[cnt][i]=matrix[cnt][i-1]*j;
                cnt++;
            }
            if(!gauss(d+2))
            {
                write(k),putchar('\n');
                break;
            }
        }
    }
    return 0;
}
