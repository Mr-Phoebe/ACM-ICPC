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
#define mp(x,y) make_pair(x,y)
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

struct node
{
    double a,b,c;
    double num(double x)
    {
    	return a*x*x +b*x+c;
    }
}q[10010];

int n;

double S(double x)
{
    double maxt=-INF;
    for(int i=0; i<n; i++)
    {
        double temp=q[i].num(x);
        if(temp>maxt)
            maxt=temp;
    }
    return maxt;
}

int main()
{
    int T;
    read(T);
    while(T--)
    {
        read(n);
        for(int i=0; i<n; i++)
            scanf("%lf %lf %lf",&q[i].a,&q[i].b,&q[i].c);
        double ans_mid,ans_mid_mid;
    	double left=0.0,right=1000.0,mid,mid_mid;
        while(right>eps+left)
        {
            mid=(right+left)/2;
            ans_mid=S(mid);
            mid_mid=(mid+right)/2;
            ans_mid_mid=S(mid_mid);
            if(ans_mid>ans_mid_mid)
                left=mid;
            else
                right=mid_mid;
        }
        printf("%.4f\n",S(right));
    }
    return 0;
}