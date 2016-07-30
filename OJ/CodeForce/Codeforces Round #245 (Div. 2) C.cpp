#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN=100005;

vector<int> g[MAXN];
int n,ini[MAXN],goa[MAXN],num,ans[MAXN];

void dfs(int x,int fl,int odd,int even,int fa)
{
	if(fl)
	{
		if(!odd)
		{
			if(ini[x]!=goa[x])//奇数偶数不等 
			{
				odd=!odd;
				ans[num++]=x;
			}	
			
		}
		else
		{
			if(ini[x]==goa[x])//奇数奇数相等 
			{
				odd=!odd;
				ans[num++]=x;
			}
		}	
	}
	else
	{
		if(!even)
		{
			if(ini[x]!=goa[x])//偶数偶数等 
			{
				even=!even;
				ans[num++]=x;
			}	
			
		}
		else
		{
			if(ini[x]==goa[x])//偶数奇数相等 
			{
				even=!even;
				ans[num++]=x;
			}
		}
	}
		
	for(int i=0;i<g[x].size();i++)
	{
		int e=g[x][i];
		if(e!=fa)
			dfs(e,!fl,odd,even,x); 
	}
	return;
}

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int so,fa;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&so,&fa);
		g[fa].push_back(so);
		g[so].push_back(fa);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&ini[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&goa[i]);
	dfs(1,1,0,0,-1);
//	sort(ans,ans+num);
	printf("%d\n",num);
	for(int i=0;i<num;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;	
}

