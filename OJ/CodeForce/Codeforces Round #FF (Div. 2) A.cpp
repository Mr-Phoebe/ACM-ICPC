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

const int maxn=2010;
typedef long long ll;

inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int p,n;
int h[maxn];

int main()
{
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif // LOCAL
    p=read();
    n=read();
    memset(h,0,sizeof(h));
    for(int pos=1;pos<=n;pos++)
    {
        int temp;
        temp=read();
        if(h[temp%p]==0)
            h[temp%p]=1;
        else {printf("%d\n",pos);return 0;}
    }
    printf("-1\n");
    return 0;
}
