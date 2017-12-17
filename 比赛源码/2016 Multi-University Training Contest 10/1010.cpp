#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
#define MAX_N 100005
#define MAX_Q 3005

using namespace std;
const double eps = 1e-11;
typedef pair<int,double> P;
int A[MAX_N],M,N,fa[MAX_N];
vector<int> G[MAX_N];
int tree[MAX_N],head[MAX_N],indfn[MAX_N],outdfn[MAX_N],idx,si,root;
double dp[MAX_Q][MAX_Q*2];
struct edge{
    int to,next;
}E[MAX_N*2];
P Q[MAX_Q];
void add_edge(int u,int v)
{
    E[si].to=v;
    E[si].next=head[u];
    head[u]=si++;
}
bool cmp(P a,P b)
{
    int u=a.first,v=b.first;
    if(indfn[u]==indfn[v])return outdfn[u]>outdfn[v];
    return indfn[u]<indfn[v];
}
void dfs(int v)
{
    indfn[v]=++idx;
    tree[v]=A[v];
    for(int i=head[v];~i;i=E[i].next){
        int u=E[i].to;
        if(u==fa[v])continue;
        dfs(u);
        tree[v]=max(tree[v],tree[u]);
    }
    outdfn[v]=idx;
}
int gonext(int k,int pre)
{
    int v=Q[k].first;
    if(~pre)G[pre].push_back(k);
    for(int i=k+1;i<=M;i=gonext(i,k)){
        if(indfn[Q[i].first]>outdfn[v]){
            return i;
        }
    }
    return M+1;
}
double calc(int j,int k)
{
	int v=Q[j].first;
	if(dp[j][k+MAX_Q]>-0.5)return dp[j][k+MAX_Q];
	if(tree[v]>tree[root]+k)return 0;
	double ans=Q[j].second,res=1.0-Q[j].second;
	if(tree[v]==tree[root]+k)ans=0;    //若当前区间原始数列最大值等于其期望最大值，则该操作不能发生，故其发生概率设为0
	for(int i=0;i<G[j].size();i++){
		int u=G[j][i];
		ans*=calc(u,k-1);
		res*=calc(u,k);
	}
	return dp[j][k+MAX_Q]=res+ans;
}
int main()
{
     //freopen("in.txt","r",stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d%d",&N,&M)!=EOF){
        memset(head,-1,sizeof head);si=0;idx=0;
        memset(fa,0,sizeof fa);
        memset(G,0,sizeof G);
        memset(dp,-1,sizeof dp);
        for(int i=1,u,v;i<N;i++){
            scanf("%d%d",&u,&v);
            fa[u]=v;
            add_edge(u,v);
            add_edge(v,u);
        }
        for(int i=1;i<=N;i++){
            scanf("%d",&A[i]);
            if(!fa[i])root=i;
        }
        dfs(root);
        for(int i=1;i<=M;i++){
            scanf("%d%lf",&Q[i].first,&Q[i].second);
        }
        Q[0]=P(root,0);
        sort(Q,Q+M+1,cmp);
        gonext(0,-1);
        double ans=0;
        for(int i=0;i<=M;i++){
            ans+=(tree[root]+i)*(calc(0,i)-calc(0,i-1));
        }
        printf("%f\n",ans);
    }
    return 0;
}
