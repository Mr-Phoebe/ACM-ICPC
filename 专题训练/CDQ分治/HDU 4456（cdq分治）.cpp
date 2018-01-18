/*
题意：给一个N*N的二维棋盘，N<=1e4，每个点有一个key值，初始值为0。给M个操作（M<=8*1e4），分两种：1、将节点（x,y）的值增加z（-100<=z<=100）；
	2、查询与节点(x,y)的曼哈顿距离小于z的所有点的值。
题目分析：二维查询，用cdq分治搞。 对于每一层分治的查询（x0,y0,z），即求所有满足|x-x0|+|y-y0|<=z的（x,y）的和，这个式子可以化作两个不等式：
	x0+y0-z<=x+y<=x0+y0+z与x0-y0-z<=x-y<=x0-y0+z
	这样一来就具有了单调性，用单调队列搞掉一维，树状数组查询即可。

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAX_N 90000
using namespace std;
typedef __int64 LL;
struct node
{
	int x,y,z,p,t;
	bool operator<(const node &q)const{
		return t<q.t;
	}
}E[MAX_N];
LL dp[MAX_N][3],bit[MAX_N];
bool cmp1(node a,node b)
{
	return a.x+a.y<=b.x+b.y;
}
bool cmp2(node a,node b)
{
	return a.x+a.y+a.z<=b.x+b.y+b.z;
}
bool cmp3(node a,node b)
{
	return a.x+a.y-a.z-1<=b.x+b.y-b.z-1;
}
int N,M;
/*树状数组要开够，就算加入的位置的范围比较小，但是求和的范围大的话也要开得足够大，WA了3发~~~~~~~~~*/
void add(int v,int x)
{
	while(v<=40100){
		bit[v]+=x;
		v+=v&-v;
	}
}
void clear(int v)
{
	while(v<=40100){
		bit[v]=0;
		v+=v&-v;
	}
}
LL sum(int v)
{
	LL ans=0;
	while(v>0){
		ans+=bit[v];
		v-=v&-v;
	}
	return ans;
}
void solve(int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	solve(l,mid);
	for(int i=mid+1;i<=r;i++){
		for(int j=1;j<=2;j++)dp[i][j]=0;
	}
	sort(E+l,E+mid+1,cmp1);
	sort(E+mid+1,E+r+1,cmp2);
	for(int i=mid+1,j=l;i<=r;i++){
		if(E[i].p==1)continue;
		int ans=E[i].x+E[i].y+E[i].z;
		while(j<=mid&&E[j].x+E[j].y<=ans){
			if(E[j].p==1){
				add(E[j].x-E[j].y+10000,E[j].z);
			}
			j++;
		}
		dp[E[i].t][1]=sum(E[i].x-E[i].y+E[i].z+10000)-sum(E[i].x-E[i].y-E[i].z+9999);
	}
	for(int i=l;i<=mid;i++)if(E[i].p==1)clear(E[i].x-E[i].y+10000);
	sort(E+mid+1,E+r+1,cmp3);
	for(int i=mid+1,j=l;i<=r;i++){
		if(E[i].p==1)continue;
		int ans=E[i].x+E[i].y-E[i].z-1;
		while(j<=mid&&E[j].x+E[j].y<=ans){
			if(E[j].p==1){
				add(E[j].x-E[j].y+10000,E[j].z);
			}
			j++;
		}
		dp[E[i].t][2]=sum(E[i].x-E[i].y+E[i].z+10000)-sum(E[i].x-E[i].y-E[i].z+9999);
	}
	for(int i=l;i<=mid;i++)if(E[i].p==1)clear(E[i].x-E[i].y+10000);
	for(int i=mid+1;i<=r;i++){
		if(E[i].p==1)continue;
		dp[E[i].t][0]+=dp[E[i].t][1]-dp[E[i].t][2];
	}
	sort(E+mid+1,E+r+1);
	solve(mid+1,r);
}
int main()
{
    freopen("data.txt","r",stdin);
    freopen("right.txt","w",stdout);
	while(scanf("%d",&N)!=EOF&&N){
		scanf("%d",&M);
		for(int i=1;i<=M;i++){
			scanf("%d%d%d%d",&E[i].p,&E[i].x,&E[i].y,&E[i].z);
			E[i].t=i;
		}
		memset(dp,0,sizeof dp);
		memset(bit,0,sizeof bit);
		solve(1,M);
		sort(E+1,E+M+1);
		for(int i=1;i<=M;i++){
			if(E[i].p==1)continue;
			printf("%I64d\n",dp[i][0]);
		}
	}
	return 0;
}
