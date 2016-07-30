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

#define lowbit(x) (x)&(-x)
#define MAXN 100010
typedef long long ll;

int n;
ll c1[MAXN],c2[MAXN],a[MAXN],b[MAXN];

void update(int i,int v,ll* c)
{
    for(;i<=n;i+=lowbit(i))
        c[i]+=v;
}

ll get_sum(int i,ll* c)
{
    ll sum=0;
    for(;i>0;i-=lowbit(i))
        sum+=c[i];
    return sum;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        update(i,a[i],c1);
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
        update(i,b[i],c2);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int t,l,r;
        scanf("%d %d %d",&t,&l,&r);
        if(t==1)
            printf("%I64d\n",get_sum(r,c1)-get_sum(l-1,c1));
        else
            printf("%I64d\n",get_sum(r,c2)-get_sum(l-1,c2));
    }
    return 0;
}
