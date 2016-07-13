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

const int MAXN=500010;
typedef long long ll;

struct Node
{
    int x,v;
}a[MAXN];
int c[MAXN],p[MAXN];
int n;

int lowbit(int x)
{
    return x&(-x);
}

void updata(int i,int v)
{
    for(;i<=n;i+=lowbit(i))
        c[i]+=v;
    return;
}

int getsum(int i)
{
    int sum=0;
    for(;i;i-=lowbit(i))
        sum+=c[i];
    return sum;
}

bool cmp(Node a,Node b)
{
    return a.v<b.v;
}

int main()
{
    while(~scanf("%d",&n)&&n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i].v);
            a[i].x=i+1;
        }
        sort(a,a+n,cmp);
        int id=0;
        p[a[0].x]=++id;
        for(int i=1;i<n;i++)
        if(a[i].v==a[i-1].v)
            p[a[i].x]=id;
        else
            p[a[i].x]=++id;
        ll ans=0;
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)
        {
            updata(p[i],1);
            ans+=(ll)i-(ll)getsum(p[i]);
        }
        printf("%lld\n",ans);
    }

    return 0;
}
/*
5
9 1 0 5 4
3
1 2 3
0


*/
