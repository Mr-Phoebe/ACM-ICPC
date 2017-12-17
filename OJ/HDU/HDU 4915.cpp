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

const int L=1000050;
int a[L][2],b[L][2];

int main()
{
    int i,j,l,sig,ta,tb;
    char s[L];
    while(scanf("%s",s+1)!=EOF)
    {
        l=strlen(s+1);
        sig=0;
        if(l%2==1)
        {
            printf("None\n");
            continue;
        }
        a[0][0]=a[0][1]=b[l][0]=b[l][1]=0;
        for(i=1; i<=l; i++)
        {
            if(s[i]=='(')a[i][0]=a[i-1][0]+1,a[i][1]=a[i-1][1]+1;
            else if(s[i]==')')
            {
                if(a[i-1][0]==0)a[i][0]=1;
                else a[i][0]=a[i-1][0]-1;
                a[i][1]=a[i-1][1]-1;
            }
            else if(s[i]=='?')
            {
                if(a[i-1][0]==0)a[i][0]=1;
                else a[i][0]=a[i-1][0]-1;
                a[i][1]=a[i-1][1]+1;
            }
            if(a[i][0]>a[i][1])sig=1;
        }
        if(sig)
        {
            printf("None\n");
            continue;
        }
        for(i=l; i>=1; i--)
        {
            if(s[i]==')')b[i-1][0]=b[i][0]+1,b[i-1][1]=b[i][1]+1;
            else if(s[i]=='(')
            {
                if(b[i][0]==0)b[i-1][0]=1;
                else b[i-1][0]=b[i][0]-1;
                b[i-1][1]=b[i][1]-1;
            }
            else if(s[i]=='?')
            {
                if(b[i][0]==0)b[i-1][0]=1;
                else b[i-1][0]=b[i][0]-1;
                b[i-1][1]=b[i][1]+1;
            }
            if(b[i][0]>b[i][1])sig=1;
        }
        if(sig)
        {
            printf("None\n");
            continue;
        }
        for(i=1; i<=l; i++)
        {
            ta=max(a[i][0],b[i][0]);
            tb=min(a[i][1],b[i][1]);
            if(ta>tb)
            {
                sig|=1;
                break;
            }
            if(ta<tb)
            {
                sig|=2;
            }
        }
        if(sig&1)
        {
            printf("None\n");
            continue;
        }
        else if(sig&2)
        {
            printf("Many\n");
            continue;
        }
        else printf("Unique\n");
    }
    return 0;
}
