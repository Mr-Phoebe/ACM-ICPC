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
#define MAXN 10005
#define ll long long

using namespace std;
template<class T>
inline bool read(T &n){
    T x = 0, tmp = 1; char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}

template <class T>
inline void write(T n) {
    if(n < 0) {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n) {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}

ll prime[]={2,3,5,7,11,13,17,19,23,29,31};
struct node
{
    int left, right;
    ll gcd;
}arr[MAXN*6];

ll num[MAXN], a[MAXN], c;
ll gcd(ll a, ll b)
{
    return b==0?a:gcd(b,a%b);
}
void build(int idx, int l, int r)
{
    arr[idx].left = l, arr[idx].right = r;
    arr[idx].gcd = 0;
    if(l == r)
	{
        arr[idx].gcd = num[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(idx << 1, l, mid);
    build(idx << 1 | 1, mid + 1, r);
    arr[idx].gcd = gcd(arr[idx << 1].gcd , arr[idx << 1 | 1].gcd);
}
ll ans;
bool query(int idx, int l, int r)
{
    if(arr[idx].right < l||arr[idx].left > r)
		return false;
    if(arr[idx].left >= l&&arr[idx].right <= r)
	{
        ans=gcd(ans,arr[idx].gcd);
        return true;
    }
    query(idx << 1, l, r);
    query(idx << 1 | 1, l, r);
    return true;
}

void update(int idx, int val, int pos)
{
    int l = arr[idx].left, r = arr[idx].right;
    if(l == r)
	{
        arr[idx].gcd=val;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid)
		update(idx << 1, val, pos);
    else
		update(idx << 1 | 1, val, pos);
    //printf("%I64d(I64d,%I64d)\n",arr[idx].gcd, arr[idx<<1].gcd, arr[idx<<1|1].gcd);
    arr[idx].gcd = gcd(arr[idx<<1].gcd, arr[idx<<1|1].gcd);
}

int fa[1010][10];
inline void Get_fac(int m)  
{  
    int tot=0,temp=m; 
	if(fa[m][0]!=0)
		return;
    for(int i=2;i*i<=temp;i++)  
        if(temp%i==0)
		{  
            fa[m][++tot]=i;  
            while(temp%i==0)
				temp/=i;  
        }  
    if(temp!=1)
		fa[m][++tot]=temp;  
    fa[m][0]=tot;  
}  

int sum[1<<11],q;
ll Sum(int m,ll n)
{
	int i,j;
	Get_fac(m);
	sum[0]=1;
	sum[1]=1;
	for(i=1;i<=fa[m][0];i++)
	{
		int k=sum[0];
		for(j=1;j<=sum[0];j++)
		{
			sum[++k]=fa[m][i]*sum[j]*-1;
		}
		sum[0]=k;
	}
//	for(i=1;i<=sum[0];i++)	printf("%d ",sum[i]);printf("\n");
	ll ret=n;
	for(i=2;i<=sum[0];i++)
		ret+=n/sum[i];
	return ret;
}

int main()
{
    int t, n, q, l, r, m;
    ll g1;
    //int c=floor(log(2)/log(2)+eps);
    while(read(n))
	{
        read(m);read(q);
        for(int i=1;i<=n;i++)
			read(num[i]);
        build(1,1,n);
/*        for(int i=1;i<2*n;i++)
			printf("(%d:%I64d[%d,%d]) ",i,arr[i].gcd,arr[i].left,arr[i].right);
        puts("");*/
        int cnt=floor(log(n)/log(2)+eps);
        int o;
        while(q--)
		{
            read(o),read(l);
            if(o==1)
			{
                read(r);
                ans=num[l];
                query(1,l,r);
                if(ans==1)
                {
                	write(-1);putchar('\n');
                }
                else
                {
                	write(Sum(ans,m)-1);putchar('\n');
                }
            }
            else
			{
                read(g1); num[l]=g1;
                update(1,g1,l);
            }
        }
    }
    return 0;
}
