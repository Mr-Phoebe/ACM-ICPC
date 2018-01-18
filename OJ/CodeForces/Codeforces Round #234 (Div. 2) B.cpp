#include<iostream> 
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

string str;
bool vis[1111]; 


int main()
{
	int n,m;
	int ans=0;
	cin>>n>>m;
	memset(vis,false,sizeof(vis));
	for(int i=0;i<n;i++)
	{
		cin>>str;
		int po1=str.find("G"),po2=str.find("S");
		int temp=po2-po1-1;
		if(temp<0)
			ans=-1;	
		else
			vis[temp]=true;
	}
	for(int i=0;i<1111&&ans!=-1;i++)
		if(vis[i])
			ans++;
	cout<<ans<<endl;
	return 0; 
}

