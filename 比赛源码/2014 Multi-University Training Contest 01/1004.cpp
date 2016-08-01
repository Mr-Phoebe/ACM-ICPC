#include<stdio.h>
#include<string.h>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100005;
struct P
{
	int x,y;
}a[N],b[N];
bool cmp(P a,P b)
{
	if(a.x==b.x)return a.y>b.y;
	return a.x>b.x;
}
map<int,int>mapp;
char s[N];
int main()
{
    //freopen("0.in","r",stdin);
	//freopen("0.out","w",stdout);
	int n,m,i,j,ans1;
	long long ans2;
	while(~scanf("%d %d",&n,&m))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&a[i].x,&a[i].y);
		}
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&b[i].x,&b[i].y);
		}
		sort(a,a+n,cmp);
		sort(b,b+m,cmp);
		mapp.clear();
		j=0,ans1=0,ans2=0;
		for(i=0;i<m;i++)
		{
			while(j<n&&a[j].x>=b[i].x)
			{
				mapp[a[j].y]++;
				j++;
			}
			map<int,int>::iterator it=mapp.lower_bound(b[i].y);
			if(it!=mapp.end())
			{
			    ans1++;
				ans2+=(b[i].x*500+b[i].y*2);
				int t=it->first;
				mapp[t]--;
				if(mapp[t]==0)mapp.erase(t);
			}
		}
		printf("%d %I64d\n",ans1,ans2);
	}
	return 0;
}
