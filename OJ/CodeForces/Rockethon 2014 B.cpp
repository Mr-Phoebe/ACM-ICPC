#include<iostream>
#include<string>

using namespace std;

string str;
int vis[1010];

int dfs(int x)
{
	if(vis[x])
		return vis[x];
	for(int i=x+1;i<str.length();i+=2)
		if(str.at(i)==str.at(x))
			vis[x]=max(vis[x],dfs(i));
	vis[x]++;
	return vis[x];
}


int main()
{
	int ans=0;
	cin>>str;
	for(int i=0;i<str.length();i++)
		if(!vis[i])
			ans=max(ans,dfs(i));
	cout<<ans<<endl;
	return 0;
}
 