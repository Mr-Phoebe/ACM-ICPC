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

const int MAXN=100010;
typedef long long ll;

ll a[MAXN],s[MAXN],ss[MAXN];
int n;

inline int lowbit(int x)
{
    return x&(-x);
}

void updata(int i,int v,ll *c)
{
    for(;i<=n;i+=lowbit(i))
        c[i]+=v;
    return;
}

ll getsum(int i,ll *c)
{
    ll sum=0;
    for(;i;i-=lowbit(i))
        sum+=c[i];
    return sum;
}

ll query(int l,int r)
{
    ll ret=0;
    ret+=a[r]+getsum(r,s)*(r+1)-getsum(r,ss);
    ret-=a[l]+getsum(l,s)*(l+1)-getsum(l,ss);
    return ret;
}

void add(int l,int r,int x)
{
    updata(l+1,x,s);
    updata(l+1,x*(l+1),ss);
    updata(r+1,-x,s);
    updata(r+1,-x*(r+1),ss);
}

int main()
{
    int q;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    getchar();
    while(q--)
    {
        char ch=getchar();
        if(ch=='Q')
        {
            int l,r;
            scanf("%d %d",&l,&r);
            ll ans=query(l-1,r);
            printf("%lld\n",ans);
        }
        else
        {
            int l,r,v;
            scanf("%d %d %d",&l,&r,&v);
            add(l-1,r,v);
        }
        getchar();
    }
    return 0;
}


