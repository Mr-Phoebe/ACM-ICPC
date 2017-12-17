#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int> g[100010],spa;
int val[100010],ans[100010],hea[100010],hs;
bool fou[100010],exi[100010];
inline bool cmp(const int& a,const int& b)
{
	return val[a]<val[b];
}
bool dfs(int now)
{
	fou[now]=true;
	static int t; 
	int i;
	bool tag=true;
	for(i=g[now].size()-1;i>=0;--i)
	{
		t=g[now][i];
		if(!fou[t])
		{
			if(val[t]==val[now])
			{
				tag=false;
			}
			else if(val[t]>val[now])
			{
				return false;
			}
			if(!dfs(t))
			{
				return false;
			}
		}
	}
	if(tag==true)
	{
		if(ans[now]==val[now])
		{
			return false;
		}
		ans[now]=val[now];
	}
	else
	{
		spa.push_back(now);
	}
	return true;
}
int main()
{
	int T,cas=0,i,n,a,b,root,count,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(exi+1,true,sizeof(bool)*n);
		for(i=1;i<=n;++i)
		{
			scanf("%d",&val[i]);
			exi[val[i]]=false;
			g[i].clear();
		}
		for(i=1;i<n;++i)
		{
			scanf("%d%d",&a,&b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		
		printf("Case #%d:",++cas);
		root=0;
		for(i=n;i>=1;--i)
		{
			if(val[i]!=n)
			{
				continue;
			}
			count=0;
			for(j=g[i].size()-1;j>=0;--j)
			{
				if(val[g[i][j]]==n)
				{
					++count;
				}
			}
			if(count<=1)
			{
				root=i;
			}
		}
		if(root==0)
		{
			puts(" Impossible");
			continue;
		}
		
		memset(ans+1,0,sizeof(int)*n);
		memset(fou+1,false,sizeof(bool)*n);
		spa.clear();
		if(!dfs(root))
		{
			puts(" Impossible");
			continue;
		}
		sort(spa.begin(),spa.end(),cmp);
		j=spa.size()-1;
		hs=0;
		for(i=n;i!=0;--i)
		{
			if(!exi[i])
			{
				continue;
			}
			while(j>=0&&val[spa[j]]>i)
			{
				hea[hs]=spa[j];
				push_heap(hea,hea+(++hs));
				--j;
			}
			if(hs==0)
			{
				break;
			}
			ans[hea[0]]=i;
			pop_heap(hea,hea+(hs--));
		}
		if(i!=0)
		{
			puts(" Impossible");
			continue;
		}
		for(i=1;i<=n;++i)
		{
			printf(" %d",ans[i]);
		}
		putchar('\n');
	}
	return 0;
}
/*
2

2
2 2
1 2

3
3 1 2
1 2
2 3
*/

