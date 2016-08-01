#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
using namespace std;
typedef long long ll;
int x[2111111];int n;
int l,k;

int a1[2111111],n1,a2[2111111],n2;
ll ans=0;
ll su1[2111111],su2[2111111];
int main()
{
	return 0;
	int tes;
	scanf("%d",&tes);
	while(tes--){
		int cnt;
		scanf("%d%d%d",&l,&cnt,&k);
		n=0;
		while(cnt--){
			int y,a;
			scanf("%d%d",&y,&a);
			for (int i=1;i<=a;i++)x[++n]=y;
		}
		k=min(k,n);
		n1=n2=0;
		for (int i=1;i<=n;i++)
			if(x[i]*2<l)a1[++n1]=x[i];
			else a2[++n2]=l-x[i];
		sort(a1+1,a1+1+n1);
		sort(a2+1,a2+1+n2);
		su1[0]=su2[0]=0;
		for (int i=1;i<=n1;i++)
			if(i<=k)su1[i]=a1[i];
			else su1[i]=a1[i]+su1[i-k];
		for (int i=1;i<=n2;i++)
			if(i<=k)su2[i]=a2[i];
			else su2[i]=a2[i]+su2[i-k];
		ans=(su1[n1]+su2[n2])*2;
		for (int i=0;i<=n1 && i<=k;i++){
			int lef=n1-i,rig=max(0,n2-(k-i));
			ans=min(ans,l+(su1[lef]+su2[rig])*2);
		}
		printf("%lld\n",ans);

	}
	return 0;
}







