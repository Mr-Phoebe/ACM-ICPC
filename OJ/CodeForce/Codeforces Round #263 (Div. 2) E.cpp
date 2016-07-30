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
#define lowbit(x) x&(-x)
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

const int MAXN=100010;

int c[MAXN];
int n,q;

void add(int i,int v)
{
    for(;i<=n;i+=lowbit(i))
        c[i]+=v;
}

int getsum(int i)
{
    int sum=0;
    for(;i>0;i-=lowbit(i))
        sum+=c[i];
    return sum;
}

int main()
{
	read(n),read(q);
	for(int i=1;i<=n;i++)
        add(i,1);
    int be=1,en=n,t,l,r,rev=0;
    while(q--)
    {
        read(t);
        if(t==1)
        {
            read(l);
            if(l<=((en-be+1)>>1))
            {
                if(rev)
                {
                    l=en-l;
                    for(;en>l;en--)
                        add(2*l-en+1,getsum(en)-getsum(en-1));
                }
                else
                {
                    l+=be-1;
                    for(;be<=l;be++)
                        add(2*l-be+1,getsum(be)-getsum(be-1));
                }
            }
            else
            {
                if(rev)
                {
                    l=en-l;
                    for(;be<=l;be++)
                        add(2*l-be+1,getsum(be)-getsum(be-1));
                }
                else
                {
                    l+=be-1;
                    for(;en>l;en--)
                        add(2*l-en+1,getsum(en)-getsum(en-1));
                }
                rev^=1;
            }
        }
        else
        {
            read(l),read(r);
            if(rev)
                l=en-l,r=en-r;
            else
                l+=be-1,r+=be-1;
            if(l>r)
                swap(l,r);
            write(getsum(r)-getsum(l));
            putchar('\n');
        }
    }
    return 0;
}
