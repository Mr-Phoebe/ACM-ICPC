/*
题目大意：有2*1e5条木棒竖立在x坐标上，已知每条棒的长度和坐标（yi，xi），现给出2*1e5个查询，（u,v），若将x木棒推到，按照多诺米骨牌效应，后面的
木棒会一直向后倒，直到某一个木棒倒下后不能触碰他的下一位木棒（即x[i]+y[i]<x[i+1]),假如将一根木棒增加单位1长度的花费为1，那么至少需要多少的
花费才能使得推到u后，能使得v也被撞倒？（只是查询这种计划的花费，木棒的长度不会改变，即查询之间相互不影响） 
题目分析：这么大的数据肯定要用个线段树或者二分查找（上次以为是平衡树结果是set0.0）
题解：显然，如果木棒u被推到后所压倒的木棒的序号大于v的话，则该花费为0。假设不能推到v,那么假设其所能推倒的最后一跟木棒编号为k，u到k之间的木棒
倒下所能砸到的最远距离为dist[k]，则其到达k+1的花费为x[k+1]-dist[k]，如果k+1倒下后也不能砸到k+2，那么又需花费x[k+2]-(x[k+1]+y[k+1]),显然
dist[k+2]=x[k+2]+y[k+2]，如果由k要直接到达k+2，其花费为x[k+2]-dist[k]>x[k+1]-dist[k]+x[k+2]-(x[k+1]+y[k+1]),所以我们可以得出一个推论：
由u到v的最小花费即为由u到v直接每一个“断开”的“多诺米片段”链接起来的花费。
设木棒i倒下后，其后第一个仍然竖立着的木棒为next[i]，如果预处理出所有的next[i]，以及dist[i],那么查询（u，v）就可以由以下求出
while(next[u]<=v)
{
	ans+=x[next[u]]-dist[u];
	u=next[u];
}
然而这样做的复杂度是O(n),无法在规定的时间内求得。那么我们可以利用st算法，预处理dp[i][j]为推到棒i使得棒i+(1<<j)-1倒下的最小花费，next[i][j]
为棒i到帮i+(1<<j)-1全部倒下后，其后仍然竖立的第一个木棒，dist[i][j]为棒i到棒i+(1<<j)-1全部倒下后所能砸到的最远距离
那么对于每一查询solve(u,v)可得递推式solve(u,v)= next[u][k]>v? dp[u][k]:dp[u][k]+x[next[u][k]]-dist[u][k]+solve(next[u][k],v),k=log2(v-u+1);
因为每一层k都为(int)log2(v-u+1)，那么有对数知识可得next[u][k]>u+(v-u+1)/2，每次递减至少一半，其复杂度不超过logn。

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