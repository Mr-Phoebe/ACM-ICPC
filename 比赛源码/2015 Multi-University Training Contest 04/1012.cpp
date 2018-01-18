#include<cstdio>
#include<cassert>
#include<set>
#include<map>
#include<cmath>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
typedef long double db;
void gn(int &x){
	char c;while((c=getchar())<'0'||c>'9');x=c-'0';
	while((c=getchar())>='0'&& c<='9')x=x*10+c-'0';
}
int n;
int a[111111],ord[111111];
int cut[111111],con[111111];
set<int> cuts;
#define inf 1000000000
inline void cutit(int x){
	if(!cut[x]){
		cut[x]=1;
		cuts.insert(x);
	}
}

int seg[444444];
int l1,r1,I,v;
void build(int l,int r,int x){
	if(l==r){
		seg[x]=a[l];
	}else{
		int mid=l+r>>1;
		build(l,mid,x<<1);
		build(mid+1,r,x<<1|1);
		seg[x]=max(seg[x<<1],seg[x<<1|1]);
	}
}
void upd(int l,int r,int x){
	if(l==r)seg[x]=-inf;
	else{
		int mid=l+r>>1;
		if(I<=mid)upd(l,mid,x<<1);
		else upd(mid+1,r,x<<1|1);
		seg[x]=max(seg[x<<1],seg[x<<1|1]);
	}
}
void que(int l,int r,int x){
	if(l1<=l && r<=r1)v=max(v,seg[x]);
	else{
		int mid=l+r>>1;
		if(l1<=mid)que(l,mid,x<<1);
		if(r1>mid)que(mid+1,r,x<<1|1);
	}
}
void conit(int x){
	if(!con[x]){
		con[x]=1;
		I=x;
		upd(1,n,1);
	}
}
int ans[111111];
int main()
{
	/*freopen("1.in","r",stdin);
	freopen("ans.out","w",stdout);*/
	int tes;
	scanf("%d",&tes);
	while(tes--){
		cuts.clear();
		scanf("%d",&n);
		/*memset(ord,0,sizeof(ord));*/
		for (int i=1;i<=n;i++)gn(a[i]),ord[a[i]]=i,cut[i]=con[i]=0;
		/*for (int i=1;i<=n;i++)assert(ord[i]);*/
		cut[n+1]=con[n+1]=0;
		cutit(1);
		cutit(n+1);
		build(1,n,1);
		for (int k=1;k<=n;k++){
			int i=ord[k];
			int rma=-inf;
			if(!cut[i+1])rma=a[i+1];
			int lma=-inf;
			if(!con[i+1]){
				set<int>::iterator it=cuts.lower_bound(i+1);it--;
				l1=*it,r1=i,v=-inf;
				que(1,n,1);
				lma=v;
			}
			if(rma>lma){
				ans[k]=rma;
				conit(i+1);
			}else{
				ans[k]=lma;
				int pos=ord[lma];
				cutit(pos);
				cutit(i+1);
				for (int j=pos+1;j<=i;j++)conit(j);
			}
		}
		for (int i=1;i<=n;i++){
			if(i>1)printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
