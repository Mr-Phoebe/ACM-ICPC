/*
��Ŀ���⣺��2*1e5��ľ��������x�����ϣ���֪ÿ�����ĳ��Ⱥ����꣨yi��xi�����ָ���2*1e5����ѯ����u,v��������xľ���Ƶ������ն�ŵ�׹���ЧӦ�������
ľ����һֱ��󵹣�ֱ��ĳһ��ľ�����º��ܴ���������һλľ������x[i]+y[i]<x[i+1]),���罫һ��ľ�����ӵ�λ1���ȵĻ���Ϊ1����ô������Ҫ���ٵ�
���Ѳ���ʹ���Ƶ�u����ʹ��vҲ��ײ������ֻ�ǲ�ѯ���ּƻ��Ļ��ѣ�ľ���ĳ��Ȳ���ı䣬����ѯ֮���໥��Ӱ�죩 
��Ŀ��������ô������ݿ϶�Ҫ�ø��߶������߶��ֲ��ң��ϴ���Ϊ��ƽ���������set0.0��
��⣺��Ȼ�����ľ��u���Ƶ�����ѹ����ľ������Ŵ���v�Ļ�����û���Ϊ0�����費���Ƶ�v,��ô�����������Ƶ������һ��ľ�����Ϊk��u��k֮���ľ��
���������ҵ�����Զ����Ϊdist[k]�����䵽��k+1�Ļ���Ϊx[k+1]-dist[k]�����k+1���º�Ҳ�����ҵ�k+2����ô���軨��x[k+2]-(x[k+1]+y[k+1]),��Ȼ
dist[k+2]=x[k+2]+y[k+2]�������kҪֱ�ӵ���k+2���仨��Ϊx[k+2]-dist[k]>x[k+1]-dist[k]+x[k+2]-(x[k+1]+y[k+1]),�������ǿ��Եó�һ�����ۣ�
��u��v����С���Ѽ�Ϊ��u��vֱ��ÿһ�����Ͽ����ġ���ŵ��Ƭ�Ρ����������Ļ��ѡ�
��ľ��i���º�����һ����Ȼ�����ŵ�ľ��Ϊnext[i]�����Ԥ��������е�next[i]���Լ�dist[i],��ô��ѯ��u��v���Ϳ������������
while(next[u]<=v)
{
	ans+=x[next[u]]-dist[u];
	u=next[u];
}
Ȼ���������ĸ��Ӷ���O(n),�޷��ڹ涨��ʱ������á���ô���ǿ�������st�㷨��Ԥ����dp[i][j]Ϊ�Ƶ���iʹ�ð�i+(1<<j)-1���µ���С���ѣ�next[i][j]
Ϊ��i����i+(1<<j)-1ȫ�����º������Ȼ�����ĵ�һ��ľ����dist[i][j]Ϊ��i����i+(1<<j)-1ȫ�����º������ҵ�����Զ����
��ô����ÿһ��ѯsolve(u,v)�ɵõ���ʽsolve(u,v)= next[u][k]>v? dp[u][k]:dp[u][k]+x[next[u][k]]-dist[u][k]+solve(next[u][k],v),k=log2(v-u+1);
��Ϊÿһ��k��Ϊ(int)log2(v-u+1)����ô�ж���֪ʶ�ɵ�next[u][k]>u+(v-u+1)/2��ÿ�εݼ�����һ�룬�临�ӶȲ�����logn��

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define MAX_N 210005
#define INF 1LL<<61
using namespace std;
typedef __int64 LL;
typedef pair<LL,LL> P;

P A[MAX_N];
int N,M,next[MAX_N][25],key[MAX_N*3];
LL tree[MAX_N*3],dp[MAX_N][25],dist[MAX_N][25];
void update(int p,int l,int r,int v,LL x)
{
	if(r<v||v<l)return;
	if(l==r){
		tree[p]=x;
		key[p]=next[v][0];
		return;
	}
	update(p*2,l,(l+r)/2,v,x);
	update(p*2+1,(l+r)/2+1,r,v,x);
	tree[p]=max(tree[p*2],tree[p*2+1]);
	key[p]=max(key[p*2],key[p*2+1]);
}
LL query(int p,int l,int r,int a,int b)
{
	if(a>r||b<l)return 0;
	if(a<=l&&r<=b)return tree[p];
	int mid=(l+r)/2;
	return max(query(p*2,l,mid,a,b),query(p*2+1,mid+1,r,a,b));
}
int nextquery(int p,int l,int r,int a,int b)
{
	if(a>r||b<l)return 0;
	if(a<=l&&r<=b)return key[p];
	int mid=(l+r)/2;
	return max(nextquery(p*2,l,mid,a,b),nextquery(p*2+1,mid+1,r,a,b));	
}
LL solve(int u,int v)
{
	if(u>=v)return 0;
	int k=(int)(log(v-u+1)/log(2.0));
	LL ans=dp[u][k];
//	printf("%d:[%d,%d] %d->%d:%I64d\n",k,u,v,u,u+(1<<k)-1,ans);
//	printf("next[%d][%d]=%d\n",u,k,next[u][k]);
	if(next[u][k]>v)return ans;
	ans+=A[next[u][k]].first-dist[u][k];
	return ans+solve(next[u][k],v);
}
void _init()
{
	memset(dist,0,sizeof dist);
	memset(next,0,sizeof next);
	memset(tree,0,sizeof tree);
	memset(dp,0,sizeof dp);
	dist[N][0]=A[N].first+A[N].second;
	next[N][0]=N+1;
	update(1,1,N,N,A[N].first+A[N].second);
	for(int i=N-1;i>=1;i--){
	//	printf("%d==%d?\n",A[i].first+A[i].second,A[N].first);
		next[i][0]=upper_bound(A+1,A+N+2,P(A[i].first+A[i].second,INF))-A;
		dist[i][0]=max(A[i].first+A[i].second,query(1,1,N,i+1,next[i][0]-1));
		next[i][0]=max(next[i][0],nextquery(1,1,N,i+1,next[i][0]-1));
		update(1,1,N,i,dist[i][0]);
	}
	for(int j=1;(1<<j)<=N;j++){
		for(int i=1;i<=N&&i+(1<<j)-1<=N;i++){
			dist[i][j]=max(dist[i][j-1],dist[i+(1<<j-1)][j-1]);
			next[i][j]=max(next[i][j-1],next[i+(1<<j-1)][j-1]);
			dp[i][j]=dp[i][j-1];
			if(next[i][j-1]<=i+(1<<j)-1){
				dp[i][j]+=A[next[i][j-1]].first-dist[i][j-1];
				if(next[i][j-1]>i+(1<<j-1)){
					dp[i][j]+=solve(next[i][j-1],i+(1<<j)-1);
				}
				else dp[i][j]+=dp[i+(1<<j-1)][j-1];
			}
		}
	}
}
int main()
{
//	printf("%d\n",INF);
	while(scanf("%d",&N)!=EOF){
		for(int i=1;i<=N;i++){
			scanf("%I64d%I64d",&A[i].first,&A[i].second);
		}
		A[N+1].first=INF;
		A[N+1].second=INF;
		_init();
		scanf("%d",&M);
		int u,v;
		for(int i=1;i<=M;i++){
			scanf("%d%d",&u,&v);
			printf("%I64d\n",solve(u,v));
		}
	}
	return 0;
}