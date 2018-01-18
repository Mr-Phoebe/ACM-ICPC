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

vector<pii> mat;
int a[5010],v[5010],n;
int dp[5010];

int main()
{
	while(read(n)&&n)
    {
        mat.clear();
        for(int i=1;i<=n;i++)
            read(a[i]);
        for(int i=1;i<=n;i++)
            read(v[i]);
        if(n==1)
        {
            putchar('0');putchar('\n');continue;
        }
        int t=0,h=n+1,mid=v[n];
        ll pre=0,beh=0;
        while(t<h)
        {
            if(pre>beh)
                beh+=a[--h];
            else if(pre<beh)
                pre+=a[++t];
            else
            {
                mat.push_back(make_pair(t,h));
                pre+=a[++t],beh+=a[--h];
            }
        }
        for(int i=0;i<mat.size();i++)
        {
            dp[i]=v[mat[i].first-0]+v[n+1-mat[i].second];
            for(int j=1;j<i;j++)
                dp[i]=min(dp[i],dp[j]+v[mat[i].first-mat[j].first]+v[mat[j].second-mat[i].second]);
            mid=min(dp[i]+v[mat[i].second-mat[i].first-1],mid);
        }
        write(mid);putchar('\n');
    }
    return 0;
}
