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
#define pb(x) push_back(x)
#define eps 1e-9
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

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

#define lowbit(x) (x&(-x))

const int MAXN=100010;
int ince[MAXN],dece[MAXN],a[MAXN],num[MAXN+1],c[MAXN+1],n,L;

int get(int i)
{
    int res=0;
    for(; i; i-=lowbit(i))
        res=max(c[i],res);
    return res;
}

void update(int i,int w)
{
    for(; i<=MAXN; i+=lowbit(i))
        c[i]=max(c[i],w);
}

int main()
{
    read(n);
    for(int i=0; i<n; i++)
        read(a[i]);
    for(int i=0; i<n; i++)
    {
        ince[i]=get(a[i]-1)+1;
        num[ince[i]]++;
        update(a[i],ince[i]);
        L=max(L,ince[i]);
    }
    CLR(c,0);
    for(int i=n-1; i>=0; i--)
    {
        dece[i]=get(MAXN-a[i])+1;
        update(MAXN-a[i]+1,dece[i]);
        L=max(L,dece[i]);
    }
    for(int i=0; i<n; i++)
        if(ince[i]+dece[i]-1!=L)
            num[ince[i]]--;         //  该前段长度不能构成LIS，故减一
    for(int i=0; i<n; i++)
    {
        if(ince[i]+dece[i]-1!=L)
            putchar('1');
        else if(num[ince[i]]!=1)
            putchar('2');
        else
            putchar('3');
    }
    return 0;
}

/*
 for(int i=0; i<n; i++)
    {
        if(1+ince[i]+dece[i]==L)
            num[ince[i]]++;
    }
*/
