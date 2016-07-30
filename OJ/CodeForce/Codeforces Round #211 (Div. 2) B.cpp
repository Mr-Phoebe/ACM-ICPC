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

int n,k,sum,head,tail=1,minn=INF,po;
int a[150010];

int main()
{
    while(read(n)&&read(k))
    {
        head=sum=tail=0;
        minn=INF;
        for(int i=0; i<n; i++)
        {
            read(a[i]);
            sum+=a[i];
            tail++;
            if(tail-head>k)
                sum-=a[head++];
            if(tail-head==k && minn>sum)
            {
                minn=sum;
                po=head;
            }
        }
        if(tail-head>k)
            sum-=a[head++];
        if(tail-head==k && minn>sum)
        {
            minn=sum;
            po=head;
        }
        printf("%d\n",po+1);
    }

    return 0;
}
