#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 300005;
const int mod = 1e9+9;
ll t[maxn<<2], f[maxn], num[maxn];
int lazyl[maxn<<2], lazyr[maxn<<2];
void update(int x, int l, int r, int a, int b, int c, int d);
int fib(int a, int b, int n)//求f(0)=a,f(1)=b的斐波那契数列第n项
{
    if (n==0) return a;
    if (n==1) return b;
    return (a*f[n-1]%mod+b*f[n]%mod)%mod;
}
void build(int x, int l, int r)
{
    lazyl[x]=lazyr[x]=0;
    if (l==r)
    {
        t[x]=num[l];
        return ;
    }
    int mid=(l+r)/2;
    build(x<<1, l, mid);
    build(x<<1|1, mid+1, r);
    t[x]=(t[x<<1]+t[x<<1|1])%mod;
}
void push_down(int x, int l, int r)
{
    int mid=(l+r)/2;
    if (lazyl[x]||lazyr[x])
    {
        update(x<<1, l, mid, l, r, lazyl[x], lazyr[x]);
        update(x<<1|1, mid+1, r, l, r, lazyl[x], lazyr[x]);
        lazyl[x]=0;
        lazyr[x]=0;
    }
}
void update(int x, int l, int r, int a, int b, int c, int d)
{
    if (a<=l&&b>=r)
    {
        int nc, nd;
        nc=fib(c, d, l-a);
        nd=fib(c, d, l-a+1);
        c=nc;
        d=nd;
        lazyl[x]=(lazyl[x]+c)%mod;
        lazyr[x]=(d+lazyr[x])%mod;
        t[x]=(t[x]+fib(c, d, r-l+2)-d)%mod;//f(0)=a,f(1)=b的前n项和∑f(i),i<n，等于f(n+1)-b
        return ;
    }
    push_down(x, l, r);
    int mid=(l+r)/2;
    if (a<=mid) update(x<<1, l, mid, a, b, c, d);
    if (b>mid) update(x<<1|1, mid+1, r, a, b, c, d);
    t[x]=(t[x<<1]+t[x<<1|1])%mod;
}
ll query(int x, int l, int r, int a, int b)
{
    if (a<=l&&b>=r) return t[x];
    push_down(x, l, r);
    int mid=(l+r)/2;
    ll ret=0;
    if (a<=mid) ret+=query(x<<1, l, mid, a, b);
    if (b>mid) ret+=query(x<<1|1, mid+1, r, a, b);
    return ret;
}
int main()
{
    int n, m, op, l, r;
    f[1]=f[2]=1;
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        scanf("%I64d", &num[i]);
    }
    for (int i=3; i<n+5; i++)
        f[i]=(f[i-1]+f[i-2])%mod;
    build(1, 1, n);
    while (m--)
    {
        scanf("%d%d%d", &op, &l, &r);
        if (op==1)
        {
            update(1, 1, n, l, r, 1, 1);
        }
        else
        {
            printf("%I64d\n", (query(1, 1, n, l, r)%mod+mod)%mod);
        }
    }
    return 0;
}
