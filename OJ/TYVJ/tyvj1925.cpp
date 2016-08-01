#include<iostream>
#include<cstring> 

using namespace std;

const int maxn=1<<11;
bool vis[maxn+10];
int path[maxn+10];
int ans=1;

void dfs(int u,int k)
{
	u&=(1<<k)-1;
	if(vis[u])
		return;
	vis[u]=true;
	dfs(u<<1,k);
	dfs((u<<1)|1,k);
	ans++;
	path[ans]=u;
	return;
}

int main()
{
	int k;
	memset(vis,false,sizeof(maxn));
	cin>>k;
	cout<<(1<<k)<<" ";
	dfs(0,k);
	for(int i=k-1;i>=1;i--)
		cout<<((path[ans]>>i)&1);
	for(int i=ans;i>k;i--)
		cout<<(path[i]&1);
	cout<<endl;
	return 0;
} 