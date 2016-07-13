#include <fstream>  
#include <cstdio>  
#include <iostream>  
#include <cstring>  
#include <string>  
#include <algorithm>  
#include <cmath>  
#include <numeric>  
#include <functional>  
#include <cctype>  
#define lowbit(x) (x&(-x)) 
typedef long long ll; 
using namespace std;  
  
const int MAXN=20010; 

int co_sum[MAXN],po_sum[MAXN];
int n; 

void updata(int i,int a,int *c)
{
	for(;i<=MAXN;i+=lowbit(i))
		c[i]+=a;
}

ll getsum(int i,int *c)
{
	ll sum=0;
	for(;i>=1;i-=lowbit(i))
		sum+=c[i];
	return sum;
}

struct Node
{
	int x,v;
	bool operator < (const Node &b) const
	{
		return v<b.v;
	}
}a[MAXN];


int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&a[i].v,&a[i].x);
	sort(a,a+n);      
	updata(a[0].x,a[0].x,po_sum);
	updata(a[0].x,1,co_sum);
	ll ans=0,total=a[0].x;
	for(int i=1;i<n;i++)
	{
		ll l_c=getsum(a[i].x,co_sum);
		ll l_p=getsum(a[i].x,po_sum);
		ll l_a=l_c*a[i].x-l_p;
		ll r_a=total-l_p-(i-l_c)*a[i].x;//分成两个貌似更容易理解 
		ans+=(r_a+l_a)*a[i].v;
		updata(a[i].x,1,co_sum);
		updata(a[i].x,a[i].x,po_sum);
		total+=a[i].x;
	}
	printf("%lld\n",ans);
	
	return 0; 
}