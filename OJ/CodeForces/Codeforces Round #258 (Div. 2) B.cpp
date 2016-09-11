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
//-----------------
const int MAXN=100010;
int n;
int a[MAXN];
int l,r,ok=0,up=1,one=0;

int main()
{
    read(n);
    for(int i=0;i<n;i++)
        read(a[i]);
    l=0,r=n-1;
    for(int i=1;i<n;i++)
    {
        if(up&&a[i]<a[i-1])
        {
            l=i-1;
            up=false;
            one++;
        }
        else if(!up&&a[i]>a[i-1])
        {
            r=i-1;
            up=true;
        }
    }//cout<<one<<endl;
    if(one>1)
    {
        puts("no");
        return 0;
    }
    else if(one==0)
    {
        puts("yes");
        printf("%d %d\n",1,1);
        return 0;
    }
    else if(r==n-1&&a[r]>a[l-1])
    {
        puts("yes");
        printf("%d %d\n",l+1,r+1);
        return 0;
    }
    else if(a[l]<a[r+1]&&a[r]>a[l-1])
    {
        puts("yes");
        printf("%d %d\n",l+1,r+1);
        return 0;
    }
    else
        puts("no");
    return 0;
}