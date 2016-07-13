#include <stdio.h>
#include <algorithm>

#define MAXN 1000005

int a[MAXN];

inline void solve()
{
	int n;
	scanf("%d",&n);
	int i;
	for (i=1;i<=n;i++) {
		scanf("%d",a+i);
	}
	int ans=std::min(2,n);
	
	int l=1;
	for (i=3;i<=n;i++) {
		bool f= 2*a[i-1]==a[i-2]+a[i];
		if (!f) l=i-1;
		ans=std::max(ans,i-l+1);
	}
	
	l=1;
	for (i=3;i<=n;i++) {
		bool f= 1LL*a[i-1]*a[i-1]==1LL*a[i-2]*a[i];
		if (!f) l=i-1;
		ans=std::max(ans,i-l+1);
	}
	
	printf("%d\n",ans);
}

int main()
{
	int T;
	scanf("%d",&T);
	int i;
	for (i=1;i<=T;i++) {
		solve();
	}
}