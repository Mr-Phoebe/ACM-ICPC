#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
const int N = 100005;
const int M = 4000005;
#define mp(x,y) make_pair(x,y)
typedef __int64 ll;
typedef pair<int,int> per;
typedef pair<int,per> pp;
struct P
{
	int l,r,v;
}dd[N];
int T[N+N],ls[M],rs[M],ct[M],len,vv[N],vk;
ll sum[M];
void insert(int L,int R,int p,int v,int pre,int &x)
{
	x=++len;
	ls[x]=ls[pre];
	rs[x]=rs[pre];
	sum[x]=sum[pre]+v*vv[p-1];
	ct[x]=ct[pre]+v;
	if(L==R)return ;
	int mid=((L+R)>>1);
	if(p<=mid)insert(L,mid,p,v,ls[pre],ls[x]);
	else insert(mid+1,R,p,v,rs[pre],rs[x]);
}
ll k_th(int L,int R,int k,int x)
{
	if(L==R)return (ll)k*vv[L-1];
	if(k<=ct[ls[x]])return k_th(L,(L+R)>>1,k,ls[x]);
	return sum[ls[x]]+k_th(((L+R)>>1)+1,R,k-ct[ls[x]],rs[x]);
}
pp dt[N+N];
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n,m,x,p,i;
	while(~scanf("%d%d%d%d",&n,&m,&x,&p))
	{
		vk=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&dd[i].l,&dd[i].r,&dd[i].v);
			vv[vk++]=dd[i].v;
		}
		sort(vv,vv+vk);
		vk=unique(vv,vv+vk)-vv;
		int k=0;
		for(i=0;i<n;i++)
		{
			dd[i].v=lower_bound(vv,vv+vk,dd[i].v)-vv+1;
			dt[k++]=mp(dd[i].l,mp(dd[i].v,1));
			dt[k++]=mp(dd[i].r+1,mp(dd[i].v,-1));
		}
		sort(dt,dt+k);
		//build(1,vk,T[0]);
		T[0]=ls[0]=rs[0]=ct[0]=sum[0]=len=0;
		for(i=0;i<k;i++)
		{
			//printf("i:%d p:%d v:%d tp:%d \n",i,dt[i].first,dt[i].second.first,dt[i].second.second);
			insert(1,vk,dt[i].second.first,dt[i].second.second,T[i],T[i+1]);
		}
		int fg=0;
		ll prek=1;
		while(m--)
		{
			int x;
			ll a,b,c,tk;
			scanf("%d%I64d%I64d%I64d",&x,&a,&b,&c);
			tk=(a*prek+b)%c;
			int t=upper_bound(dt,dt+k,mp(x,mp(vk+1,0)))-dt-1;
			//printf("t:%d \n",t);
			if(t<0) puts("0"),prek=0;
			else
			{
				ll ret=k_th(1,vk,tk,T[t+1]);
				if(fg)ret*=2;
				if(ret>p)fg=1;
				else fg=0;
				printf("%I64d\n",ret);
				prek=ret;
			}
		}
	}
	return 0;
}
